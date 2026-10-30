#!/bin/sh
# Builds the OpenCore EFI for the Dell Vostro 3520 with YOUR OWN serial numbers: same as  python3 make-efi.py
#   sh make-efi.sh                          dist/EFI, config.plist = accelerated
#   sh make-efi.sh --installer --recovery   install USB: config.plist = safe, plus the macOS recovery
# Works on Linux and macOS (needs python3 and curl). See make-efi.py for what it does.
exec python3 "$(dirname "$0")/make-efi.py" "$@"
