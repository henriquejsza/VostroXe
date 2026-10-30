#!/bin/zsh
# hdmi-flags.sh — define o boot-arg ngreenhdmiflags=<valor> no config.plist da EFI (OpenCore), no macOS.
# NootedGreen re-estampa as flags do conector externo (con1); isso muda as máscaras AGDC que o displaypolicyd
# lê (portmap/mst/ddc/aux). 0x402 = DDC limpo (ddc=1, aux=0, mst=0). Padrão do kext sem o arg = 0x401 (como hoje).
#
#   zsh hdmi-flags.sh <valor>   base = config-accel.plist; tira todo ngreenhdmiflags e acrescenta ngreenhdmiflags=<valor>
#                               (<valor> em hex 0x... ou decimal). Grava config.plist.
#   zsh hdmi-flags.sh off       config.plist = cópia de config-accel.plist (a config acelerada do make-efi.py).
#   zsh hdmi-flags.sh status    mostra os boot-args de config.plist e de config-accel.plist, e `nvram boot-args`.
#
# NÃO mexe em kexts, em config-accel.plist, nem em nenhum outro arquivo. Desmonta o que montou.
# Base de tudo: o config-accel.plist que o make-efi.py põe na EFI ao lado do config.plist.
set -e
setopt extended_glob          # habilita os padrões ## (um ou mais) e <0-> (número) no case abaixo
G=7C436110-AB2A-4BBB-A880-FE41995C9F82
PB=${HDMI_FLAGS_PB:-/usr/libexec/PlistBuddy}
ok(){ print -P "  %F{green}\u2713%f $1"; }
fail(){ print -P "%F{red}\u2717%f $1"; exit 1; }
[[ $(id -u) -eq 0 ]] || exec sudo -p "senha de administrador: " zsh "$0" "$@"

get_ba(){ nvram boot-args 2>/dev/null | sed $'s/^boot-args\t//'; }
oc_dev(){ diskutil list | awk '/OPENCORE/{print $NF; exit}'; }
WE_MOUNTED=0                 # 1 somente se ESTE script montou a OPENCORE (para desmontar so' o que montou)
# HDMI_FLAGS_OC: override do ponto de montagem (apenas para o teste no Linux; no macOS fica vazio).
mount_oc(){
  if [[ -n ${HDMI_FLAGS_OC:-} ]]; then          # teste: arvore OPENCORE falsa, sem diskutil
    OC=$HDMI_FLAGS_OC
  else
    local d before; d=$(oc_dev); [[ -n $d ]] || fail "pendrive (OPENCORE) nao encontrado."
    before=$(diskutil info -plist "$d" 2>/dev/null | plutil -extract MountPoint raw -o - - 2>/dev/null || true)
    if [[ -z $before ]]; then                   # nao estava montada -> montamos nos
      diskutil mount "$d" >/dev/null 2>&1 && WE_MOUNTED=1 || true
    fi
    OC=$(diskutil info -plist "$d" 2>/dev/null | plutil -extract MountPoint raw -o - - 2>/dev/null || true); [[ -n $OC ]] || OC=/Volumes/OPENCORE
  fi
  CFG=$OC/EFI/OC/config.plist; ACC=$OC/EFI/OC/config-accel.plist
  [[ -f $CFG ]] || fail "nao achei $CFG"; }
umount_oc(){                                     # desmonta somente se ESTE script montou
  [[ $WE_MOUNTED -eq 1 ]] || return 0
  dot_clean -m "$OC" 2>/dev/null || true; diskutil unmount "$OC" >/dev/null 2>&1 || true; }

# Tira TODO token ngreenhdmiflags=... e acrescenta ngreenhdmiflags=<valor> no fim, preservando a ordem dos demais.
set_flags(){
  local base="$1" val="$2" out="" tok
  for tok in ${(s: :)base}; do
    case $tok in
      ngreenhdmiflags=*) ;;                 # remove qualquer token de flags existente
      *) out+="$tok " ;;
    esac
  done
  print -r -- "${out}ngreenhdmiflags=${val}"
}

# Tira ngreenhdmiflags=... E ngreenhdmiddc=... e acrescenta o conjunto $2 no fim (para o comando "test").
set_tokens(){
  local base="$1" tail="$2" out="" tok
  for tok in ${(s: :)base}; do
    case $tok in
      ngreenhdmiflags=*|ngreenhdmiddc=*|ngreenhdmipw=*|ngreenhdmitrig=*|ngreenhdmiregs=*|ngreenhdmilight=*|ngreenhdmimodeset=*) ;;  # tokens de HDMI que gerenciamos
      *) out+="$tok " ;;
    esac
  done
  print -r -- "${out}${tail}"
}

base_ba(){ $PB -c "Print :NVRAM:Add:$G:boot-args" "$ACC" 2>/dev/null; }
set_add(){ $PB -c "Set :NVRAM:Add:$G:boot-args $2" "$1" 2>/dev/null || $PB -c "Add :NVRAM:Add:$G:boot-args string $2" "$1"; }
ensure_del(){ $PB -c "Print :NVRAM:Delete:$G" "$1" >/dev/null 2>&1 || $PB -c "Add :NVRAM:Delete:$G array" "$1";
  $PB -c "Print :NVRAM:Delete:$G" "$1" 2>/dev/null | grep -qx '    boot-args' || $PB -c "Add :NVRAM:Delete:$G: string boot-args" "$1"; }

# Monta config.plist = cópia de config-accel.plist com os boot-args $1; valida; só então substitui. Backup 1x.
write_cfg(){
  local newba="$1" tmp back method=""
  [[ -f $ACC ]] || fail "nao achei config-accel.plist na EFI (o make-efi.py gera esse arquivo)."
  [[ -f $OC/EFI/OC/config.plist.pre-flags ]] || cp "$CFG" "$OC/EFI/OC/config.plist.pre-flags"

  # Tentativa 1: PlistBuddy Set + leitura de volta. O PlistBuddy pode quebrar um valor com espacos no "Set";
  # por isso lemos os boot-args DE VOLTA e so' aceitamos se forem identicos ao esperado.
  tmp=$(mktemp)
  cp "$ACC" "$tmp"
  set_add "$tmp" "$newba"
  ensure_del "$tmp"
  back=$($PB -c "Print :NVRAM:Add:$G:boot-args" "$tmp" 2>/dev/null)
  if [[ "$back" == "$newba" ]]; then
    method="PlistBuddy Set"
  else
    # Tentativa 2 (fallback): recomeca de uma COPIA NOVA do config-accel.plist e usa
    #   plutil -replace "NVRAM.Add.<GUID>.boot-args" -string "<boot-args>" <tmp>
    # Keypath do plutil = key-value coding path separado por '.', entao os '-' do GUID NAO precisam de escape
    # (so' '.' separa componentes; o GUID nao tem '.'). O valor vem como argumento posicional depois de -string.
    # VERIFICADO (man plutil, macOS 12+): -replace keypath -type value sobrescreve um valor existente; -string = UTF8.
    # NAO VERIFICADO: se um valor que comeca com '-' (ex.: "-ngreentglwithgfx ...") e' aceito como posicional e nao
    # confundido com uma opcao. Por isso a leitura de volta com PlistBuddy abaixo e' obrigatoria: se o plutil
    # engolir/alterar o valor, "back" != "$newba" e abortamos sem tocar no config.plist.
    rm -f "$tmp"; tmp=$(mktemp)
    cp "$ACC" "$tmp"
    ensure_del "$tmp"
    plutil -replace "NVRAM.Add.$G.boot-args" -string "$newba" "$tmp" 2>/dev/null || true
    back=$($PB -c "Print :NVRAM:Add:$G:boot-args" "$tmp" 2>/dev/null)
    if [[ "$back" == "$newba" ]]; then
      method="plutil -replace (fallback)"
    else
      rm -f "$tmp"
      print -P "%F{red}Os dois metodos (PlistBuddy e plutil) falharam ao gravar os boot-args. Nada alterado.%f"
      print -r -- "  esperado          : $newba"
      print -r -- "  gravado (ultimo)  : $back"
      print -P "%F{yellow}Volte para o Linux e edite o config.plist por la (monte a OPENCORE e ajuste os boot-args a mao).%f"
      exit 1
    fi
  fi

  # Guardas finais (para os dois metodos): NVRAM:Delete precisa conter boot-args e o plist tem de passar no lint.
  $PB -c "Print :NVRAM:Delete:$G" "$tmp" 2>/dev/null | grep -qx '    boot-args' || { rm -f "$tmp"; fail "NVRAM:Delete sem boot-args; nada alterado."; }
  plutil -lint "$tmp" >/dev/null || { rm -f "$tmp"; fail "config invalido (plutil). Nada alterado."; }
  cp "$tmp" "$CFG"; rm -f "$tmp"
  ok "config.plist gravado via: $method"
}

cmd=${1:-}
case "$cmd" in
status)
  mount_oc
  print "config.plist ATIVO  boot-args:"; $PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null | fold -s -w 100 | sed 's/^/  /'
  print "config-accel.plist  boot-args:"; $PB -c "Print :NVRAM:Add:$G:boot-args" "$ACC" 2>/dev/null | fold -s -w 100 | sed 's/^/  /'
  print "nvram boot-args (boot atual): $(get_ba)"
  umount_oc; exit 0 ;;
off)
  mount_oc
  [[ -f $ACC ]] || fail "nao achei config-accel.plist na EFI."
  plutil -lint "$ACC" >/dev/null || fail "config-accel.plist invalido (plutil). Nada alterado."
  [[ -f $OC/EFI/OC/config.plist.pre-flags ]] || cp "$CFG" "$OC/EFI/OC/config.plist.pre-flags"
  cp "$ACC" "$CFG"
  ok "config.plist = config-accel.plist (sem ngreenhdmiflags)"
  print "  boot-args: $($PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null)"
  umount_oc; print "Pronto. Reinicie."; exit 0 ;;
"")
  print "uso: zsh hdmi-flags.sh test | <valor 0x.. ou decimal> | off | status"
  print "  test | testregs (snapshot) | testlight (FASE 1: energia+clock) | testmodeset (FASE 2 diag) | forcemodeset (FASE 2 forca) | <valor> | off | status"; exit 1 ;;
test)
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_tokens "$base" "ngreenhdmiflags=0x202 ngreenhdmiddc=1")
  write_cfg "$new"
  ok "config.plist = config-accel + ngreenhdmiflags=0x202 ngreenhdmiddc=1"
  print "  boot-args: $($PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
testpw)
  # test + o power well do pipe B (PW_B) e o gatilho de hotplug: o monitor ja e detectado, falta acender o pipe.
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_tokens "$base" "ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmipw=1 ngreenhdmitrig=1")
  write_cfg "$new"
  ok "config.plist = config-accel + ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmipw=1 ngreenhdmitrig=1"
  print "  boot-args: $($PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
testlight)
  # FASE 1 do acendimento do pipe B: energia (PG2->PW_B->DDI-B) + desbloqueio do clock da DDI-B. SEM varredura.
  # Inclui o snapshot read-only (regs) para medir o efeito. Sem trig/pw: tela interna estavel.
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_tokens "$base" "ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmilight=1 ngreenhdmiregs=1")
  write_cfg "$new"
  ok "config.plist = config-accel + flags=0x202 ddc=1 light=1 regs=1 (FASE 1: energia+clock, sem varredura)"
  print "  boot-args: $($PB -c \"Print :NVRAM:Add:$G:boot-args\" \"$CFG\" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
testmodeset)
  # FASE 2 diagnostico: deteccao (flags+ddc) + ngreenhdmimodeset=1 (so LOGA o state do path e o TRANS_CONF_B do FB1
  # no hook hwRegsNeedUpdate). NAO muda nada no hardware -> tela interna estavel, 100% seguro.
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_tokens "$base" "ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmimodeset=1")
  write_cfg "$new"
  ok "config.plist = config-accel + flags=0x202 ddc=1 modeset=1 (FASE 2 DIAGNOSTICO, seguro)"
  print "  boot-args: $($PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
forcemodeset)
  # FASE 2 FORCA: deteccao + ngreenhdmimodeset=2 (forca o modeset completo do FB1 -> LightUpTMDS da Apple) + regs p/ medir.
  # RISCO: o LightUpTMDS chama enableClocks, que pode reprogramar o DPLL compartilhado com a tela INTERNA -> ela pode
  # piscar/apagar. Reversivel reiniciando (ou 'off'). So rode com como reiniciar a mao.
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_tokens "$base" "ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmimodeset=2 ngreenhdmiregs=1")
  write_cfg "$new"
  ok "config.plist = config-accel + flags=0x202 ddc=1 modeset=2 regs=1 (FASE 2 FORCA)"
  print "  boot-args: $($PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
testregs)
  # test + snapshot READ-ONLY dos registradores do pipe B (ngreenhdmiregs). Sem trig/pw: tela interna estavel.
  # O gancho de hotplug que dispara o snapshot ja e instalado pelo ngreenhdmiedid/sink da config base.
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_tokens "$base" "ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmiregs=1")
  write_cfg "$new"
  ok "config.plist = config-accel + ngreenhdmiflags=0x202 ngreenhdmiddc=1 ngreenhdmiregs=1"
  print "  boot-args: $($PB -c \"Print :NVRAM:Add:$G:boot-args\" \"$CFG\" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
*)
  # <valor>: só hex (0x...) ou decimal; qualquer outra coisa é rejeitada.
  case "$cmd" in
    0x[0-9A-Fa-f]##) ;;
    <0-> ) ;;
    *) fail "valor invalido: '$cmd'. Use hex (ex: 0x402) ou decimal (ex: 1026)." ;;
  esac
  mount_oc
  base=$(base_ba); [[ -n $base ]] || fail "config-accel.plist sem boot-args em :NVRAM:Add:$G"
  new=$(set_flags "$base" "$cmd")
  write_cfg "$new"
  ok "config.plist = config-accel + ngreenhdmiflags=$cmd"
  print "  boot-args: $($PB -c "Print :NVRAM:Add:$G:boot-args" "$CFG" 2>/dev/null)"
  $PB -c "Print :NVRAM:Delete:$G" "$CFG" 2>/dev/null | grep -qx '    boot-args' && ok "boot-args em NVRAM:Delete (OpenCore reescreve no boot)" || fail "Delete nao ficou certo"
  umount_oc; print "Pronto. Reinicie com o cabo HDMI conectado."; exit 0 ;;
esac
