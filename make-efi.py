#!/usr/bin/env python3
"""Build dist/EFI for the Dell Vostro 3520 from this repository's EFI/ folder (Linux or macOS).

    python3 make-efi.py                         dist/EFI, config.plist = accelerated
    python3 make-efi.py --installer --recovery  install USB: config.plist = safe, plus the macOS recovery

Three things are not in git, and this script puts them back:
  - the SMBIOS serials (MacBookPro16,2), kept in smbios.local outside git. It is created on the first run; keep it,
    because new serials make iCloud and iMessage see a different Mac.
  - HfsPlus.efi (an Apple binary, needed to boot the recovery): downloaded from acidanthera/OcBinaryData and checked
    by SHA-256.
  - the macOS recovery (Apple's): downloaded from Apple by OpenCore's macrecovery (--recovery).

dist/EFI/OC gets three configs:
  config-accel.plist    accelerated (Iris Xe through NootedGreen)
  config-install.plist  safe: no GPU spoof, NootedGreen off, verbose
  config.plist          a copy of config-accel.plist, or of config-install.plist with --installer
"""
import argparse
import hashlib
import os
import platform
import plistlib
import secrets
import shutil
import subprocess
import sys
import uuid
import zipfile

ROOT = os.path.dirname(os.path.abspath(__file__))
DEPS = os.path.join(ROOT, 'build', 'deps')
DIST = os.path.join(ROOT, 'dist')
SMBIOS = os.path.join(ROOT, 'smbios.local')
MODEL = 'MacBookPro16,2'
BOARD = 'Mac-5F9802EFE386AA28'  # board-id of the MacBookPro16,2, used by macrecovery
OC_VER = '1.0.8'
OC_ZIP = (f'https://github.com/acidanthera/OpenCorePkg/releases/download/{OC_VER}/OpenCore-{OC_VER}-RELEASE.zip',
          '2011e8b7216ecb2645d97ea710df965947edd406846e92050b9bc4190be6d27b')
HFSPLUS = ('https://raw.githubusercontent.com/acidanthera/OcBinaryData/'
           'c2a98980d30e39a571a2843ab26aa8d2b9188094/Drivers/HfsPlus.efi',
           'a55b5fff36578864ba6792c4c6369c71f6f35b61dd5a853ddf8583cd36c31d8f')
KEYS = ('SystemSerialNumber', 'MLB', 'SystemUUID', 'ROM')


def sha256(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()


def fetch(url, digest, dest):
    """Download url to dest (cached) and check its SHA-256."""
    if os.path.exists(dest) and sha256(dest) == digest:
        return dest
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    print(f'  downloading {os.path.basename(dest)}')
    tmp = dest + '.part'
    try:
        subprocess.run(['curl', '-fL', '--retry', '3', '-sS', '-o', tmp, url], check=True)
    except subprocess.CalledProcessError:
        sys.exit(f'error: could not download {url}')
    if sha256(tmp) != digest:
        os.remove(tmp)
        sys.exit(f'error: unexpected SHA-256 for {url}')
    os.replace(tmp, dest)
    return dest


def oc_utilities():
    """OpenCore utilities (macserial, ocvalidate, macrecovery) from the official release."""
    base = os.path.join(DEPS, f'OpenCore-{OC_VER}')
    if not os.path.isdir(os.path.join(base, 'Utilities', 'macrecovery')):
        z = fetch(*OC_ZIP, os.path.join(DEPS, f'OpenCore-{OC_VER}-RELEASE.zip'))
        with zipfile.ZipFile(z) as zf:
            for name in zf.namelist():
                if name.startswith(('Utilities/macserial/', 'Utilities/ocvalidate/', 'Utilities/macrecovery/')):
                    zf.extract(name, base)
    return os.path.join(base, 'Utilities')


def oc_tool(name):
    suffix = {'Linux': '.linux', 'Darwin': ''}.get(platform.system())
    if suffix is None:
        sys.exit('error: run this on Linux or macOS')
    path = os.path.join(oc_utilities(), name, name + suffix)
    os.chmod(path, 0o755)  # zipfile does not keep the executable bit
    return path


def load_smbios():
    """Read smbios.local; if it does not exist, generate new SMBIOS data with macserial and save it."""
    if os.path.exists(SMBIOS):
        vals = {}
        with open(SMBIOS, encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                if line and not line.startswith('#') and '=' in line:
                    key, value = line.split('=', 1)
                    vals[key.strip()] = value.strip()
        missing = [k for k in KEYS if not vals.get(k)]
        if missing:
            sys.exit(f'error: smbios.local has no {", ".join(missing)}')
        try:
            vals['ROM'] = bytes.fromhex(vals['ROM'])
        except ValueError:
            sys.exit('error: ROM in smbios.local must be 12 hexadecimal digits')
        if len(vals['ROM']) != 6:
            sys.exit('error: ROM in smbios.local must be 12 hexadecimal digits')
        vals['SystemProductName'] = vals.get('SystemProductName') or MODEL
        print('  SMBIOS: smbios.local')
        return vals

    out = subprocess.check_output([oc_tool('macserial'), '-m', MODEL, '-g', '-n', '1'], text=True)
    serial, mlb = (x.strip() for x in out.strip().splitlines()[0].split('|'))
    vals = {'SystemProductName': MODEL, 'SystemSerialNumber': serial, 'MLB': mlb,
            'SystemUUID': str(uuid.uuid4()).upper(), 'ROM': secrets.token_bytes(6)}
    fd = os.open(SMBIOS, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
    with os.fdopen(fd, 'w', encoding='utf-8') as f:
        f.write(f'# SMBIOS of this machine ({MODEL}). Do not publish it and do not delete it:\n'
                '# new serials make iCloud and iMessage see a different Mac.\n')
        for key in ('SystemProductName',) + KEYS:
            value = vals[key].hex() if key == 'ROM' else vals[key]
            f.write(f'{key}={value}\n')
    print('  SMBIOS: new, saved in smbios.local (keep this file)')
    return vals


def build_efi(vals, installer):
    efi = os.path.join(DIST, 'EFI')
    oc = os.path.join(efi, 'OC')
    if os.path.exists(efi):
        shutil.rmtree(efi)
    shutil.copytree(os.path.join(ROOT, 'EFI'), efi)
    shutil.copy(fetch(*HFSPLUS, os.path.join(DEPS, 'HfsPlus.efi')), os.path.join(oc, 'Drivers', 'HfsPlus.efi'))
    shutil.copy(os.path.join(oc, 'config.plist'), os.path.join(oc, 'config-accel.plist'))
    ocvalidate = oc_tool('ocvalidate')
    for name in ('config-accel.plist', 'config-install.plist'):
        path = os.path.join(oc, name)
        with open(path, 'rb') as f:
            config = plistlib.load(f)
        config['PlatformInfo']['Generic'].update({k: vals[k] for k in ('SystemProductName',) + KEYS})
        for drv in config['UEFI']['Drivers']:
            if drv['Path'] == 'HfsPlus.efi':
                drv['Enabled'] = True
                drv['Comment'] = 'acidanthera/OcBinaryData (HFS+ image of the macOS recovery)'
        with open(path, 'wb') as f:
            plistlib.dump(config, f)
        result = subprocess.run([ocvalidate, path], capture_output=True, text=True)
        if result.returncode != 0 or 'No issues found' not in result.stdout:
            sys.exit(f'error: ocvalidate rejected {name}:\n{result.stdout}{result.stderr}')
        print(f'  {name}: ocvalidate OK')
    default = 'config-install.plist' if installer else 'config-accel.plist'
    shutil.copy(os.path.join(oc, default), os.path.join(oc, 'config.plist'))
    print(f'  config.plist = {default}')
    return efi


def download_recovery():
    out = os.path.join(DIST, 'com.apple.recovery.boot')
    if os.path.exists(os.path.join(out, 'BaseSystem.dmg')):
        print('  recovery: already in dist/com.apple.recovery.boot (delete the folder to download it again)')
        return out
    # download into a temporary folder: macrecovery checks the image against its chunklist and exits with an error if
    # it does not match, so only a complete image becomes dist/com.apple.recovery.boot
    part = os.path.join(DIST, 'recovery.part')
    if os.path.exists(part):
        shutil.rmtree(part)
    macrecovery = os.path.join(oc_utilities(), 'macrecovery')
    try:
        subprocess.run([sys.executable, 'macrecovery.py', '-b', BOARD, '-m', '00000000000000000', '-os', 'latest',
                        '-o', part, 'download'], check=True, cwd=macrecovery)
    except subprocess.CalledProcessError:
        sys.exit('error: the recovery download failed; run it again')
    os.replace(part, out)
    return out


def main():
    parser = argparse.ArgumentParser(description='Build dist/EFI for the Dell Vostro 3520.')
    parser.add_argument('--installer', action='store_true',
                        help='config.plist = the safe config (to install macOS); config-accel.plist stays next to it')
    parser.add_argument('--recovery', action='store_true', help='also download the macOS Tahoe recovery (~1 GB)')
    args = parser.parse_args()

    print('== EFI')
    efi = build_efi(load_smbios(), args.installer)
    recovery = None
    if args.recovery:
        print('== macOS recovery')
        recovery = download_recovery()

    print(f'\nDone: {os.path.relpath(efi, ROOT)}' + (f' and {os.path.relpath(recovery, ROOT)}' if recovery else ''))
    print('Copy them to the root of a FAT32 partition on the USB drive (or to your EFI partition).')
    print('Do not publish dist/ or smbios.local: they contain your serial numbers.')


if __name__ == '__main__':
    main()
