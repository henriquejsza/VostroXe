#!/bin/zsh
# Concede (ou remove) permissões de privacidade do macOS (TCC) para apps de terceiros.
#
# Por quê: os boot-args têm amfi_get_out_of_my_way=1, que a aceleração gráfica precisa (driver Metal e plugins
# ad-hoc em /Library/GPUBundles). Com ele, o tccd trata todo app de terceiros como "CS_PLATFORM_BINARY set but not
# AppleSigned; prompt policy is Deny": o pedido de permissão nunca aparece, as chaves em Ajustes do Sistema ›
# Privacidade e Segurança não ficam ligadas, e o app recebe "negado" sem aviso (microfone mudo, OBS sem telas).
# Apps da Apple (Terminal, QuickTime, Gravador, Cmd+Shift+5) não são afetados.
# Este script grava a permissão direto nos bancos do TCC, no formato que o próprio tccd usa, com o requisito de
# assinatura do app: vale só para o app verdadeiro e continua valendo depois de atualizações dele.
#
# Uso:   sudo zsh tools/tcc-permitir.sh <serviço> <app> [<app> ...]
#        sudo zsh tools/tcc-permitir.sh --remover <serviço> <app> [...]
#        sudo zsh tools/tcc-permitir.sh --listar
# Serviços: microfone, camera, tela (gravação de tela), audio-sistema (só o áudio do sistema),
#           monitor-entrada (atalhos globais), acessibilidade
# App: nome em /Applications ("Google Chrome"), caminho de um .app, ou bundle id (com.hnc.Discord).
# Depois: feche e abra o app de novo.
# Cada mudança faz antes um backup dos dois bancos em ~/Library/Application Support/xe-tcc/<data-hora>/.
set -euo pipefail
[[ $EUID -eq 0 ]] || { echo "rode com: sudo zsh $0 ..."; exit 1; }
[[ -n ${SUDO_USER:-} && $SUDO_USER != root ]] || { echo "rode com sudo a partir da sua conta (não como root)"; exit 1; }
U=$SUDO_USER
H=$(dscl . -read /Users/$U NFSHomeDirectory | awk '{print $2}')
UDB="$H/Library/Application Support/com.apple.TCC/TCC.db"
SDB="/Library/Application Support/com.apple.TCC/TCC.db"
BKROOT="$H/Library/Application Support/xe-tcc"
COLS="service, client, client_type, auth_value, auth_reason, auth_version, csreq, policy_id, indirect_object_identifier_type, indirect_object_identifier, indirect_object_code_identity, flags, last_modified, pid, pid_version, boot_uuid, last_reminded"
sqlite3() { command sqlite3 -cmd ".timeout 5000" "$@"; }   # o tccd pode estar com o banco aberto

# serviço -> "kTCCService... banco" (qual tccd responde, visto no log: o do usuário ou o do sistema)
svc_of() {
  case $1 in
    microfone) echo "kTCCServiceMicrophone user";;
    camera) echo "kTCCServiceCamera user";;
    audio-sistema) echo "kTCCServiceAudioCapture user";;
    tela) echo "kTCCServiceScreenCapture system";;
    monitor-entrada) echo "kTCCServiceListenEvent system";;
    acessibilidade) echo "kTCCServiceAccessibility system";;
    *) return 1;;
  esac
}

app_path() {
  local a=$1 p
  if [[ $a == *.app && -d $a ]]; then print -r -- ${a:A}; return 0; fi
  for p in "/Applications/$a.app" "/Applications/Utilities/$a.app" "$H/Applications/$a.app"; do
    [[ -d $p ]] && { print -r -- $p; return 0; }
  done
  if [[ $a =~ '^[A-Za-z0-9-]+(\.[A-Za-z0-9-]+)+$' ]]; then   # bundle id
    p=$(mdfind "kMDItemCFBundleIdentifier == '$a'" 2>/dev/null | grep '\.app$' | head -1 || true)
    [[ -n $p ]] && { print -r -- $p; return 0; }
  fi
  return 1
}

listar() {
  local db
  for db in "$UDB" "$SDB"; do
    echo "== ${db/#$H/~}"
    sqlite3 -separator '  ' "$db" "select replace(service,'kTCCService',''), client, case auth_value when 2 then 'permitido' when 0 then 'negado' else auth_value end from access where client not like 'com.apple.%' and client not like '/%' order by service, client;"
  done
}

backup() {
  [[ -n ${BK:-} ]] && return 0
  BK="$BKROOT/$(date +%Y%m%d-%H%M%S)-$$"   # PID: duas execuções no mesmo segundo não se sobrescrevem
  mkdir -p "$BK"
  sqlite3 "$UDB" ".backup '$BK/TCC-usuario.db'"
  sqlite3 "$SDB" ".backup '$BK/TCC-sistema.db'"
  chown -R "${U}:staff" "$BKROOT"; chmod 700 "$BKROOT" "$BK"
  echo "backup dos bancos: $BK"
}

[[ ${1:-} == --listar ]] && { listar; exit 0; }
REMOVER=0
[[ ${1:-} == --remover ]] && { REMOVER=1; shift; }
(( $# >= 2 )) || { sed -n '12,19p' "$0"; exit 1; }
read SVC WHICH <<< "$(svc_of "$1" || true)"
[[ -n ${SVC:-} ]] || { echo "serviço desconhecido: $1 (use microfone, camera, tela, audio-sistema, monitor-entrada, acessibilidade)"; exit 1; }
[[ $WHICH == user ]] && DB=$UDB || DB=$SDB
shift

changed=0
for a in "$@"; do
  app=$(app_path "$a") || { echo "  $a: app não encontrado, pulei"; continue; }
  id=$(/usr/libexec/PlistBuddy -c 'Print :CFBundleIdentifier' "$app/Contents/Info.plist" 2>/dev/null || true)
  [[ $id =~ '^[A-Za-z0-9-]+(\.[A-Za-z0-9-]+)+$' ]] || { echo "  $a: bundle id inválido ($id), pulei"; continue; }
  backup
  if (( REMOVER )); then
    sqlite3 "$DB" "DELETE FROM access WHERE service='$SVC' AND client='$id' AND client_type=0;"
    echo "  removido: $id (${SVC#kTCCService})"; changed=1; continue
  fi
  req=$(codesign -d -r- "$app" 2>&1 | sed -n 's/^designated => //p')
  [[ -n $req ]] || { echo "  $id: sem requisito de assinatura (app sem assinatura?), pulei"; continue; }
  tmp=$(mktemp)
  csreq -r "=$req" -b "$tmp"
  hex=$(xxd -p "$tmp" | tr -d '\n')
  rm -f "$tmp"
  now=$(date +%s)
  # auth_value 2 = permitido, auth_reason 3 = definido pelo usuário (o que a chave dos Ajustes grava)
  sqlite3 "$DB" "INSERT OR REPLACE INTO access ($COLS) VALUES ('$SVC', '$id', 0, 2, 3, 1, X'$hex', NULL, NULL, 'UNUSED', NULL, 0, $now, NULL, NULL, 'UNUSED', $now);"
  v=$(sqlite3 "$DB" "SELECT auth_value FROM access WHERE service='$SVC' AND client='$id' AND client_type=0;")
  [[ $v == 2 ]] && echo "  permitido: $id (${SVC#kTCCService})" || echo "  FALHOU: $id (auth_value=$v)"
  changed=1
done
if (( changed )); then
  for db in "$UDB" "$SDB"; do
    [[ $(sqlite3 "$db" 'PRAGMA integrity_check;') == ok ]] || echo "AVISO: integrity_check falhou em $db (restaure de $BK)"
  done
  killall tccd 2>/dev/null || true   # o launchd reabre na hora; assim nada fica em cache
  echo "pronto: feche e abra os apps de novo"
fi
