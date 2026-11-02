# Hardware OpenGL on the Iris Xe (MGL → Metal)

macOS Tahoe has no Tiger Lake OpenGL driver, so native GL on this laptop falls back to the **Apple Software
Renderer** (GL 4.1, CPU). This page is the work to get **hardware-accelerated OpenGL on the Iris Xe** through
[MGL](https://github.com/openglonmetal/MGL), which implements OpenGL 4.6 directly on Metal. MGL is kept in this
repository, with the fixes it needs here, as `src/MGL`.

> **Confirmed on the Vostro 3520.** OpenGL 4.6 runs on the GPU offscreen (31 Oct, Tahoe 26.7.1: a clear and an
> RGB-triangle shader draw render on the Iris Xe and read back correct) and on the screen (1 Nov, Sequoia 15.8.2): a
> GLFW window, a plain Cocoa window, and an **unmodified** native `NSOpenGLContext` app redirected by a
> `DYLD_INSERT_LIBRARIES` shim all draw the triangle on the Iris Xe. It is **not** system-wide GL — each app is routed
> individually, by linking MGL or through the shim — but it needs no change to the app's source. See the scope notes
> at the end.

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

A third test (`tools/mgl-window.sh`) works the way an app does: it uses only GLFW and standard OpenGL, links MGL's
`libglfw.dylib` and `libmgl.dylib`, asks for a 4.6 core context (MGL's GLFW refuses anything lower), opens a
480×360 window and draws the same triangle over a pulsing background for 6 s with `glfwSwapBuffers`. On Sequoia
15.8.2 (1 Nov):

```
GLFW plataforma = 0x00060002 (Cocoa, janela de verdade)
glfwCreateWindow: OK
GL_RENDERER : MGL  |  GL_VERSION : 4.6.0
glGetString pela GLFW (glfwGetProcAddress) vem de: ~/VostroXe-MGL/build/libmgl.dylib
quadros: 354 em 6.0 s = 59 por segundo (quadro mais lento: 148 ms); primeiro glGetError != 0: 0x0
```

The user saw the triangle drawn in the window. In MGL's own log the window's renderer runs on `Intel(R) TGL`, 355
drawables are presented at 480×360 (the window's size; the extra one is the clear GLFW presents when it creates the
context) and there is no error or warning line. Only the start is slow: 0.86 s from creating the context to the
first frame, most of it compiling the two shaders for Metal, then one frame of 121 ms. After that a frame was
presented every 16–17 ms (slowest 27 ms).

### Native apps, without GLFW

`tools/mgl-cocoa.sh` drops GLFW: a plain Cocoa program (its own `NSApplication`/`NSWindow`) binds MGL to the window
with `CppCreateMGLRendererFromContextAndBindToWindow` and draws the triangle — 357 frames, no GL error. MGL renders
into a real Cocoa window driven by the app's own run loop.

`tools/mgl-shim.sh` reaches the real goal: routing an **unmodified** native app to MGL. The shim
(`src/MGLShim/mglshim.m`, a `DYLD_INSERT_LIBRARIES` dylib) does two things. It swizzles `NSOpenGLContext`
(`initWithFormat:` → an MGL `GLMContext`, `setView:` → MGL's `CAMetalLayer` onto the app's own view,
`makeCurrentContext` → `MGLsetCurrentContext`, `flushBuffer` → `MGLswapBuffers`) and strips `NSOpenGLPFAAccelerated`
from the pixel format (Apple's accelerated format fails here, issue #21). And it redirects the `gl*` calls with dyld
interposing (`__DATA,__interpose`) — which works with two-level namespace, where a flat-namespace reexport did not.
The test runs one ordinary `NSOpenGLView` probe binary twice:

```
GL_RENDERER sem shim : Apple Software Renderer   (GL 4.1, CPU)
GL_RENDERER com shim : MGL                       (GL 4.6.0, Iris Xe: 239 frames, no GL error, triangle seen)
```

Same binary, no recompile: software when run normally, on the GPU under the shim. The shim so far interposes the 22
`gl*` the probe uses; a real app needs the full set, and MGL leaves `glBindAttribLocation` / `glBindFragDataLocation`
unimplemented, so legacy shaders without `layout(location=)` need those filled in first.

## The MGL source: `src/MGL`

MGL is kept in this repository as `src/MGL`: upstream commit `de0ded04` (Apache-2.0), without its Xcode project,
golden images and code generators, plus the six fixes below as ordinary commits (`git log -- src/MGL`). Each changed
file says so in its header, and each change is marked `VostroXe:` in the code. The build dependencies (SPIRV-Cross,
SPIRV-Tools, SPIRV-Headers, glslang, OpenGL-Registry, ezxml) are not in the repository: MGL's
`external/clone_external.sh` downloads them.

## Building and testing

Needs the Command Line Tools (`xcode-select --install`). Everything is driven from the USB with double-click
launchers, or from a Terminal:

```sh
zsh tools/mgl-build.sh     # COMPILAR-MGL.command   — builds src/MGL: libmgl.dylib, libmgl_es.dylib, libglfw.dylib
zsh tools/mgl-test.sh      # TESTAR-MGL.command     — the offscreen clear+readback GPU probe above
zsh tools/mgl-triangle.sh  # TRIANGULO-MGL.command  — the RGB-triangle shader demo, writes mgl-triangulo.bmp
zsh tools/mgl-window.sh    # JANELA-MGL.command     — the window test: the triangle in a GLFW window for ~6 s
zsh tools/mgl-cocoa.sh     # COCOA-MGL.command      — native Cocoa window (no GLFW), triangle via MGL
zsh tools/mgl-shim.sh      # SHIM-GL.command        — redirect an unmodified NSOpenGL app to MGL (DYLD shim)
```

In a VostroXe checkout, `mgl-build.sh` builds `src/MGL` in place (products in `src/MGL/build/`). On the USB stick it
uses `mgl-src.tar.gz`, an archive of `src/MGL` made with
`git archive --format=tar.gz --add-virtual-file=.vostroxe-commit:$(git rev-parse HEAD) -o mgl-src.tar.gz HEAD:src/MGL`,
and copies it to `~/VostroXe-MGL`, replacing only the files that changed so `make` rebuilds only those. The
dependencies are built once, which needs internet; later builds reuse them, including the ones an earlier version of
the script built under `~/MGL/external`. The first build with nothing cached (Sequoia 15.8.2, 1 Nov: the dependencies
downloaded and built, and a standalone cmake downloaded) took 21 minutes. The offscreen probes link `libmgl.dylib`
alone and the window test links `libglfw.dylib` and `libmgl.dylib`, as an app would.

## The six fixes to MGL

MGL as published does not run on this machine. These are the changes in `src/MGL`, one commit each:

| # | Commit | File | What and why |
|---|---|---|---|
| A | `2c10a17` | `MGL/src/glm_params.c` | Drop `kCGLPFAAccelerated` from `getMacOSDefaults`. MGL bootstraps its default GL state from a CGL context; an **accelerated** CGL pixel format is exactly what fails on this GPU (issue #21), so it aborted at startup. Without the flag the defaults come from the software renderer (same spec values) and MGL still renders on Metal. |
| B | `dadfbdf` | `Makefile` | `$(mgl_gl_obj)` → `$(mgl_core_obj)`. An upstream typo left `gl_core.o` (the `glXxx` entry points) out of `libmgl.dylib`, so the library exported no GL functions (the GLFW backend's `dlsym` and any app would fail to link). The ES library already did this correctly. |
| C | `3174ec2` | `MGL/src/MGLRenderer.m` | In `newRenderEncoder`, create the FBO colour attachment's Metal texture (`is_render_target = true` + `bindMTLTexture`) before use. It was only created lazily when a texture was *sampled*, so rendering **to** an FBO texture hit `assert(tex->mtl_data)`. |
| D | `3711e09` | `MGL/src/MGLRenderer.m` | Implement `glReadPixels` from an FBO in `mtlReadDrawable`. The read-from-framebuffer branch was stubbed (it logged and returned); it now blits the attachment texture to a shared `MTLBuffer` and copies it out. |
| E | `e391506` | `MGL/src/MGLRenderer.m` | Honour a global `glClear` on FBO attachments. The per-attachment loop only cleared when the `glClearBufferfv` bitmask was set and forced `loadAction = Load` otherwise, so a plain `glClear(GL_COLOR_BUFFER_BIT)` never cleared a bound FBO. |
| F | `fd69261` | `MGL/src/MGLRenderer.m` | Raise MGL's pointer "safety" ceilings. It rejected context, device and framebuffer pointers above `0x100000000000` (~17 TB, 12 checks) and, in one check, above `0x100000000` (4 GB). macOS x86_64 pointers sit just below 2^47 (~140 TB), above both, so `glDrawArrays` aborted ("Invalid GLM context", then "Invalid framebuffer pointer"). Every check now uses `0x800000000000` (2^47). |

Fix A gets MGL past startup; B exports the GL entry points that apps and MGL's GLFW look up; C, D and E make an
offscreen FBO clear, draw and read back; F lets draw calls run at all on macOS pointers. Until 31 Oct the build
script applied these with `perl` to a clone of MGL; the commits are, token for token (comments and whitespace
aside), the patched sources that passed the GPU tests above.

## Scope and honest limits

- **Per-app, not system-wide.** GL reaches the GPU for a program linked against MGL (`libmgl.dylib`, plus
  `libglfw.dylib` for GLFW apps), or for an **unmodified** native app launched under the shim
  (`DYLD_INSERT_LIBRARIES=mglshim.dylib`). The system's native OpenGL is still the Apple Software Renderer; nothing
  changes for an app you don't route. The shim needs library validation off (the `amfi` / `ngreenlv` configs here).
- **`GL_RENDERER` is `"MGL"`**, a fixed string. The hardware proof is the Metal device (`Intel(R) TGL`) and the
  read-back pixel, not the renderer string.
- **Coverage is partial** (MGL is not a conformant GL): vertex/fragment/compute shaders, buffers, textures, FBOs,
  most draw calls, instancing. **No geometry shaders and no `double` in shaders** (Metal limits).
- **Confirmed offscreen (FBO) and in a window on the screen**, each with a vertex+fragment shader draw. The first
  window try (31 Oct) got NULL from `glfwCreateWindow`, most likely because `libmgl.dylib` did not export its `gl*`
  functions yet (fix B): MGL's GLFW looks them up in that library, and the lookup then reached Apple's `glGetString`
  through libmgl's link to OpenGL.framework, which gives no version string without a CGL context. The log line
  `MGL: Initialized headless Metal renderer` is not a fallback: a constructor in `libmgl` (`MGL/src/glm_context.c`,
  which its comment ties to QEMU) creates that renderer when the library loads, in every program, before `main()`.
  A window's context then creates its own renderer.
- **Split across two macOS versions:** the offscreen probes ran on Tahoe 26.7.1; the GLFW window, the native Cocoa
  window and the shim ran on Sequoia 15.8.2. None of the on-screen paths have run on Tahoe with the current build.
- **FBO readback is top-origin** (Metal's texture convention), the opposite of GL's bottom-origin; a consumer that
  reads an FBO (screenshots, `glReadPixels`) must flip, as the triangle demo does.
- The Android emulator's slow GL is a **separate** problem (its own ANGLE/gfxstream, not this stack);
  see [EMULATOR.md](EMULATOR.md).

## Next

- Expand the shim's `gl*` interpose from the 22-function proof to the full MGL export set (generated), and implement
  MGL's `glBindAttribLocation` / `glBindFragDataLocation` so legacy shaders map their attributes correctly.
- Point the shim at a real native GL app and fix what it hits.
- Run the on-screen tests on Tahoe 26.7.1 (only the offscreen probes have run there).
- Measure performance against the Apple Software Renderer on a non-trivial scene.
