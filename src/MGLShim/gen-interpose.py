#!/usr/bin/env python3
# VostroXe: gera mgl_gl_interpose.c a partir das definições gl* do MGL (src/MGL/MGL/src/gl_core.c).
#
# Para cada função glXxx que o MGL implementa, emite:
#   - um extern fraco (weak_import) da glXxx da Apple  -> o "original" do interpose (NULL se a Apple não exporta)
#   - um ponteiro para a glXxx do MGL                  -> resolvido via dlsym na libmgl
#   - um wrapper w_glXxx com a mesma assinatura         -> repassa para o ponteiro do MGL
#   - a entrada __DATA,__interpose {w_glXxx, glXxx}
#   - a linha de carga em mglshim_gl_init()
#
# Assim o shim (mglshim.m) redireciona TODAS as gl* do app para o MGL, não só as 22 da sonda.
# Rode:  python3 src/MGLShim/gen-interpose.py   (reescreve src/MGLShim/mgl_gl_interpose.c)
import re, sys, os

HERE = os.path.dirname(os.path.abspath(__file__))
GLCORE = os.path.join(HERE, "..", "MGL", "MGL", "src", "gl_core.c")
GLCOREARB = os.path.join(HERE, "..", "MGL", "MGL", "include", "GL", "glcorearb.h")
OUT = os.path.join(HERE, "mgl_gl_interpose.c")

TYPE_WORDS = {"void","const","unsigned","signed","int","char","short","long","float","double","struct"}

def arg_name(param, i):
    ids = re.findall(r"[A-Za-z_]\w*", param)
    if not ids:
        return f"a{i}"
    name = ids[-1]
    if name in TYPE_WORDS:        # parâmetro sem nome (não deve ocorrer)
        return f"a{i}"
    return name

def implemented_names(path):
    # nomes das gl* que o MGL REALMENTE implementa (definições de coluna 0 seguidas de "{")
    with open(path, encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    sig = re.compile(r"^([A-Za-z_].*?)\b(gl[A-Z]\w*)\s*\((.*)\)\s*$")
    names = set()
    for idx, line in enumerate(lines):
        m = sig.match(line.rstrip("\n"))
        if not m:
            continue
        nxt = ""
        for j in range(idx+1, min(idx+3, len(lines))):
            if lines[j].strip():
                nxt = lines[j].strip(); break
        if nxt.startswith("{"):
            names.add(m.group(2))
    return names

def glcorearb_protos(path):
    # assinaturas AUTORITATIVAS do Khronos: "GLAPI <ret> APIENTRY glFoo (<params>);"
    protos = {}
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = re.match(r"^GLAPI\s+(.+?)\s*APIENTRY\s+(gl[A-Z]\w*)\s*\((.*)\);\s*$", line.strip())
            if m:
                protos[m.group(2)] = (m.group(1).strip(), m.group(3).strip())
    return protos

def parse():
    impl = implemented_names(GLCORE)
    protos = glcorearb_protos(GLCOREARB)
    funcs = {n: protos[n] for n in sorted(impl) if n in protos}
    missing = sorted(impl - set(protos))   # implementadas pelo MGL mas sem protótipo Khronos (nomes internos): ignoradas
    return funcs, len(impl), missing

def split_params(params):
    p = params.strip()
    if p == "" or p == "void":
        return []
    # não há parênteses aninhados nos params do gl_core.c (GLDEBUGPROC é typedef), split simples
    return [x.strip() for x in p.split(",")]

def gen(funcs):
    out = []
    w = out.append
    w("/* GERADO por src/MGLShim/gen-interpose.py — não edite à mão. */")
    w("/* Redireciona as gl* do app para o MGL via DYLD interpose, COM PORTÃO: só desvia enquanto o contexto */")
    w("/* MGL do app está corrente (mglshim_active). Fora disso repassa para a gl* real da Apple (a_*), para não */")
    w("/* capturar as chamadas GL internas do AppKit durante a criação do contexto. */")
    w("#include <GL/glcorearb.h>")
    w("#include <dlfcn.h>")
    w("")
    w("#if defined(__APPLE__)")
    w("#define WEAKGL __attribute__((weak_import))")
    w("#define INTERPOSE(fn) __attribute__((used)) static const struct { const void *r; const void *o; } \\")
    w("  _ip_##fn __attribute__((section(\"__DATA,__interpose\"))) = { (const void*)&w_##fn, (const void*)&fn };")
    w("#else")
    w("#define WEAKGL")
    w("#define INTERPOSE(fn)")
    w("#endif")
    w("")
    w("int mglshim_active = 0;   /* 1 enquanto o contexto MGL do app está corrente (definido em mglshim.m) */")
    w("")
    names = sorted(funcs.keys())
    for name in names:
        ret, params = funcs[name]
        plist = split_params(params)
        decl_params = ", ".join(plist) if plist else "void"
        args = ", ".join(arg_name(p, i) for i, p in enumerate(plist))
        is_void = (re.sub(r"\s+", " ", ret).strip() == "void")
        w(f"{ret} {name}({decl_params}) WEAKGL;")
        w(f"static {ret} (*p_{name})({decl_params});")   # impl do MGL
        w(f"static {ret} (*a_{name})({decl_params});")   # impl da Apple (fallback)
        if is_void:
            w(f"static {ret} w_{name}({decl_params}) {{ if (mglshim_active && p_{name}) {{ p_{name}({args}); return; }} if (a_{name}) a_{name}({args}); }}")
        else:
            w(f"static {ret} w_{name}({decl_params}) {{ if (mglshim_active && p_{name}) return p_{name}({args}); if (a_{name}) return a_{name}({args}); return ({ret})0; }}")
        w(f"INTERPOSE({name})")
    w("")
    w("/* mgl = libmgl.dylib (impl do MGL); apple = libGL.dylib da Apple (fallback). Devolve quantas gl* o MGL tem. */")
    w("int mglshim_gl_init(void *mgl, void *apple) {")
    w("    int n = 0;")
    for name in names:
        w(f'    *(void **)&p_{name} = dlsym(mgl, "{name}"); *(void **)&a_{name} = apple ? dlsym(apple, "{name}") : (void*)0; if (p_{name}) n++;')
    w("    return n;")
    w("}")
    w("")
    return "\n".join(out)

if __name__ == "__main__":
    funcs, n_impl, missing = parse()
    src = gen(funcs)
    with open(OUT, "w", encoding="utf-8") as f:
        f.write(src)
    print(f"{n_impl} gl* implementadas no MGL; {len(funcs)} com protótipo Khronos -> {os.path.relpath(OUT)}")
    if missing:
        print(f"  {len(missing)} sem protótipo Khronos (ignoradas): {', '.join(missing[:12])}{' ...' if len(missing)>12 else ''}")
