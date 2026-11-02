/* GERADO por src/MGLShim/gen-interpose.py — não edite à mão. */
/* Redireciona todas as gl* do app para o MGL via DYLD interpose. */
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

void glAccum(GLenum op, GLfloat value) WEAKGL;
static void (*p_glAccum)(GLenum op, GLfloat value);
static void w_glAccum(GLenum op, GLfloat value) { if (p_glAccum) p_glAccum(op, value); }
INTERPOSE(glAccum)
void glActiveShaderProgram(GLuint pipeline, GLuint program) WEAKGL;
static void (*p_glActiveShaderProgram)(GLuint pipeline, GLuint program);
static void w_glActiveShaderProgram(GLuint pipeline, GLuint program) { if (p_glActiveShaderProgram) p_glActiveShaderProgram(pipeline, program); }
INTERPOSE(glActiveShaderProgram)
void glActiveTexture(GLenum texture) WEAKGL;
static void (*p_glActiveTexture)(GLenum texture);
static void w_glActiveTexture(GLenum texture) { if (p_glActiveTexture) p_glActiveTexture(texture); }
INTERPOSE(glActiveTexture)
void glAlphaFunc(GLenum func, GLfloat ref) WEAKGL;
static void (*p_glAlphaFunc)(GLenum func, GLfloat ref);
static void w_glAlphaFunc(GLenum func, GLfloat ref) { if (p_glAlphaFunc) p_glAlphaFunc(func, ref); }
INTERPOSE(glAlphaFunc)
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) WEAKGL;
static GLboolean (*p_glAreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences);
static GLboolean w_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) { if (!p_glAreTexturesResident) return (GLboolean)0; return p_glAreTexturesResident(n, textures, residences); }
INTERPOSE(glAreTexturesResident)
void glArrayElement(GLint i) WEAKGL;
static void (*p_glArrayElement)(GLint i);
static void w_glArrayElement(GLint i) { if (p_glArrayElement) p_glArrayElement(i); }
INTERPOSE(glArrayElement)
void glAttachShader(GLuint program, GLuint shader) WEAKGL;
static void (*p_glAttachShader)(GLuint program, GLuint shader);
static void w_glAttachShader(GLuint program, GLuint shader) { if (p_glAttachShader) p_glAttachShader(program, shader); }
INTERPOSE(glAttachShader)
void glBegin(GLenum mode) WEAKGL;
static void (*p_glBegin)(GLenum mode);
static void w_glBegin(GLenum mode) { if (p_glBegin) p_glBegin(mode); }
INTERPOSE(glBegin)
void glBeginConditionalRender(GLuint id, GLenum mode) WEAKGL;
static void (*p_glBeginConditionalRender)(GLuint id, GLenum mode);
static void w_glBeginConditionalRender(GLuint id, GLenum mode) { if (p_glBeginConditionalRender) p_glBeginConditionalRender(id, mode); }
INTERPOSE(glBeginConditionalRender)
void glBeginQuery(GLenum target, GLuint id) WEAKGL;
static void (*p_glBeginQuery)(GLenum target, GLuint id);
static void w_glBeginQuery(GLenum target, GLuint id) { if (p_glBeginQuery) p_glBeginQuery(target, id); }
INTERPOSE(glBeginQuery)
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) WEAKGL;
static void (*p_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id);
static void w_glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) { if (p_glBeginQueryIndexed) p_glBeginQueryIndexed(target, index, id); }
INTERPOSE(glBeginQueryIndexed)
void glBeginTransformFeedback(GLenum primitiveMode) WEAKGL;
static void (*p_glBeginTransformFeedback)(GLenum primitiveMode);
static void w_glBeginTransformFeedback(GLenum primitiveMode) { if (p_glBeginTransformFeedback) p_glBeginTransformFeedback(primitiveMode); }
INTERPOSE(glBeginTransformFeedback)
void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) WEAKGL;
static void (*p_glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
static void w_glBindAttribLocation(GLuint program, GLuint index, const GLchar *name) { if (p_glBindAttribLocation) p_glBindAttribLocation(program, index, name); }
INTERPOSE(glBindAttribLocation)
void glBindBuffer(GLenum target, GLuint buffer) WEAKGL;
static void (*p_glBindBuffer)(GLenum target, GLuint buffer);
static void w_glBindBuffer(GLenum target, GLuint buffer) { if (p_glBindBuffer) p_glBindBuffer(target, buffer); }
INTERPOSE(glBindBuffer)
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) WEAKGL;
static void (*p_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
static void w_glBindBufferBase(GLenum target, GLuint index, GLuint buffer) { if (p_glBindBufferBase) p_glBindBufferBase(target, index, buffer); }
INTERPOSE(glBindBufferBase)
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (p_glBindBufferRange) p_glBindBufferRange(target, index, buffer, offset, size); }
INTERPOSE(glBindBufferRange)
void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) WEAKGL;
static void (*p_glBindBuffersBase)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
static void w_glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint *buffers) { if (p_glBindBuffersBase) p_glBindBuffersBase(target, first, count, buffers); }
INTERPOSE(glBindBuffersBase)
void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) WEAKGL;
static void (*p_glBindBuffersRange)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
static void w_glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) { if (p_glBindBuffersRange) p_glBindBuffersRange(target, first, count, buffers, offsets, sizes); }
INTERPOSE(glBindBuffersRange)
void glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name) WEAKGL;
static void (*p_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
static void w_glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name) { if (p_glBindFragDataLocation) p_glBindFragDataLocation(program, color, name); }
INTERPOSE(glBindFragDataLocation)
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) WEAKGL;
static void (*p_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
static void w_glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) { if (p_glBindFragDataLocationIndexed) p_glBindFragDataLocationIndexed(program, colorNumber, index, name); }
INTERPOSE(glBindFragDataLocationIndexed)
void glBindFramebuffer(GLenum target, GLuint framebuffer) WEAKGL;
static void (*p_glBindFramebuffer)(GLenum target, GLuint framebuffer);
static void w_glBindFramebuffer(GLenum target, GLuint framebuffer) { if (p_glBindFramebuffer) p_glBindFramebuffer(target, framebuffer); }
INTERPOSE(glBindFramebuffer)
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) WEAKGL;
static void (*p_glBindImageTexture)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
static void w_glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) { if (p_glBindImageTexture) p_glBindImageTexture(unit, texture, level, layered, layer, access, format); }
INTERPOSE(glBindImageTexture)
void glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) WEAKGL;
static void (*p_glBindImageTextures)(GLuint first, GLsizei count, const GLuint *textures);
static void w_glBindImageTextures(GLuint first, GLsizei count, const GLuint *textures) { if (p_glBindImageTextures) p_glBindImageTextures(first, count, textures); }
INTERPOSE(glBindImageTextures)
void glBindProgramPipeline(GLuint pipeline) WEAKGL;
static void (*p_glBindProgramPipeline)(GLuint pipeline);
static void w_glBindProgramPipeline(GLuint pipeline) { if (p_glBindProgramPipeline) p_glBindProgramPipeline(pipeline); }
INTERPOSE(glBindProgramPipeline)
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) WEAKGL;
static void (*p_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
static void w_glBindRenderbuffer(GLenum target, GLuint renderbuffer) { if (p_glBindRenderbuffer) p_glBindRenderbuffer(target, renderbuffer); }
INTERPOSE(glBindRenderbuffer)
void glBindSampler(GLuint unit, GLuint sampler) WEAKGL;
static void (*p_glBindSampler)(GLuint unit, GLuint sampler);
static void w_glBindSampler(GLuint unit, GLuint sampler) { if (p_glBindSampler) p_glBindSampler(unit, sampler); }
INTERPOSE(glBindSampler)
void glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) WEAKGL;
static void (*p_glBindSamplers)(GLuint first, GLsizei count, const GLuint *samplers);
static void w_glBindSamplers(GLuint first, GLsizei count, const GLuint *samplers) { if (p_glBindSamplers) p_glBindSamplers(first, count, samplers); }
INTERPOSE(glBindSamplers)
void glBindTexture(GLenum target, GLuint texture) WEAKGL;
static void (*p_glBindTexture)(GLenum target, GLuint texture);
static void w_glBindTexture(GLenum target, GLuint texture) { if (p_glBindTexture) p_glBindTexture(target, texture); }
INTERPOSE(glBindTexture)
void glBindTextureUnit(GLuint unit, GLuint texture) WEAKGL;
static void (*p_glBindTextureUnit)(GLuint unit, GLuint texture);
static void w_glBindTextureUnit(GLuint unit, GLuint texture) { if (p_glBindTextureUnit) p_glBindTextureUnit(unit, texture); }
INTERPOSE(glBindTextureUnit)
void glBindTextures(GLuint first, GLsizei count, const GLuint *textures) WEAKGL;
static void (*p_glBindTextures)(GLuint first, GLsizei count, const GLuint *textures);
static void w_glBindTextures(GLuint first, GLsizei count, const GLuint *textures) { if (p_glBindTextures) p_glBindTextures(first, count, textures); }
INTERPOSE(glBindTextures)
void glBindTransformFeedback(GLenum target, GLuint id) WEAKGL;
static void (*p_glBindTransformFeedback)(GLenum target, GLuint id);
static void w_glBindTransformFeedback(GLenum target, GLuint id) { if (p_glBindTransformFeedback) p_glBindTransformFeedback(target, id); }
INTERPOSE(glBindTransformFeedback)
void glBindVertexArray(GLuint array) WEAKGL;
static void (*p_glBindVertexArray)(GLuint array);
static void w_glBindVertexArray(GLuint array) { if (p_glBindVertexArray) p_glBindVertexArray(array); }
INTERPOSE(glBindVertexArray)
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) WEAKGL;
static void (*p_glBindVertexBuffer)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
static void w_glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { if (p_glBindVertexBuffer) p_glBindVertexBuffer(bindingindex, buffer, offset, stride); }
INTERPOSE(glBindVertexBuffer)
void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) WEAKGL;
static void (*p_glBindVertexBuffers)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
static void w_glBindVertexBuffers(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { if (p_glBindVertexBuffers) p_glBindVertexBuffers(first, count, buffers, offsets, strides); }
INTERPOSE(glBindVertexBuffers)
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) WEAKGL;
static void (*p_glBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
static void w_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) { if (p_glBitmap) p_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap); }
INTERPOSE(glBitmap)
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (p_glBlendColor) p_glBlendColor(red, green, blue, alpha); }
INTERPOSE(glBlendColor)
void glBlendEquation(GLenum mode) WEAKGL;
static void (*p_glBlendEquation)(GLenum mode);
static void w_glBlendEquation(GLenum mode) { if (p_glBlendEquation) p_glBlendEquation(mode); }
INTERPOSE(glBlendEquation)
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) WEAKGL;
static void (*p_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
static void w_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { if (p_glBlendEquationSeparate) p_glBlendEquationSeparate(modeRGB, modeAlpha); }
INTERPOSE(glBlendEquationSeparate)
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) WEAKGL;
static void (*p_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
static void w_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { if (p_glBlendEquationSeparatei) p_glBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
INTERPOSE(glBlendEquationSeparatei)
void glBlendEquationi(GLuint buf, GLenum mode) WEAKGL;
static void (*p_glBlendEquationi)(GLuint buf, GLenum mode);
static void w_glBlendEquationi(GLuint buf, GLenum mode) { if (p_glBlendEquationi) p_glBlendEquationi(buf, mode); }
INTERPOSE(glBlendEquationi)
void glBlendFunc(GLenum sfactor, GLenum dfactor) WEAKGL;
static void (*p_glBlendFunc)(GLenum sfactor, GLenum dfactor);
static void w_glBlendFunc(GLenum sfactor, GLenum dfactor) { if (p_glBlendFunc) p_glBlendFunc(sfactor, dfactor); }
INTERPOSE(glBlendFunc)
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) WEAKGL;
static void (*p_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
static void w_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { if (p_glBlendFuncSeparate) p_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
INTERPOSE(glBlendFuncSeparate)
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) WEAKGL;
static void (*p_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
static void w_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { if (p_glBlendFuncSeparatei) p_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }
INTERPOSE(glBlendFuncSeparatei)
void glBlendFunci(GLuint buf, GLenum src, GLenum dst) WEAKGL;
static void (*p_glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
static void w_glBlendFunci(GLuint buf, GLenum src, GLenum dst) { if (p_glBlendFunci) p_glBlendFunci(buf, src, dst); }
INTERPOSE(glBlendFunci)
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) WEAKGL;
static void (*p_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void w_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { if (p_glBlitFramebuffer) p_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
INTERPOSE(glBlitFramebuffer)
void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) WEAKGL;
static void (*p_glBlitNamedFramebuffer)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
static void w_glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { if (p_glBlitNamedFramebuffer) p_glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
INTERPOSE(glBlitNamedFramebuffer)
void glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) WEAKGL;
static void (*p_glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
static void w_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage) { if (p_glBufferData) p_glBufferData(target, size, data, usage); }
INTERPOSE(glBufferData)
void glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) WEAKGL;
static void (*p_glBufferStorage)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
static void w_glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) { if (p_glBufferStorage) p_glBufferStorage(target, size, data, flags); }
INTERPOSE(glBufferStorage)
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) WEAKGL;
static void (*p_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
static void w_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data) { if (p_glBufferSubData) p_glBufferSubData(target, offset, size, data); }
INTERPOSE(glBufferSubData)
void glCallList(GLuint list) WEAKGL;
static void (*p_glCallList)(GLuint list);
static void w_glCallList(GLuint list) { if (p_glCallList) p_glCallList(list); }
INTERPOSE(glCallList)
void glCallLists(GLsizei n, GLenum type, const void *lists) WEAKGL;
static void (*p_glCallLists)(GLsizei n, GLenum type, const void *lists);
static void w_glCallLists(GLsizei n, GLenum type, const void *lists) { if (p_glCallLists) p_glCallLists(n, type, lists); }
INTERPOSE(glCallLists)
GLenum glCheckFramebufferStatus(GLenum target) WEAKGL;
static GLenum (*p_glCheckFramebufferStatus)(GLenum target);
static GLenum w_glCheckFramebufferStatus(GLenum target) { if (!p_glCheckFramebufferStatus) return (GLenum)0; return p_glCheckFramebufferStatus(target); }
INTERPOSE(glCheckFramebufferStatus)
GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) WEAKGL;
static GLenum (*p_glCheckNamedFramebufferStatus)(GLuint framebuffer, GLenum target);
static GLenum w_glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) { if (!p_glCheckNamedFramebufferStatus) return (GLenum)0; return p_glCheckNamedFramebufferStatus(framebuffer, target); }
INTERPOSE(glCheckNamedFramebufferStatus)
void glClampColor(GLenum target, GLenum clamp) WEAKGL;
static void (*p_glClampColor)(GLenum target, GLenum clamp);
static void w_glClampColor(GLenum target, GLenum clamp) { if (p_glClampColor) p_glClampColor(target, clamp); }
INTERPOSE(glClampColor)
void glClear(GLbitfield mask) WEAKGL;
static void (*p_glClear)(GLbitfield mask);
static void w_glClear(GLbitfield mask) { if (p_glClear) p_glClear(mask); }
INTERPOSE(glClear)
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (p_glClearAccum) p_glClearAccum(red, green, blue, alpha); }
INTERPOSE(glClearAccum)
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearBufferData)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
static void w_glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) { if (p_glClearBufferData) p_glClearBufferData(target, internalformat, format, type, data); }
INTERPOSE(glClearBufferData)
void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearBufferSubData)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
static void w_glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { if (p_glClearBufferSubData) p_glClearBufferSubData(target, internalformat, offset, size, format, type, data); }
INTERPOSE(glClearBufferSubData)
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) WEAKGL;
static void (*p_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static void w_glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { if (p_glClearBufferfi) p_glClearBufferfi(buffer, drawbuffer, depth, stencil); }
INTERPOSE(glClearBufferfi)
void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) WEAKGL;
static void (*p_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void w_glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) { if (p_glClearBufferfv) p_glClearBufferfv(buffer, drawbuffer, value); }
INTERPOSE(glClearBufferfv)
void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) WEAKGL;
static void (*p_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
static void w_glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) { if (p_glClearBufferiv) p_glClearBufferiv(buffer, drawbuffer, value); }
INTERPOSE(glClearBufferiv)
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) WEAKGL;
static void (*p_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
static void w_glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) { if (p_glClearBufferuiv) p_glClearBufferuiv(buffer, drawbuffer, value); }
INTERPOSE(glClearBufferuiv)
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (p_glClearColor) p_glClearColor(red, green, blue, alpha); }
INTERPOSE(glClearColor)
void glClearDepth(GLdouble depth) WEAKGL;
static void (*p_glClearDepth)(GLdouble depth);
static void w_glClearDepth(GLdouble depth) { if (p_glClearDepth) p_glClearDepth(depth); }
INTERPOSE(glClearDepth)
void glClearDepthf(GLfloat d) WEAKGL;
static void (*p_glClearDepthf)(GLfloat d);
static void w_glClearDepthf(GLfloat d) { if (p_glClearDepthf) p_glClearDepthf(d); }
INTERPOSE(glClearDepthf)
void glClearIndex(GLfloat c) WEAKGL;
static void (*p_glClearIndex)(GLfloat c);
static void w_glClearIndex(GLfloat c) { if (p_glClearIndex) p_glClearIndex(c); }
INTERPOSE(glClearIndex)
void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearNamedBufferData)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
static void w_glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) { if (p_glClearNamedBufferData) p_glClearNamedBufferData(buffer, internalformat, format, type, data); }
INTERPOSE(glClearNamedBufferData)
void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearNamedBufferSubData)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
static void w_glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) { if (p_glClearNamedBufferSubData) p_glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data); }
INTERPOSE(glClearNamedBufferSubData)
void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) WEAKGL;
static void (*p_glClearNamedFramebufferfi)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
static void w_glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { if (p_glClearNamedFramebufferfi) p_glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil); }
INTERPOSE(glClearNamedFramebufferfi)
void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) WEAKGL;
static void (*p_glClearNamedFramebufferfv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
static void w_glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) { if (p_glClearNamedFramebufferfv) p_glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value); }
INTERPOSE(glClearNamedFramebufferfv)
void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) WEAKGL;
static void (*p_glClearNamedFramebufferiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
static void w_glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) { if (p_glClearNamedFramebufferiv) p_glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value); }
INTERPOSE(glClearNamedFramebufferiv)
void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) WEAKGL;
static void (*p_glClearNamedFramebufferuiv)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
static void w_glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) { if (p_glClearNamedFramebufferuiv) p_glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value); }
INTERPOSE(glClearNamedFramebufferuiv)
void glClearStencil(GLint s) WEAKGL;
static void (*p_glClearStencil)(GLint s);
static void w_glClearStencil(GLint s) { if (p_glClearStencil) p_glClearStencil(s); }
INTERPOSE(glClearStencil)
void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearTexImage)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
static void w_glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data) { if (p_glClearTexImage) p_glClearTexImage(texture, level, format, type, data); }
INTERPOSE(glClearTexImage)
void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) WEAKGL;
static void (*p_glClearTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
static void w_glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) { if (p_glClearTexSubImage) p_glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data); }
INTERPOSE(glClearTexSubImage)
void glClientActiveTexture(GLenum texture) WEAKGL;
static void (*p_glClientActiveTexture)(GLenum texture);
static void w_glClientActiveTexture(GLenum texture) { if (p_glClientActiveTexture) p_glClientActiveTexture(texture); }
INTERPOSE(glClientActiveTexture)
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) WEAKGL;
static GLenum (*p_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
static GLenum w_glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { if (!p_glClientWaitSync) return (GLenum)0; return p_glClientWaitSync(sync, flags, timeout); }
INTERPOSE(glClientWaitSync)
void glClipControl(GLenum origin, GLenum depth) WEAKGL;
static void (*p_glClipControl)(GLenum origin, GLenum depth);
static void w_glClipControl(GLenum origin, GLenum depth) { if (p_glClipControl) p_glClipControl(origin, depth); }
INTERPOSE(glClipControl)
void glClipPlane(GLenum plane, const GLdouble *equation) WEAKGL;
static void (*p_glClipPlane)(GLenum plane, const GLdouble *equation);
static void w_glClipPlane(GLenum plane, const GLdouble *equation) { if (p_glClipPlane) p_glClipPlane(plane, equation); }
INTERPOSE(glClipPlane)
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) WEAKGL;
static void (*p_glColor3b)(GLbyte red, GLbyte green, GLbyte blue);
static void w_glColor3b(GLbyte red, GLbyte green, GLbyte blue) { if (p_glColor3b) p_glColor3b(red, green, blue); }
INTERPOSE(glColor3b)
void glColor3bv(const GLbyte *v) WEAKGL;
static void (*p_glColor3bv)(const GLbyte *v);
static void w_glColor3bv(const GLbyte *v) { if (p_glColor3bv) p_glColor3bv(v); }
INTERPOSE(glColor3bv)
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) WEAKGL;
static void (*p_glColor3d)(GLdouble red, GLdouble green, GLdouble blue);
static void w_glColor3d(GLdouble red, GLdouble green, GLdouble blue) { if (p_glColor3d) p_glColor3d(red, green, blue); }
INTERPOSE(glColor3d)
void glColor3dv(const GLdouble *v) WEAKGL;
static void (*p_glColor3dv)(const GLdouble *v);
static void w_glColor3dv(const GLdouble *v) { if (p_glColor3dv) p_glColor3dv(v); }
INTERPOSE(glColor3dv)
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) WEAKGL;
static void (*p_glColor3f)(GLfloat red, GLfloat green, GLfloat blue);
static void w_glColor3f(GLfloat red, GLfloat green, GLfloat blue) { if (p_glColor3f) p_glColor3f(red, green, blue); }
INTERPOSE(glColor3f)
void glColor3fv(const GLfloat *v) WEAKGL;
static void (*p_glColor3fv)(const GLfloat *v);
static void w_glColor3fv(const GLfloat *v) { if (p_glColor3fv) p_glColor3fv(v); }
INTERPOSE(glColor3fv)
void glColor3i(GLint red, GLint green, GLint blue) WEAKGL;
static void (*p_glColor3i)(GLint red, GLint green, GLint blue);
static void w_glColor3i(GLint red, GLint green, GLint blue) { if (p_glColor3i) p_glColor3i(red, green, blue); }
INTERPOSE(glColor3i)
void glColor3iv(const GLint *v) WEAKGL;
static void (*p_glColor3iv)(const GLint *v);
static void w_glColor3iv(const GLint *v) { if (p_glColor3iv) p_glColor3iv(v); }
INTERPOSE(glColor3iv)
void glColor3s(GLshort red, GLshort green, GLshort blue) WEAKGL;
static void (*p_glColor3s)(GLshort red, GLshort green, GLshort blue);
static void w_glColor3s(GLshort red, GLshort green, GLshort blue) { if (p_glColor3s) p_glColor3s(red, green, blue); }
INTERPOSE(glColor3s)
void glColor3sv(const GLshort *v) WEAKGL;
static void (*p_glColor3sv)(const GLshort *v);
static void w_glColor3sv(const GLshort *v) { if (p_glColor3sv) p_glColor3sv(v); }
INTERPOSE(glColor3sv)
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) WEAKGL;
static void (*p_glColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
static void w_glColor3ub(GLubyte red, GLubyte green, GLubyte blue) { if (p_glColor3ub) p_glColor3ub(red, green, blue); }
INTERPOSE(glColor3ub)
void glColor3ubv(const GLubyte *v) WEAKGL;
static void (*p_glColor3ubv)(const GLubyte *v);
static void w_glColor3ubv(const GLubyte *v) { if (p_glColor3ubv) p_glColor3ubv(v); }
INTERPOSE(glColor3ubv)
void glColor3ui(GLuint red, GLuint green, GLuint blue) WEAKGL;
static void (*p_glColor3ui)(GLuint red, GLuint green, GLuint blue);
static void w_glColor3ui(GLuint red, GLuint green, GLuint blue) { if (p_glColor3ui) p_glColor3ui(red, green, blue); }
INTERPOSE(glColor3ui)
void glColor3uiv(const GLuint *v) WEAKGL;
static void (*p_glColor3uiv)(const GLuint *v);
static void w_glColor3uiv(const GLuint *v) { if (p_glColor3uiv) p_glColor3uiv(v); }
INTERPOSE(glColor3uiv)
void glColor3us(GLushort red, GLushort green, GLushort blue) WEAKGL;
static void (*p_glColor3us)(GLushort red, GLushort green, GLushort blue);
static void w_glColor3us(GLushort red, GLushort green, GLushort blue) { if (p_glColor3us) p_glColor3us(red, green, blue); }
INTERPOSE(glColor3us)
void glColor3usv(const GLushort *v) WEAKGL;
static void (*p_glColor3usv)(const GLushort *v);
static void w_glColor3usv(const GLushort *v) { if (p_glColor3usv) p_glColor3usv(v); }
INTERPOSE(glColor3usv)
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) WEAKGL;
static void (*p_glColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
static void w_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) { if (p_glColor4b) p_glColor4b(red, green, blue, alpha); }
INTERPOSE(glColor4b)
void glColor4bv(const GLbyte *v) WEAKGL;
static void (*p_glColor4bv)(const GLbyte *v);
static void w_glColor4bv(const GLbyte *v) { if (p_glColor4bv) p_glColor4bv(v); }
INTERPOSE(glColor4bv)
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) WEAKGL;
static void (*p_glColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
static void w_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) { if (p_glColor4d) p_glColor4d(red, green, blue, alpha); }
INTERPOSE(glColor4d)
void glColor4dv(const GLdouble *v) WEAKGL;
static void (*p_glColor4dv)(const GLdouble *v);
static void w_glColor4dv(const GLdouble *v) { if (p_glColor4dv) p_glColor4dv(v); }
INTERPOSE(glColor4dv)
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) WEAKGL;
static void (*p_glColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void w_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { if (p_glColor4f) p_glColor4f(red, green, blue, alpha); }
INTERPOSE(glColor4f)
void glColor4fv(const GLfloat *v) WEAKGL;
static void (*p_glColor4fv)(const GLfloat *v);
static void w_glColor4fv(const GLfloat *v) { if (p_glColor4fv) p_glColor4fv(v); }
INTERPOSE(glColor4fv)
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) WEAKGL;
static void (*p_glColor4i)(GLint red, GLint green, GLint blue, GLint alpha);
static void w_glColor4i(GLint red, GLint green, GLint blue, GLint alpha) { if (p_glColor4i) p_glColor4i(red, green, blue, alpha); }
INTERPOSE(glColor4i)
void glColor4iv(const GLint *v) WEAKGL;
static void (*p_glColor4iv)(const GLint *v);
static void w_glColor4iv(const GLint *v) { if (p_glColor4iv) p_glColor4iv(v); }
INTERPOSE(glColor4iv)
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) WEAKGL;
static void (*p_glColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
static void w_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) { if (p_glColor4s) p_glColor4s(red, green, blue, alpha); }
INTERPOSE(glColor4s)
void glColor4sv(const GLshort *v) WEAKGL;
static void (*p_glColor4sv)(const GLshort *v);
static void w_glColor4sv(const GLshort *v) { if (p_glColor4sv) p_glColor4sv(v); }
INTERPOSE(glColor4sv)
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) WEAKGL;
static void (*p_glColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
static void w_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) { if (p_glColor4ub) p_glColor4ub(red, green, blue, alpha); }
INTERPOSE(glColor4ub)
void glColor4ubv(const GLubyte *v) WEAKGL;
static void (*p_glColor4ubv)(const GLubyte *v);
static void w_glColor4ubv(const GLubyte *v) { if (p_glColor4ubv) p_glColor4ubv(v); }
INTERPOSE(glColor4ubv)
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) WEAKGL;
static void (*p_glColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
static void w_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) { if (p_glColor4ui) p_glColor4ui(red, green, blue, alpha); }
INTERPOSE(glColor4ui)
void glColor4uiv(const GLuint *v) WEAKGL;
static void (*p_glColor4uiv)(const GLuint *v);
static void w_glColor4uiv(const GLuint *v) { if (p_glColor4uiv) p_glColor4uiv(v); }
INTERPOSE(glColor4uiv)
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) WEAKGL;
static void (*p_glColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
static void w_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) { if (p_glColor4us) p_glColor4us(red, green, blue, alpha); }
INTERPOSE(glColor4us)
void glColor4usv(const GLushort *v) WEAKGL;
static void (*p_glColor4usv)(const GLushort *v);
static void w_glColor4usv(const GLushort *v) { if (p_glColor4usv) p_glColor4usv(v); }
INTERPOSE(glColor4usv)
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) WEAKGL;
static void (*p_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
static void w_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { if (p_glColorMask) p_glColorMask(red, green, blue, alpha); }
INTERPOSE(glColorMask)
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) WEAKGL;
static void (*p_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
static void w_glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { if (p_glColorMaski) p_glColorMaski(index, r, g, b, a); }
INTERPOSE(glColorMaski)
void glColorMaterial(GLenum face, GLenum mode) WEAKGL;
static void (*p_glColorMaterial)(GLenum face, GLenum mode);
static void w_glColorMaterial(GLenum face, GLenum mode) { if (p_glColorMaterial) p_glColorMaterial(face, mode); }
INTERPOSE(glColorMaterial)
void glColorP3ui(GLenum type, GLuint color) WEAKGL;
static void (*p_glColorP3ui)(GLenum type, GLuint color);
static void w_glColorP3ui(GLenum type, GLuint color) { if (p_glColorP3ui) p_glColorP3ui(type, color); }
INTERPOSE(glColorP3ui)
void glColorP3uiv(GLenum type, const GLuint *color) WEAKGL;
static void (*p_glColorP3uiv)(GLenum type, const GLuint *color);
static void w_glColorP3uiv(GLenum type, const GLuint *color) { if (p_glColorP3uiv) p_glColorP3uiv(type, color); }
INTERPOSE(glColorP3uiv)
void glColorP4ui(GLenum type, GLuint color) WEAKGL;
static void (*p_glColorP4ui)(GLenum type, GLuint color);
static void w_glColorP4ui(GLenum type, GLuint color) { if (p_glColorP4ui) p_glColorP4ui(type, color); }
INTERPOSE(glColorP4ui)
void glColorP4uiv(GLenum type, const GLuint *color) WEAKGL;
static void (*p_glColorP4uiv)(GLenum type, const GLuint *color);
static void w_glColorP4uiv(GLenum type, const GLuint *color) { if (p_glColorP4uiv) p_glColorP4uiv(type, color); }
INTERPOSE(glColorP4uiv)
void glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glColorPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (p_glColorPointer) p_glColorPointer(size, type, stride, pointer); }
INTERPOSE(glColorPointer)
void glCompileShader(GLuint shader) WEAKGL;
static void (*p_glCompileShader)(GLuint shader);
static void w_glCompileShader(GLuint shader) { if (p_glCompileShader) p_glCompileShader(shader); }
INTERPOSE(glCompileShader)
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
static void w_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) { if (p_glCompressedTexImage1D) p_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
INTERPOSE(glCompressedTexImage1D)
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
static void w_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) { if (p_glCompressedTexImage2D) p_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
INTERPOSE(glCompressedTexImage2D)
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
static void w_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) { if (p_glCompressedTexImage3D) p_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
INTERPOSE(glCompressedTexImage3D)
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { if (p_glCompressedTexSubImage1D) p_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
INTERPOSE(glCompressedTexSubImage1D)
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { if (p_glCompressedTexSubImage2D) p_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
INTERPOSE(glCompressedTexSubImage2D)
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { if (p_glCompressedTexSubImage3D) p_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
INTERPOSE(glCompressedTexSubImage3D)
void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) { if (p_glCompressedTextureSubImage1D) p_glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data); }
INTERPOSE(glCompressedTextureSubImage1D)
void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) { if (p_glCompressedTextureSubImage2D) p_glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data); }
INTERPOSE(glCompressedTextureSubImage2D)
void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) WEAKGL;
static void (*p_glCompressedTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
static void w_glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) { if (p_glCompressedTextureSubImage3D) p_glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
INTERPOSE(glCompressedTextureSubImage3D)
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) WEAKGL;
static void (*p_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
static void w_glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { if (p_glCopyBufferSubData) p_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size); }
INTERPOSE(glCopyBufferSubData)
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) WEAKGL;
static void (*p_glCopyImageSubData)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
static void w_glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) { if (p_glCopyImageSubData) p_glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth); }
INTERPOSE(glCopyImageSubData)
void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) WEAKGL;
static void (*p_glCopyNamedBufferSubData)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
static void w_glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) { if (p_glCopyNamedBufferSubData) p_glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size); }
INTERPOSE(glCopyNamedBufferSubData)
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) WEAKGL;
static void (*p_glCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
static void w_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) { if (p_glCopyPixels) p_glCopyPixels(x, y, width, height, type); }
INTERPOSE(glCopyPixels)
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) WEAKGL;
static void (*p_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
static void w_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) { if (p_glCopyTexImage1D) p_glCopyTexImage1D(target, level, internalformat, x, y, width, border); }
INTERPOSE(glCopyTexImage1D)
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) WEAKGL;
static void (*p_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
static void w_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { if (p_glCopyTexImage2D) p_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
INTERPOSE(glCopyTexImage2D)
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) WEAKGL;
static void (*p_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void w_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { if (p_glCopyTexSubImage1D) p_glCopyTexSubImage1D(target, level, xoffset, x, y, width); }
INTERPOSE(glCopyTexSubImage1D)
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glCopyTexSubImage2D) p_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
INTERPOSE(glCopyTexSubImage2D)
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glCopyTexSubImage3D) p_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }
INTERPOSE(glCopyTexSubImage3D)
void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) WEAKGL;
static void (*p_glCopyTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
static void w_glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { if (p_glCopyTextureSubImage1D) p_glCopyTextureSubImage1D(texture, level, xoffset, x, y, width); }
INTERPOSE(glCopyTextureSubImage1D)
void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glCopyTextureSubImage2D) p_glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height); }
INTERPOSE(glCopyTextureSubImage2D)
void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glCopyTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glCopyTextureSubImage3D) p_glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height); }
INTERPOSE(glCopyTextureSubImage3D)
void glCreateBuffers(GLsizei n, GLuint *buffers) WEAKGL;
static void (*p_glCreateBuffers)(GLsizei n, GLuint *buffers);
static void w_glCreateBuffers(GLsizei n, GLuint *buffers) { if (p_glCreateBuffers) p_glCreateBuffers(n, buffers); }
INTERPOSE(glCreateBuffers)
void glCreateFramebuffers(GLsizei n, GLuint *framebuffers) WEAKGL;
static void (*p_glCreateFramebuffers)(GLsizei n, GLuint *framebuffers);
static void w_glCreateFramebuffers(GLsizei n, GLuint *framebuffers) { if (p_glCreateFramebuffers) p_glCreateFramebuffers(n, framebuffers); }
INTERPOSE(glCreateFramebuffers)
GLuint glCreateProgram(void) WEAKGL;
static GLuint (*p_glCreateProgram)(void);
static GLuint w_glCreateProgram(void) { if (!p_glCreateProgram) return (GLuint)0; return p_glCreateProgram(); }
INTERPOSE(glCreateProgram)
void glCreateProgramPipelines(GLsizei n, GLuint *pipelines) WEAKGL;
static void (*p_glCreateProgramPipelines)(GLsizei n, GLuint *pipelines);
static void w_glCreateProgramPipelines(GLsizei n, GLuint *pipelines) { if (p_glCreateProgramPipelines) p_glCreateProgramPipelines(n, pipelines); }
INTERPOSE(glCreateProgramPipelines)
void glCreateQueries(GLenum target, GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glCreateQueries)(GLenum target, GLsizei n, GLuint *ids);
static void w_glCreateQueries(GLenum target, GLsizei n, GLuint *ids) { if (p_glCreateQueries) p_glCreateQueries(target, n, ids); }
INTERPOSE(glCreateQueries)
void glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers) WEAKGL;
static void (*p_glCreateRenderbuffers)(GLsizei n, GLuint *renderbuffers);
static void w_glCreateRenderbuffers(GLsizei n, GLuint *renderbuffers) { if (p_glCreateRenderbuffers) p_glCreateRenderbuffers(n, renderbuffers); }
INTERPOSE(glCreateRenderbuffers)
void glCreateSamplers(GLsizei n, GLuint *samplers) WEAKGL;
static void (*p_glCreateSamplers)(GLsizei n, GLuint *samplers);
static void w_glCreateSamplers(GLsizei n, GLuint *samplers) { if (p_glCreateSamplers) p_glCreateSamplers(n, samplers); }
INTERPOSE(glCreateSamplers)
GLuint glCreateShader(GLenum type) WEAKGL;
static GLuint (*p_glCreateShader)(GLenum type);
static GLuint w_glCreateShader(GLenum type) { if (!p_glCreateShader) return (GLuint)0; return p_glCreateShader(type); }
INTERPOSE(glCreateShader)
GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) WEAKGL;
static GLuint (*p_glCreateShaderProgramv)(GLenum type, GLsizei count, const GLchar *const*strings);
static GLuint w_glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const*strings) { if (!p_glCreateShaderProgramv) return (GLuint)0; return p_glCreateShaderProgramv(type, count, strings); }
INTERPOSE(glCreateShaderProgramv)
void glCreateTextures(GLenum target, GLsizei n, GLuint *textures) WEAKGL;
static void (*p_glCreateTextures)(GLenum target, GLsizei n, GLuint *textures);
static void w_glCreateTextures(GLenum target, GLsizei n, GLuint *textures) { if (p_glCreateTextures) p_glCreateTextures(target, n, textures); }
INTERPOSE(glCreateTextures)
void glCreateTransformFeedbacks(GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
static void w_glCreateTransformFeedbacks(GLsizei n, GLuint *ids) { if (p_glCreateTransformFeedbacks) p_glCreateTransformFeedbacks(n, ids); }
INTERPOSE(glCreateTransformFeedbacks)
void glCreateVertexArrays(GLsizei n, GLuint *arrays) WEAKGL;
static void (*p_glCreateVertexArrays)(GLsizei n, GLuint *arrays);
static void w_glCreateVertexArrays(GLsizei n, GLuint *arrays) { if (p_glCreateVertexArrays) p_glCreateVertexArrays(n, arrays); }
INTERPOSE(glCreateVertexArrays)
void glCullFace(GLenum mode) WEAKGL;
static void (*p_glCullFace)(GLenum mode);
static void w_glCullFace(GLenum mode) { if (p_glCullFace) p_glCullFace(mode); }
INTERPOSE(glCullFace)
void glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) WEAKGL;
static void (*p_glDebugMessageCallback)(GLDEBUGPROC callback, const void *userParam);
static void w_glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam) { if (p_glDebugMessageCallback) p_glDebugMessageCallback(callback, userParam); }
INTERPOSE(glDebugMessageCallback)
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) WEAKGL;
static void (*p_glDebugMessageControl)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
static void w_glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) { if (p_glDebugMessageControl) p_glDebugMessageControl(source, type, severity, count, ids, enabled); }
INTERPOSE(glDebugMessageControl)
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) WEAKGL;
static void (*p_glDebugMessageInsert)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
static void w_glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) { if (p_glDebugMessageInsert) p_glDebugMessageInsert(source, type, id, severity, length, buf); }
INTERPOSE(glDebugMessageInsert)
void glDeleteBuffers(GLsizei n, const GLuint *buffers) WEAKGL;
static void (*p_glDeleteBuffers)(GLsizei n, const GLuint *buffers);
static void w_glDeleteBuffers(GLsizei n, const GLuint *buffers) { if (p_glDeleteBuffers) p_glDeleteBuffers(n, buffers); }
INTERPOSE(glDeleteBuffers)
void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) WEAKGL;
static void (*p_glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
static void w_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers) { if (p_glDeleteFramebuffers) p_glDeleteFramebuffers(n, framebuffers); }
INTERPOSE(glDeleteFramebuffers)
void glDeleteLists(GLuint list, GLsizei range) WEAKGL;
static void (*p_glDeleteLists)(GLuint list, GLsizei range);
static void w_glDeleteLists(GLuint list, GLsizei range) { if (p_glDeleteLists) p_glDeleteLists(list, range); }
INTERPOSE(glDeleteLists)
void glDeleteProgram(GLuint program) WEAKGL;
static void (*p_glDeleteProgram)(GLuint program);
static void w_glDeleteProgram(GLuint program) { if (p_glDeleteProgram) p_glDeleteProgram(program); }
INTERPOSE(glDeleteProgram)
void glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) WEAKGL;
static void (*p_glDeleteProgramPipelines)(GLsizei n, const GLuint *pipelines);
static void w_glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines) { if (p_glDeleteProgramPipelines) p_glDeleteProgramPipelines(n, pipelines); }
INTERPOSE(glDeleteProgramPipelines)
void glDeleteQueries(GLsizei n, const GLuint *ids) WEAKGL;
static void (*p_glDeleteQueries)(GLsizei n, const GLuint *ids);
static void w_glDeleteQueries(GLsizei n, const GLuint *ids) { if (p_glDeleteQueries) p_glDeleteQueries(n, ids); }
INTERPOSE(glDeleteQueries)
void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) WEAKGL;
static void (*p_glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
static void w_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { if (p_glDeleteRenderbuffers) p_glDeleteRenderbuffers(n, renderbuffers); }
INTERPOSE(glDeleteRenderbuffers)
void glDeleteSamplers(GLsizei count, const GLuint *samplers) WEAKGL;
static void (*p_glDeleteSamplers)(GLsizei count, const GLuint *samplers);
static void w_glDeleteSamplers(GLsizei count, const GLuint *samplers) { if (p_glDeleteSamplers) p_glDeleteSamplers(count, samplers); }
INTERPOSE(glDeleteSamplers)
void glDeleteShader(GLuint shader) WEAKGL;
static void (*p_glDeleteShader)(GLuint shader);
static void w_glDeleteShader(GLuint shader) { if (p_glDeleteShader) p_glDeleteShader(shader); }
INTERPOSE(glDeleteShader)
void glDeleteSync(GLsync sync) WEAKGL;
static void (*p_glDeleteSync)(GLsync sync);
static void w_glDeleteSync(GLsync sync) { if (p_glDeleteSync) p_glDeleteSync(sync); }
INTERPOSE(glDeleteSync)
void glDeleteTextures(GLsizei n, const GLuint *textures) WEAKGL;
static void (*p_glDeleteTextures)(GLsizei n, const GLuint *textures);
static void w_glDeleteTextures(GLsizei n, const GLuint *textures) { if (p_glDeleteTextures) p_glDeleteTextures(n, textures); }
INTERPOSE(glDeleteTextures)
void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) WEAKGL;
static void (*p_glDeleteTransformFeedbacks)(GLsizei n, const GLuint *ids);
static void w_glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids) { if (p_glDeleteTransformFeedbacks) p_glDeleteTransformFeedbacks(n, ids); }
INTERPOSE(glDeleteTransformFeedbacks)
void glDeleteVertexArrays(GLsizei n, const GLuint *arrays) WEAKGL;
static void (*p_glDeleteVertexArrays)(GLsizei n, const GLuint *arrays);
static void w_glDeleteVertexArrays(GLsizei n, const GLuint *arrays) { if (p_glDeleteVertexArrays) p_glDeleteVertexArrays(n, arrays); }
INTERPOSE(glDeleteVertexArrays)
void glDepthFunc(GLenum func) WEAKGL;
static void (*p_glDepthFunc)(GLenum func);
static void w_glDepthFunc(GLenum func) { if (p_glDepthFunc) p_glDepthFunc(func); }
INTERPOSE(glDepthFunc)
void glDepthMask(GLboolean flag) WEAKGL;
static void (*p_glDepthMask)(GLboolean flag);
static void w_glDepthMask(GLboolean flag) { if (p_glDepthMask) p_glDepthMask(flag); }
INTERPOSE(glDepthMask)
void glDepthRange(GLdouble n, GLdouble f) WEAKGL;
static void (*p_glDepthRange)(GLdouble n, GLdouble f);
static void w_glDepthRange(GLdouble n, GLdouble f) { if (p_glDepthRange) p_glDepthRange(n, f); }
INTERPOSE(glDepthRange)
void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) WEAKGL;
static void (*p_glDepthRangeArrayv)(GLuint first, GLsizei count, const GLdouble *v);
static void w_glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v) { if (p_glDepthRangeArrayv) p_glDepthRangeArrayv(first, count, v); }
INTERPOSE(glDepthRangeArrayv)
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) WEAKGL;
static void (*p_glDepthRangeIndexed)(GLuint index, GLdouble n, GLdouble f);
static void w_glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) { if (p_glDepthRangeIndexed) p_glDepthRangeIndexed(index, n, f); }
INTERPOSE(glDepthRangeIndexed)
void glDepthRangef(GLfloat n, GLfloat f) WEAKGL;
static void (*p_glDepthRangef)(GLfloat n, GLfloat f);
static void w_glDepthRangef(GLfloat n, GLfloat f) { if (p_glDepthRangef) p_glDepthRangef(n, f); }
INTERPOSE(glDepthRangef)
void glDetachShader(GLuint program, GLuint shader) WEAKGL;
static void (*p_glDetachShader)(GLuint program, GLuint shader);
static void w_glDetachShader(GLuint program, GLuint shader) { if (p_glDetachShader) p_glDetachShader(program, shader); }
INTERPOSE(glDetachShader)
void glDisable(GLenum cap) WEAKGL;
static void (*p_glDisable)(GLenum cap);
static void w_glDisable(GLenum cap) { if (p_glDisable) p_glDisable(cap); }
INTERPOSE(glDisable)
void glDisableClientState(GLenum array) WEAKGL;
static void (*p_glDisableClientState)(GLenum array);
static void w_glDisableClientState(GLenum array) { if (p_glDisableClientState) p_glDisableClientState(array); }
INTERPOSE(glDisableClientState)
void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) WEAKGL;
static void (*p_glDisableVertexArrayAttrib)(GLuint vaobj, GLuint index);
static void w_glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) { if (p_glDisableVertexArrayAttrib) p_glDisableVertexArrayAttrib(vaobj, index); }
INTERPOSE(glDisableVertexArrayAttrib)
void glDisableVertexAttribArray(GLuint index) WEAKGL;
static void (*p_glDisableVertexAttribArray)(GLuint index);
static void w_glDisableVertexAttribArray(GLuint index) { if (p_glDisableVertexAttribArray) p_glDisableVertexAttribArray(index); }
INTERPOSE(glDisableVertexAttribArray)
void glDisablei(GLenum target, GLuint index) WEAKGL;
static void (*p_glDisablei)(GLenum target, GLuint index);
static void w_glDisablei(GLenum target, GLuint index) { if (p_glDisablei) p_glDisablei(target, index); }
INTERPOSE(glDisablei)
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) WEAKGL;
static void (*p_glDispatchCompute)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
static void w_glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) { if (p_glDispatchCompute) p_glDispatchCompute(num_groups_x, num_groups_y, num_groups_z); }
INTERPOSE(glDispatchCompute)
void glDispatchComputeIndirect(GLintptr indirect) WEAKGL;
static void (*p_glDispatchComputeIndirect)(GLintptr indirect);
static void w_glDispatchComputeIndirect(GLintptr indirect) { if (p_glDispatchComputeIndirect) p_glDispatchComputeIndirect(indirect); }
INTERPOSE(glDispatchComputeIndirect)
void glDrawArrays(GLenum mode, GLint first, GLsizei count) WEAKGL;
static void (*p_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
static void w_glDrawArrays(GLenum mode, GLint first, GLsizei count) { if (p_glDrawArrays) p_glDrawArrays(mode, first, count); }
INTERPOSE(glDrawArrays)
void glDrawArraysIndirect(GLenum mode, const void *indirect) WEAKGL;
static void (*p_glDrawArraysIndirect)(GLenum mode, const void *indirect);
static void w_glDrawArraysIndirect(GLenum mode, const void *indirect) { if (p_glDrawArraysIndirect) p_glDrawArraysIndirect(mode, indirect); }
INTERPOSE(glDrawArraysIndirect)
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) WEAKGL;
static void (*p_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
static void w_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { if (p_glDrawArraysInstanced) p_glDrawArraysInstanced(mode, first, count, instancecount); }
INTERPOSE(glDrawArraysInstanced)
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) WEAKGL;
static void (*p_glDrawArraysInstancedBaseInstance)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
static void w_glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) { if (p_glDrawArraysInstancedBaseInstance) p_glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance); }
INTERPOSE(glDrawArraysInstancedBaseInstance)
void glDrawBuffer(GLenum buf) WEAKGL;
static void (*p_glDrawBuffer)(GLenum buf);
static void w_glDrawBuffer(GLenum buf) { if (p_glDrawBuffer) p_glDrawBuffer(buf); }
INTERPOSE(glDrawBuffer)
void glDrawBuffers(GLsizei n, const GLenum *bufs) WEAKGL;
static void (*p_glDrawBuffers)(GLsizei n, const GLenum *bufs);
static void w_glDrawBuffers(GLsizei n, const GLenum *bufs) { if (p_glDrawBuffers) p_glDrawBuffers(n, bufs); }
INTERPOSE(glDrawBuffers)
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) WEAKGL;
static void (*p_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
static void w_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) { if (p_glDrawElements) p_glDrawElements(mode, count, type, indices); }
INTERPOSE(glDrawElements)
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) WEAKGL;
static void (*p_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
static void w_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) { if (p_glDrawElementsBaseVertex) p_glDrawElementsBaseVertex(mode, count, type, indices, basevertex); }
INTERPOSE(glDrawElementsBaseVertex)
void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) WEAKGL;
static void (*p_glDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect);
static void w_glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) { if (p_glDrawElementsIndirect) p_glDrawElementsIndirect(mode, type, indirect); }
INTERPOSE(glDrawElementsIndirect)
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) WEAKGL;
static void (*p_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
static void w_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) { if (p_glDrawElementsInstanced) p_glDrawElementsInstanced(mode, count, type, indices, instancecount); }
INTERPOSE(glDrawElementsInstanced)
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) WEAKGL;
static void (*p_glDrawElementsInstancedBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
static void w_glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) { if (p_glDrawElementsInstancedBaseInstance) p_glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance); }
INTERPOSE(glDrawElementsInstancedBaseInstance)
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) WEAKGL;
static void (*p_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
static void w_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) { if (p_glDrawElementsInstancedBaseVertex) p_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex); }
INTERPOSE(glDrawElementsInstancedBaseVertex)
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) WEAKGL;
static void (*p_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
static void w_glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) { if (p_glDrawElementsInstancedBaseVertexBaseInstance) p_glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance); }
INTERPOSE(glDrawElementsInstancedBaseVertexBaseInstance)
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void w_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { if (p_glDrawPixels) p_glDrawPixels(width, height, format, type, pixels); }
INTERPOSE(glDrawPixels)
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) WEAKGL;
static void (*p_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
static void w_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) { if (p_glDrawRangeElements) p_glDrawRangeElements(mode, start, end, count, type, indices); }
INTERPOSE(glDrawRangeElements)
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) WEAKGL;
static void (*p_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
static void w_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) { if (p_glDrawRangeElementsBaseVertex) p_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex); }
INTERPOSE(glDrawRangeElementsBaseVertex)
void glDrawTransformFeedback(GLenum mode, GLuint id) WEAKGL;
static void (*p_glDrawTransformFeedback)(GLenum mode, GLuint id);
static void w_glDrawTransformFeedback(GLenum mode, GLuint id) { if (p_glDrawTransformFeedback) p_glDrawTransformFeedback(mode, id); }
INTERPOSE(glDrawTransformFeedback)
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) WEAKGL;
static void (*p_glDrawTransformFeedbackInstanced)(GLenum mode, GLuint id, GLsizei instancecount);
static void w_glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) { if (p_glDrawTransformFeedbackInstanced) p_glDrawTransformFeedbackInstanced(mode, id, instancecount); }
INTERPOSE(glDrawTransformFeedbackInstanced)
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) WEAKGL;
static void (*p_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream);
static void w_glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) { if (p_glDrawTransformFeedbackStream) p_glDrawTransformFeedbackStream(mode, id, stream); }
INTERPOSE(glDrawTransformFeedbackStream)
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) WEAKGL;
static void (*p_glDrawTransformFeedbackStreamInstanced)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
static void w_glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) { if (p_glDrawTransformFeedbackStreamInstanced) p_glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount); }
INTERPOSE(glDrawTransformFeedbackStreamInstanced)
void glEdgeFlag(GLboolean flag) WEAKGL;
static void (*p_glEdgeFlag)(GLboolean flag);
static void w_glEdgeFlag(GLboolean flag) { if (p_glEdgeFlag) p_glEdgeFlag(flag); }
INTERPOSE(glEdgeFlag)
void glEdgeFlagPointer(GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glEdgeFlagPointer)(GLsizei stride, const void *pointer);
static void w_glEdgeFlagPointer(GLsizei stride, const void *pointer) { if (p_glEdgeFlagPointer) p_glEdgeFlagPointer(stride, pointer); }
INTERPOSE(glEdgeFlagPointer)
void glEdgeFlagv(const GLboolean *flag) WEAKGL;
static void (*p_glEdgeFlagv)(const GLboolean *flag);
static void w_glEdgeFlagv(const GLboolean *flag) { if (p_glEdgeFlagv) p_glEdgeFlagv(flag); }
INTERPOSE(glEdgeFlagv)
void glEnable(GLenum cap) WEAKGL;
static void (*p_glEnable)(GLenum cap);
static void w_glEnable(GLenum cap) { if (p_glEnable) p_glEnable(cap); }
INTERPOSE(glEnable)
void glEnableClientState(GLenum array) WEAKGL;
static void (*p_glEnableClientState)(GLenum array);
static void w_glEnableClientState(GLenum array) { if (p_glEnableClientState) p_glEnableClientState(array); }
INTERPOSE(glEnableClientState)
void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) WEAKGL;
static void (*p_glEnableVertexArrayAttrib)(GLuint vaobj, GLuint index);
static void w_glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) { if (p_glEnableVertexArrayAttrib) p_glEnableVertexArrayAttrib(vaobj, index); }
INTERPOSE(glEnableVertexArrayAttrib)
void glEnableVertexAttribArray(GLuint index) WEAKGL;
static void (*p_glEnableVertexAttribArray)(GLuint index);
static void w_glEnableVertexAttribArray(GLuint index) { if (p_glEnableVertexAttribArray) p_glEnableVertexAttribArray(index); }
INTERPOSE(glEnableVertexAttribArray)
void glEnablei(GLenum target, GLuint index) WEAKGL;
static void (*p_glEnablei)(GLenum target, GLuint index);
static void w_glEnablei(GLenum target, GLuint index) { if (p_glEnablei) p_glEnablei(target, index); }
INTERPOSE(glEnablei)
void glEnd(void) WEAKGL;
static void (*p_glEnd)(void);
static void w_glEnd(void) { if (p_glEnd) p_glEnd(); }
INTERPOSE(glEnd)
void glEndConditionalRender(void) WEAKGL;
static void (*p_glEndConditionalRender)(void);
static void w_glEndConditionalRender(void) { if (p_glEndConditionalRender) p_glEndConditionalRender(); }
INTERPOSE(glEndConditionalRender)
void glEndList(void) WEAKGL;
static void (*p_glEndList)(void);
static void w_glEndList(void) { if (p_glEndList) p_glEndList(); }
INTERPOSE(glEndList)
void glEndQuery(GLenum target) WEAKGL;
static void (*p_glEndQuery)(GLenum target);
static void w_glEndQuery(GLenum target) { if (p_glEndQuery) p_glEndQuery(target); }
INTERPOSE(glEndQuery)
void glEndQueryIndexed(GLenum target, GLuint index) WEAKGL;
static void (*p_glEndQueryIndexed)(GLenum target, GLuint index);
static void w_glEndQueryIndexed(GLenum target, GLuint index) { if (p_glEndQueryIndexed) p_glEndQueryIndexed(target, index); }
INTERPOSE(glEndQueryIndexed)
void glEndTransformFeedback(void) WEAKGL;
static void (*p_glEndTransformFeedback)(void);
static void w_glEndTransformFeedback(void) { if (p_glEndTransformFeedback) p_glEndTransformFeedback(); }
INTERPOSE(glEndTransformFeedback)
void glEvalCoord1d(GLdouble u) WEAKGL;
static void (*p_glEvalCoord1d)(GLdouble u);
static void w_glEvalCoord1d(GLdouble u) { if (p_glEvalCoord1d) p_glEvalCoord1d(u); }
INTERPOSE(glEvalCoord1d)
void glEvalCoord1dv(const GLdouble *u) WEAKGL;
static void (*p_glEvalCoord1dv)(const GLdouble *u);
static void w_glEvalCoord1dv(const GLdouble *u) { if (p_glEvalCoord1dv) p_glEvalCoord1dv(u); }
INTERPOSE(glEvalCoord1dv)
void glEvalCoord1f(GLfloat u) WEAKGL;
static void (*p_glEvalCoord1f)(GLfloat u);
static void w_glEvalCoord1f(GLfloat u) { if (p_glEvalCoord1f) p_glEvalCoord1f(u); }
INTERPOSE(glEvalCoord1f)
void glEvalCoord1fv(const GLfloat *u) WEAKGL;
static void (*p_glEvalCoord1fv)(const GLfloat *u);
static void w_glEvalCoord1fv(const GLfloat *u) { if (p_glEvalCoord1fv) p_glEvalCoord1fv(u); }
INTERPOSE(glEvalCoord1fv)
void glEvalCoord2d(GLdouble u, GLdouble v) WEAKGL;
static void (*p_glEvalCoord2d)(GLdouble u, GLdouble v);
static void w_glEvalCoord2d(GLdouble u, GLdouble v) { if (p_glEvalCoord2d) p_glEvalCoord2d(u, v); }
INTERPOSE(glEvalCoord2d)
void glEvalCoord2dv(const GLdouble *u) WEAKGL;
static void (*p_glEvalCoord2dv)(const GLdouble *u);
static void w_glEvalCoord2dv(const GLdouble *u) { if (p_glEvalCoord2dv) p_glEvalCoord2dv(u); }
INTERPOSE(glEvalCoord2dv)
void glEvalCoord2f(GLfloat u, GLfloat v) WEAKGL;
static void (*p_glEvalCoord2f)(GLfloat u, GLfloat v);
static void w_glEvalCoord2f(GLfloat u, GLfloat v) { if (p_glEvalCoord2f) p_glEvalCoord2f(u, v); }
INTERPOSE(glEvalCoord2f)
void glEvalCoord2fv(const GLfloat *u) WEAKGL;
static void (*p_glEvalCoord2fv)(const GLfloat *u);
static void w_glEvalCoord2fv(const GLfloat *u) { if (p_glEvalCoord2fv) p_glEvalCoord2fv(u); }
INTERPOSE(glEvalCoord2fv)
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) WEAKGL;
static void (*p_glEvalMesh1)(GLenum mode, GLint i1, GLint i2);
static void w_glEvalMesh1(GLenum mode, GLint i1, GLint i2) { if (p_glEvalMesh1) p_glEvalMesh1(mode, i1, i2); }
INTERPOSE(glEvalMesh1)
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) WEAKGL;
static void (*p_glEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
static void w_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) { if (p_glEvalMesh2) p_glEvalMesh2(mode, i1, i2, j1, j2); }
INTERPOSE(glEvalMesh2)
void glEvalPoint1(GLint i) WEAKGL;
static void (*p_glEvalPoint1)(GLint i);
static void w_glEvalPoint1(GLint i) { if (p_glEvalPoint1) p_glEvalPoint1(i); }
INTERPOSE(glEvalPoint1)
void glEvalPoint2(GLint i, GLint j) WEAKGL;
static void (*p_glEvalPoint2)(GLint i, GLint j);
static void w_glEvalPoint2(GLint i, GLint j) { if (p_glEvalPoint2) p_glEvalPoint2(i, j); }
INTERPOSE(glEvalPoint2)
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) WEAKGL;
static void (*p_glFeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer);
static void w_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) { if (p_glFeedbackBuffer) p_glFeedbackBuffer(size, type, buffer); }
INTERPOSE(glFeedbackBuffer)
GLsync glFenceSync(GLenum condition, GLbitfield flags) WEAKGL;
static GLsync (*p_glFenceSync)(GLenum condition, GLbitfield flags);
static GLsync w_glFenceSync(GLenum condition, GLbitfield flags) { if (!p_glFenceSync) return (GLsync)0; return p_glFenceSync(condition, flags); }
INTERPOSE(glFenceSync)
void glFinish(void) WEAKGL;
static void (*p_glFinish)(void);
static void w_glFinish(void) { if (p_glFinish) p_glFinish(); }
INTERPOSE(glFinish)
void glFlush(void) WEAKGL;
static void (*p_glFlush)(void);
static void w_glFlush(void) { if (p_glFlush) p_glFlush(); }
INTERPOSE(glFlush)
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) WEAKGL;
static void (*p_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length);
static void w_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) { if (p_glFlushMappedBufferRange) p_glFlushMappedBufferRange(target, offset, length); }
INTERPOSE(glFlushMappedBufferRange)
void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) WEAKGL;
static void (*p_glFlushMappedNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length);
static void w_glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) { if (p_glFlushMappedNamedBufferRange) p_glFlushMappedNamedBufferRange(buffer, offset, length); }
INTERPOSE(glFlushMappedNamedBufferRange)
void glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glFogCoordPointer)(GLenum type, GLsizei stride, const void *pointer);
static void w_glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer) { if (p_glFogCoordPointer) p_glFogCoordPointer(type, stride, pointer); }
INTERPOSE(glFogCoordPointer)
void glFogCoordd(GLdouble coord) WEAKGL;
static void (*p_glFogCoordd)(GLdouble coord);
static void w_glFogCoordd(GLdouble coord) { if (p_glFogCoordd) p_glFogCoordd(coord); }
INTERPOSE(glFogCoordd)
void glFogCoorddv(const GLdouble *coord) WEAKGL;
static void (*p_glFogCoorddv)(const GLdouble *coord);
static void w_glFogCoorddv(const GLdouble *coord) { if (p_glFogCoorddv) p_glFogCoorddv(coord); }
INTERPOSE(glFogCoorddv)
void glFogCoordf(GLfloat coord) WEAKGL;
static void (*p_glFogCoordf)(GLfloat coord);
static void w_glFogCoordf(GLfloat coord) { if (p_glFogCoordf) p_glFogCoordf(coord); }
INTERPOSE(glFogCoordf)
void glFogCoordfv(const GLfloat *coord) WEAKGL;
static void (*p_glFogCoordfv)(const GLfloat *coord);
static void w_glFogCoordfv(const GLfloat *coord) { if (p_glFogCoordfv) p_glFogCoordfv(coord); }
INTERPOSE(glFogCoordfv)
void glFogf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glFogf)(GLenum pname, GLfloat param);
static void w_glFogf(GLenum pname, GLfloat param) { if (p_glFogf) p_glFogf(pname, param); }
INTERPOSE(glFogf)
void glFogfv(GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glFogfv)(GLenum pname, const GLfloat *params);
static void w_glFogfv(GLenum pname, const GLfloat *params) { if (p_glFogfv) p_glFogfv(pname, params); }
INTERPOSE(glFogfv)
void glFogi(GLenum pname, GLint param) WEAKGL;
static void (*p_glFogi)(GLenum pname, GLint param);
static void w_glFogi(GLenum pname, GLint param) { if (p_glFogi) p_glFogi(pname, param); }
INTERPOSE(glFogi)
void glFogiv(GLenum pname, const GLint *params) WEAKGL;
static void (*p_glFogiv)(GLenum pname, const GLint *params);
static void w_glFogiv(GLenum pname, const GLint *params) { if (p_glFogiv) p_glFogiv(pname, params); }
INTERPOSE(glFogiv)
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) WEAKGL;
static void (*p_glFramebufferParameteri)(GLenum target, GLenum pname, GLint param);
static void w_glFramebufferParameteri(GLenum target, GLenum pname, GLint param) { if (p_glFramebufferParameteri) p_glFramebufferParameteri(target, pname, param); }
INTERPOSE(glFramebufferParameteri)
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) WEAKGL;
static void (*p_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void w_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { if (p_glFramebufferRenderbuffer) p_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
INTERPOSE(glFramebufferRenderbuffer)
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) WEAKGL;
static void (*p_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
static void w_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) { if (p_glFramebufferTexture) p_glFramebufferTexture(target, attachment, texture, level); }
INTERPOSE(glFramebufferTexture)
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) WEAKGL;
static void (*p_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void w_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { if (p_glFramebufferTexture1D) p_glFramebufferTexture1D(target, attachment, textarget, texture, level); }
INTERPOSE(glFramebufferTexture1D)
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) WEAKGL;
static void (*p_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
static void w_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { if (p_glFramebufferTexture2D) p_glFramebufferTexture2D(target, attachment, textarget, texture, level); }
INTERPOSE(glFramebufferTexture2D)
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) WEAKGL;
static void (*p_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
static void w_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) { if (p_glFramebufferTexture3D) p_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset); }
INTERPOSE(glFramebufferTexture3D)
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) WEAKGL;
static void (*p_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void w_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) { if (p_glFramebufferTextureLayer) p_glFramebufferTextureLayer(target, attachment, texture, level, layer); }
INTERPOSE(glFramebufferTextureLayer)
void glFrontFace(GLenum mode) WEAKGL;
static void (*p_glFrontFace)(GLenum mode);
static void w_glFrontFace(GLenum mode) { if (p_glFrontFace) p_glFrontFace(mode); }
INTERPOSE(glFrontFace)
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) WEAKGL;
static void (*p_glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void w_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) { if (p_glFrustum) p_glFrustum(left, right, bottom, top, zNear, zFar); }
INTERPOSE(glFrustum)
void glGenBuffers(GLsizei n, GLuint *buffers) WEAKGL;
static void (*p_glGenBuffers)(GLsizei n, GLuint *buffers);
static void w_glGenBuffers(GLsizei n, GLuint *buffers) { if (p_glGenBuffers) p_glGenBuffers(n, buffers); }
INTERPOSE(glGenBuffers)
void glGenFramebuffers(GLsizei n, GLuint *framebuffers) WEAKGL;
static void (*p_glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
static void w_glGenFramebuffers(GLsizei n, GLuint *framebuffers) { if (p_glGenFramebuffers) p_glGenFramebuffers(n, framebuffers); }
INTERPOSE(glGenFramebuffers)
GLuint glGenLists(GLsizei range) WEAKGL;
static GLuint (*p_glGenLists)(GLsizei range);
static GLuint w_glGenLists(GLsizei range) { if (!p_glGenLists) return (GLuint)0; return p_glGenLists(range); }
INTERPOSE(glGenLists)
void glGenProgramPipelines(GLsizei n, GLuint *pipelines) WEAKGL;
static void (*p_glGenProgramPipelines)(GLsizei n, GLuint *pipelines);
static void w_glGenProgramPipelines(GLsizei n, GLuint *pipelines) { if (p_glGenProgramPipelines) p_glGenProgramPipelines(n, pipelines); }
INTERPOSE(glGenProgramPipelines)
void glGenQueries(GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glGenQueries)(GLsizei n, GLuint *ids);
static void w_glGenQueries(GLsizei n, GLuint *ids) { if (p_glGenQueries) p_glGenQueries(n, ids); }
INTERPOSE(glGenQueries)
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) WEAKGL;
static void (*p_glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
static void w_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) { if (p_glGenRenderbuffers) p_glGenRenderbuffers(n, renderbuffers); }
INTERPOSE(glGenRenderbuffers)
void glGenSamplers(GLsizei count, GLuint *samplers) WEAKGL;
static void (*p_glGenSamplers)(GLsizei count, GLuint *samplers);
static void w_glGenSamplers(GLsizei count, GLuint *samplers) { if (p_glGenSamplers) p_glGenSamplers(count, samplers); }
INTERPOSE(glGenSamplers)
void glGenTextures(GLsizei n, GLuint *textures) WEAKGL;
static void (*p_glGenTextures)(GLsizei n, GLuint *textures);
static void w_glGenTextures(GLsizei n, GLuint *textures) { if (p_glGenTextures) p_glGenTextures(n, textures); }
INTERPOSE(glGenTextures)
void glGenTransformFeedbacks(GLsizei n, GLuint *ids) WEAKGL;
static void (*p_glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
static void w_glGenTransformFeedbacks(GLsizei n, GLuint *ids) { if (p_glGenTransformFeedbacks) p_glGenTransformFeedbacks(n, ids); }
INTERPOSE(glGenTransformFeedbacks)
void glGenVertexArrays(GLsizei n, GLuint *arrays) WEAKGL;
static void (*p_glGenVertexArrays)(GLsizei n, GLuint *arrays);
static void w_glGenVertexArrays(GLsizei n, GLuint *arrays) { if (p_glGenVertexArrays) p_glGenVertexArrays(n, arrays); }
INTERPOSE(glGenVertexArrays)
void glGenerateMipmap(GLenum target) WEAKGL;
static void (*p_glGenerateMipmap)(GLenum target);
static void w_glGenerateMipmap(GLenum target) { if (p_glGenerateMipmap) p_glGenerateMipmap(target); }
INTERPOSE(glGenerateMipmap)
void glGenerateTextureMipmap(GLuint texture) WEAKGL;
static void (*p_glGenerateTextureMipmap)(GLuint texture);
static void w_glGenerateTextureMipmap(GLuint texture) { if (p_glGenerateTextureMipmap) p_glGenerateTextureMipmap(texture); }
INTERPOSE(glGenerateTextureMipmap)
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetActiveAtomicCounterBufferiv)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
static void w_glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) { if (p_glGetActiveAtomicCounterBufferiv) p_glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params); }
INTERPOSE(glGetActiveAtomicCounterBufferiv)
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) WEAKGL;
static void (*p_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
static void w_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { if (p_glGetActiveAttrib) p_glGetActiveAttrib(program, index, bufSize, length, size, type, name); }
INTERPOSE(glGetActiveAttrib)
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) WEAKGL;
static void (*p_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void w_glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { if (p_glGetActiveSubroutineName) p_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name); }
INTERPOSE(glGetActiveSubroutineName)
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) WEAKGL;
static void (*p_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void w_glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { if (p_glGetActiveSubroutineUniformName) p_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name); }
INTERPOSE(glGetActiveSubroutineUniformName)
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) WEAKGL;
static void (*p_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
static void w_glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) { if (p_glGetActiveSubroutineUniformiv) p_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values); }
INTERPOSE(glGetActiveSubroutineUniformiv)
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) WEAKGL;
static void (*p_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
static void w_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { if (p_glGetActiveUniform) p_glGetActiveUniform(program, index, bufSize, length, size, type, name); }
INTERPOSE(glGetActiveUniform)
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) WEAKGL;
static void (*p_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
static void w_glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) { if (p_glGetActiveUniformBlockName) p_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName); }
INTERPOSE(glGetActiveUniformBlockName)
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
static void w_glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) { if (p_glGetActiveUniformBlockiv) p_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params); }
INTERPOSE(glGetActiveUniformBlockiv)
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) WEAKGL;
static void (*p_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
static void w_glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) { if (p_glGetActiveUniformName) p_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName); }
INTERPOSE(glGetActiveUniformName)
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
static void w_glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) { if (p_glGetActiveUniformsiv) p_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params); }
INTERPOSE(glGetActiveUniformsiv)
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) WEAKGL;
static void (*p_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
static void w_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) { if (p_glGetAttachedShaders) p_glGetAttachedShaders(program, maxCount, count, shaders); }
INTERPOSE(glGetAttachedShaders)
GLint glGetAttribLocation(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetAttribLocation)(GLuint program, const GLchar *name);
static GLint w_glGetAttribLocation(GLuint program, const GLchar *name) { if (!p_glGetAttribLocation) return (GLint)0; return p_glGetAttribLocation(program, name); }
INTERPOSE(glGetAttribLocation)
void glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) WEAKGL;
static void (*p_glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
static void w_glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) { if (p_glGetBooleani_v) p_glGetBooleani_v(target, index, data); }
INTERPOSE(glGetBooleani_v)
void glGetBooleanv(GLenum pname, GLboolean *data) WEAKGL;
static void (*p_glGetBooleanv)(GLenum pname, GLboolean *data);
static void w_glGetBooleanv(GLenum pname, GLboolean *data) { if (p_glGetBooleanv) p_glGetBooleanv(pname, data); }
INTERPOSE(glGetBooleanv)
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) WEAKGL;
static void (*p_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
static void w_glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) { if (p_glGetBufferParameteri64v) p_glGetBufferParameteri64v(target, pname, params); }
INTERPOSE(glGetBufferParameteri64v)
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params) { if (p_glGetBufferParameteriv) p_glGetBufferParameteriv(target, pname, params); }
INTERPOSE(glGetBufferParameteriv)
void glGetBufferPointerv(GLenum target, GLenum pname, void **params) WEAKGL;
static void (*p_glGetBufferPointerv)(GLenum target, GLenum pname, void **params);
static void w_glGetBufferPointerv(GLenum target, GLenum pname, void **params) { if (p_glGetBufferPointerv) p_glGetBufferPointerv(target, pname, params); }
INTERPOSE(glGetBufferPointerv)
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data) WEAKGL;
static void (*p_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
static void w_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void *data) { if (p_glGetBufferSubData) p_glGetBufferSubData(target, offset, size, data); }
INTERPOSE(glGetBufferSubData)
void glGetClipPlane(GLenum plane, GLdouble *equation) WEAKGL;
static void (*p_glGetClipPlane)(GLenum plane, GLdouble *equation);
static void w_glGetClipPlane(GLenum plane, GLdouble *equation) { if (p_glGetClipPlane) p_glGetClipPlane(plane, equation); }
INTERPOSE(glGetClipPlane)
void glGetCompressedTexImage(GLenum target, GLint level, void *img) WEAKGL;
static void (*p_glGetCompressedTexImage)(GLenum target, GLint level, void *img);
static void w_glGetCompressedTexImage(GLenum target, GLint level, void *img) { if (p_glGetCompressedTexImage) p_glGetCompressedTexImage(target, level, img); }
INTERPOSE(glGetCompressedTexImage)
void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetCompressedTextureImage)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
static void w_glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void *pixels) { if (p_glGetCompressedTextureImage) p_glGetCompressedTextureImage(texture, level, bufSize, pixels); }
INTERPOSE(glGetCompressedTextureImage)
void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetCompressedTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
static void w_glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) { if (p_glGetCompressedTextureSubImage) p_glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels); }
INTERPOSE(glGetCompressedTextureSubImage)
GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) WEAKGL;
static GLuint (*p_glGetDebugMessageLog)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
static GLuint w_glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) { if (!p_glGetDebugMessageLog) return (GLuint)0; return p_glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog); }
INTERPOSE(glGetDebugMessageLog)
void glGetDoublei_v(GLenum target, GLuint index, GLdouble *data) WEAKGL;
static void (*p_glGetDoublei_v)(GLenum target, GLuint index, GLdouble *data);
static void w_glGetDoublei_v(GLenum target, GLuint index, GLdouble *data) { if (p_glGetDoublei_v) p_glGetDoublei_v(target, index, data); }
INTERPOSE(glGetDoublei_v)
void glGetDoublev(GLenum pname, GLdouble *data) WEAKGL;
static void (*p_glGetDoublev)(GLenum pname, GLdouble *data);
static void w_glGetDoublev(GLenum pname, GLdouble *data) { if (p_glGetDoublev) p_glGetDoublev(pname, data); }
INTERPOSE(glGetDoublev)
GLenum glGetError(void) WEAKGL;
static GLenum (*p_glGetError)(void);
static GLenum w_glGetError(void) { if (!p_glGetError) return (GLenum)0; return p_glGetError(); }
INTERPOSE(glGetError)
void glGetFloati_v(GLenum target, GLuint index, GLfloat *data) WEAKGL;
static void (*p_glGetFloati_v)(GLenum target, GLuint index, GLfloat *data);
static void w_glGetFloati_v(GLenum target, GLuint index, GLfloat *data) { if (p_glGetFloati_v) p_glGetFloati_v(target, index, data); }
INTERPOSE(glGetFloati_v)
void glGetFloatv(GLenum pname, GLfloat *data) WEAKGL;
static void (*p_glGetFloatv)(GLenum pname, GLfloat *data);
static void w_glGetFloatv(GLenum pname, GLfloat *data) { if (p_glGetFloatv) p_glGetFloatv(pname, data); }
INTERPOSE(glGetFloatv)
GLint glGetFragDataIndex(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetFragDataIndex)(GLuint program, const GLchar *name);
static GLint w_glGetFragDataIndex(GLuint program, const GLchar *name) { if (!p_glGetFragDataIndex) return (GLint)0; return p_glGetFragDataIndex(program, name); }
INTERPOSE(glGetFragDataIndex)
GLint glGetFragDataLocation(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetFragDataLocation)(GLuint program, const GLchar *name);
static GLint w_glGetFragDataLocation(GLuint program, const GLchar *name) { if (!p_glGetFragDataLocation) return (GLint)0; return p_glGetFragDataLocation(program, name); }
INTERPOSE(glGetFragDataLocation)
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
static void w_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { if (p_glGetFramebufferAttachmentParameteriv) p_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
INTERPOSE(glGetFramebufferAttachmentParameteriv)
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetFramebufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint *params) { if (p_glGetFramebufferParameteriv) p_glGetFramebufferParameteriv(target, pname, params); }
INTERPOSE(glGetFramebufferParameteriv)
GLenum glGetGraphicsResetStatus(void) WEAKGL;
static GLenum (*p_glGetGraphicsResetStatus)(void);
static GLenum w_glGetGraphicsResetStatus(void) { if (!p_glGetGraphicsResetStatus) return (GLenum)0; return p_glGetGraphicsResetStatus(); }
INTERPOSE(glGetGraphicsResetStatus)
void glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) WEAKGL;
static void (*p_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
static void w_glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) { if (p_glGetInteger64i_v) p_glGetInteger64i_v(target, index, data); }
INTERPOSE(glGetInteger64i_v)
void glGetInteger64v(GLenum pname, GLint64 *data) WEAKGL;
static void (*p_glGetInteger64v)(GLenum pname, GLint64 *data);
static void w_glGetInteger64v(GLenum pname, GLint64 *data) { if (p_glGetInteger64v) p_glGetInteger64v(pname, data); }
INTERPOSE(glGetInteger64v)
void glGetIntegeri_v(GLenum target, GLuint index, GLint *data) WEAKGL;
static void (*p_glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
static void w_glGetIntegeri_v(GLenum target, GLuint index, GLint *data) { if (p_glGetIntegeri_v) p_glGetIntegeri_v(target, index, data); }
INTERPOSE(glGetIntegeri_v)
void glGetIntegerv(GLenum pname, GLint *data) WEAKGL;
static void (*p_glGetIntegerv)(GLenum pname, GLint *data);
static void w_glGetIntegerv(GLenum pname, GLint *data) { if (p_glGetIntegerv) p_glGetIntegerv(pname, data); }
INTERPOSE(glGetIntegerv)
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params) WEAKGL;
static void (*p_glGetInternalformati64v)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
static void w_glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params) { if (p_glGetInternalformati64v) p_glGetInternalformati64v(target, internalformat, pname, count, params); }
INTERPOSE(glGetInternalformati64v)
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params) WEAKGL;
static void (*p_glGetInternalformativ)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
static void w_glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params) { if (p_glGetInternalformativ) p_glGetInternalformativ(target, internalformat, pname, count, params); }
INTERPOSE(glGetInternalformativ)
void glGetLightfv(GLenum light, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetLightfv)(GLenum light, GLenum pname, GLfloat *params);
static void w_glGetLightfv(GLenum light, GLenum pname, GLfloat *params) { if (p_glGetLightfv) p_glGetLightfv(light, pname, params); }
INTERPOSE(glGetLightfv)
void glGetLightiv(GLenum light, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetLightiv)(GLenum light, GLenum pname, GLint *params);
static void w_glGetLightiv(GLenum light, GLenum pname, GLint *params) { if (p_glGetLightiv) p_glGetLightiv(light, pname, params); }
INTERPOSE(glGetLightiv)
void glGetMapdv(GLenum target, GLenum query, GLdouble *v) WEAKGL;
static void (*p_glGetMapdv)(GLenum target, GLenum query, GLdouble *v);
static void w_glGetMapdv(GLenum target, GLenum query, GLdouble *v) { if (p_glGetMapdv) p_glGetMapdv(target, query, v); }
INTERPOSE(glGetMapdv)
void glGetMapfv(GLenum target, GLenum query, GLfloat *v) WEAKGL;
static void (*p_glGetMapfv)(GLenum target, GLenum query, GLfloat *v);
static void w_glGetMapfv(GLenum target, GLenum query, GLfloat *v) { if (p_glGetMapfv) p_glGetMapfv(target, query, v); }
INTERPOSE(glGetMapfv)
void glGetMapiv(GLenum target, GLenum query, GLint *v) WEAKGL;
static void (*p_glGetMapiv)(GLenum target, GLenum query, GLint *v);
static void w_glGetMapiv(GLenum target, GLenum query, GLint *v) { if (p_glGetMapiv) p_glGetMapiv(target, query, v); }
INTERPOSE(glGetMapiv)
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetMaterialfv)(GLenum face, GLenum pname, GLfloat *params);
static void w_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params) { if (p_glGetMaterialfv) p_glGetMaterialfv(face, pname, params); }
INTERPOSE(glGetMaterialfv)
void glGetMaterialiv(GLenum face, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetMaterialiv)(GLenum face, GLenum pname, GLint *params);
static void w_glGetMaterialiv(GLenum face, GLenum pname, GLint *params) { if (p_glGetMaterialiv) p_glGetMaterialiv(face, pname, params); }
INTERPOSE(glGetMaterialiv)
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) WEAKGL;
static void (*p_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat *val);
static void w_glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) { if (p_glGetMultisamplefv) p_glGetMultisamplefv(pname, index, val); }
INTERPOSE(glGetMultisamplefv)
void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params) WEAKGL;
static void (*p_glGetNamedBufferParameteri64v)(GLuint buffer, GLenum pname, GLint64 *params);
static void w_glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 *params) { if (p_glGetNamedBufferParameteri64v) p_glGetNamedBufferParameteri64v(buffer, pname, params); }
INTERPOSE(glGetNamedBufferParameteri64v)
void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetNamedBufferParameteriv)(GLuint buffer, GLenum pname, GLint *params);
static void w_glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint *params) { if (p_glGetNamedBufferParameteriv) p_glGetNamedBufferParameteriv(buffer, pname, params); }
INTERPOSE(glGetNamedBufferParameteriv)
void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void **params) WEAKGL;
static void (*p_glGetNamedBufferPointerv)(GLuint buffer, GLenum pname, void **params);
static void w_glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void **params) { if (p_glGetNamedBufferPointerv) p_glGetNamedBufferPointerv(buffer, pname, params); }
INTERPOSE(glGetNamedBufferPointerv)
void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) WEAKGL;
static void (*p_glGetNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
static void w_glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) { if (p_glGetNamedBufferSubData) p_glGetNamedBufferSubData(buffer, offset, size, data); }
INTERPOSE(glGetNamedBufferSubData)
void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetNamedFramebufferAttachmentParameteriv)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
static void w_glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) { if (p_glGetNamedFramebufferAttachmentParameteriv) p_glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params); }
INTERPOSE(glGetNamedFramebufferAttachmentParameteriv)
void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetNamedFramebufferParameteriv)(GLuint framebuffer, GLenum pname, GLint *param);
static void w_glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint *param) { if (p_glGetNamedFramebufferParameteriv) p_glGetNamedFramebufferParameteriv(framebuffer, pname, param); }
INTERPOSE(glGetNamedFramebufferParameteriv)
void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetNamedRenderbufferParameteriv)(GLuint renderbuffer, GLenum pname, GLint *params);
static void w_glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint *params) { if (p_glGetNamedRenderbufferParameteriv) p_glGetNamedRenderbufferParameteriv(renderbuffer, pname, params); }
INTERPOSE(glGetNamedRenderbufferParameteriv)
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) WEAKGL;
static void (*p_glGetObjectLabel)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
static void w_glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) { if (p_glGetObjectLabel) p_glGetObjectLabel(identifier, name, bufSize, length, label); }
INTERPOSE(glGetObjectLabel)
void glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) WEAKGL;
static void (*p_glGetObjectPtrLabel)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
static void w_glGetObjectPtrLabel(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) { if (p_glGetObjectPtrLabel) p_glGetObjectPtrLabel(ptr, bufSize, length, label); }
INTERPOSE(glGetObjectPtrLabel)
void glGetPixelMapfv(GLenum map, GLfloat *values) WEAKGL;
static void (*p_glGetPixelMapfv)(GLenum map, GLfloat *values);
static void w_glGetPixelMapfv(GLenum map, GLfloat *values) { if (p_glGetPixelMapfv) p_glGetPixelMapfv(map, values); }
INTERPOSE(glGetPixelMapfv)
void glGetPixelMapuiv(GLenum map, GLuint *values) WEAKGL;
static void (*p_glGetPixelMapuiv)(GLenum map, GLuint *values);
static void w_glGetPixelMapuiv(GLenum map, GLuint *values) { if (p_glGetPixelMapuiv) p_glGetPixelMapuiv(map, values); }
INTERPOSE(glGetPixelMapuiv)
void glGetPixelMapusv(GLenum map, GLushort *values) WEAKGL;
static void (*p_glGetPixelMapusv)(GLenum map, GLushort *values);
static void w_glGetPixelMapusv(GLenum map, GLushort *values) { if (p_glGetPixelMapusv) p_glGetPixelMapusv(map, values); }
INTERPOSE(glGetPixelMapusv)
void glGetPointerv(GLenum pname, void **params) WEAKGL;
static void (*p_glGetPointerv)(GLenum pname, void **params);
static void w_glGetPointerv(GLenum pname, void **params) { if (p_glGetPointerv) p_glGetPointerv(pname, params); }
INTERPOSE(glGetPointerv)
void glGetPolygonStipple(GLubyte *mask) WEAKGL;
static void (*p_glGetPolygonStipple)(GLubyte *mask);
static void w_glGetPolygonStipple(GLubyte *mask) { if (p_glGetPolygonStipple) p_glGetPolygonStipple(mask); }
INTERPOSE(glGetPolygonStipple)
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) WEAKGL;
static void (*p_glGetProgramBinary)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
static void w_glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) { if (p_glGetProgramBinary) p_glGetProgramBinary(program, bufSize, length, binaryFormat, binary); }
INTERPOSE(glGetProgramBinary)
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) WEAKGL;
static void (*p_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void w_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { if (p_glGetProgramInfoLog) p_glGetProgramInfoLog(program, bufSize, length, infoLog); }
INTERPOSE(glGetProgramInfoLog)
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetProgramInterfaceiv)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
static void w_glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint *params) { if (p_glGetProgramInterfaceiv) p_glGetProgramInterfaceiv(program, programInterface, pname, params); }
INTERPOSE(glGetProgramInterfaceiv)
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) WEAKGL;
static void (*p_glGetProgramPipelineInfoLog)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void w_glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { if (p_glGetProgramPipelineInfoLog) p_glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog); }
INTERPOSE(glGetProgramPipelineInfoLog)
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetProgramPipelineiv)(GLuint pipeline, GLenum pname, GLint *params);
static void w_glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) { if (p_glGetProgramPipelineiv) p_glGetProgramPipelineiv(pipeline, pname, params); }
INTERPOSE(glGetProgramPipelineiv)
GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) WEAKGL;
static GLuint (*p_glGetProgramResourceIndex)(GLuint program, GLenum programInterface, const GLchar *name);
static GLuint w_glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar *name) { if (!p_glGetProgramResourceIndex) return (GLuint)0; return p_glGetProgramResourceIndex(program, programInterface, name); }
INTERPOSE(glGetProgramResourceIndex)
GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) WEAKGL;
static GLint (*p_glGetProgramResourceLocation)(GLuint program, GLenum programInterface, const GLchar *name);
static GLint w_glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar *name) { if (!p_glGetProgramResourceLocation) return (GLint)0; return p_glGetProgramResourceLocation(program, programInterface, name); }
INTERPOSE(glGetProgramResourceLocation)
GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name) WEAKGL;
static GLint (*p_glGetProgramResourceLocationIndex)(GLuint program, GLenum programInterface, const GLchar *name);
static GLint w_glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar *name) { if (!p_glGetProgramResourceLocationIndex) return (GLint)0; return p_glGetProgramResourceLocationIndex(program, programInterface, name); }
INTERPOSE(glGetProgramResourceLocationIndex)
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) WEAKGL;
static void (*p_glGetProgramResourceName)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
static void w_glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) { if (p_glGetProgramResourceName) p_glGetProgramResourceName(program, programInterface, index, bufSize, length, name); }
INTERPOSE(glGetProgramResourceName)
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params) WEAKGL;
static void (*p_glGetProgramResourceiv)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
static void w_glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params) { if (p_glGetProgramResourceiv) p_glGetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params); }
INTERPOSE(glGetProgramResourceiv)
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) WEAKGL;
static void (*p_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
static void w_glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values) { if (p_glGetProgramStageiv) p_glGetProgramStageiv(program, shadertype, pname, values); }
INTERPOSE(glGetProgramStageiv)
void glGetProgramiv(GLuint program, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
static void w_glGetProgramiv(GLuint program, GLenum pname, GLint *params) { if (p_glGetProgramiv) p_glGetProgramiv(program, pname, params); }
INTERPOSE(glGetProgramiv)
void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjecti64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (p_glGetQueryBufferObjecti64v) p_glGetQueryBufferObjecti64v(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjecti64v)
void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjectiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (p_glGetQueryBufferObjectiv) p_glGetQueryBufferObjectiv(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjectiv)
void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjectui64v)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (p_glGetQueryBufferObjectui64v) p_glGetQueryBufferObjectui64v(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjectui64v)
void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) WEAKGL;
static void (*p_glGetQueryBufferObjectuiv)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
static void w_glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) { if (p_glGetQueryBufferObjectuiv) p_glGetQueryBufferObjectuiv(id, buffer, pname, offset); }
INTERPOSE(glGetQueryBufferObjectuiv)
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint *params);
static void w_glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params) { if (p_glGetQueryIndexediv) p_glGetQueryIndexediv(target, index, pname, params); }
INTERPOSE(glGetQueryIndexediv)
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) WEAKGL;
static void (*p_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 *params);
static void w_glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) { if (p_glGetQueryObjecti64v) p_glGetQueryObjecti64v(id, pname, params); }
INTERPOSE(glGetQueryObjecti64v)
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
static void w_glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) { if (p_glGetQueryObjectiv) p_glGetQueryObjectiv(id, pname, params); }
INTERPOSE(glGetQueryObjectiv)
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) WEAKGL;
static void (*p_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 *params);
static void w_glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) { if (p_glGetQueryObjectui64v) p_glGetQueryObjectui64v(id, pname, params); }
INTERPOSE(glGetQueryObjectui64v)
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
static void w_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) { if (p_glGetQueryObjectuiv) p_glGetQueryObjectuiv(id, pname, params); }
INTERPOSE(glGetQueryObjectuiv)
void glGetQueryiv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetQueryiv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetQueryiv(GLenum target, GLenum pname, GLint *params) { if (p_glGetQueryiv) p_glGetQueryiv(target, pname, params); }
INTERPOSE(glGetQueryiv)
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { if (p_glGetRenderbufferParameteriv) p_glGetRenderbufferParameteriv(target, pname, params); }
INTERPOSE(glGetRenderbufferParameteriv)
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint *params);
static void w_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params) { if (p_glGetSamplerParameterIiv) p_glGetSamplerParameterIiv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameterIiv)
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint *params);
static void w_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params) { if (p_glGetSamplerParameterIuiv) p_glGetSamplerParameterIuiv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameterIuiv)
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat *params);
static void w_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params) { if (p_glGetSamplerParameterfv) p_glGetSamplerParameterfv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameterfv)
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint *params);
static void w_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params) { if (p_glGetSamplerParameteriv) p_glGetSamplerParameteriv(sampler, pname, params); }
INTERPOSE(glGetSamplerParameteriv)
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) WEAKGL;
static void (*p_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
static void w_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { if (p_glGetShaderInfoLog) p_glGetShaderInfoLog(shader, bufSize, length, infoLog); }
INTERPOSE(glGetShaderInfoLog)
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) WEAKGL;
static void (*p_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
static void w_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { if (p_glGetShaderPrecisionFormat) p_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
INTERPOSE(glGetShaderPrecisionFormat)
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) WEAKGL;
static void (*p_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
static void w_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { if (p_glGetShaderSource) p_glGetShaderSource(shader, bufSize, length, source); }
INTERPOSE(glGetShaderSource)
void glGetShaderiv(GLuint shader, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
static void w_glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { if (p_glGetShaderiv) p_glGetShaderiv(shader, pname, params); }
INTERPOSE(glGetShaderiv)
GLubyte const  * glGetString(GLenum name) WEAKGL;
static GLubyte const  * (*p_glGetString)(GLenum name);
static GLubyte const  * w_glGetString(GLenum name) { if (!p_glGetString) return (GLubyte const  *)0; return p_glGetString(name); }
INTERPOSE(glGetString)
GLubyte const  * glGetStringi(GLenum name, GLuint index) WEAKGL;
static GLubyte const  * (*p_glGetStringi)(GLenum name, GLuint index);
static GLubyte const  * w_glGetStringi(GLenum name, GLuint index) { if (!p_glGetStringi) return (GLubyte const  *)0; return p_glGetStringi(name, index); }
INTERPOSE(glGetStringi)
GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) WEAKGL;
static GLuint (*p_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar *name);
static GLuint w_glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name) { if (!p_glGetSubroutineIndex) return (GLuint)0; return p_glGetSubroutineIndex(program, shadertype, name); }
INTERPOSE(glGetSubroutineIndex)
GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name) WEAKGL;
static GLint (*p_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar *name);
static GLint w_glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name) { if (!p_glGetSubroutineUniformLocation) return (GLint)0; return p_glGetSubroutineUniformLocation(program, shadertype, name); }
INTERPOSE(glGetSubroutineUniformLocation)
void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) WEAKGL;
static void (*p_glGetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
static void w_glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) { if (p_glGetSynciv) p_glGetSynciv(sync, pname, count, length, values); }
INTERPOSE(glGetSynciv)
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params);
static void w_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) { if (p_glGetTexEnvfv) p_glGetTexEnvfv(target, pname, params); }
INTERPOSE(glGetTexEnvfv)
void glGetTexEnviv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexEnviv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetTexEnviv(GLenum target, GLenum pname, GLint *params) { if (p_glGetTexEnviv) p_glGetTexEnviv(target, pname, params); }
INTERPOSE(glGetTexEnviv)
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) WEAKGL;
static void (*p_glGetTexGendv)(GLenum coord, GLenum pname, GLdouble *params);
static void w_glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) { if (p_glGetTexGendv) p_glGetTexGendv(coord, pname, params); }
INTERPOSE(glGetTexGendv)
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params);
static void w_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) { if (p_glGetTexGenfv) p_glGetTexGenfv(coord, pname, params); }
INTERPOSE(glGetTexGenfv)
void glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexGeniv)(GLenum coord, GLenum pname, GLint *params);
static void w_glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) { if (p_glGetTexGeniv) p_glGetTexGeniv(coord, pname, params); }
INTERPOSE(glGetTexGeniv)
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) WEAKGL;
static void (*p_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
static void w_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void *pixels) { if (p_glGetTexImage) p_glGetTexImage(target, level, format, type, pixels); }
INTERPOSE(glGetTexImage)
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
static void w_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) { if (p_glGetTexLevelParameterfv) p_glGetTexLevelParameterfv(target, level, pname, params); }
INTERPOSE(glGetTexLevelParameterfv)
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
static void w_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) { if (p_glGetTexLevelParameteriv) p_glGetTexLevelParameteriv(target, level, pname, params); }
INTERPOSE(glGetTexLevelParameteriv)
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params) { if (p_glGetTexParameterIiv) p_glGetTexParameterIiv(target, pname, params); }
INTERPOSE(glGetTexParameterIiv)
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
static void w_glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) { if (p_glGetTexParameterIuiv) p_glGetTexParameterIuiv(target, pname, params); }
INTERPOSE(glGetTexParameterIuiv)
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
static void w_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { if (p_glGetTexParameterfv) p_glGetTexParameterfv(target, pname, params); }
INTERPOSE(glGetTexParameterfv)
void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
static void w_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) { if (p_glGetTexParameteriv) p_glGetTexParameteriv(target, pname, params); }
INTERPOSE(glGetTexParameteriv)
void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetTextureImage)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void w_glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { if (p_glGetTextureImage) p_glGetTextureImage(texture, level, format, type, bufSize, pixels); }
INTERPOSE(glGetTextureImage)
void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTextureLevelParameterfv)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
static void w_glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat *params) { if (p_glGetTextureLevelParameterfv) p_glGetTextureLevelParameterfv(texture, level, pname, params); }
INTERPOSE(glGetTextureLevelParameterfv)
void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTextureLevelParameteriv)(GLuint texture, GLint level, GLenum pname, GLint *params);
static void w_glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint *params) { if (p_glGetTextureLevelParameteriv) p_glGetTextureLevelParameteriv(texture, level, pname, params); }
INTERPOSE(glGetTextureLevelParameteriv)
void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTextureParameterIiv)(GLuint texture, GLenum pname, GLint *params);
static void w_glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint *params) { if (p_glGetTextureParameterIiv) p_glGetTextureParameterIiv(texture, pname, params); }
INTERPOSE(glGetTextureParameterIiv)
void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetTextureParameterIuiv)(GLuint texture, GLenum pname, GLuint *params);
static void w_glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint *params) { if (p_glGetTextureParameterIuiv) p_glGetTextureParameterIuiv(texture, pname, params); }
INTERPOSE(glGetTextureParameterIuiv)
void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetTextureParameterfv)(GLuint texture, GLenum pname, GLfloat *params);
static void w_glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat *params) { if (p_glGetTextureParameterfv) p_glGetTextureParameterfv(texture, pname, params); }
INTERPOSE(glGetTextureParameterfv)
void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetTextureParameteriv)(GLuint texture, GLenum pname, GLint *params);
static void w_glGetTextureParameteriv(GLuint texture, GLenum pname, GLint *params) { if (p_glGetTextureParameteriv) p_glGetTextureParameteriv(texture, pname, params); }
INTERPOSE(glGetTextureParameteriv)
void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetTextureSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void w_glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { if (p_glGetTextureSubImage) p_glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels); }
INTERPOSE(glGetTextureSubImage)
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) WEAKGL;
static void (*p_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
static void w_glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) { if (p_glGetTransformFeedbackVarying) p_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
INTERPOSE(glGetTransformFeedbackVarying)
void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) WEAKGL;
static void (*p_glGetTransformFeedbacki64_v)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
static void w_glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 *param) { if (p_glGetTransformFeedbacki64_v) p_glGetTransformFeedbacki64_v(xfb, pname, index, param); }
INTERPOSE(glGetTransformFeedbacki64_v)
void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param) WEAKGL;
static void (*p_glGetTransformFeedbacki_v)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
static void w_glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint *param) { if (p_glGetTransformFeedbacki_v) p_glGetTransformFeedbacki_v(xfb, pname, index, param); }
INTERPOSE(glGetTransformFeedbacki_v)
void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetTransformFeedbackiv)(GLuint xfb, GLenum pname, GLint *param);
static void w_glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint *param) { if (p_glGetTransformFeedbackiv) p_glGetTransformFeedbackiv(xfb, pname, param); }
INTERPOSE(glGetTransformFeedbackiv)
GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) WEAKGL;
static GLuint (*p_glGetUniformBlockIndex)(GLuint program, const GLchar *uniformBlockName);
static GLuint w_glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) { if (!p_glGetUniformBlockIndex) return (GLuint)0; return p_glGetUniformBlockIndex(program, uniformBlockName); }
INTERPOSE(glGetUniformBlockIndex)
void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) WEAKGL;
static void (*p_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
static void w_glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) { if (p_glGetUniformIndices) p_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices); }
INTERPOSE(glGetUniformIndices)
GLint glGetUniformLocation(GLuint program, const GLchar *name) WEAKGL;
static GLint (*p_glGetUniformLocation)(GLuint program, const GLchar *name);
static GLint w_glGetUniformLocation(GLuint program, const GLchar *name) { if (!p_glGetUniformLocation) return (GLint)0; return p_glGetUniformLocation(program, name); }
INTERPOSE(glGetUniformLocation)
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params) WEAKGL;
static void (*p_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint *params);
static void w_glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params) { if (p_glGetUniformSubroutineuiv) p_glGetUniformSubroutineuiv(shadertype, location, params); }
INTERPOSE(glGetUniformSubroutineuiv)
void glGetUniformdv(GLuint program, GLint location, GLdouble *params) WEAKGL;
static void (*p_glGetUniformdv)(GLuint program, GLint location, GLdouble *params);
static void w_glGetUniformdv(GLuint program, GLint location, GLdouble *params) { if (p_glGetUniformdv) p_glGetUniformdv(program, location, params); }
INTERPOSE(glGetUniformdv)
void glGetUniformfv(GLuint program, GLint location, GLfloat *params) WEAKGL;
static void (*p_glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
static void w_glGetUniformfv(GLuint program, GLint location, GLfloat *params) { if (p_glGetUniformfv) p_glGetUniformfv(program, location, params); }
INTERPOSE(glGetUniformfv)
void glGetUniformiv(GLuint program, GLint location, GLint *params) WEAKGL;
static void (*p_glGetUniformiv)(GLuint program, GLint location, GLint *params);
static void w_glGetUniformiv(GLuint program, GLint location, GLint *params) { if (p_glGetUniformiv) p_glGetUniformiv(program, location, params); }
INTERPOSE(glGetUniformiv)
void glGetUniformuiv(GLuint program, GLint location, GLuint *params) WEAKGL;
static void (*p_glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
static void w_glGetUniformuiv(GLuint program, GLint location, GLuint *params) { if (p_glGetUniformuiv) p_glGetUniformuiv(program, location, params); }
INTERPOSE(glGetUniformuiv)
void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) WEAKGL;
static void (*p_glGetVertexArrayIndexed64iv)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
static void w_glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) { if (p_glGetVertexArrayIndexed64iv) p_glGetVertexArrayIndexed64iv(vaobj, index, pname, param); }
INTERPOSE(glGetVertexArrayIndexed64iv)
void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetVertexArrayIndexediv)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
static void w_glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint *param) { if (p_glGetVertexArrayIndexediv) p_glGetVertexArrayIndexediv(vaobj, index, pname, param); }
INTERPOSE(glGetVertexArrayIndexediv)
void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) WEAKGL;
static void (*p_glGetVertexArrayiv)(GLuint vaobj, GLenum pname, GLint *param);
static void w_glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) { if (p_glGetVertexArrayiv) p_glGetVertexArrayiv(vaobj, pname, param); }
INTERPOSE(glGetVertexArrayiv)
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
static void w_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { if (p_glGetVertexAttribIiv) p_glGetVertexAttribIiv(index, pname, params); }
INTERPOSE(glGetVertexAttribIiv)
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) WEAKGL;
static void (*p_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
static void w_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { if (p_glGetVertexAttribIuiv) p_glGetVertexAttribIuiv(index, pname, params); }
INTERPOSE(glGetVertexAttribIuiv)
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) WEAKGL;
static void (*p_glGetVertexAttribLdv)(GLuint index, GLenum pname, GLdouble *params);
static void w_glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params) { if (p_glGetVertexAttribLdv) p_glGetVertexAttribLdv(index, pname, params); }
INTERPOSE(glGetVertexAttribLdv)
void glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) WEAKGL;
static void (*p_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
static void w_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer) { if (p_glGetVertexAttribPointerv) p_glGetVertexAttribPointerv(index, pname, pointer); }
INTERPOSE(glGetVertexAttribPointerv)
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) WEAKGL;
static void (*p_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
static void w_glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { if (p_glGetVertexAttribdv) p_glGetVertexAttribdv(index, pname, params); }
INTERPOSE(glGetVertexAttribdv)
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) WEAKGL;
static void (*p_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
static void w_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { if (p_glGetVertexAttribfv) p_glGetVertexAttribfv(index, pname, params); }
INTERPOSE(glGetVertexAttribfv)
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) WEAKGL;
static void (*p_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
static void w_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { if (p_glGetVertexAttribiv) p_glGetVertexAttribiv(index, pname, params); }
INTERPOSE(glGetVertexAttribiv)
void glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) WEAKGL;
static void (*p_glGetnColorTable)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
static void w_glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) { if (p_glGetnColorTable) p_glGetnColorTable(target, format, type, bufSize, table); }
INTERPOSE(glGetnColorTable)
void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetnCompressedTexImage)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
static void w_glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void *pixels) { if (p_glGetnCompressedTexImage) p_glGetnCompressedTexImage(target, lod, bufSize, pixels); }
INTERPOSE(glGetnCompressedTexImage)
void glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) WEAKGL;
static void (*p_glGetnConvolutionFilter)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
static void w_glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) { if (p_glGetnConvolutionFilter) p_glGetnConvolutionFilter(target, format, type, bufSize, image); }
INTERPOSE(glGetnConvolutionFilter)
void glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) WEAKGL;
static void (*p_glGetnHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
static void w_glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) { if (p_glGetnHistogram) p_glGetnHistogram(target, reset, format, type, bufSize, values); }
INTERPOSE(glGetnHistogram)
void glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) WEAKGL;
static void (*p_glGetnMapdv)(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
static void w_glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) { if (p_glGetnMapdv) p_glGetnMapdv(target, query, bufSize, v); }
INTERPOSE(glGetnMapdv)
void glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) WEAKGL;
static void (*p_glGetnMapfv)(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
static void w_glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) { if (p_glGetnMapfv) p_glGetnMapfv(target, query, bufSize, v); }
INTERPOSE(glGetnMapfv)
void glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint *v) WEAKGL;
static void (*p_glGetnMapiv)(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
static void w_glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint *v) { if (p_glGetnMapiv) p_glGetnMapiv(target, query, bufSize, v); }
INTERPOSE(glGetnMapiv)
void glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) WEAKGL;
static void (*p_glGetnMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
static void w_glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) { if (p_glGetnMinmax) p_glGetnMinmax(target, reset, format, type, bufSize, values); }
INTERPOSE(glGetnMinmax)
void glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat *values) WEAKGL;
static void (*p_glGetnPixelMapfv)(GLenum map, GLsizei bufSize, GLfloat *values);
static void w_glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat *values) { if (p_glGetnPixelMapfv) p_glGetnPixelMapfv(map, bufSize, values); }
INTERPOSE(glGetnPixelMapfv)
void glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint *values) WEAKGL;
static void (*p_glGetnPixelMapuiv)(GLenum map, GLsizei bufSize, GLuint *values);
static void w_glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint *values) { if (p_glGetnPixelMapuiv) p_glGetnPixelMapuiv(map, bufSize, values); }
INTERPOSE(glGetnPixelMapuiv)
void glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort *values) WEAKGL;
static void (*p_glGetnPixelMapusv)(GLenum map, GLsizei bufSize, GLushort *values);
static void w_glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort *values) { if (p_glGetnPixelMapusv) p_glGetnPixelMapusv(map, bufSize, values); }
INTERPOSE(glGetnPixelMapusv)
void glGetnPolygonStipple(GLsizei bufSize, GLubyte *pattern) WEAKGL;
static void (*p_glGetnPolygonStipple)(GLsizei bufSize, GLubyte *pattern);
static void w_glGetnPolygonStipple(GLsizei bufSize, GLubyte *pattern) { if (p_glGetnPolygonStipple) p_glGetnPolygonStipple(bufSize, pattern); }
INTERPOSE(glGetnPolygonStipple)
void glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) WEAKGL;
static void (*p_glGetnSeparableFilter)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
static void w_glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) { if (p_glGetnSeparableFilter) p_glGetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span); }
INTERPOSE(glGetnSeparableFilter)
void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) WEAKGL;
static void (*p_glGetnTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
static void w_glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) { if (p_glGetnTexImage) p_glGetnTexImage(target, level, format, type, bufSize, pixels); }
INTERPOSE(glGetnTexImage)
void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params) WEAKGL;
static void (*p_glGetnUniformdv)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
static void w_glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble *params) { if (p_glGetnUniformdv) p_glGetnUniformdv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformdv)
void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) WEAKGL;
static void (*p_glGetnUniformfv)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
static void w_glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat *params) { if (p_glGetnUniformfv) p_glGetnUniformfv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformfv)
void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) WEAKGL;
static void (*p_glGetnUniformiv)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
static void w_glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint *params) { if (p_glGetnUniformiv) p_glGetnUniformiv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformiv)
void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) WEAKGL;
static void (*p_glGetnUniformuiv)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
static void w_glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint *params) { if (p_glGetnUniformuiv) p_glGetnUniformuiv(program, location, bufSize, params); }
INTERPOSE(glGetnUniformuiv)
void glHint(GLenum target, GLenum mode) WEAKGL;
static void (*p_glHint)(GLenum target, GLenum mode);
static void w_glHint(GLenum target, GLenum mode) { if (p_glHint) p_glHint(target, mode); }
INTERPOSE(glHint)
void glIndexMask(GLuint mask) WEAKGL;
static void (*p_glIndexMask)(GLuint mask);
static void w_glIndexMask(GLuint mask) { if (p_glIndexMask) p_glIndexMask(mask); }
INTERPOSE(glIndexMask)
void glIndexPointer(GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glIndexPointer)(GLenum type, GLsizei stride, const void *pointer);
static void w_glIndexPointer(GLenum type, GLsizei stride, const void *pointer) { if (p_glIndexPointer) p_glIndexPointer(type, stride, pointer); }
INTERPOSE(glIndexPointer)
void glIndexd(GLdouble c) WEAKGL;
static void (*p_glIndexd)(GLdouble c);
static void w_glIndexd(GLdouble c) { if (p_glIndexd) p_glIndexd(c); }
INTERPOSE(glIndexd)
void glIndexdv(const GLdouble *c) WEAKGL;
static void (*p_glIndexdv)(const GLdouble *c);
static void w_glIndexdv(const GLdouble *c) { if (p_glIndexdv) p_glIndexdv(c); }
INTERPOSE(glIndexdv)
void glIndexf(GLfloat c) WEAKGL;
static void (*p_glIndexf)(GLfloat c);
static void w_glIndexf(GLfloat c) { if (p_glIndexf) p_glIndexf(c); }
INTERPOSE(glIndexf)
void glIndexfv(const GLfloat *c) WEAKGL;
static void (*p_glIndexfv)(const GLfloat *c);
static void w_glIndexfv(const GLfloat *c) { if (p_glIndexfv) p_glIndexfv(c); }
INTERPOSE(glIndexfv)
void glIndexi(GLint c) WEAKGL;
static void (*p_glIndexi)(GLint c);
static void w_glIndexi(GLint c) { if (p_glIndexi) p_glIndexi(c); }
INTERPOSE(glIndexi)
void glIndexiv(const GLint *c) WEAKGL;
static void (*p_glIndexiv)(const GLint *c);
static void w_glIndexiv(const GLint *c) { if (p_glIndexiv) p_glIndexiv(c); }
INTERPOSE(glIndexiv)
void glIndexs(GLshort c) WEAKGL;
static void (*p_glIndexs)(GLshort c);
static void w_glIndexs(GLshort c) { if (p_glIndexs) p_glIndexs(c); }
INTERPOSE(glIndexs)
void glIndexsv(const GLshort *c) WEAKGL;
static void (*p_glIndexsv)(const GLshort *c);
static void w_glIndexsv(const GLshort *c) { if (p_glIndexsv) p_glIndexsv(c); }
INTERPOSE(glIndexsv)
void glIndexub(GLubyte c) WEAKGL;
static void (*p_glIndexub)(GLubyte c);
static void w_glIndexub(GLubyte c) { if (p_glIndexub) p_glIndexub(c); }
INTERPOSE(glIndexub)
void glIndexubv(const GLubyte *c) WEAKGL;
static void (*p_glIndexubv)(const GLubyte *c);
static void w_glIndexubv(const GLubyte *c) { if (p_glIndexubv) p_glIndexubv(c); }
INTERPOSE(glIndexubv)
void glInitNames(void) WEAKGL;
static void (*p_glInitNames)(void);
static void w_glInitNames(void) { if (p_glInitNames) p_glInitNames(); }
INTERPOSE(glInitNames)
void glInterleavedArrays(GLenum format, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glInterleavedArrays)(GLenum format, GLsizei stride, const void *pointer);
static void w_glInterleavedArrays(GLenum format, GLsizei stride, const void *pointer) { if (p_glInterleavedArrays) p_glInterleavedArrays(format, stride, pointer); }
INTERPOSE(glInterleavedArrays)
void glInvalidateBufferData(GLuint buffer) WEAKGL;
static void (*p_glInvalidateBufferData)(GLuint buffer);
static void w_glInvalidateBufferData(GLuint buffer) { if (p_glInvalidateBufferData) p_glInvalidateBufferData(buffer); }
INTERPOSE(glInvalidateBufferData)
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) WEAKGL;
static void (*p_glInvalidateBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr length);
static void w_glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) { if (p_glInvalidateBufferSubData) p_glInvalidateBufferSubData(buffer, offset, length); }
INTERPOSE(glInvalidateBufferSubData)
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) WEAKGL;
static void (*p_glInvalidateFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
static void w_glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments) { if (p_glInvalidateFramebuffer) p_glInvalidateFramebuffer(target, numAttachments, attachments); }
INTERPOSE(glInvalidateFramebuffer)
void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) WEAKGL;
static void (*p_glInvalidateNamedFramebufferData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
static void w_glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) { if (p_glInvalidateNamedFramebufferData) p_glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments); }
INTERPOSE(glInvalidateNamedFramebufferData)
void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glInvalidateNamedFramebufferSubData)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glInvalidateNamedFramebufferSubData) p_glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height); }
INTERPOSE(glInvalidateNamedFramebufferSubData)
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glInvalidateSubFramebuffer)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glInvalidateSubFramebuffer) p_glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height); }
INTERPOSE(glInvalidateSubFramebuffer)
void glInvalidateTexImage(GLuint texture, GLint level) WEAKGL;
static void (*p_glInvalidateTexImage)(GLuint texture, GLint level);
static void w_glInvalidateTexImage(GLuint texture, GLint level) { if (p_glInvalidateTexImage) p_glInvalidateTexImage(texture, level); }
INTERPOSE(glInvalidateTexImage)
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) WEAKGL;
static void (*p_glInvalidateTexSubImage)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
static void w_glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) { if (p_glInvalidateTexSubImage) p_glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth); }
INTERPOSE(glInvalidateTexSubImage)
GLboolean glIsBuffer(GLuint buffer) WEAKGL;
static GLboolean (*p_glIsBuffer)(GLuint buffer);
static GLboolean w_glIsBuffer(GLuint buffer) { if (!p_glIsBuffer) return (GLboolean)0; return p_glIsBuffer(buffer); }
INTERPOSE(glIsBuffer)
GLboolean glIsEnabled(GLenum cap) WEAKGL;
static GLboolean (*p_glIsEnabled)(GLenum cap);
static GLboolean w_glIsEnabled(GLenum cap) { if (!p_glIsEnabled) return (GLboolean)0; return p_glIsEnabled(cap); }
INTERPOSE(glIsEnabled)
GLboolean glIsEnabledi(GLenum target, GLuint index) WEAKGL;
static GLboolean (*p_glIsEnabledi)(GLenum target, GLuint index);
static GLboolean w_glIsEnabledi(GLenum target, GLuint index) { if (!p_glIsEnabledi) return (GLboolean)0; return p_glIsEnabledi(target, index); }
INTERPOSE(glIsEnabledi)
GLboolean glIsFramebuffer(GLuint framebuffer) WEAKGL;
static GLboolean (*p_glIsFramebuffer)(GLuint framebuffer);
static GLboolean w_glIsFramebuffer(GLuint framebuffer) { if (!p_glIsFramebuffer) return (GLboolean)0; return p_glIsFramebuffer(framebuffer); }
INTERPOSE(glIsFramebuffer)
GLboolean glIsList(GLuint list) WEAKGL;
static GLboolean (*p_glIsList)(GLuint list);
static GLboolean w_glIsList(GLuint list) { if (!p_glIsList) return (GLboolean)0; return p_glIsList(list); }
INTERPOSE(glIsList)
GLboolean glIsProgram(GLuint program) WEAKGL;
static GLboolean (*p_glIsProgram)(GLuint program);
static GLboolean w_glIsProgram(GLuint program) { if (!p_glIsProgram) return (GLboolean)0; return p_glIsProgram(program); }
INTERPOSE(glIsProgram)
GLboolean glIsProgramPipeline(GLuint pipeline) WEAKGL;
static GLboolean (*p_glIsProgramPipeline)(GLuint pipeline);
static GLboolean w_glIsProgramPipeline(GLuint pipeline) { if (!p_glIsProgramPipeline) return (GLboolean)0; return p_glIsProgramPipeline(pipeline); }
INTERPOSE(glIsProgramPipeline)
GLboolean glIsQuery(GLuint id) WEAKGL;
static GLboolean (*p_glIsQuery)(GLuint id);
static GLboolean w_glIsQuery(GLuint id) { if (!p_glIsQuery) return (GLboolean)0; return p_glIsQuery(id); }
INTERPOSE(glIsQuery)
GLboolean glIsRenderbuffer(GLuint renderbuffer) WEAKGL;
static GLboolean (*p_glIsRenderbuffer)(GLuint renderbuffer);
static GLboolean w_glIsRenderbuffer(GLuint renderbuffer) { if (!p_glIsRenderbuffer) return (GLboolean)0; return p_glIsRenderbuffer(renderbuffer); }
INTERPOSE(glIsRenderbuffer)
GLboolean glIsSampler(GLuint sampler) WEAKGL;
static GLboolean (*p_glIsSampler)(GLuint sampler);
static GLboolean w_glIsSampler(GLuint sampler) { if (!p_glIsSampler) return (GLboolean)0; return p_glIsSampler(sampler); }
INTERPOSE(glIsSampler)
GLboolean glIsShader(GLuint shader) WEAKGL;
static GLboolean (*p_glIsShader)(GLuint shader);
static GLboolean w_glIsShader(GLuint shader) { if (!p_glIsShader) return (GLboolean)0; return p_glIsShader(shader); }
INTERPOSE(glIsShader)
GLboolean glIsSync(GLsync sync) WEAKGL;
static GLboolean (*p_glIsSync)(GLsync sync);
static GLboolean w_glIsSync(GLsync sync) { if (!p_glIsSync) return (GLboolean)0; return p_glIsSync(sync); }
INTERPOSE(glIsSync)
GLboolean glIsTexture(GLuint texture) WEAKGL;
static GLboolean (*p_glIsTexture)(GLuint texture);
static GLboolean w_glIsTexture(GLuint texture) { if (!p_glIsTexture) return (GLboolean)0; return p_glIsTexture(texture); }
INTERPOSE(glIsTexture)
GLboolean glIsTransformFeedback(GLuint id) WEAKGL;
static GLboolean (*p_glIsTransformFeedback)(GLuint id);
static GLboolean w_glIsTransformFeedback(GLuint id) { if (!p_glIsTransformFeedback) return (GLboolean)0; return p_glIsTransformFeedback(id); }
INTERPOSE(glIsTransformFeedback)
GLboolean glIsVertexArray(GLuint array) WEAKGL;
static GLboolean (*p_glIsVertexArray)(GLuint array);
static GLboolean w_glIsVertexArray(GLuint array) { if (!p_glIsVertexArray) return (GLboolean)0; return p_glIsVertexArray(array); }
INTERPOSE(glIsVertexArray)
void glLightModelf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glLightModelf)(GLenum pname, GLfloat param);
static void w_glLightModelf(GLenum pname, GLfloat param) { if (p_glLightModelf) p_glLightModelf(pname, param); }
INTERPOSE(glLightModelf)
void glLightModelfv(GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glLightModelfv)(GLenum pname, const GLfloat *params);
static void w_glLightModelfv(GLenum pname, const GLfloat *params) { if (p_glLightModelfv) p_glLightModelfv(pname, params); }
INTERPOSE(glLightModelfv)
void glLightModeli(GLenum pname, GLint param) WEAKGL;
static void (*p_glLightModeli)(GLenum pname, GLint param);
static void w_glLightModeli(GLenum pname, GLint param) { if (p_glLightModeli) p_glLightModeli(pname, param); }
INTERPOSE(glLightModeli)
void glLightModeliv(GLenum pname, const GLint *params) WEAKGL;
static void (*p_glLightModeliv)(GLenum pname, const GLint *params);
static void w_glLightModeliv(GLenum pname, const GLint *params) { if (p_glLightModeliv) p_glLightModeliv(pname, params); }
INTERPOSE(glLightModeliv)
void glLightf(GLenum light, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glLightf)(GLenum light, GLenum pname, GLfloat param);
static void w_glLightf(GLenum light, GLenum pname, GLfloat param) { if (p_glLightf) p_glLightf(light, pname, param); }
INTERPOSE(glLightf)
void glLightfv(GLenum light, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glLightfv)(GLenum light, GLenum pname, const GLfloat *params);
static void w_glLightfv(GLenum light, GLenum pname, const GLfloat *params) { if (p_glLightfv) p_glLightfv(light, pname, params); }
INTERPOSE(glLightfv)
void glLighti(GLenum light, GLenum pname, GLint param) WEAKGL;
static void (*p_glLighti)(GLenum light, GLenum pname, GLint param);
static void w_glLighti(GLenum light, GLenum pname, GLint param) { if (p_glLighti) p_glLighti(light, pname, param); }
INTERPOSE(glLighti)
void glLightiv(GLenum light, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glLightiv)(GLenum light, GLenum pname, const GLint *params);
static void w_glLightiv(GLenum light, GLenum pname, const GLint *params) { if (p_glLightiv) p_glLightiv(light, pname, params); }
INTERPOSE(glLightiv)
void glLineStipple(GLint factor, GLushort pattern) WEAKGL;
static void (*p_glLineStipple)(GLint factor, GLushort pattern);
static void w_glLineStipple(GLint factor, GLushort pattern) { if (p_glLineStipple) p_glLineStipple(factor, pattern); }
INTERPOSE(glLineStipple)
void glLineWidth(GLfloat width) WEAKGL;
static void (*p_glLineWidth)(GLfloat width);
static void w_glLineWidth(GLfloat width) { if (p_glLineWidth) p_glLineWidth(width); }
INTERPOSE(glLineWidth)
void glLinkProgram(GLuint program) WEAKGL;
static void (*p_glLinkProgram)(GLuint program);
static void w_glLinkProgram(GLuint program) { if (p_glLinkProgram) p_glLinkProgram(program); }
INTERPOSE(glLinkProgram)
void glListBase(GLuint base) WEAKGL;
static void (*p_glListBase)(GLuint base);
static void w_glListBase(GLuint base) { if (p_glListBase) p_glListBase(base); }
INTERPOSE(glListBase)
void glLoadIdentity(void) WEAKGL;
static void (*p_glLoadIdentity)(void);
static void w_glLoadIdentity(void) { if (p_glLoadIdentity) p_glLoadIdentity(); }
INTERPOSE(glLoadIdentity)
void glLoadMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glLoadMatrixd)(const GLdouble *m);
static void w_glLoadMatrixd(const GLdouble *m) { if (p_glLoadMatrixd) p_glLoadMatrixd(m); }
INTERPOSE(glLoadMatrixd)
void glLoadMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glLoadMatrixf)(const GLfloat *m);
static void w_glLoadMatrixf(const GLfloat *m) { if (p_glLoadMatrixf) p_glLoadMatrixf(m); }
INTERPOSE(glLoadMatrixf)
void glLoadName(GLuint name) WEAKGL;
static void (*p_glLoadName)(GLuint name);
static void w_glLoadName(GLuint name) { if (p_glLoadName) p_glLoadName(name); }
INTERPOSE(glLoadName)
void glLoadTransposeMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glLoadTransposeMatrixd)(const GLdouble *m);
static void w_glLoadTransposeMatrixd(const GLdouble *m) { if (p_glLoadTransposeMatrixd) p_glLoadTransposeMatrixd(m); }
INTERPOSE(glLoadTransposeMatrixd)
void glLoadTransposeMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glLoadTransposeMatrixf)(const GLfloat *m);
static void w_glLoadTransposeMatrixf(const GLfloat *m) { if (p_glLoadTransposeMatrixf) p_glLoadTransposeMatrixf(m); }
INTERPOSE(glLoadTransposeMatrixf)
void glLogicOp(GLenum opcode) WEAKGL;
static void (*p_glLogicOp)(GLenum opcode);
static void w_glLogicOp(GLenum opcode) { if (p_glLogicOp) p_glLogicOp(opcode); }
INTERPOSE(glLogicOp)
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) WEAKGL;
static void (*p_glMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
static void w_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) { if (p_glMap1d) p_glMap1d(target, u1, u2, stride, order, points); }
INTERPOSE(glMap1d)
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) WEAKGL;
static void (*p_glMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
static void w_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) { if (p_glMap1f) p_glMap1f(target, u1, u2, stride, order, points); }
INTERPOSE(glMap1f)
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) WEAKGL;
static void (*p_glMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
static void w_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) { if (p_glMap2d) p_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); }
INTERPOSE(glMap2d)
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) WEAKGL;
static void (*p_glMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
static void w_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) { if (p_glMap2f) p_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); }
INTERPOSE(glMap2f)
void * glMapBuffer(GLenum target, GLenum access) WEAKGL;
static void * (*p_glMapBuffer)(GLenum target, GLenum access);
static void * w_glMapBuffer(GLenum target, GLenum access) { if (!p_glMapBuffer) return (void *)0; return p_glMapBuffer(target, access); }
INTERPOSE(glMapBuffer)
void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) WEAKGL;
static void * (*p_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
static void * w_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) { if (!p_glMapBufferRange) return (void *)0; return p_glMapBufferRange(target, offset, length, access); }
INTERPOSE(glMapBufferRange)
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) WEAKGL;
static void (*p_glMapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
static void w_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) { if (p_glMapGrid1d) p_glMapGrid1d(un, u1, u2); }
INTERPOSE(glMapGrid1d)
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) WEAKGL;
static void (*p_glMapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
static void w_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) { if (p_glMapGrid1f) p_glMapGrid1f(un, u1, u2); }
INTERPOSE(glMapGrid1f)
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) WEAKGL;
static void (*p_glMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
static void w_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) { if (p_glMapGrid2d) p_glMapGrid2d(un, u1, u2, vn, v1, v2); }
INTERPOSE(glMapGrid2d)
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) WEAKGL;
static void (*p_glMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
static void w_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) { if (p_glMapGrid2f) p_glMapGrid2f(un, u1, u2, vn, v1, v2); }
INTERPOSE(glMapGrid2f)
void * glMapNamedBuffer(GLuint buffer, GLenum access) WEAKGL;
static void * (*p_glMapNamedBuffer)(GLuint buffer, GLenum access);
static void * w_glMapNamedBuffer(GLuint buffer, GLenum access) { if (!p_glMapNamedBuffer) return (void *)0; return p_glMapNamedBuffer(buffer, access); }
INTERPOSE(glMapNamedBuffer)
void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) WEAKGL;
static void * (*p_glMapNamedBufferRange)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
static void * w_glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) { if (!p_glMapNamedBufferRange) return (void *)0; return p_glMapNamedBufferRange(buffer, offset, length, access); }
INTERPOSE(glMapNamedBufferRange)
void glMaterialf(GLenum face, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glMaterialf)(GLenum face, GLenum pname, GLfloat param);
static void w_glMaterialf(GLenum face, GLenum pname, GLfloat param) { if (p_glMaterialf) p_glMaterialf(face, pname, param); }
INTERPOSE(glMaterialf)
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glMaterialfv)(GLenum face, GLenum pname, const GLfloat *params);
static void w_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) { if (p_glMaterialfv) p_glMaterialfv(face, pname, params); }
INTERPOSE(glMaterialfv)
void glMateriali(GLenum face, GLenum pname, GLint param) WEAKGL;
static void (*p_glMateriali)(GLenum face, GLenum pname, GLint param);
static void w_glMateriali(GLenum face, GLenum pname, GLint param) { if (p_glMateriali) p_glMateriali(face, pname, param); }
INTERPOSE(glMateriali)
void glMaterialiv(GLenum face, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glMaterialiv)(GLenum face, GLenum pname, const GLint *params);
static void w_glMaterialiv(GLenum face, GLenum pname, const GLint *params) { if (p_glMaterialiv) p_glMaterialiv(face, pname, params); }
INTERPOSE(glMaterialiv)
void glMatrixMode(GLenum mode) WEAKGL;
static void (*p_glMatrixMode)(GLenum mode);
static void w_glMatrixMode(GLenum mode) { if (p_glMatrixMode) p_glMatrixMode(mode); }
INTERPOSE(glMatrixMode)
void glMemoryBarrier(GLbitfield barriers) WEAKGL;
static void (*p_glMemoryBarrier)(GLbitfield barriers);
static void w_glMemoryBarrier(GLbitfield barriers) { if (p_glMemoryBarrier) p_glMemoryBarrier(barriers); }
INTERPOSE(glMemoryBarrier)
void glMemoryBarrierByRegion(GLbitfield barriers) WEAKGL;
static void (*p_glMemoryBarrierByRegion)(GLbitfield barriers);
static void w_glMemoryBarrierByRegion(GLbitfield barriers) { if (p_glMemoryBarrierByRegion) p_glMemoryBarrierByRegion(barriers); }
INTERPOSE(glMemoryBarrierByRegion)
void glMinSampleShading(GLfloat value) WEAKGL;
static void (*p_glMinSampleShading)(GLfloat value);
static void w_glMinSampleShading(GLfloat value) { if (p_glMinSampleShading) p_glMinSampleShading(value); }
INTERPOSE(glMinSampleShading)
void glMultMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glMultMatrixd)(const GLdouble *m);
static void w_glMultMatrixd(const GLdouble *m) { if (p_glMultMatrixd) p_glMultMatrixd(m); }
INTERPOSE(glMultMatrixd)
void glMultMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glMultMatrixf)(const GLfloat *m);
static void w_glMultMatrixf(const GLfloat *m) { if (p_glMultMatrixf) p_glMultMatrixf(m); }
INTERPOSE(glMultMatrixf)
void glMultTransposeMatrixd(const GLdouble *m) WEAKGL;
static void (*p_glMultTransposeMatrixd)(const GLdouble *m);
static void w_glMultTransposeMatrixd(const GLdouble *m) { if (p_glMultTransposeMatrixd) p_glMultTransposeMatrixd(m); }
INTERPOSE(glMultTransposeMatrixd)
void glMultTransposeMatrixf(const GLfloat *m) WEAKGL;
static void (*p_glMultTransposeMatrixf)(const GLfloat *m);
static void w_glMultTransposeMatrixf(const GLfloat *m) { if (p_glMultTransposeMatrixf) p_glMultTransposeMatrixf(m); }
INTERPOSE(glMultTransposeMatrixf)
void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) WEAKGL;
static void (*p_glMultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
static void w_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) { if (p_glMultiDrawArrays) p_glMultiDrawArrays(mode, first, count, drawcount); }
INTERPOSE(glMultiDrawArrays)
void glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawArraysIndirect)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
static void w_glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) { if (p_glMultiDrawArraysIndirect) p_glMultiDrawArraysIndirect(mode, indirect, drawcount, stride); }
INTERPOSE(glMultiDrawArraysIndirect)
void glMultiDrawArraysIndirectCount(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawArraysIndirectCount)(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
static void w_glMultiDrawArraysIndirectCount(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) { if (p_glMultiDrawArraysIndirectCount) p_glMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride); }
INTERPOSE(glMultiDrawArraysIndirectCount)
void glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) WEAKGL;
static void (*p_glMultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
static void w_glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) { if (p_glMultiDrawElements) p_glMultiDrawElements(mode, count, type, indices, drawcount); }
INTERPOSE(glMultiDrawElements)
void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) WEAKGL;
static void (*p_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
static void w_glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) { if (p_glMultiDrawElementsBaseVertex) p_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex); }
INTERPOSE(glMultiDrawElementsBaseVertex)
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawElementsIndirect)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
static void w_glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) { if (p_glMultiDrawElementsIndirect) p_glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride); }
INTERPOSE(glMultiDrawElementsIndirect)
void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) WEAKGL;
static void (*p_glMultiDrawElementsIndirectCount)(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
static void w_glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) { if (p_glMultiDrawElementsIndirectCount) p_glMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride); }
INTERPOSE(glMultiDrawElementsIndirectCount)
void glMultiTexCoord1d(GLenum target, GLdouble s) WEAKGL;
static void (*p_glMultiTexCoord1d)(GLenum target, GLdouble s);
static void w_glMultiTexCoord1d(GLenum target, GLdouble s) { if (p_glMultiTexCoord1d) p_glMultiTexCoord1d(target, s); }
INTERPOSE(glMultiTexCoord1d)
void glMultiTexCoord1dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord1dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord1dv(GLenum target, const GLdouble *v) { if (p_glMultiTexCoord1dv) p_glMultiTexCoord1dv(target, v); }
INTERPOSE(glMultiTexCoord1dv)
void glMultiTexCoord1f(GLenum target, GLfloat s) WEAKGL;
static void (*p_glMultiTexCoord1f)(GLenum target, GLfloat s);
static void w_glMultiTexCoord1f(GLenum target, GLfloat s) { if (p_glMultiTexCoord1f) p_glMultiTexCoord1f(target, s); }
INTERPOSE(glMultiTexCoord1f)
void glMultiTexCoord1fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord1fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord1fv(GLenum target, const GLfloat *v) { if (p_glMultiTexCoord1fv) p_glMultiTexCoord1fv(target, v); }
INTERPOSE(glMultiTexCoord1fv)
void glMultiTexCoord1i(GLenum target, GLint s) WEAKGL;
static void (*p_glMultiTexCoord1i)(GLenum target, GLint s);
static void w_glMultiTexCoord1i(GLenum target, GLint s) { if (p_glMultiTexCoord1i) p_glMultiTexCoord1i(target, s); }
INTERPOSE(glMultiTexCoord1i)
void glMultiTexCoord1iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord1iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord1iv(GLenum target, const GLint *v) { if (p_glMultiTexCoord1iv) p_glMultiTexCoord1iv(target, v); }
INTERPOSE(glMultiTexCoord1iv)
void glMultiTexCoord1s(GLenum target, GLshort s) WEAKGL;
static void (*p_glMultiTexCoord1s)(GLenum target, GLshort s);
static void w_glMultiTexCoord1s(GLenum target, GLshort s) { if (p_glMultiTexCoord1s) p_glMultiTexCoord1s(target, s); }
INTERPOSE(glMultiTexCoord1s)
void glMultiTexCoord1sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord1sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord1sv(GLenum target, const GLshort *v) { if (p_glMultiTexCoord1sv) p_glMultiTexCoord1sv(target, v); }
INTERPOSE(glMultiTexCoord1sv)
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) WEAKGL;
static void (*p_glMultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t);
static void w_glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) { if (p_glMultiTexCoord2d) p_glMultiTexCoord2d(target, s, t); }
INTERPOSE(glMultiTexCoord2d)
void glMultiTexCoord2dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord2dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord2dv(GLenum target, const GLdouble *v) { if (p_glMultiTexCoord2dv) p_glMultiTexCoord2dv(target, v); }
INTERPOSE(glMultiTexCoord2dv)
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) WEAKGL;
static void (*p_glMultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t);
static void w_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) { if (p_glMultiTexCoord2f) p_glMultiTexCoord2f(target, s, t); }
INTERPOSE(glMultiTexCoord2f)
void glMultiTexCoord2fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord2fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord2fv(GLenum target, const GLfloat *v) { if (p_glMultiTexCoord2fv) p_glMultiTexCoord2fv(target, v); }
INTERPOSE(glMultiTexCoord2fv)
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) WEAKGL;
static void (*p_glMultiTexCoord2i)(GLenum target, GLint s, GLint t);
static void w_glMultiTexCoord2i(GLenum target, GLint s, GLint t) { if (p_glMultiTexCoord2i) p_glMultiTexCoord2i(target, s, t); }
INTERPOSE(glMultiTexCoord2i)
void glMultiTexCoord2iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord2iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord2iv(GLenum target, const GLint *v) { if (p_glMultiTexCoord2iv) p_glMultiTexCoord2iv(target, v); }
INTERPOSE(glMultiTexCoord2iv)
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) WEAKGL;
static void (*p_glMultiTexCoord2s)(GLenum target, GLshort s, GLshort t);
static void w_glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) { if (p_glMultiTexCoord2s) p_glMultiTexCoord2s(target, s, t); }
INTERPOSE(glMultiTexCoord2s)
void glMultiTexCoord2sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord2sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord2sv(GLenum target, const GLshort *v) { if (p_glMultiTexCoord2sv) p_glMultiTexCoord2sv(target, v); }
INTERPOSE(glMultiTexCoord2sv)
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) WEAKGL;
static void (*p_glMultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
static void w_glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) { if (p_glMultiTexCoord3d) p_glMultiTexCoord3d(target, s, t, r); }
INTERPOSE(glMultiTexCoord3d)
void glMultiTexCoord3dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord3dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord3dv(GLenum target, const GLdouble *v) { if (p_glMultiTexCoord3dv) p_glMultiTexCoord3dv(target, v); }
INTERPOSE(glMultiTexCoord3dv)
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) WEAKGL;
static void (*p_glMultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
static void w_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) { if (p_glMultiTexCoord3f) p_glMultiTexCoord3f(target, s, t, r); }
INTERPOSE(glMultiTexCoord3f)
void glMultiTexCoord3fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord3fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord3fv(GLenum target, const GLfloat *v) { if (p_glMultiTexCoord3fv) p_glMultiTexCoord3fv(target, v); }
INTERPOSE(glMultiTexCoord3fv)
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) WEAKGL;
static void (*p_glMultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r);
static void w_glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) { if (p_glMultiTexCoord3i) p_glMultiTexCoord3i(target, s, t, r); }
INTERPOSE(glMultiTexCoord3i)
void glMultiTexCoord3iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord3iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord3iv(GLenum target, const GLint *v) { if (p_glMultiTexCoord3iv) p_glMultiTexCoord3iv(target, v); }
INTERPOSE(glMultiTexCoord3iv)
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) WEAKGL;
static void (*p_glMultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r);
static void w_glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) { if (p_glMultiTexCoord3s) p_glMultiTexCoord3s(target, s, t, r); }
INTERPOSE(glMultiTexCoord3s)
void glMultiTexCoord3sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord3sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord3sv(GLenum target, const GLshort *v) { if (p_glMultiTexCoord3sv) p_glMultiTexCoord3sv(target, v); }
INTERPOSE(glMultiTexCoord3sv)
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) WEAKGL;
static void (*p_glMultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void w_glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) { if (p_glMultiTexCoord4d) p_glMultiTexCoord4d(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4d)
void glMultiTexCoord4dv(GLenum target, const GLdouble *v) WEAKGL;
static void (*p_glMultiTexCoord4dv)(GLenum target, const GLdouble *v);
static void w_glMultiTexCoord4dv(GLenum target, const GLdouble *v) { if (p_glMultiTexCoord4dv) p_glMultiTexCoord4dv(target, v); }
INTERPOSE(glMultiTexCoord4dv)
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) WEAKGL;
static void (*p_glMultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void w_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) { if (p_glMultiTexCoord4f) p_glMultiTexCoord4f(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4f)
void glMultiTexCoord4fv(GLenum target, const GLfloat *v) WEAKGL;
static void (*p_glMultiTexCoord4fv)(GLenum target, const GLfloat *v);
static void w_glMultiTexCoord4fv(GLenum target, const GLfloat *v) { if (p_glMultiTexCoord4fv) p_glMultiTexCoord4fv(target, v); }
INTERPOSE(glMultiTexCoord4fv)
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) WEAKGL;
static void (*p_glMultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q);
static void w_glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) { if (p_glMultiTexCoord4i) p_glMultiTexCoord4i(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4i)
void glMultiTexCoord4iv(GLenum target, const GLint *v) WEAKGL;
static void (*p_glMultiTexCoord4iv)(GLenum target, const GLint *v);
static void w_glMultiTexCoord4iv(GLenum target, const GLint *v) { if (p_glMultiTexCoord4iv) p_glMultiTexCoord4iv(target, v); }
INTERPOSE(glMultiTexCoord4iv)
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) WEAKGL;
static void (*p_glMultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
static void w_glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) { if (p_glMultiTexCoord4s) p_glMultiTexCoord4s(target, s, t, r, q); }
INTERPOSE(glMultiTexCoord4s)
void glMultiTexCoord4sv(GLenum target, const GLshort *v) WEAKGL;
static void (*p_glMultiTexCoord4sv)(GLenum target, const GLshort *v);
static void w_glMultiTexCoord4sv(GLenum target, const GLshort *v) { if (p_glMultiTexCoord4sv) p_glMultiTexCoord4sv(target, v); }
INTERPOSE(glMultiTexCoord4sv)
void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) { if (p_glMultiTexCoordP1ui) p_glMultiTexCoordP1ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP1ui)
void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords) { if (p_glMultiTexCoordP1uiv) p_glMultiTexCoordP1uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP1uiv)
void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) { if (p_glMultiTexCoordP2ui) p_glMultiTexCoordP2ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP2ui)
void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords) { if (p_glMultiTexCoordP2uiv) p_glMultiTexCoordP2uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP2uiv)
void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) { if (p_glMultiTexCoordP3ui) p_glMultiTexCoordP3ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP3ui)
void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords) { if (p_glMultiTexCoordP3uiv) p_glMultiTexCoordP3uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP3uiv)
void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) WEAKGL;
static void (*p_glMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords);
static void w_glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) { if (p_glMultiTexCoordP4ui) p_glMultiTexCoordP4ui(texture, type, coords); }
INTERPOSE(glMultiTexCoordP4ui)
void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint *coords);
static void w_glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords) { if (p_glMultiTexCoordP4uiv) p_glMultiTexCoordP4uiv(texture, type, coords); }
INTERPOSE(glMultiTexCoordP4uiv)
void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) WEAKGL;
static void (*p_glNamedBufferData)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
static void w_glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) { if (p_glNamedBufferData) p_glNamedBufferData(buffer, size, data, usage); }
INTERPOSE(glNamedBufferData)
void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) WEAKGL;
static void (*p_glNamedBufferStorage)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
static void w_glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) { if (p_glNamedBufferStorage) p_glNamedBufferStorage(buffer, size, data, flags); }
INTERPOSE(glNamedBufferStorage)
void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) WEAKGL;
static void (*p_glNamedBufferSubData)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
static void w_glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) { if (p_glNamedBufferSubData) p_glNamedBufferSubData(buffer, offset, size, data); }
INTERPOSE(glNamedBufferSubData)
void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) WEAKGL;
static void (*p_glNamedFramebufferDrawBuffer)(GLuint framebuffer, GLenum buf);
static void w_glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) { if (p_glNamedFramebufferDrawBuffer) p_glNamedFramebufferDrawBuffer(framebuffer, buf); }
INTERPOSE(glNamedFramebufferDrawBuffer)
void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs) WEAKGL;
static void (*p_glNamedFramebufferDrawBuffers)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
static void w_glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum *bufs) { if (p_glNamedFramebufferDrawBuffers) p_glNamedFramebufferDrawBuffers(framebuffer, n, bufs); }
INTERPOSE(glNamedFramebufferDrawBuffers)
void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) WEAKGL;
static void (*p_glNamedFramebufferParameteri)(GLuint framebuffer, GLenum pname, GLint param);
static void w_glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) { if (p_glNamedFramebufferParameteri) p_glNamedFramebufferParameteri(framebuffer, pname, param); }
INTERPOSE(glNamedFramebufferParameteri)
void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) WEAKGL;
static void (*p_glNamedFramebufferReadBuffer)(GLuint framebuffer, GLenum src);
static void w_glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) { if (p_glNamedFramebufferReadBuffer) p_glNamedFramebufferReadBuffer(framebuffer, src); }
INTERPOSE(glNamedFramebufferReadBuffer)
void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) WEAKGL;
static void (*p_glNamedFramebufferRenderbuffer)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
static void w_glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { if (p_glNamedFramebufferRenderbuffer) p_glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer); }
INTERPOSE(glNamedFramebufferRenderbuffer)
void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) WEAKGL;
static void (*p_glNamedFramebufferTexture)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
static void w_glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) { if (p_glNamedFramebufferTexture) p_glNamedFramebufferTexture(framebuffer, attachment, texture, level); }
INTERPOSE(glNamedFramebufferTexture)
void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) WEAKGL;
static void (*p_glNamedFramebufferTextureLayer)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
static void w_glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) { if (p_glNamedFramebufferTextureLayer) p_glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer); }
INTERPOSE(glNamedFramebufferTextureLayer)
void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glNamedRenderbufferStorage)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) { if (p_glNamedRenderbufferStorage) p_glNamedRenderbufferStorage(renderbuffer, internalformat, width, height); }
INTERPOSE(glNamedRenderbufferStorage)
void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glNamedRenderbufferStorageMultisample)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { if (p_glNamedRenderbufferStorageMultisample) p_glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height); }
INTERPOSE(glNamedRenderbufferStorageMultisample)
void glNewList(GLuint list, GLenum mode) WEAKGL;
static void (*p_glNewList)(GLuint list, GLenum mode);
static void w_glNewList(GLuint list, GLenum mode) { if (p_glNewList) p_glNewList(list, mode); }
INTERPOSE(glNewList)
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) WEAKGL;
static void (*p_glNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
static void w_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) { if (p_glNormal3b) p_glNormal3b(nx, ny, nz); }
INTERPOSE(glNormal3b)
void glNormal3bv(const GLbyte *v) WEAKGL;
static void (*p_glNormal3bv)(const GLbyte *v);
static void w_glNormal3bv(const GLbyte *v) { if (p_glNormal3bv) p_glNormal3bv(v); }
INTERPOSE(glNormal3bv)
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) WEAKGL;
static void (*p_glNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
static void w_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) { if (p_glNormal3d) p_glNormal3d(nx, ny, nz); }
INTERPOSE(glNormal3d)
void glNormal3dv(const GLdouble *v) WEAKGL;
static void (*p_glNormal3dv)(const GLdouble *v);
static void w_glNormal3dv(const GLdouble *v) { if (p_glNormal3dv) p_glNormal3dv(v); }
INTERPOSE(glNormal3dv)
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) WEAKGL;
static void (*p_glNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
static void w_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) { if (p_glNormal3f) p_glNormal3f(nx, ny, nz); }
INTERPOSE(glNormal3f)
void glNormal3fv(const GLfloat *v) WEAKGL;
static void (*p_glNormal3fv)(const GLfloat *v);
static void w_glNormal3fv(const GLfloat *v) { if (p_glNormal3fv) p_glNormal3fv(v); }
INTERPOSE(glNormal3fv)
void glNormal3i(GLint nx, GLint ny, GLint nz) WEAKGL;
static void (*p_glNormal3i)(GLint nx, GLint ny, GLint nz);
static void w_glNormal3i(GLint nx, GLint ny, GLint nz) { if (p_glNormal3i) p_glNormal3i(nx, ny, nz); }
INTERPOSE(glNormal3i)
void glNormal3iv(const GLint *v) WEAKGL;
static void (*p_glNormal3iv)(const GLint *v);
static void w_glNormal3iv(const GLint *v) { if (p_glNormal3iv) p_glNormal3iv(v); }
INTERPOSE(glNormal3iv)
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) WEAKGL;
static void (*p_glNormal3s)(GLshort nx, GLshort ny, GLshort nz);
static void w_glNormal3s(GLshort nx, GLshort ny, GLshort nz) { if (p_glNormal3s) p_glNormal3s(nx, ny, nz); }
INTERPOSE(glNormal3s)
void glNormal3sv(const GLshort *v) WEAKGL;
static void (*p_glNormal3sv)(const GLshort *v);
static void w_glNormal3sv(const GLshort *v) { if (p_glNormal3sv) p_glNormal3sv(v); }
INTERPOSE(glNormal3sv)
void glNormalP3ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glNormalP3ui)(GLenum type, GLuint coords);
static void w_glNormalP3ui(GLenum type, GLuint coords) { if (p_glNormalP3ui) p_glNormalP3ui(type, coords); }
INTERPOSE(glNormalP3ui)
void glNormalP3uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glNormalP3uiv)(GLenum type, const GLuint *coords);
static void w_glNormalP3uiv(GLenum type, const GLuint *coords) { if (p_glNormalP3uiv) p_glNormalP3uiv(type, coords); }
INTERPOSE(glNormalP3uiv)
void glNormalPointer(GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glNormalPointer)(GLenum type, GLsizei stride, const void *pointer);
static void w_glNormalPointer(GLenum type, GLsizei stride, const void *pointer) { if (p_glNormalPointer) p_glNormalPointer(type, stride, pointer); }
INTERPOSE(glNormalPointer)
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) WEAKGL;
static void (*p_glObjectLabel)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
static void w_glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar *label) { if (p_glObjectLabel) p_glObjectLabel(identifier, name, length, label); }
INTERPOSE(glObjectLabel)
void glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) WEAKGL;
static void (*p_glObjectPtrLabel)(const void *ptr, GLsizei length, const GLchar *label);
static void w_glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar *label) { if (p_glObjectPtrLabel) p_glObjectPtrLabel(ptr, length, label); }
INTERPOSE(glObjectPtrLabel)
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) WEAKGL;
static void (*p_glOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
static void w_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) { if (p_glOrtho) p_glOrtho(left, right, bottom, top, zNear, zFar); }
INTERPOSE(glOrtho)
void glPassThrough(GLfloat token) WEAKGL;
static void (*p_glPassThrough)(GLfloat token);
static void w_glPassThrough(GLfloat token) { if (p_glPassThrough) p_glPassThrough(token); }
INTERPOSE(glPassThrough)
void glPatchParameterfv(GLenum pname, const GLfloat *values) WEAKGL;
static void (*p_glPatchParameterfv)(GLenum pname, const GLfloat *values);
static void w_glPatchParameterfv(GLenum pname, const GLfloat *values) { if (p_glPatchParameterfv) p_glPatchParameterfv(pname, values); }
INTERPOSE(glPatchParameterfv)
void glPatchParameteri(GLenum pname, GLint value) WEAKGL;
static void (*p_glPatchParameteri)(GLenum pname, GLint value);
static void w_glPatchParameteri(GLenum pname, GLint value) { if (p_glPatchParameteri) p_glPatchParameteri(pname, value); }
INTERPOSE(glPatchParameteri)
void glPauseTransformFeedback(void) WEAKGL;
static void (*p_glPauseTransformFeedback)(void);
static void w_glPauseTransformFeedback(void) { if (p_glPauseTransformFeedback) p_glPauseTransformFeedback(); }
INTERPOSE(glPauseTransformFeedback)
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) WEAKGL;
static void (*p_glPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values);
static void w_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) { if (p_glPixelMapfv) p_glPixelMapfv(map, mapsize, values); }
INTERPOSE(glPixelMapfv)
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) WEAKGL;
static void (*p_glPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values);
static void w_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) { if (p_glPixelMapuiv) p_glPixelMapuiv(map, mapsize, values); }
INTERPOSE(glPixelMapuiv)
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) WEAKGL;
static void (*p_glPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values);
static void w_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) { if (p_glPixelMapusv) p_glPixelMapusv(map, mapsize, values); }
INTERPOSE(glPixelMapusv)
void glPixelStoref(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glPixelStoref)(GLenum pname, GLfloat param);
static void w_glPixelStoref(GLenum pname, GLfloat param) { if (p_glPixelStoref) p_glPixelStoref(pname, param); }
INTERPOSE(glPixelStoref)
void glPixelStorei(GLenum pname, GLint param) WEAKGL;
static void (*p_glPixelStorei)(GLenum pname, GLint param);
static void w_glPixelStorei(GLenum pname, GLint param) { if (p_glPixelStorei) p_glPixelStorei(pname, param); }
INTERPOSE(glPixelStorei)
void glPixelTransferf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glPixelTransferf)(GLenum pname, GLfloat param);
static void w_glPixelTransferf(GLenum pname, GLfloat param) { if (p_glPixelTransferf) p_glPixelTransferf(pname, param); }
INTERPOSE(glPixelTransferf)
void glPixelTransferi(GLenum pname, GLint param) WEAKGL;
static void (*p_glPixelTransferi)(GLenum pname, GLint param);
static void w_glPixelTransferi(GLenum pname, GLint param) { if (p_glPixelTransferi) p_glPixelTransferi(pname, param); }
INTERPOSE(glPixelTransferi)
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) WEAKGL;
static void (*p_glPixelZoom)(GLfloat xfactor, GLfloat yfactor);
static void w_glPixelZoom(GLfloat xfactor, GLfloat yfactor) { if (p_glPixelZoom) p_glPixelZoom(xfactor, yfactor); }
INTERPOSE(glPixelZoom)
void glPointParameterf(GLenum pname, GLfloat param) WEAKGL;
static void (*p_glPointParameterf)(GLenum pname, GLfloat param);
static void w_glPointParameterf(GLenum pname, GLfloat param) { if (p_glPointParameterf) p_glPointParameterf(pname, param); }
INTERPOSE(glPointParameterf)
void glPointParameterfv(GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glPointParameterfv)(GLenum pname, const GLfloat *params);
static void w_glPointParameterfv(GLenum pname, const GLfloat *params) { if (p_glPointParameterfv) p_glPointParameterfv(pname, params); }
INTERPOSE(glPointParameterfv)
void glPointParameteri(GLenum pname, GLint param) WEAKGL;
static void (*p_glPointParameteri)(GLenum pname, GLint param);
static void w_glPointParameteri(GLenum pname, GLint param) { if (p_glPointParameteri) p_glPointParameteri(pname, param); }
INTERPOSE(glPointParameteri)
void glPointParameteriv(GLenum pname, const GLint *params) WEAKGL;
static void (*p_glPointParameteriv)(GLenum pname, const GLint *params);
static void w_glPointParameteriv(GLenum pname, const GLint *params) { if (p_glPointParameteriv) p_glPointParameteriv(pname, params); }
INTERPOSE(glPointParameteriv)
void glPointSize(GLfloat size) WEAKGL;
static void (*p_glPointSize)(GLfloat size);
static void w_glPointSize(GLfloat size) { if (p_glPointSize) p_glPointSize(size); }
INTERPOSE(glPointSize)
void glPolygonMode(GLenum face, GLenum mode) WEAKGL;
static void (*p_glPolygonMode)(GLenum face, GLenum mode);
static void w_glPolygonMode(GLenum face, GLenum mode) { if (p_glPolygonMode) p_glPolygonMode(face, mode); }
INTERPOSE(glPolygonMode)
void glPolygonOffset(GLfloat factor, GLfloat units) WEAKGL;
static void (*p_glPolygonOffset)(GLfloat factor, GLfloat units);
static void w_glPolygonOffset(GLfloat factor, GLfloat units) { if (p_glPolygonOffset) p_glPolygonOffset(factor, units); }
INTERPOSE(glPolygonOffset)
void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) WEAKGL;
static void (*p_glPolygonOffsetClamp)(GLfloat factor, GLfloat units, GLfloat clamp);
static void w_glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) { if (p_glPolygonOffsetClamp) p_glPolygonOffsetClamp(factor, units, clamp); }
INTERPOSE(glPolygonOffsetClamp)
void glPolygonStipple(const GLubyte *mask) WEAKGL;
static void (*p_glPolygonStipple)(const GLubyte *mask);
static void w_glPolygonStipple(const GLubyte *mask) { if (p_glPolygonStipple) p_glPolygonStipple(mask); }
INTERPOSE(glPolygonStipple)
void glPopAttrib(void) WEAKGL;
static void (*p_glPopAttrib)(void);
static void w_glPopAttrib(void) { if (p_glPopAttrib) p_glPopAttrib(); }
INTERPOSE(glPopAttrib)
void glPopClientAttrib(void) WEAKGL;
static void (*p_glPopClientAttrib)(void);
static void w_glPopClientAttrib(void) { if (p_glPopClientAttrib) p_glPopClientAttrib(); }
INTERPOSE(glPopClientAttrib)
void glPopDebugGroup(void) WEAKGL;
static void (*p_glPopDebugGroup)(void);
static void w_glPopDebugGroup(void) { if (p_glPopDebugGroup) p_glPopDebugGroup(); }
INTERPOSE(glPopDebugGroup)
void glPopMatrix(void) WEAKGL;
static void (*p_glPopMatrix)(void);
static void w_glPopMatrix(void) { if (p_glPopMatrix) p_glPopMatrix(); }
INTERPOSE(glPopMatrix)
void glPopName(void) WEAKGL;
static void (*p_glPopName)(void);
static void w_glPopName(void) { if (p_glPopName) p_glPopName(); }
INTERPOSE(glPopName)
void glPrimitiveRestartIndex(GLuint index) WEAKGL;
static void (*p_glPrimitiveRestartIndex)(GLuint index);
static void w_glPrimitiveRestartIndex(GLuint index) { if (p_glPrimitiveRestartIndex) p_glPrimitiveRestartIndex(index); }
INTERPOSE(glPrimitiveRestartIndex)
void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLfloat *priorities) WEAKGL;
static void (*p_glPrioritizeTextures)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
static void w_glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLfloat *priorities) { if (p_glPrioritizeTextures) p_glPrioritizeTextures(n, textures, priorities); }
INTERPOSE(glPrioritizeTextures)
void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) WEAKGL;
static void (*p_glProgramBinary)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
static void w_glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) { if (p_glProgramBinary) p_glProgramBinary(program, binaryFormat, binary, length); }
INTERPOSE(glProgramBinary)
void glProgramParameteri(GLuint program, GLenum pname, GLint value) WEAKGL;
static void (*p_glProgramParameteri)(GLuint program, GLenum pname, GLint value);
static void w_glProgramParameteri(GLuint program, GLenum pname, GLint value) { if (p_glProgramParameteri) p_glProgramParameteri(program, pname, value); }
INTERPOSE(glProgramParameteri)
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0) WEAKGL;
static void (*p_glProgramUniform1d)(GLuint program, GLint location, GLdouble v0);
static void w_glProgramUniform1d(GLuint program, GLint location, GLdouble v0) { if (p_glProgramUniform1d) p_glProgramUniform1d(program, location, v0); }
INTERPOSE(glProgramUniform1d)
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform1dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (p_glProgramUniform1dv) p_glProgramUniform1dv(program, location, count, value); }
INTERPOSE(glProgramUniform1dv)
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) WEAKGL;
static void (*p_glProgramUniform1f)(GLuint program, GLint location, GLfloat v0);
static void w_glProgramUniform1f(GLuint program, GLint location, GLfloat v0) { if (p_glProgramUniform1f) p_glProgramUniform1f(program, location, v0); }
INTERPOSE(glProgramUniform1f)
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform1fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (p_glProgramUniform1fv) p_glProgramUniform1fv(program, location, count, value); }
INTERPOSE(glProgramUniform1fv)
void glProgramUniform1i(GLuint program, GLint location, GLint v0) WEAKGL;
static void (*p_glProgramUniform1i)(GLuint program, GLint location, GLint v0);
static void w_glProgramUniform1i(GLuint program, GLint location, GLint v0) { if (p_glProgramUniform1i) p_glProgramUniform1i(program, location, v0); }
INTERPOSE(glProgramUniform1i)
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform1iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (p_glProgramUniform1iv) p_glProgramUniform1iv(program, location, count, value); }
INTERPOSE(glProgramUniform1iv)
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) WEAKGL;
static void (*p_glProgramUniform1ui)(GLuint program, GLint location, GLuint v0);
static void w_glProgramUniform1ui(GLuint program, GLint location, GLuint v0) { if (p_glProgramUniform1ui) p_glProgramUniform1ui(program, location, v0); }
INTERPOSE(glProgramUniform1ui)
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform1uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (p_glProgramUniform1uiv) p_glProgramUniform1uiv(program, location, count, value); }
INTERPOSE(glProgramUniform1uiv)
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) WEAKGL;
static void (*p_glProgramUniform2d)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
static void w_glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) { if (p_glProgramUniform2d) p_glProgramUniform2d(program, location, v0, v1); }
INTERPOSE(glProgramUniform2d)
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform2dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (p_glProgramUniform2dv) p_glProgramUniform2dv(program, location, count, value); }
INTERPOSE(glProgramUniform2dv)
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) WEAKGL;
static void (*p_glProgramUniform2f)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
static void w_glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) { if (p_glProgramUniform2f) p_glProgramUniform2f(program, location, v0, v1); }
INTERPOSE(glProgramUniform2f)
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform2fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (p_glProgramUniform2fv) p_glProgramUniform2fv(program, location, count, value); }
INTERPOSE(glProgramUniform2fv)
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) WEAKGL;
static void (*p_glProgramUniform2i)(GLuint program, GLint location, GLint v0, GLint v1);
static void w_glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) { if (p_glProgramUniform2i) p_glProgramUniform2i(program, location, v0, v1); }
INTERPOSE(glProgramUniform2i)
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform2iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (p_glProgramUniform2iv) p_glProgramUniform2iv(program, location, count, value); }
INTERPOSE(glProgramUniform2iv)
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) WEAKGL;
static void (*p_glProgramUniform2ui)(GLuint program, GLint location, GLuint v0, GLuint v1);
static void w_glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) { if (p_glProgramUniform2ui) p_glProgramUniform2ui(program, location, v0, v1); }
INTERPOSE(glProgramUniform2ui)
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform2uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (p_glProgramUniform2uiv) p_glProgramUniform2uiv(program, location, count, value); }
INTERPOSE(glProgramUniform2uiv)
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) WEAKGL;
static void (*p_glProgramUniform3d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
static void w_glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) { if (p_glProgramUniform3d) p_glProgramUniform3d(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3d)
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform3dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (p_glProgramUniform3dv) p_glProgramUniform3dv(program, location, count, value); }
INTERPOSE(glProgramUniform3dv)
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) WEAKGL;
static void (*p_glProgramUniform3f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void w_glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { if (p_glProgramUniform3f) p_glProgramUniform3f(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3f)
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform3fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (p_glProgramUniform3fv) p_glProgramUniform3fv(program, location, count, value); }
INTERPOSE(glProgramUniform3fv)
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) WEAKGL;
static void (*p_glProgramUniform3i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
static void w_glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) { if (p_glProgramUniform3i) p_glProgramUniform3i(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3i)
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform3iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (p_glProgramUniform3iv) p_glProgramUniform3iv(program, location, count, value); }
INTERPOSE(glProgramUniform3iv)
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) WEAKGL;
static void (*p_glProgramUniform3ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
static void w_glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) { if (p_glProgramUniform3ui) p_glProgramUniform3ui(program, location, v0, v1, v2); }
INTERPOSE(glProgramUniform3ui)
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform3uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (p_glProgramUniform3uiv) p_glProgramUniform3uiv(program, location, count, value); }
INTERPOSE(glProgramUniform3uiv)
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) WEAKGL;
static void (*p_glProgramUniform4d)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
static void w_glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) { if (p_glProgramUniform4d) p_glProgramUniform4d(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4d)
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniform4dv)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
static void w_glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value) { if (p_glProgramUniform4dv) p_glProgramUniform4dv(program, location, count, value); }
INTERPOSE(glProgramUniform4dv)
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) WEAKGL;
static void (*p_glProgramUniform4f)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void w_glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { if (p_glProgramUniform4f) p_glProgramUniform4f(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4f)
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniform4fv)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
static void w_glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value) { if (p_glProgramUniform4fv) p_glProgramUniform4fv(program, location, count, value); }
INTERPOSE(glProgramUniform4fv)
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) WEAKGL;
static void (*p_glProgramUniform4i)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void w_glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { if (p_glProgramUniform4i) p_glProgramUniform4i(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4i)
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glProgramUniform4iv)(GLuint program, GLint location, GLsizei count, const GLint *value);
static void w_glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value) { if (p_glProgramUniform4iv) p_glProgramUniform4iv(program, location, count, value); }
INTERPOSE(glProgramUniform4iv)
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) WEAKGL;
static void (*p_glProgramUniform4ui)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void w_glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { if (p_glProgramUniform4ui) p_glProgramUniform4ui(program, location, v0, v1, v2, v3); }
INTERPOSE(glProgramUniform4ui)
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glProgramUniform4uiv)(GLuint program, GLint location, GLsizei count, const GLuint *value);
static void w_glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value) { if (p_glProgramUniform4uiv) p_glProgramUniform4uiv(program, location, count, value); }
INTERPOSE(glProgramUniform4uiv)
void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix2dv) p_glProgramUniformMatrix2dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2dv)
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix2fv) p_glProgramUniformMatrix2fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2fv)
void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix2x3dv) p_glProgramUniformMatrix2x3dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x3dv)
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix2x3fv) p_glProgramUniformMatrix2x3fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x3fv)
void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix2x4dv) p_glProgramUniformMatrix2x4dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x4dv)
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix2x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix2x4fv) p_glProgramUniformMatrix2x4fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix2x4fv)
void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix3dv) p_glProgramUniformMatrix3dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3dv)
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix3fv) p_glProgramUniformMatrix3fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3fv)
void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix3x2dv) p_glProgramUniformMatrix3x2dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x2dv)
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix3x2fv) p_glProgramUniformMatrix3x2fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x2fv)
void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix3x4dv) p_glProgramUniformMatrix3x4dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x4dv)
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix3x4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix3x4fv) p_glProgramUniformMatrix3x4fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix3x4fv)
void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix4dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix4dv) p_glProgramUniformMatrix4dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4dv)
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix4fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix4fv) p_glProgramUniformMatrix4fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4fv)
void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x2dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix4x2dv) p_glProgramUniformMatrix4x2dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x2dv)
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x2fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix4x2fv) p_glProgramUniformMatrix4x2fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x2fv)
void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x3dv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glProgramUniformMatrix4x3dv) p_glProgramUniformMatrix4x3dv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x3dv)
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glProgramUniformMatrix4x3fv)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glProgramUniformMatrix4x3fv) p_glProgramUniformMatrix4x3fv(program, location, count, transpose, value); }
INTERPOSE(glProgramUniformMatrix4x3fv)
void glProvokingVertex(GLenum mode) WEAKGL;
static void (*p_glProvokingVertex)(GLenum mode);
static void w_glProvokingVertex(GLenum mode) { if (p_glProvokingVertex) p_glProvokingVertex(mode); }
INTERPOSE(glProvokingVertex)
void glPushAttrib(GLbitfield mask) WEAKGL;
static void (*p_glPushAttrib)(GLbitfield mask);
static void w_glPushAttrib(GLbitfield mask) { if (p_glPushAttrib) p_glPushAttrib(mask); }
INTERPOSE(glPushAttrib)
void glPushClientAttrib(GLbitfield mask) WEAKGL;
static void (*p_glPushClientAttrib)(GLbitfield mask);
static void w_glPushClientAttrib(GLbitfield mask) { if (p_glPushClientAttrib) p_glPushClientAttrib(mask); }
INTERPOSE(glPushClientAttrib)
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) WEAKGL;
static void (*p_glPushDebugGroup)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
static void w_glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar *message) { if (p_glPushDebugGroup) p_glPushDebugGroup(source, id, length, message); }
INTERPOSE(glPushDebugGroup)
void glPushMatrix(void) WEAKGL;
static void (*p_glPushMatrix)(void);
static void w_glPushMatrix(void) { if (p_glPushMatrix) p_glPushMatrix(); }
INTERPOSE(glPushMatrix)
void glPushName(GLuint name) WEAKGL;
static void (*p_glPushName)(GLuint name);
static void w_glPushName(GLuint name) { if (p_glPushName) p_glPushName(name); }
INTERPOSE(glPushName)
void glQueryCounter(GLuint id, GLenum target) WEAKGL;
static void (*p_glQueryCounter)(GLuint id, GLenum target);
static void w_glQueryCounter(GLuint id, GLenum target) { if (p_glQueryCounter) p_glQueryCounter(id, target); }
INTERPOSE(glQueryCounter)
void glRasterPos2d(GLdouble x, GLdouble y) WEAKGL;
static void (*p_glRasterPos2d)(GLdouble x, GLdouble y);
static void w_glRasterPos2d(GLdouble x, GLdouble y) { if (p_glRasterPos2d) p_glRasterPos2d(x, y); }
INTERPOSE(glRasterPos2d)
void glRasterPos2dv(const GLdouble *v) WEAKGL;
static void (*p_glRasterPos2dv)(const GLdouble *v);
static void w_glRasterPos2dv(const GLdouble *v) { if (p_glRasterPos2dv) p_glRasterPos2dv(v); }
INTERPOSE(glRasterPos2dv)
void glRasterPos2f(GLfloat x, GLfloat y) WEAKGL;
static void (*p_glRasterPos2f)(GLfloat x, GLfloat y);
static void w_glRasterPos2f(GLfloat x, GLfloat y) { if (p_glRasterPos2f) p_glRasterPos2f(x, y); }
INTERPOSE(glRasterPos2f)
void glRasterPos2fv(const GLfloat *v) WEAKGL;
static void (*p_glRasterPos2fv)(const GLfloat *v);
static void w_glRasterPos2fv(const GLfloat *v) { if (p_glRasterPos2fv) p_glRasterPos2fv(v); }
INTERPOSE(glRasterPos2fv)
void glRasterPos2i(GLint x, GLint y) WEAKGL;
static void (*p_glRasterPos2i)(GLint x, GLint y);
static void w_glRasterPos2i(GLint x, GLint y) { if (p_glRasterPos2i) p_glRasterPos2i(x, y); }
INTERPOSE(glRasterPos2i)
void glRasterPos2iv(const GLint *v) WEAKGL;
static void (*p_glRasterPos2iv)(const GLint *v);
static void w_glRasterPos2iv(const GLint *v) { if (p_glRasterPos2iv) p_glRasterPos2iv(v); }
INTERPOSE(glRasterPos2iv)
void glRasterPos2s(GLshort x, GLshort y) WEAKGL;
static void (*p_glRasterPos2s)(GLshort x, GLshort y);
static void w_glRasterPos2s(GLshort x, GLshort y) { if (p_glRasterPos2s) p_glRasterPos2s(x, y); }
INTERPOSE(glRasterPos2s)
void glRasterPos2sv(const GLshort *v) WEAKGL;
static void (*p_glRasterPos2sv)(const GLshort *v);
static void w_glRasterPos2sv(const GLshort *v) { if (p_glRasterPos2sv) p_glRasterPos2sv(v); }
INTERPOSE(glRasterPos2sv)
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glRasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
static void w_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) { if (p_glRasterPos3d) p_glRasterPos3d(x, y, z); }
INTERPOSE(glRasterPos3d)
void glRasterPos3dv(const GLdouble *v) WEAKGL;
static void (*p_glRasterPos3dv)(const GLdouble *v);
static void w_glRasterPos3dv(const GLdouble *v) { if (p_glRasterPos3dv) p_glRasterPos3dv(v); }
INTERPOSE(glRasterPos3dv)
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glRasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
static void w_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) { if (p_glRasterPos3f) p_glRasterPos3f(x, y, z); }
INTERPOSE(glRasterPos3f)
void glRasterPos3fv(const GLfloat *v) WEAKGL;
static void (*p_glRasterPos3fv)(const GLfloat *v);
static void w_glRasterPos3fv(const GLfloat *v) { if (p_glRasterPos3fv) p_glRasterPos3fv(v); }
INTERPOSE(glRasterPos3fv)
void glRasterPos3i(GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glRasterPos3i)(GLint x, GLint y, GLint z);
static void w_glRasterPos3i(GLint x, GLint y, GLint z) { if (p_glRasterPos3i) p_glRasterPos3i(x, y, z); }
INTERPOSE(glRasterPos3i)
void glRasterPos3iv(const GLint *v) WEAKGL;
static void (*p_glRasterPos3iv)(const GLint *v);
static void w_glRasterPos3iv(const GLint *v) { if (p_glRasterPos3iv) p_glRasterPos3iv(v); }
INTERPOSE(glRasterPos3iv)
void glRasterPos3s(GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glRasterPos3s)(GLshort x, GLshort y, GLshort z);
static void w_glRasterPos3s(GLshort x, GLshort y, GLshort z) { if (p_glRasterPos3s) p_glRasterPos3s(x, y, z); }
INTERPOSE(glRasterPos3s)
void glRasterPos3sv(const GLshort *v) WEAKGL;
static void (*p_glRasterPos3sv)(const GLshort *v);
static void w_glRasterPos3sv(const GLshort *v) { if (p_glRasterPos3sv) p_glRasterPos3sv(v); }
INTERPOSE(glRasterPos3sv)
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (p_glRasterPos4d) p_glRasterPos4d(x, y, z, w); }
INTERPOSE(glRasterPos4d)
void glRasterPos4dv(const GLdouble *v) WEAKGL;
static void (*p_glRasterPos4dv)(const GLdouble *v);
static void w_glRasterPos4dv(const GLdouble *v) { if (p_glRasterPos4dv) p_glRasterPos4dv(v); }
INTERPOSE(glRasterPos4dv)
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) WEAKGL;
static void (*p_glRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void w_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if (p_glRasterPos4f) p_glRasterPos4f(x, y, z, w); }
INTERPOSE(glRasterPos4f)
void glRasterPos4fv(const GLfloat *v) WEAKGL;
static void (*p_glRasterPos4fv)(const GLfloat *v);
static void w_glRasterPos4fv(const GLfloat *v) { if (p_glRasterPos4fv) p_glRasterPos4fv(v); }
INTERPOSE(glRasterPos4fv)
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) WEAKGL;
static void (*p_glRasterPos4i)(GLint x, GLint y, GLint z, GLint w);
static void w_glRasterPos4i(GLint x, GLint y, GLint z, GLint w) { if (p_glRasterPos4i) p_glRasterPos4i(x, y, z, w); }
INTERPOSE(glRasterPos4i)
void glRasterPos4iv(const GLint *v) WEAKGL;
static void (*p_glRasterPos4iv)(const GLint *v);
static void w_glRasterPos4iv(const GLint *v) { if (p_glRasterPos4iv) p_glRasterPos4iv(v); }
INTERPOSE(glRasterPos4iv)
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) WEAKGL;
static void (*p_glRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
static void w_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) { if (p_glRasterPos4s) p_glRasterPos4s(x, y, z, w); }
INTERPOSE(glRasterPos4s)
void glRasterPos4sv(const GLshort *v) WEAKGL;
static void (*p_glRasterPos4sv)(const GLshort *v);
static void w_glRasterPos4sv(const GLshort *v) { if (p_glRasterPos4sv) p_glRasterPos4sv(v); }
INTERPOSE(glRasterPos4sv)
void glReadBuffer(GLenum src) WEAKGL;
static void (*p_glReadBuffer)(GLenum src);
static void w_glReadBuffer(GLenum src) { if (p_glReadBuffer) p_glReadBuffer(src); }
INTERPOSE(glReadBuffer)
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) WEAKGL;
static void (*p_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
static void w_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels) { if (p_glReadPixels) p_glReadPixels(x, y, width, height, format, type, pixels); }
INTERPOSE(glReadPixels)
void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) WEAKGL;
static void (*p_glReadnPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
static void w_glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) { if (p_glReadnPixels) p_glReadnPixels(x, y, width, height, format, type, bufSize, data); }
INTERPOSE(glReadnPixels)
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) WEAKGL;
static void (*p_glRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
static void w_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) { if (p_glRectd) p_glRectd(x1, y1, x2, y2); }
INTERPOSE(glRectd)
void glRectdv(const GLdouble *v1, const GLdouble *v2) WEAKGL;
static void (*p_glRectdv)(const GLdouble *v1, const GLdouble *v2);
static void w_glRectdv(const GLdouble *v1, const GLdouble *v2) { if (p_glRectdv) p_glRectdv(v1, v2); }
INTERPOSE(glRectdv)
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) WEAKGL;
static void (*p_glRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
static void w_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) { if (p_glRectf) p_glRectf(x1, y1, x2, y2); }
INTERPOSE(glRectf)
void glRectfv(const GLfloat *v1, const GLfloat *v2) WEAKGL;
static void (*p_glRectfv)(const GLfloat *v1, const GLfloat *v2);
static void w_glRectfv(const GLfloat *v1, const GLfloat *v2) { if (p_glRectfv) p_glRectfv(v1, v2); }
INTERPOSE(glRectfv)
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) WEAKGL;
static void (*p_glRecti)(GLint x1, GLint y1, GLint x2, GLint y2);
static void w_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) { if (p_glRecti) p_glRecti(x1, y1, x2, y2); }
INTERPOSE(glRecti)
void glRectiv(const GLint *v1, const GLint *v2) WEAKGL;
static void (*p_glRectiv)(const GLint *v1, const GLint *v2);
static void w_glRectiv(const GLint *v1, const GLint *v2) { if (p_glRectiv) p_glRectiv(v1, v2); }
INTERPOSE(glRectiv)
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) WEAKGL;
static void (*p_glRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
static void w_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) { if (p_glRects) p_glRects(x1, y1, x2, y2); }
INTERPOSE(glRects)
void glRectsv(const GLshort *v1, const GLshort *v2) WEAKGL;
static void (*p_glRectsv)(const GLshort *v1, const GLshort *v2);
static void w_glRectsv(const GLshort *v1, const GLshort *v2) { if (p_glRectsv) p_glRectsv(v1, v2); }
INTERPOSE(glRectsv)
void glReleaseShaderCompiler(void) WEAKGL;
static void (*p_glReleaseShaderCompiler)(void);
static void w_glReleaseShaderCompiler(void) { if (p_glReleaseShaderCompiler) p_glReleaseShaderCompiler(); }
INTERPOSE(glReleaseShaderCompiler)
GLint glRenderMode(GLenum mode) WEAKGL;
static GLint (*p_glRenderMode)(GLenum mode);
static GLint w_glRenderMode(GLenum mode) { if (!p_glRenderMode) return (GLint)0; return p_glRenderMode(mode); }
INTERPOSE(glRenderMode)
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { if (p_glRenderbufferStorage) p_glRenderbufferStorage(target, internalformat, width, height); }
INTERPOSE(glRenderbufferStorage)
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) { if (p_glRenderbufferStorageMultisample) p_glRenderbufferStorageMultisample(target, samples, internalformat, width, height); }
INTERPOSE(glRenderbufferStorageMultisample)
void glResumeTransformFeedback(void) WEAKGL;
static void (*p_glResumeTransformFeedback)(void);
static void w_glResumeTransformFeedback(void) { if (p_glResumeTransformFeedback) p_glResumeTransformFeedback(); }
INTERPOSE(glResumeTransformFeedback)
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
static void w_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) { if (p_glRotated) p_glRotated(angle, x, y, z); }
INTERPOSE(glRotated)
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
static void w_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) { if (p_glRotatef) p_glRotatef(angle, x, y, z); }
INTERPOSE(glRotatef)
void glSampleCoverage(GLfloat value, GLboolean invert) WEAKGL;
static void (*p_glSampleCoverage)(GLfloat value, GLboolean invert);
static void w_glSampleCoverage(GLfloat value, GLboolean invert) { if (p_glSampleCoverage) p_glSampleCoverage(value, invert); }
INTERPOSE(glSampleCoverage)
void glSampleMaski(GLuint maskNumber, GLbitfield mask) WEAKGL;
static void (*p_glSampleMaski)(GLuint maskNumber, GLbitfield mask);
static void w_glSampleMaski(GLuint maskNumber, GLbitfield mask) { if (p_glSampleMaski) p_glSampleMaski(maskNumber, mask); }
INTERPOSE(glSampleMaski)
void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) WEAKGL;
static void (*p_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint *param);
static void w_glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param) { if (p_glSamplerParameterIiv) p_glSamplerParameterIiv(sampler, pname, param); }
INTERPOSE(glSamplerParameterIiv)
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) WEAKGL;
static void (*p_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint *param);
static void w_glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param) { if (p_glSamplerParameterIuiv) p_glSamplerParameterIuiv(sampler, pname, param); }
INTERPOSE(glSamplerParameterIuiv)
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param);
static void w_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) { if (p_glSamplerParameterf) p_glSamplerParameterf(sampler, pname, param); }
INTERPOSE(glSamplerParameterf)
void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) WEAKGL;
static void (*p_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat *param);
static void w_glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param) { if (p_glSamplerParameterfv) p_glSamplerParameterfv(sampler, pname, param); }
INTERPOSE(glSamplerParameterfv)
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) WEAKGL;
static void (*p_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param);
static void w_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) { if (p_glSamplerParameteri) p_glSamplerParameteri(sampler, pname, param); }
INTERPOSE(glSamplerParameteri)
void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) WEAKGL;
static void (*p_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint *param);
static void w_glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param) { if (p_glSamplerParameteriv) p_glSamplerParameteriv(sampler, pname, param); }
INTERPOSE(glSamplerParameteriv)
void glScaled(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glScaled)(GLdouble x, GLdouble y, GLdouble z);
static void w_glScaled(GLdouble x, GLdouble y, GLdouble z) { if (p_glScaled) p_glScaled(x, y, z); }
INTERPOSE(glScaled)
void glScalef(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glScalef)(GLfloat x, GLfloat y, GLfloat z);
static void w_glScalef(GLfloat x, GLfloat y, GLfloat z) { if (p_glScalef) p_glScalef(x, y, z); }
INTERPOSE(glScalef)
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glScissor) p_glScissor(x, y, width, height); }
INTERPOSE(glScissor)
void glScissorArrayv(GLuint first, GLsizei count, const GLint *v) WEAKGL;
static void (*p_glScissorArrayv)(GLuint first, GLsizei count, const GLint *v);
static void w_glScissorArrayv(GLuint first, GLsizei count, const GLint *v) { if (p_glScissorArrayv) p_glScissorArrayv(first, count, v); }
INTERPOSE(glScissorArrayv)
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glScissorIndexed)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
static void w_glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) { if (p_glScissorIndexed) p_glScissorIndexed(index, left, bottom, width, height); }
INTERPOSE(glScissorIndexed)
void glScissorIndexedv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glScissorIndexedv)(GLuint index, const GLint *v);
static void w_glScissorIndexedv(GLuint index, const GLint *v) { if (p_glScissorIndexedv) p_glScissorIndexedv(index, v); }
INTERPOSE(glScissorIndexedv)
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) WEAKGL;
static void (*p_glSecondaryColor3b)(GLbyte red, GLbyte green, GLbyte blue);
static void w_glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) { if (p_glSecondaryColor3b) p_glSecondaryColor3b(red, green, blue); }
INTERPOSE(glSecondaryColor3b)
void glSecondaryColor3bv(const GLbyte *v) WEAKGL;
static void (*p_glSecondaryColor3bv)(const GLbyte *v);
static void w_glSecondaryColor3bv(const GLbyte *v) { if (p_glSecondaryColor3bv) p_glSecondaryColor3bv(v); }
INTERPOSE(glSecondaryColor3bv)
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) WEAKGL;
static void (*p_glSecondaryColor3d)(GLdouble red, GLdouble green, GLdouble blue);
static void w_glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) { if (p_glSecondaryColor3d) p_glSecondaryColor3d(red, green, blue); }
INTERPOSE(glSecondaryColor3d)
void glSecondaryColor3dv(const GLdouble *v) WEAKGL;
static void (*p_glSecondaryColor3dv)(const GLdouble *v);
static void w_glSecondaryColor3dv(const GLdouble *v) { if (p_glSecondaryColor3dv) p_glSecondaryColor3dv(v); }
INTERPOSE(glSecondaryColor3dv)
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) WEAKGL;
static void (*p_glSecondaryColor3f)(GLfloat red, GLfloat green, GLfloat blue);
static void w_glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) { if (p_glSecondaryColor3f) p_glSecondaryColor3f(red, green, blue); }
INTERPOSE(glSecondaryColor3f)
void glSecondaryColor3fv(const GLfloat *v) WEAKGL;
static void (*p_glSecondaryColor3fv)(const GLfloat *v);
static void w_glSecondaryColor3fv(const GLfloat *v) { if (p_glSecondaryColor3fv) p_glSecondaryColor3fv(v); }
INTERPOSE(glSecondaryColor3fv)
void glSecondaryColor3i(GLint red, GLint green, GLint blue) WEAKGL;
static void (*p_glSecondaryColor3i)(GLint red, GLint green, GLint blue);
static void w_glSecondaryColor3i(GLint red, GLint green, GLint blue) { if (p_glSecondaryColor3i) p_glSecondaryColor3i(red, green, blue); }
INTERPOSE(glSecondaryColor3i)
void glSecondaryColor3iv(const GLint *v) WEAKGL;
static void (*p_glSecondaryColor3iv)(const GLint *v);
static void w_glSecondaryColor3iv(const GLint *v) { if (p_glSecondaryColor3iv) p_glSecondaryColor3iv(v); }
INTERPOSE(glSecondaryColor3iv)
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) WEAKGL;
static void (*p_glSecondaryColor3s)(GLshort red, GLshort green, GLshort blue);
static void w_glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) { if (p_glSecondaryColor3s) p_glSecondaryColor3s(red, green, blue); }
INTERPOSE(glSecondaryColor3s)
void glSecondaryColor3sv(const GLshort *v) WEAKGL;
static void (*p_glSecondaryColor3sv)(const GLshort *v);
static void w_glSecondaryColor3sv(const GLshort *v) { if (p_glSecondaryColor3sv) p_glSecondaryColor3sv(v); }
INTERPOSE(glSecondaryColor3sv)
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) WEAKGL;
static void (*p_glSecondaryColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
static void w_glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) { if (p_glSecondaryColor3ub) p_glSecondaryColor3ub(red, green, blue); }
INTERPOSE(glSecondaryColor3ub)
void glSecondaryColor3ubv(const GLubyte *v) WEAKGL;
static void (*p_glSecondaryColor3ubv)(const GLubyte *v);
static void w_glSecondaryColor3ubv(const GLubyte *v) { if (p_glSecondaryColor3ubv) p_glSecondaryColor3ubv(v); }
INTERPOSE(glSecondaryColor3ubv)
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) WEAKGL;
static void (*p_glSecondaryColor3ui)(GLuint red, GLuint green, GLuint blue);
static void w_glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) { if (p_glSecondaryColor3ui) p_glSecondaryColor3ui(red, green, blue); }
INTERPOSE(glSecondaryColor3ui)
void glSecondaryColor3uiv(const GLuint *v) WEAKGL;
static void (*p_glSecondaryColor3uiv)(const GLuint *v);
static void w_glSecondaryColor3uiv(const GLuint *v) { if (p_glSecondaryColor3uiv) p_glSecondaryColor3uiv(v); }
INTERPOSE(glSecondaryColor3uiv)
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) WEAKGL;
static void (*p_glSecondaryColor3us)(GLushort red, GLushort green, GLushort blue);
static void w_glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) { if (p_glSecondaryColor3us) p_glSecondaryColor3us(red, green, blue); }
INTERPOSE(glSecondaryColor3us)
void glSecondaryColor3usv(const GLushort *v) WEAKGL;
static void (*p_glSecondaryColor3usv)(const GLushort *v);
static void w_glSecondaryColor3usv(const GLushort *v) { if (p_glSecondaryColor3usv) p_glSecondaryColor3usv(v); }
INTERPOSE(glSecondaryColor3usv)
void glSecondaryColorP3ui(GLenum type, GLuint color) WEAKGL;
static void (*p_glSecondaryColorP3ui)(GLenum type, GLuint color);
static void w_glSecondaryColorP3ui(GLenum type, GLuint color) { if (p_glSecondaryColorP3ui) p_glSecondaryColorP3ui(type, color); }
INTERPOSE(glSecondaryColorP3ui)
void glSecondaryColorP3uiv(GLenum type, const GLuint *color) WEAKGL;
static void (*p_glSecondaryColorP3uiv)(GLenum type, const GLuint *color);
static void w_glSecondaryColorP3uiv(GLenum type, const GLuint *color) { if (p_glSecondaryColorP3uiv) p_glSecondaryColorP3uiv(type, color); }
INTERPOSE(glSecondaryColorP3uiv)
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glSecondaryColorPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (p_glSecondaryColorPointer) p_glSecondaryColorPointer(size, type, stride, pointer); }
INTERPOSE(glSecondaryColorPointer)
void glSelectBuffer(GLsizei size, GLuint *buffer) WEAKGL;
static void (*p_glSelectBuffer)(GLsizei size, GLuint *buffer);
static void w_glSelectBuffer(GLsizei size, GLuint *buffer) { if (p_glSelectBuffer) p_glSelectBuffer(size, buffer); }
INTERPOSE(glSelectBuffer)
void glShadeModel(GLenum mode) WEAKGL;
static void (*p_glShadeModel)(GLenum mode);
static void w_glShadeModel(GLenum mode) { if (p_glShadeModel) p_glShadeModel(mode); }
INTERPOSE(glShadeModel)
void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length) WEAKGL;
static void (*p_glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
static void w_glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length) { if (p_glShaderBinary) p_glShaderBinary(count, shaders, binaryFormat, binary, length); }
INTERPOSE(glShaderBinary)
void glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) WEAKGL;
static void (*p_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
static void w_glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) { if (p_glShaderSource) p_glShaderSource(shader, count, string, length); }
INTERPOSE(glShaderSource)
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) WEAKGL;
static void (*p_glShaderStorageBlockBinding)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
static void w_glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) { if (p_glShaderStorageBlockBinding) p_glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding); }
INTERPOSE(glShaderStorageBlockBinding)
void glSpecializeShader(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) WEAKGL;
static void (*p_glSpecializeShader)(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
static void w_glSpecializeShader(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) { if (p_glSpecializeShader) p_glSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue); }
INTERPOSE(glSpecializeShader)
void glStencilFunc(GLenum func, GLint ref, GLuint mask) WEAKGL;
static void (*p_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
static void w_glStencilFunc(GLenum func, GLint ref, GLuint mask) { if (p_glStencilFunc) p_glStencilFunc(func, ref, mask); }
INTERPOSE(glStencilFunc)
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) WEAKGL;
static void (*p_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
static void w_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { if (p_glStencilFuncSeparate) p_glStencilFuncSeparate(face, func, ref, mask); }
INTERPOSE(glStencilFuncSeparate)
void glStencilMask(GLuint mask) WEAKGL;
static void (*p_glStencilMask)(GLuint mask);
static void w_glStencilMask(GLuint mask) { if (p_glStencilMask) p_glStencilMask(mask); }
INTERPOSE(glStencilMask)
void glStencilMaskSeparate(GLenum face, GLuint mask) WEAKGL;
static void (*p_glStencilMaskSeparate)(GLenum face, GLuint mask);
static void w_glStencilMaskSeparate(GLenum face, GLuint mask) { if (p_glStencilMaskSeparate) p_glStencilMaskSeparate(face, mask); }
INTERPOSE(glStencilMaskSeparate)
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) WEAKGL;
static void (*p_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
static void w_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) { if (p_glStencilOp) p_glStencilOp(fail, zfail, zpass); }
INTERPOSE(glStencilOp)
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) WEAKGL;
static void (*p_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
static void w_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { if (p_glStencilOpSeparate) p_glStencilOpSeparate(face, sfail, dpfail, dppass); }
INTERPOSE(glStencilOpSeparate)
void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) WEAKGL;
static void (*p_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
static void w_glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { if (p_glTexBuffer) p_glTexBuffer(target, internalformat, buffer); }
INTERPOSE(glTexBuffer)
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glTexBufferRange)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (p_glTexBufferRange) p_glTexBufferRange(target, internalformat, buffer, offset, size); }
INTERPOSE(glTexBufferRange)
void glTexCoord1d(GLdouble s) WEAKGL;
static void (*p_glTexCoord1d)(GLdouble s);
static void w_glTexCoord1d(GLdouble s) { if (p_glTexCoord1d) p_glTexCoord1d(s); }
INTERPOSE(glTexCoord1d)
void glTexCoord1dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord1dv)(const GLdouble *v);
static void w_glTexCoord1dv(const GLdouble *v) { if (p_glTexCoord1dv) p_glTexCoord1dv(v); }
INTERPOSE(glTexCoord1dv)
void glTexCoord1f(GLfloat s) WEAKGL;
static void (*p_glTexCoord1f)(GLfloat s);
static void w_glTexCoord1f(GLfloat s) { if (p_glTexCoord1f) p_glTexCoord1f(s); }
INTERPOSE(glTexCoord1f)
void glTexCoord1fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord1fv)(const GLfloat *v);
static void w_glTexCoord1fv(const GLfloat *v) { if (p_glTexCoord1fv) p_glTexCoord1fv(v); }
INTERPOSE(glTexCoord1fv)
void glTexCoord1i(GLint s) WEAKGL;
static void (*p_glTexCoord1i)(GLint s);
static void w_glTexCoord1i(GLint s) { if (p_glTexCoord1i) p_glTexCoord1i(s); }
INTERPOSE(glTexCoord1i)
void glTexCoord1iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord1iv)(const GLint *v);
static void w_glTexCoord1iv(const GLint *v) { if (p_glTexCoord1iv) p_glTexCoord1iv(v); }
INTERPOSE(glTexCoord1iv)
void glTexCoord1s(GLshort s) WEAKGL;
static void (*p_glTexCoord1s)(GLshort s);
static void w_glTexCoord1s(GLshort s) { if (p_glTexCoord1s) p_glTexCoord1s(s); }
INTERPOSE(glTexCoord1s)
void glTexCoord1sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord1sv)(const GLshort *v);
static void w_glTexCoord1sv(const GLshort *v) { if (p_glTexCoord1sv) p_glTexCoord1sv(v); }
INTERPOSE(glTexCoord1sv)
void glTexCoord2d(GLdouble s, GLdouble t) WEAKGL;
static void (*p_glTexCoord2d)(GLdouble s, GLdouble t);
static void w_glTexCoord2d(GLdouble s, GLdouble t) { if (p_glTexCoord2d) p_glTexCoord2d(s, t); }
INTERPOSE(glTexCoord2d)
void glTexCoord2dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord2dv)(const GLdouble *v);
static void w_glTexCoord2dv(const GLdouble *v) { if (p_glTexCoord2dv) p_glTexCoord2dv(v); }
INTERPOSE(glTexCoord2dv)
void glTexCoord2f(GLfloat s, GLfloat t) WEAKGL;
static void (*p_glTexCoord2f)(GLfloat s, GLfloat t);
static void w_glTexCoord2f(GLfloat s, GLfloat t) { if (p_glTexCoord2f) p_glTexCoord2f(s, t); }
INTERPOSE(glTexCoord2f)
void glTexCoord2fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord2fv)(const GLfloat *v);
static void w_glTexCoord2fv(const GLfloat *v) { if (p_glTexCoord2fv) p_glTexCoord2fv(v); }
INTERPOSE(glTexCoord2fv)
void glTexCoord2i(GLint s, GLint t) WEAKGL;
static void (*p_glTexCoord2i)(GLint s, GLint t);
static void w_glTexCoord2i(GLint s, GLint t) { if (p_glTexCoord2i) p_glTexCoord2i(s, t); }
INTERPOSE(glTexCoord2i)
void glTexCoord2iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord2iv)(const GLint *v);
static void w_glTexCoord2iv(const GLint *v) { if (p_glTexCoord2iv) p_glTexCoord2iv(v); }
INTERPOSE(glTexCoord2iv)
void glTexCoord2s(GLshort s, GLshort t) WEAKGL;
static void (*p_glTexCoord2s)(GLshort s, GLshort t);
static void w_glTexCoord2s(GLshort s, GLshort t) { if (p_glTexCoord2s) p_glTexCoord2s(s, t); }
INTERPOSE(glTexCoord2s)
void glTexCoord2sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord2sv)(const GLshort *v);
static void w_glTexCoord2sv(const GLshort *v) { if (p_glTexCoord2sv) p_glTexCoord2sv(v); }
INTERPOSE(glTexCoord2sv)
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) WEAKGL;
static void (*p_glTexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
static void w_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) { if (p_glTexCoord3d) p_glTexCoord3d(s, t, r); }
INTERPOSE(glTexCoord3d)
void glTexCoord3dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord3dv)(const GLdouble *v);
static void w_glTexCoord3dv(const GLdouble *v) { if (p_glTexCoord3dv) p_glTexCoord3dv(v); }
INTERPOSE(glTexCoord3dv)
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) WEAKGL;
static void (*p_glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
static void w_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) { if (p_glTexCoord3f) p_glTexCoord3f(s, t, r); }
INTERPOSE(glTexCoord3f)
void glTexCoord3fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord3fv)(const GLfloat *v);
static void w_glTexCoord3fv(const GLfloat *v) { if (p_glTexCoord3fv) p_glTexCoord3fv(v); }
INTERPOSE(glTexCoord3fv)
void glTexCoord3i(GLint s, GLint t, GLint r) WEAKGL;
static void (*p_glTexCoord3i)(GLint s, GLint t, GLint r);
static void w_glTexCoord3i(GLint s, GLint t, GLint r) { if (p_glTexCoord3i) p_glTexCoord3i(s, t, r); }
INTERPOSE(glTexCoord3i)
void glTexCoord3iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord3iv)(const GLint *v);
static void w_glTexCoord3iv(const GLint *v) { if (p_glTexCoord3iv) p_glTexCoord3iv(v); }
INTERPOSE(glTexCoord3iv)
void glTexCoord3s(GLshort s, GLshort t, GLshort r) WEAKGL;
static void (*p_glTexCoord3s)(GLshort s, GLshort t, GLshort r);
static void w_glTexCoord3s(GLshort s, GLshort t, GLshort r) { if (p_glTexCoord3s) p_glTexCoord3s(s, t, r); }
INTERPOSE(glTexCoord3s)
void glTexCoord3sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord3sv)(const GLshort *v);
static void w_glTexCoord3sv(const GLshort *v) { if (p_glTexCoord3sv) p_glTexCoord3sv(v); }
INTERPOSE(glTexCoord3sv)
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) WEAKGL;
static void (*p_glTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
static void w_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) { if (p_glTexCoord4d) p_glTexCoord4d(s, t, r, q); }
INTERPOSE(glTexCoord4d)
void glTexCoord4dv(const GLdouble *v) WEAKGL;
static void (*p_glTexCoord4dv)(const GLdouble *v);
static void w_glTexCoord4dv(const GLdouble *v) { if (p_glTexCoord4dv) p_glTexCoord4dv(v); }
INTERPOSE(glTexCoord4dv)
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) WEAKGL;
static void (*p_glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void w_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) { if (p_glTexCoord4f) p_glTexCoord4f(s, t, r, q); }
INTERPOSE(glTexCoord4f)
void glTexCoord4fv(const GLfloat *v) WEAKGL;
static void (*p_glTexCoord4fv)(const GLfloat *v);
static void w_glTexCoord4fv(const GLfloat *v) { if (p_glTexCoord4fv) p_glTexCoord4fv(v); }
INTERPOSE(glTexCoord4fv)
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) WEAKGL;
static void (*p_glTexCoord4i)(GLint s, GLint t, GLint r, GLint q);
static void w_glTexCoord4i(GLint s, GLint t, GLint r, GLint q) { if (p_glTexCoord4i) p_glTexCoord4i(s, t, r, q); }
INTERPOSE(glTexCoord4i)
void glTexCoord4iv(const GLint *v) WEAKGL;
static void (*p_glTexCoord4iv)(const GLint *v);
static void w_glTexCoord4iv(const GLint *v) { if (p_glTexCoord4iv) p_glTexCoord4iv(v); }
INTERPOSE(glTexCoord4iv)
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) WEAKGL;
static void (*p_glTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
static void w_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) { if (p_glTexCoord4s) p_glTexCoord4s(s, t, r, q); }
INTERPOSE(glTexCoord4s)
void glTexCoord4sv(const GLshort *v) WEAKGL;
static void (*p_glTexCoord4sv)(const GLshort *v);
static void w_glTexCoord4sv(const GLshort *v) { if (p_glTexCoord4sv) p_glTexCoord4sv(v); }
INTERPOSE(glTexCoord4sv)
void glTexCoordP1ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP1ui)(GLenum type, GLuint coords);
static void w_glTexCoordP1ui(GLenum type, GLuint coords) { if (p_glTexCoordP1ui) p_glTexCoordP1ui(type, coords); }
INTERPOSE(glTexCoordP1ui)
void glTexCoordP1uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP1uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP1uiv(GLenum type, const GLuint *coords) { if (p_glTexCoordP1uiv) p_glTexCoordP1uiv(type, coords); }
INTERPOSE(glTexCoordP1uiv)
void glTexCoordP2ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP2ui)(GLenum type, GLuint coords);
static void w_glTexCoordP2ui(GLenum type, GLuint coords) { if (p_glTexCoordP2ui) p_glTexCoordP2ui(type, coords); }
INTERPOSE(glTexCoordP2ui)
void glTexCoordP2uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP2uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP2uiv(GLenum type, const GLuint *coords) { if (p_glTexCoordP2uiv) p_glTexCoordP2uiv(type, coords); }
INTERPOSE(glTexCoordP2uiv)
void glTexCoordP3ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP3ui)(GLenum type, GLuint coords);
static void w_glTexCoordP3ui(GLenum type, GLuint coords) { if (p_glTexCoordP3ui) p_glTexCoordP3ui(type, coords); }
INTERPOSE(glTexCoordP3ui)
void glTexCoordP3uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP3uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP3uiv(GLenum type, const GLuint *coords) { if (p_glTexCoordP3uiv) p_glTexCoordP3uiv(type, coords); }
INTERPOSE(glTexCoordP3uiv)
void glTexCoordP4ui(GLenum type, GLuint coords) WEAKGL;
static void (*p_glTexCoordP4ui)(GLenum type, GLuint coords);
static void w_glTexCoordP4ui(GLenum type, GLuint coords) { if (p_glTexCoordP4ui) p_glTexCoordP4ui(type, coords); }
INTERPOSE(glTexCoordP4ui)
void glTexCoordP4uiv(GLenum type, const GLuint *coords) WEAKGL;
static void (*p_glTexCoordP4uiv)(GLenum type, const GLuint *coords);
static void w_glTexCoordP4uiv(GLenum type, const GLuint *coords) { if (p_glTexCoordP4uiv) p_glTexCoordP4uiv(type, coords); }
INTERPOSE(glTexCoordP4uiv)
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (p_glTexCoordPointer) p_glTexCoordPointer(size, type, stride, pointer); }
INTERPOSE(glTexCoordPointer)
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTexEnvf)(GLenum target, GLenum pname, GLfloat param);
static void w_glTexEnvf(GLenum target, GLenum pname, GLfloat param) { if (p_glTexEnvf) p_glTexEnvf(target, pname, param); }
INTERPOSE(glTexEnvf)
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glTexEnvfv)(GLenum target, GLenum pname, const GLfloat *params);
static void w_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) { if (p_glTexEnvfv) p_glTexEnvfv(target, pname, params); }
INTERPOSE(glTexEnvfv)
void glTexEnvi(GLenum target, GLenum pname, GLint param) WEAKGL;
static void (*p_glTexEnvi)(GLenum target, GLenum pname, GLint param);
static void w_glTexEnvi(GLenum target, GLenum pname, GLint param) { if (p_glTexEnvi) p_glTexEnvi(target, pname, param); }
INTERPOSE(glTexEnvi)
void glTexEnviv(GLenum target, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexEnviv)(GLenum target, GLenum pname, const GLint *params);
static void w_glTexEnviv(GLenum target, GLenum pname, const GLint *params) { if (p_glTexEnviv) p_glTexEnviv(target, pname, params); }
INTERPOSE(glTexEnviv)
void glTexGend(GLenum coord, GLenum pname, GLdouble param) WEAKGL;
static void (*p_glTexGend)(GLenum coord, GLenum pname, GLdouble param);
static void w_glTexGend(GLenum coord, GLenum pname, GLdouble param) { if (p_glTexGend) p_glTexGend(coord, pname, param); }
INTERPOSE(glTexGend)
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) WEAKGL;
static void (*p_glTexGendv)(GLenum coord, GLenum pname, const GLdouble *params);
static void w_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) { if (p_glTexGendv) p_glTexGendv(coord, pname, params); }
INTERPOSE(glTexGendv)
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTexGenf)(GLenum coord, GLenum pname, GLfloat param);
static void w_glTexGenf(GLenum coord, GLenum pname, GLfloat param) { if (p_glTexGenf) p_glTexGenf(coord, pname, param); }
INTERPOSE(glTexGenf)
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glTexGenfv)(GLenum coord, GLenum pname, const GLfloat *params);
static void w_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params) { if (p_glTexGenfv) p_glTexGenfv(coord, pname, params); }
INTERPOSE(glTexGenfv)
void glTexGeni(GLenum coord, GLenum pname, GLint param) WEAKGL;
static void (*p_glTexGeni)(GLenum coord, GLenum pname, GLint param);
static void w_glTexGeni(GLenum coord, GLenum pname, GLint param) { if (p_glTexGeni) p_glTexGeni(coord, pname, param); }
INTERPOSE(glTexGeni)
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexGeniv)(GLenum coord, GLenum pname, const GLint *params);
static void w_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) { if (p_glTexGeniv) p_glTexGeniv(coord, pname, params); }
INTERPOSE(glTexGeniv)
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
static void w_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) { if (p_glTexImage1D) p_glTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
INTERPOSE(glTexImage1D)
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
static void w_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) { if (p_glTexImage2D) p_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
INTERPOSE(glTexImage2D)
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void w_glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { if (p_glTexImage2DMultisample) p_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
INTERPOSE(glTexImage2DMultisample)
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
static void w_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) { if (p_glTexImage3D) p_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
INTERPOSE(glTexImage3D)
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void w_glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { if (p_glTexImage3DMultisample) p_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
INTERPOSE(glTexImage3DMultisample)
void glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
static void w_glTexParameterIiv(GLenum target, GLenum pname, const GLint *params) { if (p_glTexParameterIiv) p_glTexParameterIiv(target, pname, params); }
INTERPOSE(glTexParameterIiv)
void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) WEAKGL;
static void (*p_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
static void w_glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) { if (p_glTexParameterIuiv) p_glTexParameterIuiv(target, pname, params); }
INTERPOSE(glTexParameterIuiv)
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
static void w_glTexParameterf(GLenum target, GLenum pname, GLfloat param) { if (p_glTexParameterf) p_glTexParameterf(target, pname, param); }
INTERPOSE(glTexParameterf)
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) WEAKGL;
static void (*p_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
static void w_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) { if (p_glTexParameterfv) p_glTexParameterfv(target, pname, params); }
INTERPOSE(glTexParameterfv)
void glTexParameteri(GLenum target, GLenum pname, GLint param) WEAKGL;
static void (*p_glTexParameteri)(GLenum target, GLenum pname, GLint param);
static void w_glTexParameteri(GLenum target, GLenum pname, GLint param) { if (p_glTexParameteri) p_glTexParameteri(target, pname, param); }
INTERPOSE(glTexParameteri)
void glTexParameteriv(GLenum target, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
static void w_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) { if (p_glTexParameteriv) p_glTexParameteriv(target, pname, params); }
INTERPOSE(glTexParameteriv)
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) WEAKGL;
static void (*p_glTexStorage1D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
static void w_glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) { if (p_glTexStorage1D) p_glTexStorage1D(target, levels, internalformat, width); }
INTERPOSE(glTexStorage1D)
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glTexStorage2D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { if (p_glTexStorage2D) p_glTexStorage2D(target, levels, internalformat, width, height); }
INTERPOSE(glTexStorage2D)
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexStorage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void w_glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { if (p_glTexStorage2DMultisample) p_glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations); }
INTERPOSE(glTexStorage2DMultisample)
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) WEAKGL;
static void (*p_glTexStorage3D)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void w_glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { if (p_glTexStorage3D) p_glTexStorage3D(target, levels, internalformat, width, height, depth); }
INTERPOSE(glTexStorage3D)
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTexStorage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void w_glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { if (p_glTexStorage3DMultisample) p_glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations); }
INTERPOSE(glTexStorage3DMultisample)
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
static void w_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { if (p_glTexSubImage1D) p_glTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
INTERPOSE(glTexSubImage1D)
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void w_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { if (p_glTexSubImage2D) p_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
INTERPOSE(glTexSubImage2D)
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
static void w_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { if (p_glTexSubImage3D) p_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
INTERPOSE(glTexSubImage3D)
void glTextureBarrier(void) WEAKGL;
static void (*p_glTextureBarrier)(void);
static void w_glTextureBarrier(void) { if (p_glTextureBarrier) p_glTextureBarrier(); }
INTERPOSE(glTextureBarrier)
void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) WEAKGL;
static void (*p_glTextureBuffer)(GLuint texture, GLenum internalformat, GLuint buffer);
static void w_glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) { if (p_glTextureBuffer) p_glTextureBuffer(texture, internalformat, buffer); }
INTERPOSE(glTextureBuffer)
void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glTextureBufferRange)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (p_glTextureBufferRange) p_glTextureBufferRange(texture, internalformat, buffer, offset, size); }
INTERPOSE(glTextureBufferRange)
void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params) WEAKGL;
static void (*p_glTextureParameterIiv)(GLuint texture, GLenum pname, const GLint *params);
static void w_glTextureParameterIiv(GLuint texture, GLenum pname, const GLint *params) { if (p_glTextureParameterIiv) p_glTextureParameterIiv(texture, pname, params); }
INTERPOSE(glTextureParameterIiv)
void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params) WEAKGL;
static void (*p_glTextureParameterIuiv)(GLuint texture, GLenum pname, const GLuint *params);
static void w_glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint *params) { if (p_glTextureParameterIuiv) p_glTextureParameterIuiv(texture, pname, params); }
INTERPOSE(glTextureParameterIuiv)
void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) WEAKGL;
static void (*p_glTextureParameterf)(GLuint texture, GLenum pname, GLfloat param);
static void w_glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) { if (p_glTextureParameterf) p_glTextureParameterf(texture, pname, param); }
INTERPOSE(glTextureParameterf)
void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param) WEAKGL;
static void (*p_glTextureParameterfv)(GLuint texture, GLenum pname, const GLfloat *param);
static void w_glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat *param) { if (p_glTextureParameterfv) p_glTextureParameterfv(texture, pname, param); }
INTERPOSE(glTextureParameterfv)
void glTextureParameteri(GLuint texture, GLenum pname, GLint param) WEAKGL;
static void (*p_glTextureParameteri)(GLuint texture, GLenum pname, GLint param);
static void w_glTextureParameteri(GLuint texture, GLenum pname, GLint param) { if (p_glTextureParameteri) p_glTextureParameteri(texture, pname, param); }
INTERPOSE(glTextureParameteri)
void glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param) WEAKGL;
static void (*p_glTextureParameteriv)(GLuint texture, GLenum pname, const GLint *param);
static void w_glTextureParameteriv(GLuint texture, GLenum pname, const GLint *param) { if (p_glTextureParameteriv) p_glTextureParameteriv(texture, pname, param); }
INTERPOSE(glTextureParameteriv)
void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) WEAKGL;
static void (*p_glTextureStorage1D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
static void w_glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) { if (p_glTextureStorage1D) p_glTextureStorage1D(texture, levels, internalformat, width); }
INTERPOSE(glTextureStorage1D)
void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glTextureStorage2D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
static void w_glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) { if (p_glTextureStorage2D) p_glTextureStorage2D(texture, levels, internalformat, width, height); }
INTERPOSE(glTextureStorage2D)
void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTextureStorage2DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
static void w_glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) { if (p_glTextureStorage2DMultisample) p_glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations); }
INTERPOSE(glTextureStorage2DMultisample)
void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) WEAKGL;
static void (*p_glTextureStorage3D)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
static void w_glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) { if (p_glTextureStorage3D) p_glTextureStorage3D(texture, levels, internalformat, width, height, depth); }
INTERPOSE(glTextureStorage3D)
void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) WEAKGL;
static void (*p_glTextureStorage3DMultisample)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
static void w_glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) { if (p_glTextureStorage3DMultisample) p_glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations); }
INTERPOSE(glTextureStorage3DMultisample)
void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTextureSubImage1D)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
static void w_glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) { if (p_glTextureSubImage1D) p_glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels); }
INTERPOSE(glTextureSubImage1D)
void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTextureSubImage2D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
static void w_glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) { if (p_glTextureSubImage2D) p_glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels); }
INTERPOSE(glTextureSubImage2D)
void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) WEAKGL;
static void (*p_glTextureSubImage3D)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
static void w_glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) { if (p_glTextureSubImage3D) p_glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
INTERPOSE(glTextureSubImage3D)
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) WEAKGL;
static void (*p_glTextureView)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
static void w_glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) { if (p_glTextureView) p_glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers); }
INTERPOSE(glTextureView)
void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) WEAKGL;
static void (*p_glTransformFeedbackBufferBase)(GLuint xfb, GLuint index, GLuint buffer);
static void w_glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) { if (p_glTransformFeedbackBufferBase) p_glTransformFeedbackBufferBase(xfb, index, buffer); }
INTERPOSE(glTransformFeedbackBufferBase)
void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) WEAKGL;
static void (*p_glTransformFeedbackBufferRange)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
static void w_glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { if (p_glTransformFeedbackBufferRange) p_glTransformFeedbackBufferRange(xfb, index, buffer, offset, size); }
INTERPOSE(glTransformFeedbackBufferRange)
void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) WEAKGL;
static void (*p_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
static void w_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) { if (p_glTransformFeedbackVaryings) p_glTransformFeedbackVaryings(program, count, varyings, bufferMode); }
INTERPOSE(glTransformFeedbackVaryings)
void glTranslated(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glTranslated)(GLdouble x, GLdouble y, GLdouble z);
static void w_glTranslated(GLdouble x, GLdouble y, GLdouble z) { if (p_glTranslated) p_glTranslated(x, y, z); }
INTERPOSE(glTranslated)
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glTranslatef)(GLfloat x, GLfloat y, GLfloat z);
static void w_glTranslatef(GLfloat x, GLfloat y, GLfloat z) { if (p_glTranslatef) p_glTranslatef(x, y, z); }
INTERPOSE(glTranslatef)
void glUniform1d(GLint location, GLdouble x) WEAKGL;
static void (*p_glUniform1d)(GLint location, GLdouble x);
static void w_glUniform1d(GLint location, GLdouble x) { if (p_glUniform1d) p_glUniform1d(location, x); }
INTERPOSE(glUniform1d)
void glUniform1dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform1dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform1dv(GLint location, GLsizei count, const GLdouble *value) { if (p_glUniform1dv) p_glUniform1dv(location, count, value); }
INTERPOSE(glUniform1dv)
void glUniform1f(GLint location, GLfloat v0) WEAKGL;
static void (*p_glUniform1f)(GLint location, GLfloat v0);
static void w_glUniform1f(GLint location, GLfloat v0) { if (p_glUniform1f) p_glUniform1f(location, v0); }
INTERPOSE(glUniform1f)
void glUniform1fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform1fv(GLint location, GLsizei count, const GLfloat *value) { if (p_glUniform1fv) p_glUniform1fv(location, count, value); }
INTERPOSE(glUniform1fv)
void glUniform1i(GLint location, GLint v0) WEAKGL;
static void (*p_glUniform1i)(GLint location, GLint v0);
static void w_glUniform1i(GLint location, GLint v0) { if (p_glUniform1i) p_glUniform1i(location, v0); }
INTERPOSE(glUniform1i)
void glUniform1iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform1iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform1iv(GLint location, GLsizei count, const GLint *value) { if (p_glUniform1iv) p_glUniform1iv(location, count, value); }
INTERPOSE(glUniform1iv)
void glUniform1ui(GLint location, GLuint v0) WEAKGL;
static void (*p_glUniform1ui)(GLint location, GLuint v0);
static void w_glUniform1ui(GLint location, GLuint v0) { if (p_glUniform1ui) p_glUniform1ui(location, v0); }
INTERPOSE(glUniform1ui)
void glUniform1uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform1uiv(GLint location, GLsizei count, const GLuint *value) { if (p_glUniform1uiv) p_glUniform1uiv(location, count, value); }
INTERPOSE(glUniform1uiv)
void glUniform2d(GLint location, GLdouble x, GLdouble y) WEAKGL;
static void (*p_glUniform2d)(GLint location, GLdouble x, GLdouble y);
static void w_glUniform2d(GLint location, GLdouble x, GLdouble y) { if (p_glUniform2d) p_glUniform2d(location, x, y); }
INTERPOSE(glUniform2d)
void glUniform2dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform2dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform2dv(GLint location, GLsizei count, const GLdouble *value) { if (p_glUniform2dv) p_glUniform2dv(location, count, value); }
INTERPOSE(glUniform2dv)
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) WEAKGL;
static void (*p_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
static void w_glUniform2f(GLint location, GLfloat v0, GLfloat v1) { if (p_glUniform2f) p_glUniform2f(location, v0, v1); }
INTERPOSE(glUniform2f)
void glUniform2fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform2fv(GLint location, GLsizei count, const GLfloat *value) { if (p_glUniform2fv) p_glUniform2fv(location, count, value); }
INTERPOSE(glUniform2fv)
void glUniform2i(GLint location, GLint v0, GLint v1) WEAKGL;
static void (*p_glUniform2i)(GLint location, GLint v0, GLint v1);
static void w_glUniform2i(GLint location, GLint v0, GLint v1) { if (p_glUniform2i) p_glUniform2i(location, v0, v1); }
INTERPOSE(glUniform2i)
void glUniform2iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform2iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform2iv(GLint location, GLsizei count, const GLint *value) { if (p_glUniform2iv) p_glUniform2iv(location, count, value); }
INTERPOSE(glUniform2iv)
void glUniform2ui(GLint location, GLuint v0, GLuint v1) WEAKGL;
static void (*p_glUniform2ui)(GLint location, GLuint v0, GLuint v1);
static void w_glUniform2ui(GLint location, GLuint v0, GLuint v1) { if (p_glUniform2ui) p_glUniform2ui(location, v0, v1); }
INTERPOSE(glUniform2ui)
void glUniform2uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform2uiv(GLint location, GLsizei count, const GLuint *value) { if (p_glUniform2uiv) p_glUniform2uiv(location, count, value); }
INTERPOSE(glUniform2uiv)
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z);
static void w_glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) { if (p_glUniform3d) p_glUniform3d(location, x, y, z); }
INTERPOSE(glUniform3d)
void glUniform3dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform3dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform3dv(GLint location, GLsizei count, const GLdouble *value) { if (p_glUniform3dv) p_glUniform3dv(location, count, value); }
INTERPOSE(glUniform3dv)
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) WEAKGL;
static void (*p_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
static void w_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { if (p_glUniform3f) p_glUniform3f(location, v0, v1, v2); }
INTERPOSE(glUniform3f)
void glUniform3fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { if (p_glUniform3fv) p_glUniform3fv(location, count, value); }
INTERPOSE(glUniform3fv)
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) WEAKGL;
static void (*p_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
static void w_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) { if (p_glUniform3i) p_glUniform3i(location, v0, v1, v2); }
INTERPOSE(glUniform3i)
void glUniform3iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform3iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform3iv(GLint location, GLsizei count, const GLint *value) { if (p_glUniform3iv) p_glUniform3iv(location, count, value); }
INTERPOSE(glUniform3iv)
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) WEAKGL;
static void (*p_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
static void w_glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { if (p_glUniform3ui) p_glUniform3ui(location, v0, v1, v2); }
INTERPOSE(glUniform3ui)
void glUniform3uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform3uiv(GLint location, GLsizei count, const GLuint *value) { if (p_glUniform3uiv) p_glUniform3uiv(location, count, value); }
INTERPOSE(glUniform3uiv)
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (p_glUniform4d) p_glUniform4d(location, x, y, z, w); }
INTERPOSE(glUniform4d)
void glUniform4dv(GLint location, GLsizei count, const GLdouble *value) WEAKGL;
static void (*p_glUniform4dv)(GLint location, GLsizei count, const GLdouble *value);
static void w_glUniform4dv(GLint location, GLsizei count, const GLdouble *value) { if (p_glUniform4dv) p_glUniform4dv(location, count, value); }
INTERPOSE(glUniform4dv)
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) WEAKGL;
static void (*p_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
static void w_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { if (p_glUniform4f) p_glUniform4f(location, v0, v1, v2, v3); }
INTERPOSE(glUniform4f)
void glUniform4fv(GLint location, GLsizei count, const GLfloat *value) WEAKGL;
static void (*p_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
static void w_glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { if (p_glUniform4fv) p_glUniform4fv(location, count, value); }
INTERPOSE(glUniform4fv)
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) WEAKGL;
static void (*p_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
static void w_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { if (p_glUniform4i) p_glUniform4i(location, v0, v1, v2, v3); }
INTERPOSE(glUniform4i)
void glUniform4iv(GLint location, GLsizei count, const GLint *value) WEAKGL;
static void (*p_glUniform4iv)(GLint location, GLsizei count, const GLint *value);
static void w_glUniform4iv(GLint location, GLsizei count, const GLint *value) { if (p_glUniform4iv) p_glUniform4iv(location, count, value); }
INTERPOSE(glUniform4iv)
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) WEAKGL;
static void (*p_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
static void w_glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { if (p_glUniform4ui) p_glUniform4ui(location, v0, v1, v2, v3); }
INTERPOSE(glUniform4ui)
void glUniform4uiv(GLint location, GLsizei count, const GLuint *value) WEAKGL;
static void (*p_glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
static void w_glUniform4uiv(GLint location, GLsizei count, const GLuint *value) { if (p_glUniform4uiv) p_glUniform4uiv(location, count, value); }
INTERPOSE(glUniform4uiv)
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) WEAKGL;
static void (*p_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
static void w_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) { if (p_glUniformBlockBinding) p_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding); }
INTERPOSE(glUniformBlockBinding)
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix2dv) p_glUniformMatrix2dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2dv)
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix2fv) p_glUniformMatrix2fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2fv)
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix2x3dv) p_glUniformMatrix2x3dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x3dv)
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix2x3fv) p_glUniformMatrix2x3fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x3fv)
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix2x4dv) p_glUniformMatrix2x4dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x4dv)
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix2x4fv) p_glUniformMatrix2x4fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix2x4fv)
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix3dv) p_glUniformMatrix3dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3dv)
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix3fv) p_glUniformMatrix3fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3fv)
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix3x2dv) p_glUniformMatrix3x2dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x2dv)
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix3x2fv) p_glUniformMatrix3x2fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x2fv)
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix3x4dv) p_glUniformMatrix3x4dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x4dv)
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix3x4fv) p_glUniformMatrix3x4fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix3x4fv)
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix4dv) p_glUniformMatrix4dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4dv)
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix4fv) p_glUniformMatrix4fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4fv)
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix4x2dv) p_glUniformMatrix4x2dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x2dv)
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix4x2fv) p_glUniformMatrix4x2fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x2fv)
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) WEAKGL;
static void (*p_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
static void w_glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) { if (p_glUniformMatrix4x3dv) p_glUniformMatrix4x3dv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x3dv)
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) WEAKGL;
static void (*p_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
static void w_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if (p_glUniformMatrix4x3fv) p_glUniformMatrix4x3fv(location, count, transpose, value); }
INTERPOSE(glUniformMatrix4x3fv)
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) WEAKGL;
static void (*p_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint *indices);
static void w_glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices) { if (p_glUniformSubroutinesuiv) p_glUniformSubroutinesuiv(shadertype, count, indices); }
INTERPOSE(glUniformSubroutinesuiv)
GLboolean glUnmapBuffer(GLenum target) WEAKGL;
static GLboolean (*p_glUnmapBuffer)(GLenum target);
static GLboolean w_glUnmapBuffer(GLenum target) { if (!p_glUnmapBuffer) return (GLboolean)0; return p_glUnmapBuffer(target); }
INTERPOSE(glUnmapBuffer)
GLboolean glUnmapNamedBuffer(GLuint buffer) WEAKGL;
static GLboolean (*p_glUnmapNamedBuffer)(GLuint buffer);
static GLboolean w_glUnmapNamedBuffer(GLuint buffer) { if (!p_glUnmapNamedBuffer) return (GLboolean)0; return p_glUnmapNamedBuffer(buffer); }
INTERPOSE(glUnmapNamedBuffer)
void glUseProgram(GLuint program) WEAKGL;
static void (*p_glUseProgram)(GLuint program);
static void w_glUseProgram(GLuint program) { if (p_glUseProgram) p_glUseProgram(program); }
INTERPOSE(glUseProgram)
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) WEAKGL;
static void (*p_glUseProgramStages)(GLuint pipeline, GLbitfield stages, GLuint program);
static void w_glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) { if (p_glUseProgramStages) p_glUseProgramStages(pipeline, stages, program); }
INTERPOSE(glUseProgramStages)
void glValidateProgram(GLuint program) WEAKGL;
static void (*p_glValidateProgram)(GLuint program);
static void w_glValidateProgram(GLuint program) { if (p_glValidateProgram) p_glValidateProgram(program); }
INTERPOSE(glValidateProgram)
void glValidateProgramPipeline(GLuint pipeline) WEAKGL;
static void (*p_glValidateProgramPipeline)(GLuint pipeline);
static void w_glValidateProgramPipeline(GLuint pipeline) { if (p_glValidateProgramPipeline) p_glValidateProgramPipeline(pipeline); }
INTERPOSE(glValidateProgramPipeline)
void glVertex2d(GLdouble x, GLdouble y) WEAKGL;
static void (*p_glVertex2d)(GLdouble x, GLdouble y);
static void w_glVertex2d(GLdouble x, GLdouble y) { if (p_glVertex2d) p_glVertex2d(x, y); }
INTERPOSE(glVertex2d)
void glVertex2dv(const GLdouble *v) WEAKGL;
static void (*p_glVertex2dv)(const GLdouble *v);
static void w_glVertex2dv(const GLdouble *v) { if (p_glVertex2dv) p_glVertex2dv(v); }
INTERPOSE(glVertex2dv)
void glVertex2f(GLfloat x, GLfloat y) WEAKGL;
static void (*p_glVertex2f)(GLfloat x, GLfloat y);
static void w_glVertex2f(GLfloat x, GLfloat y) { if (p_glVertex2f) p_glVertex2f(x, y); }
INTERPOSE(glVertex2f)
void glVertex2fv(const GLfloat *v) WEAKGL;
static void (*p_glVertex2fv)(const GLfloat *v);
static void w_glVertex2fv(const GLfloat *v) { if (p_glVertex2fv) p_glVertex2fv(v); }
INTERPOSE(glVertex2fv)
void glVertex2i(GLint x, GLint y) WEAKGL;
static void (*p_glVertex2i)(GLint x, GLint y);
static void w_glVertex2i(GLint x, GLint y) { if (p_glVertex2i) p_glVertex2i(x, y); }
INTERPOSE(glVertex2i)
void glVertex2iv(const GLint *v) WEAKGL;
static void (*p_glVertex2iv)(const GLint *v);
static void w_glVertex2iv(const GLint *v) { if (p_glVertex2iv) p_glVertex2iv(v); }
INTERPOSE(glVertex2iv)
void glVertex2s(GLshort x, GLshort y) WEAKGL;
static void (*p_glVertex2s)(GLshort x, GLshort y);
static void w_glVertex2s(GLshort x, GLshort y) { if (p_glVertex2s) p_glVertex2s(x, y); }
INTERPOSE(glVertex2s)
void glVertex2sv(const GLshort *v) WEAKGL;
static void (*p_glVertex2sv)(const GLshort *v);
static void w_glVertex2sv(const GLshort *v) { if (p_glVertex2sv) p_glVertex2sv(v); }
INTERPOSE(glVertex2sv)
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glVertex3d)(GLdouble x, GLdouble y, GLdouble z);
static void w_glVertex3d(GLdouble x, GLdouble y, GLdouble z) { if (p_glVertex3d) p_glVertex3d(x, y, z); }
INTERPOSE(glVertex3d)
void glVertex3dv(const GLdouble *v) WEAKGL;
static void (*p_glVertex3dv)(const GLdouble *v);
static void w_glVertex3dv(const GLdouble *v) { if (p_glVertex3dv) p_glVertex3dv(v); }
INTERPOSE(glVertex3dv)
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glVertex3f)(GLfloat x, GLfloat y, GLfloat z);
static void w_glVertex3f(GLfloat x, GLfloat y, GLfloat z) { if (p_glVertex3f) p_glVertex3f(x, y, z); }
INTERPOSE(glVertex3f)
void glVertex3fv(const GLfloat *v) WEAKGL;
static void (*p_glVertex3fv)(const GLfloat *v);
static void w_glVertex3fv(const GLfloat *v) { if (p_glVertex3fv) p_glVertex3fv(v); }
INTERPOSE(glVertex3fv)
void glVertex3i(GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glVertex3i)(GLint x, GLint y, GLint z);
static void w_glVertex3i(GLint x, GLint y, GLint z) { if (p_glVertex3i) p_glVertex3i(x, y, z); }
INTERPOSE(glVertex3i)
void glVertex3iv(const GLint *v) WEAKGL;
static void (*p_glVertex3iv)(const GLint *v);
static void w_glVertex3iv(const GLint *v) { if (p_glVertex3iv) p_glVertex3iv(v); }
INTERPOSE(glVertex3iv)
void glVertex3s(GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glVertex3s)(GLshort x, GLshort y, GLshort z);
static void w_glVertex3s(GLshort x, GLshort y, GLshort z) { if (p_glVertex3s) p_glVertex3s(x, y, z); }
INTERPOSE(glVertex3s)
void glVertex3sv(const GLshort *v) WEAKGL;
static void (*p_glVertex3sv)(const GLshort *v);
static void w_glVertex3sv(const GLshort *v) { if (p_glVertex3sv) p_glVertex3sv(v); }
INTERPOSE(glVertex3sv)
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (p_glVertex4d) p_glVertex4d(x, y, z, w); }
INTERPOSE(glVertex4d)
void glVertex4dv(const GLdouble *v) WEAKGL;
static void (*p_glVertex4dv)(const GLdouble *v);
static void w_glVertex4dv(const GLdouble *v) { if (p_glVertex4dv) p_glVertex4dv(v); }
INTERPOSE(glVertex4dv)
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) WEAKGL;
static void (*p_glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void w_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if (p_glVertex4f) p_glVertex4f(x, y, z, w); }
INTERPOSE(glVertex4f)
void glVertex4fv(const GLfloat *v) WEAKGL;
static void (*p_glVertex4fv)(const GLfloat *v);
static void w_glVertex4fv(const GLfloat *v) { if (p_glVertex4fv) p_glVertex4fv(v); }
INTERPOSE(glVertex4fv)
void glVertex4i(GLint x, GLint y, GLint z, GLint w) WEAKGL;
static void (*p_glVertex4i)(GLint x, GLint y, GLint z, GLint w);
static void w_glVertex4i(GLint x, GLint y, GLint z, GLint w) { if (p_glVertex4i) p_glVertex4i(x, y, z, w); }
INTERPOSE(glVertex4i)
void glVertex4iv(const GLint *v) WEAKGL;
static void (*p_glVertex4iv)(const GLint *v);
static void w_glVertex4iv(const GLint *v) { if (p_glVertex4iv) p_glVertex4iv(v); }
INTERPOSE(glVertex4iv)
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) WEAKGL;
static void (*p_glVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
static void w_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) { if (p_glVertex4s) p_glVertex4s(x, y, z, w); }
INTERPOSE(glVertex4s)
void glVertex4sv(const GLshort *v) WEAKGL;
static void (*p_glVertex4sv)(const GLshort *v);
static void w_glVertex4sv(const GLshort *v) { if (p_glVertex4sv) p_glVertex4sv(v); }
INTERPOSE(glVertex4sv)
void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) WEAKGL;
static void (*p_glVertexArrayAttribBinding)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
static void w_glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) { if (p_glVertexArrayAttribBinding) p_glVertexArrayAttribBinding(vaobj, attribindex, bindingindex); }
INTERPOSE(glVertexArrayAttribBinding)
void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexArrayAttribFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
static void w_glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { if (p_glVertexArrayAttribFormat) p_glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset); }
INTERPOSE(glVertexArrayAttribFormat)
void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexArrayAttribIFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (p_glVertexArrayAttribIFormat) p_glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexArrayAttribIFormat)
void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexArrayAttribLFormat)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (p_glVertexArrayAttribLFormat) p_glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexArrayAttribLFormat)
void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) WEAKGL;
static void (*p_glVertexArrayBindingDivisor)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
static void w_glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) { if (p_glVertexArrayBindingDivisor) p_glVertexArrayBindingDivisor(vaobj, bindingindex, divisor); }
INTERPOSE(glVertexArrayBindingDivisor)
void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) WEAKGL;
static void (*p_glVertexArrayElementBuffer)(GLuint vaobj, GLuint buffer);
static void w_glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) { if (p_glVertexArrayElementBuffer) p_glVertexArrayElementBuffer(vaobj, buffer); }
INTERPOSE(glVertexArrayElementBuffer)
void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) WEAKGL;
static void (*p_glVertexArrayVertexBuffer)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
static void w_glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) { if (p_glVertexArrayVertexBuffer) p_glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride); }
INTERPOSE(glVertexArrayVertexBuffer)
void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) WEAKGL;
static void (*p_glVertexArrayVertexBuffers)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
static void w_glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) { if (p_glVertexArrayVertexBuffers) p_glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides); }
INTERPOSE(glVertexArrayVertexBuffers)
void glVertexAttrib1d(GLuint index, GLdouble x) WEAKGL;
static void (*p_glVertexAttrib1d)(GLuint index, GLdouble x);
static void w_glVertexAttrib1d(GLuint index, GLdouble x) { if (p_glVertexAttrib1d) p_glVertexAttrib1d(index, x); }
INTERPOSE(glVertexAttrib1d)
void glVertexAttrib1dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib1dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib1dv(GLuint index, const GLdouble *v) { if (p_glVertexAttrib1dv) p_glVertexAttrib1dv(index, v); }
INTERPOSE(glVertexAttrib1dv)
void glVertexAttrib1f(GLuint index, GLfloat x) WEAKGL;
static void (*p_glVertexAttrib1f)(GLuint index, GLfloat x);
static void w_glVertexAttrib1f(GLuint index, GLfloat x) { if (p_glVertexAttrib1f) p_glVertexAttrib1f(index, x); }
INTERPOSE(glVertexAttrib1f)
void glVertexAttrib1fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib1fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib1fv(GLuint index, const GLfloat *v) { if (p_glVertexAttrib1fv) p_glVertexAttrib1fv(index, v); }
INTERPOSE(glVertexAttrib1fv)
void glVertexAttrib1s(GLuint index, GLshort x) WEAKGL;
static void (*p_glVertexAttrib1s)(GLuint index, GLshort x);
static void w_glVertexAttrib1s(GLuint index, GLshort x) { if (p_glVertexAttrib1s) p_glVertexAttrib1s(index, x); }
INTERPOSE(glVertexAttrib1s)
void glVertexAttrib1sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib1sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib1sv(GLuint index, const GLshort *v) { if (p_glVertexAttrib1sv) p_glVertexAttrib1sv(index, v); }
INTERPOSE(glVertexAttrib1sv)
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) WEAKGL;
static void (*p_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
static void w_glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { if (p_glVertexAttrib2d) p_glVertexAttrib2d(index, x, y); }
INTERPOSE(glVertexAttrib2d)
void glVertexAttrib2dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib2dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib2dv(GLuint index, const GLdouble *v) { if (p_glVertexAttrib2dv) p_glVertexAttrib2dv(index, v); }
INTERPOSE(glVertexAttrib2dv)
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) WEAKGL;
static void (*p_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
static void w_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { if (p_glVertexAttrib2f) p_glVertexAttrib2f(index, x, y); }
INTERPOSE(glVertexAttrib2f)
void glVertexAttrib2fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib2fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib2fv(GLuint index, const GLfloat *v) { if (p_glVertexAttrib2fv) p_glVertexAttrib2fv(index, v); }
INTERPOSE(glVertexAttrib2fv)
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) WEAKGL;
static void (*p_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
static void w_glVertexAttrib2s(GLuint index, GLshort x, GLshort y) { if (p_glVertexAttrib2s) p_glVertexAttrib2s(index, x, y); }
INTERPOSE(glVertexAttrib2s)
void glVertexAttrib2sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib2sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib2sv(GLuint index, const GLshort *v) { if (p_glVertexAttrib2sv) p_glVertexAttrib2sv(index, v); }
INTERPOSE(glVertexAttrib2sv)
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void w_glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { if (p_glVertexAttrib3d) p_glVertexAttrib3d(index, x, y, z); }
INTERPOSE(glVertexAttrib3d)
void glVertexAttrib3dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib3dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib3dv(GLuint index, const GLdouble *v) { if (p_glVertexAttrib3dv) p_glVertexAttrib3dv(index, v); }
INTERPOSE(glVertexAttrib3dv)
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
static void w_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { if (p_glVertexAttrib3f) p_glVertexAttrib3f(index, x, y, z); }
INTERPOSE(glVertexAttrib3f)
void glVertexAttrib3fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib3fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib3fv(GLuint index, const GLfloat *v) { if (p_glVertexAttrib3fv) p_glVertexAttrib3fv(index, v); }
INTERPOSE(glVertexAttrib3fv)
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
static void w_glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { if (p_glVertexAttrib3s) p_glVertexAttrib3s(index, x, y, z); }
INTERPOSE(glVertexAttrib3s)
void glVertexAttrib3sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib3sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib3sv(GLuint index, const GLshort *v) { if (p_glVertexAttrib3sv) p_glVertexAttrib3sv(index, v); }
INTERPOSE(glVertexAttrib3sv)
void glVertexAttrib4Nbv(GLuint index, const GLbyte *v) WEAKGL;
static void (*p_glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
static void w_glVertexAttrib4Nbv(GLuint index, const GLbyte *v) { if (p_glVertexAttrib4Nbv) p_glVertexAttrib4Nbv(index, v); }
INTERPOSE(glVertexAttrib4Nbv)
void glVertexAttrib4Niv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttrib4Niv)(GLuint index, const GLint *v);
static void w_glVertexAttrib4Niv(GLuint index, const GLint *v) { if (p_glVertexAttrib4Niv) p_glVertexAttrib4Niv(index, v); }
INTERPOSE(glVertexAttrib4Niv)
void glVertexAttrib4Nsv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib4Nsv(GLuint index, const GLshort *v) { if (p_glVertexAttrib4Nsv) p_glVertexAttrib4Nsv(index, v); }
INTERPOSE(glVertexAttrib4Nsv)
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) WEAKGL;
static void (*p_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
static void w_glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { if (p_glVertexAttrib4Nub) p_glVertexAttrib4Nub(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4Nub)
void glVertexAttrib4Nubv(GLuint index, const GLubyte *v) WEAKGL;
static void (*p_glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
static void w_glVertexAttrib4Nubv(GLuint index, const GLubyte *v) { if (p_glVertexAttrib4Nubv) p_glVertexAttrib4Nubv(index, v); }
INTERPOSE(glVertexAttrib4Nubv)
void glVertexAttrib4Nuiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
static void w_glVertexAttrib4Nuiv(GLuint index, const GLuint *v) { if (p_glVertexAttrib4Nuiv) p_glVertexAttrib4Nuiv(index, v); }
INTERPOSE(glVertexAttrib4Nuiv)
void glVertexAttrib4Nusv(GLuint index, const GLushort *v) WEAKGL;
static void (*p_glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
static void w_glVertexAttrib4Nusv(GLuint index, const GLushort *v) { if (p_glVertexAttrib4Nusv) p_glVertexAttrib4Nusv(index, v); }
INTERPOSE(glVertexAttrib4Nusv)
void glVertexAttrib4bv(GLuint index, const GLbyte *v) WEAKGL;
static void (*p_glVertexAttrib4bv)(GLuint index, const GLbyte *v);
static void w_glVertexAttrib4bv(GLuint index, const GLbyte *v) { if (p_glVertexAttrib4bv) p_glVertexAttrib4bv(index, v); }
INTERPOSE(glVertexAttrib4bv)
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (p_glVertexAttrib4d) p_glVertexAttrib4d(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4d)
void glVertexAttrib4dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttrib4dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttrib4dv(GLuint index, const GLdouble *v) { if (p_glVertexAttrib4dv) p_glVertexAttrib4dv(index, v); }
INTERPOSE(glVertexAttrib4dv)
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) WEAKGL;
static void (*p_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
static void w_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if (p_glVertexAttrib4f) p_glVertexAttrib4f(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4f)
void glVertexAttrib4fv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glVertexAttrib4fv)(GLuint index, const GLfloat *v);
static void w_glVertexAttrib4fv(GLuint index, const GLfloat *v) { if (p_glVertexAttrib4fv) p_glVertexAttrib4fv(index, v); }
INTERPOSE(glVertexAttrib4fv)
void glVertexAttrib4iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttrib4iv)(GLuint index, const GLint *v);
static void w_glVertexAttrib4iv(GLuint index, const GLint *v) { if (p_glVertexAttrib4iv) p_glVertexAttrib4iv(index, v); }
INTERPOSE(glVertexAttrib4iv)
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) WEAKGL;
static void (*p_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
static void w_glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { if (p_glVertexAttrib4s) p_glVertexAttrib4s(index, x, y, z, w); }
INTERPOSE(glVertexAttrib4s)
void glVertexAttrib4sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttrib4sv)(GLuint index, const GLshort *v);
static void w_glVertexAttrib4sv(GLuint index, const GLshort *v) { if (p_glVertexAttrib4sv) p_glVertexAttrib4sv(index, v); }
INTERPOSE(glVertexAttrib4sv)
void glVertexAttrib4ubv(GLuint index, const GLubyte *v) WEAKGL;
static void (*p_glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
static void w_glVertexAttrib4ubv(GLuint index, const GLubyte *v) { if (p_glVertexAttrib4ubv) p_glVertexAttrib4ubv(index, v); }
INTERPOSE(glVertexAttrib4ubv)
void glVertexAttrib4uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttrib4uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttrib4uiv(GLuint index, const GLuint *v) { if (p_glVertexAttrib4uiv) p_glVertexAttrib4uiv(index, v); }
INTERPOSE(glVertexAttrib4uiv)
void glVertexAttrib4usv(GLuint index, const GLushort *v) WEAKGL;
static void (*p_glVertexAttrib4usv)(GLuint index, const GLushort *v);
static void w_glVertexAttrib4usv(GLuint index, const GLushort *v) { if (p_glVertexAttrib4usv) p_glVertexAttrib4usv(index, v); }
INTERPOSE(glVertexAttrib4usv)
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) WEAKGL;
static void (*p_glVertexAttribBinding)(GLuint attribindex, GLuint bindingindex);
static void w_glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) { if (p_glVertexAttribBinding) p_glVertexAttribBinding(attribindex, bindingindex); }
INTERPOSE(glVertexAttribBinding)
void glVertexAttribDivisor(GLuint index, GLuint divisor) WEAKGL;
static void (*p_glVertexAttribDivisor)(GLuint index, GLuint divisor);
static void w_glVertexAttribDivisor(GLuint index, GLuint divisor) { if (p_glVertexAttribDivisor) p_glVertexAttribDivisor(index, divisor); }
INTERPOSE(glVertexAttribDivisor)
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexAttribFormat)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
static void w_glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) { if (p_glVertexAttribFormat) p_glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset); }
INTERPOSE(glVertexAttribFormat)
void glVertexAttribI1i(GLuint index, GLint x) WEAKGL;
static void (*p_glVertexAttribI1i)(GLuint index, GLint x);
static void w_glVertexAttribI1i(GLuint index, GLint x) { if (p_glVertexAttribI1i) p_glVertexAttribI1i(index, x); }
INTERPOSE(glVertexAttribI1i)
void glVertexAttribI1iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI1iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI1iv(GLuint index, const GLint *v) { if (p_glVertexAttribI1iv) p_glVertexAttribI1iv(index, v); }
INTERPOSE(glVertexAttribI1iv)
void glVertexAttribI1ui(GLuint index, GLuint x) WEAKGL;
static void (*p_glVertexAttribI1ui)(GLuint index, GLuint x);
static void w_glVertexAttribI1ui(GLuint index, GLuint x) { if (p_glVertexAttribI1ui) p_glVertexAttribI1ui(index, x); }
INTERPOSE(glVertexAttribI1ui)
void glVertexAttribI1uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI1uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI1uiv(GLuint index, const GLuint *v) { if (p_glVertexAttribI1uiv) p_glVertexAttribI1uiv(index, v); }
INTERPOSE(glVertexAttribI1uiv)
void glVertexAttribI2i(GLuint index, GLint x, GLint y) WEAKGL;
static void (*p_glVertexAttribI2i)(GLuint index, GLint x, GLint y);
static void w_glVertexAttribI2i(GLuint index, GLint x, GLint y) { if (p_glVertexAttribI2i) p_glVertexAttribI2i(index, x, y); }
INTERPOSE(glVertexAttribI2i)
void glVertexAttribI2iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI2iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI2iv(GLuint index, const GLint *v) { if (p_glVertexAttribI2iv) p_glVertexAttribI2iv(index, v); }
INTERPOSE(glVertexAttribI2iv)
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) WEAKGL;
static void (*p_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
static void w_glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) { if (p_glVertexAttribI2ui) p_glVertexAttribI2ui(index, x, y); }
INTERPOSE(glVertexAttribI2ui)
void glVertexAttribI2uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI2uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI2uiv(GLuint index, const GLuint *v) { if (p_glVertexAttribI2uiv) p_glVertexAttribI2uiv(index, v); }
INTERPOSE(glVertexAttribI2uiv)
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
static void w_glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { if (p_glVertexAttribI3i) p_glVertexAttribI3i(index, x, y, z); }
INTERPOSE(glVertexAttribI3i)
void glVertexAttribI3iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI3iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI3iv(GLuint index, const GLint *v) { if (p_glVertexAttribI3iv) p_glVertexAttribI3iv(index, v); }
INTERPOSE(glVertexAttribI3iv)
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) WEAKGL;
static void (*p_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
static void w_glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { if (p_glVertexAttribI3ui) p_glVertexAttribI3ui(index, x, y, z); }
INTERPOSE(glVertexAttribI3ui)
void glVertexAttribI3uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI3uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI3uiv(GLuint index, const GLuint *v) { if (p_glVertexAttribI3uiv) p_glVertexAttribI3uiv(index, v); }
INTERPOSE(glVertexAttribI3uiv)
void glVertexAttribI4bv(GLuint index, const GLbyte *v) WEAKGL;
static void (*p_glVertexAttribI4bv)(GLuint index, const GLbyte *v);
static void w_glVertexAttribI4bv(GLuint index, const GLbyte *v) { if (p_glVertexAttribI4bv) p_glVertexAttribI4bv(index, v); }
INTERPOSE(glVertexAttribI4bv)
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) WEAKGL;
static void (*p_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
static void w_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { if (p_glVertexAttribI4i) p_glVertexAttribI4i(index, x, y, z, w); }
INTERPOSE(glVertexAttribI4i)
void glVertexAttribI4iv(GLuint index, const GLint *v) WEAKGL;
static void (*p_glVertexAttribI4iv)(GLuint index, const GLint *v);
static void w_glVertexAttribI4iv(GLuint index, const GLint *v) { if (p_glVertexAttribI4iv) p_glVertexAttribI4iv(index, v); }
INTERPOSE(glVertexAttribI4iv)
void glVertexAttribI4sv(GLuint index, const GLshort *v) WEAKGL;
static void (*p_glVertexAttribI4sv)(GLuint index, const GLshort *v);
static void w_glVertexAttribI4sv(GLuint index, const GLshort *v) { if (p_glVertexAttribI4sv) p_glVertexAttribI4sv(index, v); }
INTERPOSE(glVertexAttribI4sv)
void glVertexAttribI4ubv(GLuint index, const GLubyte *v) WEAKGL;
static void (*p_glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
static void w_glVertexAttribI4ubv(GLuint index, const GLubyte *v) { if (p_glVertexAttribI4ubv) p_glVertexAttribI4ubv(index, v); }
INTERPOSE(glVertexAttribI4ubv)
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) WEAKGL;
static void (*p_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
static void w_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { if (p_glVertexAttribI4ui) p_glVertexAttribI4ui(index, x, y, z, w); }
INTERPOSE(glVertexAttribI4ui)
void glVertexAttribI4uiv(GLuint index, const GLuint *v) WEAKGL;
static void (*p_glVertexAttribI4uiv)(GLuint index, const GLuint *v);
static void w_glVertexAttribI4uiv(GLuint index, const GLuint *v) { if (p_glVertexAttribI4uiv) p_glVertexAttribI4uiv(index, v); }
INTERPOSE(glVertexAttribI4uiv)
void glVertexAttribI4usv(GLuint index, const GLushort *v) WEAKGL;
static void (*p_glVertexAttribI4usv)(GLuint index, const GLushort *v);
static void w_glVertexAttribI4usv(GLuint index, const GLushort *v) { if (p_glVertexAttribI4usv) p_glVertexAttribI4usv(index, v); }
INTERPOSE(glVertexAttribI4usv)
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexAttribIFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (p_glVertexAttribIFormat) p_glVertexAttribIFormat(attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexAttribIFormat)
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { if (p_glVertexAttribIPointer) p_glVertexAttribIPointer(index, size, type, stride, pointer); }
INTERPOSE(glVertexAttribIPointer)
void glVertexAttribL1d(GLuint index, GLdouble x) WEAKGL;
static void (*p_glVertexAttribL1d)(GLuint index, GLdouble x);
static void w_glVertexAttribL1d(GLuint index, GLdouble x) { if (p_glVertexAttribL1d) p_glVertexAttribL1d(index, x); }
INTERPOSE(glVertexAttribL1d)
void glVertexAttribL1dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL1dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL1dv(GLuint index, const GLdouble *v) { if (p_glVertexAttribL1dv) p_glVertexAttribL1dv(index, v); }
INTERPOSE(glVertexAttribL1dv)
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) WEAKGL;
static void (*p_glVertexAttribL2d)(GLuint index, GLdouble x, GLdouble y);
static void w_glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) { if (p_glVertexAttribL2d) p_glVertexAttribL2d(index, x, y); }
INTERPOSE(glVertexAttribL2d)
void glVertexAttribL2dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL2dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL2dv(GLuint index, const GLdouble *v) { if (p_glVertexAttribL2dv) p_glVertexAttribL2dv(index, v); }
INTERPOSE(glVertexAttribL2dv)
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glVertexAttribL3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
static void w_glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { if (p_glVertexAttribL3d) p_glVertexAttribL3d(index, x, y, z); }
INTERPOSE(glVertexAttribL3d)
void glVertexAttribL3dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL3dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL3dv(GLuint index, const GLdouble *v) { if (p_glVertexAttribL3dv) p_glVertexAttribL3dv(index, v); }
INTERPOSE(glVertexAttribL3dv)
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) WEAKGL;
static void (*p_glVertexAttribL4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
static void w_glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { if (p_glVertexAttribL4d) p_glVertexAttribL4d(index, x, y, z, w); }
INTERPOSE(glVertexAttribL4d)
void glVertexAttribL4dv(GLuint index, const GLdouble *v) WEAKGL;
static void (*p_glVertexAttribL4dv)(GLuint index, const GLdouble *v);
static void w_glVertexAttribL4dv(GLuint index, const GLdouble *v) { if (p_glVertexAttribL4dv) p_glVertexAttribL4dv(index, v); }
INTERPOSE(glVertexAttribL4dv)
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) WEAKGL;
static void (*p_glVertexAttribLFormat)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
static void w_glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) { if (p_glVertexAttribLFormat) p_glVertexAttribLFormat(attribindex, size, type, relativeoffset); }
INTERPOSE(glVertexAttribLFormat)
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexAttribLPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) { if (p_glVertexAttribLPointer) p_glVertexAttribLPointer(index, size, type, stride, pointer); }
INTERPOSE(glVertexAttribLPointer)
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (p_glVertexAttribP1ui) p_glVertexAttribP1ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP1ui)
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (p_glVertexAttribP1uiv) p_glVertexAttribP1uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP1uiv)
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (p_glVertexAttribP2ui) p_glVertexAttribP2ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP2ui)
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (p_glVertexAttribP2uiv) p_glVertexAttribP2uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP2uiv)
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (p_glVertexAttribP3ui) p_glVertexAttribP3ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP3ui)
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (p_glVertexAttribP3uiv) p_glVertexAttribP3uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP3uiv)
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) WEAKGL;
static void (*p_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
static void w_glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) { if (p_glVertexAttribP4ui) p_glVertexAttribP4ui(index, type, normalized, value); }
INTERPOSE(glVertexAttribP4ui)
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) WEAKGL;
static void (*p_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
static void w_glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value) { if (p_glVertexAttribP4uiv) p_glVertexAttribP4uiv(index, type, normalized, value); }
INTERPOSE(glVertexAttribP4uiv)
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
static void w_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) { if (p_glVertexAttribPointer) p_glVertexAttribPointer(index, size, type, normalized, stride, pointer); }
INTERPOSE(glVertexAttribPointer)
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) WEAKGL;
static void (*p_glVertexBindingDivisor)(GLuint bindingindex, GLuint divisor);
static void w_glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) { if (p_glVertexBindingDivisor) p_glVertexBindingDivisor(bindingindex, divisor); }
INTERPOSE(glVertexBindingDivisor)
void glVertexP2ui(GLenum type, GLuint value) WEAKGL;
static void (*p_glVertexP2ui)(GLenum type, GLuint value);
static void w_glVertexP2ui(GLenum type, GLuint value) { if (p_glVertexP2ui) p_glVertexP2ui(type, value); }
INTERPOSE(glVertexP2ui)
void glVertexP2uiv(GLenum type, const GLuint *value) WEAKGL;
static void (*p_glVertexP2uiv)(GLenum type, const GLuint *value);
static void w_glVertexP2uiv(GLenum type, const GLuint *value) { if (p_glVertexP2uiv) p_glVertexP2uiv(type, value); }
INTERPOSE(glVertexP2uiv)
void glVertexP3ui(GLenum type, GLuint value) WEAKGL;
static void (*p_glVertexP3ui)(GLenum type, GLuint value);
static void w_glVertexP3ui(GLenum type, GLuint value) { if (p_glVertexP3ui) p_glVertexP3ui(type, value); }
INTERPOSE(glVertexP3ui)
void glVertexP3uiv(GLenum type, const GLuint *value) WEAKGL;
static void (*p_glVertexP3uiv)(GLenum type, const GLuint *value);
static void w_glVertexP3uiv(GLenum type, const GLuint *value) { if (p_glVertexP3uiv) p_glVertexP3uiv(type, value); }
INTERPOSE(glVertexP3uiv)
void glVertexP4ui(GLenum type, GLuint value) WEAKGL;
static void (*p_glVertexP4ui)(GLenum type, GLuint value);
static void w_glVertexP4ui(GLenum type, GLuint value) { if (p_glVertexP4ui) p_glVertexP4ui(type, value); }
INTERPOSE(glVertexP4ui)
void glVertexP4uiv(GLenum type, const GLuint *value) WEAKGL;
static void (*p_glVertexP4uiv)(GLenum type, const GLuint *value);
static void w_glVertexP4uiv(GLenum type, const GLuint *value) { if (p_glVertexP4uiv) p_glVertexP4uiv(type, value); }
INTERPOSE(glVertexP4uiv)
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) WEAKGL;
static void (*p_glVertexPointer)(GLint size, GLenum type, GLsizei stride, const void *pointer);
static void w_glVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer) { if (p_glVertexPointer) p_glVertexPointer(size, type, stride, pointer); }
INTERPOSE(glVertexPointer)
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) WEAKGL;
static void (*p_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
static void w_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) { if (p_glViewport) p_glViewport(x, y, width, height); }
INTERPOSE(glViewport)
void glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) WEAKGL;
static void (*p_glViewportArrayv)(GLuint first, GLsizei count, const GLfloat *v);
static void w_glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) { if (p_glViewportArrayv) p_glViewportArrayv(first, count, v); }
INTERPOSE(glViewportArrayv)
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) WEAKGL;
static void (*p_glViewportIndexedf)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
static void w_glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) { if (p_glViewportIndexedf) p_glViewportIndexedf(index, x, y, w, h); }
INTERPOSE(glViewportIndexedf)
void glViewportIndexedfv(GLuint index, const GLfloat *v) WEAKGL;
static void (*p_glViewportIndexedfv)(GLuint index, const GLfloat *v);
static void w_glViewportIndexedfv(GLuint index, const GLfloat *v) { if (p_glViewportIndexedfv) p_glViewportIndexedfv(index, v); }
INTERPOSE(glViewportIndexedfv)
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) WEAKGL;
static void (*p_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
static void w_glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { if (p_glWaitSync) p_glWaitSync(sync, flags, timeout); }
INTERPOSE(glWaitSync)
void glWindowPos2d(GLdouble x, GLdouble y) WEAKGL;
static void (*p_glWindowPos2d)(GLdouble x, GLdouble y);
static void w_glWindowPos2d(GLdouble x, GLdouble y) { if (p_glWindowPos2d) p_glWindowPos2d(x, y); }
INTERPOSE(glWindowPos2d)
void glWindowPos2dv(const GLdouble *v) WEAKGL;
static void (*p_glWindowPos2dv)(const GLdouble *v);
static void w_glWindowPos2dv(const GLdouble *v) { if (p_glWindowPos2dv) p_glWindowPos2dv(v); }
INTERPOSE(glWindowPos2dv)
void glWindowPos2f(GLfloat x, GLfloat y) WEAKGL;
static void (*p_glWindowPos2f)(GLfloat x, GLfloat y);
static void w_glWindowPos2f(GLfloat x, GLfloat y) { if (p_glWindowPos2f) p_glWindowPos2f(x, y); }
INTERPOSE(glWindowPos2f)
void glWindowPos2fv(const GLfloat *v) WEAKGL;
static void (*p_glWindowPos2fv)(const GLfloat *v);
static void w_glWindowPos2fv(const GLfloat *v) { if (p_glWindowPos2fv) p_glWindowPos2fv(v); }
INTERPOSE(glWindowPos2fv)
void glWindowPos2i(GLint x, GLint y) WEAKGL;
static void (*p_glWindowPos2i)(GLint x, GLint y);
static void w_glWindowPos2i(GLint x, GLint y) { if (p_glWindowPos2i) p_glWindowPos2i(x, y); }
INTERPOSE(glWindowPos2i)
void glWindowPos2iv(const GLint *v) WEAKGL;
static void (*p_glWindowPos2iv)(const GLint *v);
static void w_glWindowPos2iv(const GLint *v) { if (p_glWindowPos2iv) p_glWindowPos2iv(v); }
INTERPOSE(glWindowPos2iv)
void glWindowPos2s(GLshort x, GLshort y) WEAKGL;
static void (*p_glWindowPos2s)(GLshort x, GLshort y);
static void w_glWindowPos2s(GLshort x, GLshort y) { if (p_glWindowPos2s) p_glWindowPos2s(x, y); }
INTERPOSE(glWindowPos2s)
void glWindowPos2sv(const GLshort *v) WEAKGL;
static void (*p_glWindowPos2sv)(const GLshort *v);
static void w_glWindowPos2sv(const GLshort *v) { if (p_glWindowPos2sv) p_glWindowPos2sv(v); }
INTERPOSE(glWindowPos2sv)
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) WEAKGL;
static void (*p_glWindowPos3d)(GLdouble x, GLdouble y, GLdouble z);
static void w_glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) { if (p_glWindowPos3d) p_glWindowPos3d(x, y, z); }
INTERPOSE(glWindowPos3d)
void glWindowPos3dv(const GLdouble *v) WEAKGL;
static void (*p_glWindowPos3dv)(const GLdouble *v);
static void w_glWindowPos3dv(const GLdouble *v) { if (p_glWindowPos3dv) p_glWindowPos3dv(v); }
INTERPOSE(glWindowPos3dv)
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) WEAKGL;
static void (*p_glWindowPos3f)(GLfloat x, GLfloat y, GLfloat z);
static void w_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) { if (p_glWindowPos3f) p_glWindowPos3f(x, y, z); }
INTERPOSE(glWindowPos3f)
void glWindowPos3fv(const GLfloat *v) WEAKGL;
static void (*p_glWindowPos3fv)(const GLfloat *v);
static void w_glWindowPos3fv(const GLfloat *v) { if (p_glWindowPos3fv) p_glWindowPos3fv(v); }
INTERPOSE(glWindowPos3fv)
void glWindowPos3i(GLint x, GLint y, GLint z) WEAKGL;
static void (*p_glWindowPos3i)(GLint x, GLint y, GLint z);
static void w_glWindowPos3i(GLint x, GLint y, GLint z) { if (p_glWindowPos3i) p_glWindowPos3i(x, y, z); }
INTERPOSE(glWindowPos3i)
void glWindowPos3iv(const GLint *v) WEAKGL;
static void (*p_glWindowPos3iv)(const GLint *v);
static void w_glWindowPos3iv(const GLint *v) { if (p_glWindowPos3iv) p_glWindowPos3iv(v); }
INTERPOSE(glWindowPos3iv)
void glWindowPos3s(GLshort x, GLshort y, GLshort z) WEAKGL;
static void (*p_glWindowPos3s)(GLshort x, GLshort y, GLshort z);
static void w_glWindowPos3s(GLshort x, GLshort y, GLshort z) { if (p_glWindowPos3s) p_glWindowPos3s(x, y, z); }
INTERPOSE(glWindowPos3s)
void glWindowPos3sv(const GLshort *v) WEAKGL;
static void (*p_glWindowPos3sv)(const GLshort *v);
static void w_glWindowPos3sv(const GLshort *v) { if (p_glWindowPos3sv) p_glWindowPos3sv(v); }
INTERPOSE(glWindowPos3sv)

int mglshim_gl_init(void *h) {
    int n = 0;
    *(void **)&p_glAccum = dlsym(h, "glAccum"); if (p_glAccum) n++;
    *(void **)&p_glActiveShaderProgram = dlsym(h, "glActiveShaderProgram"); if (p_glActiveShaderProgram) n++;
    *(void **)&p_glActiveTexture = dlsym(h, "glActiveTexture"); if (p_glActiveTexture) n++;
    *(void **)&p_glAlphaFunc = dlsym(h, "glAlphaFunc"); if (p_glAlphaFunc) n++;
    *(void **)&p_glAreTexturesResident = dlsym(h, "glAreTexturesResident"); if (p_glAreTexturesResident) n++;
    *(void **)&p_glArrayElement = dlsym(h, "glArrayElement"); if (p_glArrayElement) n++;
    *(void **)&p_glAttachShader = dlsym(h, "glAttachShader"); if (p_glAttachShader) n++;
    *(void **)&p_glBegin = dlsym(h, "glBegin"); if (p_glBegin) n++;
    *(void **)&p_glBeginConditionalRender = dlsym(h, "glBeginConditionalRender"); if (p_glBeginConditionalRender) n++;
    *(void **)&p_glBeginQuery = dlsym(h, "glBeginQuery"); if (p_glBeginQuery) n++;
    *(void **)&p_glBeginQueryIndexed = dlsym(h, "glBeginQueryIndexed"); if (p_glBeginQueryIndexed) n++;
    *(void **)&p_glBeginTransformFeedback = dlsym(h, "glBeginTransformFeedback"); if (p_glBeginTransformFeedback) n++;
    *(void **)&p_glBindAttribLocation = dlsym(h, "glBindAttribLocation"); if (p_glBindAttribLocation) n++;
    *(void **)&p_glBindBuffer = dlsym(h, "glBindBuffer"); if (p_glBindBuffer) n++;
    *(void **)&p_glBindBufferBase = dlsym(h, "glBindBufferBase"); if (p_glBindBufferBase) n++;
    *(void **)&p_glBindBufferRange = dlsym(h, "glBindBufferRange"); if (p_glBindBufferRange) n++;
    *(void **)&p_glBindBuffersBase = dlsym(h, "glBindBuffersBase"); if (p_glBindBuffersBase) n++;
    *(void **)&p_glBindBuffersRange = dlsym(h, "glBindBuffersRange"); if (p_glBindBuffersRange) n++;
    *(void **)&p_glBindFragDataLocation = dlsym(h, "glBindFragDataLocation"); if (p_glBindFragDataLocation) n++;
    *(void **)&p_glBindFragDataLocationIndexed = dlsym(h, "glBindFragDataLocationIndexed"); if (p_glBindFragDataLocationIndexed) n++;
    *(void **)&p_glBindFramebuffer = dlsym(h, "glBindFramebuffer"); if (p_glBindFramebuffer) n++;
    *(void **)&p_glBindImageTexture = dlsym(h, "glBindImageTexture"); if (p_glBindImageTexture) n++;
    *(void **)&p_glBindImageTextures = dlsym(h, "glBindImageTextures"); if (p_glBindImageTextures) n++;
    *(void **)&p_glBindProgramPipeline = dlsym(h, "glBindProgramPipeline"); if (p_glBindProgramPipeline) n++;
    *(void **)&p_glBindRenderbuffer = dlsym(h, "glBindRenderbuffer"); if (p_glBindRenderbuffer) n++;
    *(void **)&p_glBindSampler = dlsym(h, "glBindSampler"); if (p_glBindSampler) n++;
    *(void **)&p_glBindSamplers = dlsym(h, "glBindSamplers"); if (p_glBindSamplers) n++;
    *(void **)&p_glBindTexture = dlsym(h, "glBindTexture"); if (p_glBindTexture) n++;
    *(void **)&p_glBindTextureUnit = dlsym(h, "glBindTextureUnit"); if (p_glBindTextureUnit) n++;
    *(void **)&p_glBindTextures = dlsym(h, "glBindTextures"); if (p_glBindTextures) n++;
    *(void **)&p_glBindTransformFeedback = dlsym(h, "glBindTransformFeedback"); if (p_glBindTransformFeedback) n++;
    *(void **)&p_glBindVertexArray = dlsym(h, "glBindVertexArray"); if (p_glBindVertexArray) n++;
    *(void **)&p_glBindVertexBuffer = dlsym(h, "glBindVertexBuffer"); if (p_glBindVertexBuffer) n++;
    *(void **)&p_glBindVertexBuffers = dlsym(h, "glBindVertexBuffers"); if (p_glBindVertexBuffers) n++;
    *(void **)&p_glBitmap = dlsym(h, "glBitmap"); if (p_glBitmap) n++;
    *(void **)&p_glBlendColor = dlsym(h, "glBlendColor"); if (p_glBlendColor) n++;
    *(void **)&p_glBlendEquation = dlsym(h, "glBlendEquation"); if (p_glBlendEquation) n++;
    *(void **)&p_glBlendEquationSeparate = dlsym(h, "glBlendEquationSeparate"); if (p_glBlendEquationSeparate) n++;
    *(void **)&p_glBlendEquationSeparatei = dlsym(h, "glBlendEquationSeparatei"); if (p_glBlendEquationSeparatei) n++;
    *(void **)&p_glBlendEquationi = dlsym(h, "glBlendEquationi"); if (p_glBlendEquationi) n++;
    *(void **)&p_glBlendFunc = dlsym(h, "glBlendFunc"); if (p_glBlendFunc) n++;
    *(void **)&p_glBlendFuncSeparate = dlsym(h, "glBlendFuncSeparate"); if (p_glBlendFuncSeparate) n++;
    *(void **)&p_glBlendFuncSeparatei = dlsym(h, "glBlendFuncSeparatei"); if (p_glBlendFuncSeparatei) n++;
    *(void **)&p_glBlendFunci = dlsym(h, "glBlendFunci"); if (p_glBlendFunci) n++;
    *(void **)&p_glBlitFramebuffer = dlsym(h, "glBlitFramebuffer"); if (p_glBlitFramebuffer) n++;
    *(void **)&p_glBlitNamedFramebuffer = dlsym(h, "glBlitNamedFramebuffer"); if (p_glBlitNamedFramebuffer) n++;
    *(void **)&p_glBufferData = dlsym(h, "glBufferData"); if (p_glBufferData) n++;
    *(void **)&p_glBufferStorage = dlsym(h, "glBufferStorage"); if (p_glBufferStorage) n++;
    *(void **)&p_glBufferSubData = dlsym(h, "glBufferSubData"); if (p_glBufferSubData) n++;
    *(void **)&p_glCallList = dlsym(h, "glCallList"); if (p_glCallList) n++;
    *(void **)&p_glCallLists = dlsym(h, "glCallLists"); if (p_glCallLists) n++;
    *(void **)&p_glCheckFramebufferStatus = dlsym(h, "glCheckFramebufferStatus"); if (p_glCheckFramebufferStatus) n++;
    *(void **)&p_glCheckNamedFramebufferStatus = dlsym(h, "glCheckNamedFramebufferStatus"); if (p_glCheckNamedFramebufferStatus) n++;
    *(void **)&p_glClampColor = dlsym(h, "glClampColor"); if (p_glClampColor) n++;
    *(void **)&p_glClear = dlsym(h, "glClear"); if (p_glClear) n++;
    *(void **)&p_glClearAccum = dlsym(h, "glClearAccum"); if (p_glClearAccum) n++;
    *(void **)&p_glClearBufferData = dlsym(h, "glClearBufferData"); if (p_glClearBufferData) n++;
    *(void **)&p_glClearBufferSubData = dlsym(h, "glClearBufferSubData"); if (p_glClearBufferSubData) n++;
    *(void **)&p_glClearBufferfi = dlsym(h, "glClearBufferfi"); if (p_glClearBufferfi) n++;
    *(void **)&p_glClearBufferfv = dlsym(h, "glClearBufferfv"); if (p_glClearBufferfv) n++;
    *(void **)&p_glClearBufferiv = dlsym(h, "glClearBufferiv"); if (p_glClearBufferiv) n++;
    *(void **)&p_glClearBufferuiv = dlsym(h, "glClearBufferuiv"); if (p_glClearBufferuiv) n++;
    *(void **)&p_glClearColor = dlsym(h, "glClearColor"); if (p_glClearColor) n++;
    *(void **)&p_glClearDepth = dlsym(h, "glClearDepth"); if (p_glClearDepth) n++;
    *(void **)&p_glClearDepthf = dlsym(h, "glClearDepthf"); if (p_glClearDepthf) n++;
    *(void **)&p_glClearIndex = dlsym(h, "glClearIndex"); if (p_glClearIndex) n++;
    *(void **)&p_glClearNamedBufferData = dlsym(h, "glClearNamedBufferData"); if (p_glClearNamedBufferData) n++;
    *(void **)&p_glClearNamedBufferSubData = dlsym(h, "glClearNamedBufferSubData"); if (p_glClearNamedBufferSubData) n++;
    *(void **)&p_glClearNamedFramebufferfi = dlsym(h, "glClearNamedFramebufferfi"); if (p_glClearNamedFramebufferfi) n++;
    *(void **)&p_glClearNamedFramebufferfv = dlsym(h, "glClearNamedFramebufferfv"); if (p_glClearNamedFramebufferfv) n++;
    *(void **)&p_glClearNamedFramebufferiv = dlsym(h, "glClearNamedFramebufferiv"); if (p_glClearNamedFramebufferiv) n++;
    *(void **)&p_glClearNamedFramebufferuiv = dlsym(h, "glClearNamedFramebufferuiv"); if (p_glClearNamedFramebufferuiv) n++;
    *(void **)&p_glClearStencil = dlsym(h, "glClearStencil"); if (p_glClearStencil) n++;
    *(void **)&p_glClearTexImage = dlsym(h, "glClearTexImage"); if (p_glClearTexImage) n++;
    *(void **)&p_glClearTexSubImage = dlsym(h, "glClearTexSubImage"); if (p_glClearTexSubImage) n++;
    *(void **)&p_glClientActiveTexture = dlsym(h, "glClientActiveTexture"); if (p_glClientActiveTexture) n++;
    *(void **)&p_glClientWaitSync = dlsym(h, "glClientWaitSync"); if (p_glClientWaitSync) n++;
    *(void **)&p_glClipControl = dlsym(h, "glClipControl"); if (p_glClipControl) n++;
    *(void **)&p_glClipPlane = dlsym(h, "glClipPlane"); if (p_glClipPlane) n++;
    *(void **)&p_glColor3b = dlsym(h, "glColor3b"); if (p_glColor3b) n++;
    *(void **)&p_glColor3bv = dlsym(h, "glColor3bv"); if (p_glColor3bv) n++;
    *(void **)&p_glColor3d = dlsym(h, "glColor3d"); if (p_glColor3d) n++;
    *(void **)&p_glColor3dv = dlsym(h, "glColor3dv"); if (p_glColor3dv) n++;
    *(void **)&p_glColor3f = dlsym(h, "glColor3f"); if (p_glColor3f) n++;
    *(void **)&p_glColor3fv = dlsym(h, "glColor3fv"); if (p_glColor3fv) n++;
    *(void **)&p_glColor3i = dlsym(h, "glColor3i"); if (p_glColor3i) n++;
    *(void **)&p_glColor3iv = dlsym(h, "glColor3iv"); if (p_glColor3iv) n++;
    *(void **)&p_glColor3s = dlsym(h, "glColor3s"); if (p_glColor3s) n++;
    *(void **)&p_glColor3sv = dlsym(h, "glColor3sv"); if (p_glColor3sv) n++;
    *(void **)&p_glColor3ub = dlsym(h, "glColor3ub"); if (p_glColor3ub) n++;
    *(void **)&p_glColor3ubv = dlsym(h, "glColor3ubv"); if (p_glColor3ubv) n++;
    *(void **)&p_glColor3ui = dlsym(h, "glColor3ui"); if (p_glColor3ui) n++;
    *(void **)&p_glColor3uiv = dlsym(h, "glColor3uiv"); if (p_glColor3uiv) n++;
    *(void **)&p_glColor3us = dlsym(h, "glColor3us"); if (p_glColor3us) n++;
    *(void **)&p_glColor3usv = dlsym(h, "glColor3usv"); if (p_glColor3usv) n++;
    *(void **)&p_glColor4b = dlsym(h, "glColor4b"); if (p_glColor4b) n++;
    *(void **)&p_glColor4bv = dlsym(h, "glColor4bv"); if (p_glColor4bv) n++;
    *(void **)&p_glColor4d = dlsym(h, "glColor4d"); if (p_glColor4d) n++;
    *(void **)&p_glColor4dv = dlsym(h, "glColor4dv"); if (p_glColor4dv) n++;
    *(void **)&p_glColor4f = dlsym(h, "glColor4f"); if (p_glColor4f) n++;
    *(void **)&p_glColor4fv = dlsym(h, "glColor4fv"); if (p_glColor4fv) n++;
    *(void **)&p_glColor4i = dlsym(h, "glColor4i"); if (p_glColor4i) n++;
    *(void **)&p_glColor4iv = dlsym(h, "glColor4iv"); if (p_glColor4iv) n++;
    *(void **)&p_glColor4s = dlsym(h, "glColor4s"); if (p_glColor4s) n++;
    *(void **)&p_glColor4sv = dlsym(h, "glColor4sv"); if (p_glColor4sv) n++;
    *(void **)&p_glColor4ub = dlsym(h, "glColor4ub"); if (p_glColor4ub) n++;
    *(void **)&p_glColor4ubv = dlsym(h, "glColor4ubv"); if (p_glColor4ubv) n++;
    *(void **)&p_glColor4ui = dlsym(h, "glColor4ui"); if (p_glColor4ui) n++;
    *(void **)&p_glColor4uiv = dlsym(h, "glColor4uiv"); if (p_glColor4uiv) n++;
    *(void **)&p_glColor4us = dlsym(h, "glColor4us"); if (p_glColor4us) n++;
    *(void **)&p_glColor4usv = dlsym(h, "glColor4usv"); if (p_glColor4usv) n++;
    *(void **)&p_glColorMask = dlsym(h, "glColorMask"); if (p_glColorMask) n++;
    *(void **)&p_glColorMaski = dlsym(h, "glColorMaski"); if (p_glColorMaski) n++;
    *(void **)&p_glColorMaterial = dlsym(h, "glColorMaterial"); if (p_glColorMaterial) n++;
    *(void **)&p_glColorP3ui = dlsym(h, "glColorP3ui"); if (p_glColorP3ui) n++;
    *(void **)&p_glColorP3uiv = dlsym(h, "glColorP3uiv"); if (p_glColorP3uiv) n++;
    *(void **)&p_glColorP4ui = dlsym(h, "glColorP4ui"); if (p_glColorP4ui) n++;
    *(void **)&p_glColorP4uiv = dlsym(h, "glColorP4uiv"); if (p_glColorP4uiv) n++;
    *(void **)&p_glColorPointer = dlsym(h, "glColorPointer"); if (p_glColorPointer) n++;
    *(void **)&p_glCompileShader = dlsym(h, "glCompileShader"); if (p_glCompileShader) n++;
    *(void **)&p_glCompressedTexImage1D = dlsym(h, "glCompressedTexImage1D"); if (p_glCompressedTexImage1D) n++;
    *(void **)&p_glCompressedTexImage2D = dlsym(h, "glCompressedTexImage2D"); if (p_glCompressedTexImage2D) n++;
    *(void **)&p_glCompressedTexImage3D = dlsym(h, "glCompressedTexImage3D"); if (p_glCompressedTexImage3D) n++;
    *(void **)&p_glCompressedTexSubImage1D = dlsym(h, "glCompressedTexSubImage1D"); if (p_glCompressedTexSubImage1D) n++;
    *(void **)&p_glCompressedTexSubImage2D = dlsym(h, "glCompressedTexSubImage2D"); if (p_glCompressedTexSubImage2D) n++;
    *(void **)&p_glCompressedTexSubImage3D = dlsym(h, "glCompressedTexSubImage3D"); if (p_glCompressedTexSubImage3D) n++;
    *(void **)&p_glCompressedTextureSubImage1D = dlsym(h, "glCompressedTextureSubImage1D"); if (p_glCompressedTextureSubImage1D) n++;
    *(void **)&p_glCompressedTextureSubImage2D = dlsym(h, "glCompressedTextureSubImage2D"); if (p_glCompressedTextureSubImage2D) n++;
    *(void **)&p_glCompressedTextureSubImage3D = dlsym(h, "glCompressedTextureSubImage3D"); if (p_glCompressedTextureSubImage3D) n++;
    *(void **)&p_glCopyBufferSubData = dlsym(h, "glCopyBufferSubData"); if (p_glCopyBufferSubData) n++;
    *(void **)&p_glCopyImageSubData = dlsym(h, "glCopyImageSubData"); if (p_glCopyImageSubData) n++;
    *(void **)&p_glCopyNamedBufferSubData = dlsym(h, "glCopyNamedBufferSubData"); if (p_glCopyNamedBufferSubData) n++;
    *(void **)&p_glCopyPixels = dlsym(h, "glCopyPixels"); if (p_glCopyPixels) n++;
    *(void **)&p_glCopyTexImage1D = dlsym(h, "glCopyTexImage1D"); if (p_glCopyTexImage1D) n++;
    *(void **)&p_glCopyTexImage2D = dlsym(h, "glCopyTexImage2D"); if (p_glCopyTexImage2D) n++;
    *(void **)&p_glCopyTexSubImage1D = dlsym(h, "glCopyTexSubImage1D"); if (p_glCopyTexSubImage1D) n++;
    *(void **)&p_glCopyTexSubImage2D = dlsym(h, "glCopyTexSubImage2D"); if (p_glCopyTexSubImage2D) n++;
    *(void **)&p_glCopyTexSubImage3D = dlsym(h, "glCopyTexSubImage3D"); if (p_glCopyTexSubImage3D) n++;
    *(void **)&p_glCopyTextureSubImage1D = dlsym(h, "glCopyTextureSubImage1D"); if (p_glCopyTextureSubImage1D) n++;
    *(void **)&p_glCopyTextureSubImage2D = dlsym(h, "glCopyTextureSubImage2D"); if (p_glCopyTextureSubImage2D) n++;
    *(void **)&p_glCopyTextureSubImage3D = dlsym(h, "glCopyTextureSubImage3D"); if (p_glCopyTextureSubImage3D) n++;
    *(void **)&p_glCreateBuffers = dlsym(h, "glCreateBuffers"); if (p_glCreateBuffers) n++;
    *(void **)&p_glCreateFramebuffers = dlsym(h, "glCreateFramebuffers"); if (p_glCreateFramebuffers) n++;
    *(void **)&p_glCreateProgram = dlsym(h, "glCreateProgram"); if (p_glCreateProgram) n++;
    *(void **)&p_glCreateProgramPipelines = dlsym(h, "glCreateProgramPipelines"); if (p_glCreateProgramPipelines) n++;
    *(void **)&p_glCreateQueries = dlsym(h, "glCreateQueries"); if (p_glCreateQueries) n++;
    *(void **)&p_glCreateRenderbuffers = dlsym(h, "glCreateRenderbuffers"); if (p_glCreateRenderbuffers) n++;
    *(void **)&p_glCreateSamplers = dlsym(h, "glCreateSamplers"); if (p_glCreateSamplers) n++;
    *(void **)&p_glCreateShader = dlsym(h, "glCreateShader"); if (p_glCreateShader) n++;
    *(void **)&p_glCreateShaderProgramv = dlsym(h, "glCreateShaderProgramv"); if (p_glCreateShaderProgramv) n++;
    *(void **)&p_glCreateTextures = dlsym(h, "glCreateTextures"); if (p_glCreateTextures) n++;
    *(void **)&p_glCreateTransformFeedbacks = dlsym(h, "glCreateTransformFeedbacks"); if (p_glCreateTransformFeedbacks) n++;
    *(void **)&p_glCreateVertexArrays = dlsym(h, "glCreateVertexArrays"); if (p_glCreateVertexArrays) n++;
    *(void **)&p_glCullFace = dlsym(h, "glCullFace"); if (p_glCullFace) n++;
    *(void **)&p_glDebugMessageCallback = dlsym(h, "glDebugMessageCallback"); if (p_glDebugMessageCallback) n++;
    *(void **)&p_glDebugMessageControl = dlsym(h, "glDebugMessageControl"); if (p_glDebugMessageControl) n++;
    *(void **)&p_glDebugMessageInsert = dlsym(h, "glDebugMessageInsert"); if (p_glDebugMessageInsert) n++;
    *(void **)&p_glDeleteBuffers = dlsym(h, "glDeleteBuffers"); if (p_glDeleteBuffers) n++;
    *(void **)&p_glDeleteFramebuffers = dlsym(h, "glDeleteFramebuffers"); if (p_glDeleteFramebuffers) n++;
    *(void **)&p_glDeleteLists = dlsym(h, "glDeleteLists"); if (p_glDeleteLists) n++;
    *(void **)&p_glDeleteProgram = dlsym(h, "glDeleteProgram"); if (p_glDeleteProgram) n++;
    *(void **)&p_glDeleteProgramPipelines = dlsym(h, "glDeleteProgramPipelines"); if (p_glDeleteProgramPipelines) n++;
    *(void **)&p_glDeleteQueries = dlsym(h, "glDeleteQueries"); if (p_glDeleteQueries) n++;
    *(void **)&p_glDeleteRenderbuffers = dlsym(h, "glDeleteRenderbuffers"); if (p_glDeleteRenderbuffers) n++;
    *(void **)&p_glDeleteSamplers = dlsym(h, "glDeleteSamplers"); if (p_glDeleteSamplers) n++;
    *(void **)&p_glDeleteShader = dlsym(h, "glDeleteShader"); if (p_glDeleteShader) n++;
    *(void **)&p_glDeleteSync = dlsym(h, "glDeleteSync"); if (p_glDeleteSync) n++;
    *(void **)&p_glDeleteTextures = dlsym(h, "glDeleteTextures"); if (p_glDeleteTextures) n++;
    *(void **)&p_glDeleteTransformFeedbacks = dlsym(h, "glDeleteTransformFeedbacks"); if (p_glDeleteTransformFeedbacks) n++;
    *(void **)&p_glDeleteVertexArrays = dlsym(h, "glDeleteVertexArrays"); if (p_glDeleteVertexArrays) n++;
    *(void **)&p_glDepthFunc = dlsym(h, "glDepthFunc"); if (p_glDepthFunc) n++;
    *(void **)&p_glDepthMask = dlsym(h, "glDepthMask"); if (p_glDepthMask) n++;
    *(void **)&p_glDepthRange = dlsym(h, "glDepthRange"); if (p_glDepthRange) n++;
    *(void **)&p_glDepthRangeArrayv = dlsym(h, "glDepthRangeArrayv"); if (p_glDepthRangeArrayv) n++;
    *(void **)&p_glDepthRangeIndexed = dlsym(h, "glDepthRangeIndexed"); if (p_glDepthRangeIndexed) n++;
    *(void **)&p_glDepthRangef = dlsym(h, "glDepthRangef"); if (p_glDepthRangef) n++;
    *(void **)&p_glDetachShader = dlsym(h, "glDetachShader"); if (p_glDetachShader) n++;
    *(void **)&p_glDisable = dlsym(h, "glDisable"); if (p_glDisable) n++;
    *(void **)&p_glDisableClientState = dlsym(h, "glDisableClientState"); if (p_glDisableClientState) n++;
    *(void **)&p_glDisableVertexArrayAttrib = dlsym(h, "glDisableVertexArrayAttrib"); if (p_glDisableVertexArrayAttrib) n++;
    *(void **)&p_glDisableVertexAttribArray = dlsym(h, "glDisableVertexAttribArray"); if (p_glDisableVertexAttribArray) n++;
    *(void **)&p_glDisablei = dlsym(h, "glDisablei"); if (p_glDisablei) n++;
    *(void **)&p_glDispatchCompute = dlsym(h, "glDispatchCompute"); if (p_glDispatchCompute) n++;
    *(void **)&p_glDispatchComputeIndirect = dlsym(h, "glDispatchComputeIndirect"); if (p_glDispatchComputeIndirect) n++;
    *(void **)&p_glDrawArrays = dlsym(h, "glDrawArrays"); if (p_glDrawArrays) n++;
    *(void **)&p_glDrawArraysIndirect = dlsym(h, "glDrawArraysIndirect"); if (p_glDrawArraysIndirect) n++;
    *(void **)&p_glDrawArraysInstanced = dlsym(h, "glDrawArraysInstanced"); if (p_glDrawArraysInstanced) n++;
    *(void **)&p_glDrawArraysInstancedBaseInstance = dlsym(h, "glDrawArraysInstancedBaseInstance"); if (p_glDrawArraysInstancedBaseInstance) n++;
    *(void **)&p_glDrawBuffer = dlsym(h, "glDrawBuffer"); if (p_glDrawBuffer) n++;
    *(void **)&p_glDrawBuffers = dlsym(h, "glDrawBuffers"); if (p_glDrawBuffers) n++;
    *(void **)&p_glDrawElements = dlsym(h, "glDrawElements"); if (p_glDrawElements) n++;
    *(void **)&p_glDrawElementsBaseVertex = dlsym(h, "glDrawElementsBaseVertex"); if (p_glDrawElementsBaseVertex) n++;
    *(void **)&p_glDrawElementsIndirect = dlsym(h, "glDrawElementsIndirect"); if (p_glDrawElementsIndirect) n++;
    *(void **)&p_glDrawElementsInstanced = dlsym(h, "glDrawElementsInstanced"); if (p_glDrawElementsInstanced) n++;
    *(void **)&p_glDrawElementsInstancedBaseInstance = dlsym(h, "glDrawElementsInstancedBaseInstance"); if (p_glDrawElementsInstancedBaseInstance) n++;
    *(void **)&p_glDrawElementsInstancedBaseVertex = dlsym(h, "glDrawElementsInstancedBaseVertex"); if (p_glDrawElementsInstancedBaseVertex) n++;
    *(void **)&p_glDrawElementsInstancedBaseVertexBaseInstance = dlsym(h, "glDrawElementsInstancedBaseVertexBaseInstance"); if (p_glDrawElementsInstancedBaseVertexBaseInstance) n++;
    *(void **)&p_glDrawPixels = dlsym(h, "glDrawPixels"); if (p_glDrawPixels) n++;
    *(void **)&p_glDrawRangeElements = dlsym(h, "glDrawRangeElements"); if (p_glDrawRangeElements) n++;
    *(void **)&p_glDrawRangeElementsBaseVertex = dlsym(h, "glDrawRangeElementsBaseVertex"); if (p_glDrawRangeElementsBaseVertex) n++;
    *(void **)&p_glDrawTransformFeedback = dlsym(h, "glDrawTransformFeedback"); if (p_glDrawTransformFeedback) n++;
    *(void **)&p_glDrawTransformFeedbackInstanced = dlsym(h, "glDrawTransformFeedbackInstanced"); if (p_glDrawTransformFeedbackInstanced) n++;
    *(void **)&p_glDrawTransformFeedbackStream = dlsym(h, "glDrawTransformFeedbackStream"); if (p_glDrawTransformFeedbackStream) n++;
    *(void **)&p_glDrawTransformFeedbackStreamInstanced = dlsym(h, "glDrawTransformFeedbackStreamInstanced"); if (p_glDrawTransformFeedbackStreamInstanced) n++;
    *(void **)&p_glEdgeFlag = dlsym(h, "glEdgeFlag"); if (p_glEdgeFlag) n++;
    *(void **)&p_glEdgeFlagPointer = dlsym(h, "glEdgeFlagPointer"); if (p_glEdgeFlagPointer) n++;
    *(void **)&p_glEdgeFlagv = dlsym(h, "glEdgeFlagv"); if (p_glEdgeFlagv) n++;
    *(void **)&p_glEnable = dlsym(h, "glEnable"); if (p_glEnable) n++;
    *(void **)&p_glEnableClientState = dlsym(h, "glEnableClientState"); if (p_glEnableClientState) n++;
    *(void **)&p_glEnableVertexArrayAttrib = dlsym(h, "glEnableVertexArrayAttrib"); if (p_glEnableVertexArrayAttrib) n++;
    *(void **)&p_glEnableVertexAttribArray = dlsym(h, "glEnableVertexAttribArray"); if (p_glEnableVertexAttribArray) n++;
    *(void **)&p_glEnablei = dlsym(h, "glEnablei"); if (p_glEnablei) n++;
    *(void **)&p_glEnd = dlsym(h, "glEnd"); if (p_glEnd) n++;
    *(void **)&p_glEndConditionalRender = dlsym(h, "glEndConditionalRender"); if (p_glEndConditionalRender) n++;
    *(void **)&p_glEndList = dlsym(h, "glEndList"); if (p_glEndList) n++;
    *(void **)&p_glEndQuery = dlsym(h, "glEndQuery"); if (p_glEndQuery) n++;
    *(void **)&p_glEndQueryIndexed = dlsym(h, "glEndQueryIndexed"); if (p_glEndQueryIndexed) n++;
    *(void **)&p_glEndTransformFeedback = dlsym(h, "glEndTransformFeedback"); if (p_glEndTransformFeedback) n++;
    *(void **)&p_glEvalCoord1d = dlsym(h, "glEvalCoord1d"); if (p_glEvalCoord1d) n++;
    *(void **)&p_glEvalCoord1dv = dlsym(h, "glEvalCoord1dv"); if (p_glEvalCoord1dv) n++;
    *(void **)&p_glEvalCoord1f = dlsym(h, "glEvalCoord1f"); if (p_glEvalCoord1f) n++;
    *(void **)&p_glEvalCoord1fv = dlsym(h, "glEvalCoord1fv"); if (p_glEvalCoord1fv) n++;
    *(void **)&p_glEvalCoord2d = dlsym(h, "glEvalCoord2d"); if (p_glEvalCoord2d) n++;
    *(void **)&p_glEvalCoord2dv = dlsym(h, "glEvalCoord2dv"); if (p_glEvalCoord2dv) n++;
    *(void **)&p_glEvalCoord2f = dlsym(h, "glEvalCoord2f"); if (p_glEvalCoord2f) n++;
    *(void **)&p_glEvalCoord2fv = dlsym(h, "glEvalCoord2fv"); if (p_glEvalCoord2fv) n++;
    *(void **)&p_glEvalMesh1 = dlsym(h, "glEvalMesh1"); if (p_glEvalMesh1) n++;
    *(void **)&p_glEvalMesh2 = dlsym(h, "glEvalMesh2"); if (p_glEvalMesh2) n++;
    *(void **)&p_glEvalPoint1 = dlsym(h, "glEvalPoint1"); if (p_glEvalPoint1) n++;
    *(void **)&p_glEvalPoint2 = dlsym(h, "glEvalPoint2"); if (p_glEvalPoint2) n++;
    *(void **)&p_glFeedbackBuffer = dlsym(h, "glFeedbackBuffer"); if (p_glFeedbackBuffer) n++;
    *(void **)&p_glFenceSync = dlsym(h, "glFenceSync"); if (p_glFenceSync) n++;
    *(void **)&p_glFinish = dlsym(h, "glFinish"); if (p_glFinish) n++;
    *(void **)&p_glFlush = dlsym(h, "glFlush"); if (p_glFlush) n++;
    *(void **)&p_glFlushMappedBufferRange = dlsym(h, "glFlushMappedBufferRange"); if (p_glFlushMappedBufferRange) n++;
    *(void **)&p_glFlushMappedNamedBufferRange = dlsym(h, "glFlushMappedNamedBufferRange"); if (p_glFlushMappedNamedBufferRange) n++;
    *(void **)&p_glFogCoordPointer = dlsym(h, "glFogCoordPointer"); if (p_glFogCoordPointer) n++;
    *(void **)&p_glFogCoordd = dlsym(h, "glFogCoordd"); if (p_glFogCoordd) n++;
    *(void **)&p_glFogCoorddv = dlsym(h, "glFogCoorddv"); if (p_glFogCoorddv) n++;
    *(void **)&p_glFogCoordf = dlsym(h, "glFogCoordf"); if (p_glFogCoordf) n++;
    *(void **)&p_glFogCoordfv = dlsym(h, "glFogCoordfv"); if (p_glFogCoordfv) n++;
    *(void **)&p_glFogf = dlsym(h, "glFogf"); if (p_glFogf) n++;
    *(void **)&p_glFogfv = dlsym(h, "glFogfv"); if (p_glFogfv) n++;
    *(void **)&p_glFogi = dlsym(h, "glFogi"); if (p_glFogi) n++;
    *(void **)&p_glFogiv = dlsym(h, "glFogiv"); if (p_glFogiv) n++;
    *(void **)&p_glFramebufferParameteri = dlsym(h, "glFramebufferParameteri"); if (p_glFramebufferParameteri) n++;
    *(void **)&p_glFramebufferRenderbuffer = dlsym(h, "glFramebufferRenderbuffer"); if (p_glFramebufferRenderbuffer) n++;
    *(void **)&p_glFramebufferTexture = dlsym(h, "glFramebufferTexture"); if (p_glFramebufferTexture) n++;
    *(void **)&p_glFramebufferTexture1D = dlsym(h, "glFramebufferTexture1D"); if (p_glFramebufferTexture1D) n++;
    *(void **)&p_glFramebufferTexture2D = dlsym(h, "glFramebufferTexture2D"); if (p_glFramebufferTexture2D) n++;
    *(void **)&p_glFramebufferTexture3D = dlsym(h, "glFramebufferTexture3D"); if (p_glFramebufferTexture3D) n++;
    *(void **)&p_glFramebufferTextureLayer = dlsym(h, "glFramebufferTextureLayer"); if (p_glFramebufferTextureLayer) n++;
    *(void **)&p_glFrontFace = dlsym(h, "glFrontFace"); if (p_glFrontFace) n++;
    *(void **)&p_glFrustum = dlsym(h, "glFrustum"); if (p_glFrustum) n++;
    *(void **)&p_glGenBuffers = dlsym(h, "glGenBuffers"); if (p_glGenBuffers) n++;
    *(void **)&p_glGenFramebuffers = dlsym(h, "glGenFramebuffers"); if (p_glGenFramebuffers) n++;
    *(void **)&p_glGenLists = dlsym(h, "glGenLists"); if (p_glGenLists) n++;
    *(void **)&p_glGenProgramPipelines = dlsym(h, "glGenProgramPipelines"); if (p_glGenProgramPipelines) n++;
    *(void **)&p_glGenQueries = dlsym(h, "glGenQueries"); if (p_glGenQueries) n++;
    *(void **)&p_glGenRenderbuffers = dlsym(h, "glGenRenderbuffers"); if (p_glGenRenderbuffers) n++;
    *(void **)&p_glGenSamplers = dlsym(h, "glGenSamplers"); if (p_glGenSamplers) n++;
    *(void **)&p_glGenTextures = dlsym(h, "glGenTextures"); if (p_glGenTextures) n++;
    *(void **)&p_glGenTransformFeedbacks = dlsym(h, "glGenTransformFeedbacks"); if (p_glGenTransformFeedbacks) n++;
    *(void **)&p_glGenVertexArrays = dlsym(h, "glGenVertexArrays"); if (p_glGenVertexArrays) n++;
    *(void **)&p_glGenerateMipmap = dlsym(h, "glGenerateMipmap"); if (p_glGenerateMipmap) n++;
    *(void **)&p_glGenerateTextureMipmap = dlsym(h, "glGenerateTextureMipmap"); if (p_glGenerateTextureMipmap) n++;
    *(void **)&p_glGetActiveAtomicCounterBufferiv = dlsym(h, "glGetActiveAtomicCounterBufferiv"); if (p_glGetActiveAtomicCounterBufferiv) n++;
    *(void **)&p_glGetActiveAttrib = dlsym(h, "glGetActiveAttrib"); if (p_glGetActiveAttrib) n++;
    *(void **)&p_glGetActiveSubroutineName = dlsym(h, "glGetActiveSubroutineName"); if (p_glGetActiveSubroutineName) n++;
    *(void **)&p_glGetActiveSubroutineUniformName = dlsym(h, "glGetActiveSubroutineUniformName"); if (p_glGetActiveSubroutineUniformName) n++;
    *(void **)&p_glGetActiveSubroutineUniformiv = dlsym(h, "glGetActiveSubroutineUniformiv"); if (p_glGetActiveSubroutineUniformiv) n++;
    *(void **)&p_glGetActiveUniform = dlsym(h, "glGetActiveUniform"); if (p_glGetActiveUniform) n++;
    *(void **)&p_glGetActiveUniformBlockName = dlsym(h, "glGetActiveUniformBlockName"); if (p_glGetActiveUniformBlockName) n++;
    *(void **)&p_glGetActiveUniformBlockiv = dlsym(h, "glGetActiveUniformBlockiv"); if (p_glGetActiveUniformBlockiv) n++;
    *(void **)&p_glGetActiveUniformName = dlsym(h, "glGetActiveUniformName"); if (p_glGetActiveUniformName) n++;
    *(void **)&p_glGetActiveUniformsiv = dlsym(h, "glGetActiveUniformsiv"); if (p_glGetActiveUniformsiv) n++;
    *(void **)&p_glGetAttachedShaders = dlsym(h, "glGetAttachedShaders"); if (p_glGetAttachedShaders) n++;
    *(void **)&p_glGetAttribLocation = dlsym(h, "glGetAttribLocation"); if (p_glGetAttribLocation) n++;
    *(void **)&p_glGetBooleani_v = dlsym(h, "glGetBooleani_v"); if (p_glGetBooleani_v) n++;
    *(void **)&p_glGetBooleanv = dlsym(h, "glGetBooleanv"); if (p_glGetBooleanv) n++;
    *(void **)&p_glGetBufferParameteri64v = dlsym(h, "glGetBufferParameteri64v"); if (p_glGetBufferParameteri64v) n++;
    *(void **)&p_glGetBufferParameteriv = dlsym(h, "glGetBufferParameteriv"); if (p_glGetBufferParameteriv) n++;
    *(void **)&p_glGetBufferPointerv = dlsym(h, "glGetBufferPointerv"); if (p_glGetBufferPointerv) n++;
    *(void **)&p_glGetBufferSubData = dlsym(h, "glGetBufferSubData"); if (p_glGetBufferSubData) n++;
    *(void **)&p_glGetClipPlane = dlsym(h, "glGetClipPlane"); if (p_glGetClipPlane) n++;
    *(void **)&p_glGetCompressedTexImage = dlsym(h, "glGetCompressedTexImage"); if (p_glGetCompressedTexImage) n++;
    *(void **)&p_glGetCompressedTextureImage = dlsym(h, "glGetCompressedTextureImage"); if (p_glGetCompressedTextureImage) n++;
    *(void **)&p_glGetCompressedTextureSubImage = dlsym(h, "glGetCompressedTextureSubImage"); if (p_glGetCompressedTextureSubImage) n++;
    *(void **)&p_glGetDebugMessageLog = dlsym(h, "glGetDebugMessageLog"); if (p_glGetDebugMessageLog) n++;
    *(void **)&p_glGetDoublei_v = dlsym(h, "glGetDoublei_v"); if (p_glGetDoublei_v) n++;
    *(void **)&p_glGetDoublev = dlsym(h, "glGetDoublev"); if (p_glGetDoublev) n++;
    *(void **)&p_glGetError = dlsym(h, "glGetError"); if (p_glGetError) n++;
    *(void **)&p_glGetFloati_v = dlsym(h, "glGetFloati_v"); if (p_glGetFloati_v) n++;
    *(void **)&p_glGetFloatv = dlsym(h, "glGetFloatv"); if (p_glGetFloatv) n++;
    *(void **)&p_glGetFragDataIndex = dlsym(h, "glGetFragDataIndex"); if (p_glGetFragDataIndex) n++;
    *(void **)&p_glGetFragDataLocation = dlsym(h, "glGetFragDataLocation"); if (p_glGetFragDataLocation) n++;
    *(void **)&p_glGetFramebufferAttachmentParameteriv = dlsym(h, "glGetFramebufferAttachmentParameteriv"); if (p_glGetFramebufferAttachmentParameteriv) n++;
    *(void **)&p_glGetFramebufferParameteriv = dlsym(h, "glGetFramebufferParameteriv"); if (p_glGetFramebufferParameteriv) n++;
    *(void **)&p_glGetGraphicsResetStatus = dlsym(h, "glGetGraphicsResetStatus"); if (p_glGetGraphicsResetStatus) n++;
    *(void **)&p_glGetInteger64i_v = dlsym(h, "glGetInteger64i_v"); if (p_glGetInteger64i_v) n++;
    *(void **)&p_glGetInteger64v = dlsym(h, "glGetInteger64v"); if (p_glGetInteger64v) n++;
    *(void **)&p_glGetIntegeri_v = dlsym(h, "glGetIntegeri_v"); if (p_glGetIntegeri_v) n++;
    *(void **)&p_glGetIntegerv = dlsym(h, "glGetIntegerv"); if (p_glGetIntegerv) n++;
    *(void **)&p_glGetInternalformati64v = dlsym(h, "glGetInternalformati64v"); if (p_glGetInternalformati64v) n++;
    *(void **)&p_glGetInternalformativ = dlsym(h, "glGetInternalformativ"); if (p_glGetInternalformativ) n++;
    *(void **)&p_glGetLightfv = dlsym(h, "glGetLightfv"); if (p_glGetLightfv) n++;
    *(void **)&p_glGetLightiv = dlsym(h, "glGetLightiv"); if (p_glGetLightiv) n++;
    *(void **)&p_glGetMapdv = dlsym(h, "glGetMapdv"); if (p_glGetMapdv) n++;
    *(void **)&p_glGetMapfv = dlsym(h, "glGetMapfv"); if (p_glGetMapfv) n++;
    *(void **)&p_glGetMapiv = dlsym(h, "glGetMapiv"); if (p_glGetMapiv) n++;
    *(void **)&p_glGetMaterialfv = dlsym(h, "glGetMaterialfv"); if (p_glGetMaterialfv) n++;
    *(void **)&p_glGetMaterialiv = dlsym(h, "glGetMaterialiv"); if (p_glGetMaterialiv) n++;
    *(void **)&p_glGetMultisamplefv = dlsym(h, "glGetMultisamplefv"); if (p_glGetMultisamplefv) n++;
    *(void **)&p_glGetNamedBufferParameteri64v = dlsym(h, "glGetNamedBufferParameteri64v"); if (p_glGetNamedBufferParameteri64v) n++;
    *(void **)&p_glGetNamedBufferParameteriv = dlsym(h, "glGetNamedBufferParameteriv"); if (p_glGetNamedBufferParameteriv) n++;
    *(void **)&p_glGetNamedBufferPointerv = dlsym(h, "glGetNamedBufferPointerv"); if (p_glGetNamedBufferPointerv) n++;
    *(void **)&p_glGetNamedBufferSubData = dlsym(h, "glGetNamedBufferSubData"); if (p_glGetNamedBufferSubData) n++;
    *(void **)&p_glGetNamedFramebufferAttachmentParameteriv = dlsym(h, "glGetNamedFramebufferAttachmentParameteriv"); if (p_glGetNamedFramebufferAttachmentParameteriv) n++;
    *(void **)&p_glGetNamedFramebufferParameteriv = dlsym(h, "glGetNamedFramebufferParameteriv"); if (p_glGetNamedFramebufferParameteriv) n++;
    *(void **)&p_glGetNamedRenderbufferParameteriv = dlsym(h, "glGetNamedRenderbufferParameteriv"); if (p_glGetNamedRenderbufferParameteriv) n++;
    *(void **)&p_glGetObjectLabel = dlsym(h, "glGetObjectLabel"); if (p_glGetObjectLabel) n++;
    *(void **)&p_glGetObjectPtrLabel = dlsym(h, "glGetObjectPtrLabel"); if (p_glGetObjectPtrLabel) n++;
    *(void **)&p_glGetPixelMapfv = dlsym(h, "glGetPixelMapfv"); if (p_glGetPixelMapfv) n++;
    *(void **)&p_glGetPixelMapuiv = dlsym(h, "glGetPixelMapuiv"); if (p_glGetPixelMapuiv) n++;
    *(void **)&p_glGetPixelMapusv = dlsym(h, "glGetPixelMapusv"); if (p_glGetPixelMapusv) n++;
    *(void **)&p_glGetPointerv = dlsym(h, "glGetPointerv"); if (p_glGetPointerv) n++;
    *(void **)&p_glGetPolygonStipple = dlsym(h, "glGetPolygonStipple"); if (p_glGetPolygonStipple) n++;
    *(void **)&p_glGetProgramBinary = dlsym(h, "glGetProgramBinary"); if (p_glGetProgramBinary) n++;
    *(void **)&p_glGetProgramInfoLog = dlsym(h, "glGetProgramInfoLog"); if (p_glGetProgramInfoLog) n++;
    *(void **)&p_glGetProgramInterfaceiv = dlsym(h, "glGetProgramInterfaceiv"); if (p_glGetProgramInterfaceiv) n++;
    *(void **)&p_glGetProgramPipelineInfoLog = dlsym(h, "glGetProgramPipelineInfoLog"); if (p_glGetProgramPipelineInfoLog) n++;
    *(void **)&p_glGetProgramPipelineiv = dlsym(h, "glGetProgramPipelineiv"); if (p_glGetProgramPipelineiv) n++;
    *(void **)&p_glGetProgramResourceIndex = dlsym(h, "glGetProgramResourceIndex"); if (p_glGetProgramResourceIndex) n++;
    *(void **)&p_glGetProgramResourceLocation = dlsym(h, "glGetProgramResourceLocation"); if (p_glGetProgramResourceLocation) n++;
    *(void **)&p_glGetProgramResourceLocationIndex = dlsym(h, "glGetProgramResourceLocationIndex"); if (p_glGetProgramResourceLocationIndex) n++;
    *(void **)&p_glGetProgramResourceName = dlsym(h, "glGetProgramResourceName"); if (p_glGetProgramResourceName) n++;
    *(void **)&p_glGetProgramResourceiv = dlsym(h, "glGetProgramResourceiv"); if (p_glGetProgramResourceiv) n++;
    *(void **)&p_glGetProgramStageiv = dlsym(h, "glGetProgramStageiv"); if (p_glGetProgramStageiv) n++;
    *(void **)&p_glGetProgramiv = dlsym(h, "glGetProgramiv"); if (p_glGetProgramiv) n++;
    *(void **)&p_glGetQueryBufferObjecti64v = dlsym(h, "glGetQueryBufferObjecti64v"); if (p_glGetQueryBufferObjecti64v) n++;
    *(void **)&p_glGetQueryBufferObjectiv = dlsym(h, "glGetQueryBufferObjectiv"); if (p_glGetQueryBufferObjectiv) n++;
    *(void **)&p_glGetQueryBufferObjectui64v = dlsym(h, "glGetQueryBufferObjectui64v"); if (p_glGetQueryBufferObjectui64v) n++;
    *(void **)&p_glGetQueryBufferObjectuiv = dlsym(h, "glGetQueryBufferObjectuiv"); if (p_glGetQueryBufferObjectuiv) n++;
    *(void **)&p_glGetQueryIndexediv = dlsym(h, "glGetQueryIndexediv"); if (p_glGetQueryIndexediv) n++;
    *(void **)&p_glGetQueryObjecti64v = dlsym(h, "glGetQueryObjecti64v"); if (p_glGetQueryObjecti64v) n++;
    *(void **)&p_glGetQueryObjectiv = dlsym(h, "glGetQueryObjectiv"); if (p_glGetQueryObjectiv) n++;
    *(void **)&p_glGetQueryObjectui64v = dlsym(h, "glGetQueryObjectui64v"); if (p_glGetQueryObjectui64v) n++;
    *(void **)&p_glGetQueryObjectuiv = dlsym(h, "glGetQueryObjectuiv"); if (p_glGetQueryObjectuiv) n++;
    *(void **)&p_glGetQueryiv = dlsym(h, "glGetQueryiv"); if (p_glGetQueryiv) n++;
    *(void **)&p_glGetRenderbufferParameteriv = dlsym(h, "glGetRenderbufferParameteriv"); if (p_glGetRenderbufferParameteriv) n++;
    *(void **)&p_glGetSamplerParameterIiv = dlsym(h, "glGetSamplerParameterIiv"); if (p_glGetSamplerParameterIiv) n++;
    *(void **)&p_glGetSamplerParameterIuiv = dlsym(h, "glGetSamplerParameterIuiv"); if (p_glGetSamplerParameterIuiv) n++;
    *(void **)&p_glGetSamplerParameterfv = dlsym(h, "glGetSamplerParameterfv"); if (p_glGetSamplerParameterfv) n++;
    *(void **)&p_glGetSamplerParameteriv = dlsym(h, "glGetSamplerParameteriv"); if (p_glGetSamplerParameteriv) n++;
    *(void **)&p_glGetShaderInfoLog = dlsym(h, "glGetShaderInfoLog"); if (p_glGetShaderInfoLog) n++;
    *(void **)&p_glGetShaderPrecisionFormat = dlsym(h, "glGetShaderPrecisionFormat"); if (p_glGetShaderPrecisionFormat) n++;
    *(void **)&p_glGetShaderSource = dlsym(h, "glGetShaderSource"); if (p_glGetShaderSource) n++;
    *(void **)&p_glGetShaderiv = dlsym(h, "glGetShaderiv"); if (p_glGetShaderiv) n++;
    *(void **)&p_glGetString = dlsym(h, "glGetString"); if (p_glGetString) n++;
    *(void **)&p_glGetStringi = dlsym(h, "glGetStringi"); if (p_glGetStringi) n++;
    *(void **)&p_glGetSubroutineIndex = dlsym(h, "glGetSubroutineIndex"); if (p_glGetSubroutineIndex) n++;
    *(void **)&p_glGetSubroutineUniformLocation = dlsym(h, "glGetSubroutineUniformLocation"); if (p_glGetSubroutineUniformLocation) n++;
    *(void **)&p_glGetSynciv = dlsym(h, "glGetSynciv"); if (p_glGetSynciv) n++;
    *(void **)&p_glGetTexEnvfv = dlsym(h, "glGetTexEnvfv"); if (p_glGetTexEnvfv) n++;
    *(void **)&p_glGetTexEnviv = dlsym(h, "glGetTexEnviv"); if (p_glGetTexEnviv) n++;
    *(void **)&p_glGetTexGendv = dlsym(h, "glGetTexGendv"); if (p_glGetTexGendv) n++;
    *(void **)&p_glGetTexGenfv = dlsym(h, "glGetTexGenfv"); if (p_glGetTexGenfv) n++;
    *(void **)&p_glGetTexGeniv = dlsym(h, "glGetTexGeniv"); if (p_glGetTexGeniv) n++;
    *(void **)&p_glGetTexImage = dlsym(h, "glGetTexImage"); if (p_glGetTexImage) n++;
    *(void **)&p_glGetTexLevelParameterfv = dlsym(h, "glGetTexLevelParameterfv"); if (p_glGetTexLevelParameterfv) n++;
    *(void **)&p_glGetTexLevelParameteriv = dlsym(h, "glGetTexLevelParameteriv"); if (p_glGetTexLevelParameteriv) n++;
    *(void **)&p_glGetTexParameterIiv = dlsym(h, "glGetTexParameterIiv"); if (p_glGetTexParameterIiv) n++;
    *(void **)&p_glGetTexParameterIuiv = dlsym(h, "glGetTexParameterIuiv"); if (p_glGetTexParameterIuiv) n++;
    *(void **)&p_glGetTexParameterfv = dlsym(h, "glGetTexParameterfv"); if (p_glGetTexParameterfv) n++;
    *(void **)&p_glGetTexParameteriv = dlsym(h, "glGetTexParameteriv"); if (p_glGetTexParameteriv) n++;
    *(void **)&p_glGetTextureImage = dlsym(h, "glGetTextureImage"); if (p_glGetTextureImage) n++;
    *(void **)&p_glGetTextureLevelParameterfv = dlsym(h, "glGetTextureLevelParameterfv"); if (p_glGetTextureLevelParameterfv) n++;
    *(void **)&p_glGetTextureLevelParameteriv = dlsym(h, "glGetTextureLevelParameteriv"); if (p_glGetTextureLevelParameteriv) n++;
    *(void **)&p_glGetTextureParameterIiv = dlsym(h, "glGetTextureParameterIiv"); if (p_glGetTextureParameterIiv) n++;
    *(void **)&p_glGetTextureParameterIuiv = dlsym(h, "glGetTextureParameterIuiv"); if (p_glGetTextureParameterIuiv) n++;
    *(void **)&p_glGetTextureParameterfv = dlsym(h, "glGetTextureParameterfv"); if (p_glGetTextureParameterfv) n++;
    *(void **)&p_glGetTextureParameteriv = dlsym(h, "glGetTextureParameteriv"); if (p_glGetTextureParameteriv) n++;
    *(void **)&p_glGetTextureSubImage = dlsym(h, "glGetTextureSubImage"); if (p_glGetTextureSubImage) n++;
    *(void **)&p_glGetTransformFeedbackVarying = dlsym(h, "glGetTransformFeedbackVarying"); if (p_glGetTransformFeedbackVarying) n++;
    *(void **)&p_glGetTransformFeedbacki64_v = dlsym(h, "glGetTransformFeedbacki64_v"); if (p_glGetTransformFeedbacki64_v) n++;
    *(void **)&p_glGetTransformFeedbacki_v = dlsym(h, "glGetTransformFeedbacki_v"); if (p_glGetTransformFeedbacki_v) n++;
    *(void **)&p_glGetTransformFeedbackiv = dlsym(h, "glGetTransformFeedbackiv"); if (p_glGetTransformFeedbackiv) n++;
    *(void **)&p_glGetUniformBlockIndex = dlsym(h, "glGetUniformBlockIndex"); if (p_glGetUniformBlockIndex) n++;
    *(void **)&p_glGetUniformIndices = dlsym(h, "glGetUniformIndices"); if (p_glGetUniformIndices) n++;
    *(void **)&p_glGetUniformLocation = dlsym(h, "glGetUniformLocation"); if (p_glGetUniformLocation) n++;
    *(void **)&p_glGetUniformSubroutineuiv = dlsym(h, "glGetUniformSubroutineuiv"); if (p_glGetUniformSubroutineuiv) n++;
    *(void **)&p_glGetUniformdv = dlsym(h, "glGetUniformdv"); if (p_glGetUniformdv) n++;
    *(void **)&p_glGetUniformfv = dlsym(h, "glGetUniformfv"); if (p_glGetUniformfv) n++;
    *(void **)&p_glGetUniformiv = dlsym(h, "glGetUniformiv"); if (p_glGetUniformiv) n++;
    *(void **)&p_glGetUniformuiv = dlsym(h, "glGetUniformuiv"); if (p_glGetUniformuiv) n++;
    *(void **)&p_glGetVertexArrayIndexed64iv = dlsym(h, "glGetVertexArrayIndexed64iv"); if (p_glGetVertexArrayIndexed64iv) n++;
    *(void **)&p_glGetVertexArrayIndexediv = dlsym(h, "glGetVertexArrayIndexediv"); if (p_glGetVertexArrayIndexediv) n++;
    *(void **)&p_glGetVertexArrayiv = dlsym(h, "glGetVertexArrayiv"); if (p_glGetVertexArrayiv) n++;
    *(void **)&p_glGetVertexAttribIiv = dlsym(h, "glGetVertexAttribIiv"); if (p_glGetVertexAttribIiv) n++;
    *(void **)&p_glGetVertexAttribIuiv = dlsym(h, "glGetVertexAttribIuiv"); if (p_glGetVertexAttribIuiv) n++;
    *(void **)&p_glGetVertexAttribLdv = dlsym(h, "glGetVertexAttribLdv"); if (p_glGetVertexAttribLdv) n++;
    *(void **)&p_glGetVertexAttribPointerv = dlsym(h, "glGetVertexAttribPointerv"); if (p_glGetVertexAttribPointerv) n++;
    *(void **)&p_glGetVertexAttribdv = dlsym(h, "glGetVertexAttribdv"); if (p_glGetVertexAttribdv) n++;
    *(void **)&p_glGetVertexAttribfv = dlsym(h, "glGetVertexAttribfv"); if (p_glGetVertexAttribfv) n++;
    *(void **)&p_glGetVertexAttribiv = dlsym(h, "glGetVertexAttribiv"); if (p_glGetVertexAttribiv) n++;
    *(void **)&p_glGetnColorTable = dlsym(h, "glGetnColorTable"); if (p_glGetnColorTable) n++;
    *(void **)&p_glGetnCompressedTexImage = dlsym(h, "glGetnCompressedTexImage"); if (p_glGetnCompressedTexImage) n++;
    *(void **)&p_glGetnConvolutionFilter = dlsym(h, "glGetnConvolutionFilter"); if (p_glGetnConvolutionFilter) n++;
    *(void **)&p_glGetnHistogram = dlsym(h, "glGetnHistogram"); if (p_glGetnHistogram) n++;
    *(void **)&p_glGetnMapdv = dlsym(h, "glGetnMapdv"); if (p_glGetnMapdv) n++;
    *(void **)&p_glGetnMapfv = dlsym(h, "glGetnMapfv"); if (p_glGetnMapfv) n++;
    *(void **)&p_glGetnMapiv = dlsym(h, "glGetnMapiv"); if (p_glGetnMapiv) n++;
    *(void **)&p_glGetnMinmax = dlsym(h, "glGetnMinmax"); if (p_glGetnMinmax) n++;
    *(void **)&p_glGetnPixelMapfv = dlsym(h, "glGetnPixelMapfv"); if (p_glGetnPixelMapfv) n++;
    *(void **)&p_glGetnPixelMapuiv = dlsym(h, "glGetnPixelMapuiv"); if (p_glGetnPixelMapuiv) n++;
    *(void **)&p_glGetnPixelMapusv = dlsym(h, "glGetnPixelMapusv"); if (p_glGetnPixelMapusv) n++;
    *(void **)&p_glGetnPolygonStipple = dlsym(h, "glGetnPolygonStipple"); if (p_glGetnPolygonStipple) n++;
    *(void **)&p_glGetnSeparableFilter = dlsym(h, "glGetnSeparableFilter"); if (p_glGetnSeparableFilter) n++;
    *(void **)&p_glGetnTexImage = dlsym(h, "glGetnTexImage"); if (p_glGetnTexImage) n++;
    *(void **)&p_glGetnUniformdv = dlsym(h, "glGetnUniformdv"); if (p_glGetnUniformdv) n++;
    *(void **)&p_glGetnUniformfv = dlsym(h, "glGetnUniformfv"); if (p_glGetnUniformfv) n++;
    *(void **)&p_glGetnUniformiv = dlsym(h, "glGetnUniformiv"); if (p_glGetnUniformiv) n++;
    *(void **)&p_glGetnUniformuiv = dlsym(h, "glGetnUniformuiv"); if (p_glGetnUniformuiv) n++;
    *(void **)&p_glHint = dlsym(h, "glHint"); if (p_glHint) n++;
    *(void **)&p_glIndexMask = dlsym(h, "glIndexMask"); if (p_glIndexMask) n++;
    *(void **)&p_glIndexPointer = dlsym(h, "glIndexPointer"); if (p_glIndexPointer) n++;
    *(void **)&p_glIndexd = dlsym(h, "glIndexd"); if (p_glIndexd) n++;
    *(void **)&p_glIndexdv = dlsym(h, "glIndexdv"); if (p_glIndexdv) n++;
    *(void **)&p_glIndexf = dlsym(h, "glIndexf"); if (p_glIndexf) n++;
    *(void **)&p_glIndexfv = dlsym(h, "glIndexfv"); if (p_glIndexfv) n++;
    *(void **)&p_glIndexi = dlsym(h, "glIndexi"); if (p_glIndexi) n++;
    *(void **)&p_glIndexiv = dlsym(h, "glIndexiv"); if (p_glIndexiv) n++;
    *(void **)&p_glIndexs = dlsym(h, "glIndexs"); if (p_glIndexs) n++;
    *(void **)&p_glIndexsv = dlsym(h, "glIndexsv"); if (p_glIndexsv) n++;
    *(void **)&p_glIndexub = dlsym(h, "glIndexub"); if (p_glIndexub) n++;
    *(void **)&p_glIndexubv = dlsym(h, "glIndexubv"); if (p_glIndexubv) n++;
    *(void **)&p_glInitNames = dlsym(h, "glInitNames"); if (p_glInitNames) n++;
    *(void **)&p_glInterleavedArrays = dlsym(h, "glInterleavedArrays"); if (p_glInterleavedArrays) n++;
    *(void **)&p_glInvalidateBufferData = dlsym(h, "glInvalidateBufferData"); if (p_glInvalidateBufferData) n++;
    *(void **)&p_glInvalidateBufferSubData = dlsym(h, "glInvalidateBufferSubData"); if (p_glInvalidateBufferSubData) n++;
    *(void **)&p_glInvalidateFramebuffer = dlsym(h, "glInvalidateFramebuffer"); if (p_glInvalidateFramebuffer) n++;
    *(void **)&p_glInvalidateNamedFramebufferData = dlsym(h, "glInvalidateNamedFramebufferData"); if (p_glInvalidateNamedFramebufferData) n++;
    *(void **)&p_glInvalidateNamedFramebufferSubData = dlsym(h, "glInvalidateNamedFramebufferSubData"); if (p_glInvalidateNamedFramebufferSubData) n++;
    *(void **)&p_glInvalidateSubFramebuffer = dlsym(h, "glInvalidateSubFramebuffer"); if (p_glInvalidateSubFramebuffer) n++;
    *(void **)&p_glInvalidateTexImage = dlsym(h, "glInvalidateTexImage"); if (p_glInvalidateTexImage) n++;
    *(void **)&p_glInvalidateTexSubImage = dlsym(h, "glInvalidateTexSubImage"); if (p_glInvalidateTexSubImage) n++;
    *(void **)&p_glIsBuffer = dlsym(h, "glIsBuffer"); if (p_glIsBuffer) n++;
    *(void **)&p_glIsEnabled = dlsym(h, "glIsEnabled"); if (p_glIsEnabled) n++;
    *(void **)&p_glIsEnabledi = dlsym(h, "glIsEnabledi"); if (p_glIsEnabledi) n++;
    *(void **)&p_glIsFramebuffer = dlsym(h, "glIsFramebuffer"); if (p_glIsFramebuffer) n++;
    *(void **)&p_glIsList = dlsym(h, "glIsList"); if (p_glIsList) n++;
    *(void **)&p_glIsProgram = dlsym(h, "glIsProgram"); if (p_glIsProgram) n++;
    *(void **)&p_glIsProgramPipeline = dlsym(h, "glIsProgramPipeline"); if (p_glIsProgramPipeline) n++;
    *(void **)&p_glIsQuery = dlsym(h, "glIsQuery"); if (p_glIsQuery) n++;
    *(void **)&p_glIsRenderbuffer = dlsym(h, "glIsRenderbuffer"); if (p_glIsRenderbuffer) n++;
    *(void **)&p_glIsSampler = dlsym(h, "glIsSampler"); if (p_glIsSampler) n++;
    *(void **)&p_glIsShader = dlsym(h, "glIsShader"); if (p_glIsShader) n++;
    *(void **)&p_glIsSync = dlsym(h, "glIsSync"); if (p_glIsSync) n++;
    *(void **)&p_glIsTexture = dlsym(h, "glIsTexture"); if (p_glIsTexture) n++;
    *(void **)&p_glIsTransformFeedback = dlsym(h, "glIsTransformFeedback"); if (p_glIsTransformFeedback) n++;
    *(void **)&p_glIsVertexArray = dlsym(h, "glIsVertexArray"); if (p_glIsVertexArray) n++;
    *(void **)&p_glLightModelf = dlsym(h, "glLightModelf"); if (p_glLightModelf) n++;
    *(void **)&p_glLightModelfv = dlsym(h, "glLightModelfv"); if (p_glLightModelfv) n++;
    *(void **)&p_glLightModeli = dlsym(h, "glLightModeli"); if (p_glLightModeli) n++;
    *(void **)&p_glLightModeliv = dlsym(h, "glLightModeliv"); if (p_glLightModeliv) n++;
    *(void **)&p_glLightf = dlsym(h, "glLightf"); if (p_glLightf) n++;
    *(void **)&p_glLightfv = dlsym(h, "glLightfv"); if (p_glLightfv) n++;
    *(void **)&p_glLighti = dlsym(h, "glLighti"); if (p_glLighti) n++;
    *(void **)&p_glLightiv = dlsym(h, "glLightiv"); if (p_glLightiv) n++;
    *(void **)&p_glLineStipple = dlsym(h, "glLineStipple"); if (p_glLineStipple) n++;
    *(void **)&p_glLineWidth = dlsym(h, "glLineWidth"); if (p_glLineWidth) n++;
    *(void **)&p_glLinkProgram = dlsym(h, "glLinkProgram"); if (p_glLinkProgram) n++;
    *(void **)&p_glListBase = dlsym(h, "glListBase"); if (p_glListBase) n++;
    *(void **)&p_glLoadIdentity = dlsym(h, "glLoadIdentity"); if (p_glLoadIdentity) n++;
    *(void **)&p_glLoadMatrixd = dlsym(h, "glLoadMatrixd"); if (p_glLoadMatrixd) n++;
    *(void **)&p_glLoadMatrixf = dlsym(h, "glLoadMatrixf"); if (p_glLoadMatrixf) n++;
    *(void **)&p_glLoadName = dlsym(h, "glLoadName"); if (p_glLoadName) n++;
    *(void **)&p_glLoadTransposeMatrixd = dlsym(h, "glLoadTransposeMatrixd"); if (p_glLoadTransposeMatrixd) n++;
    *(void **)&p_glLoadTransposeMatrixf = dlsym(h, "glLoadTransposeMatrixf"); if (p_glLoadTransposeMatrixf) n++;
    *(void **)&p_glLogicOp = dlsym(h, "glLogicOp"); if (p_glLogicOp) n++;
    *(void **)&p_glMap1d = dlsym(h, "glMap1d"); if (p_glMap1d) n++;
    *(void **)&p_glMap1f = dlsym(h, "glMap1f"); if (p_glMap1f) n++;
    *(void **)&p_glMap2d = dlsym(h, "glMap2d"); if (p_glMap2d) n++;
    *(void **)&p_glMap2f = dlsym(h, "glMap2f"); if (p_glMap2f) n++;
    *(void **)&p_glMapBuffer = dlsym(h, "glMapBuffer"); if (p_glMapBuffer) n++;
    *(void **)&p_glMapBufferRange = dlsym(h, "glMapBufferRange"); if (p_glMapBufferRange) n++;
    *(void **)&p_glMapGrid1d = dlsym(h, "glMapGrid1d"); if (p_glMapGrid1d) n++;
    *(void **)&p_glMapGrid1f = dlsym(h, "glMapGrid1f"); if (p_glMapGrid1f) n++;
    *(void **)&p_glMapGrid2d = dlsym(h, "glMapGrid2d"); if (p_glMapGrid2d) n++;
    *(void **)&p_glMapGrid2f = dlsym(h, "glMapGrid2f"); if (p_glMapGrid2f) n++;
    *(void **)&p_glMapNamedBuffer = dlsym(h, "glMapNamedBuffer"); if (p_glMapNamedBuffer) n++;
    *(void **)&p_glMapNamedBufferRange = dlsym(h, "glMapNamedBufferRange"); if (p_glMapNamedBufferRange) n++;
    *(void **)&p_glMaterialf = dlsym(h, "glMaterialf"); if (p_glMaterialf) n++;
    *(void **)&p_glMaterialfv = dlsym(h, "glMaterialfv"); if (p_glMaterialfv) n++;
    *(void **)&p_glMateriali = dlsym(h, "glMateriali"); if (p_glMateriali) n++;
    *(void **)&p_glMaterialiv = dlsym(h, "glMaterialiv"); if (p_glMaterialiv) n++;
    *(void **)&p_glMatrixMode = dlsym(h, "glMatrixMode"); if (p_glMatrixMode) n++;
    *(void **)&p_glMemoryBarrier = dlsym(h, "glMemoryBarrier"); if (p_glMemoryBarrier) n++;
    *(void **)&p_glMemoryBarrierByRegion = dlsym(h, "glMemoryBarrierByRegion"); if (p_glMemoryBarrierByRegion) n++;
    *(void **)&p_glMinSampleShading = dlsym(h, "glMinSampleShading"); if (p_glMinSampleShading) n++;
    *(void **)&p_glMultMatrixd = dlsym(h, "glMultMatrixd"); if (p_glMultMatrixd) n++;
    *(void **)&p_glMultMatrixf = dlsym(h, "glMultMatrixf"); if (p_glMultMatrixf) n++;
    *(void **)&p_glMultTransposeMatrixd = dlsym(h, "glMultTransposeMatrixd"); if (p_glMultTransposeMatrixd) n++;
    *(void **)&p_glMultTransposeMatrixf = dlsym(h, "glMultTransposeMatrixf"); if (p_glMultTransposeMatrixf) n++;
    *(void **)&p_glMultiDrawArrays = dlsym(h, "glMultiDrawArrays"); if (p_glMultiDrawArrays) n++;
    *(void **)&p_glMultiDrawArraysIndirect = dlsym(h, "glMultiDrawArraysIndirect"); if (p_glMultiDrawArraysIndirect) n++;
    *(void **)&p_glMultiDrawArraysIndirectCount = dlsym(h, "glMultiDrawArraysIndirectCount"); if (p_glMultiDrawArraysIndirectCount) n++;
    *(void **)&p_glMultiDrawElements = dlsym(h, "glMultiDrawElements"); if (p_glMultiDrawElements) n++;
    *(void **)&p_glMultiDrawElementsBaseVertex = dlsym(h, "glMultiDrawElementsBaseVertex"); if (p_glMultiDrawElementsBaseVertex) n++;
    *(void **)&p_glMultiDrawElementsIndirect = dlsym(h, "glMultiDrawElementsIndirect"); if (p_glMultiDrawElementsIndirect) n++;
    *(void **)&p_glMultiDrawElementsIndirectCount = dlsym(h, "glMultiDrawElementsIndirectCount"); if (p_glMultiDrawElementsIndirectCount) n++;
    *(void **)&p_glMultiTexCoord1d = dlsym(h, "glMultiTexCoord1d"); if (p_glMultiTexCoord1d) n++;
    *(void **)&p_glMultiTexCoord1dv = dlsym(h, "glMultiTexCoord1dv"); if (p_glMultiTexCoord1dv) n++;
    *(void **)&p_glMultiTexCoord1f = dlsym(h, "glMultiTexCoord1f"); if (p_glMultiTexCoord1f) n++;
    *(void **)&p_glMultiTexCoord1fv = dlsym(h, "glMultiTexCoord1fv"); if (p_glMultiTexCoord1fv) n++;
    *(void **)&p_glMultiTexCoord1i = dlsym(h, "glMultiTexCoord1i"); if (p_glMultiTexCoord1i) n++;
    *(void **)&p_glMultiTexCoord1iv = dlsym(h, "glMultiTexCoord1iv"); if (p_glMultiTexCoord1iv) n++;
    *(void **)&p_glMultiTexCoord1s = dlsym(h, "glMultiTexCoord1s"); if (p_glMultiTexCoord1s) n++;
    *(void **)&p_glMultiTexCoord1sv = dlsym(h, "glMultiTexCoord1sv"); if (p_glMultiTexCoord1sv) n++;
    *(void **)&p_glMultiTexCoord2d = dlsym(h, "glMultiTexCoord2d"); if (p_glMultiTexCoord2d) n++;
    *(void **)&p_glMultiTexCoord2dv = dlsym(h, "glMultiTexCoord2dv"); if (p_glMultiTexCoord2dv) n++;
    *(void **)&p_glMultiTexCoord2f = dlsym(h, "glMultiTexCoord2f"); if (p_glMultiTexCoord2f) n++;
    *(void **)&p_glMultiTexCoord2fv = dlsym(h, "glMultiTexCoord2fv"); if (p_glMultiTexCoord2fv) n++;
    *(void **)&p_glMultiTexCoord2i = dlsym(h, "glMultiTexCoord2i"); if (p_glMultiTexCoord2i) n++;
    *(void **)&p_glMultiTexCoord2iv = dlsym(h, "glMultiTexCoord2iv"); if (p_glMultiTexCoord2iv) n++;
    *(void **)&p_glMultiTexCoord2s = dlsym(h, "glMultiTexCoord2s"); if (p_glMultiTexCoord2s) n++;
    *(void **)&p_glMultiTexCoord2sv = dlsym(h, "glMultiTexCoord2sv"); if (p_glMultiTexCoord2sv) n++;
    *(void **)&p_glMultiTexCoord3d = dlsym(h, "glMultiTexCoord3d"); if (p_glMultiTexCoord3d) n++;
    *(void **)&p_glMultiTexCoord3dv = dlsym(h, "glMultiTexCoord3dv"); if (p_glMultiTexCoord3dv) n++;
    *(void **)&p_glMultiTexCoord3f = dlsym(h, "glMultiTexCoord3f"); if (p_glMultiTexCoord3f) n++;
    *(void **)&p_glMultiTexCoord3fv = dlsym(h, "glMultiTexCoord3fv"); if (p_glMultiTexCoord3fv) n++;
    *(void **)&p_glMultiTexCoord3i = dlsym(h, "glMultiTexCoord3i"); if (p_glMultiTexCoord3i) n++;
    *(void **)&p_glMultiTexCoord3iv = dlsym(h, "glMultiTexCoord3iv"); if (p_glMultiTexCoord3iv) n++;
    *(void **)&p_glMultiTexCoord3s = dlsym(h, "glMultiTexCoord3s"); if (p_glMultiTexCoord3s) n++;
    *(void **)&p_glMultiTexCoord3sv = dlsym(h, "glMultiTexCoord3sv"); if (p_glMultiTexCoord3sv) n++;
    *(void **)&p_glMultiTexCoord4d = dlsym(h, "glMultiTexCoord4d"); if (p_glMultiTexCoord4d) n++;
    *(void **)&p_glMultiTexCoord4dv = dlsym(h, "glMultiTexCoord4dv"); if (p_glMultiTexCoord4dv) n++;
    *(void **)&p_glMultiTexCoord4f = dlsym(h, "glMultiTexCoord4f"); if (p_glMultiTexCoord4f) n++;
    *(void **)&p_glMultiTexCoord4fv = dlsym(h, "glMultiTexCoord4fv"); if (p_glMultiTexCoord4fv) n++;
    *(void **)&p_glMultiTexCoord4i = dlsym(h, "glMultiTexCoord4i"); if (p_glMultiTexCoord4i) n++;
    *(void **)&p_glMultiTexCoord4iv = dlsym(h, "glMultiTexCoord4iv"); if (p_glMultiTexCoord4iv) n++;
    *(void **)&p_glMultiTexCoord4s = dlsym(h, "glMultiTexCoord4s"); if (p_glMultiTexCoord4s) n++;
    *(void **)&p_glMultiTexCoord4sv = dlsym(h, "glMultiTexCoord4sv"); if (p_glMultiTexCoord4sv) n++;
    *(void **)&p_glMultiTexCoordP1ui = dlsym(h, "glMultiTexCoordP1ui"); if (p_glMultiTexCoordP1ui) n++;
    *(void **)&p_glMultiTexCoordP1uiv = dlsym(h, "glMultiTexCoordP1uiv"); if (p_glMultiTexCoordP1uiv) n++;
    *(void **)&p_glMultiTexCoordP2ui = dlsym(h, "glMultiTexCoordP2ui"); if (p_glMultiTexCoordP2ui) n++;
    *(void **)&p_glMultiTexCoordP2uiv = dlsym(h, "glMultiTexCoordP2uiv"); if (p_glMultiTexCoordP2uiv) n++;
    *(void **)&p_glMultiTexCoordP3ui = dlsym(h, "glMultiTexCoordP3ui"); if (p_glMultiTexCoordP3ui) n++;
    *(void **)&p_glMultiTexCoordP3uiv = dlsym(h, "glMultiTexCoordP3uiv"); if (p_glMultiTexCoordP3uiv) n++;
    *(void **)&p_glMultiTexCoordP4ui = dlsym(h, "glMultiTexCoordP4ui"); if (p_glMultiTexCoordP4ui) n++;
    *(void **)&p_glMultiTexCoordP4uiv = dlsym(h, "glMultiTexCoordP4uiv"); if (p_glMultiTexCoordP4uiv) n++;
    *(void **)&p_glNamedBufferData = dlsym(h, "glNamedBufferData"); if (p_glNamedBufferData) n++;
    *(void **)&p_glNamedBufferStorage = dlsym(h, "glNamedBufferStorage"); if (p_glNamedBufferStorage) n++;
    *(void **)&p_glNamedBufferSubData = dlsym(h, "glNamedBufferSubData"); if (p_glNamedBufferSubData) n++;
    *(void **)&p_glNamedFramebufferDrawBuffer = dlsym(h, "glNamedFramebufferDrawBuffer"); if (p_glNamedFramebufferDrawBuffer) n++;
    *(void **)&p_glNamedFramebufferDrawBuffers = dlsym(h, "glNamedFramebufferDrawBuffers"); if (p_glNamedFramebufferDrawBuffers) n++;
    *(void **)&p_glNamedFramebufferParameteri = dlsym(h, "glNamedFramebufferParameteri"); if (p_glNamedFramebufferParameteri) n++;
    *(void **)&p_glNamedFramebufferReadBuffer = dlsym(h, "glNamedFramebufferReadBuffer"); if (p_glNamedFramebufferReadBuffer) n++;
    *(void **)&p_glNamedFramebufferRenderbuffer = dlsym(h, "glNamedFramebufferRenderbuffer"); if (p_glNamedFramebufferRenderbuffer) n++;
    *(void **)&p_glNamedFramebufferTexture = dlsym(h, "glNamedFramebufferTexture"); if (p_glNamedFramebufferTexture) n++;
    *(void **)&p_glNamedFramebufferTextureLayer = dlsym(h, "glNamedFramebufferTextureLayer"); if (p_glNamedFramebufferTextureLayer) n++;
    *(void **)&p_glNamedRenderbufferStorage = dlsym(h, "glNamedRenderbufferStorage"); if (p_glNamedRenderbufferStorage) n++;
    *(void **)&p_glNamedRenderbufferStorageMultisample = dlsym(h, "glNamedRenderbufferStorageMultisample"); if (p_glNamedRenderbufferStorageMultisample) n++;
    *(void **)&p_glNewList = dlsym(h, "glNewList"); if (p_glNewList) n++;
    *(void **)&p_glNormal3b = dlsym(h, "glNormal3b"); if (p_glNormal3b) n++;
    *(void **)&p_glNormal3bv = dlsym(h, "glNormal3bv"); if (p_glNormal3bv) n++;
    *(void **)&p_glNormal3d = dlsym(h, "glNormal3d"); if (p_glNormal3d) n++;
    *(void **)&p_glNormal3dv = dlsym(h, "glNormal3dv"); if (p_glNormal3dv) n++;
    *(void **)&p_glNormal3f = dlsym(h, "glNormal3f"); if (p_glNormal3f) n++;
    *(void **)&p_glNormal3fv = dlsym(h, "glNormal3fv"); if (p_glNormal3fv) n++;
    *(void **)&p_glNormal3i = dlsym(h, "glNormal3i"); if (p_glNormal3i) n++;
    *(void **)&p_glNormal3iv = dlsym(h, "glNormal3iv"); if (p_glNormal3iv) n++;
    *(void **)&p_glNormal3s = dlsym(h, "glNormal3s"); if (p_glNormal3s) n++;
    *(void **)&p_glNormal3sv = dlsym(h, "glNormal3sv"); if (p_glNormal3sv) n++;
    *(void **)&p_glNormalP3ui = dlsym(h, "glNormalP3ui"); if (p_glNormalP3ui) n++;
    *(void **)&p_glNormalP3uiv = dlsym(h, "glNormalP3uiv"); if (p_glNormalP3uiv) n++;
    *(void **)&p_glNormalPointer = dlsym(h, "glNormalPointer"); if (p_glNormalPointer) n++;
    *(void **)&p_glObjectLabel = dlsym(h, "glObjectLabel"); if (p_glObjectLabel) n++;
    *(void **)&p_glObjectPtrLabel = dlsym(h, "glObjectPtrLabel"); if (p_glObjectPtrLabel) n++;
    *(void **)&p_glOrtho = dlsym(h, "glOrtho"); if (p_glOrtho) n++;
    *(void **)&p_glPassThrough = dlsym(h, "glPassThrough"); if (p_glPassThrough) n++;
    *(void **)&p_glPatchParameterfv = dlsym(h, "glPatchParameterfv"); if (p_glPatchParameterfv) n++;
    *(void **)&p_glPatchParameteri = dlsym(h, "glPatchParameteri"); if (p_glPatchParameteri) n++;
    *(void **)&p_glPauseTransformFeedback = dlsym(h, "glPauseTransformFeedback"); if (p_glPauseTransformFeedback) n++;
    *(void **)&p_glPixelMapfv = dlsym(h, "glPixelMapfv"); if (p_glPixelMapfv) n++;
    *(void **)&p_glPixelMapuiv = dlsym(h, "glPixelMapuiv"); if (p_glPixelMapuiv) n++;
    *(void **)&p_glPixelMapusv = dlsym(h, "glPixelMapusv"); if (p_glPixelMapusv) n++;
    *(void **)&p_glPixelStoref = dlsym(h, "glPixelStoref"); if (p_glPixelStoref) n++;
    *(void **)&p_glPixelStorei = dlsym(h, "glPixelStorei"); if (p_glPixelStorei) n++;
    *(void **)&p_glPixelTransferf = dlsym(h, "glPixelTransferf"); if (p_glPixelTransferf) n++;
    *(void **)&p_glPixelTransferi = dlsym(h, "glPixelTransferi"); if (p_glPixelTransferi) n++;
    *(void **)&p_glPixelZoom = dlsym(h, "glPixelZoom"); if (p_glPixelZoom) n++;
    *(void **)&p_glPointParameterf = dlsym(h, "glPointParameterf"); if (p_glPointParameterf) n++;
    *(void **)&p_glPointParameterfv = dlsym(h, "glPointParameterfv"); if (p_glPointParameterfv) n++;
    *(void **)&p_glPointParameteri = dlsym(h, "glPointParameteri"); if (p_glPointParameteri) n++;
    *(void **)&p_glPointParameteriv = dlsym(h, "glPointParameteriv"); if (p_glPointParameteriv) n++;
    *(void **)&p_glPointSize = dlsym(h, "glPointSize"); if (p_glPointSize) n++;
    *(void **)&p_glPolygonMode = dlsym(h, "glPolygonMode"); if (p_glPolygonMode) n++;
    *(void **)&p_glPolygonOffset = dlsym(h, "glPolygonOffset"); if (p_glPolygonOffset) n++;
    *(void **)&p_glPolygonOffsetClamp = dlsym(h, "glPolygonOffsetClamp"); if (p_glPolygonOffsetClamp) n++;
    *(void **)&p_glPolygonStipple = dlsym(h, "glPolygonStipple"); if (p_glPolygonStipple) n++;
    *(void **)&p_glPopAttrib = dlsym(h, "glPopAttrib"); if (p_glPopAttrib) n++;
    *(void **)&p_glPopClientAttrib = dlsym(h, "glPopClientAttrib"); if (p_glPopClientAttrib) n++;
    *(void **)&p_glPopDebugGroup = dlsym(h, "glPopDebugGroup"); if (p_glPopDebugGroup) n++;
    *(void **)&p_glPopMatrix = dlsym(h, "glPopMatrix"); if (p_glPopMatrix) n++;
    *(void **)&p_glPopName = dlsym(h, "glPopName"); if (p_glPopName) n++;
    *(void **)&p_glPrimitiveRestartIndex = dlsym(h, "glPrimitiveRestartIndex"); if (p_glPrimitiveRestartIndex) n++;
    *(void **)&p_glPrioritizeTextures = dlsym(h, "glPrioritizeTextures"); if (p_glPrioritizeTextures) n++;
    *(void **)&p_glProgramBinary = dlsym(h, "glProgramBinary"); if (p_glProgramBinary) n++;
    *(void **)&p_glProgramParameteri = dlsym(h, "glProgramParameteri"); if (p_glProgramParameteri) n++;
    *(void **)&p_glProgramUniform1d = dlsym(h, "glProgramUniform1d"); if (p_glProgramUniform1d) n++;
    *(void **)&p_glProgramUniform1dv = dlsym(h, "glProgramUniform1dv"); if (p_glProgramUniform1dv) n++;
    *(void **)&p_glProgramUniform1f = dlsym(h, "glProgramUniform1f"); if (p_glProgramUniform1f) n++;
    *(void **)&p_glProgramUniform1fv = dlsym(h, "glProgramUniform1fv"); if (p_glProgramUniform1fv) n++;
    *(void **)&p_glProgramUniform1i = dlsym(h, "glProgramUniform1i"); if (p_glProgramUniform1i) n++;
    *(void **)&p_glProgramUniform1iv = dlsym(h, "glProgramUniform1iv"); if (p_glProgramUniform1iv) n++;
    *(void **)&p_glProgramUniform1ui = dlsym(h, "glProgramUniform1ui"); if (p_glProgramUniform1ui) n++;
    *(void **)&p_glProgramUniform1uiv = dlsym(h, "glProgramUniform1uiv"); if (p_glProgramUniform1uiv) n++;
    *(void **)&p_glProgramUniform2d = dlsym(h, "glProgramUniform2d"); if (p_glProgramUniform2d) n++;
    *(void **)&p_glProgramUniform2dv = dlsym(h, "glProgramUniform2dv"); if (p_glProgramUniform2dv) n++;
    *(void **)&p_glProgramUniform2f = dlsym(h, "glProgramUniform2f"); if (p_glProgramUniform2f) n++;
    *(void **)&p_glProgramUniform2fv = dlsym(h, "glProgramUniform2fv"); if (p_glProgramUniform2fv) n++;
    *(void **)&p_glProgramUniform2i = dlsym(h, "glProgramUniform2i"); if (p_glProgramUniform2i) n++;
    *(void **)&p_glProgramUniform2iv = dlsym(h, "glProgramUniform2iv"); if (p_glProgramUniform2iv) n++;
    *(void **)&p_glProgramUniform2ui = dlsym(h, "glProgramUniform2ui"); if (p_glProgramUniform2ui) n++;
    *(void **)&p_glProgramUniform2uiv = dlsym(h, "glProgramUniform2uiv"); if (p_glProgramUniform2uiv) n++;
    *(void **)&p_glProgramUniform3d = dlsym(h, "glProgramUniform3d"); if (p_glProgramUniform3d) n++;
    *(void **)&p_glProgramUniform3dv = dlsym(h, "glProgramUniform3dv"); if (p_glProgramUniform3dv) n++;
    *(void **)&p_glProgramUniform3f = dlsym(h, "glProgramUniform3f"); if (p_glProgramUniform3f) n++;
    *(void **)&p_glProgramUniform3fv = dlsym(h, "glProgramUniform3fv"); if (p_glProgramUniform3fv) n++;
    *(void **)&p_glProgramUniform3i = dlsym(h, "glProgramUniform3i"); if (p_glProgramUniform3i) n++;
    *(void **)&p_glProgramUniform3iv = dlsym(h, "glProgramUniform3iv"); if (p_glProgramUniform3iv) n++;
    *(void **)&p_glProgramUniform3ui = dlsym(h, "glProgramUniform3ui"); if (p_glProgramUniform3ui) n++;
    *(void **)&p_glProgramUniform3uiv = dlsym(h, "glProgramUniform3uiv"); if (p_glProgramUniform3uiv) n++;
    *(void **)&p_glProgramUniform4d = dlsym(h, "glProgramUniform4d"); if (p_glProgramUniform4d) n++;
    *(void **)&p_glProgramUniform4dv = dlsym(h, "glProgramUniform4dv"); if (p_glProgramUniform4dv) n++;
    *(void **)&p_glProgramUniform4f = dlsym(h, "glProgramUniform4f"); if (p_glProgramUniform4f) n++;
    *(void **)&p_glProgramUniform4fv = dlsym(h, "glProgramUniform4fv"); if (p_glProgramUniform4fv) n++;
    *(void **)&p_glProgramUniform4i = dlsym(h, "glProgramUniform4i"); if (p_glProgramUniform4i) n++;
    *(void **)&p_glProgramUniform4iv = dlsym(h, "glProgramUniform4iv"); if (p_glProgramUniform4iv) n++;
    *(void **)&p_glProgramUniform4ui = dlsym(h, "glProgramUniform4ui"); if (p_glProgramUniform4ui) n++;
    *(void **)&p_glProgramUniform4uiv = dlsym(h, "glProgramUniform4uiv"); if (p_glProgramUniform4uiv) n++;
    *(void **)&p_glProgramUniformMatrix2dv = dlsym(h, "glProgramUniformMatrix2dv"); if (p_glProgramUniformMatrix2dv) n++;
    *(void **)&p_glProgramUniformMatrix2fv = dlsym(h, "glProgramUniformMatrix2fv"); if (p_glProgramUniformMatrix2fv) n++;
    *(void **)&p_glProgramUniformMatrix2x3dv = dlsym(h, "glProgramUniformMatrix2x3dv"); if (p_glProgramUniformMatrix2x3dv) n++;
    *(void **)&p_glProgramUniformMatrix2x3fv = dlsym(h, "glProgramUniformMatrix2x3fv"); if (p_glProgramUniformMatrix2x3fv) n++;
    *(void **)&p_glProgramUniformMatrix2x4dv = dlsym(h, "glProgramUniformMatrix2x4dv"); if (p_glProgramUniformMatrix2x4dv) n++;
    *(void **)&p_glProgramUniformMatrix2x4fv = dlsym(h, "glProgramUniformMatrix2x4fv"); if (p_glProgramUniformMatrix2x4fv) n++;
    *(void **)&p_glProgramUniformMatrix3dv = dlsym(h, "glProgramUniformMatrix3dv"); if (p_glProgramUniformMatrix3dv) n++;
    *(void **)&p_glProgramUniformMatrix3fv = dlsym(h, "glProgramUniformMatrix3fv"); if (p_glProgramUniformMatrix3fv) n++;
    *(void **)&p_glProgramUniformMatrix3x2dv = dlsym(h, "glProgramUniformMatrix3x2dv"); if (p_glProgramUniformMatrix3x2dv) n++;
    *(void **)&p_glProgramUniformMatrix3x2fv = dlsym(h, "glProgramUniformMatrix3x2fv"); if (p_glProgramUniformMatrix3x2fv) n++;
    *(void **)&p_glProgramUniformMatrix3x4dv = dlsym(h, "glProgramUniformMatrix3x4dv"); if (p_glProgramUniformMatrix3x4dv) n++;
    *(void **)&p_glProgramUniformMatrix3x4fv = dlsym(h, "glProgramUniformMatrix3x4fv"); if (p_glProgramUniformMatrix3x4fv) n++;
    *(void **)&p_glProgramUniformMatrix4dv = dlsym(h, "glProgramUniformMatrix4dv"); if (p_glProgramUniformMatrix4dv) n++;
    *(void **)&p_glProgramUniformMatrix4fv = dlsym(h, "glProgramUniformMatrix4fv"); if (p_glProgramUniformMatrix4fv) n++;
    *(void **)&p_glProgramUniformMatrix4x2dv = dlsym(h, "glProgramUniformMatrix4x2dv"); if (p_glProgramUniformMatrix4x2dv) n++;
    *(void **)&p_glProgramUniformMatrix4x2fv = dlsym(h, "glProgramUniformMatrix4x2fv"); if (p_glProgramUniformMatrix4x2fv) n++;
    *(void **)&p_glProgramUniformMatrix4x3dv = dlsym(h, "glProgramUniformMatrix4x3dv"); if (p_glProgramUniformMatrix4x3dv) n++;
    *(void **)&p_glProgramUniformMatrix4x3fv = dlsym(h, "glProgramUniformMatrix4x3fv"); if (p_glProgramUniformMatrix4x3fv) n++;
    *(void **)&p_glProvokingVertex = dlsym(h, "glProvokingVertex"); if (p_glProvokingVertex) n++;
    *(void **)&p_glPushAttrib = dlsym(h, "glPushAttrib"); if (p_glPushAttrib) n++;
    *(void **)&p_glPushClientAttrib = dlsym(h, "glPushClientAttrib"); if (p_glPushClientAttrib) n++;
    *(void **)&p_glPushDebugGroup = dlsym(h, "glPushDebugGroup"); if (p_glPushDebugGroup) n++;
    *(void **)&p_glPushMatrix = dlsym(h, "glPushMatrix"); if (p_glPushMatrix) n++;
    *(void **)&p_glPushName = dlsym(h, "glPushName"); if (p_glPushName) n++;
    *(void **)&p_glQueryCounter = dlsym(h, "glQueryCounter"); if (p_glQueryCounter) n++;
    *(void **)&p_glRasterPos2d = dlsym(h, "glRasterPos2d"); if (p_glRasterPos2d) n++;
    *(void **)&p_glRasterPos2dv = dlsym(h, "glRasterPos2dv"); if (p_glRasterPos2dv) n++;
    *(void **)&p_glRasterPos2f = dlsym(h, "glRasterPos2f"); if (p_glRasterPos2f) n++;
    *(void **)&p_glRasterPos2fv = dlsym(h, "glRasterPos2fv"); if (p_glRasterPos2fv) n++;
    *(void **)&p_glRasterPos2i = dlsym(h, "glRasterPos2i"); if (p_glRasterPos2i) n++;
    *(void **)&p_glRasterPos2iv = dlsym(h, "glRasterPos2iv"); if (p_glRasterPos2iv) n++;
    *(void **)&p_glRasterPos2s = dlsym(h, "glRasterPos2s"); if (p_glRasterPos2s) n++;
    *(void **)&p_glRasterPos2sv = dlsym(h, "glRasterPos2sv"); if (p_glRasterPos2sv) n++;
    *(void **)&p_glRasterPos3d = dlsym(h, "glRasterPos3d"); if (p_glRasterPos3d) n++;
    *(void **)&p_glRasterPos3dv = dlsym(h, "glRasterPos3dv"); if (p_glRasterPos3dv) n++;
    *(void **)&p_glRasterPos3f = dlsym(h, "glRasterPos3f"); if (p_glRasterPos3f) n++;
    *(void **)&p_glRasterPos3fv = dlsym(h, "glRasterPos3fv"); if (p_glRasterPos3fv) n++;
    *(void **)&p_glRasterPos3i = dlsym(h, "glRasterPos3i"); if (p_glRasterPos3i) n++;
    *(void **)&p_glRasterPos3iv = dlsym(h, "glRasterPos3iv"); if (p_glRasterPos3iv) n++;
    *(void **)&p_glRasterPos3s = dlsym(h, "glRasterPos3s"); if (p_glRasterPos3s) n++;
    *(void **)&p_glRasterPos3sv = dlsym(h, "glRasterPos3sv"); if (p_glRasterPos3sv) n++;
    *(void **)&p_glRasterPos4d = dlsym(h, "glRasterPos4d"); if (p_glRasterPos4d) n++;
    *(void **)&p_glRasterPos4dv = dlsym(h, "glRasterPos4dv"); if (p_glRasterPos4dv) n++;
    *(void **)&p_glRasterPos4f = dlsym(h, "glRasterPos4f"); if (p_glRasterPos4f) n++;
    *(void **)&p_glRasterPos4fv = dlsym(h, "glRasterPos4fv"); if (p_glRasterPos4fv) n++;
    *(void **)&p_glRasterPos4i = dlsym(h, "glRasterPos4i"); if (p_glRasterPos4i) n++;
    *(void **)&p_glRasterPos4iv = dlsym(h, "glRasterPos4iv"); if (p_glRasterPos4iv) n++;
    *(void **)&p_glRasterPos4s = dlsym(h, "glRasterPos4s"); if (p_glRasterPos4s) n++;
    *(void **)&p_glRasterPos4sv = dlsym(h, "glRasterPos4sv"); if (p_glRasterPos4sv) n++;
    *(void **)&p_glReadBuffer = dlsym(h, "glReadBuffer"); if (p_glReadBuffer) n++;
    *(void **)&p_glReadPixels = dlsym(h, "glReadPixels"); if (p_glReadPixels) n++;
    *(void **)&p_glReadnPixels = dlsym(h, "glReadnPixels"); if (p_glReadnPixels) n++;
    *(void **)&p_glRectd = dlsym(h, "glRectd"); if (p_glRectd) n++;
    *(void **)&p_glRectdv = dlsym(h, "glRectdv"); if (p_glRectdv) n++;
    *(void **)&p_glRectf = dlsym(h, "glRectf"); if (p_glRectf) n++;
    *(void **)&p_glRectfv = dlsym(h, "glRectfv"); if (p_glRectfv) n++;
    *(void **)&p_glRecti = dlsym(h, "glRecti"); if (p_glRecti) n++;
    *(void **)&p_glRectiv = dlsym(h, "glRectiv"); if (p_glRectiv) n++;
    *(void **)&p_glRects = dlsym(h, "glRects"); if (p_glRects) n++;
    *(void **)&p_glRectsv = dlsym(h, "glRectsv"); if (p_glRectsv) n++;
    *(void **)&p_glReleaseShaderCompiler = dlsym(h, "glReleaseShaderCompiler"); if (p_glReleaseShaderCompiler) n++;
    *(void **)&p_glRenderMode = dlsym(h, "glRenderMode"); if (p_glRenderMode) n++;
    *(void **)&p_glRenderbufferStorage = dlsym(h, "glRenderbufferStorage"); if (p_glRenderbufferStorage) n++;
    *(void **)&p_glRenderbufferStorageMultisample = dlsym(h, "glRenderbufferStorageMultisample"); if (p_glRenderbufferStorageMultisample) n++;
    *(void **)&p_glResumeTransformFeedback = dlsym(h, "glResumeTransformFeedback"); if (p_glResumeTransformFeedback) n++;
    *(void **)&p_glRotated = dlsym(h, "glRotated"); if (p_glRotated) n++;
    *(void **)&p_glRotatef = dlsym(h, "glRotatef"); if (p_glRotatef) n++;
    *(void **)&p_glSampleCoverage = dlsym(h, "glSampleCoverage"); if (p_glSampleCoverage) n++;
    *(void **)&p_glSampleMaski = dlsym(h, "glSampleMaski"); if (p_glSampleMaski) n++;
    *(void **)&p_glSamplerParameterIiv = dlsym(h, "glSamplerParameterIiv"); if (p_glSamplerParameterIiv) n++;
    *(void **)&p_glSamplerParameterIuiv = dlsym(h, "glSamplerParameterIuiv"); if (p_glSamplerParameterIuiv) n++;
    *(void **)&p_glSamplerParameterf = dlsym(h, "glSamplerParameterf"); if (p_glSamplerParameterf) n++;
    *(void **)&p_glSamplerParameterfv = dlsym(h, "glSamplerParameterfv"); if (p_glSamplerParameterfv) n++;
    *(void **)&p_glSamplerParameteri = dlsym(h, "glSamplerParameteri"); if (p_glSamplerParameteri) n++;
    *(void **)&p_glSamplerParameteriv = dlsym(h, "glSamplerParameteriv"); if (p_glSamplerParameteriv) n++;
    *(void **)&p_glScaled = dlsym(h, "glScaled"); if (p_glScaled) n++;
    *(void **)&p_glScalef = dlsym(h, "glScalef"); if (p_glScalef) n++;
    *(void **)&p_glScissor = dlsym(h, "glScissor"); if (p_glScissor) n++;
    *(void **)&p_glScissorArrayv = dlsym(h, "glScissorArrayv"); if (p_glScissorArrayv) n++;
    *(void **)&p_glScissorIndexed = dlsym(h, "glScissorIndexed"); if (p_glScissorIndexed) n++;
    *(void **)&p_glScissorIndexedv = dlsym(h, "glScissorIndexedv"); if (p_glScissorIndexedv) n++;
    *(void **)&p_glSecondaryColor3b = dlsym(h, "glSecondaryColor3b"); if (p_glSecondaryColor3b) n++;
    *(void **)&p_glSecondaryColor3bv = dlsym(h, "glSecondaryColor3bv"); if (p_glSecondaryColor3bv) n++;
    *(void **)&p_glSecondaryColor3d = dlsym(h, "glSecondaryColor3d"); if (p_glSecondaryColor3d) n++;
    *(void **)&p_glSecondaryColor3dv = dlsym(h, "glSecondaryColor3dv"); if (p_glSecondaryColor3dv) n++;
    *(void **)&p_glSecondaryColor3f = dlsym(h, "glSecondaryColor3f"); if (p_glSecondaryColor3f) n++;
    *(void **)&p_glSecondaryColor3fv = dlsym(h, "glSecondaryColor3fv"); if (p_glSecondaryColor3fv) n++;
    *(void **)&p_glSecondaryColor3i = dlsym(h, "glSecondaryColor3i"); if (p_glSecondaryColor3i) n++;
    *(void **)&p_glSecondaryColor3iv = dlsym(h, "glSecondaryColor3iv"); if (p_glSecondaryColor3iv) n++;
    *(void **)&p_glSecondaryColor3s = dlsym(h, "glSecondaryColor3s"); if (p_glSecondaryColor3s) n++;
    *(void **)&p_glSecondaryColor3sv = dlsym(h, "glSecondaryColor3sv"); if (p_glSecondaryColor3sv) n++;
    *(void **)&p_glSecondaryColor3ub = dlsym(h, "glSecondaryColor3ub"); if (p_glSecondaryColor3ub) n++;
    *(void **)&p_glSecondaryColor3ubv = dlsym(h, "glSecondaryColor3ubv"); if (p_glSecondaryColor3ubv) n++;
    *(void **)&p_glSecondaryColor3ui = dlsym(h, "glSecondaryColor3ui"); if (p_glSecondaryColor3ui) n++;
    *(void **)&p_glSecondaryColor3uiv = dlsym(h, "glSecondaryColor3uiv"); if (p_glSecondaryColor3uiv) n++;
    *(void **)&p_glSecondaryColor3us = dlsym(h, "glSecondaryColor3us"); if (p_glSecondaryColor3us) n++;
    *(void **)&p_glSecondaryColor3usv = dlsym(h, "glSecondaryColor3usv"); if (p_glSecondaryColor3usv) n++;
    *(void **)&p_glSecondaryColorP3ui = dlsym(h, "glSecondaryColorP3ui"); if (p_glSecondaryColorP3ui) n++;
    *(void **)&p_glSecondaryColorP3uiv = dlsym(h, "glSecondaryColorP3uiv"); if (p_glSecondaryColorP3uiv) n++;
    *(void **)&p_glSecondaryColorPointer = dlsym(h, "glSecondaryColorPointer"); if (p_glSecondaryColorPointer) n++;
    *(void **)&p_glSelectBuffer = dlsym(h, "glSelectBuffer"); if (p_glSelectBuffer) n++;
    *(void **)&p_glShadeModel = dlsym(h, "glShadeModel"); if (p_glShadeModel) n++;
    *(void **)&p_glShaderBinary = dlsym(h, "glShaderBinary"); if (p_glShaderBinary) n++;
    *(void **)&p_glShaderSource = dlsym(h, "glShaderSource"); if (p_glShaderSource) n++;
    *(void **)&p_glShaderStorageBlockBinding = dlsym(h, "glShaderStorageBlockBinding"); if (p_glShaderStorageBlockBinding) n++;
    *(void **)&p_glSpecializeShader = dlsym(h, "glSpecializeShader"); if (p_glSpecializeShader) n++;
    *(void **)&p_glStencilFunc = dlsym(h, "glStencilFunc"); if (p_glStencilFunc) n++;
    *(void **)&p_glStencilFuncSeparate = dlsym(h, "glStencilFuncSeparate"); if (p_glStencilFuncSeparate) n++;
    *(void **)&p_glStencilMask = dlsym(h, "glStencilMask"); if (p_glStencilMask) n++;
    *(void **)&p_glStencilMaskSeparate = dlsym(h, "glStencilMaskSeparate"); if (p_glStencilMaskSeparate) n++;
    *(void **)&p_glStencilOp = dlsym(h, "glStencilOp"); if (p_glStencilOp) n++;
    *(void **)&p_glStencilOpSeparate = dlsym(h, "glStencilOpSeparate"); if (p_glStencilOpSeparate) n++;
    *(void **)&p_glTexBuffer = dlsym(h, "glTexBuffer"); if (p_glTexBuffer) n++;
    *(void **)&p_glTexBufferRange = dlsym(h, "glTexBufferRange"); if (p_glTexBufferRange) n++;
    *(void **)&p_glTexCoord1d = dlsym(h, "glTexCoord1d"); if (p_glTexCoord1d) n++;
    *(void **)&p_glTexCoord1dv = dlsym(h, "glTexCoord1dv"); if (p_glTexCoord1dv) n++;
    *(void **)&p_glTexCoord1f = dlsym(h, "glTexCoord1f"); if (p_glTexCoord1f) n++;
    *(void **)&p_glTexCoord1fv = dlsym(h, "glTexCoord1fv"); if (p_glTexCoord1fv) n++;
    *(void **)&p_glTexCoord1i = dlsym(h, "glTexCoord1i"); if (p_glTexCoord1i) n++;
    *(void **)&p_glTexCoord1iv = dlsym(h, "glTexCoord1iv"); if (p_glTexCoord1iv) n++;
    *(void **)&p_glTexCoord1s = dlsym(h, "glTexCoord1s"); if (p_glTexCoord1s) n++;
    *(void **)&p_glTexCoord1sv = dlsym(h, "glTexCoord1sv"); if (p_glTexCoord1sv) n++;
    *(void **)&p_glTexCoord2d = dlsym(h, "glTexCoord2d"); if (p_glTexCoord2d) n++;
    *(void **)&p_glTexCoord2dv = dlsym(h, "glTexCoord2dv"); if (p_glTexCoord2dv) n++;
    *(void **)&p_glTexCoord2f = dlsym(h, "glTexCoord2f"); if (p_glTexCoord2f) n++;
    *(void **)&p_glTexCoord2fv = dlsym(h, "glTexCoord2fv"); if (p_glTexCoord2fv) n++;
    *(void **)&p_glTexCoord2i = dlsym(h, "glTexCoord2i"); if (p_glTexCoord2i) n++;
    *(void **)&p_glTexCoord2iv = dlsym(h, "glTexCoord2iv"); if (p_glTexCoord2iv) n++;
    *(void **)&p_glTexCoord2s = dlsym(h, "glTexCoord2s"); if (p_glTexCoord2s) n++;
    *(void **)&p_glTexCoord2sv = dlsym(h, "glTexCoord2sv"); if (p_glTexCoord2sv) n++;
    *(void **)&p_glTexCoord3d = dlsym(h, "glTexCoord3d"); if (p_glTexCoord3d) n++;
    *(void **)&p_glTexCoord3dv = dlsym(h, "glTexCoord3dv"); if (p_glTexCoord3dv) n++;
    *(void **)&p_glTexCoord3f = dlsym(h, "glTexCoord3f"); if (p_glTexCoord3f) n++;
    *(void **)&p_glTexCoord3fv = dlsym(h, "glTexCoord3fv"); if (p_glTexCoord3fv) n++;
    *(void **)&p_glTexCoord3i = dlsym(h, "glTexCoord3i"); if (p_glTexCoord3i) n++;
    *(void **)&p_glTexCoord3iv = dlsym(h, "glTexCoord3iv"); if (p_glTexCoord3iv) n++;
    *(void **)&p_glTexCoord3s = dlsym(h, "glTexCoord3s"); if (p_glTexCoord3s) n++;
    *(void **)&p_glTexCoord3sv = dlsym(h, "glTexCoord3sv"); if (p_glTexCoord3sv) n++;
    *(void **)&p_glTexCoord4d = dlsym(h, "glTexCoord4d"); if (p_glTexCoord4d) n++;
    *(void **)&p_glTexCoord4dv = dlsym(h, "glTexCoord4dv"); if (p_glTexCoord4dv) n++;
    *(void **)&p_glTexCoord4f = dlsym(h, "glTexCoord4f"); if (p_glTexCoord4f) n++;
    *(void **)&p_glTexCoord4fv = dlsym(h, "glTexCoord4fv"); if (p_glTexCoord4fv) n++;
    *(void **)&p_glTexCoord4i = dlsym(h, "glTexCoord4i"); if (p_glTexCoord4i) n++;
    *(void **)&p_glTexCoord4iv = dlsym(h, "glTexCoord4iv"); if (p_glTexCoord4iv) n++;
    *(void **)&p_glTexCoord4s = dlsym(h, "glTexCoord4s"); if (p_glTexCoord4s) n++;
    *(void **)&p_glTexCoord4sv = dlsym(h, "glTexCoord4sv"); if (p_glTexCoord4sv) n++;
    *(void **)&p_glTexCoordP1ui = dlsym(h, "glTexCoordP1ui"); if (p_glTexCoordP1ui) n++;
    *(void **)&p_glTexCoordP1uiv = dlsym(h, "glTexCoordP1uiv"); if (p_glTexCoordP1uiv) n++;
    *(void **)&p_glTexCoordP2ui = dlsym(h, "glTexCoordP2ui"); if (p_glTexCoordP2ui) n++;
    *(void **)&p_glTexCoordP2uiv = dlsym(h, "glTexCoordP2uiv"); if (p_glTexCoordP2uiv) n++;
    *(void **)&p_glTexCoordP3ui = dlsym(h, "glTexCoordP3ui"); if (p_glTexCoordP3ui) n++;
    *(void **)&p_glTexCoordP3uiv = dlsym(h, "glTexCoordP3uiv"); if (p_glTexCoordP3uiv) n++;
    *(void **)&p_glTexCoordP4ui = dlsym(h, "glTexCoordP4ui"); if (p_glTexCoordP4ui) n++;
    *(void **)&p_glTexCoordP4uiv = dlsym(h, "glTexCoordP4uiv"); if (p_glTexCoordP4uiv) n++;
    *(void **)&p_glTexCoordPointer = dlsym(h, "glTexCoordPointer"); if (p_glTexCoordPointer) n++;
    *(void **)&p_glTexEnvf = dlsym(h, "glTexEnvf"); if (p_glTexEnvf) n++;
    *(void **)&p_glTexEnvfv = dlsym(h, "glTexEnvfv"); if (p_glTexEnvfv) n++;
    *(void **)&p_glTexEnvi = dlsym(h, "glTexEnvi"); if (p_glTexEnvi) n++;
    *(void **)&p_glTexEnviv = dlsym(h, "glTexEnviv"); if (p_glTexEnviv) n++;
    *(void **)&p_glTexGend = dlsym(h, "glTexGend"); if (p_glTexGend) n++;
    *(void **)&p_glTexGendv = dlsym(h, "glTexGendv"); if (p_glTexGendv) n++;
    *(void **)&p_glTexGenf = dlsym(h, "glTexGenf"); if (p_glTexGenf) n++;
    *(void **)&p_glTexGenfv = dlsym(h, "glTexGenfv"); if (p_glTexGenfv) n++;
    *(void **)&p_glTexGeni = dlsym(h, "glTexGeni"); if (p_glTexGeni) n++;
    *(void **)&p_glTexGeniv = dlsym(h, "glTexGeniv"); if (p_glTexGeniv) n++;
    *(void **)&p_glTexImage1D = dlsym(h, "glTexImage1D"); if (p_glTexImage1D) n++;
    *(void **)&p_glTexImage2D = dlsym(h, "glTexImage2D"); if (p_glTexImage2D) n++;
    *(void **)&p_glTexImage2DMultisample = dlsym(h, "glTexImage2DMultisample"); if (p_glTexImage2DMultisample) n++;
    *(void **)&p_glTexImage3D = dlsym(h, "glTexImage3D"); if (p_glTexImage3D) n++;
    *(void **)&p_glTexImage3DMultisample = dlsym(h, "glTexImage3DMultisample"); if (p_glTexImage3DMultisample) n++;
    *(void **)&p_glTexParameterIiv = dlsym(h, "glTexParameterIiv"); if (p_glTexParameterIiv) n++;
    *(void **)&p_glTexParameterIuiv = dlsym(h, "glTexParameterIuiv"); if (p_glTexParameterIuiv) n++;
    *(void **)&p_glTexParameterf = dlsym(h, "glTexParameterf"); if (p_glTexParameterf) n++;
    *(void **)&p_glTexParameterfv = dlsym(h, "glTexParameterfv"); if (p_glTexParameterfv) n++;
    *(void **)&p_glTexParameteri = dlsym(h, "glTexParameteri"); if (p_glTexParameteri) n++;
    *(void **)&p_glTexParameteriv = dlsym(h, "glTexParameteriv"); if (p_glTexParameteriv) n++;
    *(void **)&p_glTexStorage1D = dlsym(h, "glTexStorage1D"); if (p_glTexStorage1D) n++;
    *(void **)&p_glTexStorage2D = dlsym(h, "glTexStorage2D"); if (p_glTexStorage2D) n++;
    *(void **)&p_glTexStorage2DMultisample = dlsym(h, "glTexStorage2DMultisample"); if (p_glTexStorage2DMultisample) n++;
    *(void **)&p_glTexStorage3D = dlsym(h, "glTexStorage3D"); if (p_glTexStorage3D) n++;
    *(void **)&p_glTexStorage3DMultisample = dlsym(h, "glTexStorage3DMultisample"); if (p_glTexStorage3DMultisample) n++;
    *(void **)&p_glTexSubImage1D = dlsym(h, "glTexSubImage1D"); if (p_glTexSubImage1D) n++;
    *(void **)&p_glTexSubImage2D = dlsym(h, "glTexSubImage2D"); if (p_glTexSubImage2D) n++;
    *(void **)&p_glTexSubImage3D = dlsym(h, "glTexSubImage3D"); if (p_glTexSubImage3D) n++;
    *(void **)&p_glTextureBarrier = dlsym(h, "glTextureBarrier"); if (p_glTextureBarrier) n++;
    *(void **)&p_glTextureBuffer = dlsym(h, "glTextureBuffer"); if (p_glTextureBuffer) n++;
    *(void **)&p_glTextureBufferRange = dlsym(h, "glTextureBufferRange"); if (p_glTextureBufferRange) n++;
    *(void **)&p_glTextureParameterIiv = dlsym(h, "glTextureParameterIiv"); if (p_glTextureParameterIiv) n++;
    *(void **)&p_glTextureParameterIuiv = dlsym(h, "glTextureParameterIuiv"); if (p_glTextureParameterIuiv) n++;
    *(void **)&p_glTextureParameterf = dlsym(h, "glTextureParameterf"); if (p_glTextureParameterf) n++;
    *(void **)&p_glTextureParameterfv = dlsym(h, "glTextureParameterfv"); if (p_glTextureParameterfv) n++;
    *(void **)&p_glTextureParameteri = dlsym(h, "glTextureParameteri"); if (p_glTextureParameteri) n++;
    *(void **)&p_glTextureParameteriv = dlsym(h, "glTextureParameteriv"); if (p_glTextureParameteriv) n++;
    *(void **)&p_glTextureStorage1D = dlsym(h, "glTextureStorage1D"); if (p_glTextureStorage1D) n++;
    *(void **)&p_glTextureStorage2D = dlsym(h, "glTextureStorage2D"); if (p_glTextureStorage2D) n++;
    *(void **)&p_glTextureStorage2DMultisample = dlsym(h, "glTextureStorage2DMultisample"); if (p_glTextureStorage2DMultisample) n++;
    *(void **)&p_glTextureStorage3D = dlsym(h, "glTextureStorage3D"); if (p_glTextureStorage3D) n++;
    *(void **)&p_glTextureStorage3DMultisample = dlsym(h, "glTextureStorage3DMultisample"); if (p_glTextureStorage3DMultisample) n++;
    *(void **)&p_glTextureSubImage1D = dlsym(h, "glTextureSubImage1D"); if (p_glTextureSubImage1D) n++;
    *(void **)&p_glTextureSubImage2D = dlsym(h, "glTextureSubImage2D"); if (p_glTextureSubImage2D) n++;
    *(void **)&p_glTextureSubImage3D = dlsym(h, "glTextureSubImage3D"); if (p_glTextureSubImage3D) n++;
    *(void **)&p_glTextureView = dlsym(h, "glTextureView"); if (p_glTextureView) n++;
    *(void **)&p_glTransformFeedbackBufferBase = dlsym(h, "glTransformFeedbackBufferBase"); if (p_glTransformFeedbackBufferBase) n++;
    *(void **)&p_glTransformFeedbackBufferRange = dlsym(h, "glTransformFeedbackBufferRange"); if (p_glTransformFeedbackBufferRange) n++;
    *(void **)&p_glTransformFeedbackVaryings = dlsym(h, "glTransformFeedbackVaryings"); if (p_glTransformFeedbackVaryings) n++;
    *(void **)&p_glTranslated = dlsym(h, "glTranslated"); if (p_glTranslated) n++;
    *(void **)&p_glTranslatef = dlsym(h, "glTranslatef"); if (p_glTranslatef) n++;
    *(void **)&p_glUniform1d = dlsym(h, "glUniform1d"); if (p_glUniform1d) n++;
    *(void **)&p_glUniform1dv = dlsym(h, "glUniform1dv"); if (p_glUniform1dv) n++;
    *(void **)&p_glUniform1f = dlsym(h, "glUniform1f"); if (p_glUniform1f) n++;
    *(void **)&p_glUniform1fv = dlsym(h, "glUniform1fv"); if (p_glUniform1fv) n++;
    *(void **)&p_glUniform1i = dlsym(h, "glUniform1i"); if (p_glUniform1i) n++;
    *(void **)&p_glUniform1iv = dlsym(h, "glUniform1iv"); if (p_glUniform1iv) n++;
    *(void **)&p_glUniform1ui = dlsym(h, "glUniform1ui"); if (p_glUniform1ui) n++;
    *(void **)&p_glUniform1uiv = dlsym(h, "glUniform1uiv"); if (p_glUniform1uiv) n++;
    *(void **)&p_glUniform2d = dlsym(h, "glUniform2d"); if (p_glUniform2d) n++;
    *(void **)&p_glUniform2dv = dlsym(h, "glUniform2dv"); if (p_glUniform2dv) n++;
    *(void **)&p_glUniform2f = dlsym(h, "glUniform2f"); if (p_glUniform2f) n++;
    *(void **)&p_glUniform2fv = dlsym(h, "glUniform2fv"); if (p_glUniform2fv) n++;
    *(void **)&p_glUniform2i = dlsym(h, "glUniform2i"); if (p_glUniform2i) n++;
    *(void **)&p_glUniform2iv = dlsym(h, "glUniform2iv"); if (p_glUniform2iv) n++;
    *(void **)&p_glUniform2ui = dlsym(h, "glUniform2ui"); if (p_glUniform2ui) n++;
    *(void **)&p_glUniform2uiv = dlsym(h, "glUniform2uiv"); if (p_glUniform2uiv) n++;
    *(void **)&p_glUniform3d = dlsym(h, "glUniform3d"); if (p_glUniform3d) n++;
    *(void **)&p_glUniform3dv = dlsym(h, "glUniform3dv"); if (p_glUniform3dv) n++;
    *(void **)&p_glUniform3f = dlsym(h, "glUniform3f"); if (p_glUniform3f) n++;
    *(void **)&p_glUniform3fv = dlsym(h, "glUniform3fv"); if (p_glUniform3fv) n++;
    *(void **)&p_glUniform3i = dlsym(h, "glUniform3i"); if (p_glUniform3i) n++;
    *(void **)&p_glUniform3iv = dlsym(h, "glUniform3iv"); if (p_glUniform3iv) n++;
    *(void **)&p_glUniform3ui = dlsym(h, "glUniform3ui"); if (p_glUniform3ui) n++;
    *(void **)&p_glUniform3uiv = dlsym(h, "glUniform3uiv"); if (p_glUniform3uiv) n++;
    *(void **)&p_glUniform4d = dlsym(h, "glUniform4d"); if (p_glUniform4d) n++;
    *(void **)&p_glUniform4dv = dlsym(h, "glUniform4dv"); if (p_glUniform4dv) n++;
    *(void **)&p_glUniform4f = dlsym(h, "glUniform4f"); if (p_glUniform4f) n++;
    *(void **)&p_glUniform4fv = dlsym(h, "glUniform4fv"); if (p_glUniform4fv) n++;
    *(void **)&p_glUniform4i = dlsym(h, "glUniform4i"); if (p_glUniform4i) n++;
    *(void **)&p_glUniform4iv = dlsym(h, "glUniform4iv"); if (p_glUniform4iv) n++;
    *(void **)&p_glUniform4ui = dlsym(h, "glUniform4ui"); if (p_glUniform4ui) n++;
    *(void **)&p_glUniform4uiv = dlsym(h, "glUniform4uiv"); if (p_glUniform4uiv) n++;
    *(void **)&p_glUniformBlockBinding = dlsym(h, "glUniformBlockBinding"); if (p_glUniformBlockBinding) n++;
    *(void **)&p_glUniformMatrix2dv = dlsym(h, "glUniformMatrix2dv"); if (p_glUniformMatrix2dv) n++;
    *(void **)&p_glUniformMatrix2fv = dlsym(h, "glUniformMatrix2fv"); if (p_glUniformMatrix2fv) n++;
    *(void **)&p_glUniformMatrix2x3dv = dlsym(h, "glUniformMatrix2x3dv"); if (p_glUniformMatrix2x3dv) n++;
    *(void **)&p_glUniformMatrix2x3fv = dlsym(h, "glUniformMatrix2x3fv"); if (p_glUniformMatrix2x3fv) n++;
    *(void **)&p_glUniformMatrix2x4dv = dlsym(h, "glUniformMatrix2x4dv"); if (p_glUniformMatrix2x4dv) n++;
    *(void **)&p_glUniformMatrix2x4fv = dlsym(h, "glUniformMatrix2x4fv"); if (p_glUniformMatrix2x4fv) n++;
    *(void **)&p_glUniformMatrix3dv = dlsym(h, "glUniformMatrix3dv"); if (p_glUniformMatrix3dv) n++;
    *(void **)&p_glUniformMatrix3fv = dlsym(h, "glUniformMatrix3fv"); if (p_glUniformMatrix3fv) n++;
    *(void **)&p_glUniformMatrix3x2dv = dlsym(h, "glUniformMatrix3x2dv"); if (p_glUniformMatrix3x2dv) n++;
    *(void **)&p_glUniformMatrix3x2fv = dlsym(h, "glUniformMatrix3x2fv"); if (p_glUniformMatrix3x2fv) n++;
    *(void **)&p_glUniformMatrix3x4dv = dlsym(h, "glUniformMatrix3x4dv"); if (p_glUniformMatrix3x4dv) n++;
    *(void **)&p_glUniformMatrix3x4fv = dlsym(h, "glUniformMatrix3x4fv"); if (p_glUniformMatrix3x4fv) n++;
    *(void **)&p_glUniformMatrix4dv = dlsym(h, "glUniformMatrix4dv"); if (p_glUniformMatrix4dv) n++;
    *(void **)&p_glUniformMatrix4fv = dlsym(h, "glUniformMatrix4fv"); if (p_glUniformMatrix4fv) n++;
    *(void **)&p_glUniformMatrix4x2dv = dlsym(h, "glUniformMatrix4x2dv"); if (p_glUniformMatrix4x2dv) n++;
    *(void **)&p_glUniformMatrix4x2fv = dlsym(h, "glUniformMatrix4x2fv"); if (p_glUniformMatrix4x2fv) n++;
    *(void **)&p_glUniformMatrix4x3dv = dlsym(h, "glUniformMatrix4x3dv"); if (p_glUniformMatrix4x3dv) n++;
    *(void **)&p_glUniformMatrix4x3fv = dlsym(h, "glUniformMatrix4x3fv"); if (p_glUniformMatrix4x3fv) n++;
    *(void **)&p_glUniformSubroutinesuiv = dlsym(h, "glUniformSubroutinesuiv"); if (p_glUniformSubroutinesuiv) n++;
    *(void **)&p_glUnmapBuffer = dlsym(h, "glUnmapBuffer"); if (p_glUnmapBuffer) n++;
    *(void **)&p_glUnmapNamedBuffer = dlsym(h, "glUnmapNamedBuffer"); if (p_glUnmapNamedBuffer) n++;
    *(void **)&p_glUseProgram = dlsym(h, "glUseProgram"); if (p_glUseProgram) n++;
    *(void **)&p_glUseProgramStages = dlsym(h, "glUseProgramStages"); if (p_glUseProgramStages) n++;
    *(void **)&p_glValidateProgram = dlsym(h, "glValidateProgram"); if (p_glValidateProgram) n++;
    *(void **)&p_glValidateProgramPipeline = dlsym(h, "glValidateProgramPipeline"); if (p_glValidateProgramPipeline) n++;
    *(void **)&p_glVertex2d = dlsym(h, "glVertex2d"); if (p_glVertex2d) n++;
    *(void **)&p_glVertex2dv = dlsym(h, "glVertex2dv"); if (p_glVertex2dv) n++;
    *(void **)&p_glVertex2f = dlsym(h, "glVertex2f"); if (p_glVertex2f) n++;
    *(void **)&p_glVertex2fv = dlsym(h, "glVertex2fv"); if (p_glVertex2fv) n++;
    *(void **)&p_glVertex2i = dlsym(h, "glVertex2i"); if (p_glVertex2i) n++;
    *(void **)&p_glVertex2iv = dlsym(h, "glVertex2iv"); if (p_glVertex2iv) n++;
    *(void **)&p_glVertex2s = dlsym(h, "glVertex2s"); if (p_glVertex2s) n++;
    *(void **)&p_glVertex2sv = dlsym(h, "glVertex2sv"); if (p_glVertex2sv) n++;
    *(void **)&p_glVertex3d = dlsym(h, "glVertex3d"); if (p_glVertex3d) n++;
    *(void **)&p_glVertex3dv = dlsym(h, "glVertex3dv"); if (p_glVertex3dv) n++;
    *(void **)&p_glVertex3f = dlsym(h, "glVertex3f"); if (p_glVertex3f) n++;
    *(void **)&p_glVertex3fv = dlsym(h, "glVertex3fv"); if (p_glVertex3fv) n++;
    *(void **)&p_glVertex3i = dlsym(h, "glVertex3i"); if (p_glVertex3i) n++;
    *(void **)&p_glVertex3iv = dlsym(h, "glVertex3iv"); if (p_glVertex3iv) n++;
    *(void **)&p_glVertex3s = dlsym(h, "glVertex3s"); if (p_glVertex3s) n++;
    *(void **)&p_glVertex3sv = dlsym(h, "glVertex3sv"); if (p_glVertex3sv) n++;
    *(void **)&p_glVertex4d = dlsym(h, "glVertex4d"); if (p_glVertex4d) n++;
    *(void **)&p_glVertex4dv = dlsym(h, "glVertex4dv"); if (p_glVertex4dv) n++;
    *(void **)&p_glVertex4f = dlsym(h, "glVertex4f"); if (p_glVertex4f) n++;
    *(void **)&p_glVertex4fv = dlsym(h, "glVertex4fv"); if (p_glVertex4fv) n++;
    *(void **)&p_glVertex4i = dlsym(h, "glVertex4i"); if (p_glVertex4i) n++;
    *(void **)&p_glVertex4iv = dlsym(h, "glVertex4iv"); if (p_glVertex4iv) n++;
    *(void **)&p_glVertex4s = dlsym(h, "glVertex4s"); if (p_glVertex4s) n++;
    *(void **)&p_glVertex4sv = dlsym(h, "glVertex4sv"); if (p_glVertex4sv) n++;
    *(void **)&p_glVertexArrayAttribBinding = dlsym(h, "glVertexArrayAttribBinding"); if (p_glVertexArrayAttribBinding) n++;
    *(void **)&p_glVertexArrayAttribFormat = dlsym(h, "glVertexArrayAttribFormat"); if (p_glVertexArrayAttribFormat) n++;
    *(void **)&p_glVertexArrayAttribIFormat = dlsym(h, "glVertexArrayAttribIFormat"); if (p_glVertexArrayAttribIFormat) n++;
    *(void **)&p_glVertexArrayAttribLFormat = dlsym(h, "glVertexArrayAttribLFormat"); if (p_glVertexArrayAttribLFormat) n++;
    *(void **)&p_glVertexArrayBindingDivisor = dlsym(h, "glVertexArrayBindingDivisor"); if (p_glVertexArrayBindingDivisor) n++;
    *(void **)&p_glVertexArrayElementBuffer = dlsym(h, "glVertexArrayElementBuffer"); if (p_glVertexArrayElementBuffer) n++;
    *(void **)&p_glVertexArrayVertexBuffer = dlsym(h, "glVertexArrayVertexBuffer"); if (p_glVertexArrayVertexBuffer) n++;
    *(void **)&p_glVertexArrayVertexBuffers = dlsym(h, "glVertexArrayVertexBuffers"); if (p_glVertexArrayVertexBuffers) n++;
    *(void **)&p_glVertexAttrib1d = dlsym(h, "glVertexAttrib1d"); if (p_glVertexAttrib1d) n++;
    *(void **)&p_glVertexAttrib1dv = dlsym(h, "glVertexAttrib1dv"); if (p_glVertexAttrib1dv) n++;
    *(void **)&p_glVertexAttrib1f = dlsym(h, "glVertexAttrib1f"); if (p_glVertexAttrib1f) n++;
    *(void **)&p_glVertexAttrib1fv = dlsym(h, "glVertexAttrib1fv"); if (p_glVertexAttrib1fv) n++;
    *(void **)&p_glVertexAttrib1s = dlsym(h, "glVertexAttrib1s"); if (p_glVertexAttrib1s) n++;
    *(void **)&p_glVertexAttrib1sv = dlsym(h, "glVertexAttrib1sv"); if (p_glVertexAttrib1sv) n++;
    *(void **)&p_glVertexAttrib2d = dlsym(h, "glVertexAttrib2d"); if (p_glVertexAttrib2d) n++;
    *(void **)&p_glVertexAttrib2dv = dlsym(h, "glVertexAttrib2dv"); if (p_glVertexAttrib2dv) n++;
    *(void **)&p_glVertexAttrib2f = dlsym(h, "glVertexAttrib2f"); if (p_glVertexAttrib2f) n++;
    *(void **)&p_glVertexAttrib2fv = dlsym(h, "glVertexAttrib2fv"); if (p_glVertexAttrib2fv) n++;
    *(void **)&p_glVertexAttrib2s = dlsym(h, "glVertexAttrib2s"); if (p_glVertexAttrib2s) n++;
    *(void **)&p_glVertexAttrib2sv = dlsym(h, "glVertexAttrib2sv"); if (p_glVertexAttrib2sv) n++;
    *(void **)&p_glVertexAttrib3d = dlsym(h, "glVertexAttrib3d"); if (p_glVertexAttrib3d) n++;
    *(void **)&p_glVertexAttrib3dv = dlsym(h, "glVertexAttrib3dv"); if (p_glVertexAttrib3dv) n++;
    *(void **)&p_glVertexAttrib3f = dlsym(h, "glVertexAttrib3f"); if (p_glVertexAttrib3f) n++;
    *(void **)&p_glVertexAttrib3fv = dlsym(h, "glVertexAttrib3fv"); if (p_glVertexAttrib3fv) n++;
    *(void **)&p_glVertexAttrib3s = dlsym(h, "glVertexAttrib3s"); if (p_glVertexAttrib3s) n++;
    *(void **)&p_glVertexAttrib3sv = dlsym(h, "glVertexAttrib3sv"); if (p_glVertexAttrib3sv) n++;
    *(void **)&p_glVertexAttrib4Nbv = dlsym(h, "glVertexAttrib4Nbv"); if (p_glVertexAttrib4Nbv) n++;
    *(void **)&p_glVertexAttrib4Niv = dlsym(h, "glVertexAttrib4Niv"); if (p_glVertexAttrib4Niv) n++;
    *(void **)&p_glVertexAttrib4Nsv = dlsym(h, "glVertexAttrib4Nsv"); if (p_glVertexAttrib4Nsv) n++;
    *(void **)&p_glVertexAttrib4Nub = dlsym(h, "glVertexAttrib4Nub"); if (p_glVertexAttrib4Nub) n++;
    *(void **)&p_glVertexAttrib4Nubv = dlsym(h, "glVertexAttrib4Nubv"); if (p_glVertexAttrib4Nubv) n++;
    *(void **)&p_glVertexAttrib4Nuiv = dlsym(h, "glVertexAttrib4Nuiv"); if (p_glVertexAttrib4Nuiv) n++;
    *(void **)&p_glVertexAttrib4Nusv = dlsym(h, "glVertexAttrib4Nusv"); if (p_glVertexAttrib4Nusv) n++;
    *(void **)&p_glVertexAttrib4bv = dlsym(h, "glVertexAttrib4bv"); if (p_glVertexAttrib4bv) n++;
    *(void **)&p_glVertexAttrib4d = dlsym(h, "glVertexAttrib4d"); if (p_glVertexAttrib4d) n++;
    *(void **)&p_glVertexAttrib4dv = dlsym(h, "glVertexAttrib4dv"); if (p_glVertexAttrib4dv) n++;
    *(void **)&p_glVertexAttrib4f = dlsym(h, "glVertexAttrib4f"); if (p_glVertexAttrib4f) n++;
    *(void **)&p_glVertexAttrib4fv = dlsym(h, "glVertexAttrib4fv"); if (p_glVertexAttrib4fv) n++;
    *(void **)&p_glVertexAttrib4iv = dlsym(h, "glVertexAttrib4iv"); if (p_glVertexAttrib4iv) n++;
    *(void **)&p_glVertexAttrib4s = dlsym(h, "glVertexAttrib4s"); if (p_glVertexAttrib4s) n++;
    *(void **)&p_glVertexAttrib4sv = dlsym(h, "glVertexAttrib4sv"); if (p_glVertexAttrib4sv) n++;
    *(void **)&p_glVertexAttrib4ubv = dlsym(h, "glVertexAttrib4ubv"); if (p_glVertexAttrib4ubv) n++;
    *(void **)&p_glVertexAttrib4uiv = dlsym(h, "glVertexAttrib4uiv"); if (p_glVertexAttrib4uiv) n++;
    *(void **)&p_glVertexAttrib4usv = dlsym(h, "glVertexAttrib4usv"); if (p_glVertexAttrib4usv) n++;
    *(void **)&p_glVertexAttribBinding = dlsym(h, "glVertexAttribBinding"); if (p_glVertexAttribBinding) n++;
    *(void **)&p_glVertexAttribDivisor = dlsym(h, "glVertexAttribDivisor"); if (p_glVertexAttribDivisor) n++;
    *(void **)&p_glVertexAttribFormat = dlsym(h, "glVertexAttribFormat"); if (p_glVertexAttribFormat) n++;
    *(void **)&p_glVertexAttribI1i = dlsym(h, "glVertexAttribI1i"); if (p_glVertexAttribI1i) n++;
    *(void **)&p_glVertexAttribI1iv = dlsym(h, "glVertexAttribI1iv"); if (p_glVertexAttribI1iv) n++;
    *(void **)&p_glVertexAttribI1ui = dlsym(h, "glVertexAttribI1ui"); if (p_glVertexAttribI1ui) n++;
    *(void **)&p_glVertexAttribI1uiv = dlsym(h, "glVertexAttribI1uiv"); if (p_glVertexAttribI1uiv) n++;
    *(void **)&p_glVertexAttribI2i = dlsym(h, "glVertexAttribI2i"); if (p_glVertexAttribI2i) n++;
    *(void **)&p_glVertexAttribI2iv = dlsym(h, "glVertexAttribI2iv"); if (p_glVertexAttribI2iv) n++;
    *(void **)&p_glVertexAttribI2ui = dlsym(h, "glVertexAttribI2ui"); if (p_glVertexAttribI2ui) n++;
    *(void **)&p_glVertexAttribI2uiv = dlsym(h, "glVertexAttribI2uiv"); if (p_glVertexAttribI2uiv) n++;
    *(void **)&p_glVertexAttribI3i = dlsym(h, "glVertexAttribI3i"); if (p_glVertexAttribI3i) n++;
    *(void **)&p_glVertexAttribI3iv = dlsym(h, "glVertexAttribI3iv"); if (p_glVertexAttribI3iv) n++;
    *(void **)&p_glVertexAttribI3ui = dlsym(h, "glVertexAttribI3ui"); if (p_glVertexAttribI3ui) n++;
    *(void **)&p_glVertexAttribI3uiv = dlsym(h, "glVertexAttribI3uiv"); if (p_glVertexAttribI3uiv) n++;
    *(void **)&p_glVertexAttribI4bv = dlsym(h, "glVertexAttribI4bv"); if (p_glVertexAttribI4bv) n++;
    *(void **)&p_glVertexAttribI4i = dlsym(h, "glVertexAttribI4i"); if (p_glVertexAttribI4i) n++;
    *(void **)&p_glVertexAttribI4iv = dlsym(h, "glVertexAttribI4iv"); if (p_glVertexAttribI4iv) n++;
    *(void **)&p_glVertexAttribI4sv = dlsym(h, "glVertexAttribI4sv"); if (p_glVertexAttribI4sv) n++;
    *(void **)&p_glVertexAttribI4ubv = dlsym(h, "glVertexAttribI4ubv"); if (p_glVertexAttribI4ubv) n++;
    *(void **)&p_glVertexAttribI4ui = dlsym(h, "glVertexAttribI4ui"); if (p_glVertexAttribI4ui) n++;
    *(void **)&p_glVertexAttribI4uiv = dlsym(h, "glVertexAttribI4uiv"); if (p_glVertexAttribI4uiv) n++;
    *(void **)&p_glVertexAttribI4usv = dlsym(h, "glVertexAttribI4usv"); if (p_glVertexAttribI4usv) n++;
    *(void **)&p_glVertexAttribIFormat = dlsym(h, "glVertexAttribIFormat"); if (p_glVertexAttribIFormat) n++;
    *(void **)&p_glVertexAttribIPointer = dlsym(h, "glVertexAttribIPointer"); if (p_glVertexAttribIPointer) n++;
    *(void **)&p_glVertexAttribL1d = dlsym(h, "glVertexAttribL1d"); if (p_glVertexAttribL1d) n++;
    *(void **)&p_glVertexAttribL1dv = dlsym(h, "glVertexAttribL1dv"); if (p_glVertexAttribL1dv) n++;
    *(void **)&p_glVertexAttribL2d = dlsym(h, "glVertexAttribL2d"); if (p_glVertexAttribL2d) n++;
    *(void **)&p_glVertexAttribL2dv = dlsym(h, "glVertexAttribL2dv"); if (p_glVertexAttribL2dv) n++;
    *(void **)&p_glVertexAttribL3d = dlsym(h, "glVertexAttribL3d"); if (p_glVertexAttribL3d) n++;
    *(void **)&p_glVertexAttribL3dv = dlsym(h, "glVertexAttribL3dv"); if (p_glVertexAttribL3dv) n++;
    *(void **)&p_glVertexAttribL4d = dlsym(h, "glVertexAttribL4d"); if (p_glVertexAttribL4d) n++;
    *(void **)&p_glVertexAttribL4dv = dlsym(h, "glVertexAttribL4dv"); if (p_glVertexAttribL4dv) n++;
    *(void **)&p_glVertexAttribLFormat = dlsym(h, "glVertexAttribLFormat"); if (p_glVertexAttribLFormat) n++;
    *(void **)&p_glVertexAttribLPointer = dlsym(h, "glVertexAttribLPointer"); if (p_glVertexAttribLPointer) n++;
    *(void **)&p_glVertexAttribP1ui = dlsym(h, "glVertexAttribP1ui"); if (p_glVertexAttribP1ui) n++;
    *(void **)&p_glVertexAttribP1uiv = dlsym(h, "glVertexAttribP1uiv"); if (p_glVertexAttribP1uiv) n++;
    *(void **)&p_glVertexAttribP2ui = dlsym(h, "glVertexAttribP2ui"); if (p_glVertexAttribP2ui) n++;
    *(void **)&p_glVertexAttribP2uiv = dlsym(h, "glVertexAttribP2uiv"); if (p_glVertexAttribP2uiv) n++;
    *(void **)&p_glVertexAttribP3ui = dlsym(h, "glVertexAttribP3ui"); if (p_glVertexAttribP3ui) n++;
    *(void **)&p_glVertexAttribP3uiv = dlsym(h, "glVertexAttribP3uiv"); if (p_glVertexAttribP3uiv) n++;
    *(void **)&p_glVertexAttribP4ui = dlsym(h, "glVertexAttribP4ui"); if (p_glVertexAttribP4ui) n++;
    *(void **)&p_glVertexAttribP4uiv = dlsym(h, "glVertexAttribP4uiv"); if (p_glVertexAttribP4uiv) n++;
    *(void **)&p_glVertexAttribPointer = dlsym(h, "glVertexAttribPointer"); if (p_glVertexAttribPointer) n++;
    *(void **)&p_glVertexBindingDivisor = dlsym(h, "glVertexBindingDivisor"); if (p_glVertexBindingDivisor) n++;
    *(void **)&p_glVertexP2ui = dlsym(h, "glVertexP2ui"); if (p_glVertexP2ui) n++;
    *(void **)&p_glVertexP2uiv = dlsym(h, "glVertexP2uiv"); if (p_glVertexP2uiv) n++;
    *(void **)&p_glVertexP3ui = dlsym(h, "glVertexP3ui"); if (p_glVertexP3ui) n++;
    *(void **)&p_glVertexP3uiv = dlsym(h, "glVertexP3uiv"); if (p_glVertexP3uiv) n++;
    *(void **)&p_glVertexP4ui = dlsym(h, "glVertexP4ui"); if (p_glVertexP4ui) n++;
    *(void **)&p_glVertexP4uiv = dlsym(h, "glVertexP4uiv"); if (p_glVertexP4uiv) n++;
    *(void **)&p_glVertexPointer = dlsym(h, "glVertexPointer"); if (p_glVertexPointer) n++;
    *(void **)&p_glViewport = dlsym(h, "glViewport"); if (p_glViewport) n++;
    *(void **)&p_glViewportArrayv = dlsym(h, "glViewportArrayv"); if (p_glViewportArrayv) n++;
    *(void **)&p_glViewportIndexedf = dlsym(h, "glViewportIndexedf"); if (p_glViewportIndexedf) n++;
    *(void **)&p_glViewportIndexedfv = dlsym(h, "glViewportIndexedfv"); if (p_glViewportIndexedfv) n++;
    *(void **)&p_glWaitSync = dlsym(h, "glWaitSync"); if (p_glWaitSync) n++;
    *(void **)&p_glWindowPos2d = dlsym(h, "glWindowPos2d"); if (p_glWindowPos2d) n++;
    *(void **)&p_glWindowPos2dv = dlsym(h, "glWindowPos2dv"); if (p_glWindowPos2dv) n++;
    *(void **)&p_glWindowPos2f = dlsym(h, "glWindowPos2f"); if (p_glWindowPos2f) n++;
    *(void **)&p_glWindowPos2fv = dlsym(h, "glWindowPos2fv"); if (p_glWindowPos2fv) n++;
    *(void **)&p_glWindowPos2i = dlsym(h, "glWindowPos2i"); if (p_glWindowPos2i) n++;
    *(void **)&p_glWindowPos2iv = dlsym(h, "glWindowPos2iv"); if (p_glWindowPos2iv) n++;
    *(void **)&p_glWindowPos2s = dlsym(h, "glWindowPos2s"); if (p_glWindowPos2s) n++;
    *(void **)&p_glWindowPos2sv = dlsym(h, "glWindowPos2sv"); if (p_glWindowPos2sv) n++;
    *(void **)&p_glWindowPos3d = dlsym(h, "glWindowPos3d"); if (p_glWindowPos3d) n++;
    *(void **)&p_glWindowPos3dv = dlsym(h, "glWindowPos3dv"); if (p_glWindowPos3dv) n++;
    *(void **)&p_glWindowPos3f = dlsym(h, "glWindowPos3f"); if (p_glWindowPos3f) n++;
    *(void **)&p_glWindowPos3fv = dlsym(h, "glWindowPos3fv"); if (p_glWindowPos3fv) n++;
    *(void **)&p_glWindowPos3i = dlsym(h, "glWindowPos3i"); if (p_glWindowPos3i) n++;
    *(void **)&p_glWindowPos3iv = dlsym(h, "glWindowPos3iv"); if (p_glWindowPos3iv) n++;
    *(void **)&p_glWindowPos3s = dlsym(h, "glWindowPos3s"); if (p_glWindowPos3s) n++;
    *(void **)&p_glWindowPos3sv = dlsym(h, "glWindowPos3sv"); if (p_glWindowPos3sv) n++;
    return n;
}
