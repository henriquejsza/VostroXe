#!/bin/zsh
# Dell Vostro 3520 — macOS Tahoe com aceleração da Iris Xe E som interno, tudo junto.
# Reconstrói o NootedGreen com as correções dos dois panics de boot (divisão por zero no timing do framebuffer
# e __cxa_pure_virtual em probePortState), instala o som interno (CS8409HDA + XeSpeakers) e liga a config acelerada
# já com o kext de som. Rode no macOS.
#
#   zsh /Volumes/MACINSTALL/tudo.sh           compila tudo, instala na EFI do pendrive e liga a config acelerada. REINICIE.
#   zsh /Volumes/MACINSTALL/tudo.sh testar    (depois do reboot) confere a tela acelerada e faz o autoteste do som
#   zsh /Volumes/MACINSTALL/tudo.sh status    mostra o estado
#   zsh /Volumes/MACINSTALL/tudo.sh off       volta para a config SEGURA (sem aceleração) e tira o som
#
# Correções do NootedGreen ligadas por padrão; se a tela der problema dá para desligar cada uma por boot-arg:
#   -ngreennoportmode   desliga a correção do probePortState (panic __cxa_pure_virtual)
#   ngreenportmode=N     muda o modo de porta devolvido pelo stub (0..4, padrão 0)
#   -ngreennofixbootmode desliga o worker de timing (inclui a correção da divisão por zero)
# Se não iniciar: desligue no botão, entre no Linux e copie config-install.plist por cima de config.plist (EFI/OC).
set -e

MI=${0:A:h}
KIT=$MI/CS8409HDA
NG_SRC=$KIT/nootedgreen/src/NootedGreen          # fonte do NootedGreen já com as correções (vem do pendrive)
REPO=https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe.git
COMMIT=6b5f049
DIR=$HOME/Hackintosh-XPS13Plus-IrisXe-Tahoe
BUILD_REQ=25G241

ok()   { print -P "  %F{green}✓%f $1"; }
step() { print; print -P "%F{cyan}%B$1%b%f"; }
fail() { print; print -P "%F{red}✗%f $1"; exit 1; }

oc_dev() { diskutil list | awk '/OPENCORE/ {print $NF; exit}'; }
mount_oc() {
  local dev; dev=$(oc_dev)
  [[ -n $dev ]] || fail "não achei o pendrive (partição OPENCORE). Conecte o pendrive e rode de novo."
  sudo diskutil mount $dev >/dev/null 2>&1 || true
  OC=$(diskutil info -plist $dev | plutil -extract MountPoint raw -o - - 2>/dev/null || true)
  [[ -n $OC ]] || OC=/Volumes/OPENCORE
  [[ -f $OC/EFI/OC/config-accel.plist && -f $OC/EFI/OC/config-install.plist ]] ||
    fail "não achei a EFI do Vostro na partição OPENCORE ($dev)."
}
umount_oc() { sudo dot_clean -m "$OC" 2>/dev/null || true; sudo diskutil unmount "$OC" >/dev/null 2>&1 || true; }

show_status() {
  print "macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion))"
  local gpu=$(ioreg -r -c IOPCIDevice -n IGPU -d 1 2>/dev/null)
  [[ $gpu == *'"device-id" = <499a0000>'* ]] && ok "GPU como Tiger Lake (9A49): config acelerada" ||
    print "  GPU com o ID real (46A8): config segura"
  kmutil showloaded 2>/dev/null | grep -q NootedGreen && ok "NootedGreen carregado" || print "  NootedGreen não carregado"
  kmutil showloaded 2>/dev/null | grep -q local.xe.CS8409HDA && ok "CS8409HDA (som) carregado" || print "  CS8409HDA não carregado"
  system_profiler SPAudioDataType 2>/dev/null | grep -q "Alto-falantes internos" && ok "\"Alto-falantes internos\" disponível" || true
}

case ${1:-} in
  status) show_status; exit 0 ;;
  testar)
    step "Tela"
    BUILD=$(sw_vers -buildVersion)
    kmutil showloaded 2>/dev/null | grep -q NootedGreen && ok "NootedGreen carregado (boot acelerado OK)" ||
      print "  NootedGreen não carregado — você está na config segura?"
    step "Som (bipes + autoteste)"
    zsh "$MI/audio.sh" testar
    exit $? ;;
  off)
    zsh "$MI/audio.sh" off || true
    mount_oc
    sudo cp "$OC/EFI/OC/config-install.plist" "$OC/EFI/OC/config.plist"
    umount_oc
    ok "config segura ligada e som desligado no pendrive. Reinicie."
    exit 0 ;;
  "") ;;
  *) print "uso: zsh tudo.sh [testar|status|off]"; exit 1 ;;
esac

step "1/5 Verificações"
[[ $(uname -m) == x86_64 ]] || fail "isto só funciona em Mac Intel."
BUILD=$(sw_vers -buildVersion)
[[ $BUILD == $BUILD_REQ ]] || fail "este macOS é o $(sw_vers -productVersion) ($BUILD); a aceleração precisa do 26.7.1 ($BUILD_REQ).
  Atualize em Ajustes do Sistema > Geral > Atualização de Software e rode de novo."
ok "macOS $(sw_vers -productVersion) ($BUILD)"
[[ -d $NG_SRC ]] || fail "não achei o fonte corrigido do NootedGreen em $NG_SRC (o pendrive foi preparado no Linux com make-kit.sh?)"
ok "fonte corrigido do NootedGreen presente"
[[ -n $(oc_dev) ]] || fail "não achei o pendrive (partição OPENCORE)."
ok "pendrive conectado"
xcode-select -p >/dev/null 2>&1 || { print "  instale as Command Line Tools (vai abrir a janela: clique em Instalar)"; xcode-select --install >/dev/null 2>&1 || true; until xcode-select -p >/dev/null 2>&1; do sleep 10; done; }
ok "Command Line Tools"
curl -fsI --max-time 20 https://github.com >/dev/null 2>&1 || fail "sem internet (precisa para baixar Lilu/MacKernelSDK na 1ª compilação). Conecte o cabo ou o celular por USB."
ok "internet"

step "2/5 Projeto base (commit $COMMIT) + correções"
[[ -d $DIR/.git ]] || git clone -q $REPO $DIR
git -C $DIR fetch -q origin 2>/dev/null || true
git -C $DIR checkout -q $COMMIT
# sobrepõe o NootedGreen já corrigido (o commit $COMMIT ainda não tem as correções dos panics)
rm -rf "$DIR/src/NootedGreen"
ditto --norsrc --noextattr "$NG_SRC" "$DIR/src/NootedGreen"
ok "NootedGreen corrigido aplicado sobre o clone"

step "3/5 Compilar e instalar o NootedGreen"
zsh "$DIR/build-nootedgreen.sh"
[[ -d $DIR/build/NootedGreen.kext ]] || fail "a compilação do NootedGreen falhou"
codesign -v "$DIR/build/NootedGreen.kext" || fail "assinatura do NootedGreen falhou"
mount_oc
K=$OC/EFI/OC/Kexts/NootedGreen.kext
[[ -d $OC/NootedGreen.kext.original ]] || sudo ditto --norsrc --noextattr "$K" "$OC/NootedGreen.kext.original"
sudo rm -rf "$K"
sudo ditto --norsrc --noextattr --noqtn --noacl "$DIR/build/NootedGreen.kext" "$K"
ok "NootedGreen recém-compilado na EFI"
umount_oc

step "4/5 Som interno (compila e põe o CS8409HDA.kext na EFI, nas 3 configs)"
zsh "$MI/audio.sh"      # build + kext nas 3 configs (config.plist, config-accel.plist, config-install.plist)

step "5/5 Ligar a config acelerada (já com o som)"
mount_oc
sudo cp "$OC/EFI/OC/config-accel.plist" "$OC/EFI/OC/config.plist"
umount_oc
ok "config acelerada ligada (Iris Xe + som)"

print
print -P "%BPronto.%b Reinicie com o pendrive conectado. Se tiver um monitor/cabo HDMI, deixe DESCONECTADO neste primeiro boot."
print "  Depois do boot:  zsh /Volumes/MACINSTALL/tudo.sh testar"
print "  Estado:          zsh /Volumes/MACINSTALL/tudo.sh status"
print "  Voltar à segura: zsh /Volumes/MACINSTALL/tudo.sh off"
print "  Não iniciou? Botão de desligar, entre no Linux e copie config-install.plist por cima de config.plist (EFI/OC)."
