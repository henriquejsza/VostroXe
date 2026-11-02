/* GERADO por src/MGLShim/gen-interpose.py — não edite à mão. */
/* Redireciona as gl* do app para o MGL via DYLD interpose, COM PORTÃO: só desvia enquanto o contexto */
/* MGL do app está corrente (mglshim_active). Fora disso repassa para a gl* real da Apple (a_*), para não */
/* capturar as chamadas GL internas do AppKit durante a criação do contexto. */
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

void glAccum(GLenum op, GLfloat value) WEAKGL;
static void (*p_glAccum)(GLenum op, GLfloat value);
static void (*a_glAccum)(GLenum op, GLfloat value);
static void w_glAccum(GLenum op, GLfloat value) { if (mglshim_active && p_glAccum) { p_glAccum(op, value); return; } if (a_glAccum) a_glAccum(op, value); }
INTERPOSE(glAccum)
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
void glAlphaFunc(GLenum func, GLfloat ref) WEAKGL;
static void (*p_glAlphaFunc)(GLenum func, GLfloat ref);
static void (*a_glAlphaFunc)(GLenum func, GLfloat ref);
static void w_glAlphaFunc(GLenum func, GLfloat ref) { if (mglshim_active && p_glAlphaFunc) { p_glAlphaFunc(func, ref); return; } if (a_glAlphaFunc) a_glAlphaFunc(func, ref); }
INTERPOSE(glAlphaFunc)
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) WEAKGL;
static GLboolean (*p_glAreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences);
static GLboolean (*a_glAreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences);
static GLboolean w_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) { if (mglshim_active && p_glAreTexturesResident) return p_glAreTexturesResident(n, textures, residences); if (a_glAreTexturesResident) return a_glAreTexturesResident(n, textures, residences); return (GLboolean)0; }
INTERPOSE(glAreTexturesResident)
void glArrayElement(GLint i) WEAKGL;
static void (*p_glArrayElement)(GLint i);
static void (*a_glArrayElement)(GLint i);
static void w_glArrayElement(GLint i) { if (mglshim_active && p_glArrayElement) { p_glArrayElement(i); return; } if (a_glArrayElement) a_glArrayElement(i); }
INTERPOSE(glArrayElement)
void glAttachShader(GLuint program, GLuint shader) WEAKGL;
static void (*p_glAttachShader)(GLuint program, GLuint shader);
static void (*a_glAttachShader)(GLuint program, GLuint shader);
static void w_glAttachShader(GLuint program, GLuint shader) { if (mglshim_active && p_glAttachShader) { p_glAttachShader(program, shader); return; } if (a_glAttachShader) a_glAttachShader(program, shader); }
INTERPOSE(glAttachShader)
void glBegin(GLenum mode) WEAKGL;
static void (*p_glBegin)(GLenum mode);
static void (*a_glBegin)(GLenum mode);
static void w_glBegin(GLenum mode) { if (mglshim_active && p_glBegin) { p_glBegin(mode); return; } if (a_glBegin) a_glBegin(mode); }
INTERPOSE(glBegin)
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
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) WEAKGL;
static void (*p_glBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
static void (*a_glBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
static void w_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) { if (mglshim_active && p_glBitmap) { p_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap); return; } if (a_glBitmap) a_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap); }
INTERPOSE(glBitmap)
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
void glCallList(GLuint list) WEAKGL;
static void (*p_glCallList)(GLuint list);
static void (*a_glCallList)(GLuint list);
static void w_glCallList(GLuint list) { if (mglshim_active && p_glCallList) { p_glCallList(list); return; } if (a_glCallList) a_glCallList(list); }
INTERPOSE(glCallList)
void glCallLists(GLsizei n, GLenum type, const void *lists) WEAKGL;
static void (*p_glCallLists)(GLsizei n, GLenum type, const void *lists);
static void (*a_glCallLists)(GLsizei n, GLenum type, const void *lists);
static void w_glCallLists(GLsizei n, GLenum type, const void *lists) { if (mglshim_active && p_glCallLists) { p_glCallLists(n, type, lists); return; } if (a_glCallLists) a_glCallLists(n, type, lists); }
INTERPOSE(glCallLists)
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
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void (*a_glClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (mglshim_active && p_glClearAccum) { p_glClearAccum(red, green, blue, alpha); return; } if (a_glClearAccum) a_glClearAccum(red, green, blue, alpha); }
INTERPOSE(glClearAccum)
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
void glClearIndex(GLfloat c) WEAKGL;
static void (*p_glClearIndex)(GLfloat c);
static void (*a_glClearIndex)(GLfloat c);
static void w_glClearIndex(GLfloat c) { if (mglshim_active && p_glClearIndex) { p_glClearIndex(c); return; } if (a_glClearIndex) a_glClearIndex(c); }
INTERPOSE(glClearIndex)
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
void glClientActiveTexture(GLenum texture) WEAKGL;
static void (*p_glClientActiveTexture)(GLenum texture);
static void (*a_glClientActiveTexture)(GLenum texture);
static void w_glClientActiveTexture(GLenum texture) { if (mglshim_active && p_glClientActiveTexture) { p_glClientActiveTexture(texture); return; } if (a_glClientActiveTexture) a_glClientActiveTexture(texture); }
INTERPOSE(glClientActiveTexture)
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
void glClipPlane(GLenum plane, const GLdouble *equation) WEAKGL;
static void (*p_glClipPlane)(GLenum plane, const GLdouble *equation);
static void (*a_glClipPlane)(GLenum plane, const GLdouble *equation);
static void w_glClipPlane(GLenum plane, const GLdouble *equation) { if (mglshim_active && p_glClipPlane) { p_glClipPlane(plane, equation); return; } if (a_glClipPlane) a_glClipPlane(plane, equation); }
INTERPOSE(glClipPlane)
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) WEAKGL;
static void (*p_glColor3b)(GLbyte red, GLbyte green, GLbyte blue);
static void (*a_glColor3b)(GLbyte red, GLbyte green, GLbyte blue);
static void w_glColor3b(GLbyte red, GLbyte green, GLbyte blue) { if (mglshim_active && p_glColor3b) { p_glColor3b(red, green, blue); return; } if (a_glColor3b) a_glColor3b(red, green, blue); }
INTERPOSE(glColor3b)
void glColor3bv(const GLbyte *v) WEAKGL;
static void (*p_glColor3bv)(const GLbyte *v);
static void (*a_glColor3bv)(const GLbyte *v);
static void w_glColor3bv(const GLbyte *v) { if (mglshim_active && p_glColor3bv) { p_glColor3bv(v); return; } if (a_glColor3bv) a_glColor3bv(v); }
INTERPOSE(glColor3bv)
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) WEAKGL;
static void (*p_glColor3d)(GLdouble red, GLdouble green, GLdouble blue);
static void (*a_glColor3d)(GLdouble red, GLdouble green, GLdouble blue);
static void w_glColor3d(GLdouble red, GLdouble green, GLdouble blue) { if (mglshim_active && p_glColor3d) { p_glColor3d(red, green, blue); return; } if (a_glColor3d) a_glColor3d(red, green, blue); }
INTERPOSE(glColor3d)
void glColor3dv(const GLdouble *v) WEAKGL;
static void (*p_glColor3dv)(const GLdouble *v);
static void (*a_glColor3dv)(const GLdouble *v);
static void w_glColor3dv(const GLdouble *v) { if (mglshim_active && p_glColor3dv) { p_glColor3dv(v); return; } if (a_glColor3dv) a_glColor3dv(v); }
INTERPOSE(glColor3dv)
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) WEAKGL;
static void (*p_glColor3f)(GLfloat red, GLfloat green, GLfloat blue);
static void (*a_glColor3f)(GLfloat red, GLfloat green, GLfloat blue);
static void w_glColor3f(GLfloat red, GLfloat green, GLfloat blue) { if (mglshim_active && p_glColor3f) { p_glColor3f(red, green, blue); return; } if (a_glColor3f) a_glColor3f(red, green, blue); }
INTERPOSE(glColor3f)
void glColor3fv(const GLfloat *v) WEAKGL;
static void (*p_glColor3fv)(const GLfloat *v);
static void (*a_glColor3fv)(const GLfloat *v);
static void w_glColor3fv(const GLfloat *v) { if (mglshim_active && p_glColor3fv) { p_glColor3fv(v); return; } if (a_glColor3fv) a_glColor3fv(v); }
INTERPOSE(glColor3fv)
void glColor3i(GLint red, GLint green, GLint blue) WEAKGL;
static void (*p_glColor3i)(GLint red, GLint green, GLint blue);
static void (*a_glColor3i)(GLint red, GLint green, GLint blue);
static void w_glColor3i(GLint red, GLint green, GLint blue) { if (mglshim_active && p_glColor3i) { p_glColor3i(red, green, blue); return; } if (a_glColor3i) a_glColor3i(red, green, blue); }
INTERPOSE(glColor3i)
void glColor3iv(const GLint *v) WEAKGL;
static void (*p_glColor3iv)(const GLint *v);
static void (*a_glColor3iv)(const GLint *v);
static void w_glColor3iv(const GLint *v) { if (mglshim_active && p_glColor3iv) { p_glColor3iv(v); return; } if (a_glColor3iv) a_glColor3iv(v); }
INTERPOSE(glColor3iv)
void glColor3s(GLshort red, GLshort green, GLshort blue) WEAKGL;
static void (*p_glColor3s)(GLshort red, GLshort green, GLshort blue);
static void (*a_glColor3s)(GLshort red, GLshort green, GLshort blue);
static void w_glColor3s(GLshort red, GLshort green, GLshort blue) { if (mglshim_active && p_glColor3s) { p_glColor3s(red, green, blue); return; } if (a_glColor3s) a_glColor3s(red, green, blue); }
INTERPOSE(glColor3s)
void glColor3sv(const GLshort *v) WEAKGL;
static void (*p_glColor3sv)(const GLshort *v);
static void (*a_glColor3sv)(const GLshort *v);
static void w_glColor3sv(const GLshort *v) { if (mglshim_active && p_glColor3sv) { p_glColor3sv(v); return; } if (a_glColor3sv) a_glColor3sv(v); }
INTERPOSE(glColor3sv)
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) WEAKGL;
static void (*p_glColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
static void (*a_glColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
static void w_glColor3ub(GLubyte red, GLubyte green, GLubyte blue) { if (mglshim_active && p_glColor3ub) { p_glColor3ub(red, green, blue); return; } if (a_glColor3ub) a_glColor3ub(red, green, blue); }
INTERPOSE(glColor3ub)
void glColor3ubv(const GLubyte *v) WEAKGL;
static void (*p_glColor3ubv)(const GLubyte *v);
static void (*a_glColor3ubv)(const GLubyte *v);
static void w_glColor3ubv(const GLubyte *v) { if (mglshim_active && p_glColor3ubv) { p_glColor3ubv(v); return; } if (a_glColor3ubv) a_glColor3ubv(v); }
INTERPOSE(glColor3ubv)
void glColor3ui(GLuint red, GLuint green, GLuint blue) WEAKGL;
static void (*p_glColor3ui)(GLuint red, GLuint green, GLuint blue);
static void (*a_glColor3ui)(GLuint red, GLuint green, GLuint blue);
static void w_glColor3ui(GLuint red, GLuint green, GLuint blue) { if (mglshim_active && p_glColor3ui) { p_glColor3ui(red, green, blue); return; } if (a_glColor3ui) a_glColor3ui(red, green, blue); }
INTERPOSE(glColor3ui)
void glColor3uiv(const GLuint *v) WEAKGL;
static void (*p_glColor3uiv)(const GLuint *v);
static void (*a_glColor3uiv)(const GLuint *v);
static void w_glColor3uiv(const GLuint *v) { if (mglshim_active && p_glColor3uiv) { p_glColor3uiv(v); return; } if (a_glColor3uiv) a_glColor3uiv(v); }
INTERPOSE(glColor3uiv)
void glColor3us(GLushort red, GLushort green, GLushort blue) WEAKGL;
static void (*p_glColor3us)(GLushort red, GLushort green, GLushort blue);
static void (*a_glColor3us)(GLushort red, GLushort green, GLushort blue);
static void w_glColor3us(GLushort red, GLushort green, GLushort blue) { if (mglshim_active && p_glColor3us) { p_glColor3us(red, green, blue); return; } if (a_glColor3us) a_glColor3us(red, green, blue); }
INTERPOSE(glColor3us)
void glColor3usv(const GLushort *v) WEAKGL;
static void (*p_glColor3usv)(const GLushort *v);
static void (*a_glColor3usv)(const GLushort *v);
static void w_glColor3usv(const GLushort *v) { if (mglshim_active && p_glColor3usv) { p_glColor3usv(v); return; } if (a_glColor3usv) a_glColor3usv(v); }
INTERPOSE(glColor3usv)
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) WEAKGL;
static void (*p_glColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
static void (*a_glColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
static void w_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) { if (mglshim_active && p_glColor4b) { p_glColor4b(red, green, blue, alpha); return; } if (a_glColor4b) a_glColor4b(red, green, blue, alpha); }
INTERPOSE(glColor4b)
void glColor4bv(const GLbyte *v) WEAKGL;
static void (*p_glColor4bv)(const GLbyte *v);
static void (*a_glColor4bv)(const GLbyte *v);
static void w_glColor4bv(const GLbyte *v) { if (mglshim_active && p_glColor4bv) { p_glColor4bv(v); return; } if (a_glColor4bv) a_glColor4bv(v); }
INTERPOSE(glColor4bv)
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) WEAKGL;
static void (*p_glColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
static void (*a_glColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
static void w_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) { if (mglshim_active && p_glColor4d) { p_glColor4d(red, green, blue, alpha); return; } if (a_glColor4d) a_glColor4d(red, green, blue, alpha); }
INTERPOSE(glColor4d)
void glColor4dv(const GLdouble *v) WEAKGL;
static void (*p_glColor4dv)(const GLdouble *v);
static void (*a_glColor4dv)(const GLdouble *v);
static void w_glColor4dv(const GLdouble *v) { if (mglshim_active && p_glColor4dv) { p_glColor4dv(v); return; } if (a_glColor4dv) a_glColor4dv(v); }
INTERPOSE(glColor4dv)
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void (*a_glColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (mglshim_active && p_glColor4f) { p_glColor4f(red, green, blue, alpha); return; } if (a_glColor4f) a_glColor4f(red, green, blue, alpha); }
INTERPOSE(glColor4f)
void glColor4fv(const GLfloat *v) WEAKGL;
static void (*p_glColor4fv)(const GLfloat *v);
static void (*a_glColor4fv)(const GLfloat *v);
static void w_glColor4fv(const GLfloat *v) { if (mglshim_active && p_glColor4fv) { p_glColor4fv(v); return; } if (a_glColor4fv) a_glColor4fv(v); }
INTERPOSE(glColor4fv)
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) WEAKGL;
static void (*p_glColor4i)(GLint red, GLint green, GLint blue, GLint alpha);
static void (*a_glColor4i)(GLint red, GLint green, GLint blue, GLint alpha);
static void w_glColor4i(GLint red, GLint green, GLint blue, GLint alpha) { if (mglshim_active && p_glColor4i) { p_glColor4i(red, green, blue, alpha); return; } if (a_glColor4i) a_glColor4i(red, green, blue, alpha); }
INTERPOSE(glColor4i)
void glColor4iv(const GLint *v) WEAKGL;
static void (*p_glColor4iv)(const GLint *v);
static void (*a_glColor4iv)(const GLint *v);
static void w_glColor4iv(const GLint *v) { if (mglshim_active && p_glColor4iv) { p_glColor4iv(v); return; } if (a_glColor4iv) a_glColor4iv(v); }
INTERPOSE(glColor4iv)
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) WEAKGL;
static void (*p_glColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
static void (*a_glColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
static void w_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) { if (mglshim_active && p_glColor4s) { p_glColor4s(red, green, blue, alpha); return; } if (a_glColor4s) a_glColor4s(red, green, blue, alpha); }
INTERPOSE(glColor4s)
void glColor4sv(const GLshort *v) WEAKGL;
static void (*p_glColor4sv)(const GLshort *v);
static void (*a_glColor4sv)(const GLshort *v);
static void w_glColor4sv(const GLshort *v) { if (mglshim_active && p_glColor4sv) { p_glColor4sv(v); return; } if (a_glColor4sv) a_glColor4sv(v); }
INTERPOSE(glColor4sv)
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) WEAKGL;
static void (*p_glColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
static void (*a_glColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
static void w_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) { if (mglshim_active && p_glColor4ub) { p_glColor4ub(red, green, blue, alpha); return; } if (a_glColor4ub) a_glColor4ub(red, green, blue, alpha); }
INTERPOSE(glColor4ub)
void glColor4ubv(const GLubyte *v) WEAKGL;
static void (*p_glColor4ubv)(const GLubyte *v);
static void (*a_glColor4ubv)(const GLubyte *v);
static void w_glColor4ubv(const GLubyte *v) { if (mglshim_active && p_glColor4ubv) { p_glColor4ubv(v); return; } if (a_glColor4ubv) a_glColor4ubv(v); }
INTERPOSE(glColor4ubv)
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) WEAKGL;
static void (*p_glColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
static void (*a_glColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
static void w_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) { if (mglshim_active && p_glColor4ui) { p_glColor4ui(red, green, blue, alpha); return; } if (a_glColor4ui) a_glColor4ui(red, green, blue, alpha); }
INTERPOSE(glColor4ui)
void glColor4uiv(const GLuint *v) WEAKGL;
static void (*p_glColor4uiv)(const GLuint *v);
static void (*a_glColor4uiv)(const GLuint *v);
static void w_glColor4uiv(const GLuint *v) { if (mglshim_active && p_glColor4uiv) { p_glColor4uiv(v); return; } if (a_glColor4uiv) a_glColor4uiv(v); }
INTERPOSE(glColor4uiv)
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) WEAKGL;
static void (*p_glColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
static void (*a_glColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
static void w_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) { if (mglshim_active && p_glColor4us) { p_glColor4us(red, green, blue, alpha); return; } if (a_glColor4us) a_glColor4us(red, green, blue, alpha); }
INTERPOSE(glColor4us)
void glColor4usv(const GLushort *v) WEAKGL;
static void (*p_glColor4usv)(const GLushort *v);
static void (*a_glColor4usv)(const GLushort *v);
static void w_glColor4usv(const GLushort *v) { if (mglshim_active && p_glColor4usv) { p_glColor4usv(v); return; } if (a_glColor4usv) a_glColor4usv(v); }
INTERPOSE(glColor4usv)
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
void glColorMaterial(GLenum face, GLenum mode) WEAKGL;
static void (*p_glColorMaterial)(GLenum face, GLenum mode);
static void (*a_glColorMaterial)(GLenum face, GLenum mode);
static void w_glColorMaterial(GLenum face, GLenum mode) { if (mglshim_active && p_glColorMaterial) { p_glColorMaterial(face, mode); return; } if (a_glColorMaterial) a_glColorMaterial(face, mode); }
INTERPOSE(glColorMaterial)
void glColorP3ui(GLenum type, GLuint color) WEAKGL;
static void (*p_glColorP3ui)(GLenum type, GLuint color);
static void (*a_glColorP3ui)(GLenum type, GLuint color);
static void w_glColorP3ui(GLenum type, GLuint color) { if (mglshim_active && p_glColorP3ui) { p_glColorP3ui(type, color); return; } if (a_glColorP3ui) a_glColorP3ui(type, color); }
INTERPOSE(glColorP3ui)
void glColorP3uiv(GLenum type, const GLuint *color) WEAKGL;
static void (*p_glColorP3uiv)(GLenum type, const GLuint *color);
static void (*a_glColorP3uiv)(GLenum type, const GLuint *color);
static void w_glColorP3uiv(GLenum type, const GLuint *color) { if (mglshim_active && p_glColorP3uiv) { p_glColorP3uiv(type, color); return; } if (a_glColorP3uiv) a_glColorP3uiv(type, color); }
INTERPOSE(glColorP3uiv)
void glColorP4ui(GLenum type, GLuint color) WEAKGL;
static void (*p_glColorP4ui)(GLenum type, GLuint color);
static void (*a_glColorP4ui)(GLenum type, GLuint color);
static void w_glColorP4ui(GLenum type, GLuint color) { if (mglshim_active && p_glColorP4ui) { p_glColorP4ui(type, color); return; } if (a_glColorP4ui) a_glColorP4ui(type, color); }
INTERPOSE(glColorP4ui)
void glColorP4uiv(GLenum type, const GLuint *color) WEAKGL;
static void (*p_glColorP4uiv)(GLenum type, const GLuint *color);
static void (*a_glColorP4uiv)(GLenum type, const GLuint *color);
static void w_glColorP4uiv(GLenum type, const GLuint *color) { if (mglshim_active && p_glColorP4uiv) { p_glColorP4uiv(type, color); return; } if (a_glColorP4uiv) a_glColorP4uiv(type, color); }
INTERPOSE(glColorP4uiv)
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glColorPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*a_glColorPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glColorPointer) { p_glColorPointer(size, type, stride, pointer); return; } if (a_glColorPointer) a_glColorPointer(size, type, stride, pointer); }
INTERPOSE(glColorPointer)
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
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) WEAKGL;
static void (*p_glCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
static void (*a_glCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
static void w_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) { if (mglshim_active && p_glCopyPixels) { p_glCopyPixels(x, y, width, height, type); return; } if (a_glCopyPixels) a_glCopyPixels(x, y, width, height, type); }
INTERPOSE(glCopyPixels)
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
void glDeleteLists(GLuint list, GLsizei range) WEAKGL;
static void (*p_glDeleteLists)(GLuint list, GLsizei range);
static void (*a_glDeleteLists)(GLuint list, GLsizei range);
static void w_glDeleteLists(GLuint list, GLsizei range) { if (mglshim_active && p_glDeleteLists) { p_glDeleteLists(list, range); return; } if (a_glDeleteLists) a_glDeleteLists(list, range); }
INTERPOSE(glDeleteLists)
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
void glDisableClientState(GLenum array) WEAKGL;
static void (*p_glDisableClientState)(GLenum array);
static void (*a_glDisableClientState)(GLenum array);
static void w_glDisableClientState(GLenum array) { if (mglshim_active && p_glDisableClientState) { p_glDisableClientState(array); return; } if (a_glDisableClientState) a_glDisableClientState(array); }
INTERPOSE(glDisableClientState)
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
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void (*a_glDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void w_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { if (mglshim_active && p_glDrawPixels) { p_glDrawPixels(width, height, format, type, pixels); return; } if (a_glDrawPixels) a_glDrawPixels(width, height, format, type, pixels); }
INTERPOSE(glDrawPixels)
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
void glEdgeFlag(GLboolean flag) WEAKGL;
static void (*p_glEdgeFlag)(GLboolean flag);
static void (*a_glEdgeFlag)(GLboolean flag);
static void w_glEdgeFlag(GLboolean flag) { if (mglshim_active && p_glEdgeFlag) { p_glEdgeFlag(flag); return; } if (a_glEdgeFlag) a_glEdgeFlag(flag); }
INTERPOSE(glEdgeFlag)
void glEdgeFlagPointer(GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glEdgeFlagPointer)(GLsizei stride, const void *pointer);
static void (*a_glEdgeFlagPointer)(GLsizei stride, const void *pointer);
static void w_glEdgeFlagPointer(GLsizei stride, const void *pointer) { if (mglshim_active && p_glEdgeFlagPointer) { p_glEdgeFlagPointer(stride, pointer); return; } if (a_glEdgeFlagPointer) a_glEdgeFlagPointer(stride, pointer); }
INTERPOSE(glEdgeFlagPointer)
void glEdgeFlagv(const GLboolean *flag) WEAKGL;
static void (*p_glEdgeFlagv)(const GLboolean *flag);
static void (*a_glEdgeFlagv)(const GLboolean *flag);
static void w_glEdgeFlagv(const GLboolean *flag) { if (mglshim_active && p_glEdgeFlagv) { p_glEdgeFlagv(flag); return; } if (a_glEdgeFlagv) a_glEdgeFlagv(flag); }
INTERPOSE(glEdgeFlagv)
void glEnable(GLenum cap) WEAKGL;
static void (*p_glEnable)(GLenum cap);
static void (*a_glEnable)(GLenum cap);
static void w_glEnable(GLenum cap) { if (mglshim_active && p_glEnable) { p_glEnable(cap); return; } if (a_glEnable) a_glEnable(cap); }
INTERPOSE(glEnable)
void glEnableClientState(GLenum array) WEAKGL;
static void (*p_glEnableClientState)(GLenum array);
static void (*a_glEnableClientState)(GLenum array);
static void w_glEnableClientState(GLenum array) { if (mglshim_active && p_glEnableClientState) { p_glEnableClientState(array); return; } if (a_glEnableClientState) a_glEnableClientState(array); }
INTERPOSE(glEnableClientState)
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
void glEnd(void) WEAKGL;
static void (*p_glEnd)(void);
static void (*a_glEnd)(void);
static void w_glEnd(void) { if (mglshim_active && p_glEnd) { p_glEnd(); return; } if (a_glEnd) a_glEnd(); }
INTERPOSE(glEnd)
void glEndConditionalRender(void) WEAKGL;
static void (*p_glEndConditionalRender)(void);
static void (*a_glEndConditionalRender)(void);
static void w_glEndConditionalRender(void) { if (mglshim_active && p_glEndConditionalRender) { p_glEndConditionalRender(); return; } if (a_glEndConditionalRender) a_glEndConditionalRender(); }
INTERPOSE(glEndConditionalRender)
void glEndList(void) WEAKGL;
static void (*p_glEndList)(void);
static void (*a_glEndList)(void);
static void w_glEndList(void) { if (mglshim_active && p_glEndList) { p_glEndList(); return; } if (a_glEndList) a_glEndList(); }
INTERPOSE(glEndList)
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
void glEvalCoord1d(GLdouble u) WEAKGL;
static void (*p_glEvalCoord1d)(GLdouble u);
static void (*a_glEvalCoord1d)(GLdouble u);
static void w_glEvalCoord1d(GLdouble u) { if (mglshim_active && p_glEvalCoord1d) { p_glEvalCoord1d(u); return; } if (a_glEvalCoord1d) a_glEvalCoord1d(u); }
INTERPOSE(glEvalCoord1d)
void glEvalCoord1dv(const GLdouble *u) WEAKGL;
static void (*p_glEvalCoord1dv)(const GLdouble *u);
static void (*a_glEvalCoord1dv)(const GLdouble *u);
static void w_glEvalCoord1dv(const GLdouble *u) { if (mglshim_active && p_glEvalCoord1dv) { p_glEvalCoord1dv(u); return; } if (a_glEvalCoord1dv) a_glEvalCoord1dv(u); }
INTERPOSE(glEvalCoord1dv)
void glEvalCoord1f(GLfloat u) WEAKGL;
static void (*p_glEvalCoord1f)(GLfloat u);
static void (*a_glEvalCoord1f)(GLfloat u);
static void w_glEvalCoord1f(GLfloat u) { if (mglshim_active && p_glEvalCoord1f) { p_glEvalCoord1f(u); return; } if (a_glEvalCoord1f) a_glEvalCoord1f(u); }
INTERPOSE(glEvalCoord1f)
void glEvalCoord1fv(const GLfloat *u) WEAKGL;
static void (*p_glEvalCoord1fv)(const GLfloat *u);
static void (*a_glEvalCoord1fv)(const GLfloat *u);
static void w_glEvalCoord1fv(const GLfloat *u) { if (mglshim_active && p_glEvalCoord1fv) { p_glEvalCoord1fv(u); return; } if (a_glEvalCoord1fv) a_glEvalCoord1fv(u); }
INTERPOSE(glEvalCoord1fv)
void glEvalCoord2d(GLdouble u, GLdouble v) WEAKGL;
static void (*p_glEvalCoord2d)(GLdouble u, GLdouble v);
static void (*a_glEvalCoord2d)(GLdouble u, GLdouble v);
static void w_glEvalCoord2d(GLdouble u, GLdouble v) { if (mglshim_active && p_glEvalCoord2d) { p_glEvalCoord2d(u, v); return; } if (a_glEvalCoord2d) a_glEvalCoord2d(u, v); }
INTERPOSE(glEvalCoord2d)
void glEvalCoord2dv(const GLdouble *u) WEAKGL;
static void (*p_glEvalCoord2dv)(const GLdouble *u);
static void (*a_glEvalCoord2dv)(const GLdouble *u);
static void w_glEvalCoord2dv(const GLdouble *u) { if (mglshim_active && p_glEvalCoord2dv) { p_glEvalCoord2dv(u); return; } if (a_glEvalCoord2dv) a_glEvalCoord2dv(u); }
INTERPOSE(glEvalCoord2dv)
void glEvalCoord2f(GLfloat u, GLfloat v) WEAKGL;
static void (*p_glEvalCoord2f)(GLfloat u, GLfloat v);
static void (*a_glEvalCoord2f)(GLfloat u, GLfloat v);
static void w_glEvalCoord2f(GLfloat u, GLfloat v) { if (mglshim_active && p_glEvalCoord2f) { p_glEvalCoord2f(u, v); return; } if (a_glEvalCoord2f) a_glEvalCoord2f(u, v); }
INTERPOSE(glEvalCoord2f)
void glEvalCoord2fv(const GLfloat *u) WEAKGL;
static void (*p_glEvalCoord2fv)(const GLfloat *u);
static void (*a_glEvalCoord2fv)(const GLfloat *u);
static void w_glEvalCoord2fv(const GLfloat *u) { if (mglshim_active && p_glEvalCoord2fv) { p_glEvalCoord2fv(u); return; } if (a_glEvalCoord2fv) a_glEvalCoord2fv(u); }
INTERPOSE(glEvalCoord2fv)
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) WEAKGL;
static void (*p_glEvalMesh1)(GLenum mode, GLint i1, GLint i2);
static void (*a_glEvalMesh1)(GLenum mode, GLint i1, GLint i2);
static void w_glEvalMesh1(GLenum mode, GLint i1, GLint i2) { if (mglshim_active && p_glEvalMesh1) { p_glEvalMesh1(mode, i1, i2); return; } if (a_glEvalMesh1) a_glEvalMesh1(mode, i1, i2); }
INTERPOSE(glEvalMesh1)
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) WEAKGL;
static void (*p_glEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
static void (*a_glEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
static void w_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) { if (mglshim_active && p_glEvalMesh2) { p_glEvalMesh2(mode, i1, i2, j1, j2); return; } if (a_glEvalMesh2) a_glEvalMesh2(mode, i1, i2, j1, j2); }
INTERPOSE(glEvalMesh2)
void glEvalPoint1(GLint i) WEAKGL;
static void (*p_glEvalPoint1)(GLint i);
static void (*a_glEvalPoint1)(GLint i);
static void w_glEvalPoint1(GLint i) { if (mglshim_active && p_glEvalPoint1) { p_glEvalPoint1(i); return; } if (a_glEvalPoint1) a_glEvalPoint1(i); }
INTERPOSE(glEvalPoint1)
void glEvalPoint2(GLint i, GLint j) WEAKGL;
static void (*p_glEvalPoint2)(GLint i, GLint j);
static void (*a_glEvalPoint2)(GLint i, GLint j);
static void w_glEvalPoint2(GLint i, GLint j) { if (mglshim_active && p_glEvalPoint2) { p_glEvalPoint2(i, j); return; } if (a_glEvalPoint2) a_glEvalPoint2(i, j); }
INTERPOSE(glEvalPoint2)
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) WEAKGL;
static void (*p_glFeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer);
static void (*a_glFeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer);
static void w_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) { if (mglshim_active && p_glFeedbackBuffer) { p_glFeedbackBuffer(size, type, buffer); return; } if (a_glFeedbackBuffer) a_glFeedbackBuffer(size, type, buffer); }
INTERPOSE(glFeedbackBuffer)
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
void glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glFogCoordPointer)(GLenum type, GLsizei stride, const void *pointer);
static void (*a_glFogCoordPointer)(GLenum type, GLsizei stride, const void *pointer);
static void w_glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glFogCoordPointer) { p_glFogCoordPointer(type, stride, pointer); return; } if (a_glFogCoordPointer) a_glFogCoordPointer(type, stride, pointer); }
INTERPOSE(glFogCoordPointer)
void glFogCoordd(GLdouble coord) WEAKGL;
static void (*p_glFogCoordd)(GLdouble coord);
static void (*a_glFogCoordd)(GLdouble coord);
static void w_glFogCoordd(GLdouble coord) { if (mglshim_active && p_glFogCoordd) { p_glFogCoordd(coord); return; } if (a_glFogCoordd) a_glFogCoordd(coord); }
INTERPOSE(glFogCoordd)
void glFogCoorddv(const GLdouble *coord) WEAKGL;
static void (*p_glFogCoorddv)(const GLdouble *coord);
static void (*a_glFogCoorddv)(const GLdouble *coord);
static void w_glFogCoorddv(const GLdouble *coord) { if (mglshim_active && p_glFogCoorddv) { p_glFogCoorddv(coord); return; } if (a_glFogCoorddv) a_glFogCoorddv(coord); }
INTERPOSE(glFogCoorddv)
void glFogCoordf(GLfloat coord) WEAKGL;
static void (*p_glFogCoordf)(GLfloat coord);
static void (*a_glFogCoordf)(GLfloat coord);
static void w_glFogCoordf(GLfloat coord) { if (mglshim_active && p_glFogCoordf) { p_glFogCoordf(coord); return; } if (a_glFogCoordf) a_glFogCoordf(coord); }
INTERPOSE(glFogCoordf)
void glFogCoordfv(const GLfloat *coord) WEAKGL;
static void (*p_glFogCoordfv)(const GLfloat *coord);
static void (*a_glFogCoordfv)(const GLfloat *coord);
static void w_glFogCoordfv(const GLfloat *coord) { if (mglshim_active && p_glFogCoordfv) { p_glFogCoordfv(coord); return; } if (a_glFogCoordfv) a_glFogCoordfv(coord); }
INTERPOSE(glFogCoordfv)
void glFogf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glFogf)(GLenum pname, GLfloat param);
static void (*a_glFogf)(GLenum pname, GLfloat param);
static void w_glFogf(GLenum pname, GLfloat param) { if (mglshim_active && p_glFogf) { p_glFogf(pname, param); return; } if (a_glFogf) a_glFogf(pname, param); }
INTERPOSE(glFogf)
void glFogfv(GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glFogfv)(GLenum pname, const GLfloat *params);
static void (*a_glFogfv)(GLenum pname, const GLfloat *params);
static void w_glFogfv(GLenum pname, const GLfloat *params) { if (mglshim_active && p_glFogfv) { p_glFogfv(pname, params); return; } if (a_glFogfv) a_glFogfv(pname, params); }
INTERPOSE(glFogfv)
void glFogi(GLenum pname, GLint param) WEAKGL;
static void (*p_glFogi)(GLenum pname, GLint param);
static void (*a_glFogi)(GLenum pname, GLint param);
static void w_glFogi(GLenum pname, GLint param) { if (mglshim_active && p_glFogi) { p_glFogi(pname, param); return; } if (a_glFogi) a_glFogi(pname, param); }
INTERPOSE(glFogi)
void glFogiv(GLenum pname, const GLint *params) WEAKGL;
static void (*p_glFogiv)(GLenum pname, const GLint *params);
static void (*a_glFogiv)(GLenum pname, const GLint *params);
static void w_glFogiv(GLenum pname, const GLint *params) { if (mglshim_active && p_glFogiv) { p_glFogiv(pname, params); return; } if (a_glFogiv) a_glFogiv(pname, params); }
INTERPOSE(glFogiv)
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
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) WEAKGL;
static void (*p_glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void (*a_glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void w_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) { if (mglshim_active && p_glFrustum) { p_glFrustum(left, right, bottom, top, zNear, zFar); return; } if (a_glFrustum) a_glFrustum(left, right, bottom, top, zNear, zFar); }
INTERPOSE(glFrustum)
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
GLuint glGenLists(GLsizei range) WEAKGL;
static GLuint (*p_glGenLists)(GLsizei range);
static GLuint (*a_glGenLists)(GLsizei range);
static GLuint w_glGenLists(GLsizei range) { if (mglshim_active && p_glGenLists) return p_glGenLists(range); if (a_glGenLists) return a_glGenLists(range); return (GLuint)0; }
INTERPOSE(glGenLists)
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
void glGetClipPlane(GLenum plane, GLdouble *equation) WEAKGL;
static void (*p_glGetClipPlane)(GLenum plane, GLdouble *equation);
static void (*a_glGetClipPlane)(GLenum plane, GLdouble *equation);
static void w_glGetClipPlane(GLenum plane, GLdouble *equation) { if (mglshim_active && p_glGetClipPlane) { p_glGetClipPlane(plane, equation); return; } if (a_glGetClipPlane) a_glGetClipPlane(plane, equation); }
INTERPOSE(glGetClipPlane)
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
void glGetLightfv(GLenum light, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetLightfv)(GLenum light, GLenum pname, GLfloat *params);
static void (*a_glGetLightfv)(GLenum light, GLenum pname, GLfloat *params);
static void w_glGetLightfv(GLenum light, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetLightfv) { p_glGetLightfv(light, pname, params); return; } if (a_glGetLightfv) a_glGetLightfv(light, pname, params); }
INTERPOSE(glGetLightfv)
void glGetLightiv(GLenum light, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetLightiv)(GLenum light, GLenum pname, GLint *params);
static void (*a_glGetLightiv)(GLenum light, GLenum pname, GLint *params);
static void w_glGetLightiv(GLenum light, GLenum pname, GLint *params) { if (mglshim_active && p_glGetLightiv) { p_glGetLightiv(light, pname, params); return; } if (a_glGetLightiv) a_glGetLightiv(light, pname, params); }
INTERPOSE(glGetLightiv)
void glGetMapdv(GLenum target, GLenum query, GLdouble *v) WEAKGL;
static void (*p_glGetMapdv)(GLenum target, GLenum query, GLdouble *v);
static void (*a_glGetMapdv)(GLenum target, GLenum query, GLdouble *v);
static void w_glGetMapdv(GLenum target, GLenum query, GLdouble *v) { if (mglshim_active && p_glGetMapdv) { p_glGetMapdv(target, query, v); return; } if (a_glGetMapdv) a_glGetMapdv(target, query, v); }
INTERPOSE(glGetMapdv)
void glGetMapfv(GLenum target, GLenum query, GLfloat *v) WEAKGL;
static void (*p_glGetMapfv)(GLenum target, GLenum query, GLfloat *v);
static void (*a_glGetMapfv)(GLenum target, GLenum query, GLfloat *v);
static void w_glGetMapfv(GLenum target, GLenum query, GLfloat *v) { if (mglshim_active && p_glGetMapfv) { p_glGetMapfv(target, query, v); return; } if (a_glGetMapfv) a_glGetMapfv(target, query, v); }
INTERPOSE(glGetMapfv)
void glGetMapiv(GLenum target, GLenum query, GLint *v) WEAKGL;
static void (*p_glGetMapiv)(GLenum target, GLenum query, GLint *v);
static void (*a_glGetMapiv)(GLenum target, GLenum query, GLint *v);
static void w_glGetMapiv(GLenum target, GLenum query, GLint *v) { if (mglshim_active && p_glGetMapiv) { p_glGetMapiv(target, query, v); return; } if (a_glGetMapiv) a_glGetMapiv(target, query, v); }
INTERPOSE(glGetMapiv)
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetMaterialfv)(GLenum face, GLenum pname, GLfloat *params);
static void (*a_glGetMaterialfv)(GLenum face, GLenum pname, GLfloat *params);
static void w_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetMaterialfv) { p_glGetMaterialfv(face, pname, params); return; } if (a_glGetMaterialfv) a_glGetMaterialfv(face, pname, params); }
INTERPOSE(glGetMaterialfv)
void glGetMaterialiv(GLenum face, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetMaterialiv)(GLenum face, GLenum pname, GLint *params);
static void (*a_glGetMaterialiv)(GLenum face, GLenum pname, GLint *params);
static void w_glGetMaterialiv(GLenum face, GLenum pname, GLint *params) { if (mglshim_active && p_glGetMaterialiv) { p_glGetMaterialiv(face, pname, params); return; } if (a_glGetMaterialiv) a_glGetMaterialiv(face, pname, params); }
INTERPOSE(glGetMaterialiv)
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
void glGetPixelMapfv(GLenum map, GLfloat *values) WEAKGL;
static void (*p_glGetPixelMapfv)(GLenum map, GLfloat *values);
static void (*a_glGetPixelMapfv)(GLenum map, GLfloat *values);
static void w_glGetPixelMapfv(GLenum map, GLfloat *values) { if (mglshim_active && p_glGetPixelMapfv) { p_glGetPixelMapfv(map, values); return; } if (a_glGetPixelMapfv) a_glGetPixelMapfv(map, values); }
INTERPOSE(glGetPixelMapfv)
void glGetPixelMapuiv(GLenum map, GLuint *values) WEAKGL;
static void (*p_glGetPixelMapuiv)(GLenum map, GLuint *values);
static void (*a_glGetPixelMapuiv)(GLenum map, GLuint *values);
static void w_glGetPixelMapuiv(GLenum map, GLuint *values) { if (mglshim_active && p_glGetPixelMapuiv) { p_glGetPixelMapuiv(map, values); return; } if (a_glGetPixelMapuiv) a_glGetPixelMapuiv(map, values); }
INTERPOSE(glGetPixelMapuiv)
void glGetPixelMapusv(GLenum map, GLushort *values) WEAKGL;
static void (*p_glGetPixelMapusv)(GLenum map, GLushort *values);
static void (*a_glGetPixelMapusv)(GLenum map, GLushort *values);
static void w_glGetPixelMapusv(GLenum map, GLushort *values) { if (mglshim_active && p_glGetPixelMapusv) { p_glGetPixelMapusv(map, values); return; } if (a_glGetPixelMapusv) a_glGetPixelMapusv(map, values); }
INTERPOSE(glGetPixelMapusv)
void glGetPointerv(GLenum pname, void **params) WEAKGL;
static void (*p_glGetPointerv)(GLenum pname, void **params);
static void (*a_glGetPointerv)(GLenum pname, void **params);
static void w_glGetPointerv(GLenum pname, void **params) { if (mglshim_active && p_glGetPointerv) { p_glGetPointerv(pname, params); return; } if (a_glGetPointerv) a_glGetPointerv(pname, params); }
INTERPOSE(glGetPointerv)
void glGetPolygonStipple(GLubyte *mask) WEAKGL;
static void (*p_glGetPolygonStipple)(GLubyte *mask);
static void (*a_glGetPolygonStipple)(GLubyte *mask);
static void w_glGetPolygonStipple(GLubyte *mask) { if (mglshim_active && p_glGetPolygonStipple) { p_glGetPolygonStipple(mask); return; } if (a_glGetPolygonStipple) a_glGetPolygonStipple(mask); }
INTERPOSE(glGetPolygonStipple)
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
GLubyte const  * glGetString(GLenum name) WEAKGL;
static GLubyte const  * (*p_glGetString)(GLenum name);
static GLubyte const  * (*a_glGetString)(GLenum name);
static GLubyte const  * w_glGetString(GLenum name) { if (mglshim_active && p_glGetString) return p_glGetString(name); if (a_glGetString) return a_glGetString(name); return (GLubyte const  *)0; }
INTERPOSE(glGetString)
GLubyte const  * glGetStringi(GLenum name, GLuint index) WEAKGL;
static GLubyte const  * (*p_glGetStringi)(GLenum name, GLuint index);
static GLubyte const  * (*a_glGetStringi)(GLenum name, GLuint index);
static GLubyte const  * w_glGetStringi(GLenum name, GLuint index) { if (mglshim_active && p_glGetStringi) return p_glGetStringi(name, index); if (a_glGetStringi) return a_glGetStringi(name, index); return (GLubyte const  *)0; }
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
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params);
static void (*a_glGetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params);
static void w_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetTexEnvfv) { p_glGetTexEnvfv(target, pname, params); return; } if (a_glGetTexEnvfv) a_glGetTexEnvfv(target, pname, params); }
INTERPOSE(glGetTexEnvfv)
void glGetTexEnviv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexEnviv)(GLenum target, GLenum pname, GLint *params);
static void (*a_glGetTexEnviv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetTexEnviv(GLenum target, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTexEnviv) { p_glGetTexEnviv(target, pname, params); return; } if (a_glGetTexEnviv) a_glGetTexEnviv(target, pname, params); }
INTERPOSE(glGetTexEnviv)
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) WEAKGL;
static void (*p_glGetTexGendv)(GLenum coord, GLenum pname, GLdouble *params);
static void (*a_glGetTexGendv)(GLenum coord, GLenum pname, GLdouble *params);
static void w_glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) { if (mglshim_active && p_glGetTexGendv) { p_glGetTexGendv(coord, pname, params); return; } if (a_glGetTexGendv) a_glGetTexGendv(coord, pname, params); }
INTERPOSE(glGetTexGendv)
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params);
static void (*a_glGetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params);
static void w_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) { if (mglshim_active && p_glGetTexGenfv) { p_glGetTexGenfv(coord, pname, params); return; } if (a_glGetTexGenfv) a_glGetTexGenfv(coord, pname, params); }
INTERPOSE(glGetTexGenfv)
void glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexGeniv)(GLenum coord, GLenum pname, GLint *params);
static void (*a_glGetTexGeniv)(GLenum coord, GLenum pname, GLint *params);
static void w_glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) { if (mglshim_active && p_glGetTexGeniv) { p_glGetTexGeniv(coord, pname, params); return; } if (a_glGetTexGeniv) a_glGetTexGeniv(coord, pname, params); }
INTERPOSE(glGetTexGeniv)
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
void glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) WEAKGL;
static void (*p_glGetnColorTable)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
static void (*a_glGetnColorTable)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
static void w_glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) { if (mglshim_active && p_glGetnColorTable) { p_glGetnColorTable(target, format, type, bufSize, table); return; } if (a_glGetnColorTable) a_glGetnColorTable(target, format, type, bufSize, table); }
INTERPOSE(glGetnColorTable)
void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
static void (*a_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
static void w_glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) { if (mglshim_active && p_glGetnCompressedTexImage) { p_glGetnCompressedTexImage(target, lod, bufSize, pixels); return; } if (a_glGetnCompressedTexImage) a_glGetnCompressedTexImage(target, lod, bufSize, pixels); }
INTERPOSE(glGetnCompressedTexImage)
void glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) WEAKGL;
static void (*p_glGetnConvolutionFilter)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
static void (*a_glGetnConvolutionFilter)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
static void w_glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) { if (mglshim_active && p_glGetnConvolutionFilter) { p_glGetnConvolutionFilter(target, format, type, bufSize, image); return; } if (a_glGetnConvolutionFilter) a_glGetnConvolutionFilter(target, format, type, bufSize, image); }
INTERPOSE(glGetnConvolutionFilter)
void glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) WEAKGL;
static void (*p_glGetnHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
static void (*a_glGetnHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
static void w_glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) { if (mglshim_active && p_glGetnHistogram) { p_glGetnHistogram(target, reset, format, type, bufSize, values); return; } if (a_glGetnHistogram) a_glGetnHistogram(target, reset, format, type, bufSize, values); }
INTERPOSE(glGetnHistogram)
void glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) WEAKGL;
static void (*p_glGetnMapdv)(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
static void (*a_glGetnMapdv)(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
static void w_glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) { if (mglshim_active && p_glGetnMapdv) { p_glGetnMapdv(target, query, bufSize, v); return; } if (a_glGetnMapdv) a_glGetnMapdv(target, query, bufSize, v); }
INTERPOSE(glGetnMapdv)
void glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) WEAKGL;
static void (*p_glGetnMapfv)(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
static void (*a_glGetnMapfv)(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
static void w_glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) { if (mglshim_active && p_glGetnMapfv) { p_glGetnMapfv(target, query, bufSize, v); return; } if (a_glGetnMapfv) a_glGetnMapfv(target, query, bufSize, v); }
INTERPOSE(glGetnMapfv)
void glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint *v) WEAKGL;
static void (*p_glGetnMapiv)(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
static void (*a_glGetnMapiv)(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
static void w_glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint *v) { if (mglshim_active && p_glGetnMapiv) { p_glGetnMapiv(target, query, bufSize, v); return; } if (a_glGetnMapiv) a_glGetnMapiv(target, query, bufSize, v); }
INTERPOSE(glGetnMapiv)
void glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) WEAKGL;
static void (*p_glGetnMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
static void (*a_glGetnMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
static void w_glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) { if (mglshim_active && p_glGetnMinmax) { p_glGetnMinmax(target, reset, format, type, bufSize, values); return; } if (a_glGetnMinmax) a_glGetnMinmax(target, reset, format, type, bufSize, values); }
INTERPOSE(glGetnMinmax)
void glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat *values) WEAKGL;
static void (*p_glGetnPixelMapfv)(GLenum map, GLsizei bufSize, GLfloat *values);
static void (*a_glGetnPixelMapfv)(GLenum map, GLsizei bufSize, GLfloat *values);
static void w_glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat *values) { if (mglshim_active && p_glGetnPixelMapfv) { p_glGetnPixelMapfv(map, bufSize, values); return; } if (a_glGetnPixelMapfv) a_glGetnPixelMapfv(map, bufSize, values); }
INTERPOSE(glGetnPixelMapfv)
void glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint *values) WEAKGL;
static void (*p_glGetnPixelMapuiv)(GLenum map, GLsizei bufSize, GLuint *values);
static void (*a_glGetnPixelMapuiv)(GLenum map, GLsizei bufSize, GLuint *values);
static void w_glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint *values) { if (mglshim_active && p_glGetnPixelMapuiv) { p_glGetnPixelMapuiv(map, bufSize, values); return; } if (a_glGetnPixelMapuiv) a_glGetnPixelMapuiv(map, bufSize, values); }
INTERPOSE(glGetnPixelMapuiv)
void glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort *values) WEAKGL;
static void (*p_glGetnPixelMapusv)(GLenum map, GLsizei bufSize, GLushort *values);
static void (*a_glGetnPixelMapusv)(GLenum map, GLsizei bufSize, GLushort *values);
static void w_glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort *values) { if (mglshim_active && p_glGetnPixelMapusv) { p_glGetnPixelMapusv(map, bufSize, values); return; } if (a_glGetnPixelMapusv) a_glGetnPixelMapusv(map, bufSize, values); }
INTERPOSE(glGetnPixelMapusv)
void glGetnPolygonStipple(GLsizei bufSize, GLubyte *pattern) WEAKGL;
static void (*p_glGetnPolygonStipple)(GLsizei bufSize, GLubyte *pattern);
static void (*a_glGetnPolygonStipple)(GLsizei bufSize, GLubyte *pattern);
static void w_glGetnPolygonStipple(GLsizei bufSize, GLubyte *pattern) { if (mglshim_active && p_glGetnPolygonStipple) { p_glGetnPolygonStipple(bufSize, pattern); return; } if (a_glGetnPolygonStipple) a_glGetnPolygonStipple(bufSize, pattern); }
INTERPOSE(glGetnPolygonStipple)
void glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) WEAKGL;
static void (*p_glGetnSeparableFilter)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
static void (*a_glGetnSeparableFilter)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
static void w_glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) { if (mglshim_active && p_glGetnSeparableFilter) { p_glGetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span); return; } if (a_glGetnSeparableFilter) a_glGetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span); }
INTERPOSE(glGetnSeparableFilter)
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
void glIndexMask(GLuint mask) WEAKGL;
static void (*p_glIndexMask)(GLuint mask);
static void (*a_glIndexMask)(GLuint mask);
static void w_glIndexMask(GLuint mask) { if (mglshim_active && p_glIndexMask) { p_glIndexMask(mask); return; } if (a_glIndexMask) a_glIndexMask(mask); }
INTERPOSE(glIndexMask)
void glIndexPointer(GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glIndexPointer)(GLenum type, GLsizei stride, const void *pointer);
static void (*a_glIndexPointer)(GLenum type, GLsizei stride, const void *pointer);
static void w_glIndexPointer(GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glIndexPointer) { p_glIndexPointer(type, stride, pointer); return; } if (a_glIndexPointer) a_glIndexPointer(type, stride, pointer); }
INTERPOSE(glIndexPointer)
void glIndexd(GLdouble c) WEAKGL;
static void (*p_glIndexd)(GLdouble c);
static void (*a_glIndexd)(GLdouble c);
static void w_glIndexd(GLdouble c) { if (mglshim_active && p_glIndexd) { p_glIndexd(c); return; } if (a_glIndexd) a_glIndexd(c); }
INTERPOSE(glIndexd)
void glIndexdv(const GLdouble *c) WEAKGL;
static void (*p_glIndexdv)(const GLdouble *c);
static void (*a_glIndexdv)(const GLdouble *c);
static void w_glIndexdv(const GLdouble *c) { if (mglshim_active && p_glIndexdv) { p_glIndexdv(c); return; } if (a_glIndexdv) a_glIndexdv(c); }
INTERPOSE(glIndexdv)
void glIndexf(GLfloat c) WEAKGL;
static void (*p_glIndexf)(GLfloat c);
static void (*a_glIndexf)(GLfloat c);
static void w_glIndexf(GLfloat c) { if (mglshim_active && p_glIndexf) { p_glIndexf(c); return; } if (a_glIndexf) a_glIndexf(c); }
INTERPOSE(glIndexf)
void glIndexfv(const GLfloat *c) WEAKGL;
static void (*p_glIndexfv)(const GLfloat *c);
static void (*a_glIndexfv)(const GLfloat *c);
static void w_glIndexfv(const GLfloat *c) { if (mglshim_active && p_glIndexfv) { p_glIndexfv(c); return; } if (a_glIndexfv) a_glIndexfv(c); }
INTERPOSE(glIndexfv)
void glIndexi(GLint c) WEAKGL;
static void (*p_glIndexi)(GLint c);
static void (*a_glIndexi)(GLint c);
static void w_glIndexi(GLint c) { if (mglshim_active && p_glIndexi) { p_glIndexi(c); return; } if (a_glIndexi) a_glIndexi(c); }
INTERPOSE(glIndexi)
void glIndexiv(const GLint *c) WEAKGL;
static void (*p_glIndexiv)(const GLint *c);
static void (*a_glIndexiv)(const GLint *c);
static void w_glIndexiv(const GLint *c) { if (mglshim_active && p_glIndexiv) { p_glIndexiv(c); return; } if (a_glIndexiv) a_glIndexiv(c); }
INTERPOSE(glIndexiv)
void glIndexs(GLshort c) WEAKGL;
static void (*p_glIndexs)(GLshort c);
static void (*a_glIndexs)(GLshort c);
static void w_glIndexs(GLshort c) { if (mglshim_active && p_glIndexs) { p_glIndexs(c); return; } if (a_glIndexs) a_glIndexs(c); }
INTERPOSE(glIndexs)
void glIndexsv(const GLshort *c) WEAKGL;
static void (*p_glIndexsv)(const GLshort *c);
static void (*a_glIndexsv)(const GLshort *c);
static void w_glIndexsv(const GLshort *c) { if (mglshim_active && p_glIndexsv) { p_glIndexsv(c); return; } if (a_glIndexsv) a_glIndexsv(c); }
INTERPOSE(glIndexsv)
void glIndexub(GLubyte c) WEAKGL;
static void (*p_glIndexub)(GLubyte c);
static void (*a_glIndexub)(GLubyte c);
static void w_glIndexub(GLubyte c) { if (mglshim_active && p_glIndexub) { p_glIndexub(c); return; } if (a_glIndexub) a_glIndexub(c); }
INTERPOSE(glIndexub)
void glIndexubv(const GLubyte *c) WEAKGL;
static void (*p_glIndexubv)(const GLubyte *c);
static void (*a_glIndexubv)(const GLubyte *c);
static void w_glIndexubv(const GLubyte *c) { if (mglshim_active && p_glIndexubv) { p_glIndexubv(c); return; } if (a_glIndexubv) a_glIndexubv(c); }
INTERPOSE(glIndexubv)
void glInitNames(void) WEAKGL;
static void (*p_glInitNames)(void);
static void (*a_glInitNames)(void);
static void w_glInitNames(void) { if (mglshim_active && p_glInitNames) { p_glInitNames(); return; } if (a_glInitNames) a_glInitNames(); }
INTERPOSE(glInitNames)
void glInterleavedArrays(GLenum format, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glInterleavedArrays)(GLenum format, GLsizei stride, const void *pointer);
static void (*a_glInterleavedArrays)(GLenum format, GLsizei stride, const void *pointer);
static void w_glInterleavedArrays(GLenum format, GLsizei stride, const void *pointer) { if (mglshim_active && p_glInterleavedArrays) { p_glInterleavedArrays(format, stride, pointer); return; } if (a_glInterleavedArrays) a_glInterleavedArrays(format, stride, pointer); }
INTERPOSE(glInterleavedArrays)
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
GLboolean glIsList(GLuint list) WEAKGL;
static GLboolean (*p_glIsList)(GLuint list);
static GLboolean (*a_glIsList)(GLuint list);
static GLboolean w_glIsList(GLuint list) { if (mglshim_active && p_glIsList) return p_glIsList(list); if (a_glIsList) return a_glIsList(list); return (GLboolean)0; }
INTERPOSE(glIsList)
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
void glLightModelf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glLightModelf)(GLenum pname, GLfloat param);
static void (*a_glLightModelf)(GLenum pname, GLfloat param);
static void w_glLightModelf(GLenum pname, GLfloat param) { if (mglshim_active && p_glLightModelf) { p_glLightModelf(pname, param); return; } if (a_glLightModelf) a_glLightModelf(pname, param); }
INTERPOSE(glLightModelf)
void glLightModelfv(GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glLightModelfv)(GLenum pname, const GLfloat *params);
static void (*a_glLightModelfv)(GLenum pname, const GLfloat *params);
static void w_glLightModelfv(GLenum pname, const GLfloat *params) { if (mglshim_active && p_glLightModelfv) { p_glLightModelfv(pname, params); return; } if (a_glLightModelfv) a_glLightModelfv(pname, params); }
INTERPOSE(glLightModelfv)
void glLightModeli(GLenum pname, GLint param) WEAKGL;
static void (*p_glLightModeli)(GLenum pname, GLint param);
static void (*a_glLightModeli)(GLenum pname, GLint param);
static void w_glLightModeli(GLenum pname, GLint param) { if (mglshim_active && p_glLightModeli) { p_glLightModeli(pname, param); return; } if (a_glLightModeli) a_glLightModeli(pname, param); }
INTERPOSE(glLightModeli)
void glLightModeliv(GLenum pname, const GLint *params) WEAKGL;
static void (*p_glLightModeliv)(GLenum pname, const GLint *params);
static void (*a_glLightModeliv)(GLenum pname, const GLint *params);
static void w_glLightModeliv(GLenum pname, const GLint *params) { if (mglshim_active && p_glLightModeliv) { p_glLightModeliv(pname, params); return; } if (a_glLightModeliv) a_glLightModeliv(pname, params); }
INTERPOSE(glLightModeliv)
void glLightf(GLenum light, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glLightf)(GLenum light, GLenum pname, GLfloat param);
static void (*a_glLightf)(GLenum light, GLenum pname, GLfloat param);
static void w_glLightf(GLenum light, GLenum pname, GLfloat param) { if (mglshim_active && p_glLightf) { p_glLightf(light, pname, param); return; } if (a_glLightf) a_glLightf(light, pname, param); }
INTERPOSE(glLightf)
void glLightfv(GLenum light, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glLightfv)(GLenum light, GLenum pname, const GLfloat *params);
static void (*a_glLightfv)(GLenum light, GLenum pname, const GLfloat *params);
static void w_glLightfv(GLenum light, GLenum pname, const GLfloat *params) { if (mglshim_active && p_glLightfv) { p_glLightfv(light, pname, params); return; } if (a_glLightfv) a_glLightfv(light, pname, params); }
INTERPOSE(glLightfv)
void glLighti(GLenum light, GLenum pname, GLint param) WEAKGL;
static void (*p_glLighti)(GLenum light, GLenum pname, GLint param);
static void (*a_glLighti)(GLenum light, GLenum pname, GLint param);
static void w_glLighti(GLenum light, GLenum pname, GLint param) { if (mglshim_active && p_glLighti) { p_glLighti(light, pname, param); return; } if (a_glLighti) a_glLighti(light, pname, param); }
INTERPOSE(glLighti)
void glLightiv(GLenum light, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glLightiv)(GLenum light, GLenum pname, const GLint *params);
static void (*a_glLightiv)(GLenum light, GLenum pname, const GLint *params);
static void w_glLightiv(GLenum light, GLenum pname, const GLint *params) { if (mglshim_active && p_glLightiv) { p_glLightiv(light, pname, params); return; } if (a_glLightiv) a_glLightiv(light, pname, params); }
INTERPOSE(glLightiv)
void glLineStipple(GLint factor, GLushort pattern) WEAKGL;
static void (*p_glLineStipple)(GLint factor, GLushort pattern);
static void (*a_glLineStipple)(GLint factor, GLushort pattern);
static void w_glLineStipple(GLint factor, GLushort pattern) { if (mglshim_active && p_glLineStipple) { p_glLineStipple(factor, pattern); return; } if (a_glLineStipple) a_glLineStipple(factor, pattern); }
INTERPOSE(glLineStipple)
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
void glListBase(GLuint base) WEAKGL;
static void (*p_glListBase)(GLuint base);
static void (*a_glListBase)(GLuint base);
static void w_glListBase(GLuint base) { if (mglshim_active && p_glListBase) { p_glListBase(base); return; } if (a_glListBase) a_glListBase(base); }
INTERPOSE(glListBase)
void glLoadIdentity(void) WEAKGL;
static void (*p_glLoadIdentity)(void);
static void (*a_glLoadIdentity)(void);
static void w_glLoadIdentity(void) { if (mglshim_active && p_glLoadIdentity) { p_glLoadIdentity(); return; } if (a_glLoadIdentity) a_glLoadIdentity(); }
INTERPOSE(glLoadIdentity)
void glLoadMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glLoadMatrixd)(const GLdouble *m);
static void (*a_glLoadMatrixd)(const GLdouble *m);
static void w_glLoadMatrixd(const GLdouble *m) { if (mglshim_active && p_glLoadMatrixd) { p_glLoadMatrixd(m); return; } if (a_glLoadMatrixd) a_glLoadMatrixd(m); }
INTERPOSE(glLoadMatrixd)
void glLoadMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glLoadMatrixf)(const GLfloat *m);
static void (*a_glLoadMatrixf)(const GLfloat *m);
static void w_glLoadMatrixf(const GLfloat *m) { if (mglshim_active && p_glLoadMatrixf) { p_glLoadMatrixf(m); return; } if (a_glLoadMatrixf) a_glLoadMatrixf(m); }
INTERPOSE(glLoadMatrixf)
void glLoadName(GLuint name) WEAKGL;
static void (*p_glLoadName)(GLuint name);
static void (*a_glLoadName)(GLuint name);
static void w_glLoadName(GLuint name) { if (mglshim_active && p_glLoadName) { p_glLoadName(name); return; } if (a_glLoadName) a_glLoadName(name); }
INTERPOSE(glLoadName)
void glLoadTransposeMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glLoadTransposeMatrixd)(const GLdouble *m);
static void (*a_glLoadTransposeMatrixd)(const GLdouble *m);
static void w_glLoadTransposeMatrixd(const GLdouble *m) { if (mglshim_active && p_glLoadTransposeMatrixd) { p_glLoadTransposeMatrixd(m); return; } if (a_glLoadTransposeMatrixd) a_glLoadTransposeMatrixd(m); }
INTERPOSE(glLoadTransposeMatrixd)
void glLoadTransposeMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glLoadTransposeMatrixf)(const GLfloat *m);
static void (*a_glLoadTransposeMatrixf)(const GLfloat *m);
static void w_glLoadTransposeMatrixf(const GLfloat *m) { if (mglshim_active && p_glLoadTransposeMatrixf) { p_glLoadTransposeMatrixf(m); return; } if (a_glLoadTransposeMatrixf) a_glLoadTransposeMatrixf(m); }
INTERPOSE(glLoadTransposeMatrixf)
void glLogicOp(GLenum opcode) WEAKGL;
static void (*p_glLogicOp)(GLenum opcode);
static void (*a_glLogicOp)(GLenum opcode);
static void w_glLogicOp(GLenum opcode) { if (mglshim_active && p_glLogicOp) { p_glLogicOp(opcode); return; } if (a_glLogicOp) a_glLogicOp(opcode); }
INTERPOSE(glLogicOp)
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) WEAKGL;
static void (*p_glMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
static void (*a_glMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
static void w_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) { if (mglshim_active && p_glMap1d) { p_glMap1d(target, u1, u2, stride, order, points); return; } if (a_glMap1d) a_glMap1d(target, u1, u2, stride, order, points); }
INTERPOSE(glMap1d)
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) WEAKGL;
static void (*p_glMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
static void (*a_glMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
static void w_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) { if (mglshim_active && p_glMap1f) { p_glMap1f(target, u1, u2, stride, order, points); return; } if (a_glMap1f) a_glMap1f(target, u1, u2, stride, order, points); }
INTERPOSE(glMap1f)
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) WEAKGL;
static void (*p_glMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
static void (*a_glMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
static void w_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) { if (mglshim_active && p_glMap2d) { p_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); return; } if (a_glMap2d) a_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); }
INTERPOSE(glMap2d)
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) WEAKGL;
static void (*p_glMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
static void (*a_glMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
static void w_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) { if (mglshim_active && p_glMap2f) { p_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); return; } if (a_glMap2f) a_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); }
INTERPOSE(glMap2f)
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
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) WEAKGL;
static void (*p_glMapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
static void (*a_glMapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
static void w_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) { if (mglshim_active && p_glMapGrid1d) { p_glMapGrid1d(un, u1, u2); return; } if (a_glMapGrid1d) a_glMapGrid1d(un, u1, u2); }
INTERPOSE(glMapGrid1d)
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) WEAKGL;
static void (*p_glMapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
static void (*a_glMapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
static void w_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) { if (mglshim_active && p_glMapGrid1f) { p_glMapGrid1f(un, u1, u2); return; } if (a_glMapGrid1f) a_glMapGrid1f(un, u1, u2); }
INTERPOSE(glMapGrid1f)
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) WEAKGL;
static void (*p_glMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
static void (*a_glMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
static void w_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) { if (mglshim_active && p_glMapGrid2d) { p_glMapGrid2d(un, u1, u2, vn, v1, v2); return; } if (a_glMapGrid2d) a_glMapGrid2d(un, u1, u2, vn, v1, v2); }
INTERPOSE(glMapGrid2d)
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) WEAKGL;
static void (*p_glMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
static void (*a_glMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
static void w_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) { if (mglshim_active && p_glMapGrid2f) { p_glMapGrid2f(un, u1, u2, vn, v1, v2); return; } if (a_glMapGrid2f) a_glMapGrid2f(un, u1, u2, vn, v1, v2); }
INTERPOSE(glMapGrid2f)
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
void glMaterialf(GLenum face, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glMaterialf)(GLenum face, GLenum pname, GLfloat param);
static void (*a_glMaterialf)(GLenum face, GLenum pname, GLfloat param);
static void w_glMaterialf(GLenum face, GLenum pname, GLfloat param) { if (mglshim_active && p_glMaterialf) { p_glMaterialf(face, pname, param); return; } if (a_glMaterialf) a_glMaterialf(face, pname, param); }
INTERPOSE(glMaterialf)
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glMaterialfv)(GLenum face, GLenum pname, const GLfloat *params);
static void (*a_glMaterialfv)(GLenum face, GLenum pname, const GLfloat *params);
static void w_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) { if (mglshim_active && p_glMaterialfv) { p_glMaterialfv(face, pname, params); return; } if (a_glMaterialfv) a_glMaterialfv(face, pname, params); }
INTERPOSE(glMaterialfv)
void glMateriali(GLenum face, GLenum pname, GLint param) WEAKGL;
static void (*p_glMateriali)(GLenum face, GLenum pname, GLint param);
static void (*a_glMateriali)(GLenum face, GLenum pname, GLint param);
static void w_glMateriali(GLenum face, GLenum pname, GLint param) { if (mglshim_active && p_glMateriali) { p_glMateriali(face, pname, param); return; } if (a_glMateriali) a_glMateriali(face, pname, param); }
INTERPOSE(glMateriali)
void glMaterialiv(GLenum face, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glMaterialiv)(GLenum face, GLenum pname, const GLint *params);
static void (*a_glMaterialiv)(GLenum face, GLenum pname, const GLint *params);
static void w_glMaterialiv(GLenum face, GLenum pname, const GLint *params) { if (mglshim_active && p_glMaterialiv) { p_glMaterialiv(face, pname, params); return; } if (a_glMaterialiv) a_glMaterialiv(face, pname, params); }
INTERPOSE(glMaterialiv)
void glMatrixMode(GLenum mode) WEAKGL;
static void (*p_glMatrixMode)(GLenum mode);
static void (*a_glMatrixMode)(GLenum mode);
static void w_glMatrixMode(GLenum mode) { if (mglshim_active && p_glMatrixMode) { p_glMatrixMode(mode); return; } if (a_glMatrixMode) a_glMatrixMode(mode); }
INTERPOSE(glMatrixMode)
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
void glMultMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glMultMatrixd)(const GLdouble *m);
static void (*a_glMultMatrixd)(const GLdouble *m);
static void w_glMultMatrixd(const GLdouble *m) { if (mglshim_active && p_glMultMatrixd) { p_glMultMatrixd(m); return; } if (a_glMultMatrixd) a_glMultMatrixd(m); }
INTERPOSE(glMultMatrixd)
void glMultMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glMultMatrixf)(const GLfloat *m);
static void (*a_glMultMatrixf)(const GLfloat *m);
static void w_glMultMatrixf(const GLfloat *m) { if (mglshim_active && p_glMultMatrixf) { p_glMultMatrixf(m); return; } if (a_glMultMatrixf) a_glMultMatrixf(m); }
INTERPOSE(glMultMatrixf)
void glMultTransposeMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glMultTransposeMatrixd)(const GLdouble *m);
static void (*a_glMultTransposeMatrixd)(const GLdouble *m);
static void w_glMultTransposeMatrixd(const GLdouble *m) { if (mglshim_active && p_glMultTransposeMatrixd) { p_glMultTransposeMatrixd(m); return; } if (a_glMultTransposeMatrixd) a_glMultTransposeMatrixd(m); }
INTERPOSE(glMultTransposeMatrixd)
void glMultTransposeMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glMultTransposeMatrixf)(const GLfloat *m);
static void (*a_glMultTransposeMatrixf)(const GLfloat *m);
static void w_glMultTransposeMatrixf(const GLfloat *m) { if (mglshim_active && p_glMultTransposeMatrixf) { p_glMultTransposeMatrixf(m); return; } if (a_glMultTransposeMatrixf) a_glMultTransposeMatrixf(m); }
INTERPOSE(glMultTransposeMatrixf)
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
void glMultiTexCoord1d(GLenum target, GLdouble s) WEAKGL;
static void (*p_glMultiTexCoord1d)(GLenum target, GLdouble s);
static void (*a_glMultiTexCoord1d)(GLenum target, GLdouble s);
static void w_glMultiTexCoord1d(GLenum target, GLdouble s) { if (mglshim_active && p_glMultiTexCoord1d) { p_glMultiTexCoord1d(target, s); return; } if (a_glMultiTexCoord1d) a_glMultiTexCoord1d(target, s); }
INTERPOSE(glMultiTexCoord1d)
void glMultiTexCoord1dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord1dv)(GLenum target, const GLdouble *v);
static void (*a_glMultiTexCoord1dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord1dv(GLenum target, const GLdouble *v) { if (mglshim_active && p_glMultiTexCoord1dv) { p_glMultiTexCoord1dv(target, v); return; } if (a_glMultiTexCoord1dv) a_glMultiTexCoord1dv(target, v); }
INTERPOSE(glMultiTexCoord1dv)
void glMultiTexCoord1f(GLenum target, GLfloat s) WEAKGL;
static void (*p_glMultiTexCoord1f)(GLenum target, GLfloat s);
static void (*a_glMultiTexCoord1f)(GLenum target, GLfloat s);
static void w_glMultiTexCoord1f(GLenum target, GLfloat s) { if (mglshim_active && p_glMultiTexCoord1f) { p_glMultiTexCoord1f(target, s); return; } if (a_glMultiTexCoord1f) a_glMultiTexCoord1f(target, s); }
INTERPOSE(glMultiTexCoord1f)
void glMultiTexCoord1fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord1fv)(GLenum target, const GLfloat *v);
static void (*a_glMultiTexCoord1fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord1fv(GLenum target, const GLfloat *v) { if (mglshim_active && p_glMultiTexCoord1fv) { p_glMultiTexCoord1fv(target, v); return; } if (a_glMultiTexCoord1fv) a_glMultiTexCoord1fv(target, v); }
INTERPOSE(glMultiTexCoord1fv)
void glMultiTexCoord1i(GLenum target, GLint s) WEAKGL;
static void (*p_glMultiTexCoord1i)(GLenum target, GLint s);
static void (*a_glMultiTexCoord1i)(GLenum target, GLint s);
static void w_glMultiTexCoord1i(GLenum target, GLint s) { if (mglshim_active && p_glMultiTexCoord1i) { p_glMultiTexCoord1i(target, s); return; } if (a_glMultiTexCoord1i) a_glMultiTexCoord1i(target, s); }
INTERPOSE(glMultiTexCoord1i)
void glMultiTexCoord1iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord1iv)(GLenum target, const GLint *v);
static void (*a_glMultiTexCoord1iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord1iv(GLenum target, const GLint *v) { if (mglshim_active && p_glMultiTexCoord1iv) { p_glMultiTexCoord1iv(target, v); return; } if (a_glMultiTexCoord1iv) a_glMultiTexCoord1iv(target, v); }
INTERPOSE(glMultiTexCoord1iv)
void glMultiTexCoord1s(GLenum target, GLshort s) WEAKGL;
static void (*p_glMultiTexCoord1s)(GLenum target, GLshort s);
static void (*a_glMultiTexCoord1s)(GLenum target, GLshort s);
static void w_glMultiTexCoord1s(GLenum target, GLshort s) { if (mglshim_active && p_glMultiTexCoord1s) { p_glMultiTexCoord1s(target, s); return; } if (a_glMultiTexCoord1s) a_glMultiTexCoord1s(target, s); }
INTERPOSE(glMultiTexCoord1s)
void glMultiTexCoord1sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord1sv)(GLenum target, const GLshort *v);
static void (*a_glMultiTexCoord1sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord1sv(GLenum target, const GLshort *v) { if (mglshim_active && p_glMultiTexCoord1sv) { p_glMultiTexCoord1sv(target, v); return; } if (a_glMultiTexCoord1sv) a_glMultiTexCoord1sv(target, v); }
INTERPOSE(glMultiTexCoord1sv)
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) WEAKGL;
static void (*p_glMultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t);
static void (*a_glMultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t);
static void w_glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) { if (mglshim_active && p_glMultiTexCoord2d) { p_glMultiTexCoord2d(target, s, t); return; } if (a_glMultiTexCoord2d) a_glMultiTexCoord2d(target, s, t); }
INTERPOSE(glMultiTexCoord2d)
void glMultiTexCoord2dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord2dv)(GLenum target, const GLdouble *v);
static void (*a_glMultiTexCoord2dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord2dv(GLenum target, const GLdouble *v) { if (mglshim_active && p_glMultiTexCoord2dv) { p_glMultiTexCoord2dv(target, v); return; } if (a_glMultiTexCoord2dv) a_glMultiTexCoord2dv(target, v); }
INTERPOSE(glMultiTexCoord2dv)
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) WEAKGL;
static void (*p_glMultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t);
static void (*a_glMultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t);
static void w_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) { if (mglshim_active && p_glMultiTexCoord2f) { p_glMultiTexCoord2f(target, s, t); return; } if (a_glMultiTexCoord2f) a_glMultiTexCoord2f(target, s, t); }
INTERPOSE(glMultiTexCoord2f)
void glMultiTexCoord2fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord2fv)(GLenum target, const GLfloat *v);
static void (*a_glMultiTexCoord2fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord2fv(GLenum target, const GLfloat *v) { if (mglshim_active && p_glMultiTexCoord2fv) { p_glMultiTexCoord2fv(target, v); return; } if (a_glMultiTexCoord2fv) a_glMultiTexCoord2fv(target, v); }
INTERPOSE(glMultiTexCoord2fv)
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) WEAKGL;
static void (*p_glMultiTexCoord2i)(GLenum target, GLint s, GLint t);
static void (*a_glMultiTexCoord2i)(GLenum target, GLint s, GLint t);
static void w_glMultiTexCoord2i(GLenum target, GLint s, GLint t) { if (mglshim_active && p_glMultiTexCoord2i) { p_glMultiTexCoord2i(target, s, t); return; } if (a_glMultiTexCoord2i) a_glMultiTexCoord2i(target, s, t); }
INTERPOSE(glMultiTexCoord2i)
void glMultiTexCoord2iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord2iv)(GLenum target, const GLint *v);
static void (*a_glMultiTexCoord2iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord2iv(GLenum target, const GLint *v) { if (mglshim_active && p_glMultiTexCoord2iv) { p_glMultiTexCoord2iv(target, v); return; } if (a_glMultiTexCoord2iv) a_glMultiTexCoord2iv(target, v); }
INTERPOSE(glMultiTexCoord2iv)
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) WEAKGL;
static void (*p_glMultiTexCoord2s)(GLenum target, GLshort s, GLshort t);
static void (*a_glMultiTexCoord2s)(GLenum target, GLshort s, GLshort t);
static void w_glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) { if (mglshim_active && p_glMultiTexCoord2s) { p_glMultiTexCoord2s(target, s, t); return; } if (a_glMultiTexCoord2s) a_glMultiTexCoord2s(target, s, t); }
INTERPOSE(glMultiTexCoord2s)
void glMultiTexCoord2sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord2sv)(GLenum target, const GLshort *v);
static void (*a_glMultiTexCoord2sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord2sv(GLenum target, const GLshort *v) { if (mglshim_active && p_glMultiTexCoord2sv) { p_glMultiTexCoord2sv(target, v); return; } if (a_glMultiTexCoord2sv) a_glMultiTexCoord2sv(target, v); }
INTERPOSE(glMultiTexCoord2sv)
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) WEAKGL;
static void (*p_glMultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
static void (*a_glMultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
static void w_glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) { if (mglshim_active && p_glMultiTexCoord3d) { p_glMultiTexCoord3d(target, s, t, r); return; } if (a_glMultiTexCoord3d) a_glMultiTexCoord3d(target, s, t, r); }
INTERPOSE(glMultiTexCoord3d)
void glMultiTexCoord3dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord3dv)(GLenum target, const GLdouble *v);
static void (*a_glMultiTexCoord3dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord3dv(GLenum target, const GLdouble *v) { if (mglshim_active && p_glMultiTexCoord3dv) { p_glMultiTexCoord3dv(target, v); return; } if (a_glMultiTexCoord3dv) a_glMultiTexCoord3dv(target, v); }
INTERPOSE(glMultiTexCoord3dv)
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) WEAKGL;
static void (*p_glMultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
static void (*a_glMultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
static void w_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) { if (mglshim_active && p_glMultiTexCoord3f) { p_glMultiTexCoord3f(target, s, t, r); return; } if (a_glMultiTexCoord3f) a_glMultiTexCoord3f(target, s, t, r); }
INTERPOSE(glMultiTexCoord3f)
void glMultiTexCoord3fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord3fv)(GLenum target, const GLfloat *v);
static void (*a_glMultiTexCoord3fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord3fv(GLenum target, const GLfloat *v) { if (mglshim_active && p_glMultiTexCoord3fv) { p_glMultiTexCoord3fv(target, v); return; } if (a_glMultiTexCoord3fv) a_glMultiTexCoord3fv(target, v); }
INTERPOSE(glMultiTexCoord3fv)
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) WEAKGL;
static void (*p_glMultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r);
static void (*a_glMultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r);
static void w_glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) { if (mglshim_active && p_glMultiTexCoord3i) { p_glMultiTexCoord3i(target, s, t, r); return; } if (a_glMultiTexCoord3i) a_glMultiTexCoord3i(target, s, t, r); }
INTERPOSE(glMultiTexCoord3i)
void glMultiTexCoord3iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord3iv)(GLenum target, const GLint *v);
static void (*a_glMultiTexCoord3iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord3iv(GLenum target, const GLint *v) { if (mglshim_active && p_glMultiTexCoord3iv) { p_glMultiTexCoord3iv(target, v); return; } if (a_glMultiTexCoord3iv) a_glMultiTexCoord3iv(target, v); }
INTERPOSE(glMultiTexCoord3iv)
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) WEAKGL;
static void (*p_glMultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r);
static void (*a_glMultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r);
static void w_glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) { if (mglshim_active && p_glMultiTexCoord3s) { p_glMultiTexCoord3s(target, s, t, r); return; } if (a_glMultiTexCoord3s) a_glMultiTexCoord3s(target, s, t, r); }
INTERPOSE(glMultiTexCoord3s)
void glMultiTexCoord3sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord3sv)(GLenum target, const GLshort *v);
static void (*a_glMultiTexCoord3sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord3sv(GLenum target, const GLshort *v) { if (mglshim_active && p_glMultiTexCoord3sv) { p_glMultiTexCoord3sv(target, v); return; } if (a_glMultiTexCoord3sv) a_glMultiTexCoord3sv(target, v); }
INTERPOSE(glMultiTexCoord3sv)
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) WEAKGL;
static void (*p_glMultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void (*a_glMultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void w_glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) { if (mglshim_active && p_glMultiTexCoord4d) { p_glMultiTexCoord4d(target, s, t, r, q); return; } if (a_glMultiTexCoord4d) a_glMultiTexCoord4d(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4d)
void glMultiTexCoord4dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord4dv)(GLenum target, const GLdouble *v);
static void (*a_glMultiTexCoord4dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord4dv(GLenum target, const GLdouble *v) { if (mglshim_active && p_glMultiTexCoord4dv) { p_glMultiTexCoord4dv(target, v); return; } if (a_glMultiTexCoord4dv) a_glMultiTexCoord4dv(target, v); }
INTERPOSE(glMultiTexCoord4dv)
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) WEAKGL;
static void (*p_glMultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void (*a_glMultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void w_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) { if (mglshim_active && p_glMultiTexCoord4f) { p_glMultiTexCoord4f(target, s, t, r, q); return; } if (a_glMultiTexCoord4f) a_glMultiTexCoord4f(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4f)
void glMultiTexCoord4fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord4fv)(GLenum target, const GLfloat *v);
static void (*a_glMultiTexCoord4fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord4fv(GLenum target, const GLfloat *v) { if (mglshim_active && p_glMultiTexCoord4fv) { p_glMultiTexCoord4fv(target, v); return; } if (a_glMultiTexCoord4fv) a_glMultiTexCoord4fv(target, v); }
INTERPOSE(glMultiTexCoord4fv)
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) WEAKGL;
static void (*p_glMultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q);
static void (*a_glMultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q);
static void w_glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) { if (mglshim_active && p_glMultiTexCoord4i) { p_glMultiTexCoord4i(target, s, t, r, q); return; } if (a_glMultiTexCoord4i) a_glMultiTexCoord4i(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4i)
void glMultiTexCoord4iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord4iv)(GLenum target, const GLint *v);
static void (*a_glMultiTexCoord4iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord4iv(GLenum target, const GLint *v) { if (mglshim_active && p_glMultiTexCoord4iv) { p_glMultiTexCoord4iv(target, v); return; } if (a_glMultiTexCoord4iv) a_glMultiTexCoord4iv(target, v); }
INTERPOSE(glMultiTexCoord4iv)
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) WEAKGL;
static void (*p_glMultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
static void (*a_glMultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
static void w_glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) { if (mglshim_active && p_glMultiTexCoord4s) { p_glMultiTexCoord4s(target, s, t, r, q); return; } if (a_glMultiTexCoord4s) a_glMultiTexCoord4s(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4s)
void glMultiTexCoord4sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord4sv)(GLenum target, const GLshort *v);
static void (*a_glMultiTexCoord4sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord4sv(GLenum target, const GLshort *v) { if (mglshim_active && p_glMultiTexCoord4sv) { p_glMultiTexCoord4sv(target, v); return; } if (a_glMultiTexCoord4sv) a_glMultiTexCoord4sv(target, v); }
INTERPOSE(glMultiTexCoord4sv)
void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords);
static void (*a_glMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) { if (mglshim_active && p_glMultiTexCoordP1ui) { p_glMultiTexCoordP1ui(texture, type, coords); return; } if (a_glMultiTexCoordP1ui) a_glMultiTexCoordP1ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP1ui)
void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void (*a_glMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords) { if (mglshim_active && p_glMultiTexCoordP1uiv) { p_glMultiTexCoordP1uiv(texture, type, coords); return; } if (a_glMultiTexCoordP1uiv) a_glMultiTexCoordP1uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP1uiv)
void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords);
static void (*a_glMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) { if (mglshim_active && p_glMultiTexCoordP2ui) { p_glMultiTexCoordP2ui(texture, type, coords); return; } if (a_glMultiTexCoordP2ui) a_glMultiTexCoordP2ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP2ui)
void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void (*a_glMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords) { if (mglshim_active && p_glMultiTexCoordP2uiv) { p_glMultiTexCoordP2uiv(texture, type, coords); return; } if (a_glMultiTexCoordP2uiv) a_glMultiTexCoordP2uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP2uiv)
void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords);
static void (*a_glMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) { if (mglshim_active && p_glMultiTexCoordP3ui) { p_glMultiTexCoordP3ui(texture, type, coords); return; } if (a_glMultiTexCoordP3ui) a_glMultiTexCoordP3ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP3ui)
void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void (*a_glMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords) { if (mglshim_active && p_glMultiTexCoordP3uiv) { p_glMultiTexCoordP3uiv(texture, type, coords); return; } if (a_glMultiTexCoordP3uiv) a_glMultiTexCoordP3uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP3uiv)
void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords);
static void (*a_glMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) { if (mglshim_active && p_glMultiTexCoordP4ui) { p_glMultiTexCoordP4ui(texture, type, coords); return; } if (a_glMultiTexCoordP4ui) a_glMultiTexCoordP4ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP4ui)
void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void (*a_glMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords) { if (mglshim_active && p_glMultiTexCoordP4uiv) { p_glMultiTexCoordP4uiv(texture, type, coords); return; } if (a_glMultiTexCoordP4uiv) a_glMultiTexCoordP4uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP4uiv)
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
void glNewList(GLuint list, GLenum mode) WEAKGL;
static void (*p_glNewList)(GLuint list, GLenum mode);
static void (*a_glNewList)(GLuint list, GLenum mode);
static void w_glNewList(GLuint list, GLenum mode) { if (mglshim_active && p_glNewList) { p_glNewList(list, mode); return; } if (a_glNewList) a_glNewList(list, mode); }
INTERPOSE(glNewList)
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) WEAKGL;
static void (*p_glNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
static void (*a_glNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
static void w_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) { if (mglshim_active && p_glNormal3b) { p_glNormal3b(nx, ny, nz); return; } if (a_glNormal3b) a_glNormal3b(nx, ny, nz); }
INTERPOSE(glNormal3b)
void glNormal3bv(const GLbyte *v) WEAKGL;
static void (*p_glNormal3bv)(const GLbyte *v);
static void (*a_glNormal3bv)(const GLbyte *v);
static void w_glNormal3bv(const GLbyte *v) { if (mglshim_active && p_glNormal3bv) { p_glNormal3bv(v); return; } if (a_glNormal3bv) a_glNormal3bv(v); }
INTERPOSE(glNormal3bv)
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) WEAKGL;
static void (*p_glNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
static void (*a_glNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
static void w_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) { if (mglshim_active && p_glNormal3d) { p_glNormal3d(nx, ny, nz); return; } if (a_glNormal3d) a_glNormal3d(nx, ny, nz); }
INTERPOSE(glNormal3d)
void glNormal3dv(const GLdouble *v) WEAKGL;
static void (*p_glNormal3dv)(const GLdouble *v);
static void (*a_glNormal3dv)(const GLdouble *v);
static void w_glNormal3dv(const GLdouble *v) { if (mglshim_active && p_glNormal3dv) { p_glNormal3dv(v); return; } if (a_glNormal3dv) a_glNormal3dv(v); }
INTERPOSE(glNormal3dv)
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) WEAKGL;
static void (*p_glNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
static void (*a_glNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
static void w_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) { if (mglshim_active && p_glNormal3f) { p_glNormal3f(nx, ny, nz); return; } if (a_glNormal3f) a_glNormal3f(nx, ny, nz); }
INTERPOSE(glNormal3f)
void glNormal3fv(const GLfloat *v) WEAKGL;
static void (*p_glNormal3fv)(const GLfloat *v);
static void (*a_glNormal3fv)(const GLfloat *v);
static void w_glNormal3fv(const GLfloat *v) { if (mglshim_active && p_glNormal3fv) { p_glNormal3fv(v); return; } if (a_glNormal3fv) a_glNormal3fv(v); }
INTERPOSE(glNormal3fv)
void glNormal3i(GLint nx, GLint ny, GLint nz) WEAKGL;
static void (*p_glNormal3i)(GLint nx, GLint ny, GLint nz);
static void (*a_glNormal3i)(GLint nx, GLint ny, GLint nz);
static void w_glNormal3i(GLint nx, GLint ny, GLint nz) { if (mglshim_active && p_glNormal3i) { p_glNormal3i(nx, ny, nz); return; } if (a_glNormal3i) a_glNormal3i(nx, ny, nz); }
INTERPOSE(glNormal3i)
void glNormal3iv(const GLint *v) WEAKGL;
static void (*p_glNormal3iv)(const GLint *v);
static void (*a_glNormal3iv)(const GLint *v);
static void w_glNormal3iv(const GLint *v) { if (mglshim_active && p_glNormal3iv) { p_glNormal3iv(v); return; } if (a_glNormal3iv) a_glNormal3iv(v); }
INTERPOSE(glNormal3iv)
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) WEAKGL;
static void (*p_glNormal3s)(GLshort nx, GLshort ny, GLshort nz);
static void (*a_glNormal3s)(GLshort nx, GLshort ny, GLshort nz);
static void w_glNormal3s(GLshort nx, GLshort ny, GLshort nz) { if (mglshim_active && p_glNormal3s) { p_glNormal3s(nx, ny, nz); return; } if (a_glNormal3s) a_glNormal3s(nx, ny, nz); }
INTERPOSE(glNormal3s)
void glNormal3sv(const GLshort *v) WEAKGL;
static void (*p_glNormal3sv)(const GLshort *v);
static void (*a_glNormal3sv)(const GLshort *v);
static void w_glNormal3sv(const GLshort *v) { if (mglshim_active && p_glNormal3sv) { p_glNormal3sv(v); return; } if (a_glNormal3sv) a_glNormal3sv(v); }
INTERPOSE(glNormal3sv)
void glNormalP3ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glNormalP3ui)(GLenum type, GLuint coords);
static void (*a_glNormalP3ui)(GLenum type, GLuint coords);
static void w_glNormalP3ui(GLenum type, GLuint coords) { if (mglshim_active && p_glNormalP3ui) { p_glNormalP3ui(type, coords); return; } if (a_glNormalP3ui) a_glNormalP3ui(type, coords); }
INTERPOSE(glNormalP3ui)
void glNormalP3uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glNormalP3uiv)(GLenum type, const GLuint *coords);
static void (*a_glNormalP3uiv)(GLenum type, const GLuint *coords);
static void w_glNormalP3uiv(GLenum type, const GLuint *coords) { if (mglshim_active && p_glNormalP3uiv) { p_glNormalP3uiv(type, coords); return; } if (a_glNormalP3uiv) a_glNormalP3uiv(type, coords); }
INTERPOSE(glNormalP3uiv)
void glNormalPointer(GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glNormalPointer)(GLenum type, GLsizei stride, const void *pointer);
static void (*a_glNormalPointer)(GLenum type, GLsizei stride, const void *pointer);
static void w_glNormalPointer(GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glNormalPointer) { p_glNormalPointer(type, stride, pointer); return; } if (a_glNormalPointer) a_glNormalPointer(type, stride, pointer); }
INTERPOSE(glNormalPointer)
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
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) WEAKGL;
static void (*p_glOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void (*a_glOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void w_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) { if (mglshim_active && p_glOrtho) { p_glOrtho(left, right, bottom, top, zNear, zFar); return; } if (a_glOrtho) a_glOrtho(left, right, bottom, top, zNear, zFar); }
INTERPOSE(glOrtho)
void glPassThrough(GLfloat token) WEAKGL;
static void (*p_glPassThrough)(GLfloat token);
static void (*a_glPassThrough)(GLfloat token);
static void w_glPassThrough(GLfloat token) { if (mglshim_active && p_glPassThrough) { p_glPassThrough(token); return; } if (a_glPassThrough) a_glPassThrough(token); }
INTERPOSE(glPassThrough)
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
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) WEAKGL;
static void (*p_glPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values);
static void (*a_glPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values);
static void w_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) { if (mglshim_active && p_glPixelMapfv) { p_glPixelMapfv(map, mapsize, values); return; } if (a_glPixelMapfv) a_glPixelMapfv(map, mapsize, values); }
INTERPOSE(glPixelMapfv)
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) WEAKGL;
static void (*p_glPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values);
static void (*a_glPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values);
static void w_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) { if (mglshim_active && p_glPixelMapuiv) { p_glPixelMapuiv(map, mapsize, values); return; } if (a_glPixelMapuiv) a_glPixelMapuiv(map, mapsize, values); }
INTERPOSE(glPixelMapuiv)
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) WEAKGL;
static void (*p_glPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values);
static void (*a_glPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values);
static void w_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) { if (mglshim_active && p_glPixelMapusv) { p_glPixelMapusv(map, mapsize, values); return; } if (a_glPixelMapusv) a_glPixelMapusv(map, mapsize, values); }
INTERPOSE(glPixelMapusv)
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
void glPixelTransferf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glPixelTransferf)(GLenum pname, GLfloat param);
static void (*a_glPixelTransferf)(GLenum pname, GLfloat param);
static void w_glPixelTransferf(GLenum pname, GLfloat param) { if (mglshim_active && p_glPixelTransferf) { p_glPixelTransferf(pname, param); return; } if (a_glPixelTransferf) a_glPixelTransferf(pname, param); }
INTERPOSE(glPixelTransferf)
void glPixelTransferi(GLenum pname, GLint param) WEAKGL;
static void (*p_glPixelTransferi)(GLenum pname, GLint param);
static void (*a_glPixelTransferi)(GLenum pname, GLint param);
static void w_glPixelTransferi(GLenum pname, GLint param) { if (mglshim_active && p_glPixelTransferi) { p_glPixelTransferi(pname, param); return; } if (a_glPixelTransferi) a_glPixelTransferi(pname, param); }
INTERPOSE(glPixelTransferi)
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) WEAKGL;
static void (*p_glPixelZoom)(GLfloat xfactor, GLfloat yfactor);
static void (*a_glPixelZoom)(GLfloat xfactor, GLfloat yfactor);
static void w_glPixelZoom(GLfloat xfactor, GLfloat yfactor) { if (mglshim_active && p_glPixelZoom) { p_glPixelZoom(xfactor, yfactor); return; } if (a_glPixelZoom) a_glPixelZoom(xfactor, yfactor); }
INTERPOSE(glPixelZoom)
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
void glPolygonStipple(const GLubyte *mask) WEAKGL;
static void (*p_glPolygonStipple)(const GLubyte *mask);
static void (*a_glPolygonStipple)(const GLubyte *mask);
static void w_glPolygonStipple(const GLubyte *mask) { if (mglshim_active && p_glPolygonStipple) { p_glPolygonStipple(mask); return; } if (a_glPolygonStipple) a_glPolygonStipple(mask); }
INTERPOSE(glPolygonStipple)
void glPopAttrib(void) WEAKGL;
static void (*p_glPopAttrib)(void);
static void (*a_glPopAttrib)(void);
static void w_glPopAttrib(void) { if (mglshim_active && p_glPopAttrib) { p_glPopAttrib(); return; } if (a_glPopAttrib) a_glPopAttrib(); }
INTERPOSE(glPopAttrib)
void glPopClientAttrib(void) WEAKGL;
static void (*p_glPopClientAttrib)(void);
static void (*a_glPopClientAttrib)(void);
static void w_glPopClientAttrib(void) { if (mglshim_active && p_glPopClientAttrib) { p_glPopClientAttrib(); return; } if (a_glPopClientAttrib) a_glPopClientAttrib(); }
INTERPOSE(glPopClientAttrib)
void glPopDebugGroup(void) WEAKGL;
static void (*p_glPopDebugGroup)(void);
static void (*a_glPopDebugGroup)(void);
static void w_glPopDebugGroup(void) { if (mglshim_active && p_glPopDebugGroup) { p_glPopDebugGroup(); return; } if (a_glPopDebugGroup) a_glPopDebugGroup(); }
INTERPOSE(glPopDebugGroup)
void glPopMatrix(void) WEAKGL;
static void (*p_glPopMatrix)(void);
static void (*a_glPopMatrix)(void);
static void w_glPopMatrix(void) { if (mglshim_active && p_glPopMatrix) { p_glPopMatrix(); return; } if (a_glPopMatrix) a_glPopMatrix(); }
INTERPOSE(glPopMatrix)
void glPopName(void) WEAKGL;
static void (*p_glPopName)(void);
static void (*a_glPopName)(void);
static void w_glPopName(void) { if (mglshim_active && p_glPopName) { p_glPopName(); return; } if (a_glPopName) a_glPopName(); }
INTERPOSE(glPopName)
void glPrimitiveRestartIndex(GLuint index) WEAKGL;
static void (*p_glPrimitiveRestartIndex)(GLuint index);
static void (*a_glPrimitiveRestartIndex)(GLuint index);
static void w_glPrimitiveRestartIndex(GLuint index) { if (mglshim_active && p_glPrimitiveRestartIndex) { p_glPrimitiveRestartIndex(index); return; } if (a_glPrimitiveRestartIndex) a_glPrimitiveRestartIndex(index); }
INTERPOSE(glPrimitiveRestartIndex)
void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLfloat *priorities) WEAKGL;
static void (*p_glPrioritizeTextures)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
static void (*a_glPrioritizeTextures)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
static void w_glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLfloat *priorities) { if (mglshim_active && p_glPrioritizeTextures) { p_glPrioritizeTextures(n, textures, priorities); return; } if (a_glPrioritizeTextures) a_glPrioritizeTextures(n, textures, priorities); }
INTERPOSE(glPrioritizeTextures)
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
void glPushAttrib(GLbitfield mask) WEAKGL;
static void (*p_glPushAttrib)(GLbitfield mask);
static void (*a_glPushAttrib)(GLbitfield mask);
static void w_glPushAttrib(GLbitfield mask) { if (mglshim_active && p_glPushAttrib) { p_glPushAttrib(mask); return; } if (a_glPushAttrib) a_glPushAttrib(mask); }
INTERPOSE(glPushAttrib)
void glPushClientAttrib(GLbitfield mask) WEAKGL;
static void (*p_glPushClientAttrib)(GLbitfield mask);
static void (*a_glPushClientAttrib)(GLbitfield mask);
static void w_glPushClientAttrib(GLbitfield mask) { if (mglshim_active && p_glPushClientAttrib) { p_glPushClientAttrib(mask); return; } if (a_glPushClientAttrib) a_glPushClientAttrib(mask); }
INTERPOSE(glPushClientAttrib)
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) WEAKGL;
static void (*p_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
static void (*a_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
static void w_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) { if (mglshim_active && p_glPushDebugGroup) { p_glPushDebugGroup(source, id, length, message); return; } if (a_glPushDebugGroup) a_glPushDebugGroup(source, id, length, message); }
INTERPOSE(glPushDebugGroup)
void glPushMatrix(void) WEAKGL;
static void (*p_glPushMatrix)(void);
static void (*a_glPushMatrix)(void);
static void w_glPushMatrix(void) { if (mglshim_active && p_glPushMatrix) { p_glPushMatrix(); return; } if (a_glPushMatrix) a_glPushMatrix(); }
INTERPOSE(glPushMatrix)
void glPushName(GLuint name) WEAKGL;
static void (*p_glPushName)(GLuint name);
static void (*a_glPushName)(GLuint name);
static void w_glPushName(GLuint name) { if (mglshim_active && p_glPushName) { p_glPushName(name); return; } if (a_glPushName) a_glPushName(name); }
INTERPOSE(glPushName)
void glQueryCounter(GLuint id, GLenum target) WEAKGL;
static void (*p_glQueryCounter)(GLuint id, GLenum target);
static void (*a_glQueryCounter)(GLuint id, GLenum target);
static void w_glQueryCounter(GLuint id, GLenum target) { if (mglshim_active && p_glQueryCounter) { p_glQueryCounter(id, target); return; } if (a_glQueryCounter) a_glQueryCounter(id, target); }
INTERPOSE(glQueryCounter)
void glRasterPos2d(GLdouble x, GLdouble y) WEAKGL;
static void (*p_glRasterPos2d)(GLdouble x, GLdouble y);
static void (*a_glRasterPos2d)(GLdouble x, GLdouble y);
static void w_glRasterPos2d(GLdouble x, GLdouble y) { if (mglshim_active && p_glRasterPos2d) { p_glRasterPos2d(x, y); return; } if (a_glRasterPos2d) a_glRasterPos2d(x, y); }
INTERPOSE(glRasterPos2d)
void glRasterPos2dv(const GLdouble *v) WEAKGL;
static void (*p_glRasterPos2dv)(const GLdouble *v);
static void (*a_glRasterPos2dv)(const GLdouble *v);
static void w_glRasterPos2dv(const GLdouble *v) { if (mglshim_active && p_glRasterPos2dv) { p_glRasterPos2dv(v); return; } if (a_glRasterPos2dv) a_glRasterPos2dv(v); }
INTERPOSE(glRasterPos2dv)
void glRasterPos2f(GLfloat x, GLfloat y) WEAKGL;
static void (*p_glRasterPos2f)(GLfloat x, GLfloat y);
static void (*a_glRasterPos2f)(GLfloat x, GLfloat y);
static void w_glRasterPos2f(GLfloat x, GLfloat y) { if (mglshim_active && p_glRasterPos2f) { p_glRasterPos2f(x, y); return; } if (a_glRasterPos2f) a_glRasterPos2f(x, y); }
INTERPOSE(glRasterPos2f)
void glRasterPos2fv(const GLfloat *v) WEAKGL;
static void (*p_glRasterPos2fv)(const GLfloat *v);
static void (*a_glRasterPos2fv)(const GLfloat *v);
static void w_glRasterPos2fv(const GLfloat *v) { if (mglshim_active && p_glRasterPos2fv) { p_glRasterPos2fv(v); return; } if (a_glRasterPos2fv) a_glRasterPos2fv(v); }
INTERPOSE(glRasterPos2fv)
void glRasterPos2i(GLint x, GLint y) WEAKGL;
static void (*p_glRasterPos2i)(GLint x, GLint y);
static void (*a_glRasterPos2i)(GLint x, GLint y);
static void w_glRasterPos2i(GLint x, GLint y) { if (mglshim_active && p_glRasterPos2i) { p_glRasterPos2i(x, y); return; } if (a_glRasterPos2i) a_glRasterPos2i(x, y); }
INTERPOSE(glRasterPos2i)
void glRasterPos2iv(const GLint *v) WEAKGL;
static void (*p_glRasterPos2iv)(const GLint *v);
static void (*a_glRasterPos2iv)(const GLint *v);
static void w_glRasterPos2iv(const GLint *v) { if (mglshim_active && p_glRasterPos2iv) { p_glRasterPos2iv(v); return; } if (a_glRasterPos2iv) a_glRasterPos2iv(v); }
INTERPOSE(glRasterPos2iv)
void glRasterPos2s(GLshort x, GLshort y) WEAKGL;
static void (*p_glRasterPos2s)(GLshort x, GLshort y);
static void (*a_glRasterPos2s)(GLshort x, GLshort y);
static void w_glRasterPos2s(GLshort x, GLshort y) { if (mglshim_active && p_glRasterPos2s) { p_glRasterPos2s(x, y); return; } if (a_glRasterPos2s) a_glRasterPos2s(x, y); }
INTERPOSE(glRasterPos2s)
void glRasterPos2sv(const GLshort *v) WEAKGL;
static void (*p_glRasterPos2sv)(const GLshort *v);
static void (*a_glRasterPos2sv)(const GLshort *v);
static void w_glRasterPos2sv(const GLshort *v) { if (mglshim_active && p_glRasterPos2sv) { p_glRasterPos2sv(v); return; } if (a_glRasterPos2sv) a_glRasterPos2sv(v); }
INTERPOSE(glRasterPos2sv)
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glRasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
static void (*a_glRasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
static void w_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glRasterPos3d) { p_glRasterPos3d(x, y, z); return; } if (a_glRasterPos3d) a_glRasterPos3d(x, y, z); }
INTERPOSE(glRasterPos3d)
void glRasterPos3dv(const GLdouble *v) WEAKGL;
static void (*p_glRasterPos3dv)(const GLdouble *v);
static void (*a_glRasterPos3dv)(const GLdouble *v);
static void w_glRasterPos3dv(const GLdouble *v) { if (mglshim_active && p_glRasterPos3dv) { p_glRasterPos3dv(v); return; } if (a_glRasterPos3dv) a_glRasterPos3dv(v); }
INTERPOSE(glRasterPos3dv)
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glRasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
static void (*a_glRasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
static void w_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glRasterPos3f) { p_glRasterPos3f(x, y, z); return; } if (a_glRasterPos3f) a_glRasterPos3f(x, y, z); }
INTERPOSE(glRasterPos3f)
void glRasterPos3fv(const GLfloat *v) WEAKGL;
static void (*p_glRasterPos3fv)(const GLfloat *v);
static void (*a_glRasterPos3fv)(const GLfloat *v);
static void w_glRasterPos3fv(const GLfloat *v) { if (mglshim_active && p_glRasterPos3fv) { p_glRasterPos3fv(v); return; } if (a_glRasterPos3fv) a_glRasterPos3fv(v); }
INTERPOSE(glRasterPos3fv)
void glRasterPos3i(GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glRasterPos3i)(GLint x, GLint y, GLint z);
static void (*a_glRasterPos3i)(GLint x, GLint y, GLint z);
static void w_glRasterPos3i(GLint x, GLint y, GLint z) { if (mglshim_active && p_glRasterPos3i) { p_glRasterPos3i(x, y, z); return; } if (a_glRasterPos3i) a_glRasterPos3i(x, y, z); }
INTERPOSE(glRasterPos3i)
void glRasterPos3iv(const GLint *v) WEAKGL;
static void (*p_glRasterPos3iv)(const GLint *v);
static void (*a_glRasterPos3iv)(const GLint *v);
static void w_glRasterPos3iv(const GLint *v) { if (mglshim_active && p_glRasterPos3iv) { p_glRasterPos3iv(v); return; } if (a_glRasterPos3iv) a_glRasterPos3iv(v); }
INTERPOSE(glRasterPos3iv)
void glRasterPos3s(GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glRasterPos3s)(GLshort x, GLshort y, GLshort z);
static void (*a_glRasterPos3s)(GLshort x, GLshort y, GLshort z);
static void w_glRasterPos3s(GLshort x, GLshort y, GLshort z) { if (mglshim_active && p_glRasterPos3s) { p_glRasterPos3s(x, y, z); return; } if (a_glRasterPos3s) a_glRasterPos3s(x, y, z); }
INTERPOSE(glRasterPos3s)
void glRasterPos3sv(const GLshort *v) WEAKGL;
static void (*p_glRasterPos3sv)(const GLshort *v);
static void (*a_glRasterPos3sv)(const GLshort *v);
static void w_glRasterPos3sv(const GLshort *v) { if (mglshim_active && p_glRasterPos3sv) { p_glRasterPos3sv(v); return; } if (a_glRasterPos3sv) a_glRasterPos3sv(v); }
INTERPOSE(glRasterPos3sv)
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*a_glRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (mglshim_active && p_glRasterPos4d) { p_glRasterPos4d(x, y, z, w); return; } if (a_glRasterPos4d) a_glRasterPos4d(x, y, z, w); }
INTERPOSE(glRasterPos4d)
void glRasterPos4dv(const GLdouble *v) WEAKGL;
static void (*p_glRasterPos4dv)(const GLdouble *v);
static void (*a_glRasterPos4dv)(const GLdouble *v);
static void w_glRasterPos4dv(const GLdouble *v) { if (mglshim_active && p_glRasterPos4dv) { p_glRasterPos4dv(v); return; } if (a_glRasterPos4dv) a_glRasterPos4dv(v); }
INTERPOSE(glRasterPos4dv)
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) WEAKGL;
static void (*p_glRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*a_glRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void w_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if (mglshim_active && p_glRasterPos4f) { p_glRasterPos4f(x, y, z, w); return; } if (a_glRasterPos4f) a_glRasterPos4f(x, y, z, w); }
INTERPOSE(glRasterPos4f)
void glRasterPos4fv(const GLfloat *v) WEAKGL;
static void (*p_glRasterPos4fv)(const GLfloat *v);
static void (*a_glRasterPos4fv)(const GLfloat *v);
static void w_glRasterPos4fv(const GLfloat *v) { if (mglshim_active && p_glRasterPos4fv) { p_glRasterPos4fv(v); return; } if (a_glRasterPos4fv) a_glRasterPos4fv(v); }
INTERPOSE(glRasterPos4fv)
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) WEAKGL;
static void (*p_glRasterPos4i)(GLint x, GLint y, GLint z, GLint w);
static void (*a_glRasterPos4i)(GLint x, GLint y, GLint z, GLint w);
static void w_glRasterPos4i(GLint x, GLint y, GLint z, GLint w) { if (mglshim_active && p_glRasterPos4i) { p_glRasterPos4i(x, y, z, w); return; } if (a_glRasterPos4i) a_glRasterPos4i(x, y, z, w); }
INTERPOSE(glRasterPos4i)
void glRasterPos4iv(const GLint *v) WEAKGL;
static void (*p_glRasterPos4iv)(const GLint *v);
static void (*a_glRasterPos4iv)(const GLint *v);
static void w_glRasterPos4iv(const GLint *v) { if (mglshim_active && p_glRasterPos4iv) { p_glRasterPos4iv(v); return; } if (a_glRasterPos4iv) a_glRasterPos4iv(v); }
INTERPOSE(glRasterPos4iv)
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) WEAKGL;
static void (*p_glRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
static void (*a_glRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
static void w_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) { if (mglshim_active && p_glRasterPos4s) { p_glRasterPos4s(x, y, z, w); return; } if (a_glRasterPos4s) a_glRasterPos4s(x, y, z, w); }
INTERPOSE(glRasterPos4s)
void glRasterPos4sv(const GLshort *v) WEAKGL;
static void (*p_glRasterPos4sv)(const GLshort *v);
static void (*a_glRasterPos4sv)(const GLshort *v);
static void w_glRasterPos4sv(const GLshort *v) { if (mglshim_active && p_glRasterPos4sv) { p_glRasterPos4sv(v); return; } if (a_glRasterPos4sv) a_glRasterPos4sv(v); }
INTERPOSE(glRasterPos4sv)
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
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) WEAKGL;
static void (*p_glRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
static void (*a_glRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
static void w_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) { if (mglshim_active && p_glRectd) { p_glRectd(x1, y1, x2, y2); return; } if (a_glRectd) a_glRectd(x1, y1, x2, y2); }
INTERPOSE(glRectd)
void glRectdv(const GLdouble *v1, const GLdouble *v2) WEAKGL;
static void (*p_glRectdv)(const GLdouble *v1, const GLdouble *v2);
static void (*a_glRectdv)(const GLdouble *v1, const GLdouble *v2);
static void w_glRectdv(const GLdouble *v1, const GLdouble *v2) { if (mglshim_active && p_glRectdv) { p_glRectdv(v1, v2); return; } if (a_glRectdv) a_glRectdv(v1, v2); }
INTERPOSE(glRectdv)
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) WEAKGL;
static void (*p_glRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
static void (*a_glRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
static void w_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) { if (mglshim_active && p_glRectf) { p_glRectf(x1, y1, x2, y2); return; } if (a_glRectf) a_glRectf(x1, y1, x2, y2); }
INTERPOSE(glRectf)
void glRectfv(const GLfloat *v1, const GLfloat *v2) WEAKGL;
static void (*p_glRectfv)(const GLfloat *v1, const GLfloat *v2);
static void (*a_glRectfv)(const GLfloat *v1, const GLfloat *v2);
static void w_glRectfv(const GLfloat *v1, const GLfloat *v2) { if (mglshim_active && p_glRectfv) { p_glRectfv(v1, v2); return; } if (a_glRectfv) a_glRectfv(v1, v2); }
INTERPOSE(glRectfv)
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) WEAKGL;
static void (*p_glRecti)(GLint x1, GLint y1, GLint x2, GLint y2);
static void (*a_glRecti)(GLint x1, GLint y1, GLint x2, GLint y2);
static void w_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) { if (mglshim_active && p_glRecti) { p_glRecti(x1, y1, x2, y2); return; } if (a_glRecti) a_glRecti(x1, y1, x2, y2); }
INTERPOSE(glRecti)
void glRectiv(const GLint *v1, const GLint *v2) WEAKGL;
static void (*p_glRectiv)(const GLint *v1, const GLint *v2);
static void (*a_glRectiv)(const GLint *v1, const GLint *v2);
static void w_glRectiv(const GLint *v1, const GLint *v2) { if (mglshim_active && p_glRectiv) { p_glRectiv(v1, v2); return; } if (a_glRectiv) a_glRectiv(v1, v2); }
INTERPOSE(glRectiv)
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) WEAKGL;
static void (*p_glRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
static void (*a_glRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
static void w_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) { if (mglshim_active && p_glRects) { p_glRects(x1, y1, x2, y2); return; } if (a_glRects) a_glRects(x1, y1, x2, y2); }
INTERPOSE(glRects)
void glRectsv(const GLshort *v1, const GLshort *v2) WEAKGL;
static void (*p_glRectsv)(const GLshort *v1, const GLshort *v2);
static void (*a_glRectsv)(const GLshort *v1, const GLshort *v2);
static void w_glRectsv(const GLshort *v1, const GLshort *v2) { if (mglshim_active && p_glRectsv) { p_glRectsv(v1, v2); return; } if (a_glRectsv) a_glRectsv(v1, v2); }
INTERPOSE(glRectsv)
void glReleaseShaderCompiler(void) WEAKGL;
static void (*p_glReleaseShaderCompiler)(void);
static void (*a_glReleaseShaderCompiler)(void);
static void w_glReleaseShaderCompiler(void) { if (mglshim_active && p_glReleaseShaderCompiler) { p_glReleaseShaderCompiler(); return; } if (a_glReleaseShaderCompiler) a_glReleaseShaderCompiler(); }
INTERPOSE(glReleaseShaderCompiler)
GLint glRenderMode(GLenum mode) WEAKGL;
static GLint (*p_glRenderMode)(GLenum mode);
static GLint (*a_glRenderMode)(GLenum mode);
static GLint w_glRenderMode(GLenum mode) { if (mglshim_active && p_glRenderMode) return p_glRenderMode(mode); if (a_glRenderMode) return a_glRenderMode(mode); return (GLint)0; }
INTERPOSE(glRenderMode)
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
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
static void (*a_glRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
static void w_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glRotated) { p_glRotated(angle, x, y, z); return; } if (a_glRotated) a_glRotated(angle, x, y, z); }
INTERPOSE(glRotated)
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
static void (*a_glRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
static void w_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glRotatef) { p_glRotatef(angle, x, y, z); return; } if (a_glRotatef) a_glRotatef(angle, x, y, z); }
INTERPOSE(glRotatef)
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
void glScaled(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glScaled)(GLdouble x, GLdouble y, GLdouble z);
static void (*a_glScaled)(GLdouble x, GLdouble y, GLdouble z);
static void w_glScaled(GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glScaled) { p_glScaled(x, y, z); return; } if (a_glScaled) a_glScaled(x, y, z); }
INTERPOSE(glScaled)
void glScalef(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glScalef)(GLfloat x, GLfloat y, GLfloat z);
static void (*a_glScalef)(GLfloat x, GLfloat y, GLfloat z);
static void w_glScalef(GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glScalef) { p_glScalef(x, y, z); return; } if (a_glScalef) a_glScalef(x, y, z); }
INTERPOSE(glScalef)
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
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) WEAKGL;
static void (*p_glSecondaryColor3b)(GLbyte red, GLbyte green, GLbyte blue);
static void (*a_glSecondaryColor3b)(GLbyte red, GLbyte green, GLbyte blue);
static void w_glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) { if (mglshim_active && p_glSecondaryColor3b) { p_glSecondaryColor3b(red, green, blue); return; } if (a_glSecondaryColor3b) a_glSecondaryColor3b(red, green, blue); }
INTERPOSE(glSecondaryColor3b)
void glSecondaryColor3bv(const GLbyte *v) WEAKGL;
static void (*p_glSecondaryColor3bv)(const GLbyte *v);
static void (*a_glSecondaryColor3bv)(const GLbyte *v);
static void w_glSecondaryColor3bv(const GLbyte *v) { if (mglshim_active && p_glSecondaryColor3bv) { p_glSecondaryColor3bv(v); return; } if (a_glSecondaryColor3bv) a_glSecondaryColor3bv(v); }
INTERPOSE(glSecondaryColor3bv)
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) WEAKGL;
static void (*p_glSecondaryColor3d)(GLdouble red, GLdouble green, GLdouble blue);
static void (*a_glSecondaryColor3d)(GLdouble red, GLdouble green, GLdouble blue);
static void w_glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) { if (mglshim_active && p_glSecondaryColor3d) { p_glSecondaryColor3d(red, green, blue); return; } if (a_glSecondaryColor3d) a_glSecondaryColor3d(red, green, blue); }
INTERPOSE(glSecondaryColor3d)
void glSecondaryColor3dv(const GLdouble *v) WEAKGL;
static void (*p_glSecondaryColor3dv)(const GLdouble *v);
static void (*a_glSecondaryColor3dv)(const GLdouble *v);
static void w_glSecondaryColor3dv(const GLdouble *v) { if (mglshim_active && p_glSecondaryColor3dv) { p_glSecondaryColor3dv(v); return; } if (a_glSecondaryColor3dv) a_glSecondaryColor3dv(v); }
INTERPOSE(glSecondaryColor3dv)
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) WEAKGL;
static void (*p_glSecondaryColor3f)(GLfloat red, GLfloat green, GLfloat blue);
static void (*a_glSecondaryColor3f)(GLfloat red, GLfloat green, GLfloat blue);
static void w_glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) { if (mglshim_active && p_glSecondaryColor3f) { p_glSecondaryColor3f(red, green, blue); return; } if (a_glSecondaryColor3f) a_glSecondaryColor3f(red, green, blue); }
INTERPOSE(glSecondaryColor3f)
void glSecondaryColor3fv(const GLfloat *v) WEAKGL;
static void (*p_glSecondaryColor3fv)(const GLfloat *v);
static void (*a_glSecondaryColor3fv)(const GLfloat *v);
static void w_glSecondaryColor3fv(const GLfloat *v) { if (mglshim_active && p_glSecondaryColor3fv) { p_glSecondaryColor3fv(v); return; } if (a_glSecondaryColor3fv) a_glSecondaryColor3fv(v); }
INTERPOSE(glSecondaryColor3fv)
void glSecondaryColor3i(GLint red, GLint green, GLint blue) WEAKGL;
static void (*p_glSecondaryColor3i)(GLint red, GLint green, GLint blue);
static void (*a_glSecondaryColor3i)(GLint red, GLint green, GLint blue);
static void w_glSecondaryColor3i(GLint red, GLint green, GLint blue) { if (mglshim_active && p_glSecondaryColor3i) { p_glSecondaryColor3i(red, green, blue); return; } if (a_glSecondaryColor3i) a_glSecondaryColor3i(red, green, blue); }
INTERPOSE(glSecondaryColor3i)
void glSecondaryColor3iv(const GLint *v) WEAKGL;
static void (*p_glSecondaryColor3iv)(const GLint *v);
static void (*a_glSecondaryColor3iv)(const GLint *v);
static void w_glSecondaryColor3iv(const GLint *v) { if (mglshim_active && p_glSecondaryColor3iv) { p_glSecondaryColor3iv(v); return; } if (a_glSecondaryColor3iv) a_glSecondaryColor3iv(v); }
INTERPOSE(glSecondaryColor3iv)
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) WEAKGL;
static void (*p_glSecondaryColor3s)(GLshort red, GLshort green, GLshort blue);
static void (*a_glSecondaryColor3s)(GLshort red, GLshort green, GLshort blue);
static void w_glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) { if (mglshim_active && p_glSecondaryColor3s) { p_glSecondaryColor3s(red, green, blue); return; } if (a_glSecondaryColor3s) a_glSecondaryColor3s(red, green, blue); }
INTERPOSE(glSecondaryColor3s)
void glSecondaryColor3sv(const GLshort *v) WEAKGL;
static void (*p_glSecondaryColor3sv)(const GLshort *v);
static void (*a_glSecondaryColor3sv)(const GLshort *v);
static void w_glSecondaryColor3sv(const GLshort *v) { if (mglshim_active && p_glSecondaryColor3sv) { p_glSecondaryColor3sv(v); return; } if (a_glSecondaryColor3sv) a_glSecondaryColor3sv(v); }
INTERPOSE(glSecondaryColor3sv)
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) WEAKGL;
static void (*p_glSecondaryColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
static void (*a_glSecondaryColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
static void w_glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) { if (mglshim_active && p_glSecondaryColor3ub) { p_glSecondaryColor3ub(red, green, blue); return; } if (a_glSecondaryColor3ub) a_glSecondaryColor3ub(red, green, blue); }
INTERPOSE(glSecondaryColor3ub)
void glSecondaryColor3ubv(const GLubyte *v) WEAKGL;
static void (*p_glSecondaryColor3ubv)(const GLubyte *v);
static void (*a_glSecondaryColor3ubv)(const GLubyte *v);
static void w_glSecondaryColor3ubv(const GLubyte *v) { if (mglshim_active && p_glSecondaryColor3ubv) { p_glSecondaryColor3ubv(v); return; } if (a_glSecondaryColor3ubv) a_glSecondaryColor3ubv(v); }
INTERPOSE(glSecondaryColor3ubv)
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) WEAKGL;
static void (*p_glSecondaryColor3ui)(GLuint red, GLuint green, GLuint blue);
static void (*a_glSecondaryColor3ui)(GLuint red, GLuint green, GLuint blue);
static void w_glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) { if (mglshim_active && p_glSecondaryColor3ui) { p_glSecondaryColor3ui(red, green, blue); return; } if (a_glSecondaryColor3ui) a_glSecondaryColor3ui(red, green, blue); }
INTERPOSE(glSecondaryColor3ui)
void glSecondaryColor3uiv(const GLuint *v) WEAKGL;
static void (*p_glSecondaryColor3uiv)(const GLuint *v);
static void (*a_glSecondaryColor3uiv)(const GLuint *v);
static void w_glSecondaryColor3uiv(const GLuint *v) { if (mglshim_active && p_glSecondaryColor3uiv) { p_glSecondaryColor3uiv(v); return; } if (a_glSecondaryColor3uiv) a_glSecondaryColor3uiv(v); }
INTERPOSE(glSecondaryColor3uiv)
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) WEAKGL;
static void (*p_glSecondaryColor3us)(GLushort red, GLushort green, GLushort blue);
static void (*a_glSecondaryColor3us)(GLushort red, GLushort green, GLushort blue);
static void w_glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) { if (mglshim_active && p_glSecondaryColor3us) { p_glSecondaryColor3us(red, green, blue); return; } if (a_glSecondaryColor3us) a_glSecondaryColor3us(red, green, blue); }
INTERPOSE(glSecondaryColor3us)
void glSecondaryColor3usv(const GLushort *v) WEAKGL;
static void (*p_glSecondaryColor3usv)(const GLushort *v);
static void (*a_glSecondaryColor3usv)(const GLushort *v);
static void w_glSecondaryColor3usv(const GLushort *v) { if (mglshim_active && p_glSecondaryColor3usv) { p_glSecondaryColor3usv(v); return; } if (a_glSecondaryColor3usv) a_glSecondaryColor3usv(v); }
INTERPOSE(glSecondaryColor3usv)
void glSecondaryColorP3ui(GLenum type, GLuint color) WEAKGL;
static void (*p_glSecondaryColorP3ui)(GLenum type, GLuint color);
static void (*a_glSecondaryColorP3ui)(GLenum type, GLuint color);
static void w_glSecondaryColorP3ui(GLenum type, GLuint color) { if (mglshim_active && p_glSecondaryColorP3ui) { p_glSecondaryColorP3ui(type, color); return; } if (a_glSecondaryColorP3ui) a_glSecondaryColorP3ui(type, color); }
INTERPOSE(glSecondaryColorP3ui)
void glSecondaryColorP3uiv(GLenum type, const GLuint *color) WEAKGL;
static void (*p_glSecondaryColorP3uiv)(GLenum type, const GLuint *color);
static void (*a_glSecondaryColorP3uiv)(GLenum type, const GLuint *color);
static void w_glSecondaryColorP3uiv(GLenum type, const GLuint *color) { if (mglshim_active && p_glSecondaryColorP3uiv) { p_glSecondaryColorP3uiv(type, color); return; } if (a_glSecondaryColorP3uiv) a_glSecondaryColorP3uiv(type, color); }
INTERPOSE(glSecondaryColorP3uiv)
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glSecondaryColorPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*a_glSecondaryColorPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glSecondaryColorPointer) { p_glSecondaryColorPointer(size, type, stride, pointer); return; } if (a_glSecondaryColorPointer) a_glSecondaryColorPointer(size, type, stride, pointer); }
INTERPOSE(glSecondaryColorPointer)
void glSelectBuffer(GLsizei size, GLuint *buffer) WEAKGL;
static void (*p_glSelectBuffer)(GLsizei size, GLuint *buffer);
static void (*a_glSelectBuffer)(GLsizei size, GLuint *buffer);
static void w_glSelectBuffer(GLsizei size, GLuint *buffer) { if (mglshim_active && p_glSelectBuffer) { p_glSelectBuffer(size, buffer); return; } if (a_glSelectBuffer) a_glSelectBuffer(size, buffer); }
INTERPOSE(glSelectBuffer)
void glShadeModel(GLenum mode) WEAKGL;
static void (*p_glShadeModel)(GLenum mode);
static void (*a_glShadeModel)(GLenum mode);
static void w_glShadeModel(GLenum mode) { if (mglshim_active && p_glShadeModel) { p_glShadeModel(mode); return; } if (a_glShadeModel) a_glShadeModel(mode); }
INTERPOSE(glShadeModel)
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
void glTexCoord1d(GLdouble s) WEAKGL;
static void (*p_glTexCoord1d)(GLdouble s);
static void (*a_glTexCoord1d)(GLdouble s);
static void w_glTexCoord1d(GLdouble s) { if (mglshim_active && p_glTexCoord1d) { p_glTexCoord1d(s); return; } if (a_glTexCoord1d) a_glTexCoord1d(s); }
INTERPOSE(glTexCoord1d)
void glTexCoord1dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord1dv)(const GLdouble *v);
static void (*a_glTexCoord1dv)(const GLdouble *v);
static void w_glTexCoord1dv(const GLdouble *v) { if (mglshim_active && p_glTexCoord1dv) { p_glTexCoord1dv(v); return; } if (a_glTexCoord1dv) a_glTexCoord1dv(v); }
INTERPOSE(glTexCoord1dv)
void glTexCoord1f(GLfloat s) WEAKGL;
static void (*p_glTexCoord1f)(GLfloat s);
static void (*a_glTexCoord1f)(GLfloat s);
static void w_glTexCoord1f(GLfloat s) { if (mglshim_active && p_glTexCoord1f) { p_glTexCoord1f(s); return; } if (a_glTexCoord1f) a_glTexCoord1f(s); }
INTERPOSE(glTexCoord1f)
void glTexCoord1fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord1fv)(const GLfloat *v);
static void (*a_glTexCoord1fv)(const GLfloat *v);
static void w_glTexCoord1fv(const GLfloat *v) { if (mglshim_active && p_glTexCoord1fv) { p_glTexCoord1fv(v); return; } if (a_glTexCoord1fv) a_glTexCoord1fv(v); }
INTERPOSE(glTexCoord1fv)
void glTexCoord1i(GLint s) WEAKGL;
static void (*p_glTexCoord1i)(GLint s);
static void (*a_glTexCoord1i)(GLint s);
static void w_glTexCoord1i(GLint s) { if (mglshim_active && p_glTexCoord1i) { p_glTexCoord1i(s); return; } if (a_glTexCoord1i) a_glTexCoord1i(s); }
INTERPOSE(glTexCoord1i)
void glTexCoord1iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord1iv)(const GLint *v);
static void (*a_glTexCoord1iv)(const GLint *v);
static void w_glTexCoord1iv(const GLint *v) { if (mglshim_active && p_glTexCoord1iv) { p_glTexCoord1iv(v); return; } if (a_glTexCoord1iv) a_glTexCoord1iv(v); }
INTERPOSE(glTexCoord1iv)
void glTexCoord1s(GLshort s) WEAKGL;
static void (*p_glTexCoord1s)(GLshort s);
static void (*a_glTexCoord1s)(GLshort s);
static void w_glTexCoord1s(GLshort s) { if (mglshim_active && p_glTexCoord1s) { p_glTexCoord1s(s); return; } if (a_glTexCoord1s) a_glTexCoord1s(s); }
INTERPOSE(glTexCoord1s)
void glTexCoord1sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord1sv)(const GLshort *v);
static void (*a_glTexCoord1sv)(const GLshort *v);
static void w_glTexCoord1sv(const GLshort *v) { if (mglshim_active && p_glTexCoord1sv) { p_glTexCoord1sv(v); return; } if (a_glTexCoord1sv) a_glTexCoord1sv(v); }
INTERPOSE(glTexCoord1sv)
void glTexCoord2d(GLdouble s, GLdouble t) WEAKGL;
static void (*p_glTexCoord2d)(GLdouble s, GLdouble t);
static void (*a_glTexCoord2d)(GLdouble s, GLdouble t);
static void w_glTexCoord2d(GLdouble s, GLdouble t) { if (mglshim_active && p_glTexCoord2d) { p_glTexCoord2d(s, t); return; } if (a_glTexCoord2d) a_glTexCoord2d(s, t); }
INTERPOSE(glTexCoord2d)
void glTexCoord2dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord2dv)(const GLdouble *v);
static void (*a_glTexCoord2dv)(const GLdouble *v);
static void w_glTexCoord2dv(const GLdouble *v) { if (mglshim_active && p_glTexCoord2dv) { p_glTexCoord2dv(v); return; } if (a_glTexCoord2dv) a_glTexCoord2dv(v); }
INTERPOSE(glTexCoord2dv)
void glTexCoord2f(GLfloat s, GLfloat t) WEAKGL;
static void (*p_glTexCoord2f)(GLfloat s, GLfloat t);
static void (*a_glTexCoord2f)(GLfloat s, GLfloat t);
static void w_glTexCoord2f(GLfloat s, GLfloat t) { if (mglshim_active && p_glTexCoord2f) { p_glTexCoord2f(s, t); return; } if (a_glTexCoord2f) a_glTexCoord2f(s, t); }
INTERPOSE(glTexCoord2f)
void glTexCoord2fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord2fv)(const GLfloat *v);
static void (*a_glTexCoord2fv)(const GLfloat *v);
static void w_glTexCoord2fv(const GLfloat *v) { if (mglshim_active && p_glTexCoord2fv) { p_glTexCoord2fv(v); return; } if (a_glTexCoord2fv) a_glTexCoord2fv(v); }
INTERPOSE(glTexCoord2fv)
void glTexCoord2i(GLint s, GLint t) WEAKGL;
static void (*p_glTexCoord2i)(GLint s, GLint t);
static void (*a_glTexCoord2i)(GLint s, GLint t);
static void w_glTexCoord2i(GLint s, GLint t) { if (mglshim_active && p_glTexCoord2i) { p_glTexCoord2i(s, t); return; } if (a_glTexCoord2i) a_glTexCoord2i(s, t); }
INTERPOSE(glTexCoord2i)
void glTexCoord2iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord2iv)(const GLint *v);
static void (*a_glTexCoord2iv)(const GLint *v);
static void w_glTexCoord2iv(const GLint *v) { if (mglshim_active && p_glTexCoord2iv) { p_glTexCoord2iv(v); return; } if (a_glTexCoord2iv) a_glTexCoord2iv(v); }
INTERPOSE(glTexCoord2iv)
void glTexCoord2s(GLshort s, GLshort t) WEAKGL;
static void (*p_glTexCoord2s)(GLshort s, GLshort t);
static void (*a_glTexCoord2s)(GLshort s, GLshort t);
static void w_glTexCoord2s(GLshort s, GLshort t) { if (mglshim_active && p_glTexCoord2s) { p_glTexCoord2s(s, t); return; } if (a_glTexCoord2s) a_glTexCoord2s(s, t); }
INTERPOSE(glTexCoord2s)
void glTexCoord2sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord2sv)(const GLshort *v);
static void (*a_glTexCoord2sv)(const GLshort *v);
static void w_glTexCoord2sv(const GLshort *v) { if (mglshim_active && p_glTexCoord2sv) { p_glTexCoord2sv(v); return; } if (a_glTexCoord2sv) a_glTexCoord2sv(v); }
INTERPOSE(glTexCoord2sv)
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) WEAKGL;
static void (*p_glTexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
static void (*a_glTexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
static void w_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) { if (mglshim_active && p_glTexCoord3d) { p_glTexCoord3d(s, t, r); return; } if (a_glTexCoord3d) a_glTexCoord3d(s, t, r); }
INTERPOSE(glTexCoord3d)
void glTexCoord3dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord3dv)(const GLdouble *v);
static void (*a_glTexCoord3dv)(const GLdouble *v);
static void w_glTexCoord3dv(const GLdouble *v) { if (mglshim_active && p_glTexCoord3dv) { p_glTexCoord3dv(v); return; } if (a_glTexCoord3dv) a_glTexCoord3dv(v); }
INTERPOSE(glTexCoord3dv)
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) WEAKGL;
static void (*p_glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
static void (*a_glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
static void w_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) { if (mglshim_active && p_glTexCoord3f) { p_glTexCoord3f(s, t, r); return; } if (a_glTexCoord3f) a_glTexCoord3f(s, t, r); }
INTERPOSE(glTexCoord3f)
void glTexCoord3fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord3fv)(const GLfloat *v);
static void (*a_glTexCoord3fv)(const GLfloat *v);
static void w_glTexCoord3fv(const GLfloat *v) { if (mglshim_active && p_glTexCoord3fv) { p_glTexCoord3fv(v); return; } if (a_glTexCoord3fv) a_glTexCoord3fv(v); }
INTERPOSE(glTexCoord3fv)
void glTexCoord3i(GLint s, GLint t, GLint r) WEAKGL;
static void (*p_glTexCoord3i)(GLint s, GLint t, GLint r);
static void (*a_glTexCoord3i)(GLint s, GLint t, GLint r);
static void w_glTexCoord3i(GLint s, GLint t, GLint r) { if (mglshim_active && p_glTexCoord3i) { p_glTexCoord3i(s, t, r); return; } if (a_glTexCoord3i) a_glTexCoord3i(s, t, r); }
INTERPOSE(glTexCoord3i)
void glTexCoord3iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord3iv)(const GLint *v);
static void (*a_glTexCoord3iv)(const GLint *v);
static void w_glTexCoord3iv(const GLint *v) { if (mglshim_active && p_glTexCoord3iv) { p_glTexCoord3iv(v); return; } if (a_glTexCoord3iv) a_glTexCoord3iv(v); }
INTERPOSE(glTexCoord3iv)
void glTexCoord3s(GLshort s, GLshort t, GLshort r) WEAKGL;
static void (*p_glTexCoord3s)(GLshort s, GLshort t, GLshort r);
static void (*a_glTexCoord3s)(GLshort s, GLshort t, GLshort r);
static void w_glTexCoord3s(GLshort s, GLshort t, GLshort r) { if (mglshim_active && p_glTexCoord3s) { p_glTexCoord3s(s, t, r); return; } if (a_glTexCoord3s) a_glTexCoord3s(s, t, r); }
INTERPOSE(glTexCoord3s)
void glTexCoord3sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord3sv)(const GLshort *v);
static void (*a_glTexCoord3sv)(const GLshort *v);
static void w_glTexCoord3sv(const GLshort *v) { if (mglshim_active && p_glTexCoord3sv) { p_glTexCoord3sv(v); return; } if (a_glTexCoord3sv) a_glTexCoord3sv(v); }
INTERPOSE(glTexCoord3sv)
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) WEAKGL;
static void (*p_glTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void (*a_glTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void w_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) { if (mglshim_active && p_glTexCoord4d) { p_glTexCoord4d(s, t, r, q); return; } if (a_glTexCoord4d) a_glTexCoord4d(s, t, r, q); }
INTERPOSE(glTexCoord4d)
void glTexCoord4dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord4dv)(const GLdouble *v);
static void (*a_glTexCoord4dv)(const GLdouble *v);
static void w_glTexCoord4dv(const GLdouble *v) { if (mglshim_active && p_glTexCoord4dv) { p_glTexCoord4dv(v); return; } if (a_glTexCoord4dv) a_glTexCoord4dv(v); }
INTERPOSE(glTexCoord4dv)
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) WEAKGL;
static void (*p_glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void (*a_glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void w_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) { if (mglshim_active && p_glTexCoord4f) { p_glTexCoord4f(s, t, r, q); return; } if (a_glTexCoord4f) a_glTexCoord4f(s, t, r, q); }
INTERPOSE(glTexCoord4f)
void glTexCoord4fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord4fv)(const GLfloat *v);
static void (*a_glTexCoord4fv)(const GLfloat *v);
static void w_glTexCoord4fv(const GLfloat *v) { if (mglshim_active && p_glTexCoord4fv) { p_glTexCoord4fv(v); return; } if (a_glTexCoord4fv) a_glTexCoord4fv(v); }
INTERPOSE(glTexCoord4fv)
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) WEAKGL;
static void (*p_glTexCoord4i)(GLint s, GLint t, GLint r, GLint q);
static void (*a_glTexCoord4i)(GLint s, GLint t, GLint r, GLint q);
static void w_glTexCoord4i(GLint s, GLint t, GLint r, GLint q) { if (mglshim_active && p_glTexCoord4i) { p_glTexCoord4i(s, t, r, q); return; } if (a_glTexCoord4i) a_glTexCoord4i(s, t, r, q); }
INTERPOSE(glTexCoord4i)
void glTexCoord4iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord4iv)(const GLint *v);
static void (*a_glTexCoord4iv)(const GLint *v);
static void w_glTexCoord4iv(const GLint *v) { if (mglshim_active && p_glTexCoord4iv) { p_glTexCoord4iv(v); return; } if (a_glTexCoord4iv) a_glTexCoord4iv(v); }
INTERPOSE(glTexCoord4iv)
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) WEAKGL;
static void (*p_glTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
static void (*a_glTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
static void w_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) { if (mglshim_active && p_glTexCoord4s) { p_glTexCoord4s(s, t, r, q); return; } if (a_glTexCoord4s) a_glTexCoord4s(s, t, r, q); }
INTERPOSE(glTexCoord4s)
void glTexCoord4sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord4sv)(const GLshort *v);
static void (*a_glTexCoord4sv)(const GLshort *v);
static void w_glTexCoord4sv(const GLshort *v) { if (mglshim_active && p_glTexCoord4sv) { p_glTexCoord4sv(v); return; } if (a_glTexCoord4sv) a_glTexCoord4sv(v); }
INTERPOSE(glTexCoord4sv)
void glTexCoordP1ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP1ui)(GLenum type, GLuint coords);
static void (*a_glTexCoordP1ui)(GLenum type, GLuint coords);
static void w_glTexCoordP1ui(GLenum type, GLuint coords) { if (mglshim_active && p_glTexCoordP1ui) { p_glTexCoordP1ui(type, coords); return; } if (a_glTexCoordP1ui) a_glTexCoordP1ui(type, coords); }
INTERPOSE(glTexCoordP1ui)
void glTexCoordP1uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP1uiv)(GLenum type, const GLuint *coords);
static void (*a_glTexCoordP1uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP1uiv(GLenum type, const GLuint *coords) { if (mglshim_active && p_glTexCoordP1uiv) { p_glTexCoordP1uiv(type, coords); return; } if (a_glTexCoordP1uiv) a_glTexCoordP1uiv(type, coords); }
INTERPOSE(glTexCoordP1uiv)
void glTexCoordP2ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP2ui)(GLenum type, GLuint coords);
static void (*a_glTexCoordP2ui)(GLenum type, GLuint coords);
static void w_glTexCoordP2ui(GLenum type, GLuint coords) { if (mglshim_active && p_glTexCoordP2ui) { p_glTexCoordP2ui(type, coords); return; } if (a_glTexCoordP2ui) a_glTexCoordP2ui(type, coords); }
INTERPOSE(glTexCoordP2ui)
void glTexCoordP2uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP2uiv)(GLenum type, const GLuint *coords);
static void (*a_glTexCoordP2uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP2uiv(GLenum type, const GLuint *coords) { if (mglshim_active && p_glTexCoordP2uiv) { p_glTexCoordP2uiv(type, coords); return; } if (a_glTexCoordP2uiv) a_glTexCoordP2uiv(type, coords); }
INTERPOSE(glTexCoordP2uiv)
void glTexCoordP3ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP3ui)(GLenum type, GLuint coords);
static void (*a_glTexCoordP3ui)(GLenum type, GLuint coords);
static void w_glTexCoordP3ui(GLenum type, GLuint coords) { if (mglshim_active && p_glTexCoordP3ui) { p_glTexCoordP3ui(type, coords); return; } if (a_glTexCoordP3ui) a_glTexCoordP3ui(type, coords); }
INTERPOSE(glTexCoordP3ui)
void glTexCoordP3uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP3uiv)(GLenum type, const GLuint *coords);
static void (*a_glTexCoordP3uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP3uiv(GLenum type, const GLuint *coords) { if (mglshim_active && p_glTexCoordP3uiv) { p_glTexCoordP3uiv(type, coords); return; } if (a_glTexCoordP3uiv) a_glTexCoordP3uiv(type, coords); }
INTERPOSE(glTexCoordP3uiv)
void glTexCoordP4ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP4ui)(GLenum type, GLuint coords);
static void (*a_glTexCoordP4ui)(GLenum type, GLuint coords);
static void w_glTexCoordP4ui(GLenum type, GLuint coords) { if (mglshim_active && p_glTexCoordP4ui) { p_glTexCoordP4ui(type, coords); return; } if (a_glTexCoordP4ui) a_glTexCoordP4ui(type, coords); }
INTERPOSE(glTexCoordP4ui)
void glTexCoordP4uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP4uiv)(GLenum type, const GLuint *coords);
static void (*a_glTexCoordP4uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP4uiv(GLenum type, const GLuint *coords) { if (mglshim_active && p_glTexCoordP4uiv) { p_glTexCoordP4uiv(type, coords); return; } if (a_glTexCoordP4uiv) a_glTexCoordP4uiv(type, coords); }
INTERPOSE(glTexCoordP4uiv)
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*a_glTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glTexCoordPointer) { p_glTexCoordPointer(size, type, stride, pointer); return; } if (a_glTexCoordPointer) a_glTexCoordPointer(size, type, stride, pointer); }
INTERPOSE(glTexCoordPointer)
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTexEnvf)(GLenum target, GLenum pname, GLfloat param);
static void (*a_glTexEnvf)(GLenum target, GLenum pname, GLfloat param);
static void w_glTexEnvf(GLenum target, GLenum pname, GLfloat param) { if (mglshim_active && p_glTexEnvf) { p_glTexEnvf(target, pname, param); return; } if (a_glTexEnvf) a_glTexEnvf(target, pname, param); }
INTERPOSE(glTexEnvf)
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glTexEnvfv)(GLenum target, GLenum pname, const GLfloat *params);
static void (*a_glTexEnvfv)(GLenum target, GLenum pname, const GLfloat *params);
static void w_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) { if (mglshim_active && p_glTexEnvfv) { p_glTexEnvfv(target, pname, params); return; } if (a_glTexEnvfv) a_glTexEnvfv(target, pname, params); }
INTERPOSE(glTexEnvfv)
void glTexEnvi(GLenum target, GLenum pname, GLint param) WEAKGL;
static void (*p_glTexEnvi)(GLenum target, GLenum pname, GLint param);
static void (*a_glTexEnvi)(GLenum target, GLenum pname, GLint param);
static void w_glTexEnvi(GLenum target, GLenum pname, GLint param) { if (mglshim_active && p_glTexEnvi) { p_glTexEnvi(target, pname, param); return; } if (a_glTexEnvi) a_glTexEnvi(target, pname, param); }
INTERPOSE(glTexEnvi)
void glTexEnviv(GLenum target, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexEnviv)(GLenum target, GLenum pname, const GLint *params);
static void (*a_glTexEnviv)(GLenum target, GLenum pname, const GLint *params);
static void w_glTexEnviv(GLenum target, GLenum pname, const GLint *params) { if (mglshim_active && p_glTexEnviv) { p_glTexEnviv(target, pname, params); return; } if (a_glTexEnviv) a_glTexEnviv(target, pname, params); }
INTERPOSE(glTexEnviv)
void glTexGend(GLenum coord, GLenum pname, GLdouble param) WEAKGL;
static void (*p_glTexGend)(GLenum coord, GLenum pname, GLdouble param);
static void (*a_glTexGend)(GLenum coord, GLenum pname, GLdouble param);
static void w_glTexGend(GLenum coord, GLenum pname, GLdouble param) { if (mglshim_active && p_glTexGend) { p_glTexGend(coord, pname, param); return; } if (a_glTexGend) a_glTexGend(coord, pname, param); }
INTERPOSE(glTexGend)
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) WEAKGL;
static void (*p_glTexGendv)(GLenum coord, GLenum pname, const GLdouble *params);
static void (*a_glTexGendv)(GLenum coord, GLenum pname, const GLdouble *params);
static void w_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) { if (mglshim_active && p_glTexGendv) { p_glTexGendv(coord, pname, params); return; } if (a_glTexGendv) a_glTexGendv(coord, pname, params); }
INTERPOSE(glTexGendv)
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTexGenf)(GLenum coord, GLenum pname, GLfloat param);
static void (*a_glTexGenf)(GLenum coord, GLenum pname, GLfloat param);
static void w_glTexGenf(GLenum coord, GLenum pname, GLfloat param) { if (mglshim_active && p_glTexGenf) { p_glTexGenf(coord, pname, param); return; } if (a_glTexGenf) a_glTexGenf(coord, pname, param); }
INTERPOSE(glTexGenf)
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glTexGenfv)(GLenum coord, GLenum pname, const GLfloat *params);
static void (*a_glTexGenfv)(GLenum coord, GLenum pname, const GLfloat *params);
static void w_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params) { if (mglshim_active && p_glTexGenfv) { p_glTexGenfv(coord, pname, params); return; } if (a_glTexGenfv) a_glTexGenfv(coord, pname, params); }
INTERPOSE(glTexGenfv)
void glTexGeni(GLenum coord, GLenum pname, GLint param) WEAKGL;
static void (*p_glTexGeni)(GLenum coord, GLenum pname, GLint param);
static void (*a_glTexGeni)(GLenum coord, GLenum pname, GLint param);
static void w_glTexGeni(GLenum coord, GLenum pname, GLint param) { if (mglshim_active && p_glTexGeni) { p_glTexGeni(coord, pname, param); return; } if (a_glTexGeni) a_glTexGeni(coord, pname, param); }
INTERPOSE(glTexGeni)
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexGeniv)(GLenum coord, GLenum pname, const GLint *params);
static void (*a_glTexGeniv)(GLenum coord, GLenum pname, const GLint *params);
static void w_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) { if (mglshim_active && p_glTexGeniv) { p_glTexGeniv(coord, pname, params); return; } if (a_glTexGeniv) a_glTexGeniv(coord, pname, params); }
INTERPOSE(glTexGeniv)
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
void glTranslated(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glTranslated)(GLdouble x, GLdouble y, GLdouble z);
static void (*a_glTranslated)(GLdouble x, GLdouble y, GLdouble z);
static void w_glTranslated(GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glTranslated) { p_glTranslated(x, y, z); return; } if (a_glTranslated) a_glTranslated(x, y, z); }
INTERPOSE(glTranslated)
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glTranslatef)(GLfloat x, GLfloat y, GLfloat z);
static void (*a_glTranslatef)(GLfloat x, GLfloat y, GLfloat z);
static void w_glTranslatef(GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glTranslatef) { p_glTranslatef(x, y, z); return; } if (a_glTranslatef) a_glTranslatef(x, y, z); }
INTERPOSE(glTranslatef)
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
void glVertex2d(GLdouble x, GLdouble y) WEAKGL;
static void (*p_glVertex2d)(GLdouble x, GLdouble y);
static void (*a_glVertex2d)(GLdouble x, GLdouble y);
static void w_glVertex2d(GLdouble x, GLdouble y) { if (mglshim_active && p_glVertex2d) { p_glVertex2d(x, y); return; } if (a_glVertex2d) a_glVertex2d(x, y); }
INTERPOSE(glVertex2d)
void glVertex2dv(const GLdouble *v) WEAKGL;
static void (*p_glVertex2dv)(const GLdouble *v);
static void (*a_glVertex2dv)(const GLdouble *v);
static void w_glVertex2dv(const GLdouble *v) { if (mglshim_active && p_glVertex2dv) { p_glVertex2dv(v); return; } if (a_glVertex2dv) a_glVertex2dv(v); }
INTERPOSE(glVertex2dv)
void glVertex2f(GLfloat x, GLfloat y) WEAKGL;
static void (*p_glVertex2f)(GLfloat x, GLfloat y);
static void (*a_glVertex2f)(GLfloat x, GLfloat y);
static void w_glVertex2f(GLfloat x, GLfloat y) { if (mglshim_active && p_glVertex2f) { p_glVertex2f(x, y); return; } if (a_glVertex2f) a_glVertex2f(x, y); }
INTERPOSE(glVertex2f)
void glVertex2fv(const GLfloat *v) WEAKGL;
static void (*p_glVertex2fv)(const GLfloat *v);
static void (*a_glVertex2fv)(const GLfloat *v);
static void w_glVertex2fv(const GLfloat *v) { if (mglshim_active && p_glVertex2fv) { p_glVertex2fv(v); return; } if (a_glVertex2fv) a_glVertex2fv(v); }
INTERPOSE(glVertex2fv)
void glVertex2i(GLint x, GLint y) WEAKGL;
static void (*p_glVertex2i)(GLint x, GLint y);
static void (*a_glVertex2i)(GLint x, GLint y);
static void w_glVertex2i(GLint x, GLint y) { if (mglshim_active && p_glVertex2i) { p_glVertex2i(x, y); return; } if (a_glVertex2i) a_glVertex2i(x, y); }
INTERPOSE(glVertex2i)
void glVertex2iv(const GLint *v) WEAKGL;
static void (*p_glVertex2iv)(const GLint *v);
static void (*a_glVertex2iv)(const GLint *v);
static void w_glVertex2iv(const GLint *v) { if (mglshim_active && p_glVertex2iv) { p_glVertex2iv(v); return; } if (a_glVertex2iv) a_glVertex2iv(v); }
INTERPOSE(glVertex2iv)
void glVertex2s(GLshort x, GLshort y) WEAKGL;
static void (*p_glVertex2s)(GLshort x, GLshort y);
static void (*a_glVertex2s)(GLshort x, GLshort y);
static void w_glVertex2s(GLshort x, GLshort y) { if (mglshim_active && p_glVertex2s) { p_glVertex2s(x, y); return; } if (a_glVertex2s) a_glVertex2s(x, y); }
INTERPOSE(glVertex2s)
void glVertex2sv(const GLshort *v) WEAKGL;
static void (*p_glVertex2sv)(const GLshort *v);
static void (*a_glVertex2sv)(const GLshort *v);
static void w_glVertex2sv(const GLshort *v) { if (mglshim_active && p_glVertex2sv) { p_glVertex2sv(v); return; } if (a_glVertex2sv) a_glVertex2sv(v); }
INTERPOSE(glVertex2sv)
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glVertex3d)(GLdouble x, GLdouble y, GLdouble z);
static void (*a_glVertex3d)(GLdouble x, GLdouble y, GLdouble z);
static void w_glVertex3d(GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glVertex3d) { p_glVertex3d(x, y, z); return; } if (a_glVertex3d) a_glVertex3d(x, y, z); }
INTERPOSE(glVertex3d)
void glVertex3dv(const GLdouble *v) WEAKGL;
static void (*p_glVertex3dv)(const GLdouble *v);
static void (*a_glVertex3dv)(const GLdouble *v);
static void w_glVertex3dv(const GLdouble *v) { if (mglshim_active && p_glVertex3dv) { p_glVertex3dv(v); return; } if (a_glVertex3dv) a_glVertex3dv(v); }
INTERPOSE(glVertex3dv)
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glVertex3f)(GLfloat x, GLfloat y, GLfloat z);
static void (*a_glVertex3f)(GLfloat x, GLfloat y, GLfloat z);
static void w_glVertex3f(GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glVertex3f) { p_glVertex3f(x, y, z); return; } if (a_glVertex3f) a_glVertex3f(x, y, z); }
INTERPOSE(glVertex3f)
void glVertex3fv(const GLfloat *v) WEAKGL;
static void (*p_glVertex3fv)(const GLfloat *v);
static void (*a_glVertex3fv)(const GLfloat *v);
static void w_glVertex3fv(const GLfloat *v) { if (mglshim_active && p_glVertex3fv) { p_glVertex3fv(v); return; } if (a_glVertex3fv) a_glVertex3fv(v); }
INTERPOSE(glVertex3fv)
void glVertex3i(GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glVertex3i)(GLint x, GLint y, GLint z);
static void (*a_glVertex3i)(GLint x, GLint y, GLint z);
static void w_glVertex3i(GLint x, GLint y, GLint z) { if (mglshim_active && p_glVertex3i) { p_glVertex3i(x, y, z); return; } if (a_glVertex3i) a_glVertex3i(x, y, z); }
INTERPOSE(glVertex3i)
void glVertex3iv(const GLint *v) WEAKGL;
static void (*p_glVertex3iv)(const GLint *v);
static void (*a_glVertex3iv)(const GLint *v);
static void w_glVertex3iv(const GLint *v) { if (mglshim_active && p_glVertex3iv) { p_glVertex3iv(v); return; } if (a_glVertex3iv) a_glVertex3iv(v); }
INTERPOSE(glVertex3iv)
void glVertex3s(GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glVertex3s)(GLshort x, GLshort y, GLshort z);
static void (*a_glVertex3s)(GLshort x, GLshort y, GLshort z);
static void w_glVertex3s(GLshort x, GLshort y, GLshort z) { if (mglshim_active && p_glVertex3s) { p_glVertex3s(x, y, z); return; } if (a_glVertex3s) a_glVertex3s(x, y, z); }
INTERPOSE(glVertex3s)
void glVertex3sv(const GLshort *v) WEAKGL;
static void (*p_glVertex3sv)(const GLshort *v);
static void (*a_glVertex3sv)(const GLshort *v);
static void w_glVertex3sv(const GLshort *v) { if (mglshim_active && p_glVertex3sv) { p_glVertex3sv(v); return; } if (a_glVertex3sv) a_glVertex3sv(v); }
INTERPOSE(glVertex3sv)
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void (*a_glVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (mglshim_active && p_glVertex4d) { p_glVertex4d(x, y, z, w); return; } if (a_glVertex4d) a_glVertex4d(x, y, z, w); }
INTERPOSE(glVertex4d)
void glVertex4dv(const GLdouble *v) WEAKGL;
static void (*p_glVertex4dv)(const GLdouble *v);
static void (*a_glVertex4dv)(const GLdouble *v);
static void w_glVertex4dv(const GLdouble *v) { if (mglshim_active && p_glVertex4dv) { p_glVertex4dv(v); return; } if (a_glVertex4dv) a_glVertex4dv(v); }
INTERPOSE(glVertex4dv)
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) WEAKGL;
static void (*p_glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void (*a_glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void w_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if (mglshim_active && p_glVertex4f) { p_glVertex4f(x, y, z, w); return; } if (a_glVertex4f) a_glVertex4f(x, y, z, w); }
INTERPOSE(glVertex4f)
void glVertex4fv(const GLfloat *v) WEAKGL;
static void (*p_glVertex4fv)(const GLfloat *v);
static void (*a_glVertex4fv)(const GLfloat *v);
static void w_glVertex4fv(const GLfloat *v) { if (mglshim_active && p_glVertex4fv) { p_glVertex4fv(v); return; } if (a_glVertex4fv) a_glVertex4fv(v); }
INTERPOSE(glVertex4fv)
void glVertex4i(GLint x, GLint y, GLint z, GLint w) WEAKGL;
static void (*p_glVertex4i)(GLint x, GLint y, GLint z, GLint w);
static void (*a_glVertex4i)(GLint x, GLint y, GLint z, GLint w);
static void w_glVertex4i(GLint x, GLint y, GLint z, GLint w) { if (mglshim_active && p_glVertex4i) { p_glVertex4i(x, y, z, w); return; } if (a_glVertex4i) a_glVertex4i(x, y, z, w); }
INTERPOSE(glVertex4i)
void glVertex4iv(const GLint *v) WEAKGL;
static void (*p_glVertex4iv)(const GLint *v);
static void (*a_glVertex4iv)(const GLint *v);
static void w_glVertex4iv(const GLint *v) { if (mglshim_active && p_glVertex4iv) { p_glVertex4iv(v); return; } if (a_glVertex4iv) a_glVertex4iv(v); }
INTERPOSE(glVertex4iv)
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) WEAKGL;
static void (*p_glVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
static void (*a_glVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
static void w_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) { if (mglshim_active && p_glVertex4s) { p_glVertex4s(x, y, z, w); return; } if (a_glVertex4s) a_glVertex4s(x, y, z, w); }
INTERPOSE(glVertex4s)
void glVertex4sv(const GLshort *v) WEAKGL;
static void (*p_glVertex4sv)(const GLshort *v);
static void (*a_glVertex4sv)(const GLshort *v);
static void w_glVertex4sv(const GLshort *v) { if (mglshim_active && p_glVertex4sv) { p_glVertex4sv(v); return; } if (a_glVertex4sv) a_glVertex4sv(v); }
INTERPOSE(glVertex4sv)
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
void glVertexP2ui(GLenum type, GLuint value) WEAKGL;
static void (*p_glVertexP2ui)(GLenum type, GLuint value);
static void (*a_glVertexP2ui)(GLenum type, GLuint value);
static void w_glVertexP2ui(GLenum type, GLuint value) { if (mglshim_active && p_glVertexP2ui) { p_glVertexP2ui(type, value); return; } if (a_glVertexP2ui) a_glVertexP2ui(type, value); }
INTERPOSE(glVertexP2ui)
void glVertexP2uiv(GLenum type, const GLuint *value) WEAKGL;
static void (*p_glVertexP2uiv)(GLenum type, const GLuint *value);
static void (*a_glVertexP2uiv)(GLenum type, const GLuint *value);
static void w_glVertexP2uiv(GLenum type, const GLuint *value) { if (mglshim_active && p_glVertexP2uiv) { p_glVertexP2uiv(type, value); return; } if (a_glVertexP2uiv) a_glVertexP2uiv(type, value); }
INTERPOSE(glVertexP2uiv)
void glVertexP3ui(GLenum type, GLuint value) WEAKGL;
static void (*p_glVertexP3ui)(GLenum type, GLuint value);
static void (*a_glVertexP3ui)(GLenum type, GLuint value);
static void w_glVertexP3ui(GLenum type, GLuint value) { if (mglshim_active && p_glVertexP3ui) { p_glVertexP3ui(type, value); return; } if (a_glVertexP3ui) a_glVertexP3ui(type, value); }
INTERPOSE(glVertexP3ui)
void glVertexP3uiv(GLenum type, const GLuint *value) WEAKGL;
static void (*p_glVertexP3uiv)(GLenum type, const GLuint *value);
static void (*a_glVertexP3uiv)(GLenum type, const GLuint *value);
static void w_glVertexP3uiv(GLenum type, const GLuint *value) { if (mglshim_active && p_glVertexP3uiv) { p_glVertexP3uiv(type, value); return; } if (a_glVertexP3uiv) a_glVertexP3uiv(type, value); }
INTERPOSE(glVertexP3uiv)
void glVertexP4ui(GLenum type, GLuint value) WEAKGL;
static void (*p_glVertexP4ui)(GLenum type, GLuint value);
static void (*a_glVertexP4ui)(GLenum type, GLuint value);
static void w_glVertexP4ui(GLenum type, GLuint value) { if (mglshim_active && p_glVertexP4ui) { p_glVertexP4ui(type, value); return; } if (a_glVertexP4ui) a_glVertexP4ui(type, value); }
INTERPOSE(glVertexP4ui)
void glVertexP4uiv(GLenum type, const GLuint *value) WEAKGL;
static void (*p_glVertexP4uiv)(GLenum type, const GLuint *value);
static void (*a_glVertexP4uiv)(GLenum type, const GLuint *value);
static void w_glVertexP4uiv(GLenum type, const GLuint *value) { if (mglshim_active && p_glVertexP4uiv) { p_glVertexP4uiv(type, value); return; } if (a_glVertexP4uiv) a_glVertexP4uiv(type, value); }
INTERPOSE(glVertexP4uiv)
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void (*a_glVertexPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (mglshim_active && p_glVertexPointer) { p_glVertexPointer(size, type, stride, pointer); return; } if (a_glVertexPointer) a_glVertexPointer(size, type, stride, pointer); }
INTERPOSE(glVertexPointer)
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
void glWindowPos2d(GLdouble x, GLdouble y) WEAKGL;
static void (*p_glWindowPos2d)(GLdouble x, GLdouble y);
static void (*a_glWindowPos2d)(GLdouble x, GLdouble y);
static void w_glWindowPos2d(GLdouble x, GLdouble y) { if (mglshim_active && p_glWindowPos2d) { p_glWindowPos2d(x, y); return; } if (a_glWindowPos2d) a_glWindowPos2d(x, y); }
INTERPOSE(glWindowPos2d)
void glWindowPos2dv(const GLdouble *v) WEAKGL;
static void (*p_glWindowPos2dv)(const GLdouble *v);
static void (*a_glWindowPos2dv)(const GLdouble *v);
static void w_glWindowPos2dv(const GLdouble *v) { if (mglshim_active && p_glWindowPos2dv) { p_glWindowPos2dv(v); return; } if (a_glWindowPos2dv) a_glWindowPos2dv(v); }
INTERPOSE(glWindowPos2dv)
void glWindowPos2f(GLfloat x, GLfloat y) WEAKGL;
static void (*p_glWindowPos2f)(GLfloat x, GLfloat y);
static void (*a_glWindowPos2f)(GLfloat x, GLfloat y);
static void w_glWindowPos2f(GLfloat x, GLfloat y) { if (mglshim_active && p_glWindowPos2f) { p_glWindowPos2f(x, y); return; } if (a_glWindowPos2f) a_glWindowPos2f(x, y); }
INTERPOSE(glWindowPos2f)
void glWindowPos2fv(const GLfloat *v) WEAKGL;
static void (*p_glWindowPos2fv)(const GLfloat *v);
static void (*a_glWindowPos2fv)(const GLfloat *v);
static void w_glWindowPos2fv(const GLfloat *v) { if (mglshim_active && p_glWindowPos2fv) { p_glWindowPos2fv(v); return; } if (a_glWindowPos2fv) a_glWindowPos2fv(v); }
INTERPOSE(glWindowPos2fv)
void glWindowPos2i(GLint x, GLint y) WEAKGL;
static void (*p_glWindowPos2i)(GLint x, GLint y);
static void (*a_glWindowPos2i)(GLint x, GLint y);
static void w_glWindowPos2i(GLint x, GLint y) { if (mglshim_active && p_glWindowPos2i) { p_glWindowPos2i(x, y); return; } if (a_glWindowPos2i) a_glWindowPos2i(x, y); }
INTERPOSE(glWindowPos2i)
void glWindowPos2iv(const GLint *v) WEAKGL;
static void (*p_glWindowPos2iv)(const GLint *v);
static void (*a_glWindowPos2iv)(const GLint *v);
static void w_glWindowPos2iv(const GLint *v) { if (mglshim_active && p_glWindowPos2iv) { p_glWindowPos2iv(v); return; } if (a_glWindowPos2iv) a_glWindowPos2iv(v); }
INTERPOSE(glWindowPos2iv)
void glWindowPos2s(GLshort x, GLshort y) WEAKGL;
static void (*p_glWindowPos2s)(GLshort x, GLshort y);
static void (*a_glWindowPos2s)(GLshort x, GLshort y);
static void w_glWindowPos2s(GLshort x, GLshort y) { if (mglshim_active && p_glWindowPos2s) { p_glWindowPos2s(x, y); return; } if (a_glWindowPos2s) a_glWindowPos2s(x, y); }
INTERPOSE(glWindowPos2s)
void glWindowPos2sv(const GLshort *v) WEAKGL;
static void (*p_glWindowPos2sv)(const GLshort *v);
static void (*a_glWindowPos2sv)(const GLshort *v);
static void w_glWindowPos2sv(const GLshort *v) { if (mglshim_active && p_glWindowPos2sv) { p_glWindowPos2sv(v); return; } if (a_glWindowPos2sv) a_glWindowPos2sv(v); }
INTERPOSE(glWindowPos2sv)
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glWindowPos3d)(GLdouble x, GLdouble y, GLdouble z);
static void (*a_glWindowPos3d)(GLdouble x, GLdouble y, GLdouble z);
static void w_glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) { if (mglshim_active && p_glWindowPos3d) { p_glWindowPos3d(x, y, z); return; } if (a_glWindowPos3d) a_glWindowPos3d(x, y, z); }
INTERPOSE(glWindowPos3d)
void glWindowPos3dv(const GLdouble *v) WEAKGL;
static void (*p_glWindowPos3dv)(const GLdouble *v);
static void (*a_glWindowPos3dv)(const GLdouble *v);
static void w_glWindowPos3dv(const GLdouble *v) { if (mglshim_active && p_glWindowPos3dv) { p_glWindowPos3dv(v); return; } if (a_glWindowPos3dv) a_glWindowPos3dv(v); }
INTERPOSE(glWindowPos3dv)
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glWindowPos3f)(GLfloat x, GLfloat y, GLfloat z);
static void (*a_glWindowPos3f)(GLfloat x, GLfloat y, GLfloat z);
static void w_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) { if (mglshim_active && p_glWindowPos3f) { p_glWindowPos3f(x, y, z); return; } if (a_glWindowPos3f) a_glWindowPos3f(x, y, z); }
INTERPOSE(glWindowPos3f)
void glWindowPos3fv(const GLfloat *v) WEAKGL;
static void (*p_glWindowPos3fv)(const GLfloat *v);
static void (*a_glWindowPos3fv)(const GLfloat *v);
static void w_glWindowPos3fv(const GLfloat *v) { if (mglshim_active && p_glWindowPos3fv) { p_glWindowPos3fv(v); return; } if (a_glWindowPos3fv) a_glWindowPos3fv(v); }
INTERPOSE(glWindowPos3fv)
void glWindowPos3i(GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glWindowPos3i)(GLint x, GLint y, GLint z);
static void (*a_glWindowPos3i)(GLint x, GLint y, GLint z);
static void w_glWindowPos3i(GLint x, GLint y, GLint z) { if (mglshim_active && p_glWindowPos3i) { p_glWindowPos3i(x, y, z); return; } if (a_glWindowPos3i) a_glWindowPos3i(x, y, z); }
INTERPOSE(glWindowPos3i)
void glWindowPos3iv(const GLint *v) WEAKGL;
static void (*p_glWindowPos3iv)(const GLint *v);
static void (*a_glWindowPos3iv)(const GLint *v);
static void w_glWindowPos3iv(const GLint *v) { if (mglshim_active && p_glWindowPos3iv) { p_glWindowPos3iv(v); return; } if (a_glWindowPos3iv) a_glWindowPos3iv(v); }
INTERPOSE(glWindowPos3iv)
void glWindowPos3s(GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glWindowPos3s)(GLshort x, GLshort y, GLshort z);
static void (*a_glWindowPos3s)(GLshort x, GLshort y, GLshort z);
static void w_glWindowPos3s(GLshort x, GLshort y, GLshort z) { if (mglshim_active && p_glWindowPos3s) { p_glWindowPos3s(x, y, z); return; } if (a_glWindowPos3s) a_glWindowPos3s(x, y, z); }
INTERPOSE(glWindowPos3s)
void glWindowPos3sv(const GLshort *v) WEAKGL;
static void (*p_glWindowPos3sv)(const GLshort *v);
static void (*a_glWindowPos3sv)(const GLshort *v);
static void w_glWindowPos3sv(const GLshort *v) { if (mglshim_active && p_glWindowPos3sv) { p_glWindowPos3sv(v); return; } if (a_glWindowPos3sv) a_glWindowPos3sv(v); }
INTERPOSE(glWindowPos3sv)

/* mgl = libmgl.dylib (impl do MGL); apple = libGL.dylib da Apple (fallback). Devolve quantas gl* o MGL tem. */
int mglshim_gl_init(void *mgl, void *apple) {
    int n = 0;
    *(void **)&p_glAccum = dlsym(mgl, "glAccum"); *(void **)&a_glAccum = apple ? dlsym(apple, "glAccum") : (void*)0; if (p_glAccum) n++;
    *(void **)&p_glActiveShaderProgram = dlsym(mgl, "glActiveShaderProgram"); *(void **)&a_glActiveShaderProgram = apple ? dlsym(apple, "glActiveShaderProgram") : (void*)0; if (p_glActiveShaderProgram) n++;
    *(void **)&p_glActiveTexture = dlsym(mgl, "glActiveTexture"); *(void **)&a_glActiveTexture = apple ? dlsym(apple, "glActiveTexture") : (void*)0; if (p_glActiveTexture) n++;
    *(void **)&p_glAlphaFunc = dlsym(mgl, "glAlphaFunc"); *(void **)&a_glAlphaFunc = apple ? dlsym(apple, "glAlphaFunc") : (void*)0; if (p_glAlphaFunc) n++;
    *(void **)&p_glAreTexturesResident = dlsym(mgl, "glAreTexturesResident"); *(void **)&a_glAreTexturesResident = apple ? dlsym(apple, "glAreTexturesResident") : (void*)0; if (p_glAreTexturesResident) n++;
    *(void **)&p_glArrayElement = dlsym(mgl, "glArrayElement"); *(void **)&a_glArrayElement = apple ? dlsym(apple, "glArrayElement") : (void*)0; if (p_glArrayElement) n++;
    *(void **)&p_glAttachShader = dlsym(mgl, "glAttachShader"); *(void **)&a_glAttachShader = apple ? dlsym(apple, "glAttachShader") : (void*)0; if (p_glAttachShader) n++;
    *(void **)&p_glBegin = dlsym(mgl, "glBegin"); *(void **)&a_glBegin = apple ? dlsym(apple, "glBegin") : (void*)0; if (p_glBegin) n++;
    *(void **)&p_glBeginConditionalRender = dlsym(mgl, "glBeginConditionalRender"); *(void **)&a_glBeginConditionalRender = apple ? dlsym(apple, "glBeginConditionalRender") : (void*)0; if (p_glBeginConditionalRender) n++;
    *(void **)&p_glBeginQuery = dlsym(mgl, "glBeginQuery"); *(void **)&a_glBeginQuery = apple ? dlsym(apple, "glBeginQuery") : (void*)0; if (p_glBeginQuery) n++;
    *(void **)&p_glBeginQueryIndexed = dlsym(mgl, "glBeginQueryIndexed"); *(void **)&a_glBeginQueryIndexed = apple ? dlsym(apple, "glBeginQueryIndexed") : (void*)0; if (p_glBeginQueryIndexed) n++;
    *(void **)&p_glBeginTransformFeedback = dlsym(mgl, "glBeginTransformFeedback"); *(void **)&a_glBeginTransformFeedback = apple ? dlsym(apple, "glBeginTransformFeedback") : (void*)0; if (p_glBeginTransformFeedback) n++;
    *(void **)&p_glBindAttribLocation = dlsym(mgl, "glBindAttribLocation"); *(void **)&a_glBindAttribLocation = apple ? dlsym(apple, "glBindAttribLocation") : (void*)0; if (p_glBindAttribLocation) n++;
    *(void **)&p_glBindBuffer = dlsym(mgl, "glBindBuffer"); *(void **)&a_glBindBuffer = apple ? dlsym(apple, "glBindBuffer") : (void*)0; if (p_glBindBuffer) n++;
    *(void **)&p_glBindBufferBase = dlsym(mgl, "glBindBufferBase"); *(void **)&a_glBindBufferBase = apple ? dlsym(apple, "glBindBufferBase") : (void*)0; if (p_glBindBufferBase) n++;
    *(void **)&p_glBindBufferRange = dlsym(mgl, "glBindBufferRange"); *(void **)&a_glBindBufferRange = apple ? dlsym(apple, "glBindBufferRange") : (void*)0; if (p_glBindBufferRange) n++;
    *(void **)&p_glBindBuffersBase = dlsym(mgl, "glBindBuffersBase"); *(void **)&a_glBindBuffersBase = apple ? dlsym(apple, "glBindBuffersBase") : (void*)0; if (p_glBindBuffersBase) n++;
    *(void **)&p_glBindBuffersRange = dlsym(mgl, "glBindBuffersRange"); *(void **)&a_glBindBuffersRange = apple ? dlsym(apple, "glBindBuffersRange") : (void*)0; if (p_glBindBuffersRange) n++;
    *(void **)&p_glBindFragDataLocation = dlsym(mgl, "glBindFragDataLocation"); *(void **)&a_glBindFragDataLocation = apple ? dlsym(apple, "glBindFragDataLocation") : (void*)0; if (p_glBindFragDataLocation) n++;
    *(void **)&p_glBindFragDataLocationIndexed = dlsym(mgl, "glBindFragDataLocationIndexed"); *(void **)&a_glBindFragDataLocationIndexed = apple ? dlsym(apple, "glBindFragDataLocationIndexed") : (void*)0; if (p_glBindFragDataLocationIndexed) n++;
    *(void **)&p_glBindFramebuffer = dlsym(mgl, "glBindFramebuffer"); *(void **)&a_glBindFramebuffer = apple ? dlsym(apple, "glBindFramebuffer") : (void*)0; if (p_glBindFramebuffer) n++;
    *(void **)&p_glBindImageTexture = dlsym(mgl, "glBindImageTexture"); *(void **)&a_glBindImageTexture = apple ? dlsym(apple, "glBindImageTexture") : (void*)0; if (p_glBindImageTexture) n++;
    *(void **)&p_glBindImageTextures = dlsym(mgl, "glBindImageTextures"); *(void **)&a_glBindImageTextures = apple ? dlsym(apple, "glBindImageTextures") : (void*)0; if (p_glBindImageTextures) n++;
    *(void **)&p_glBindProgramPipeline = dlsym(mgl, "glBindProgramPipeline"); *(void **)&a_glBindProgramPipeline = apple ? dlsym(apple, "glBindProgramPipeline") : (void*)0; if (p_glBindProgramPipeline) n++;
    *(void **)&p_glBindRenderbuffer = dlsym(mgl, "glBindRenderbuffer"); *(void **)&a_glBindRenderbuffer = apple ? dlsym(apple, "glBindRenderbuffer") : (void*)0; if (p_glBindRenderbuffer) n++;
    *(void **)&p_glBindSampler = dlsym(mgl, "glBindSampler"); *(void **)&a_glBindSampler = apple ? dlsym(apple, "glBindSampler") : (void*)0; if (p_glBindSampler) n++;
    *(void **)&p_glBindSamplers = dlsym(mgl, "glBindSamplers"); *(void **)&a_glBindSamplers = apple ? dlsym(apple, "glBindSamplers") : (void*)0; if (p_glBindSamplers) n++;
    *(void **)&p_glBindTexture = dlsym(mgl, "glBindTexture"); *(void **)&a_glBindTexture = apple ? dlsym(apple, "glBindTexture") : (void*)0; if (p_glBindTexture) n++;
    *(void **)&p_glBindTextureUnit = dlsym(mgl, "glBindTextureUnit"); *(void **)&a_glBindTextureUnit = apple ? dlsym(apple, "glBindTextureUnit") : (void*)0; if (p_glBindTextureUnit) n++;
    *(void **)&p_glBindTextures = dlsym(mgl, "glBindTextures"); *(void **)&a_glBindTextures = apple ? dlsym(apple, "glBindTextures") : (void*)0; if (p_glBindTextures) n++;
    *(void **)&p_glBindTransformFeedback = dlsym(mgl, "glBindTransformFeedback"); *(void **)&a_glBindTransformFeedback = apple ? dlsym(apple, "glBindTransformFeedback") : (void*)0; if (p_glBindTransformFeedback) n++;
    *(void **)&p_glBindVertexArray = dlsym(mgl, "glBindVertexArray"); *(void **)&a_glBindVertexArray = apple ? dlsym(apple, "glBindVertexArray") : (void*)0; if (p_glBindVertexArray) n++;
    *(void **)&p_glBindVertexBuffer = dlsym(mgl, "glBindVertexBuffer"); *(void **)&a_glBindVertexBuffer = apple ? dlsym(apple, "glBindVertexBuffer") : (void*)0; if (p_glBindVertexBuffer) n++;
    *(void **)&p_glBindVertexBuffers = dlsym(mgl, "glBindVertexBuffers"); *(void **)&a_glBindVertexBuffers = apple ? dlsym(apple, "glBindVertexBuffers") : (void*)0; if (p_glBindVertexBuffers) n++;
    *(void **)&p_glBitmap = dlsym(mgl, "glBitmap"); *(void **)&a_glBitmap = apple ? dlsym(apple, "glBitmap") : (void*)0; if (p_glBitmap) n++;
    *(void **)&p_glBlendColor = dlsym(mgl, "glBlendColor"); *(void **)&a_glBlendColor = apple ? dlsym(apple, "glBlendColor") : (void*)0; if (p_glBlendColor) n++;
    *(void **)&p_glBlendEquation = dlsym(mgl, "glBlendEquation"); *(void **)&a_glBlendEquation = apple ? dlsym(apple, "glBlendEquation") : (void*)0; if (p_glBlendEquation) n++;
    *(void **)&p_glBlendEquationSeparate = dlsym(mgl, "glBlendEquationSeparate"); *(void **)&a_glBlendEquationSeparate = apple ? dlsym(apple, "glBlendEquationSeparate") : (void*)0; if (p_glBlendEquationSeparate) n++;
    *(void **)&p_glBlendEquationSeparatei = dlsym(mgl, "glBlendEquationSeparatei"); *(void **)&a_glBlendEquationSeparatei = apple ? dlsym(apple, "glBlendEquationSeparatei") : (void*)0; if (p_glBlendEquationSeparatei) n++;
    *(void **)&p_glBlendEquationi = dlsym(mgl, "glBlendEquationi"); *(void **)&a_glBlendEquationi = apple ? dlsym(apple, "glBlendEquationi") : (void*)0; if (p_glBlendEquationi) n++;
    *(void **)&p_glBlendFunc = dlsym(mgl, "glBlendFunc"); *(void **)&a_glBlendFunc = apple ? dlsym(apple, "glBlendFunc") : (void*)0; if (p_glBlendFunc) n++;
    *(void **)&p_glBlendFuncSeparate = dlsym(mgl, "glBlendFuncSeparate"); *(void **)&a_glBlendFuncSeparate = apple ? dlsym(apple, "glBlendFuncSeparate") : (void*)0; if (p_glBlendFuncSeparate) n++;
    *(void **)&p_glBlendFuncSeparatei = dlsym(mgl, "glBlendFuncSeparatei"); *(void **)&a_glBlendFuncSeparatei = apple ? dlsym(apple, "glBlendFuncSeparatei") : (void*)0; if (p_glBlendFuncSeparatei) n++;
    *(void **)&p_glBlendFunci = dlsym(mgl, "glBlendFunci"); *(void **)&a_glBlendFunci = apple ? dlsym(apple, "glBlendFunci") : (void*)0; if (p_glBlendFunci) n++;
    *(void **)&p_glBlitFramebuffer = dlsym(mgl, "glBlitFramebuffer"); *(void **)&a_glBlitFramebuffer = apple ? dlsym(apple, "glBlitFramebuffer") : (void*)0; if (p_glBlitFramebuffer) n++;
    *(void **)&p_glBlitNamedFramebuffer = dlsym(mgl, "glBlitNamedFramebuffer"); *(void **)&a_glBlitNamedFramebuffer = apple ? dlsym(apple, "glBlitNamedFramebuffer") : (void*)0; if (p_glBlitNamedFramebuffer) n++;
    *(void **)&p_glBufferData = dlsym(mgl, "glBufferData"); *(void **)&a_glBufferData = apple ? dlsym(apple, "glBufferData") : (void*)0; if (p_glBufferData) n++;
    *(void **)&p_glBufferStorage = dlsym(mgl, "glBufferStorage"); *(void **)&a_glBufferStorage = apple ? dlsym(apple, "glBufferStorage") : (void*)0; if (p_glBufferStorage) n++;
    *(void **)&p_glBufferSubData = dlsym(mgl, "glBufferSubData"); *(void **)&a_glBufferSubData = apple ? dlsym(apple, "glBufferSubData") : (void*)0; if (p_glBufferSubData) n++;
    *(void **)&p_glCallList = dlsym(mgl, "glCallList"); *(void **)&a_glCallList = apple ? dlsym(apple, "glCallList") : (void*)0; if (p_glCallList) n++;
    *(void **)&p_glCallLists = dlsym(mgl, "glCallLists"); *(void **)&a_glCallLists = apple ? dlsym(apple, "glCallLists") : (void*)0; if (p_glCallLists) n++;
    *(void **)&p_glCheckFramebufferStatus = dlsym(mgl, "glCheckFramebufferStatus"); *(void **)&a_glCheckFramebufferStatus = apple ? dlsym(apple, "glCheckFramebufferStatus") : (void*)0; if (p_glCheckFramebufferStatus) n++;
    *(void **)&p_glCheckNamedFramebufferStatus = dlsym(mgl, "glCheckNamedFramebufferStatus"); *(void **)&a_glCheckNamedFramebufferStatus = apple ? dlsym(apple, "glCheckNamedFramebufferStatus") : (void*)0; if (p_glCheckNamedFramebufferStatus) n++;
    *(void **)&p_glClampColor = dlsym(mgl, "glClampColor"); *(void **)&a_glClampColor = apple ? dlsym(apple, "glClampColor") : (void*)0; if (p_glClampColor) n++;
    *(void **)&p_glClear = dlsym(mgl, "glClear"); *(void **)&a_glClear = apple ? dlsym(apple, "glClear") : (void*)0; if (p_glClear) n++;
    *(void **)&p_glClearAccum = dlsym(mgl, "glClearAccum"); *(void **)&a_glClearAccum = apple ? dlsym(apple, "glClearAccum") : (void*)0; if (p_glClearAccum) n++;
    *(void **)&p_glClearBufferData = dlsym(mgl, "glClearBufferData"); *(void **)&a_glClearBufferData = apple ? dlsym(apple, "glClearBufferData") : (void*)0; if (p_glClearBufferData) n++;
    *(void **)&p_glClearBufferSubData = dlsym(mgl, "glClearBufferSubData"); *(void **)&a_glClearBufferSubData = apple ? dlsym(apple, "glClearBufferSubData") : (void*)0; if (p_glClearBufferSubData) n++;
    *(void **)&p_glClearBufferfi = dlsym(mgl, "glClearBufferfi"); *(void **)&a_glClearBufferfi = apple ? dlsym(apple, "glClearBufferfi") : (void*)0; if (p_glClearBufferfi) n++;
    *(void **)&p_glClearBufferfv = dlsym(mgl, "glClearBufferfv"); *(void **)&a_glClearBufferfv = apple ? dlsym(apple, "glClearBufferfv") : (void*)0; if (p_glClearBufferfv) n++;
    *(void **)&p_glClearBufferiv = dlsym(mgl, "glClearBufferiv"); *(void **)&a_glClearBufferiv = apple ? dlsym(apple, "glClearBufferiv") : (void*)0; if (p_glClearBufferiv) n++;
    *(void **)&p_glClearBufferuiv = dlsym(mgl, "glClearBufferuiv"); *(void **)&a_glClearBufferuiv = apple ? dlsym(apple, "glClearBufferuiv") : (void*)0; if (p_glClearBufferuiv) n++;
    *(void **)&p_glClearColor = dlsym(mgl, "glClearColor"); *(void **)&a_glClearColor = apple ? dlsym(apple, "glClearColor") : (void*)0; if (p_glClearColor) n++;
    *(void **)&p_glClearDepth = dlsym(mgl, "glClearDepth"); *(void **)&a_glClearDepth = apple ? dlsym(apple, "glClearDepth") : (void*)0; if (p_glClearDepth) n++;
    *(void **)&p_glClearDepthf = dlsym(mgl, "glClearDepthf"); *(void **)&a_glClearDepthf = apple ? dlsym(apple, "glClearDepthf") : (void*)0; if (p_glClearDepthf) n++;
    *(void **)&p_glClearIndex = dlsym(mgl, "glClearIndex"); *(void **)&a_glClearIndex = apple ? dlsym(apple, "glClearIndex") : (void*)0; if (p_glClearIndex) n++;
    *(void **)&p_glClearNamedBufferData = dlsym(mgl, "glClearNamedBufferData"); *(void **)&a_glClearNamedBufferData = apple ? dlsym(apple, "glClearNamedBufferData") : (void*)0; if (p_glClearNamedBufferData) n++;
    *(void **)&p_glClearNamedBufferSubData = dlsym(mgl, "glClearNamedBufferSubData"); *(void **)&a_glClearNamedBufferSubData = apple ? dlsym(apple, "glClearNamedBufferSubData") : (void*)0; if (p_glClearNamedBufferSubData) n++;
    *(void **)&p_glClearNamedFramebufferfi = dlsym(mgl, "glClearNamedFramebufferfi"); *(void **)&a_glClearNamedFramebufferfi = apple ? dlsym(apple, "glClearNamedFramebufferfi") : (void*)0; if (p_glClearNamedFramebufferfi) n++;
    *(void **)&p_glClearNamedFramebufferfv = dlsym(mgl, "glClearNamedFramebufferfv"); *(void **)&a_glClearNamedFramebufferfv = apple ? dlsym(apple, "glClearNamedFramebufferfv") : (void*)0; if (p_glClearNamedFramebufferfv) n++;
    *(void **)&p_glClearNamedFramebufferiv = dlsym(mgl, "glClearNamedFramebufferiv"); *(void **)&a_glClearNamedFramebufferiv = apple ? dlsym(apple, "glClearNamedFramebufferiv") : (void*)0; if (p_glClearNamedFramebufferiv) n++;
    *(void **)&p_glClearNamedFramebufferuiv = dlsym(mgl, "glClearNamedFramebufferuiv"); *(void **)&a_glClearNamedFramebufferuiv = apple ? dlsym(apple, "glClearNamedFramebufferuiv") : (void*)0; if (p_glClearNamedFramebufferuiv) n++;
    *(void **)&p_glClearStencil = dlsym(mgl, "glClearStencil"); *(void **)&a_glClearStencil = apple ? dlsym(apple, "glClearStencil") : (void*)0; if (p_glClearStencil) n++;
    *(void **)&p_glClearTexImage = dlsym(mgl, "glClearTexImage"); *(void **)&a_glClearTexImage = apple ? dlsym(apple, "glClearTexImage") : (void*)0; if (p_glClearTexImage) n++;
    *(void **)&p_glClearTexSubImage = dlsym(mgl, "glClearTexSubImage"); *(void **)&a_glClearTexSubImage = apple ? dlsym(apple, "glClearTexSubImage") : (void*)0; if (p_glClearTexSubImage) n++;
    *(void **)&p_glClientActiveTexture = dlsym(mgl, "glClientActiveTexture"); *(void **)&a_glClientActiveTexture = apple ? dlsym(apple, "glClientActiveTexture") : (void*)0; if (p_glClientActiveTexture) n++;
    *(void **)&p_glClientWaitSync = dlsym(mgl, "glClientWaitSync"); *(void **)&a_glClientWaitSync = apple ? dlsym(apple, "glClientWaitSync") : (void*)0; if (p_glClientWaitSync) n++;
    *(void **)&p_glClipControl = dlsym(mgl, "glClipControl"); *(void **)&a_glClipControl = apple ? dlsym(apple, "glClipControl") : (void*)0; if (p_glClipControl) n++;
    *(void **)&p_glClipPlane = dlsym(mgl, "glClipPlane"); *(void **)&a_glClipPlane = apple ? dlsym(apple, "glClipPlane") : (void*)0; if (p_glClipPlane) n++;
    *(void **)&p_glColor3b = dlsym(mgl, "glColor3b"); *(void **)&a_glColor3b = apple ? dlsym(apple, "glColor3b") : (void*)0; if (p_glColor3b) n++;
    *(void **)&p_glColor3bv = dlsym(mgl, "glColor3bv"); *(void **)&a_glColor3bv = apple ? dlsym(apple, "glColor3bv") : (void*)0; if (p_glColor3bv) n++;
    *(void **)&p_glColor3d = dlsym(mgl, "glColor3d"); *(void **)&a_glColor3d = apple ? dlsym(apple, "glColor3d") : (void*)0; if (p_glColor3d) n++;
    *(void **)&p_glColor3dv = dlsym(mgl, "glColor3dv"); *(void **)&a_glColor3dv = apple ? dlsym(apple, "glColor3dv") : (void*)0; if (p_glColor3dv) n++;
    *(void **)&p_glColor3f = dlsym(mgl, "glColor3f"); *(void **)&a_glColor3f = apple ? dlsym(apple, "glColor3f") : (void*)0; if (p_glColor3f) n++;
    *(void **)&p_glColor3fv = dlsym(mgl, "glColor3fv"); *(void **)&a_glColor3fv = apple ? dlsym(apple, "glColor3fv") : (void*)0; if (p_glColor3fv) n++;
    *(void **)&p_glColor3i = dlsym(mgl, "glColor3i"); *(void **)&a_glColor3i = apple ? dlsym(apple, "glColor3i") : (void*)0; if (p_glColor3i) n++;
    *(void **)&p_glColor3iv = dlsym(mgl, "glColor3iv"); *(void **)&a_glColor3iv = apple ? dlsym(apple, "glColor3iv") : (void*)0; if (p_glColor3iv) n++;
    *(void **)&p_glColor3s = dlsym(mgl, "glColor3s"); *(void **)&a_glColor3s = apple ? dlsym(apple, "glColor3s") : (void*)0; if (p_glColor3s) n++;
    *(void **)&p_glColor3sv = dlsym(mgl, "glColor3sv"); *(void **)&a_glColor3sv = apple ? dlsym(apple, "glColor3sv") : (void*)0; if (p_glColor3sv) n++;
    *(void **)&p_glColor3ub = dlsym(mgl, "glColor3ub"); *(void **)&a_glColor3ub = apple ? dlsym(apple, "glColor3ub") : (void*)0; if (p_glColor3ub) n++;
    *(void **)&p_glColor3ubv = dlsym(mgl, "glColor3ubv"); *(void **)&a_glColor3ubv = apple ? dlsym(apple, "glColor3ubv") : (void*)0; if (p_glColor3ubv) n++;
    *(void **)&p_glColor3ui = dlsym(mgl, "glColor3ui"); *(void **)&a_glColor3ui = apple ? dlsym(apple, "glColor3ui") : (void*)0; if (p_glColor3ui) n++;
    *(void **)&p_glColor3uiv = dlsym(mgl, "glColor3uiv"); *(void **)&a_glColor3uiv = apple ? dlsym(apple, "glColor3uiv") : (void*)0; if (p_glColor3uiv) n++;
    *(void **)&p_glColor3us = dlsym(mgl, "glColor3us"); *(void **)&a_glColor3us = apple ? dlsym(apple, "glColor3us") : (void*)0; if (p_glColor3us) n++;
    *(void **)&p_glColor3usv = dlsym(mgl, "glColor3usv"); *(void **)&a_glColor3usv = apple ? dlsym(apple, "glColor3usv") : (void*)0; if (p_glColor3usv) n++;
    *(void **)&p_glColor4b = dlsym(mgl, "glColor4b"); *(void **)&a_glColor4b = apple ? dlsym(apple, "glColor4b") : (void*)0; if (p_glColor4b) n++;
    *(void **)&p_glColor4bv = dlsym(mgl, "glColor4bv"); *(void **)&a_glColor4bv = apple ? dlsym(apple, "glColor4bv") : (void*)0; if (p_glColor4bv) n++;
    *(void **)&p_glColor4d = dlsym(mgl, "glColor4d"); *(void **)&a_glColor4d = apple ? dlsym(apple, "glColor4d") : (void*)0; if (p_glColor4d) n++;
    *(void **)&p_glColor4dv = dlsym(mgl, "glColor4dv"); *(void **)&a_glColor4dv = apple ? dlsym(apple, "glColor4dv") : (void*)0; if (p_glColor4dv) n++;
    *(void **)&p_glColor4f = dlsym(mgl, "glColor4f"); *(void **)&a_glColor4f = apple ? dlsym(apple, "glColor4f") : (void*)0; if (p_glColor4f) n++;
    *(void **)&p_glColor4fv = dlsym(mgl, "glColor4fv"); *(void **)&a_glColor4fv = apple ? dlsym(apple, "glColor4fv") : (void*)0; if (p_glColor4fv) n++;
    *(void **)&p_glColor4i = dlsym(mgl, "glColor4i"); *(void **)&a_glColor4i = apple ? dlsym(apple, "glColor4i") : (void*)0; if (p_glColor4i) n++;
    *(void **)&p_glColor4iv = dlsym(mgl, "glColor4iv"); *(void **)&a_glColor4iv = apple ? dlsym(apple, "glColor4iv") : (void*)0; if (p_glColor4iv) n++;
    *(void **)&p_glColor4s = dlsym(mgl, "glColor4s"); *(void **)&a_glColor4s = apple ? dlsym(apple, "glColor4s") : (void*)0; if (p_glColor4s) n++;
    *(void **)&p_glColor4sv = dlsym(mgl, "glColor4sv"); *(void **)&a_glColor4sv = apple ? dlsym(apple, "glColor4sv") : (void*)0; if (p_glColor4sv) n++;
    *(void **)&p_glColor4ub = dlsym(mgl, "glColor4ub"); *(void **)&a_glColor4ub = apple ? dlsym(apple, "glColor4ub") : (void*)0; if (p_glColor4ub) n++;
    *(void **)&p_glColor4ubv = dlsym(mgl, "glColor4ubv"); *(void **)&a_glColor4ubv = apple ? dlsym(apple, "glColor4ubv") : (void*)0; if (p_glColor4ubv) n++;
    *(void **)&p_glColor4ui = dlsym(mgl, "glColor4ui"); *(void **)&a_glColor4ui = apple ? dlsym(apple, "glColor4ui") : (void*)0; if (p_glColor4ui) n++;
    *(void **)&p_glColor4uiv = dlsym(mgl, "glColor4uiv"); *(void **)&a_glColor4uiv = apple ? dlsym(apple, "glColor4uiv") : (void*)0; if (p_glColor4uiv) n++;
    *(void **)&p_glColor4us = dlsym(mgl, "glColor4us"); *(void **)&a_glColor4us = apple ? dlsym(apple, "glColor4us") : (void*)0; if (p_glColor4us) n++;
    *(void **)&p_glColor4usv = dlsym(mgl, "glColor4usv"); *(void **)&a_glColor4usv = apple ? dlsym(apple, "glColor4usv") : (void*)0; if (p_glColor4usv) n++;
    *(void **)&p_glColorMask = dlsym(mgl, "glColorMask"); *(void **)&a_glColorMask = apple ? dlsym(apple, "glColorMask") : (void*)0; if (p_glColorMask) n++;
    *(void **)&p_glColorMaski = dlsym(mgl, "glColorMaski"); *(void **)&a_glColorMaski = apple ? dlsym(apple, "glColorMaski") : (void*)0; if (p_glColorMaski) n++;
    *(void **)&p_glColorMaterial = dlsym(mgl, "glColorMaterial"); *(void **)&a_glColorMaterial = apple ? dlsym(apple, "glColorMaterial") : (void*)0; if (p_glColorMaterial) n++;
    *(void **)&p_glColorP3ui = dlsym(mgl, "glColorP3ui"); *(void **)&a_glColorP3ui = apple ? dlsym(apple, "glColorP3ui") : (void*)0; if (p_glColorP3ui) n++;
    *(void **)&p_glColorP3uiv = dlsym(mgl, "glColorP3uiv"); *(void **)&a_glColorP3uiv = apple ? dlsym(apple, "glColorP3uiv") : (void*)0; if (p_glColorP3uiv) n++;
    *(void **)&p_glColorP4ui = dlsym(mgl, "glColorP4ui"); *(void **)&a_glColorP4ui = apple ? dlsym(apple, "glColorP4ui") : (void*)0; if (p_glColorP4ui) n++;
    *(void **)&p_glColorP4uiv = dlsym(mgl, "glColorP4uiv"); *(void **)&a_glColorP4uiv = apple ? dlsym(apple, "glColorP4uiv") : (void*)0; if (p_glColorP4uiv) n++;
    *(void **)&p_glColorPointer = dlsym(mgl, "glColorPointer"); *(void **)&a_glColorPointer = apple ? dlsym(apple, "glColorPointer") : (void*)0; if (p_glColorPointer) n++;
    *(void **)&p_glCompileShader = dlsym(mgl, "glCompileShader"); *(void **)&a_glCompileShader = apple ? dlsym(apple, "glCompileShader") : (void*)0; if (p_glCompileShader) n++;
    *(void **)&p_glCompressedTexImage1D = dlsym(mgl, "glCompressedTexImage1D"); *(void **)&a_glCompressedTexImage1D = apple ? dlsym(apple, "glCompressedTexImage1D") : (void*)0; if (p_glCompressedTexImage1D) n++;
    *(void **)&p_glCompressedTexImage2D = dlsym(mgl, "glCompressedTexImage2D"); *(void **)&a_glCompressedTexImage2D = apple ? dlsym(apple, "glCompressedTexImage2D") : (void*)0; if (p_glCompressedTexImage2D) n++;
    *(void **)&p_glCompressedTexImage3D = dlsym(mgl, "glCompressedTexImage3D"); *(void **)&a_glCompressedTexImage3D = apple ? dlsym(apple, "glCompressedTexImage3D") : (void*)0; if (p_glCompressedTexImage3D) n++;
    *(void **)&p_glCompressedTexSubImage1D = dlsym(mgl, "glCompressedTexSubImage1D"); *(void **)&a_glCompressedTexSubImage1D = apple ? dlsym(apple, "glCompressedTexSubImage1D") : (void*)0; if (p_glCompressedTexSubImage1D) n++;
    *(void **)&p_glCompressedTexSubImage2D = dlsym(mgl, "glCompressedTexSubImage2D"); *(void **)&a_glCompressedTexSubImage2D = apple ? dlsym(apple, "glCompressedTexSubImage2D") : (void*)0; if (p_glCompressedTexSubImage2D) n++;
    *(void **)&p_glCompressedTexSubImage3D = dlsym(mgl, "glCompressedTexSubImage3D"); *(void **)&a_glCompressedTexSubImage3D = apple ? dlsym(apple, "glCompressedTexSubImage3D") : (void*)0; if (p_glCompressedTexSubImage3D) n++;
    *(void **)&p_glCompressedTextureSubImage1D = dlsym(mgl, "glCompressedTextureSubImage1D"); *(void **)&a_glCompressedTextureSubImage1D = apple ? dlsym(apple, "glCompressedTextureSubImage1D") : (void*)0; if (p_glCompressedTextureSubImage1D) n++;
    *(void **)&p_glCompressedTextureSubImage2D = dlsym(mgl, "glCompressedTextureSubImage2D"); *(void **)&a_glCompressedTextureSubImage2D = apple ? dlsym(apple, "glCompressedTextureSubImage2D") : (void*)0; if (p_glCompressedTextureSubImage2D) n++;
    *(void **)&p_glCompressedTextureSubImage3D = dlsym(mgl, "glCompressedTextureSubImage3D"); *(void **)&a_glCompressedTextureSubImage3D = apple ? dlsym(apple, "glCompressedTextureSubImage3D") : (void*)0; if (p_glCompressedTextureSubImage3D) n++;
    *(void **)&p_glCopyBufferSubData = dlsym(mgl, "glCopyBufferSubData"); *(void **)&a_glCopyBufferSubData = apple ? dlsym(apple, "glCopyBufferSubData") : (void*)0; if (p_glCopyBufferSubData) n++;
    *(void **)&p_glCopyImageSubData = dlsym(mgl, "glCopyImageSubData"); *(void **)&a_glCopyImageSubData = apple ? dlsym(apple, "glCopyImageSubData") : (void*)0; if (p_glCopyImageSubData) n++;
    *(void **)&p_glCopyNamedBufferSubData = dlsym(mgl, "glCopyNamedBufferSubData"); *(void **)&a_glCopyNamedBufferSubData = apple ? dlsym(apple, "glCopyNamedBufferSubData") : (void*)0; if (p_glCopyNamedBufferSubData) n++;
    *(void **)&p_glCopyPixels = dlsym(mgl, "glCopyPixels"); *(void **)&a_glCopyPixels = apple ? dlsym(apple, "glCopyPixels") : (void*)0; if (p_glCopyPixels) n++;
    *(void **)&p_glCopyTexImage1D = dlsym(mgl, "glCopyTexImage1D"); *(void **)&a_glCopyTexImage1D = apple ? dlsym(apple, "glCopyTexImage1D") : (void*)0; if (p_glCopyTexImage1D) n++;
    *(void **)&p_glCopyTexImage2D = dlsym(mgl, "glCopyTexImage2D"); *(void **)&a_glCopyTexImage2D = apple ? dlsym(apple, "glCopyTexImage2D") : (void*)0; if (p_glCopyTexImage2D) n++;
    *(void **)&p_glCopyTexSubImage1D = dlsym(mgl, "glCopyTexSubImage1D"); *(void **)&a_glCopyTexSubImage1D = apple ? dlsym(apple, "glCopyTexSubImage1D") : (void*)0; if (p_glCopyTexSubImage1D) n++;
    *(void **)&p_glCopyTexSubImage2D = dlsym(mgl, "glCopyTexSubImage2D"); *(void **)&a_glCopyTexSubImage2D = apple ? dlsym(apple, "glCopyTexSubImage2D") : (void*)0; if (p_glCopyTexSubImage2D) n++;
    *(void **)&p_glCopyTexSubImage3D = dlsym(mgl, "glCopyTexSubImage3D"); *(void **)&a_glCopyTexSubImage3D = apple ? dlsym(apple, "glCopyTexSubImage3D") : (void*)0; if (p_glCopyTexSubImage3D) n++;
    *(void **)&p_glCopyTextureSubImage1D = dlsym(mgl, "glCopyTextureSubImage1D"); *(void **)&a_glCopyTextureSubImage1D = apple ? dlsym(apple, "glCopyTextureSubImage1D") : (void*)0; if (p_glCopyTextureSubImage1D) n++;
    *(void **)&p_glCopyTextureSubImage2D = dlsym(mgl, "glCopyTextureSubImage2D"); *(void **)&a_glCopyTextureSubImage2D = apple ? dlsym(apple, "glCopyTextureSubImage2D") : (void*)0; if (p_glCopyTextureSubImage2D) n++;
    *(void **)&p_glCopyTextureSubImage3D = dlsym(mgl, "glCopyTextureSubImage3D"); *(void **)&a_glCopyTextureSubImage3D = apple ? dlsym(apple, "glCopyTextureSubImage3D") : (void*)0; if (p_glCopyTextureSubImage3D) n++;
    *(void **)&p_glCreateBuffers = dlsym(mgl, "glCreateBuffers"); *(void **)&a_glCreateBuffers = apple ? dlsym(apple, "glCreateBuffers") : (void*)0; if (p_glCreateBuffers) n++;
    *(void **)&p_glCreateFramebuffers = dlsym(mgl, "glCreateFramebuffers"); *(void **)&a_glCreateFramebuffers = apple ? dlsym(apple, "glCreateFramebuffers") : (void*)0; if (p_glCreateFramebuffers) n++;
    *(void **)&p_glCreateProgram = dlsym(mgl, "glCreateProgram"); *(void **)&a_glCreateProgram = apple ? dlsym(apple, "glCreateProgram") : (void*)0; if (p_glCreateProgram) n++;
    *(void **)&p_glCreateProgramPipelines = dlsym(mgl, "glCreateProgramPipelines"); *(void **)&a_glCreateProgramPipelines = apple ? dlsym(apple, "glCreateProgramPipelines") : (void*)0; if (p_glCreateProgramPipelines) n++;
    *(void **)&p_glCreateQueries = dlsym(mgl, "glCreateQueries"); *(void **)&a_glCreateQueries = apple ? dlsym(apple, "glCreateQueries") : (void*)0; if (p_glCreateQueries) n++;
    *(void **)&p_glCreateRenderbuffers = dlsym(mgl, "glCreateRenderbuffers"); *(void **)&a_glCreateRenderbuffers = apple ? dlsym(apple, "glCreateRenderbuffers") : (void*)0; if (p_glCreateRenderbuffers) n++;
    *(void **)&p_glCreateSamplers = dlsym(mgl, "glCreateSamplers"); *(void **)&a_glCreateSamplers = apple ? dlsym(apple, "glCreateSamplers") : (void*)0; if (p_glCreateSamplers) n++;
    *(void **)&p_glCreateShader = dlsym(mgl, "glCreateShader"); *(void **)&a_glCreateShader = apple ? dlsym(apple, "glCreateShader") : (void*)0; if (p_glCreateShader) n++;
    *(void **)&p_glCreateShaderProgramv = dlsym(mgl, "glCreateShaderProgramv"); *(void **)&a_glCreateShaderProgramv = apple ? dlsym(apple, "glCreateShaderProgramv") : (void*)0; if (p_glCreateShaderProgramv) n++;
    *(void **)&p_glCreateTextures = dlsym(mgl, "glCreateTextures"); *(void **)&a_glCreateTextures = apple ? dlsym(apple, "glCreateTextures") : (void*)0; if (p_glCreateTextures) n++;
    *(void **)&p_glCreateTransformFeedbacks = dlsym(mgl, "glCreateTransformFeedbacks"); *(void **)&a_glCreateTransformFeedbacks = apple ? dlsym(apple, "glCreateTransformFeedbacks") : (void*)0; if (p_glCreateTransformFeedbacks) n++;
    *(void **)&p_glCreateVertexArrays = dlsym(mgl, "glCreateVertexArrays"); *(void **)&a_glCreateVertexArrays = apple ? dlsym(apple, "glCreateVertexArrays") : (void*)0; if (p_glCreateVertexArrays) n++;
    *(void **)&p_glCullFace = dlsym(mgl, "glCullFace"); *(void **)&a_glCullFace = apple ? dlsym(apple, "glCullFace") : (void*)0; if (p_glCullFace) n++;
    *(void **)&p_glDebugMessageCallback = dlsym(mgl, "glDebugMessageCallback"); *(void **)&a_glDebugMessageCallback = apple ? dlsym(apple, "glDebugMessageCallback") : (void*)0; if (p_glDebugMessageCallback) n++;
    *(void **)&p_glDebugMessageControl = dlsym(mgl, "glDebugMessageControl"); *(void **)&a_glDebugMessageControl = apple ? dlsym(apple, "glDebugMessageControl") : (void*)0; if (p_glDebugMessageControl) n++;
    *(void **)&p_glDebugMessageInsert = dlsym(mgl, "glDebugMessageInsert"); *(void **)&a_glDebugMessageInsert = apple ? dlsym(apple, "glDebugMessageInsert") : (void*)0; if (p_glDebugMessageInsert) n++;
    *(void **)&p_glDeleteBuffers = dlsym(mgl, "glDeleteBuffers"); *(void **)&a_glDeleteBuffers = apple ? dlsym(apple, "glDeleteBuffers") : (void*)0; if (p_glDeleteBuffers) n++;
    *(void **)&p_glDeleteFramebuffers = dlsym(mgl, "glDeleteFramebuffers"); *(void **)&a_glDeleteFramebuffers = apple ? dlsym(apple, "glDeleteFramebuffers") : (void*)0; if (p_glDeleteFramebuffers) n++;
    *(void **)&p_glDeleteLists = dlsym(mgl, "glDeleteLists"); *(void **)&a_glDeleteLists = apple ? dlsym(apple, "glDeleteLists") : (void*)0; if (p_glDeleteLists) n++;
    *(void **)&p_glDeleteProgram = dlsym(mgl, "glDeleteProgram"); *(void **)&a_glDeleteProgram = apple ? dlsym(apple, "glDeleteProgram") : (void*)0; if (p_glDeleteProgram) n++;
    *(void **)&p_glDeleteProgramPipelines = dlsym(mgl, "glDeleteProgramPipelines"); *(void **)&a_glDeleteProgramPipelines = apple ? dlsym(apple, "glDeleteProgramPipelines") : (void*)0; if (p_glDeleteProgramPipelines) n++;
    *(void **)&p_glDeleteQueries = dlsym(mgl, "glDeleteQueries"); *(void **)&a_glDeleteQueries = apple ? dlsym(apple, "glDeleteQueries") : (void*)0; if (p_glDeleteQueries) n++;
    *(void **)&p_glDeleteRenderbuffers = dlsym(mgl, "glDeleteRenderbuffers"); *(void **)&a_glDeleteRenderbuffers = apple ? dlsym(apple, "glDeleteRenderbuffers") : (void*)0; if (p_glDeleteRenderbuffers) n++;
    *(void **)&p_glDeleteSamplers = dlsym(mgl, "glDeleteSamplers"); *(void **)&a_glDeleteSamplers = apple ? dlsym(apple, "glDeleteSamplers") : (void*)0; if (p_glDeleteSamplers) n++;
    *(void **)&p_glDeleteShader = dlsym(mgl, "glDeleteShader"); *(void **)&a_glDeleteShader = apple ? dlsym(apple, "glDeleteShader") : (void*)0; if (p_glDeleteShader) n++;
    *(void **)&p_glDeleteSync = dlsym(mgl, "glDeleteSync"); *(void **)&a_glDeleteSync = apple ? dlsym(apple, "glDeleteSync") : (void*)0; if (p_glDeleteSync) n++;
    *(void **)&p_glDeleteTextures = dlsym(mgl, "glDeleteTextures"); *(void **)&a_glDeleteTextures = apple ? dlsym(apple, "glDeleteTextures") : (void*)0; if (p_glDeleteTextures) n++;
    *(void **)&p_glDeleteTransformFeedbacks = dlsym(mgl, "glDeleteTransformFeedbacks"); *(void **)&a_glDeleteTransformFeedbacks = apple ? dlsym(apple, "glDeleteTransformFeedbacks") : (void*)0; if (p_glDeleteTransformFeedbacks) n++;
    *(void **)&p_glDeleteVertexArrays = dlsym(mgl, "glDeleteVertexArrays"); *(void **)&a_glDeleteVertexArrays = apple ? dlsym(apple, "glDeleteVertexArrays") : (void*)0; if (p_glDeleteVertexArrays) n++;
    *(void **)&p_glDepthFunc = dlsym(mgl, "glDepthFunc"); *(void **)&a_glDepthFunc = apple ? dlsym(apple, "glDepthFunc") : (void*)0; if (p_glDepthFunc) n++;
    *(void **)&p_glDepthMask = dlsym(mgl, "glDepthMask"); *(void **)&a_glDepthMask = apple ? dlsym(apple, "glDepthMask") : (void*)0; if (p_glDepthMask) n++;
    *(void **)&p_glDepthRange = dlsym(mgl, "glDepthRange"); *(void **)&a_glDepthRange = apple ? dlsym(apple, "glDepthRange") : (void*)0; if (p_glDepthRange) n++;
    *(void **)&p_glDepthRangeArrayv = dlsym(mgl, "glDepthRangeArrayv"); *(void **)&a_glDepthRangeArrayv = apple ? dlsym(apple, "glDepthRangeArrayv") : (void*)0; if (p_glDepthRangeArrayv) n++;
    *(void **)&p_glDepthRangeIndexed = dlsym(mgl, "glDepthRangeIndexed"); *(void **)&a_glDepthRangeIndexed = apple ? dlsym(apple, "glDepthRangeIndexed") : (void*)0; if (p_glDepthRangeIndexed) n++;
    *(void **)&p_glDepthRangef = dlsym(mgl, "glDepthRangef"); *(void **)&a_glDepthRangef = apple ? dlsym(apple, "glDepthRangef") : (void*)0; if (p_glDepthRangef) n++;
    *(void **)&p_glDetachShader = dlsym(mgl, "glDetachShader"); *(void **)&a_glDetachShader = apple ? dlsym(apple, "glDetachShader") : (void*)0; if (p_glDetachShader) n++;
    *(void **)&p_glDisable = dlsym(mgl, "glDisable"); *(void **)&a_glDisable = apple ? dlsym(apple, "glDisable") : (void*)0; if (p_glDisable) n++;
    *(void **)&p_glDisableClientState = dlsym(mgl, "glDisableClientState"); *(void **)&a_glDisableClientState = apple ? dlsym(apple, "glDisableClientState") : (void*)0; if (p_glDisableClientState) n++;
    *(void **)&p_glDisableVertexArrayAttrib = dlsym(mgl, "glDisableVertexArrayAttrib"); *(void **)&a_glDisableVertexArrayAttrib = apple ? dlsym(apple, "glDisableVertexArrayAttrib") : (void*)0; if (p_glDisableVertexArrayAttrib) n++;
    *(void **)&p_glDisableVertexAttribArray = dlsym(mgl, "glDisableVertexAttribArray"); *(void **)&a_glDisableVertexAttribArray = apple ? dlsym(apple, "glDisableVertexAttribArray") : (void*)0; if (p_glDisableVertexAttribArray) n++;
    *(void **)&p_glDisablei = dlsym(mgl, "glDisablei"); *(void **)&a_glDisablei = apple ? dlsym(apple, "glDisablei") : (void*)0; if (p_glDisablei) n++;
    *(void **)&p_glDispatchCompute = dlsym(mgl, "glDispatchCompute"); *(void **)&a_glDispatchCompute = apple ? dlsym(apple, "glDispatchCompute") : (void*)0; if (p_glDispatchCompute) n++;
    *(void **)&p_glDispatchComputeIndirect = dlsym(mgl, "glDispatchComputeIndirect"); *(void **)&a_glDispatchComputeIndirect = apple ? dlsym(apple, "glDispatchComputeIndirect") : (void*)0; if (p_glDispatchComputeIndirect) n++;
    *(void **)&p_glDrawArrays = dlsym(mgl, "glDrawArrays"); *(void **)&a_glDrawArrays = apple ? dlsym(apple, "glDrawArrays") : (void*)0; if (p_glDrawArrays) n++;
    *(void **)&p_glDrawArraysIndirect = dlsym(mgl, "glDrawArraysIndirect"); *(void **)&a_glDrawArraysIndirect = apple ? dlsym(apple, "glDrawArraysIndirect") : (void*)0; if (p_glDrawArraysIndirect) n++;
    *(void **)&p_glDrawArraysInstanced = dlsym(mgl, "glDrawArraysInstanced"); *(void **)&a_glDrawArraysInstanced = apple ? dlsym(apple, "glDrawArraysInstanced") : (void*)0; if (p_glDrawArraysInstanced) n++;
    *(void **)&p_glDrawArraysInstancedBaseInstance = dlsym(mgl, "glDrawArraysInstancedBaseInstance"); *(void **)&a_glDrawArraysInstancedBaseInstance = apple ? dlsym(apple, "glDrawArraysInstancedBaseInstance") : (void*)0; if (p_glDrawArraysInstancedBaseInstance) n++;
    *(void **)&p_glDrawBuffer = dlsym(mgl, "glDrawBuffer"); *(void **)&a_glDrawBuffer = apple ? dlsym(apple, "glDrawBuffer") : (void*)0; if (p_glDrawBuffer) n++;
    *(void **)&p_glDrawBuffers = dlsym(mgl, "glDrawBuffers"); *(void **)&a_glDrawBuffers = apple ? dlsym(apple, "glDrawBuffers") : (void*)0; if (p_glDrawBuffers) n++;
    *(void **)&p_glDrawElements = dlsym(mgl, "glDrawElements"); *(void **)&a_glDrawElements = apple ? dlsym(apple, "glDrawElements") : (void*)0; if (p_glDrawElements) n++;
    *(void **)&p_glDrawElementsBaseVertex = dlsym(mgl, "glDrawElementsBaseVertex"); *(void **)&a_glDrawElementsBaseVertex = apple ? dlsym(apple, "glDrawElementsBaseVertex") : (void*)0; if (p_glDrawElementsBaseVertex) n++;
    *(void **)&p_glDrawElementsIndirect = dlsym(mgl, "glDrawElementsIndirect"); *(void **)&a_glDrawElementsIndirect = apple ? dlsym(apple, "glDrawElementsIndirect") : (void*)0; if (p_glDrawElementsIndirect) n++;
    *(void **)&p_glDrawElementsInstanced = dlsym(mgl, "glDrawElementsInstanced"); *(void **)&a_glDrawElementsInstanced = apple ? dlsym(apple, "glDrawElementsInstanced") : (void*)0; if (p_glDrawElementsInstanced) n++;
    *(void **)&p_glDrawElementsInstancedBaseInstance = dlsym(mgl, "glDrawElementsInstancedBaseInstance"); *(void **)&a_glDrawElementsInstancedBaseInstance = apple ? dlsym(apple, "glDrawElementsInstancedBaseInstance") : (void*)0; if (p_glDrawElementsInstancedBaseInstance) n++;
    *(void **)&p_glDrawElementsInstancedBaseVertex = dlsym(mgl, "glDrawElementsInstancedBaseVertex"); *(void **)&a_glDrawElementsInstancedBaseVertex = apple ? dlsym(apple, "glDrawElementsInstancedBaseVertex") : (void*)0; if (p_glDrawElementsInstancedBaseVertex) n++;
    *(void **)&p_glDrawElementsInstancedBaseVertexBaseInstance = dlsym(mgl, "glDrawElementsInstancedBaseVertexBaseInstance"); *(void **)&a_glDrawElementsInstancedBaseVertexBaseInstance = apple ? dlsym(apple, "glDrawElementsInstancedBaseVertexBaseInstance") : (void*)0; if (p_glDrawElementsInstancedBaseVertexBaseInstance) n++;
    *(void **)&p_glDrawPixels = dlsym(mgl, "glDrawPixels"); *(void **)&a_glDrawPixels = apple ? dlsym(apple, "glDrawPixels") : (void*)0; if (p_glDrawPixels) n++;
    *(void **)&p_glDrawRangeElements = dlsym(mgl, "glDrawRangeElements"); *(void **)&a_glDrawRangeElements = apple ? dlsym(apple, "glDrawRangeElements") : (void*)0; if (p_glDrawRangeElements) n++;
    *(void **)&p_glDrawRangeElementsBaseVertex = dlsym(mgl, "glDrawRangeElementsBaseVertex"); *(void **)&a_glDrawRangeElementsBaseVertex = apple ? dlsym(apple, "glDrawRangeElementsBaseVertex") : (void*)0; if (p_glDrawRangeElementsBaseVertex) n++;
    *(void **)&p_glDrawTransformFeedback = dlsym(mgl, "glDrawTransformFeedback"); *(void **)&a_glDrawTransformFeedback = apple ? dlsym(apple, "glDrawTransformFeedback") : (void*)0; if (p_glDrawTransformFeedback) n++;
    *(void **)&p_glDrawTransformFeedbackInstanced = dlsym(mgl, "glDrawTransformFeedbackInstanced"); *(void **)&a_glDrawTransformFeedbackInstanced = apple ? dlsym(apple, "glDrawTransformFeedbackInstanced") : (void*)0; if (p_glDrawTransformFeedbackInstanced) n++;
    *(void **)&p_glDrawTransformFeedbackStream = dlsym(mgl, "glDrawTransformFeedbackStream"); *(void **)&a_glDrawTransformFeedbackStream = apple ? dlsym(apple, "glDrawTransformFeedbackStream") : (void*)0; if (p_glDrawTransformFeedbackStream) n++;
    *(void **)&p_glDrawTransformFeedbackStreamInstanced = dlsym(mgl, "glDrawTransformFeedbackStreamInstanced"); *(void **)&a_glDrawTransformFeedbackStreamInstanced = apple ? dlsym(apple, "glDrawTransformFeedbackStreamInstanced") : (void*)0; if (p_glDrawTransformFeedbackStreamInstanced) n++;
    *(void **)&p_glEdgeFlag = dlsym(mgl, "glEdgeFlag"); *(void **)&a_glEdgeFlag = apple ? dlsym(apple, "glEdgeFlag") : (void*)0; if (p_glEdgeFlag) n++;
    *(void **)&p_glEdgeFlagPointer = dlsym(mgl, "glEdgeFlagPointer"); *(void **)&a_glEdgeFlagPointer = apple ? dlsym(apple, "glEdgeFlagPointer") : (void*)0; if (p_glEdgeFlagPointer) n++;
    *(void **)&p_glEdgeFlagv = dlsym(mgl, "glEdgeFlagv"); *(void **)&a_glEdgeFlagv = apple ? dlsym(apple, "glEdgeFlagv") : (void*)0; if (p_glEdgeFlagv) n++;
    *(void **)&p_glEnable = dlsym(mgl, "glEnable"); *(void **)&a_glEnable = apple ? dlsym(apple, "glEnable") : (void*)0; if (p_glEnable) n++;
    *(void **)&p_glEnableClientState = dlsym(mgl, "glEnableClientState"); *(void **)&a_glEnableClientState = apple ? dlsym(apple, "glEnableClientState") : (void*)0; if (p_glEnableClientState) n++;
    *(void **)&p_glEnableVertexArrayAttrib = dlsym(mgl, "glEnableVertexArrayAttrib"); *(void **)&a_glEnableVertexArrayAttrib = apple ? dlsym(apple, "glEnableVertexArrayAttrib") : (void*)0; if (p_glEnableVertexArrayAttrib) n++;
    *(void **)&p_glEnableVertexAttribArray = dlsym(mgl, "glEnableVertexAttribArray"); *(void **)&a_glEnableVertexAttribArray = apple ? dlsym(apple, "glEnableVertexAttribArray") : (void*)0; if (p_glEnableVertexAttribArray) n++;
    *(void **)&p_glEnablei = dlsym(mgl, "glEnablei"); *(void **)&a_glEnablei = apple ? dlsym(apple, "glEnablei") : (void*)0; if (p_glEnablei) n++;
    *(void **)&p_glEnd = dlsym(mgl, "glEnd"); *(void **)&a_glEnd = apple ? dlsym(apple, "glEnd") : (void*)0; if (p_glEnd) n++;
    *(void **)&p_glEndConditionalRender = dlsym(mgl, "glEndConditionalRender"); *(void **)&a_glEndConditionalRender = apple ? dlsym(apple, "glEndConditionalRender") : (void*)0; if (p_glEndConditionalRender) n++;
    *(void **)&p_glEndList = dlsym(mgl, "glEndList"); *(void **)&a_glEndList = apple ? dlsym(apple, "glEndList") : (void*)0; if (p_glEndList) n++;
    *(void **)&p_glEndQuery = dlsym(mgl, "glEndQuery"); *(void **)&a_glEndQuery = apple ? dlsym(apple, "glEndQuery") : (void*)0; if (p_glEndQuery) n++;
    *(void **)&p_glEndQueryIndexed = dlsym(mgl, "glEndQueryIndexed"); *(void **)&a_glEndQueryIndexed = apple ? dlsym(apple, "glEndQueryIndexed") : (void*)0; if (p_glEndQueryIndexed) n++;
    *(void **)&p_glEndTransformFeedback = dlsym(mgl, "glEndTransformFeedback"); *(void **)&a_glEndTransformFeedback = apple ? dlsym(apple, "glEndTransformFeedback") : (void*)0; if (p_glEndTransformFeedback) n++;
    *(void **)&p_glEvalCoord1d = dlsym(mgl, "glEvalCoord1d"); *(void **)&a_glEvalCoord1d = apple ? dlsym(apple, "glEvalCoord1d") : (void*)0; if (p_glEvalCoord1d) n++;
    *(void **)&p_glEvalCoord1dv = dlsym(mgl, "glEvalCoord1dv"); *(void **)&a_glEvalCoord1dv = apple ? dlsym(apple, "glEvalCoord1dv") : (void*)0; if (p_glEvalCoord1dv) n++;
    *(void **)&p_glEvalCoord1f = dlsym(mgl, "glEvalCoord1f"); *(void **)&a_glEvalCoord1f = apple ? dlsym(apple, "glEvalCoord1f") : (void*)0; if (p_glEvalCoord1f) n++;
    *(void **)&p_glEvalCoord1fv = dlsym(mgl, "glEvalCoord1fv"); *(void **)&a_glEvalCoord1fv = apple ? dlsym(apple, "glEvalCoord1fv") : (void*)0; if (p_glEvalCoord1fv) n++;
    *(void **)&p_glEvalCoord2d = dlsym(mgl, "glEvalCoord2d"); *(void **)&a_glEvalCoord2d = apple ? dlsym(apple, "glEvalCoord2d") : (void*)0; if (p_glEvalCoord2d) n++;
    *(void **)&p_glEvalCoord2dv = dlsym(mgl, "glEvalCoord2dv"); *(void **)&a_glEvalCoord2dv = apple ? dlsym(apple, "glEvalCoord2dv") : (void*)0; if (p_glEvalCoord2dv) n++;
    *(void **)&p_glEvalCoord2f = dlsym(mgl, "glEvalCoord2f"); *(void **)&a_glEvalCoord2f = apple ? dlsym(apple, "glEvalCoord2f") : (void*)0; if (p_glEvalCoord2f) n++;
    *(void **)&p_glEvalCoord2fv = dlsym(mgl, "glEvalCoord2fv"); *(void **)&a_glEvalCoord2fv = apple ? dlsym(apple, "glEvalCoord2fv") : (void*)0; if (p_glEvalCoord2fv) n++;
    *(void **)&p_glEvalMesh1 = dlsym(mgl, "glEvalMesh1"); *(void **)&a_glEvalMesh1 = apple ? dlsym(apple, "glEvalMesh1") : (void*)0; if (p_glEvalMesh1) n++;
    *(void **)&p_glEvalMesh2 = dlsym(mgl, "glEvalMesh2"); *(void **)&a_glEvalMesh2 = apple ? dlsym(apple, "glEvalMesh2") : (void*)0; if (p_glEvalMesh2) n++;
    *(void **)&p_glEvalPoint1 = dlsym(mgl, "glEvalPoint1"); *(void **)&a_glEvalPoint1 = apple ? dlsym(apple, "glEvalPoint1") : (void*)0; if (p_glEvalPoint1) n++;
    *(void **)&p_glEvalPoint2 = dlsym(mgl, "glEvalPoint2"); *(void **)&a_glEvalPoint2 = apple ? dlsym(apple, "glEvalPoint2") : (void*)0; if (p_glEvalPoint2) n++;
    *(void **)&p_glFeedbackBuffer = dlsym(mgl, "glFeedbackBuffer"); *(void **)&a_glFeedbackBuffer = apple ? dlsym(apple, "glFeedbackBuffer") : (void*)0; if (p_glFeedbackBuffer) n++;
    *(void **)&p_glFenceSync = dlsym(mgl, "glFenceSync"); *(void **)&a_glFenceSync = apple ? dlsym(apple, "glFenceSync") : (void*)0; if (p_glFenceSync) n++;
    *(void **)&p_glFinish = dlsym(mgl, "glFinish"); *(void **)&a_glFinish = apple ? dlsym(apple, "glFinish") : (void*)0; if (p_glFinish) n++;
    *(void **)&p_glFlush = dlsym(mgl, "glFlush"); *(void **)&a_glFlush = apple ? dlsym(apple, "glFlush") : (void*)0; if (p_glFlush) n++;
    *(void **)&p_glFlushMappedBufferRange = dlsym(mgl, "glFlushMappedBufferRange"); *(void **)&a_glFlushMappedBufferRange = apple ? dlsym(apple, "glFlushMappedBufferRange") : (void*)0; if (p_glFlushMappedBufferRange) n++;
    *(void **)&p_glFlushMappedNamedBufferRange = dlsym(mgl, "glFlushMappedNamedBufferRange"); *(void **)&a_glFlushMappedNamedBufferRange = apple ? dlsym(apple, "glFlushMappedNamedBufferRange") : (void*)0; if (p_glFlushMappedNamedBufferRange) n++;
    *(void **)&p_glFogCoordPointer = dlsym(mgl, "glFogCoordPointer"); *(void **)&a_glFogCoordPointer = apple ? dlsym(apple, "glFogCoordPointer") : (void*)0; if (p_glFogCoordPointer) n++;
    *(void **)&p_glFogCoordd = dlsym(mgl, "glFogCoordd"); *(void **)&a_glFogCoordd = apple ? dlsym(apple, "glFogCoordd") : (void*)0; if (p_glFogCoordd) n++;
    *(void **)&p_glFogCoorddv = dlsym(mgl, "glFogCoorddv"); *(void **)&a_glFogCoorddv = apple ? dlsym(apple, "glFogCoorddv") : (void*)0; if (p_glFogCoorddv) n++;
    *(void **)&p_glFogCoordf = dlsym(mgl, "glFogCoordf"); *(void **)&a_glFogCoordf = apple ? dlsym(apple, "glFogCoordf") : (void*)0; if (p_glFogCoordf) n++;
    *(void **)&p_glFogCoordfv = dlsym(mgl, "glFogCoordfv"); *(void **)&a_glFogCoordfv = apple ? dlsym(apple, "glFogCoordfv") : (void*)0; if (p_glFogCoordfv) n++;
    *(void **)&p_glFogf = dlsym(mgl, "glFogf"); *(void **)&a_glFogf = apple ? dlsym(apple, "glFogf") : (void*)0; if (p_glFogf) n++;
    *(void **)&p_glFogfv = dlsym(mgl, "glFogfv"); *(void **)&a_glFogfv = apple ? dlsym(apple, "glFogfv") : (void*)0; if (p_glFogfv) n++;
    *(void **)&p_glFogi = dlsym(mgl, "glFogi"); *(void **)&a_glFogi = apple ? dlsym(apple, "glFogi") : (void*)0; if (p_glFogi) n++;
    *(void **)&p_glFogiv = dlsym(mgl, "glFogiv"); *(void **)&a_glFogiv = apple ? dlsym(apple, "glFogiv") : (void*)0; if (p_glFogiv) n++;
    *(void **)&p_glFramebufferParameteri = dlsym(mgl, "glFramebufferParameteri"); *(void **)&a_glFramebufferParameteri = apple ? dlsym(apple, "glFramebufferParameteri") : (void*)0; if (p_glFramebufferParameteri) n++;
    *(void **)&p_glFramebufferRenderbuffer = dlsym(mgl, "glFramebufferRenderbuffer"); *(void **)&a_glFramebufferRenderbuffer = apple ? dlsym(apple, "glFramebufferRenderbuffer") : (void*)0; if (p_glFramebufferRenderbuffer) n++;
    *(void **)&p_glFramebufferTexture = dlsym(mgl, "glFramebufferTexture"); *(void **)&a_glFramebufferTexture = apple ? dlsym(apple, "glFramebufferTexture") : (void*)0; if (p_glFramebufferTexture) n++;
    *(void **)&p_glFramebufferTexture1D = dlsym(mgl, "glFramebufferTexture1D"); *(void **)&a_glFramebufferTexture1D = apple ? dlsym(apple, "glFramebufferTexture1D") : (void*)0; if (p_glFramebufferTexture1D) n++;
    *(void **)&p_glFramebufferTexture2D = dlsym(mgl, "glFramebufferTexture2D"); *(void **)&a_glFramebufferTexture2D = apple ? dlsym(apple, "glFramebufferTexture2D") : (void*)0; if (p_glFramebufferTexture2D) n++;
    *(void **)&p_glFramebufferTexture3D = dlsym(mgl, "glFramebufferTexture3D"); *(void **)&a_glFramebufferTexture3D = apple ? dlsym(apple, "glFramebufferTexture3D") : (void*)0; if (p_glFramebufferTexture3D) n++;
    *(void **)&p_glFramebufferTextureLayer = dlsym(mgl, "glFramebufferTextureLayer"); *(void **)&a_glFramebufferTextureLayer = apple ? dlsym(apple, "glFramebufferTextureLayer") : (void*)0; if (p_glFramebufferTextureLayer) n++;
    *(void **)&p_glFrontFace = dlsym(mgl, "glFrontFace"); *(void **)&a_glFrontFace = apple ? dlsym(apple, "glFrontFace") : (void*)0; if (p_glFrontFace) n++;
    *(void **)&p_glFrustum = dlsym(mgl, "glFrustum"); *(void **)&a_glFrustum = apple ? dlsym(apple, "glFrustum") : (void*)0; if (p_glFrustum) n++;
    *(void **)&p_glGenBuffers = dlsym(mgl, "glGenBuffers"); *(void **)&a_glGenBuffers = apple ? dlsym(apple, "glGenBuffers") : (void*)0; if (p_glGenBuffers) n++;
    *(void **)&p_glGenFramebuffers = dlsym(mgl, "glGenFramebuffers"); *(void **)&a_glGenFramebuffers = apple ? dlsym(apple, "glGenFramebuffers") : (void*)0; if (p_glGenFramebuffers) n++;
    *(void **)&p_glGenLists = dlsym(mgl, "glGenLists"); *(void **)&a_glGenLists = apple ? dlsym(apple, "glGenLists") : (void*)0; if (p_glGenLists) n++;
    *(void **)&p_glGenProgramPipelines = dlsym(mgl, "glGenProgramPipelines"); *(void **)&a_glGenProgramPipelines = apple ? dlsym(apple, "glGenProgramPipelines") : (void*)0; if (p_glGenProgramPipelines) n++;
    *(void **)&p_glGenQueries = dlsym(mgl, "glGenQueries"); *(void **)&a_glGenQueries = apple ? dlsym(apple, "glGenQueries") : (void*)0; if (p_glGenQueries) n++;
    *(void **)&p_glGenRenderbuffers = dlsym(mgl, "glGenRenderbuffers"); *(void **)&a_glGenRenderbuffers = apple ? dlsym(apple, "glGenRenderbuffers") : (void*)0; if (p_glGenRenderbuffers) n++;
    *(void **)&p_glGenSamplers = dlsym(mgl, "glGenSamplers"); *(void **)&a_glGenSamplers = apple ? dlsym(apple, "glGenSamplers") : (void*)0; if (p_glGenSamplers) n++;
    *(void **)&p_glGenTextures = dlsym(mgl, "glGenTextures"); *(void **)&a_glGenTextures = apple ? dlsym(apple, "glGenTextures") : (void*)0; if (p_glGenTextures) n++;
    *(void **)&p_glGenTransformFeedbacks = dlsym(mgl, "glGenTransformFeedbacks"); *(void **)&a_glGenTransformFeedbacks = apple ? dlsym(apple, "glGenTransformFeedbacks") : (void*)0; if (p_glGenTransformFeedbacks) n++;
    *(void **)&p_glGenVertexArrays = dlsym(mgl, "glGenVertexArrays"); *(void **)&a_glGenVertexArrays = apple ? dlsym(apple, "glGenVertexArrays") : (void*)0; if (p_glGenVertexArrays) n++;
    *(void **)&p_glGenerateMipmap = dlsym(mgl, "glGenerateMipmap"); *(void **)&a_glGenerateMipmap = apple ? dlsym(apple, "glGenerateMipmap") : (void*)0; if (p_glGenerateMipmap) n++;
    *(void **)&p_glGenerateTextureMipmap = dlsym(mgl, "glGenerateTextureMipmap"); *(void **)&a_glGenerateTextureMipmap = apple ? dlsym(apple, "glGenerateTextureMipmap") : (void*)0; if (p_glGenerateTextureMipmap) n++;
    *(void **)&p_glGetActiveAtomicCounterBufferiv = dlsym(mgl, "glGetActiveAtomicCounterBufferiv"); *(void **)&a_glGetActiveAtomicCounterBufferiv = apple ? dlsym(apple, "glGetActiveAtomicCounterBufferiv") : (void*)0; if (p_glGetActiveAtomicCounterBufferiv) n++;
    *(void **)&p_glGetActiveAttrib = dlsym(mgl, "glGetActiveAttrib"); *(void **)&a_glGetActiveAttrib = apple ? dlsym(apple, "glGetActiveAttrib") : (void*)0; if (p_glGetActiveAttrib) n++;
    *(void **)&p_glGetActiveSubroutineName = dlsym(mgl, "glGetActiveSubroutineName"); *(void **)&a_glGetActiveSubroutineName = apple ? dlsym(apple, "glGetActiveSubroutineName") : (void*)0; if (p_glGetActiveSubroutineName) n++;
    *(void **)&p_glGetActiveSubroutineUniformName = dlsym(mgl, "glGetActiveSubroutineUniformName"); *(void **)&a_glGetActiveSubroutineUniformName = apple ? dlsym(apple, "glGetActiveSubroutineUniformName") : (void*)0; if (p_glGetActiveSubroutineUniformName) n++;
    *(void **)&p_glGetActiveSubroutineUniformiv = dlsym(mgl, "glGetActiveSubroutineUniformiv"); *(void **)&a_glGetActiveSubroutineUniformiv = apple ? dlsym(apple, "glGetActiveSubroutineUniformiv") : (void*)0; if (p_glGetActiveSubroutineUniformiv) n++;
    *(void **)&p_glGetActiveUniform = dlsym(mgl, "glGetActiveUniform"); *(void **)&a_glGetActiveUniform = apple ? dlsym(apple, "glGetActiveUniform") : (void*)0; if (p_glGetActiveUniform) n++;
    *(void **)&p_glGetActiveUniformBlockName = dlsym(mgl, "glGetActiveUniformBlockName"); *(void **)&a_glGetActiveUniformBlockName = apple ? dlsym(apple, "glGetActiveUniformBlockName") : (void*)0; if (p_glGetActiveUniformBlockName) n++;
    *(void **)&p_glGetActiveUniformBlockiv = dlsym(mgl, "glGetActiveUniformBlockiv"); *(void **)&a_glGetActiveUniformBlockiv = apple ? dlsym(apple, "glGetActiveUniformBlockiv") : (void*)0; if (p_glGetActiveUniformBlockiv) n++;
    *(void **)&p_glGetActiveUniformName = dlsym(mgl, "glGetActiveUniformName"); *(void **)&a_glGetActiveUniformName = apple ? dlsym(apple, "glGetActiveUniformName") : (void*)0; if (p_glGetActiveUniformName) n++;
    *(void **)&p_glGetActiveUniformsiv = dlsym(mgl, "glGetActiveUniformsiv"); *(void **)&a_glGetActiveUniformsiv = apple ? dlsym(apple, "glGetActiveUniformsiv") : (void*)0; if (p_glGetActiveUniformsiv) n++;
    *(void **)&p_glGetAttachedShaders = dlsym(mgl, "glGetAttachedShaders"); *(void **)&a_glGetAttachedShaders = apple ? dlsym(apple, "glGetAttachedShaders") : (void*)0; if (p_glGetAttachedShaders) n++;
    *(void **)&p_glGetAttribLocation = dlsym(mgl, "glGetAttribLocation"); *(void **)&a_glGetAttribLocation = apple ? dlsym(apple, "glGetAttribLocation") : (void*)0; if (p_glGetAttribLocation) n++;
    *(void **)&p_glGetBooleani_v = dlsym(mgl, "glGetBooleani_v"); *(void **)&a_glGetBooleani_v = apple ? dlsym(apple, "glGetBooleani_v") : (void*)0; if (p_glGetBooleani_v) n++;
    *(void **)&p_glGetBooleanv = dlsym(mgl, "glGetBooleanv"); *(void **)&a_glGetBooleanv = apple ? dlsym(apple, "glGetBooleanv") : (void*)0; if (p_glGetBooleanv) n++;
    *(void **)&p_glGetBufferParameteri64v = dlsym(mgl, "glGetBufferParameteri64v"); *(void **)&a_glGetBufferParameteri64v = apple ? dlsym(apple, "glGetBufferParameteri64v") : (void*)0; if (p_glGetBufferParameteri64v) n++;
    *(void **)&p_glGetBufferParameteriv = dlsym(mgl, "glGetBufferParameteriv"); *(void **)&a_glGetBufferParameteriv = apple ? dlsym(apple, "glGetBufferParameteriv") : (void*)0; if (p_glGetBufferParameteriv) n++;
    *(void **)&p_glGetBufferPointerv = dlsym(mgl, "glGetBufferPointerv"); *(void **)&a_glGetBufferPointerv = apple ? dlsym(apple, "glGetBufferPointerv") : (void*)0; if (p_glGetBufferPointerv) n++;
    *(void **)&p_glGetBufferSubData = dlsym(mgl, "glGetBufferSubData"); *(void **)&a_glGetBufferSubData = apple ? dlsym(apple, "glGetBufferSubData") : (void*)0; if (p_glGetBufferSubData) n++;
    *(void **)&p_glGetClipPlane = dlsym(mgl, "glGetClipPlane"); *(void **)&a_glGetClipPlane = apple ? dlsym(apple, "glGetClipPlane") : (void*)0; if (p_glGetClipPlane) n++;
    *(void **)&p_glGetCompressedTexImage = dlsym(mgl, "glGetCompressedTexImage"); *(void **)&a_glGetCompressedTexImage = apple ? dlsym(apple, "glGetCompressedTexImage") : (void*)0; if (p_glGetCompressedTexImage) n++;
    *(void **)&p_glGetCompressedTextureImage = dlsym(mgl, "glGetCompressedTextureImage"); *(void **)&a_glGetCompressedTextureImage = apple ? dlsym(apple, "glGetCompressedTextureImage") : (void*)0; if (p_glGetCompressedTextureImage) n++;
    *(void **)&p_glGetCompressedTextureSubImage = dlsym(mgl, "glGetCompressedTextureSubImage"); *(void **)&a_glGetCompressedTextureSubImage = apple ? dlsym(apple, "glGetCompressedTextureSubImage") : (void*)0; if (p_glGetCompressedTextureSubImage) n++;
    *(void **)&p_glGetDebugMessageLog = dlsym(mgl, "glGetDebugMessageLog"); *(void **)&a_glGetDebugMessageLog = apple ? dlsym(apple, "glGetDebugMessageLog") : (void*)0; if (p_glGetDebugMessageLog) n++;
    *(void **)&p_glGetDoublei_v = dlsym(mgl, "glGetDoublei_v"); *(void **)&a_glGetDoublei_v = apple ? dlsym(apple, "glGetDoublei_v") : (void*)0; if (p_glGetDoublei_v) n++;
    *(void **)&p_glGetDoublev = dlsym(mgl, "glGetDoublev"); *(void **)&a_glGetDoublev = apple ? dlsym(apple, "glGetDoublev") : (void*)0; if (p_glGetDoublev) n++;
    *(void **)&p_glGetError = dlsym(mgl, "glGetError"); *(void **)&a_glGetError = apple ? dlsym(apple, "glGetError") : (void*)0; if (p_glGetError) n++;
    *(void **)&p_glGetFloati_v = dlsym(mgl, "glGetFloati_v"); *(void **)&a_glGetFloati_v = apple ? dlsym(apple, "glGetFloati_v") : (void*)0; if (p_glGetFloati_v) n++;
    *(void **)&p_glGetFloatv = dlsym(mgl, "glGetFloatv"); *(void **)&a_glGetFloatv = apple ? dlsym(apple, "glGetFloatv") : (void*)0; if (p_glGetFloatv) n++;
    *(void **)&p_glGetFragDataIndex = dlsym(mgl, "glGetFragDataIndex"); *(void **)&a_glGetFragDataIndex = apple ? dlsym(apple, "glGetFragDataIndex") : (void*)0; if (p_glGetFragDataIndex) n++;
    *(void **)&p_glGetFragDataLocation = dlsym(mgl, "glGetFragDataLocation"); *(void **)&a_glGetFragDataLocation = apple ? dlsym(apple, "glGetFragDataLocation") : (void*)0; if (p_glGetFragDataLocation) n++;
    *(void **)&p_glGetFramebufferAttachmentParameteriv = dlsym(mgl, "glGetFramebufferAttachmentParameteriv"); *(void **)&a_glGetFramebufferAttachmentParameteriv = apple ? dlsym(apple, "glGetFramebufferAttachmentParameteriv") : (void*)0; if (p_glGetFramebufferAttachmentParameteriv) n++;
    *(void **)&p_glGetFramebufferParameteriv = dlsym(mgl, "glGetFramebufferParameteriv"); *(void **)&a_glGetFramebufferParameteriv = apple ? dlsym(apple, "glGetFramebufferParameteriv") : (void*)0; if (p_glGetFramebufferParameteriv) n++;
    *(void **)&p_glGetGraphicsResetStatus = dlsym(mgl, "glGetGraphicsResetStatus"); *(void **)&a_glGetGraphicsResetStatus = apple ? dlsym(apple, "glGetGraphicsResetStatus") : (void*)0; if (p_glGetGraphicsResetStatus) n++;
    *(void **)&p_glGetInteger64i_v = dlsym(mgl, "glGetInteger64i_v"); *(void **)&a_glGetInteger64i_v = apple ? dlsym(apple, "glGetInteger64i_v") : (void*)0; if (p_glGetInteger64i_v) n++;
    *(void **)&p_glGetInteger64v = dlsym(mgl, "glGetInteger64v"); *(void **)&a_glGetInteger64v = apple ? dlsym(apple, "glGetInteger64v") : (void*)0; if (p_glGetInteger64v) n++;
    *(void **)&p_glGetIntegeri_v = dlsym(mgl, "glGetIntegeri_v"); *(void **)&a_glGetIntegeri_v = apple ? dlsym(apple, "glGetIntegeri_v") : (void*)0; if (p_glGetIntegeri_v) n++;
    *(void **)&p_glGetIntegerv = dlsym(mgl, "glGetIntegerv"); *(void **)&a_glGetIntegerv = apple ? dlsym(apple, "glGetIntegerv") : (void*)0; if (p_glGetIntegerv) n++;
    *(void **)&p_glGetInternalformati64v = dlsym(mgl, "glGetInternalformati64v"); *(void **)&a_glGetInternalformati64v = apple ? dlsym(apple, "glGetInternalformati64v") : (void*)0; if (p_glGetInternalformati64v) n++;
    *(void **)&p_glGetInternalformativ = dlsym(mgl, "glGetInternalformativ"); *(void **)&a_glGetInternalformativ = apple ? dlsym(apple, "glGetInternalformativ") : (void*)0; if (p_glGetInternalformativ) n++;
    *(void **)&p_glGetLightfv = dlsym(mgl, "glGetLightfv"); *(void **)&a_glGetLightfv = apple ? dlsym(apple, "glGetLightfv") : (void*)0; if (p_glGetLightfv) n++;
    *(void **)&p_glGetLightiv = dlsym(mgl, "glGetLightiv"); *(void **)&a_glGetLightiv = apple ? dlsym(apple, "glGetLightiv") : (void*)0; if (p_glGetLightiv) n++;
    *(void **)&p_glGetMapdv = dlsym(mgl, "glGetMapdv"); *(void **)&a_glGetMapdv = apple ? dlsym(apple, "glGetMapdv") : (void*)0; if (p_glGetMapdv) n++;
    *(void **)&p_glGetMapfv = dlsym(mgl, "glGetMapfv"); *(void **)&a_glGetMapfv = apple ? dlsym(apple, "glGetMapfv") : (void*)0; if (p_glGetMapfv) n++;
    *(void **)&p_glGetMapiv = dlsym(mgl, "glGetMapiv"); *(void **)&a_glGetMapiv = apple ? dlsym(apple, "glGetMapiv") : (void*)0; if (p_glGetMapiv) n++;
    *(void **)&p_glGetMaterialfv = dlsym(mgl, "glGetMaterialfv"); *(void **)&a_glGetMaterialfv = apple ? dlsym(apple, "glGetMaterialfv") : (void*)0; if (p_glGetMaterialfv) n++;
    *(void **)&p_glGetMaterialiv = dlsym(mgl, "glGetMaterialiv"); *(void **)&a_glGetMaterialiv = apple ? dlsym(apple, "glGetMaterialiv") : (void*)0; if (p_glGetMaterialiv) n++;
    *(void **)&p_glGetMultisamplefv = dlsym(mgl, "glGetMultisamplefv"); *(void **)&a_glGetMultisamplefv = apple ? dlsym(apple, "glGetMultisamplefv") : (void*)0; if (p_glGetMultisamplefv) n++;
    *(void **)&p_glGetNamedBufferParameteri64v = dlsym(mgl, "glGetNamedBufferParameteri64v"); *(void **)&a_glGetNamedBufferParameteri64v = apple ? dlsym(apple, "glGetNamedBufferParameteri64v") : (void*)0; if (p_glGetNamedBufferParameteri64v) n++;
    *(void **)&p_glGetNamedBufferParameteriv = dlsym(mgl, "glGetNamedBufferParameteriv"); *(void **)&a_glGetNamedBufferParameteriv = apple ? dlsym(apple, "glGetNamedBufferParameteriv") : (void*)0; if (p_glGetNamedBufferParameteriv) n++;
    *(void **)&p_glGetNamedBufferPointerv = dlsym(mgl, "glGetNamedBufferPointerv"); *(void **)&a_glGetNamedBufferPointerv = apple ? dlsym(apple, "glGetNamedBufferPointerv") : (void*)0; if (p_glGetNamedBufferPointerv) n++;
    *(void **)&p_glGetNamedBufferSubData = dlsym(mgl, "glGetNamedBufferSubData"); *(void **)&a_glGetNamedBufferSubData = apple ? dlsym(apple, "glGetNamedBufferSubData") : (void*)0; if (p_glGetNamedBufferSubData) n++;
    *(void **)&p_glGetNamedFramebufferAttachmentParameteriv = dlsym(mgl, "glGetNamedFramebufferAttachmentParameteriv"); *(void **)&a_glGetNamedFramebufferAttachmentParameteriv = apple ? dlsym(apple, "glGetNamedFramebufferAttachmentParameteriv") : (void*)0; if (p_glGetNamedFramebufferAttachmentParameteriv) n++;
    *(void **)&p_glGetNamedFramebufferParameteriv = dlsym(mgl, "glGetNamedFramebufferParameteriv"); *(void **)&a_glGetNamedFramebufferParameteriv = apple ? dlsym(apple, "glGetNamedFramebufferParameteriv") : (void*)0; if (p_glGetNamedFramebufferParameteriv) n++;
    *(void **)&p_glGetNamedRenderbufferParameteriv = dlsym(mgl, "glGetNamedRenderbufferParameteriv"); *(void **)&a_glGetNamedRenderbufferParameteriv = apple ? dlsym(apple, "glGetNamedRenderbufferParameteriv") : (void*)0; if (p_glGetNamedRenderbufferParameteriv) n++;
    *(void **)&p_glGetObjectLabel = dlsym(mgl, "glGetObjectLabel"); *(void **)&a_glGetObjectLabel = apple ? dlsym(apple, "glGetObjectLabel") : (void*)0; if (p_glGetObjectLabel) n++;
    *(void **)&p_glGetObjectPtrLabel = dlsym(mgl, "glGetObjectPtrLabel"); *(void **)&a_glGetObjectPtrLabel = apple ? dlsym(apple, "glGetObjectPtrLabel") : (void*)0; if (p_glGetObjectPtrLabel) n++;
    *(void **)&p_glGetPixelMapfv = dlsym(mgl, "glGetPixelMapfv"); *(void **)&a_glGetPixelMapfv = apple ? dlsym(apple, "glGetPixelMapfv") : (void*)0; if (p_glGetPixelMapfv) n++;
    *(void **)&p_glGetPixelMapuiv = dlsym(mgl, "glGetPixelMapuiv"); *(void **)&a_glGetPixelMapuiv = apple ? dlsym(apple, "glGetPixelMapuiv") : (void*)0; if (p_glGetPixelMapuiv) n++;
    *(void **)&p_glGetPixelMapusv = dlsym(mgl, "glGetPixelMapusv"); *(void **)&a_glGetPixelMapusv = apple ? dlsym(apple, "glGetPixelMapusv") : (void*)0; if (p_glGetPixelMapusv) n++;
    *(void **)&p_glGetPointerv = dlsym(mgl, "glGetPointerv"); *(void **)&a_glGetPointerv = apple ? dlsym(apple, "glGetPointerv") : (void*)0; if (p_glGetPointerv) n++;
    *(void **)&p_glGetPolygonStipple = dlsym(mgl, "glGetPolygonStipple"); *(void **)&a_glGetPolygonStipple = apple ? dlsym(apple, "glGetPolygonStipple") : (void*)0; if (p_glGetPolygonStipple) n++;
    *(void **)&p_glGetProgramBinary = dlsym(mgl, "glGetProgramBinary"); *(void **)&a_glGetProgramBinary = apple ? dlsym(apple, "glGetProgramBinary") : (void*)0; if (p_glGetProgramBinary) n++;
    *(void **)&p_glGetProgramInfoLog = dlsym(mgl, "glGetProgramInfoLog"); *(void **)&a_glGetProgramInfoLog = apple ? dlsym(apple, "glGetProgramInfoLog") : (void*)0; if (p_glGetProgramInfoLog) n++;
    *(void **)&p_glGetProgramInterfaceiv = dlsym(mgl, "glGetProgramInterfaceiv"); *(void **)&a_glGetProgramInterfaceiv = apple ? dlsym(apple, "glGetProgramInterfaceiv") : (void*)0; if (p_glGetProgramInterfaceiv) n++;
    *(void **)&p_glGetProgramPipelineInfoLog = dlsym(mgl, "glGetProgramPipelineInfoLog"); *(void **)&a_glGetProgramPipelineInfoLog = apple ? dlsym(apple, "glGetProgramPipelineInfoLog") : (void*)0; if (p_glGetProgramPipelineInfoLog) n++;
    *(void **)&p_glGetProgramPipelineiv = dlsym(mgl, "glGetProgramPipelineiv"); *(void **)&a_glGetProgramPipelineiv = apple ? dlsym(apple, "glGetProgramPipelineiv") : (void*)0; if (p_glGetProgramPipelineiv) n++;
    *(void **)&p_glGetProgramResourceIndex = dlsym(mgl, "glGetProgramResourceIndex"); *(void **)&a_glGetProgramResourceIndex = apple ? dlsym(apple, "glGetProgramResourceIndex") : (void*)0; if (p_glGetProgramResourceIndex) n++;
    *(void **)&p_glGetProgramResourceLocation = dlsym(mgl, "glGetProgramResourceLocation"); *(void **)&a_glGetProgramResourceLocation = apple ? dlsym(apple, "glGetProgramResourceLocation") : (void*)0; if (p_glGetProgramResourceLocation) n++;
    *(void **)&p_glGetProgramResourceLocationIndex = dlsym(mgl, "glGetProgramResourceLocationIndex"); *(void **)&a_glGetProgramResourceLocationIndex = apple ? dlsym(apple, "glGetProgramResourceLocationIndex") : (void*)0; if (p_glGetProgramResourceLocationIndex) n++;
    *(void **)&p_glGetProgramResourceName = dlsym(mgl, "glGetProgramResourceName"); *(void **)&a_glGetProgramResourceName = apple ? dlsym(apple, "glGetProgramResourceName") : (void*)0; if (p_glGetProgramResourceName) n++;
    *(void **)&p_glGetProgramResourceiv = dlsym(mgl, "glGetProgramResourceiv"); *(void **)&a_glGetProgramResourceiv = apple ? dlsym(apple, "glGetProgramResourceiv") : (void*)0; if (p_glGetProgramResourceiv) n++;
    *(void **)&p_glGetProgramStageiv = dlsym(mgl, "glGetProgramStageiv"); *(void **)&a_glGetProgramStageiv = apple ? dlsym(apple, "glGetProgramStageiv") : (void*)0; if (p_glGetProgramStageiv) n++;
    *(void **)&p_glGetProgramiv = dlsym(mgl, "glGetProgramiv"); *(void **)&a_glGetProgramiv = apple ? dlsym(apple, "glGetProgramiv") : (void*)0; if (p_glGetProgramiv) n++;
    *(void **)&p_glGetQueryBufferObjecti64v = dlsym(mgl, "glGetQueryBufferObjecti64v"); *(void **)&a_glGetQueryBufferObjecti64v = apple ? dlsym(apple, "glGetQueryBufferObjecti64v") : (void*)0; if (p_glGetQueryBufferObjecti64v) n++;
    *(void **)&p_glGetQueryBufferObjectiv = dlsym(mgl, "glGetQueryBufferObjectiv"); *(void **)&a_glGetQueryBufferObjectiv = apple ? dlsym(apple, "glGetQueryBufferObjectiv") : (void*)0; if (p_glGetQueryBufferObjectiv) n++;
    *(void **)&p_glGetQueryBufferObjectui64v = dlsym(mgl, "glGetQueryBufferObjectui64v"); *(void **)&a_glGetQueryBufferObjectui64v = apple ? dlsym(apple, "glGetQueryBufferObjectui64v") : (void*)0; if (p_glGetQueryBufferObjectui64v) n++;
    *(void **)&p_glGetQueryBufferObjectuiv = dlsym(mgl, "glGetQueryBufferObjectuiv"); *(void **)&a_glGetQueryBufferObjectuiv = apple ? dlsym(apple, "glGetQueryBufferObjectuiv") : (void*)0; if (p_glGetQueryBufferObjectuiv) n++;
    *(void **)&p_glGetQueryIndexediv = dlsym(mgl, "glGetQueryIndexediv"); *(void **)&a_glGetQueryIndexediv = apple ? dlsym(apple, "glGetQueryIndexediv") : (void*)0; if (p_glGetQueryIndexediv) n++;
    *(void **)&p_glGetQueryObjecti64v = dlsym(mgl, "glGetQueryObjecti64v"); *(void **)&a_glGetQueryObjecti64v = apple ? dlsym(apple, "glGetQueryObjecti64v") : (void*)0; if (p_glGetQueryObjecti64v) n++;
    *(void **)&p_glGetQueryObjectiv = dlsym(mgl, "glGetQueryObjectiv"); *(void **)&a_glGetQueryObjectiv = apple ? dlsym(apple, "glGetQueryObjectiv") : (void*)0; if (p_glGetQueryObjectiv) n++;
    *(void **)&p_glGetQueryObjectui64v = dlsym(mgl, "glGetQueryObjectui64v"); *(void **)&a_glGetQueryObjectui64v = apple ? dlsym(apple, "glGetQueryObjectui64v") : (void*)0; if (p_glGetQueryObjectui64v) n++;
    *(void **)&p_glGetQueryObjectuiv = dlsym(mgl, "glGetQueryObjectuiv"); *(void **)&a_glGetQueryObjectuiv = apple ? dlsym(apple, "glGetQueryObjectuiv") : (void*)0; if (p_glGetQueryObjectuiv) n++;
    *(void **)&p_glGetQueryiv = dlsym(mgl, "glGetQueryiv"); *(void **)&a_glGetQueryiv = apple ? dlsym(apple, "glGetQueryiv") : (void*)0; if (p_glGetQueryiv) n++;
    *(void **)&p_glGetRenderbufferParameteriv = dlsym(mgl, "glGetRenderbufferParameteriv"); *(void **)&a_glGetRenderbufferParameteriv = apple ? dlsym(apple, "glGetRenderbufferParameteriv") : (void*)0; if (p_glGetRenderbufferParameteriv) n++;
    *(void **)&p_glGetSamplerParameterIiv = dlsym(mgl, "glGetSamplerParameterIiv"); *(void **)&a_glGetSamplerParameterIiv = apple ? dlsym(apple, "glGetSamplerParameterIiv") : (void*)0; if (p_glGetSamplerParameterIiv) n++;
    *(void **)&p_glGetSamplerParameterIuiv = dlsym(mgl, "glGetSamplerParameterIuiv"); *(void **)&a_glGetSamplerParameterIuiv = apple ? dlsym(apple, "glGetSamplerParameterIuiv") : (void*)0; if (p_glGetSamplerParameterIuiv) n++;
    *(void **)&p_glGetSamplerParameterfv = dlsym(mgl, "glGetSamplerParameterfv"); *(void **)&a_glGetSamplerParameterfv = apple ? dlsym(apple, "glGetSamplerParameterfv") : (void*)0; if (p_glGetSamplerParameterfv) n++;
    *(void **)&p_glGetSamplerParameteriv = dlsym(mgl, "glGetSamplerParameteriv"); *(void **)&a_glGetSamplerParameteriv = apple ? dlsym(apple, "glGetSamplerParameteriv") : (void*)0; if (p_glGetSamplerParameteriv) n++;
    *(void **)&p_glGetShaderInfoLog = dlsym(mgl, "glGetShaderInfoLog"); *(void **)&a_glGetShaderInfoLog = apple ? dlsym(apple, "glGetShaderInfoLog") : (void*)0; if (p_glGetShaderInfoLog) n++;
    *(void **)&p_glGetShaderPrecisionFormat = dlsym(mgl, "glGetShaderPrecisionFormat"); *(void **)&a_glGetShaderPrecisionFormat = apple ? dlsym(apple, "glGetShaderPrecisionFormat") : (void*)0; if (p_glGetShaderPrecisionFormat) n++;
    *(void **)&p_glGetShaderSource = dlsym(mgl, "glGetShaderSource"); *(void **)&a_glGetShaderSource = apple ? dlsym(apple, "glGetShaderSource") : (void*)0; if (p_glGetShaderSource) n++;
    *(void **)&p_glGetShaderiv = dlsym(mgl, "glGetShaderiv"); *(void **)&a_glGetShaderiv = apple ? dlsym(apple, "glGetShaderiv") : (void*)0; if (p_glGetShaderiv) n++;
    *(void **)&p_glGetString = dlsym(mgl, "glGetString"); *(void **)&a_glGetString = apple ? dlsym(apple, "glGetString") : (void*)0; if (p_glGetString) n++;
    *(void **)&p_glGetStringi = dlsym(mgl, "glGetStringi"); *(void **)&a_glGetStringi = apple ? dlsym(apple, "glGetStringi") : (void*)0; if (p_glGetStringi) n++;
    *(void **)&p_glGetSubroutineIndex = dlsym(mgl, "glGetSubroutineIndex"); *(void **)&a_glGetSubroutineIndex = apple ? dlsym(apple, "glGetSubroutineIndex") : (void*)0; if (p_glGetSubroutineIndex) n++;
    *(void **)&p_glGetSubroutineUniformLocation = dlsym(mgl, "glGetSubroutineUniformLocation"); *(void **)&a_glGetSubroutineUniformLocation = apple ? dlsym(apple, "glGetSubroutineUniformLocation") : (void*)0; if (p_glGetSubroutineUniformLocation) n++;
    *(void **)&p_glGetSynciv = dlsym(mgl, "glGetSynciv"); *(void **)&a_glGetSynciv = apple ? dlsym(apple, "glGetSynciv") : (void*)0; if (p_glGetSynciv) n++;
    *(void **)&p_glGetTexEnvfv = dlsym(mgl, "glGetTexEnvfv"); *(void **)&a_glGetTexEnvfv = apple ? dlsym(apple, "glGetTexEnvfv") : (void*)0; if (p_glGetTexEnvfv) n++;
    *(void **)&p_glGetTexEnviv = dlsym(mgl, "glGetTexEnviv"); *(void **)&a_glGetTexEnviv = apple ? dlsym(apple, "glGetTexEnviv") : (void*)0; if (p_glGetTexEnviv) n++;
    *(void **)&p_glGetTexGendv = dlsym(mgl, "glGetTexGendv"); *(void **)&a_glGetTexGendv = apple ? dlsym(apple, "glGetTexGendv") : (void*)0; if (p_glGetTexGendv) n++;
    *(void **)&p_glGetTexGenfv = dlsym(mgl, "glGetTexGenfv"); *(void **)&a_glGetTexGenfv = apple ? dlsym(apple, "glGetTexGenfv") : (void*)0; if (p_glGetTexGenfv) n++;
    *(void **)&p_glGetTexGeniv = dlsym(mgl, "glGetTexGeniv"); *(void **)&a_glGetTexGeniv = apple ? dlsym(apple, "glGetTexGeniv") : (void*)0; if (p_glGetTexGeniv) n++;
    *(void **)&p_glGetTexImage = dlsym(mgl, "glGetTexImage"); *(void **)&a_glGetTexImage = apple ? dlsym(apple, "glGetTexImage") : (void*)0; if (p_glGetTexImage) n++;
    *(void **)&p_glGetTexLevelParameterfv = dlsym(mgl, "glGetTexLevelParameterfv"); *(void **)&a_glGetTexLevelParameterfv = apple ? dlsym(apple, "glGetTexLevelParameterfv") : (void*)0; if (p_glGetTexLevelParameterfv) n++;
    *(void **)&p_glGetTexLevelParameteriv = dlsym(mgl, "glGetTexLevelParameteriv"); *(void **)&a_glGetTexLevelParameteriv = apple ? dlsym(apple, "glGetTexLevelParameteriv") : (void*)0; if (p_glGetTexLevelParameteriv) n++;
    *(void **)&p_glGetTexParameterIiv = dlsym(mgl, "glGetTexParameterIiv"); *(void **)&a_glGetTexParameterIiv = apple ? dlsym(apple, "glGetTexParameterIiv") : (void*)0; if (p_glGetTexParameterIiv) n++;
    *(void **)&p_glGetTexParameterIuiv = dlsym(mgl, "glGetTexParameterIuiv"); *(void **)&a_glGetTexParameterIuiv = apple ? dlsym(apple, "glGetTexParameterIuiv") : (void*)0; if (p_glGetTexParameterIuiv) n++;
    *(void **)&p_glGetTexParameterfv = dlsym(mgl, "glGetTexParameterfv"); *(void **)&a_glGetTexParameterfv = apple ? dlsym(apple, "glGetTexParameterfv") : (void*)0; if (p_glGetTexParameterfv) n++;
    *(void **)&p_glGetTexParameteriv = dlsym(mgl, "glGetTexParameteriv"); *(void **)&a_glGetTexParameteriv = apple ? dlsym(apple, "glGetTexParameteriv") : (void*)0; if (p_glGetTexParameteriv) n++;
    *(void **)&p_glGetTextureImage = dlsym(mgl, "glGetTextureImage"); *(void **)&a_glGetTextureImage = apple ? dlsym(apple, "glGetTextureImage") : (void*)0; if (p_glGetTextureImage) n++;
    *(void **)&p_glGetTextureLevelParameterfv = dlsym(mgl, "glGetTextureLevelParameterfv"); *(void **)&a_glGetTextureLevelParameterfv = apple ? dlsym(apple, "glGetTextureLevelParameterfv") : (void*)0; if (p_glGetTextureLevelParameterfv) n++;
    *(void **)&p_glGetTextureLevelParameteriv = dlsym(mgl, "glGetTextureLevelParameteriv"); *(void **)&a_glGetTextureLevelParameteriv = apple ? dlsym(apple, "glGetTextureLevelParameteriv") : (void*)0; if (p_glGetTextureLevelParameteriv) n++;
    *(void **)&p_glGetTextureParameterIiv = dlsym(mgl, "glGetTextureParameterIiv"); *(void **)&a_glGetTextureParameterIiv = apple ? dlsym(apple, "glGetTextureParameterIiv") : (void*)0; if (p_glGetTextureParameterIiv) n++;
    *(void **)&p_glGetTextureParameterIuiv = dlsym(mgl, "glGetTextureParameterIuiv"); *(void **)&a_glGetTextureParameterIuiv = apple ? dlsym(apple, "glGetTextureParameterIuiv") : (void*)0; if (p_glGetTextureParameterIuiv) n++;
    *(void **)&p_glGetTextureParameterfv = dlsym(mgl, "glGetTextureParameterfv"); *(void **)&a_glGetTextureParameterfv = apple ? dlsym(apple, "glGetTextureParameterfv") : (void*)0; if (p_glGetTextureParameterfv) n++;
    *(void **)&p_glGetTextureParameteriv = dlsym(mgl, "glGetTextureParameteriv"); *(void **)&a_glGetTextureParameteriv = apple ? dlsym(apple, "glGetTextureParameteriv") : (void*)0; if (p_glGetTextureParameteriv) n++;
    *(void **)&p_glGetTextureSubImage = dlsym(mgl, "glGetTextureSubImage"); *(void **)&a_glGetTextureSubImage = apple ? dlsym(apple, "glGetTextureSubImage") : (void*)0; if (p_glGetTextureSubImage) n++;
    *(void **)&p_glGetTransformFeedbackVarying = dlsym(mgl, "glGetTransformFeedbackVarying"); *(void **)&a_glGetTransformFeedbackVarying = apple ? dlsym(apple, "glGetTransformFeedbackVarying") : (void*)0; if (p_glGetTransformFeedbackVarying) n++;
    *(void **)&p_glGetTransformFeedbacki64_v = dlsym(mgl, "glGetTransformFeedbacki64_v"); *(void **)&a_glGetTransformFeedbacki64_v = apple ? dlsym(apple, "glGetTransformFeedbacki64_v") : (void*)0; if (p_glGetTransformFeedbacki64_v) n++;
    *(void **)&p_glGetTransformFeedbacki_v = dlsym(mgl, "glGetTransformFeedbacki_v"); *(void **)&a_glGetTransformFeedbacki_v = apple ? dlsym(apple, "glGetTransformFeedbacki_v") : (void*)0; if (p_glGetTransformFeedbacki_v) n++;
    *(void **)&p_glGetTransformFeedbackiv = dlsym(mgl, "glGetTransformFeedbackiv"); *(void **)&a_glGetTransformFeedbackiv = apple ? dlsym(apple, "glGetTransformFeedbackiv") : (void*)0; if (p_glGetTransformFeedbackiv) n++;
    *(void **)&p_glGetUniformBlockIndex = dlsym(mgl, "glGetUniformBlockIndex"); *(void **)&a_glGetUniformBlockIndex = apple ? dlsym(apple, "glGetUniformBlockIndex") : (void*)0; if (p_glGetUniformBlockIndex) n++;
    *(void **)&p_glGetUniformIndices = dlsym(mgl, "glGetUniformIndices"); *(void **)&a_glGetUniformIndices = apple ? dlsym(apple, "glGetUniformIndices") : (void*)0; if (p_glGetUniformIndices) n++;
    *(void **)&p_glGetUniformLocation = dlsym(mgl, "glGetUniformLocation"); *(void **)&a_glGetUniformLocation = apple ? dlsym(apple, "glGetUniformLocation") : (void*)0; if (p_glGetUniformLocation) n++;
    *(void **)&p_glGetUniformSubroutineuiv = dlsym(mgl, "glGetUniformSubroutineuiv"); *(void **)&a_glGetUniformSubroutineuiv = apple ? dlsym(apple, "glGetUniformSubroutineuiv") : (void*)0; if (p_glGetUniformSubroutineuiv) n++;
    *(void **)&p_glGetUniformdv = dlsym(mgl, "glGetUniformdv"); *(void **)&a_glGetUniformdv = apple ? dlsym(apple, "glGetUniformdv") : (void*)0; if (p_glGetUniformdv) n++;
    *(void **)&p_glGetUniformfv = dlsym(mgl, "glGetUniformfv"); *(void **)&a_glGetUniformfv = apple ? dlsym(apple, "glGetUniformfv") : (void*)0; if (p_glGetUniformfv) n++;
    *(void **)&p_glGetUniformiv = dlsym(mgl, "glGetUniformiv"); *(void **)&a_glGetUniformiv = apple ? dlsym(apple, "glGetUniformiv") : (void*)0; if (p_glGetUniformiv) n++;
    *(void **)&p_glGetUniformuiv = dlsym(mgl, "glGetUniformuiv"); *(void **)&a_glGetUniformuiv = apple ? dlsym(apple, "glGetUniformuiv") : (void*)0; if (p_glGetUniformuiv) n++;
    *(void **)&p_glGetVertexArrayIndexed64iv = dlsym(mgl, "glGetVertexArrayIndexed64iv"); *(void **)&a_glGetVertexArrayIndexed64iv = apple ? dlsym(apple, "glGetVertexArrayIndexed64iv") : (void*)0; if (p_glGetVertexArrayIndexed64iv) n++;
    *(void **)&p_glGetVertexArrayIndexediv = dlsym(mgl, "glGetVertexArrayIndexediv"); *(void **)&a_glGetVertexArrayIndexediv = apple ? dlsym(apple, "glGetVertexArrayIndexediv") : (void*)0; if (p_glGetVertexArrayIndexediv) n++;
    *(void **)&p_glGetVertexArrayiv = dlsym(mgl, "glGetVertexArrayiv"); *(void **)&a_glGetVertexArrayiv = apple ? dlsym(apple, "glGetVertexArrayiv") : (void*)0; if (p_glGetVertexArrayiv) n++;
    *(void **)&p_glGetVertexAttribIiv = dlsym(mgl, "glGetVertexAttribIiv"); *(void **)&a_glGetVertexAttribIiv = apple ? dlsym(apple, "glGetVertexAttribIiv") : (void*)0; if (p_glGetVertexAttribIiv) n++;
    *(void **)&p_glGetVertexAttribIuiv = dlsym(mgl, "glGetVertexAttribIuiv"); *(void **)&a_glGetVertexAttribIuiv = apple ? dlsym(apple, "glGetVertexAttribIuiv") : (void*)0; if (p_glGetVertexAttribIuiv) n++;
    *(void **)&p_glGetVertexAttribLdv = dlsym(mgl, "glGetVertexAttribLdv"); *(void **)&a_glGetVertexAttribLdv = apple ? dlsym(apple, "glGetVertexAttribLdv") : (void*)0; if (p_glGetVertexAttribLdv) n++;
    *(void **)&p_glGetVertexAttribPointerv = dlsym(mgl, "glGetVertexAttribPointerv"); *(void **)&a_glGetVertexAttribPointerv = apple ? dlsym(apple, "glGetVertexAttribPointerv") : (void*)0; if (p_glGetVertexAttribPointerv) n++;
    *(void **)&p_glGetVertexAttribdv = dlsym(mgl, "glGetVertexAttribdv"); *(void **)&a_glGetVertexAttribdv = apple ? dlsym(apple, "glGetVertexAttribdv") : (void*)0; if (p_glGetVertexAttribdv) n++;
    *(void **)&p_glGetVertexAttribfv = dlsym(mgl, "glGetVertexAttribfv"); *(void **)&a_glGetVertexAttribfv = apple ? dlsym(apple, "glGetVertexAttribfv") : (void*)0; if (p_glGetVertexAttribfv) n++;
    *(void **)&p_glGetVertexAttribiv = dlsym(mgl, "glGetVertexAttribiv"); *(void **)&a_glGetVertexAttribiv = apple ? dlsym(apple, "glGetVertexAttribiv") : (void*)0; if (p_glGetVertexAttribiv) n++;
    *(void **)&p_glGetnColorTable = dlsym(mgl, "glGetnColorTable"); *(void **)&a_glGetnColorTable = apple ? dlsym(apple, "glGetnColorTable") : (void*)0; if (p_glGetnColorTable) n++;
    *(void **)&p_glGetnCompressedTexImage = dlsym(mgl, "glGetnCompressedTexImage"); *(void **)&a_glGetnCompressedTexImage = apple ? dlsym(apple, "glGetnCompressedTexImage") : (void*)0; if (p_glGetnCompressedTexImage) n++;
    *(void **)&p_glGetnConvolutionFilter = dlsym(mgl, "glGetnConvolutionFilter"); *(void **)&a_glGetnConvolutionFilter = apple ? dlsym(apple, "glGetnConvolutionFilter") : (void*)0; if (p_glGetnConvolutionFilter) n++;
    *(void **)&p_glGetnHistogram = dlsym(mgl, "glGetnHistogram"); *(void **)&a_glGetnHistogram = apple ? dlsym(apple, "glGetnHistogram") : (void*)0; if (p_glGetnHistogram) n++;
    *(void **)&p_glGetnMapdv = dlsym(mgl, "glGetnMapdv"); *(void **)&a_glGetnMapdv = apple ? dlsym(apple, "glGetnMapdv") : (void*)0; if (p_glGetnMapdv) n++;
    *(void **)&p_glGetnMapfv = dlsym(mgl, "glGetnMapfv"); *(void **)&a_glGetnMapfv = apple ? dlsym(apple, "glGetnMapfv") : (void*)0; if (p_glGetnMapfv) n++;
    *(void **)&p_glGetnMapiv = dlsym(mgl, "glGetnMapiv"); *(void **)&a_glGetnMapiv = apple ? dlsym(apple, "glGetnMapiv") : (void*)0; if (p_glGetnMapiv) n++;
    *(void **)&p_glGetnMinmax = dlsym(mgl, "glGetnMinmax"); *(void **)&a_glGetnMinmax = apple ? dlsym(apple, "glGetnMinmax") : (void*)0; if (p_glGetnMinmax) n++;
    *(void **)&p_glGetnPixelMapfv = dlsym(mgl, "glGetnPixelMapfv"); *(void **)&a_glGetnPixelMapfv = apple ? dlsym(apple, "glGetnPixelMapfv") : (void*)0; if (p_glGetnPixelMapfv) n++;
    *(void **)&p_glGetnPixelMapuiv = dlsym(mgl, "glGetnPixelMapuiv"); *(void **)&a_glGetnPixelMapuiv = apple ? dlsym(apple, "glGetnPixelMapuiv") : (void*)0; if (p_glGetnPixelMapuiv) n++;
    *(void **)&p_glGetnPixelMapusv = dlsym(mgl, "glGetnPixelMapusv"); *(void **)&a_glGetnPixelMapusv = apple ? dlsym(apple, "glGetnPixelMapusv") : (void*)0; if (p_glGetnPixelMapusv) n++;
    *(void **)&p_glGetnPolygonStipple = dlsym(mgl, "glGetnPolygonStipple"); *(void **)&a_glGetnPolygonStipple = apple ? dlsym(apple, "glGetnPolygonStipple") : (void*)0; if (p_glGetnPolygonStipple) n++;
    *(void **)&p_glGetnSeparableFilter = dlsym(mgl, "glGetnSeparableFilter"); *(void **)&a_glGetnSeparableFilter = apple ? dlsym(apple, "glGetnSeparableFilter") : (void*)0; if (p_glGetnSeparableFilter) n++;
    *(void **)&p_glGetnTexImage = dlsym(mgl, "glGetnTexImage"); *(void **)&a_glGetnTexImage = apple ? dlsym(apple, "glGetnTexImage") : (void*)0; if (p_glGetnTexImage) n++;
    *(void **)&p_glGetnUniformdv = dlsym(mgl, "glGetnUniformdv"); *(void **)&a_glGetnUniformdv = apple ? dlsym(apple, "glGetnUniformdv") : (void*)0; if (p_glGetnUniformdv) n++;
    *(void **)&p_glGetnUniformfv = dlsym(mgl, "glGetnUniformfv"); *(void **)&a_glGetnUniformfv = apple ? dlsym(apple, "glGetnUniformfv") : (void*)0; if (p_glGetnUniformfv) n++;
    *(void **)&p_glGetnUniformiv = dlsym(mgl, "glGetnUniformiv"); *(void **)&a_glGetnUniformiv = apple ? dlsym(apple, "glGetnUniformiv") : (void*)0; if (p_glGetnUniformiv) n++;
    *(void **)&p_glGetnUniformuiv = dlsym(mgl, "glGetnUniformuiv"); *(void **)&a_glGetnUniformuiv = apple ? dlsym(apple, "glGetnUniformuiv") : (void*)0; if (p_glGetnUniformuiv) n++;
    *(void **)&p_glHint = dlsym(mgl, "glHint"); *(void **)&a_glHint = apple ? dlsym(apple, "glHint") : (void*)0; if (p_glHint) n++;
    *(void **)&p_glIndexMask = dlsym(mgl, "glIndexMask"); *(void **)&a_glIndexMask = apple ? dlsym(apple, "glIndexMask") : (void*)0; if (p_glIndexMask) n++;
    *(void **)&p_glIndexPointer = dlsym(mgl, "glIndexPointer"); *(void **)&a_glIndexPointer = apple ? dlsym(apple, "glIndexPointer") : (void*)0; if (p_glIndexPointer) n++;
    *(void **)&p_glIndexd = dlsym(mgl, "glIndexd"); *(void **)&a_glIndexd = apple ? dlsym(apple, "glIndexd") : (void*)0; if (p_glIndexd) n++;
    *(void **)&p_glIndexdv = dlsym(mgl, "glIndexdv"); *(void **)&a_glIndexdv = apple ? dlsym(apple, "glIndexdv") : (void*)0; if (p_glIndexdv) n++;
    *(void **)&p_glIndexf = dlsym(mgl, "glIndexf"); *(void **)&a_glIndexf = apple ? dlsym(apple, "glIndexf") : (void*)0; if (p_glIndexf) n++;
    *(void **)&p_glIndexfv = dlsym(mgl, "glIndexfv"); *(void **)&a_glIndexfv = apple ? dlsym(apple, "glIndexfv") : (void*)0; if (p_glIndexfv) n++;
    *(void **)&p_glIndexi = dlsym(mgl, "glIndexi"); *(void **)&a_glIndexi = apple ? dlsym(apple, "glIndexi") : (void*)0; if (p_glIndexi) n++;
    *(void **)&p_glIndexiv = dlsym(mgl, "glIndexiv"); *(void **)&a_glIndexiv = apple ? dlsym(apple, "glIndexiv") : (void*)0; if (p_glIndexiv) n++;
    *(void **)&p_glIndexs = dlsym(mgl, "glIndexs"); *(void **)&a_glIndexs = apple ? dlsym(apple, "glIndexs") : (void*)0; if (p_glIndexs) n++;
    *(void **)&p_glIndexsv = dlsym(mgl, "glIndexsv"); *(void **)&a_glIndexsv = apple ? dlsym(apple, "glIndexsv") : (void*)0; if (p_glIndexsv) n++;
    *(void **)&p_glIndexub = dlsym(mgl, "glIndexub"); *(void **)&a_glIndexub = apple ? dlsym(apple, "glIndexub") : (void*)0; if (p_glIndexub) n++;
    *(void **)&p_glIndexubv = dlsym(mgl, "glIndexubv"); *(void **)&a_glIndexubv = apple ? dlsym(apple, "glIndexubv") : (void*)0; if (p_glIndexubv) n++;
    *(void **)&p_glInitNames = dlsym(mgl, "glInitNames"); *(void **)&a_glInitNames = apple ? dlsym(apple, "glInitNames") : (void*)0; if (p_glInitNames) n++;
    *(void **)&p_glInterleavedArrays = dlsym(mgl, "glInterleavedArrays"); *(void **)&a_glInterleavedArrays = apple ? dlsym(apple, "glInterleavedArrays") : (void*)0; if (p_glInterleavedArrays) n++;
    *(void **)&p_glInvalidateBufferData = dlsym(mgl, "glInvalidateBufferData"); *(void **)&a_glInvalidateBufferData = apple ? dlsym(apple, "glInvalidateBufferData") : (void*)0; if (p_glInvalidateBufferData) n++;
    *(void **)&p_glInvalidateBufferSubData = dlsym(mgl, "glInvalidateBufferSubData"); *(void **)&a_glInvalidateBufferSubData = apple ? dlsym(apple, "glInvalidateBufferSubData") : (void*)0; if (p_glInvalidateBufferSubData) n++;
    *(void **)&p_glInvalidateFramebuffer = dlsym(mgl, "glInvalidateFramebuffer"); *(void **)&a_glInvalidateFramebuffer = apple ? dlsym(apple, "glInvalidateFramebuffer") : (void*)0; if (p_glInvalidateFramebuffer) n++;
    *(void **)&p_glInvalidateNamedFramebufferData = dlsym(mgl, "glInvalidateNamedFramebufferData"); *(void **)&a_glInvalidateNamedFramebufferData = apple ? dlsym(apple, "glInvalidateNamedFramebufferData") : (void*)0; if (p_glInvalidateNamedFramebufferData) n++;
    *(void **)&p_glInvalidateNamedFramebufferSubData = dlsym(mgl, "glInvalidateNamedFramebufferSubData"); *(void **)&a_glInvalidateNamedFramebufferSubData = apple ? dlsym(apple, "glInvalidateNamedFramebufferSubData") : (void*)0; if (p_glInvalidateNamedFramebufferSubData) n++;
    *(void **)&p_glInvalidateSubFramebuffer = dlsym(mgl, "glInvalidateSubFramebuffer"); *(void **)&a_glInvalidateSubFramebuffer = apple ? dlsym(apple, "glInvalidateSubFramebuffer") : (void*)0; if (p_glInvalidateSubFramebuffer) n++;
    *(void **)&p_glInvalidateTexImage = dlsym(mgl, "glInvalidateTexImage"); *(void **)&a_glInvalidateTexImage = apple ? dlsym(apple, "glInvalidateTexImage") : (void*)0; if (p_glInvalidateTexImage) n++;
    *(void **)&p_glInvalidateTexSubImage = dlsym(mgl, "glInvalidateTexSubImage"); *(void **)&a_glInvalidateTexSubImage = apple ? dlsym(apple, "glInvalidateTexSubImage") : (void*)0; if (p_glInvalidateTexSubImage) n++;
    *(void **)&p_glIsBuffer = dlsym(mgl, "glIsBuffer"); *(void **)&a_glIsBuffer = apple ? dlsym(apple, "glIsBuffer") : (void*)0; if (p_glIsBuffer) n++;
    *(void **)&p_glIsEnabled = dlsym(mgl, "glIsEnabled"); *(void **)&a_glIsEnabled = apple ? dlsym(apple, "glIsEnabled") : (void*)0; if (p_glIsEnabled) n++;
    *(void **)&p_glIsEnabledi = dlsym(mgl, "glIsEnabledi"); *(void **)&a_glIsEnabledi = apple ? dlsym(apple, "glIsEnabledi") : (void*)0; if (p_glIsEnabledi) n++;
    *(void **)&p_glIsFramebuffer = dlsym(mgl, "glIsFramebuffer"); *(void **)&a_glIsFramebuffer = apple ? dlsym(apple, "glIsFramebuffer") : (void*)0; if (p_glIsFramebuffer) n++;
    *(void **)&p_glIsList = dlsym(mgl, "glIsList"); *(void **)&a_glIsList = apple ? dlsym(apple, "glIsList") : (void*)0; if (p_glIsList) n++;
    *(void **)&p_glIsProgram = dlsym(mgl, "glIsProgram"); *(void **)&a_glIsProgram = apple ? dlsym(apple, "glIsProgram") : (void*)0; if (p_glIsProgram) n++;
    *(void **)&p_glIsProgramPipeline = dlsym(mgl, "glIsProgramPipeline"); *(void **)&a_glIsProgramPipeline = apple ? dlsym(apple, "glIsProgramPipeline") : (void*)0; if (p_glIsProgramPipeline) n++;
    *(void **)&p_glIsQuery = dlsym(mgl, "glIsQuery"); *(void **)&a_glIsQuery = apple ? dlsym(apple, "glIsQuery") : (void*)0; if (p_glIsQuery) n++;
    *(void **)&p_glIsRenderbuffer = dlsym(mgl, "glIsRenderbuffer"); *(void **)&a_glIsRenderbuffer = apple ? dlsym(apple, "glIsRenderbuffer") : (void*)0; if (p_glIsRenderbuffer) n++;
    *(void **)&p_glIsSampler = dlsym(mgl, "glIsSampler"); *(void **)&a_glIsSampler = apple ? dlsym(apple, "glIsSampler") : (void*)0; if (p_glIsSampler) n++;
    *(void **)&p_glIsShader = dlsym(mgl, "glIsShader"); *(void **)&a_glIsShader = apple ? dlsym(apple, "glIsShader") : (void*)0; if (p_glIsShader) n++;
    *(void **)&p_glIsSync = dlsym(mgl, "glIsSync"); *(void **)&a_glIsSync = apple ? dlsym(apple, "glIsSync") : (void*)0; if (p_glIsSync) n++;
    *(void **)&p_glIsTexture = dlsym(mgl, "glIsTexture"); *(void **)&a_glIsTexture = apple ? dlsym(apple, "glIsTexture") : (void*)0; if (p_glIsTexture) n++;
    *(void **)&p_glIsTransformFeedback = dlsym(mgl, "glIsTransformFeedback"); *(void **)&a_glIsTransformFeedback = apple ? dlsym(apple, "glIsTransformFeedback") : (void*)0; if (p_glIsTransformFeedback) n++;
    *(void **)&p_glIsVertexArray = dlsym(mgl, "glIsVertexArray"); *(void **)&a_glIsVertexArray = apple ? dlsym(apple, "glIsVertexArray") : (void*)0; if (p_glIsVertexArray) n++;
    *(void **)&p_glLightModelf = dlsym(mgl, "glLightModelf"); *(void **)&a_glLightModelf = apple ? dlsym(apple, "glLightModelf") : (void*)0; if (p_glLightModelf) n++;
    *(void **)&p_glLightModelfv = dlsym(mgl, "glLightModelfv"); *(void **)&a_glLightModelfv = apple ? dlsym(apple, "glLightModelfv") : (void*)0; if (p_glLightModelfv) n++;
    *(void **)&p_glLightModeli = dlsym(mgl, "glLightModeli"); *(void **)&a_glLightModeli = apple ? dlsym(apple, "glLightModeli") : (void*)0; if (p_glLightModeli) n++;
    *(void **)&p_glLightModeliv = dlsym(mgl, "glLightModeliv"); *(void **)&a_glLightModeliv = apple ? dlsym(apple, "glLightModeliv") : (void*)0; if (p_glLightModeliv) n++;
    *(void **)&p_glLightf = dlsym(mgl, "glLightf"); *(void **)&a_glLightf = apple ? dlsym(apple, "glLightf") : (void*)0; if (p_glLightf) n++;
    *(void **)&p_glLightfv = dlsym(mgl, "glLightfv"); *(void **)&a_glLightfv = apple ? dlsym(apple, "glLightfv") : (void*)0; if (p_glLightfv) n++;
    *(void **)&p_glLighti = dlsym(mgl, "glLighti"); *(void **)&a_glLighti = apple ? dlsym(apple, "glLighti") : (void*)0; if (p_glLighti) n++;
    *(void **)&p_glLightiv = dlsym(mgl, "glLightiv"); *(void **)&a_glLightiv = apple ? dlsym(apple, "glLightiv") : (void*)0; if (p_glLightiv) n++;
    *(void **)&p_glLineStipple = dlsym(mgl, "glLineStipple"); *(void **)&a_glLineStipple = apple ? dlsym(apple, "glLineStipple") : (void*)0; if (p_glLineStipple) n++;
    *(void **)&p_glLineWidth = dlsym(mgl, "glLineWidth"); *(void **)&a_glLineWidth = apple ? dlsym(apple, "glLineWidth") : (void*)0; if (p_glLineWidth) n++;
    *(void **)&p_glLinkProgram = dlsym(mgl, "glLinkProgram"); *(void **)&a_glLinkProgram = apple ? dlsym(apple, "glLinkProgram") : (void*)0; if (p_glLinkProgram) n++;
    *(void **)&p_glListBase = dlsym(mgl, "glListBase"); *(void **)&a_glListBase = apple ? dlsym(apple, "glListBase") : (void*)0; if (p_glListBase) n++;
    *(void **)&p_glLoadIdentity = dlsym(mgl, "glLoadIdentity"); *(void **)&a_glLoadIdentity = apple ? dlsym(apple, "glLoadIdentity") : (void*)0; if (p_glLoadIdentity) n++;
    *(void **)&p_glLoadMatrixd = dlsym(mgl, "glLoadMatrixd"); *(void **)&a_glLoadMatrixd = apple ? dlsym(apple, "glLoadMatrixd") : (void*)0; if (p_glLoadMatrixd) n++;
    *(void **)&p_glLoadMatrixf = dlsym(mgl, "glLoadMatrixf"); *(void **)&a_glLoadMatrixf = apple ? dlsym(apple, "glLoadMatrixf") : (void*)0; if (p_glLoadMatrixf) n++;
    *(void **)&p_glLoadName = dlsym(mgl, "glLoadName"); *(void **)&a_glLoadName = apple ? dlsym(apple, "glLoadName") : (void*)0; if (p_glLoadName) n++;
    *(void **)&p_glLoadTransposeMatrixd = dlsym(mgl, "glLoadTransposeMatrixd"); *(void **)&a_glLoadTransposeMatrixd = apple ? dlsym(apple, "glLoadTransposeMatrixd") : (void*)0; if (p_glLoadTransposeMatrixd) n++;
    *(void **)&p_glLoadTransposeMatrixf = dlsym(mgl, "glLoadTransposeMatrixf"); *(void **)&a_glLoadTransposeMatrixf = apple ? dlsym(apple, "glLoadTransposeMatrixf") : (void*)0; if (p_glLoadTransposeMatrixf) n++;
    *(void **)&p_glLogicOp = dlsym(mgl, "glLogicOp"); *(void **)&a_glLogicOp = apple ? dlsym(apple, "glLogicOp") : (void*)0; if (p_glLogicOp) n++;
    *(void **)&p_glMap1d = dlsym(mgl, "glMap1d"); *(void **)&a_glMap1d = apple ? dlsym(apple, "glMap1d") : (void*)0; if (p_glMap1d) n++;
    *(void **)&p_glMap1f = dlsym(mgl, "glMap1f"); *(void **)&a_glMap1f = apple ? dlsym(apple, "glMap1f") : (void*)0; if (p_glMap1f) n++;
    *(void **)&p_glMap2d = dlsym(mgl, "glMap2d"); *(void **)&a_glMap2d = apple ? dlsym(apple, "glMap2d") : (void*)0; if (p_glMap2d) n++;
    *(void **)&p_glMap2f = dlsym(mgl, "glMap2f"); *(void **)&a_glMap2f = apple ? dlsym(apple, "glMap2f") : (void*)0; if (p_glMap2f) n++;
    *(void **)&p_glMapBuffer = dlsym(mgl, "glMapBuffer"); *(void **)&a_glMapBuffer = apple ? dlsym(apple, "glMapBuffer") : (void*)0; if (p_glMapBuffer) n++;
    *(void **)&p_glMapBufferRange = dlsym(mgl, "glMapBufferRange"); *(void **)&a_glMapBufferRange = apple ? dlsym(apple, "glMapBufferRange") : (void*)0; if (p_glMapBufferRange) n++;
    *(void **)&p_glMapGrid1d = dlsym(mgl, "glMapGrid1d"); *(void **)&a_glMapGrid1d = apple ? dlsym(apple, "glMapGrid1d") : (void*)0; if (p_glMapGrid1d) n++;
    *(void **)&p_glMapGrid1f = dlsym(mgl, "glMapGrid1f"); *(void **)&a_glMapGrid1f = apple ? dlsym(apple, "glMapGrid1f") : (void*)0; if (p_glMapGrid1f) n++;
    *(void **)&p_glMapGrid2d = dlsym(mgl, "glMapGrid2d"); *(void **)&a_glMapGrid2d = apple ? dlsym(apple, "glMapGrid2d") : (void*)0; if (p_glMapGrid2d) n++;
    *(void **)&p_glMapGrid2f = dlsym(mgl, "glMapGrid2f"); *(void **)&a_glMapGrid2f = apple ? dlsym(apple, "glMapGrid2f") : (void*)0; if (p_glMapGrid2f) n++;
    *(void **)&p_glMapNamedBuffer = dlsym(mgl, "glMapNamedBuffer"); *(void **)&a_glMapNamedBuffer = apple ? dlsym(apple, "glMapNamedBuffer") : (void*)0; if (p_glMapNamedBuffer) n++;
    *(void **)&p_glMapNamedBufferRange = dlsym(mgl, "glMapNamedBufferRange"); *(void **)&a_glMapNamedBufferRange = apple ? dlsym(apple, "glMapNamedBufferRange") : (void*)0; if (p_glMapNamedBufferRange) n++;
    *(void **)&p_glMaterialf = dlsym(mgl, "glMaterialf"); *(void **)&a_glMaterialf = apple ? dlsym(apple, "glMaterialf") : (void*)0; if (p_glMaterialf) n++;
    *(void **)&p_glMaterialfv = dlsym(mgl, "glMaterialfv"); *(void **)&a_glMaterialfv = apple ? dlsym(apple, "glMaterialfv") : (void*)0; if (p_glMaterialfv) n++;
    *(void **)&p_glMateriali = dlsym(mgl, "glMateriali"); *(void **)&a_glMateriali = apple ? dlsym(apple, "glMateriali") : (void*)0; if (p_glMateriali) n++;
    *(void **)&p_glMaterialiv = dlsym(mgl, "glMaterialiv"); *(void **)&a_glMaterialiv = apple ? dlsym(apple, "glMaterialiv") : (void*)0; if (p_glMaterialiv) n++;
    *(void **)&p_glMatrixMode = dlsym(mgl, "glMatrixMode"); *(void **)&a_glMatrixMode = apple ? dlsym(apple, "glMatrixMode") : (void*)0; if (p_glMatrixMode) n++;
    *(void **)&p_glMemoryBarrier = dlsym(mgl, "glMemoryBarrier"); *(void **)&a_glMemoryBarrier = apple ? dlsym(apple, "glMemoryBarrier") : (void*)0; if (p_glMemoryBarrier) n++;
    *(void **)&p_glMemoryBarrierByRegion = dlsym(mgl, "glMemoryBarrierByRegion"); *(void **)&a_glMemoryBarrierByRegion = apple ? dlsym(apple, "glMemoryBarrierByRegion") : (void*)0; if (p_glMemoryBarrierByRegion) n++;
    *(void **)&p_glMinSampleShading = dlsym(mgl, "glMinSampleShading"); *(void **)&a_glMinSampleShading = apple ? dlsym(apple, "glMinSampleShading") : (void*)0; if (p_glMinSampleShading) n++;
    *(void **)&p_glMultMatrixd = dlsym(mgl, "glMultMatrixd"); *(void **)&a_glMultMatrixd = apple ? dlsym(apple, "glMultMatrixd") : (void*)0; if (p_glMultMatrixd) n++;
    *(void **)&p_glMultMatrixf = dlsym(mgl, "glMultMatrixf"); *(void **)&a_glMultMatrixf = apple ? dlsym(apple, "glMultMatrixf") : (void*)0; if (p_glMultMatrixf) n++;
    *(void **)&p_glMultTransposeMatrixd = dlsym(mgl, "glMultTransposeMatrixd"); *(void **)&a_glMultTransposeMatrixd = apple ? dlsym(apple, "glMultTransposeMatrixd") : (void*)0; if (p_glMultTransposeMatrixd) n++;
    *(void **)&p_glMultTransposeMatrixf = dlsym(mgl, "glMultTransposeMatrixf"); *(void **)&a_glMultTransposeMatrixf = apple ? dlsym(apple, "glMultTransposeMatrixf") : (void*)0; if (p_glMultTransposeMatrixf) n++;
    *(void **)&p_glMultiDrawArrays = dlsym(mgl, "glMultiDrawArrays"); *(void **)&a_glMultiDrawArrays = apple ? dlsym(apple, "glMultiDrawArrays") : (void*)0; if (p_glMultiDrawArrays) n++;
    *(void **)&p_glMultiDrawArraysIndirect = dlsym(mgl, "glMultiDrawArraysIndirect"); *(void **)&a_glMultiDrawArraysIndirect = apple ? dlsym(apple, "glMultiDrawArraysIndirect") : (void*)0; if (p_glMultiDrawArraysIndirect) n++;
    *(void **)&p_glMultiDrawArraysIndirectCount = dlsym(mgl, "glMultiDrawArraysIndirectCount"); *(void **)&a_glMultiDrawArraysIndirectCount = apple ? dlsym(apple, "glMultiDrawArraysIndirectCount") : (void*)0; if (p_glMultiDrawArraysIndirectCount) n++;
    *(void **)&p_glMultiDrawElements = dlsym(mgl, "glMultiDrawElements"); *(void **)&a_glMultiDrawElements = apple ? dlsym(apple, "glMultiDrawElements") : (void*)0; if (p_glMultiDrawElements) n++;
    *(void **)&p_glMultiDrawElementsBaseVertex = dlsym(mgl, "glMultiDrawElementsBaseVertex"); *(void **)&a_glMultiDrawElementsBaseVertex = apple ? dlsym(apple, "glMultiDrawElementsBaseVertex") : (void*)0; if (p_glMultiDrawElementsBaseVertex) n++;
    *(void **)&p_glMultiDrawElementsIndirect = dlsym(mgl, "glMultiDrawElementsIndirect"); *(void **)&a_glMultiDrawElementsIndirect = apple ? dlsym(apple, "glMultiDrawElementsIndirect") : (void*)0; if (p_glMultiDrawElementsIndirect) n++;
    *(void **)&p_glMultiDrawElementsIndirectCount = dlsym(mgl, "glMultiDrawElementsIndirectCount"); *(void **)&a_glMultiDrawElementsIndirectCount = apple ? dlsym(apple, "glMultiDrawElementsIndirectCount") : (void*)0; if (p_glMultiDrawElementsIndirectCount) n++;
    *(void **)&p_glMultiTexCoord1d = dlsym(mgl, "glMultiTexCoord1d"); *(void **)&a_glMultiTexCoord1d = apple ? dlsym(apple, "glMultiTexCoord1d") : (void*)0; if (p_glMultiTexCoord1d) n++;
    *(void **)&p_glMultiTexCoord1dv = dlsym(mgl, "glMultiTexCoord1dv"); *(void **)&a_glMultiTexCoord1dv = apple ? dlsym(apple, "glMultiTexCoord1dv") : (void*)0; if (p_glMultiTexCoord1dv) n++;
    *(void **)&p_glMultiTexCoord1f = dlsym(mgl, "glMultiTexCoord1f"); *(void **)&a_glMultiTexCoord1f = apple ? dlsym(apple, "glMultiTexCoord1f") : (void*)0; if (p_glMultiTexCoord1f) n++;
    *(void **)&p_glMultiTexCoord1fv = dlsym(mgl, "glMultiTexCoord1fv"); *(void **)&a_glMultiTexCoord1fv = apple ? dlsym(apple, "glMultiTexCoord1fv") : (void*)0; if (p_glMultiTexCoord1fv) n++;
    *(void **)&p_glMultiTexCoord1i = dlsym(mgl, "glMultiTexCoord1i"); *(void **)&a_glMultiTexCoord1i = apple ? dlsym(apple, "glMultiTexCoord1i") : (void*)0; if (p_glMultiTexCoord1i) n++;
    *(void **)&p_glMultiTexCoord1iv = dlsym(mgl, "glMultiTexCoord1iv"); *(void **)&a_glMultiTexCoord1iv = apple ? dlsym(apple, "glMultiTexCoord1iv") : (void*)0; if (p_glMultiTexCoord1iv) n++;
    *(void **)&p_glMultiTexCoord1s = dlsym(mgl, "glMultiTexCoord1s"); *(void **)&a_glMultiTexCoord1s = apple ? dlsym(apple, "glMultiTexCoord1s") : (void*)0; if (p_glMultiTexCoord1s) n++;
    *(void **)&p_glMultiTexCoord1sv = dlsym(mgl, "glMultiTexCoord1sv"); *(void **)&a_glMultiTexCoord1sv = apple ? dlsym(apple, "glMultiTexCoord1sv") : (void*)0; if (p_glMultiTexCoord1sv) n++;
    *(void **)&p_glMultiTexCoord2d = dlsym(mgl, "glMultiTexCoord2d"); *(void **)&a_glMultiTexCoord2d = apple ? dlsym(apple, "glMultiTexCoord2d") : (void*)0; if (p_glMultiTexCoord2d) n++;
    *(void **)&p_glMultiTexCoord2dv = dlsym(mgl, "glMultiTexCoord2dv"); *(void **)&a_glMultiTexCoord2dv = apple ? dlsym(apple, "glMultiTexCoord2dv") : (void*)0; if (p_glMultiTexCoord2dv) n++;
    *(void **)&p_glMultiTexCoord2f = dlsym(mgl, "glMultiTexCoord2f"); *(void **)&a_glMultiTexCoord2f = apple ? dlsym(apple, "glMultiTexCoord2f") : (void*)0; if (p_glMultiTexCoord2f) n++;
    *(void **)&p_glMultiTexCoord2fv = dlsym(mgl, "glMultiTexCoord2fv"); *(void **)&a_glMultiTexCoord2fv = apple ? dlsym(apple, "glMultiTexCoord2fv") : (void*)0; if (p_glMultiTexCoord2fv) n++;
    *(void **)&p_glMultiTexCoord2i = dlsym(mgl, "glMultiTexCoord2i"); *(void **)&a_glMultiTexCoord2i = apple ? dlsym(apple, "glMultiTexCoord2i") : (void*)0; if (p_glMultiTexCoord2i) n++;
    *(void **)&p_glMultiTexCoord2iv = dlsym(mgl, "glMultiTexCoord2iv"); *(void **)&a_glMultiTexCoord2iv = apple ? dlsym(apple, "glMultiTexCoord2iv") : (void*)0; if (p_glMultiTexCoord2iv) n++;
    *(void **)&p_glMultiTexCoord2s = dlsym(mgl, "glMultiTexCoord2s"); *(void **)&a_glMultiTexCoord2s = apple ? dlsym(apple, "glMultiTexCoord2s") : (void*)0; if (p_glMultiTexCoord2s) n++;
    *(void **)&p_glMultiTexCoord2sv = dlsym(mgl, "glMultiTexCoord2sv"); *(void **)&a_glMultiTexCoord2sv = apple ? dlsym(apple, "glMultiTexCoord2sv") : (void*)0; if (p_glMultiTexCoord2sv) n++;
    *(void **)&p_glMultiTexCoord3d = dlsym(mgl, "glMultiTexCoord3d"); *(void **)&a_glMultiTexCoord3d = apple ? dlsym(apple, "glMultiTexCoord3d") : (void*)0; if (p_glMultiTexCoord3d) n++;
    *(void **)&p_glMultiTexCoord3dv = dlsym(mgl, "glMultiTexCoord3dv"); *(void **)&a_glMultiTexCoord3dv = apple ? dlsym(apple, "glMultiTexCoord3dv") : (void*)0; if (p_glMultiTexCoord3dv) n++;
    *(void **)&p_glMultiTexCoord3f = dlsym(mgl, "glMultiTexCoord3f"); *(void **)&a_glMultiTexCoord3f = apple ? dlsym(apple, "glMultiTexCoord3f") : (void*)0; if (p_glMultiTexCoord3f) n++;
    *(void **)&p_glMultiTexCoord3fv = dlsym(mgl, "glMultiTexCoord3fv"); *(void **)&a_glMultiTexCoord3fv = apple ? dlsym(apple, "glMultiTexCoord3fv") : (void*)0; if (p_glMultiTexCoord3fv) n++;
    *(void **)&p_glMultiTexCoord3i = dlsym(mgl, "glMultiTexCoord3i"); *(void **)&a_glMultiTexCoord3i = apple ? dlsym(apple, "glMultiTexCoord3i") : (void*)0; if (p_glMultiTexCoord3i) n++;
    *(void **)&p_glMultiTexCoord3iv = dlsym(mgl, "glMultiTexCoord3iv"); *(void **)&a_glMultiTexCoord3iv = apple ? dlsym(apple, "glMultiTexCoord3iv") : (void*)0; if (p_glMultiTexCoord3iv) n++;
    *(void **)&p_glMultiTexCoord3s = dlsym(mgl, "glMultiTexCoord3s"); *(void **)&a_glMultiTexCoord3s = apple ? dlsym(apple, "glMultiTexCoord3s") : (void*)0; if (p_glMultiTexCoord3s) n++;
    *(void **)&p_glMultiTexCoord3sv = dlsym(mgl, "glMultiTexCoord3sv"); *(void **)&a_glMultiTexCoord3sv = apple ? dlsym(apple, "glMultiTexCoord3sv") : (void*)0; if (p_glMultiTexCoord3sv) n++;
    *(void **)&p_glMultiTexCoord4d = dlsym(mgl, "glMultiTexCoord4d"); *(void **)&a_glMultiTexCoord4d = apple ? dlsym(apple, "glMultiTexCoord4d") : (void*)0; if (p_glMultiTexCoord4d) n++;
    *(void **)&p_glMultiTexCoord4dv = dlsym(mgl, "glMultiTexCoord4dv"); *(void **)&a_glMultiTexCoord4dv = apple ? dlsym(apple, "glMultiTexCoord4dv") : (void*)0; if (p_glMultiTexCoord4dv) n++;
    *(void **)&p_glMultiTexCoord4f = dlsym(mgl, "glMultiTexCoord4f"); *(void **)&a_glMultiTexCoord4f = apple ? dlsym(apple, "glMultiTexCoord4f") : (void*)0; if (p_glMultiTexCoord4f) n++;
    *(void **)&p_glMultiTexCoord4fv = dlsym(mgl, "glMultiTexCoord4fv"); *(void **)&a_glMultiTexCoord4fv = apple ? dlsym(apple, "glMultiTexCoord4fv") : (void*)0; if (p_glMultiTexCoord4fv) n++;
    *(void **)&p_glMultiTexCoord4i = dlsym(mgl, "glMultiTexCoord4i"); *(void **)&a_glMultiTexCoord4i = apple ? dlsym(apple, "glMultiTexCoord4i") : (void*)0; if (p_glMultiTexCoord4i) n++;
    *(void **)&p_glMultiTexCoord4iv = dlsym(mgl, "glMultiTexCoord4iv"); *(void **)&a_glMultiTexCoord4iv = apple ? dlsym(apple, "glMultiTexCoord4iv") : (void*)0; if (p_glMultiTexCoord4iv) n++;
    *(void **)&p_glMultiTexCoord4s = dlsym(mgl, "glMultiTexCoord4s"); *(void **)&a_glMultiTexCoord4s = apple ? dlsym(apple, "glMultiTexCoord4s") : (void*)0; if (p_glMultiTexCoord4s) n++;
    *(void **)&p_glMultiTexCoord4sv = dlsym(mgl, "glMultiTexCoord4sv"); *(void **)&a_glMultiTexCoord4sv = apple ? dlsym(apple, "glMultiTexCoord4sv") : (void*)0; if (p_glMultiTexCoord4sv) n++;
    *(void **)&p_glMultiTexCoordP1ui = dlsym(mgl, "glMultiTexCoordP1ui"); *(void **)&a_glMultiTexCoordP1ui = apple ? dlsym(apple, "glMultiTexCoordP1ui") : (void*)0; if (p_glMultiTexCoordP1ui) n++;
    *(void **)&p_glMultiTexCoordP1uiv = dlsym(mgl, "glMultiTexCoordP1uiv"); *(void **)&a_glMultiTexCoordP1uiv = apple ? dlsym(apple, "glMultiTexCoordP1uiv") : (void*)0; if (p_glMultiTexCoordP1uiv) n++;
    *(void **)&p_glMultiTexCoordP2ui = dlsym(mgl, "glMultiTexCoordP2ui"); *(void **)&a_glMultiTexCoordP2ui = apple ? dlsym(apple, "glMultiTexCoordP2ui") : (void*)0; if (p_glMultiTexCoordP2ui) n++;
    *(void **)&p_glMultiTexCoordP2uiv = dlsym(mgl, "glMultiTexCoordP2uiv"); *(void **)&a_glMultiTexCoordP2uiv = apple ? dlsym(apple, "glMultiTexCoordP2uiv") : (void*)0; if (p_glMultiTexCoordP2uiv) n++;
    *(void **)&p_glMultiTexCoordP3ui = dlsym(mgl, "glMultiTexCoordP3ui"); *(void **)&a_glMultiTexCoordP3ui = apple ? dlsym(apple, "glMultiTexCoordP3ui") : (void*)0; if (p_glMultiTexCoordP3ui) n++;
    *(void **)&p_glMultiTexCoordP3uiv = dlsym(mgl, "glMultiTexCoordP3uiv"); *(void **)&a_glMultiTexCoordP3uiv = apple ? dlsym(apple, "glMultiTexCoordP3uiv") : (void*)0; if (p_glMultiTexCoordP3uiv) n++;
    *(void **)&p_glMultiTexCoordP4ui = dlsym(mgl, "glMultiTexCoordP4ui"); *(void **)&a_glMultiTexCoordP4ui = apple ? dlsym(apple, "glMultiTexCoordP4ui") : (void*)0; if (p_glMultiTexCoordP4ui) n++;
    *(void **)&p_glMultiTexCoordP4uiv = dlsym(mgl, "glMultiTexCoordP4uiv"); *(void **)&a_glMultiTexCoordP4uiv = apple ? dlsym(apple, "glMultiTexCoordP4uiv") : (void*)0; if (p_glMultiTexCoordP4uiv) n++;
    *(void **)&p_glNamedBufferData = dlsym(mgl, "glNamedBufferData"); *(void **)&a_glNamedBufferData = apple ? dlsym(apple, "glNamedBufferData") : (void*)0; if (p_glNamedBufferData) n++;
    *(void **)&p_glNamedBufferStorage = dlsym(mgl, "glNamedBufferStorage"); *(void **)&a_glNamedBufferStorage = apple ? dlsym(apple, "glNamedBufferStorage") : (void*)0; if (p_glNamedBufferStorage) n++;
    *(void **)&p_glNamedBufferSubData = dlsym(mgl, "glNamedBufferSubData"); *(void **)&a_glNamedBufferSubData = apple ? dlsym(apple, "glNamedBufferSubData") : (void*)0; if (p_glNamedBufferSubData) n++;
    *(void **)&p_glNamedFramebufferDrawBuffer = dlsym(mgl, "glNamedFramebufferDrawBuffer"); *(void **)&a_glNamedFramebufferDrawBuffer = apple ? dlsym(apple, "glNamedFramebufferDrawBuffer") : (void*)0; if (p_glNamedFramebufferDrawBuffer) n++;
    *(void **)&p_glNamedFramebufferDrawBuffers = dlsym(mgl, "glNamedFramebufferDrawBuffers"); *(void **)&a_glNamedFramebufferDrawBuffers = apple ? dlsym(apple, "glNamedFramebufferDrawBuffers") : (void*)0; if (p_glNamedFramebufferDrawBuffers) n++;
    *(void **)&p_glNamedFramebufferParameteri = dlsym(mgl, "glNamedFramebufferParameteri"); *(void **)&a_glNamedFramebufferParameteri = apple ? dlsym(apple, "glNamedFramebufferParameteri") : (void*)0; if (p_glNamedFramebufferParameteri) n++;
    *(void **)&p_glNamedFramebufferReadBuffer = dlsym(mgl, "glNamedFramebufferReadBuffer"); *(void **)&a_glNamedFramebufferReadBuffer = apple ? dlsym(apple, "glNamedFramebufferReadBuffer") : (void*)0; if (p_glNamedFramebufferReadBuffer) n++;
    *(void **)&p_glNamedFramebufferRenderbuffer = dlsym(mgl, "glNamedFramebufferRenderbuffer"); *(void **)&a_glNamedFramebufferRenderbuffer = apple ? dlsym(apple, "glNamedFramebufferRenderbuffer") : (void*)0; if (p_glNamedFramebufferRenderbuffer) n++;
    *(void **)&p_glNamedFramebufferTexture = dlsym(mgl, "glNamedFramebufferTexture"); *(void **)&a_glNamedFramebufferTexture = apple ? dlsym(apple, "glNamedFramebufferTexture") : (void*)0; if (p_glNamedFramebufferTexture) n++;
    *(void **)&p_glNamedFramebufferTextureLayer = dlsym(mgl, "glNamedFramebufferTextureLayer"); *(void **)&a_glNamedFramebufferTextureLayer = apple ? dlsym(apple, "glNamedFramebufferTextureLayer") : (void*)0; if (p_glNamedFramebufferTextureLayer) n++;
    *(void **)&p_glNamedRenderbufferStorage = dlsym(mgl, "glNamedRenderbufferStorage"); *(void **)&a_glNamedRenderbufferStorage = apple ? dlsym(apple, "glNamedRenderbufferStorage") : (void*)0; if (p_glNamedRenderbufferStorage) n++;
    *(void **)&p_glNamedRenderbufferStorageMultisample = dlsym(mgl, "glNamedRenderbufferStorageMultisample"); *(void **)&a_glNamedRenderbufferStorageMultisample = apple ? dlsym(apple, "glNamedRenderbufferStorageMultisample") : (void*)0; if (p_glNamedRenderbufferStorageMultisample) n++;
    *(void **)&p_glNewList = dlsym(mgl, "glNewList"); *(void **)&a_glNewList = apple ? dlsym(apple, "glNewList") : (void*)0; if (p_glNewList) n++;
    *(void **)&p_glNormal3b = dlsym(mgl, "glNormal3b"); *(void **)&a_glNormal3b = apple ? dlsym(apple, "glNormal3b") : (void*)0; if (p_glNormal3b) n++;
    *(void **)&p_glNormal3bv = dlsym(mgl, "glNormal3bv"); *(void **)&a_glNormal3bv = apple ? dlsym(apple, "glNormal3bv") : (void*)0; if (p_glNormal3bv) n++;
    *(void **)&p_glNormal3d = dlsym(mgl, "glNormal3d"); *(void **)&a_glNormal3d = apple ? dlsym(apple, "glNormal3d") : (void*)0; if (p_glNormal3d) n++;
    *(void **)&p_glNormal3dv = dlsym(mgl, "glNormal3dv"); *(void **)&a_glNormal3dv = apple ? dlsym(apple, "glNormal3dv") : (void*)0; if (p_glNormal3dv) n++;
    *(void **)&p_glNormal3f = dlsym(mgl, "glNormal3f"); *(void **)&a_glNormal3f = apple ? dlsym(apple, "glNormal3f") : (void*)0; if (p_glNormal3f) n++;
    *(void **)&p_glNormal3fv = dlsym(mgl, "glNormal3fv"); *(void **)&a_glNormal3fv = apple ? dlsym(apple, "glNormal3fv") : (void*)0; if (p_glNormal3fv) n++;
    *(void **)&p_glNormal3i = dlsym(mgl, "glNormal3i"); *(void **)&a_glNormal3i = apple ? dlsym(apple, "glNormal3i") : (void*)0; if (p_glNormal3i) n++;
    *(void **)&p_glNormal3iv = dlsym(mgl, "glNormal3iv"); *(void **)&a_glNormal3iv = apple ? dlsym(apple, "glNormal3iv") : (void*)0; if (p_glNormal3iv) n++;
    *(void **)&p_glNormal3s = dlsym(mgl, "glNormal3s"); *(void **)&a_glNormal3s = apple ? dlsym(apple, "glNormal3s") : (void*)0; if (p_glNormal3s) n++;
    *(void **)&p_glNormal3sv = dlsym(mgl, "glNormal3sv"); *(void **)&a_glNormal3sv = apple ? dlsym(apple, "glNormal3sv") : (void*)0; if (p_glNormal3sv) n++;
    *(void **)&p_glNormalP3ui = dlsym(mgl, "glNormalP3ui"); *(void **)&a_glNormalP3ui = apple ? dlsym(apple, "glNormalP3ui") : (void*)0; if (p_glNormalP3ui) n++;
    *(void **)&p_glNormalP3uiv = dlsym(mgl, "glNormalP3uiv"); *(void **)&a_glNormalP3uiv = apple ? dlsym(apple, "glNormalP3uiv") : (void*)0; if (p_glNormalP3uiv) n++;
    *(void **)&p_glNormalPointer = dlsym(mgl, "glNormalPointer"); *(void **)&a_glNormalPointer = apple ? dlsym(apple, "glNormalPointer") : (void*)0; if (p_glNormalPointer) n++;
    *(void **)&p_glObjectLabel = dlsym(mgl, "glObjectLabel"); *(void **)&a_glObjectLabel = apple ? dlsym(apple, "glObjectLabel") : (void*)0; if (p_glObjectLabel) n++;
    *(void **)&p_glObjectPtrLabel = dlsym(mgl, "glObjectPtrLabel"); *(void **)&a_glObjectPtrLabel = apple ? dlsym(apple, "glObjectPtrLabel") : (void*)0; if (p_glObjectPtrLabel) n++;
    *(void **)&p_glOrtho = dlsym(mgl, "glOrtho"); *(void **)&a_glOrtho = apple ? dlsym(apple, "glOrtho") : (void*)0; if (p_glOrtho) n++;
    *(void **)&p_glPassThrough = dlsym(mgl, "glPassThrough"); *(void **)&a_glPassThrough = apple ? dlsym(apple, "glPassThrough") : (void*)0; if (p_glPassThrough) n++;
    *(void **)&p_glPatchParameterfv = dlsym(mgl, "glPatchParameterfv"); *(void **)&a_glPatchParameterfv = apple ? dlsym(apple, "glPatchParameterfv") : (void*)0; if (p_glPatchParameterfv) n++;
    *(void **)&p_glPatchParameteri = dlsym(mgl, "glPatchParameteri"); *(void **)&a_glPatchParameteri = apple ? dlsym(apple, "glPatchParameteri") : (void*)0; if (p_glPatchParameteri) n++;
    *(void **)&p_glPauseTransformFeedback = dlsym(mgl, "glPauseTransformFeedback"); *(void **)&a_glPauseTransformFeedback = apple ? dlsym(apple, "glPauseTransformFeedback") : (void*)0; if (p_glPauseTransformFeedback) n++;
    *(void **)&p_glPixelMapfv = dlsym(mgl, "glPixelMapfv"); *(void **)&a_glPixelMapfv = apple ? dlsym(apple, "glPixelMapfv") : (void*)0; if (p_glPixelMapfv) n++;
    *(void **)&p_glPixelMapuiv = dlsym(mgl, "glPixelMapuiv"); *(void **)&a_glPixelMapuiv = apple ? dlsym(apple, "glPixelMapuiv") : (void*)0; if (p_glPixelMapuiv) n++;
    *(void **)&p_glPixelMapusv = dlsym(mgl, "glPixelMapusv"); *(void **)&a_glPixelMapusv = apple ? dlsym(apple, "glPixelMapusv") : (void*)0; if (p_glPixelMapusv) n++;
    *(void **)&p_glPixelStoref = dlsym(mgl, "glPixelStoref"); *(void **)&a_glPixelStoref = apple ? dlsym(apple, "glPixelStoref") : (void*)0; if (p_glPixelStoref) n++;
    *(void **)&p_glPixelStorei = dlsym(mgl, "glPixelStorei"); *(void **)&a_glPixelStorei = apple ? dlsym(apple, "glPixelStorei") : (void*)0; if (p_glPixelStorei) n++;
    *(void **)&p_glPixelTransferf = dlsym(mgl, "glPixelTransferf"); *(void **)&a_glPixelTransferf = apple ? dlsym(apple, "glPixelTransferf") : (void*)0; if (p_glPixelTransferf) n++;
    *(void **)&p_glPixelTransferi = dlsym(mgl, "glPixelTransferi"); *(void **)&a_glPixelTransferi = apple ? dlsym(apple, "glPixelTransferi") : (void*)0; if (p_glPixelTransferi) n++;
    *(void **)&p_glPixelZoom = dlsym(mgl, "glPixelZoom"); *(void **)&a_glPixelZoom = apple ? dlsym(apple, "glPixelZoom") : (void*)0; if (p_glPixelZoom) n++;
    *(void **)&p_glPointParameterf = dlsym(mgl, "glPointParameterf"); *(void **)&a_glPointParameterf = apple ? dlsym(apple, "glPointParameterf") : (void*)0; if (p_glPointParameterf) n++;
    *(void **)&p_glPointParameterfv = dlsym(mgl, "glPointParameterfv"); *(void **)&a_glPointParameterfv = apple ? dlsym(apple, "glPointParameterfv") : (void*)0; if (p_glPointParameterfv) n++;
    *(void **)&p_glPointParameteri = dlsym(mgl, "glPointParameteri"); *(void **)&a_glPointParameteri = apple ? dlsym(apple, "glPointParameteri") : (void*)0; if (p_glPointParameteri) n++;
    *(void **)&p_glPointParameteriv = dlsym(mgl, "glPointParameteriv"); *(void **)&a_glPointParameteriv = apple ? dlsym(apple, "glPointParameteriv") : (void*)0; if (p_glPointParameteriv) n++;
    *(void **)&p_glPointSize = dlsym(mgl, "glPointSize"); *(void **)&a_glPointSize = apple ? dlsym(apple, "glPointSize") : (void*)0; if (p_glPointSize) n++;
    *(void **)&p_glPolygonMode = dlsym(mgl, "glPolygonMode"); *(void **)&a_glPolygonMode = apple ? dlsym(apple, "glPolygonMode") : (void*)0; if (p_glPolygonMode) n++;
    *(void **)&p_glPolygonOffset = dlsym(mgl, "glPolygonOffset"); *(void **)&a_glPolygonOffset = apple ? dlsym(apple, "glPolygonOffset") : (void*)0; if (p_glPolygonOffset) n++;
    *(void **)&p_glPolygonOffsetClamp = dlsym(mgl, "glPolygonOffsetClamp"); *(void **)&a_glPolygonOffsetClamp = apple ? dlsym(apple, "glPolygonOffsetClamp") : (void*)0; if (p_glPolygonOffsetClamp) n++;
    *(void **)&p_glPolygonStipple = dlsym(mgl, "glPolygonStipple"); *(void **)&a_glPolygonStipple = apple ? dlsym(apple, "glPolygonStipple") : (void*)0; if (p_glPolygonStipple) n++;
    *(void **)&p_glPopAttrib = dlsym(mgl, "glPopAttrib"); *(void **)&a_glPopAttrib = apple ? dlsym(apple, "glPopAttrib") : (void*)0; if (p_glPopAttrib) n++;
    *(void **)&p_glPopClientAttrib = dlsym(mgl, "glPopClientAttrib"); *(void **)&a_glPopClientAttrib = apple ? dlsym(apple, "glPopClientAttrib") : (void*)0; if (p_glPopClientAttrib) n++;
    *(void **)&p_glPopDebugGroup = dlsym(mgl, "glPopDebugGroup"); *(void **)&a_glPopDebugGroup = apple ? dlsym(apple, "glPopDebugGroup") : (void*)0; if (p_glPopDebugGroup) n++;
    *(void **)&p_glPopMatrix = dlsym(mgl, "glPopMatrix"); *(void **)&a_glPopMatrix = apple ? dlsym(apple, "glPopMatrix") : (void*)0; if (p_glPopMatrix) n++;
    *(void **)&p_glPopName = dlsym(mgl, "glPopName"); *(void **)&a_glPopName = apple ? dlsym(apple, "glPopName") : (void*)0; if (p_glPopName) n++;
    *(void **)&p_glPrimitiveRestartIndex = dlsym(mgl, "glPrimitiveRestartIndex"); *(void **)&a_glPrimitiveRestartIndex = apple ? dlsym(apple, "glPrimitiveRestartIndex") : (void*)0; if (p_glPrimitiveRestartIndex) n++;
    *(void **)&p_glPrioritizeTextures = dlsym(mgl, "glPrioritizeTextures"); *(void **)&a_glPrioritizeTextures = apple ? dlsym(apple, "glPrioritizeTextures") : (void*)0; if (p_glPrioritizeTextures) n++;
    *(void **)&p_glProgramBinary = dlsym(mgl, "glProgramBinary"); *(void **)&a_glProgramBinary = apple ? dlsym(apple, "glProgramBinary") : (void*)0; if (p_glProgramBinary) n++;
    *(void **)&p_glProgramParameteri = dlsym(mgl, "glProgramParameteri"); *(void **)&a_glProgramParameteri = apple ? dlsym(apple, "glProgramParameteri") : (void*)0; if (p_glProgramParameteri) n++;
    *(void **)&p_glProgramUniform1d = dlsym(mgl, "glProgramUniform1d"); *(void **)&a_glProgramUniform1d = apple ? dlsym(apple, "glProgramUniform1d") : (void*)0; if (p_glProgramUniform1d) n++;
    *(void **)&p_glProgramUniform1dv = dlsym(mgl, "glProgramUniform1dv"); *(void **)&a_glProgramUniform1dv = apple ? dlsym(apple, "glProgramUniform1dv") : (void*)0; if (p_glProgramUniform1dv) n++;
    *(void **)&p_glProgramUniform1f = dlsym(mgl, "glProgramUniform1f"); *(void **)&a_glProgramUniform1f = apple ? dlsym(apple, "glProgramUniform1f") : (void*)0; if (p_glProgramUniform1f) n++;
    *(void **)&p_glProgramUniform1fv = dlsym(mgl, "glProgramUniform1fv"); *(void **)&a_glProgramUniform1fv = apple ? dlsym(apple, "glProgramUniform1fv") : (void*)0; if (p_glProgramUniform1fv) n++;
    *(void **)&p_glProgramUniform1i = dlsym(mgl, "glProgramUniform1i"); *(void **)&a_glProgramUniform1i = apple ? dlsym(apple, "glProgramUniform1i") : (void*)0; if (p_glProgramUniform1i) n++;
    *(void **)&p_glProgramUniform1iv = dlsym(mgl, "glProgramUniform1iv"); *(void **)&a_glProgramUniform1iv = apple ? dlsym(apple, "glProgramUniform1iv") : (void*)0; if (p_glProgramUniform1iv) n++;
    *(void **)&p_glProgramUniform1ui = dlsym(mgl, "glProgramUniform1ui"); *(void **)&a_glProgramUniform1ui = apple ? dlsym(apple, "glProgramUniform1ui") : (void*)0; if (p_glProgramUniform1ui) n++;
    *(void **)&p_glProgramUniform1uiv = dlsym(mgl, "glProgramUniform1uiv"); *(void **)&a_glProgramUniform1uiv = apple ? dlsym(apple, "glProgramUniform1uiv") : (void*)0; if (p_glProgramUniform1uiv) n++;
    *(void **)&p_glProgramUniform2d = dlsym(mgl, "glProgramUniform2d"); *(void **)&a_glProgramUniform2d = apple ? dlsym(apple, "glProgramUniform2d") : (void*)0; if (p_glProgramUniform2d) n++;
    *(void **)&p_glProgramUniform2dv = dlsym(mgl, "glProgramUniform2dv"); *(void **)&a_glProgramUniform2dv = apple ? dlsym(apple, "glProgramUniform2dv") : (void*)0; if (p_glProgramUniform2dv) n++;
    *(void **)&p_glProgramUniform2f = dlsym(mgl, "glProgramUniform2f"); *(void **)&a_glProgramUniform2f = apple ? dlsym(apple, "glProgramUniform2f") : (void*)0; if (p_glProgramUniform2f) n++;
    *(void **)&p_glProgramUniform2fv = dlsym(mgl, "glProgramUniform2fv"); *(void **)&a_glProgramUniform2fv = apple ? dlsym(apple, "glProgramUniform2fv") : (void*)0; if (p_glProgramUniform2fv) n++;
    *(void **)&p_glProgramUniform2i = dlsym(mgl, "glProgramUniform2i"); *(void **)&a_glProgramUniform2i = apple ? dlsym(apple, "glProgramUniform2i") : (void*)0; if (p_glProgramUniform2i) n++;
    *(void **)&p_glProgramUniform2iv = dlsym(mgl, "glProgramUniform2iv"); *(void **)&a_glProgramUniform2iv = apple ? dlsym(apple, "glProgramUniform2iv") : (void*)0; if (p_glProgramUniform2iv) n++;
    *(void **)&p_glProgramUniform2ui = dlsym(mgl, "glProgramUniform2ui"); *(void **)&a_glProgramUniform2ui = apple ? dlsym(apple, "glProgramUniform2ui") : (void*)0; if (p_glProgramUniform2ui) n++;
    *(void **)&p_glProgramUniform2uiv = dlsym(mgl, "glProgramUniform2uiv"); *(void **)&a_glProgramUniform2uiv = apple ? dlsym(apple, "glProgramUniform2uiv") : (void*)0; if (p_glProgramUniform2uiv) n++;
    *(void **)&p_glProgramUniform3d = dlsym(mgl, "glProgramUniform3d"); *(void **)&a_glProgramUniform3d = apple ? dlsym(apple, "glProgramUniform3d") : (void*)0; if (p_glProgramUniform3d) n++;
    *(void **)&p_glProgramUniform3dv = dlsym(mgl, "glProgramUniform3dv"); *(void **)&a_glProgramUniform3dv = apple ? dlsym(apple, "glProgramUniform3dv") : (void*)0; if (p_glProgramUniform3dv) n++;
    *(void **)&p_glProgramUniform3f = dlsym(mgl, "glProgramUniform3f"); *(void **)&a_glProgramUniform3f = apple ? dlsym(apple, "glProgramUniform3f") : (void*)0; if (p_glProgramUniform3f) n++;
    *(void **)&p_glProgramUniform3fv = dlsym(mgl, "glProgramUniform3fv"); *(void **)&a_glProgramUniform3fv = apple ? dlsym(apple, "glProgramUniform3fv") : (void*)0; if (p_glProgramUniform3fv) n++;
    *(void **)&p_glProgramUniform3i = dlsym(mgl, "glProgramUniform3i"); *(void **)&a_glProgramUniform3i = apple ? dlsym(apple, "glProgramUniform3i") : (void*)0; if (p_glProgramUniform3i) n++;
    *(void **)&p_glProgramUniform3iv = dlsym(mgl, "glProgramUniform3iv"); *(void **)&a_glProgramUniform3iv = apple ? dlsym(apple, "glProgramUniform3iv") : (void*)0; if (p_glProgramUniform3iv) n++;
    *(void **)&p_glProgramUniform3ui = dlsym(mgl, "glProgramUniform3ui"); *(void **)&a_glProgramUniform3ui = apple ? dlsym(apple, "glProgramUniform3ui") : (void*)0; if (p_glProgramUniform3ui) n++;
    *(void **)&p_glProgramUniform3uiv = dlsym(mgl, "glProgramUniform3uiv"); *(void **)&a_glProgramUniform3uiv = apple ? dlsym(apple, "glProgramUniform3uiv") : (void*)0; if (p_glProgramUniform3uiv) n++;
    *(void **)&p_glProgramUniform4d = dlsym(mgl, "glProgramUniform4d"); *(void **)&a_glProgramUniform4d = apple ? dlsym(apple, "glProgramUniform4d") : (void*)0; if (p_glProgramUniform4d) n++;
    *(void **)&p_glProgramUniform4dv = dlsym(mgl, "glProgramUniform4dv"); *(void **)&a_glProgramUniform4dv = apple ? dlsym(apple, "glProgramUniform4dv") : (void*)0; if (p_glProgramUniform4dv) n++;
    *(void **)&p_glProgramUniform4f = dlsym(mgl, "glProgramUniform4f"); *(void **)&a_glProgramUniform4f = apple ? dlsym(apple, "glProgramUniform4f") : (void*)0; if (p_glProgramUniform4f) n++;
    *(void **)&p_glProgramUniform4fv = dlsym(mgl, "glProgramUniform4fv"); *(void **)&a_glProgramUniform4fv = apple ? dlsym(apple, "glProgramUniform4fv") : (void*)0; if (p_glProgramUniform4fv) n++;
    *(void **)&p_glProgramUniform4i = dlsym(mgl, "glProgramUniform4i"); *(void **)&a_glProgramUniform4i = apple ? dlsym(apple, "glProgramUniform4i") : (void*)0; if (p_glProgramUniform4i) n++;
    *(void **)&p_glProgramUniform4iv = dlsym(mgl, "glProgramUniform4iv"); *(void **)&a_glProgramUniform4iv = apple ? dlsym(apple, "glProgramUniform4iv") : (void*)0; if (p_glProgramUniform4iv) n++;
    *(void **)&p_glProgramUniform4ui = dlsym(mgl, "glProgramUniform4ui"); *(void **)&a_glProgramUniform4ui = apple ? dlsym(apple, "glProgramUniform4ui") : (void*)0; if (p_glProgramUniform4ui) n++;
    *(void **)&p_glProgramUniform4uiv = dlsym(mgl, "glProgramUniform4uiv"); *(void **)&a_glProgramUniform4uiv = apple ? dlsym(apple, "glProgramUniform4uiv") : (void*)0; if (p_glProgramUniform4uiv) n++;
    *(void **)&p_glProgramUniformMatrix2dv = dlsym(mgl, "glProgramUniformMatrix2dv"); *(void **)&a_glProgramUniformMatrix2dv = apple ? dlsym(apple, "glProgramUniformMatrix2dv") : (void*)0; if (p_glProgramUniformMatrix2dv) n++;
    *(void **)&p_glProgramUniformMatrix2fv = dlsym(mgl, "glProgramUniformMatrix2fv"); *(void **)&a_glProgramUniformMatrix2fv = apple ? dlsym(apple, "glProgramUniformMatrix2fv") : (void*)0; if (p_glProgramUniformMatrix2fv) n++;
    *(void **)&p_glProgramUniformMatrix2x3dv = dlsym(mgl, "glProgramUniformMatrix2x3dv"); *(void **)&a_glProgramUniformMatrix2x3dv = apple ? dlsym(apple, "glProgramUniformMatrix2x3dv") : (void*)0; if (p_glProgramUniformMatrix2x3dv) n++;
    *(void **)&p_glProgramUniformMatrix2x3fv = dlsym(mgl, "glProgramUniformMatrix2x3fv"); *(void **)&a_glProgramUniformMatrix2x3fv = apple ? dlsym(apple, "glProgramUniformMatrix2x3fv") : (void*)0; if (p_glProgramUniformMatrix2x3fv) n++;
    *(void **)&p_glProgramUniformMatrix2x4dv = dlsym(mgl, "glProgramUniformMatrix2x4dv"); *(void **)&a_glProgramUniformMatrix2x4dv = apple ? dlsym(apple, "glProgramUniformMatrix2x4dv") : (void*)0; if (p_glProgramUniformMatrix2x4dv) n++;
    *(void **)&p_glProgramUniformMatrix2x4fv = dlsym(mgl, "glProgramUniformMatrix2x4fv"); *(void **)&a_glProgramUniformMatrix2x4fv = apple ? dlsym(apple, "glProgramUniformMatrix2x4fv") : (void*)0; if (p_glProgramUniformMatrix2x4fv) n++;
    *(void **)&p_glProgramUniformMatrix3dv = dlsym(mgl, "glProgramUniformMatrix3dv"); *(void **)&a_glProgramUniformMatrix3dv = apple ? dlsym(apple, "glProgramUniformMatrix3dv") : (void*)0; if (p_glProgramUniformMatrix3dv) n++;
    *(void **)&p_glProgramUniformMatrix3fv = dlsym(mgl, "glProgramUniformMatrix3fv"); *(void **)&a_glProgramUniformMatrix3fv = apple ? dlsym(apple, "glProgramUniformMatrix3fv") : (void*)0; if (p_glProgramUniformMatrix3fv) n++;
    *(void **)&p_glProgramUniformMatrix3x2dv = dlsym(mgl, "glProgramUniformMatrix3x2dv"); *(void **)&a_glProgramUniformMatrix3x2dv = apple ? dlsym(apple, "glProgramUniformMatrix3x2dv") : (void*)0; if (p_glProgramUniformMatrix3x2dv) n++;
    *(void **)&p_glProgramUniformMatrix3x2fv = dlsym(mgl, "glProgramUniformMatrix3x2fv"); *(void **)&a_glProgramUniformMatrix3x2fv = apple ? dlsym(apple, "glProgramUniformMatrix3x2fv") : (void*)0; if (p_glProgramUniformMatrix3x2fv) n++;
    *(void **)&p_glProgramUniformMatrix3x4dv = dlsym(mgl, "glProgramUniformMatrix3x4dv"); *(void **)&a_glProgramUniformMatrix3x4dv = apple ? dlsym(apple, "glProgramUniformMatrix3x4dv") : (void*)0; if (p_glProgramUniformMatrix3x4dv) n++;
    *(void **)&p_glProgramUniformMatrix3x4fv = dlsym(mgl, "glProgramUniformMatrix3x4fv"); *(void **)&a_glProgramUniformMatrix3x4fv = apple ? dlsym(apple, "glProgramUniformMatrix3x4fv") : (void*)0; if (p_glProgramUniformMatrix3x4fv) n++;
    *(void **)&p_glProgramUniformMatrix4dv = dlsym(mgl, "glProgramUniformMatrix4dv"); *(void **)&a_glProgramUniformMatrix4dv = apple ? dlsym(apple, "glProgramUniformMatrix4dv") : (void*)0; if (p_glProgramUniformMatrix4dv) n++;
    *(void **)&p_glProgramUniformMatrix4fv = dlsym(mgl, "glProgramUniformMatrix4fv"); *(void **)&a_glProgramUniformMatrix4fv = apple ? dlsym(apple, "glProgramUniformMatrix4fv") : (void*)0; if (p_glProgramUniformMatrix4fv) n++;
    *(void **)&p_glProgramUniformMatrix4x2dv = dlsym(mgl, "glProgramUniformMatrix4x2dv"); *(void **)&a_glProgramUniformMatrix4x2dv = apple ? dlsym(apple, "glProgramUniformMatrix4x2dv") : (void*)0; if (p_glProgramUniformMatrix4x2dv) n++;
    *(void **)&p_glProgramUniformMatrix4x2fv = dlsym(mgl, "glProgramUniformMatrix4x2fv"); *(void **)&a_glProgramUniformMatrix4x2fv = apple ? dlsym(apple, "glProgramUniformMatrix4x2fv") : (void*)0; if (p_glProgramUniformMatrix4x2fv) n++;
    *(void **)&p_glProgramUniformMatrix4x3dv = dlsym(mgl, "glProgramUniformMatrix4x3dv"); *(void **)&a_glProgramUniformMatrix4x3dv = apple ? dlsym(apple, "glProgramUniformMatrix4x3dv") : (void*)0; if (p_glProgramUniformMatrix4x3dv) n++;
    *(void **)&p_glProgramUniformMatrix4x3fv = dlsym(mgl, "glProgramUniformMatrix4x3fv"); *(void **)&a_glProgramUniformMatrix4x3fv = apple ? dlsym(apple, "glProgramUniformMatrix4x3fv") : (void*)0; if (p_glProgramUniformMatrix4x3fv) n++;
    *(void **)&p_glProvokingVertex = dlsym(mgl, "glProvokingVertex"); *(void **)&a_glProvokingVertex = apple ? dlsym(apple, "glProvokingVertex") : (void*)0; if (p_glProvokingVertex) n++;
    *(void **)&p_glPushAttrib = dlsym(mgl, "glPushAttrib"); *(void **)&a_glPushAttrib = apple ? dlsym(apple, "glPushAttrib") : (void*)0; if (p_glPushAttrib) n++;
    *(void **)&p_glPushClientAttrib = dlsym(mgl, "glPushClientAttrib"); *(void **)&a_glPushClientAttrib = apple ? dlsym(apple, "glPushClientAttrib") : (void*)0; if (p_glPushClientAttrib) n++;
    *(void **)&p_glPushDebugGroup = dlsym(mgl, "glPushDebugGroup"); *(void **)&a_glPushDebugGroup = apple ? dlsym(apple, "glPushDebugGroup") : (void*)0; if (p_glPushDebugGroup) n++;
    *(void **)&p_glPushMatrix = dlsym(mgl, "glPushMatrix"); *(void **)&a_glPushMatrix = apple ? dlsym(apple, "glPushMatrix") : (void*)0; if (p_glPushMatrix) n++;
    *(void **)&p_glPushName = dlsym(mgl, "glPushName"); *(void **)&a_glPushName = apple ? dlsym(apple, "glPushName") : (void*)0; if (p_glPushName) n++;
    *(void **)&p_glQueryCounter = dlsym(mgl, "glQueryCounter"); *(void **)&a_glQueryCounter = apple ? dlsym(apple, "glQueryCounter") : (void*)0; if (p_glQueryCounter) n++;
    *(void **)&p_glRasterPos2d = dlsym(mgl, "glRasterPos2d"); *(void **)&a_glRasterPos2d = apple ? dlsym(apple, "glRasterPos2d") : (void*)0; if (p_glRasterPos2d) n++;
    *(void **)&p_glRasterPos2dv = dlsym(mgl, "glRasterPos2dv"); *(void **)&a_glRasterPos2dv = apple ? dlsym(apple, "glRasterPos2dv") : (void*)0; if (p_glRasterPos2dv) n++;
    *(void **)&p_glRasterPos2f = dlsym(mgl, "glRasterPos2f"); *(void **)&a_glRasterPos2f = apple ? dlsym(apple, "glRasterPos2f") : (void*)0; if (p_glRasterPos2f) n++;
    *(void **)&p_glRasterPos2fv = dlsym(mgl, "glRasterPos2fv"); *(void **)&a_glRasterPos2fv = apple ? dlsym(apple, "glRasterPos2fv") : (void*)0; if (p_glRasterPos2fv) n++;
    *(void **)&p_glRasterPos2i = dlsym(mgl, "glRasterPos2i"); *(void **)&a_glRasterPos2i = apple ? dlsym(apple, "glRasterPos2i") : (void*)0; if (p_glRasterPos2i) n++;
    *(void **)&p_glRasterPos2iv = dlsym(mgl, "glRasterPos2iv"); *(void **)&a_glRasterPos2iv = apple ? dlsym(apple, "glRasterPos2iv") : (void*)0; if (p_glRasterPos2iv) n++;
    *(void **)&p_glRasterPos2s = dlsym(mgl, "glRasterPos2s"); *(void **)&a_glRasterPos2s = apple ? dlsym(apple, "glRasterPos2s") : (void*)0; if (p_glRasterPos2s) n++;
    *(void **)&p_glRasterPos2sv = dlsym(mgl, "glRasterPos2sv"); *(void **)&a_glRasterPos2sv = apple ? dlsym(apple, "glRasterPos2sv") : (void*)0; if (p_glRasterPos2sv) n++;
    *(void **)&p_glRasterPos3d = dlsym(mgl, "glRasterPos3d"); *(void **)&a_glRasterPos3d = apple ? dlsym(apple, "glRasterPos3d") : (void*)0; if (p_glRasterPos3d) n++;
    *(void **)&p_glRasterPos3dv = dlsym(mgl, "glRasterPos3dv"); *(void **)&a_glRasterPos3dv = apple ? dlsym(apple, "glRasterPos3dv") : (void*)0; if (p_glRasterPos3dv) n++;
    *(void **)&p_glRasterPos3f = dlsym(mgl, "glRasterPos3f"); *(void **)&a_glRasterPos3f = apple ? dlsym(apple, "glRasterPos3f") : (void*)0; if (p_glRasterPos3f) n++;
    *(void **)&p_glRasterPos3fv = dlsym(mgl, "glRasterPos3fv"); *(void **)&a_glRasterPos3fv = apple ? dlsym(apple, "glRasterPos3fv") : (void*)0; if (p_glRasterPos3fv) n++;
    *(void **)&p_glRasterPos3i = dlsym(mgl, "glRasterPos3i"); *(void **)&a_glRasterPos3i = apple ? dlsym(apple, "glRasterPos3i") : (void*)0; if (p_glRasterPos3i) n++;
    *(void **)&p_glRasterPos3iv = dlsym(mgl, "glRasterPos3iv"); *(void **)&a_glRasterPos3iv = apple ? dlsym(apple, "glRasterPos3iv") : (void*)0; if (p_glRasterPos3iv) n++;
    *(void **)&p_glRasterPos3s = dlsym(mgl, "glRasterPos3s"); *(void **)&a_glRasterPos3s = apple ? dlsym(apple, "glRasterPos3s") : (void*)0; if (p_glRasterPos3s) n++;
    *(void **)&p_glRasterPos3sv = dlsym(mgl, "glRasterPos3sv"); *(void **)&a_glRasterPos3sv = apple ? dlsym(apple, "glRasterPos3sv") : (void*)0; if (p_glRasterPos3sv) n++;
    *(void **)&p_glRasterPos4d = dlsym(mgl, "glRasterPos4d"); *(void **)&a_glRasterPos4d = apple ? dlsym(apple, "glRasterPos4d") : (void*)0; if (p_glRasterPos4d) n++;
    *(void **)&p_glRasterPos4dv = dlsym(mgl, "glRasterPos4dv"); *(void **)&a_glRasterPos4dv = apple ? dlsym(apple, "glRasterPos4dv") : (void*)0; if (p_glRasterPos4dv) n++;
    *(void **)&p_glRasterPos4f = dlsym(mgl, "glRasterPos4f"); *(void **)&a_glRasterPos4f = apple ? dlsym(apple, "glRasterPos4f") : (void*)0; if (p_glRasterPos4f) n++;
    *(void **)&p_glRasterPos4fv = dlsym(mgl, "glRasterPos4fv"); *(void **)&a_glRasterPos4fv = apple ? dlsym(apple, "glRasterPos4fv") : (void*)0; if (p_glRasterPos4fv) n++;
    *(void **)&p_glRasterPos4i = dlsym(mgl, "glRasterPos4i"); *(void **)&a_glRasterPos4i = apple ? dlsym(apple, "glRasterPos4i") : (void*)0; if (p_glRasterPos4i) n++;
    *(void **)&p_glRasterPos4iv = dlsym(mgl, "glRasterPos4iv"); *(void **)&a_glRasterPos4iv = apple ? dlsym(apple, "glRasterPos4iv") : (void*)0; if (p_glRasterPos4iv) n++;
    *(void **)&p_glRasterPos4s = dlsym(mgl, "glRasterPos4s"); *(void **)&a_glRasterPos4s = apple ? dlsym(apple, "glRasterPos4s") : (void*)0; if (p_glRasterPos4s) n++;
    *(void **)&p_glRasterPos4sv = dlsym(mgl, "glRasterPos4sv"); *(void **)&a_glRasterPos4sv = apple ? dlsym(apple, "glRasterPos4sv") : (void*)0; if (p_glRasterPos4sv) n++;
    *(void **)&p_glReadBuffer = dlsym(mgl, "glReadBuffer"); *(void **)&a_glReadBuffer = apple ? dlsym(apple, "glReadBuffer") : (void*)0; if (p_glReadBuffer) n++;
    *(void **)&p_glReadPixels = dlsym(mgl, "glReadPixels"); *(void **)&a_glReadPixels = apple ? dlsym(apple, "glReadPixels") : (void*)0; if (p_glReadPixels) n++;
    *(void **)&p_glReadnPixels = dlsym(mgl, "glReadnPixels"); *(void **)&a_glReadnPixels = apple ? dlsym(apple, "glReadnPixels") : (void*)0; if (p_glReadnPixels) n++;
    *(void **)&p_glRectd = dlsym(mgl, "glRectd"); *(void **)&a_glRectd = apple ? dlsym(apple, "glRectd") : (void*)0; if (p_glRectd) n++;
    *(void **)&p_glRectdv = dlsym(mgl, "glRectdv"); *(void **)&a_glRectdv = apple ? dlsym(apple, "glRectdv") : (void*)0; if (p_glRectdv) n++;
    *(void **)&p_glRectf = dlsym(mgl, "glRectf"); *(void **)&a_glRectf = apple ? dlsym(apple, "glRectf") : (void*)0; if (p_glRectf) n++;
    *(void **)&p_glRectfv = dlsym(mgl, "glRectfv"); *(void **)&a_glRectfv = apple ? dlsym(apple, "glRectfv") : (void*)0; if (p_glRectfv) n++;
    *(void **)&p_glRecti = dlsym(mgl, "glRecti"); *(void **)&a_glRecti = apple ? dlsym(apple, "glRecti") : (void*)0; if (p_glRecti) n++;
    *(void **)&p_glRectiv = dlsym(mgl, "glRectiv"); *(void **)&a_glRectiv = apple ? dlsym(apple, "glRectiv") : (void*)0; if (p_glRectiv) n++;
    *(void **)&p_glRects = dlsym(mgl, "glRects"); *(void **)&a_glRects = apple ? dlsym(apple, "glRects") : (void*)0; if (p_glRects) n++;
    *(void **)&p_glRectsv = dlsym(mgl, "glRectsv"); *(void **)&a_glRectsv = apple ? dlsym(apple, "glRectsv") : (void*)0; if (p_glRectsv) n++;
    *(void **)&p_glReleaseShaderCompiler = dlsym(mgl, "glReleaseShaderCompiler"); *(void **)&a_glReleaseShaderCompiler = apple ? dlsym(apple, "glReleaseShaderCompiler") : (void*)0; if (p_glReleaseShaderCompiler) n++;
    *(void **)&p_glRenderMode = dlsym(mgl, "glRenderMode"); *(void **)&a_glRenderMode = apple ? dlsym(apple, "glRenderMode") : (void*)0; if (p_glRenderMode) n++;
    *(void **)&p_glRenderbufferStorage = dlsym(mgl, "glRenderbufferStorage"); *(void **)&a_glRenderbufferStorage = apple ? dlsym(apple, "glRenderbufferStorage") : (void*)0; if (p_glRenderbufferStorage) n++;
    *(void **)&p_glRenderbufferStorageMultisample = dlsym(mgl, "glRenderbufferStorageMultisample"); *(void **)&a_glRenderbufferStorageMultisample = apple ? dlsym(apple, "glRenderbufferStorageMultisample") : (void*)0; if (p_glRenderbufferStorageMultisample) n++;
    *(void **)&p_glResumeTransformFeedback = dlsym(mgl, "glResumeTransformFeedback"); *(void **)&a_glResumeTransformFeedback = apple ? dlsym(apple, "glResumeTransformFeedback") : (void*)0; if (p_glResumeTransformFeedback) n++;
    *(void **)&p_glRotated = dlsym(mgl, "glRotated"); *(void **)&a_glRotated = apple ? dlsym(apple, "glRotated") : (void*)0; if (p_glRotated) n++;
    *(void **)&p_glRotatef = dlsym(mgl, "glRotatef"); *(void **)&a_glRotatef = apple ? dlsym(apple, "glRotatef") : (void*)0; if (p_glRotatef) n++;
    *(void **)&p_glSampleCoverage = dlsym(mgl, "glSampleCoverage"); *(void **)&a_glSampleCoverage = apple ? dlsym(apple, "glSampleCoverage") : (void*)0; if (p_glSampleCoverage) n++;
    *(void **)&p_glSampleMaski = dlsym(mgl, "glSampleMaski"); *(void **)&a_glSampleMaski = apple ? dlsym(apple, "glSampleMaski") : (void*)0; if (p_glSampleMaski) n++;
    *(void **)&p_glSamplerParameterIiv = dlsym(mgl, "glSamplerParameterIiv"); *(void **)&a_glSamplerParameterIiv = apple ? dlsym(apple, "glSamplerParameterIiv") : (void*)0; if (p_glSamplerParameterIiv) n++;
    *(void **)&p_glSamplerParameterIuiv = dlsym(mgl, "glSamplerParameterIuiv"); *(void **)&a_glSamplerParameterIuiv = apple ? dlsym(apple, "glSamplerParameterIuiv") : (void*)0; if (p_glSamplerParameterIuiv) n++;
    *(void **)&p_glSamplerParameterf = dlsym(mgl, "glSamplerParameterf"); *(void **)&a_glSamplerParameterf = apple ? dlsym(apple, "glSamplerParameterf") : (void*)0; if (p_glSamplerParameterf) n++;
    *(void **)&p_glSamplerParameterfv = dlsym(mgl, "glSamplerParameterfv"); *(void **)&a_glSamplerParameterfv = apple ? dlsym(apple, "glSamplerParameterfv") : (void*)0; if (p_glSamplerParameterfv) n++;
    *(void **)&p_glSamplerParameteri = dlsym(mgl, "glSamplerParameteri"); *(void **)&a_glSamplerParameteri = apple ? dlsym(apple, "glSamplerParameteri") : (void*)0; if (p_glSamplerParameteri) n++;
    *(void **)&p_glSamplerParameteriv = dlsym(mgl, "glSamplerParameteriv"); *(void **)&a_glSamplerParameteriv = apple ? dlsym(apple, "glSamplerParameteriv") : (void*)0; if (p_glSamplerParameteriv) n++;
    *(void **)&p_glScaled = dlsym(mgl, "glScaled"); *(void **)&a_glScaled = apple ? dlsym(apple, "glScaled") : (void*)0; if (p_glScaled) n++;
    *(void **)&p_glScalef = dlsym(mgl, "glScalef"); *(void **)&a_glScalef = apple ? dlsym(apple, "glScalef") : (void*)0; if (p_glScalef) n++;
    *(void **)&p_glScissor = dlsym(mgl, "glScissor"); *(void **)&a_glScissor = apple ? dlsym(apple, "glScissor") : (void*)0; if (p_glScissor) n++;
    *(void **)&p_glScissorArrayv = dlsym(mgl, "glScissorArrayv"); *(void **)&a_glScissorArrayv = apple ? dlsym(apple, "glScissorArrayv") : (void*)0; if (p_glScissorArrayv) n++;
    *(void **)&p_glScissorIndexed = dlsym(mgl, "glScissorIndexed"); *(void **)&a_glScissorIndexed = apple ? dlsym(apple, "glScissorIndexed") : (void*)0; if (p_glScissorIndexed) n++;
    *(void **)&p_glScissorIndexedv = dlsym(mgl, "glScissorIndexedv"); *(void **)&a_glScissorIndexedv = apple ? dlsym(apple, "glScissorIndexedv") : (void*)0; if (p_glScissorIndexedv) n++;
    *(void **)&p_glSecondaryColor3b = dlsym(mgl, "glSecondaryColor3b"); *(void **)&a_glSecondaryColor3b = apple ? dlsym(apple, "glSecondaryColor3b") : (void*)0; if (p_glSecondaryColor3b) n++;
    *(void **)&p_glSecondaryColor3bv = dlsym(mgl, "glSecondaryColor3bv"); *(void **)&a_glSecondaryColor3bv = apple ? dlsym(apple, "glSecondaryColor3bv") : (void*)0; if (p_glSecondaryColor3bv) n++;
    *(void **)&p_glSecondaryColor3d = dlsym(mgl, "glSecondaryColor3d"); *(void **)&a_glSecondaryColor3d = apple ? dlsym(apple, "glSecondaryColor3d") : (void*)0; if (p_glSecondaryColor3d) n++;
    *(void **)&p_glSecondaryColor3dv = dlsym(mgl, "glSecondaryColor3dv"); *(void **)&a_glSecondaryColor3dv = apple ? dlsym(apple, "glSecondaryColor3dv") : (void*)0; if (p_glSecondaryColor3dv) n++;
    *(void **)&p_glSecondaryColor3f = dlsym(mgl, "glSecondaryColor3f"); *(void **)&a_glSecondaryColor3f = apple ? dlsym(apple, "glSecondaryColor3f") : (void*)0; if (p_glSecondaryColor3f) n++;
    *(void **)&p_glSecondaryColor3fv = dlsym(mgl, "glSecondaryColor3fv"); *(void **)&a_glSecondaryColor3fv = apple ? dlsym(apple, "glSecondaryColor3fv") : (void*)0; if (p_glSecondaryColor3fv) n++;
    *(void **)&p_glSecondaryColor3i = dlsym(mgl, "glSecondaryColor3i"); *(void **)&a_glSecondaryColor3i = apple ? dlsym(apple, "glSecondaryColor3i") : (void*)0; if (p_glSecondaryColor3i) n++;
    *(void **)&p_glSecondaryColor3iv = dlsym(mgl, "glSecondaryColor3iv"); *(void **)&a_glSecondaryColor3iv = apple ? dlsym(apple, "glSecondaryColor3iv") : (void*)0; if (p_glSecondaryColor3iv) n++;
    *(void **)&p_glSecondaryColor3s = dlsym(mgl, "glSecondaryColor3s"); *(void **)&a_glSecondaryColor3s = apple ? dlsym(apple, "glSecondaryColor3s") : (void*)0; if (p_glSecondaryColor3s) n++;
    *(void **)&p_glSecondaryColor3sv = dlsym(mgl, "glSecondaryColor3sv"); *(void **)&a_glSecondaryColor3sv = apple ? dlsym(apple, "glSecondaryColor3sv") : (void*)0; if (p_glSecondaryColor3sv) n++;
    *(void **)&p_glSecondaryColor3ub = dlsym(mgl, "glSecondaryColor3ub"); *(void **)&a_glSecondaryColor3ub = apple ? dlsym(apple, "glSecondaryColor3ub") : (void*)0; if (p_glSecondaryColor3ub) n++;
    *(void **)&p_glSecondaryColor3ubv = dlsym(mgl, "glSecondaryColor3ubv"); *(void **)&a_glSecondaryColor3ubv = apple ? dlsym(apple, "glSecondaryColor3ubv") : (void*)0; if (p_glSecondaryColor3ubv) n++;
    *(void **)&p_glSecondaryColor3ui = dlsym(mgl, "glSecondaryColor3ui"); *(void **)&a_glSecondaryColor3ui = apple ? dlsym(apple, "glSecondaryColor3ui") : (void*)0; if (p_glSecondaryColor3ui) n++;
    *(void **)&p_glSecondaryColor3uiv = dlsym(mgl, "glSecondaryColor3uiv"); *(void **)&a_glSecondaryColor3uiv = apple ? dlsym(apple, "glSecondaryColor3uiv") : (void*)0; if (p_glSecondaryColor3uiv) n++;
    *(void **)&p_glSecondaryColor3us = dlsym(mgl, "glSecondaryColor3us"); *(void **)&a_glSecondaryColor3us = apple ? dlsym(apple, "glSecondaryColor3us") : (void*)0; if (p_glSecondaryColor3us) n++;
    *(void **)&p_glSecondaryColor3usv = dlsym(mgl, "glSecondaryColor3usv"); *(void **)&a_glSecondaryColor3usv = apple ? dlsym(apple, "glSecondaryColor3usv") : (void*)0; if (p_glSecondaryColor3usv) n++;
    *(void **)&p_glSecondaryColorP3ui = dlsym(mgl, "glSecondaryColorP3ui"); *(void **)&a_glSecondaryColorP3ui = apple ? dlsym(apple, "glSecondaryColorP3ui") : (void*)0; if (p_glSecondaryColorP3ui) n++;
    *(void **)&p_glSecondaryColorP3uiv = dlsym(mgl, "glSecondaryColorP3uiv"); *(void **)&a_glSecondaryColorP3uiv = apple ? dlsym(apple, "glSecondaryColorP3uiv") : (void*)0; if (p_glSecondaryColorP3uiv) n++;
    *(void **)&p_glSecondaryColorPointer = dlsym(mgl, "glSecondaryColorPointer"); *(void **)&a_glSecondaryColorPointer = apple ? dlsym(apple, "glSecondaryColorPointer") : (void*)0; if (p_glSecondaryColorPointer) n++;
    *(void **)&p_glSelectBuffer = dlsym(mgl, "glSelectBuffer"); *(void **)&a_glSelectBuffer = apple ? dlsym(apple, "glSelectBuffer") : (void*)0; if (p_glSelectBuffer) n++;
    *(void **)&p_glShadeModel = dlsym(mgl, "glShadeModel"); *(void **)&a_glShadeModel = apple ? dlsym(apple, "glShadeModel") : (void*)0; if (p_glShadeModel) n++;
    *(void **)&p_glShaderBinary = dlsym(mgl, "glShaderBinary"); *(void **)&a_glShaderBinary = apple ? dlsym(apple, "glShaderBinary") : (void*)0; if (p_glShaderBinary) n++;
    *(void **)&p_glShaderSource = dlsym(mgl, "glShaderSource"); *(void **)&a_glShaderSource = apple ? dlsym(apple, "glShaderSource") : (void*)0; if (p_glShaderSource) n++;
    *(void **)&p_glShaderStorageBlockBinding = dlsym(mgl, "glShaderStorageBlockBinding"); *(void **)&a_glShaderStorageBlockBinding = apple ? dlsym(apple, "glShaderStorageBlockBinding") : (void*)0; if (p_glShaderStorageBlockBinding) n++;
    *(void **)&p_glSpecializeShader = dlsym(mgl, "glSpecializeShader"); *(void **)&a_glSpecializeShader = apple ? dlsym(apple, "glSpecializeShader") : (void*)0; if (p_glSpecializeShader) n++;
    *(void **)&p_glStencilFunc = dlsym(mgl, "glStencilFunc"); *(void **)&a_glStencilFunc = apple ? dlsym(apple, "glStencilFunc") : (void*)0; if (p_glStencilFunc) n++;
    *(void **)&p_glStencilFuncSeparate = dlsym(mgl, "glStencilFuncSeparate"); *(void **)&a_glStencilFuncSeparate = apple ? dlsym(apple, "glStencilFuncSeparate") : (void*)0; if (p_glStencilFuncSeparate) n++;
    *(void **)&p_glStencilMask = dlsym(mgl, "glStencilMask"); *(void **)&a_glStencilMask = apple ? dlsym(apple, "glStencilMask") : (void*)0; if (p_glStencilMask) n++;
    *(void **)&p_glStencilMaskSeparate = dlsym(mgl, "glStencilMaskSeparate"); *(void **)&a_glStencilMaskSeparate = apple ? dlsym(apple, "glStencilMaskSeparate") : (void*)0; if (p_glStencilMaskSeparate) n++;
    *(void **)&p_glStencilOp = dlsym(mgl, "glStencilOp"); *(void **)&a_glStencilOp = apple ? dlsym(apple, "glStencilOp") : (void*)0; if (p_glStencilOp) n++;
    *(void **)&p_glStencilOpSeparate = dlsym(mgl, "glStencilOpSeparate"); *(void **)&a_glStencilOpSeparate = apple ? dlsym(apple, "glStencilOpSeparate") : (void*)0; if (p_glStencilOpSeparate) n++;
    *(void **)&p_glTexBuffer = dlsym(mgl, "glTexBuffer"); *(void **)&a_glTexBuffer = apple ? dlsym(apple, "glTexBuffer") : (void*)0; if (p_glTexBuffer) n++;
    *(void **)&p_glTexBufferRange = dlsym(mgl, "glTexBufferRange"); *(void **)&a_glTexBufferRange = apple ? dlsym(apple, "glTexBufferRange") : (void*)0; if (p_glTexBufferRange) n++;
    *(void **)&p_glTexCoord1d = dlsym(mgl, "glTexCoord1d"); *(void **)&a_glTexCoord1d = apple ? dlsym(apple, "glTexCoord1d") : (void*)0; if (p_glTexCoord1d) n++;
    *(void **)&p_glTexCoord1dv = dlsym(mgl, "glTexCoord1dv"); *(void **)&a_glTexCoord1dv = apple ? dlsym(apple, "glTexCoord1dv") : (void*)0; if (p_glTexCoord1dv) n++;
    *(void **)&p_glTexCoord1f = dlsym(mgl, "glTexCoord1f"); *(void **)&a_glTexCoord1f = apple ? dlsym(apple, "glTexCoord1f") : (void*)0; if (p_glTexCoord1f) n++;
    *(void **)&p_glTexCoord1fv = dlsym(mgl, "glTexCoord1fv"); *(void **)&a_glTexCoord1fv = apple ? dlsym(apple, "glTexCoord1fv") : (void*)0; if (p_glTexCoord1fv) n++;
    *(void **)&p_glTexCoord1i = dlsym(mgl, "glTexCoord1i"); *(void **)&a_glTexCoord1i = apple ? dlsym(apple, "glTexCoord1i") : (void*)0; if (p_glTexCoord1i) n++;
    *(void **)&p_glTexCoord1iv = dlsym(mgl, "glTexCoord1iv"); *(void **)&a_glTexCoord1iv = apple ? dlsym(apple, "glTexCoord1iv") : (void*)0; if (p_glTexCoord1iv) n++;
    *(void **)&p_glTexCoord1s = dlsym(mgl, "glTexCoord1s"); *(void **)&a_glTexCoord1s = apple ? dlsym(apple, "glTexCoord1s") : (void*)0; if (p_glTexCoord1s) n++;
    *(void **)&p_glTexCoord1sv = dlsym(mgl, "glTexCoord1sv"); *(void **)&a_glTexCoord1sv = apple ? dlsym(apple, "glTexCoord1sv") : (void*)0; if (p_glTexCoord1sv) n++;
    *(void **)&p_glTexCoord2d = dlsym(mgl, "glTexCoord2d"); *(void **)&a_glTexCoord2d = apple ? dlsym(apple, "glTexCoord2d") : (void*)0; if (p_glTexCoord2d) n++;
    *(void **)&p_glTexCoord2dv = dlsym(mgl, "glTexCoord2dv"); *(void **)&a_glTexCoord2dv = apple ? dlsym(apple, "glTexCoord2dv") : (void*)0; if (p_glTexCoord2dv) n++;
    *(void **)&p_glTexCoord2f = dlsym(mgl, "glTexCoord2f"); *(void **)&a_glTexCoord2f = apple ? dlsym(apple, "glTexCoord2f") : (void*)0; if (p_glTexCoord2f) n++;
    *(void **)&p_glTexCoord2fv = dlsym(mgl, "glTexCoord2fv"); *(void **)&a_glTexCoord2fv = apple ? dlsym(apple, "glTexCoord2fv") : (void*)0; if (p_glTexCoord2fv) n++;
    *(void **)&p_glTexCoord2i = dlsym(mgl, "glTexCoord2i"); *(void **)&a_glTexCoord2i = apple ? dlsym(apple, "glTexCoord2i") : (void*)0; if (p_glTexCoord2i) n++;
    *(void **)&p_glTexCoord2iv = dlsym(mgl, "glTexCoord2iv"); *(void **)&a_glTexCoord2iv = apple ? dlsym(apple, "glTexCoord2iv") : (void*)0; if (p_glTexCoord2iv) n++;
    *(void **)&p_glTexCoord2s = dlsym(mgl, "glTexCoord2s"); *(void **)&a_glTexCoord2s = apple ? dlsym(apple, "glTexCoord2s") : (void*)0; if (p_glTexCoord2s) n++;
    *(void **)&p_glTexCoord2sv = dlsym(mgl, "glTexCoord2sv"); *(void **)&a_glTexCoord2sv = apple ? dlsym(apple, "glTexCoord2sv") : (void*)0; if (p_glTexCoord2sv) n++;
    *(void **)&p_glTexCoord3d = dlsym(mgl, "glTexCoord3d"); *(void **)&a_glTexCoord3d = apple ? dlsym(apple, "glTexCoord3d") : (void*)0; if (p_glTexCoord3d) n++;
    *(void **)&p_glTexCoord3dv = dlsym(mgl, "glTexCoord3dv"); *(void **)&a_glTexCoord3dv = apple ? dlsym(apple, "glTexCoord3dv") : (void*)0; if (p_glTexCoord3dv) n++;
    *(void **)&p_glTexCoord3f = dlsym(mgl, "glTexCoord3f"); *(void **)&a_glTexCoord3f = apple ? dlsym(apple, "glTexCoord3f") : (void*)0; if (p_glTexCoord3f) n++;
    *(void **)&p_glTexCoord3fv = dlsym(mgl, "glTexCoord3fv"); *(void **)&a_glTexCoord3fv = apple ? dlsym(apple, "glTexCoord3fv") : (void*)0; if (p_glTexCoord3fv) n++;
    *(void **)&p_glTexCoord3i = dlsym(mgl, "glTexCoord3i"); *(void **)&a_glTexCoord3i = apple ? dlsym(apple, "glTexCoord3i") : (void*)0; if (p_glTexCoord3i) n++;
    *(void **)&p_glTexCoord3iv = dlsym(mgl, "glTexCoord3iv"); *(void **)&a_glTexCoord3iv = apple ? dlsym(apple, "glTexCoord3iv") : (void*)0; if (p_glTexCoord3iv) n++;
    *(void **)&p_glTexCoord3s = dlsym(mgl, "glTexCoord3s"); *(void **)&a_glTexCoord3s = apple ? dlsym(apple, "glTexCoord3s") : (void*)0; if (p_glTexCoord3s) n++;
    *(void **)&p_glTexCoord3sv = dlsym(mgl, "glTexCoord3sv"); *(void **)&a_glTexCoord3sv = apple ? dlsym(apple, "glTexCoord3sv") : (void*)0; if (p_glTexCoord3sv) n++;
    *(void **)&p_glTexCoord4d = dlsym(mgl, "glTexCoord4d"); *(void **)&a_glTexCoord4d = apple ? dlsym(apple, "glTexCoord4d") : (void*)0; if (p_glTexCoord4d) n++;
    *(void **)&p_glTexCoord4dv = dlsym(mgl, "glTexCoord4dv"); *(void **)&a_glTexCoord4dv = apple ? dlsym(apple, "glTexCoord4dv") : (void*)0; if (p_glTexCoord4dv) n++;
    *(void **)&p_glTexCoord4f = dlsym(mgl, "glTexCoord4f"); *(void **)&a_glTexCoord4f = apple ? dlsym(apple, "glTexCoord4f") : (void*)0; if (p_glTexCoord4f) n++;
    *(void **)&p_glTexCoord4fv = dlsym(mgl, "glTexCoord4fv"); *(void **)&a_glTexCoord4fv = apple ? dlsym(apple, "glTexCoord4fv") : (void*)0; if (p_glTexCoord4fv) n++;
    *(void **)&p_glTexCoord4i = dlsym(mgl, "glTexCoord4i"); *(void **)&a_glTexCoord4i = apple ? dlsym(apple, "glTexCoord4i") : (void*)0; if (p_glTexCoord4i) n++;
    *(void **)&p_glTexCoord4iv = dlsym(mgl, "glTexCoord4iv"); *(void **)&a_glTexCoord4iv = apple ? dlsym(apple, "glTexCoord4iv") : (void*)0; if (p_glTexCoord4iv) n++;
    *(void **)&p_glTexCoord4s = dlsym(mgl, "glTexCoord4s"); *(void **)&a_glTexCoord4s = apple ? dlsym(apple, "glTexCoord4s") : (void*)0; if (p_glTexCoord4s) n++;
    *(void **)&p_glTexCoord4sv = dlsym(mgl, "glTexCoord4sv"); *(void **)&a_glTexCoord4sv = apple ? dlsym(apple, "glTexCoord4sv") : (void*)0; if (p_glTexCoord4sv) n++;
    *(void **)&p_glTexCoordP1ui = dlsym(mgl, "glTexCoordP1ui"); *(void **)&a_glTexCoordP1ui = apple ? dlsym(apple, "glTexCoordP1ui") : (void*)0; if (p_glTexCoordP1ui) n++;
    *(void **)&p_glTexCoordP1uiv = dlsym(mgl, "glTexCoordP1uiv"); *(void **)&a_glTexCoordP1uiv = apple ? dlsym(apple, "glTexCoordP1uiv") : (void*)0; if (p_glTexCoordP1uiv) n++;
    *(void **)&p_glTexCoordP2ui = dlsym(mgl, "glTexCoordP2ui"); *(void **)&a_glTexCoordP2ui = apple ? dlsym(apple, "glTexCoordP2ui") : (void*)0; if (p_glTexCoordP2ui) n++;
    *(void **)&p_glTexCoordP2uiv = dlsym(mgl, "glTexCoordP2uiv"); *(void **)&a_glTexCoordP2uiv = apple ? dlsym(apple, "glTexCoordP2uiv") : (void*)0; if (p_glTexCoordP2uiv) n++;
    *(void **)&p_glTexCoordP3ui = dlsym(mgl, "glTexCoordP3ui"); *(void **)&a_glTexCoordP3ui = apple ? dlsym(apple, "glTexCoordP3ui") : (void*)0; if (p_glTexCoordP3ui) n++;
    *(void **)&p_glTexCoordP3uiv = dlsym(mgl, "glTexCoordP3uiv"); *(void **)&a_glTexCoordP3uiv = apple ? dlsym(apple, "glTexCoordP3uiv") : (void*)0; if (p_glTexCoordP3uiv) n++;
    *(void **)&p_glTexCoordP4ui = dlsym(mgl, "glTexCoordP4ui"); *(void **)&a_glTexCoordP4ui = apple ? dlsym(apple, "glTexCoordP4ui") : (void*)0; if (p_glTexCoordP4ui) n++;
    *(void **)&p_glTexCoordP4uiv = dlsym(mgl, "glTexCoordP4uiv"); *(void **)&a_glTexCoordP4uiv = apple ? dlsym(apple, "glTexCoordP4uiv") : (void*)0; if (p_glTexCoordP4uiv) n++;
    *(void **)&p_glTexCoordPointer = dlsym(mgl, "glTexCoordPointer"); *(void **)&a_glTexCoordPointer = apple ? dlsym(apple, "glTexCoordPointer") : (void*)0; if (p_glTexCoordPointer) n++;
    *(void **)&p_glTexEnvf = dlsym(mgl, "glTexEnvf"); *(void **)&a_glTexEnvf = apple ? dlsym(apple, "glTexEnvf") : (void*)0; if (p_glTexEnvf) n++;
    *(void **)&p_glTexEnvfv = dlsym(mgl, "glTexEnvfv"); *(void **)&a_glTexEnvfv = apple ? dlsym(apple, "glTexEnvfv") : (void*)0; if (p_glTexEnvfv) n++;
    *(void **)&p_glTexEnvi = dlsym(mgl, "glTexEnvi"); *(void **)&a_glTexEnvi = apple ? dlsym(apple, "glTexEnvi") : (void*)0; if (p_glTexEnvi) n++;
    *(void **)&p_glTexEnviv = dlsym(mgl, "glTexEnviv"); *(void **)&a_glTexEnviv = apple ? dlsym(apple, "glTexEnviv") : (void*)0; if (p_glTexEnviv) n++;
    *(void **)&p_glTexGend = dlsym(mgl, "glTexGend"); *(void **)&a_glTexGend = apple ? dlsym(apple, "glTexGend") : (void*)0; if (p_glTexGend) n++;
    *(void **)&p_glTexGendv = dlsym(mgl, "glTexGendv"); *(void **)&a_glTexGendv = apple ? dlsym(apple, "glTexGendv") : (void*)0; if (p_glTexGendv) n++;
    *(void **)&p_glTexGenf = dlsym(mgl, "glTexGenf"); *(void **)&a_glTexGenf = apple ? dlsym(apple, "glTexGenf") : (void*)0; if (p_glTexGenf) n++;
    *(void **)&p_glTexGenfv = dlsym(mgl, "glTexGenfv"); *(void **)&a_glTexGenfv = apple ? dlsym(apple, "glTexGenfv") : (void*)0; if (p_glTexGenfv) n++;
    *(void **)&p_glTexGeni = dlsym(mgl, "glTexGeni"); *(void **)&a_glTexGeni = apple ? dlsym(apple, "glTexGeni") : (void*)0; if (p_glTexGeni) n++;
    *(void **)&p_glTexGeniv = dlsym(mgl, "glTexGeniv"); *(void **)&a_glTexGeniv = apple ? dlsym(apple, "glTexGeniv") : (void*)0; if (p_glTexGeniv) n++;
    *(void **)&p_glTexImage1D = dlsym(mgl, "glTexImage1D"); *(void **)&a_glTexImage1D = apple ? dlsym(apple, "glTexImage1D") : (void*)0; if (p_glTexImage1D) n++;
    *(void **)&p_glTexImage2D = dlsym(mgl, "glTexImage2D"); *(void **)&a_glTexImage2D = apple ? dlsym(apple, "glTexImage2D") : (void*)0; if (p_glTexImage2D) n++;
    *(void **)&p_glTexImage2DMultisample = dlsym(mgl, "glTexImage2DMultisample"); *(void **)&a_glTexImage2DMultisample = apple ? dlsym(apple, "glTexImage2DMultisample") : (void*)0; if (p_glTexImage2DMultisample) n++;
    *(void **)&p_glTexImage3D = dlsym(mgl, "glTexImage3D"); *(void **)&a_glTexImage3D = apple ? dlsym(apple, "glTexImage3D") : (void*)0; if (p_glTexImage3D) n++;
    *(void **)&p_glTexImage3DMultisample = dlsym(mgl, "glTexImage3DMultisample"); *(void **)&a_glTexImage3DMultisample = apple ? dlsym(apple, "glTexImage3DMultisample") : (void*)0; if (p_glTexImage3DMultisample) n++;
    *(void **)&p_glTexParameterIiv = dlsym(mgl, "glTexParameterIiv"); *(void **)&a_glTexParameterIiv = apple ? dlsym(apple, "glTexParameterIiv") : (void*)0; if (p_glTexParameterIiv) n++;
    *(void **)&p_glTexParameterIuiv = dlsym(mgl, "glTexParameterIuiv"); *(void **)&a_glTexParameterIuiv = apple ? dlsym(apple, "glTexParameterIuiv") : (void*)0; if (p_glTexParameterIuiv) n++;
    *(void **)&p_glTexParameterf = dlsym(mgl, "glTexParameterf"); *(void **)&a_glTexParameterf = apple ? dlsym(apple, "glTexParameterf") : (void*)0; if (p_glTexParameterf) n++;
    *(void **)&p_glTexParameterfv = dlsym(mgl, "glTexParameterfv"); *(void **)&a_glTexParameterfv = apple ? dlsym(apple, "glTexParameterfv") : (void*)0; if (p_glTexParameterfv) n++;
    *(void **)&p_glTexParameteri = dlsym(mgl, "glTexParameteri"); *(void **)&a_glTexParameteri = apple ? dlsym(apple, "glTexParameteri") : (void*)0; if (p_glTexParameteri) n++;
    *(void **)&p_glTexParameteriv = dlsym(mgl, "glTexParameteriv"); *(void **)&a_glTexParameteriv = apple ? dlsym(apple, "glTexParameteriv") : (void*)0; if (p_glTexParameteriv) n++;
    *(void **)&p_glTexStorage1D = dlsym(mgl, "glTexStorage1D"); *(void **)&a_glTexStorage1D = apple ? dlsym(apple, "glTexStorage1D") : (void*)0; if (p_glTexStorage1D) n++;
    *(void **)&p_glTexStorage2D = dlsym(mgl, "glTexStorage2D"); *(void **)&a_glTexStorage2D = apple ? dlsym(apple, "glTexStorage2D") : (void*)0; if (p_glTexStorage2D) n++;
    *(void **)&p_glTexStorage2DMultisample = dlsym(mgl, "glTexStorage2DMultisample"); *(void **)&a_glTexStorage2DMultisample = apple ? dlsym(apple, "glTexStorage2DMultisample") : (void*)0; if (p_glTexStorage2DMultisample) n++;
    *(void **)&p_glTexStorage3D = dlsym(mgl, "glTexStorage3D"); *(void **)&a_glTexStorage3D = apple ? dlsym(apple, "glTexStorage3D") : (void*)0; if (p_glTexStorage3D) n++;
    *(void **)&p_glTexStorage3DMultisample = dlsym(mgl, "glTexStorage3DMultisample"); *(void **)&a_glTexStorage3DMultisample = apple ? dlsym(apple, "glTexStorage3DMultisample") : (void*)0; if (p_glTexStorage3DMultisample) n++;
    *(void **)&p_glTexSubImage1D = dlsym(mgl, "glTexSubImage1D"); *(void **)&a_glTexSubImage1D = apple ? dlsym(apple, "glTexSubImage1D") : (void*)0; if (p_glTexSubImage1D) n++;
    *(void **)&p_glTexSubImage2D = dlsym(mgl, "glTexSubImage2D"); *(void **)&a_glTexSubImage2D = apple ? dlsym(apple, "glTexSubImage2D") : (void*)0; if (p_glTexSubImage2D) n++;
    *(void **)&p_glTexSubImage3D = dlsym(mgl, "glTexSubImage3D"); *(void **)&a_glTexSubImage3D = apple ? dlsym(apple, "glTexSubImage3D") : (void*)0; if (p_glTexSubImage3D) n++;
    *(void **)&p_glTextureBarrier = dlsym(mgl, "glTextureBarrier"); *(void **)&a_glTextureBarrier = apple ? dlsym(apple, "glTextureBarrier") : (void*)0; if (p_glTextureBarrier) n++;
    *(void **)&p_glTextureBuffer = dlsym(mgl, "glTextureBuffer"); *(void **)&a_glTextureBuffer = apple ? dlsym(apple, "glTextureBuffer") : (void*)0; if (p_glTextureBuffer) n++;
    *(void **)&p_glTextureBufferRange = dlsym(mgl, "glTextureBufferRange"); *(void **)&a_glTextureBufferRange = apple ? dlsym(apple, "glTextureBufferRange") : (void*)0; if (p_glTextureBufferRange) n++;
    *(void **)&p_glTextureParameterIiv = dlsym(mgl, "glTextureParameterIiv"); *(void **)&a_glTextureParameterIiv = apple ? dlsym(apple, "glTextureParameterIiv") : (void*)0; if (p_glTextureParameterIiv) n++;
    *(void **)&p_glTextureParameterIuiv = dlsym(mgl, "glTextureParameterIuiv"); *(void **)&a_glTextureParameterIuiv = apple ? dlsym(apple, "glTextureParameterIuiv") : (void*)0; if (p_glTextureParameterIuiv) n++;
    *(void **)&p_glTextureParameterf = dlsym(mgl, "glTextureParameterf"); *(void **)&a_glTextureParameterf = apple ? dlsym(apple, "glTextureParameterf") : (void*)0; if (p_glTextureParameterf) n++;
    *(void **)&p_glTextureParameterfv = dlsym(mgl, "glTextureParameterfv"); *(void **)&a_glTextureParameterfv = apple ? dlsym(apple, "glTextureParameterfv") : (void*)0; if (p_glTextureParameterfv) n++;
    *(void **)&p_glTextureParameteri = dlsym(mgl, "glTextureParameteri"); *(void **)&a_glTextureParameteri = apple ? dlsym(apple, "glTextureParameteri") : (void*)0; if (p_glTextureParameteri) n++;
    *(void **)&p_glTextureParameteriv = dlsym(mgl, "glTextureParameteriv"); *(void **)&a_glTextureParameteriv = apple ? dlsym(apple, "glTextureParameteriv") : (void*)0; if (p_glTextureParameteriv) n++;
    *(void **)&p_glTextureStorage1D = dlsym(mgl, "glTextureStorage1D"); *(void **)&a_glTextureStorage1D = apple ? dlsym(apple, "glTextureStorage1D") : (void*)0; if (p_glTextureStorage1D) n++;
    *(void **)&p_glTextureStorage2D = dlsym(mgl, "glTextureStorage2D"); *(void **)&a_glTextureStorage2D = apple ? dlsym(apple, "glTextureStorage2D") : (void*)0; if (p_glTextureStorage2D) n++;
    *(void **)&p_glTextureStorage2DMultisample = dlsym(mgl, "glTextureStorage2DMultisample"); *(void **)&a_glTextureStorage2DMultisample = apple ? dlsym(apple, "glTextureStorage2DMultisample") : (void*)0; if (p_glTextureStorage2DMultisample) n++;
    *(void **)&p_glTextureStorage3D = dlsym(mgl, "glTextureStorage3D"); *(void **)&a_glTextureStorage3D = apple ? dlsym(apple, "glTextureStorage3D") : (void*)0; if (p_glTextureStorage3D) n++;
    *(void **)&p_glTextureStorage3DMultisample = dlsym(mgl, "glTextureStorage3DMultisample"); *(void **)&a_glTextureStorage3DMultisample = apple ? dlsym(apple, "glTextureStorage3DMultisample") : (void*)0; if (p_glTextureStorage3DMultisample) n++;
    *(void **)&p_glTextureSubImage1D = dlsym(mgl, "glTextureSubImage1D"); *(void **)&a_glTextureSubImage1D = apple ? dlsym(apple, "glTextureSubImage1D") : (void*)0; if (p_glTextureSubImage1D) n++;
    *(void **)&p_glTextureSubImage2D = dlsym(mgl, "glTextureSubImage2D"); *(void **)&a_glTextureSubImage2D = apple ? dlsym(apple, "glTextureSubImage2D") : (void*)0; if (p_glTextureSubImage2D) n++;
    *(void **)&p_glTextureSubImage3D = dlsym(mgl, "glTextureSubImage3D"); *(void **)&a_glTextureSubImage3D = apple ? dlsym(apple, "glTextureSubImage3D") : (void*)0; if (p_glTextureSubImage3D) n++;
    *(void **)&p_glTextureView = dlsym(mgl, "glTextureView"); *(void **)&a_glTextureView = apple ? dlsym(apple, "glTextureView") : (void*)0; if (p_glTextureView) n++;
    *(void **)&p_glTransformFeedbackBufferBase = dlsym(mgl, "glTransformFeedbackBufferBase"); *(void **)&a_glTransformFeedbackBufferBase = apple ? dlsym(apple, "glTransformFeedbackBufferBase") : (void*)0; if (p_glTransformFeedbackBufferBase) n++;
    *(void **)&p_glTransformFeedbackBufferRange = dlsym(mgl, "glTransformFeedbackBufferRange"); *(void **)&a_glTransformFeedbackBufferRange = apple ? dlsym(apple, "glTransformFeedbackBufferRange") : (void*)0; if (p_glTransformFeedbackBufferRange) n++;
    *(void **)&p_glTransformFeedbackVaryings = dlsym(mgl, "glTransformFeedbackVaryings"); *(void **)&a_glTransformFeedbackVaryings = apple ? dlsym(apple, "glTransformFeedbackVaryings") : (void*)0; if (p_glTransformFeedbackVaryings) n++;
    *(void **)&p_glTranslated = dlsym(mgl, "glTranslated"); *(void **)&a_glTranslated = apple ? dlsym(apple, "glTranslated") : (void*)0; if (p_glTranslated) n++;
    *(void **)&p_glTranslatef = dlsym(mgl, "glTranslatef"); *(void **)&a_glTranslatef = apple ? dlsym(apple, "glTranslatef") : (void*)0; if (p_glTranslatef) n++;
    *(void **)&p_glUniform1d = dlsym(mgl, "glUniform1d"); *(void **)&a_glUniform1d = apple ? dlsym(apple, "glUniform1d") : (void*)0; if (p_glUniform1d) n++;
    *(void **)&p_glUniform1dv = dlsym(mgl, "glUniform1dv"); *(void **)&a_glUniform1dv = apple ? dlsym(apple, "glUniform1dv") : (void*)0; if (p_glUniform1dv) n++;
    *(void **)&p_glUniform1f = dlsym(mgl, "glUniform1f"); *(void **)&a_glUniform1f = apple ? dlsym(apple, "glUniform1f") : (void*)0; if (p_glUniform1f) n++;
    *(void **)&p_glUniform1fv = dlsym(mgl, "glUniform1fv"); *(void **)&a_glUniform1fv = apple ? dlsym(apple, "glUniform1fv") : (void*)0; if (p_glUniform1fv) n++;
    *(void **)&p_glUniform1i = dlsym(mgl, "glUniform1i"); *(void **)&a_glUniform1i = apple ? dlsym(apple, "glUniform1i") : (void*)0; if (p_glUniform1i) n++;
    *(void **)&p_glUniform1iv = dlsym(mgl, "glUniform1iv"); *(void **)&a_glUniform1iv = apple ? dlsym(apple, "glUniform1iv") : (void*)0; if (p_glUniform1iv) n++;
    *(void **)&p_glUniform1ui = dlsym(mgl, "glUniform1ui"); *(void **)&a_glUniform1ui = apple ? dlsym(apple, "glUniform1ui") : (void*)0; if (p_glUniform1ui) n++;
    *(void **)&p_glUniform1uiv = dlsym(mgl, "glUniform1uiv"); *(void **)&a_glUniform1uiv = apple ? dlsym(apple, "glUniform1uiv") : (void*)0; if (p_glUniform1uiv) n++;
    *(void **)&p_glUniform2d = dlsym(mgl, "glUniform2d"); *(void **)&a_glUniform2d = apple ? dlsym(apple, "glUniform2d") : (void*)0; if (p_glUniform2d) n++;
    *(void **)&p_glUniform2dv = dlsym(mgl, "glUniform2dv"); *(void **)&a_glUniform2dv = apple ? dlsym(apple, "glUniform2dv") : (void*)0; if (p_glUniform2dv) n++;
    *(void **)&p_glUniform2f = dlsym(mgl, "glUniform2f"); *(void **)&a_glUniform2f = apple ? dlsym(apple, "glUniform2f") : (void*)0; if (p_glUniform2f) n++;
    *(void **)&p_glUniform2fv = dlsym(mgl, "glUniform2fv"); *(void **)&a_glUniform2fv = apple ? dlsym(apple, "glUniform2fv") : (void*)0; if (p_glUniform2fv) n++;
    *(void **)&p_glUniform2i = dlsym(mgl, "glUniform2i"); *(void **)&a_glUniform2i = apple ? dlsym(apple, "glUniform2i") : (void*)0; if (p_glUniform2i) n++;
    *(void **)&p_glUniform2iv = dlsym(mgl, "glUniform2iv"); *(void **)&a_glUniform2iv = apple ? dlsym(apple, "glUniform2iv") : (void*)0; if (p_glUniform2iv) n++;
    *(void **)&p_glUniform2ui = dlsym(mgl, "glUniform2ui"); *(void **)&a_glUniform2ui = apple ? dlsym(apple, "glUniform2ui") : (void*)0; if (p_glUniform2ui) n++;
    *(void **)&p_glUniform2uiv = dlsym(mgl, "glUniform2uiv"); *(void **)&a_glUniform2uiv = apple ? dlsym(apple, "glUniform2uiv") : (void*)0; if (p_glUniform2uiv) n++;
    *(void **)&p_glUniform3d = dlsym(mgl, "glUniform3d"); *(void **)&a_glUniform3d = apple ? dlsym(apple, "glUniform3d") : (void*)0; if (p_glUniform3d) n++;
    *(void **)&p_glUniform3dv = dlsym(mgl, "glUniform3dv"); *(void **)&a_glUniform3dv = apple ? dlsym(apple, "glUniform3dv") : (void*)0; if (p_glUniform3dv) n++;
    *(void **)&p_glUniform3f = dlsym(mgl, "glUniform3f"); *(void **)&a_glUniform3f = apple ? dlsym(apple, "glUniform3f") : (void*)0; if (p_glUniform3f) n++;
    *(void **)&p_glUniform3fv = dlsym(mgl, "glUniform3fv"); *(void **)&a_glUniform3fv = apple ? dlsym(apple, "glUniform3fv") : (void*)0; if (p_glUniform3fv) n++;
    *(void **)&p_glUniform3i = dlsym(mgl, "glUniform3i"); *(void **)&a_glUniform3i = apple ? dlsym(apple, "glUniform3i") : (void*)0; if (p_glUniform3i) n++;
    *(void **)&p_glUniform3iv = dlsym(mgl, "glUniform3iv"); *(void **)&a_glUniform3iv = apple ? dlsym(apple, "glUniform3iv") : (void*)0; if (p_glUniform3iv) n++;
    *(void **)&p_glUniform3ui = dlsym(mgl, "glUniform3ui"); *(void **)&a_glUniform3ui = apple ? dlsym(apple, "glUniform3ui") : (void*)0; if (p_glUniform3ui) n++;
    *(void **)&p_glUniform3uiv = dlsym(mgl, "glUniform3uiv"); *(void **)&a_glUniform3uiv = apple ? dlsym(apple, "glUniform3uiv") : (void*)0; if (p_glUniform3uiv) n++;
    *(void **)&p_glUniform4d = dlsym(mgl, "glUniform4d"); *(void **)&a_glUniform4d = apple ? dlsym(apple, "glUniform4d") : (void*)0; if (p_glUniform4d) n++;
    *(void **)&p_glUniform4dv = dlsym(mgl, "glUniform4dv"); *(void **)&a_glUniform4dv = apple ? dlsym(apple, "glUniform4dv") : (void*)0; if (p_glUniform4dv) n++;
    *(void **)&p_glUniform4f = dlsym(mgl, "glUniform4f"); *(void **)&a_glUniform4f = apple ? dlsym(apple, "glUniform4f") : (void*)0; if (p_glUniform4f) n++;
    *(void **)&p_glUniform4fv = dlsym(mgl, "glUniform4fv"); *(void **)&a_glUniform4fv = apple ? dlsym(apple, "glUniform4fv") : (void*)0; if (p_glUniform4fv) n++;
    *(void **)&p_glUniform4i = dlsym(mgl, "glUniform4i"); *(void **)&a_glUniform4i = apple ? dlsym(apple, "glUniform4i") : (void*)0; if (p_glUniform4i) n++;
    *(void **)&p_glUniform4iv = dlsym(mgl, "glUniform4iv"); *(void **)&a_glUniform4iv = apple ? dlsym(apple, "glUniform4iv") : (void*)0; if (p_glUniform4iv) n++;
    *(void **)&p_glUniform4ui = dlsym(mgl, "glUniform4ui"); *(void **)&a_glUniform4ui = apple ? dlsym(apple, "glUniform4ui") : (void*)0; if (p_glUniform4ui) n++;
    *(void **)&p_glUniform4uiv = dlsym(mgl, "glUniform4uiv"); *(void **)&a_glUniform4uiv = apple ? dlsym(apple, "glUniform4uiv") : (void*)0; if (p_glUniform4uiv) n++;
    *(void **)&p_glUniformBlockBinding = dlsym(mgl, "glUniformBlockBinding"); *(void **)&a_glUniformBlockBinding = apple ? dlsym(apple, "glUniformBlockBinding") : (void*)0; if (p_glUniformBlockBinding) n++;
    *(void **)&p_glUniformMatrix2dv = dlsym(mgl, "glUniformMatrix2dv"); *(void **)&a_glUniformMatrix2dv = apple ? dlsym(apple, "glUniformMatrix2dv") : (void*)0; if (p_glUniformMatrix2dv) n++;
    *(void **)&p_glUniformMatrix2fv = dlsym(mgl, "glUniformMatrix2fv"); *(void **)&a_glUniformMatrix2fv = apple ? dlsym(apple, "glUniformMatrix2fv") : (void*)0; if (p_glUniformMatrix2fv) n++;
    *(void **)&p_glUniformMatrix2x3dv = dlsym(mgl, "glUniformMatrix2x3dv"); *(void **)&a_glUniformMatrix2x3dv = apple ? dlsym(apple, "glUniformMatrix2x3dv") : (void*)0; if (p_glUniformMatrix2x3dv) n++;
    *(void **)&p_glUniformMatrix2x3fv = dlsym(mgl, "glUniformMatrix2x3fv"); *(void **)&a_glUniformMatrix2x3fv = apple ? dlsym(apple, "glUniformMatrix2x3fv") : (void*)0; if (p_glUniformMatrix2x3fv) n++;
    *(void **)&p_glUniformMatrix2x4dv = dlsym(mgl, "glUniformMatrix2x4dv"); *(void **)&a_glUniformMatrix2x4dv = apple ? dlsym(apple, "glUniformMatrix2x4dv") : (void*)0; if (p_glUniformMatrix2x4dv) n++;
    *(void **)&p_glUniformMatrix2x4fv = dlsym(mgl, "glUniformMatrix2x4fv"); *(void **)&a_glUniformMatrix2x4fv = apple ? dlsym(apple, "glUniformMatrix2x4fv") : (void*)0; if (p_glUniformMatrix2x4fv) n++;
    *(void **)&p_glUniformMatrix3dv = dlsym(mgl, "glUniformMatrix3dv"); *(void **)&a_glUniformMatrix3dv = apple ? dlsym(apple, "glUniformMatrix3dv") : (void*)0; if (p_glUniformMatrix3dv) n++;
    *(void **)&p_glUniformMatrix3fv = dlsym(mgl, "glUniformMatrix3fv"); *(void **)&a_glUniformMatrix3fv = apple ? dlsym(apple, "glUniformMatrix3fv") : (void*)0; if (p_glUniformMatrix3fv) n++;
    *(void **)&p_glUniformMatrix3x2dv = dlsym(mgl, "glUniformMatrix3x2dv"); *(void **)&a_glUniformMatrix3x2dv = apple ? dlsym(apple, "glUniformMatrix3x2dv") : (void*)0; if (p_glUniformMatrix3x2dv) n++;
    *(void **)&p_glUniformMatrix3x2fv = dlsym(mgl, "glUniformMatrix3x2fv"); *(void **)&a_glUniformMatrix3x2fv = apple ? dlsym(apple, "glUniformMatrix3x2fv") : (void*)0; if (p_glUniformMatrix3x2fv) n++;
    *(void **)&p_glUniformMatrix3x4dv = dlsym(mgl, "glUniformMatrix3x4dv"); *(void **)&a_glUniformMatrix3x4dv = apple ? dlsym(apple, "glUniformMatrix3x4dv") : (void*)0; if (p_glUniformMatrix3x4dv) n++;
    *(void **)&p_glUniformMatrix3x4fv = dlsym(mgl, "glUniformMatrix3x4fv"); *(void **)&a_glUniformMatrix3x4fv = apple ? dlsym(apple, "glUniformMatrix3x4fv") : (void*)0; if (p_glUniformMatrix3x4fv) n++;
    *(void **)&p_glUniformMatrix4dv = dlsym(mgl, "glUniformMatrix4dv"); *(void **)&a_glUniformMatrix4dv = apple ? dlsym(apple, "glUniformMatrix4dv") : (void*)0; if (p_glUniformMatrix4dv) n++;
    *(void **)&p_glUniformMatrix4fv = dlsym(mgl, "glUniformMatrix4fv"); *(void **)&a_glUniformMatrix4fv = apple ? dlsym(apple, "glUniformMatrix4fv") : (void*)0; if (p_glUniformMatrix4fv) n++;
    *(void **)&p_glUniformMatrix4x2dv = dlsym(mgl, "glUniformMatrix4x2dv"); *(void **)&a_glUniformMatrix4x2dv = apple ? dlsym(apple, "glUniformMatrix4x2dv") : (void*)0; if (p_glUniformMatrix4x2dv) n++;
    *(void **)&p_glUniformMatrix4x2fv = dlsym(mgl, "glUniformMatrix4x2fv"); *(void **)&a_glUniformMatrix4x2fv = apple ? dlsym(apple, "glUniformMatrix4x2fv") : (void*)0; if (p_glUniformMatrix4x2fv) n++;
    *(void **)&p_glUniformMatrix4x3dv = dlsym(mgl, "glUniformMatrix4x3dv"); *(void **)&a_glUniformMatrix4x3dv = apple ? dlsym(apple, "glUniformMatrix4x3dv") : (void*)0; if (p_glUniformMatrix4x3dv) n++;
    *(void **)&p_glUniformMatrix4x3fv = dlsym(mgl, "glUniformMatrix4x3fv"); *(void **)&a_glUniformMatrix4x3fv = apple ? dlsym(apple, "glUniformMatrix4x3fv") : (void*)0; if (p_glUniformMatrix4x3fv) n++;
    *(void **)&p_glUniformSubroutinesuiv = dlsym(mgl, "glUniformSubroutinesuiv"); *(void **)&a_glUniformSubroutinesuiv = apple ? dlsym(apple, "glUniformSubroutinesuiv") : (void*)0; if (p_glUniformSubroutinesuiv) n++;
    *(void **)&p_glUnmapBuffer = dlsym(mgl, "glUnmapBuffer"); *(void **)&a_glUnmapBuffer = apple ? dlsym(apple, "glUnmapBuffer") : (void*)0; if (p_glUnmapBuffer) n++;
    *(void **)&p_glUnmapNamedBuffer = dlsym(mgl, "glUnmapNamedBuffer"); *(void **)&a_glUnmapNamedBuffer = apple ? dlsym(apple, "glUnmapNamedBuffer") : (void*)0; if (p_glUnmapNamedBuffer) n++;
    *(void **)&p_glUseProgram = dlsym(mgl, "glUseProgram"); *(void **)&a_glUseProgram = apple ? dlsym(apple, "glUseProgram") : (void*)0; if (p_glUseProgram) n++;
    *(void **)&p_glUseProgramStages = dlsym(mgl, "glUseProgramStages"); *(void **)&a_glUseProgramStages = apple ? dlsym(apple, "glUseProgramStages") : (void*)0; if (p_glUseProgramStages) n++;
    *(void **)&p_glValidateProgram = dlsym(mgl, "glValidateProgram"); *(void **)&a_glValidateProgram = apple ? dlsym(apple, "glValidateProgram") : (void*)0; if (p_glValidateProgram) n++;
    *(void **)&p_glValidateProgramPipeline = dlsym(mgl, "glValidateProgramPipeline"); *(void **)&a_glValidateProgramPipeline = apple ? dlsym(apple, "glValidateProgramPipeline") : (void*)0; if (p_glValidateProgramPipeline) n++;
    *(void **)&p_glVertex2d = dlsym(mgl, "glVertex2d"); *(void **)&a_glVertex2d = apple ? dlsym(apple, "glVertex2d") : (void*)0; if (p_glVertex2d) n++;
    *(void **)&p_glVertex2dv = dlsym(mgl, "glVertex2dv"); *(void **)&a_glVertex2dv = apple ? dlsym(apple, "glVertex2dv") : (void*)0; if (p_glVertex2dv) n++;
    *(void **)&p_glVertex2f = dlsym(mgl, "glVertex2f"); *(void **)&a_glVertex2f = apple ? dlsym(apple, "glVertex2f") : (void*)0; if (p_glVertex2f) n++;
    *(void **)&p_glVertex2fv = dlsym(mgl, "glVertex2fv"); *(void **)&a_glVertex2fv = apple ? dlsym(apple, "glVertex2fv") : (void*)0; if (p_glVertex2fv) n++;
    *(void **)&p_glVertex2i = dlsym(mgl, "glVertex2i"); *(void **)&a_glVertex2i = apple ? dlsym(apple, "glVertex2i") : (void*)0; if (p_glVertex2i) n++;
    *(void **)&p_glVertex2iv = dlsym(mgl, "glVertex2iv"); *(void **)&a_glVertex2iv = apple ? dlsym(apple, "glVertex2iv") : (void*)0; if (p_glVertex2iv) n++;
    *(void **)&p_glVertex2s = dlsym(mgl, "glVertex2s"); *(void **)&a_glVertex2s = apple ? dlsym(apple, "glVertex2s") : (void*)0; if (p_glVertex2s) n++;
    *(void **)&p_glVertex2sv = dlsym(mgl, "glVertex2sv"); *(void **)&a_glVertex2sv = apple ? dlsym(apple, "glVertex2sv") : (void*)0; if (p_glVertex2sv) n++;
    *(void **)&p_glVertex3d = dlsym(mgl, "glVertex3d"); *(void **)&a_glVertex3d = apple ? dlsym(apple, "glVertex3d") : (void*)0; if (p_glVertex3d) n++;
    *(void **)&p_glVertex3dv = dlsym(mgl, "glVertex3dv"); *(void **)&a_glVertex3dv = apple ? dlsym(apple, "glVertex3dv") : (void*)0; if (p_glVertex3dv) n++;
    *(void **)&p_glVertex3f = dlsym(mgl, "glVertex3f"); *(void **)&a_glVertex3f = apple ? dlsym(apple, "glVertex3f") : (void*)0; if (p_glVertex3f) n++;
    *(void **)&p_glVertex3fv = dlsym(mgl, "glVertex3fv"); *(void **)&a_glVertex3fv = apple ? dlsym(apple, "glVertex3fv") : (void*)0; if (p_glVertex3fv) n++;
    *(void **)&p_glVertex3i = dlsym(mgl, "glVertex3i"); *(void **)&a_glVertex3i = apple ? dlsym(apple, "glVertex3i") : (void*)0; if (p_glVertex3i) n++;
    *(void **)&p_glVertex3iv = dlsym(mgl, "glVertex3iv"); *(void **)&a_glVertex3iv = apple ? dlsym(apple, "glVertex3iv") : (void*)0; if (p_glVertex3iv) n++;
    *(void **)&p_glVertex3s = dlsym(mgl, "glVertex3s"); *(void **)&a_glVertex3s = apple ? dlsym(apple, "glVertex3s") : (void*)0; if (p_glVertex3s) n++;
    *(void **)&p_glVertex3sv = dlsym(mgl, "glVertex3sv"); *(void **)&a_glVertex3sv = apple ? dlsym(apple, "glVertex3sv") : (void*)0; if (p_glVertex3sv) n++;
    *(void **)&p_glVertex4d = dlsym(mgl, "glVertex4d"); *(void **)&a_glVertex4d = apple ? dlsym(apple, "glVertex4d") : (void*)0; if (p_glVertex4d) n++;
    *(void **)&p_glVertex4dv = dlsym(mgl, "glVertex4dv"); *(void **)&a_glVertex4dv = apple ? dlsym(apple, "glVertex4dv") : (void*)0; if (p_glVertex4dv) n++;
    *(void **)&p_glVertex4f = dlsym(mgl, "glVertex4f"); *(void **)&a_glVertex4f = apple ? dlsym(apple, "glVertex4f") : (void*)0; if (p_glVertex4f) n++;
    *(void **)&p_glVertex4fv = dlsym(mgl, "glVertex4fv"); *(void **)&a_glVertex4fv = apple ? dlsym(apple, "glVertex4fv") : (void*)0; if (p_glVertex4fv) n++;
    *(void **)&p_glVertex4i = dlsym(mgl, "glVertex4i"); *(void **)&a_glVertex4i = apple ? dlsym(apple, "glVertex4i") : (void*)0; if (p_glVertex4i) n++;
    *(void **)&p_glVertex4iv = dlsym(mgl, "glVertex4iv"); *(void **)&a_glVertex4iv = apple ? dlsym(apple, "glVertex4iv") : (void*)0; if (p_glVertex4iv) n++;
    *(void **)&p_glVertex4s = dlsym(mgl, "glVertex4s"); *(void **)&a_glVertex4s = apple ? dlsym(apple, "glVertex4s") : (void*)0; if (p_glVertex4s) n++;
    *(void **)&p_glVertex4sv = dlsym(mgl, "glVertex4sv"); *(void **)&a_glVertex4sv = apple ? dlsym(apple, "glVertex4sv") : (void*)0; if (p_glVertex4sv) n++;
    *(void **)&p_glVertexArrayAttribBinding = dlsym(mgl, "glVertexArrayAttribBinding"); *(void **)&a_glVertexArrayAttribBinding = apple ? dlsym(apple, "glVertexArrayAttribBinding") : (void*)0; if (p_glVertexArrayAttribBinding) n++;
    *(void **)&p_glVertexArrayAttribFormat = dlsym(mgl, "glVertexArrayAttribFormat"); *(void **)&a_glVertexArrayAttribFormat = apple ? dlsym(apple, "glVertexArrayAttribFormat") : (void*)0; if (p_glVertexArrayAttribFormat) n++;
    *(void **)&p_glVertexArrayAttribIFormat = dlsym(mgl, "glVertexArrayAttribIFormat"); *(void **)&a_glVertexArrayAttribIFormat = apple ? dlsym(apple, "glVertexArrayAttribIFormat") : (void*)0; if (p_glVertexArrayAttribIFormat) n++;
    *(void **)&p_glVertexArrayAttribLFormat = dlsym(mgl, "glVertexArrayAttribLFormat"); *(void **)&a_glVertexArrayAttribLFormat = apple ? dlsym(apple, "glVertexArrayAttribLFormat") : (void*)0; if (p_glVertexArrayAttribLFormat) n++;
    *(void **)&p_glVertexArrayBindingDivisor = dlsym(mgl, "glVertexArrayBindingDivisor"); *(void **)&a_glVertexArrayBindingDivisor = apple ? dlsym(apple, "glVertexArrayBindingDivisor") : (void*)0; if (p_glVertexArrayBindingDivisor) n++;
    *(void **)&p_glVertexArrayElementBuffer = dlsym(mgl, "glVertexArrayElementBuffer"); *(void **)&a_glVertexArrayElementBuffer = apple ? dlsym(apple, "glVertexArrayElementBuffer") : (void*)0; if (p_glVertexArrayElementBuffer) n++;
    *(void **)&p_glVertexArrayVertexBuffer = dlsym(mgl, "glVertexArrayVertexBuffer"); *(void **)&a_glVertexArrayVertexBuffer = apple ? dlsym(apple, "glVertexArrayVertexBuffer") : (void*)0; if (p_glVertexArrayVertexBuffer) n++;
    *(void **)&p_glVertexArrayVertexBuffers = dlsym(mgl, "glVertexArrayVertexBuffers"); *(void **)&a_glVertexArrayVertexBuffers = apple ? dlsym(apple, "glVertexArrayVertexBuffers") : (void*)0; if (p_glVertexArrayVertexBuffers) n++;
    *(void **)&p_glVertexAttrib1d = dlsym(mgl, "glVertexAttrib1d"); *(void **)&a_glVertexAttrib1d = apple ? dlsym(apple, "glVertexAttrib1d") : (void*)0; if (p_glVertexAttrib1d) n++;
    *(void **)&p_glVertexAttrib1dv = dlsym(mgl, "glVertexAttrib1dv"); *(void **)&a_glVertexAttrib1dv = apple ? dlsym(apple, "glVertexAttrib1dv") : (void*)0; if (p_glVertexAttrib1dv) n++;
    *(void **)&p_glVertexAttrib1f = dlsym(mgl, "glVertexAttrib1f"); *(void **)&a_glVertexAttrib1f = apple ? dlsym(apple, "glVertexAttrib1f") : (void*)0; if (p_glVertexAttrib1f) n++;
    *(void **)&p_glVertexAttrib1fv = dlsym(mgl, "glVertexAttrib1fv"); *(void **)&a_glVertexAttrib1fv = apple ? dlsym(apple, "glVertexAttrib1fv") : (void*)0; if (p_glVertexAttrib1fv) n++;
    *(void **)&p_glVertexAttrib1s = dlsym(mgl, "glVertexAttrib1s"); *(void **)&a_glVertexAttrib1s = apple ? dlsym(apple, "glVertexAttrib1s") : (void*)0; if (p_glVertexAttrib1s) n++;
    *(void **)&p_glVertexAttrib1sv = dlsym(mgl, "glVertexAttrib1sv"); *(void **)&a_glVertexAttrib1sv = apple ? dlsym(apple, "glVertexAttrib1sv") : (void*)0; if (p_glVertexAttrib1sv) n++;
    *(void **)&p_glVertexAttrib2d = dlsym(mgl, "glVertexAttrib2d"); *(void **)&a_glVertexAttrib2d = apple ? dlsym(apple, "glVertexAttrib2d") : (void*)0; if (p_glVertexAttrib2d) n++;
    *(void **)&p_glVertexAttrib2dv = dlsym(mgl, "glVertexAttrib2dv"); *(void **)&a_glVertexAttrib2dv = apple ? dlsym(apple, "glVertexAttrib2dv") : (void*)0; if (p_glVertexAttrib2dv) n++;
    *(void **)&p_glVertexAttrib2f = dlsym(mgl, "glVertexAttrib2f"); *(void **)&a_glVertexAttrib2f = apple ? dlsym(apple, "glVertexAttrib2f") : (void*)0; if (p_glVertexAttrib2f) n++;
    *(void **)&p_glVertexAttrib2fv = dlsym(mgl, "glVertexAttrib2fv"); *(void **)&a_glVertexAttrib2fv = apple ? dlsym(apple, "glVertexAttrib2fv") : (void*)0; if (p_glVertexAttrib2fv) n++;
    *(void **)&p_glVertexAttrib2s = dlsym(mgl, "glVertexAttrib2s"); *(void **)&a_glVertexAttrib2s = apple ? dlsym(apple, "glVertexAttrib2s") : (void*)0; if (p_glVertexAttrib2s) n++;
    *(void **)&p_glVertexAttrib2sv = dlsym(mgl, "glVertexAttrib2sv"); *(void **)&a_glVertexAttrib2sv = apple ? dlsym(apple, "glVertexAttrib2sv") : (void*)0; if (p_glVertexAttrib2sv) n++;
    *(void **)&p_glVertexAttrib3d = dlsym(mgl, "glVertexAttrib3d"); *(void **)&a_glVertexAttrib3d = apple ? dlsym(apple, "glVertexAttrib3d") : (void*)0; if (p_glVertexAttrib3d) n++;
    *(void **)&p_glVertexAttrib3dv = dlsym(mgl, "glVertexAttrib3dv"); *(void **)&a_glVertexAttrib3dv = apple ? dlsym(apple, "glVertexAttrib3dv") : (void*)0; if (p_glVertexAttrib3dv) n++;
    *(void **)&p_glVertexAttrib3f = dlsym(mgl, "glVertexAttrib3f"); *(void **)&a_glVertexAttrib3f = apple ? dlsym(apple, "glVertexAttrib3f") : (void*)0; if (p_glVertexAttrib3f) n++;
    *(void **)&p_glVertexAttrib3fv = dlsym(mgl, "glVertexAttrib3fv"); *(void **)&a_glVertexAttrib3fv = apple ? dlsym(apple, "glVertexAttrib3fv") : (void*)0; if (p_glVertexAttrib3fv) n++;
    *(void **)&p_glVertexAttrib3s = dlsym(mgl, "glVertexAttrib3s"); *(void **)&a_glVertexAttrib3s = apple ? dlsym(apple, "glVertexAttrib3s") : (void*)0; if (p_glVertexAttrib3s) n++;
    *(void **)&p_glVertexAttrib3sv = dlsym(mgl, "glVertexAttrib3sv"); *(void **)&a_glVertexAttrib3sv = apple ? dlsym(apple, "glVertexAttrib3sv") : (void*)0; if (p_glVertexAttrib3sv) n++;
    *(void **)&p_glVertexAttrib4Nbv = dlsym(mgl, "glVertexAttrib4Nbv"); *(void **)&a_glVertexAttrib4Nbv = apple ? dlsym(apple, "glVertexAttrib4Nbv") : (void*)0; if (p_glVertexAttrib4Nbv) n++;
    *(void **)&p_glVertexAttrib4Niv = dlsym(mgl, "glVertexAttrib4Niv"); *(void **)&a_glVertexAttrib4Niv = apple ? dlsym(apple, "glVertexAttrib4Niv") : (void*)0; if (p_glVertexAttrib4Niv) n++;
    *(void **)&p_glVertexAttrib4Nsv = dlsym(mgl, "glVertexAttrib4Nsv"); *(void **)&a_glVertexAttrib4Nsv = apple ? dlsym(apple, "glVertexAttrib4Nsv") : (void*)0; if (p_glVertexAttrib4Nsv) n++;
    *(void **)&p_glVertexAttrib4Nub = dlsym(mgl, "glVertexAttrib4Nub"); *(void **)&a_glVertexAttrib4Nub = apple ? dlsym(apple, "glVertexAttrib4Nub") : (void*)0; if (p_glVertexAttrib4Nub) n++;
    *(void **)&p_glVertexAttrib4Nubv = dlsym(mgl, "glVertexAttrib4Nubv"); *(void **)&a_glVertexAttrib4Nubv = apple ? dlsym(apple, "glVertexAttrib4Nubv") : (void*)0; if (p_glVertexAttrib4Nubv) n++;
    *(void **)&p_glVertexAttrib4Nuiv = dlsym(mgl, "glVertexAttrib4Nuiv"); *(void **)&a_glVertexAttrib4Nuiv = apple ? dlsym(apple, "glVertexAttrib4Nuiv") : (void*)0; if (p_glVertexAttrib4Nuiv) n++;
    *(void **)&p_glVertexAttrib4Nusv = dlsym(mgl, "glVertexAttrib4Nusv"); *(void **)&a_glVertexAttrib4Nusv = apple ? dlsym(apple, "glVertexAttrib4Nusv") : (void*)0; if (p_glVertexAttrib4Nusv) n++;
    *(void **)&p_glVertexAttrib4bv = dlsym(mgl, "glVertexAttrib4bv"); *(void **)&a_glVertexAttrib4bv = apple ? dlsym(apple, "glVertexAttrib4bv") : (void*)0; if (p_glVertexAttrib4bv) n++;
    *(void **)&p_glVertexAttrib4d = dlsym(mgl, "glVertexAttrib4d"); *(void **)&a_glVertexAttrib4d = apple ? dlsym(apple, "glVertexAttrib4d") : (void*)0; if (p_glVertexAttrib4d) n++;
    *(void **)&p_glVertexAttrib4dv = dlsym(mgl, "glVertexAttrib4dv"); *(void **)&a_glVertexAttrib4dv = apple ? dlsym(apple, "glVertexAttrib4dv") : (void*)0; if (p_glVertexAttrib4dv) n++;
    *(void **)&p_glVertexAttrib4f = dlsym(mgl, "glVertexAttrib4f"); *(void **)&a_glVertexAttrib4f = apple ? dlsym(apple, "glVertexAttrib4f") : (void*)0; if (p_glVertexAttrib4f) n++;
    *(void **)&p_glVertexAttrib4fv = dlsym(mgl, "glVertexAttrib4fv"); *(void **)&a_glVertexAttrib4fv = apple ? dlsym(apple, "glVertexAttrib4fv") : (void*)0; if (p_glVertexAttrib4fv) n++;
    *(void **)&p_glVertexAttrib4iv = dlsym(mgl, "glVertexAttrib4iv"); *(void **)&a_glVertexAttrib4iv = apple ? dlsym(apple, "glVertexAttrib4iv") : (void*)0; if (p_glVertexAttrib4iv) n++;
    *(void **)&p_glVertexAttrib4s = dlsym(mgl, "glVertexAttrib4s"); *(void **)&a_glVertexAttrib4s = apple ? dlsym(apple, "glVertexAttrib4s") : (void*)0; if (p_glVertexAttrib4s) n++;
    *(void **)&p_glVertexAttrib4sv = dlsym(mgl, "glVertexAttrib4sv"); *(void **)&a_glVertexAttrib4sv = apple ? dlsym(apple, "glVertexAttrib4sv") : (void*)0; if (p_glVertexAttrib4sv) n++;
    *(void **)&p_glVertexAttrib4ubv = dlsym(mgl, "glVertexAttrib4ubv"); *(void **)&a_glVertexAttrib4ubv = apple ? dlsym(apple, "glVertexAttrib4ubv") : (void*)0; if (p_glVertexAttrib4ubv) n++;
    *(void **)&p_glVertexAttrib4uiv = dlsym(mgl, "glVertexAttrib4uiv"); *(void **)&a_glVertexAttrib4uiv = apple ? dlsym(apple, "glVertexAttrib4uiv") : (void*)0; if (p_glVertexAttrib4uiv) n++;
    *(void **)&p_glVertexAttrib4usv = dlsym(mgl, "glVertexAttrib4usv"); *(void **)&a_glVertexAttrib4usv = apple ? dlsym(apple, "glVertexAttrib4usv") : (void*)0; if (p_glVertexAttrib4usv) n++;
    *(void **)&p_glVertexAttribBinding = dlsym(mgl, "glVertexAttribBinding"); *(void **)&a_glVertexAttribBinding = apple ? dlsym(apple, "glVertexAttribBinding") : (void*)0; if (p_glVertexAttribBinding) n++;
    *(void **)&p_glVertexAttribDivisor = dlsym(mgl, "glVertexAttribDivisor"); *(void **)&a_glVertexAttribDivisor = apple ? dlsym(apple, "glVertexAttribDivisor") : (void*)0; if (p_glVertexAttribDivisor) n++;
    *(void **)&p_glVertexAttribFormat = dlsym(mgl, "glVertexAttribFormat"); *(void **)&a_glVertexAttribFormat = apple ? dlsym(apple, "glVertexAttribFormat") : (void*)0; if (p_glVertexAttribFormat) n++;
    *(void **)&p_glVertexAttribI1i = dlsym(mgl, "glVertexAttribI1i"); *(void **)&a_glVertexAttribI1i = apple ? dlsym(apple, "glVertexAttribI1i") : (void*)0; if (p_glVertexAttribI1i) n++;
    *(void **)&p_glVertexAttribI1iv = dlsym(mgl, "glVertexAttribI1iv"); *(void **)&a_glVertexAttribI1iv = apple ? dlsym(apple, "glVertexAttribI1iv") : (void*)0; if (p_glVertexAttribI1iv) n++;
    *(void **)&p_glVertexAttribI1ui = dlsym(mgl, "glVertexAttribI1ui"); *(void **)&a_glVertexAttribI1ui = apple ? dlsym(apple, "glVertexAttribI1ui") : (void*)0; if (p_glVertexAttribI1ui) n++;
    *(void **)&p_glVertexAttribI1uiv = dlsym(mgl, "glVertexAttribI1uiv"); *(void **)&a_glVertexAttribI1uiv = apple ? dlsym(apple, "glVertexAttribI1uiv") : (void*)0; if (p_glVertexAttribI1uiv) n++;
    *(void **)&p_glVertexAttribI2i = dlsym(mgl, "glVertexAttribI2i"); *(void **)&a_glVertexAttribI2i = apple ? dlsym(apple, "glVertexAttribI2i") : (void*)0; if (p_glVertexAttribI2i) n++;
    *(void **)&p_glVertexAttribI2iv = dlsym(mgl, "glVertexAttribI2iv"); *(void **)&a_glVertexAttribI2iv = apple ? dlsym(apple, "glVertexAttribI2iv") : (void*)0; if (p_glVertexAttribI2iv) n++;
    *(void **)&p_glVertexAttribI2ui = dlsym(mgl, "glVertexAttribI2ui"); *(void **)&a_glVertexAttribI2ui = apple ? dlsym(apple, "glVertexAttribI2ui") : (void*)0; if (p_glVertexAttribI2ui) n++;
    *(void **)&p_glVertexAttribI2uiv = dlsym(mgl, "glVertexAttribI2uiv"); *(void **)&a_glVertexAttribI2uiv = apple ? dlsym(apple, "glVertexAttribI2uiv") : (void*)0; if (p_glVertexAttribI2uiv) n++;
    *(void **)&p_glVertexAttribI3i = dlsym(mgl, "glVertexAttribI3i"); *(void **)&a_glVertexAttribI3i = apple ? dlsym(apple, "glVertexAttribI3i") : (void*)0; if (p_glVertexAttribI3i) n++;
    *(void **)&p_glVertexAttribI3iv = dlsym(mgl, "glVertexAttribI3iv"); *(void **)&a_glVertexAttribI3iv = apple ? dlsym(apple, "glVertexAttribI3iv") : (void*)0; if (p_glVertexAttribI3iv) n++;
    *(void **)&p_glVertexAttribI3ui = dlsym(mgl, "glVertexAttribI3ui"); *(void **)&a_glVertexAttribI3ui = apple ? dlsym(apple, "glVertexAttribI3ui") : (void*)0; if (p_glVertexAttribI3ui) n++;
    *(void **)&p_glVertexAttribI3uiv = dlsym(mgl, "glVertexAttribI3uiv"); *(void **)&a_glVertexAttribI3uiv = apple ? dlsym(apple, "glVertexAttribI3uiv") : (void*)0; if (p_glVertexAttribI3uiv) n++;
    *(void **)&p_glVertexAttribI4bv = dlsym(mgl, "glVertexAttribI4bv"); *(void **)&a_glVertexAttribI4bv = apple ? dlsym(apple, "glVertexAttribI4bv") : (void*)0; if (p_glVertexAttribI4bv) n++;
    *(void **)&p_glVertexAttribI4i = dlsym(mgl, "glVertexAttribI4i"); *(void **)&a_glVertexAttribI4i = apple ? dlsym(apple, "glVertexAttribI4i") : (void*)0; if (p_glVertexAttribI4i) n++;
    *(void **)&p_glVertexAttribI4iv = dlsym(mgl, "glVertexAttribI4iv"); *(void **)&a_glVertexAttribI4iv = apple ? dlsym(apple, "glVertexAttribI4iv") : (void*)0; if (p_glVertexAttribI4iv) n++;
    *(void **)&p_glVertexAttribI4sv = dlsym(mgl, "glVertexAttribI4sv"); *(void **)&a_glVertexAttribI4sv = apple ? dlsym(apple, "glVertexAttribI4sv") : (void*)0; if (p_glVertexAttribI4sv) n++;
    *(void **)&p_glVertexAttribI4ubv = dlsym(mgl, "glVertexAttribI4ubv"); *(void **)&a_glVertexAttribI4ubv = apple ? dlsym(apple, "glVertexAttribI4ubv") : (void*)0; if (p_glVertexAttribI4ubv) n++;
    *(void **)&p_glVertexAttribI4ui = dlsym(mgl, "glVertexAttribI4ui"); *(void **)&a_glVertexAttribI4ui = apple ? dlsym(apple, "glVertexAttribI4ui") : (void*)0; if (p_glVertexAttribI4ui) n++;
    *(void **)&p_glVertexAttribI4uiv = dlsym(mgl, "glVertexAttribI4uiv"); *(void **)&a_glVertexAttribI4uiv = apple ? dlsym(apple, "glVertexAttribI4uiv") : (void*)0; if (p_glVertexAttribI4uiv) n++;
    *(void **)&p_glVertexAttribI4usv = dlsym(mgl, "glVertexAttribI4usv"); *(void **)&a_glVertexAttribI4usv = apple ? dlsym(apple, "glVertexAttribI4usv") : (void*)0; if (p_glVertexAttribI4usv) n++;
    *(void **)&p_glVertexAttribIFormat = dlsym(mgl, "glVertexAttribIFormat"); *(void **)&a_glVertexAttribIFormat = apple ? dlsym(apple, "glVertexAttribIFormat") : (void*)0; if (p_glVertexAttribIFormat) n++;
    *(void **)&p_glVertexAttribIPointer = dlsym(mgl, "glVertexAttribIPointer"); *(void **)&a_glVertexAttribIPointer = apple ? dlsym(apple, "glVertexAttribIPointer") : (void*)0; if (p_glVertexAttribIPointer) n++;
    *(void **)&p_glVertexAttribL1d = dlsym(mgl, "glVertexAttribL1d"); *(void **)&a_glVertexAttribL1d = apple ? dlsym(apple, "glVertexAttribL1d") : (void*)0; if (p_glVertexAttribL1d) n++;
    *(void **)&p_glVertexAttribL1dv = dlsym(mgl, "glVertexAttribL1dv"); *(void **)&a_glVertexAttribL1dv = apple ? dlsym(apple, "glVertexAttribL1dv") : (void*)0; if (p_glVertexAttribL1dv) n++;
    *(void **)&p_glVertexAttribL2d = dlsym(mgl, "glVertexAttribL2d"); *(void **)&a_glVertexAttribL2d = apple ? dlsym(apple, "glVertexAttribL2d") : (void*)0; if (p_glVertexAttribL2d) n++;
    *(void **)&p_glVertexAttribL2dv = dlsym(mgl, "glVertexAttribL2dv"); *(void **)&a_glVertexAttribL2dv = apple ? dlsym(apple, "glVertexAttribL2dv") : (void*)0; if (p_glVertexAttribL2dv) n++;
    *(void **)&p_glVertexAttribL3d = dlsym(mgl, "glVertexAttribL3d"); *(void **)&a_glVertexAttribL3d = apple ? dlsym(apple, "glVertexAttribL3d") : (void*)0; if (p_glVertexAttribL3d) n++;
    *(void **)&p_glVertexAttribL3dv = dlsym(mgl, "glVertexAttribL3dv"); *(void **)&a_glVertexAttribL3dv = apple ? dlsym(apple, "glVertexAttribL3dv") : (void*)0; if (p_glVertexAttribL3dv) n++;
    *(void **)&p_glVertexAttribL4d = dlsym(mgl, "glVertexAttribL4d"); *(void **)&a_glVertexAttribL4d = apple ? dlsym(apple, "glVertexAttribL4d") : (void*)0; if (p_glVertexAttribL4d) n++;
    *(void **)&p_glVertexAttribL4dv = dlsym(mgl, "glVertexAttribL4dv"); *(void **)&a_glVertexAttribL4dv = apple ? dlsym(apple, "glVertexAttribL4dv") : (void*)0; if (p_glVertexAttribL4dv) n++;
    *(void **)&p_glVertexAttribLFormat = dlsym(mgl, "glVertexAttribLFormat"); *(void **)&a_glVertexAttribLFormat = apple ? dlsym(apple, "glVertexAttribLFormat") : (void*)0; if (p_glVertexAttribLFormat) n++;
    *(void **)&p_glVertexAttribLPointer = dlsym(mgl, "glVertexAttribLPointer"); *(void **)&a_glVertexAttribLPointer = apple ? dlsym(apple, "glVertexAttribLPointer") : (void*)0; if (p_glVertexAttribLPointer) n++;
    *(void **)&p_glVertexAttribP1ui = dlsym(mgl, "glVertexAttribP1ui"); *(void **)&a_glVertexAttribP1ui = apple ? dlsym(apple, "glVertexAttribP1ui") : (void*)0; if (p_glVertexAttribP1ui) n++;
    *(void **)&p_glVertexAttribP1uiv = dlsym(mgl, "glVertexAttribP1uiv"); *(void **)&a_glVertexAttribP1uiv = apple ? dlsym(apple, "glVertexAttribP1uiv") : (void*)0; if (p_glVertexAttribP1uiv) n++;
    *(void **)&p_glVertexAttribP2ui = dlsym(mgl, "glVertexAttribP2ui"); *(void **)&a_glVertexAttribP2ui = apple ? dlsym(apple, "glVertexAttribP2ui") : (void*)0; if (p_glVertexAttribP2ui) n++;
    *(void **)&p_glVertexAttribP2uiv = dlsym(mgl, "glVertexAttribP2uiv"); *(void **)&a_glVertexAttribP2uiv = apple ? dlsym(apple, "glVertexAttribP2uiv") : (void*)0; if (p_glVertexAttribP2uiv) n++;
    *(void **)&p_glVertexAttribP3ui = dlsym(mgl, "glVertexAttribP3ui"); *(void **)&a_glVertexAttribP3ui = apple ? dlsym(apple, "glVertexAttribP3ui") : (void*)0; if (p_glVertexAttribP3ui) n++;
    *(void **)&p_glVertexAttribP3uiv = dlsym(mgl, "glVertexAttribP3uiv"); *(void **)&a_glVertexAttribP3uiv = apple ? dlsym(apple, "glVertexAttribP3uiv") : (void*)0; if (p_glVertexAttribP3uiv) n++;
    *(void **)&p_glVertexAttribP4ui = dlsym(mgl, "glVertexAttribP4ui"); *(void **)&a_glVertexAttribP4ui = apple ? dlsym(apple, "glVertexAttribP4ui") : (void*)0; if (p_glVertexAttribP4ui) n++;
    *(void **)&p_glVertexAttribP4uiv = dlsym(mgl, "glVertexAttribP4uiv"); *(void **)&a_glVertexAttribP4uiv = apple ? dlsym(apple, "glVertexAttribP4uiv") : (void*)0; if (p_glVertexAttribP4uiv) n++;
    *(void **)&p_glVertexAttribPointer = dlsym(mgl, "glVertexAttribPointer"); *(void **)&a_glVertexAttribPointer = apple ? dlsym(apple, "glVertexAttribPointer") : (void*)0; if (p_glVertexAttribPointer) n++;
    *(void **)&p_glVertexBindingDivisor = dlsym(mgl, "glVertexBindingDivisor"); *(void **)&a_glVertexBindingDivisor = apple ? dlsym(apple, "glVertexBindingDivisor") : (void*)0; if (p_glVertexBindingDivisor) n++;
    *(void **)&p_glVertexP2ui = dlsym(mgl, "glVertexP2ui"); *(void **)&a_glVertexP2ui = apple ? dlsym(apple, "glVertexP2ui") : (void*)0; if (p_glVertexP2ui) n++;
    *(void **)&p_glVertexP2uiv = dlsym(mgl, "glVertexP2uiv"); *(void **)&a_glVertexP2uiv = apple ? dlsym(apple, "glVertexP2uiv") : (void*)0; if (p_glVertexP2uiv) n++;
    *(void **)&p_glVertexP3ui = dlsym(mgl, "glVertexP3ui"); *(void **)&a_glVertexP3ui = apple ? dlsym(apple, "glVertexP3ui") : (void*)0; if (p_glVertexP3ui) n++;
    *(void **)&p_glVertexP3uiv = dlsym(mgl, "glVertexP3uiv"); *(void **)&a_glVertexP3uiv = apple ? dlsym(apple, "glVertexP3uiv") : (void*)0; if (p_glVertexP3uiv) n++;
    *(void **)&p_glVertexP4ui = dlsym(mgl, "glVertexP4ui"); *(void **)&a_glVertexP4ui = apple ? dlsym(apple, "glVertexP4ui") : (void*)0; if (p_glVertexP4ui) n++;
    *(void **)&p_glVertexP4uiv = dlsym(mgl, "glVertexP4uiv"); *(void **)&a_glVertexP4uiv = apple ? dlsym(apple, "glVertexP4uiv") : (void*)0; if (p_glVertexP4uiv) n++;
    *(void **)&p_glVertexPointer = dlsym(mgl, "glVertexPointer"); *(void **)&a_glVertexPointer = apple ? dlsym(apple, "glVertexPointer") : (void*)0; if (p_glVertexPointer) n++;
    *(void **)&p_glViewport = dlsym(mgl, "glViewport"); *(void **)&a_glViewport = apple ? dlsym(apple, "glViewport") : (void*)0; if (p_glViewport) n++;
    *(void **)&p_glViewportArrayv = dlsym(mgl, "glViewportArrayv"); *(void **)&a_glViewportArrayv = apple ? dlsym(apple, "glViewportArrayv") : (void*)0; if (p_glViewportArrayv) n++;
    *(void **)&p_glViewportIndexedf = dlsym(mgl, "glViewportIndexedf"); *(void **)&a_glViewportIndexedf = apple ? dlsym(apple, "glViewportIndexedf") : (void*)0; if (p_glViewportIndexedf) n++;
    *(void **)&p_glViewportIndexedfv = dlsym(mgl, "glViewportIndexedfv"); *(void **)&a_glViewportIndexedfv = apple ? dlsym(apple, "glViewportIndexedfv") : (void*)0; if (p_glViewportIndexedfv) n++;
    *(void **)&p_glWaitSync = dlsym(mgl, "glWaitSync"); *(void **)&a_glWaitSync = apple ? dlsym(apple, "glWaitSync") : (void*)0; if (p_glWaitSync) n++;
    *(void **)&p_glWindowPos2d = dlsym(mgl, "glWindowPos2d"); *(void **)&a_glWindowPos2d = apple ? dlsym(apple, "glWindowPos2d") : (void*)0; if (p_glWindowPos2d) n++;
    *(void **)&p_glWindowPos2dv = dlsym(mgl, "glWindowPos2dv"); *(void **)&a_glWindowPos2dv = apple ? dlsym(apple, "glWindowPos2dv") : (void*)0; if (p_glWindowPos2dv) n++;
    *(void **)&p_glWindowPos2f = dlsym(mgl, "glWindowPos2f"); *(void **)&a_glWindowPos2f = apple ? dlsym(apple, "glWindowPos2f") : (void*)0; if (p_glWindowPos2f) n++;
    *(void **)&p_glWindowPos2fv = dlsym(mgl, "glWindowPos2fv"); *(void **)&a_glWindowPos2fv = apple ? dlsym(apple, "glWindowPos2fv") : (void*)0; if (p_glWindowPos2fv) n++;
    *(void **)&p_glWindowPos2i = dlsym(mgl, "glWindowPos2i"); *(void **)&a_glWindowPos2i = apple ? dlsym(apple, "glWindowPos2i") : (void*)0; if (p_glWindowPos2i) n++;
    *(void **)&p_glWindowPos2iv = dlsym(mgl, "glWindowPos2iv"); *(void **)&a_glWindowPos2iv = apple ? dlsym(apple, "glWindowPos2iv") : (void*)0; if (p_glWindowPos2iv) n++;
    *(void **)&p_glWindowPos2s = dlsym(mgl, "glWindowPos2s"); *(void **)&a_glWindowPos2s = apple ? dlsym(apple, "glWindowPos2s") : (void*)0; if (p_glWindowPos2s) n++;
    *(void **)&p_glWindowPos2sv = dlsym(mgl, "glWindowPos2sv"); *(void **)&a_glWindowPos2sv = apple ? dlsym(apple, "glWindowPos2sv") : (void*)0; if (p_glWindowPos2sv) n++;
    *(void **)&p_glWindowPos3d = dlsym(mgl, "glWindowPos3d"); *(void **)&a_glWindowPos3d = apple ? dlsym(apple, "glWindowPos3d") : (void*)0; if (p_glWindowPos3d) n++;
    *(void **)&p_glWindowPos3dv = dlsym(mgl, "glWindowPos3dv"); *(void **)&a_glWindowPos3dv = apple ? dlsym(apple, "glWindowPos3dv") : (void*)0; if (p_glWindowPos3dv) n++;
    *(void **)&p_glWindowPos3f = dlsym(mgl, "glWindowPos3f"); *(void **)&a_glWindowPos3f = apple ? dlsym(apple, "glWindowPos3f") : (void*)0; if (p_glWindowPos3f) n++;
    *(void **)&p_glWindowPos3fv = dlsym(mgl, "glWindowPos3fv"); *(void **)&a_glWindowPos3fv = apple ? dlsym(apple, "glWindowPos3fv") : (void*)0; if (p_glWindowPos3fv) n++;
    *(void **)&p_glWindowPos3i = dlsym(mgl, "glWindowPos3i"); *(void **)&a_glWindowPos3i = apple ? dlsym(apple, "glWindowPos3i") : (void*)0; if (p_glWindowPos3i) n++;
    *(void **)&p_glWindowPos3iv = dlsym(mgl, "glWindowPos3iv"); *(void **)&a_glWindowPos3iv = apple ? dlsym(apple, "glWindowPos3iv") : (void*)0; if (p_glWindowPos3iv) n++;
    *(void **)&p_glWindowPos3s = dlsym(mgl, "glWindowPos3s"); *(void **)&a_glWindowPos3s = apple ? dlsym(apple, "glWindowPos3s") : (void*)0; if (p_glWindowPos3s) n++;
    *(void **)&p_glWindowPos3sv = dlsym(mgl, "glWindowPos3sv"); *(void **)&a_glWindowPos3sv = apple ? dlsym(apple, "glWindowPos3sv") : (void*)0; if (p_glWindowPos3sv) n++;
    return n;
}
