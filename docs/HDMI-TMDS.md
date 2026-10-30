# Referência HDMI/TMDS — Dell Vostro 3520 (ADL combo PHY B / DDI B)

Captura READ-ONLY do MMIO da GPU (i915) com o HDMI **aceso** vs **apagado** no Linux, nesta máquina.
Modo de referência: 1920x1080@60, TMDS 148.5 MHz, **pipe B, DDI B, PHY B** (i915_display_info).
Mode: `60 148500 1920 2008 2052 2200 1080 1084 1089 1125 0x40 0x5` (CEA 1080p60).
VBT: hdmi_level_shifter=29. GMBUS/DDC pin 2.

Estes são os valores-alvo que o modeset do NootedGreen deve atingir (comparar com o que a Apple
programa e corrigir as diferenças). `off`=HDMI apagado, `on`=HDMI aceso.

## Power wells (PWR_WELL_CTL / fuses) — habilita pipe B / DDI B / PHY B
```
0x045008  off=0xc043c000  on=0xc041c000
0x045254  off=0x00000000  on=0x00000001
0x045264  off=0x0ce2545a  on=0x0ccda5ee
0x045274  off=0x00000000  on=0x00000077
0x04528c  off=0x00000235  on=0x00000339
0x045300  off=0x0000ffff  on=0x0000032c
0x045304  off=0x0000000e  on=0x000007ba
0x045400  off=0x00000405  on=0x00001405
0x045404  off=0x00000c0f  on=0x00003c0f
0x04540c  off=0x00000405  on=0x00001405
0x045424  off=0x00000023  on=0x00000063
0x045450  off=0x00000001  on=0x00000005
0x045454  off=0x00000003  on=0x0000000f
0x04545c  off=0x00000001  on=0x00000005
0x046000  off=0x00780164  on=0x0038017e
0x046014  off=0x00000000  on=0xcc000000
0x046070  off=0xc000000e  on=0xc000000a
0x046144  off=0x00000000  on=0x20000000
```

## DPLL p/ pipe B (dividers do clock TMDS 148.5 MHz)
```
0x164b54  off=0xfda017fb  on=0xbda017fb
0x164b60  off=0x902effef  on=0x902dffef
0x164b74  off=0x0632f167  on=0x16329167
0x164c54  off=0x1ff801ff  on=0xbde01bfa
0x164c58  off=0x0003ff80  on=0x069da208
0x164c60  off=0x90007eff  on=0x902a7eff
0x164c64  off=0x0000003a  on=0x4080003a
0x164c68  off=0x04000000  on=0x04400008
0x164c70  off=0x3a008000  on=0x3a3d9800
0x164c74  off=0x0032b007  on=0x01329067
0x164c78  off=0x00000054  on=0x05d1d054
0x164c7c  off=0x771d29ff  on=0x1d0519a5
```

## DPCLKA_CFGCR0 — roteia/!gate do DPLL -> DDI B
```
0x164280  off=0x01e07804  on=0x01e07004
```

## DPCLKA_CFGCR0 (mirror)
```
0x164e80  off=0x01e07804  on=0x01e07004
```

## Combo PHY B (0x6C000): comp, CL_DW, TX swing/level-shifter HDMI
```
0x06c00c  off=0x2f770ff0  on=0xef770ff0
0x06c034  off=0x0000001c  on=0x000003e0
0x06c100  off=0x80005f30  on=0x80005f26
0x06c10c  off=0xc0607725  on=0xc0607625
0x06c1a4  off=0xb0060000  on=0xb0020000
0x06c808  off=0xf20004a1  on=0xf200734c
0x06c8c4  off=0x00002040  on=0x00002528
0x06c908  off=0xf20004a1  on=0xf200734c
0x06c9c4  off=0x00002040  on=0x00002528
0x06ca08  off=0xf20004a1  on=0xf200734c
0x06cac4  off=0x00002040  on=0x00002528
0x06cb08  off=0xf20004a1  on=0xf200734c
0x06cbc4  off=0x00002040  on=0x00002527
```

## DDI_BUF_CTL_B (0x64100): enable buffer DDI B
```
0x064100  off=0x00000080  on=0x80000000
```

## TRANS_DDI_FUNC_CTL_B (0x61400): modo HDMI, seleciona DDI B, enable
```
0x061400  off=0x00030000  on=0x90030000
```

## Transcoder B config/timing (0x61000-0x612ff)
```
0x06101c  off=0x00000000  on=0x077f0437
0x061058  off=0x00000000  on=0x40000000
0x061200  off=0x00000000  on=0x00011101
0x06129c  off=0x00000000  on=0x4fefc7cf
```

## TRANS_CONF_B (0x71008): enable transcoder B
```
0x071008  off=0x00000000  on=0xc0000000
```

## GMBUS (0xc5100): leitura de EDID (pino DDI B)
```
0x0c5100  off=0x00000000  on=0x0000000d
0x0c5104  off=0x08000000  on=0x420100a0
0x0c5108  off=0x00008800  on=0x00008200
0x0c510c  off=0x006ee604  on=0x00000000
0x0c5110  off=0x00000000  on=0x00000002
```

## Fixes opt-in (26/10) — veja docs/KERNEL-PATCHES.md e docs/CATALOG.md §3.3
Três boot-args novos, todos padrão off, inertes sem o argumento e no XPS 13 Plus:
`ngreenhdmilanes=1` (computeLaneCount devolve 4 lanes no con1), `ngreenhdmionline=1`
(getAttributeForConnection 'enab' = online no con1) e `ngreenhdmipw=1` (espelha o pedido de PW_3 da Apple
para PW_B em 0x45404 — alvo acima: off=0x0c0f → on=0x3c0f, bits 12/13 = PW_B STATE/REQ — no display 13).
Diagnóstico read-only que coleta tudo num arquivo: `tools/diagnostics/hdmi-diag.sh <rótulo>`.

### Iteração 2 (26/10) — correções
- **PW_B (ngreenhdmipw):** antes de pedir PW_B esperamos o STATE de PW_2 (bit 2 de 0x45404, i915
  ICL_PW_CTL_IDX_PW_2=1) subir, como o i915 faz. A chamada que carrega PW_3 (máscara 0xaa, bit 5) é
  `overridePowerWellsState(true)` @0x89970 (não `enableDisplayEngine`, que manda máscara 2 = PW_1). Como esse
  chamador não tem invocador provável no binário do FB, há um segundo gatilho no hotplug do HDMI. `ngreen-hdmipw`
  é publicado de um site IOService (o AppleIntelPowerWell tem super-metaclasse OSObject, não IOService).
- **Nomes de registrador no diag:** 0x164c54/0x164c58 **não** são DPLL CFGCR; são a região DIV0 do DPLL1
  (_TGL_DPLL1_DIV0 0x164C00). Os CFGCR reais (i915 intel_display_regs.h:3023-3034, usados pelo ADL-P via
  TGL_DPLL_CFGCR0/1): _TGL_DPLL0_CFGCR0 0x164284, _TGL_DPLL1_CFGCR0 0x16428C, o par CFGCR1 0x164288/0x164290,
  _TGL_DPLL0_DIV0 0x164B00, _TGL_DPLL1_DIV0 0x164C00. 0x46070 = BXT_DE_PLL_ENABLE, 0x46000 = CDCLK_CTL,
  0x45254 = _PIPEDMC_CONTROL_B. O script `hdmi-diag.sh` agora lê o bloco de captura em tempo de execução.
- **CDCLK (candidato de fase 2, F8 — sem código):** 0x46070 off=0xc000000e → on=0xc000000a é a razão do PLL do
  CDCLK 14 → 10, que na tabela ADL-P do i915 a refclk 38.4 MHz significa **179.2 MHz → 192 MHz**
  (intel_cdclk.c:1470-1471). A subida vem do mínimo de áudio HDMI (`intel_audio_min_cdclk`: `max(min, 2*96000)`
  = 192 MHz, intel_cdclk.c:3161). A tabela do TGL a 38.4 MHz **não tem** a entrada 179.2 (pula 172.8 → 192), então
  a lógica de CDCLK do driver TGL pode escolher um valor diferente no ADL-P. Registradores que o diag lê para
  conferir: CDCLK_CTL 0x46000 e BXT_DE_PLL_ENABLE 0x46070. Não implementado.

### Iteração 3 (26/10) — B1 (correção da iteração 2) e N3
- **B1 — o espelho dispara no init (a frase da iteração 2 estava errada).** A afirmação acima de que
  `overridePowerWellsState` "não tem invocador provável no binário" é **falsa** (a desassembly linear da iter 2
  dessincronizou). Com desassembly delimitado por símbolos (capstone + llvm-objdump), `overridePowerWellsState(bool)`
  @0x89722 tem **6** chamadores E8: `setDCState` @0x6556b (false), `enableSWDC6` @0x65d34 (false), `hwShutdown`
  @0x77a29 (false), **`AppleIntelPowerWell::init` @0x8817a (true)**, `enableDisplayEngine` @0x886c4 (false) e
  **`restorePowerWellsState` @0x8c12e (true)**. A ramificação true chama `hwSetPowerWellStatePG(1, 0xaa)` @0x89970
  (bit 5 = PW_3), a false chama `hwSetPowerWellStatePG(0, 2)` @0x899b8 (só PW_1). Logo o espelho de PW_B **dispara no
  init do GPU em todo boot do display 13** — é o caminho principal, não o gatilho de hotplug. O gatilho de hotplug é
  um extra redundante (pede o mesmo PW_B) para reforço e publicação. **Leitura do Run C:** espere ver `V183.PGE`
  **com** `mask=0xaa` (bit 5) já no boot; o espelho (linha `XeHDMI pw en=1 …`) sai aí, antes de qualquer hotplug.
  A orientação anterior ("se nenhum V183.PGE carregar bit5, foi o gatilho de hotplug que ligou PW_B") estava
  **invertida** e foi corrigida.
- **N3 — retenção one-way de PW_B.** O espelho só solta PW_B quando `param_1=false` **e** `param_2` carrega bit 5
  (um release real de PW_3, p.ex. `disablePowerWellPG(PW_3)` no teardown). `overridePowerWellsState(false)` passa
  máscara 2 (sem bit 5) e **não** solta PW_B. Então, após disables que não carregam bit 5, PW_B fica retido — custo
  só de residência DC5/DC6 enquanto o HDMI está ligado (igual à assimetria do CTL1 que o handler já tinha). Opt-in.

### Iteração 4 (26/10) — ngreenhdmiflags (máscaras AGDC do con1)
O bloqueio da raiz nos logs do macOS é `displaypolicyd: Vendor portmap 0x6 mst 0x4 ddc 0x0 aux 0x6` seguido de
`XeFB SetFbStatusOnNextProbe:1357 FB1: Path has not been assigned`: a porta externa é anunciada como DisplayPort com
AUX e **sem DDC**, então o displaypolicyd nunca lê o EDID por I2C e nunca atribui caminho ao framebuffer. Essas
máscaras são montadas por `AppleIntelBaseController::GetGPUCapability` @0x9fc48 a partir da **palavra de flags do
conector** (campo +0x14 de `ConnectorEntry`, = descritor+0x34 na entrada ativa). Desassembly delimitado (capstone)
confirma, por porta presente (bit = contador do laço + 1): **bit 0x1 → MST e AUX** (stores @0x9fd1f e @0x9fd3a, este
via `test …,9`), **bit 0x8 → AUX** (@0x9fd3a), **bit 0x2 → DDC** (@0x9fd53, `(flags>>1)&1`). As flags atuais do con1,
`0x401` (= `0x1|0x400`), acendem o bit0 → MST+AUX e DDC=0, reproduzindo exatamente o log (replay do algoritmo com
con0=0x18 e con1=0x401 dá `portmap 0x6 mst 0x4 ddc 0x0 aux 0x6`). O novo boot-arg **opt-in** `ngreenhdmiflags=N`
(valorado, sem forma `-`, padrão `0x401`) re-estampa as flags do con1 **na entrada ativa** (`active+0xd40`,
conectores +0x20, passo 0x18, flags +0x14) **só quando o arg é dado**; sem o arg, a tabela e todo o comportamento
ficam idênticos a hoje (a única mudança sem o arg é `flags=0x%x` na string IORegistry `ngreen-hdmi-con1` e na linha
`hdmiargs`). `GetPortCapability` @0xa330c **não** lê esse campo (cap = constante `0x101001a` + flags do controlador
`[r15+0x1b5c..0x1b5e]`), então as flags do con1 afetam **só** as máscaras AGDC. Valor recomendado: `0x402` (limpa o
bit0, acende o bit1 → `mst 0x0 ddc 0x4 aux 0x2`). Ordem de teste: **0x402, 0x6, 0x82, 0x403** (0x6/0x82 são os valores
de HDMI da própria Apple, mesmas máscaras; 0x403 mantém MST/AUX além do DDC). Helper:
`tools/hdmi-flags.sh <valor>|off|status` grava o arg no `config.plist`. Leitura: no relatório do `hdmi-diag.sh`, o bit `ddc`
do displaypolicyd deve deixar de ser 0 e a linha `FB1: Path has not been assigned` deve sumir.

### Iteração 5 (26/10) — ngreenhdmiddc (leitura do EDID por DDC servida pelo NootedGreen)
O teste **F202** (`ngreenhdmiflags=0x202`) venceu a etapa anterior: o log por-GPU `displaypolicyd.0:2:0.log` passou de
`ddc 0x0` para `Vendor portmap 0x6 mst 0x0 ddc 0x4 aux 0x2`, ou seja, o displaypolicyd agora **anuncia DDC e tenta ler
o EDID** da porta HDMI. O novo e único bloqueio é que a rotina da Apple `AppleIntelBaseController::hwDoGMBusRequest`
(@0x7b470, símbolo `__ZN24AppleIntelBaseController16hwDoGMBusRequestEjjP12IOI2CRequest`) **falha** nesse pino: a fatia
do boot F202 (da última `PolicyEngine started`, 22:39:25, ao fim) tem **67×** `EDID read 2.0 failed: GPU failed the
command for block 0`, cada uma de 0 a 2,88 s (~95 s no total, ~26 ciclos de hotplug) = as **travadas** do usuário. O
**nosso** leitor GMBUS (`xeReadEdidGmbus`) lê o EDID do mesmo pino 2 certo (`ngreen-edid header=1 vendor=GSM`), logo o
hardware/pino está bom e quem erra é a rotina da Apple. O boot-arg **opt-in** `ngreenhdmiddc=1` (padrão 0) embrulha
`hwDoGMBusRequest` (rota via `RouteRequestPlus` em `installHdmiTrigger`, ao lado de `invokeHotplugHandler`) e, **só**
quando ligado **e** `bus==gHdmiBus` (o pino DDC do HDMI, padrão 2) **e** for o display 13 (`!getIsRealTGL`) **e** a
requisição for uma **leitura pura do bloco EDID** (slave `0x50`, offset 0, contagem 1..128, sem payload de escrita —
todos os campos decodificados do `IOI2CRequest` por desassembly delimitado 0x7b470..0x7c26a: `+0x04` fase, `+0x08`/
`+0x0c` slave, `+0x10`/`+0x11` offset, `+0x28` contagem de escrita, `+0x38` contagem de leitura, `+0x44` buffer de
escrita, `+0x4c` buffer de leitura, `+0x1c` resultado), serve a leitura com `xeReadEdidGmbus`, preenche o buffer do
chamador e marca sucesso (`[req+0x1c]=0`, retorno 0 — igual ao caminho de sucesso da Apple @0x7c25a). **Qualquer outra
coisa** (escrita, offset≠0, outro slave/contagem, outro pino, TGL real, ou se a nossa própria leitura falhar) cai no
original sem alteração — então o kext sem o arg é byte-idêntico a hoje. O limite de pino `cmp [rbp-0x34],8` (@0x7b55d)
só rejeita pinos ≥8, portanto **não** nos bloqueia (o pino 2 passa). Resumo em `ngreen-hdmiddc` (calls/served/
passthrough/último resultado). Leitura: no relatório do `hdmi-diag.sh`, a contagem `EDID read 2.0 failed` (67 no
F202) deve cair e a linha `last 'XeHDMI ddc' (NootedGreen)` deve mostrar `served`.

#### Iteração 5b (26/10) — portão alargado para a LEITURA INDEXADA do EDID

Ao desmontar `hwDoGMBusRequest` função-delimitada (0x7b470..0x7c26a) confirmou-se que a Apple **não** emite uma
leitura pura: ela monta uma **leitura indexada** (DDC clássico). Com `kind` (`+0x00`) `==1` ela dobra no GMBUS1
(`[rcx+rax+0x42000000]` @0x7b8a7, `0x42000000` = SW_RDY | `CYCLE_INDEX` bits[26:25]=0b10) o slave de escrita
(`+0x08`, bits[7:0]), o byte de offset (`+0x10`, bits[15:8]) e a contagem (`+0x28`, bits[24:16]); depois, com a fase
de leitura (`+0x04`==1 @0x7beaf), lê N bytes do slave de leitura (`+0x0c`, @0x7bef4) usando `0x42000001` (bit0 = READ),
contagem em `+0x38` (@0x7bec5), gravando em `+0x4c` (@0x7bf94-0x7bf9b). Ou seja: **escreve o byte de offset 0 no
slave 0x50, depois lê 128 bytes do slave 0x50** — exatamente o que o portão antigo (leitura pura, `wcount==0`)
recusava, caindo no original que falha. O portão agora **serve a leitura indexada do bloco-base**: aceita que o único
sub-bloco de escrita seja um ÚNICO byte de índice 0 (`wcount<=1 && byte(+0x10)==0`, sem exigir slave de escrita) além da
leitura do bloco-base (`(slave(+0x0c)>>1)==0x50` — o `IOI2CRequest` do macOS carrega o endereço DDC em 8 bits `0xA0`
(=`0x50<<1`, leitura `0xA1`), conforme o dump ao vivo `rs=0xa0`; `offset(+0x11)==0`, `1<=count(+0x38)<=128`). **Rejeita** (cai no
original, nunca falsifica): qualquer escrita de payload (>1 byte ou byte!=0, p.ex. o ponteiro de segmento
0x60), offset de leitura!=0 (extensão/segmento), outro slave de leitura (`(slave(+0x0c)>>1)!=0x50`), contagem>128, outro pino, TGL real, ou falha do nosso
próprio leitor. O resumo `ngreen-hdmiddc` agora traz `case=` (`pure-read`/`indexed-edid-read`/`passthrough:...`) e
served-vs-passthrough, para o relatório do `hdmi-diag.sh` mostrar se o portão **engatou**. Verificado em Linux:
`clang++ -fsyntax-only` do `kern_gen11.cpp` e do baseline pre-ddc — ambos exit 0, 21 warnings, conjuntos idênticos.

#### Iteração 6 (27/10) — correção do endereço do slave para a forma 8-bit `0xA0`

A run ao vivo de 2026-10-27 01:58 (`ngreen-hdmiddc`) mostrou `calls=301 served=0`, **toda** chamada
`case=passthrough:not-edid-read` com os campos decodificados `phase=1, r=128, ro=0, rs=0xa0, w=1, wb=0x0, ws=0x0,
kind=0x0`. O portão recusava porque comparava o slave de leitura com `0x50` (7 bits), mas o `IOI2CRequest` do macOS
carrega o endereço DDC na forma **8 bits** `0xA0` (=`0x50<<1`; leitura `0xA1`), não `0x50`. O leitor
`xeReadEdidGmbus` já usava `(0x50<<1)|1`=`0xA1` e estava certo; só o portão estava errado. **Correção** (só a
comparação do portão, nenhuma outra mudança): leitura aceita `(rslave>>1)==0x50` (passam `0xA0` e `0xA1`); o
sub-bloco de escrita deixa de exigir slave (`wslave==0x50` removido), mantendo `wcount<=1 && wbyte==0`. Toda
referência anterior a "slave `0x50`" nas iterações 5/5b acima descreve o predicado **antigo** (7 bits) e fica como
registro histórico; o predicado em vigor é o de 8 bits descrito aqui. Re-derivação com o dump ao vivo
(`phase=1,r=128,ro=0,rs=0xa0,w=1,wb=0,ws=0,kind=0`): `serveEdid=true` → `case=indexed-edid-read` (SERVE). Ainda caem
no original (passthrough, nunca falsifica): `rs=0xC0` (`(0xC0>>1)=0x60≠0x50`), `ro=0x80` (extensão), e `w=2`/`wb!=0`
(escrita real). Verificado em Linux: `clang++ -fsyntax-only` do `kern_gen11.cpp` e do baseline pre-ddc — ambos exit 0,
21 warnings, conjuntos idênticos. Engate em runtime (served>0, queda de `EDID read 2.0 failed`, 2 telas) continua
**NÃO VERIFICADO** (precisa de boot no macOS/hardware).

### Iteração 7 (27/10) — ngreenhdmiregs (snapshot READ-ONLY dos registradores do pipe B)

Com `ngreenhdmiflags=0x202` + `ngreenhdmiddc` o LG é **detectado** (2 telas no `system_profiler`) mas a tela fica
**PRETA**: o `ngreen-hdmipw` do último boot mostrou `HSW_PWR_WELL_CTL2` (0x45404) = `0x2c03` com PW_B STATE (bit 12)
baixo e PW_2 STATE (bit 2) baixo, contra o valor `on` do Linux acima (`0x45404 on=0x3c0f`). Ou seja, o bring-up de
power/clock/transcoder do pipe B está **incompleto** — pedir só o bit PW_B REQ não acende nada. O novo boot-arg
**opt-in** `ngreenhdmiregs=1` (padrão 0, só no display 13 `!getIsRealTGL`) dá um snapshot **READ-ONLY** (só
`NGreen::readReg32`, BAR0, nunca `writeReg32`) deste conjunto fixo de offsets e publica em `ngreen-hdmiregs1`/
`ngreen-hdmiregs2`, cada um `nome@off=vivo<verdito>` (`=` = igual ao `on` do Linux, `.` = igual ao `off`, `?` =
outro), para ver **em que estágio** o pipe B parou **sem o usuário carregar o XeShim** (que não carregou no macOS dele):

- power/fuse: `0x45400`, `0x45404`, `0x45454`, `0x42000` (sem captura on/off aqui → sempre `?`, só valor vivo —
  **UNVERIFIED** contra Linux), `0x45254` (`_PIPEDMC_CONTROL_B`);
- clock/PLL: `0x164280` (+espelho `0x164e80`), `0x46000` (`CDCLK_CTL`), `0x46070` (`BXT_DE_PLL_ENABLE`), `0x46144`
  (`TRANS_CLK_SEL_B`);
- DDI/transcoder/pipe B: `0x64100` (`DDI_BUF_CTL_B`), `0x61400` (`TRANS_DDI_FUNC_CTL_B`), `0x71008` (`TRANS_CONF_B`),
  `0x6101c` (`PIPE_SRCSZ_B`);
- combo PHY B: `0x6c00c`.

Os offsets e os valores on/off são lidos **desta tabela** (seções acima), não chutados. Publicado dos sites de thread
`xeHotplugHook` (logo APÓS a tentativa de modeset da Apple no conector externo) e `getOSInformation` (refresh); no
máximo 16 leituras; nunca de contexto de interrupção. Inerte sem o arg e no XPS 13 Plus. Lido no relatório do
`hdmi-diag.sh` (linhas `ngreen-hdmiregs1/2 (ioreg)` no SUMMARY). Verificação em Linux: `clang++ -fsyntax-only` do
`kern_gen11.cpp` e do baseline pre-regs — mesmos warnings. Engate em runtime **NÃO VERIFICADO** (precisa de boot no
macOS/hardware).

### Iteração 8 (27/10) — ngreenhdmilight (FASE 1 do light-up: energia + ungate do clock, SEM scanout)

O snapshot da iteração 7 (`ngreenhdmiregs`, relatório `hdmi-diag-regs-20261027-125037.txt`) provou que a Apple
identifica o LG externo mas deixa **toda a cadeia de saída do pipe B no reset**: power wells PG2/PW_B/DDI-B
apagados (`0x45404=0x0c03` vs on `0x3c0f`; `0x45454=0x3` vs on `0xf`), clock da DDI-B com gate (`0x164280` bit11
setado), DPLL off e o scanout todo off. O boot-arg **opt-in** `ngreenhdmilight` (valorado + forma `-`, padrão 0, só
no display 13 `!getIsRealTGL`) acende **APENAS a energia + o clock** do pipe B — **FASE 1**, sem habilitar scanout:
nada de DDI_BUF/transcoder/pipe/plane/PHY-TX, logo não pode apagar/travar o pipe. Sequência ordenada
(read-modify-write + espera limitada + read-back; `IODelay`, sem sleep; aborta a cadeia em qualquer timeout de STATE):

  1. **PG2/PW_2** — RMW set REQ bit3 em `0x45404` → espera STATE bit2 (≤2 ms). Timeout ⇒ aborta (não cascateia).
  2. **PW_B** — RMW set REQ bit13 em `0x45404` → espera STATE bit12 (≤2 ms).
  3. **DDI-B well** — RMW set REQ bit3 em `0x45454` → espera STATE bit2 (≤2 ms).
  4. **DPCLKA ungate** — RMW **limpa** o bit11 (0x800 = `ICL_DPCLKA_CFGCR0_DDI_CLK_OFF(PHY_B)`,
     intel_display_regs.h:2872) em `0x164280` e no espelho `0x164e80`.

Bits verificados: PG2/PW_2 = domínio índice 1 → REQ `2<<(2*1)`=bit3, STATE bit2; PW_B = índice XELPD 6 →
REQ bit13, STATE bit12; DDI-B (0x45454) índice 1 → REQ bit3, STATE bit2 (WhateverXe `kern_display13_power.hpp`
request/enabled; captura acima `0x45404 0x0c0f→0x3c0f`, `0x45454 0x3→0xf`).

**O DPLL (P2) FICA DE FORA — o DPLL1 alimenta o PAINEL INTERNO no macOS.** O `ICL_DPCLKA_CFGCR0` tem um campo
`DDI_CLK_SEL` de 2 bits por PHY combo (intel_display_regs.h:2879-2889): PHY_A em bits[1:0], PHY_B em bits[3:2], o
valor = índice do PLL; o clock-off é bit10 (PHY_A) / bit11 (PHY_B). A leitura **ao vivo no macOS** `0x164280 =
0x01e07801` (parte baixa `0x7801`) decodifica: **bits[1:0]=01 → DDI-A (eDP interno) = DPLL1**; bits[3:2]=00 → DDI-B
(HDMI) = DPLL0; bit11=1 (clock da PHY_B com gate). Isso é o **OPOSTO** do Linux (on `0x7004`: A→DPLL0, B→DPLL1).
Ou seja, **no macOS o DPLL1 é o PLL do painel interno**, não do HDMI. Ligar/reprogramar o DPLL1 (0x46014 + CFGCR/
DIV0) perturbaria o eDP — não dá para provar o DPLL1 como external-only aqui, então a Fase 1 **não** mexe no DPLL
(ver o bloco de comentário de `ngreenhdmilight` em `kern_gen11.cpp`). Limpar o bit11 (passo 4) é seguro: só desbloqueia a entrada de clock da
DDI-B e **não** toca no campo `DDI_CLK_SEL`, então o roteamento do eDP interno fica intacto (depois da Fase 1 o mux
ainda lê PHY_B=DPLL0, então nenhum pixel-clock chega à DDI-B ainda — isso é trabalho da Fase 2, que terá de
re-apontar o `DDI_CLK_SEL` da PHY_B antes de qualquer enable de PLL).

Gating (tudo tem de valer antes de qualquer escrita): `gHdmiLight` **e** `!getIsRealTGL()` **e** rodando do
`xeHotplugHook` (contexto de thread, APÓS o handler original) para `ddi==gHdmiDdi` **e** `TRANSCONF_B` (`0x71008`)
`==0` (a Apple terminou e deixou o pipe B apagado — não corremos contra ela; se `!=0`, não faz nada). Contador
anti-churn (poucas execuções, como o `ngreenhdmipw`). Publica antes/depois de `0x45404`/`0x45454`/`0x164280` e o
ok/timeout de cada espera em `ngreen-hdmilight` (+ linha `XeHDMI light` no IOLog). O `0x46014 DPLL1_ENABLE`
(off=0 → on=0xcc000000) foi **adicionado à tabela READ-ONLY** do `ngreenhdmiregs` para a P2 ficar observável; ele
**nunca é escrito** na Fase 1. Reversível: retenção one-way dos power wells aceita (custo só de residência DC5/DC6,
igual à assimetria do `ngreenhdmipw`); bootar sem o arg restaura o stock (a sequência nunca roda). Inerte sem o arg
e no XPS 13 Plus (kext byte-idêntico). Deltas esperados no `ngreenhdmiregs` após a Fase 1:
`0x45404 0x0c03→0x3c0f`, `0x45454 0x3→0xf`, `0x164280/0x164e80 …7801→…7004`. Verificado em Linux:
`clang++ -fsyntax-only` do `kern_gen11.cpp` e do baseline pre-light — ambos exit 0, 21 warnings, conjuntos
idênticos; `zsh -n hdmi-diag.sh` OK. Engate em runtime (STATE sobe, deltas) **NÃO VERIFICADO** (precisa de boot no
macOS/hardware).

### Iteração 9 (30/10) — XE-HDMI13 (`ngreenhdmilight=2`): o acendimento completo pelo caminho da Apple

Ainda **não testada** no notebook. Captura nova do Linux com o HDMI aceso (read-only,
`tools/diagnostics/i915-regdump.py`):

- Clocks: `DPCLKA_CFGCR0 0x164280 = 0x01e07004` (PHY A/eDP no DPLL0, PHY B/HDMI no DPLL1); `DPLL0_ENABLE 0x46010` e
  `DPLL1_ENABLE 0x46014` = `0xcc000000`. DPLL1 `CFGCR0/1` (`0x16428C`/`0x164290`) = `0x001001d0`/`0x00000e84`
  (148,5 MHz); DPLL0 (eDP, 270 MHz) = `0x00e001a5`/`0x00000088`. Referência 38,4 MHz (`SKL_DSSM 0x51004 = 0x40000000`).
- DBUF: `DBUF_CTL_S0..S3` (`0x45008`, `0x44FE8`, `0x44300`, `0x44304`) = `0xc041c000` (tracker 8, min tracker 1);
  `MBUS_CTL 0x4438C = 0x1c000700` (sem join). Plano 1B: `PLANE_BUF_CFG 0x7127c = 0x07db0000` (blocos 0..2011,
  relativos ao banco B, que começa em S2).
- Pipe B: `PIPE_ARB_CTL 0x71028 = 0x2a0f` (bit 13, Wa_22012358565), `PIPE_CHICKEN 0x71038 = 0x40008080`,
  `PIPE_MBUS_DBOX_CTL 0x7103c = 0xb1038804`, `TRANS_CLK_SEL_B = 0x20000000`, `TRANS_DDI_FUNC_CTL_B = 0x90030000`,
  `DDI_BUF_CTL_B = 0x80000000`, `TRANSCONF_B = 0xc0000000`.

O que o binário 16.0.32 mostra (desmontagem delimitada por símbolo):

1. **O f10 impede o modeset completo.** `hwSetMode(fb, path, timing)` @0x74c1e chama `hwRegsNeedUpdate` @0x75028;
   `je 0x7508c` @0x7502f leva ao "Partial modeset" e o fall-through ao modeset completo (`disableDisplay`, despacho
   `LightUpEDP/DP/TMDS` pelo kind da porta, estado do path = 2). O patch f10 do NootedGreen (lista do FB debug,
   `e8 af e2 ff ff 84 c0 74 5b` → `… eb 5b`) troca o `je` por `jmp`: todo modeset é parcial. O eDP depende disso.
   Por isso o `ngreenhdmimodeset=2` nunca funcionou: no boot de 27/10 18:17 UTC o gancho logou `force=1` quatro vezes e
   o FB1 logou "Partial modeset" em todas. O path do FB1 estava com estado 1 (alocado, não ativo).
2. **`enableClocks(port, other, ClockParams)` @0xa5dae** usa o DPLL de índice = DDI (`0x46010 + 4*ddi`) e grava os
   divisores pela tabela @0xf3518 = `0x164000/0x164080/0x164200` (endereços do ICL), não nos `TGL_DPLL_CFGCR0/1`.
   Para a DDI B: DPLL1, que no macOS é o PLL do eDP (`DPCLKA 0x01e07801`). O `disableClocks(port, other)` @0xa6ed4
   desliga `DPLL[ddi]`. Os dois mandam o nível de tensão pelo mailbox 7 (3 antes, `calculateVoltageLevel` depois) e
   ligam/desligam o poço da DDI IO.
3. **`LightUpTMDS` @0x76376:** `enableClocks(fb, path)` → `TRANS_CLK_SEL` (0x46140 + 4·pipe) → plano desligado →
   escalador → `enablePipe` (timings, `TRANS_DDI_FUNC_CTL`, `TRANSCONF`, interrupções) →
   `setVoltageSwingAndPreEmphasis(0,0,0)` → `enablePort` (`DDI_BUF_CTL`, espera o IS_IDLE cair por 500 µs) →
   infoframes. O `SetupParams` monta `TRANS_DDI_FUNC_CTL` com DDI B = `0x10000000` e modo HDMI pelo `fb+0x4289`.
4. **adlpDcExit** gravava `CTL2 = 0x0C03` e `DDI2 = 0x3`, apagando os pedidos de PW_2/PW_B/DDI-IO-B.
5. O panic de watchdog do WindowServer de 27/10 16:02 (boot C6A3612, com `ngreenhdmimodeset=2`) não veio do HDMI:
   os erros de canal da GPU começaram às 18:55:25 UTC, 5 minutos antes do replug, e o FB1 não teve modeset nesse boot.

**Implementação** (`kern_gen11.cpp`, bloco XE-HDMI13; só com `ngreenhdmilight=2` e fora do TGL real):

- O f10 é desfeito logo depois de aplicado; o gancho do `hwRegsNeedUpdate`, só para a chamada vinda do `hwSetMode`
  (endereço de retorno `hwSetMode+0x40f`, bytes conferidos na carga), devolve 0 para o eDP (como o f10), 1 para o
  path do HDMI enquanto `TRANSCONF` e `DDI_BUF_CTL` dele não estiverem ligados (no máximo 6 por plug) e o resultado
  da Apple depois de aceso. HPD baixo: 0.
- `enableClocks`/`disableClocks(port)` substituídos para a porta HDMI: combo PLL que nenhuma PHY ligada usa (aqui o
  DPLL0), WRPLL como o i915 (`icl_calc_wrpll`, Display WA 22010492432: metade da fração com ref 38,4 MHz; 148,5 MHz →
  `0x001001d0`/`0x00000e84`), `combo_pll_enable` (POWER → STATE, CFGCR, ENABLE → LOCK), `DPCLKA` em duas escritas,
  `port+0x140` = clock do link em Hz. O desligamento só apaga o PLL que é nosso.
- Energia no HPD alto e antes de cada modeset do HDMI: PW_2 → PW_B (com os fuses), banco B do DBUF (S2/S3 com
  tracker 8 e min tracker 1) e, se o MBUS estiver unido, a separação do i915 (min tracker 1 nas 4 fatias, crédito A
  do DBOX do pipe A 6 → 4, `MBUS_CTL` 2x2 sem join). O adlpDcExit mantém os bits; com o pipe seguro, escritas da
  Apple em `CTL2` mantêm PW_2/PW_B e as de `DC_STATE_EN` ficam sem DC5/DC6/DC3CO. Retenção até o próximo boot.
- Antes do `LightUpTMDS`: `PIPE_ARB_CTL` bit 13 e `PIPE_CHICKEN 0x40008080`; o clock do modo vem do pixel clock do
  timing. Depois: `PIPE_MBUS_DBOX_CTL` como o i915 no ADL-P e `GAMMA_MODE_B = 0` (bypass, como o pipe A). V97P/V97C
  só no pipe A.
- Diagnóstico: `ngreen-hdmi13` (resumo: `f10undone`, `held`, `pll`, `forces`, `lightups`, `clkon/clkoff`),
  `-pwr`, `-rnu` (decisão), `-clk` (PLL, CFGCR, lock, DPCLKA), `-pre`/`-post` (retrato do caminho do pipe com `=`
  igual ao Linux e `!` diferente) e `-late` (2 s depois: quadros em 100 ms e o bit de underrun do IIR do pipe), e as
  linhas `XeHDMI13` no log do kernel (o `hdmi-diag.sh` tem uma seção para elas).

O kext do teste foi compilado no Linux (clang 22 `--target=x86_64-apple-macos13.0 -mkernel`, com
`-fno-use-cxa-atexit -mllvm -disable-atexit-based-global-dtor-lowering`, e o `ld64` do cctools-port com
`-kext -static`); importa os mesmos símbolos que o build do macOS mais `IOSleep`, `OSBitOrAtomic` e `strlen`.

**O que olhar no teste:** `f10undone=1`; `-rnu` com `decision=1`; `lightups` > 0; em `-clk`, `lock=1`, `pll=0` e
`DPCLKA` com o bit 11 limpo; em `-post`, `DDIBUF` sem o bit 7 e `TCONF=c0000000`; em `-late`, quadros > 0 e
`underrun=0`. Tela interna estável o tempo todo.
