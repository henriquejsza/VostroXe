/* GERADO por src/MGLShim/gen-interpose.py — não edite à mão. */
/* Redireciona as gl* do app para o MGL via DYLD interpose, COM PORTÃO: só desvia enquanto o contexto */
/* MGL do app está corrente (mglshim_active). Fora disso repassa para a gl* real da Apple (a_*), para não */
/* capturar as chamadas GL internas do AppKit durante a criação do contexto. */
#define _GNU_SOURCE 1   /* RTLD_NEXT (no macOS já vem; no Linux precisa, para o syntax-check) */
#include <GL/glcorearb.h>
#include <dlfcn.h>

#if defined(__APPLE__)
#define WEAKGL __attribute__((weak_import))
#define INTERPOSE(fn) __attribute__((used)) static const struct { const void *r; const void *o; } \
  _ip_##fn __attribute__((section("__DATA,__interpose"))) = { (const void*)&w_##fn, (const void*)&fn };
#else
#define WEAKGL
#define INTERPOSE(fn)
#endif

int mglshim_active = 0;   /* 1 enquanto o contexto MGL do app está corrente (definido em mglshim.m) */

void glActiveShaderProgram(GLuint pipeline, GLuint program) WEAKGL;
static void (*p_glActiveShaderProgram)(GLuint pipeline, GLuint program);
static void (*a_glActiveShaderProgram)(GLuint pipeline, GLuint program);
static void w_glActiveShaderProgram(GLuint pipeline, GLuint program) { if (mglshim_active && p_glActiveShaderProgram) { p_glActiveShaderProgram(pipeline, program); return; } if (a_glActiveShaderProgram) a_glActiveShaderProgram(pipeline, program); }
INTERPOSE(glActiveShaderProgram)
void glActiveTexture(GLenum texture) WEAKGL;
static void (*p_glActiveTexture)(GLenum texture);
static void (*a_glActiveTexture)(GLenum texture);
static void w_glActiveTexture(GLenum texture) { if (mglshim_active && p_glActiveTexture) { p_glActiveTexture(texture); return; } if (a_glActiveTexture) a_glActiveTexture(texture); }
INTERPOSE(glActiveTexture)
void glAttachShader(GLuint program, GLuint shader) WEAKGL;
static void (*p_glAttachShader)(GLuint program, GLuint shader);
static void (*a_glAttachShader)(GLuint program, GLuint shader);
static void w_glAttachShader(GLuint program, GLuint shader) { if (mglshim_active && p_glAttachShader) { p_glAttachShader(program, shader); return; } if (a_glAttachShader) a_glAttachShader(program, shader); }
INTERPOSE(glAttachShader)
void glBeginConditionalRender(GLuint id, GLenum mode) WEAKGL;
static void (*p_glBeginConditionalRender)(GLuint id, GLenum mode);
static void (*a_glBeginConditionalRender)(GLuint id, GLenum mode);
static void w_glBeginConditionalRender(GLuint id, GLenum mode) { if (mglshim_active && p_glBeginConditionalRender) { p_glBeginConditionalRender(id, mode); return; } if (a_glBeginConditionalRender) a_glBeginConditionalRender(id, mode); }
INTERPOSE(glBeginConditionalRender)
void glBeginQuery(GLenum target, GLuint id) WEAKGL;
static void (*p_glBeginQuery)(GLenum target, GLuint id);
static void (*a_glBeginQuery)(GLenum target, GLuint id);
static void w_glBeginQuery(GLenum target, GLuint id) { if (mglshim_active && p_glBeginQuery) { p_glBeginQuery(target, id); return; } if (a_glBeginQuery) a_glBeginQuery(target, id); }
INTERPOSE(glBeginQuery)
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) WEAKGL;
static void (*p_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
static void (*a_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
static void w_glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) { if (mglshim_active && p_glBeginQueryIndexed) { p_glBeginQueryIndexed(target, index, id); return; } if (a_glBeginQueryIndexed) a_glBeginQueryIndexed(target, index, id); }
INTERPOSE(glBeginQueryIndexed)
void glBeginTransformFeedback(GLenum primitiveMode) WEAKGL;
static void (*p_glBeginTransformFeedback)(GLenum primitiveMode);
static void (*a_glBeginTransformFeedback)(GLenum primitiveMode);
static void w_glBeginTransformFeedback(GLenum primitiveMode) { if (mglshim_active && p_glBeginTransformFeedback) { p_glBeginTransformFeedback(primitiveMode); return; } if (a_glBeginTransformFeedback) a_glBeginTransformFeedback(primitiveMode); }
INTERPOSE(glBeginTransformFeedback)
void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) WEAKGL;
static void (*p_glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
static void (*a_glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
static void w_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) { if (mglshim_active && p_glBindAttribLocation) { p_glBindAttribLocation(program, index, name); return; } if (a_glBindAttribLocation) a_glBindAttribLocation(program, index, name); }
INTERPOSE(glBindAttribLocation)
void glBindBuffer(GLenum target, GLuint buffer) WEAKGL;
static void (*p_glBindBuffer)(GLenum target, GLuint buffer);
static void (*a_glBindBuffer)(GLenum target, GLuint buffer);
static void w_glBindBuffer(GLenum target, GLuint buffer) { if (mglshim_active && p_glBindBuffer) { p_glBindBuffer(target, buffer); return; } if (a_glBindBuffer) a_glBindBuffer(target, buffer); }
INTERPOSE(glBindBuffer)
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) WEAKGL;
static void (*p_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
static void (*a_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
static void w_glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { if (mglshim_active && p_glBindBufferBase) { p_glBindBufferBase(target, index, buffer); return; } if (a_glBindBufferBase) a_glBindBufferBase(target, index, buffer); }
INTERPOSE(glBindBufferBase)
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void (*a_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (mglshim_active && p_glBindBufferRange) { p_glBindBufferRange(target, index, buffer, offset, size); return; } if (a_glBindBufferRange) a_glBindBufferRange(target, index, buffer, offset, size); }
INTERPOSE(glBindBufferRange)
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) WEAKGL;
static void (*p_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
static void (*a_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
static void w_glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) { if (mglshim_active && p_glBindBuffersBase) { p_glBindBuffersBase(target, first, count, buffers); return; } if (a_glBindBuffersBase) a_glBindBuffersBase(target, first, count, buffers); }
INTERPOSE(glBindBuffersBase)
void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) WEAKGL;
static void (*p_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
static void (*a_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
static void w_glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) { if (mglshim_active && p_glBindBuffersRange) { p_glBindBuffersRange(target, first, count, buffers, offsets, sizes); return; } if (a_glBindBuffersRange) a_glBindBuffersRange(target, first, count, buffers, offsets, sizes); }
INTERPOSE(glBindBuffersRange)
void glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name) WEAKGL;
static void (*p_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
static void (*a_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
static void w_glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name) { if (mglshim_active && p_glBindFragDataLocation) { p_glBindFragDataLocation(program, color, name); return; } if (a_glBindFragDataLocation) a_glBindFragDataLocation(program, color, name); }
INTERPOSE(glBindFragDataLocation)
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) WEAKGL;
static void (*p_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
static void (*a_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
static void w_glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) { if (mglshim_active && p_glBindFragDataLocationIndexed) { p_glBindFragDataLocationIndexed(program, colorNumber, index, name); return; } if (a_glBindFragDataLocationIndexed) a_glBindFragDataLocationIndexed(program, colorNumber, index, name); }
INTERPOSE(glBindFragDataLocationIndexed)
void glBindFramebuffer(GLenum target, GLuint framebuffer) WEAKGL;
static void (*p_glBindFramebuffer)(GLenum target, GLuint framebuffer);
static void (*a_glBindFramebuffer)(GLenum target, GLuint framebuffer);
static void w_glBindFramebuffer(GLenum target, GLuint framebuffer) { if (mglshim_active && p_glBindFramebuffer) { p_glBindFramebuffer(target, framebuffer); return; } if (a_glBindFramebuffer) a_glBindFramebuffer(target, framebuffer); }
INTERPOSE(glBindFramebuffer)
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) WEAKGL;
static void (*p_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
static void (*a_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
static void w_glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) { if (mglshim_active && p_glBindImageTexture) { p_glBindImageTexture(unit, texture, level, layered, layer, access, format); return; } if (a_glBindImageTexture) a_glBindImageTexture(unit, texture, level, layered, layer, access, format); }
INTERPOSE(glBindImageTexture)
void glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) WEAKGL;
static void (*p_glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
static void (*a_glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
static void w_glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) { if (mglshim_active && p_glBindImageTextures) { p_glBindImageTextures(first, count, textures); return; } if (a_glBindImageTextures) a_glBindImageTextures(first, count, textures); }
INTERPOSE(glBindImageTextures)
void glBindProgramPipeline(GLuint pipeline) WEAKGL;
static void (*p_glBindProgramPipeline)(GLuint pipeline);
static void (*a_glBindProgramPipeline)(GLuint pipeline);
static void w_glBindProgramPipeline(GLuint pipeline) { if (mglshim_active && p_glBindProgramPipeline) { p_glBindProgramPipeline(pipeline); return; } if (a_glBindProgramPipeline) a_glBindProgramPipeline(pipeline); }
INTERPOSE(glBindProgramPipeline)
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) WEAKGL;
static void (*p_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
static void (*a_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
static void w_glBindRenderbuffer(GLenum target, GLuint renderbuffer) { if (mglshim_active && p_glBindRenderbuffer) { p_glBindRenderbuffer(target, renderbuffer); return; } if (a_glBindRenderbuffer) a_glBindRenderbuffer(target, renderbuffer); }
INTERPOSE(glBindRenderbuffer)
void glBindSampler(GLuint unit, GLuint sampler) WEAKGL;
static void (*p_glBindSampler)(GLuint unit, GLuint sampler);
static void (*a_glBindSampler)(GLuint unit, GLuint sampler);
static void w_glBindSampler(GLuint unit, GLuint sampler) { if (mglshim_active && p_glBindSampler) { p_glBindSampler(unit, sampler); return; } if (a_glBindSampler) a_glBindSampler(unit, sampler); }
INTERPOSE(glBindSampler)
void glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) WEAKGL;
static void (*p_glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
static void (*a_glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
static void w_glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) { if (mglshim_active && p_glBindSamplers) { p_glBindSamplers(first, count, samplers); return; } if (a_glBindSamplers) a_glBindSamplers(first, count, samplers); }
INTERPOSE(glBindSamplers)
void glBindTexture(GLenum target, GLuint texture) WEAKGL;
static void (*p_glBindTexture)(GLenum target, GLuint texture);
static void (*a_glBindTexture)(GLenum target, GLuint texture);
static void w_glBindTexture(GLenum target, GLuint texture) { if (mglshim_active && p_glBindTexture) { p_glBindTexture(target, texture); return; } if (a_glBindTexture) a_glBindTexture(target, texture); }
INTERPOSE(glBindTexture)
void glBindTextureUnit(GLuint unit, GLuint texture) WEAKGL;
static void (*p_glBindTextureUnit)(GLuint unit, GLuint texture);
static void (*a_glBindTextureUnit)(GLuint unit, GLuint texture);
static void w_glBindTextureUnit(GLuint unit, GLuint texture) { if (mglshim_active && p_glBindTextureUnit) { p_glBindTextureUnit(unit, texture); return; } if (a_glBindTextureUnit) a_glBindTextureUnit(unit, texture); }
INTERPOSE(glBindTextureUnit)
void glBindTextures(GLuint first, GLsizei count, const GLuint *textures) WEAKGL;
static void (*p_glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
static void (*a_glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
static void w_glBindTextures(GLuint first, GLsizei count, const GLuint *textures) { if (mglshim_active && p_glBindTextures) { p_glBindTextures(first, count, textures); return; } if (a_glBindTextures) a_glBindTextures(first, count, textures); }
INTERPOSE(glBindTextures)
void glBindTransformFeedback(GLenum target, GLuint id) WEAKGL;
static void (*p_glBindTransformFeedback)(GLenum target, GLuint id);
static void (*a_glBindTransformFeedback)(GLenum target, GLuint id);
static void w_glBindTransformFeedback(GLenum target, GLuint id) { if (mglshim_active && p_glBindTransformFeedback) { p_glBindTransformFeedback(target, id); return; } if (a_glBindTransformFeedback) a_glBindTransformFeedback(target, id); }
INTERPOSE(glBindTransformFeedback)
void glBindVertexArray(GLuint array) WEAKGL;
static void (*p_glBindVertexArray)(GLuint array);
static void (*a_glBindVertexArray)(GLuint array);
static void w_glBindVertexArray(GLuint array) { if (mglshim_active && p_glBindVertexArray) { p_glBindVertexArray(array); return; } if (a_glBindVertexArray) a_glBindVertexArray(array); }
INTERPOSE(glBindVertexArray)
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) WEAKGL;
static void (*p_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
static void (*a_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
static void w_glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { if (mglshim_active && p_glBindVertexBuffer) { p_glBindVertexBuffer(bindingindex, buffer, offset, stride); return; } if (a_glBindVertexBuffer) a_glBindVertexBuffer(bindingindex, buffer, offset, stride); }
INTERPOSE(glBindVertexBuffer)
void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) WEAKGL;
static void (*p_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
static void (*a_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
static void w_glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { if (mglshim_active && p_glBindVertexBuffers) { p_glBindVertexBuffers(first, count, buffers, offsets, strides); return; } if (a_glBindVertexBuffers) a_glBindVertexBuffers(first, count, buffers, offsets, strides); }
INTERPOSE(glBindVertexBuffers)
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void (*a_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (mglshim_active && p_glBlendColor) { p_glBlendColor(red, green, blue, alpha); return; } if (a_glBlendColor) a_glBlendColor(red, green, blue, alpha); }
INTERPOSE(glBlendColor)
void glBlendEquation(GLenum mode) WEAKGL;
static void (*p_glBlendEquation)(GLenum mode);
static void (*a_glBlendEquation)(GLenum mode);
static void w_glBlendEquation(GLenum mode) { if (mglshim_active && p_glBlendEquation) { p_glBlendEquation(mode); return; } if (a_glBlendEquation) a_glBlendEquation(mode); }
INTERPOSE(glBlendEquation)
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) WEAKGL;
static void (*p_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
static void (*a_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
static void w_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { if (mglshim_active && p_glBlendEquationSeparate) { p_glBlendEquationSeparate(modeRGB, modeAlpha); return; } if (a_glBlendEquationSeparate) a_glBlendEquationSeparate(modeRGB, modeAlpha); }
INTERPOSE(glBlendEquationSeparate)
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) WEAKGL;
static void (*p_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
static void (*a_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
static void w_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { if (mglshim_active && p_glBlendEquationSeparatei) { p_glBlendEquationSeparatei(buf, modeRGB, modeAlpha); return; } if (a_glBlendEquationSeparatei) a_glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
INTERPOSE(glBlendEquationSeparatei)
void glBlendEquationi(GLuint buf, GLenum mode) WEAKGL;
static void (*p_glBlendEquationi)(GLuint buf, GLenum mode);
static void (*a_glBlendEquationi)(GLuint buf, GLenum mode);
static void w_glBlendEquationi(GLuint buf, GLenum mode) { if (mglshim_active && p_glBlendEquationi) { p_glBlendEquationi(buf, mode); return; } if (a_glBlendEquationi) a_glBlendEquationi(buf, mode); }
INTERPOSE(glBlendEquationi)
void glBlendFunc(GLenum sfactor, GLenum dfactor) WEAKGL;
static void (*p_glBlendFunc)(GLenum sfactor, GLenum dfactor);
static void (*a_glBlendFunc)(GLenum sfactor, GLenum dfactor);
static void w_glBlendFunc(GLenum sfactor, GLenum dfactor) { if (mglshim_active && p_glBlendFunc) { p_glBlendFunc(sfactor, dfactor); return; } if (a_glBlendFunc) a_glBlendFunc(sfactor, dfactor); }
INTERPOSE(glBlendFunc)
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) WEAKGL;
static void (*p_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
static void (*a_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
static void w_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { if (mglshim_active && p_glBlendFuncSeparate) { p_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); return; } if (a_glBlendFuncSeparate) a_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
INTERPOSE(glBlendFuncSeparate)
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) WEAKGL;
static void (*p_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
static void (*a_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
static void w_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { if (mglshim_active && p_glBlendFuncSeparatei) { p_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); return; } if (a_glBlendFuncSeparatei) a_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
INTERPOSE(glBlendFuncSeparatei)
void glBlendFunci(GLuint buf, GLenum src, GLenum dst) WEAKGL;
static void (*p_glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
static void (*a_glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
static void w_glBlendFunci(GLuint buf, GLenum src, GLenum dst) { if (mglshim_active && p_glBlendFunci) { p_glBlendFunci(buf, src, dst); return; } if (a_glBlendFunci) a_glBlendFunci(buf, src, dst); }
INTERPOSE(glBlendFunci)
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) WEAKGL;
static void (*p_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void (*a_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void w_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { if (mglshim_active && p_glBlitFramebuffer) { p_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); return; } if (a_glBlitFramebuffer) a_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
INTERPOSE(glBlitFramebuffer)
void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) WEAKGL;
static void (*p_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void (*a_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void w_glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { if (mglshim_active && p_glBlitNamedFramebuffer) { p_glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); return; } if (a_glBlitNamedFramebuffer) a_glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
INTERPOSE(glBlitNamedFramebuffer)
void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) WEAKGL;
static void (*p_glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
static void (*a_glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
static void w_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) { if (mglshim_active && p_glBufferData) { p_glBufferData(target, size, data, usage); return; } if (a_glBufferData) a_glBufferData(target, size, data, usage); }
INTERPOSE(glBufferData)
void glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) WEAKGL;
static void (*p_glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
static void (*a_glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
static void w_glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) { if (mglshim_active && p_glBufferStorage) { p_glBufferStorage(target, size, data, flags); return; } if (a_glBufferStorage) a_glBufferStorage(target, size, data, flags); }
INTERPOSE(glBufferStorage)
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) WEAKGL;
static void (*p_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
static void (*a_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
static void w_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) { if (mglshim_active && p_glBufferSubData) { p_glBufferSubData(target, offset, size, data); return; } if (a_glBufferSubData) a_glBufferSubData(target, offset, size, data); }
INTERPOSE(glBufferSubData)
GLenum glCheckFramebufferStatus(GLenum target) WEAKGL;
static GLenum (*p_glCheckFramebufferStatus)(GLenum target);
static GLenum (*a_glCheckFramebufferStatus)(GLenum target);
static GLenum w_glCheckFramebufferStatus(GLenum target) { if (mglshim_active && p_glCheckFramebufferStatus) return p_glCheckFramebufferStatus(target); if (a_glCheckFramebufferStatus) return a_glCheckFramebufferStatus(target); return (GLenum)0; }
INTERPOSE(glCheckFramebufferStatus)
GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) WEAKGL;
static GLenum (*p_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
static GLenum (*a_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
static GLenum w_glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) { if (mglshim_active && p_glCheckNamedFramebufferStatus) return p_glCheckNamedFramebufferStatus(framebuffer, target); if (a_glCheckNamedFramebufferStatus) return a_glCheckNamedFramebufferStatus(framebuffer, target); return (GLenum)0; }
INTERPOSE(glCheckNamedFramebufferStatus)
void glClampColor(GLenum target, GLenum clamp) WEAKGL;
static void (*p_glClampColor)(GLenum target, GLenum clamp);
static void (*a_glClampColor)(GLenum target, GLenum clamp);
static void w_glClampColor(GLenum target, GLenum clamp) { if (mglshim_active && p_glClampColor) { p_glClampColor(target, clamp); return; } if (a_glClampColor) a_glClampColor(target, clamp); }
INTERPOSE(glClampColor)
void glClear(GLbitfield mask) WEAKGL;
static void (*p_glClear)(GLbitfield mask);
static void (*a_glClear)(GLbitfield mask);
static void w_glClear(GLbitfield mask) { if (mglshim_active && p_glClear) { p_glClear(mask); return; } if (a_glClear) a_glClear(mask); }
INTERPOSE(glClear)
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
static void (*a_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
static void w_glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) { if (mglshim_active && p_glClearBufferData) { p_glClearBufferData(target, internalformat, format, type, data); return; } if (a_glClearBufferData) a_glClearBufferData(target, internalformat, format, type, data); }
INTERPOSE(glClearBufferData)
void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
static void (*a_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
static void w_glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { if (mglshim_active && p_glClearBufferSubData) { p_glClearBufferSubData(target, internalformat, offset, size, format, type, data); return; } if (a_glClearBufferSubData) a_glClearBufferSubData(target, internalformat, offset, size, format, type, data); }
INTERPOSE(glClearBufferSubData)
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) WEAKGL;
static void (*p_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static void (*a_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static void w_glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { if (mglshim_active && p_glClearBufferfi) { p_glClearBufferfi(buffer, drawbuffer, depth, stencil); return; } if (a_glClearBufferfi) a_glClearBufferfi(buffer, drawbuffer, depth, stencil); }
INTERPOSE(glClearBufferfi)
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) WEAKGL;
static void (*p_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void (*a_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void w_glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) { if (mglshim_active && p_glClearBufferfv) { p_glClearBufferfv(buffer, drawbuffer, value); return; } if (a_glClearBufferfv) a_glClearBufferfv(buffer, drawbuffer, value); }
INTERPOSE(glClearBufferfv)
void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) WEAKGL;
static void (*p_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
static void (*a_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
static void w_glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) { if (mglshim_active && p_glClearBufferiv) { p_glClearBufferiv(buffer, drawbuffer, value); return; } if (a_glClearBufferiv) a_glClearBufferiv(buffer, drawbuffer, value); }
INTERPOSE(glClearBufferiv)
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) WEAKGL;
static void (*p_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
static void (*a_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
static void w_glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) { if (mglshim_active && p_glClearBufferuiv) { p_glClearBufferuiv(buffer, drawbuffer, value); return; } if (a_glClearBufferuiv) a_glClearBufferuiv(buffer, drawbuffer, value); }
INTERPOSE(glClearBufferuiv)
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void (*a_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (mglshim_active && p_glClearColor) { p_glClearColor(red, green, blue, alpha); return; } if (a_glClearColor) a_glClearColor(red, green, blue, alpha); }
INTERPOSE(glClearColor)
void glClearDepth(GLdouble depth) WEAKGL;
static void (*p_glClearDepth)(GLdouble depth);
static void (*a_glClearDepth)(GLdouble depth);
static void w_glClearDepth(GLdouble depth) { if (mglshim_active && p_glClearDepth) { p_glClearDepth(depth); return; } if (a_glClearDepth) a_glClearDepth(depth); }
INTERPOSE(glClearDepth)
void glClearDepthf(GLfloat d) WEAKGL;
static void (*p_glClearDepthf)(GLfloat d);
static void (*a_glClearDepthf)(GLfloat d);
static void w_glClearDepthf(GLfloat d) { if (mglshim_active && p_glClearDepthf) { p_glClearDepthf(d); return; } if (a_glClearDepthf) a_glClearDepthf(d); }
INTERPOSE(glClearDepthf)
void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
static void (*a_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
static void w_glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) { if (mglshim_active && p_glClearNamedBufferData) { p_glClearNamedBufferData(buffer, internalformat, format, type, data); return; } if (a_glClearNamedBufferData) a_glClearNamedBufferData(buffer, internalformat, format, type, data); }
INTERPOSE(glClearNamedBufferData)
void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
static void (*a_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
static void w_glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { if (mglshim_active && p_glClearNamedBufferSubData) { p_glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data); return; } if (a_glClearNamedBufferSubData) a_glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data); }
INTERPOSE(glClearNamedBufferSubData)
void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) WEAKGL;
static void (*p_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static void (*a_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static void w_glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { if (mglshim_active && p_glClearNamedFramebufferfi) { p_glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil); return; } if (a_glClearNamedFramebufferfi) a_glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil); }
INTERPOSE(glClearNamedFramebufferfi)
void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) WEAKGL;
static void (*p_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void (*a_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void w_glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) { if (mglshim_active && p_glClearNamedFramebufferfv) { p_glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value); return; } if (a_glClearNamedFramebufferfv) a_glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value); }
INTERPOSE(glClearNamedFramebufferfv)
void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) WEAKGL;
static void (*p_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
static void (*a_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
static void w_glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) { if (mglshim_active && p_glClearNamedFramebufferiv) { p_glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value); return; } if (a_glClearNamedFramebufferiv) a_glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value); }
INTERPOSE(glClearNamedFramebufferiv)
void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) WEAKGL;
static void (*p_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
static void (*a_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
static void w_glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) { if (mglshim_active && p_glClearNamedFramebufferuiv) { p_glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value); return; } if (a_glClearNamedFramebufferuiv) a_glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value); }
INTERPOSE(glClearNamedFramebufferuiv)
void glClearStencil(GLint s) WEAKGL;
static void (*p_glClearStencil)(GLint s);
static void (*a_glClearStencil)(GLint s);
static void w_glClearStencil(GLint s) { if (mglshim_active && p_glClearStencil) { p_glClearStencil(s); return; } if (a_glClearStencil) a_glClearStencil(s); }
INTERPOSE(glClearStencil)
void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
static void (*a_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
static void w_glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data) { if (mglshim_active && p_glClearTexImage) { p_glClearTexImage(texture, level, format, type, data); return; } if (a_glClearTexImage) a_glClearTexImage(texture, level, format, type, data); }
INTERPOSE(glClearTexImage)
void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
static void (*a_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
static void w_glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) { if (mglshim_active && p_glClearTexSubImage) { p_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); return; } if (a_glClearTexSubImage) a_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); }
INTERPOSE(glClearTexSubImage)
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) WEAKGL;
static GLenum (*p_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
static GLenum (*a_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
static GLenum w_glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { if (mglshim_active && p_glClientWaitSync) return p_glClientWaitSync(sync, flags, timeout); if (a_glClientWaitSync) return a_glClientWaitSync(sync, flags, timeout); return (GLenum)0; }
INTERPOSE(glClientWaitSync)
void glClipControl(GLenum origin, GLenum depth) WEAKGL;
static void (*p_glClipControl)(GLenum origin, GLenum depth);
static void (*a_glClipControl)(GLenum origin, GLenum depth);
static void w_glClipControl(GLenum origin, GLenum depth) { if (mglshim_active && p_glClipControl) { p_glClipControl(origin, depth); return; } if (a_glClipControl) a_glClipControl(origin, depth); }
INTERPOSE(glClipControl)
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) WEAKGL;
static void (*p_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
static void (*a_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
static void w_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { if (mglshim_active && p_glColorMask) { p_glColorMask(red, green, blue, alpha); return; } if (a_glColorMask) a_glColorMask(red, green, blue, alpha); }
INTERPOSE(glColorMask)
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) WEAKGL;
static void (*p_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
static void (*a_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
static void w_glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { if (mglshim_active && p_glColorMaski) { p_glColorMaski(index, r, g, b, a); return; } if (a_glColorMaski) a_glColorMaski(index, r, g, b, a); }
INTERPOSE(glColorMaski)
void glCompileShader(GLuint shader) WEAKGL;
static void (*p_glCompileShader)(GLuint shader);
static void (*a_glCompileShader)(GLuint shader);
static void w_glCompileShader(GLuint shader) { if (mglshim_active && p_glCompileShader) { p_glCompileShader(shader); return; } if (a_glCompileShader) a_glCompileShader(shader); }
INTERPOSE(glCompileShader)
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
static void (*a_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
static void w_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTexImage1D) { p_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); return; } if (a_glCompressedTexImage1D) a_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
INTERPOSE(glCompressedTexImage1D)
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
static void (*a_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
static void w_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTexImage2D) { p_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); return; } if (a_glCompressedTexImage2D) a_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
INTERPOSE(glCompressedTexImage2D)
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
static void (*a_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
static void w_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTexImage3D) { p_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); return; } if (a_glCompressedTexImage3D) a_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
INTERPOSE(glCompressedTexImage3D)
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
static void (*a_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTexSubImage1D) { p_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); return; } if (a_glCompressedTexSubImage1D) a_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
INTERPOSE(glCompressedTexSubImage1D)
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
static void (*a_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTexSubImage2D) { p_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); return; } if (a_glCompressedTexSubImage2D) a_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
INTERPOSE(glCompressedTexSubImage2D)
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
static void (*a_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTexSubImage3D) { p_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); return; } if (a_glCompressedTexSubImage3D) a_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
INTERPOSE(glCompressedTexSubImage3D)
void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
static void (*a_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTextureSubImage1D) { p_glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data); return; } if (a_glCompressedTextureSubImage1D) a_glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data); }
INTERPOSE(glCompressedTextureSubImage1D)
void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
static void (*a_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTextureSubImage2D) { p_glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data); return; } if (a_glCompressedTextureSubImage2D) a_glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data); }
INTERPOSE(glCompressedTextureSubImage2D)
void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
static void (*a_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { if (mglshim_active && p_glCompressedTextureSubImage3D) { p_glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); return; } if (a_glCompressedTextureSubImage3D) a_glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
INTERPOSE(glCompressedTextureSubImage3D)
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) WEAKGL;
static void (*p_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
static void (*a_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
static void w_glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { if (mglshim_active && p_glCopyBufferSubData) { p_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); return; } if (a_glCopyBufferSubData) a_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
INTERPOSE(glCopyBufferSubData)
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) WEAKGL;
static void (*p_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
static void (*a_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
static void w_glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) { if (mglshim_active && p_glCopyImageSubData) { p_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); return; } if (a_glCopyImageSubData) a_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }
INTERPOSE(glCopyImageSubData)
void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) WEAKGL;
static void (*p_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
static void (*a_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
static void w_glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { if (mglshim_active && p_glCopyNamedBufferSubData) { p_glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size); return; } if (a_glCopyNamedBufferSubData) a_glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size); }
INTERPOSE(glCopyNamedBufferSubData)
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) WEAKGL;
static void (*p_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
static void (*a_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
static void w_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) { if (mglshim_active && p_glCopyTexImage1D) { p_glCopyTexImage1D(target, level, internalformat, x, y, width, border); return; } if (a_glCopyTexImage1D) a_glCopyTexImage1D(target, level, internalformat, x, y, width, border); }
INTERPOSE(glCopyTexImage1D)
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) WEAKGL;
static void (*p_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
static void (*a_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
static void w_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { if (mglshim_active && p_glCopyTexImage2D) { p_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); return; } if (a_glCopyTexImage2D) a_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
INTERPOSE(glCopyTexImage2D)
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) WEAKGL;
static void (*p_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void (*a_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void w_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { if (mglshim_active && p_glCopyTexSubImage1D) { p_glCopyTexSubImage1D(target, level, xoffset, x, y, width); return; } if (a_glCopyTexSubImage1D) a_glCopyTexSubImage1D(target, level, xoffset, x, y, width); }
INTERPOSE(glCopyTexSubImage1D)
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glCopyTexSubImage2D) { p_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); return; } if (a_glCopyTexSubImage2D) a_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
INTERPOSE(glCopyTexSubImage2D)
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glCopyTexSubImage3D) { p_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); return; } if (a_glCopyTexSubImage3D) a_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
INTERPOSE(glCopyTexSubImage3D)
void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) WEAKGL;
static void (*p_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void (*a_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void w_glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { if (mglshim_active && p_glCopyTextureSubImage1D) { p_glCopyTextureSubImage1D(texture, level, xoffset, x, y, width); return; } if (a_glCopyTextureSubImage1D) a_glCopyTextureSubImage1D(texture, level, xoffset, x, y, width); }
INTERPOSE(glCopyTextureSubImage1D)
void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glCopyTextureSubImage2D) { p_glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height); return; } if (a_glCopyTextureSubImage2D) a_glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height); }
INTERPOSE(glCopyTextureSubImage2D)
void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glCopyTextureSubImage3D) { p_glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height); return; } if (a_glCopyTextureSubImage3D) a_glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height); }
INTERPOSE(glCopyTextureSubImage3D)
void glCreateBuffers(GLsizei n, GLuint *buffers) WEAKGL;
static void (*p_glCreateBuffers)(GLsizei n, GLuint *buffers);
static void (*a_glCreateBuffers)(GLsizei n, GLuint *buffers);
static void w_glCreateBuffers(GLsizei n, GLuint *buffers) { if (mglshim_active && p_glCreateBuffers) { p_glCreateBuffers(n, buffers); return; } if (a_glCreateBuffers) a_glCreateBuffers(n, buffers); }
INTERPOSE(glCreateBuffers)
void glCreateFramebuffers(GLsizei n, GLuint *framebuffers) WEAKGL;
static void (*p_glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
static void (*a_glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
static void w_glCreateFramebuffers(GLsizei n, GLuint *framebuffers) { if (mglshim_active && p_glCreateFramebuffers) { p_glCreateFramebuffers(n, framebuffers); return; } if (a_glCreateFramebuffers) a_glCreateFramebuffers(n, framebuffers); }
INTERPOSE(glCreateFramebuffers)
GLuint glCreateProgram(void) WEAKGL;
static GLuint (*p_glCreateProgram)(void);
static GLuint (*a_glCreateProgram)(void);
static GLuint w_glCreateProgram(void) { if (mglshim_active && p_glCreateProgram) return p_glCreateProgram(); if (a_glCreateProgram) return a_glCreateProgram(); return (GLuint)0; }
INTERPOSE(glCreateProgram)
void glCreateProgramPipelines(GLsizei n, GLuint *pipelines) WEAKGL;
static void (*p_glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
static void (*a_glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
static void w_glCreateProgramPipelines(GLsizei n, GLuint *pipelines) { if (mglshim_active && p_glCreateProgramPipelines) { p_glCreateProgramPipelines(n, pipelines); return; } if (a_glCreateProgramPipelines) a_glCreateProgramPipelines(n, pipelines); }
INTERPOSE(glCreateProgramPipelines)
void glCreateQueries(GLenum target, GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
static void (*a_glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
static void w_glCreateQueries(GLenum target, GLsizei n, GLuint *ids) { if (mglshim_active && p_glCreateQueries) { p_glCreateQueries(target, n, ids); return; } if (a_glCreateQueries) a_glCreateQueries(target, n, ids); }
INTERPOSE(glCreateQueries)
void glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers) WEAKGL;
static void (*p_glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
static void (*a_glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
static void w_glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers) { if (mglshim_active && p_glCreateRenderbuffers) { p_glCreateRenderbuffers(n, renderbuffers); return; } if (a_glCreateRenderbuffers) a_glCreateRenderbuffers(n, renderbuffers); }
INTERPOSE(glCreateRenderbuffers)
void glCreateSamplers(GLsizei n, GLuint *samplers) WEAKGL;
static void (*p_glCreateSamplers)(GLsizei n, GLuint *samplers);
static void (*a_glCreateSamplers)(GLsizei n, GLuint *samplers);
static void w_glCreateSamplers(GLsizei n, GLuint *samplers) { if (mglshim_active && p_glCreateSamplers) { p_glCreateSamplers(n, samplers); return; } if (a_glCreateSamplers) a_glCreateSamplers(n, samplers); }
INTERPOSE(glCreateSamplers)
GLuint glCreateShader(GLenum type) WEAKGL;
static GLuint (*p_glCreateShader)(GLenum type);
static GLuint (*a_glCreateShader)(GLenum type);
static GLuint w_glCreateShader(GLenum type) { if (mglshim_active && p_glCreateShader) return p_glCreateShader(type); if (a_glCreateShader) return a_glCreateShader(type); return (GLuint)0; }
INTERPOSE(glCreateShader)
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) WEAKGL;
static GLuint (*p_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
static GLuint (*a_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
static GLuint w_glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) { if (mglshim_active && p_glCreateShaderProgramv) return p_glCreateShaderProgramv(type, count, strings); if (a_glCreateShaderProgramv) return a_glCreateShaderProgramv(type, count, strings); return (GLuint)0; }
INTERPOSE(glCreateShaderProgramv)
void glCreateTextures(GLenum target, GLsizei n, GLuint *textures) WEAKGL;
static void (*p_glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
static void (*a_glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
static void w_glCreateTextures(GLenum target, GLsizei n, GLuint *textures) { if (mglshim_active && p_glCreateTextures) { p_glCreateTextures(target, n, textures); return; } if (a_glCreateTextures) a_glCreateTextures(target, n, textures); }
INTERPOSE(glCreateTextures)
void glCreateTransformFeedbacks(GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
static void (*a_glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
static void w_glCreateTransformFeedbacks(GLsizei n, GLuint *ids) { if (mglshim_active && p_glCreateTransformFeedbacks) { p_glCreateTransformFeedbacks(n, ids); return; } if (a_glCreateTransformFeedbacks) a_glCreateTransformFeedbacks(n, ids); }
INTERPOSE(glCreateTransformFeedbacks)
void glCreateVertexArrays(GLsizei n, GLuint *arrays) WEAKGL;
static void (*p_glCreateVertexArrays)(GLsizei n, GLuint *arrays);
static void (*a_glCreateVertexArrays)(GLsizei n, GLuint *arrays);
static void w_glCreateVertexArrays(GLsizei n, GLuint *arrays) { if (mglshim_active && p_glCreateVertexArrays) { p_glCreateVertexArrays(n, arrays); return; } if (a_glCreateVertexArrays) a_glCreateVertexArrays(n, arrays); }
INTERPOSE(glCreateVertexArrays)
void glCullFace(GLenum mode) WEAKGL;
static void (*p_glCullFace)(GLenum mode);
static void (*a_glCullFace)(GLenum mode);
static void w_glCullFace(GLenum mode) { if (mglshim_active && p_glCullFace) { p_glCullFace(mode); return; } if (a_glCullFace) a_glCullFace(mode); }
INTERPOSE(glCullFace)
void glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) WEAKGL;
static void (*p_glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
static void (*a_glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
static void w_glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) { if (mglshim_active && p_glDebugMessageCallback) { p_glDebugMessageCallback(callback, userParam); return; } if (a_glDebugMessageCallback) a_glDebugMessageCallback(callback, userParam); }
INTERPOSE(glDebugMessageCallback)
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) WEAKGL;
static void (*p_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
static void (*a_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
static void w_glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) { if (mglshim_active && p_glDebugMessageControl) { p_glDebugMessageControl(source, type, severity, count, ids, enabled); return; } if (a_glDebugMessageControl) a_glDebugMessageControl(source, type, severity, count, ids, enabled); }
INTERPOSE(glDebugMessageControl)
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) WEAKGL;
static void (*p_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
static void (*a_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
static void w_glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) { if (mglshim_active && p_glDebugMessageInsert) { p_glDebugMessageInsert(source, type, id, severity, length, buf); return; } if (a_glDebugMessageInsert) a_glDebugMessageInsert(source, type, id, severity, length, buf); }
INTERPOSE(glDebugMessageInsert)
void glDeleteBuffers(GLsizei n, const GLuint *buffers) WEAKGL;
static void (*p_glDeleteBuffers)(GLsizei n, const GLuint *buffers);
static void (*a_glDeleteBuffers)(GLsizei n, const GLuint *buffers);
static void w_glDeleteBuffers(GLsizei n, const GLuint *buffers) { if (mglshim_active && p_glDeleteBuffers) { p_glDeleteBuffers(n, buffers); return; } if (a_glDeleteBuffers) a_glDeleteBuffers(n, buffers); }
INTERPOSE(glDeleteBuffers)
void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) WEAKGL;
static void (*p_glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
static void (*a_glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
static void w_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) { if (mglshim_active && p_glDeleteFramebuffers) { p_glDeleteFramebuffers(n, framebuffers); return; } if (a_glDeleteFramebuffers) a_glDeleteFramebuffers(n, framebuffers); }
INTERPOSE(glDeleteFramebuffers)
void glDeleteProgram(GLuint program) WEAKGL;
static void (*p_glDeleteProgram)(GLuint program);
static void (*a_glDeleteProgram)(GLuint program);
static void w_glDeleteProgram(GLuint program) { if (mglshim_active && p_glDeleteProgram) { p_glDeleteProgram(program); return; } if (a_glDeleteProgram) a_glDeleteProgram(program); }
INTERPOSE(glDeleteProgram)
void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) WEAKGL;
static void (*p_glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
static void (*a_glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
static void w_glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) { if (mglshim_active && p_glDeleteProgramPipelines) { p_glDeleteProgramPipelines(n, pipelines); return; } if (a_glDeleteProgramPipelines) a_glDeleteProgramPipelines(n, pipelines); }
INTERPOSE(glDeleteProgramPipelines)
void glDeleteQueries(GLsizei n, const GLuint *ids) WEAKGL;
static void (*p_glDeleteQueries)(GLsizei n, const GLuint *ids);
static void (*a_glDeleteQueries)(GLsizei n, const GLuint *ids);
static void w_glDeleteQueries(GLsizei n, const GLuint *ids) { if (mglshim_active && p_glDeleteQueries) { p_glDeleteQueries(n, ids); return; } if (a_glDeleteQueries) a_glDeleteQueries(n, ids); }
INTERPOSE(glDeleteQueries)
void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) WEAKGL;
static void (*p_glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
static void (*a_glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
static void w_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { if (mglshim_active && p_glDeleteRenderbuffers) { p_glDeleteRenderbuffers(n, renderbuffers); return; } if (a_glDeleteRenderbuffers) a_glDeleteRenderbuffers(n, renderbuffers); }
INTERPOSE(glDeleteRenderbuffers)
void glDeleteSamplers(GLsizei count, const GLuint *samplers) WEAKGL;
static void (*p_glDeleteSamplers)(GLsizei count, const GLuint *samplers);
static void (*a_glDeleteSamplers)(GLsizei count, const GLuint *samplers);
static void w_glDeleteSamplers(GLsizei count, const GLuint *samplers) { if (mglshim_active && p_glDeleteSamplers) { p_glDeleteSamplers(count, samplers); return; } if (a_glDeleteSamplers) a_glDeleteSamplers(count, samplers); }
INTERPOSE(glDeleteSamplers)
void glDeleteShader(GLuint shader) WEAKGL;
static void (*p_glDeleteShader)(GLuint shader);
static void (*a_glDeleteShader)(GLuint shader);
static void w_glDeleteShader(GLuint shader) { if (mglshim_active && p_glDeleteShader) { p_glDeleteShader(shader); return; } if (a_glDeleteShader) a_glDeleteShader(shader); }
INTERPOSE(glDeleteShader)
void glDeleteSync(GLsync sync) WEAKGL;
static void (*p_glDeleteSync)(GLsync sync);
static void (*a_glDeleteSync)(GLsync sync);
static void w_glDeleteSync(GLsync sync) { if (mglshim_active && p_glDeleteSync) { p_glDeleteSync(sync); return; } if (a_glDeleteSync) a_glDeleteSync(sync); }
INTERPOSE(glDeleteSync)
void glDeleteTextures(GLsizei n, const GLuint *textures) WEAKGL;
static void (*p_glDeleteTextures)(GLsizei n, const GLuint *textures);
static void (*a_glDeleteTextures)(GLsizei n, const GLuint *textures);
static void w_glDeleteTextures(GLsizei n, const GLuint *textures) { if (mglshim_active && p_glDeleteTextures) { p_glDeleteTextures(n, textures); return; } if (a_glDeleteTextures) a_glDeleteTextures(n, textures); }
INTERPOSE(glDeleteTextures)
void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) WEAKGL;
static void (*p_glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
static void (*a_glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
static void w_glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) { if (mglshim_active && p_glDeleteTransformFeedbacks) { p_glDeleteTransformFeedbacks(n, ids); return; } if (a_glDeleteTransformFeedbacks) a_glDeleteTransformFeedbacks(n, ids); }
INTERPOSE(glDeleteTransformFeedbacks)
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) WEAKGL;
static void (*p_glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
static void (*a_glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
static void w_glDeleteVertexArrays(GLsizei n, const GLuint *arrays) { if (mglshim_active && p_glDeleteVertexArrays) { p_glDeleteVertexArrays(n, arrays); return; } if (a_glDeleteVertexArrays) a_glDeleteVertexArrays(n, arrays); }
INTERPOSE(glDeleteVertexArrays)
void glDepthFunc(GLenum func) WEAKGL;
static void (*p_glDepthFunc)(GLenum func);
static void (*a_glDepthFunc)(GLenum func);
static void w_glDepthFunc(GLenum func) { if (mglshim_active && p_glDepthFunc) { p_glDepthFunc(func); return; } if (a_glDepthFunc) a_glDepthFunc(func); }
INTERPOSE(glDepthFunc)
void glDepthMask(GLboolean flag) WEAKGL;
static void (*p_glDepthMask)(GLboolean flag);
static void (*a_glDepthMask)(GLboolean flag);
static void w_glDepthMask(GLboolean flag) { if (mglshim_active && p_glDepthMask) { p_glDepthMask(flag); return; } if (a_glDepthMask) a_glDepthMask(flag); }
INTERPOSE(glDepthMask)
void glDepthRange(GLdouble n, GLdouble f) WEAKGL;
static void (*p_glDepthRange)(GLdouble n, GLdouble f);
static void (*a_glDepthRange)(GLdouble n, GLdouble f);
static void w_glDepthRange(GLdouble n, GLdouble f) { if (mglshim_active && p_glDepthRange) { p_glDepthRange(n, f); return; } if (a_glDepthRange) a_glDepthRange(n, f); }
INTERPOSE(glDepthRange)
void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) WEAKGL;
static void (*p_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
static void (*a_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
static void w_glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) { if (mglshim_active && p_glDepthRangeArrayv) { p_glDepthRangeArrayv(first, count, v); return; } if (a_glDepthRangeArrayv) a_glDepthRangeArrayv(first, count, v); }
INTERPOSE(glDepthRangeArrayv)
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) WEAKGL;
static void (*p_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
static void (*a_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
static void w_glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) { if (mglshim_active && p_glDepthRangeIndexed) { p_glDepthRangeIndexed(index, n, f); return; } if (a_glDepthRangeIndexed) a_glDepthRangeIndexed(index, n, f); }
INTERPOSE(glDepthRangeIndexed)
void glDepthRangef(GLfloat n, GLfloat f) WEAKGL;
static void (*p_glDepthRangef)(GLfloat n, GLfloat f);
static void (*a_glDepthRangef)(GLfloat n, GLfloat f);
static void w_glDepthRangef(GLfloat n, GLfloat f) { if (mglshim_active && p_glDepthRangef) { p_glDepthRangef(n, f); return; } if (a_glDepthRangef) a_glDepthRangef(n, f); }
INTERPOSE(glDepthRangef)
void glDetachShader(GLuint program, GLuint shader) WEAKGL;
static void (*p_glDetachShader)(GLuint program, GLuint shader);
static void (*a_glDetachShader)(GLuint program, GLuint shader);
static void w_glDetachShader(GLuint program, GLuint shader) { if (mglshim_active && p_glDetachShader) { p_glDetachShader(program, shader); return; } if (a_glDetachShader) a_glDetachShader(program, shader); }
INTERPOSE(glDetachShader)
void glDisable(GLenum cap) WEAKGL;
static void (*p_glDisable)(GLenum cap);
static void (*a_glDisable)(GLenum cap);
static void w_glDisable(GLenum cap) { if (mglshim_active && p_glDisable) { p_glDisable(cap); return; } if (a_glDisable) a_glDisable(cap); }
INTERPOSE(glDisable)
void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) WEAKGL;
static void (*p_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
static void (*a_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
static void w_glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) { if (mglshim_active && p_glDisableVertexArrayAttrib) { p_glDisableVertexArrayAttrib(vaobj, index); return; } if (a_glDisableVertexArrayAttrib) a_glDisableVertexArrayAttrib(vaobj, index); }
INTERPOSE(glDisableVertexArrayAttrib)
void glDisableVertexAttribArray(GLuint index) WEAKGL;
static void (*p_glDisableVertexAttribArray)(GLuint index);
static void (*a_glDisableVertexAttribArray)(GLuint index);
static void w_glDisableVertexAttribArray(GLuint index) { if (mglshim_active && p_glDisableVertexAttribArray) { p_glDisableVertexAttribArray(index); return; } if (a_glDisableVertexAttribArray) a_glDisableVertexAttribArray(index); }
INTERPOSE(glDisableVertexAttribArray)
void glDisablei(GLenum target, GLuint index) WEAKGL;
static void (*p_glDisablei)(GLenum target, GLuint index);
static void (*a_glDisablei)(GLenum target, GLuint index);
static void w_glDisablei(GLenum target, GLuint index) { if (mglshim_active && p_glDisablei) { p_glDisablei(target, index); return; } if (a_glDisablei) a_glDisablei(target, index); }
INTERPOSE(glDisablei)
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) WEAKGL;
static void (*p_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
static void (*a_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
static void w_glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { if (mglshim_active && p_glDispatchCompute) { p_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); return; } if (a_glDispatchCompute) a_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
INTERPOSE(glDispatchCompute)
void glDispatchComputeIndirect(GLintptr indirect) WEAKGL;
static void (*p_glDispatchComputeIndirect)(GLintptr indirect);
static void (*a_glDispatchComputeIndirect)(GLintptr indirect);
static void w_glDispatchComputeIndirect(GLintptr indirect) { if (mglshim_active && p_glDispatchComputeIndirect) { p_glDispatchComputeIndirect(indirect); return; } if (a_glDispatchComputeIndirect) a_glDispatchComputeIndirect(indirect); }
INTERPOSE(glDispatchComputeIndirect)
void glDrawArrays(GLenum mode, GLint first, GLsizei count) WEAKGL;
static void (*p_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
static void (*a_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
static void w_glDrawArrays(GLenum mode, GLint first, GLsizei count) { if (mglshim_active && p_glDrawArrays) { p_glDrawArrays(mode, first, count); return; } if (a_glDrawArrays) a_glDrawArrays(mode, first, count); }
INTERPOSE(glDrawArrays)
void glDrawArraysIndirect(GLenum mode, const void *indirect) WEAKGL;
static void (*p_glDrawArraysIndirect)(GLenum mode, const void *indirect);
static void (*a_glDrawArraysIndirect)(GLenum mode, const void *indirect);
static void w_glDrawArraysIndirect(GLenum mode, const void *indirect) { if (mglshim_active && p_glDrawArraysIndirect) { p_glDrawArraysIndirect(mode, indirect); return; } if (a_glDrawArraysIndirect) a_glDrawArraysIndirect(mode, indirect); }
INTERPOSE(glDrawArraysIndirect)
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) WEAKGL;
static void (*p_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
static void (*a_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
static void w_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { if (mglshim_active && p_glDrawArraysInstanced) { p_glDrawArraysInstanced(mode, first, count, instancecount); return; } if (a_glDrawArraysInstanced) a_glDrawArraysInstanced(mode, first, count, instancecount); }
INTERPOSE(glDrawArraysInstanced)
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) WEAKGL;
static void (*p_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
static void (*a_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
static void w_glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) { if (mglshim_active && p_glDrawArraysInstancedBaseInstance) { p_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance); return; } if (a_glDrawArraysInstancedBaseInstance) a_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance); }
INTERPOSE(glDrawArraysInstancedBaseInstance)
void glDrawBuffer(GLenum buf) WEAKGL;
static void (*p_glDrawBuffer)(GLenum buf);
static void (*a_glDrawBuffer)(GLenum buf);
static void w_glDrawBuffer(GLenum buf) { if (mglshim_active && p_glDrawBuffer) { p_glDrawBuffer(buf); return; } if (a_glDrawBuffer) a_glDrawBuffer(buf); }
INTERPOSE(glDrawBuffer)
void glDrawBuffers(GLsizei n, const GLenum *bufs) WEAKGL;
static void (*p_glDrawBuffers)(GLsizei n, const GLenum *bufs);
static void (*a_glDrawBuffers)(GLsizei n, const GLenum *bufs);
static void w_glDrawBuffers(GLsizei n, const GLenum *bufs) { if (mglshim_active && p_glDrawBuffers) { p_glDrawBuffers(n, bufs); return; } if (a_glDrawBuffers) a_glDrawBuffers(n, bufs); }
INTERPOSE(glDrawBuffers)
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) WEAKGL;
static void (*p_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
static void (*a_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
static void w_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) { if (mglshim_active && p_glDrawElements) { p_glDrawElements(mode, count, type, indices); return; } if (a_glDrawElements) a_glDrawElements(mode, count, type, indices); }
INTERPOSE(glDrawElements)
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) WEAKGL;
static void (*p_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
static void (*a_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
static void w_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) { if (mglshim_active && p_glDrawElementsBaseVertex) { p_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); return; } if (a_glDrawElementsBaseVertex) a_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
INTERPOSE(glDrawElementsBaseVertex)
void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) WEAKGL;
static void (*p_glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
static void (*a_glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
static void w_glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) { if (mglshim_active && p_glDrawElementsIndirect) { p_glDrawElementsIndirect(mode, type, indirect); return; } if (a_glDrawElementsIndirect) a_glDrawElementsIndirect(mode, type, indirect); }
INTERPOSE(glDrawElementsIndirect)
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) WEAKGL;
static void (*p_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
static void (*a_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
static void w_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) { if (mglshim_active && p_glDrawElementsInstanced) { p_glDrawElementsInstanced(mode, count, type, indices, instancecount); return; } if (a_glDrawElementsInstanced) a_glDrawElementsInstanced(mode, count, type, indices, instancecount); }
INTERPOSE(glDrawElementsInstanced)
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) WEAKGL;
static void (*p_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
static void (*a_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
static void w_glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) { if (mglshim_active && p_glDrawElementsInstancedBaseInstance) { p_glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance); return; } if (a_glDrawElementsInstancedBaseInstance) a_glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance); }
INTERPOSE(glDrawElementsInstancedBaseInstance)
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) WEAKGL;
static void (*p_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
static void (*a_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
static void w_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) { if (mglshim_active && p_glDrawElementsInstancedBaseVertex) { p_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); return; } if (a_glDrawElementsInstancedBaseVertex) a_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
INTERPOSE(glDrawElementsInstancedBaseVertex)
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) WEAKGL;
static void (*p_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
static void (*a_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
static void w_glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) { if (mglshim_active && p_glDrawElementsInstancedBaseVertexBaseInstance) { p_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance); return; } if (a_glDrawElementsInstancedBaseVertexBaseInstance) a_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance); }
INTERPOSE(glDrawElementsInstancedBaseVertexBaseInstance)
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) WEAKGL;
static void (*p_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
static void (*a_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
static void w_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) { if (mglshim_active && p_glDrawRangeElements) { p_glDrawRangeElements(mode, start, end, count, type, indices); return; } if (a_glDrawRangeElements) a_glDrawRangeElements(mode, start, end, count, type, indices); }
INTERPOSE(glDrawRangeElements)
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) WEAKGL;
static void (*p_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
static void (*a_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
static void w_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) { if (mglshim_active && p_glDrawRangeElementsBaseVertex) { p_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); return; } if (a_glDrawRangeElementsBaseVertex) a_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
INTERPOSE(glDrawRangeElementsBaseVertex)
void glDrawTransformFeedback(GLenum mode, GLuint id) WEAKGL;
static void (*p_glDrawTransformFeedback)(GLenum mode, GLuint id);
static void (*a_glDrawTransformFeedback)(GLenum mode, GLuint id);
static void w_glDrawTransformFeedback(GLenum mode, GLuint id) { if (mglshim_active && p_glDrawTransformFeedback) { p_glDrawTransformFeedback(mode, id); return; } if (a_glDrawTransformFeedback) a_glDrawTransformFeedback(mode, id); }
INTERPOSE(glDrawTransformFeedback)
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) WEAKGL;
static void (*p_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
static void (*a_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
static void w_glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) { if (mglshim_active && p_glDrawTransformFeedbackInstanced) { p_glDrawTransformFeedbackInstanced(mode, id, instancecount); return; } if (a_glDrawTransformFeedbackInstanced) a_glDrawTransformFeedbackInstanced(mode, id, instancecount); }
INTERPOSE(glDrawTransformFeedbackInstanced)
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) WEAKGL;
static void (*p_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
static void (*a_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
static void w_glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { if (mglshim_active && p_glDrawTransformFeedbackStream) { p_glDrawTransformFeedbackStream(mode, id, stream); return; } if (a_glDrawTransformFeedbackStream) a_glDrawTransformFeedbackStream(mode, id, stream); }
INTERPOSE(glDrawTransformFeedbackStream)
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) WEAKGL;
static void (*p_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
static void (*a_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
static void w_glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) { if (mglshim_active && p_glDrawTransformFeedbackStreamInstanced) { p_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount); return; } if (a_glDrawTransformFeedbackStreamInstanced) a_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount); }
INTERPOSE(glDrawTransformFeedbackStreamInstanced)
void glEnable(GLenum cap) WEAKGL;
static void (*p_glEnable)(GLenum cap);
static void (*a_glEnable)(GLenum cap);
static void w_glEnable(GLenum cap) { if (mglshim_active && p_glEnable) { p_glEnable(cap); return; } if (a_glEnable) a_glEnable(cap); }
INTERPOSE(glEnable)
void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) WEAKGL;
static void (*p_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
static void (*a_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
static void w_glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) { if (mglshim_active && p_glEnableVertexArrayAttrib) { p_glEnableVertexArrayAttrib(vaobj, index); return; } if (a_glEnableVertexArrayAttrib) a_glEnableVertexArrayAttrib(vaobj, index); }
INTERPOSE(glEnableVertexArrayAttrib)
void glEnableVertexAttribArray(GLuint index) WEAKGL;
static void (*p_glEnableVertexAttribArray)(GLuint index);
static void (*a_glEnableVertexAttribArray)(GLuint index);
static void w_glEnableVertexAttribArray(GLuint index) { if (mglshim_active && p_glEnableVertexAttribArray) { p_glEnableVertexAttribArray(index); return; } if (a_glEnableVertexAttribArray) a_glEnableVertexAttribArray(index); }
INTERPOSE(glEnableVertexAttribArray)
void glEnablei(GLenum target, GLuint index) WEAKGL;
static void (*p_glEnablei)(GLenum target, GLuint index);
static void (*a_glEnablei)(GLenum target, GLuint index);
static void w_glEnablei(GLenum target, GLuint index) { if (mglshim_active && p_glEnablei) { p_glEnablei(target, index); return; } if (a_glEnablei) a_glEnablei(target, index); }
INTERPOSE(glEnablei)
void glEndConditionalRender(void) WEAKGL;
static void (*p_glEndConditionalRender)(void);
static void (*a_glEndConditionalRender)(void);
static void w_glEndConditionalRender(void) { if (mglshim_active && p_glEndConditionalRender) { p_glEndConditionalRender(); return; } if (a_glEndConditionalRender) a_glEndConditionalRender(); }
INTERPOSE(glEndConditionalRender)
void glEndQuery(GLenum target) WEAKGL;
static void (*p_glEndQuery)(GLenum target);
static void (*a_glEndQuery)(GLenum target);
static void w_glEndQuery(GLenum target) { if (mglshim_active && p_glEndQuery) { p_glEndQuery(target); return; } if (a_glEndQuery) a_glEndQuery(target); }
INTERPOSE(glEndQuery)
void glEndQueryIndexed(GLenum target, GLuint index) WEAKGL;
static void (*p_glEndQueryIndexed)(GLenum target, GLuint index);
static void (*a_glEndQueryIndexed)(GLenum target, GLuint index);
static void w_glEndQueryIndexed(GLenum target, GLuint index) { if (mglshim_active && p_glEndQueryIndexed) { p_glEndQueryIndexed(target, index); return; } if (a_glEndQueryIndexed) a_glEndQueryIndexed(target, index); }
INTERPOSE(glEndQueryIndexed)
void glEndTransformFeedback(void) WEAKGL;
static void (*p_glEndTransformFeedback)(void);
static void (*a_glEndTransformFeedback)(void);
static void w_glEndTransformFeedback(void) { if (mglshim_active && p_glEndTransformFeedback) { p_glEndTransformFeedback(); return; } if (a_glEndTransformFeedback) a_glEndTransformFeedback(); }
INTERPOSE(glEndTransformFeedback)
GLsync glFenceSync(GLenum condition, GLbitfield flags) WEAKGL;
static GLsync (*p_glFenceSync)(GLenum condition, GLbitfield flags);
static GLsync (*a_glFenceSync)(GLenum condition, GLbitfield flags);
static GLsync w_glFenceSync(GLenum condition, GLbitfield flags) { if (mglshim_active && p_glFenceSync) return p_glFenceSync(condition, flags); if (a_glFenceSync) return a_glFenceSync(condition, flags); return (GLsync)0; }
INTERPOSE(glFenceSync)
void glFinish(void) WEAKGL;
static void (*p_glFinish)(void);
static void (*a_glFinish)(void);
static void w_glFinish(void) { if (mglshim_active && p_glFinish) { p_glFinish(); return; } if (a_glFinish) a_glFinish(); }
INTERPOSE(glFinish)
void glFlush(void) WEAKGL;
static void (*p_glFlush)(void);
static void (*a_glFlush)(void);
static void w_glFlush(void) { if (mglshim_active && p_glFlush) { p_glFlush(); return; } if (a_glFlush) a_glFlush(); }
INTERPOSE(glFlush)
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) WEAKGL;
static void (*p_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
static void (*a_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
static void w_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { if (mglshim_active && p_glFlushMappedBufferRange) { p_glFlushMappedBufferRange(target, offset, length); return; } if (a_glFlushMappedBufferRange) a_glFlushMappedBufferRange(target, offset, length); }
INTERPOSE(glFlushMappedBufferRange)
void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) WEAKGL;
static void (*p_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
static void (*a_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
static void w_glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) { if (mglshim_active && p_glFlushMappedNamedBufferRange) { p_glFlushMappedNamedBufferRange(buffer, offset, length); return; } if (a_glFlushMappedNamedBufferRange) a_glFlushMappedNamedBufferRange(buffer, offset, length); }
INTERPOSE(glFlushMappedNamedBufferRange)
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) WEAKGL;
static void (*p_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
static void (*a_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
static void w_glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { if (mglshim_active && p_glFramebufferParameteri) { p_glFramebufferParameteri(target, pname, param); return; } if (a_glFramebufferParameteri) a_glFramebufferParameteri(target, pname, param); }
INTERPOSE(glFramebufferParameteri)
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) WEAKGL;
static void (*p_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void (*a_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void w_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { if (mglshim_active && p_glFramebufferRenderbuffer) { p_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); return; } if (a_glFramebufferRenderbuffer) a_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
INTERPOSE(glFramebufferRenderbuffer)
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) WEAKGL;
static void (*p_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
static void (*a_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
static void w_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { if (mglshim_active && p_glFramebufferTexture) { p_glFramebufferTexture(target, attachment, texture, level); return; } if (a_glFramebufferTexture) a_glFramebufferTexture(target, attachment, texture, level); }
INTERPOSE(glFramebufferTexture)
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) WEAKGL;
static void (*p_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void (*a_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void w_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { if (mglshim_active && p_glFramebufferTexture1D) { p_glFramebufferTexture1D(target, attachment, textarget, texture, level); return; } if (a_glFramebufferTexture1D) a_glFramebufferTexture1D(target, attachment, textarget, texture, level); }
INTERPOSE(glFramebufferTexture1D)
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) WEAKGL;
static void (*p_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void (*a_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void w_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { if (mglshim_active && p_glFramebufferTexture2D) { p_glFramebufferTexture2D(target, attachment, textarget, texture, level); return; } if (a_glFramebufferTexture2D) a_glFramebufferTexture2D(target, attachment, textarget, texture, level); }
INTERPOSE(glFramebufferTexture2D)
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) WEAKGL;
static void (*p_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
static void (*a_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
static void w_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) { if (mglshim_active && p_glFramebufferTexture3D) { p_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); return; } if (a_glFramebufferTexture3D) a_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
INTERPOSE(glFramebufferTexture3D)
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) WEAKGL;
static void (*p_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void (*a_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void w_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { if (mglshim_active && p_glFramebufferTextureLayer) { p_glFramebufferTextureLayer(target, attachment, texture, level, layer); return; } if (a_glFramebufferTextureLayer) a_glFramebufferTextureLayer(target, attachment, texture, level, layer); }
INTERPOSE(glFramebufferTextureLayer)
void glFrontFace(GLenum mode) WEAKGL;
static void (*p_glFrontFace)(GLenum mode);
static void (*a_glFrontFace)(GLenum mode);
static void w_glFrontFace(GLenum mode) { if (mglshim_active && p_glFrontFace) { p_glFrontFace(mode); return; } if (a_glFrontFace) a_glFrontFace(mode); }
INTERPOSE(glFrontFace)
void glGenBuffers(GLsizei n, GLuint *buffers) WEAKGL;
static void (*p_glGenBuffers)(GLsizei n, GLuint *buffers);
static void (*a_glGenBuffers)(GLsizei n, GLuint *buffers);
static void w_glGenBuffers(GLsizei n, GLuint *buffers) { if (mglshim_active && p_glGenBuffers) { p_glGenBuffers(n, buffers); return; } if (a_glGenBuffers) a_glGenBuffers(n, buffers); }
INTERPOSE(glGenBuffers)
void glGenFramebuffers(GLsizei n, GLuint *framebuffers) WEAKGL;
static void (*p_glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
static void (*a_glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
static void w_glGenFramebuffers(GLsizei n, GLuint *framebuffers) { if (mglshim_active && p_glGenFramebuffers) { p_glGenFramebuffers(n, framebuffers); return; } if (a_glGenFramebuffers) a_glGenFramebuffers(n, framebuffers); }
INTERPOSE(glGenFramebuffers)
void glGenProgramPipelines(GLsizei n, GLuint *pipelines) WEAKGL;
static void (*p_glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
static void (*a_glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
static void w_glGenProgramPipelines(GLsizei n, GLuint *pipelines) { if (mglshim_active && p_glGenProgramPipelines) { p_glGenProgramPipelines(n, pipelines); return; } if (a_glGenProgramPipelines) a_glGenProgramPipelines(n, pipelines); }
INTERPOSE(glGenProgramPipelines)
void glGenQueries(GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glGenQueries)(GLsizei n, GLuint *ids);
static void (*a_glGenQueries)(GLsizei n, GLuint *ids);
static void w_glGenQueries(GLsizei n, GLuint *ids) { if (mglshim_active && p_glGenQueries) { p_glGenQueries(n, ids); return; } if (a_glGenQueries) a_glGenQueries(n, ids); }
INTERPOSE(glGenQueries)
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) WEAKGL;
static void (*p_glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
static void (*a_glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
static void w_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) { if (mglshim_active && p_glGenRenderbuffers) { p_glGenRenderbuffers(n, renderbuffers); return; } if (a_glGenRenderbuffers) a_glGenRenderbuffers(n, renderbuffers); }
INTERPOSE(glGenRenderbuffers)
void glGenSamplers(GLsizei count, GLuint *samplers) WEAKGL;
static void (*p_glGenSamplers)(GLsizei count, GLuint *samplers);
static void (*a_glGenSamplers)(GLsizei count, GLuint *samplers);
static void w_glGenSamplers(GLsizei count, GLuint *samplers) { if (mglshim_active && p_glGenSamplers) { p_glGenSamplers(count, samplers); return; } if (a_glGenSamplers) a_glGenSamplers(count, samplers); }
INTERPOSE(glGenSamplers)
void glGenTextures(GLsizei n, GLuint *textures) WEAKGL;
static void (*p_glGenTextures)(GLsizei n, GLuint *textures);
static void (*a_glGenTextures)(GLsizei n, GLuint *textures);
static void w_glGenTextures(GLsizei n, GLuint *textures) { if (mglshim_active && p_glGenTextures) { p_glGenTextures(n, textures); return; } if (a_glGenTextures) a_glGenTextures(n, textures); }
INTERPOSE(glGenTextures)
void glGenTransformFeedbacks(GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
static void (*a_glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
static void w_glGenTransformFeedbacks(GLsizei n, GLuint *ids) { if (mglshim_active && p_glGenTransformFeedbacks) { p_glGenTransformFeedbacks(n, ids); return; } if (a_glGenTransformFeedbacks) a_glGenTransformFeedbacks(n, ids); }
INTERPOSE(glGenTransformFeedbacks)
void glGenVertexArrays(GLsizei n, GLuint *arrays) WEAKGL;
static void (*p_glGenVertexArrays)(GLsizei n, GLuint *arrays);
static void (*a_glGenVertexArrays)(GLsizei n, GLuint *arrays);
static void w_glGenVertexArrays(GLsizei n, GLuint *arrays) { if (mglshim_active && p_glGenVertexArrays) { p_glGenVertexArrays(n, arrays); return; } if (a_glGenVertexArrays) a_glGenVertexArrays(n, arrays); }
INTERPOSE(glGenVertexArrays)
void glGenerateMipmap(GLenum target) WEAKGL;
static void (*p_glGenerateMipmap)(GLenum target);
static void (*a_glGenerateMipmap)(GLenum target);
static void w_glGenerateMipmap(GLenum target) { if (mglshim_active && p_glGenerateMipmap) { p_glGenerateMipmap(target); return; } if (a_glGenerateMipmap) a_glGenerateMipmap(target); }
INTERPOSE(glGenerateMipmap)
void glGenerateTextureMipmap(GLuint texture) WEAKGL;
static void (*p_glGenerateTextureMipmap)(GLuint texture);
static void (*a_glGenerateTextureMipmap)(GLuint texture);
static void w_glGenerateTextureMipmap(GLuint texture) { if (mglshim_active && p_glGenerateTextureMipmap) { p_glGenerateTextureMipmap(texture); return; } if (a_glGenerateTextureMipmap) a_glGenerateTextureMipmap(texture); }
INTERPOSE(glGenerateTextureMipmap)
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
static void (*a_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
static void w_glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) { if (mglshim_active && p_glGetActiveAtomicCounterBufferiv) { p_glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params); return; } if (a_glGetActiveAtomicCounterBufferiv) a_glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params); }
INTERPOSE(glGetActiveAtomicCounterBufferiv)
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) WEAKGL;
static void (*p_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
static void (*a_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
static void w_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { if (mglshim_active && p_glGetActiveAttrib) { p_glGetActiveAttrib(program, index, bufSize, length, size, type, name); return; } if (a_glGetActiveAttrib) a_glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
INTERPOSE(glGetActiveAttrib)
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) WEAKGL;
static void (*p_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void (*a_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void w_glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { if (mglshim_active && p_glGetActiveSubroutineName) { p_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name); return; } if (a_glGetActiveSubroutineName) a_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name); }
INTERPOSE(glGetActiveSubroutineName)
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) WEAKGL;
static void (*p_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void (*a_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void w_glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { if (mglshim_active && p_glGetActiveSubroutineUniformName) { p_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name); return; } if (a_glGetActiveSubroutineUniformName) a_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name); }
INTERPOSE(glGetActiveSubroutineUniformName)
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) WEAKGL;
static void (*p_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
static void (*a_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
static void w_glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) { if (mglshim_active && p_glGetActiveSubroutineUniformiv) { p_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); return; } if (a_glGetActiveSubroutineUniformiv) a_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); }
INTERPOSE(glGetActiveSubroutineUniformiv)
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) WEAKGL;
static void (*p_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
static void (*a_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
static void w_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { if (mglshim_active && p_glGetActiveUniform) { p_glGetActiveUniform(program, index, bufSize, length, size, type, name); return; } if (a_glGetActiveUniform) a_glGetActiveUniform(program, index, bufSize, length, size, type, name); }
INTERPOSE(glGetActiveUniform)
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) WEAKGL;
static void (*p_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
static void (*a_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
static void w_glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) { if (mglshim_active && p_glGetActiveUniformBlockName) { p_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); return; } if (a_glGetActiveUniformBlockName) a_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
INTERPOSE(glGetActiveUniformBlockName)
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
static void (*a_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
static void w_glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) { if (mglshim_active && p_glGetActiveUniformBlockiv) { p_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); return; } if (a_glGetActiveUniformBlockiv) a_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
INTERPOSE(glGetActiveUniformBlockiv)
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) WEAKGL;
static void (*p_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
static void (*a_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
static void w_glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) { if (mglshim_active && p_glGetActiveUniformName) { p_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); return; } if (a_glGetActiveUniformName) a_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
INTERPOSE(glGetActiveUniformName)
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
static void (*a_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
static void w_glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) { if (mglshim_active && p_glGetActiveUniformsiv) { p_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); return; } if (a_glGetActiveUniformsiv) a_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
INTERPOSE(glGetActiveUniformsiv)
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) WEAKGL;
static void (*p_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
static void (*a_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
static void w_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { if (mglshim_active && p_glGetAttachedShaders) { p_glGetAttachedShaders(program, maxCount, count, shaders); return; } if (a_glGetAttachedShaders) a_glGetAttachedShaders(program, maxCount, count, shaders); }
INTERPOSE(glGetAttachedShaders)
GLint glGetAttribLocation(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetAttribLocation)(GLuint program, const GLchar *name);
static GLint (*a_glGetAttribLocation)(GLuint program, const GLchar *name);
static GLint w_glGetAttribLocation(GLuint program, const GLchar *name) { if (mglshim_active && p_glGetAttribLocation) return p_glGetAttribLocation(program, name); if (a_glGetAttribLocation) return a_glGetAttribLocation(program, name); return (GLint)0; }
INTERPOSE(glGetAttribLocation)
void glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) WEAKGL;
static void (*p_glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
static void (*a_glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
static void w_glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) { if (mglshim_active && p_glGetBooleani_v) { p_glGetBooleani_v(target, index, data); return; } if (a_glGetBooleani_v) a_glGetBooleani_v(target, index, data); }
INTERPOSE(glGetBooleani_v)
void glGetBooleanv(GLenum pname, GLboolean *data) WEAKGL;
static void (*p_glGetBooleanv)(GLenum pname, GLboolean *data);
static void (*a_glGetBooleanv)(GLenum pname, GLboolean *data);
static void w_glGetBooleanv(GLenum pname, GLboolean *data) { if (mglshim_active && p_glGetBooleanv) { p_glGetBooleanv(pname, data); return; } if (a_glGetBooleanv) a_glGetBooleanv(pname, data); }
INTERPOSE(glGetBooleanv)
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) WEAKGL;
static void (*p_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
static void (*a_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
static void w_glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) { if (mglshim_active && p_glGetBufferParameteri64v) { p_glGetBufferParameteri64v(target, pname, params); return; } if (a_glGetBufferParameteri64v) a_glGetBufferParameteri64v(target, pname, params); }
INTERPOSE(glGetBufferParameteri64v)
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetBufferParameteriv) { p_glGetBufferParameteriv(target, pname, params); return; } if (a_glGetBufferParameteriv) a_glGetBufferParameteriv(target, pname, params); }
INTERPOSE(glGetBufferParameteriv)
void glGetBufferPointerv(GLenum target, GLenum pname, void **params) WEAKGL;
static void (*p_glGetBufferPointerv)(GLenum target, GLenum pname, void **params);
static void (*a_glGetBufferPointerv)(GLenum target, GLenum pname, void **params);
static void w_glGetBufferPointerv(GLenum target, GLenum pname, void **params) { if (mglshim_active && p_glGetBufferPointerv) { p_glGetBufferPointerv(target, pname, params); return; } if (a_glGetBufferPointerv) a_glGetBufferPointerv(target, pname, params); }
INTERPOSE(glGetBufferPointerv)
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data) WEAKGL;
static void (*p_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
static void (*a_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
static void w_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data) { if (mglshim_active && p_glGetBufferSubData) { p_glGetBufferSubData(target, offset, size, data); return; } if (a_glGetBufferSubData) a_glGetBufferSubData(target, offset, size, data); }
INTERPOSE(glGetBufferSubData)
void glGetCompressedTexImage(GLenum target, GLint level, void *img) WEAKGL;
static void (*p_glGetCompressedTexImage)(GLenum target, GLint level, void *img);
static void (*a_glGetCompressedTexImage)(GLenum target, GLint level, void *img);
static void w_glGetCompressedTexImage(GLenum target, GLint level, void *img) { if (mglshim_active && p_glGetCompressedTexImage) { p_glGetCompressedTexImage(target, level, img); return; } if (a_glGetCompressedTexImage) a_glGetCompressedTexImage(target, level, img); }
INTERPOSE(glGetCompressedTexImage)
void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
static void (*a_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
static void w_glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetCompressedTextureImage) { p_glGetCompressedTextureImage(texture, level, bufSize, pixels); return; } if (a_glGetCompressedTextureImage) a_glGetCompressedTextureImage(texture, level, bufSize, pixels); }
INTERPOSE(glGetCompressedTextureImage)
void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
static void (*a_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
static void w_glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetCompressedTextureSubImage) { p_glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels); return; } if (a_glGetCompressedTextureSubImage) a_glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels); }
INTERPOSE(glGetCompressedTextureSubImage)
GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) WEAKGL;
static GLuint (*p_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
static GLuint (*a_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
static GLuint w_glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) { if (mglshim_active && p_glGetDebugMessageLog) return p_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog); if (a_glGetDebugMessageLog) return a_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog); return (GLuint)0; }
INTERPOSE(glGetDebugMessageLog)
void glGetDoublei_v(GLenum target, GLuint index, GLdouble *data) WEAKGL;
static void (*p_glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);
static void (*a_glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);
static void w_glGetDoublei_v(GLenum target, GLuint index, GLdouble *data) { if (mglshim_active && p_glGetDoublei_v) { p_glGetDoublei_v(target, index, data); return; } if (a_glGetDoublei_v) a_glGetDoublei_v(target, index, data); }
INTERPOSE(glGetDoublei_v)
void glGetDoublev(GLenum pname, GLdouble *data) WEAKGL;
static void (*p_glGetDoublev)(GLenum pname, GLdouble *data);
static void (*a_glGetDoublev)(GLenum pname, GLdouble *data);
static void w_glGetDoublev(GLenum pname, GLdouble *data) { if (mglshim_active && p_glGetDoublev) { p_glGetDoublev(pname, data); return; } if (a_glGetDoublev) a_glGetDoublev(pname, data); }
INTERPOSE(glGetDoublev)
GLenum glGetError(void) WEAKGL;
static GLenum (*p_glGetError)(void);
static GLenum (*a_glGetError)(void);
static GLenum w_glGetError(void) { if (mglshim_active && p_glGetError) return p_glGetError(); if (a_glGetError) return a_glGetError(); return (GLenum)0; }
INTERPOSE(glGetError)
void glGetFloati_v(GLenum target, GLuint index, GLfloat *data) WEAKGL;
static void (*p_glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
static void (*a_glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
static void w_glGetFloati_v(GLenum target, GLuint index, GLfloat *data) { if (mglshim_active && p_glGetFloati_v) { p_glGetFloati_v(target, index, data); return; } if (a_glGetFloati_v) a_glGetFloati_v(target, index, data); }
INTERPOSE(glGetFloati_v)
void glGetFloatv(GLenum pname, GLfloat *data) WEAKGL;
static void (*p_glGetFloatv)(GLenum pname, GLfloat *data);
static void (*a_glGetFloatv)(GLenum pname, GLfloat *data);
static void w_glGetFloatv(GLenum pname, GLfloat *data) { if (mglshim_active && p_glGetFloatv) { p_glGetFloatv(pname, data); return; } if (a_glGetFloatv) a_glGetFloatv(pname, data); }
INTERPOSE(glGetFloatv)
GLint glGetFragDataIndex(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetFragDataIndex)(GLuint program, const GLchar *name);
static GLint (*a_glGetFragDataIndex)(GLuint program, const GLchar *name);
static GLint w_glGetFragDataIndex(GLuint program, const GLchar *name) { if (mglshim_active && p_glGetFragDataIndex) return p_glGetFragDataIndex(program, name); if (a_glGetFragDataIndex) return a_glGetFragDataIndex(program, name); return (GLint)0; }
INTERPOSE(glGetFragDataIndex)
GLint glGetFragDataLocation(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetFragDataLocation)(GLuint program, const GLchar *name);
static GLint (*a_glGetFragDataLocation)(GLuint program, const GLchar *name);
static GLint w_glGetFragDataLocation(GLuint program, const GLchar *name) { if (mglshim_active && p_glGetFragDataLocation) return p_glGetFragDataLocation(program, name); if (a_glGetFragDataLocation) return a_glGetFragDataLocation(program, name); return (GLint)0; }
INTERPOSE(glGetFragDataLocation)
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
static void (*a_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
static void w_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { if (mglshim_active && p_glGetFramebufferAttachmentParameteriv) { p_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); return; } if (a_glGetFramebufferAttachmentParameteriv) a_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
INTERPOSE(glGetFramebufferAttachmentParameteriv)
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetFramebufferParameteriv) { p_glGetFramebufferParameteriv(target, pname, params); return; } if (a_glGetFramebufferParameteriv) a_glGetFramebufferParameteriv(target, pname, params); }
INTERPOSE(glGetFramebufferParameteriv)
GLenum glGetGraphicsResetStatus(void) WEAKGL;
static GLenum (*p_glGetGraphicsResetStatus)(void);
static GLenum (*a_glGetGraphicsResetStatus)(void);
static GLenum w_glGetGraphicsResetStatus(void) { if (mglshim_active && p_glGetGraphicsResetStatus) return p_glGetGraphicsResetStatus(); if (a_glGetGraphicsResetStatus) return a_glGetGraphicsResetStatus(); return (GLenum)0; }
INTERPOSE(glGetGraphicsResetStatus)
void glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) WEAKGL;
static void (*p_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
static void (*a_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
static void w_glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) { if (mglshim_active && p_glGetInteger64i_v) { p_glGetInteger64i_v(target, index, data); return; } if (a_glGetInteger64i_v) a_glGetInteger64i_v(target, index, data); }
INTERPOSE(glGetInteger64i_v)
void glGetInteger64v(GLenum pname, GLint64 *data) WEAKGL;
static void (*p_glGetInteger64v)(GLenum pname, GLint64 *data);
static void (*a_glGetInteger64v)(GLenum pname, GLint64 *data);
static void w_glGetInteger64v(GLenum pname, GLint64 *data) { if (mglshim_active && p_glGetInteger64v) { p_glGetInteger64v(pname, data); return; } if (a_glGetInteger64v) a_glGetInteger64v(pname, data); }
INTERPOSE(glGetInteger64v)
void glGetIntegeri_v(GLenum target, GLuint index, GLint *data) WEAKGL;
static void (*p_glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
static void (*a_glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
static void w_glGetIntegeri_v(GLenum target, GLuint index, GLint *data) { if (mglshim_active && p_glGetIntegeri_v) { p_glGetIntegeri_v(target, index, data); return; } if (a_glGetIntegeri_v) a_glGetIntegeri_v(target, index, data); }
INTERPOSE(glGetIntegeri_v)
void glGetIntegerv(GLenum pname, GLint *data) WEAKGL;
static void (*p_glGetIntegerv)(GLenum pname, GLint *data);
static void (*a_glGetIntegerv)(GLenum pname, GLint *data);
static void w_glGetIntegerv(GLenum pname, GLint *data) { if (mglshim_active && p_glGetIntegerv) { p_glGetIntegerv(pname, data); return; } if (a_glGetIntegerv) a_glGetIntegerv(pname, data); }
INTERPOSE(glGetIntegerv)
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params) WEAKGL;
static void (*p_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
static void (*a_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
static void w_glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params) { if (mglshim_active && p_glGetInternalformati64v) { p_glGetInternalformati64v(target, internalformat, pname, count, params); return; } if (a_glGetInternalformati64v) a_glGetInternalformati64v(target, internalformat, pname, count, params); }
INTERPOSE(glGetInternalformati64v)
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params) WEAKGL;
static void (*p_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
static void (*a_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
static void w_glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params) { if (mglshim_active && p_glGetInternalformativ) { p_glGetInternalformativ(target, internalformat, pname, count, params); return; } if (a_glGetInternalformativ) a_glGetInternalformativ(target, internalformat, pname, count, params); }
INTERPOSE(glGetInternalformativ)
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) WEAKGL;
static void (*p_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
static void (*a_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
static void w_glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { if (mglshim_active && p_glGetMultisamplefv) { p_glGetMultisamplefv(pname, index, val); return; } if (a_glGetMultisamplefv) a_glGetMultisamplefv(pname, index, val); }
INTERPOSE(glGetMultisamplefv)
void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params) WEAKGL;
static void (*p_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
static void (*a_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
static void w_glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params) { if (mglshim_active && p_glGetNamedBufferParameteri64v) { p_glGetNamedBufferParameteri64v(buffer, pname, params); return; } if (a_glGetNamedBufferParameteri64v) a_glGetNamedBufferParameteri64v(buffer, pname, params); }
INTERPOSE(glGetNamedBufferParameteri64v)
void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
static void (*a_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
static void w_glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params) { if (mglshim_active && p_glGetNamedBufferParameteriv) { p_glGetNamedBufferParameteriv(buffer, pname, params); return; } if (a_glGetNamedBufferParameteriv) a_glGetNamedBufferParameteriv(buffer, pname, params); }
INTERPOSE(glGetNamedBufferParameteriv)
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void **params) WEAKGL;
static void (*p_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
static void (*a_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
static void w_glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void **params) { if (mglshim_active && p_glGetNamedBufferPointerv) { p_glGetNamedBufferPointerv(buffer, pname, params); return; } if (a_glGetNamedBufferPointerv) a_glGetNamedBufferPointerv(buffer, pname, params); }
INTERPOSE(glGetNamedBufferPointerv)
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) WEAKGL;
static void (*p_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
static void (*a_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
static void w_glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) { if (mglshim_active && p_glGetNamedBufferSubData) { p_glGetNamedBufferSubData(buffer, offset, size, data); return; } if (a_glGetNamedBufferSubData) a_glGetNamedBufferSubData(buffer, offset, size, data); }
INTERPOSE(glGetNamedBufferSubData)
void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
static void (*a_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
static void w_glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) { if (mglshim_active && p_glGetNamedFramebufferAttachmentParameteriv) { p_glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params); return; } if (a_glGetNamedFramebufferAttachmentParameteriv) a_glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params); }
INTERPOSE(glGetNamedFramebufferAttachmentParameteriv)
void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
static void (*a_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
static void w_glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param) { if (mglshim_active && p_glGetNamedFramebufferParameteriv) { p_glGetNamedFramebufferParameteriv(framebuffer, pname, param); return; } if (a_glGetNamedFramebufferParameteriv) a_glGetNamedFramebufferParameteriv(framebuffer, pname, param); }
INTERPOSE(glGetNamedFramebufferParameteriv)
void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
static void (*a_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
static void w_glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params) { if (mglshim_active && p_glGetNamedRenderbufferParameteriv) { p_glGetNamedRenderbufferParameteriv(renderbuffer, pname, params); return; } if (a_glGetNamedRenderbufferParameteriv) a_glGetNamedRenderbufferParameteriv(renderbuffer, pname, params); }
INTERPOSE(glGetNamedRenderbufferParameteriv)
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) WEAKGL;
static void (*p_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
static void (*a_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
static void w_glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) { if (mglshim_active && p_glGetObjectLabel) { p_glGetObjectLabel(identifier, name, bufSize, length, label); return; } if (a_glGetObjectLabel) a_glGetObjectLabel(identifier, name, bufSize, length, label); }
INTERPOSE(glGetObjectLabel)
void glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) WEAKGL;
static void (*p_glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
static void (*a_glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
static void w_glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) { if (mglshim_active && p_glGetObjectPtrLabel) { p_glGetObjectPtrLabel(ptr, bufSize, length, label); return; } if (a_glGetObjectPtrLabel) a_glGetObjectPtrLabel(ptr, bufSize, length, label); }
INTERPOSE(glGetObjectPtrLabel)
void glGetPointerv(GLenum pname, void **params) WEAKGL;
static void (*p_glGetPointerv)(GLenum pname, void **params);
static void (*a_glGetPointerv)(GLenum pname, void **params);
static void w_glGetPointerv(GLenum pname, void **params) { if (mglshim_active && p_glGetPointerv) { p_glGetPointerv(pname, params); return; } if (a_glGetPointerv) a_glGetPointerv(pname, params); }
INTERPOSE(glGetPointerv)
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) WEAKGL;
static void (*p_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
static void (*a_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
static void w_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) { if (mglshim_active && p_glGetProgramBinary) { p_glGetProgramBinary(program, bufSize, length, binaryFormat, binary); return; } if (a_glGetProgramBinary) a_glGetProgramBinary(program, bufSize, length, binaryFormat, binary); }
INTERPOSE(glGetProgramBinary)
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) WEAKGL;
static void (*p_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void (*a_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void w_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { if (mglshim_active && p_glGetProgramInfoLog) { p_glGetProgramInfoLog(program, bufSize, length, infoLog); return; } if (a_glGetProgramInfoLog) a_glGetProgramInfoLog(program, bufSize, length, infoLog); }
INTERPOSE(glGetProgramInfoLog)
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
static void (*a_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
static void w_glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) { if (mglshim_active && p_glGetProgramInterfaceiv) { p_glGetProgramInterfaceiv(program, programInterface, pname, params); return; } if (a_glGetProgramInterfaceiv) a_glGetProgramInterfaceiv(program, programInterface, pname, params); }
INTERPOSE(glGetProgramInterfaceiv)
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) WEAKGL;
static void (*p_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void (*a_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void w_glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { if (mglshim_active && p_glGetProgramPipelineInfoLog) { p_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); return; } if (a_glGetProgramPipelineInfoLog) a_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); }
INTERPOSE(glGetProgramPipelineInfoLog)
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
static void (*a_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
static void w_glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { if (mglshim_active && p_glGetProgramPipelineiv) { p_glGetProgramPipelineiv(pipeline, pname, params); return; } if (a_glGetProgramPipelineiv) a_glGetProgramPipelineiv(pipeline, pname, params); }
INTERPOSE(glGetProgramPipelineiv)
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) WEAKGL;
static GLuint (*p_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
static GLuint (*a_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
static GLuint w_glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) { if (mglshim_active && p_glGetProgramResourceIndex) return p_glGetProgramResourceIndex(program, programInterface, name); if (a_glGetProgramResourceIndex) return a_glGetProgramResourceIndex(program, programInterface, name); return (GLuint)0; }
INTERPOSE(glGetProgramResourceIndex)
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) WEAKGL;
static GLint (*p_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
static GLint (*a_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
static GLint w_glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) { if (mglshim_active && p_glGetProgramResourceLocation) return p_glGetProgramResourceLocation(program, programInterface, name); if (a_glGetProgramResourceLocation) return a_glGetProgramResourceLocation(program, programInterface, name); return (GLint)0; }
INTERPOSE(glGetProgramResourceLocation)
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name) WEAKGL;
static GLint (*p_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
static GLint (*a_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
static GLint w_glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name) { if (mglshim_active && p_glGetProgramResourceLocationIndex) return p_glGetProgramResourceLocationIndex(program, programInterface, name); if (a_glGetProgramResourceLocationIndex) return a_glGetProgramResourceLocationIndex(program, programInterface, name); return (GLint)0; }
INTERPOSE(glGetProgramResourceLocationIndex)
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) WEAKGL;
static void (*p_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void (*a_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void w_glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { if (mglshim_active && p_glGetProgramResourceName) { p_glGetProgramResourceName(program, programInterface, index, bufSize, length, name); return; } if (a_glGetProgramResourceName) a_glGetProgramResourceName(program, programInterface, index, bufSize, length, name); }
INTERPOSE(glGetProgramResourceName)
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params) WEAKGL;
static void (*p_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
static void (*a_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
static void w_glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params) { if (mglshim_active && p_glGetProgramResourceiv) { p_glGetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params); return; } if (a_glGetProgramResourceiv) a_glGetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params); }
INTERPOSE(glGetProgramResourceiv)
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) WEAKGL;
static void (*p_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
static void (*a_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
static void w_glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) { if (mglshim_active && p_glGetProgramStageiv) { p_glGetProgramStageiv(program, shadertype, pname, values); return; } if (a_glGetProgramStageiv) a_glGetProgramStageiv(program, shadertype, pname, values); }
INTERPOSE(glGetProgramStageiv)
void glGetProgramiv(GLuint program, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
static void (*a_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
static void w_glGetProgramiv(GLuint program, GLenum pname, GLint *params) { if (mglshim_active && p_glGetProgramiv) { p_glGetProgramiv(program, pname, params); return; } if (a_glGetProgramiv) a_glGetProgramiv(program, pname, params); }
INTERPOSE(glGetProgramiv)
void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void (*a_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (mglshim_active && p_glGetQueryBufferObjecti64v) { p_glGetQueryBufferObjecti64v(id, buffer, pname, offset); return; } if (a_glGetQueryBufferObjecti64v) a_glGetQueryBufferObjecti64v(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjecti64v)
void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void (*a_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (mglshim_active && p_glGetQueryBufferObjectiv) { p_glGetQueryBufferObjectiv(id, buffer, pname, offset); return; } if (a_glGetQueryBufferObjectiv) a_glGetQueryBufferObjectiv(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjectiv)
void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void (*a_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (mglshim_active && p_glGetQueryBufferObjectui64v) { p_glGetQueryBufferObjectui64v(id, buffer, pname, offset); return; } if (a_glGetQueryBufferObjectui64v) a_glGetQueryBufferObjectui64v(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjectui64v)
void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void (*a_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (mglshim_active && p_glGetQueryBufferObjectuiv) { p_glGetQueryBufferObjectuiv(id, buffer, pname, offset); return; } if (a_glGetQueryBufferObjectuiv) a_glGetQueryBufferObjectuiv(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjectuiv)
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);
static void (*a_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);
static void w_glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params) { if (mglshim_active && p_glGetQueryIndexediv) { p_glGetQueryIndexediv(target, index, pname, params); return; } if (a_glGetQueryIndexediv) a_glGetQueryIndexediv(target, index, pname, params); }
INTERPOSE(glGetQueryIndexediv)
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) WEAKGL;
static void (*p_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
static void (*a_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
static void w_glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) { if (mglshim_active && p_glGetQueryObjecti64v) { p_glGetQueryObjecti64v(id, pname, params); return; } if (a_glGetQueryObjecti64v) a_glGetQueryObjecti64v(id, pname, params); }
INTERPOSE(glGetQueryObjecti64v)
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
static void (*a_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
static void w_glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) { if (mglshim_active && p_glGetQueryObjectiv) { p_glGetQueryObjectiv(id, pname, params); return; } if (a_glGetQueryObjectiv) a_glGetQueryObjectiv(id, pname, params); }
INTERPOSE(glGetQueryObjectiv)
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) WEAKGL;
static void (*p_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
static void (*a_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
static void w_glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) { if (mglshim_active && p_glGetQueryObjectui64v) { p_glGetQueryObjectui64v(id, pname, params); return; } if (a_glGetQueryObjectui64v) a_glGetQueryObjectui64v(id, pname, params); }
INTERPOSE(glGetQueryObjectui64v)
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
static void (*a_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
static void w_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) { if (mglshim_active && p_glGetQueryObjectuiv) { p_glGetQueryObjectuiv(id, pname, params); return; } if (a_glGetQueryObjectuiv) a_glGetQueryObjectuiv(id, pname, params); }
INTERPOSE(glGetQueryObjectuiv)
void glGetQueryiv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetQueryiv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetQueryiv) { p_glGetQueryiv(target, pname, params); return; } if (a_glGetQueryiv) a_glGetQueryiv(target, pname, params); }
INTERPOSE(glGetQueryiv)
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetRenderbufferParameteriv) { p_glGetRenderbufferParameteriv(target, pname, params); return; } if (a_glGetRenderbufferParameteriv) a_glGetRenderbufferParameteriv(target, pname, params); }
INTERPOSE(glGetRenderbufferParameteriv)
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
static void (*a_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
static void w_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) { if (mglshim_active && p_glGetSamplerParameterIiv) { p_glGetSamplerParameterIiv(sampler, pname, params); return; } if (a_glGetSamplerParameterIiv) a_glGetSamplerParameterIiv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameterIiv)
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
static void (*a_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
static void w_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) { if (mglshim_active && p_glGetSamplerParameterIuiv) { p_glGetSamplerParameterIuiv(sampler, pname, params); return; } if (a_glGetSamplerParameterIuiv) a_glGetSamplerParameterIuiv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameterIuiv)
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
static void (*a_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
static void w_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetSamplerParameterfv) { p_glGetSamplerParameterfv(sampler, pname, params); return; } if (a_glGetSamplerParameterfv) a_glGetSamplerParameterfv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameterfv)
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
static void (*a_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
static void w_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) { if (mglshim_active && p_glGetSamplerParameteriv) { p_glGetSamplerParameteriv(sampler, pname, params); return; } if (a_glGetSamplerParameteriv) a_glGetSamplerParameteriv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameteriv)
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) WEAKGL;
static void (*p_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void (*a_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void w_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { if (mglshim_active && p_glGetShaderInfoLog) { p_glGetShaderInfoLog(shader, bufSize, length, infoLog); return; } if (a_glGetShaderInfoLog) a_glGetShaderInfoLog(shader, bufSize, length, infoLog); }
INTERPOSE(glGetShaderInfoLog)
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) WEAKGL;
static void (*p_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
static void (*a_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
static void w_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { if (mglshim_active && p_glGetShaderPrecisionFormat) { p_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); return; } if (a_glGetShaderPrecisionFormat) a_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
INTERPOSE(glGetShaderPrecisionFormat)
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) WEAKGL;
static void (*p_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
static void (*a_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
static void w_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { if (mglshim_active && p_glGetShaderSource) { p_glGetShaderSource(shader, bufSize, length, source); return; } if (a_glGetShaderSource) a_glGetShaderSource(shader, bufSize, length, source); }
INTERPOSE(glGetShaderSource)
void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
static void (*a_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
static void w_glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { if (mglshim_active && p_glGetShaderiv) { p_glGetShaderiv(shader, pname, params); return; } if (a_glGetShaderiv) a_glGetShaderiv(shader, pname, params); }
INTERPOSE(glGetShaderiv)
const GLubyte * glGetString(GLenum name) WEAKGL;
static const GLubyte * (*p_glGetString)(GLenum name);
static const GLubyte * (*a_glGetString)(GLenum name);
static const GLubyte * w_glGetString(GLenum name) { if (mglshim_active && p_glGetString) return p_glGetString(name); if (a_glGetString) return a_glGetString(name); return (const GLubyte *)0; }
INTERPOSE(glGetString)
const GLubyte * glGetStringi(GLenum name, GLuint index) WEAKGL;
static const GLubyte * (*p_glGetStringi)(GLenum name, GLuint index);
static const GLubyte * (*a_glGetStringi)(GLenum name, GLuint index);
static const GLubyte * w_glGetStringi(GLenum name, GLuint index) { if (mglshim_active && p_glGetStringi) return p_glGetStringi(name, index); if (a_glGetStringi) return a_glGetStringi(name, index); return (const GLubyte *)0; }
INTERPOSE(glGetStringi)
GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) WEAKGL;
static GLuint (*p_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
static GLuint (*a_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
static GLuint w_glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) { if (mglshim_active && p_glGetSubroutineIndex) return p_glGetSubroutineIndex(program, shadertype, name); if (a_glGetSubroutineIndex) return a_glGetSubroutineIndex(program, shadertype, name); return (GLuint)0; }
INTERPOSE(glGetSubroutineIndex)
GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name) WEAKGL;
static GLint (*p_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
static GLint (*a_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
static GLint w_glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name) { if (mglshim_active && p_glGetSubroutineUniformLocation) return p_glGetSubroutineUniformLocation(program, shadertype, name); if (a_glGetSubroutineUniformLocation) return a_glGetSubroutineUniformLocation(program, shadertype, name); return (GLint)0; }
INTERPOSE(glGetSubroutineUniformLocation)
void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) WEAKGL;
static void (*p_glGetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
static void (*a_glGetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
static void w_glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) { if (mglshim_active && p_glGetSynciv) { p_glGetSynciv(sync, pname, count, length, values); return; } if (a_glGetSynciv) a_glGetSynciv(sync, pname, count, length, values); }
INTERPOSE(glGetSynciv)
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) WEAKGL;
static void (*p_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
static void (*a_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
static void w_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) { if (mglshim_active && p_glGetTexImage) { p_glGetTexImage(target, level, format, type, pixels); return; } if (a_glGetTexImage) a_glGetTexImage(target, level, format, type, pixels); }
INTERPOSE(glGetTexImage)
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
static void (*a_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
static void w_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetTexLevelParameterfv) { p_glGetTexLevelParameterfv(target, level, pname, params); return; } if (a_glGetTexLevelParameterfv) a_glGetTexLevelParameterfv(target, level, pname, params); }
INTERPOSE(glGetTexLevelParameterfv)
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
static void (*a_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
static void w_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTexLevelParameteriv) { p_glGetTexLevelParameteriv(target, level, pname, params); return; } if (a_glGetTexLevelParameteriv) a_glGetTexLevelParameteriv(target, level, pname, params); }
INTERPOSE(glGetTexLevelParameteriv)
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTexParameterIiv) { p_glGetTexParameterIiv(target, pname, params); return; } if (a_glGetTexParameterIiv) a_glGetTexParameterIiv(target, pname, params); }
INTERPOSE(glGetTexParameterIiv)
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
static void (*a_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
static void w_glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) { if (mglshim_active && p_glGetTexParameterIuiv) { p_glGetTexParameterIuiv(target, pname, params); return; } if (a_glGetTexParameterIuiv) a_glGetTexParameterIuiv(target, pname, params); }
INTERPOSE(glGetTexParameterIuiv)
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
static void (*a_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
static void w_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetTexParameterfv) { p_glGetTexParameterfv(target, pname, params); return; } if (a_glGetTexParameterfv) a_glGetTexParameterfv(target, pname, params); }
INTERPOSE(glGetTexParameterfv)
void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTexParameteriv) { p_glGetTexParameteriv(target, pname, params); return; } if (a_glGetTexParameteriv) a_glGetTexParameteriv(target, pname, params); }
INTERPOSE(glGetTexParameteriv)
void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void (*a_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void w_glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetTextureImage) { p_glGetTextureImage(texture, level, format, type, bufSize, pixels); return; } if (a_glGetTextureImage) a_glGetTextureImage(texture, level, format, type, bufSize, pixels); }
INTERPOSE(glGetTextureImage)
void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
static void (*a_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
static void w_glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetTextureLevelParameterfv) { p_glGetTextureLevelParameterfv(texture, level, pname, params); return; } if (a_glGetTextureLevelParameterfv) a_glGetTextureLevelParameterfv(texture, level, pname, params); }
INTERPOSE(glGetTextureLevelParameterfv)
void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
static void (*a_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
static void w_glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTextureLevelParameteriv) { p_glGetTextureLevelParameteriv(texture, level, pname, params); return; } if (a_glGetTextureLevelParameteriv) a_glGetTextureLevelParameteriv(texture, level, pname, params); }
INTERPOSE(glGetTextureLevelParameteriv)
void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
static void (*a_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
static void w_glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTextureParameterIiv) { p_glGetTextureParameterIiv(texture, pname, params); return; } if (a_glGetTextureParameterIiv) a_glGetTextureParameterIiv(texture, pname, params); }
INTERPOSE(glGetTextureParameterIiv)
void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
static void (*a_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
static void w_glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params) { if (mglshim_active && p_glGetTextureParameterIuiv) { p_glGetTextureParameterIuiv(texture, pname, params); return; } if (a_glGetTextureParameterIuiv) a_glGetTextureParameterIuiv(texture, pname, params); }
INTERPOSE(glGetTextureParameterIuiv)
void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
static void (*a_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
static void w_glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetTextureParameterfv) { p_glGetTextureParameterfv(texture, pname, params); return; } if (a_glGetTextureParameterfv) a_glGetTextureParameterfv(texture, pname, params); }
INTERPOSE(glGetTextureParameterfv)
void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
static void (*a_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
static void w_glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTextureParameteriv) { p_glGetTextureParameteriv(texture, pname, params); return; } if (a_glGetTextureParameteriv) a_glGetTextureParameteriv(texture, pname, params); }
INTERPOSE(glGetTextureParameteriv)
void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void (*a_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void w_glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetTextureSubImage) { p_glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels); return; } if (a_glGetTextureSubImage) a_glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels); }
INTERPOSE(glGetTextureSubImage)
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) WEAKGL;
static void (*p_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
static void (*a_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
static void w_glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) { if (mglshim_active && p_glGetTransformFeedbackVarying) { p_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); return; } if (a_glGetTransformFeedbackVarying) a_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
INTERPOSE(glGetTransformFeedbackVarying)
void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) WEAKGL;
static void (*p_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
static void (*a_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
static void w_glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) { if (mglshim_active && p_glGetTransformFeedbacki64_v) { p_glGetTransformFeedbacki64_v(xfb, pname, index, param); return; } if (a_glGetTransformFeedbacki64_v) a_glGetTransformFeedbacki64_v(xfb, pname, index, param); }
INTERPOSE(glGetTransformFeedbacki64_v)
void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param) WEAKGL;
static void (*p_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
static void (*a_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
static void w_glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param) { if (mglshim_active && p_glGetTransformFeedbacki_v) { p_glGetTransformFeedbacki_v(xfb, pname, index, param); return; } if (a_glGetTransformFeedbacki_v) a_glGetTransformFeedbacki_v(xfb, pname, index, param); }
INTERPOSE(glGetTransformFeedbacki_v)
void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
static void (*a_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
static void w_glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param) { if (mglshim_active && p_glGetTransformFeedbackiv) { p_glGetTransformFeedbackiv(xfb, pname, param); return; } if (a_glGetTransformFeedbackiv) a_glGetTransformFeedbackiv(xfb, pname, param); }
INTERPOSE(glGetTransformFeedbackiv)
GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) WEAKGL;
static GLuint (*p_glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
static GLuint (*a_glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
static GLuint w_glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { if (mglshim_active && p_glGetUniformBlockIndex) return p_glGetUniformBlockIndex(program, uniformBlockName); if (a_glGetUniformBlockIndex) return a_glGetUniformBlockIndex(program, uniformBlockName); return (GLuint)0; }
INTERPOSE(glGetUniformBlockIndex)
void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) WEAKGL;
static void (*p_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
static void (*a_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
static void w_glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) { if (mglshim_active && p_glGetUniformIndices) { p_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); return; } if (a_glGetUniformIndices) a_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
INTERPOSE(glGetUniformIndices)
GLint glGetUniformLocation(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetUniformLocation)(GLuint program, const GLchar *name);
static GLint (*a_glGetUniformLocation)(GLuint program, const GLchar *name);
static GLint w_glGetUniformLocation(GLuint program, const GLchar *name) { if (mglshim_active && p_glGetUniformLocation) return p_glGetUniformLocation(program, name); if (a_glGetUniformLocation) return a_glGetUniformLocation(program, name); return (GLint)0; }
INTERPOSE(glGetUniformLocation)
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params) WEAKGL;
static void (*p_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
static void (*a_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
static void w_glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params) { if (mglshim_active && p_glGetUniformSubroutineuiv) { p_glGetUniformSubroutineuiv(shadertype, location, params); return; } if (a_glGetUniformSubroutineuiv) a_glGetUniformSubroutineuiv(shadertype, location, params); }
INTERPOSE(glGetUniformSubroutineuiv)
void glGetUniformdv(GLuint program, GLint location, GLdouble *params) WEAKGL;
static void (*p_glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
static void (*a_glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
static void w_glGetUniformdv(GLuint program, GLint location, GLdouble *params) { if (mglshim_active && p_glGetUniformdv) { p_glGetUniformdv(program, location, params); return; } if (a_glGetUniformdv) a_glGetUniformdv(program, location, params); }
INTERPOSE(glGetUniformdv)
void glGetUniformfv(GLuint program, GLint location, GLfloat *params) WEAKGL;
static void (*p_glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
static void (*a_glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
static void w_glGetUniformfv(GLuint program, GLint location, GLfloat *params) { if (mglshim_active && p_glGetUniformfv) { p_glGetUniformfv(program, location, params); return; } if (a_glGetUniformfv) a_glGetUniformfv(program, location, params); }
INTERPOSE(glGetUniformfv)
void glGetUniformiv(GLuint program, GLint location, GLint *params) WEAKGL;
static void (*p_glGetUniformiv)(GLuint program, GLint location, GLint *params);
static void (*a_glGetUniformiv)(GLuint program, GLint location, GLint *params);
static void w_glGetUniformiv(GLuint program, GLint location, GLint *params) { if (mglshim_active && p_glGetUniformiv) { p_glGetUniformiv(program, location, params); return; } if (a_glGetUniformiv) a_glGetUniformiv(program, location, params); }
INTERPOSE(glGetUniformiv)
void glGetUniformuiv(GLuint program, GLint location, GLuint *params) WEAKGL;
static void (*p_glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
static void (*a_glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
static void w_glGetUniformuiv(GLuint program, GLint location, GLuint *params) { if (mglshim_active && p_glGetUniformuiv) { p_glGetUniformuiv(program, location, params); return; } if (a_glGetUniformuiv) a_glGetUniformuiv(program, location, params); }
INTERPOSE(glGetUniformuiv)
void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) WEAKGL;
static void (*p_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
static void (*a_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
static void w_glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) { if (mglshim_active && p_glGetVertexArrayIndexed64iv) { p_glGetVertexArrayIndexed64iv(vaobj, index, pname, param); return; } if (a_glGetVertexArrayIndexed64iv) a_glGetVertexArrayIndexed64iv(vaobj, index, pname, param); }
INTERPOSE(glGetVertexArrayIndexed64iv)
void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
static void (*a_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
static void w_glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param) { if (mglshim_active && p_glGetVertexArrayIndexediv) { p_glGetVertexArrayIndexediv(vaobj, index, pname, param); return; } if (a_glGetVertexArrayIndexediv) a_glGetVertexArrayIndexediv(vaobj, index, pname, param); }
INTERPOSE(glGetVertexArrayIndexediv)
void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
static void (*a_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
static void w_glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) { if (mglshim_active && p_glGetVertexArrayiv) { p_glGetVertexArrayiv(vaobj, pname, param); return; } if (a_glGetVertexArrayiv) a_glGetVertexArrayiv(vaobj, pname, param); }
INTERPOSE(glGetVertexArrayiv)
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
static void (*a_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
static void w_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { if (mglshim_active && p_glGetVertexAttribIiv) { p_glGetVertexAttribIiv(index, pname, params); return; } if (a_glGetVertexAttribIiv) a_glGetVertexAttribIiv(index, pname, params); }
INTERPOSE(glGetVertexAttribIiv)
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
static void (*a_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
static void w_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { if (mglshim_active && p_glGetVertexAttribIuiv) { p_glGetVertexAttribIuiv(index, pname, params); return; } if (a_glGetVertexAttribIuiv) a_glGetVertexAttribIuiv(index, pname, params); }
INTERPOSE(glGetVertexAttribIuiv)
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) WEAKGL;
static void (*p_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
static void (*a_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
static void w_glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) { if (mglshim_active && p_glGetVertexAttribLdv) { p_glGetVertexAttribLdv(index, pname, params); return; } if (a_glGetVertexAttribLdv) a_glGetVertexAttribLdv(index, pname, params); }
INTERPOSE(glGetVertexAttribLdv)
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) WEAKGL;
static void (*p_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
static void (*a_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
static void w_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) { if (mglshim_active && p_glGetVertexAttribPointerv) { p_glGetVertexAttribPointerv(index, pname, pointer); return; } if (a_glGetVertexAttribPointerv) a_glGetVertexAttribPointerv(index, pname, pointer); }
INTERPOSE(glGetVertexAttribPointerv)
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) WEAKGL;
static void (*p_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
static void (*a_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
static void w_glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { if (mglshim_active && p_glGetVertexAttribdv) { p_glGetVertexAttribdv(index, pname, params); return; } if (a_glGetVertexAttribdv) a_glGetVertexAttribdv(index, pname, params); }
INTERPOSE(glGetVertexAttribdv)
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
static void (*a_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
static void w_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetVertexAttribfv) { p_glGetVertexAttribfv(index, pname, params); return; } if (a_glGetVertexAttribfv) a_glGetVertexAttribfv(index, pname, params); }
INTERPOSE(glGetVertexAttribfv)
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
static void (*a_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
static void w_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { if (mglshim_active && p_glGetVertexAttribiv) { p_glGetVertexAttribiv(index, pname, params); return; } if (a_glGetVertexAttribiv) a_glGetVertexAttribiv(index, pname, params); }
INTERPOSE(glGetVertexAttribiv)
void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
static void (*a_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
static void w_glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetnCompressedTexImage) { p_glGetnCompressedTexImage(target, lod, bufSize, pixels); return; } if (a_glGetnCompressedTexImage) a_glGetnCompressedTexImage(target, lod, bufSize, pixels); }
INTERPOSE(glGetnCompressedTexImage)
void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void (*a_glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void w_glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetnTexImage) { p_glGetnTexImage(target, level, format, type, bufSize, pixels); return; } if (a_glGetnTexImage) a_glGetnTexImage(target, level, format, type, bufSize, pixels); }
INTERPOSE(glGetnTexImage)
void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params) WEAKGL;
static void (*p_glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
static void (*a_glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
static void w_glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params) { if (mglshim_active && p_glGetnUniformdv) { p_glGetnUniformdv(program, location, bufSize, params); return; } if (a_glGetnUniformdv) a_glGetnUniformdv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformdv)
void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) WEAKGL;
static void (*p_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
static void (*a_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
static void w_glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) { if (mglshim_active && p_glGetnUniformfv) { p_glGetnUniformfv(program, location, bufSize, params); return; } if (a_glGetnUniformfv) a_glGetnUniformfv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformfv)
void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) WEAKGL;
static void (*p_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
static void (*a_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
static void w_glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) { if (mglshim_active && p_glGetnUniformiv) { p_glGetnUniformiv(program, location, bufSize, params); return; } if (a_glGetnUniformiv) a_glGetnUniformiv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformiv)
void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) WEAKGL;
static void (*p_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
static void (*a_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
static void w_glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) { if (mglshim_active && p_glGetnUniformuiv) { p_glGetnUniformuiv(program, location, bufSize, params); return; } if (a_glGetnUniformuiv) a_glGetnUniformuiv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformuiv)
void glHint(GLenum target, GLenum mode) WEAKGL;
static void (*p_glHint)(GLenum target, GLenum mode);
static void (*a_glHint)(GLenum target, GLenum mode);
static void w_glHint(GLenum target, GLenum mode) { if (mglshim_active && p_glHint) { p_glHint(target, mode); return; } if (a_glHint) a_glHint(target, mode); }
INTERPOSE(glHint)
void glInvalidateBufferData(GLuint buffer) WEAKGL;
static void (*p_glInvalidateBufferData)(GLuint buffer);
static void (*a_glInvalidateBufferData)(GLuint buffer);
static void w_glInvalidateBufferData(GLuint buffer) { if (mglshim_active && p_glInvalidateBufferData) { p_glInvalidateBufferData(buffer); return; } if (a_glInvalidateBufferData) a_glInvalidateBufferData(buffer); }
INTERPOSE(glInvalidateBufferData)
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) WEAKGL;
static void (*p_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
static void (*a_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
static void w_glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) { if (mglshim_active && p_glInvalidateBufferSubData) { p_glInvalidateBufferSubData(buffer, offset, length); return; } if (a_glInvalidateBufferSubData) a_glInvalidateBufferSubData(buffer, offset, length); }
INTERPOSE(glInvalidateBufferSubData)
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) WEAKGL;
static void (*p_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
static void (*a_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
static void w_glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) { if (mglshim_active && p_glInvalidateFramebuffer) { p_glInvalidateFramebuffer(target, numAttachments, attachments); return; } if (a_glInvalidateFramebuffer) a_glInvalidateFramebuffer(target, numAttachments, attachments); }
INTERPOSE(glInvalidateFramebuffer)
void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) WEAKGL;
static void (*p_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
static void (*a_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
static void w_glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) { if (mglshim_active && p_glInvalidateNamedFramebufferData) { p_glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments); return; } if (a_glInvalidateNamedFramebufferData) a_glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments); }
INTERPOSE(glInvalidateNamedFramebufferData)
void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glInvalidateNamedFramebufferSubData) { p_glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height); return; } if (a_glInvalidateNamedFramebufferSubData) a_glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height); }
INTERPOSE(glInvalidateNamedFramebufferSubData)
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glInvalidateSubFramebuffer) { p_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); return; } if (a_glInvalidateSubFramebuffer) a_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); }
INTERPOSE(glInvalidateSubFramebuffer)
void glInvalidateTexImage(GLuint texture, GLint level) WEAKGL;
static void (*p_glInvalidateTexImage)(GLuint texture, GLint level);
static void (*a_glInvalidateTexImage)(GLuint texture, GLint level);
static void w_glInvalidateTexImage(GLuint texture, GLint level) { if (mglshim_active && p_glInvalidateTexImage) { p_glInvalidateTexImage(texture, level); return; } if (a_glInvalidateTexImage) a_glInvalidateTexImage(texture, level); }
INTERPOSE(glInvalidateTexImage)
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) WEAKGL;
static void (*p_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
static void (*a_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
static void w_glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) { if (mglshim_active && p_glInvalidateTexSubImage) { p_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth); return; } if (a_glInvalidateTexSubImage) a_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth); }
INTERPOSE(glInvalidateTexSubImage)
GLboolean glIsBuffer(GLuint buffer) WEAKGL;
static GLboolean (*p_glIsBuffer)(GLuint buffer);
static GLboolean (*a_glIsBuffer)(GLuint buffer);
static GLboolean w_glIsBuffer(GLuint buffer) { if (mglshim_active && p_glIsBuffer) return p_glIsBuffer(buffer); if (a_glIsBuffer) return a_glIsBuffer(buffer); return (GLboolean)0; }
INTERPOSE(glIsBuffer)
GLboolean glIsEnabled(GLenum cap) WEAKGL;
static GLboolean (*p_glIsEnabled)(GLenum cap);
static GLboolean (*a_glIsEnabled)(GLenum cap);
static GLboolean w_glIsEnabled(GLenum cap) { if (mglshim_active && p_glIsEnabled) return p_glIsEnabled(cap); if (a_glIsEnabled) return a_glIsEnabled(cap); return (GLboolean)0; }
INTERPOSE(glIsEnabled)
GLboolean glIsEnabledi(GLenum target, GLuint index) WEAKGL;
static GLboolean (*p_glIsEnabledi)(GLenum target, GLuint index);
static GLboolean (*a_glIsEnabledi)(GLenum target, GLuint index);
static GLboolean w_glIsEnabledi(GLenum target, GLuint index) { if (mglshim_active && p_glIsEnabledi) return p_glIsEnabledi(target, index); if (a_glIsEnabledi) return a_glIsEnabledi(target, index); return (GLboolean)0; }
INTERPOSE(glIsEnabledi)
GLboolean glIsFramebuffer(GLuint framebuffer) WEAKGL;
static GLboolean (*p_glIsFramebuffer)(GLuint framebuffer);
static GLboolean (*a_glIsFramebuffer)(GLuint framebuffer);
static GLboolean w_glIsFramebuffer(GLuint framebuffer) { if (mglshim_active && p_glIsFramebuffer) return p_glIsFramebuffer(framebuffer); if (a_glIsFramebuffer) return a_glIsFramebuffer(framebuffer); return (GLboolean)0; }
INTERPOSE(glIsFramebuffer)
GLboolean glIsProgram(GLuint program) WEAKGL;
static GLboolean (*p_glIsProgram)(GLuint program);
static GLboolean (*a_glIsProgram)(GLuint program);
static GLboolean w_glIsProgram(GLuint program) { if (mglshim_active && p_glIsProgram) return p_glIsProgram(program); if (a_glIsProgram) return a_glIsProgram(program); return (GLboolean)0; }
INTERPOSE(glIsProgram)
GLboolean glIsProgramPipeline(GLuint pipeline) WEAKGL;
static GLboolean (*p_glIsProgramPipeline)(GLuint pipeline);
static GLboolean (*a_glIsProgramPipeline)(GLuint pipeline);
static GLboolean w_glIsProgramPipeline(GLuint pipeline) { if (mglshim_active && p_glIsProgramPipeline) return p_glIsProgramPipeline(pipeline); if (a_glIsProgramPipeline) return a_glIsProgramPipeline(pipeline); return (GLboolean)0; }
INTERPOSE(glIsProgramPipeline)
GLboolean glIsQuery(GLuint id) WEAKGL;
static GLboolean (*p_glIsQuery)(GLuint id);
static GLboolean (*a_glIsQuery)(GLuint id);
static GLboolean w_glIsQuery(GLuint id) { if (mglshim_active && p_glIsQuery) return p_glIsQuery(id); if (a_glIsQuery) return a_glIsQuery(id); return (GLboolean)0; }
INTERPOSE(glIsQuery)
GLboolean glIsRenderbuffer(GLuint renderbuffer) WEAKGL;
static GLboolean (*p_glIsRenderbuffer)(GLuint renderbuffer);
static GLboolean (*a_glIsRenderbuffer)(GLuint renderbuffer);
static GLboolean w_glIsRenderbuffer(GLuint renderbuffer) { if (mglshim_active && p_glIsRenderbuffer) return p_glIsRenderbuffer(renderbuffer); if (a_glIsRenderbuffer) return a_glIsRenderbuffer(renderbuffer); return (GLboolean)0; }
INTERPOSE(glIsRenderbuffer)
GLboolean glIsSampler(GLuint sampler) WEAKGL;
static GLboolean (*p_glIsSampler)(GLuint sampler);
static GLboolean (*a_glIsSampler)(GLuint sampler);
static GLboolean w_glIsSampler(GLuint sampler) { if (mglshim_active && p_glIsSampler) return p_glIsSampler(sampler); if (a_glIsSampler) return a_glIsSampler(sampler); return (GLboolean)0; }
INTERPOSE(glIsSampler)
GLboolean glIsShader(GLuint shader) WEAKGL;
static GLboolean (*p_glIsShader)(GLuint shader);
static GLboolean (*a_glIsShader)(GLuint shader);
static GLboolean w_glIsShader(GLuint shader) { if (mglshim_active && p_glIsShader) return p_glIsShader(shader); if (a_glIsShader) return a_glIsShader(shader); return (GLboolean)0; }
INTERPOSE(glIsShader)
GLboolean glIsSync(GLsync sync) WEAKGL;
static GLboolean (*p_glIsSync)(GLsync sync);
static GLboolean (*a_glIsSync)(GLsync sync);
static GLboolean w_glIsSync(GLsync sync) { if (mglshim_active && p_glIsSync) return p_glIsSync(sync); if (a_glIsSync) return a_glIsSync(sync); return (GLboolean)0; }
INTERPOSE(glIsSync)
GLboolean glIsTexture(GLuint texture) WEAKGL;
static GLboolean (*p_glIsTexture)(GLuint texture);
static GLboolean (*a_glIsTexture)(GLuint texture);
static GLboolean w_glIsTexture(GLuint texture) { if (mglshim_active && p_glIsTexture) return p_glIsTexture(texture); if (a_glIsTexture) return a_glIsTexture(texture); return (GLboolean)0; }
INTERPOSE(glIsTexture)
GLboolean glIsTransformFeedback(GLuint id) WEAKGL;
static GLboolean (*p_glIsTransformFeedback)(GLuint id);
static GLboolean (*a_glIsTransformFeedback)(GLuint id);
static GLboolean w_glIsTransformFeedback(GLuint id) { if (mglshim_active && p_glIsTransformFeedback) return p_glIsTransformFeedback(id); if (a_glIsTransformFeedback) return a_glIsTransformFeedback(id); return (GLboolean)0; }
INTERPOSE(glIsTransformFeedback)
GLboolean glIsVertexArray(GLuint array) WEAKGL;
static GLboolean (*p_glIsVertexArray)(GLuint array);
static GLboolean (*a_glIsVertexArray)(GLuint array);
static GLboolean w_glIsVertexArray(GLuint array) { if (mglshim_active && p_glIsVertexArray) return p_glIsVertexArray(array); if (a_glIsVertexArray) return a_glIsVertexArray(array); return (GLboolean)0; }
INTERPOSE(glIsVertexArray)
void glLineWidth(GLfloat width) WEAKGL;
static void (*p_glLineWidth)(GLfloat width);
static void (*a_glLineWidth)(GLfloat width);
static void w_glLineWidth(GLfloat width) { if (mglshim_active && p_glLineWidth) { p_glLineWidth(width); return; } if (a_glLineWidth) a_glLineWidth(width); }
INTERPOSE(glLineWidth)
void glLinkProgram(GLuint program) WEAKGL;
static void (*p_glLinkProgram)(GLuint program);
static void (*a_glLinkProgram)(GLuint program);
static void w_glLinkProgram(GLuint program) { if (mglshim_active && p_glLinkProgram) { p_glLinkProgram(program); return; } if (a_glLinkProgram) a_glLinkProgram(program); }
INTERPOSE(glLinkProgram)
void glLogicOp(GLenum opcode) WEAKGL;
static void (*p_glLogicOp)(GLenum opcode);
static void (*a_glLogicOp)(GLenum opcode);
static void w_glLogicOp(GLenum opcode) { if (mglshim_active && p_glLogicOp) { p_glLogicOp(opcode); return; } if (a_glLogicOp) a_glLogicOp(opcode); }
INTERPOSE(glLogicOp)
void * glMapBuffer(GLenum target, GLenum access) WEAKGL;
static void * (*p_glMapBuffer)(GLenum target, GLenum access);
static void * (*a_glMapBuffer)(GLenum target, GLenum access);
static void * w_glMapBuffer(GLenum target, GLenum access) { if (mglshim_active && p_glMapBuffer) return p_glMapBuffer(target, access); if (a_glMapBuffer) return a_glMapBuffer(target, access); return (void *)0; }
INTERPOSE(glMapBuffer)
void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) WEAKGL;
static void * (*p_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
static void * (*a_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
static void * w_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { if (mglshim_active && p_glMapBufferRange) return p_glMapBufferRange(target, offset, length, access); if (a_glMapBufferRange) return a_glMapBufferRange(target, offset, length, access); return (void *)0; }
INTERPOSE(glMapBufferRange)
void * glMapNamedBuffer(GLuint buffer, GLenum access) WEAKGL;
static void * (*p_glMapNamedBuffer)(GLuint buffer, GLenum access);
static void * (*a_glMapNamedBuffer)(GLuint buffer, GLenum access);
static void * w_glMapNamedBuffer(GLuint buffer, GLenum access) { if (mglshim_active && p_glMapNamedBuffer) return p_glMapNamedBuffer(buffer, access); if (a_glMapNamedBuffer) return a_glMapNamedBuffer(buffer, access); return (void *)0; }
INTERPOSE(glMapNamedBuffer)
void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) WEAKGL;
static void * (*p_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
static void * (*a_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
static void * w_glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) { if (mglshim_active && p_glMapNamedBufferRange) return p_glMapNamedBufferRange(buffer, offset, length, access); if (a_glMapNamedBufferRange) return a_glMapNamedBufferRange(buffer, offset, length, access); return (void *)0; }
INTERPOSE(glMapNamedBufferRange)
void glMemoryBarrier(GLbitfield barriers) WEAKGL;
static void (*p_glMemoryBarrier)(GLbitfield barriers);
static void (*a_glMemoryBarrier)(GLbitfield barriers);
static void w_glMemoryBarrier(GLbitfield barriers) { if (mglshim_active && p_glMemoryBarrier) { p_glMemoryBarrier(barriers); return; } if (a_glMemoryBarrier) a_glMemoryBarrier(barriers); }
INTERPOSE(glMemoryBarrier)
void glMemoryBarrierByRegion(GLbitfield barriers) WEAKGL;
static void (*p_glMemoryBarrierByRegion)(GLbitfield barriers);
static void (*a_glMemoryBarrierByRegion)(GLbitfield barriers);
static void w_glMemoryBarrierByRegion(GLbitfield barriers) { if (mglshim_active && p_glMemoryBarrierByRegion) { p_glMemoryBarrierByRegion(barriers); return; } if (a_glMemoryBarrierByRegion) a_glMemoryBarrierByRegion(barriers); }
INTERPOSE(glMemoryBarrierByRegion)
void glMinSampleShading(GLfloat value) WEAKGL;
static void (*p_glMinSampleShading)(GLfloat value);
static void (*a_glMinSampleShading)(GLfloat value);
static void w_glMinSampleShading(GLfloat value) { if (mglshim_active && p_glMinSampleShading) { p_glMinSampleShading(value); return; } if (a_glMinSampleShading) a_glMinSampleShading(value); }
INTERPOSE(glMinSampleShading)
void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) WEAKGL;
static void (*p_glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
static void (*a_glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
static void w_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) { if (mglshim_active && p_glMultiDrawArrays) { p_glMultiDrawArrays(mode, first, count, drawcount); return; } if (a_glMultiDrawArrays) a_glMultiDrawArrays(mode, first, count, drawcount); }
INTERPOSE(glMultiDrawArrays)
void glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
static void (*a_glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
static void w_glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) { if (mglshim_active && p_glMultiDrawArraysIndirect) { p_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride); return; } if (a_glMultiDrawArraysIndirect) a_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride); }
INTERPOSE(glMultiDrawArraysIndirect)
void glMultiDrawArraysIndirectCount(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawArraysIndirectCount)(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
static void (*a_glMultiDrawArraysIndirectCount)(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
static void w_glMultiDrawArraysIndirectCount(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) { if (mglshim_active && p_glMultiDrawArraysIndirectCount) { p_glMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride); return; } if (a_glMultiDrawArraysIndirectCount) a_glMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride); }
INTERPOSE(glMultiDrawArraysIndirectCount)
void glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) WEAKGL;
static void (*p_glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
static void (*a_glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
static void w_glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) { if (mglshim_active && p_glMultiDrawElements) { p_glMultiDrawElements(mode, count, type, indices, drawcount); return; } if (a_glMultiDrawElements) a_glMultiDrawElements(mode, count, type, indices, drawcount); }
INTERPOSE(glMultiDrawElements)
void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) WEAKGL;
static void (*p_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
static void (*a_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
static void w_glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) { if (mglshim_active && p_glMultiDrawElementsBaseVertex) { p_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); return; } if (a_glMultiDrawElementsBaseVertex) a_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
INTERPOSE(glMultiDrawElementsBaseVertex)
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
static void (*a_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
static void w_glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) { if (mglshim_active && p_glMultiDrawElementsIndirect) { p_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride); return; } if (a_glMultiDrawElementsIndirect) a_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride); }
INTERPOSE(glMultiDrawElementsIndirect)
void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawElementsIndirectCount)(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
static void (*a_glMultiDrawElementsIndirectCount)(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
static void w_glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) { if (mglshim_active && p_glMultiDrawElementsIndirectCount) { p_glMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride); return; } if (a_glMultiDrawElementsIndirectCount) a_glMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride); }
INTERPOSE(glMultiDrawElementsIndirectCount)
void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) WEAKGL;
static void (*p_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
static void (*a_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
static void w_glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) { if (mglshim_active && p_glNamedBufferData) { p_glNamedBufferData(buffer, size, data, usage); return; } if (a_glNamedBufferData) a_glNamedBufferData(buffer, size, data, usage); }
INTERPOSE(glNamedBufferData)
void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) WEAKGL;
static void (*p_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
static void (*a_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
static void w_glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) { if (mglshim_active && p_glNamedBufferStorage) { p_glNamedBufferStorage(buffer, size, data, flags); return; } if (a_glNamedBufferStorage) a_glNamedBufferStorage(buffer, size, data, flags); }
INTERPOSE(glNamedBufferStorage)
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) WEAKGL;
static void (*p_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
static void (*a_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
static void w_glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) { if (mglshim_active && p_glNamedBufferSubData) { p_glNamedBufferSubData(buffer, offset, size, data); return; } if (a_glNamedBufferSubData) a_glNamedBufferSubData(buffer, offset, size, data); }
INTERPOSE(glNamedBufferSubData)
void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) WEAKGL;
static void (*p_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
static void (*a_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
static void w_glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) { if (mglshim_active && p_glNamedFramebufferDrawBuffer) { p_glNamedFramebufferDrawBuffer(framebuffer, buf); return; } if (a_glNamedFramebufferDrawBuffer) a_glNamedFramebufferDrawBuffer(framebuffer, buf); }
INTERPOSE(glNamedFramebufferDrawBuffer)
void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs) WEAKGL;
static void (*p_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
static void (*a_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
static void w_glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs) { if (mglshim_active && p_glNamedFramebufferDrawBuffers) { p_glNamedFramebufferDrawBuffers(framebuffer, n, bufs); return; } if (a_glNamedFramebufferDrawBuffers) a_glNamedFramebufferDrawBuffers(framebuffer, n, bufs); }
INTERPOSE(glNamedFramebufferDrawBuffers)
void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) WEAKGL;
static void (*p_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
static void (*a_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
static void w_glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) { if (mglshim_active && p_glNamedFramebufferParameteri) { p_glNamedFramebufferParameteri(framebuffer, pname, param); return; } if (a_glNamedFramebufferParameteri) a_glNamedFramebufferParameteri(framebuffer, pname, param); }
INTERPOSE(glNamedFramebufferParameteri)
void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) WEAKGL;
static void (*p_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
static void (*a_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
static void w_glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) { if (mglshim_active && p_glNamedFramebufferReadBuffer) { p_glNamedFramebufferReadBuffer(framebuffer, src); return; } if (a_glNamedFramebufferReadBuffer) a_glNamedFramebufferReadBuffer(framebuffer, src); }
INTERPOSE(glNamedFramebufferReadBuffer)
void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) WEAKGL;
static void (*p_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void (*a_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void w_glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { if (mglshim_active && p_glNamedFramebufferRenderbuffer) { p_glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer); return; } if (a_glNamedFramebufferRenderbuffer) a_glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer); }
INTERPOSE(glNamedFramebufferRenderbuffer)
void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) WEAKGL;
static void (*p_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
static void (*a_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
static void w_glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) { if (mglshim_active && p_glNamedFramebufferTexture) { p_glNamedFramebufferTexture(framebuffer, attachment, texture, level); return; } if (a_glNamedFramebufferTexture) a_glNamedFramebufferTexture(framebuffer, attachment, texture, level); }
INTERPOSE(glNamedFramebufferTexture)
void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) WEAKGL;
static void (*p_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void (*a_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void w_glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) { if (mglshim_active && p_glNamedFramebufferTextureLayer) { p_glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer); return; } if (a_glNamedFramebufferTextureLayer) a_glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer); }
INTERPOSE(glNamedFramebufferTextureLayer)
void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
static void (*a_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) { if (mglshim_active && p_glNamedRenderbufferStorage) { p_glNamedRenderbufferStorage(renderbuffer, internalformat, width, height); return; } if (a_glNamedRenderbufferStorage) a_glNamedRenderbufferStorage(renderbuffer, internalformat, width, height); }
INTERPOSE(glNamedRenderbufferStorage)
void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void (*a_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { if (mglshim_active && p_glNamedRenderbufferStorageMultisample) { p_glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height); return; } if (a_glNamedRenderbufferStorageMultisample) a_glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height); }
INTERPOSE(glNamedRenderbufferStorageMultisample)
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) WEAKGL;
static void (*p_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
static void (*a_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
static void w_glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) { if (mglshim_active && p_glObjectLabel) { p_glObjectLabel(identifier, name, length, label); return; } if (a_glObjectLabel) a_glObjectLabel(identifier, name, length, label); }
INTERPOSE(glObjectLabel)
void glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) WEAKGL;
static void (*p_glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
static void (*a_glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
static void w_glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) { if (mglshim_active && p_glObjectPtrLabel) { p_glObjectPtrLabel(ptr, length, label); return; } if (a_glObjectPtrLabel) a_glObjectPtrLabel(ptr, length, label); }
INTERPOSE(glObjectPtrLabel)
void glPatchParameterfv(GLenum pname, const GLfloat *values) WEAKGL;
static void (*p_glPatchParameterfv)(GLenum pname, const GLfloat *values);
static void (*a_glPatchParameterfv)(GLenum pname, const GLfloat *values);
static void w_glPatchParameterfv(GLenum pname, const GLfloat *values) { if (mglshim_active && p_glPatchParameterfv) { p_glPatchParameterfv(pname, values); return; } if (a_glPatchParameterfv) a_glPatchParameterfv(pname, values); }
INTERPOSE(glPatchParameterfv)
void glPatchParameteri(GLenum pname, GLint value) WEAKGL;
static void (*p_glPatchParameteri)(GLenum pname, GLint value);
static void (*a_glPatchParameteri)(GLenum pname, GLint value);
static void w_glPatchParameteri(GLenum pname, GLint value) { if (mglshim_active && p_glPatchParameteri) { p_glPatchParameteri(pname, value); return; } if (a_glPatchParameteri) a_glPatchParameteri(pname, value); }
INTERPOSE(glPatchParameteri)
void glPauseTransformFeedback(void) WEAKGL;
static void (*p_glPauseTransformFeedback)(void);
static void (*a_glPauseTransformFeedback)(void);
static void w_glPauseTransformFeedback(void) { if (mglshim_active && p_glPauseTransformFeedback) { p_glPauseTransformFeedback(); return; } if (a_glPauseTransformFeedback) a_glPauseTransformFeedback(); }
INTERPOSE(glPauseTransformFeedback)
void glPixelStoref(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glPixelStoref)(GLenum pname, GLfloat param);
static void (*a_glPixelStoref)(GLenum pname, GLfloat param);
static void w_glPixelStoref(GLenum pname, GLfloat param) { if (mglshim_active && p_glPixelStoref) { p_glPixelStoref(pname, param); return; } if (a_glPixelStoref) a_glPixelStoref(pname, param); }
INTERPOSE(glPixelStoref)
void glPixelStorei(GLenum pname, GLint param) WEAKGL;
static void (*p_glPixelStorei)(GLenum pname, GLint param);
static void (*a_glPixelStorei)(GLenum pname, GLint param);
static void w_glPixelStorei(GLenum pname, GLint param) { if (mglshim_active && p_glPixelStorei) { p_glPixelStorei(pname, param); return; } if (a_glPixelStorei) a_glPixelStorei(pname, param); }
INTERPOSE(glPixelStorei)
void glPointParameterf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glPointParameterf)(GLenum pname, GLfloat param);
static void (*a_glPointParameterf)(GLenum pname, GLfloat param);
static void w_glPointParameterf(GLenum pname, GLfloat param) { if (mglshim_active && p_glPointParameterf) { p_glPointParameterf(pname, param); return; } if (a_glPointParameterf) a_glPointParameterf(pname, param); }
INTERPOSE(glPointParameterf)
void glPointParameterfv(GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glPointParameterfv)(GLenum pname, const GLfloat *params);
static void (*a_glPointParameterfv)(GLenum pname, const GLfloat *params);
static void w_glPointParameterfv(GLenum pname, const GLfloat *params) { if (mglshim_active && p_glPointParameterfv) { p_glPointParameterfv(pname, params); return; } if (a_glPointParameterfv) a_glPointParameterfv(pname, params); }
INTERPOSE(glPointParameterfv)
void glPointParameteri(GLenum pname, GLint param) WEAKGL;
static void (*p_glPointParameteri)(GLenum pname, GLint param);
static void (*a_glPointParameteri)(GLenum pname, GLint param);
static void w_glPointParameteri(GLenum pname, GLint param) { if (mglshim_active && p_glPointParameteri) { p_glPointParameteri(pname, param); return; } if (a_glPointParameteri) a_glPointParameteri(pname, param); }
INTERPOSE(glPointParameteri)
void glPointParameteriv(GLenum pname, const GLint *params) WEAKGL;
static void (*p_glPointParameteriv)(GLenum pname, const GLint *params);
static void (*a_glPointParameteriv)(GLenum pname, const GLint *params);
static void w_glPointParameteriv(GLenum pname, const GLint *params) { if (mglshim_active && p_glPointParameteriv) { p_glPointParameteriv(pname, params); return; } if (a_glPointParameteriv) a_glPointParameteriv(pname, params); }
INTERPOSE(glPointParameteriv)
void glPointSize(GLfloat size) WEAKGL;
static void (*p_glPointSize)(GLfloat size);
static void (*a_glPointSize)(GLfloat size);
static void w_glPointSize(GLfloat size) { if (mglshim_active && p_glPointSize) { p_glPointSize(size); return; } if (a_glPointSize) a_glPointSize(size); }
INTERPOSE(glPointSize)
void glPolygonMode(GLenum face, GLenum mode) WEAKGL;
static void (*p_glPolygonMode)(GLenum face, GLenum mode);
static void (*a_glPolygonMode)(GLenum face, GLenum mode);
static void w_glPolygonMode(GLenum face, GLenum mode) { if (mglshim_active && p_glPolygonMode) { p_glPolygonMode(face, mode); return; } if (a_glPolygonMode) a_glPolygonMode(face, mode); }
INTERPOSE(glPolygonMode)
void glPolygonOffset(GLfloat factor, GLfloat units) WEAKGL;
static void (*p_glPolygonOffset)(GLfloat factor, GLfloat units);
static void (*a_glPolygonOffset)(GLfloat factor, GLfloat units);
static void w_glPolygonOffset(GLfloat factor, GLfloat units) { if (mglshim_active && p_glPolygonOffset) { p_glPolygonOffset(factor, units); return; } if (a_glPolygonOffset) a_glPolygonOffset(factor, units); }
INTERPOSE(glPolygonOffset)
void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) WEAKGL;
static void (*p_glPolygonOffsetClamp)(GLfloat factor, GLfloat units, GLfloat clamp);
static void (*a_glPolygonOffsetClamp)(GLfloat factor, GLfloat units, GLfloat clamp);
static void w_glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) { if (mglshim_active && p_glPolygonOffsetClamp) { p_glPolygonOffsetClamp(factor, units, clamp); return; } if (a_glPolygonOffsetClamp) a_glPolygonOffsetClamp(factor, units, clamp); }
INTERPOSE(glPolygonOffsetClamp)
void glPopDebugGroup(void) WEAKGL;
static void (*p_glPopDebugGroup)(void);
static void (*a_glPopDebugGroup)(void);
static void w_glPopDebugGroup(void) { if (mglshim_active && p_glPopDebugGroup) { p_glPopDebugGroup(); return; } if (a_glPopDebugGroup) a_glPopDebugGroup(); }
INTERPOSE(glPopDebugGroup)
void glPrimitiveRestartIndex(GLuint index) WEAKGL;
static void (*p_glPrimitiveRestartIndex)(GLuint index);
static void (*a_glPrimitiveRestartIndex)(GLuint index);
static void w_glPrimitiveRestartIndex(GLuint index) { if (mglshim_active && p_glPrimitiveRestartIndex) { p_glPrimitiveRestartIndex(index); return; } if (a_glPrimitiveRestartIndex) a_glPrimitiveRestartIndex(index); }
INTERPOSE(glPrimitiveRestartIndex)
void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) WEAKGL;
static void (*p_glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
static void (*a_glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
static void w_glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) { if (mglshim_active && p_glProgramBinary) { p_glProgramBinary(program, binaryFormat, binary, length); return; } if (a_glProgramBinary) a_glProgramBinary(program, binaryFormat, binary, length); }
INTERPOSE(glProgramBinary)
void glProgramParameteri(GLuint program, GLenum pname, GLint value) WEAKGL;
static void (*p_glProgramParameteri)(GLuint program, GLenum pname, GLint value);
static void (*a_glProgramParameteri)(GLuint program, GLenum pname, GLint value);
static void w_glProgramParameteri(GLuint program, GLenum pname, GLint value) { if (mglshim_active && p_glProgramParameteri) { p_glProgramParameteri(program, pname, value); return; } if (a_glProgramParameteri) a_glProgramParameteri(program, pname, value); }
INTERPOSE(glProgramParameteri)
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0) WEAKGL;
static void (*p_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
static void (*a_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
static void w_glProgramUniform1d(GLuint program, GLint location, GLdouble v0) { if (mglshim_active && p_glProgramUniform1d) { p_glProgramUniform1d(program, location, v0); return; } if (a_glProgramUniform1d) a_glProgramUniform1d(program, location, v0); }
INTERPOSE(glProgramUniform1d)
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*a_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glProgramUniform1dv) { p_glProgramUniform1dv(program, location, count, value); return; } if (a_glProgramUniform1dv) a_glProgramUniform1dv(program, location, count, value); }
INTERPOSE(glProgramUniform1dv)
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) WEAKGL;
static void (*p_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
static void (*a_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
static void w_glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { if (mglshim_active && p_glProgramUniform1f) { p_glProgramUniform1f(program, location, v0); return; } if (a_glProgramUniform1f) a_glProgramUniform1f(program, location, v0); }
INTERPOSE(glProgramUniform1f)
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*a_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glProgramUniform1fv) { p_glProgramUniform1fv(program, location, count, value); return; } if (a_glProgramUniform1fv) a_glProgramUniform1fv(program, location, count, value); }
INTERPOSE(glProgramUniform1fv)
void glProgramUniform1i(GLuint program, GLint location, GLint v0) WEAKGL;
static void (*p_glProgramUniform1i)(GLuint program, GLint location, GLint v0);
static void (*a_glProgramUniform1i)(GLuint program, GLint location, GLint v0);
static void w_glProgramUniform1i(GLuint program, GLint location, GLint v0) { if (mglshim_active && p_glProgramUniform1i) { p_glProgramUniform1i(program, location, v0); return; } if (a_glProgramUniform1i) a_glProgramUniform1i(program, location, v0); }
INTERPOSE(glProgramUniform1i)
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*a_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glProgramUniform1iv) { p_glProgramUniform1iv(program, location, count, value); return; } if (a_glProgramUniform1iv) a_glProgramUniform1iv(program, location, count, value); }
INTERPOSE(glProgramUniform1iv)
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) WEAKGL;
static void (*p_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
static void (*a_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
static void w_glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { if (mglshim_active && p_glProgramUniform1ui) { p_glProgramUniform1ui(program, location, v0); return; } if (a_glProgramUniform1ui) a_glProgramUniform1ui(program, location, v0); }
INTERPOSE(glProgramUniform1ui)
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*a_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glProgramUniform1uiv) { p_glProgramUniform1uiv(program, location, count, value); return; } if (a_glProgramUniform1uiv) a_glProgramUniform1uiv(program, location, count, value); }
INTERPOSE(glProgramUniform1uiv)
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) WEAKGL;
static void (*p_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
static void (*a_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
static void w_glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) { if (mglshim_active && p_glProgramUniform2d) { p_glProgramUniform2d(program, location, v0, v1); return; } if (a_glProgramUniform2d) a_glProgramUniform2d(program, location, v0, v1); }
INTERPOSE(glProgramUniform2d)
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*a_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glProgramUniform2dv) { p_glProgramUniform2dv(program, location, count, value); return; } if (a_glProgramUniform2dv) a_glProgramUniform2dv(program, location, count, value); }
INTERPOSE(glProgramUniform2dv)
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) WEAKGL;
static void (*p_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
static void (*a_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
static void w_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { if (mglshim_active && p_glProgramUniform2f) { p_glProgramUniform2f(program, location, v0, v1); return; } if (a_glProgramUniform2f) a_glProgramUniform2f(program, location, v0, v1); }
INTERPOSE(glProgramUniform2f)
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*a_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glProgramUniform2fv) { p_glProgramUniform2fv(program, location, count, value); return; } if (a_glProgramUniform2fv) a_glProgramUniform2fv(program, location, count, value); }
INTERPOSE(glProgramUniform2fv)
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) WEAKGL;
static void (*p_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
static void (*a_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
static void w_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { if (mglshim_active && p_glProgramUniform2i) { p_glProgramUniform2i(program, location, v0, v1); return; } if (a_glProgramUniform2i) a_glProgramUniform2i(program, location, v0, v1); }
INTERPOSE(glProgramUniform2i)
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*a_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glProgramUniform2iv) { p_glProgramUniform2iv(program, location, count, value); return; } if (a_glProgramUniform2iv) a_glProgramUniform2iv(program, location, count, value); }
INTERPOSE(glProgramUniform2iv)
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) WEAKGL;
static void (*p_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
static void (*a_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
static void w_glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) { if (mglshim_active && p_glProgramUniform2ui) { p_glProgramUniform2ui(program, location, v0, v1); return; } if (a_glProgramUniform2ui) a_glProgramUniform2ui(program, location, v0, v1); }
INTERPOSE(glProgramUniform2ui)
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*a_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glProgramUniform2uiv) { p_glProgramUniform2uiv(program, location, count, value); return; } if (a_glProgramUniform2uiv) a_glProgramUniform2uiv(program, location, count, value); }
INTERPOSE(glProgramUniform2uiv)
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) WEAKGL;
static void (*p_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
static void (*a_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
static void w_glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) { if (mglshim_active && p_glProgramUniform3d) { p_glProgramUniform3d(program, location, v0, v1, v2); return; } if (a_glProgramUniform3d) a_glProgramUniform3d(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3d)
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*a_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glProgramUniform3dv) { p_glProgramUniform3dv(program, location, count, value); return; } if (a_glProgramUniform3dv) a_glProgramUniform3dv(program, location, count, value); }
INTERPOSE(glProgramUniform3dv)
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) WEAKGL;
static void (*p_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void (*a_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void w_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { if (mglshim_active && p_glProgramUniform3f) { p_glProgramUniform3f(program, location, v0, v1, v2); return; } if (a_glProgramUniform3f) a_glProgramUniform3f(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3f)
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*a_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glProgramUniform3fv) { p_glProgramUniform3fv(program, location, count, value); return; } if (a_glProgramUniform3fv) a_glProgramUniform3fv(program, location, count, value); }
INTERPOSE(glProgramUniform3fv)
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) WEAKGL;
static void (*p_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
static void (*a_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
static void w_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { if (mglshim_active && p_glProgramUniform3i) { p_glProgramUniform3i(program, location, v0, v1, v2); return; } if (a_glProgramUniform3i) a_glProgramUniform3i(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3i)
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*a_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glProgramUniform3iv) { p_glProgramUniform3iv(program, location, count, value); return; } if (a_glProgramUniform3iv) a_glProgramUniform3iv(program, location, count, value); }
INTERPOSE(glProgramUniform3iv)
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) WEAKGL;
static void (*p_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
static void (*a_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
static void w_glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) { if (mglshim_active && p_glProgramUniform3ui) { p_glProgramUniform3ui(program, location, v0, v1, v2); return; } if (a_glProgramUniform3ui) a_glProgramUniform3ui(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3ui)
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*a_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glProgramUniform3uiv) { p_glProgramUniform3uiv(program, location, count, value); return; } if (a_glProgramUniform3uiv) a_glProgramUniform3uiv(program, location, count, value); }
INTERPOSE(glProgramUniform3uiv)
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) WEAKGL;
static void (*p_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
static void (*a_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
static void w_glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { if (mglshim_active && p_glProgramUniform4d) { p_glProgramUniform4d(program, location, v0, v1, v2, v3); return; } if (a_glProgramUniform4d) a_glProgramUniform4d(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4d)
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void (*a_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glProgramUniform4dv) { p_glProgramUniform4dv(program, location, count, value); return; } if (a_glProgramUniform4dv) a_glProgramUniform4dv(program, location, count, value); }
INTERPOSE(glProgramUniform4dv)
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) WEAKGL;
static void (*p_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void (*a_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void w_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { if (mglshim_active && p_glProgramUniform4f) { p_glProgramUniform4f(program, location, v0, v1, v2, v3); return; } if (a_glProgramUniform4f) a_glProgramUniform4f(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4f)
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void (*a_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glProgramUniform4fv) { p_glProgramUniform4fv(program, location, count, value); return; } if (a_glProgramUniform4fv) a_glProgramUniform4fv(program, location, count, value); }
INTERPOSE(glProgramUniform4fv)
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) WEAKGL;
static void (*p_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void (*a_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void w_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { if (mglshim_active && p_glProgramUniform4i) { p_glProgramUniform4i(program, location, v0, v1, v2, v3); return; } if (a_glProgramUniform4i) a_glProgramUniform4i(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4i)
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void (*a_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glProgramUniform4iv) { p_glProgramUniform4iv(program, location, count, value); return; } if (a_glProgramUniform4iv) a_glProgramUniform4iv(program, location, count, value); }
INTERPOSE(glProgramUniform4iv)
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) WEAKGL;
static void (*p_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void (*a_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void w_glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { if (mglshim_active && p_glProgramUniform4ui) { p_glProgramUniform4ui(program, location, v0, v1, v2, v3); return; } if (a_glProgramUniform4ui) a_glProgramUniform4ui(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4ui)
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void (*a_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glProgramUniform4uiv) { p_glProgramUniform4uiv(program, location, count, value); return; } if (a_glProgramUniform4uiv) a_glProgramUniform4uiv(program, location, count, value); }
INTERPOSE(glProgramUniform4uiv)
void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix2dv) { p_glProgramUniformMatrix2dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix2dv) a_glProgramUniformMatrix2dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2dv)
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix2fv) { p_glProgramUniformMatrix2fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix2fv) a_glProgramUniformMatrix2fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2fv)
void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix2x3dv) { p_glProgramUniformMatrix2x3dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix2x3dv) a_glProgramUniformMatrix2x3dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x3dv)
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix2x3fv) { p_glProgramUniformMatrix2x3fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix2x3fv) a_glProgramUniformMatrix2x3fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x3fv)
void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix2x4dv) { p_glProgramUniformMatrix2x4dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix2x4dv) a_glProgramUniformMatrix2x4dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x4dv)
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix2x4fv) { p_glProgramUniformMatrix2x4fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix2x4fv) a_glProgramUniformMatrix2x4fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x4fv)
void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix3dv) { p_glProgramUniformMatrix3dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix3dv) a_glProgramUniformMatrix3dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3dv)
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix3fv) { p_glProgramUniformMatrix3fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix3fv) a_glProgramUniformMatrix3fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3fv)
void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix3x2dv) { p_glProgramUniformMatrix3x2dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix3x2dv) a_glProgramUniformMatrix3x2dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x2dv)
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix3x2fv) { p_glProgramUniformMatrix3x2fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix3x2fv) a_glProgramUniformMatrix3x2fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x2fv)
void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix3x4dv) { p_glProgramUniformMatrix3x4dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix3x4dv) a_glProgramUniformMatrix3x4dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x4dv)
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix3x4fv) { p_glProgramUniformMatrix3x4fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix3x4fv) a_glProgramUniformMatrix3x4fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x4fv)
void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix4dv) { p_glProgramUniformMatrix4dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix4dv) a_glProgramUniformMatrix4dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4dv)
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix4fv) { p_glProgramUniformMatrix4fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix4fv) a_glProgramUniformMatrix4fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4fv)
void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix4x2dv) { p_glProgramUniformMatrix4x2dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix4x2dv) a_glProgramUniformMatrix4x2dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x2dv)
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix4x2fv) { p_glProgramUniformMatrix4x2fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix4x2fv) a_glProgramUniformMatrix4x2fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x2fv)
void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glProgramUniformMatrix4x3dv) { p_glProgramUniformMatrix4x3dv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix4x3dv) a_glProgramUniformMatrix4x3dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x3dv)
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glProgramUniformMatrix4x3fv) { p_glProgramUniformMatrix4x3fv(program, location, count, transpose, value); return; } if (a_glProgramUniformMatrix4x3fv) a_glProgramUniformMatrix4x3fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x3fv)
void glProvokingVertex(GLenum mode) WEAKGL;
static void (*p_glProvokingVertex)(GLenum mode);
static void (*a_glProvokingVertex)(GLenum mode);
static void w_glProvokingVertex(GLenum mode) { if (mglshim_active && p_glProvokingVertex) { p_glProvokingVertex(mode); return; } if (a_glProvokingVertex) a_glProvokingVertex(mode); }
INTERPOSE(glProvokingVertex)
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) WEAKGL;
static void (*p_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
static void (*a_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
static void w_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) { if (mglshim_active && p_glPushDebugGroup) { p_glPushDebugGroup(source, id, length, message); return; } if (a_glPushDebugGroup) a_glPushDebugGroup(source, id, length, message); }
INTERPOSE(glPushDebugGroup)
void glQueryCounter(GLuint id, GLenum target) WEAKGL;
static void (*p_glQueryCounter)(GLuint id, GLenum target);
static void (*a_glQueryCounter)(GLuint id, GLenum target);
static void w_glQueryCounter(GLuint id, GLenum target) { if (mglshim_active && p_glQueryCounter) { p_glQueryCounter(id, target); return; } if (a_glQueryCounter) a_glQueryCounter(id, target); }
INTERPOSE(glQueryCounter)
void glReadBuffer(GLenum src) WEAKGL;
static void (*p_glReadBuffer)(GLenum src);
static void (*a_glReadBuffer)(GLenum src);
static void w_glReadBuffer(GLenum src) { if (mglshim_active && p_glReadBuffer) { p_glReadBuffer(src); return; } if (a_glReadBuffer) a_glReadBuffer(src); }
INTERPOSE(glReadBuffer)
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) WEAKGL;
static void (*p_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
static void (*a_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
static void w_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) { if (mglshim_active && p_glReadPixels) { p_glReadPixels(x, y, width, height, format, type, pixels); return; } if (a_glReadPixels) a_glReadPixels(x, y, width, height, format, type, pixels); }
INTERPOSE(glReadPixels)
void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) WEAKGL;
static void (*p_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
static void (*a_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
static void w_glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) { if (mglshim_active && p_glReadnPixels) { p_glReadnPixels(x, y, width, height, format, type, bufSize, data); return; } if (a_glReadnPixels) a_glReadnPixels(x, y, width, height, format, type, bufSize, data); }
INTERPOSE(glReadnPixels)
void glReleaseShaderCompiler(void) WEAKGL;
static void (*p_glReleaseShaderCompiler)(void);
static void (*a_glReleaseShaderCompiler)(void);
static void w_glReleaseShaderCompiler(void) { if (mglshim_active && p_glReleaseShaderCompiler) { p_glReleaseShaderCompiler(); return; } if (a_glReleaseShaderCompiler) a_glReleaseShaderCompiler(); }
INTERPOSE(glReleaseShaderCompiler)
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
static void (*a_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { if (mglshim_active && p_glRenderbufferStorage) { p_glRenderbufferStorage(target, internalformat, width, height); return; } if (a_glRenderbufferStorage) a_glRenderbufferStorage(target, internalformat, width, height); }
INTERPOSE(glRenderbufferStorage)
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void (*a_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { if (mglshim_active && p_glRenderbufferStorageMultisample) { p_glRenderbufferStorageMultisample(target, samples, internalformat, width, height); return; } if (a_glRenderbufferStorageMultisample) a_glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
INTERPOSE(glRenderbufferStorageMultisample)
void glResumeTransformFeedback(void) WEAKGL;
static void (*p_glResumeTransformFeedback)(void);
static void (*a_glResumeTransformFeedback)(void);
static void w_glResumeTransformFeedback(void) { if (mglshim_active && p_glResumeTransformFeedback) { p_glResumeTransformFeedback(); return; } if (a_glResumeTransformFeedback) a_glResumeTransformFeedback(); }
INTERPOSE(glResumeTransformFeedback)
void glSampleCoverage(GLfloat value, GLboolean invert) WEAKGL;
static void (*p_glSampleCoverage)(GLfloat value, GLboolean invert);
static void (*a_glSampleCoverage)(GLfloat value, GLboolean invert);
static void w_glSampleCoverage(GLfloat value, GLboolean invert) { if (mglshim_active && p_glSampleCoverage) { p_glSampleCoverage(value, invert); return; } if (a_glSampleCoverage) a_glSampleCoverage(value, invert); }
INTERPOSE(glSampleCoverage)
void glSampleMaski(GLuint maskNumber, GLbitfield mask) WEAKGL;
static void (*p_glSampleMaski)(GLuint maskNumber, GLbitfield mask);
static void (*a_glSampleMaski)(GLuint maskNumber, GLbitfield mask);
static void w_glSampleMaski(GLuint maskNumber, GLbitfield mask) { if (mglshim_active && p_glSampleMaski) { p_glSampleMaski(maskNumber, mask); return; } if (a_glSampleMaski) a_glSampleMaski(maskNumber, mask); }
INTERPOSE(glSampleMaski)
void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) WEAKGL;
static void (*p_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
static void (*a_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
static void w_glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) { if (mglshim_active && p_glSamplerParameterIiv) { p_glSamplerParameterIiv(sampler, pname, param); return; } if (a_glSamplerParameterIiv) a_glSamplerParameterIiv(sampler, pname, param); }
INTERPOSE(glSamplerParameterIiv)
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) WEAKGL;
static void (*p_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
static void (*a_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
static void w_glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) { if (mglshim_active && p_glSamplerParameterIuiv) { p_glSamplerParameterIuiv(sampler, pname, param); return; } if (a_glSamplerParameterIuiv) a_glSamplerParameterIuiv(sampler, pname, param); }
INTERPOSE(glSamplerParameterIuiv)
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
static void (*a_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
static void w_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { if (mglshim_active && p_glSamplerParameterf) { p_glSamplerParameterf(sampler, pname, param); return; } if (a_glSamplerParameterf) a_glSamplerParameterf(sampler, pname, param); }
INTERPOSE(glSamplerParameterf)
void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) WEAKGL;
static void (*p_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
static void (*a_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
static void w_glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) { if (mglshim_active && p_glSamplerParameterfv) { p_glSamplerParameterfv(sampler, pname, param); return; } if (a_glSamplerParameterfv) a_glSamplerParameterfv(sampler, pname, param); }
INTERPOSE(glSamplerParameterfv)
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) WEAKGL;
static void (*p_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
static void (*a_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
static void w_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { if (mglshim_active && p_glSamplerParameteri) { p_glSamplerParameteri(sampler, pname, param); return; } if (a_glSamplerParameteri) a_glSamplerParameteri(sampler, pname, param); }
INTERPOSE(glSamplerParameteri)
void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) WEAKGL;
static void (*p_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
static void (*a_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
static void w_glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) { if (mglshim_active && p_glSamplerParameteriv) { p_glSamplerParameteriv(sampler, pname, param); return; } if (a_glSamplerParameteriv) a_glSamplerParameteriv(sampler, pname, param); }
INTERPOSE(glSamplerParameteriv)
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glScissor) { p_glScissor(x, y, width, height); return; } if (a_glScissor) a_glScissor(x, y, width, height); }
INTERPOSE(glScissor)
void glScissorArrayv(GLuint first, GLsizei count, const GLint *v) WEAKGL;
static void (*p_glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
static void (*a_glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
static void w_glScissorArrayv(GLuint first, GLsizei count, const GLint *v) { if (mglshim_active && p_glScissorArrayv) { p_glScissorArrayv(first, count, v); return; } if (a_glScissorArrayv) a_glScissorArrayv(first, count, v); }
INTERPOSE(glScissorArrayv)
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
static void (*a_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
static void w_glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) { if (mglshim_active && p_glScissorIndexed) { p_glScissorIndexed(index, left, bottom, width, height); return; } if (a_glScissorIndexed) a_glScissorIndexed(index, left, bottom, width, height); }
INTERPOSE(glScissorIndexed)
void glScissorIndexedv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glScissorIndexedv)(GLuint index, const GLint *v);
static void (*a_glScissorIndexedv)(GLuint index, const GLint *v);
static void w_glScissorIndexedv(GLuint index, const GLint *v) { if (mglshim_active && p_glScissorIndexedv) { p_glScissorIndexedv(index, v); return; } if (a_glScissorIndexedv) a_glScissorIndexedv(index, v); }
INTERPOSE(glScissorIndexedv)
void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length) WEAKGL;
static void (*p_glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
static void (*a_glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
static void w_glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length) { if (mglshim_active && p_glShaderBinary) { p_glShaderBinary(count, shaders, binaryFormat, binary, length); return; } if (a_glShaderBinary) a_glShaderBinary(count, shaders, binaryFormat, binary, length); }
INTERPOSE(glShaderBinary)
void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) WEAKGL;
static void (*p_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
static void (*a_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
static void w_glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) { if (mglshim_active && p_glShaderSource) { p_glShaderSource(shader, count, string, length); return; } if (a_glShaderSource) a_glShaderSource(shader, count, string, length); }
INTERPOSE(glShaderSource)
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) WEAKGL;
static void (*p_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
static void (*a_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
static void w_glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) { if (mglshim_active && p_glShaderStorageBlockBinding) { p_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding); return; } if (a_glShaderStorageBlockBinding) a_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding); }
INTERPOSE(glShaderStorageBlockBinding)
void glSpecializeShader(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) WEAKGL;
static void (*p_glSpecializeShader)(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
static void (*a_glSpecializeShader)(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
static void w_glSpecializeShader(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) { if (mglshim_active && p_glSpecializeShader) { p_glSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue); return; } if (a_glSpecializeShader) a_glSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue); }
INTERPOSE(glSpecializeShader)
void glStencilFunc(GLenum func, GLint ref, GLuint mask) WEAKGL;
static void (*p_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
static void (*a_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
static void w_glStencilFunc(GLenum func, GLint ref, GLuint mask) { if (mglshim_active && p_glStencilFunc) { p_glStencilFunc(func, ref, mask); return; } if (a_glStencilFunc) a_glStencilFunc(func, ref, mask); }
INTERPOSE(glStencilFunc)
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) WEAKGL;
static void (*p_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
static void (*a_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
static void w_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { if (mglshim_active && p_glStencilFuncSeparate) { p_glStencilFuncSeparate(face, func, ref, mask); return; } if (a_glStencilFuncSeparate) a_glStencilFuncSeparate(face, func, ref, mask); }
INTERPOSE(glStencilFuncSeparate)
void glStencilMask(GLuint mask) WEAKGL;
static void (*p_glStencilMask)(GLuint mask);
static void (*a_glStencilMask)(GLuint mask);
static void w_glStencilMask(GLuint mask) { if (mglshim_active && p_glStencilMask) { p_glStencilMask(mask); return; } if (a_glStencilMask) a_glStencilMask(mask); }
INTERPOSE(glStencilMask)
void glStencilMaskSeparate(GLenum face, GLuint mask) WEAKGL;
static void (*p_glStencilMaskSeparate)(GLenum face, GLuint mask);
static void (*a_glStencilMaskSeparate)(GLenum face, GLuint mask);
static void w_glStencilMaskSeparate(GLenum face, GLuint mask) { if (mglshim_active && p_glStencilMaskSeparate) { p_glStencilMaskSeparate(face, mask); return; } if (a_glStencilMaskSeparate) a_glStencilMaskSeparate(face, mask); }
INTERPOSE(glStencilMaskSeparate)
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) WEAKGL;
static void (*p_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
static void (*a_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
static void w_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { if (mglshim_active && p_glStencilOp) { p_glStencilOp(fail, zfail, zpass); return; } if (a_glStencilOp) a_glStencilOp(fail, zfail, zpass); }
INTERPOSE(glStencilOp)
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) WEAKGL;
static void (*p_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
static void (*a_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
static void w_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { if (mglshim_active && p_glStencilOpSeparate) { p_glStencilOpSeparate(face, sfail, dpfail, dppass); return; } if (a_glStencilOpSeparate) a_glStencilOpSeparate(face, sfail, dpfail, dppass); }
INTERPOSE(glStencilOpSeparate)
void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) WEAKGL;
static void (*p_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
static void (*a_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
static void w_glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { if (mglshim_active && p_glTexBuffer) { p_glTexBuffer(target, internalformat, buffer); return; } if (a_glTexBuffer) a_glTexBuffer(target, internalformat, buffer); }
INTERPOSE(glTexBuffer)
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void (*a_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (mglshim_active && p_glTexBufferRange) { p_glTexBufferRange(target, internalformat, buffer, offset, size); return; } if (a_glTexBufferRange) a_glTexBufferRange(target, internalformat, buffer, offset, size); }
INTERPOSE(glTexBufferRange)
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
static void (*a_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
static void w_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTexImage1D) { p_glTexImage1D(target, level, internalformat, width, border, format, type, pixels); return; } if (a_glTexImage1D) a_glTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
INTERPOSE(glTexImage1D)
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
static void (*a_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
static void w_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTexImage2D) { p_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); return; } if (a_glTexImage2D) a_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
INTERPOSE(glTexImage2D)
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void (*a_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void w_glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { if (mglshim_active && p_glTexImage2DMultisample) { p_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); return; } if (a_glTexImage2DMultisample) a_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
INTERPOSE(glTexImage2DMultisample)
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
static void (*a_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
static void w_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTexImage3D) { p_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); return; } if (a_glTexImage3D) a_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
INTERPOSE(glTexImage3D)
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void (*a_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void w_glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { if (mglshim_active && p_glTexImage3DMultisample) { p_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); return; } if (a_glTexImage3DMultisample) a_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
INTERPOSE(glTexImage3DMultisample)
void glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
static void (*a_glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
static void w_glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) { if (mglshim_active && p_glTexParameterIiv) { p_glTexParameterIiv(target, pname, params); return; } if (a_glTexParameterIiv) a_glTexParameterIiv(target, pname, params); }
INTERPOSE(glTexParameterIiv)
void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) WEAKGL;
static void (*p_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
static void (*a_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
static void w_glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) { if (mglshim_active && p_glTexParameterIuiv) { p_glTexParameterIuiv(target, pname, params); return; } if (a_glTexParameterIuiv) a_glTexParameterIuiv(target, pname, params); }
INTERPOSE(glTexParameterIuiv)
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
static void (*a_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
static void w_glTexParameterf(GLenum target, GLenum pname, GLfloat param) { if (mglshim_active && p_glTexParameterf) { p_glTexParameterf(target, pname, param); return; } if (a_glTexParameterf) a_glTexParameterf(target, pname, param); }
INTERPOSE(glTexParameterf)
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
static void (*a_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
static void w_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) { if (mglshim_active && p_glTexParameterfv) { p_glTexParameterfv(target, pname, params); return; } if (a_glTexParameterfv) a_glTexParameterfv(target, pname, params); }
INTERPOSE(glTexParameterfv)
void glTexParameteri(GLenum target, GLenum pname, GLint param) WEAKGL;
static void (*p_glTexParameteri)(GLenum target, GLenum pname, GLint param);
static void (*a_glTexParameteri)(GLenum target, GLenum pname, GLint param);
static void w_glTexParameteri(GLenum target, GLenum pname, GLint param) { if (mglshim_active && p_glTexParameteri) { p_glTexParameteri(target, pname, param); return; } if (a_glTexParameteri) a_glTexParameteri(target, pname, param); }
INTERPOSE(glTexParameteri)
void glTexParameteriv(GLenum target, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
static void (*a_glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
static void w_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) { if (mglshim_active && p_glTexParameteriv) { p_glTexParameteriv(target, pname, params); return; } if (a_glTexParameteriv) a_glTexParameteriv(target, pname, params); }
INTERPOSE(glTexParameteriv)
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) WEAKGL;
static void (*p_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
static void (*a_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
static void w_glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) { if (mglshim_active && p_glTexStorage1D) { p_glTexStorage1D(target, levels, internalformat, width); return; } if (a_glTexStorage1D) a_glTexStorage1D(target, levels, internalformat, width); }
INTERPOSE(glTexStorage1D)
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void (*a_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { if (mglshim_active && p_glTexStorage2D) { p_glTexStorage2D(target, levels, internalformat, width, height); return; } if (a_glTexStorage2D) a_glTexStorage2D(target, levels, internalformat, width, height); }
INTERPOSE(glTexStorage2D)
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void (*a_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void w_glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { if (mglshim_active && p_glTexStorage2DMultisample) { p_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); return; } if (a_glTexStorage2DMultisample) a_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
INTERPOSE(glTexStorage2DMultisample)
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) WEAKGL;
static void (*p_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void (*a_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void w_glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { if (mglshim_active && p_glTexStorage3D) { p_glTexStorage3D(target, levels, internalformat, width, height, depth); return; } if (a_glTexStorage3D) a_glTexStorage3D(target, levels, internalformat, width, height, depth); }
INTERPOSE(glTexStorage3D)
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void (*a_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void w_glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { if (mglshim_active && p_glTexStorage3DMultisample) { p_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); return; } if (a_glTexStorage3DMultisample) a_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
INTERPOSE(glTexStorage3DMultisample)
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
static void (*a_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
static void w_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTexSubImage1D) { p_glTexSubImage1D(target, level, xoffset, width, format, type, pixels); return; } if (a_glTexSubImage1D) a_glTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
INTERPOSE(glTexSubImage1D)
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void (*a_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void w_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTexSubImage2D) { p_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); return; } if (a_glTexSubImage2D) a_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
INTERPOSE(glTexSubImage2D)
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
static void (*a_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
static void w_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTexSubImage3D) { p_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); return; } if (a_glTexSubImage3D) a_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
INTERPOSE(glTexSubImage3D)
void glTextureBarrier(void) WEAKGL;
static void (*p_glTextureBarrier)(void);
static void (*a_glTextureBarrier)(void);
static void w_glTextureBarrier(void) { if (mglshim_active && p_glTextureBarrier) { p_glTextureBarrier(); return; } if (a_glTextureBarrier) a_glTextureBarrier(); }
INTERPOSE(glTextureBarrier)
void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) WEAKGL;
static void (*p_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
static void (*a_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
static void w_glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) { if (mglshim_active && p_glTextureBuffer) { p_glTextureBuffer(texture, internalformat, buffer); return; } if (a_glTextureBuffer) a_glTextureBuffer(texture, internalformat, buffer); }
INTERPOSE(glTextureBuffer)
void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void (*a_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (mglshim_active && p_glTextureBufferRange) { p_glTextureBufferRange(texture, internalformat, buffer, offset, size); return; } if (a_glTextureBufferRange) a_glTextureBufferRange(texture, internalformat, buffer, offset, size); }
INTERPOSE(glTextureBufferRange)
void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
static void (*a_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
static void w_glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params) { if (mglshim_active && p_glTextureParameterIiv) { p_glTextureParameterIiv(texture, pname, params); return; } if (a_glTextureParameterIiv) a_glTextureParameterIiv(texture, pname, params); }
INTERPOSE(glTextureParameterIiv)
void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params) WEAKGL;
static void (*p_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
static void (*a_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
static void w_glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params) { if (mglshim_active && p_glTextureParameterIuiv) { p_glTextureParameterIuiv(texture, pname, params); return; } if (a_glTextureParameterIuiv) a_glTextureParameterIuiv(texture, pname, params); }
INTERPOSE(glTextureParameterIuiv)
void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
static void (*a_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
static void w_glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) { if (mglshim_active && p_glTextureParameterf) { p_glTextureParameterf(texture, pname, param); return; } if (a_glTextureParameterf) a_glTextureParameterf(texture, pname, param); }
INTERPOSE(glTextureParameterf)
void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param) WEAKGL;
static void (*p_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
static void (*a_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
static void w_glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param) { if (mglshim_active && p_glTextureParameterfv) { p_glTextureParameterfv(texture, pname, param); return; } if (a_glTextureParameterfv) a_glTextureParameterfv(texture, pname, param); }
INTERPOSE(glTextureParameterfv)
void glTextureParameteri(GLuint texture, GLenum pname, GLint param) WEAKGL;
static void (*p_glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
static void (*a_glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
static void w_glTextureParameteri(GLuint texture, GLenum pname, GLint param) { if (mglshim_active && p_glTextureParameteri) { p_glTextureParameteri(texture, pname, param); return; } if (a_glTextureParameteri) a_glTextureParameteri(texture, pname, param); }
INTERPOSE(glTextureParameteri)
void glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param) WEAKGL;
static void (*p_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
static void (*a_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
static void w_glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param) { if (mglshim_active && p_glTextureParameteriv) { p_glTextureParameteriv(texture, pname, param); return; } if (a_glTextureParameteriv) a_glTextureParameteriv(texture, pname, param); }
INTERPOSE(glTextureParameteriv)
void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) WEAKGL;
static void (*p_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
static void (*a_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
static void w_glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) { if (mglshim_active && p_glTextureStorage1D) { p_glTextureStorage1D(texture, levels, internalformat, width); return; } if (a_glTextureStorage1D) a_glTextureStorage1D(texture, levels, internalformat, width); }
INTERPOSE(glTextureStorage1D)
void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void (*a_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { if (mglshim_active && p_glTextureStorage2D) { p_glTextureStorage2D(texture, levels, internalformat, width, height); return; } if (a_glTextureStorage2D) a_glTextureStorage2D(texture, levels, internalformat, width, height); }
INTERPOSE(glTextureStorage2D)
void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void (*a_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void w_glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { if (mglshim_active && p_glTextureStorage2DMultisample) { p_glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations); return; } if (a_glTextureStorage2DMultisample) a_glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations); }
INTERPOSE(glTextureStorage2DMultisample)
void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) WEAKGL;
static void (*p_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void (*a_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void w_glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { if (mglshim_active && p_glTextureStorage3D) { p_glTextureStorage3D(texture, levels, internalformat, width, height, depth); return; } if (a_glTextureStorage3D) a_glTextureStorage3D(texture, levels, internalformat, width, height, depth); }
INTERPOSE(glTextureStorage3D)
void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void (*a_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void w_glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { if (mglshim_active && p_glTextureStorage3DMultisample) { p_glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations); return; } if (a_glTextureStorage3DMultisample) a_glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations); }
INTERPOSE(glTextureStorage3DMultisample)
void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
static void (*a_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
static void w_glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTextureSubImage1D) { p_glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels); return; } if (a_glTextureSubImage1D) a_glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels); }
INTERPOSE(glTextureSubImage1D)
void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void (*a_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void w_glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTextureSubImage2D) { p_glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels); return; } if (a_glTextureSubImage2D) a_glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels); }
INTERPOSE(glTextureSubImage2D)
void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
static void (*a_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
static void w_glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glTextureSubImage3D) { p_glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); return; } if (a_glTextureSubImage3D) a_glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
INTERPOSE(glTextureSubImage3D)
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) WEAKGL;
static void (*p_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
static void (*a_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
static void w_glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) { if (mglshim_active && p_glTextureView) { p_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); return; } if (a_glTextureView) a_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); }
INTERPOSE(glTextureView)
void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) WEAKGL;
static void (*p_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
static void (*a_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
static void w_glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) { if (mglshim_active && p_glTransformFeedbackBufferBase) { p_glTransformFeedbackBufferBase(xfb, index, buffer); return; } if (a_glTransformFeedbackBufferBase) a_glTransformFeedbackBufferBase(xfb, index, buffer); }
INTERPOSE(glTransformFeedbackBufferBase)
void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void (*a_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (mglshim_active && p_glTransformFeedbackBufferRange) { p_glTransformFeedbackBufferRange(xfb, index, buffer, offset, size); return; } if (a_glTransformFeedbackBufferRange) a_glTransformFeedbackBufferRange(xfb, index, buffer, offset, size); }
INTERPOSE(glTransformFeedbackBufferRange)
void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) WEAKGL;
static void (*p_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
static void (*a_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
static void w_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) { if (mglshim_active && p_glTransformFeedbackVaryings) { p_glTransformFeedbackVaryings(program, count, varyings, bufferMode); return; } if (a_glTransformFeedbackVaryings) a_glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
INTERPOSE(glTransformFeedbackVaryings)
void glUniform1d(GLint location, GLdouble x) WEAKGL;
static void (*p_glUniform1d)(GLint location, GLdouble x);
static void (*a_glUniform1d)(GLint location, GLdouble x);
static void w_glUniform1d(GLint location, GLdouble x) { if (mglshim_active && p_glUniform1d) { p_glUniform1d(location, x); return; } if (a_glUniform1d) a_glUniform1d(location, x); }
INTERPOSE(glUniform1d)
void glUniform1dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
static void (*a_glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform1dv(GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glUniform1dv) { p_glUniform1dv(location, count, value); return; } if (a_glUniform1dv) a_glUniform1dv(location, count, value); }
INTERPOSE(glUniform1dv)
void glUniform1f(GLint location, GLfloat v0) WEAKGL;
static void (*p_glUniform1f)(GLint location, GLfloat v0);
static void (*a_glUniform1f)(GLint location, GLfloat v0);
static void w_glUniform1f(GLint location, GLfloat v0) { if (mglshim_active && p_glUniform1f) { p_glUniform1f(location, v0); return; } if (a_glUniform1f) a_glUniform1f(location, v0); }
INTERPOSE(glUniform1f)
void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
static void (*a_glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glUniform1fv) { p_glUniform1fv(location, count, value); return; } if (a_glUniform1fv) a_glUniform1fv(location, count, value); }
INTERPOSE(glUniform1fv)
void glUniform1i(GLint location, GLint v0) WEAKGL;
static void (*p_glUniform1i)(GLint location, GLint v0);
static void (*a_glUniform1i)(GLint location, GLint v0);
static void w_glUniform1i(GLint location, GLint v0) { if (mglshim_active && p_glUniform1i) { p_glUniform1i(location, v0); return; } if (a_glUniform1i) a_glUniform1i(location, v0); }
INTERPOSE(glUniform1i)
void glUniform1iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform1iv)(GLint location, GLsizei count, const GLint *value);
static void (*a_glUniform1iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform1iv(GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glUniform1iv) { p_glUniform1iv(location, count, value); return; } if (a_glUniform1iv) a_glUniform1iv(location, count, value); }
INTERPOSE(glUniform1iv)
void glUniform1ui(GLint location, GLuint v0) WEAKGL;
static void (*p_glUniform1ui)(GLint location, GLuint v0);
static void (*a_glUniform1ui)(GLint location, GLuint v0);
static void w_glUniform1ui(GLint location, GLuint v0) { if (mglshim_active && p_glUniform1ui) { p_glUniform1ui(location, v0); return; } if (a_glUniform1ui) a_glUniform1ui(location, v0); }
INTERPOSE(glUniform1ui)
void glUniform1uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
static void (*a_glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform1uiv(GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glUniform1uiv) { p_glUniform1uiv(location, count, value); return; } if (a_glUniform1uiv) a_glUniform1uiv(location, count, value); }
INTERPOSE(glUniform1uiv)
void glUniform2d(GLint location, GLdouble x, GLdouble y) WEAKGL;
static void (*p_glUniform2d)(GLint location, GLdouble x, GLdouble y);
static void (*a_glUniform2d)(GLint location, GLdouble x, GLdouble y);
static void w_glUniform2d(GLint location, GLdouble x, GLdouble y) { if (mglshim_active && p_glUniform2d) { p_glUniform2d(location, x, y); return; } if (a_glUniform2d) a_glUniform2d(location, x, y); }
INTERPOSE(glUniform2d)
void glUniform2dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
static void (*a_glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform2dv(GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glUniform2dv) { p_glUniform2dv(location, count, value); return; } if (a_glUniform2dv) a_glUniform2dv(location, count, value); }
INTERPOSE(glUniform2dv)
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) WEAKGL;
static void (*p_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
static void (*a_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
static void w_glUniform2f(GLint location, GLfloat v0, GLfloat v1) { if (mglshim_active && p_glUniform2f) { p_glUniform2f(location, v0, v1); return; } if (a_glUniform2f) a_glUniform2f(location, v0, v1); }
INTERPOSE(glUniform2f)
void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
static void (*a_glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glUniform2fv) { p_glUniform2fv(location, count, value); return; } if (a_glUniform2fv) a_glUniform2fv(location, count, value); }
INTERPOSE(glUniform2fv)
void glUniform2i(GLint location, GLint v0, GLint v1) WEAKGL;
static void (*p_glUniform2i)(GLint location, GLint v0, GLint v1);
static void (*a_glUniform2i)(GLint location, GLint v0, GLint v1);
static void w_glUniform2i(GLint location, GLint v0, GLint v1) { if (mglshim_active && p_glUniform2i) { p_glUniform2i(location, v0, v1); return; } if (a_glUniform2i) a_glUniform2i(location, v0, v1); }
INTERPOSE(glUniform2i)
void glUniform2iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform2iv)(GLint location, GLsizei count, const GLint *value);
static void (*a_glUniform2iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform2iv(GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glUniform2iv) { p_glUniform2iv(location, count, value); return; } if (a_glUniform2iv) a_glUniform2iv(location, count, value); }
INTERPOSE(glUniform2iv)
void glUniform2ui(GLint location, GLuint v0, GLuint v1) WEAKGL;
static void (*p_glUniform2ui)(GLint location, GLuint v0, GLuint v1);
static void (*a_glUniform2ui)(GLint location, GLuint v0, GLuint v1);
static void w_glUniform2ui(GLint location, GLuint v0, GLuint v1) { if (mglshim_active && p_glUniform2ui) { p_glUniform2ui(location, v0, v1); return; } if (a_glUniform2ui) a_glUniform2ui(location, v0, v1); }
INTERPOSE(glUniform2ui)
void glUniform2uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
static void (*a_glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform2uiv(GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glUniform2uiv) { p_glUniform2uiv(location, count, value); return; } if (a_glUniform2uiv) a_glUniform2uiv(location, count, value); }
INTERPOSE(glUniform2uiv)
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
static void (*a_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
static void w_glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glUniform3d) { p_glUniform3d(location, x, y, z); return; } if (a_glUniform3d) a_glUniform3d(location, x, y, z); }
INTERPOSE(glUniform3d)
void glUniform3dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
static void (*a_glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform3dv(GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glUniform3dv) { p_glUniform3dv(location, count, value); return; } if (a_glUniform3dv) a_glUniform3dv(location, count, value); }
INTERPOSE(glUniform3dv)
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) WEAKGL;
static void (*p_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void (*a_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void w_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { if (mglshim_active && p_glUniform3f) { p_glUniform3f(location, v0, v1, v2); return; } if (a_glUniform3f) a_glUniform3f(location, v0, v1, v2); }
INTERPOSE(glUniform3f)
void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
static void (*a_glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glUniform3fv) { p_glUniform3fv(location, count, value); return; } if (a_glUniform3fv) a_glUniform3fv(location, count, value); }
INTERPOSE(glUniform3fv)
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) WEAKGL;
static void (*p_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
static void (*a_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
static void w_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { if (mglshim_active && p_glUniform3i) { p_glUniform3i(location, v0, v1, v2); return; } if (a_glUniform3i) a_glUniform3i(location, v0, v1, v2); }
INTERPOSE(glUniform3i)
void glUniform3iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform3iv)(GLint location, GLsizei count, const GLint *value);
static void (*a_glUniform3iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform3iv(GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glUniform3iv) { p_glUniform3iv(location, count, value); return; } if (a_glUniform3iv) a_glUniform3iv(location, count, value); }
INTERPOSE(glUniform3iv)
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) WEAKGL;
static void (*p_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
static void (*a_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
static void w_glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { if (mglshim_active && p_glUniform3ui) { p_glUniform3ui(location, v0, v1, v2); return; } if (a_glUniform3ui) a_glUniform3ui(location, v0, v1, v2); }
INTERPOSE(glUniform3ui)
void glUniform3uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
static void (*a_glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform3uiv(GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glUniform3uiv) { p_glUniform3uiv(location, count, value); return; } if (a_glUniform3uiv) a_glUniform3uiv(location, count, value); }
INTERPOSE(glUniform3uiv)
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*a_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (mglshim_active && p_glUniform4d) { p_glUniform4d(location, x, y, z, w); return; } if (a_glUniform4d) a_glUniform4d(location, x, y, z, w); }
INTERPOSE(glUniform4d)
void glUniform4dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
static void (*a_glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform4dv(GLint location, GLsizei count, const GLdouble *value) { if (mglshim_active && p_glUniform4dv) { p_glUniform4dv(location, count, value); return; } if (a_glUniform4dv) a_glUniform4dv(location, count, value); }
INTERPOSE(glUniform4dv)
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) WEAKGL;
static void (*p_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void (*a_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void w_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { if (mglshim_active && p_glUniform4f) { p_glUniform4f(location, v0, v1, v2, v3); return; } if (a_glUniform4f) a_glUniform4f(location, v0, v1, v2, v3); }
INTERPOSE(glUniform4f)
void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
static void (*a_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { if (mglshim_active && p_glUniform4fv) { p_glUniform4fv(location, count, value); return; } if (a_glUniform4fv) a_glUniform4fv(location, count, value); }
INTERPOSE(glUniform4fv)
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) WEAKGL;
static void (*p_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void (*a_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void w_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { if (mglshim_active && p_glUniform4i) { p_glUniform4i(location, v0, v1, v2, v3); return; } if (a_glUniform4i) a_glUniform4i(location, v0, v1, v2, v3); }
INTERPOSE(glUniform4i)
void glUniform4iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform4iv)(GLint location, GLsizei count, const GLint *value);
static void (*a_glUniform4iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform4iv(GLint location, GLsizei count, const GLint *value) { if (mglshim_active && p_glUniform4iv) { p_glUniform4iv(location, count, value); return; } if (a_glUniform4iv) a_glUniform4iv(location, count, value); }
INTERPOSE(glUniform4iv)
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) WEAKGL;
static void (*p_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void (*a_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void w_glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { if (mglshim_active && p_glUniform4ui) { p_glUniform4ui(location, v0, v1, v2, v3); return; } if (a_glUniform4ui) a_glUniform4ui(location, v0, v1, v2, v3); }
INTERPOSE(glUniform4ui)
void glUniform4uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
static void (*a_glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform4uiv(GLint location, GLsizei count, const GLuint *value) { if (mglshim_active && p_glUniform4uiv) { p_glUniform4uiv(location, count, value); return; } if (a_glUniform4uiv) a_glUniform4uiv(location, count, value); }
INTERPOSE(glUniform4uiv)
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) WEAKGL;
static void (*p_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
static void (*a_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
static void w_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { if (mglshim_active && p_glUniformBlockBinding) { p_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); return; } if (a_glUniformBlockBinding) a_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
INTERPOSE(glUniformBlockBinding)
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix2dv) { p_glUniformMatrix2dv(location, count, transpose, value); return; } if (a_glUniformMatrix2dv) a_glUniformMatrix2dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2dv)
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix2fv) { p_glUniformMatrix2fv(location, count, transpose, value); return; } if (a_glUniformMatrix2fv) a_glUniformMatrix2fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2fv)
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix2x3dv) { p_glUniformMatrix2x3dv(location, count, transpose, value); return; } if (a_glUniformMatrix2x3dv) a_glUniformMatrix2x3dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x3dv)
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix2x3fv) { p_glUniformMatrix2x3fv(location, count, transpose, value); return; } if (a_glUniformMatrix2x3fv) a_glUniformMatrix2x3fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x3fv)
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix2x4dv) { p_glUniformMatrix2x4dv(location, count, transpose, value); return; } if (a_glUniformMatrix2x4dv) a_glUniformMatrix2x4dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x4dv)
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix2x4fv) { p_glUniformMatrix2x4fv(location, count, transpose, value); return; } if (a_glUniformMatrix2x4fv) a_glUniformMatrix2x4fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x4fv)
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix3dv) { p_glUniformMatrix3dv(location, count, transpose, value); return; } if (a_glUniformMatrix3dv) a_glUniformMatrix3dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3dv)
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix3fv) { p_glUniformMatrix3fv(location, count, transpose, value); return; } if (a_glUniformMatrix3fv) a_glUniformMatrix3fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3fv)
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix3x2dv) { p_glUniformMatrix3x2dv(location, count, transpose, value); return; } if (a_glUniformMatrix3x2dv) a_glUniformMatrix3x2dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x2dv)
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix3x2fv) { p_glUniformMatrix3x2fv(location, count, transpose, value); return; } if (a_glUniformMatrix3x2fv) a_glUniformMatrix3x2fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x2fv)
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix3x4dv) { p_glUniformMatrix3x4dv(location, count, transpose, value); return; } if (a_glUniformMatrix3x4dv) a_glUniformMatrix3x4dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x4dv)
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix3x4fv) { p_glUniformMatrix3x4fv(location, count, transpose, value); return; } if (a_glUniformMatrix3x4fv) a_glUniformMatrix3x4fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x4fv)
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix4dv) { p_glUniformMatrix4dv(location, count, transpose, value); return; } if (a_glUniformMatrix4dv) a_glUniformMatrix4dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4dv)
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix4fv) { p_glUniformMatrix4fv(location, count, transpose, value); return; } if (a_glUniformMatrix4fv) a_glUniformMatrix4fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4fv)
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix4x2dv) { p_glUniformMatrix4x2dv(location, count, transpose, value); return; } if (a_glUniformMatrix4x2dv) a_glUniformMatrix4x2dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x2dv)
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix4x2fv) { p_glUniformMatrix4x2fv(location, count, transpose, value); return; } if (a_glUniformMatrix4x2fv) a_glUniformMatrix4x2fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x2fv)
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void (*a_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (mglshim_active && p_glUniformMatrix4x3dv) { p_glUniformMatrix4x3dv(location, count, transpose, value); return; } if (a_glUniformMatrix4x3dv) a_glUniformMatrix4x3dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x3dv)
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void (*a_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (mglshim_active && p_glUniformMatrix4x3fv) { p_glUniformMatrix4x3fv(location, count, transpose, value); return; } if (a_glUniformMatrix4x3fv) a_glUniformMatrix4x3fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x3fv)
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) WEAKGL;
static void (*p_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
static void (*a_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
static void w_glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) { if (mglshim_active && p_glUniformSubroutinesuiv) { p_glUniformSubroutinesuiv(shadertype, count, indices); return; } if (a_glUniformSubroutinesuiv) a_glUniformSubroutinesuiv(shadertype, count, indices); }
INTERPOSE(glUniformSubroutinesuiv)
GLboolean glUnmapBuffer(GLenum target) WEAKGL;
static GLboolean (*p_glUnmapBuffer)(GLenum target);
static GLboolean (*a_glUnmapBuffer)(GLenum target);
static GLboolean w_glUnmapBuffer(GLenum target) { if (mglshim_active && p_glUnmapBuffer) return p_glUnmapBuffer(target); if (a_glUnmapBuffer) return a_glUnmapBuffer(target); return (GLboolean)0; }
INTERPOSE(glUnmapBuffer)
GLboolean glUnmapNamedBuffer(GLuint buffer) WEAKGL;
static GLboolean (*p_glUnmapNamedBuffer)(GLuint buffer);
static GLboolean (*a_glUnmapNamedBuffer)(GLuint buffer);
static GLboolean w_glUnmapNamedBuffer(GLuint buffer) { if (mglshim_active && p_glUnmapNamedBuffer) return p_glUnmapNamedBuffer(buffer); if (a_glUnmapNamedBuffer) return a_glUnmapNamedBuffer(buffer); return (GLboolean)0; }
INTERPOSE(glUnmapNamedBuffer)
void glUseProgram(GLuint program) WEAKGL;
static void (*p_glUseProgram)(GLuint program);
static void (*a_glUseProgram)(GLuint program);
static void w_glUseProgram(GLuint program) { if (mglshim_active && p_glUseProgram) { p_glUseProgram(program); return; } if (a_glUseProgram) a_glUseProgram(program); }
INTERPOSE(glUseProgram)
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) WEAKGL;
static void (*p_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
static void (*a_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
static void w_glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { if (mglshim_active && p_glUseProgramStages) { p_glUseProgramStages(pipeline, stages, program); return; } if (a_glUseProgramStages) a_glUseProgramStages(pipeline, stages, program); }
INTERPOSE(glUseProgramStages)
void glValidateProgram(GLuint program) WEAKGL;
static void (*p_glValidateProgram)(GLuint program);
static void (*a_glValidateProgram)(GLuint program);
static void w_glValidateProgram(GLuint program) { if (mglshim_active && p_glValidateProgram) { p_glValidateProgram(program); return; } if (a_glValidateProgram) a_glValidateProgram(program); }
INTERPOSE(glValidateProgram)
void glValidateProgramPipeline(GLuint pipeline) WEAKGL;
static void (*p_glValidateProgramPipeline)(GLuint pipeline);
static void (*a_glValidateProgramPipeline)(GLuint pipeline);
static void w_glValidateProgramPipeline(GLuint pipeline) { if (mglshim_active && p_glValidateProgramPipeline) { p_glValidateProgramPipeline(pipeline); return; } if (a_glValidateProgramPipeline) a_glValidateProgramPipeline(pipeline); }
INTERPOSE(glValidateProgramPipeline)
void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) WEAKGL;
static void (*p_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
static void (*a_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
static void w_glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) { if (mglshim_active && p_glVertexArrayAttribBinding) { p_glVertexArrayAttribBinding(vaobj, attribindex, bindingindex); return; } if (a_glVertexArrayAttribBinding) a_glVertexArrayAttribBinding(vaobj, attribindex, bindingindex); }
INTERPOSE(glVertexArrayAttribBinding)
void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
static void (*a_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
static void w_glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { if (mglshim_active && p_glVertexArrayAttribFormat) { p_glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset); return; } if (a_glVertexArrayAttribFormat) a_glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset); }
INTERPOSE(glVertexArrayAttribFormat)
void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void (*a_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (mglshim_active && p_glVertexArrayAttribIFormat) { p_glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset); return; } if (a_glVertexArrayAttribIFormat) a_glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexArrayAttribIFormat)
void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void (*a_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (mglshim_active && p_glVertexArrayAttribLFormat) { p_glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset); return; } if (a_glVertexArrayAttribLFormat) a_glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexArrayAttribLFormat)
void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) WEAKGL;
static void (*p_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
static void (*a_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
static void w_glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) { if (mglshim_active && p_glVertexArrayBindingDivisor) { p_glVertexArrayBindingDivisor(vaobj, bindingindex, divisor); return; } if (a_glVertexArrayBindingDivisor) a_glVertexArrayBindingDivisor(vaobj, bindingindex, divisor); }
INTERPOSE(glVertexArrayBindingDivisor)
void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) WEAKGL;
static void (*p_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
static void (*a_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
static void w_glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) { if (mglshim_active && p_glVertexArrayElementBuffer) { p_glVertexArrayElementBuffer(vaobj, buffer); return; } if (a_glVertexArrayElementBuffer) a_glVertexArrayElementBuffer(vaobj, buffer); }
INTERPOSE(glVertexArrayElementBuffer)
void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) WEAKGL;
static void (*p_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
static void (*a_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
static void w_glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { if (mglshim_active && p_glVertexArrayVertexBuffer) { p_glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride); return; } if (a_glVertexArrayVertexBuffer) a_glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride); }
INTERPOSE(glVertexArrayVertexBuffer)
void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) WEAKGL;
static void (*p_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
static void (*a_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
static void w_glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { if (mglshim_active && p_glVertexArrayVertexBuffers) { p_glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides); return; } if (a_glVertexArrayVertexBuffers) a_glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides); }
INTERPOSE(glVertexArrayVertexBuffers)
void glVertexAttrib1d(GLuint index, GLdouble x) WEAKGL;
static void (*p_glVertexAttrib1d)(GLuint index, GLdouble x);
static void (*a_glVertexAttrib1d)(GLuint index, GLdouble x);
static void w_glVertexAttrib1d(GLuint index, GLdouble x) { if (mglshim_active && p_glVertexAttrib1d) { p_glVertexAttrib1d(index, x); return; } if (a_glVertexAttrib1d) a_glVertexAttrib1d(index, x); }
INTERPOSE(glVertexAttrib1d)
void glVertexAttrib1dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib1dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttrib1dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib1dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttrib1dv) { p_glVertexAttrib1dv(index, v); return; } if (a_glVertexAttrib1dv) a_glVertexAttrib1dv(index, v); }
INTERPOSE(glVertexAttrib1dv)
void glVertexAttrib1f(GLuint index, GLfloat x) WEAKGL;
static void (*p_glVertexAttrib1f)(GLuint index, GLfloat x);
static void (*a_glVertexAttrib1f)(GLuint index, GLfloat x);
static void w_glVertexAttrib1f(GLuint index, GLfloat x) { if (mglshim_active && p_glVertexAttrib1f) { p_glVertexAttrib1f(index, x); return; } if (a_glVertexAttrib1f) a_glVertexAttrib1f(index, x); }
INTERPOSE(glVertexAttrib1f)
void glVertexAttrib1fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib1fv)(GLuint index, const GLfloat *v);
static void (*a_glVertexAttrib1fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib1fv(GLuint index, const GLfloat *v) { if (mglshim_active && p_glVertexAttrib1fv) { p_glVertexAttrib1fv(index, v); return; } if (a_glVertexAttrib1fv) a_glVertexAttrib1fv(index, v); }
INTERPOSE(glVertexAttrib1fv)
void glVertexAttrib1s(GLuint index, GLshort x) WEAKGL;
static void (*p_glVertexAttrib1s)(GLuint index, GLshort x);
static void (*a_glVertexAttrib1s)(GLuint index, GLshort x);
static void w_glVertexAttrib1s(GLuint index, GLshort x) { if (mglshim_active && p_glVertexAttrib1s) { p_glVertexAttrib1s(index, x); return; } if (a_glVertexAttrib1s) a_glVertexAttrib1s(index, x); }
INTERPOSE(glVertexAttrib1s)
void glVertexAttrib1sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib1sv)(GLuint index, const GLshort *v);
static void (*a_glVertexAttrib1sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib1sv(GLuint index, const GLshort *v) { if (mglshim_active && p_glVertexAttrib1sv) { p_glVertexAttrib1sv(index, v); return; } if (a_glVertexAttrib1sv) a_glVertexAttrib1sv(index, v); }
INTERPOSE(glVertexAttrib1sv)
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) WEAKGL;
static void (*p_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
static void (*a_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
static void w_glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { if (mglshim_active && p_glVertexAttrib2d) { p_glVertexAttrib2d(index, x, y); return; } if (a_glVertexAttrib2d) a_glVertexAttrib2d(index, x, y); }
INTERPOSE(glVertexAttrib2d)
void glVertexAttrib2dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib2dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttrib2dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib2dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttrib2dv) { p_glVertexAttrib2dv(index, v); return; } if (a_glVertexAttrib2dv) a_glVertexAttrib2dv(index, v); }
INTERPOSE(glVertexAttrib2dv)
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) WEAKGL;
static void (*p_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
static void (*a_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
static void w_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { if (mglshim_active && p_glVertexAttrib2f) { p_glVertexAttrib2f(index, x, y); return; } if (a_glVertexAttrib2f) a_glVertexAttrib2f(index, x, y); }
INTERPOSE(glVertexAttrib2f)
void glVertexAttrib2fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib2fv)(GLuint index, const GLfloat *v);
static void (*a_glVertexAttrib2fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib2fv(GLuint index, const GLfloat *v) { if (mglshim_active && p_glVertexAttrib2fv) { p_glVertexAttrib2fv(index, v); return; } if (a_glVertexAttrib2fv) a_glVertexAttrib2fv(index, v); }
INTERPOSE(glVertexAttrib2fv)
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) WEAKGL;
static void (*p_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
static void (*a_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
static void w_glVertexAttrib2s(GLuint index, GLshort x, GLshort y) { if (mglshim_active && p_glVertexAttrib2s) { p_glVertexAttrib2s(index, x, y); return; } if (a_glVertexAttrib2s) a_glVertexAttrib2s(index, x, y); }
INTERPOSE(glVertexAttrib2s)
void glVertexAttrib2sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib2sv)(GLuint index, const GLshort *v);
static void (*a_glVertexAttrib2sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib2sv(GLuint index, const GLshort *v) { if (mglshim_active && p_glVertexAttrib2sv) { p_glVertexAttrib2sv(index, v); return; } if (a_glVertexAttrib2sv) a_glVertexAttrib2sv(index, v); }
INTERPOSE(glVertexAttrib2sv)
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void (*a_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void w_glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glVertexAttrib3d) { p_glVertexAttrib3d(index, x, y, z); return; } if (a_glVertexAttrib3d) a_glVertexAttrib3d(index, x, y, z); }
INTERPOSE(glVertexAttrib3d)
void glVertexAttrib3dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib3dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttrib3dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib3dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttrib3dv) { p_glVertexAttrib3dv(index, v); return; } if (a_glVertexAttrib3dv) a_glVertexAttrib3dv(index, v); }
INTERPOSE(glVertexAttrib3dv)
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
static void (*a_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
static void w_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glVertexAttrib3f) { p_glVertexAttrib3f(index, x, y, z); return; } if (a_glVertexAttrib3f) a_glVertexAttrib3f(index, x, y, z); }
INTERPOSE(glVertexAttrib3f)
void glVertexAttrib3fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib3fv)(GLuint index, const GLfloat *v);
static void (*a_glVertexAttrib3fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib3fv(GLuint index, const GLfloat *v) { if (mglshim_active && p_glVertexAttrib3fv) { p_glVertexAttrib3fv(index, v); return; } if (a_glVertexAttrib3fv) a_glVertexAttrib3fv(index, v); }
INTERPOSE(glVertexAttrib3fv)
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
static void (*a_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
static void w_glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { if (mglshim_active && p_glVertexAttrib3s) { p_glVertexAttrib3s(index, x, y, z); return; } if (a_glVertexAttrib3s) a_glVertexAttrib3s(index, x, y, z); }
INTERPOSE(glVertexAttrib3s)
void glVertexAttrib3sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib3sv)(GLuint index, const GLshort *v);
static void (*a_glVertexAttrib3sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib3sv(GLuint index, const GLshort *v) { if (mglshim_active && p_glVertexAttrib3sv) { p_glVertexAttrib3sv(index, v); return; } if (a_glVertexAttrib3sv) a_glVertexAttrib3sv(index, v); }
INTERPOSE(glVertexAttrib3sv)
void glVertexAttrib4Nbv(GLuint index, const GLbyte *v) WEAKGL;
static void (*p_glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
static void (*a_glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
static void w_glVertexAttrib4Nbv(GLuint index, const GLbyte *v) { if (mglshim_active && p_glVertexAttrib4Nbv) { p_glVertexAttrib4Nbv(index, v); return; } if (a_glVertexAttrib4Nbv) a_glVertexAttrib4Nbv(index, v); }
INTERPOSE(glVertexAttrib4Nbv)
void glVertexAttrib4Niv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttrib4Niv)(GLuint index, const GLint *v);
static void (*a_glVertexAttrib4Niv)(GLuint index, const GLint *v);
static void w_glVertexAttrib4Niv(GLuint index, const GLint *v) { if (mglshim_active && p_glVertexAttrib4Niv) { p_glVertexAttrib4Niv(index, v); return; } if (a_glVertexAttrib4Niv) a_glVertexAttrib4Niv(index, v); }
INTERPOSE(glVertexAttrib4Niv)
void glVertexAttrib4Nsv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
static void (*a_glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib4Nsv(GLuint index, const GLshort *v) { if (mglshim_active && p_glVertexAttrib4Nsv) { p_glVertexAttrib4Nsv(index, v); return; } if (a_glVertexAttrib4Nsv) a_glVertexAttrib4Nsv(index, v); }
INTERPOSE(glVertexAttrib4Nsv)
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) WEAKGL;
static void (*p_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
static void (*a_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
static void w_glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { if (mglshim_active && p_glVertexAttrib4Nub) { p_glVertexAttrib4Nub(index, x, y, z, w); return; } if (a_glVertexAttrib4Nub) a_glVertexAttrib4Nub(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4Nub)
void glVertexAttrib4Nubv(GLuint index, const GLubyte *v) WEAKGL;
static void (*p_glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
static void (*a_glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
static void w_glVertexAttrib4Nubv(GLuint index, const GLubyte *v) { if (mglshim_active && p_glVertexAttrib4Nubv) { p_glVertexAttrib4Nubv(index, v); return; } if (a_glVertexAttrib4Nubv) a_glVertexAttrib4Nubv(index, v); }
INTERPOSE(glVertexAttrib4Nubv)
void glVertexAttrib4Nuiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
static void (*a_glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
static void w_glVertexAttrib4Nuiv(GLuint index, const GLuint *v) { if (mglshim_active && p_glVertexAttrib4Nuiv) { p_glVertexAttrib4Nuiv(index, v); return; } if (a_glVertexAttrib4Nuiv) a_glVertexAttrib4Nuiv(index, v); }
INTERPOSE(glVertexAttrib4Nuiv)
void glVertexAttrib4Nusv(GLuint index, const GLushort *v) WEAKGL;
static void (*p_glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
static void (*a_glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
static void w_glVertexAttrib4Nusv(GLuint index, const GLushort *v) { if (mglshim_active && p_glVertexAttrib4Nusv) { p_glVertexAttrib4Nusv(index, v); return; } if (a_glVertexAttrib4Nusv) a_glVertexAttrib4Nusv(index, v); }
INTERPOSE(glVertexAttrib4Nusv)
void glVertexAttrib4bv(GLuint index, const GLbyte *v) WEAKGL;
static void (*p_glVertexAttrib4bv)(GLuint index, const GLbyte *v);
static void (*a_glVertexAttrib4bv)(GLuint index, const GLbyte *v);
static void w_glVertexAttrib4bv(GLuint index, const GLbyte *v) { if (mglshim_active && p_glVertexAttrib4bv) { p_glVertexAttrib4bv(index, v); return; } if (a_glVertexAttrib4bv) a_glVertexAttrib4bv(index, v); }
INTERPOSE(glVertexAttrib4bv)
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*a_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (mglshim_active && p_glVertexAttrib4d) { p_glVertexAttrib4d(index, x, y, z, w); return; } if (a_glVertexAttrib4d) a_glVertexAttrib4d(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4d)
void glVertexAttrib4dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib4dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttrib4dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib4dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttrib4dv) { p_glVertexAttrib4dv(index, v); return; } if (a_glVertexAttrib4dv) a_glVertexAttrib4dv(index, v); }
INTERPOSE(glVertexAttrib4dv)
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) WEAKGL;
static void (*p_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*a_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void w_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if (mglshim_active && p_glVertexAttrib4f) { p_glVertexAttrib4f(index, x, y, z, w); return; } if (a_glVertexAttrib4f) a_glVertexAttrib4f(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4f)
void glVertexAttrib4fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib4fv)(GLuint index, const GLfloat *v);
static void (*a_glVertexAttrib4fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib4fv(GLuint index, const GLfloat *v) { if (mglshim_active && p_glVertexAttrib4fv) { p_glVertexAttrib4fv(index, v); return; } if (a_glVertexAttrib4fv) a_glVertexAttrib4fv(index, v); }
INTERPOSE(glVertexAttrib4fv)
void glVertexAttrib4iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttrib4iv)(GLuint index, const GLint *v);
static void (*a_glVertexAttrib4iv)(GLuint index, const GLint *v);
static void w_glVertexAttrib4iv(GLuint index, const GLint *v) { if (mglshim_active && p_glVertexAttrib4iv) { p_glVertexAttrib4iv(index, v); return; } if (a_glVertexAttrib4iv) a_glVertexAttrib4iv(index, v); }
INTERPOSE(glVertexAttrib4iv)
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) WEAKGL;
static void (*p_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
static void (*a_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
static void w_glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { if (mglshim_active && p_glVertexAttrib4s) { p_glVertexAttrib4s(index, x, y, z, w); return; } if (a_glVertexAttrib4s) a_glVertexAttrib4s(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4s)
void glVertexAttrib4sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib4sv)(GLuint index, const GLshort *v);
static void (*a_glVertexAttrib4sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib4sv(GLuint index, const GLshort *v) { if (mglshim_active && p_glVertexAttrib4sv) { p_glVertexAttrib4sv(index, v); return; } if (a_glVertexAttrib4sv) a_glVertexAttrib4sv(index, v); }
INTERPOSE(glVertexAttrib4sv)
void glVertexAttrib4ubv(GLuint index, const GLubyte *v) WEAKGL;
static void (*p_glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
static void (*a_glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
static void w_glVertexAttrib4ubv(GLuint index, const GLubyte *v) { if (mglshim_active && p_glVertexAttrib4ubv) { p_glVertexAttrib4ubv(index, v); return; } if (a_glVertexAttrib4ubv) a_glVertexAttrib4ubv(index, v); }
INTERPOSE(glVertexAttrib4ubv)
void glVertexAttrib4uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttrib4uiv)(GLuint index, const GLuint *v);
static void (*a_glVertexAttrib4uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttrib4uiv(GLuint index, const GLuint *v) { if (mglshim_active && p_glVertexAttrib4uiv) { p_glVertexAttrib4uiv(index, v); return; } if (a_glVertexAttrib4uiv) a_glVertexAttrib4uiv(index, v); }
INTERPOSE(glVertexAttrib4uiv)
void glVertexAttrib4usv(GLuint index, const GLushort *v) WEAKGL;
static void (*p_glVertexAttrib4usv)(GLuint index, const GLushort *v);
static void (*a_glVertexAttrib4usv)(GLuint index, const GLushort *v);
static void w_glVertexAttrib4usv(GLuint index, const GLushort *v) { if (mglshim_active && p_glVertexAttrib4usv) { p_glVertexAttrib4usv(index, v); return; } if (a_glVertexAttrib4usv) a_glVertexAttrib4usv(index, v); }
INTERPOSE(glVertexAttrib4usv)
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) WEAKGL;
static void (*p_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
static void (*a_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
static void w_glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { if (mglshim_active && p_glVertexAttribBinding) { p_glVertexAttribBinding(attribindex, bindingindex); return; } if (a_glVertexAttribBinding) a_glVertexAttribBinding(attribindex, bindingindex); }
INTERPOSE(glVertexAttribBinding)
void glVertexAttribDivisor(GLuint index, GLuint divisor) WEAKGL;
static void (*p_glVertexAttribDivisor)(GLuint index, GLuint divisor);
static void (*a_glVertexAttribDivisor)(GLuint index, GLuint divisor);
static void w_glVertexAttribDivisor(GLuint index, GLuint divisor) { if (mglshim_active && p_glVertexAttribDivisor) { p_glVertexAttribDivisor(index, divisor); return; } if (a_glVertexAttribDivisor) a_glVertexAttribDivisor(index, divisor); }
INTERPOSE(glVertexAttribDivisor)
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
static void (*a_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
static void w_glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { if (mglshim_active && p_glVertexAttribFormat) { p_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); return; } if (a_glVertexAttribFormat) a_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); }
INTERPOSE(glVertexAttribFormat)
void glVertexAttribI1i(GLuint index, GLint x) WEAKGL;
static void (*p_glVertexAttribI1i)(GLuint index, GLint x);
static void (*a_glVertexAttribI1i)(GLuint index, GLint x);
static void w_glVertexAttribI1i(GLuint index, GLint x) { if (mglshim_active && p_glVertexAttribI1i) { p_glVertexAttribI1i(index, x); return; } if (a_glVertexAttribI1i) a_glVertexAttribI1i(index, x); }
INTERPOSE(glVertexAttribI1i)
void glVertexAttribI1iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI1iv)(GLuint index, const GLint *v);
static void (*a_glVertexAttribI1iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI1iv(GLuint index, const GLint *v) { if (mglshim_active && p_glVertexAttribI1iv) { p_glVertexAttribI1iv(index, v); return; } if (a_glVertexAttribI1iv) a_glVertexAttribI1iv(index, v); }
INTERPOSE(glVertexAttribI1iv)
void glVertexAttribI1ui(GLuint index, GLuint x) WEAKGL;
static void (*p_glVertexAttribI1ui)(GLuint index, GLuint x);
static void (*a_glVertexAttribI1ui)(GLuint index, GLuint x);
static void w_glVertexAttribI1ui(GLuint index, GLuint x) { if (mglshim_active && p_glVertexAttribI1ui) { p_glVertexAttribI1ui(index, x); return; } if (a_glVertexAttribI1ui) a_glVertexAttribI1ui(index, x); }
INTERPOSE(glVertexAttribI1ui)
void glVertexAttribI1uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI1uiv)(GLuint index, const GLuint *v);
static void (*a_glVertexAttribI1uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI1uiv(GLuint index, const GLuint *v) { if (mglshim_active && p_glVertexAttribI1uiv) { p_glVertexAttribI1uiv(index, v); return; } if (a_glVertexAttribI1uiv) a_glVertexAttribI1uiv(index, v); }
INTERPOSE(glVertexAttribI1uiv)
void glVertexAttribI2i(GLuint index, GLint x, GLint y) WEAKGL;
static void (*p_glVertexAttribI2i)(GLuint index, GLint x, GLint y);
static void (*a_glVertexAttribI2i)(GLuint index, GLint x, GLint y);
static void w_glVertexAttribI2i(GLuint index, GLint x, GLint y) { if (mglshim_active && p_glVertexAttribI2i) { p_glVertexAttribI2i(index, x, y); return; } if (a_glVertexAttribI2i) a_glVertexAttribI2i(index, x, y); }
INTERPOSE(glVertexAttribI2i)
void glVertexAttribI2iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI2iv)(GLuint index, const GLint *v);
static void (*a_glVertexAttribI2iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI2iv(GLuint index, const GLint *v) { if (mglshim_active && p_glVertexAttribI2iv) { p_glVertexAttribI2iv(index, v); return; } if (a_glVertexAttribI2iv) a_glVertexAttribI2iv(index, v); }
INTERPOSE(glVertexAttribI2iv)
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) WEAKGL;
static void (*p_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
static void (*a_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
static void w_glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) { if (mglshim_active && p_glVertexAttribI2ui) { p_glVertexAttribI2ui(index, x, y); return; } if (a_glVertexAttribI2ui) a_glVertexAttribI2ui(index, x, y); }
INTERPOSE(glVertexAttribI2ui)
void glVertexAttribI2uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI2uiv)(GLuint index, const GLuint *v);
static void (*a_glVertexAttribI2uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI2uiv(GLuint index, const GLuint *v) { if (mglshim_active && p_glVertexAttribI2uiv) { p_glVertexAttribI2uiv(index, v); return; } if (a_glVertexAttribI2uiv) a_glVertexAttribI2uiv(index, v); }
INTERPOSE(glVertexAttribI2uiv)
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
static void (*a_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
static void w_glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { if (mglshim_active && p_glVertexAttribI3i) { p_glVertexAttribI3i(index, x, y, z); return; } if (a_glVertexAttribI3i) a_glVertexAttribI3i(index, x, y, z); }
INTERPOSE(glVertexAttribI3i)
void glVertexAttribI3iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI3iv)(GLuint index, const GLint *v);
static void (*a_glVertexAttribI3iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI3iv(GLuint index, const GLint *v) { if (mglshim_active && p_glVertexAttribI3iv) { p_glVertexAttribI3iv(index, v); return; } if (a_glVertexAttribI3iv) a_glVertexAttribI3iv(index, v); }
INTERPOSE(glVertexAttribI3iv)
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) WEAKGL;
static void (*p_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
static void (*a_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
static void w_glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { if (mglshim_active && p_glVertexAttribI3ui) { p_glVertexAttribI3ui(index, x, y, z); return; } if (a_glVertexAttribI3ui) a_glVertexAttribI3ui(index, x, y, z); }
INTERPOSE(glVertexAttribI3ui)
void glVertexAttribI3uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI3uiv)(GLuint index, const GLuint *v);
static void (*a_glVertexAttribI3uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI3uiv(GLuint index, const GLuint *v) { if (mglshim_active && p_glVertexAttribI3uiv) { p_glVertexAttribI3uiv(index, v); return; } if (a_glVertexAttribI3uiv) a_glVertexAttribI3uiv(index, v); }
INTERPOSE(glVertexAttribI3uiv)
void glVertexAttribI4bv(GLuint index, const GLbyte *v) WEAKGL;
static void (*p_glVertexAttribI4bv)(GLuint index, const GLbyte *v);
static void (*a_glVertexAttribI4bv)(GLuint index, const GLbyte *v);
static void w_glVertexAttribI4bv(GLuint index, const GLbyte *v) { if (mglshim_active && p_glVertexAttribI4bv) { p_glVertexAttribI4bv(index, v); return; } if (a_glVertexAttribI4bv) a_glVertexAttribI4bv(index, v); }
INTERPOSE(glVertexAttribI4bv)
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) WEAKGL;
static void (*p_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
static void (*a_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
static void w_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { if (mglshim_active && p_glVertexAttribI4i) { p_glVertexAttribI4i(index, x, y, z, w); return; } if (a_glVertexAttribI4i) a_glVertexAttribI4i(index, x, y, z, w); }
INTERPOSE(glVertexAttribI4i)
void glVertexAttribI4iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI4iv)(GLuint index, const GLint *v);
static void (*a_glVertexAttribI4iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI4iv(GLuint index, const GLint *v) { if (mglshim_active && p_glVertexAttribI4iv) { p_glVertexAttribI4iv(index, v); return; } if (a_glVertexAttribI4iv) a_glVertexAttribI4iv(index, v); }
INTERPOSE(glVertexAttribI4iv)
void glVertexAttribI4sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttribI4sv)(GLuint index, const GLshort *v);
static void (*a_glVertexAttribI4sv)(GLuint index, const GLshort *v);
static void w_glVertexAttribI4sv(GLuint index, const GLshort *v) { if (mglshim_active && p_glVertexAttribI4sv) { p_glVertexAttribI4sv(index, v); return; } if (a_glVertexAttribI4sv) a_glVertexAttribI4sv(index, v); }
INTERPOSE(glVertexAttribI4sv)
void glVertexAttribI4ubv(GLuint index, const GLubyte *v) WEAKGL;
static void (*p_glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
static void (*a_glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
static void w_glVertexAttribI4ubv(GLuint index, const GLubyte *v) { if (mglshim_active && p_glVertexAttribI4ubv) { p_glVertexAttribI4ubv(index, v); return; } if (a_glVertexAttribI4ubv) a_glVertexAttribI4ubv(index, v); }
INTERPOSE(glVertexAttribI4ubv)
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) WEAKGL;
static void (*p_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
static void (*a_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
static void w_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { if (mglshim_active && p_glVertexAttribI4ui) { p_glVertexAttribI4ui(index, x, y, z, w); return; } if (a_glVertexAttribI4ui) a_glVertexAttribI4ui(index, x, y, z, w); }
INTERPOSE(glVertexAttribI4ui)
void glVertexAttribI4uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI4uiv)(GLuint index, const GLuint *v);
static void (*a_glVertexAttribI4uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI4uiv(GLuint index, const GLuint *v) { if (mglshim_active && p_glVertexAttribI4uiv) { p_glVertexAttribI4uiv(index, v); return; } if (a_glVertexAttribI4uiv) a_glVertexAttribI4uiv(index, v); }
INTERPOSE(glVertexAttribI4uiv)
void glVertexAttribI4usv(GLuint index, const GLushort *v) WEAKGL;
static void (*p_glVertexAttribI4usv)(GLuint index, const GLushort *v);
static void (*a_glVertexAttribI4usv)(GLuint index, const GLushort *v);
static void w_glVertexAttribI4usv(GLuint index, const GLushort *v) { if (mglshim_active && p_glVertexAttribI4usv) { p_glVertexAttribI4usv(index, v); return; } if (a_glVertexAttribI4usv) a_glVertexAttribI4usv(index, v); }
INTERPOSE(glVertexAttribI4usv)
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void (*a_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (mglshim_active && p_glVertexAttribIFormat) { p_glVertexAttribIFormat(attribindex, size, type, relativeoffset); return; } if (a_glVertexAttribIFormat) a_glVertexAttribIFormat(attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexAttribIFormat)
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*a_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glVertexAttribIPointer) { p_glVertexAttribIPointer(index, size, type, stride, pointer); return; } if (a_glVertexAttribIPointer) a_glVertexAttribIPointer(index, size, type, stride, pointer); }
INTERPOSE(glVertexAttribIPointer)
void glVertexAttribL1d(GLuint index, GLdouble x) WEAKGL;
static void (*p_glVertexAttribL1d)(GLuint index, GLdouble x);
static void (*a_glVertexAttribL1d)(GLuint index, GLdouble x);
static void w_glVertexAttribL1d(GLuint index, GLdouble x) { if (mglshim_active && p_glVertexAttribL1d) { p_glVertexAttribL1d(index, x); return; } if (a_glVertexAttribL1d) a_glVertexAttribL1d(index, x); }
INTERPOSE(glVertexAttribL1d)
void glVertexAttribL1dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL1dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttribL1dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL1dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttribL1dv) { p_glVertexAttribL1dv(index, v); return; } if (a_glVertexAttribL1dv) a_glVertexAttribL1dv(index, v); }
INTERPOSE(glVertexAttribL1dv)
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) WEAKGL;
static void (*p_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
static void (*a_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
static void w_glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) { if (mglshim_active && p_glVertexAttribL2d) { p_glVertexAttribL2d(index, x, y); return; } if (a_glVertexAttribL2d) a_glVertexAttribL2d(index, x, y); }
INTERPOSE(glVertexAttribL2d)
void glVertexAttribL2dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL2dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttribL2dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL2dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttribL2dv) { p_glVertexAttribL2dv(index, v); return; } if (a_glVertexAttribL2dv) a_glVertexAttribL2dv(index, v); }
INTERPOSE(glVertexAttribL2dv)
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void (*a_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void w_glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glVertexAttribL3d) { p_glVertexAttribL3d(index, x, y, z); return; } if (a_glVertexAttribL3d) a_glVertexAttribL3d(index, x, y, z); }
INTERPOSE(glVertexAttribL3d)
void glVertexAttribL3dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL3dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttribL3dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL3dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttribL3dv) { p_glVertexAttribL3dv(index, v); return; } if (a_glVertexAttribL3dv) a_glVertexAttribL3dv(index, v); }
INTERPOSE(glVertexAttribL3dv)
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*a_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (mglshim_active && p_glVertexAttribL4d) { p_glVertexAttribL4d(index, x, y, z, w); return; } if (a_glVertexAttribL4d) a_glVertexAttribL4d(index, x, y, z, w); }
INTERPOSE(glVertexAttribL4d)
void glVertexAttribL4dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL4dv)(GLuint index, const GLdouble *v);
static void (*a_glVertexAttribL4dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL4dv(GLuint index, const GLdouble *v) { if (mglshim_active && p_glVertexAttribL4dv) { p_glVertexAttribL4dv(index, v); return; } if (a_glVertexAttribL4dv) a_glVertexAttribL4dv(index, v); }
INTERPOSE(glVertexAttribL4dv)
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void (*a_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (mglshim_active && p_glVertexAttribLFormat) { p_glVertexAttribLFormat(attribindex, size, type, relativeoffset); return; } if (a_glVertexAttribLFormat) a_glVertexAttribLFormat(attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexAttribLFormat)
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*a_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glVertexAttribLPointer) { p_glVertexAttribLPointer(index, size, type, stride, pointer); return; } if (a_glVertexAttribLPointer) a_glVertexAttribLPointer(index, size, type, stride, pointer); }
INTERPOSE(glVertexAttribLPointer)
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*a_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (mglshim_active && p_glVertexAttribP1ui) { p_glVertexAttribP1ui(index, type, normalized, value); return; } if (a_glVertexAttribP1ui) a_glVertexAttribP1ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP1ui)
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*a_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (mglshim_active && p_glVertexAttribP1uiv) { p_glVertexAttribP1uiv(index, type, normalized, value); return; } if (a_glVertexAttribP1uiv) a_glVertexAttribP1uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP1uiv)
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*a_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (mglshim_active && p_glVertexAttribP2ui) { p_glVertexAttribP2ui(index, type, normalized, value); return; } if (a_glVertexAttribP2ui) a_glVertexAttribP2ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP2ui)
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*a_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (mglshim_active && p_glVertexAttribP2uiv) { p_glVertexAttribP2uiv(index, type, normalized, value); return; } if (a_glVertexAttribP2uiv) a_glVertexAttribP2uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP2uiv)
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*a_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (mglshim_active && p_glVertexAttribP3ui) { p_glVertexAttribP3ui(index, type, normalized, value); return; } if (a_glVertexAttribP3ui) a_glVertexAttribP3ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP3ui)
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*a_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (mglshim_active && p_glVertexAttribP3uiv) { p_glVertexAttribP3uiv(index, type, normalized, value); return; } if (a_glVertexAttribP3uiv) a_glVertexAttribP3uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP3uiv)
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void (*a_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (mglshim_active && p_glVertexAttribP4ui) { p_glVertexAttribP4ui(index, type, normalized, value); return; } if (a_glVertexAttribP4ui) a_glVertexAttribP4ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP4ui)
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void (*a_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (mglshim_active && p_glVertexAttribP4uiv) { p_glVertexAttribP4uiv(index, type, normalized, value); return; } if (a_glVertexAttribP4uiv) a_glVertexAttribP4uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP4uiv)
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
static void (*a_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
static void w_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) { if (mglshim_active && p_glVertexAttribPointer) { p_glVertexAttribPointer(index, size, type, normalized, stride, pointer); return; } if (a_glVertexAttribPointer) a_glVertexAttribPointer(index, size, type, normalized, stride, pointer); }
INTERPOSE(glVertexAttribPointer)
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) WEAKGL;
static void (*p_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
static void (*a_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
static void w_glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { if (mglshim_active && p_glVertexBindingDivisor) { p_glVertexBindingDivisor(bindingindex, divisor); return; } if (a_glVertexBindingDivisor) a_glVertexBindingDivisor(bindingindex, divisor); }
INTERPOSE(glVertexBindingDivisor)
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
static void (*a_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { if (mglshim_active && p_glViewport) { p_glViewport(x, y, width, height); return; } if (a_glViewport) a_glViewport(x, y, width, height); }
INTERPOSE(glViewport)
void glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) WEAKGL;
static void (*p_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
static void (*a_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
static void w_glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) { if (mglshim_active && p_glViewportArrayv) { p_glViewportArrayv(first, count, v); return; } if (a_glViewportArrayv) a_glViewportArrayv(first, count, v); }
INTERPOSE(glViewportArrayv)
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) WEAKGL;
static void (*p_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
static void (*a_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
static void w_glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) { if (mglshim_active && p_glViewportIndexedf) { p_glViewportIndexedf(index, x, y, w, h); return; } if (a_glViewportIndexedf) a_glViewportIndexedf(index, x, y, w, h); }
INTERPOSE(glViewportIndexedf)
void glViewportIndexedfv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glViewportIndexedfv)(GLuint index, const GLfloat *v);
static void (*a_glViewportIndexedfv)(GLuint index, const GLfloat *v);
static void w_glViewportIndexedfv(GLuint index, const GLfloat *v) { if (mglshim_active && p_glViewportIndexedfv) { p_glViewportIndexedfv(index, v); return; } if (a_glViewportIndexedfv) a_glViewportIndexedfv(index, v); }
INTERPOSE(glViewportIndexedfv)
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) WEAKGL;
static void (*p_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
static void (*a_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
static void w_glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { if (mglshim_active && p_glWaitSync) { p_glWaitSync(sync, flags, timeout); return; } if (a_glWaitSync) a_glWaitSync(sync, flags, timeout); }
INTERPOSE(glWaitSync)

/* mgl = libmgl.dylib (impl do MGL). a_* = a função REAL da Apple, via RTLD_NEXT (pula este interpositor, */
/* senão dlsym devolveria o próprio wrapper e recursionaria). Devolve quantas gl* o MGL tem. */
int mglshim_gl_init(void *mgl) {
    int n = 0;
    *(void **)&p_glActiveShaderProgram = dlsym(mgl, "glActiveShaderProgram"); *(void **)&a_glActiveShaderProgram = dlsym(RTLD_NEXT, "glActiveShaderProgram"); if (p_glActiveShaderProgram) n++;
    *(void **)&p_glActiveTexture = dlsym(mgl, "glActiveTexture"); *(void **)&a_glActiveTexture = dlsym(RTLD_NEXT, "glActiveTexture"); if (p_glActiveTexture) n++;
    *(void **)&p_glAttachShader = dlsym(mgl, "glAttachShader"); *(void **)&a_glAttachShader = dlsym(RTLD_NEXT, "glAttachShader"); if (p_glAttachShader) n++;
    *(void **)&p_glBeginConditionalRender = dlsym(mgl, "glBeginConditionalRender"); *(void **)&a_glBeginConditionalRender = dlsym(RTLD_NEXT, "glBeginConditionalRender"); if (p_glBeginConditionalRender) n++;
    *(void **)&p_glBeginQuery = dlsym(mgl, "glBeginQuery"); *(void **)&a_glBeginQuery = dlsym(RTLD_NEXT, "glBeginQuery"); if (p_glBeginQuery) n++;
    *(void **)&p_glBeginQueryIndexed = dlsym(mgl, "glBeginQueryIndexed"); *(void **)&a_glBeginQueryIndexed = dlsym(RTLD_NEXT, "glBeginQueryIndexed"); if (p_glBeginQueryIndexed) n++;
    *(void **)&p_glBeginTransformFeedback = dlsym(mgl, "glBeginTransformFeedback"); *(void **)&a_glBeginTransformFeedback = dlsym(RTLD_NEXT, "glBeginTransformFeedback"); if (p_glBeginTransformFeedback) n++;
    *(void **)&p_glBindAttribLocation = dlsym(mgl, "glBindAttribLocation"); *(void **)&a_glBindAttribLocation = dlsym(RTLD_NEXT, "glBindAttribLocation"); if (p_glBindAttribLocation) n++;
    *(void **)&p_glBindBuffer = dlsym(mgl, "glBindBuffer"); *(void **)&a_glBindBuffer = dlsym(RTLD_NEXT, "glBindBuffer"); if (p_glBindBuffer) n++;
    *(void **)&p_glBindBufferBase = dlsym(mgl, "glBindBufferBase"); *(void **)&a_glBindBufferBase = dlsym(RTLD_NEXT, "glBindBufferBase"); if (p_glBindBufferBase) n++;
    *(void **)&p_glBindBufferRange = dlsym(mgl, "glBindBufferRange"); *(void **)&a_glBindBufferRange = dlsym(RTLD_NEXT, "glBindBufferRange"); if (p_glBindBufferRange) n++;
    *(void **)&p_glBindBuffersBase = dlsym(mgl, "glBindBuffersBase"); *(void **)&a_glBindBuffersBase = dlsym(RTLD_NEXT, "glBindBuffersBase"); if (p_glBindBuffersBase) n++;
    *(void **)&p_glBindBuffersRange = dlsym(mgl, "glBindBuffersRange"); *(void **)&a_glBindBuffersRange = dlsym(RTLD_NEXT, "glBindBuffersRange"); if (p_glBindBuffersRange) n++;
    *(void **)&p_glBindFragDataLocation = dlsym(mgl, "glBindFragDataLocation"); *(void **)&a_glBindFragDataLocation = dlsym(RTLD_NEXT, "glBindFragDataLocation"); if (p_glBindFragDataLocation) n++;
    *(void **)&p_glBindFragDataLocationIndexed = dlsym(mgl, "glBindFragDataLocationIndexed"); *(void **)&a_glBindFragDataLocationIndexed = dlsym(RTLD_NEXT, "glBindFragDataLocationIndexed"); if (p_glBindFragDataLocationIndexed) n++;
    *(void **)&p_glBindFramebuffer = dlsym(mgl, "glBindFramebuffer"); *(void **)&a_glBindFramebuffer = dlsym(RTLD_NEXT, "glBindFramebuffer"); if (p_glBindFramebuffer) n++;
    *(void **)&p_glBindImageTexture = dlsym(mgl, "glBindImageTexture"); *(void **)&a_glBindImageTexture = dlsym(RTLD_NEXT, "glBindImageTexture"); if (p_glBindImageTexture) n++;
    *(void **)&p_glBindImageTextures = dlsym(mgl, "glBindImageTextures"); *(void **)&a_glBindImageTextures = dlsym(RTLD_NEXT, "glBindImageTextures"); if (p_glBindImageTextures) n++;
    *(void **)&p_glBindProgramPipeline = dlsym(mgl, "glBindProgramPipeline"); *(void **)&a_glBindProgramPipeline = dlsym(RTLD_NEXT, "glBindProgramPipeline"); if (p_glBindProgramPipeline) n++;
    *(void **)&p_glBindRenderbuffer = dlsym(mgl, "glBindRenderbuffer"); *(void **)&a_glBindRenderbuffer = dlsym(RTLD_NEXT, "glBindRenderbuffer"); if (p_glBindRenderbuffer) n++;
    *(void **)&p_glBindSampler = dlsym(mgl, "glBindSampler"); *(void **)&a_glBindSampler = dlsym(RTLD_NEXT, "glBindSampler"); if (p_glBindSampler) n++;
    *(void **)&p_glBindSamplers = dlsym(mgl, "glBindSamplers"); *(void **)&a_glBindSamplers = dlsym(RTLD_NEXT, "glBindSamplers"); if (p_glBindSamplers) n++;
    *(void **)&p_glBindTexture = dlsym(mgl, "glBindTexture"); *(void **)&a_glBindTexture = dlsym(RTLD_NEXT, "glBindTexture"); if (p_glBindTexture) n++;
    *(void **)&p_glBindTextureUnit = dlsym(mgl, "glBindTextureUnit"); *(void **)&a_glBindTextureUnit = dlsym(RTLD_NEXT, "glBindTextureUnit"); if (p_glBindTextureUnit) n++;
    *(void **)&p_glBindTextures = dlsym(mgl, "glBindTextures"); *(void **)&a_glBindTextures = dlsym(RTLD_NEXT, "glBindTextures"); if (p_glBindTextures) n++;
    *(void **)&p_glBindTransformFeedback = dlsym(mgl, "glBindTransformFeedback"); *(void **)&a_glBindTransformFeedback = dlsym(RTLD_NEXT, "glBindTransformFeedback"); if (p_glBindTransformFeedback) n++;
    *(void **)&p_glBindVertexArray = dlsym(mgl, "glBindVertexArray"); *(void **)&a_glBindVertexArray = dlsym(RTLD_NEXT, "glBindVertexArray"); if (p_glBindVertexArray) n++;
    *(void **)&p_glBindVertexBuffer = dlsym(mgl, "glBindVertexBuffer"); *(void **)&a_glBindVertexBuffer = dlsym(RTLD_NEXT, "glBindVertexBuffer"); if (p_glBindVertexBuffer) n++;
    *(void **)&p_glBindVertexBuffers = dlsym(mgl, "glBindVertexBuffers"); *(void **)&a_glBindVertexBuffers = dlsym(RTLD_NEXT, "glBindVertexBuffers"); if (p_glBindVertexBuffers) n++;
    *(void **)&p_glBlendColor = dlsym(mgl, "glBlendColor"); *(void **)&a_glBlendColor = dlsym(RTLD_NEXT, "glBlendColor"); if (p_glBlendColor) n++;
    *(void **)&p_glBlendEquation = dlsym(mgl, "glBlendEquation"); *(void **)&a_glBlendEquation = dlsym(RTLD_NEXT, "glBlendEquation"); if (p_glBlendEquation) n++;
    *(void **)&p_glBlendEquationSeparate = dlsym(mgl, "glBlendEquationSeparate"); *(void **)&a_glBlendEquationSeparate = dlsym(RTLD_NEXT, "glBlendEquationSeparate"); if (p_glBlendEquationSeparate) n++;
    *(void **)&p_glBlendEquationSeparatei = dlsym(mgl, "glBlendEquationSeparatei"); *(void **)&a_glBlendEquationSeparatei = dlsym(RTLD_NEXT, "glBlendEquationSeparatei"); if (p_glBlendEquationSeparatei) n++;
    *(void **)&p_glBlendEquationi = dlsym(mgl, "glBlendEquationi"); *(void **)&a_glBlendEquationi = dlsym(RTLD_NEXT, "glBlendEquationi"); if (p_glBlendEquationi) n++;
    *(void **)&p_glBlendFunc = dlsym(mgl, "glBlendFunc"); *(void **)&a_glBlendFunc = dlsym(RTLD_NEXT, "glBlendFunc"); if (p_glBlendFunc) n++;
    *(void **)&p_glBlendFuncSeparate = dlsym(mgl, "glBlendFuncSeparate"); *(void **)&a_glBlendFuncSeparate = dlsym(RTLD_NEXT, "glBlendFuncSeparate"); if (p_glBlendFuncSeparate) n++;
    *(void **)&p_glBlendFuncSeparatei = dlsym(mgl, "glBlendFuncSeparatei"); *(void **)&a_glBlendFuncSeparatei = dlsym(RTLD_NEXT, "glBlendFuncSeparatei"); if (p_glBlendFuncSeparatei) n++;
    *(void **)&p_glBlendFunci = dlsym(mgl, "glBlendFunci"); *(void **)&a_glBlendFunci = dlsym(RTLD_NEXT, "glBlendFunci"); if (p_glBlendFunci) n++;
    *(void **)&p_glBlitFramebuffer = dlsym(mgl, "glBlitFramebuffer"); *(void **)&a_glBlitFramebuffer = dlsym(RTLD_NEXT, "glBlitFramebuffer"); if (p_glBlitFramebuffer) n++;
    *(void **)&p_glBlitNamedFramebuffer = dlsym(mgl, "glBlitNamedFramebuffer"); *(void **)&a_glBlitNamedFramebuffer = dlsym(RTLD_NEXT, "glBlitNamedFramebuffer"); if (p_glBlitNamedFramebuffer) n++;
    *(void **)&p_glBufferData = dlsym(mgl, "glBufferData"); *(void **)&a_glBufferData = dlsym(RTLD_NEXT, "glBufferData"); if (p_glBufferData) n++;
    *(void **)&p_glBufferStorage = dlsym(mgl, "glBufferStorage"); *(void **)&a_glBufferStorage = dlsym(RTLD_NEXT, "glBufferStorage"); if (p_glBufferStorage) n++;
    *(void **)&p_glBufferSubData = dlsym(mgl, "glBufferSubData"); *(void **)&a_glBufferSubData = dlsym(RTLD_NEXT, "glBufferSubData"); if (p_glBufferSubData) n++;
    *(void **)&p_glCheckFramebufferStatus = dlsym(mgl, "glCheckFramebufferStatus"); *(void **)&a_glCheckFramebufferStatus = dlsym(RTLD_NEXT, "glCheckFramebufferStatus"); if (p_glCheckFramebufferStatus) n++;
    *(void **)&p_glCheckNamedFramebufferStatus = dlsym(mgl, "glCheckNamedFramebufferStatus"); *(void **)&a_glCheckNamedFramebufferStatus = dlsym(RTLD_NEXT, "glCheckNamedFramebufferStatus"); if (p_glCheckNamedFramebufferStatus) n++;
    *(void **)&p_glClampColor = dlsym(mgl, "glClampColor"); *(void **)&a_glClampColor = dlsym(RTLD_NEXT, "glClampColor"); if (p_glClampColor) n++;
    *(void **)&p_glClear = dlsym(mgl, "glClear"); *(void **)&a_glClear = dlsym(RTLD_NEXT, "glClear"); if (p_glClear) n++;
    *(void **)&p_glClearBufferData = dlsym(mgl, "glClearBufferData"); *(void **)&a_glClearBufferData = dlsym(RTLD_NEXT, "glClearBufferData"); if (p_glClearBufferData) n++;
    *(void **)&p_glClearBufferSubData = dlsym(mgl, "glClearBufferSubData"); *(void **)&a_glClearBufferSubData = dlsym(RTLD_NEXT, "glClearBufferSubData"); if (p_glClearBufferSubData) n++;
    *(void **)&p_glClearBufferfi = dlsym(mgl, "glClearBufferfi"); *(void **)&a_glClearBufferfi = dlsym(RTLD_NEXT, "glClearBufferfi"); if (p_glClearBufferfi) n++;
    *(void **)&p_glClearBufferfv = dlsym(mgl, "glClearBufferfv"); *(void **)&a_glClearBufferfv = dlsym(RTLD_NEXT, "glClearBufferfv"); if (p_glClearBufferfv) n++;
    *(void **)&p_glClearBufferiv = dlsym(mgl, "glClearBufferiv"); *(void **)&a_glClearBufferiv = dlsym(RTLD_NEXT, "glClearBufferiv"); if (p_glClearBufferiv) n++;
    *(void **)&p_glClearBufferuiv = dlsym(mgl, "glClearBufferuiv"); *(void **)&a_glClearBufferuiv = dlsym(RTLD_NEXT, "glClearBufferuiv"); if (p_glClearBufferuiv) n++;
    *(void **)&p_glClearColor = dlsym(mgl, "glClearColor"); *(void **)&a_glClearColor = dlsym(RTLD_NEXT, "glClearColor"); if (p_glClearColor) n++;
    *(void **)&p_glClearDepth = dlsym(mgl, "glClearDepth"); *(void **)&a_glClearDepth = dlsym(RTLD_NEXT, "glClearDepth"); if (p_glClearDepth) n++;
    *(void **)&p_glClearDepthf = dlsym(mgl, "glClearDepthf"); *(void **)&a_glClearDepthf = dlsym(RTLD_NEXT, "glClearDepthf"); if (p_glClearDepthf) n++;
    *(void **)&p_glClearNamedBufferData = dlsym(mgl, "glClearNamedBufferData"); *(void **)&a_glClearNamedBufferData = dlsym(RTLD_NEXT, "glClearNamedBufferData"); if (p_glClearNamedBufferData) n++;
    *(void **)&p_glClearNamedBufferSubData = dlsym(mgl, "glClearNamedBufferSubData"); *(void **)&a_glClearNamedBufferSubData = dlsym(RTLD_NEXT, "glClearNamedBufferSubData"); if (p_glClearNamedBufferSubData) n++;
    *(void **)&p_glClearNamedFramebufferfi = dlsym(mgl, "glClearNamedFramebufferfi"); *(void **)&a_glClearNamedFramebufferfi = dlsym(RTLD_NEXT, "glClearNamedFramebufferfi"); if (p_glClearNamedFramebufferfi) n++;
    *(void **)&p_glClearNamedFramebufferfv = dlsym(mgl, "glClearNamedFramebufferfv"); *(void **)&a_glClearNamedFramebufferfv = dlsym(RTLD_NEXT, "glClearNamedFramebufferfv"); if (p_glClearNamedFramebufferfv) n++;
    *(void **)&p_glClearNamedFramebufferiv = dlsym(mgl, "glClearNamedFramebufferiv"); *(void **)&a_glClearNamedFramebufferiv = dlsym(RTLD_NEXT, "glClearNamedFramebufferiv"); if (p_glClearNamedFramebufferiv) n++;
    *(void **)&p_glClearNamedFramebufferuiv = dlsym(mgl, "glClearNamedFramebufferuiv"); *(void **)&a_glClearNamedFramebufferuiv = dlsym(RTLD_NEXT, "glClearNamedFramebufferuiv"); if (p_glClearNamedFramebufferuiv) n++;
    *(void **)&p_glClearStencil = dlsym(mgl, "glClearStencil"); *(void **)&a_glClearStencil = dlsym(RTLD_NEXT, "glClearStencil"); if (p_glClearStencil) n++;
    *(void **)&p_glClearTexImage = dlsym(mgl, "glClearTexImage"); *(void **)&a_glClearTexImage = dlsym(RTLD_NEXT, "glClearTexImage"); if (p_glClearTexImage) n++;
    *(void **)&p_glClearTexSubImage = dlsym(mgl, "glClearTexSubImage"); *(void **)&a_glClearTexSubImage = dlsym(RTLD_NEXT, "glClearTexSubImage"); if (p_glClearTexSubImage) n++;
    *(void **)&p_glClientWaitSync = dlsym(mgl, "glClientWaitSync"); *(void **)&a_glClientWaitSync = dlsym(RTLD_NEXT, "glClientWaitSync"); if (p_glClientWaitSync) n++;
    *(void **)&p_glClipControl = dlsym(mgl, "glClipControl"); *(void **)&a_glClipControl = dlsym(RTLD_NEXT, "glClipControl"); if (p_glClipControl) n++;
    *(void **)&p_glColorMask = dlsym(mgl, "glColorMask"); *(void **)&a_glColorMask = dlsym(RTLD_NEXT, "glColorMask"); if (p_glColorMask) n++;
    *(void **)&p_glColorMaski = dlsym(mgl, "glColorMaski"); *(void **)&a_glColorMaski = dlsym(RTLD_NEXT, "glColorMaski"); if (p_glColorMaski) n++;
    *(void **)&p_glCompileShader = dlsym(mgl, "glCompileShader"); *(void **)&a_glCompileShader = dlsym(RTLD_NEXT, "glCompileShader"); if (p_glCompileShader) n++;
    *(void **)&p_glCompressedTexImage1D = dlsym(mgl, "glCompressedTexImage1D"); *(void **)&a_glCompressedTexImage1D = dlsym(RTLD_NEXT, "glCompressedTexImage1D"); if (p_glCompressedTexImage1D) n++;
    *(void **)&p_glCompressedTexImage2D = dlsym(mgl, "glCompressedTexImage2D"); *(void **)&a_glCompressedTexImage2D = dlsym(RTLD_NEXT, "glCompressedTexImage2D"); if (p_glCompressedTexImage2D) n++;
    *(void **)&p_glCompressedTexImage3D = dlsym(mgl, "glCompressedTexImage3D"); *(void **)&a_glCompressedTexImage3D = dlsym(RTLD_NEXT, "glCompressedTexImage3D"); if (p_glCompressedTexImage3D) n++;
    *(void **)&p_glCompressedTexSubImage1D = dlsym(mgl, "glCompressedTexSubImage1D"); *(void **)&a_glCompressedTexSubImage1D = dlsym(RTLD_NEXT, "glCompressedTexSubImage1D"); if (p_glCompressedTexSubImage1D) n++;
    *(void **)&p_glCompressedTexSubImage2D = dlsym(mgl, "glCompressedTexSubImage2D"); *(void **)&a_glCompressedTexSubImage2D = dlsym(RTLD_NEXT, "glCompressedTexSubImage2D"); if (p_glCompressedTexSubImage2D) n++;
    *(void **)&p_glCompressedTexSubImage3D = dlsym(mgl, "glCompressedTexSubImage3D"); *(void **)&a_glCompressedTexSubImage3D = dlsym(RTLD_NEXT, "glCompressedTexSubImage3D"); if (p_glCompressedTexSubImage3D) n++;
    *(void **)&p_glCompressedTextureSubImage1D = dlsym(mgl, "glCompressedTextureSubImage1D"); *(void **)&a_glCompressedTextureSubImage1D = dlsym(RTLD_NEXT, "glCompressedTextureSubImage1D"); if (p_glCompressedTextureSubImage1D) n++;
    *(void **)&p_glCompressedTextureSubImage2D = dlsym(mgl, "glCompressedTextureSubImage2D"); *(void **)&a_glCompressedTextureSubImage2D = dlsym(RTLD_NEXT, "glCompressedTextureSubImage2D"); if (p_glCompressedTextureSubImage2D) n++;
    *(void **)&p_glCompressedTextureSubImage3D = dlsym(mgl, "glCompressedTextureSubImage3D"); *(void **)&a_glCompressedTextureSubImage3D = dlsym(RTLD_NEXT, "glCompressedTextureSubImage3D"); if (p_glCompressedTextureSubImage3D) n++;
    *(void **)&p_glCopyBufferSubData = dlsym(mgl, "glCopyBufferSubData"); *(void **)&a_glCopyBufferSubData = dlsym(RTLD_NEXT, "glCopyBufferSubData"); if (p_glCopyBufferSubData) n++;
    *(void **)&p_glCopyImageSubData = dlsym(mgl, "glCopyImageSubData"); *(void **)&a_glCopyImageSubData = dlsym(RTLD_NEXT, "glCopyImageSubData"); if (p_glCopyImageSubData) n++;
    *(void **)&p_glCopyNamedBufferSubData = dlsym(mgl, "glCopyNamedBufferSubData"); *(void **)&a_glCopyNamedBufferSubData = dlsym(RTLD_NEXT, "glCopyNamedBufferSubData"); if (p_glCopyNamedBufferSubData) n++;
    *(void **)&p_glCopyTexImage1D = dlsym(mgl, "glCopyTexImage1D"); *(void **)&a_glCopyTexImage1D = dlsym(RTLD_NEXT, "glCopyTexImage1D"); if (p_glCopyTexImage1D) n++;
    *(void **)&p_glCopyTexImage2D = dlsym(mgl, "glCopyTexImage2D"); *(void **)&a_glCopyTexImage2D = dlsym(RTLD_NEXT, "glCopyTexImage2D"); if (p_glCopyTexImage2D) n++;
    *(void **)&p_glCopyTexSubImage1D = dlsym(mgl, "glCopyTexSubImage1D"); *(void **)&a_glCopyTexSubImage1D = dlsym(RTLD_NEXT, "glCopyTexSubImage1D"); if (p_glCopyTexSubImage1D) n++;
    *(void **)&p_glCopyTexSubImage2D = dlsym(mgl, "glCopyTexSubImage2D"); *(void **)&a_glCopyTexSubImage2D = dlsym(RTLD_NEXT, "glCopyTexSubImage2D"); if (p_glCopyTexSubImage2D) n++;
    *(void **)&p_glCopyTexSubImage3D = dlsym(mgl, "glCopyTexSubImage3D"); *(void **)&a_glCopyTexSubImage3D = dlsym(RTLD_NEXT, "glCopyTexSubImage3D"); if (p_glCopyTexSubImage3D) n++;
    *(void **)&p_glCopyTextureSubImage1D = dlsym(mgl, "glCopyTextureSubImage1D"); *(void **)&a_glCopyTextureSubImage1D = dlsym(RTLD_NEXT, "glCopyTextureSubImage1D"); if (p_glCopyTextureSubImage1D) n++;
    *(void **)&p_glCopyTextureSubImage2D = dlsym(mgl, "glCopyTextureSubImage2D"); *(void **)&a_glCopyTextureSubImage2D = dlsym(RTLD_NEXT, "glCopyTextureSubImage2D"); if (p_glCopyTextureSubImage2D) n++;
    *(void **)&p_glCopyTextureSubImage3D = dlsym(mgl, "glCopyTextureSubImage3D"); *(void **)&a_glCopyTextureSubImage3D = dlsym(RTLD_NEXT, "glCopyTextureSubImage3D"); if (p_glCopyTextureSubImage3D) n++;
    *(void **)&p_glCreateBuffers = dlsym(mgl, "glCreateBuffers"); *(void **)&a_glCreateBuffers = dlsym(RTLD_NEXT, "glCreateBuffers"); if (p_glCreateBuffers) n++;
    *(void **)&p_glCreateFramebuffers = dlsym(mgl, "glCreateFramebuffers"); *(void **)&a_glCreateFramebuffers = dlsym(RTLD_NEXT, "glCreateFramebuffers"); if (p_glCreateFramebuffers) n++;
    *(void **)&p_glCreateProgram = dlsym(mgl, "glCreateProgram"); *(void **)&a_glCreateProgram = dlsym(RTLD_NEXT, "glCreateProgram"); if (p_glCreateProgram) n++;
    *(void **)&p_glCreateProgramPipelines = dlsym(mgl, "glCreateProgramPipelines"); *(void **)&a_glCreateProgramPipelines = dlsym(RTLD_NEXT, "glCreateProgramPipelines"); if (p_glCreateProgramPipelines) n++;
    *(void **)&p_glCreateQueries = dlsym(mgl, "glCreateQueries"); *(void **)&a_glCreateQueries = dlsym(RTLD_NEXT, "glCreateQueries"); if (p_glCreateQueries) n++;
    *(void **)&p_glCreateRenderbuffers = dlsym(mgl, "glCreateRenderbuffers"); *(void **)&a_glCreateRenderbuffers = dlsym(RTLD_NEXT, "glCreateRenderbuffers"); if (p_glCreateRenderbuffers) n++;
    *(void **)&p_glCreateSamplers = dlsym(mgl, "glCreateSamplers"); *(void **)&a_glCreateSamplers = dlsym(RTLD_NEXT, "glCreateSamplers"); if (p_glCreateSamplers) n++;
    *(void **)&p_glCreateShader = dlsym(mgl, "glCreateShader"); *(void **)&a_glCreateShader = dlsym(RTLD_NEXT, "glCreateShader"); if (p_glCreateShader) n++;
    *(void **)&p_glCreateShaderProgramv = dlsym(mgl, "glCreateShaderProgramv"); *(void **)&a_glCreateShaderProgramv = dlsym(RTLD_NEXT, "glCreateShaderProgramv"); if (p_glCreateShaderProgramv) n++;
    *(void **)&p_glCreateTextures = dlsym(mgl, "glCreateTextures"); *(void **)&a_glCreateTextures = dlsym(RTLD_NEXT, "glCreateTextures"); if (p_glCreateTextures) n++;
    *(void **)&p_glCreateTransformFeedbacks = dlsym(mgl, "glCreateTransformFeedbacks"); *(void **)&a_glCreateTransformFeedbacks = dlsym(RTLD_NEXT, "glCreateTransformFeedbacks"); if (p_glCreateTransformFeedbacks) n++;
    *(void **)&p_glCreateVertexArrays = dlsym(mgl, "glCreateVertexArrays"); *(void **)&a_glCreateVertexArrays = dlsym(RTLD_NEXT, "glCreateVertexArrays"); if (p_glCreateVertexArrays) n++;
    *(void **)&p_glCullFace = dlsym(mgl, "glCullFace"); *(void **)&a_glCullFace = dlsym(RTLD_NEXT, "glCullFace"); if (p_glCullFace) n++;
    *(void **)&p_glDebugMessageCallback = dlsym(mgl, "glDebugMessageCallback"); *(void **)&a_glDebugMessageCallback = dlsym(RTLD_NEXT, "glDebugMessageCallback"); if (p_glDebugMessageCallback) n++;
    *(void **)&p_glDebugMessageControl = dlsym(mgl, "glDebugMessageControl"); *(void **)&a_glDebugMessageControl = dlsym(RTLD_NEXT, "glDebugMessageControl"); if (p_glDebugMessageControl) n++;
    *(void **)&p_glDebugMessageInsert = dlsym(mgl, "glDebugMessageInsert"); *(void **)&a_glDebugMessageInsert = dlsym(RTLD_NEXT, "glDebugMessageInsert"); if (p_glDebugMessageInsert) n++;
    *(void **)&p_glDeleteBuffers = dlsym(mgl, "glDeleteBuffers"); *(void **)&a_glDeleteBuffers = dlsym(RTLD_NEXT, "glDeleteBuffers"); if (p_glDeleteBuffers) n++;
    *(void **)&p_glDeleteFramebuffers = dlsym(mgl, "glDeleteFramebuffers"); *(void **)&a_glDeleteFramebuffers = dlsym(RTLD_NEXT, "glDeleteFramebuffers"); if (p_glDeleteFramebuffers) n++;
    *(void **)&p_glDeleteProgram = dlsym(mgl, "glDeleteProgram"); *(void **)&a_glDeleteProgram = dlsym(RTLD_NEXT, "glDeleteProgram"); if (p_glDeleteProgram) n++;
    *(void **)&p_glDeleteProgramPipelines = dlsym(mgl, "glDeleteProgramPipelines"); *(void **)&a_glDeleteProgramPipelines = dlsym(RTLD_NEXT, "glDeleteProgramPipelines"); if (p_glDeleteProgramPipelines) n++;
    *(void **)&p_glDeleteQueries = dlsym(mgl, "glDeleteQueries"); *(void **)&a_glDeleteQueries = dlsym(RTLD_NEXT, "glDeleteQueries"); if (p_glDeleteQueries) n++;
    *(void **)&p_glDeleteRenderbuffers = dlsym(mgl, "glDeleteRenderbuffers"); *(void **)&a_glDeleteRenderbuffers = dlsym(RTLD_NEXT, "glDeleteRenderbuffers"); if (p_glDeleteRenderbuffers) n++;
    *(void **)&p_glDeleteSamplers = dlsym(mgl, "glDeleteSamplers"); *(void **)&a_glDeleteSamplers = dlsym(RTLD_NEXT, "glDeleteSamplers"); if (p_glDeleteSamplers) n++;
    *(void **)&p_glDeleteShader = dlsym(mgl, "glDeleteShader"); *(void **)&a_glDeleteShader = dlsym(RTLD_NEXT, "glDeleteShader"); if (p_glDeleteShader) n++;
    *(void **)&p_glDeleteSync = dlsym(mgl, "glDeleteSync"); *(void **)&a_glDeleteSync = dlsym(RTLD_NEXT, "glDeleteSync"); if (p_glDeleteSync) n++;
    *(void **)&p_glDeleteTextures = dlsym(mgl, "glDeleteTextures"); *(void **)&a_glDeleteTextures = dlsym(RTLD_NEXT, "glDeleteTextures"); if (p_glDeleteTextures) n++;
    *(void **)&p_glDeleteTransformFeedbacks = dlsym(mgl, "glDeleteTransformFeedbacks"); *(void **)&a_glDeleteTransformFeedbacks = dlsym(RTLD_NEXT, "glDeleteTransformFeedbacks"); if (p_glDeleteTransformFeedbacks) n++;
    *(void **)&p_glDeleteVertexArrays = dlsym(mgl, "glDeleteVertexArrays"); *(void **)&a_glDeleteVertexArrays = dlsym(RTLD_NEXT, "glDeleteVertexArrays"); if (p_glDeleteVertexArrays) n++;
    *(void **)&p_glDepthFunc = dlsym(mgl, "glDepthFunc"); *(void **)&a_glDepthFunc = dlsym(RTLD_NEXT, "glDepthFunc"); if (p_glDepthFunc) n++;
    *(void **)&p_glDepthMask = dlsym(mgl, "glDepthMask"); *(void **)&a_glDepthMask = dlsym(RTLD_NEXT, "glDepthMask"); if (p_glDepthMask) n++;
    *(void **)&p_glDepthRange = dlsym(mgl, "glDepthRange"); *(void **)&a_glDepthRange = dlsym(RTLD_NEXT, "glDepthRange"); if (p_glDepthRange) n++;
    *(void **)&p_glDepthRangeArrayv = dlsym(mgl, "glDepthRangeArrayv"); *(void **)&a_glDepthRangeArrayv = dlsym(RTLD_NEXT, "glDepthRangeArrayv"); if (p_glDepthRangeArrayv) n++;
    *(void **)&p_glDepthRangeIndexed = dlsym(mgl, "glDepthRangeIndexed"); *(void **)&a_glDepthRangeIndexed = dlsym(RTLD_NEXT, "glDepthRangeIndexed"); if (p_glDepthRangeIndexed) n++;
    *(void **)&p_glDepthRangef = dlsym(mgl, "glDepthRangef"); *(void **)&a_glDepthRangef = dlsym(RTLD_NEXT, "glDepthRangef"); if (p_glDepthRangef) n++;
    *(void **)&p_glDetachShader = dlsym(mgl, "glDetachShader"); *(void **)&a_glDetachShader = dlsym(RTLD_NEXT, "glDetachShader"); if (p_glDetachShader) n++;
    *(void **)&p_glDisable = dlsym(mgl, "glDisable"); *(void **)&a_glDisable = dlsym(RTLD_NEXT, "glDisable"); if (p_glDisable) n++;
    *(void **)&p_glDisableVertexArrayAttrib = dlsym(mgl, "glDisableVertexArrayAttrib"); *(void **)&a_glDisableVertexArrayAttrib = dlsym(RTLD_NEXT, "glDisableVertexArrayAttrib"); if (p_glDisableVertexArrayAttrib) n++;
    *(void **)&p_glDisableVertexAttribArray = dlsym(mgl, "glDisableVertexAttribArray"); *(void **)&a_glDisableVertexAttribArray = dlsym(RTLD_NEXT, "glDisableVertexAttribArray"); if (p_glDisableVertexAttribArray) n++;
    *(void **)&p_glDisablei = dlsym(mgl, "glDisablei"); *(void **)&a_glDisablei = dlsym(RTLD_NEXT, "glDisablei"); if (p_glDisablei) n++;
    *(void **)&p_glDispatchCompute = dlsym(mgl, "glDispatchCompute"); *(void **)&a_glDispatchCompute = dlsym(RTLD_NEXT, "glDispatchCompute"); if (p_glDispatchCompute) n++;
    *(void **)&p_glDispatchComputeIndirect = dlsym(mgl, "glDispatchComputeIndirect"); *(void **)&a_glDispatchComputeIndirect = dlsym(RTLD_NEXT, "glDispatchComputeIndirect"); if (p_glDispatchComputeIndirect) n++;
    *(void **)&p_glDrawArrays = dlsym(mgl, "glDrawArrays"); *(void **)&a_glDrawArrays = dlsym(RTLD_NEXT, "glDrawArrays"); if (p_glDrawArrays) n++;
    *(void **)&p_glDrawArraysIndirect = dlsym(mgl, "glDrawArraysIndirect"); *(void **)&a_glDrawArraysIndirect = dlsym(RTLD_NEXT, "glDrawArraysIndirect"); if (p_glDrawArraysIndirect) n++;
    *(void **)&p_glDrawArraysInstanced = dlsym(mgl, "glDrawArraysInstanced"); *(void **)&a_glDrawArraysInstanced = dlsym(RTLD_NEXT, "glDrawArraysInstanced"); if (p_glDrawArraysInstanced) n++;
    *(void **)&p_glDrawArraysInstancedBaseInstance = dlsym(mgl, "glDrawArraysInstancedBaseInstance"); *(void **)&a_glDrawArraysInstancedBaseInstance = dlsym(RTLD_NEXT, "glDrawArraysInstancedBaseInstance"); if (p_glDrawArraysInstancedBaseInstance) n++;
    *(void **)&p_glDrawBuffer = dlsym(mgl, "glDrawBuffer"); *(void **)&a_glDrawBuffer = dlsym(RTLD_NEXT, "glDrawBuffer"); if (p_glDrawBuffer) n++;
    *(void **)&p_glDrawBuffers = dlsym(mgl, "glDrawBuffers"); *(void **)&a_glDrawBuffers = dlsym(RTLD_NEXT, "glDrawBuffers"); if (p_glDrawBuffers) n++;
    *(void **)&p_glDrawElements = dlsym(mgl, "glDrawElements"); *(void **)&a_glDrawElements = dlsym(RTLD_NEXT, "glDrawElements"); if (p_glDrawElements) n++;
    *(void **)&p_glDrawElementsBaseVertex = dlsym(mgl, "glDrawElementsBaseVertex"); *(void **)&a_glDrawElementsBaseVertex = dlsym(RTLD_NEXT, "glDrawElementsBaseVertex"); if (p_glDrawElementsBaseVertex) n++;
    *(void **)&p_glDrawElementsIndirect = dlsym(mgl, "glDrawElementsIndirect"); *(void **)&a_glDrawElementsIndirect = dlsym(RTLD_NEXT, "glDrawElementsIndirect"); if (p_glDrawElementsIndirect) n++;
    *(void **)&p_glDrawElementsInstanced = dlsym(mgl, "glDrawElementsInstanced"); *(void **)&a_glDrawElementsInstanced = dlsym(RTLD_NEXT, "glDrawElementsInstanced"); if (p_glDrawElementsInstanced) n++;
    *(void **)&p_glDrawElementsInstancedBaseInstance = dlsym(mgl, "glDrawElementsInstancedBaseInstance"); *(void **)&a_glDrawElementsInstancedBaseInstance = dlsym(RTLD_NEXT, "glDrawElementsInstancedBaseInstance"); if (p_glDrawElementsInstancedBaseInstance) n++;
    *(void **)&p_glDrawElementsInstancedBaseVertex = dlsym(mgl, "glDrawElementsInstancedBaseVertex"); *(void **)&a_glDrawElementsInstancedBaseVertex = dlsym(RTLD_NEXT, "glDrawElementsInstancedBaseVertex"); if (p_glDrawElementsInstancedBaseVertex) n++;
    *(void **)&p_glDrawElementsInstancedBaseVertexBaseInstance = dlsym(mgl, "glDrawElementsInstancedBaseVertexBaseInstance"); *(void **)&a_glDrawElementsInstancedBaseVertexBaseInstance = dlsym(RTLD_NEXT, "glDrawElementsInstancedBaseVertexBaseInstance"); if (p_glDrawElementsInstancedBaseVertexBaseInstance) n++;
    *(void **)&p_glDrawRangeElements = dlsym(mgl, "glDrawRangeElements"); *(void **)&a_glDrawRangeElements = dlsym(RTLD_NEXT, "glDrawRangeElements"); if (p_glDrawRangeElements) n++;
    *(void **)&p_glDrawRangeElementsBaseVertex = dlsym(mgl, "glDrawRangeElementsBaseVertex"); *(void **)&a_glDrawRangeElementsBaseVertex = dlsym(RTLD_NEXT, "glDrawRangeElementsBaseVertex"); if (p_glDrawRangeElementsBaseVertex) n++;
    *(void **)&p_glDrawTransformFeedback = dlsym(mgl, "glDrawTransformFeedback"); *(void **)&a_glDrawTransformFeedback = dlsym(RTLD_NEXT, "glDrawTransformFeedback"); if (p_glDrawTransformFeedback) n++;
    *(void **)&p_glDrawTransformFeedbackInstanced = dlsym(mgl, "glDrawTransformFeedbackInstanced"); *(void **)&a_glDrawTransformFeedbackInstanced = dlsym(RTLD_NEXT, "glDrawTransformFeedbackInstanced"); if (p_glDrawTransformFeedbackInstanced) n++;
    *(void **)&p_glDrawTransformFeedbackStream = dlsym(mgl, "glDrawTransformFeedbackStream"); *(void **)&a_glDrawTransformFeedbackStream = dlsym(RTLD_NEXT, "glDrawTransformFeedbackStream"); if (p_glDrawTransformFeedbackStream) n++;
    *(void **)&p_glDrawTransformFeedbackStreamInstanced = dlsym(mgl, "glDrawTransformFeedbackStreamInstanced"); *(void **)&a_glDrawTransformFeedbackStreamInstanced = dlsym(RTLD_NEXT, "glDrawTransformFeedbackStreamInstanced"); if (p_glDrawTransformFeedbackStreamInstanced) n++;
    *(void **)&p_glEnable = dlsym(mgl, "glEnable"); *(void **)&a_glEnable = dlsym(RTLD_NEXT, "glEnable"); if (p_glEnable) n++;
    *(void **)&p_glEnableVertexArrayAttrib = dlsym(mgl, "glEnableVertexArrayAttrib"); *(void **)&a_glEnableVertexArrayAttrib = dlsym(RTLD_NEXT, "glEnableVertexArrayAttrib"); if (p_glEnableVertexArrayAttrib) n++;
    *(void **)&p_glEnableVertexAttribArray = dlsym(mgl, "glEnableVertexAttribArray"); *(void **)&a_glEnableVertexAttribArray = dlsym(RTLD_NEXT, "glEnableVertexAttribArray"); if (p_glEnableVertexAttribArray) n++;
    *(void **)&p_glEnablei = dlsym(mgl, "glEnablei"); *(void **)&a_glEnablei = dlsym(RTLD_NEXT, "glEnablei"); if (p_glEnablei) n++;
    *(void **)&p_glEndConditionalRender = dlsym(mgl, "glEndConditionalRender"); *(void **)&a_glEndConditionalRender = dlsym(RTLD_NEXT, "glEndConditionalRender"); if (p_glEndConditionalRender) n++;
    *(void **)&p_glEndQuery = dlsym(mgl, "glEndQuery"); *(void **)&a_glEndQuery = dlsym(RTLD_NEXT, "glEndQuery"); if (p_glEndQuery) n++;
    *(void **)&p_glEndQueryIndexed = dlsym(mgl, "glEndQueryIndexed"); *(void **)&a_glEndQueryIndexed = dlsym(RTLD_NEXT, "glEndQueryIndexed"); if (p_glEndQueryIndexed) n++;
    *(void **)&p_glEndTransformFeedback = dlsym(mgl, "glEndTransformFeedback"); *(void **)&a_glEndTransformFeedback = dlsym(RTLD_NEXT, "glEndTransformFeedback"); if (p_glEndTransformFeedback) n++;
    *(void **)&p_glFenceSync = dlsym(mgl, "glFenceSync"); *(void **)&a_glFenceSync = dlsym(RTLD_NEXT, "glFenceSync"); if (p_glFenceSync) n++;
    *(void **)&p_glFinish = dlsym(mgl, "glFinish"); *(void **)&a_glFinish = dlsym(RTLD_NEXT, "glFinish"); if (p_glFinish) n++;
    *(void **)&p_glFlush = dlsym(mgl, "glFlush"); *(void **)&a_glFlush = dlsym(RTLD_NEXT, "glFlush"); if (p_glFlush) n++;
    *(void **)&p_glFlushMappedBufferRange = dlsym(mgl, "glFlushMappedBufferRange"); *(void **)&a_glFlushMappedBufferRange = dlsym(RTLD_NEXT, "glFlushMappedBufferRange"); if (p_glFlushMappedBufferRange) n++;
    *(void **)&p_glFlushMappedNamedBufferRange = dlsym(mgl, "glFlushMappedNamedBufferRange"); *(void **)&a_glFlushMappedNamedBufferRange = dlsym(RTLD_NEXT, "glFlushMappedNamedBufferRange"); if (p_glFlushMappedNamedBufferRange) n++;
    *(void **)&p_glFramebufferParameteri = dlsym(mgl, "glFramebufferParameteri"); *(void **)&a_glFramebufferParameteri = dlsym(RTLD_NEXT, "glFramebufferParameteri"); if (p_glFramebufferParameteri) n++;
    *(void **)&p_glFramebufferRenderbuffer = dlsym(mgl, "glFramebufferRenderbuffer"); *(void **)&a_glFramebufferRenderbuffer = dlsym(RTLD_NEXT, "glFramebufferRenderbuffer"); if (p_glFramebufferRenderbuffer) n++;
    *(void **)&p_glFramebufferTexture = dlsym(mgl, "glFramebufferTexture"); *(void **)&a_glFramebufferTexture = dlsym(RTLD_NEXT, "glFramebufferTexture"); if (p_glFramebufferTexture) n++;
    *(void **)&p_glFramebufferTexture1D = dlsym(mgl, "glFramebufferTexture1D"); *(void **)&a_glFramebufferTexture1D = dlsym(RTLD_NEXT, "glFramebufferTexture1D"); if (p_glFramebufferTexture1D) n++;
    *(void **)&p_glFramebufferTexture2D = dlsym(mgl, "glFramebufferTexture2D"); *(void **)&a_glFramebufferTexture2D = dlsym(RTLD_NEXT, "glFramebufferTexture2D"); if (p_glFramebufferTexture2D) n++;
    *(void **)&p_glFramebufferTexture3D = dlsym(mgl, "glFramebufferTexture3D"); *(void **)&a_glFramebufferTexture3D = dlsym(RTLD_NEXT, "glFramebufferTexture3D"); if (p_glFramebufferTexture3D) n++;
    *(void **)&p_glFramebufferTextureLayer = dlsym(mgl, "glFramebufferTextureLayer"); *(void **)&a_glFramebufferTextureLayer = dlsym(RTLD_NEXT, "glFramebufferTextureLayer"); if (p_glFramebufferTextureLayer) n++;
    *(void **)&p_glFrontFace = dlsym(mgl, "glFrontFace"); *(void **)&a_glFrontFace = dlsym(RTLD_NEXT, "glFrontFace"); if (p_glFrontFace) n++;
    *(void **)&p_glGenBuffers = dlsym(mgl, "glGenBuffers"); *(void **)&a_glGenBuffers = dlsym(RTLD_NEXT, "glGenBuffers"); if (p_glGenBuffers) n++;
    *(void **)&p_glGenFramebuffers = dlsym(mgl, "glGenFramebuffers"); *(void **)&a_glGenFramebuffers = dlsym(RTLD_NEXT, "glGenFramebuffers"); if (p_glGenFramebuffers) n++;
    *(void **)&p_glGenProgramPipelines = dlsym(mgl, "glGenProgramPipelines"); *(void **)&a_glGenProgramPipelines = dlsym(RTLD_NEXT, "glGenProgramPipelines"); if (p_glGenProgramPipelines) n++;
    *(void **)&p_glGenQueries = dlsym(mgl, "glGenQueries"); *(void **)&a_glGenQueries = dlsym(RTLD_NEXT, "glGenQueries"); if (p_glGenQueries) n++;
    *(void **)&p_glGenRenderbuffers = dlsym(mgl, "glGenRenderbuffers"); *(void **)&a_glGenRenderbuffers = dlsym(RTLD_NEXT, "glGenRenderbuffers"); if (p_glGenRenderbuffers) n++;
    *(void **)&p_glGenSamplers = dlsym(mgl, "glGenSamplers"); *(void **)&a_glGenSamplers = dlsym(RTLD_NEXT, "glGenSamplers"); if (p_glGenSamplers) n++;
    *(void **)&p_glGenTextures = dlsym(mgl, "glGenTextures"); *(void **)&a_glGenTextures = dlsym(RTLD_NEXT, "glGenTextures"); if (p_glGenTextures) n++;
    *(void **)&p_glGenTransformFeedbacks = dlsym(mgl, "glGenTransformFeedbacks"); *(void **)&a_glGenTransformFeedbacks = dlsym(RTLD_NEXT, "glGenTransformFeedbacks"); if (p_glGenTransformFeedbacks) n++;
    *(void **)&p_glGenVertexArrays = dlsym(mgl, "glGenVertexArrays"); *(void **)&a_glGenVertexArrays = dlsym(RTLD_NEXT, "glGenVertexArrays"); if (p_glGenVertexArrays) n++;
    *(void **)&p_glGenerateMipmap = dlsym(mgl, "glGenerateMipmap"); *(void **)&a_glGenerateMipmap = dlsym(RTLD_NEXT, "glGenerateMipmap"); if (p_glGenerateMipmap) n++;
    *(void **)&p_glGenerateTextureMipmap = dlsym(mgl, "glGenerateTextureMipmap"); *(void **)&a_glGenerateTextureMipmap = dlsym(RTLD_NEXT, "glGenerateTextureMipmap"); if (p_glGenerateTextureMipmap) n++;
    *(void **)&p_glGetActiveAtomicCounterBufferiv = dlsym(mgl, "glGetActiveAtomicCounterBufferiv"); *(void **)&a_glGetActiveAtomicCounterBufferiv = dlsym(RTLD_NEXT, "glGetActiveAtomicCounterBufferiv"); if (p_glGetActiveAtomicCounterBufferiv) n++;
    *(void **)&p_glGetActiveAttrib = dlsym(mgl, "glGetActiveAttrib"); *(void **)&a_glGetActiveAttrib = dlsym(RTLD_NEXT, "glGetActiveAttrib"); if (p_glGetActiveAttrib) n++;
    *(void **)&p_glGetActiveSubroutineName = dlsym(mgl, "glGetActiveSubroutineName"); *(void **)&a_glGetActiveSubroutineName = dlsym(RTLD_NEXT, "glGetActiveSubroutineName"); if (p_glGetActiveSubroutineName) n++;
    *(void **)&p_glGetActiveSubroutineUniformName = dlsym(mgl, "glGetActiveSubroutineUniformName"); *(void **)&a_glGetActiveSubroutineUniformName = dlsym(RTLD_NEXT, "glGetActiveSubroutineUniformName"); if (p_glGetActiveSubroutineUniformName) n++;
    *(void **)&p_glGetActiveSubroutineUniformiv = dlsym(mgl, "glGetActiveSubroutineUniformiv"); *(void **)&a_glGetActiveSubroutineUniformiv = dlsym(RTLD_NEXT, "glGetActiveSubroutineUniformiv"); if (p_glGetActiveSubroutineUniformiv) n++;
    *(void **)&p_glGetActiveUniform = dlsym(mgl, "glGetActiveUniform"); *(void **)&a_glGetActiveUniform = dlsym(RTLD_NEXT, "glGetActiveUniform"); if (p_glGetActiveUniform) n++;
    *(void **)&p_glGetActiveUniformBlockName = dlsym(mgl, "glGetActiveUniformBlockName"); *(void **)&a_glGetActiveUniformBlockName = dlsym(RTLD_NEXT, "glGetActiveUniformBlockName"); if (p_glGetActiveUniformBlockName) n++;
    *(void **)&p_glGetActiveUniformBlockiv = dlsym(mgl, "glGetActiveUniformBlockiv"); *(void **)&a_glGetActiveUniformBlockiv = dlsym(RTLD_NEXT, "glGetActiveUniformBlockiv"); if (p_glGetActiveUniformBlockiv) n++;
    *(void **)&p_glGetActiveUniformName = dlsym(mgl, "glGetActiveUniformName"); *(void **)&a_glGetActiveUniformName = dlsym(RTLD_NEXT, "glGetActiveUniformName"); if (p_glGetActiveUniformName) n++;
    *(void **)&p_glGetActiveUniformsiv = dlsym(mgl, "glGetActiveUniformsiv"); *(void **)&a_glGetActiveUniformsiv = dlsym(RTLD_NEXT, "glGetActiveUniformsiv"); if (p_glGetActiveUniformsiv) n++;
    *(void **)&p_glGetAttachedShaders = dlsym(mgl, "glGetAttachedShaders"); *(void **)&a_glGetAttachedShaders = dlsym(RTLD_NEXT, "glGetAttachedShaders"); if (p_glGetAttachedShaders) n++;
    *(void **)&p_glGetAttribLocation = dlsym(mgl, "glGetAttribLocation"); *(void **)&a_glGetAttribLocation = dlsym(RTLD_NEXT, "glGetAttribLocation"); if (p_glGetAttribLocation) n++;
    *(void **)&p_glGetBooleani_v = dlsym(mgl, "glGetBooleani_v"); *(void **)&a_glGetBooleani_v = dlsym(RTLD_NEXT, "glGetBooleani_v"); if (p_glGetBooleani_v) n++;
    *(void **)&p_glGetBooleanv = dlsym(mgl, "glGetBooleanv"); *(void **)&a_glGetBooleanv = dlsym(RTLD_NEXT, "glGetBooleanv"); if (p_glGetBooleanv) n++;
    *(void **)&p_glGetBufferParameteri64v = dlsym(mgl, "glGetBufferParameteri64v"); *(void **)&a_glGetBufferParameteri64v = dlsym(RTLD_NEXT, "glGetBufferParameteri64v"); if (p_glGetBufferParameteri64v) n++;
    *(void **)&p_glGetBufferParameteriv = dlsym(mgl, "glGetBufferParameteriv"); *(void **)&a_glGetBufferParameteriv = dlsym(RTLD_NEXT, "glGetBufferParameteriv"); if (p_glGetBufferParameteriv) n++;
    *(void **)&p_glGetBufferPointerv = dlsym(mgl, "glGetBufferPointerv"); *(void **)&a_glGetBufferPointerv = dlsym(RTLD_NEXT, "glGetBufferPointerv"); if (p_glGetBufferPointerv) n++;
    *(void **)&p_glGetBufferSubData = dlsym(mgl, "glGetBufferSubData"); *(void **)&a_glGetBufferSubData = dlsym(RTLD_NEXT, "glGetBufferSubData"); if (p_glGetBufferSubData) n++;
    *(void **)&p_glGetCompressedTexImage = dlsym(mgl, "glGetCompressedTexImage"); *(void **)&a_glGetCompressedTexImage = dlsym(RTLD_NEXT, "glGetCompressedTexImage"); if (p_glGetCompressedTexImage) n++;
    *(void **)&p_glGetCompressedTextureImage = dlsym(mgl, "glGetCompressedTextureImage"); *(void **)&a_glGetCompressedTextureImage = dlsym(RTLD_NEXT, "glGetCompressedTextureImage"); if (p_glGetCompressedTextureImage) n++;
    *(void **)&p_glGetCompressedTextureSubImage = dlsym(mgl, "glGetCompressedTextureSubImage"); *(void **)&a_glGetCompressedTextureSubImage = dlsym(RTLD_NEXT, "glGetCompressedTextureSubImage"); if (p_glGetCompressedTextureSubImage) n++;
    *(void **)&p_glGetDebugMessageLog = dlsym(mgl, "glGetDebugMessageLog"); *(void **)&a_glGetDebugMessageLog = dlsym(RTLD_NEXT, "glGetDebugMessageLog"); if (p_glGetDebugMessageLog) n++;
    *(void **)&p_glGetDoublei_v = dlsym(mgl, "glGetDoublei_v"); *(void **)&a_glGetDoublei_v = dlsym(RTLD_NEXT, "glGetDoublei_v"); if (p_glGetDoublei_v) n++;
    *(void **)&p_glGetDoublev = dlsym(mgl, "glGetDoublev"); *(void **)&a_glGetDoublev = dlsym(RTLD_NEXT, "glGetDoublev"); if (p_glGetDoublev) n++;
    *(void **)&p_glGetError = dlsym(mgl, "glGetError"); *(void **)&a_glGetError = dlsym(RTLD_NEXT, "glGetError"); if (p_glGetError) n++;
    *(void **)&p_glGetFloati_v = dlsym(mgl, "glGetFloati_v"); *(void **)&a_glGetFloati_v = dlsym(RTLD_NEXT, "glGetFloati_v"); if (p_glGetFloati_v) n++;
    *(void **)&p_glGetFloatv = dlsym(mgl, "glGetFloatv"); *(void **)&a_glGetFloatv = dlsym(RTLD_NEXT, "glGetFloatv"); if (p_glGetFloatv) n++;
    *(void **)&p_glGetFragDataIndex = dlsym(mgl, "glGetFragDataIndex"); *(void **)&a_glGetFragDataIndex = dlsym(RTLD_NEXT, "glGetFragDataIndex"); if (p_glGetFragDataIndex) n++;
    *(void **)&p_glGetFragDataLocation = dlsym(mgl, "glGetFragDataLocation"); *(void **)&a_glGetFragDataLocation = dlsym(RTLD_NEXT, "glGetFragDataLocation"); if (p_glGetFragDataLocation) n++;
    *(void **)&p_glGetFramebufferAttachmentParameteriv = dlsym(mgl, "glGetFramebufferAttachmentParameteriv"); *(void **)&a_glGetFramebufferAttachmentParameteriv = dlsym(RTLD_NEXT, "glGetFramebufferAttachmentParameteriv"); if (p_glGetFramebufferAttachmentParameteriv) n++;
    *(void **)&p_glGetFramebufferParameteriv = dlsym(mgl, "glGetFramebufferParameteriv"); *(void **)&a_glGetFramebufferParameteriv = dlsym(RTLD_NEXT, "glGetFramebufferParameteriv"); if (p_glGetFramebufferParameteriv) n++;
    *(void **)&p_glGetGraphicsResetStatus = dlsym(mgl, "glGetGraphicsResetStatus"); *(void **)&a_glGetGraphicsResetStatus = dlsym(RTLD_NEXT, "glGetGraphicsResetStatus"); if (p_glGetGraphicsResetStatus) n++;
    *(void **)&p_glGetInteger64i_v = dlsym(mgl, "glGetInteger64i_v"); *(void **)&a_glGetInteger64i_v = dlsym(RTLD_NEXT, "glGetInteger64i_v"); if (p_glGetInteger64i_v) n++;
    *(void **)&p_glGetInteger64v = dlsym(mgl, "glGetInteger64v"); *(void **)&a_glGetInteger64v = dlsym(RTLD_NEXT, "glGetInteger64v"); if (p_glGetInteger64v) n++;
    *(void **)&p_glGetIntegeri_v = dlsym(mgl, "glGetIntegeri_v"); *(void **)&a_glGetIntegeri_v = dlsym(RTLD_NEXT, "glGetIntegeri_v"); if (p_glGetIntegeri_v) n++;
    *(void **)&p_glGetIntegerv = dlsym(mgl, "glGetIntegerv"); *(void **)&a_glGetIntegerv = dlsym(RTLD_NEXT, "glGetIntegerv"); if (p_glGetIntegerv) n++;
    *(void **)&p_glGetInternalformati64v = dlsym(mgl, "glGetInternalformati64v"); *(void **)&a_glGetInternalformati64v = dlsym(RTLD_NEXT, "glGetInternalformati64v"); if (p_glGetInternalformati64v) n++;
    *(void **)&p_glGetInternalformativ = dlsym(mgl, "glGetInternalformativ"); *(void **)&a_glGetInternalformativ = dlsym(RTLD_NEXT, "glGetInternalformativ"); if (p_glGetInternalformativ) n++;
    *(void **)&p_glGetMultisamplefv = dlsym(mgl, "glGetMultisamplefv"); *(void **)&a_glGetMultisamplefv = dlsym(RTLD_NEXT, "glGetMultisamplefv"); if (p_glGetMultisamplefv) n++;
    *(void **)&p_glGetNamedBufferParameteri64v = dlsym(mgl, "glGetNamedBufferParameteri64v"); *(void **)&a_glGetNamedBufferParameteri64v = dlsym(RTLD_NEXT, "glGetNamedBufferParameteri64v"); if (p_glGetNamedBufferParameteri64v) n++;
    *(void **)&p_glGetNamedBufferParameteriv = dlsym(mgl, "glGetNamedBufferParameteriv"); *(void **)&a_glGetNamedBufferParameteriv = dlsym(RTLD_NEXT, "glGetNamedBufferParameteriv"); if (p_glGetNamedBufferParameteriv) n++;
    *(void **)&p_glGetNamedBufferPointerv = dlsym(mgl, "glGetNamedBufferPointerv"); *(void **)&a_glGetNamedBufferPointerv = dlsym(RTLD_NEXT, "glGetNamedBufferPointerv"); if (p_glGetNamedBufferPointerv) n++;
    *(void **)&p_glGetNamedBufferSubData = dlsym(mgl, "glGetNamedBufferSubData"); *(void **)&a_glGetNamedBufferSubData = dlsym(RTLD_NEXT, "glGetNamedBufferSubData"); if (p_glGetNamedBufferSubData) n++;
    *(void **)&p_glGetNamedFramebufferAttachmentParameteriv = dlsym(mgl, "glGetNamedFramebufferAttachmentParameteriv"); *(void **)&a_glGetNamedFramebufferAttachmentParameteriv = dlsym(RTLD_NEXT, "glGetNamedFramebufferAttachmentParameteriv"); if (p_glGetNamedFramebufferAttachmentParameteriv) n++;
    *(void **)&p_glGetNamedFramebufferParameteriv = dlsym(mgl, "glGetNamedFramebufferParameteriv"); *(void **)&a_glGetNamedFramebufferParameteriv = dlsym(RTLD_NEXT, "glGetNamedFramebufferParameteriv"); if (p_glGetNamedFramebufferParameteriv) n++;
    *(void **)&p_glGetNamedRenderbufferParameteriv = dlsym(mgl, "glGetNamedRenderbufferParameteriv"); *(void **)&a_glGetNamedRenderbufferParameteriv = dlsym(RTLD_NEXT, "glGetNamedRenderbufferParameteriv"); if (p_glGetNamedRenderbufferParameteriv) n++;
    *(void **)&p_glGetObjectLabel = dlsym(mgl, "glGetObjectLabel"); *(void **)&a_glGetObjectLabel = dlsym(RTLD_NEXT, "glGetObjectLabel"); if (p_glGetObjectLabel) n++;
    *(void **)&p_glGetObjectPtrLabel = dlsym(mgl, "glGetObjectPtrLabel"); *(void **)&a_glGetObjectPtrLabel = dlsym(RTLD_NEXT, "glGetObjectPtrLabel"); if (p_glGetObjectPtrLabel) n++;
    *(void **)&p_glGetPointerv = dlsym(mgl, "glGetPointerv"); *(void **)&a_glGetPointerv = dlsym(RTLD_NEXT, "glGetPointerv"); if (p_glGetPointerv) n++;
    *(void **)&p_glGetProgramBinary = dlsym(mgl, "glGetProgramBinary"); *(void **)&a_glGetProgramBinary = dlsym(RTLD_NEXT, "glGetProgramBinary"); if (p_glGetProgramBinary) n++;
    *(void **)&p_glGetProgramInfoLog = dlsym(mgl, "glGetProgramInfoLog"); *(void **)&a_glGetProgramInfoLog = dlsym(RTLD_NEXT, "glGetProgramInfoLog"); if (p_glGetProgramInfoLog) n++;
    *(void **)&p_glGetProgramInterfaceiv = dlsym(mgl, "glGetProgramInterfaceiv"); *(void **)&a_glGetProgramInterfaceiv = dlsym(RTLD_NEXT, "glGetProgramInterfaceiv"); if (p_glGetProgramInterfaceiv) n++;
    *(void **)&p_glGetProgramPipelineInfoLog = dlsym(mgl, "glGetProgramPipelineInfoLog"); *(void **)&a_glGetProgramPipelineInfoLog = dlsym(RTLD_NEXT, "glGetProgramPipelineInfoLog"); if (p_glGetProgramPipelineInfoLog) n++;
    *(void **)&p_glGetProgramPipelineiv = dlsym(mgl, "glGetProgramPipelineiv"); *(void **)&a_glGetProgramPipelineiv = dlsym(RTLD_NEXT, "glGetProgramPipelineiv"); if (p_glGetProgramPipelineiv) n++;
    *(void **)&p_glGetProgramResourceIndex = dlsym(mgl, "glGetProgramResourceIndex"); *(void **)&a_glGetProgramResourceIndex = dlsym(RTLD_NEXT, "glGetProgramResourceIndex"); if (p_glGetProgramResourceIndex) n++;
    *(void **)&p_glGetProgramResourceLocation = dlsym(mgl, "glGetProgramResourceLocation"); *(void **)&a_glGetProgramResourceLocation = dlsym(RTLD_NEXT, "glGetProgramResourceLocation"); if (p_glGetProgramResourceLocation) n++;
    *(void **)&p_glGetProgramResourceLocationIndex = dlsym(mgl, "glGetProgramResourceLocationIndex"); *(void **)&a_glGetProgramResourceLocationIndex = dlsym(RTLD_NEXT, "glGetProgramResourceLocationIndex"); if (p_glGetProgramResourceLocationIndex) n++;
    *(void **)&p_glGetProgramResourceName = dlsym(mgl, "glGetProgramResourceName"); *(void **)&a_glGetProgramResourceName = dlsym(RTLD_NEXT, "glGetProgramResourceName"); if (p_glGetProgramResourceName) n++;
    *(void **)&p_glGetProgramResourceiv = dlsym(mgl, "glGetProgramResourceiv"); *(void **)&a_glGetProgramResourceiv = dlsym(RTLD_NEXT, "glGetProgramResourceiv"); if (p_glGetProgramResourceiv) n++;
    *(void **)&p_glGetProgramStageiv = dlsym(mgl, "glGetProgramStageiv"); *(void **)&a_glGetProgramStageiv = dlsym(RTLD_NEXT, "glGetProgramStageiv"); if (p_glGetProgramStageiv) n++;
    *(void **)&p_glGetProgramiv = dlsym(mgl, "glGetProgramiv"); *(void **)&a_glGetProgramiv = dlsym(RTLD_NEXT, "glGetProgramiv"); if (p_glGetProgramiv) n++;
    *(void **)&p_glGetQueryBufferObjecti64v = dlsym(mgl, "glGetQueryBufferObjecti64v"); *(void **)&a_glGetQueryBufferObjecti64v = dlsym(RTLD_NEXT, "glGetQueryBufferObjecti64v"); if (p_glGetQueryBufferObjecti64v) n++;
    *(void **)&p_glGetQueryBufferObjectiv = dlsym(mgl, "glGetQueryBufferObjectiv"); *(void **)&a_glGetQueryBufferObjectiv = dlsym(RTLD_NEXT, "glGetQueryBufferObjectiv"); if (p_glGetQueryBufferObjectiv) n++;
    *(void **)&p_glGetQueryBufferObjectui64v = dlsym(mgl, "glGetQueryBufferObjectui64v"); *(void **)&a_glGetQueryBufferObjectui64v = dlsym(RTLD_NEXT, "glGetQueryBufferObjectui64v"); if (p_glGetQueryBufferObjectui64v) n++;
    *(void **)&p_glGetQueryBufferObjectuiv = dlsym(mgl, "glGetQueryBufferObjectuiv"); *(void **)&a_glGetQueryBufferObjectuiv = dlsym(RTLD_NEXT, "glGetQueryBufferObjectuiv"); if (p_glGetQueryBufferObjectuiv) n++;
    *(void **)&p_glGetQueryIndexediv = dlsym(mgl, "glGetQueryIndexediv"); *(void **)&a_glGetQueryIndexediv = dlsym(RTLD_NEXT, "glGetQueryIndexediv"); if (p_glGetQueryIndexediv) n++;
    *(void **)&p_glGetQueryObjecti64v = dlsym(mgl, "glGetQueryObjecti64v"); *(void **)&a_glGetQueryObjecti64v = dlsym(RTLD_NEXT, "glGetQueryObjecti64v"); if (p_glGetQueryObjecti64v) n++;
    *(void **)&p_glGetQueryObjectiv = dlsym(mgl, "glGetQueryObjectiv"); *(void **)&a_glGetQueryObjectiv = dlsym(RTLD_NEXT, "glGetQueryObjectiv"); if (p_glGetQueryObjectiv) n++;
    *(void **)&p_glGetQueryObjectui64v = dlsym(mgl, "glGetQueryObjectui64v"); *(void **)&a_glGetQueryObjectui64v = dlsym(RTLD_NEXT, "glGetQueryObjectui64v"); if (p_glGetQueryObjectui64v) n++;
    *(void **)&p_glGetQueryObjectuiv = dlsym(mgl, "glGetQueryObjectuiv"); *(void **)&a_glGetQueryObjectuiv = dlsym(RTLD_NEXT, "glGetQueryObjectuiv"); if (p_glGetQueryObjectuiv) n++;
    *(void **)&p_glGetQueryiv = dlsym(mgl, "glGetQueryiv"); *(void **)&a_glGetQueryiv = dlsym(RTLD_NEXT, "glGetQueryiv"); if (p_glGetQueryiv) n++;
    *(void **)&p_glGetRenderbufferParameteriv = dlsym(mgl, "glGetRenderbufferParameteriv"); *(void **)&a_glGetRenderbufferParameteriv = dlsym(RTLD_NEXT, "glGetRenderbufferParameteriv"); if (p_glGetRenderbufferParameteriv) n++;
    *(void **)&p_glGetSamplerParameterIiv = dlsym(mgl, "glGetSamplerParameterIiv"); *(void **)&a_glGetSamplerParameterIiv = dlsym(RTLD_NEXT, "glGetSamplerParameterIiv"); if (p_glGetSamplerParameterIiv) n++;
    *(void **)&p_glGetSamplerParameterIuiv = dlsym(mgl, "glGetSamplerParameterIuiv"); *(void **)&a_glGetSamplerParameterIuiv = dlsym(RTLD_NEXT, "glGetSamplerParameterIuiv"); if (p_glGetSamplerParameterIuiv) n++;
    *(void **)&p_glGetSamplerParameterfv = dlsym(mgl, "glGetSamplerParameterfv"); *(void **)&a_glGetSamplerParameterfv = dlsym(RTLD_NEXT, "glGetSamplerParameterfv"); if (p_glGetSamplerParameterfv) n++;
    *(void **)&p_glGetSamplerParameteriv = dlsym(mgl, "glGetSamplerParameteriv"); *(void **)&a_glGetSamplerParameteriv = dlsym(RTLD_NEXT, "glGetSamplerParameteriv"); if (p_glGetSamplerParameteriv) n++;
    *(void **)&p_glGetShaderInfoLog = dlsym(mgl, "glGetShaderInfoLog"); *(void **)&a_glGetShaderInfoLog = dlsym(RTLD_NEXT, "glGetShaderInfoLog"); if (p_glGetShaderInfoLog) n++;
    *(void **)&p_glGetShaderPrecisionFormat = dlsym(mgl, "glGetShaderPrecisionFormat"); *(void **)&a_glGetShaderPrecisionFormat = dlsym(RTLD_NEXT, "glGetShaderPrecisionFormat"); if (p_glGetShaderPrecisionFormat) n++;
    *(void **)&p_glGetShaderSource = dlsym(mgl, "glGetShaderSource"); *(void **)&a_glGetShaderSource = dlsym(RTLD_NEXT, "glGetShaderSource"); if (p_glGetShaderSource) n++;
    *(void **)&p_glGetShaderiv = dlsym(mgl, "glGetShaderiv"); *(void **)&a_glGetShaderiv = dlsym(RTLD_NEXT, "glGetShaderiv"); if (p_glGetShaderiv) n++;
    *(void **)&p_glGetString = dlsym(mgl, "glGetString"); *(void **)&a_glGetString = dlsym(RTLD_NEXT, "glGetString"); if (p_glGetString) n++;
    *(void **)&p_glGetStringi = dlsym(mgl, "glGetStringi"); *(void **)&a_glGetStringi = dlsym(RTLD_NEXT, "glGetStringi"); if (p_glGetStringi) n++;
    *(void **)&p_glGetSubroutineIndex = dlsym(mgl, "glGetSubroutineIndex"); *(void **)&a_glGetSubroutineIndex = dlsym(RTLD_NEXT, "glGetSubroutineIndex"); if (p_glGetSubroutineIndex) n++;
    *(void **)&p_glGetSubroutineUniformLocation = dlsym(mgl, "glGetSubroutineUniformLocation"); *(void **)&a_glGetSubroutineUniformLocation = dlsym(RTLD_NEXT, "glGetSubroutineUniformLocation"); if (p_glGetSubroutineUniformLocation) n++;
    *(void **)&p_glGetSynciv = dlsym(mgl, "glGetSynciv"); *(void **)&a_glGetSynciv = dlsym(RTLD_NEXT, "glGetSynciv"); if (p_glGetSynciv) n++;
    *(void **)&p_glGetTexImage = dlsym(mgl, "glGetTexImage"); *(void **)&a_glGetTexImage = dlsym(RTLD_NEXT, "glGetTexImage"); if (p_glGetTexImage) n++;
    *(void **)&p_glGetTexLevelParameterfv = dlsym(mgl, "glGetTexLevelParameterfv"); *(void **)&a_glGetTexLevelParameterfv = dlsym(RTLD_NEXT, "glGetTexLevelParameterfv"); if (p_glGetTexLevelParameterfv) n++;
    *(void **)&p_glGetTexLevelParameteriv = dlsym(mgl, "glGetTexLevelParameteriv"); *(void **)&a_glGetTexLevelParameteriv = dlsym(RTLD_NEXT, "glGetTexLevelParameteriv"); if (p_glGetTexLevelParameteriv) n++;
    *(void **)&p_glGetTexParameterIiv = dlsym(mgl, "glGetTexParameterIiv"); *(void **)&a_glGetTexParameterIiv = dlsym(RTLD_NEXT, "glGetTexParameterIiv"); if (p_glGetTexParameterIiv) n++;
    *(void **)&p_glGetTexParameterIuiv = dlsym(mgl, "glGetTexParameterIuiv"); *(void **)&a_glGetTexParameterIuiv = dlsym(RTLD_NEXT, "glGetTexParameterIuiv"); if (p_glGetTexParameterIuiv) n++;
    *(void **)&p_glGetTexParameterfv = dlsym(mgl, "glGetTexParameterfv"); *(void **)&a_glGetTexParameterfv = dlsym(RTLD_NEXT, "glGetTexParameterfv"); if (p_glGetTexParameterfv) n++;
    *(void **)&p_glGetTexParameteriv = dlsym(mgl, "glGetTexParameteriv"); *(void **)&a_glGetTexParameteriv = dlsym(RTLD_NEXT, "glGetTexParameteriv"); if (p_glGetTexParameteriv) n++;
    *(void **)&p_glGetTextureImage = dlsym(mgl, "glGetTextureImage"); *(void **)&a_glGetTextureImage = dlsym(RTLD_NEXT, "glGetTextureImage"); if (p_glGetTextureImage) n++;
    *(void **)&p_glGetTextureLevelParameterfv = dlsym(mgl, "glGetTextureLevelParameterfv"); *(void **)&a_glGetTextureLevelParameterfv = dlsym(RTLD_NEXT, "glGetTextureLevelParameterfv"); if (p_glGetTextureLevelParameterfv) n++;
    *(void **)&p_glGetTextureLevelParameteriv = dlsym(mgl, "glGetTextureLevelParameteriv"); *(void **)&a_glGetTextureLevelParameteriv = dlsym(RTLD_NEXT, "glGetTextureLevelParameteriv"); if (p_glGetTextureLevelParameteriv) n++;
    *(void **)&p_glGetTextureParameterIiv = dlsym(mgl, "glGetTextureParameterIiv"); *(void **)&a_glGetTextureParameterIiv = dlsym(RTLD_NEXT, "glGetTextureParameterIiv"); if (p_glGetTextureParameterIiv) n++;
    *(void **)&p_glGetTextureParameterIuiv = dlsym(mgl, "glGetTextureParameterIuiv"); *(void **)&a_glGetTextureParameterIuiv = dlsym(RTLD_NEXT, "glGetTextureParameterIuiv"); if (p_glGetTextureParameterIuiv) n++;
    *(void **)&p_glGetTextureParameterfv = dlsym(mgl, "glGetTextureParameterfv"); *(void **)&a_glGetTextureParameterfv = dlsym(RTLD_NEXT, "glGetTextureParameterfv"); if (p_glGetTextureParameterfv) n++;
    *(void **)&p_glGetTextureParameteriv = dlsym(mgl, "glGetTextureParameteriv"); *(void **)&a_glGetTextureParameteriv = dlsym(RTLD_NEXT, "glGetTextureParameteriv"); if (p_glGetTextureParameteriv) n++;
    *(void **)&p_glGetTextureSubImage = dlsym(mgl, "glGetTextureSubImage"); *(void **)&a_glGetTextureSubImage = dlsym(RTLD_NEXT, "glGetTextureSubImage"); if (p_glGetTextureSubImage) n++;
    *(void **)&p_glGetTransformFeedbackVarying = dlsym(mgl, "glGetTransformFeedbackVarying"); *(void **)&a_glGetTransformFeedbackVarying = dlsym(RTLD_NEXT, "glGetTransformFeedbackVarying"); if (p_glGetTransformFeedbackVarying) n++;
    *(void **)&p_glGetTransformFeedbacki64_v = dlsym(mgl, "glGetTransformFeedbacki64_v"); *(void **)&a_glGetTransformFeedbacki64_v = dlsym(RTLD_NEXT, "glGetTransformFeedbacki64_v"); if (p_glGetTransformFeedbacki64_v) n++;
    *(void **)&p_glGetTransformFeedbacki_v = dlsym(mgl, "glGetTransformFeedbacki_v"); *(void **)&a_glGetTransformFeedbacki_v = dlsym(RTLD_NEXT, "glGetTransformFeedbacki_v"); if (p_glGetTransformFeedbacki_v) n++;
    *(void **)&p_glGetTransformFeedbackiv = dlsym(mgl, "glGetTransformFeedbackiv"); *(void **)&a_glGetTransformFeedbackiv = dlsym(RTLD_NEXT, "glGetTransformFeedbackiv"); if (p_glGetTransformFeedbackiv) n++;
    *(void **)&p_glGetUniformBlockIndex = dlsym(mgl, "glGetUniformBlockIndex"); *(void **)&a_glGetUniformBlockIndex = dlsym(RTLD_NEXT, "glGetUniformBlockIndex"); if (p_glGetUniformBlockIndex) n++;
    *(void **)&p_glGetUniformIndices = dlsym(mgl, "glGetUniformIndices"); *(void **)&a_glGetUniformIndices = dlsym(RTLD_NEXT, "glGetUniformIndices"); if (p_glGetUniformIndices) n++;
    *(void **)&p_glGetUniformLocation = dlsym(mgl, "glGetUniformLocation"); *(void **)&a_glGetUniformLocation = dlsym(RTLD_NEXT, "glGetUniformLocation"); if (p_glGetUniformLocation) n++;
    *(void **)&p_glGetUniformSubroutineuiv = dlsym(mgl, "glGetUniformSubroutineuiv"); *(void **)&a_glGetUniformSubroutineuiv = dlsym(RTLD_NEXT, "glGetUniformSubroutineuiv"); if (p_glGetUniformSubroutineuiv) n++;
    *(void **)&p_glGetUniformdv = dlsym(mgl, "glGetUniformdv"); *(void **)&a_glGetUniformdv = dlsym(RTLD_NEXT, "glGetUniformdv"); if (p_glGetUniformdv) n++;
    *(void **)&p_glGetUniformfv = dlsym(mgl, "glGetUniformfv"); *(void **)&a_glGetUniformfv = dlsym(RTLD_NEXT, "glGetUniformfv"); if (p_glGetUniformfv) n++;
    *(void **)&p_glGetUniformiv = dlsym(mgl, "glGetUniformiv"); *(void **)&a_glGetUniformiv = dlsym(RTLD_NEXT, "glGetUniformiv"); if (p_glGetUniformiv) n++;
    *(void **)&p_glGetUniformuiv = dlsym(mgl, "glGetUniformuiv"); *(void **)&a_glGetUniformuiv = dlsym(RTLD_NEXT, "glGetUniformuiv"); if (p_glGetUniformuiv) n++;
    *(void **)&p_glGetVertexArrayIndexed64iv = dlsym(mgl, "glGetVertexArrayIndexed64iv"); *(void **)&a_glGetVertexArrayIndexed64iv = dlsym(RTLD_NEXT, "glGetVertexArrayIndexed64iv"); if (p_glGetVertexArrayIndexed64iv) n++;
    *(void **)&p_glGetVertexArrayIndexediv = dlsym(mgl, "glGetVertexArrayIndexediv"); *(void **)&a_glGetVertexArrayIndexediv = dlsym(RTLD_NEXT, "glGetVertexArrayIndexediv"); if (p_glGetVertexArrayIndexediv) n++;
    *(void **)&p_glGetVertexArrayiv = dlsym(mgl, "glGetVertexArrayiv"); *(void **)&a_glGetVertexArrayiv = dlsym(RTLD_NEXT, "glGetVertexArrayiv"); if (p_glGetVertexArrayiv) n++;
    *(void **)&p_glGetVertexAttribIiv = dlsym(mgl, "glGetVertexAttribIiv"); *(void **)&a_glGetVertexAttribIiv = dlsym(RTLD_NEXT, "glGetVertexAttribIiv"); if (p_glGetVertexAttribIiv) n++;
    *(void **)&p_glGetVertexAttribIuiv = dlsym(mgl, "glGetVertexAttribIuiv"); *(void **)&a_glGetVertexAttribIuiv = dlsym(RTLD_NEXT, "glGetVertexAttribIuiv"); if (p_glGetVertexAttribIuiv) n++;
    *(void **)&p_glGetVertexAttribLdv = dlsym(mgl, "glGetVertexAttribLdv"); *(void **)&a_glGetVertexAttribLdv = dlsym(RTLD_NEXT, "glGetVertexAttribLdv"); if (p_glGetVertexAttribLdv) n++;
    *(void **)&p_glGetVertexAttribPointerv = dlsym(mgl, "glGetVertexAttribPointerv"); *(void **)&a_glGetVertexAttribPointerv = dlsym(RTLD_NEXT, "glGetVertexAttribPointerv"); if (p_glGetVertexAttribPointerv) n++;
    *(void **)&p_glGetVertexAttribdv = dlsym(mgl, "glGetVertexAttribdv"); *(void **)&a_glGetVertexAttribdv = dlsym(RTLD_NEXT, "glGetVertexAttribdv"); if (p_glGetVertexAttribdv) n++;
    *(void **)&p_glGetVertexAttribfv = dlsym(mgl, "glGetVertexAttribfv"); *(void **)&a_glGetVertexAttribfv = dlsym(RTLD_NEXT, "glGetVertexAttribfv"); if (p_glGetVertexAttribfv) n++;
    *(void **)&p_glGetVertexAttribiv = dlsym(mgl, "glGetVertexAttribiv"); *(void **)&a_glGetVertexAttribiv = dlsym(RTLD_NEXT, "glGetVertexAttribiv"); if (p_glGetVertexAttribiv) n++;
    *(void **)&p_glGetnCompressedTexImage = dlsym(mgl, "glGetnCompressedTexImage"); *(void **)&a_glGetnCompressedTexImage = dlsym(RTLD_NEXT, "glGetnCompressedTexImage"); if (p_glGetnCompressedTexImage) n++;
    *(void **)&p_glGetnTexImage = dlsym(mgl, "glGetnTexImage"); *(void **)&a_glGetnTexImage = dlsym(RTLD_NEXT, "glGetnTexImage"); if (p_glGetnTexImage) n++;
    *(void **)&p_glGetnUniformdv = dlsym(mgl, "glGetnUniformdv"); *(void **)&a_glGetnUniformdv = dlsym(RTLD_NEXT, "glGetnUniformdv"); if (p_glGetnUniformdv) n++;
    *(void **)&p_glGetnUniformfv = dlsym(mgl, "glGetnUniformfv"); *(void **)&a_glGetnUniformfv = dlsym(RTLD_NEXT, "glGetnUniformfv"); if (p_glGetnUniformfv) n++;
    *(void **)&p_glGetnUniformiv = dlsym(mgl, "glGetnUniformiv"); *(void **)&a_glGetnUniformiv = dlsym(RTLD_NEXT, "glGetnUniformiv"); if (p_glGetnUniformiv) n++;
    *(void **)&p_glGetnUniformuiv = dlsym(mgl, "glGetnUniformuiv"); *(void **)&a_glGetnUniformuiv = dlsym(RTLD_NEXT, "glGetnUniformuiv"); if (p_glGetnUniformuiv) n++;
    *(void **)&p_glHint = dlsym(mgl, "glHint"); *(void **)&a_glHint = dlsym(RTLD_NEXT, "glHint"); if (p_glHint) n++;
    *(void **)&p_glInvalidateBufferData = dlsym(mgl, "glInvalidateBufferData"); *(void **)&a_glInvalidateBufferData = dlsym(RTLD_NEXT, "glInvalidateBufferData"); if (p_glInvalidateBufferData) n++;
    *(void **)&p_glInvalidateBufferSubData = dlsym(mgl, "glInvalidateBufferSubData"); *(void **)&a_glInvalidateBufferSubData = dlsym(RTLD_NEXT, "glInvalidateBufferSubData"); if (p_glInvalidateBufferSubData) n++;
    *(void **)&p_glInvalidateFramebuffer = dlsym(mgl, "glInvalidateFramebuffer"); *(void **)&a_glInvalidateFramebuffer = dlsym(RTLD_NEXT, "glInvalidateFramebuffer"); if (p_glInvalidateFramebuffer) n++;
    *(void **)&p_glInvalidateNamedFramebufferData = dlsym(mgl, "glInvalidateNamedFramebufferData"); *(void **)&a_glInvalidateNamedFramebufferData = dlsym(RTLD_NEXT, "glInvalidateNamedFramebufferData"); if (p_glInvalidateNamedFramebufferData) n++;
    *(void **)&p_glInvalidateNamedFramebufferSubData = dlsym(mgl, "glInvalidateNamedFramebufferSubData"); *(void **)&a_glInvalidateNamedFramebufferSubData = dlsym(RTLD_NEXT, "glInvalidateNamedFramebufferSubData"); if (p_glInvalidateNamedFramebufferSubData) n++;
    *(void **)&p_glInvalidateSubFramebuffer = dlsym(mgl, "glInvalidateSubFramebuffer"); *(void **)&a_glInvalidateSubFramebuffer = dlsym(RTLD_NEXT, "glInvalidateSubFramebuffer"); if (p_glInvalidateSubFramebuffer) n++;
    *(void **)&p_glInvalidateTexImage = dlsym(mgl, "glInvalidateTexImage"); *(void **)&a_glInvalidateTexImage = dlsym(RTLD_NEXT, "glInvalidateTexImage"); if (p_glInvalidateTexImage) n++;
    *(void **)&p_glInvalidateTexSubImage = dlsym(mgl, "glInvalidateTexSubImage"); *(void **)&a_glInvalidateTexSubImage = dlsym(RTLD_NEXT, "glInvalidateTexSubImage"); if (p_glInvalidateTexSubImage) n++;
    *(void **)&p_glIsBuffer = dlsym(mgl, "glIsBuffer"); *(void **)&a_glIsBuffer = dlsym(RTLD_NEXT, "glIsBuffer"); if (p_glIsBuffer) n++;
    *(void **)&p_glIsEnabled = dlsym(mgl, "glIsEnabled"); *(void **)&a_glIsEnabled = dlsym(RTLD_NEXT, "glIsEnabled"); if (p_glIsEnabled) n++;
    *(void **)&p_glIsEnabledi = dlsym(mgl, "glIsEnabledi"); *(void **)&a_glIsEnabledi = dlsym(RTLD_NEXT, "glIsEnabledi"); if (p_glIsEnabledi) n++;
    *(void **)&p_glIsFramebuffer = dlsym(mgl, "glIsFramebuffer"); *(void **)&a_glIsFramebuffer = dlsym(RTLD_NEXT, "glIsFramebuffer"); if (p_glIsFramebuffer) n++;
    *(void **)&p_glIsProgram = dlsym(mgl, "glIsProgram"); *(void **)&a_glIsProgram = dlsym(RTLD_NEXT, "glIsProgram"); if (p_glIsProgram) n++;
    *(void **)&p_glIsProgramPipeline = dlsym(mgl, "glIsProgramPipeline"); *(void **)&a_glIsProgramPipeline = dlsym(RTLD_NEXT, "glIsProgramPipeline"); if (p_glIsProgramPipeline) n++;
    *(void **)&p_glIsQuery = dlsym(mgl, "glIsQuery"); *(void **)&a_glIsQuery = dlsym(RTLD_NEXT, "glIsQuery"); if (p_glIsQuery) n++;
    *(void **)&p_glIsRenderbuffer = dlsym(mgl, "glIsRenderbuffer"); *(void **)&a_glIsRenderbuffer = dlsym(RTLD_NEXT, "glIsRenderbuffer"); if (p_glIsRenderbuffer) n++;
    *(void **)&p_glIsSampler = dlsym(mgl, "glIsSampler"); *(void **)&a_glIsSampler = dlsym(RTLD_NEXT, "glIsSampler"); if (p_glIsSampler) n++;
    *(void **)&p_glIsShader = dlsym(mgl, "glIsShader"); *(void **)&a_glIsShader = dlsym(RTLD_NEXT, "glIsShader"); if (p_glIsShader) n++;
    *(void **)&p_glIsSync = dlsym(mgl, "glIsSync"); *(void **)&a_glIsSync = dlsym(RTLD_NEXT, "glIsSync"); if (p_glIsSync) n++;
    *(void **)&p_glIsTexture = dlsym(mgl, "glIsTexture"); *(void **)&a_glIsTexture = dlsym(RTLD_NEXT, "glIsTexture"); if (p_glIsTexture) n++;
    *(void **)&p_glIsTransformFeedback = dlsym(mgl, "glIsTransformFeedback"); *(void **)&a_glIsTransformFeedback = dlsym(RTLD_NEXT, "glIsTransformFeedback"); if (p_glIsTransformFeedback) n++;
    *(void **)&p_glIsVertexArray = dlsym(mgl, "glIsVertexArray"); *(void **)&a_glIsVertexArray = dlsym(RTLD_NEXT, "glIsVertexArray"); if (p_glIsVertexArray) n++;
    *(void **)&p_glLineWidth = dlsym(mgl, "glLineWidth"); *(void **)&a_glLineWidth = dlsym(RTLD_NEXT, "glLineWidth"); if (p_glLineWidth) n++;
    *(void **)&p_glLinkProgram = dlsym(mgl, "glLinkProgram"); *(void **)&a_glLinkProgram = dlsym(RTLD_NEXT, "glLinkProgram"); if (p_glLinkProgram) n++;
    *(void **)&p_glLogicOp = dlsym(mgl, "glLogicOp"); *(void **)&a_glLogicOp = dlsym(RTLD_NEXT, "glLogicOp"); if (p_glLogicOp) n++;
    *(void **)&p_glMapBuffer = dlsym(mgl, "glMapBuffer"); *(void **)&a_glMapBuffer = dlsym(RTLD_NEXT, "glMapBuffer"); if (p_glMapBuffer) n++;
    *(void **)&p_glMapBufferRange = dlsym(mgl, "glMapBufferRange"); *(void **)&a_glMapBufferRange = dlsym(RTLD_NEXT, "glMapBufferRange"); if (p_glMapBufferRange) n++;
    *(void **)&p_glMapNamedBuffer = dlsym(mgl, "glMapNamedBuffer"); *(void **)&a_glMapNamedBuffer = dlsym(RTLD_NEXT, "glMapNamedBuffer"); if (p_glMapNamedBuffer) n++;
    *(void **)&p_glMapNamedBufferRange = dlsym(mgl, "glMapNamedBufferRange"); *(void **)&a_glMapNamedBufferRange = dlsym(RTLD_NEXT, "glMapNamedBufferRange"); if (p_glMapNamedBufferRange) n++;
    *(void **)&p_glMemoryBarrier = dlsym(mgl, "glMemoryBarrier"); *(void **)&a_glMemoryBarrier = dlsym(RTLD_NEXT, "glMemoryBarrier"); if (p_glMemoryBarrier) n++;
    *(void **)&p_glMemoryBarrierByRegion = dlsym(mgl, "glMemoryBarrierByRegion"); *(void **)&a_glMemoryBarrierByRegion = dlsym(RTLD_NEXT, "glMemoryBarrierByRegion"); if (p_glMemoryBarrierByRegion) n++;
    *(void **)&p_glMinSampleShading = dlsym(mgl, "glMinSampleShading"); *(void **)&a_glMinSampleShading = dlsym(RTLD_NEXT, "glMinSampleShading"); if (p_glMinSampleShading) n++;
    *(void **)&p_glMultiDrawArrays = dlsym(mgl, "glMultiDrawArrays"); *(void **)&a_glMultiDrawArrays = dlsym(RTLD_NEXT, "glMultiDrawArrays"); if (p_glMultiDrawArrays) n++;
    *(void **)&p_glMultiDrawArraysIndirect = dlsym(mgl, "glMultiDrawArraysIndirect"); *(void **)&a_glMultiDrawArraysIndirect = dlsym(RTLD_NEXT, "glMultiDrawArraysIndirect"); if (p_glMultiDrawArraysIndirect) n++;
    *(void **)&p_glMultiDrawArraysIndirectCount = dlsym(mgl, "glMultiDrawArraysIndirectCount"); *(void **)&a_glMultiDrawArraysIndirectCount = dlsym(RTLD_NEXT, "glMultiDrawArraysIndirectCount"); if (p_glMultiDrawArraysIndirectCount) n++;
    *(void **)&p_glMultiDrawElements = dlsym(mgl, "glMultiDrawElements"); *(void **)&a_glMultiDrawElements = dlsym(RTLD_NEXT, "glMultiDrawElements"); if (p_glMultiDrawElements) n++;
    *(void **)&p_glMultiDrawElementsBaseVertex = dlsym(mgl, "glMultiDrawElementsBaseVertex"); *(void **)&a_glMultiDrawElementsBaseVertex = dlsym(RTLD_NEXT, "glMultiDrawElementsBaseVertex"); if (p_glMultiDrawElementsBaseVertex) n++;
    *(void **)&p_glMultiDrawElementsIndirect = dlsym(mgl, "glMultiDrawElementsIndirect"); *(void **)&a_glMultiDrawElementsIndirect = dlsym(RTLD_NEXT, "glMultiDrawElementsIndirect"); if (p_glMultiDrawElementsIndirect) n++;
    *(void **)&p_glMultiDrawElementsIndirectCount = dlsym(mgl, "glMultiDrawElementsIndirectCount"); *(void **)&a_glMultiDrawElementsIndirectCount = dlsym(RTLD_NEXT, "glMultiDrawElementsIndirectCount"); if (p_glMultiDrawElementsIndirectCount) n++;
    *(void **)&p_glNamedBufferData = dlsym(mgl, "glNamedBufferData"); *(void **)&a_glNamedBufferData = dlsym(RTLD_NEXT, "glNamedBufferData"); if (p_glNamedBufferData) n++;
    *(void **)&p_glNamedBufferStorage = dlsym(mgl, "glNamedBufferStorage"); *(void **)&a_glNamedBufferStorage = dlsym(RTLD_NEXT, "glNamedBufferStorage"); if (p_glNamedBufferStorage) n++;
    *(void **)&p_glNamedBufferSubData = dlsym(mgl, "glNamedBufferSubData"); *(void **)&a_glNamedBufferSubData = dlsym(RTLD_NEXT, "glNamedBufferSubData"); if (p_glNamedBufferSubData) n++;
    *(void **)&p_glNamedFramebufferDrawBuffer = dlsym(mgl, "glNamedFramebufferDrawBuffer"); *(void **)&a_glNamedFramebufferDrawBuffer = dlsym(RTLD_NEXT, "glNamedFramebufferDrawBuffer"); if (p_glNamedFramebufferDrawBuffer) n++;
    *(void **)&p_glNamedFramebufferDrawBuffers = dlsym(mgl, "glNamedFramebufferDrawBuffers"); *(void **)&a_glNamedFramebufferDrawBuffers = dlsym(RTLD_NEXT, "glNamedFramebufferDrawBuffers"); if (p_glNamedFramebufferDrawBuffers) n++;
    *(void **)&p_glNamedFramebufferParameteri = dlsym(mgl, "glNamedFramebufferParameteri"); *(void **)&a_glNamedFramebufferParameteri = dlsym(RTLD_NEXT, "glNamedFramebufferParameteri"); if (p_glNamedFramebufferParameteri) n++;
    *(void **)&p_glNamedFramebufferReadBuffer = dlsym(mgl, "glNamedFramebufferReadBuffer"); *(void **)&a_glNamedFramebufferReadBuffer = dlsym(RTLD_NEXT, "glNamedFramebufferReadBuffer"); if (p_glNamedFramebufferReadBuffer) n++;
    *(void **)&p_glNamedFramebufferRenderbuffer = dlsym(mgl, "glNamedFramebufferRenderbuffer"); *(void **)&a_glNamedFramebufferRenderbuffer = dlsym(RTLD_NEXT, "glNamedFramebufferRenderbuffer"); if (p_glNamedFramebufferRenderbuffer) n++;
    *(void **)&p_glNamedFramebufferTexture = dlsym(mgl, "glNamedFramebufferTexture"); *(void **)&a_glNamedFramebufferTexture = dlsym(RTLD_NEXT, "glNamedFramebufferTexture"); if (p_glNamedFramebufferTexture) n++;
    *(void **)&p_glNamedFramebufferTextureLayer = dlsym(mgl, "glNamedFramebufferTextureLayer"); *(void **)&a_glNamedFramebufferTextureLayer = dlsym(RTLD_NEXT, "glNamedFramebufferTextureLayer"); if (p_glNamedFramebufferTextureLayer) n++;
    *(void **)&p_glNamedRenderbufferStorage = dlsym(mgl, "glNamedRenderbufferStorage"); *(void **)&a_glNamedRenderbufferStorage = dlsym(RTLD_NEXT, "glNamedRenderbufferStorage"); if (p_glNamedRenderbufferStorage) n++;
    *(void **)&p_glNamedRenderbufferStorageMultisample = dlsym(mgl, "glNamedRenderbufferStorageMultisample"); *(void **)&a_glNamedRenderbufferStorageMultisample = dlsym(RTLD_NEXT, "glNamedRenderbufferStorageMultisample"); if (p_glNamedRenderbufferStorageMultisample) n++;
    *(void **)&p_glObjectLabel = dlsym(mgl, "glObjectLabel"); *(void **)&a_glObjectLabel = dlsym(RTLD_NEXT, "glObjectLabel"); if (p_glObjectLabel) n++;
    *(void **)&p_glObjectPtrLabel = dlsym(mgl, "glObjectPtrLabel"); *(void **)&a_glObjectPtrLabel = dlsym(RTLD_NEXT, "glObjectPtrLabel"); if (p_glObjectPtrLabel) n++;
    *(void **)&p_glPatchParameterfv = dlsym(mgl, "glPatchParameterfv"); *(void **)&a_glPatchParameterfv = dlsym(RTLD_NEXT, "glPatchParameterfv"); if (p_glPatchParameterfv) n++;
    *(void **)&p_glPatchParameteri = dlsym(mgl, "glPatchParameteri"); *(void **)&a_glPatchParameteri = dlsym(RTLD_NEXT, "glPatchParameteri"); if (p_glPatchParameteri) n++;
    *(void **)&p_glPauseTransformFeedback = dlsym(mgl, "glPauseTransformFeedback"); *(void **)&a_glPauseTransformFeedback = dlsym(RTLD_NEXT, "glPauseTransformFeedback"); if (p_glPauseTransformFeedback) n++;
    *(void **)&p_glPixelStoref = dlsym(mgl, "glPixelStoref"); *(void **)&a_glPixelStoref = dlsym(RTLD_NEXT, "glPixelStoref"); if (p_glPixelStoref) n++;
    *(void **)&p_glPixelStorei = dlsym(mgl, "glPixelStorei"); *(void **)&a_glPixelStorei = dlsym(RTLD_NEXT, "glPixelStorei"); if (p_glPixelStorei) n++;
    *(void **)&p_glPointParameterf = dlsym(mgl, "glPointParameterf"); *(void **)&a_glPointParameterf = dlsym(RTLD_NEXT, "glPointParameterf"); if (p_glPointParameterf) n++;
    *(void **)&p_glPointParameterfv = dlsym(mgl, "glPointParameterfv"); *(void **)&a_glPointParameterfv = dlsym(RTLD_NEXT, "glPointParameterfv"); if (p_glPointParameterfv) n++;
    *(void **)&p_glPointParameteri = dlsym(mgl, "glPointParameteri"); *(void **)&a_glPointParameteri = dlsym(RTLD_NEXT, "glPointParameteri"); if (p_glPointParameteri) n++;
    *(void **)&p_glPointParameteriv = dlsym(mgl, "glPointParameteriv"); *(void **)&a_glPointParameteriv = dlsym(RTLD_NEXT, "glPointParameteriv"); if (p_glPointParameteriv) n++;
    *(void **)&p_glPointSize = dlsym(mgl, "glPointSize"); *(void **)&a_glPointSize = dlsym(RTLD_NEXT, "glPointSize"); if (p_glPointSize) n++;
    *(void **)&p_glPolygonMode = dlsym(mgl, "glPolygonMode"); *(void **)&a_glPolygonMode = dlsym(RTLD_NEXT, "glPolygonMode"); if (p_glPolygonMode) n++;
    *(void **)&p_glPolygonOffset = dlsym(mgl, "glPolygonOffset"); *(void **)&a_glPolygonOffset = dlsym(RTLD_NEXT, "glPolygonOffset"); if (p_glPolygonOffset) n++;
    *(void **)&p_glPolygonOffsetClamp = dlsym(mgl, "glPolygonOffsetClamp"); *(void **)&a_glPolygonOffsetClamp = dlsym(RTLD_NEXT, "glPolygonOffsetClamp"); if (p_glPolygonOffsetClamp) n++;
    *(void **)&p_glPopDebugGroup = dlsym(mgl, "glPopDebugGroup"); *(void **)&a_glPopDebugGroup = dlsym(RTLD_NEXT, "glPopDebugGroup"); if (p_glPopDebugGroup) n++;
    *(void **)&p_glPrimitiveRestartIndex = dlsym(mgl, "glPrimitiveRestartIndex"); *(void **)&a_glPrimitiveRestartIndex = dlsym(RTLD_NEXT, "glPrimitiveRestartIndex"); if (p_glPrimitiveRestartIndex) n++;
    *(void **)&p_glProgramBinary = dlsym(mgl, "glProgramBinary"); *(void **)&a_glProgramBinary = dlsym(RTLD_NEXT, "glProgramBinary"); if (p_glProgramBinary) n++;
    *(void **)&p_glProgramParameteri = dlsym(mgl, "glProgramParameteri"); *(void **)&a_glProgramParameteri = dlsym(RTLD_NEXT, "glProgramParameteri"); if (p_glProgramParameteri) n++;
    *(void **)&p_glProgramUniform1d = dlsym(mgl, "glProgramUniform1d"); *(void **)&a_glProgramUniform1d = dlsym(RTLD_NEXT, "glProgramUniform1d"); if (p_glProgramUniform1d) n++;
    *(void **)&p_glProgramUniform1dv = dlsym(mgl, "glProgramUniform1dv"); *(void **)&a_glProgramUniform1dv = dlsym(RTLD_NEXT, "glProgramUniform1dv"); if (p_glProgramUniform1dv) n++;
    *(void **)&p_glProgramUniform1f = dlsym(mgl, "glProgramUniform1f"); *(void **)&a_glProgramUniform1f = dlsym(RTLD_NEXT, "glProgramUniform1f"); if (p_glProgramUniform1f) n++;
    *(void **)&p_glProgramUniform1fv = dlsym(mgl, "glProgramUniform1fv"); *(void **)&a_glProgramUniform1fv = dlsym(RTLD_NEXT, "glProgramUniform1fv"); if (p_glProgramUniform1fv) n++;
    *(void **)&p_glProgramUniform1i = dlsym(mgl, "glProgramUniform1i"); *(void **)&a_glProgramUniform1i = dlsym(RTLD_NEXT, "glProgramUniform1i"); if (p_glProgramUniform1i) n++;
    *(void **)&p_glProgramUniform1iv = dlsym(mgl, "glProgramUniform1iv"); *(void **)&a_glProgramUniform1iv = dlsym(RTLD_NEXT, "glProgramUniform1iv"); if (p_glProgramUniform1iv) n++;
    *(void **)&p_glProgramUniform1ui = dlsym(mgl, "glProgramUniform1ui"); *(void **)&a_glProgramUniform1ui = dlsym(RTLD_NEXT, "glProgramUniform1ui"); if (p_glProgramUniform1ui) n++;
    *(void **)&p_glProgramUniform1uiv = dlsym(mgl, "glProgramUniform1uiv"); *(void **)&a_glProgramUniform1uiv = dlsym(RTLD_NEXT, "glProgramUniform1uiv"); if (p_glProgramUniform1uiv) n++;
    *(void **)&p_glProgramUniform2d = dlsym(mgl, "glProgramUniform2d"); *(void **)&a_glProgramUniform2d = dlsym(RTLD_NEXT, "glProgramUniform2d"); if (p_glProgramUniform2d) n++;
    *(void **)&p_glProgramUniform2dv = dlsym(mgl, "glProgramUniform2dv"); *(void **)&a_glProgramUniform2dv = dlsym(RTLD_NEXT, "glProgramUniform2dv"); if (p_glProgramUniform2dv) n++;
    *(void **)&p_glProgramUniform2f = dlsym(mgl, "glProgramUniform2f"); *(void **)&a_glProgramUniform2f = dlsym(RTLD_NEXT, "glProgramUniform2f"); if (p_glProgramUniform2f) n++;
    *(void **)&p_glProgramUniform2fv = dlsym(mgl, "glProgramUniform2fv"); *(void **)&a_glProgramUniform2fv = dlsym(RTLD_NEXT, "glProgramUniform2fv"); if (p_glProgramUniform2fv) n++;
    *(void **)&p_glProgramUniform2i = dlsym(mgl, "glProgramUniform2i"); *(void **)&a_glProgramUniform2i = dlsym(RTLD_NEXT, "glProgramUniform2i"); if (p_glProgramUniform2i) n++;
    *(void **)&p_glProgramUniform2iv = dlsym(mgl, "glProgramUniform2iv"); *(void **)&a_glProgramUniform2iv = dlsym(RTLD_NEXT, "glProgramUniform2iv"); if (p_glProgramUniform2iv) n++;
    *(void **)&p_glProgramUniform2ui = dlsym(mgl, "glProgramUniform2ui"); *(void **)&a_glProgramUniform2ui = dlsym(RTLD_NEXT, "glProgramUniform2ui"); if (p_glProgramUniform2ui) n++;
    *(void **)&p_glProgramUniform2uiv = dlsym(mgl, "glProgramUniform2uiv"); *(void **)&a_glProgramUniform2uiv = dlsym(RTLD_NEXT, "glProgramUniform2uiv"); if (p_glProgramUniform2uiv) n++;
    *(void **)&p_glProgramUniform3d = dlsym(mgl, "glProgramUniform3d"); *(void **)&a_glProgramUniform3d = dlsym(RTLD_NEXT, "glProgramUniform3d"); if (p_glProgramUniform3d) n++;
    *(void **)&p_glProgramUniform3dv = dlsym(mgl, "glProgramUniform3dv"); *(void **)&a_glProgramUniform3dv = dlsym(RTLD_NEXT, "glProgramUniform3dv"); if (p_glProgramUniform3dv) n++;
    *(void **)&p_glProgramUniform3f = dlsym(mgl, "glProgramUniform3f"); *(void **)&a_glProgramUniform3f = dlsym(RTLD_NEXT, "glProgramUniform3f"); if (p_glProgramUniform3f) n++;
    *(void **)&p_glProgramUniform3fv = dlsym(mgl, "glProgramUniform3fv"); *(void **)&a_glProgramUniform3fv = dlsym(RTLD_NEXT, "glProgramUniform3fv"); if (p_glProgramUniform3fv) n++;
    *(void **)&p_glProgramUniform3i = dlsym(mgl, "glProgramUniform3i"); *(void **)&a_glProgramUniform3i = dlsym(RTLD_NEXT, "glProgramUniform3i"); if (p_glProgramUniform3i) n++;
    *(void **)&p_glProgramUniform3iv = dlsym(mgl, "glProgramUniform3iv"); *(void **)&a_glProgramUniform3iv = dlsym(RTLD_NEXT, "glProgramUniform3iv"); if (p_glProgramUniform3iv) n++;
    *(void **)&p_glProgramUniform3ui = dlsym(mgl, "glProgramUniform3ui"); *(void **)&a_glProgramUniform3ui = dlsym(RTLD_NEXT, "glProgramUniform3ui"); if (p_glProgramUniform3ui) n++;
    *(void **)&p_glProgramUniform3uiv = dlsym(mgl, "glProgramUniform3uiv"); *(void **)&a_glProgramUniform3uiv = dlsym(RTLD_NEXT, "glProgramUniform3uiv"); if (p_glProgramUniform3uiv) n++;
    *(void **)&p_glProgramUniform4d = dlsym(mgl, "glProgramUniform4d"); *(void **)&a_glProgramUniform4d = dlsym(RTLD_NEXT, "glProgramUniform4d"); if (p_glProgramUniform4d) n++;
    *(void **)&p_glProgramUniform4dv = dlsym(mgl, "glProgramUniform4dv"); *(void **)&a_glProgramUniform4dv = dlsym(RTLD_NEXT, "glProgramUniform4dv"); if (p_glProgramUniform4dv) n++;
    *(void **)&p_glProgramUniform4f = dlsym(mgl, "glProgramUniform4f"); *(void **)&a_glProgramUniform4f = dlsym(RTLD_NEXT, "glProgramUniform4f"); if (p_glProgramUniform4f) n++;
    *(void **)&p_glProgramUniform4fv = dlsym(mgl, "glProgramUniform4fv"); *(void **)&a_glProgramUniform4fv = dlsym(RTLD_NEXT, "glProgramUniform4fv"); if (p_glProgramUniform4fv) n++;
    *(void **)&p_glProgramUniform4i = dlsym(mgl, "glProgramUniform4i"); *(void **)&a_glProgramUniform4i = dlsym(RTLD_NEXT, "glProgramUniform4i"); if (p_glProgramUniform4i) n++;
    *(void **)&p_glProgramUniform4iv = dlsym(mgl, "glProgramUniform4iv"); *(void **)&a_glProgramUniform4iv = dlsym(RTLD_NEXT, "glProgramUniform4iv"); if (p_glProgramUniform4iv) n++;
    *(void **)&p_glProgramUniform4ui = dlsym(mgl, "glProgramUniform4ui"); *(void **)&a_glProgramUniform4ui = dlsym(RTLD_NEXT, "glProgramUniform4ui"); if (p_glProgramUniform4ui) n++;
    *(void **)&p_glProgramUniform4uiv = dlsym(mgl, "glProgramUniform4uiv"); *(void **)&a_glProgramUniform4uiv = dlsym(RTLD_NEXT, "glProgramUniform4uiv"); if (p_glProgramUniform4uiv) n++;
    *(void **)&p_glProgramUniformMatrix2dv = dlsym(mgl, "glProgramUniformMatrix2dv"); *(void **)&a_glProgramUniformMatrix2dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix2dv"); if (p_glProgramUniformMatrix2dv) n++;
    *(void **)&p_glProgramUniformMatrix2fv = dlsym(mgl, "glProgramUniformMatrix2fv"); *(void **)&a_glProgramUniformMatrix2fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix2fv"); if (p_glProgramUniformMatrix2fv) n++;
    *(void **)&p_glProgramUniformMatrix2x3dv = dlsym(mgl, "glProgramUniformMatrix2x3dv"); *(void **)&a_glProgramUniformMatrix2x3dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix2x3dv"); if (p_glProgramUniformMatrix2x3dv) n++;
    *(void **)&p_glProgramUniformMatrix2x3fv = dlsym(mgl, "glProgramUniformMatrix2x3fv"); *(void **)&a_glProgramUniformMatrix2x3fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix2x3fv"); if (p_glProgramUniformMatrix2x3fv) n++;
    *(void **)&p_glProgramUniformMatrix2x4dv = dlsym(mgl, "glProgramUniformMatrix2x4dv"); *(void **)&a_glProgramUniformMatrix2x4dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix2x4dv"); if (p_glProgramUniformMatrix2x4dv) n++;
    *(void **)&p_glProgramUniformMatrix2x4fv = dlsym(mgl, "glProgramUniformMatrix2x4fv"); *(void **)&a_glProgramUniformMatrix2x4fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix2x4fv"); if (p_glProgramUniformMatrix2x4fv) n++;
    *(void **)&p_glProgramUniformMatrix3dv = dlsym(mgl, "glProgramUniformMatrix3dv"); *(void **)&a_glProgramUniformMatrix3dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix3dv"); if (p_glProgramUniformMatrix3dv) n++;
    *(void **)&p_glProgramUniformMatrix3fv = dlsym(mgl, "glProgramUniformMatrix3fv"); *(void **)&a_glProgramUniformMatrix3fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix3fv"); if (p_glProgramUniformMatrix3fv) n++;
    *(void **)&p_glProgramUniformMatrix3x2dv = dlsym(mgl, "glProgramUniformMatrix3x2dv"); *(void **)&a_glProgramUniformMatrix3x2dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix3x2dv"); if (p_glProgramUniformMatrix3x2dv) n++;
    *(void **)&p_glProgramUniformMatrix3x2fv = dlsym(mgl, "glProgramUniformMatrix3x2fv"); *(void **)&a_glProgramUniformMatrix3x2fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix3x2fv"); if (p_glProgramUniformMatrix3x2fv) n++;
    *(void **)&p_glProgramUniformMatrix3x4dv = dlsym(mgl, "glProgramUniformMatrix3x4dv"); *(void **)&a_glProgramUniformMatrix3x4dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix3x4dv"); if (p_glProgramUniformMatrix3x4dv) n++;
    *(void **)&p_glProgramUniformMatrix3x4fv = dlsym(mgl, "glProgramUniformMatrix3x4fv"); *(void **)&a_glProgramUniformMatrix3x4fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix3x4fv"); if (p_glProgramUniformMatrix3x4fv) n++;
    *(void **)&p_glProgramUniformMatrix4dv = dlsym(mgl, "glProgramUniformMatrix4dv"); *(void **)&a_glProgramUniformMatrix4dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix4dv"); if (p_glProgramUniformMatrix4dv) n++;
    *(void **)&p_glProgramUniformMatrix4fv = dlsym(mgl, "glProgramUniformMatrix4fv"); *(void **)&a_glProgramUniformMatrix4fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix4fv"); if (p_glProgramUniformMatrix4fv) n++;
    *(void **)&p_glProgramUniformMatrix4x2dv = dlsym(mgl, "glProgramUniformMatrix4x2dv"); *(void **)&a_glProgramUniformMatrix4x2dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix4x2dv"); if (p_glProgramUniformMatrix4x2dv) n++;
    *(void **)&p_glProgramUniformMatrix4x2fv = dlsym(mgl, "glProgramUniformMatrix4x2fv"); *(void **)&a_glProgramUniformMatrix4x2fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix4x2fv"); if (p_glProgramUniformMatrix4x2fv) n++;
    *(void **)&p_glProgramUniformMatrix4x3dv = dlsym(mgl, "glProgramUniformMatrix4x3dv"); *(void **)&a_glProgramUniformMatrix4x3dv = dlsym(RTLD_NEXT, "glProgramUniformMatrix4x3dv"); if (p_glProgramUniformMatrix4x3dv) n++;
    *(void **)&p_glProgramUniformMatrix4x3fv = dlsym(mgl, "glProgramUniformMatrix4x3fv"); *(void **)&a_glProgramUniformMatrix4x3fv = dlsym(RTLD_NEXT, "glProgramUniformMatrix4x3fv"); if (p_glProgramUniformMatrix4x3fv) n++;
    *(void **)&p_glProvokingVertex = dlsym(mgl, "glProvokingVertex"); *(void **)&a_glProvokingVertex = dlsym(RTLD_NEXT, "glProvokingVertex"); if (p_glProvokingVertex) n++;
    *(void **)&p_glPushDebugGroup = dlsym(mgl, "glPushDebugGroup"); *(void **)&a_glPushDebugGroup = dlsym(RTLD_NEXT, "glPushDebugGroup"); if (p_glPushDebugGroup) n++;
    *(void **)&p_glQueryCounter = dlsym(mgl, "glQueryCounter"); *(void **)&a_glQueryCounter = dlsym(RTLD_NEXT, "glQueryCounter"); if (p_glQueryCounter) n++;
    *(void **)&p_glReadBuffer = dlsym(mgl, "glReadBuffer"); *(void **)&a_glReadBuffer = dlsym(RTLD_NEXT, "glReadBuffer"); if (p_glReadBuffer) n++;
    *(void **)&p_glReadPixels = dlsym(mgl, "glReadPixels"); *(void **)&a_glReadPixels = dlsym(RTLD_NEXT, "glReadPixels"); if (p_glReadPixels) n++;
    *(void **)&p_glReadnPixels = dlsym(mgl, "glReadnPixels"); *(void **)&a_glReadnPixels = dlsym(RTLD_NEXT, "glReadnPixels"); if (p_glReadnPixels) n++;
    *(void **)&p_glReleaseShaderCompiler = dlsym(mgl, "glReleaseShaderCompiler"); *(void **)&a_glReleaseShaderCompiler = dlsym(RTLD_NEXT, "glReleaseShaderCompiler"); if (p_glReleaseShaderCompiler) n++;
    *(void **)&p_glRenderbufferStorage = dlsym(mgl, "glRenderbufferStorage"); *(void **)&a_glRenderbufferStorage = dlsym(RTLD_NEXT, "glRenderbufferStorage"); if (p_glRenderbufferStorage) n++;
    *(void **)&p_glRenderbufferStorageMultisample = dlsym(mgl, "glRenderbufferStorageMultisample"); *(void **)&a_glRenderbufferStorageMultisample = dlsym(RTLD_NEXT, "glRenderbufferStorageMultisample"); if (p_glRenderbufferStorageMultisample) n++;
    *(void **)&p_glResumeTransformFeedback = dlsym(mgl, "glResumeTransformFeedback"); *(void **)&a_glResumeTransformFeedback = dlsym(RTLD_NEXT, "glResumeTransformFeedback"); if (p_glResumeTransformFeedback) n++;
    *(void **)&p_glSampleCoverage = dlsym(mgl, "glSampleCoverage"); *(void **)&a_glSampleCoverage = dlsym(RTLD_NEXT, "glSampleCoverage"); if (p_glSampleCoverage) n++;
    *(void **)&p_glSampleMaski = dlsym(mgl, "glSampleMaski"); *(void **)&a_glSampleMaski = dlsym(RTLD_NEXT, "glSampleMaski"); if (p_glSampleMaski) n++;
    *(void **)&p_glSamplerParameterIiv = dlsym(mgl, "glSamplerParameterIiv"); *(void **)&a_glSamplerParameterIiv = dlsym(RTLD_NEXT, "glSamplerParameterIiv"); if (p_glSamplerParameterIiv) n++;
    *(void **)&p_glSamplerParameterIuiv = dlsym(mgl, "glSamplerParameterIuiv"); *(void **)&a_glSamplerParameterIuiv = dlsym(RTLD_NEXT, "glSamplerParameterIuiv"); if (p_glSamplerParameterIuiv) n++;
    *(void **)&p_glSamplerParameterf = dlsym(mgl, "glSamplerParameterf"); *(void **)&a_glSamplerParameterf = dlsym(RTLD_NEXT, "glSamplerParameterf"); if (p_glSamplerParameterf) n++;
    *(void **)&p_glSamplerParameterfv = dlsym(mgl, "glSamplerParameterfv"); *(void **)&a_glSamplerParameterfv = dlsym(RTLD_NEXT, "glSamplerParameterfv"); if (p_glSamplerParameterfv) n++;
    *(void **)&p_glSamplerParameteri = dlsym(mgl, "glSamplerParameteri"); *(void **)&a_glSamplerParameteri = dlsym(RTLD_NEXT, "glSamplerParameteri"); if (p_glSamplerParameteri) n++;
    *(void **)&p_glSamplerParameteriv = dlsym(mgl, "glSamplerParameteriv"); *(void **)&a_glSamplerParameteriv = dlsym(RTLD_NEXT, "glSamplerParameteriv"); if (p_glSamplerParameteriv) n++;
    *(void **)&p_glScissor = dlsym(mgl, "glScissor"); *(void **)&a_glScissor = dlsym(RTLD_NEXT, "glScissor"); if (p_glScissor) n++;
    *(void **)&p_glScissorArrayv = dlsym(mgl, "glScissorArrayv"); *(void **)&a_glScissorArrayv = dlsym(RTLD_NEXT, "glScissorArrayv"); if (p_glScissorArrayv) n++;
    *(void **)&p_glScissorIndexed = dlsym(mgl, "glScissorIndexed"); *(void **)&a_glScissorIndexed = dlsym(RTLD_NEXT, "glScissorIndexed"); if (p_glScissorIndexed) n++;
    *(void **)&p_glScissorIndexedv = dlsym(mgl, "glScissorIndexedv"); *(void **)&a_glScissorIndexedv = dlsym(RTLD_NEXT, "glScissorIndexedv"); if (p_glScissorIndexedv) n++;
    *(void **)&p_glShaderBinary = dlsym(mgl, "glShaderBinary"); *(void **)&a_glShaderBinary = dlsym(RTLD_NEXT, "glShaderBinary"); if (p_glShaderBinary) n++;
    *(void **)&p_glShaderSource = dlsym(mgl, "glShaderSource"); *(void **)&a_glShaderSource = dlsym(RTLD_NEXT, "glShaderSource"); if (p_glShaderSource) n++;
    *(void **)&p_glShaderStorageBlockBinding = dlsym(mgl, "glShaderStorageBlockBinding"); *(void **)&a_glShaderStorageBlockBinding = dlsym(RTLD_NEXT, "glShaderStorageBlockBinding"); if (p_glShaderStorageBlockBinding) n++;
    *(void **)&p_glSpecializeShader = dlsym(mgl, "glSpecializeShader"); *(void **)&a_glSpecializeShader = dlsym(RTLD_NEXT, "glSpecializeShader"); if (p_glSpecializeShader) n++;
    *(void **)&p_glStencilFunc = dlsym(mgl, "glStencilFunc"); *(void **)&a_glStencilFunc = dlsym(RTLD_NEXT, "glStencilFunc"); if (p_glStencilFunc) n++;
    *(void **)&p_glStencilFuncSeparate = dlsym(mgl, "glStencilFuncSeparate"); *(void **)&a_glStencilFuncSeparate = dlsym(RTLD_NEXT, "glStencilFuncSeparate"); if (p_glStencilFuncSeparate) n++;
    *(void **)&p_glStencilMask = dlsym(mgl, "glStencilMask"); *(void **)&a_glStencilMask = dlsym(RTLD_NEXT, "glStencilMask"); if (p_glStencilMask) n++;
    *(void **)&p_glStencilMaskSeparate = dlsym(mgl, "glStencilMaskSeparate"); *(void **)&a_glStencilMaskSeparate = dlsym(RTLD_NEXT, "glStencilMaskSeparate"); if (p_glStencilMaskSeparate) n++;
    *(void **)&p_glStencilOp = dlsym(mgl, "glStencilOp"); *(void **)&a_glStencilOp = dlsym(RTLD_NEXT, "glStencilOp"); if (p_glStencilOp) n++;
    *(void **)&p_glStencilOpSeparate = dlsym(mgl, "glStencilOpSeparate"); *(void **)&a_glStencilOpSeparate = dlsym(RTLD_NEXT, "glStencilOpSeparate"); if (p_glStencilOpSeparate) n++;
    *(void **)&p_glTexBuffer = dlsym(mgl, "glTexBuffer"); *(void **)&a_glTexBuffer = dlsym(RTLD_NEXT, "glTexBuffer"); if (p_glTexBuffer) n++;
    *(void **)&p_glTexBufferRange = dlsym(mgl, "glTexBufferRange"); *(void **)&a_glTexBufferRange = dlsym(RTLD_NEXT, "glTexBufferRange"); if (p_glTexBufferRange) n++;
    *(void **)&p_glTexImage1D = dlsym(mgl, "glTexImage1D"); *(void **)&a_glTexImage1D = dlsym(RTLD_NEXT, "glTexImage1D"); if (p_glTexImage1D) n++;
    *(void **)&p_glTexImage2D = dlsym(mgl, "glTexImage2D"); *(void **)&a_glTexImage2D = dlsym(RTLD_NEXT, "glTexImage2D"); if (p_glTexImage2D) n++;
    *(void **)&p_glTexImage2DMultisample = dlsym(mgl, "glTexImage2DMultisample"); *(void **)&a_glTexImage2DMultisample = dlsym(RTLD_NEXT, "glTexImage2DMultisample"); if (p_glTexImage2DMultisample) n++;
    *(void **)&p_glTexImage3D = dlsym(mgl, "glTexImage3D"); *(void **)&a_glTexImage3D = dlsym(RTLD_NEXT, "glTexImage3D"); if (p_glTexImage3D) n++;
    *(void **)&p_glTexImage3DMultisample = dlsym(mgl, "glTexImage3DMultisample"); *(void **)&a_glTexImage3DMultisample = dlsym(RTLD_NEXT, "glTexImage3DMultisample"); if (p_glTexImage3DMultisample) n++;
    *(void **)&p_glTexParameterIiv = dlsym(mgl, "glTexParameterIiv"); *(void **)&a_glTexParameterIiv = dlsym(RTLD_NEXT, "glTexParameterIiv"); if (p_glTexParameterIiv) n++;
    *(void **)&p_glTexParameterIuiv = dlsym(mgl, "glTexParameterIuiv"); *(void **)&a_glTexParameterIuiv = dlsym(RTLD_NEXT, "glTexParameterIuiv"); if (p_glTexParameterIuiv) n++;
    *(void **)&p_glTexParameterf = dlsym(mgl, "glTexParameterf"); *(void **)&a_glTexParameterf = dlsym(RTLD_NEXT, "glTexParameterf"); if (p_glTexParameterf) n++;
    *(void **)&p_glTexParameterfv = dlsym(mgl, "glTexParameterfv"); *(void **)&a_glTexParameterfv = dlsym(RTLD_NEXT, "glTexParameterfv"); if (p_glTexParameterfv) n++;
    *(void **)&p_glTexParameteri = dlsym(mgl, "glTexParameteri"); *(void **)&a_glTexParameteri = dlsym(RTLD_NEXT, "glTexParameteri"); if (p_glTexParameteri) n++;
    *(void **)&p_glTexParameteriv = dlsym(mgl, "glTexParameteriv"); *(void **)&a_glTexParameteriv = dlsym(RTLD_NEXT, "glTexParameteriv"); if (p_glTexParameteriv) n++;
    *(void **)&p_glTexStorage1D = dlsym(mgl, "glTexStorage1D"); *(void **)&a_glTexStorage1D = dlsym(RTLD_NEXT, "glTexStorage1D"); if (p_glTexStorage1D) n++;
    *(void **)&p_glTexStorage2D = dlsym(mgl, "glTexStorage2D"); *(void **)&a_glTexStorage2D = dlsym(RTLD_NEXT, "glTexStorage2D"); if (p_glTexStorage2D) n++;
    *(void **)&p_glTexStorage2DMultisample = dlsym(mgl, "glTexStorage2DMultisample"); *(void **)&a_glTexStorage2DMultisample = dlsym(RTLD_NEXT, "glTexStorage2DMultisample"); if (p_glTexStorage2DMultisample) n++;
    *(void **)&p_glTexStorage3D = dlsym(mgl, "glTexStorage3D"); *(void **)&a_glTexStorage3D = dlsym(RTLD_NEXT, "glTexStorage3D"); if (p_glTexStorage3D) n++;
    *(void **)&p_glTexStorage3DMultisample = dlsym(mgl, "glTexStorage3DMultisample"); *(void **)&a_glTexStorage3DMultisample = dlsym(RTLD_NEXT, "glTexStorage3DMultisample"); if (p_glTexStorage3DMultisample) n++;
    *(void **)&p_glTexSubImage1D = dlsym(mgl, "glTexSubImage1D"); *(void **)&a_glTexSubImage1D = dlsym(RTLD_NEXT, "glTexSubImage1D"); if (p_glTexSubImage1D) n++;
    *(void **)&p_glTexSubImage2D = dlsym(mgl, "glTexSubImage2D"); *(void **)&a_glTexSubImage2D = dlsym(RTLD_NEXT, "glTexSubImage2D"); if (p_glTexSubImage2D) n++;
    *(void **)&p_glTexSubImage3D = dlsym(mgl, "glTexSubImage3D"); *(void **)&a_glTexSubImage3D = dlsym(RTLD_NEXT, "glTexSubImage3D"); if (p_glTexSubImage3D) n++;
    *(void **)&p_glTextureBarrier = dlsym(mgl, "glTextureBarrier"); *(void **)&a_glTextureBarrier = dlsym(RTLD_NEXT, "glTextureBarrier"); if (p_glTextureBarrier) n++;
    *(void **)&p_glTextureBuffer = dlsym(mgl, "glTextureBuffer"); *(void **)&a_glTextureBuffer = dlsym(RTLD_NEXT, "glTextureBuffer"); if (p_glTextureBuffer) n++;
    *(void **)&p_glTextureBufferRange = dlsym(mgl, "glTextureBufferRange"); *(void **)&a_glTextureBufferRange = dlsym(RTLD_NEXT, "glTextureBufferRange"); if (p_glTextureBufferRange) n++;
    *(void **)&p_glTextureParameterIiv = dlsym(mgl, "glTextureParameterIiv"); *(void **)&a_glTextureParameterIiv = dlsym(RTLD_NEXT, "glTextureParameterIiv"); if (p_glTextureParameterIiv) n++;
    *(void **)&p_glTextureParameterIuiv = dlsym(mgl, "glTextureParameterIuiv"); *(void **)&a_glTextureParameterIuiv = dlsym(RTLD_NEXT, "glTextureParameterIuiv"); if (p_glTextureParameterIuiv) n++;
    *(void **)&p_glTextureParameterf = dlsym(mgl, "glTextureParameterf"); *(void **)&a_glTextureParameterf = dlsym(RTLD_NEXT, "glTextureParameterf"); if (p_glTextureParameterf) n++;
    *(void **)&p_glTextureParameterfv = dlsym(mgl, "glTextureParameterfv"); *(void **)&a_glTextureParameterfv = dlsym(RTLD_NEXT, "glTextureParameterfv"); if (p_glTextureParameterfv) n++;
    *(void **)&p_glTextureParameteri = dlsym(mgl, "glTextureParameteri"); *(void **)&a_glTextureParameteri = dlsym(RTLD_NEXT, "glTextureParameteri"); if (p_glTextureParameteri) n++;
    *(void **)&p_glTextureParameteriv = dlsym(mgl, "glTextureParameteriv"); *(void **)&a_glTextureParameteriv = dlsym(RTLD_NEXT, "glTextureParameteriv"); if (p_glTextureParameteriv) n++;
    *(void **)&p_glTextureStorage1D = dlsym(mgl, "glTextureStorage1D"); *(void **)&a_glTextureStorage1D = dlsym(RTLD_NEXT, "glTextureStorage1D"); if (p_glTextureStorage1D) n++;
    *(void **)&p_glTextureStorage2D = dlsym(mgl, "glTextureStorage2D"); *(void **)&a_glTextureStorage2D = dlsym(RTLD_NEXT, "glTextureStorage2D"); if (p_glTextureStorage2D) n++;
    *(void **)&p_glTextureStorage2DMultisample = dlsym(mgl, "glTextureStorage2DMultisample"); *(void **)&a_glTextureStorage2DMultisample = dlsym(RTLD_NEXT, "glTextureStorage2DMultisample"); if (p_glTextureStorage2DMultisample) n++;
    *(void **)&p_glTextureStorage3D = dlsym(mgl, "glTextureStorage3D"); *(void **)&a_glTextureStorage3D = dlsym(RTLD_NEXT, "glTextureStorage3D"); if (p_glTextureStorage3D) n++;
    *(void **)&p_glTextureStorage3DMultisample = dlsym(mgl, "glTextureStorage3DMultisample"); *(void **)&a_glTextureStorage3DMultisample = dlsym(RTLD_NEXT, "glTextureStorage3DMultisample"); if (p_glTextureStorage3DMultisample) n++;
    *(void **)&p_glTextureSubImage1D = dlsym(mgl, "glTextureSubImage1D"); *(void **)&a_glTextureSubImage1D = dlsym(RTLD_NEXT, "glTextureSubImage1D"); if (p_glTextureSubImage1D) n++;
    *(void **)&p_glTextureSubImage2D = dlsym(mgl, "glTextureSubImage2D"); *(void **)&a_glTextureSubImage2D = dlsym(RTLD_NEXT, "glTextureSubImage2D"); if (p_glTextureSubImage2D) n++;
    *(void **)&p_glTextureSubImage3D = dlsym(mgl, "glTextureSubImage3D"); *(void **)&a_glTextureSubImage3D = dlsym(RTLD_NEXT, "glTextureSubImage3D"); if (p_glTextureSubImage3D) n++;
    *(void **)&p_glTextureView = dlsym(mgl, "glTextureView"); *(void **)&a_glTextureView = dlsym(RTLD_NEXT, "glTextureView"); if (p_glTextureView) n++;
    *(void **)&p_glTransformFeedbackBufferBase = dlsym(mgl, "glTransformFeedbackBufferBase"); *(void **)&a_glTransformFeedbackBufferBase = dlsym(RTLD_NEXT, "glTransformFeedbackBufferBase"); if (p_glTransformFeedbackBufferBase) n++;
    *(void **)&p_glTransformFeedbackBufferRange = dlsym(mgl, "glTransformFeedbackBufferRange"); *(void **)&a_glTransformFeedbackBufferRange = dlsym(RTLD_NEXT, "glTransformFeedbackBufferRange"); if (p_glTransformFeedbackBufferRange) n++;
    *(void **)&p_glTransformFeedbackVaryings = dlsym(mgl, "glTransformFeedbackVaryings"); *(void **)&a_glTransformFeedbackVaryings = dlsym(RTLD_NEXT, "glTransformFeedbackVaryings"); if (p_glTransformFeedbackVaryings) n++;
    *(void **)&p_glUniform1d = dlsym(mgl, "glUniform1d"); *(void **)&a_glUniform1d = dlsym(RTLD_NEXT, "glUniform1d"); if (p_glUniform1d) n++;
    *(void **)&p_glUniform1dv = dlsym(mgl, "glUniform1dv"); *(void **)&a_glUniform1dv = dlsym(RTLD_NEXT, "glUniform1dv"); if (p_glUniform1dv) n++;
    *(void **)&p_glUniform1f = dlsym(mgl, "glUniform1f"); *(void **)&a_glUniform1f = dlsym(RTLD_NEXT, "glUniform1f"); if (p_glUniform1f) n++;
    *(void **)&p_glUniform1fv = dlsym(mgl, "glUniform1fv"); *(void **)&a_glUniform1fv = dlsym(RTLD_NEXT, "glUniform1fv"); if (p_glUniform1fv) n++;
    *(void **)&p_glUniform1i = dlsym(mgl, "glUniform1i"); *(void **)&a_glUniform1i = dlsym(RTLD_NEXT, "glUniform1i"); if (p_glUniform1i) n++;
    *(void **)&p_glUniform1iv = dlsym(mgl, "glUniform1iv"); *(void **)&a_glUniform1iv = dlsym(RTLD_NEXT, "glUniform1iv"); if (p_glUniform1iv) n++;
    *(void **)&p_glUniform1ui = dlsym(mgl, "glUniform1ui"); *(void **)&a_glUniform1ui = dlsym(RTLD_NEXT, "glUniform1ui"); if (p_glUniform1ui) n++;
    *(void **)&p_glUniform1uiv = dlsym(mgl, "glUniform1uiv"); *(void **)&a_glUniform1uiv = dlsym(RTLD_NEXT, "glUniform1uiv"); if (p_glUniform1uiv) n++;
    *(void **)&p_glUniform2d = dlsym(mgl, "glUniform2d"); *(void **)&a_glUniform2d = dlsym(RTLD_NEXT, "glUniform2d"); if (p_glUniform2d) n++;
    *(void **)&p_glUniform2dv = dlsym(mgl, "glUniform2dv"); *(void **)&a_glUniform2dv = dlsym(RTLD_NEXT, "glUniform2dv"); if (p_glUniform2dv) n++;
    *(void **)&p_glUniform2f = dlsym(mgl, "glUniform2f"); *(void **)&a_glUniform2f = dlsym(RTLD_NEXT, "glUniform2f"); if (p_glUniform2f) n++;
    *(void **)&p_glUniform2fv = dlsym(mgl, "glUniform2fv"); *(void **)&a_glUniform2fv = dlsym(RTLD_NEXT, "glUniform2fv"); if (p_glUniform2fv) n++;
    *(void **)&p_glUniform2i = dlsym(mgl, "glUniform2i"); *(void **)&a_glUniform2i = dlsym(RTLD_NEXT, "glUniform2i"); if (p_glUniform2i) n++;
    *(void **)&p_glUniform2iv = dlsym(mgl, "glUniform2iv"); *(void **)&a_glUniform2iv = dlsym(RTLD_NEXT, "glUniform2iv"); if (p_glUniform2iv) n++;
    *(void **)&p_glUniform2ui = dlsym(mgl, "glUniform2ui"); *(void **)&a_glUniform2ui = dlsym(RTLD_NEXT, "glUniform2ui"); if (p_glUniform2ui) n++;
    *(void **)&p_glUniform2uiv = dlsym(mgl, "glUniform2uiv"); *(void **)&a_glUniform2uiv = dlsym(RTLD_NEXT, "glUniform2uiv"); if (p_glUniform2uiv) n++;
    *(void **)&p_glUniform3d = dlsym(mgl, "glUniform3d"); *(void **)&a_glUniform3d = dlsym(RTLD_NEXT, "glUniform3d"); if (p_glUniform3d) n++;
    *(void **)&p_glUniform3dv = dlsym(mgl, "glUniform3dv"); *(void **)&a_glUniform3dv = dlsym(RTLD_NEXT, "glUniform3dv"); if (p_glUniform3dv) n++;
    *(void **)&p_glUniform3f = dlsym(mgl, "glUniform3f"); *(void **)&a_glUniform3f = dlsym(RTLD_NEXT, "glUniform3f"); if (p_glUniform3f) n++;
    *(void **)&p_glUniform3fv = dlsym(mgl, "glUniform3fv"); *(void **)&a_glUniform3fv = dlsym(RTLD_NEXT, "glUniform3fv"); if (p_glUniform3fv) n++;
    *(void **)&p_glUniform3i = dlsym(mgl, "glUniform3i"); *(void **)&a_glUniform3i = dlsym(RTLD_NEXT, "glUniform3i"); if (p_glUniform3i) n++;
    *(void **)&p_glUniform3iv = dlsym(mgl, "glUniform3iv"); *(void **)&a_glUniform3iv = dlsym(RTLD_NEXT, "glUniform3iv"); if (p_glUniform3iv) n++;
    *(void **)&p_glUniform3ui = dlsym(mgl, "glUniform3ui"); *(void **)&a_glUniform3ui = dlsym(RTLD_NEXT, "glUniform3ui"); if (p_glUniform3ui) n++;
    *(void **)&p_glUniform3uiv = dlsym(mgl, "glUniform3uiv"); *(void **)&a_glUniform3uiv = dlsym(RTLD_NEXT, "glUniform3uiv"); if (p_glUniform3uiv) n++;
    *(void **)&p_glUniform4d = dlsym(mgl, "glUniform4d"); *(void **)&a_glUniform4d = dlsym(RTLD_NEXT, "glUniform4d"); if (p_glUniform4d) n++;
    *(void **)&p_glUniform4dv = dlsym(mgl, "glUniform4dv"); *(void **)&a_glUniform4dv = dlsym(RTLD_NEXT, "glUniform4dv"); if (p_glUniform4dv) n++;
    *(void **)&p_glUniform4f = dlsym(mgl, "glUniform4f"); *(void **)&a_glUniform4f = dlsym(RTLD_NEXT, "glUniform4f"); if (p_glUniform4f) n++;
    *(void **)&p_glUniform4fv = dlsym(mgl, "glUniform4fv"); *(void **)&a_glUniform4fv = dlsym(RTLD_NEXT, "glUniform4fv"); if (p_glUniform4fv) n++;
    *(void **)&p_glUniform4i = dlsym(mgl, "glUniform4i"); *(void **)&a_glUniform4i = dlsym(RTLD_NEXT, "glUniform4i"); if (p_glUniform4i) n++;
    *(void **)&p_glUniform4iv = dlsym(mgl, "glUniform4iv"); *(void **)&a_glUniform4iv = dlsym(RTLD_NEXT, "glUniform4iv"); if (p_glUniform4iv) n++;
    *(void **)&p_glUniform4ui = dlsym(mgl, "glUniform4ui"); *(void **)&a_glUniform4ui = dlsym(RTLD_NEXT, "glUniform4ui"); if (p_glUniform4ui) n++;
    *(void **)&p_glUniform4uiv = dlsym(mgl, "glUniform4uiv"); *(void **)&a_glUniform4uiv = dlsym(RTLD_NEXT, "glUniform4uiv"); if (p_glUniform4uiv) n++;
    *(void **)&p_glUniformBlockBinding = dlsym(mgl, "glUniformBlockBinding"); *(void **)&a_glUniformBlockBinding = dlsym(RTLD_NEXT, "glUniformBlockBinding"); if (p_glUniformBlockBinding) n++;
    *(void **)&p_glUniformMatrix2dv = dlsym(mgl, "glUniformMatrix2dv"); *(void **)&a_glUniformMatrix2dv = dlsym(RTLD_NEXT, "glUniformMatrix2dv"); if (p_glUniformMatrix2dv) n++;
    *(void **)&p_glUniformMatrix2fv = dlsym(mgl, "glUniformMatrix2fv"); *(void **)&a_glUniformMatrix2fv = dlsym(RTLD_NEXT, "glUniformMatrix2fv"); if (p_glUniformMatrix2fv) n++;
    *(void **)&p_glUniformMatrix2x3dv = dlsym(mgl, "glUniformMatrix2x3dv"); *(void **)&a_glUniformMatrix2x3dv = dlsym(RTLD_NEXT, "glUniformMatrix2x3dv"); if (p_glUniformMatrix2x3dv) n++;
    *(void **)&p_glUniformMatrix2x3fv = dlsym(mgl, "glUniformMatrix2x3fv"); *(void **)&a_glUniformMatrix2x3fv = dlsym(RTLD_NEXT, "glUniformMatrix2x3fv"); if (p_glUniformMatrix2x3fv) n++;
    *(void **)&p_glUniformMatrix2x4dv = dlsym(mgl, "glUniformMatrix2x4dv"); *(void **)&a_glUniformMatrix2x4dv = dlsym(RTLD_NEXT, "glUniformMatrix2x4dv"); if (p_glUniformMatrix2x4dv) n++;
    *(void **)&p_glUniformMatrix2x4fv = dlsym(mgl, "glUniformMatrix2x4fv"); *(void **)&a_glUniformMatrix2x4fv = dlsym(RTLD_NEXT, "glUniformMatrix2x4fv"); if (p_glUniformMatrix2x4fv) n++;
    *(void **)&p_glUniformMatrix3dv = dlsym(mgl, "glUniformMatrix3dv"); *(void **)&a_glUniformMatrix3dv = dlsym(RTLD_NEXT, "glUniformMatrix3dv"); if (p_glUniformMatrix3dv) n++;
    *(void **)&p_glUniformMatrix3fv = dlsym(mgl, "glUniformMatrix3fv"); *(void **)&a_glUniformMatrix3fv = dlsym(RTLD_NEXT, "glUniformMatrix3fv"); if (p_glUniformMatrix3fv) n++;
    *(void **)&p_glUniformMatrix3x2dv = dlsym(mgl, "glUniformMatrix3x2dv"); *(void **)&a_glUniformMatrix3x2dv = dlsym(RTLD_NEXT, "glUniformMatrix3x2dv"); if (p_glUniformMatrix3x2dv) n++;
    *(void **)&p_glUniformMatrix3x2fv = dlsym(mgl, "glUniformMatrix3x2fv"); *(void **)&a_glUniformMatrix3x2fv = dlsym(RTLD_NEXT, "glUniformMatrix3x2fv"); if (p_glUniformMatrix3x2fv) n++;
    *(void **)&p_glUniformMatrix3x4dv = dlsym(mgl, "glUniformMatrix3x4dv"); *(void **)&a_glUniformMatrix3x4dv = dlsym(RTLD_NEXT, "glUniformMatrix3x4dv"); if (p_glUniformMatrix3x4dv) n++;
    *(void **)&p_glUniformMatrix3x4fv = dlsym(mgl, "glUniformMatrix3x4fv"); *(void **)&a_glUniformMatrix3x4fv = dlsym(RTLD_NEXT, "glUniformMatrix3x4fv"); if (p_glUniformMatrix3x4fv) n++;
    *(void **)&p_glUniformMatrix4dv = dlsym(mgl, "glUniformMatrix4dv"); *(void **)&a_glUniformMatrix4dv = dlsym(RTLD_NEXT, "glUniformMatrix4dv"); if (p_glUniformMatrix4dv) n++;
    *(void **)&p_glUniformMatrix4fv = dlsym(mgl, "glUniformMatrix4fv"); *(void **)&a_glUniformMatrix4fv = dlsym(RTLD_NEXT, "glUniformMatrix4fv"); if (p_glUniformMatrix4fv) n++;
    *(void **)&p_glUniformMatrix4x2dv = dlsym(mgl, "glUniformMatrix4x2dv"); *(void **)&a_glUniformMatrix4x2dv = dlsym(RTLD_NEXT, "glUniformMatrix4x2dv"); if (p_glUniformMatrix4x2dv) n++;
    *(void **)&p_glUniformMatrix4x2fv = dlsym(mgl, "glUniformMatrix4x2fv"); *(void **)&a_glUniformMatrix4x2fv = dlsym(RTLD_NEXT, "glUniformMatrix4x2fv"); if (p_glUniformMatrix4x2fv) n++;
    *(void **)&p_glUniformMatrix4x3dv = dlsym(mgl, "glUniformMatrix4x3dv"); *(void **)&a_glUniformMatrix4x3dv = dlsym(RTLD_NEXT, "glUniformMatrix4x3dv"); if (p_glUniformMatrix4x3dv) n++;
    *(void **)&p_glUniformMatrix4x3fv = dlsym(mgl, "glUniformMatrix4x3fv"); *(void **)&a_glUniformMatrix4x3fv = dlsym(RTLD_NEXT, "glUniformMatrix4x3fv"); if (p_glUniformMatrix4x3fv) n++;
    *(void **)&p_glUniformSubroutinesuiv = dlsym(mgl, "glUniformSubroutinesuiv"); *(void **)&a_glUniformSubroutinesuiv = dlsym(RTLD_NEXT, "glUniformSubroutinesuiv"); if (p_glUniformSubroutinesuiv) n++;
    *(void **)&p_glUnmapBuffer = dlsym(mgl, "glUnmapBuffer"); *(void **)&a_glUnmapBuffer = dlsym(RTLD_NEXT, "glUnmapBuffer"); if (p_glUnmapBuffer) n++;
    *(void **)&p_glUnmapNamedBuffer = dlsym(mgl, "glUnmapNamedBuffer"); *(void **)&a_glUnmapNamedBuffer = dlsym(RTLD_NEXT, "glUnmapNamedBuffer"); if (p_glUnmapNamedBuffer) n++;
    *(void **)&p_glUseProgram = dlsym(mgl, "glUseProgram"); *(void **)&a_glUseProgram = dlsym(RTLD_NEXT, "glUseProgram"); if (p_glUseProgram) n++;
    *(void **)&p_glUseProgramStages = dlsym(mgl, "glUseProgramStages"); *(void **)&a_glUseProgramStages = dlsym(RTLD_NEXT, "glUseProgramStages"); if (p_glUseProgramStages) n++;
    *(void **)&p_glValidateProgram = dlsym(mgl, "glValidateProgram"); *(void **)&a_glValidateProgram = dlsym(RTLD_NEXT, "glValidateProgram"); if (p_glValidateProgram) n++;
    *(void **)&p_glValidateProgramPipeline = dlsym(mgl, "glValidateProgramPipeline"); *(void **)&a_glValidateProgramPipeline = dlsym(RTLD_NEXT, "glValidateProgramPipeline"); if (p_glValidateProgramPipeline) n++;
    *(void **)&p_glVertexArrayAttribBinding = dlsym(mgl, "glVertexArrayAttribBinding"); *(void **)&a_glVertexArrayAttribBinding = dlsym(RTLD_NEXT, "glVertexArrayAttribBinding"); if (p_glVertexArrayAttribBinding) n++;
    *(void **)&p_glVertexArrayAttribFormat = dlsym(mgl, "glVertexArrayAttribFormat"); *(void **)&a_glVertexArrayAttribFormat = dlsym(RTLD_NEXT, "glVertexArrayAttribFormat"); if (p_glVertexArrayAttribFormat) n++;
    *(void **)&p_glVertexArrayAttribIFormat = dlsym(mgl, "glVertexArrayAttribIFormat"); *(void **)&a_glVertexArrayAttribIFormat = dlsym(RTLD_NEXT, "glVertexArrayAttribIFormat"); if (p_glVertexArrayAttribIFormat) n++;
    *(void **)&p_glVertexArrayAttribLFormat = dlsym(mgl, "glVertexArrayAttribLFormat"); *(void **)&a_glVertexArrayAttribLFormat = dlsym(RTLD_NEXT, "glVertexArrayAttribLFormat"); if (p_glVertexArrayAttribLFormat) n++;
    *(void **)&p_glVertexArrayBindingDivisor = dlsym(mgl, "glVertexArrayBindingDivisor"); *(void **)&a_glVertexArrayBindingDivisor = dlsym(RTLD_NEXT, "glVertexArrayBindingDivisor"); if (p_glVertexArrayBindingDivisor) n++;
    *(void **)&p_glVertexArrayElementBuffer = dlsym(mgl, "glVertexArrayElementBuffer"); *(void **)&a_glVertexArrayElementBuffer = dlsym(RTLD_NEXT, "glVertexArrayElementBuffer"); if (p_glVertexArrayElementBuffer) n++;
    *(void **)&p_glVertexArrayVertexBuffer = dlsym(mgl, "glVertexArrayVertexBuffer"); *(void **)&a_glVertexArrayVertexBuffer = dlsym(RTLD_NEXT, "glVertexArrayVertexBuffer"); if (p_glVertexArrayVertexBuffer) n++;
    *(void **)&p_glVertexArrayVertexBuffers = dlsym(mgl, "glVertexArrayVertexBuffers"); *(void **)&a_glVertexArrayVertexBuffers = dlsym(RTLD_NEXT, "glVertexArrayVertexBuffers"); if (p_glVertexArrayVertexBuffers) n++;
    *(void **)&p_glVertexAttrib1d = dlsym(mgl, "glVertexAttrib1d"); *(void **)&a_glVertexAttrib1d = dlsym(RTLD_NEXT, "glVertexAttrib1d"); if (p_glVertexAttrib1d) n++;
    *(void **)&p_glVertexAttrib1dv = dlsym(mgl, "glVertexAttrib1dv"); *(void **)&a_glVertexAttrib1dv = dlsym(RTLD_NEXT, "glVertexAttrib1dv"); if (p_glVertexAttrib1dv) n++;
    *(void **)&p_glVertexAttrib1f = dlsym(mgl, "glVertexAttrib1f"); *(void **)&a_glVertexAttrib1f = dlsym(RTLD_NEXT, "glVertexAttrib1f"); if (p_glVertexAttrib1f) n++;
    *(void **)&p_glVertexAttrib1fv = dlsym(mgl, "glVertexAttrib1fv"); *(void **)&a_glVertexAttrib1fv = dlsym(RTLD_NEXT, "glVertexAttrib1fv"); if (p_glVertexAttrib1fv) n++;
    *(void **)&p_glVertexAttrib1s = dlsym(mgl, "glVertexAttrib1s"); *(void **)&a_glVertexAttrib1s = dlsym(RTLD_NEXT, "glVertexAttrib1s"); if (p_glVertexAttrib1s) n++;
    *(void **)&p_glVertexAttrib1sv = dlsym(mgl, "glVertexAttrib1sv"); *(void **)&a_glVertexAttrib1sv = dlsym(RTLD_NEXT, "glVertexAttrib1sv"); if (p_glVertexAttrib1sv) n++;
    *(void **)&p_glVertexAttrib2d = dlsym(mgl, "glVertexAttrib2d"); *(void **)&a_glVertexAttrib2d = dlsym(RTLD_NEXT, "glVertexAttrib2d"); if (p_glVertexAttrib2d) n++;
    *(void **)&p_glVertexAttrib2dv = dlsym(mgl, "glVertexAttrib2dv"); *(void **)&a_glVertexAttrib2dv = dlsym(RTLD_NEXT, "glVertexAttrib2dv"); if (p_glVertexAttrib2dv) n++;
    *(void **)&p_glVertexAttrib2f = dlsym(mgl, "glVertexAttrib2f"); *(void **)&a_glVertexAttrib2f = dlsym(RTLD_NEXT, "glVertexAttrib2f"); if (p_glVertexAttrib2f) n++;
    *(void **)&p_glVertexAttrib2fv = dlsym(mgl, "glVertexAttrib2fv"); *(void **)&a_glVertexAttrib2fv = dlsym(RTLD_NEXT, "glVertexAttrib2fv"); if (p_glVertexAttrib2fv) n++;
    *(void **)&p_glVertexAttrib2s = dlsym(mgl, "glVertexAttrib2s"); *(void **)&a_glVertexAttrib2s = dlsym(RTLD_NEXT, "glVertexAttrib2s"); if (p_glVertexAttrib2s) n++;
    *(void **)&p_glVertexAttrib2sv = dlsym(mgl, "glVertexAttrib2sv"); *(void **)&a_glVertexAttrib2sv = dlsym(RTLD_NEXT, "glVertexAttrib2sv"); if (p_glVertexAttrib2sv) n++;
    *(void **)&p_glVertexAttrib3d = dlsym(mgl, "glVertexAttrib3d"); *(void **)&a_glVertexAttrib3d = dlsym(RTLD_NEXT, "glVertexAttrib3d"); if (p_glVertexAttrib3d) n++;
    *(void **)&p_glVertexAttrib3dv = dlsym(mgl, "glVertexAttrib3dv"); *(void **)&a_glVertexAttrib3dv = dlsym(RTLD_NEXT, "glVertexAttrib3dv"); if (p_glVertexAttrib3dv) n++;
    *(void **)&p_glVertexAttrib3f = dlsym(mgl, "glVertexAttrib3f"); *(void **)&a_glVertexAttrib3f = dlsym(RTLD_NEXT, "glVertexAttrib3f"); if (p_glVertexAttrib3f) n++;
    *(void **)&p_glVertexAttrib3fv = dlsym(mgl, "glVertexAttrib3fv"); *(void **)&a_glVertexAttrib3fv = dlsym(RTLD_NEXT, "glVertexAttrib3fv"); if (p_glVertexAttrib3fv) n++;
    *(void **)&p_glVertexAttrib3s = dlsym(mgl, "glVertexAttrib3s"); *(void **)&a_glVertexAttrib3s = dlsym(RTLD_NEXT, "glVertexAttrib3s"); if (p_glVertexAttrib3s) n++;
    *(void **)&p_glVertexAttrib3sv = dlsym(mgl, "glVertexAttrib3sv"); *(void **)&a_glVertexAttrib3sv = dlsym(RTLD_NEXT, "glVertexAttrib3sv"); if (p_glVertexAttrib3sv) n++;
    *(void **)&p_glVertexAttrib4Nbv = dlsym(mgl, "glVertexAttrib4Nbv"); *(void **)&a_glVertexAttrib4Nbv = dlsym(RTLD_NEXT, "glVertexAttrib4Nbv"); if (p_glVertexAttrib4Nbv) n++;
    *(void **)&p_glVertexAttrib4Niv = dlsym(mgl, "glVertexAttrib4Niv"); *(void **)&a_glVertexAttrib4Niv = dlsym(RTLD_NEXT, "glVertexAttrib4Niv"); if (p_glVertexAttrib4Niv) n++;
    *(void **)&p_glVertexAttrib4Nsv = dlsym(mgl, "glVertexAttrib4Nsv"); *(void **)&a_glVertexAttrib4Nsv = dlsym(RTLD_NEXT, "glVertexAttrib4Nsv"); if (p_glVertexAttrib4Nsv) n++;
    *(void **)&p_glVertexAttrib4Nub = dlsym(mgl, "glVertexAttrib4Nub"); *(void **)&a_glVertexAttrib4Nub = dlsym(RTLD_NEXT, "glVertexAttrib4Nub"); if (p_glVertexAttrib4Nub) n++;
    *(void **)&p_glVertexAttrib4Nubv = dlsym(mgl, "glVertexAttrib4Nubv"); *(void **)&a_glVertexAttrib4Nubv = dlsym(RTLD_NEXT, "glVertexAttrib4Nubv"); if (p_glVertexAttrib4Nubv) n++;
    *(void **)&p_glVertexAttrib4Nuiv = dlsym(mgl, "glVertexAttrib4Nuiv"); *(void **)&a_glVertexAttrib4Nuiv = dlsym(RTLD_NEXT, "glVertexAttrib4Nuiv"); if (p_glVertexAttrib4Nuiv) n++;
    *(void **)&p_glVertexAttrib4Nusv = dlsym(mgl, "glVertexAttrib4Nusv"); *(void **)&a_glVertexAttrib4Nusv = dlsym(RTLD_NEXT, "glVertexAttrib4Nusv"); if (p_glVertexAttrib4Nusv) n++;
    *(void **)&p_glVertexAttrib4bv = dlsym(mgl, "glVertexAttrib4bv"); *(void **)&a_glVertexAttrib4bv = dlsym(RTLD_NEXT, "glVertexAttrib4bv"); if (p_glVertexAttrib4bv) n++;
    *(void **)&p_glVertexAttrib4d = dlsym(mgl, "glVertexAttrib4d"); *(void **)&a_glVertexAttrib4d = dlsym(RTLD_NEXT, "glVertexAttrib4d"); if (p_glVertexAttrib4d) n++;
    *(void **)&p_glVertexAttrib4dv = dlsym(mgl, "glVertexAttrib4dv"); *(void **)&a_glVertexAttrib4dv = dlsym(RTLD_NEXT, "glVertexAttrib4dv"); if (p_glVertexAttrib4dv) n++;
    *(void **)&p_glVertexAttrib4f = dlsym(mgl, "glVertexAttrib4f"); *(void **)&a_glVertexAttrib4f = dlsym(RTLD_NEXT, "glVertexAttrib4f"); if (p_glVertexAttrib4f) n++;
    *(void **)&p_glVertexAttrib4fv = dlsym(mgl, "glVertexAttrib4fv"); *(void **)&a_glVertexAttrib4fv = dlsym(RTLD_NEXT, "glVertexAttrib4fv"); if (p_glVertexAttrib4fv) n++;
    *(void **)&p_glVertexAttrib4iv = dlsym(mgl, "glVertexAttrib4iv"); *(void **)&a_glVertexAttrib4iv = dlsym(RTLD_NEXT, "glVertexAttrib4iv"); if (p_glVertexAttrib4iv) n++;
    *(void **)&p_glVertexAttrib4s = dlsym(mgl, "glVertexAttrib4s"); *(void **)&a_glVertexAttrib4s = dlsym(RTLD_NEXT, "glVertexAttrib4s"); if (p_glVertexAttrib4s) n++;
    *(void **)&p_glVertexAttrib4sv = dlsym(mgl, "glVertexAttrib4sv"); *(void **)&a_glVertexAttrib4sv = dlsym(RTLD_NEXT, "glVertexAttrib4sv"); if (p_glVertexAttrib4sv) n++;
    *(void **)&p_glVertexAttrib4ubv = dlsym(mgl, "glVertexAttrib4ubv"); *(void **)&a_glVertexAttrib4ubv = dlsym(RTLD_NEXT, "glVertexAttrib4ubv"); if (p_glVertexAttrib4ubv) n++;
    *(void **)&p_glVertexAttrib4uiv = dlsym(mgl, "glVertexAttrib4uiv"); *(void **)&a_glVertexAttrib4uiv = dlsym(RTLD_NEXT, "glVertexAttrib4uiv"); if (p_glVertexAttrib4uiv) n++;
    *(void **)&p_glVertexAttrib4usv = dlsym(mgl, "glVertexAttrib4usv"); *(void **)&a_glVertexAttrib4usv = dlsym(RTLD_NEXT, "glVertexAttrib4usv"); if (p_glVertexAttrib4usv) n++;
    *(void **)&p_glVertexAttribBinding = dlsym(mgl, "glVertexAttribBinding"); *(void **)&a_glVertexAttribBinding = dlsym(RTLD_NEXT, "glVertexAttribBinding"); if (p_glVertexAttribBinding) n++;
    *(void **)&p_glVertexAttribDivisor = dlsym(mgl, "glVertexAttribDivisor"); *(void **)&a_glVertexAttribDivisor = dlsym(RTLD_NEXT, "glVertexAttribDivisor"); if (p_glVertexAttribDivisor) n++;
    *(void **)&p_glVertexAttribFormat = dlsym(mgl, "glVertexAttribFormat"); *(void **)&a_glVertexAttribFormat = dlsym(RTLD_NEXT, "glVertexAttribFormat"); if (p_glVertexAttribFormat) n++;
    *(void **)&p_glVertexAttribI1i = dlsym(mgl, "glVertexAttribI1i"); *(void **)&a_glVertexAttribI1i = dlsym(RTLD_NEXT, "glVertexAttribI1i"); if (p_glVertexAttribI1i) n++;
    *(void **)&p_glVertexAttribI1iv = dlsym(mgl, "glVertexAttribI1iv"); *(void **)&a_glVertexAttribI1iv = dlsym(RTLD_NEXT, "glVertexAttribI1iv"); if (p_glVertexAttribI1iv) n++;
    *(void **)&p_glVertexAttribI1ui = dlsym(mgl, "glVertexAttribI1ui"); *(void **)&a_glVertexAttribI1ui = dlsym(RTLD_NEXT, "glVertexAttribI1ui"); if (p_glVertexAttribI1ui) n++;
    *(void **)&p_glVertexAttribI1uiv = dlsym(mgl, "glVertexAttribI1uiv"); *(void **)&a_glVertexAttribI1uiv = dlsym(RTLD_NEXT, "glVertexAttribI1uiv"); if (p_glVertexAttribI1uiv) n++;
    *(void **)&p_glVertexAttribI2i = dlsym(mgl, "glVertexAttribI2i"); *(void **)&a_glVertexAttribI2i = dlsym(RTLD_NEXT, "glVertexAttribI2i"); if (p_glVertexAttribI2i) n++;
    *(void **)&p_glVertexAttribI2iv = dlsym(mgl, "glVertexAttribI2iv"); *(void **)&a_glVertexAttribI2iv = dlsym(RTLD_NEXT, "glVertexAttribI2iv"); if (p_glVertexAttribI2iv) n++;
    *(void **)&p_glVertexAttribI2ui = dlsym(mgl, "glVertexAttribI2ui"); *(void **)&a_glVertexAttribI2ui = dlsym(RTLD_NEXT, "glVertexAttribI2ui"); if (p_glVertexAttribI2ui) n++;
    *(void **)&p_glVertexAttribI2uiv = dlsym(mgl, "glVertexAttribI2uiv"); *(void **)&a_glVertexAttribI2uiv = dlsym(RTLD_NEXT, "glVertexAttribI2uiv"); if (p_glVertexAttribI2uiv) n++;
    *(void **)&p_glVertexAttribI3i = dlsym(mgl, "glVertexAttribI3i"); *(void **)&a_glVertexAttribI3i = dlsym(RTLD_NEXT, "glVertexAttribI3i"); if (p_glVertexAttribI3i) n++;
    *(void **)&p_glVertexAttribI3iv = dlsym(mgl, "glVertexAttribI3iv"); *(void **)&a_glVertexAttribI3iv = dlsym(RTLD_NEXT, "glVertexAttribI3iv"); if (p_glVertexAttribI3iv) n++;
    *(void **)&p_glVertexAttribI3ui = dlsym(mgl, "glVertexAttribI3ui"); *(void **)&a_glVertexAttribI3ui = dlsym(RTLD_NEXT, "glVertexAttribI3ui"); if (p_glVertexAttribI3ui) n++;
    *(void **)&p_glVertexAttribI3uiv = dlsym(mgl, "glVertexAttribI3uiv"); *(void **)&a_glVertexAttribI3uiv = dlsym(RTLD_NEXT, "glVertexAttribI3uiv"); if (p_glVertexAttribI3uiv) n++;
    *(void **)&p_glVertexAttribI4bv = dlsym(mgl, "glVertexAttribI4bv"); *(void **)&a_glVertexAttribI4bv = dlsym(RTLD_NEXT, "glVertexAttribI4bv"); if (p_glVertexAttribI4bv) n++;
    *(void **)&p_glVertexAttribI4i = dlsym(mgl, "glVertexAttribI4i"); *(void **)&a_glVertexAttribI4i = dlsym(RTLD_NEXT, "glVertexAttribI4i"); if (p_glVertexAttribI4i) n++;
    *(void **)&p_glVertexAttribI4iv = dlsym(mgl, "glVertexAttribI4iv"); *(void **)&a_glVertexAttribI4iv = dlsym(RTLD_NEXT, "glVertexAttribI4iv"); if (p_glVertexAttribI4iv) n++;
    *(void **)&p_glVertexAttribI4sv = dlsym(mgl, "glVertexAttribI4sv"); *(void **)&a_glVertexAttribI4sv = dlsym(RTLD_NEXT, "glVertexAttribI4sv"); if (p_glVertexAttribI4sv) n++;
    *(void **)&p_glVertexAttribI4ubv = dlsym(mgl, "glVertexAttribI4ubv"); *(void **)&a_glVertexAttribI4ubv = dlsym(RTLD_NEXT, "glVertexAttribI4ubv"); if (p_glVertexAttribI4ubv) n++;
    *(void **)&p_glVertexAttribI4ui = dlsym(mgl, "glVertexAttribI4ui"); *(void **)&a_glVertexAttribI4ui = dlsym(RTLD_NEXT, "glVertexAttribI4ui"); if (p_glVertexAttribI4ui) n++;
    *(void **)&p_glVertexAttribI4uiv = dlsym(mgl, "glVertexAttribI4uiv"); *(void **)&a_glVertexAttribI4uiv = dlsym(RTLD_NEXT, "glVertexAttribI4uiv"); if (p_glVertexAttribI4uiv) n++;
    *(void **)&p_glVertexAttribI4usv = dlsym(mgl, "glVertexAttribI4usv"); *(void **)&a_glVertexAttribI4usv = dlsym(RTLD_NEXT, "glVertexAttribI4usv"); if (p_glVertexAttribI4usv) n++;
    *(void **)&p_glVertexAttribIFormat = dlsym(mgl, "glVertexAttribIFormat"); *(void **)&a_glVertexAttribIFormat = dlsym(RTLD_NEXT, "glVertexAttribIFormat"); if (p_glVertexAttribIFormat) n++;
    *(void **)&p_glVertexAttribIPointer = dlsym(mgl, "glVertexAttribIPointer"); *(void **)&a_glVertexAttribIPointer = dlsym(RTLD_NEXT, "glVertexAttribIPointer"); if (p_glVertexAttribIPointer) n++;
    *(void **)&p_glVertexAttribL1d = dlsym(mgl, "glVertexAttribL1d"); *(void **)&a_glVertexAttribL1d = dlsym(RTLD_NEXT, "glVertexAttribL1d"); if (p_glVertexAttribL1d) n++;
    *(void **)&p_glVertexAttribL1dv = dlsym(mgl, "glVertexAttribL1dv"); *(void **)&a_glVertexAttribL1dv = dlsym(RTLD_NEXT, "glVertexAttribL1dv"); if (p_glVertexAttribL1dv) n++;
    *(void **)&p_glVertexAttribL2d = dlsym(mgl, "glVertexAttribL2d"); *(void **)&a_glVertexAttribL2d = dlsym(RTLD_NEXT, "glVertexAttribL2d"); if (p_glVertexAttribL2d) n++;
    *(void **)&p_glVertexAttribL2dv = dlsym(mgl, "glVertexAttribL2dv"); *(void **)&a_glVertexAttribL2dv = dlsym(RTLD_NEXT, "glVertexAttribL2dv"); if (p_glVertexAttribL2dv) n++;
    *(void **)&p_glVertexAttribL3d = dlsym(mgl, "glVertexAttribL3d"); *(void **)&a_glVertexAttribL3d = dlsym(RTLD_NEXT, "glVertexAttribL3d"); if (p_glVertexAttribL3d) n++;
    *(void **)&p_glVertexAttribL3dv = dlsym(mgl, "glVertexAttribL3dv"); *(void **)&a_glVertexAttribL3dv = dlsym(RTLD_NEXT, "glVertexAttribL3dv"); if (p_glVertexAttribL3dv) n++;
    *(void **)&p_glVertexAttribL4d = dlsym(mgl, "glVertexAttribL4d"); *(void **)&a_glVertexAttribL4d = dlsym(RTLD_NEXT, "glVertexAttribL4d"); if (p_glVertexAttribL4d) n++;
    *(void **)&p_glVertexAttribL4dv = dlsym(mgl, "glVertexAttribL4dv"); *(void **)&a_glVertexAttribL4dv = dlsym(RTLD_NEXT, "glVertexAttribL4dv"); if (p_glVertexAttribL4dv) n++;
    *(void **)&p_glVertexAttribLFormat = dlsym(mgl, "glVertexAttribLFormat"); *(void **)&a_glVertexAttribLFormat = dlsym(RTLD_NEXT, "glVertexAttribLFormat"); if (p_glVertexAttribLFormat) n++;
    *(void **)&p_glVertexAttribLPointer = dlsym(mgl, "glVertexAttribLPointer"); *(void **)&a_glVertexAttribLPointer = dlsym(RTLD_NEXT, "glVertexAttribLPointer"); if (p_glVertexAttribLPointer) n++;
    *(void **)&p_glVertexAttribP1ui = dlsym(mgl, "glVertexAttribP1ui"); *(void **)&a_glVertexAttribP1ui = dlsym(RTLD_NEXT, "glVertexAttribP1ui"); if (p_glVertexAttribP1ui) n++;
    *(void **)&p_glVertexAttribP1uiv = dlsym(mgl, "glVertexAttribP1uiv"); *(void **)&a_glVertexAttribP1uiv = dlsym(RTLD_NEXT, "glVertexAttribP1uiv"); if (p_glVertexAttribP1uiv) n++;
    *(void **)&p_glVertexAttribP2ui = dlsym(mgl, "glVertexAttribP2ui"); *(void **)&a_glVertexAttribP2ui = dlsym(RTLD_NEXT, "glVertexAttribP2ui"); if (p_glVertexAttribP2ui) n++;
    *(void **)&p_glVertexAttribP2uiv = dlsym(mgl, "glVertexAttribP2uiv"); *(void **)&a_glVertexAttribP2uiv = dlsym(RTLD_NEXT, "glVertexAttribP2uiv"); if (p_glVertexAttribP2uiv) n++;
    *(void **)&p_glVertexAttribP3ui = dlsym(mgl, "glVertexAttribP3ui"); *(void **)&a_glVertexAttribP3ui = dlsym(RTLD_NEXT, "glVertexAttribP3ui"); if (p_glVertexAttribP3ui) n++;
    *(void **)&p_glVertexAttribP3uiv = dlsym(mgl, "glVertexAttribP3uiv"); *(void **)&a_glVertexAttribP3uiv = dlsym(RTLD_NEXT, "glVertexAttribP3uiv"); if (p_glVertexAttribP3uiv) n++;
    *(void **)&p_glVertexAttribP4ui = dlsym(mgl, "glVertexAttribP4ui"); *(void **)&a_glVertexAttribP4ui = dlsym(RTLD_NEXT, "glVertexAttribP4ui"); if (p_glVertexAttribP4ui) n++;
    *(void **)&p_glVertexAttribP4uiv = dlsym(mgl, "glVertexAttribP4uiv"); *(void **)&a_glVertexAttribP4uiv = dlsym(RTLD_NEXT, "glVertexAttribP4uiv"); if (p_glVertexAttribP4uiv) n++;
    *(void **)&p_glVertexAttribPointer = dlsym(mgl, "glVertexAttribPointer"); *(void **)&a_glVertexAttribPointer = dlsym(RTLD_NEXT, "glVertexAttribPointer"); if (p_glVertexAttribPointer) n++;
    *(void **)&p_glVertexBindingDivisor = dlsym(mgl, "glVertexBindingDivisor"); *(void **)&a_glVertexBindingDivisor = dlsym(RTLD_NEXT, "glVertexBindingDivisor"); if (p_glVertexBindingDivisor) n++;
    *(void **)&p_glViewport = dlsym(mgl, "glViewport"); *(void **)&a_glViewport = dlsym(RTLD_NEXT, "glViewport"); if (p_glViewport) n++;
    *(void **)&p_glViewportArrayv = dlsym(mgl, "glViewportArrayv"); *(void **)&a_glViewportArrayv = dlsym(RTLD_NEXT, "glViewportArrayv"); if (p_glViewportArrayv) n++;
    *(void **)&p_glViewportIndexedf = dlsym(mgl, "glViewportIndexedf"); *(void **)&a_glViewportIndexedf = dlsym(RTLD_NEXT, "glViewportIndexedf"); if (p_glViewportIndexedf) n++;
    *(void **)&p_glViewportIndexedfv = dlsym(mgl, "glViewportIndexedfv"); *(void **)&a_glViewportIndexedfv = dlsym(RTLD_NEXT, "glViewportIndexedfv"); if (p_glViewportIndexedfv) n++;
    *(void **)&p_glWaitSync = dlsym(mgl, "glWaitSync"); *(void **)&a_glWaitSync = dlsym(RTLD_NEXT, "glWaitSync"); if (p_glWaitSync) n++;
    return n;
}
