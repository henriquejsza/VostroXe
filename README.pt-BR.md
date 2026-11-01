# VostroXe

Aceleração gráfica da Iris Xe no macOS Tahoe para o **Dell Vostro 3520** (Core i5-1235U, Iris Xe `8086:46A8`,
80 EU), num hackintosh com OpenCore.

> 🇺🇸 English: [README.md](README.md)

Não existe driver da Apple para a GPU do Alder Lake. O VostroXe é um fork do
[Hackintosh-XPS13Plus-IrisXe-Tahoe](https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe), que roda o
driver da Apple para a Iris Xe do Tiger Lake (GPUDriversIntel 16.0.32) em GPUs Iris Xe mais novas: um
[NootedGreen](https://github.com/sgiammori/NootedGreen) modificado faz os patches no kernel, e partes do espaço do
usuário, também modificadas, adaptam o driver de 2020 à pilha Metal do Tahoe. O VostroXe acrescenta o que este
notebook precisa (a EFI OpenCore, duas correções de panic no boot, um driver para o áudio e o trabalho em andamento
na porta HDMI) e acompanha o projeto base na parte da GPU.

> ⚠️ **Experimental.** Espere travamentos da GPU e kernel panics de vez em quando. Tenha outro jeito de bootar, como
> o pendrive de instalação com a config segura.

## O que funciona

Testado em um Vostro 3520 (i5-1235U, BIOS 1.43.0) com o macOS Tahoe 26.7.1 (25G241).

| Área | Estado |
|---|---|
| Vídeo | ✅ Metal na Iris Xe (Informações do Sistema: Metal 2, 1536 MB), tela interna em 1920×1080 a 120 Hz |
| Alto-falantes, microfones | ✅ alto-falantes e microfones internos (CS8409HDA + XeSpeakers; autoteste: o tom 62 dB acima do silêncio) · ❌ entrada de fone com microfone |
| Boot | ✅ boot acelerado, com as correções dos panics de `probePortState` e de divisão por zero (24/10) |
| Teclado, USB, NVMe | ✅ |
| Rede | ✅ um dispositivo de rede USB CDC-ECM (driver da Apple) · ❌ Wi-Fi e Bluetooth: o Realtek RTL8821CE não tem driver no macOS |
| HDMI externo | ✅ imagem em 1920×1080, 60 Hz num monitor 1080p, com boot-args opcionais (`zsh tools/hdmi-flags.sh light`, [docs/HDMI.md](docs/HDMI.md)) · ❌ áudio pelo HDMI (a porta funciona em modo DVI) · replug e repouso ainda não testados |
| Na EFI, ainda sem confirmação | Ethernet (RealtekRTL8111), roteador USB RNDIS do Android (HoRNDIS), touchpad (VoodooI2C em polling), estado da bateria, os 12 threads da CPU (correção no `Cpuid1Data`), perfil XE-PM de turbo e repouso (`ngreenpm=20`) |
| Ainda não conferido | teclas de brilho, repouso, webcam, leitor de digital |

Problemas conhecidos: o `powermetrics` derruba o kernel, um travamento do WindowServer já terminou num panic do
watchdog, e com `amfi_get_out_of_my_way=1` apps de terceiros nunca recebem o pedido de permissão de microfone,
câmera ou gravação de tela (solução: `tools/tcc-permitir.sh`; no Sequoia, o config com `ngreenlv=1` traz os
pedidos nativos de volta, [docs/SEQUOIA.md](docs/SEQUOIA.md)). O emulador do Android mostra a janela preta (correção ainda não testada:
`tools/emulador-android.sh`, [docs/EMULATOR.md](docs/EMULATOR.md)). Detalhes
em [docs/VOSTRO.md](docs/VOSTRO.md#known-issues).

## Instalação

Precisa do macOS Tahoe **26.7.1 (25G241)**: os patches são feitos para essa versão. Na BIOS (F2), deixe o
armazenamento em AHCI (não RAID/Intel RST) e desligue o Secure Boot.

**1. EFI e pendrive de instalação**, no Linux ou no macOS (precisa de git, python3 e curl):

```sh
git clone https://github.com/henriquejsza/VostroXe.git && cd VostroXe
python3 make-efi.py --installer --recovery
```

Copie `dist/EFI` e `dist/com.apple.recovery.boot` para a raiz de uma partição FAT32 do pendrive. O `smbios.local`
agora guarda os números de série deste Mac: guarde esse arquivo e não publique nem ele nem a pasta `dist/`.

**2. Instale o macOS.** Boote pelo pendrive (F12), escolha "macOS Base System", apague só o volume onde o macOS vai
ficar (APFS) e reinstale. O instalador baixa o macOS e o Wi-Fi não funciona: antes, conecte um cabo de rede ou um
dispositivo de rede USB. Se precisar, atualize até o 26.7.1 (25G241), e não passe dele.

**3. Config acelerada.** No pendrive, copie `EFI/OC/config-accel.plist` por cima de `EFI/OC/config.plist` e
reinicie. A GPU passa a aparecer como Tiger Lake (`9A49`), ainda sem aceleração.

**4. No macOS**, a partir de um clone num disco APFS (a sua pasta de usuário):

```sh
xcode-select --install
git clone https://github.com/henriquejsza/VostroXe.git ~/VostroXe && cd ~/VostroXe
zsh install.sh
```

O `install.sh` baixa os bundles 16.0.32 do driver da Apple pelo projeto NootedGreen, compila o NootedGreen, o
HookCase, o driver Metal modificado, o libxedrv e o compilador de shaders, e instala tudo. Se o macOS pedir, aprove
a extensão de sistema e reinicie. A EFI já traz um `NootedGreen.kext` compilado a partir de `src/NootedGreen`.

**5. Som:** `zsh tools/CS8409HDA/macos/audio.sh test` (bipes, um autoteste e depois o dispositivo de som).

**6. Permissões de privacidade** para os apps que precisam, por exemplo:
`sudo zsh tools/tcc-permitir.sh microfone "Google Chrome"`.

Se um boot falhar, copie `config-install.plist` por cima de `config.plist` a partir de outro sistema (no Linux,
monte a partição EFI do pendrive) para voltar à config segura.

## Atualização

```sh
cd ~/VostroXe && git pull && zsh install.sh
```

Depois copie `build/NootedGreen.kext` para `EFI/OC/Kexts/` na EFI de onde você boota (guarde o antigo) e rode
`zsh tools/CS8409HDA/macos/audio.sh efi` se `tools/CS8409HDA` mudou. Mantenha a sua EFI e os números de série dela.
Se for gerar a EFI de novo com o `make-efi.py`, rode onde está o seu `smbios.local`.

## Organização do repositório

```
EFI/                     EFI OpenCore do Vostro 3520, sem os números de série (o make-efi.py preenche)
make-efi.py              gera dist/EFI no Linux ou no macOS: SMBIOS, HfsPlus.efi, ocvalidate, recovery
src/NootedGreen/         o plugin do kernel, com as mudanças do Vostro (correções de boot, HDMI)
src/HookCase/            o HookCase modificado para o NootedGreen (MIT)
src/MGL/                 o MGL (OpenGL 4.6 sobre Metal, Apache-2.0) com as correções que o fazem rodar na Iris Xe
macos/                   espaço do usuário: patcher do driver Metal, libxedrv, compilador de shaders, instalador
tools/CS8409HDA/         driver de áudio para o Cirrus CS8409 do Vostro, com um harness de teste no Linux
tools/XeSpeakers/        o dispositivo de som do macOS (AudioServerPlugIn)
tools/hdmi-flags.sh      troca os boot-args dos experimentos de HDMI
tools/diagnostics/       hdmi-diag.sh, i915-regdump.py (Linux) e os programas de teste de GPU do projeto base
tools/tcc-permitir.sh    permissões de privacidade que o amfi_get_out_of_my_way=1 bloqueia
tools/emulador-android.sh  correção do emulador do Android para AVDs x86_64 (parâmetro do kernel do guest)
tools/mgl-build.sh       compila o src/MGL; mgl-test.sh, mgl-triangle.sh e mgl-window.sh testam o OpenGL na GPU
docs/VOSTRO.md           este notebook: hardware, EFI, patches, problemas conhecidos, mudanças
docs/HDMI.md             o trabalho no HDMI
docs/EMULATOR.md         o emulador do Android
docs/OPENGL.md           OpenGL na GPU pelo MGL
docs/SEQUOIA.md          o porte para o macOS Sequoia 15.8.2 (em andamento)
```

As outras ferramentas (AudShim, tela de toque, digital, vibração do touchpad e outras) e os outros documentos em
`docs/` vêm do projeto base e descrevem o Dell XPS 13 Plus. O [CHANGELOG](CHANGELOG.md) dele fica como está no
projeto original.

## Créditos

- **JulioNectar**, autor do [Hackintosh-XPS13Plus-IrisXe-Tahoe](https://github.com/JulioNectar/Hackintosh-XPS13Plus-IrisXe-Tahoe):
  o trabalho que faz o driver Tiger Lake da Apple rodar no Alder Lake e no Raptor Lake (patches do kernel, driver
  Metal, compilador de shaders, XE-PM), sobre o qual o VostroXe é feito. O README dele dá os créditos dos projetos
  em que se baseia.
- **StezzaPilot**, [NootedGreen](https://github.com/sgiammori/NootedGreen): a base do plugin do kernel e a origem dos
  bundles 16.0.32 do driver.
- **acidanthera** (OpenCore, Lilu, WhateverGreen, VirtualSMC, NVMeFix, RestrictEvents, BrightnessKeys), **VoodooI2C**,
  **VoodooPS2**, **USBToolBox** (dhinakg), **Mieze** (RealtekRTL8111), **jwise** (HoRNDIS).
- Os drivers `cs8409` e `cs42l42` do Linux (Cirrus Logic): a referência para a programação do codec no CS8409HDA.
- **b00t0x**, [WhateverXe](https://github.com/b00t0x/WhateverXe): a referência para o HDMI no Display 13.
- **Michael Larson** e colaboradores, [MGL](https://github.com/openglonmetal/MGL): OpenGL 4.6 sobre Metal, a base do
  `src/MGL`.

## Licença

A [Thou Shalt Not Profit License 1.0](LICENSE), a licença do NootedGreen e do projeto base. Os kexts de terceiros em
`EFI/` mantêm as próprias licenças, e nenhum software da Apple está incluído: veja o [NOTICE.md](NOTICE.md).

O VostroXe é um projeto sem fins lucrativos: o autor não tem nenhuma receita com a distribuição dele nem com suporte
ou serviços relacionados. Não tem relação com a Apple, a Intel ou a Dell nem com os autores dos projetos em que se
baseia, e não é endossado por eles.
