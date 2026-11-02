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
OUT = os.path.join(HERE, "mgl_gl_interpose.c")

TYPE_WORDS = {"void","const","unsigned","signed","int","char","short","long","float","double","struct"}

def arg_name(param, i):
    ids = re.findall(r"[A-Za-z_]\w*", param)
    if not ids:
        return f"a{i}"
    name = ids[-1]
    if name in TYPE_WORDS:        # parâmetro sem nome (não deve ocorrer em definições)
        return f"a{i}"
    return name

def parse(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    # assinatura de definição: linha de coluna 0 "RET glXxx(params)" seguida de linha que começa com "{"
    sig = re.compile(r"^([A-Za-z_].*?)\b(gl[A-Z]\w*)\s*\((.*)\)\s*$")
    funcs = {}
    for idx, line in enumerate(lines):
        m = sig.match(line.rstrip("\n"))
        if not m:
            continue
        nxt = ""
        for j in range(idx+1, min(idx+3, len(lines))):
            if lines[j].strip():
                nxt = lines[j].strip(); break
        if not nxt.startswith("{"):
            continue
        ret = m.group(1).strip()
        name = m.group(2)
        params = m.group(3).strip()
        funcs[name] = (ret, params)   # dedupe: última definição vence
    return funcs

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
    w("/* Redireciona todas as gl* do app para o MGL via DYLD interpose. */")
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
    names = sorted(funcs.keys())
    for name in names:
        ret, params = funcs[name]
        plist = split_params(params)
        decl_params = ", ".join(plist) if plist else "void"
        args = ", ".join(arg_name(p, i) for i, p in enumerate(plist))
        is_void = (re.sub(r"\s+", " ", ret).strip() == "void")
        w(f"{ret} {name}({decl_params}) WEAKGL;")
        w(f"static {ret} (*p_{name})({decl_params});")
        if is_void:
            w(f"static {ret} w_{name}({decl_params}) {{ if (p_{name}) p_{name}({args}); }}")
        else:
            w(f"static {ret} w_{name}({decl_params}) {{ if (!p_{name}) return ({ret})0; return p_{name}({args}); }}")
        w(f"INTERPOSE({name})")
    w("")
    w("int mglshim_gl_init(void *h) {")
    w("    int n = 0;")
    for name in names:
        w(f'    *(void **)&p_{name} = dlsym(h, "{name}"); if (p_{name}) n++;')
    w("    return n;")
    w("}")
    w("")
    return "\n".join(out)

if __name__ == "__main__":
    funcs = parse(GLCORE)
    src = gen(funcs)
    with open(OUT, "w", encoding="utf-8") as f:
        f.write(src)
    print(f"{len(funcs)} funções gl* -> {os.path.relpath(OUT)}")
