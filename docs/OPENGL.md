# Hardware OpenGL on the Iris Xe (MGL → Metal)

macOS Tahoe has no Tiger Lake OpenGL driver, so native GL on this laptop falls back to the **Apple Software
Renderer** (GL 4.1, CPU). This page is the work to get **hardware-accelerated OpenGL on the Iris Xe** through
[MGL](https://github.com/openglonmetal/MGL), which implements OpenGL 4.6 directly on Metal.

> **Confirmed on the Vostro 3520, 2026-10-31.** Offscreen OpenGL 4.6 runs on the GPU: a clear and an RGB-triangle
> shader draw both render on the Iris Xe and read back correct. It is **not** system-wide GL: an app has to be built
> against MGL. See the scope notes at the end.

## Why not native GL, Vulkan or Zink

- **Native GL:** the project installs Apple's Tiger Lake GL driver bundle (`AppleIntelTGLGraphicsGLDriver`, 16.0.32),
  but its binary cannot get HW caps from the kernel accelerator (`[IGPU] HWCAPS: Failed to get the connection for HW
  caps from the kernel.`), so no accelerated pixel format is offered and GL stays software. Base project issue #21
  confirms there is no known fix. This wall is unchanged.
- **Vulkan works** on the GPU through MoltenVK (`vulkaninfo` shows Intel(R) TGL `0x9a49`, Vulkan 1.4; `vkcube`
  renders). That is the enabler, but a full GL-over-Vulkan stack (Mesa **Zink** + MoltenVK) needs a large Mesa build
  and a window bridge, and the proven Zink recipe uses the arm64-only KosmicKrisp driver.
- **MGL** translates GL straight to Metal (no Vulkan), is small, builds with the Command Line Tools, and is the
  path PrismLauncher uses. Metal has no geometry shaders and no 64-bit float in shaders, so neither does MGL.

## What is confirmed

A headless probe (`tools/mgl-test.sh`) creates a GL 4.6 context, makes an RGBA8 texture + FBO, clears it blue with
`glClearColor(0, 0.5, 1, 1)` / `glClear`, and reads the centre pixel back:

```
MGL INFO: Metal device created: <MTLIGAccelDevice ...>  name = Intel(R) TGL   ← the Iris Xe
GL_RENDERER : MGL · GL_VERSION : 4.6.0 · framebuffer status = complete
pixel central RGBA = 0 128 255 255     ← the exact clear colour, read back from the GPU
glGetError = 0x0
```

The Metal device MGL renders on is the Intel Iris Xe, the render-encoder/command-buffer run on it, and the result
is correct. `GL_RENDERER` is the fixed string `"MGL"`, not the GPU name; the GPU proof is the Metal device line and
the read-back pixel.

A second probe (`tools/mgl-triangle.sh`) goes further: it compiles a GLSL 460 vertex+fragment shader, uploads a
VBO/VAO and draws the classic RGB triangle with `glDrawArrays`, offscreen, then reads it back and writes a BMP:

```
shader vertex: compilou · shader fragment: compilou · programa: linkou
glGetError pos-draw = 0x0
pixels: fundo=49336 triangulo=16200  (vermelho=3766 verde=3786 azul=3786)
```

So the whole pipeline runs on the GPU: GLSL compiled to Metal (MGL's glslang → SPIR-V → SPIRV-Cross → MSL
toolchain), vertex buffers, a draw call, rasterisation and colour interpolation. The saved image
(`mgl-triangulo.bmp`) is a red/green/blue gradient triangle. MGL reads an FBO top-origin (Metal's convention), so
the probe flips the image vertically to GL's bottom-origin orientation.

## Building and testing

Needs the Command Line Tools (`xcode-select --install`) and, for the first build, an internet connection (the script
clones MGL and its dependencies). Everything is driven from the USB with double-click launchers, or from a Terminal:

```sh
zsh tools/mgl-build.sh     # COMPILAR-MGL.command   — clones + builds MGL, applies the patches below, builds libmgl.dylib
zsh tools/mgl-test.sh      # TESTAR-MGL.command     — the offscreen clear+readback GPU probe above
zsh tools/mgl-triangle.sh  # TRIANGULO-MGL.command  — the RGB-triangle shader demo, writes mgl-triangulo.bmp
```

`mgl-build.sh` is resumable: it reuses the cloned sources and the already-built dependencies, re-applies the patches
(idempotent) and relinks. Products are `~/MGL/build/libmgl.dylib`, `libmgl_es.dylib` and `libglfw.dylib`.

## The six patches to MGL

MGL as published does not run here unmodified; `mgl-build.sh` applies these to the checkout before `make` (each is
idempotent and re-applied on every build):

| # | File | What and why |
|---|---|---|
| A | `MGL/src/glm_params.c` | Drop `kCGLPFAAccelerated` from `getMacOSDefaults`. MGL bootstraps its default GL state from a CGL context; an **accelerated** CGL pixel format is exactly what fails on this GPU (issue #21), so it aborted at startup. Without the flag the defaults come from the software renderer (same spec values) and MGL still renders on Metal. |
| B | `Makefile` | `$(mgl_gl_obj)` → `$(mgl_core_obj)`. An upstream typo left `gl_core.o` (the `glXxx` entry points) out of `libmgl.dylib`, so the library exported no GL functions (the GLFW backend's `dlsym` and any app would fail to link). The ES library already did this correctly. |
| C | `MGL/src/MGLRenderer.m` | In `newRenderEncoder`, realise the FBO colour attachment's Metal texture (`is_render_target = true` + `bindMTLTexture`) before use. It was only realised lazily when a texture was *sampled*, so rendering **to** an FBO texture hit `assert(tex->mtl_data)`. |
| D | `MGL/src/MGLRenderer.m` | Implement `glReadPixels` from an FBO in `mtlReadDrawable`. The read-from-framebuffer branch was stubbed (it logged and returned); it now blits the attachment texture to a shared `MTLBuffer` and copies it out. |
| E | `MGL/src/MGLRenderer.m` | Honour a global `glClear` on FBO attachments. The per-attachment loop only cleared when the `glClearBufferfv` bitmask was set and forced `loadAction = Load` otherwise, so a plain `glClear(GL_COLOR_BUFFER_BIT)` never cleared a bound FBO. |
| F | `MGL/src/MGLRenderer.m` | Raise the bogus pointer "safety" ceilings. This fork rejects context/device/framebuffer pointers above QEMU-era limits — `0x100000000000` (~17 TB, 12×) and one `0x100000000` (4 GB!). macOS x86_64 pointers sit just below 2^47 (~140 TB), above both, so `glDrawArrays` aborted ("Invalid GLM context" / "Invalid framebuffer pointer"). Both ceilings go to `0x800000000000` (2^47). |

Patch A gets MGL past startup; C/D/E make an offscreen FBO actually clear, draw and read back; F lets draw calls run
at all on macOS pointers. All are in `tools/mgl-build.sh`, applied with `perl` and guarded so a re-run is a no-op.

## Scope and honest limits

- **Per-app, not system-wide.** This routes GL to the GPU only for a program built or linked against MGL
  (`libmgl.dylib`, and `libglfw.dylib` for windowed apps). The system's native OpenGL is still the Apple Software
  Renderer; this does not change what the Minecraft Launcher or any stock GL app sees.
- **`GL_RENDERER` is `"MGL"`**, a fixed string. The hardware proof is the Metal device (`Intel(R) TGL`) and the
  read-back pixel, not the renderer string.
- **Coverage is partial** (MGL is not a conformant GL): vertex/fragment/compute shaders, buffers, textures, FBOs,
  most draw calls, instancing. **No geometry shaders and no `double` in shaders** (Metal limits).
- **Confirmed path is offscreen (FBO): clear, shader draw and readback.** A GL 4.6 clear and an RGB-triangle shader
  draw both render on the GPU and read back correct. MGL's windowed path (its modified GLFW, `glfwCreateWindow`) did
  not create a window from a plain command-line binary here (it fell back to a headless renderer and returned NULL);
  that is the open item for driving an on-screen GL app.
- **FBO readback is top-origin** (Metal's texture convention), the opposite of GL's bottom-origin; a consumer that
  reads an FBO (screenshots, `glReadPixels`) must flip, as the triangle demo does.
- The Android emulator's slow GL is a **separate** problem (its own ANGLE/gfxstream, not this stack);
  see [EMULATOR.md](EMULATOR.md).

## Next

- Drive a real on-screen GL app through MGL's `libglfw.dylib` (link or `DYLD_INSERT_LIBRARIES`), which means solving
  the windowed `glfwCreateWindow` path (app-bundle / window-server context).
- Measure performance against the Apple Software Renderer on a non-trivial scene.
