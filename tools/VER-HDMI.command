#!/bin/zsh
# Dois cliques (macOS): junta no pendrive o que eu preciso para ver a HDMI neste boot: as telas que o macOS vê, os
# boot-args que o kernel recebeu, as propriedades de diagnóstico do NootedGreen (ngreen-hdmi13…), as linhas da HDMI
# no log do kernel e o displaypolicyd. Só lê, não muda nada. Pede a senha uma vez.
D=${0:A:h}
OUT="$D/hdmi-seq-$(date +%Y%m%d-%H%M%S).txt"
echo "== senha do macOS (uma vez, só para ler os logs):"; sudo -v || exit 1
echo "== coletando…"
{
echo "== $(date '+%d/%m %H:%M:%S')  macOS $(sw_vers -productVersion) ($(sw_vers -buildVersion))"
echo "== boot-args recebidos pelo kernel:"; sysctl -n kern.bootargs
echo; echo "== telas (system_profiler)"; system_profiler SPDisplaysDataType 2>/dev/null
echo; echo "== NootedGreen: propriedades de diagnóstico da HDMI (IORegistry)"
ioreg -lw0 2>/dev/null | grep -oE '"ngreen-(hdmi[A-Za-z0-9-]*|edid)" = .{0,900}' | sort -u
echo; echo "== kernel: linhas da HDMI neste boot"
sudo log show --last boot --style compact --predicate 'process == "kernel" AND (eventMessage CONTAINS[c] "hdmi" OR eventMessage CONTAINS "FB1" OR eventMessage CONTAINS "LightUpTMDS" OR eventMessage CONTAINS "runAUXCommand" OR eventMessage CONTAINS "DivideByZero" OR eventMessage CONTAINS "hotplug" OR eventMessage CONTAINS "Hotplug")' 2>/dev/null | head -n 20000
echo; echo "== displaypolicyd (log unificado deste boot, final)"
sudo log show --last boot --style compact --predicate 'process == "displaypolicyd"' 2>/dev/null | tail -n 300
echo; echo "== displaypolicyd (arquivo próprio, final)"
sudo tail -n 150 /private/var/log/displaypolicy/displaypolicyd.log 2>/dev/null || echo "(sem o arquivo)"
echo; echo "== panic mais novo:"; ls -t /Library/Logs/DiagnosticReports/*.panic 2>/dev/null | head -1
} > "$OUT" 2>&1
sync
echo "== pronto: ${OUT:t} ($(wc -l < "$OUT" | tr -d ' ') linhas)"
echo ">>> Volte pro Linux e me avise."
read -k 1 "?Aperte uma tecla para fechar. "
