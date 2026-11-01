#!/bin/zsh
# Dois cliques (macOS): coleta os logs da tentativa de boot acelerado para o pendrive, pra eu ler no Linux.
# Rode depois de uma tentativa — mesmo que tenha dado panic e você tenha voltado a um macOS que liga.
# Pode pedir sua senha uma vez.
D=${0:A:h}
OUT="$D/accel-logs-$(date +%Y%m%d-%H%M%S)"
mkdir -p "$OUT"
echo "== coletando para $OUT (pode pedir senha)…"
# 1) relatórios de panic/crash (texto/JSON) — persistem entre boots
sudo cp /Library/Logs/DiagnosticReports/*.panic "$OUT/" 2>/dev/null
sudo cp /Library/Logs/DiagnosticReports/*.ips   "$OUT/" 2>/dev/null
# 2) log unificado das últimas ~2h (pega o boot acelerado anterior), filtrado pelo nosso stack
log show --last 2h --predicate 'process == "WindowServer" OR process == "kernel" AND (eventMessage CONTAINS[c] "ngreen" OR eventMessage CONTAINS "DYLD" OR eventMessage CONTAINS[c] "xedrv" OR eventMessage CONTAINS[c] "IOAccel" OR eventMessage CONTAINS "AGDP" OR eventMessage CONTAINS[c] "TGLGraphics" OR eventMessage CONTAINS "Gen11" OR eventMessage CONTAINS[c] "metal")' > "$OUT/log-2h.txt" 2>/dev/null
echo "   linhas no log-2h.txt: $(wc -l < "$OUT/log-2h.txt" 2>/dev/null)"
# 3) estado atual de GPU/Metal e kexts carregados
system_profiler SPDisplaysDataType > "$OUT/displays.txt" 2>/dev/null
kextstat 2>/dev/null | grep -iE 'ngreen|hookcase|TGLGraphics|Lilu|HookCase' > "$OUT/kextstat.txt"
ioreg -lw0 2>/dev/null | grep -iE 'AppleIntelTGLGraphics|IOAccelerator|MetalPluginName|PerformanceStatistics' > "$OUT/ioreg-gpu.txt"
sync
echo "== pronto. Conteúdo:"; ls -la "$OUT"
echo ">>> volte pro Linux e me avise; eu leio $OUT:t no pendrive."
read -k 1 "?Aperte uma tecla para fechar. "
