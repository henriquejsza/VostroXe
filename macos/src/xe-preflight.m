// Loads a libxedrv.dylib in a normal process, so its constructor runs the descriptor-layout preflight against the
// Metal.framework of the running macOS, without the Iris Xe driver and without rebooting. The verdict goes to
// /tmp/xedrv-xe-preflight.log ("layout: Sequoia -> conversão ligada" when the conversion would be used).
//   clang -fobjc-arc -framework Foundation -framework Metal xe-preflight.m -o /tmp/xe-preflight
//   /tmp/xe-preflight <path to libxedrv.dylib>
#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv) {
  if (argc < 2) { fprintf(stderr, "usage: %s <libxedrv.dylib>\n", argv[0]); return 2; }
  @autoreleasepool {
    (void)[MTLRenderPipelineDescriptor class];   // Metal is loaded before libxedrv, as in a real process
    void* h = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!h) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
  }
  return 0;
}
