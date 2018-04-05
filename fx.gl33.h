#include <GL/glcorearb.h>

#define _FX_GL33_FN_MAP(X)                                                                                                                                                                                                                                                                         \
    X(PFNGLDEBUGMESSAGECALLBACKPROC, void, glDebugMessageCallback, GLDEBUGPROC callback, const void* userParam)                                                                                                                                                                                    \
    X(PFNGLDEBUGMESSAGECONTROLPROC, void, glDebugMessageControl, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled)                                                                                                                                 \
    X(PFNGLDEBUGMESSAGEINSERTPROC, void, glDebugMessageInsert, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf)                                                                                                                                          \
    X(PFNGLCULLFACEPROC, void, glCullFace, GLenum mode)                                                                                                                                                                                                                                            \
    X(PFNGLFRONTFACEPROC, void, glFrontFace, GLenum mode)                                                                                                                                                                                                                                          \
    X(PFNGLHINTPROC, void, glHint, GLenum target, GLenum mode)                                                                                                                                                                                                                                     \
    X(PFNGLLINEWIDTHPROC, void, glLineWidth, GLfloat width)                                                                                                                                                                                                                                        \
    X(PFNGLPOINTSIZEPROC, void, glPointSize, GLfloat size)                                                                                                                                                                                                                                         \
    X(PFNGLPOLYGONMODEPROC, void, glPolygonMode, GLenum face, GLenum mode)                                                                                                                                                                                                                         \
    X(PFNGLSCISSORPROC, void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height)                                                                                                                                                                                                          \
    X(PFNGLTEXPARAMETERFPROC, void, glTexParameterf, GLenum target, GLenum pname, GLfloat param)                                                                                                                                                                                                   \
    X(PFNGLTEXPARAMETERFVPROC, void, glTexParameterfv, GLenum target, GLenum pname, const GLfloat *params)                                                                                                                                                                                         \
    X(PFNGLTEXPARAMETERIPROC, void, glTexParameteri, GLenum target, GLenum pname, GLint param)                                                                                                                                                                                                     \
    X(PFNGLTEXPARAMETERIVPROC, void, glTexParameteriv, GLenum target, GLenum pname, const GLint *params)                                                                                                                                                                                           \
    X(PFNGLTEXIMAGE1DPROC, void, glTexImage1D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels)                                                                                                                      \
    X(PFNGLTEXIMAGE2DPROC, void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)                                                                                                      \
    X(PFNGLDRAWBUFFERPROC, void, glDrawBuffer, GLenum buf)                                                                                                                                                                                                                                         \
    X(PFNGLCLEARPROC, void, glClear, GLbitfield mask)                                                                                                                                                                                                                                              \
    X(PFNGLCLEARCOLORPROC, void, glClearColor, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)                                                                                                                                                                                            \
    X(PFNGLCLEARSTENCILPROC, void, glClearStencil, GLint s)                                                                                                                                                                                                                                        \
    X(PFNGLCLEARDEPTHPROC, void, glClearDepth, GLdouble depth)                                                                                                                                                                                                                                     \
    X(PFNGLSTENCILMASKPROC, void, glStencilMask, GLuint mask)                                                                                                                                                                                                                                      \
    X(PFNGLCOLORMASKPROC, void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)                                                                                                                                                                                      \
    X(PFNGLDEPTHMASKPROC, void, glDepthMask, GLboolean flag)                                                                                                                                                                                                                                       \
    X(PFNGLDISABLEPROC, void, glDisable, GLenum cap)                                                                                                                                                                                                                                               \
    X(PFNGLENABLEPROC, void, glEnable, GLenum cap)                                                                                                                                                                                                                                                 \
    X(PFNGLFINISHPROC, void, glFinish)                                                                                                                                                                                                                                                             \
    X(PFNGLFLUSHPROC, void, glFlush)                                                                                                                                                                                                                                                               \
    X(PFNGLBLENDFUNCPROC, void, glBlendFunc, GLenum sfactor, GLenum dfactor)                                                                                                                                                                                                                       \
    X(PFNGLLOGICOPPROC, void, glLogicOp, GLenum opcode)                                                                                                                                                                                                                                            \
    X(PFNGLSTENCILFUNCPROC, void, glStencilFunc, GLenum func, GLint ref, GLuint mask)                                                                                                                                                                                                              \
    X(PFNGLSTENCILOPPROC, void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass)                                                                                                                                                                                                              \
    X(PFNGLDEPTHFUNCPROC, void, glDepthFunc, GLenum func)                                                                                                                                                                                                                                          \
    X(PFNGLPIXELSTOREFPROC, void, glPixelStoref, GLenum pname, GLfloat param)                                                                                                                                                                                                                      \
    X(PFNGLPIXELSTOREIPROC, void, glPixelStorei, GLenum pname, GLint param)                                                                                                                                                                                                                        \
    X(PFNGLREADBUFFERPROC, void, glReadBuffer, GLenum src)                                                                                                                                                                                                                                         \
    X(PFNGLREADPIXELSPROC, void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)                                                                                                                                                          \
    X(PFNGLGETBOOLEANVPROC, void, glGetBooleanv, GLenum pname, GLboolean *data)                                                                                                                                                                                                                    \
    X(PFNGLGETDOUBLEVPROC, void, glGetDoublev, GLenum pname, GLdouble *data)                                                                                                                                                                                                                       \
    X(PFNGLGETERRORPROC, GLenum, glGetError)                                                                                                                                                                                                                                                       \
    X(PFNGLGETFLOATVPROC, void, glGetFloatv, GLenum pname, GLfloat *data)                                                                                                                                                                                                                          \
    X(PFNGLGETINTEGERVPROC, void, glGetIntegerv, GLenum pname, GLint *data)                                                                                                                                                                                                                        \
    X(PFNGLGETSTRINGPROC, const GLubyte*, glGetString, GLenum name)                                                                                                                                                                                                                                \
    X(PFNGLGETTEXIMAGEPROC, void, glGetTexImage, GLenum target, GLint level, GLenum format, GLenum type, void *pixels)                                                                                                                                                                             \
    X(PFNGLGETTEXPARAMETERFVPROC, void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat *params)                                                                                                                                                                                         \
    X(PFNGLGETTEXPARAMETERIVPROC, void, glGetTexParameteriv, GLenum target, GLenum pname, GLint *params)                                                                                                                                                                                           \
    X(PFNGLGETTEXLEVELPARAMETERFVPROC, void, glGetTexLevelParameterfv, GLenum target, GLint level, GLenum pname, GLfloat *params)                                                                                                                                                                  \
    X(PFNGLGETTEXLEVELPARAMETERIVPROC, void, glGetTexLevelParameteriv, GLenum target, GLint level, GLenum pname, GLint *params)                                                                                                                                                                    \
    X(PFNGLISENABLEDPROC, GLboolean, glIsEnabled, GLenum cap)                                                                                                                                                                                                                                      \
    X(PFNGLDEPTHRANGEPROC, void, glDepthRange, GLdouble near, GLdouble far)                                                                                                                                                                                                                        \
    X(PFNGLVIEWPORTPROC, void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height)                                                                                                                                                                                                        \
    X(PFNGLDRAWARRAYSPROC, void, glDrawArrays, GLenum mode, GLint first, GLsizei count)                                                                                                                                                                                                            \
    X(PFNGLDRAWELEMENTSPROC, void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const void *indices)                                                                                                                                                                                   \
    X(PFNGLPOLYGONOFFSETPROC, void, glPolygonOffset, GLfloat factor, GLfloat units)                                                                                                                                                                                                                \
    X(PFNGLCOPYTEXIMAGE1DPROC, void, glCopyTexImage1D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)                                                                                                                                           \
    X(PFNGLCOPYTEXIMAGE2DPROC, void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)                                                                                                                           \
    X(PFNGLCOPYTEXSUBIMAGE1DPROC, void, glCopyTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)                                                                                                                                                           \
    X(PFNGLCOPYTEXSUBIMAGE2DPROC, void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)                                                                                                                            \
    X(PFNGLTEXSUBIMAGE1DPROC, void, glTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels)                                                                                                                                     \
    X(PFNGLTEXSUBIMAGE2DPROC, void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)                                                                                                      \
    X(PFNGLBINDTEXTUREPROC, void, glBindTexture, GLenum target, GLuint texture)                                                                                                                                                                                                                    \
    X(PFNGLDELETETEXTURESPROC, void, glDeleteTextures, GLsizei n, const GLuint *textures)                                                                                                                                                                                                          \
    X(PFNGLGENTEXTURESPROC, void, glGenTextures, GLsizei n, GLuint *textures)                                                                                                                                                                                                                      \
    X(PFNGLISTEXTUREPROC, GLboolean, glIsTexture, GLuint texture)                                                                                                                                                                                                                                  \
    X(PFNGLDRAWRANGEELEMENTSPROC, void, glDrawRangeElements, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)                                                                                                                                               \
    X(PFNGLTEXIMAGE3DPROC, void, glTexImage3D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)                                                                                       \
    X(PFNGLTEXSUBIMAGE3DPROC, void, glTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)                                                                        \
    X(PFNGLCOPYTEXSUBIMAGE3DPROC, void, glCopyTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)                                                                                                             \
    X(PFNGLACTIVETEXTUREPROC, void, glActiveTexture, GLenum texture)                                                                                                                                                                                                                               \
    X(PFNGLSAMPLECOVERAGEPROC, void, glSampleCoverage, GLfloat value, GLboolean invert)                                                                                                                                                                                                            \
    X(PFNGLCOMPRESSEDTEXIMAGE3DPROC, void, glCompressedTexImage3D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)                                                                             \
    X(PFNGLCOMPRESSEDTEXIMAGE2DPROC, void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)                                                                                            \
    X(PFNGLCOMPRESSEDTEXIMAGE1DPROC, void, glCompressedTexImage1D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data)                                                                                                            \
    X(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, void, glCompressedTexSubImage3D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)                                                \
    X(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)                                                                              \
    X(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, void, glCompressedTexSubImage1D, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data)                                                                                                             \
    X(PFNGLGETCOMPRESSEDTEXIMAGEPROC, void, glGetCompressedTexImage, GLenum target, GLint level, void *img)                                                                                                                                                                                        \
    X(PFNGLBLENDFUNCSEPARATEPROC, void, glBlendFuncSeparate, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)                                                                                                                                                       \
    X(PFNGLMULTIDRAWARRAYSPROC, void, glMultiDrawArrays, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)                                                                                                                                                                 \
    X(PFNGLMULTIDRAWELEMENTSPROC, void, glMultiDrawElements, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount)                                                                                                                                         \
    X(PFNGLPOINTPARAMETERFPROC, void, glPointParameterf, GLenum pname, GLfloat param)                                                                                                                                                                                                              \
    X(PFNGLPOINTPARAMETERFVPROC, void, glPointParameterfv, GLenum pname, const GLfloat *params)                                                                                                                                                                                                    \
    X(PFNGLPOINTPARAMETERIPROC, void, glPointParameteri, GLenum pname, GLint param)                                                                                                                                                                                                                \
    X(PFNGLPOINTPARAMETERIVPROC, void, glPointParameteriv, GLenum pname, const GLint *params)                                                                                                                                                                                                      \
    X(PFNGLBLENDCOLORPROC, void, glBlendColor, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)                                                                                                                                                                                            \
    X(PFNGLBLENDEQUATIONPROC, void, glBlendEquation, GLenum mode)                                                                                                                                                                                                                                  \
    X(PFNGLGENQUERIESPROC, void, glGenQueries, GLsizei n, GLuint *ids)                                                                                                                                                                                                                             \
    X(PFNGLDELETEQUERIESPROC, void, glDeleteQueries, GLsizei n, const GLuint *ids)                                                                                                                                                                                                                 \
    X(PFNGLISQUERYPROC, GLboolean, glIsQuery, GLuint id)                                                                                                                                                                                                                                           \
    X(PFNGLBEGINQUERYPROC, void, glBeginQuery, GLenum target, GLuint id)                                                                                                                                                                                                                           \
    X(PFNGLENDQUERYPROC, void, glEndQuery, GLenum target)                                                                                                                                                                                                                                          \
    X(PFNGLGETQUERYIVPROC, void, glGetQueryiv, GLenum target, GLenum pname, GLint *params)                                                                                                                                                                                                         \
    X(PFNGLGETQUERYOBJECTIVPROC, void, glGetQueryObjectiv, GLuint id, GLenum pname, GLint *params)                                                                                                                                                                                                 \
    X(PFNGLGETQUERYOBJECTUIVPROC, void, glGetQueryObjectuiv, GLuint id, GLenum pname, GLuint *params)                                                                                                                                                                                              \
    X(PFNGLBINDBUFFERPROC, void, glBindBuffer, GLenum target, GLuint buffer)                                                                                                                                                                                                                       \
    X(PFNGLDELETEBUFFERSPROC, void, glDeleteBuffers, GLsizei n, const GLuint *buffers)                                                                                                                                                                                                             \
    X(PFNGLGENBUFFERSPROC, void, glGenBuffers, GLsizei n, GLuint *buffers)                                                                                                                                                                                                                         \
    X(PFNGLISBUFFERPROC, GLboolean, glIsBuffer, GLuint buffer)                                                                                                                                                                                                                                     \
    X(PFNGLBUFFERDATAPROC, void, glBufferData, GLenum target, GLsizeiptr size, const void *data, GLenum usage)                                                                                                                                                                                     \
    X(PFNGLBUFFERSUBDATAPROC, void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const void *data)                                                                                                                                                                            \
    X(PFNGLGETBUFFERSUBDATAPROC, void, glGetBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, void *data)                                                                                                                                                                            \
    X(PFNGLMAPBUFFERPROC, void*, glMapBuffer, GLenum target, GLenum access)                                                                                                                                                                                                                        \
    X(PFNGLUNMAPBUFFERPROC, GLboolean, glUnmapBuffer, GLenum target)                                                                                                                                                                                                                               \
    X(PFNGLGETBUFFERPARAMETERIVPROC, void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint *params)                                                                                                                                                                                     \
    X(PFNGLGETBUFFERPOINTERVPROC, void, glGetBufferPointerv, GLenum target, GLenum pname, void **params)                                                                                                                                                                                           \
    X(PFNGLBLENDEQUATIONSEPARATEPROC, void, glBlendEquationSeparate, GLenum modeRGB, GLenum modeAlpha)                                                                                                                                                                                             \
    X(PFNGLDRAWBUFFERSPROC, void, glDrawBuffers, GLsizei n, const GLenum *bufs)                                                                                                                                                                                                                    \
    X(PFNGLSTENCILOPSEPARATEPROC, void, glStencilOpSeparate, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)                                                                                                                                                                              \
    X(PFNGLSTENCILFUNCSEPARATEPROC, void, glStencilFuncSeparate, GLenum face, GLenum func, GLint ref, GLuint mask)                                                                                                                                                                                 \
    X(PFNGLSTENCILMASKSEPARATEPROC, void, glStencilMaskSeparate, GLenum face, GLuint mask)                                                                                                                                                                                                         \
    X(PFNGLATTACHSHADERPROC, void, glAttachShader, GLuint program, GLuint shader)                                                                                                                                                                                                                  \
    X(PFNGLBINDATTRIBLOCATIONPROC, void, glBindAttribLocation, GLuint program, GLuint index, const GLchar *name)                                                                                                                                                                                   \
    X(PFNGLCOMPILESHADERPROC, void, glCompileShader, GLuint shader)                                                                                                                                                                                                                                \
    X(PFNGLCREATEPROGRAMPROC, GLuint, glCreateProgram)                                                                                                                                                                                                                                             \
    X(PFNGLCREATESHADERPROC, GLuint, glCreateShader, GLenum type)                                                                                                                                                                                                                                  \
    X(PFNGLDELETEPROGRAMPROC, void, glDeleteProgram, GLuint program)                                                                                                                                                                                                                               \
    X(PFNGLDELETESHADERPROC, void, glDeleteShader, GLuint shader)                                                                                                                                                                                                                                  \
    X(PFNGLDETACHSHADERPROC, void, glDetachShader, GLuint program, GLuint shader)                                                                                                                                                                                                                  \
    X(PFNGLDISABLEVERTEXATTRIBARRAYPROC, void, glDisableVertexAttribArray, GLuint index)                                                                                                                                                                                                           \
    X(PFNGLENABLEVERTEXATTRIBARRAYPROC, void, glEnableVertexAttribArray, GLuint index)                                                                                                                                                                                                             \
    X(PFNGLGETACTIVEATTRIBPROC, void, glGetActiveAttrib, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)                                                                                                                                  \
    X(PFNGLGETACTIVEUNIFORMPROC, void, glGetActiveUniform, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)                                                                                                                                \
    X(PFNGLGETATTACHEDSHADERSPROC, void, glGetAttachedShaders, GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)                                                                                                                                                                  \
    X(PFNGLGETATTRIBLOCATIONPROC, GLint, glGetAttribLocation, GLuint program, const GLchar *name)                                                                                                                                                                                                  \
    X(PFNGLGETPROGRAMIVPROC, void, glGetProgramiv, GLuint program, GLenum pname, GLint *params)                                                                                                                                                                                                    \
    X(PFNGLGETPROGRAMINFOLOGPROC, void, glGetProgramInfoLog, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)                                                                                                                                                                    \
    X(PFNGLGETSHADERIVPROC, void, glGetShaderiv, GLuint shader, GLenum pname, GLint *params)                                                                                                                                                                                                       \
    X(PFNGLGETSHADERINFOLOGPROC, void, glGetShaderInfoLog, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)                                                                                                                                                                       \
    X(PFNGLGETSHADERSOURCEPROC, void, glGetShaderSource, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)                                                                                                                                                                          \
    X(PFNGLGETUNIFORMLOCATIONPROC, GLint, glGetUniformLocation, GLuint program, const GLchar *name)                                                                                                                                                                                                \
    X(PFNGLGETUNIFORMFVPROC, void, glGetUniformfv, GLuint program, GLint location, GLfloat *params)                                                                                                                                                                                                \
    X(PFNGLGETUNIFORMIVPROC, void, glGetUniformiv, GLuint program, GLint location, GLint *params)                                                                                                                                                                                                  \
    X(PFNGLGETVERTEXATTRIBDVPROC, void, glGetVertexAttribdv, GLuint index, GLenum pname, GLdouble *params)                                                                                                                                                                                         \
    X(PFNGLGETVERTEXATTRIBFVPROC, void, glGetVertexAttribfv, GLuint index, GLenum pname, GLfloat *params)                                                                                                                                                                                          \
    X(PFNGLGETVERTEXATTRIBIVPROC, void, glGetVertexAttribiv, GLuint index, GLenum pname, GLint *params)                                                                                                                                                                                            \
    X(PFNGLGETVERTEXATTRIBPOINTERVPROC, void, glGetVertexAttribPointerv, GLuint index, GLenum pname, void **pointer)                                                                                                                                                                               \
    X(PFNGLISPROGRAMPROC, GLboolean, glIsProgram, GLuint program)                                                                                                                                                                                                                                  \
    X(PFNGLISSHADERPROC, GLboolean, glIsShader, GLuint shader)                                                                                                                                                                                                                                     \
    X(PFNGLLINKPROGRAMPROC, void, glLinkProgram, GLuint program)                                                                                                                                                                                                                                   \
    X(PFNGLSHADERSOURCEPROC, void, glShaderSource, GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)                                                                                                                                                                  \
    X(PFNGLUSEPROGRAMPROC, void, glUseProgram, GLuint program)                                                                                                                                                                                                                                     \
    X(PFNGLUNIFORM1FPROC, void, glUniform1f, GLint location, GLfloat v0)                                                                                                                                                                                                                           \
    X(PFNGLUNIFORM2FPROC, void, glUniform2f, GLint location, GLfloat v0, GLfloat v1)                                                                                                                                                                                                               \
    X(PFNGLUNIFORM3FPROC, void, glUniform3f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)                                                                                                                                                                                                   \
    X(PFNGLUNIFORM4FPROC, void, glUniform4f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)                                                                                                                                                                                       \
    X(PFNGLUNIFORM1IPROC, void, glUniform1i, GLint location, GLint v0)                                                                                                                                                                                                                             \
    X(PFNGLUNIFORM2IPROC, void, glUniform2i, GLint location, GLint v0, GLint v1)                                                                                                                                                                                                                   \
    X(PFNGLUNIFORM3IPROC, void, glUniform3i, GLint location, GLint v0, GLint v1, GLint v2)                                                                                                                                                                                                         \
    X(PFNGLUNIFORM4IPROC, void, glUniform4i, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)                                                                                                                                                                                               \
    X(PFNGLUNIFORM1FVPROC, void, glUniform1fv, GLint location, GLsizei count, const GLfloat *value)                                                                                                                                                                                                \
    X(PFNGLUNIFORM2FVPROC, void, glUniform2fv, GLint location, GLsizei count, const GLfloat *value)                                                                                                                                                                                                \
    X(PFNGLUNIFORM3FVPROC, void, glUniform3fv, GLint location, GLsizei count, const GLfloat *value)                                                                                                                                                                                                \
    X(PFNGLUNIFORM4FVPROC, void, glUniform4fv, GLint location, GLsizei count, const GLfloat *value)                                                                                                                                                                                                \
    X(PFNGLUNIFORM1IVPROC, void, glUniform1iv, GLint location, GLsizei count, const GLint *value)                                                                                                                                                                                                  \
    X(PFNGLUNIFORM2IVPROC, void, glUniform2iv, GLint location, GLsizei count, const GLint *value)                                                                                                                                                                                                  \
    X(PFNGLUNIFORM3IVPROC, void, glUniform3iv, GLint location, GLsizei count, const GLint *value)                                                                                                                                                                                                  \
    X(PFNGLUNIFORM4IVPROC, void, glUniform4iv, GLint location, GLsizei count, const GLint *value)                                                                                                                                                                                                  \
    X(PFNGLUNIFORMMATRIX2FVPROC, void, glUniformMatrix2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                               \
    X(PFNGLUNIFORMMATRIX3FVPROC, void, glUniformMatrix3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                               \
    X(PFNGLUNIFORMMATRIX4FVPROC, void, glUniformMatrix4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                               \
    X(PFNGLVALIDATEPROGRAMPROC, void, glValidateProgram, GLuint program)                                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB1DPROC, void, glVertexAttrib1d, GLuint index, GLdouble x)                                                                                                                                                                                                                   \
    X(PFNGLVERTEXATTRIB1DVPROC, void, glVertexAttrib1dv, GLuint index, const GLdouble *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIB1FPROC, void, glVertexAttrib1f, GLuint index, GLfloat x)                                                                                                                                                                                                                    \
    X(PFNGLVERTEXATTRIB1FVPROC, void, glVertexAttrib1fv, GLuint index, const GLfloat *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB1SPROC, void, glVertexAttrib1s, GLuint index, GLshort x)                                                                                                                                                                                                                    \
    X(PFNGLVERTEXATTRIB1SVPROC, void, glVertexAttrib1sv, GLuint index, const GLshort *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB2DPROC, void, glVertexAttrib2d, GLuint index, GLdouble x, GLdouble y)                                                                                                                                                                                                       \
    X(PFNGLVERTEXATTRIB2DVPROC, void, glVertexAttrib2dv, GLuint index, const GLdouble *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIB2FPROC, void, glVertexAttrib2f, GLuint index, GLfloat x, GLfloat y)                                                                                                                                                                                                         \
    X(PFNGLVERTEXATTRIB2FVPROC, void, glVertexAttrib2fv, GLuint index, const GLfloat *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB2SPROC, void, glVertexAttrib2s, GLuint index, GLshort x, GLshort y)                                                                                                                                                                                                         \
    X(PFNGLVERTEXATTRIB2SVPROC, void, glVertexAttrib2sv, GLuint index, const GLshort *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB3DPROC, void, glVertexAttrib3d, GLuint index, GLdouble x, GLdouble y, GLdouble z)                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB3DVPROC, void, glVertexAttrib3dv, GLuint index, const GLdouble *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIB3FPROC, void, glVertexAttrib3f, GLuint index, GLfloat x, GLfloat y, GLfloat z)                                                                                                                                                                                              \
    X(PFNGLVERTEXATTRIB3FVPROC, void, glVertexAttrib3fv, GLuint index, const GLfloat *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB3SPROC, void, glVertexAttrib3s, GLuint index, GLshort x, GLshort y, GLshort z)                                                                                                                                                                                              \
    X(PFNGLVERTEXATTRIB3SVPROC, void, glVertexAttrib3sv, GLuint index, const GLshort *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB4NBVPROC, void, glVertexAttrib4Nbv, GLuint index, const GLbyte *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIB4NIVPROC, void, glVertexAttrib4Niv, GLuint index, const GLint *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB4NSVPROC, void, glVertexAttrib4Nsv, GLuint index, const GLshort *v)                                                                                                                                                                                                         \
    X(PFNGLVERTEXATTRIB4NUBPROC, void, glVertexAttrib4Nub, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)                                                                                                                                                                               \
    X(PFNGLVERTEXATTRIB4NUBVPROC, void, glVertexAttrib4Nubv, GLuint index, const GLubyte *v)                                                                                                                                                                                                       \
    X(PFNGLVERTEXATTRIB4NUIVPROC, void, glVertexAttrib4Nuiv, GLuint index, const GLuint *v)                                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIB4NUSVPROC, void, glVertexAttrib4Nusv, GLuint index, const GLushort *v)                                                                                                                                                                                                      \
    X(PFNGLVERTEXATTRIB4BVPROC, void, glVertexAttrib4bv, GLuint index, const GLbyte *v)                                                                                                                                                                                                            \
    X(PFNGLVERTEXATTRIB4DPROC, void, glVertexAttrib4d, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)                                                                                                                                                                               \
    X(PFNGLVERTEXATTRIB4DVPROC, void, glVertexAttrib4dv, GLuint index, const GLdouble *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIB4FPROC, void, glVertexAttrib4f, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)                                                                                                                                                                                   \
    X(PFNGLVERTEXATTRIB4FVPROC, void, glVertexAttrib4fv, GLuint index, const GLfloat *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB4IVPROC, void, glVertexAttrib4iv, GLuint index, const GLint *v)                                                                                                                                                                                                             \
    X(PFNGLVERTEXATTRIB4SPROC, void, glVertexAttrib4s, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)                                                                                                                                                                                   \
    X(PFNGLVERTEXATTRIB4SVPROC, void, glVertexAttrib4sv, GLuint index, const GLshort *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIB4UBVPROC, void, glVertexAttrib4ubv, GLuint index, const GLubyte *v)                                                                                                                                                                                                         \
    X(PFNGLVERTEXATTRIB4UIVPROC, void, glVertexAttrib4uiv, GLuint index, const GLuint *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIB4USVPROC, void, glVertexAttrib4usv, GLuint index, const GLushort *v)                                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIBPOINTERPROC, void, glVertexAttribPointer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)                                                                                                                                 \
    X(PFNGLUNIFORMMATRIX2X3FVPROC, void, glUniformMatrix2x3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                           \
    X(PFNGLUNIFORMMATRIX3X2FVPROC, void, glUniformMatrix3x2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                           \
    X(PFNGLUNIFORMMATRIX2X4FVPROC, void, glUniformMatrix2x4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                           \
    X(PFNGLUNIFORMMATRIX4X2FVPROC, void, glUniformMatrix4x2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                           \
    X(PFNGLUNIFORMMATRIX3X4FVPROC, void, glUniformMatrix3x4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                           \
    X(PFNGLUNIFORMMATRIX4X3FVPROC, void, glUniformMatrix4x3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)                                                                                                                                                           \
    X(PFNGLCOLORMASKIPROC, void, glColorMaski, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)                                                                                                                                                                                   \
    X(PFNGLGETBOOLEANI_VPROC, void, glGetBooleani_v, GLenum target, GLuint index, GLboolean *data)                                                                                                                                                                                                 \
    X(PFNGLGETINTEGERI_VPROC, void, glGetIntegeri_v, GLenum target, GLuint index, GLint *data)                                                                                                                                                                                                     \
    X(PFNGLENABLEIPROC, void, glEnablei, GLenum target, GLuint index)                                                                                                                                                                                                                              \
    X(PFNGLDISABLEIPROC, void, glDisablei, GLenum target, GLuint index)                                                                                                                                                                                                                            \
    X(PFNGLISENABLEDIPROC, GLboolean, glIsEnabledi, GLenum target, GLuint index)                                                                                                                                                                                                                   \
    X(PFNGLBEGINTRANSFORMFEEDBACKPROC, void, glBeginTransformFeedback, GLenum primitiveMode)                                                                                                                                                                                                       \
    X(PFNGLENDTRANSFORMFEEDBACKPROC, void, glEndTransformFeedback)                                                                                                                                                                                                                                 \
    X(PFNGLBINDBUFFERRANGEPROC, void, glBindBufferRange, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)                                                                                                                                                             \
    X(PFNGLBINDBUFFERBASEPROC, void, glBindBufferBase, GLenum target, GLuint index, GLuint buffer)                                                                                                                                                                                                 \
    X(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, void, glTransformFeedbackVaryings, GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)                                                                                                                                       \
    X(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, void, glGetTransformFeedbackVarying, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)                                                                                                        \
    X(PFNGLCLAMPCOLORPROC, void, glClampColor, GLenum target, GLenum clamp)                                                                                                                                                                                                                        \
    X(PFNGLBEGINCONDITIONALRENDERPROC, void, glBeginConditionalRender, GLuint id, GLenum mode)                                                                                                                                                                                                     \
    X(PFNGLENDCONDITIONALRENDERPROC, void, glEndConditionalRender)                                                                                                                                                                                                                                 \
    X(PFNGLVERTEXATTRIBIPOINTERPROC, void, glVertexAttribIPointer, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)                                                                                                                                                     \
    X(PFNGLGETVERTEXATTRIBIIVPROC, void, glGetVertexAttribIiv, GLuint index, GLenum pname, GLint *params)                                                                                                                                                                                          \
    X(PFNGLGETVERTEXATTRIBIUIVPROC, void, glGetVertexAttribIuiv, GLuint index, GLenum pname, GLuint *params)                                                                                                                                                                                       \
    X(PFNGLVERTEXATTRIBI1IPROC, void, glVertexAttribI1i, GLuint index, GLint x)                                                                                                                                                                                                                    \
    X(PFNGLVERTEXATTRIBI2IPROC, void, glVertexAttribI2i, GLuint index, GLint x, GLint y)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIBI3IPROC, void, glVertexAttribI3i, GLuint index, GLint x, GLint y, GLint z)                                                                                                                                                                                                  \
    X(PFNGLVERTEXATTRIBI4IPROC, void, glVertexAttribI4i, GLuint index, GLint x, GLint y, GLint z, GLint w)                                                                                                                                                                                         \
    X(PFNGLVERTEXATTRIBI1UIPROC, void, glVertexAttribI1ui, GLuint index, GLuint x)                                                                                                                                                                                                                 \
    X(PFNGLVERTEXATTRIBI2UIPROC, void, glVertexAttribI2ui, GLuint index, GLuint x, GLuint y)                                                                                                                                                                                                       \
    X(PFNGLVERTEXATTRIBI3UIPROC, void, glVertexAttribI3ui, GLuint index, GLuint x, GLuint y, GLuint z)                                                                                                                                                                                             \
    X(PFNGLVERTEXATTRIBI4UIPROC, void, glVertexAttribI4ui, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)                                                                                                                                                                                   \
    X(PFNGLVERTEXATTRIBI1IVPROC, void, glVertexAttribI1iv, GLuint index, const GLint *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIBI2IVPROC, void, glVertexAttribI2iv, GLuint index, const GLint *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIBI3IVPROC, void, glVertexAttribI3iv, GLuint index, const GLint *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIBI4IVPROC, void, glVertexAttribI4iv, GLuint index, const GLint *v)                                                                                                                                                                                                           \
    X(PFNGLVERTEXATTRIBI1UIVPROC, void, glVertexAttribI1uiv, GLuint index, const GLuint *v)                                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIBI2UIVPROC, void, glVertexAttribI2uiv, GLuint index, const GLuint *v)                                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIBI3UIVPROC, void, glVertexAttribI3uiv, GLuint index, const GLuint *v)                                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIBI4UIVPROC, void, glVertexAttribI4uiv, GLuint index, const GLuint *v)                                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIBI4BVPROC, void, glVertexAttribI4bv, GLuint index, const GLbyte *v)                                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIBI4SVPROC, void, glVertexAttribI4sv, GLuint index, const GLshort *v)                                                                                                                                                                                                         \
    X(PFNGLVERTEXATTRIBI4UBVPROC, void, glVertexAttribI4ubv, GLuint index, const GLubyte *v)                                                                                                                                                                                                       \
    X(PFNGLVERTEXATTRIBI4USVPROC, void, glVertexAttribI4usv, GLuint index, const GLushort *v)                                                                                                                                                                                                      \
    X(PFNGLGETUNIFORMUIVPROC, void, glGetUniformuiv, GLuint program, GLint location, GLuint *params)                                                                                                                                                                                               \
    X(PFNGLBINDFRAGDATALOCATIONPROC, void, glBindFragDataLocation, GLuint program, GLuint color, const GLchar *name)                                                                                                                                                                               \
    X(PFNGLGETFRAGDATALOCATIONPROC, GLint, glGetFragDataLocation, GLuint program, const GLchar *name)                                                                                                                                                                                              \
    X(PFNGLUNIFORM1UIPROC, void, glUniform1ui, GLint location, GLuint v0)                                                                                                                                                                                                                          \
    X(PFNGLUNIFORM2UIPROC, void, glUniform2ui, GLint location, GLuint v0, GLuint v1)                                                                                                                                                                                                               \
    X(PFNGLUNIFORM3UIPROC, void, glUniform3ui, GLint location, GLuint v0, GLuint v1, GLuint v2)                                                                                                                                                                                                    \
    X(PFNGLUNIFORM4UIPROC, void, glUniform4ui, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)                                                                                                                                                                                         \
    X(PFNGLUNIFORM1UIVPROC, void, glUniform1uiv, GLint location, GLsizei count, const GLuint *value)                                                                                                                                                                                               \
    X(PFNGLUNIFORM2UIVPROC, void, glUniform2uiv, GLint location, GLsizei count, const GLuint *value)                                                                                                                                                                                               \
    X(PFNGLUNIFORM3UIVPROC, void, glUniform3uiv, GLint location, GLsizei count, const GLuint *value)                                                                                                                                                                                               \
    X(PFNGLUNIFORM4UIVPROC, void, glUniform4uiv, GLint location, GLsizei count, const GLuint *value)                                                                                                                                                                                               \
    X(PFNGLTEXPARAMETERIIVPROC, void, glTexParameterIiv, GLenum target, GLenum pname, const GLint *params)                                                                                                                                                                                         \
    X(PFNGLTEXPARAMETERIUIVPROC, void, glTexParameterIuiv, GLenum target, GLenum pname, const GLuint *params)                                                                                                                                                                                      \
    X(PFNGLGETTEXPARAMETERIIVPROC, void, glGetTexParameterIiv, GLenum target, GLenum pname, GLint *params)                                                                                                                                                                                         \
    X(PFNGLGETTEXPARAMETERIUIVPROC, void, glGetTexParameterIuiv, GLenum target, GLenum pname, GLuint *params)                                                                                                                                                                                      \
    X(PFNGLCLEARBUFFERIVPROC, void, glClearBufferiv, GLenum buffer, GLint drawbuffer, const GLint *value)                                                                                                                                                                                          \
    X(PFNGLCLEARBUFFERUIVPROC, void, glClearBufferuiv, GLenum buffer, GLint drawbuffer, const GLuint *value)                                                                                                                                                                                       \
    X(PFNGLCLEARBUFFERFVPROC, void, glClearBufferfv, GLenum buffer, GLint drawbuffer, const GLfloat *value)                                                                                                                                                                                        \
    X(PFNGLCLEARBUFFERFIPROC, void, glClearBufferfi, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)                                                                                                                                                                                \
    X(PFNGLGETSTRINGIPROC, const GLubyte*, glGetStringi, GLenum name, GLuint index)                                                                                                                                                                                                                \
    X(PFNGLISRENDERBUFFERPROC, GLboolean, glIsRenderbuffer, GLuint renderbuffer)                                                                                                                                                                                                                   \
    X(PFNGLBINDRENDERBUFFERPROC, void, glBindRenderbuffer, GLenum target, GLuint renderbuffer)                                                                                                                                                                                                     \
    X(PFNGLDELETERENDERBUFFERSPROC, void, glDeleteRenderbuffers, GLsizei n, const GLuint *renderbuffers)                                                                                                                                                                                           \
    X(PFNGLGENRENDERBUFFERSPROC, void, glGenRenderbuffers, GLsizei n, GLuint *renderbuffers)                                                                                                                                                                                                       \
    X(PFNGLRENDERBUFFERSTORAGEPROC, void, glRenderbufferStorage, GLenum target, GLenum internalformat, GLsizei width, GLsizei height)                                                                                                                                                              \
    X(PFNGLGETRENDERBUFFERPARAMETERIVPROC, void, glGetRenderbufferParameteriv, GLenum target, GLenum pname, GLint *params)                                                                                                                                                                         \
    X(PFNGLISFRAMEBUFFERPROC, GLboolean, glIsFramebuffer, GLuint framebuffer)                                                                                                                                                                                                                      \
    X(PFNGLBINDFRAMEBUFFERPROC, void, glBindFramebuffer, GLenum target, GLuint framebuffer)                                                                                                                                                                                                        \
    X(PFNGLDELETEFRAMEBUFFERSPROC, void, glDeleteFramebuffers, GLsizei n, const GLuint *framebuffers)                                                                                                                                                                                              \
    X(PFNGLGENFRAMEBUFFERSPROC, void, glGenFramebuffers, GLsizei n, GLuint *framebuffers)                                                                                                                                                                                                          \
    X(PFNGLCHECKFRAMEBUFFERSTATUSPROC, GLenum, glCheckFramebufferStatus, GLenum target)                                                                                                                                                                                                            \
    X(PFNGLFRAMEBUFFERTEXTURE1DPROC, void, glFramebufferTexture1D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)                                                                                                                                                \
    X(PFNGLFRAMEBUFFERTEXTURE2DPROC, void, glFramebufferTexture2D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)                                                                                                                                                \
    X(PFNGLFRAMEBUFFERTEXTURE3DPROC, void, glFramebufferTexture3D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)                                                                                                                                 \
    X(PFNGLFRAMEBUFFERRENDERBUFFERPROC, void, glFramebufferRenderbuffer, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)                                                                                                                                         \
    X(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, void, glGetFramebufferAttachmentParameteriv, GLenum target, GLenum attachment, GLenum pname, GLint *params)                                                                                                                                    \
    X(PFNGLGENERATEMIPMAPPROC, void, glGenerateMipmap, GLenum target)                                                                                                                                                                                                                              \
    X(PFNGLBLITFRAMEBUFFERPROC, void, glBlitFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)                                                                                                   \
    X(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, void, glRenderbufferStorageMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)                                                                                                                       \
    X(PFNGLFRAMEBUFFERTEXTURELAYERPROC, void, glFramebufferTextureLayer, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)                                                                                                                                               \
    X(PFNGLMAPBUFFERRANGEPROC, void*, glMapBufferRange, GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)                                                                                                                                                                      \
    X(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, void, glFlushMappedBufferRange, GLenum target, GLintptr offset, GLsizeiptr length)                                                                                                                                                                          \
    X(PFNGLBINDVERTEXARRAYPROC, void, glBindVertexArray, GLuint array)                                                                                                                                                                                                                             \
    X(PFNGLDELETEVERTEXARRAYSPROC, void, glDeleteVertexArrays, GLsizei n, const GLuint *arrays)                                                                                                                                                                                                    \
    X(PFNGLGENVERTEXARRAYSPROC, void, glGenVertexArrays, GLsizei n, GLuint *arrays)                                                                                                                                                                                                                \
    X(PFNGLISVERTEXARRAYPROC, GLboolean, glIsVertexArray, GLuint array)                                                                                                                                                                                                                            \
    X(PFNGLDRAWARRAYSINSTANCEDPROC, void, glDrawArraysInstanced, GLenum mode, GLint first, GLsizei count, GLsizei instancecount)                                                                                                                                                                   \
    X(PFNGLDRAWELEMENTSINSTANCEDPROC, void, glDrawElementsInstanced, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount)                                                                                                                                          \
    X(PFNGLTEXBUFFERPROC, void, glTexBuffer, GLenum target, GLenum internalformat, GLuint buffer)                                                                                                                                                                                                  \
    X(PFNGLPRIMITIVERESTARTINDEXPROC, void, glPrimitiveRestartIndex, GLuint index)                                                                                                                                                                                                                 \
    X(PFNGLCOPYBUFFERSUBDATAPROC, void, glCopyBufferSubData, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)                                                                                                                                    \
    X(PFNGLGETUNIFORMINDICESPROC, void, glGetUniformIndices, GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices)                                                                                                                                       \
    X(PFNGLGETACTIVEUNIFORMSIVPROC, void, glGetActiveUniformsiv, GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)                                                                                                                                  \
    X(PFNGLGETACTIVEUNIFORMNAMEPROC, void, glGetActiveUniformName, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)                                                                                                                                     \
    X(PFNGLGETUNIFORMBLOCKINDEXPROC, GLuint, glGetUniformBlockIndex, GLuint program, const GLchar *uniformBlockName)                                                                                                                                                                               \
    X(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, void, glGetActiveUniformBlockiv, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)                                                                                                                                                    \
    X(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, void, glGetActiveUniformBlockName, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)                                                                                                                 \
    X(PFNGLUNIFORMBLOCKBINDINGPROC, void, glUniformBlockBinding, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)                                                                                                                                                             \
    X(PFNGLDRAWELEMENTSBASEVERTEXPROC, void, glDrawElementsBaseVertex, GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)                                                                                                                                             \
    X(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, void, glDrawRangeElementsBaseVertex, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)                                                                                                         \
    X(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, void, glDrawElementsInstancedBaseVertex, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)                                                                                                    \
    X(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, void, glMultiDrawElementsBaseVertex, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex)                                                                                            \
    X(PFNGLPROVOKINGVERTEXPROC, void, glProvokingVertex, GLenum mode)                                                                                                                                                                                                                              \
    X(PFNGLFENCESYNCPROC, GLsync, glFenceSync, GLenum condition, GLbitfield flags)                                                                                                                                                                                                                 \
    X(PFNGLISSYNCPROC, GLboolean, glIsSync, GLsync sync)                                                                                                                                                                                                                                           \
    X(PFNGLDELETESYNCPROC, void, glDeleteSync, GLsync sync)                                                                                                                                                                                                                                        \
    X(PFNGLCLIENTWAITSYNCPROC, GLenum, glClientWaitSync, GLsync sync, GLbitfield flags, GLuint64 timeout)                                                                                                                                                                                          \
    X(PFNGLWAITSYNCPROC, void, glWaitSync, GLsync sync, GLbitfield flags, GLuint64 timeout)                                                                                                                                                                                                        \
    X(PFNGLGETINTEGER64VPROC, void, glGetInteger64v, GLenum pname, GLint64 *data)                                                                                                                                                                                                                  \
    X(PFNGLGETSYNCIVPROC, void, glGetSynciv, GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)                                                                                                                                                                           \
    X(PFNGLGETINTEGER64I_VPROC, void, glGetInteger64i_v, GLenum target, GLuint index, GLint64 *data)                                                                                                                                                                                               \
    X(PFNGLGETBUFFERPARAMETERI64VPROC, void, glGetBufferParameteri64v, GLenum target, GLenum pname, GLint64 *params)                                                                                                                                                                               \
    X(PFNGLFRAMEBUFFERTEXTUREPROC, void, glFramebufferTexture, GLenum target, GLenum attachment, GLuint texture, GLint level)                                                                                                                                                                      \
    X(PFNGLTEXIMAGE2DMULTISAMPLEPROC, void, glTexImage2DMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)                                                                                                         \
    X(PFNGLTEXIMAGE3DMULTISAMPLEPROC, void, glTexImage3DMultisample, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)                                                                                          \
    X(PFNGLGETMULTISAMPLEFVPROC, void, glGetMultisamplefv, GLenum pname, GLuint index, GLfloat *val)                                                                                                                                                                                               \
    X(PFNGLSAMPLEMASKIPROC, void, glSampleMaski, GLuint maskNumber, GLbitfield mask)                                                                                                                                                                                                               \
    X(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, void, glBindFragDataLocationIndexed, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)                                                                                                                                             \
    X(PFNGLGETFRAGDATAINDEXPROC, GLint, glGetFragDataIndex, GLuint program, const GLchar *name)                                                                                                                                                                                                    \
    X(PFNGLGENSAMPLERSPROC, void, glGenSamplers, GLsizei count, GLuint *samplers)                                                                                                                                                                                                                  \
    X(PFNGLDELETESAMPLERSPROC, void, glDeleteSamplers, GLsizei count, const GLuint *samplers)                                                                                                                                                                                                      \
    X(PFNGLISSAMPLERPROC, GLboolean, glIsSampler, GLuint sampler)                                                                                                                                                                                                                                  \
    X(PFNGLBINDSAMPLERPROC, void, glBindSampler, GLuint unit, GLuint sampler)                                                                                                                                                                                                                      \
    X(PFNGLSAMPLERPARAMETERIPROC, void, glSamplerParameteri, GLuint sampler, GLenum pname, GLint param)                                                                                                                                                                                            \
    X(PFNGLSAMPLERPARAMETERIVPROC, void, glSamplerParameteriv, GLuint sampler, GLenum pname, const GLint *param)                                                                                                                                                                                   \
    X(PFNGLSAMPLERPARAMETERFPROC, void, glSamplerParameterf, GLuint sampler, GLenum pname, GLfloat param)                                                                                                                                                                                          \
    X(PFNGLSAMPLERPARAMETERFVPROC, void, glSamplerParameterfv, GLuint sampler, GLenum pname, const GLfloat *param)                                                                                                                                                                                 \
    X(PFNGLSAMPLERPARAMETERIIVPROC, void, glSamplerParameterIiv, GLuint sampler, GLenum pname, const GLint *param)                                                                                                                                                                                 \
    X(PFNGLSAMPLERPARAMETERIUIVPROC, void, glSamplerParameterIuiv, GLuint sampler, GLenum pname, const GLuint *param)                                                                                                                                                                              \
    X(PFNGLGETSAMPLERPARAMETERIVPROC, void, glGetSamplerParameteriv, GLuint sampler, GLenum pname, GLint *params)                                                                                                                                                                                  \
    X(PFNGLGETSAMPLERPARAMETERIIVPROC, void, glGetSamplerParameterIiv, GLuint sampler, GLenum pname, GLint *params)                                                                                                                                                                                \
    X(PFNGLGETSAMPLERPARAMETERFVPROC, void, glGetSamplerParameterfv, GLuint sampler, GLenum pname, GLfloat *params)                                                                                                                                                                                \
    X(PFNGLGETSAMPLERPARAMETERIUIVPROC, void, glGetSamplerParameterIuiv, GLuint sampler, GLenum pname, GLuint *params)                                                                                                                                                                             \
    X(PFNGLQUERYCOUNTERPROC, void, glQueryCounter, GLuint id, GLenum target)                                                                                                                                                                                                                       \
    X(PFNGLGETQUERYOBJECTI64VPROC, void, glGetQueryObjecti64v, GLuint id, GLenum pname, GLint64 *params)                                                                                                                                                                                           \
    X(PFNGLGETQUERYOBJECTUI64VPROC, void, glGetQueryObjectui64v, GLuint id, GLenum pname, GLuint64 *params)                                                                                                                                                                                        \
    X(PFNGLVERTEXATTRIBDIVISORPROC, void, glVertexAttribDivisor, GLuint index, GLuint divisor)                                                                                                                                                                                                     \
    X(PFNGLVERTEXATTRIBP1UIPROC, void, glVertexAttribP1ui, GLuint index, GLenum type, GLboolean normalized, GLuint value)                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIBP1UIVPROC, void, glVertexAttribP1uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)                                                                                                                                                                 \
    X(PFNGLVERTEXATTRIBP2UIPROC, void, glVertexAttribP2ui, GLuint index, GLenum type, GLboolean normalized, GLuint value)                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIBP2UIVPROC, void, glVertexAttribP2uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)                                                                                                                                                                 \
    X(PFNGLVERTEXATTRIBP3UIPROC, void, glVertexAttribP3ui, GLuint index, GLenum type, GLboolean normalized, GLuint value)                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIBP3UIVPROC, void, glVertexAttribP3uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)                                                                                                                                                                 \
    X(PFNGLVERTEXATTRIBP4UIPROC, void, glVertexAttribP4ui, GLuint index, GLenum type, GLboolean normalized, GLuint value)                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIBP4UIVPROC, void, glVertexAttribP4uiv, GLuint index, GLenum type, GLboolean normalized, const GLuint *value)                                                                                                                                                                 \
    X(PFNGLVERTEXP2UIPROC, void, glVertexP2ui, GLenum type, GLuint value)                                                                                                                                                                                                                          \
    X(PFNGLVERTEXP2UIVPROC, void, glVertexP2uiv, GLenum type, const GLuint *value)                                                                                                                                                                                                                 \
    X(PFNGLVERTEXP3UIPROC, void, glVertexP3ui, GLenum type, GLuint value)                                                                                                                                                                                                                          \
    X(PFNGLVERTEXP3UIVPROC, void, glVertexP3uiv, GLenum type, const GLuint *value)                                                                                                                                                                                                                 \
    X(PFNGLVERTEXP4UIPROC, void, glVertexP4ui, GLenum type, GLuint value)                                                                                                                                                                                                                          \
    X(PFNGLVERTEXP4UIVPROC, void, glVertexP4uiv, GLenum type, const GLuint *value)                                                                                                                                                                                                                 \
    X(PFNGLTEXCOORDP1UIPROC, void, glTexCoordP1ui, GLenum type, GLuint coords)                                                                                                                                                                                                                     \
    X(PFNGLTEXCOORDP1UIVPROC, void, glTexCoordP1uiv, GLenum type, const GLuint *coords)                                                                                                                                                                                                            \
    X(PFNGLTEXCOORDP2UIPROC, void, glTexCoordP2ui, GLenum type, GLuint coords)                                                                                                                                                                                                                     \
    X(PFNGLTEXCOORDP2UIVPROC, void, glTexCoordP2uiv, GLenum type, const GLuint *coords)                                                                                                                                                                                                            \
    X(PFNGLTEXCOORDP3UIPROC, void, glTexCoordP3ui, GLenum type, GLuint coords)                                                                                                                                                                                                                     \
    X(PFNGLTEXCOORDP3UIVPROC, void, glTexCoordP3uiv, GLenum type, const GLuint *coords)                                                                                                                                                                                                            \
    X(PFNGLTEXCOORDP4UIPROC, void, glTexCoordP4ui, GLenum type, GLuint coords)                                                                                                                                                                                                                     \
    X(PFNGLTEXCOORDP4UIVPROC, void, glTexCoordP4uiv, GLenum type, const GLuint *coords)                                                                                                                                                                                                            \
    X(PFNGLMULTITEXCOORDP1UIPROC, void, glMultiTexCoordP1ui, GLenum texture, GLenum type, GLuint coords)                                                                                                                                                                                           \
    X(PFNGLMULTITEXCOORDP1UIVPROC, void, glMultiTexCoordP1uiv, GLenum texture, GLenum type, const GLuint *coords)                                                                                                                                                                                  \
    X(PFNGLMULTITEXCOORDP2UIPROC, void, glMultiTexCoordP2ui, GLenum texture, GLenum type, GLuint coords)                                                                                                                                                                                           \
    X(PFNGLMULTITEXCOORDP2UIVPROC, void, glMultiTexCoordP2uiv, GLenum texture, GLenum type, const GLuint *coords)                                                                                                                                                                                  \
    X(PFNGLMULTITEXCOORDP3UIPROC, void, glMultiTexCoordP3ui, GLenum texture, GLenum type, GLuint coords)                                                                                                                                                                                           \
    X(PFNGLMULTITEXCOORDP3UIVPROC, void, glMultiTexCoordP3uiv, GLenum texture, GLenum type, const GLuint *coords)                                                                                                                                                                                  \
    X(PFNGLMULTITEXCOORDP4UIPROC, void, glMultiTexCoordP4ui, GLenum texture, GLenum type, GLuint coords)                                                                                                                                                                                           \
    X(PFNGLMULTITEXCOORDP4UIVPROC, void, glMultiTexCoordP4uiv, GLenum texture, GLenum type, const GLuint *coords)                                                                                                                                                                                  \
    X(PFNGLNORMALP3UIPROC, void, glNormalP3ui, GLenum type, GLuint coords)                                                                                                                                                                                                                         \
    X(PFNGLNORMALP3UIVPROC, void, glNormalP3uiv, GLenum type, const GLuint *coords)                                                                                                                                                                                                                \
    X(PFNGLCOLORP3UIPROC, void, glColorP3ui, GLenum type, GLuint color)                                                                                                                                                                                                                            \
    X(PFNGLCOLORP3UIVPROC, void, glColorP3uiv, GLenum type, const GLuint *color)                                                                                                                                                                                                                   \
    X(PFNGLCOLORP4UIPROC, void, glColorP4ui, GLenum type, GLuint color)                                                                                                                                                                                                                            \
    X(PFNGLCOLORP4UIVPROC, void, glColorP4uiv, GLenum type, const GLuint *color)                                                                                                                                                                                                                   \
    X(PFNGLSECONDARYCOLORP3UIPROC, void, glSecondaryColorP3ui, GLenum type, GLuint color)                                                                                                                                                                                                          \
    X(PFNGLSECONDARYCOLORP3UIVPROC, void, glSecondaryColorP3uiv, GLenum type, const GLuint *color)

static uint32_t _FX_GL33_LINE = 0;

#if !defined(GL_COMPRESSED_RGBA_S3TC_DXT1_EXT)
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT (0x83F1)
#endif

#if !defined(GL_COMPRESSED_RGBA_S3TC_DXT3_EXT)
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT (0x83F2)
#endif

#if !defined(GL_COMPRESSED_RGBA_S3TC_DXT5_EXT)
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT (0x83F3)
#endif

#if !defined(GL_ETC1_RGB8_OES)
#define GL_ETC1_RGB8_OES (0x8D64)
#endif

#if !defined(GL_COMPRESSED_RGB8_ETC2)
#define GL_COMPRESSED_RGB8_ETC2 (0x9274)
#endif

#if !defined(GL_COMPRESSED_RGBA8_ETC2_EAC)
#define GL_COMPRESSED_RGBA8_ETC2_EAC (0x9278)
#endif

#if !defined(GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2)
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 (0x9276)
#endif

static const GLenum _FX_GL33_INDEX_TYPE[] = {
    GL_UNSIGNED_SHORT,
    GL_UNSIGNED_INT,
};

static const GLenum _FX_GL33_PRIMITIVE[] = {
    GL_TRIANGLES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,
    GL_POINTS,
    GL_LINES,
    GL_LINE_STRIP,
    GL_PATCHES,
};

static const GLenum _FX_GL33_POLYGON[] = {
    GL_FILL,
    GL_LINE,
    GL_POINT,
};

static const GLenum _FX_GL33_CULL[] = {
    GL_NONE,
    GL_FRONT,
    GL_BACK,
    GL_FRONT_AND_BACK,
};

static const GLenum _FX_GL33_FRONT_FACE[] = {
    GL_CCW,
    GL_CW,
};

static const GLenum _FX_GL33_COMPARE_FUNC[] = {
    GL_ALWAYS,
    GL_LESS,
    GL_LEQUAL,
    GL_EQUAL,
    GL_NOTEQUAL,
    GL_GREATER,
    GL_GEQUAL,
    GL_NEVER,
};

static const GLenum _FX_GL33_STENCIL_OP[] = {
    GL_KEEP,
    GL_ZERO,
    GL_REPLACE,
    GL_INCR,
    GL_INCR_WRAP,
    GL_DECR,
    GL_DECR_WRAP,
    GL_INVERT,
};

static const GLenum _FX_GL33_BLEND_FACTOR[] = {
    GL_ZERO,
    GL_ONE,
    GL_SRC_COLOR,
    GL_ONE_MINUS_SRC_COLOR,
    GL_DST_COLOR,
    GL_ONE_MINUS_DST_COLOR,
    GL_SRC_ALPHA,
    GL_ONE_MINUS_SRC_ALPHA,
    GL_DST_ALPHA,
    GL_ONE_MINUS_DST_ALPHA,
    GL_CONSTANT_COLOR,
    GL_ONE_MINUS_CONSTANT_COLOR,
    GL_CONSTANT_ALPHA,
    GL_ONE_MINUS_CONSTANT_ALPHA,
    GL_SRC_ALPHA_SATURATE,
    GL_SRC1_COLOR,
    GL_ONE_MINUS_SRC1_COLOR,
    GL_SRC1_ALPHA,
    GL_ONE_MINUS_SRC1_ALPHA,
};

static const GLenum _FX_GL33_LOGIC_OP[] = {
    GL_COPY,
    GL_NOOP,
    GL_CLEAR,
    GL_AND,
    GL_AND_REVERSE,
    GL_AND_INVERTED,
    GL_XOR,
    GL_OR,
    GL_NOR,
    GL_EQUIV,
    GL_INVERT,
    GL_OR_REVERSE,
    GL_COPY_INVERTED,
    GL_OR_INVERTED,
    GL_NAND,
    GL_SET,
};

static const GLenum _FX_GL33_BLEND_OP[] = {
    GL_FUNC_ADD,
    GL_FUNC_SUBTRACT,
    GL_FUNC_REVERSE_SUBTRACT,
    GL_MIN,
    GL_MAX
};

static const GLenum _FX_GL33_COMPONENT_SWIZZLE[] = {
    GL_NONE,
    GL_ZERO,
    GL_ONE,
    GL_RED,
    GL_GREEN,
    GL_BLUE,
    GL_ALPHA
};

static const GLenum _FX_GL33_BUFFER_TARGET[] = {
    GL_ARRAY_BUFFER,
    GL_ELEMENT_ARRAY_BUFFER,
    GL_UNIFORM_BUFFER,
};

static const GLenum _FX_GL33_BUFFER_USAGE[] = {
    GL_ARRAY_BUFFER,
    GL_ELEMENT_ARRAY_BUFFER,
    GL_UNIFORM_BUFFER
};

static struct {
    uint8_t size;
    uint8_t count;
    GLboolean normalised;
    GLenum kind;
    GLenum internal_format;
    GLenum format;
} _FX_GL33_FORMAT[] = {
    { 0, 0, 0,           GL_NONE,                                     GL_NONE,                                     GL_NONE, },

    { 0, 0, 0,           GL_NONE,            GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,            GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, },
    { 0, 0, 0,           GL_NONE,            GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,            GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, },
    { 0, 0, 0,           GL_NONE,            GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,            GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, },
    { 0, 0, 0,           GL_NONE,                            GL_ETC1_RGB8_OES,                            GL_ETC1_RGB8_OES, },
    { 0, 0, 0,           GL_NONE,                     GL_COMPRESSED_RGB8_ETC2,                     GL_COMPRESSED_RGB8_ETC2, },
    { 0, 0, 0,           GL_NONE,                GL_COMPRESSED_RGBA8_ETC2_EAC,                GL_COMPRESSED_RGBA8_ETC2_EAC, },
    { 0, 0, 0,           GL_NONE, GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2, GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2, },

    { 1, 1, 1,  GL_UNSIGNED_BYTE,                                       GL_R8,                                      GL_RED, },
    { 1, 1, 1,           GL_BYTE,                                       GL_R8,                                      GL_RED, },
    { 1, 1, 0,  GL_UNSIGNED_BYTE,                                     GL_R8UI,                              GL_RED_INTEGER, },
    { 1, 1, 0,           GL_BYTE,                                      GL_R8I,                              GL_RED_INTEGER, },
    { 1, 2, 1,  GL_UNSIGNED_BYTE,                                      GL_RG8,                                       GL_RG, },
    { 1, 2, 1,           GL_BYTE,                                      GL_RG8,                                       GL_RG, },
    { 1, 2, 0,  GL_UNSIGNED_BYTE,                                    GL_RG8UI,                               GL_RG_INTEGER, },
    { 1, 2, 0,           GL_BYTE,                                     GL_RG8I,                               GL_RG_INTEGER, },
    { 1, 3, 1,  GL_UNSIGNED_BYTE,                                     GL_RGB8,                                      GL_RGB, },
    { 1, 3, 1,           GL_BYTE,                                     GL_RGB8,                                      GL_RGB, },
    { 1, 3, 0,  GL_UNSIGNED_BYTE,                                   GL_RGB8UI,                              GL_RGB_INTEGER, },
    { 1, 3, 0,           GL_BYTE,                                    GL_RGB8I,                              GL_RGB_INTEGER, },
    { 1, 4, 1,  GL_UNSIGNED_BYTE,                                    GL_RGBA8,                                     GL_RGBA, },
    { 1, 4, 1,           GL_BYTE,                                    GL_RGBA8,                                     GL_RGBA, },
    { 1, 4, 0,  GL_UNSIGNED_BYTE,                                  GL_RGBA8UI,                             GL_RGBA_INTEGER, },
    { 1, 4, 0,           GL_BYTE,                                   GL_RGBA8I,                             GL_RGBA_INTEGER, },
    { 1, 4, 1,  GL_UNSIGNED_BYTE,                                    GL_RGBA8,                                     GL_BGRA, },
    { 1, 4, 1,           GL_BYTE,                                    GL_RGBA8,                                     GL_BGRA, },
    { 1, 4, 0,  GL_UNSIGNED_BYTE,                                  GL_RGBA8UI,                             GL_BGRA_INTEGER, },
    { 1, 4, 0,           GL_BYTE,                                   GL_RGBA8I,                             GL_BGRA_INTEGER, },

    { 2, 1, 1, GL_UNSIGNED_SHORT,                                    GL_R16UI,                                      GL_RED, },
    { 2, 1, 1,          GL_SHORT,                                     GL_R16I,                                      GL_RED, },
    { 2, 1, 0, GL_UNSIGNED_SHORT,                                    GL_R16UI,                              GL_RED_INTEGER, },
    { 2, 1, 0,          GL_SHORT,                                     GL_R16I,                              GL_RED_INTEGER, },
    { 2, 2, 1, GL_UNSIGNED_SHORT,                                   GL_RG16UI,                                       GL_RG, },
    { 2, 2, 1,          GL_SHORT,                                    GL_RG16I,                                       GL_RG, },
    { 2, 2, 0, GL_UNSIGNED_SHORT,                                   GL_RG16UI,                               GL_RG_INTEGER, },
    { 2, 2, 0,          GL_SHORT,                                    GL_RG16I,                               GL_RG_INTEGER, },
    { 2, 3, 1, GL_UNSIGNED_SHORT,                                  GL_RGB16UI,                                      GL_RGB, },
    { 2, 3, 1,          GL_SHORT,                                   GL_RGB16I,                                      GL_RGB, },
    { 2, 3, 0, GL_UNSIGNED_SHORT,                                  GL_RGB16UI,                              GL_RGB_INTEGER, },
    { 2, 3, 0,          GL_SHORT,                                   GL_RGB16I,                              GL_RGB_INTEGER, },
    { 2, 4, 1, GL_UNSIGNED_SHORT,                                 GL_RGBA16UI,                                     GL_RGBA, },
    { 2, 4, 1,          GL_SHORT,                                  GL_RGBA16I,                                     GL_RGBA, },
    { 2, 4, 0, GL_UNSIGNED_SHORT,                                 GL_RGBA16UI,                             GL_RGBA_INTEGER, },
    { 2, 4, 0,          GL_SHORT,                                  GL_RGBA16I,                             GL_RGBA_INTEGER, },

    { 4, 1, 1,   GL_UNSIGNED_INT,                                    GL_R32UI,                                      GL_RED, },
    { 4, 1, 1,            GL_INT,                                     GL_R32I,                                      GL_RED, },
    { 4, 1, 0,   GL_UNSIGNED_INT,                                    GL_R32UI,                              GL_RED_INTEGER, },
    { 4, 1, 0,            GL_INT,                                     GL_R32I,                              GL_RED_INTEGER, },
    { 4, 2, 1,   GL_UNSIGNED_INT,                                   GL_RG32UI,                                       GL_RG, },
    { 4, 2, 1,            GL_INT,                                    GL_RG32I,                                       GL_RG, },
    { 4, 2, 0,   GL_UNSIGNED_INT,                                   GL_RG32UI,                               GL_RG_INTEGER, },
    { 4, 2, 0,            GL_INT,                                    GL_RG32I,                               GL_RG_INTEGER, },
    { 4, 3, 1,   GL_UNSIGNED_INT,                                  GL_RGB32UI,                                      GL_RGB, },
    { 4, 3, 1,            GL_INT,                                   GL_RGB32I,                                      GL_RGB, },
    { 4, 3, 0,   GL_UNSIGNED_INT,                                  GL_RGB32UI,                              GL_RGB_INTEGER, },
    { 4, 3, 0,            GL_INT,                                   GL_RGB32I,                              GL_RGB_INTEGER, },
    { 4, 4, 1,   GL_UNSIGNED_INT,                                 GL_RGBA32UI,                                     GL_RGBA, },
    { 4, 4, 1,            GL_INT,                                  GL_RGBA32I,                                     GL_RGBA, },
    { 4, 4, 0,   GL_UNSIGNED_INT,                                 GL_RGBA32UI,                             GL_RGBA_INTEGER, },
    { 4, 4, 0,            GL_INT,                                  GL_RGBA32I,                             GL_RGBA_INTEGER, },

    { 2, 1, 1,          GL_FLOAT,                                     GL_R16F,                                      GL_RED, },
    { 2, 1, 0,          GL_FLOAT,                                     GL_R16F,                                      GL_RED, },
    { 2, 2, 1,          GL_FLOAT,                                    GL_RG16F,                                       GL_RG, },
    { 2, 2, 0,          GL_FLOAT,                                    GL_RG16F,                                       GL_RG, },
    { 2, 3, 1,          GL_FLOAT,                                   GL_RGB16F,                                      GL_RGB, },
    { 2, 3, 0,          GL_FLOAT,                                   GL_RGB16F,                                      GL_RGB, },
    { 2, 4, 1,          GL_FLOAT,                                  GL_RGBA16F,                                     GL_RGBA, },
    { 2, 4, 0,          GL_FLOAT,                                  GL_RGBA16F,                                     GL_RGBA, },

    { 4, 1, 1,          GL_FLOAT,                                     GL_R32F,                                      GL_RED, },
    { 4, 1, 0,          GL_FLOAT,                                     GL_R32F,                                      GL_RED, },
    { 4, 2, 1,          GL_FLOAT,                                    GL_RG32F,                                       GL_RG, },
    { 4, 2, 0,          GL_FLOAT,                                    GL_RG32F,                                       GL_RG, },
    { 4, 3, 1,          GL_FLOAT,                                   GL_RGB32F,                                      GL_RGB, },
    { 4, 3, 0,          GL_FLOAT,                                   GL_RGB32F,                                      GL_RGB, },
    { 4, 4, 1,          GL_FLOAT,                                  GL_RGBA32F,                                     GL_RGBA, },
    { 4, 4, 0,          GL_FLOAT,                                  GL_RGBA32F,                                     GL_RGBA, },

    { 2, 1, 1, GL_UNSIGNED_SHORT,                        GL_DEPTH_COMPONENT16,                        GL_DEPTH_COMPONENT16, },
    { 4, 1, 1,   GL_UNSIGNED_INT,                         GL_DEPTH24_STENCIL8,                         GL_DEPTH24_STENCIL8, },
    { 4, 1, 1,          GL_FLOAT,                        GL_DEPTH_COMPONENT32,                       GL_DEPTH_COMPONENT32F, },
};

static const GLenum _FX_GL33_TEXTURE_TARGET[] = {
    GL_TEXTURE_2D,
    GL_TEXTURE_2D_ARRAY,
};

static const GLenum _FX_GL33_FILTER_TYPE[] = {
    GL_NEAREST,
    GL_LINEAR,
};

static const GLenum _FX_GL33_FILTER_MIPMAP_TYPE[] = {
    GL_NONE,
    GL_NEAREST_MIPMAP_NEAREST,
    GL_LINEAR_MIPMAP_NEAREST,
    GL_NEAREST_MIPMAP_LINEAR,
    GL_LINEAR_MIPMAP_LINEAR,
};

static const GLenum _FX_GL33_WRAP_TYPE[] = {
    GL_REPEAT,
    GL_MIRRORED_REPEAT,
    GL_CLAMP_TO_EDGE,
    GL_CLAMP_TO_BORDER,
    GL_MIRROR_CLAMP_TO_EDGE,
};

static const GLenum _FX_GL33_SHADER_STAGE[] = {
    GL_VERTEX_SHADER,
    GL_TESS_CONTROL_SHADER,
    GL_TESS_EVALUATION_SHADER,
    GL_GEOMETRY_SHADER,
    GL_FRAGMENT_SHADER,
};

//static const char* _fx_backend_glsl_type_name(GLenum type) {
//    switch(type) {
//        case GL_INT: return "int";
//        case GL_INT_VEC2: return "ivec2";
//        case GL_INT_VEC3: return "ivec3";
//        case GL_INT_VEC4: return "ivec4";
//        case GL_UNSIGNED_INT: return "uint";
//        case GL_UNSIGNED_INT_VEC2: return "uvec2";
//        case GL_UNSIGNED_INT_VEC3: return "uvec3";
//        case GL_UNSIGNED_INT_VEC4: return "uvec4";
//        case GL_FLOAT: return "float";
//        case GL_FLOAT_VEC2: return "vec2";
//        case GL_FLOAT_VEC3: return "vec3";
//        case GL_FLOAT_VEC4: return "vec4";
//        case GL_FLOAT_MAT4: return "mat4";
//        case GL_INT_SAMPLER_2D: return "sampler2D";
//        case GL_INT_SAMPLER_2D_ARRAY: return "sampler2DArray";
//        case GL_INT_SAMPLER_2D_MULTISAMPLE: return "sampler2D";
//        case GL_UNSIGNED_INT_SAMPLER_2D: return "isampler2D";
//        case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY: return "isampler2DArray";
//        case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE: return "isampler2D";
//        case GL_SAMPLER_2D: return "sampler2D";
//        case GL_SAMPLER_2D_ARRAY: return "sampler2DArray";
//        case GL_SAMPLER_2D_MULTISAMPLE: return "sampler2DMS";
//        case GL_INT_SAMPLER_3D: return "isampler3D";
//        case GL_UNSIGNED_INT_SAMPLER_3D: return "usampler3D";
//        case GL_SAMPLER_3D: return "sampler3D";
//        case GL_INT_IMAGE_1D: return "iimage1D";
//        case GL_UNSIGNED_INT_IMAGE_1D: return "uimage1D";
//        case GL_IMAGE_1D: return "image1D";
//        case GL_INT_IMAGE_2D: return "iimage2D";
//        case GL_INT_IMAGE_2D_ARRAY: return "iimage2DArray";
//        case GL_UNSIGNED_INT_IMAGE_2D: return "uimage2D";
//        case GL_IMAGE_2D: return "image2D";
//        case GL_INT_IMAGE_3D: return "iimage3D";
//        case GL_UNSIGNED_INT_IMAGE_3D: return "uimage3D";
//        case GL_IMAGE_3D: return "image3D";
//        case GL_INT_IMAGE_CUBE: return "iimageCube";
//        case GL_UNSIGNED_INT_IMAGE_CUBE: return "uimageCube";
//        case GL_IMAGE_CUBE: return "imageCube";
//        default: return "glsl unknown";
//    }
//}

typedef struct fxGl33Buffer {
    uintptr_t _;

    fxBufferId id;
    uint32_t name;
    uint32_t target;
    uint32_t usage;
    uint32_t size;
    void* ptr;
} fxGl33Buffer;

typedef struct fxGl33Texture {
    uintptr_t _;

    fxTextureId id;
    uint32_t name;
    uint32_t target;
    uint32_t kind;
    uint32_t format;

    fxTextureCfg cfg;
} fxGl33Texture;

typedef struct fxGl33Sampler {
    uintptr_t _;

    fxSamplerId id;
    uint32_t name;
    uint32_t flags;
} fxGl33Sampler;

typedef struct fxGl33Shader {
    uintptr_t _;

    fxShaderId id;
    uint32_t name;
} fxGl33Shader;

typedef struct fxGl33Program {
    uint32_t name;
    struct {
        uint32_t name;
    } stages[FX_SHADER_STAGE_COUNT];
} fxGl33Program;

typedef struct fxGl33Attachment {
    fxGl33Texture* texture;
} fxGl33Attachment;

typedef struct fxGl33Pass {
    uintptr_t _;

    fxPassId id;
    uint32_t name;
    fxGl33Attachment colours[FX_CONFIG_ATTACHMENT_MAX];
    fxGl33Attachment depth_stencil;
    uint32_t count;

    fxPassCfg cfg;
} fxGl33Pass;

typedef struct fxGl33VertexAttrib {
    uint32_t binding: 3;
    uint32_t location: 3;
    uint32_t normalised: 1;
    uint32_t count: 3;
    uint32_t kind: 16;
    uint32_t offset: 6;
} fxGl33VertexAttrib;

typedef struct fxGl33Layout {
    fxGl33VertexAttrib attribs[FX_ATTRIB_SEMANTIC_COUNT];
    uint32_t rate;
    uint32_t stride;
    uint32_t count;
} fxGl33Layout;

typedef struct fxGl33Pipeline {
    uintptr_t _;

    fxPipelineId id;
    fxPipelineBlendCfg blend;
    fxPipelineRasterCfg raster;
    fxPipelineDepthStencilCfg depth_stencil;
    fxGl33Layout layouts[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
    fxGl33Program program;
} fxGl33Pipeline;

struct fxBackendCtx {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);

    fxPoolAllocator pipeline_allocator;
    fxPoolAllocator buffer_allocator;
    fxPoolAllocator shader_allocator;
    fxPoolAllocator texture_allocator;
    fxPoolAllocator sampler_allocator;
    fxPoolAllocator pass_allocator;

    fxGl33Pipeline pipelines[FX_CONFIG_PIPELINE_MAX];
    fxGl33Buffer buffers[FX_CONFIG_BUFFER_MAX];
    fxGl33Shader shaders[FX_CONFIG_SHADER_MAX];
    fxGl33Texture textures[FX_CONFIG_TEXTURE_MAX];
    fxGl33Sampler samplers[FX_CONFIG_TEXTURE_MAX];
    fxGl33Pass passes[FX_CONFIG_PASS_MAX];

    fxGl33Pass default_pass;

    struct {
        uint32_t vertex_array;
        fxGl33Pipeline* pipeline;
        struct {
            uint32_t vertex[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
            uint32_t index;
            uint32_t index_type;
            uint32_t uniform[FX_CONFIG_UNIFORM_BUFFER_BINDING_MAX];
            uint32_t texture[FX_CONFIG_ATTACHMENT_MAX];
            uint32_t sampler[FX_CONFIG_ATTACHMENT_MAX];
            uint32_t pass;
        } binding;
        struct {
            bool enabled;
            float colour[4];
            GLenum factor_src_colour;
            GLenum factor_src_alpha;
            GLenum factor_dst_colour;
            GLenum factor_dst_alpha;
            GLenum op_colour;
            GLenum op_alpha;
            uint32_t colour_mask;
            GLenum op_logic;
            bool logic_enabled;
        } blend;
        struct {
            bool scissor;
            bool alpha_to_coverage;
            bool depth_clamp;
            bool discard;
            GLenum fill;
            GLenum cull;
            GLenum winding;
            float line_width;
            float point_size;
            uint8_t samples;
        } raster;
        struct {
            bool depth_test;
            bool depth_write;
            GLenum depth_op;
            bool depth_bounds_test;
            float depth_min;
            float depth_max;
            bool stencil_test;
            fxStencilOpCfg front;
            fxStencilOpCfg back;
        } depth_stencil;
    } cache;

#define _FX_GL33_FN_DECL(type, ret, name, ...) ret (*name)(__VA_ARGS__);
    _FX_GL33_FN_MAP(_FX_GL33_FN_DECL)
#undef _FX_GL33_FN_DECL
};

#define FX_GL(ctx, fn) (ctx)->fn; _FX_GL33_LINE = __LINE__

static void _fx_backend_destroy(fxBackendCtx* ctx) {
    FX_ASSERT(ctx != NULL);
    FX_GL(ctx, glDeleteVertexArrays(1, &ctx->cache.vertex_array));
    FX_GL(ctx, glBindVertexArray(0));
}

static fxGl33Program _fx_backend_program(fxBackendCtx* ctx, fxPipelineShaderCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    FX_ASSERT(cfg->vertex != FX_ID_INVALID);
    FX_ASSERT(cfg->fragment != FX_ID_INVALID);
    FX_ASSERT(cfg->tessellation_control == FX_ID_INVALID);
    FX_ASSERT(cfg->tessellation_evaluation == FX_ID_INVALID);
    fxGl33Program res = {};

    res.name = FX_GL(ctx, glCreateProgram());

    res.stages[FX_SHADER_STAGE_VERTEX].name = FX_PTR_FROM_ID(ctx->shaders, cfg->vertex)->name;
    FX_GL(ctx, glAttachShader(res.name, res.stages[FX_SHADER_STAGE_VERTEX].name));

    if(cfg->geometry) {
        res.stages[FX_SHADER_STAGE_GEOMETRY].name = FX_PTR_FROM_ID(ctx->shaders, cfg->geometry)->name;
        FX_GL(ctx, glAttachShader(res.name, res.stages[FX_SHADER_STAGE_GEOMETRY].name));
    }

    res.stages[FX_SHADER_STAGE_FRAGMENT].name = FX_PTR_FROM_ID(ctx->shaders, cfg->fragment)->name;
    FX_GL(ctx, glAttachShader(res.name, res.stages[FX_SHADER_STAGE_FRAGMENT].name));

    FX_GL(ctx, glLinkProgram(res.name));

    GLint log_size = 0;
    FX_GL(ctx, glGetProgramiv(res.name, GL_INFO_LOG_LENGTH, &log_size));
    if(log_size) {
        char log[4096];
        FX_GL(ctx, glGetProgramInfoLog(res.name, sizeof(log), &log_size, log));
        FX_GL(ctx, glDeleteProgram(res.name));
        log[log_size] = '\0';
        ctx->log(ctx->usr, "%s\n", log);
        FX_ASSERT(!"Failed to link program");
    }
    return res;
}

static fxPipelineId _fx_backend_pipeline(fxBackendCtx* ctx, fxPipelineCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl33Pipeline* pipeline = (fxGl33Pipeline*) _fx_pool_allocator_alloc(&ctx->pipeline_allocator);
    FX_ASSERT(pipeline != NULL);

    fxPipelineId id = FX_INDEX_FROM_PTR(pipeline, ctx->pipelines);
    pipeline->id = id;
    pipeline->program = _fx_backend_program(ctx, &cfg->shader);
    FX_MEMCOPY(&pipeline->blend, &cfg->blend, sizeof(fxPipelineBlendCfg));
    FX_MEMCOPY(&pipeline->raster, &cfg->raster, sizeof(fxPipelineRasterCfg));
    FX_MEMCOPY(&pipeline->depth_stencil, &cfg->depth_stencil, sizeof(fxPipelineDepthStencilCfg));
    for(uint32_t i = 0; i < FX_CONFIG_VERTEX_BUFFER_BINDING_MAX; i++) {
        fxPipelineLayoutCfg* layout = &cfg->layouts[i];
        fxGl33Layout* backend_layout = &pipeline->layouts[i];
        backend_layout->stride = (uint32_t) layout->stride;
        backend_layout->rate = (uint32_t) layout->rate;
        for(uint32_t j = 0; j < FX_ATTRIB_SEMANTIC_COUNT; j++) {
            fxVertexAttrib attrib = layout->attribs[j];
            if(attrib.format == FX_FORMAT_INVALID) {
                break;
            }
            if(layout->stride == 0) {
                backend_layout->stride += _FX_GL33_FORMAT[attrib.format].size * _FX_GL33_FORMAT[attrib.format].count;
            }
            backend_layout->attribs[j].binding = attrib.binding;
            backend_layout->attribs[j].location = attrib.location;
            backend_layout->attribs[j].normalised = _FX_GL33_FORMAT[attrib.format].normalised;
            backend_layout->attribs[j].count = _FX_GL33_FORMAT[attrib.format].count;
            backend_layout->attribs[j].kind = _FX_GL33_FORMAT[attrib.format].kind;
            backend_layout->attribs[j].offset = attrib.offset;
            backend_layout->count++;
        }
    }
    return FX_INDEX_FROM_PTR(pipeline, ctx->pipelines);
}

static void _fx_backend_pipeline_destroy(fxBackendCtx* ctx, fxPipelineId pipeline) {
    FX_ASSERT(ctx != NULL);
    fxGl33Pipeline* pipeline_ptr = FX_PTR_FROM_ID(ctx->pipelines, pipeline);
    _fx_pool_allocator_dealloc(&ctx->pipeline_allocator, pipeline_ptr);
}

static void _fx_backend_buffer_create(fxBackendCtx* ctx, uint32_t* buffers, uint32_t count, void* data, uint32_t size, GLenum target, uint32_t usage) {
    FX_ASSERT(ctx != NULL);
    FX_GL(ctx, glGenBuffers(count, buffers));
    for(uint32_t i = 0; i < count; i++) {
        FX_GL(ctx, glBindBuffer(target, buffers[i]));
        FX_GL(ctx, glBufferData(target, size, data, usage));
    }
    FX_GL(ctx, glBindBuffer(target, 0));
}

static fxBufferId _fx_backend_buffer(fxBackendCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size) {
    FX_ASSERT(ctx != NULL);
    fxGl33Buffer* buffer = (fxGl33Buffer*) _fx_pool_allocator_alloc(&ctx->buffer_allocator);
    FX_ASSERT(buffer != NULL);
    FX_ASSERT(size <= cfg->size);

    buffer->size = cfg->size;
    buffer->usage = (cfg->flags & FX_BUFFER_DYNAMIC) ? GL_DYNAMIC_DRAW: GL_STATIC_DRAW;
    buffer->target = _FX_GL33_BUFFER_TARGET[cfg->kind];
    _fx_backend_buffer_create(ctx, &buffer->name, 1, data, buffer->size, buffer->target, buffer->usage);
    return FX_INDEX_FROM_PTR(buffer, ctx->buffers);
}

static void _fx_backend_buffer_destroy(fxBackendCtx* ctx, fxBufferId buffer) {
    FX_ASSERT(ctx != NULL);
    fxGl33Buffer* buffer_ptr = FX_PTR_FROM_ID(ctx->buffers, buffer);
    FX_GL(ctx, glDeleteBuffers(1, &buffer_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->buffer_allocator, buffer_ptr);
}

static void _fx_backend_buffer_update(fxBackendCtx* ctx, fxBufferId buffer, void* data, uint32_t size, uint32_t offset) {
    FX_ASSERT(ctx != NULL);
    fxGl33Buffer* buffer_ptr = FX_PTR_FROM_ID(ctx->buffers, buffer);
    FX_ASSERT(buffer_ptr->usage == GL_DYNAMIC_DRAW);
    FX_ASSERT(offset + size <= buffer_ptr->size);
    FX_GL(ctx, glBindBuffer(buffer_ptr->target, buffer_ptr->name));
    FX_GL(ctx, glBufferSubData(buffer_ptr->target, offset, size, data));
}

static fxTextureId _fx_backend_texture(fxBackendCtx* ctx, fxTextureCfg* cfg, void** datas, uint32_t* sizes) {
    FX_ASSERT(ctx != NULL);
    fxGl33Texture* texture = (fxGl33Texture*) _fx_pool_allocator_alloc(&ctx->texture_allocator);
    FX_ASSERT(texture != NULL);
    FX_ASSERT((cfg->flags & ~FX_TEXTURE_MULTISAMPLE) == 0);

    fxTextureId id = FX_INDEX_FROM_PTR(texture, ctx->textures);
    texture->id = id;
    bool compressed = cfg->format >= FX_FORMAT_BC1 && cfg->format <= FX_FORMAT_ETC2A1;
    uint32_t width = cfg->width;
    uint32_t height = cfg->height;
    uint32_t depth = cfg->depth;
    uint32_t mipmaps = FX_MAX(1, cfg->mipmaps);
    GLenum internal_format = _FX_GL33_FORMAT[cfg->format].internal_format;
    texture->format = _FX_GL33_FORMAT[cfg->format].format;
    texture->kind = _FX_GL33_FORMAT[cfg->format].kind;
    texture->target = _FX_GL33_TEXTURE_TARGET[cfg->kind];

    FX_MEMCOPY(&texture->cfg, cfg, sizeof(fxTextureCfg));

    FX_GL(ctx, glGenTextures(1, &texture->name));
    FX_GL(ctx, glActiveTexture(GL_TEXTURE0));
    FX_GL(ctx, glBindTexture(texture->target, texture->name));

    if(texture->target == GL_TEXTURE_2D) {
        if(cfg->flags & FX_TEXTURE_MULTISAMPLE) {
            FX_GL(ctx, glTexImage2DMultisample(texture->name, cfg->samples, internal_format, width, height, GL_FALSE));
        } else {
            FX_GL(ctx, glTexImage2D(texture->target, 0, internal_format, width, height, 0, texture->format, texture->kind, NULL));
        }
    } else if(texture->target == GL_TEXTURE_2D_ARRAY) {
        if(cfg->flags & FX_TEXTURE_MULTISAMPLE) {
            FX_GL(ctx, glTexImage3DMultisample(texture->name, cfg->samples, internal_format, width, height, depth, GL_FALSE));
        } else {
            FX_GL(ctx, glTexImage3D(texture->target, 0, internal_format, width, height, depth, 0, texture->format, texture->kind, NULL));
        }
    }

    for(uint32_t mipmap = 0; mipmap < mipmaps; mipmap++) {
        if(texture->target == GL_TEXTURE_2D) {
            if(datas[mipmap]) {
                if(compressed) {
                    FX_GL(ctx, glCompressedTexSubImage2D(texture->target, mipmap, 0, 0, width, height, texture->format, sizes[mipmap], datas[mipmap]));
                } else {
                    FX_GL(ctx, glTexSubImage2D(texture->target, mipmap, 0, 0, width, height, texture->format, texture->kind, datas[mipmap]));
                }
            }
        } else if(texture->target == GL_TEXTURE_2D_ARRAY) {
            if(datas[mipmap]) {
                if(compressed) {
                    FX_GL(ctx, glCompressedTexSubImage3D(texture->target, mipmap, 0, 0, 0, width, height, depth, texture->format, sizes[mipmap], datas[mipmap]));
                } else {
                    FX_GL(ctx, glTexSubImage3D(texture->target, mipmap, 0, 0, 0, width, height, depth, texture->format, texture->kind, datas[mipmap]));
                }
            }
        }
        width >>= 1;
        height >>= 1;
        width = FX_MAX(1, width);
        height = FX_MAX(1, height);
    }

    if(cfg->swizzle_r != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTexParameteri(texture->target, GL_TEXTURE_SWIZZLE_R, _FX_GL33_COMPONENT_SWIZZLE[cfg->swizzle_r]));
    }
    if(cfg->swizzle_g != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTexParameteri(texture->target, GL_TEXTURE_SWIZZLE_G, _FX_GL33_COMPONENT_SWIZZLE[cfg->swizzle_g]));
    }
    if(cfg->swizzle_b != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTexParameteri(texture->target, GL_TEXTURE_SWIZZLE_B, _FX_GL33_COMPONENT_SWIZZLE[cfg->swizzle_b]));
    }
    if(cfg->swizzle_a != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTexParameteri(texture->target, GL_TEXTURE_SWIZZLE_A, _FX_GL33_COMPONENT_SWIZZLE[cfg->swizzle_a]));
    }
    return FX_INDEX_FROM_PTR(texture, ctx->textures);
}

static void _fx_backend_texture_destroy(fxBackendCtx* ctx, fxTextureId texture) {
    FX_ASSERT(ctx != NULL);
    fxGl33Texture* texture_ptr = FX_PTR_FROM_ID(ctx->textures, texture);
    FX_GL(ctx, glDeleteTextures(1, &texture_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->texture_allocator, texture_ptr);
}

static void _fx_backend_texture_update(fxBackendCtx* ctx, fxTextureId texture, void* data, fxTextureRegion* region) {
    FX_ASSERT(ctx != NULL);
    fxGl33Texture* texture_ptr = FX_PTR_FROM_ID(ctx->textures, texture);
    FX_GL(ctx, glTexSubImage2D(
        texture_ptr->name, 0, region->src_offset.x, region->src_offset.y,
        region->width, region->height, texture_ptr->format, texture_ptr->kind, data));
}

static fxSamplerId _fx_backend_sampler(fxBackendCtx* ctx, fxSamplerCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl33Sampler* sampler = (fxGl33Sampler*) _fx_pool_allocator_alloc(&ctx->sampler_allocator);
    FX_ASSERT(sampler != NULL);

    fxSamplerId id = FX_INDEX_FROM_PTR(sampler, ctx->samplers);
    sampler->id = id;
    sampler->flags = cfg->flags;
    FX_GL(ctx, glGenSamplers(1, &sampler->name));
    if(cfg->filter_mipmap != FX_FILTER_MIPMAP_MODE_NONE) {
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MIN_FILTER, _FX_GL33_FILTER_TYPE[cfg->filter_min]));
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MAG_FILTER, _FX_GL33_FILTER_MIPMAP_TYPE[cfg->filter_mipmap]));
    } else {
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MIN_FILTER, _FX_GL33_FILTER_TYPE[cfg->filter_min]));
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MAG_FILTER, _FX_GL33_FILTER_TYPE[cfg->filter_mag]));
    }
    FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_WRAP_S, _FX_GL33_WRAP_TYPE[cfg->wrap_u]));
    FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_WRAP_T, _FX_GL33_WRAP_TYPE[cfg->wrap_v]));
    FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_WRAP_R, _FX_GL33_WRAP_TYPE[cfg->wrap_w]));
    return FX_INDEX_FROM_PTR(sampler, ctx->samplers);
}

static void _fx_backend_sampler_destroy(fxBackendCtx* ctx, fxSamplerId sampler) {
    FX_ASSERT(ctx != NULL);
    fxGl33Sampler* sampler_ptr = FX_PTR_FROM_ID(ctx->samplers, sampler);
    FX_GL(ctx, glDeleteSamplers(1, &sampler_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->sampler_allocator, sampler_ptr);
}

static fxPassId _fx_backend_pass(fxBackendCtx* ctx, fxPassCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    (void) (cfg);
    fxGl33Pass* pass = (fxGl33Pass*) _fx_pool_allocator_alloc(&ctx->pass_allocator);
    FX_ASSERT(pass != NULL);

    fxPassId id = FX_INDEX_FROM_PTR(pass, ctx->passes);
    pass->id = id;
    pass->count = 0;
    FX_GL(ctx, glGenFramebuffers(1, &pass->name));
    FX_GL(ctx, glBindFramebuffer(GL_FRAMEBUFFER, pass->name));
    for(uint64_t i = 0; i < FX_CONFIG_ATTACHMENT_MAX; i++) {
        if(cfg->colours[i].texture == FX_ID_INVALID) { break; }
        fxGl33Texture* colour = &ctx->textures[cfg->colours[i].texture];
        FX_GL(ctx, glFramebufferTexture(GL_FRAMEBUFFER, (GLenum) (GL_COLOR_ATTACHMENT0 + i), colour->name, 0));
        pass->count++;
    }
    if(cfg->depth_stencil.texture != FX_ID_INVALID) {
        fxGl33Texture* depth_stencil = &ctx->textures[cfg->depth_stencil.texture];
        GLenum depth_attachment = GL_DEPTH_STENCIL_ATTACHMENT;
        FX_GL(ctx, glFramebufferTexture(GL_FRAMEBUFFER, depth_attachment, depth_stencil->name, 0));
    }
    if(ctx->glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        FX_GL(ctx, glDeleteFramebuffers(1, &pass->name));
        _fx_pool_allocator_dealloc(&ctx->pass_allocator, pass);
        return FX_ID_INVALID;
    }
    FX_MEMCOPY(&pass->cfg, cfg, sizeof(fxPassCfg));
    return FX_INDEX_FROM_PTR(pass, ctx->passes);
}

static void _fx_backend_pass_destroy(fxBackendCtx* ctx, fxPassId pass) {
    FX_ASSERT(ctx != NULL);
    fxGl33Pass* pass_ptr = FX_PTR_FROM_ID(ctx->passes, pass);
    FX_GL(ctx, glDeleteFramebuffers(1, &pass_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->pass_allocator, pass_ptr);
}

static fxShaderId _fx_backend_shader(fxBackendCtx* ctx, fxShaderCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl33Shader* shader = (fxGl33Shader*) _fx_pool_allocator_alloc(&ctx->shader_allocator);
    FX_ASSERT(shader != NULL);

    fxShaderId id = FX_INDEX_FROM_PTR(shader, ctx->shaders);
    shader->id = id;
#if 0
    uint32_t magic = *(uint32_t*) cfg->source;
    if(magic == 0x07230203) {
        shader = FX_GL(ctx, glCreateProgram);
        GLuint shader = FX_GL(ctx, glCreateShader, stage);
        FX_GL(ctx, glShaderBinary, 1, &shader, GL_SHADER_BINARY_FORMAT_SPIR_V, cfg->source, cfg->size);
        FX_GL(ctx, glSpecializeShaderARB, shader, !cfg->entry ? "main": cfg->entry, 0, NULL, NULL);
        shader = FX_GL(ctx, glCreateProgram);
        FX_GL(ctx, glProgramParameteri, shader, GL_PROGRAM_SEPARABLE, GL_TRUE);
        FX_GL(ctx, glAttachShader, shader, shader);
        FX_GL(ctx, glLinkProgram, shader);
        FX_GL(ctx, glDetachShader, shader, shader);
        FX_GL(ctx, glDeleteShader, shader);
    } else {
#endif
        const char* sources[] = { cfg->source };
        shader->name = FX_GL(ctx, glCreateShader(_FX_GL33_SHADER_STAGE[cfg->stage]));
        FX_GL(ctx, glShaderSource(shader->name, FX_COUNT_OF(sources), sources, NULL));
        FX_GL(ctx, glCompileShader(shader->name));
#if 0
    }
#endif

    GLint log_size = 0;
    FX_GL(ctx, glGetShaderiv(shader->name, GL_INFO_LOG_LENGTH, &log_size));
    GLint status = 0;
    FX_GL(ctx, glGetShaderiv(shader->name, GL_COMPILE_STATUS, &status));
    if(!status) {
        char log[4096];
        FX_GL(ctx, glGetShaderInfoLog(shader->name, sizeof(log), &log_size, log));
        FX_GL(ctx, glDeleteShader(shader->name));
        log[log_size] = '\0';
        ctx->log(ctx->usr, "%s\n", log);
        FX_ASSERT(!"Failed to compile shader");
        return 0;
    }

    //GLint input_count = 0, uniform_count = 0, output_count = 0;
    //GLint input_name_max = 0, uniform_name_max = 0, output_name_max = 0;
    //FX_GL(ctx, glGetProgramInterfaceiv(shader->name, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &input_count));
    //FX_GL(ctx, glGetProgramInterfaceiv(shader->name, GL_UNIFORM, GL_ACTIVE_RESOURCES, &uniform_count));
    //FX_GL(ctx, glGetProgramInterfaceiv(shader->name, GL_PROGRAM_OUTPUT, GL_ACTIVE_RESOURCES, &output_count));
    //FX_GL(ctx, glGetProgramInterfaceiv(shader->name, GL_PROGRAM_INPUT, GL_MAX_NAME_LENGTH, &input_name_max));
    //FX_GL(ctx, glGetProgramInterfaceiv(shader->name, GL_UNIFORM, GL_MAX_NAME_LENGTH, &uniform_name_max));
    //FX_GL(ctx, glGetProgramInterfaceiv(shader->name, GL_PROGRAM_OUTPUT, GL_MAX_NAME_LENGTH, &output_name_max));

    //uint32_t name_max = FX_MAX(input_name_max, FX_MAX(uniform_name_max, output_name_max));
    //char* name = (char*) alloca(name_max + 1);
    //ctx->log(ctx->usr, "Stage %d\n", shader->name);
    //ctx->log(ctx->usr, "\tInputs (%d):\n", input_count);
    //for(int32_t i = 0; i < input_count; i++) {
    //    GLint count = 0;
    //    GLenum kind = 0;
    //    FX_GL(ctx, glGetProgramResourceName(shader->name, GL_PROGRAM_INPUT, i, name_max + 1, &count, name));
    //    GLenum props[] = {
    //        GL_TYPE,
    //    };
    //    FX_GL(ctx, glGetProgramResourceiv(shader->name, GL_PROGRAM_INPUT, i, FX_COUNT_OF(props), props, 1, NULL, (GLint*) &kind));
    //    ctx->log(ctx->usr, "\t\tlayout(location = %d) in %s %s\n", ctx->glGetAttribLocation(shader->name, name), _fx_backend_glsl_type_name(kind), name);
    //}

    //typedef struct {
    //    GLenum kind;
    //    GLint location;
    //    GLint count;
    //} fxGl33UniformInfo;

    //ctx->log(ctx->usr, "\tUniforms (%d):\n", uniform_count);
    //for(int32_t i = 0; i < uniform_count; i++) {
    //    GLint count = 0;
    //    GLenum kind = 0;
    //    fxGl33UniformInfo info;
    //    GLenum props[] = {
    //        GL_TYPE,
    //        GL_LOCATION,
    //        GL_ARRAY_SIZE,
    //    };
    //    FX_GL(ctx, glGetProgramResourceName(shader->name, GL_UNIFORM, i, name_max + 1, NULL, name));
    //    FX_GL(ctx, glGetProgramResourceiv(shader->name, GL_UNIFORM, i, FX_COUNT_OF(props), props, 1, NULL, (GLint*) &info));
    //    count = info.count;
    //    kind = info.kind;
    //    ctx->log(ctx->usr,
    //        "\t\tlayout(location = %d) uniform %s %s\n", ctx->glGetUniformLocation(shader->name, name), _fx_backend_glsl_type_name(kind), name);
    //}

    //ctx->log(ctx->usr, "\tOutputs (%d):\n", output_count);
    //for(int32_t i = 0; i < output_count; i++) {
    //    fxGl33UniformInfo info;
    //    GLenum props[] = {
    //        GL_TYPE,
    //        GL_LOCATION,
    //        GL_ARRAY_SIZE,
    //    };
    //    FX_GL(ctx, glGetProgramResourceName(shader->name, GL_PROGRAM_OUTPUT, i, name_max + 1, NULL, name));
    //    FX_GL(ctx, glGetProgramResourceiv( shader->name, GL_PROGRAM_OUTPUT, i, FX_COUNT_OF(props), props, 1, NULL, (GLint*) &info));
    //    ctx->log(ctx->usr, "\t\tlayout(location = %d) out %s %s\n", info.location, _fx_backend_glsl_type_name(info.kind), name);
    //}

    return FX_INDEX_FROM_PTR(shader, ctx->shaders);
}

static void _fx_backend_shader_destroy(fxBackendCtx* ctx, fxShaderId shader) {
    FX_ASSERT(ctx != NULL);
    fxGl33Shader* shader_ptr = FX_PTR_FROM_ID(ctx->shaders, shader);
    FX_GL(ctx, glDeleteShader(shader_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->shader_allocator, shader_ptr);
}

static void _fx_backend_submit(fxBackendCtx* ctx, fxCmdBuffer* cmd_buffer) {
    FX_ASSERT(ctx != NULL);
    uint8_t* cmds = cmd_buffer->cmds;
    do {
        fxCmdHeader* header = (fxCmdHeader*) cmds;
        void* raw_cmd = (void*) (header + 1);
        switch(header->kind) {
            case FX_CMD_KIND_BEGIN_PASS: {
                fxCmdBeginPass* cmd = (fxCmdBeginPass*) raw_cmd;
                fxGl33Pass* pass = (fxGl33Pass*) (cmd->pass != FX_ID_INVALID ? FX_PTR_FROM_ID(ctx->passes, cmd->pass): &ctx->default_pass);
                fxGl33Texture* texture = pass->colours[0].texture;
                int32_t width = texture ? texture->cfg.width: cmd->width;
                int32_t height = texture ? texture->cfg.height: cmd->height;
                FX_GL(ctx, glBindFramebuffer(GL_FRAMEBUFFER, pass->name));
                FX_GL(ctx, glViewport(0.0f, 0.0f, width, height));
                FX_GL(ctx, glScissor(0.0f, 0.0f, width, height));
                fxPassOp* ops = &cmd->ops;
                for(uint32_t i = 0; i < pass->count; i++) {
                    if(ops->colours[i].kind == FX_PASS_OP_KIND_CLEAR) {
                        float colour[4];
                        colour[0] = ((ops->colours[i].clear >> 24) & 0xFF) * (1.0f / 255.0f);
                        colour[1] = ((ops->colours[i].clear >> 16) & 0xFF) * (1.0f / 255.0f);
                        colour[2] = ((ops->colours[i].clear >> 8) & 0xFF) * (1.0f / 255.0f);
                        colour[3] = ((ops->colours[i].clear >> 0) & 0xFF) * (1.0f / 255.0f);
                        FX_GL(ctx, glClearBufferfv(GL_COLOR, i, colour));
                    }
                }
                if(ops->depth.kind == FX_PASS_OP_KIND_CLEAR) {
                    FX_GL(ctx, glClearBufferfv(GL_DEPTH, 0, &ops->depth.clear));
                }
                if(ops->stencil.kind == FX_PASS_OP_KIND_CLEAR) {
                    FX_GL(ctx, glClearBufferiv(GL_STENCIL, 0, &ops->stencil.clear));
                }
            } break;
            case FX_CMD_KIND_END_PASS: {
            } break;
            case FX_CMD_KIND_VIEWPORT: {
                fxCmdViewport* cmd = (fxCmdViewport*) raw_cmd;
                FX_GL(ctx, glViewport(cmd->x, cmd->y, cmd->width, cmd->height));
            } break;
            case FX_CMD_KIND_SCISSOR: {
                fxCmdScissor* cmd = (fxCmdScissor*) raw_cmd;
                FX_GL(ctx, glScissor(cmd->x, cmd->y, cmd->width, cmd->height));
            } break;
            case FX_CMD_KIND_BIND_PIPELINE: {
                fxCmdBindPipeline* cmd = (fxCmdBindPipeline*) raw_cmd;
                fxGl33Pipeline* pipeline = FX_PTR_FROM_ID(ctx->pipelines, cmd->pipeline);
                FX_ASSERT(cmd->pipeline == pipeline->id);
                if(ctx->cache.pipeline != pipeline) {
                    ctx->cache.pipeline = pipeline;

                    bool depth_test = pipeline->depth_stencil.flags & FX_PIPELINE_DEPTH_STENCIL_DEPTH_TEST;
                    if(ctx->cache.depth_stencil.depth_test != depth_test) {
                        ctx->cache.depth_stencil.depth_test = depth_test;
                        if(depth_test) {
                            FX_GL(ctx, glEnable(GL_DEPTH_TEST));
                        } else {
                            FX_GL(ctx, glDisable(GL_DEPTH_TEST));
                        }
                    }

                    GLenum depth_op = _FX_GL33_COMPARE_FUNC[pipeline->depth_stencil.depth_op];
                    if(ctx->cache.depth_stencil.depth_op != depth_op) {
                        ctx->cache.depth_stencil.depth_op = depth_op;
                        FX_GL(ctx, glDepthFunc(depth_op));
                    }

                    bool depth_write = pipeline->depth_stencil.flags & FX_PIPELINE_DEPTH_STENCIL_DEPTH_WRITE;
                    if(ctx->cache.depth_stencil.depth_write != depth_write) {
                        ctx->cache.depth_stencil.depth_write = depth_write;
                        FX_GL(ctx, glDepthMask(depth_write));
                    }

                    bool stencil_test = pipeline->depth_stencil.flags & FX_PIPELINE_DEPTH_STENCIL_STENCIL_TEST;
                    if(ctx->cache.depth_stencil.stencil_test != stencil_test) {
                        ctx->cache.depth_stencil.stencil_test = stencil_test;
                        if(stencil_test) {
                            FX_GL(ctx, glEnable(GL_STENCIL_TEST));
                        } else {
                            FX_GL(ctx, glDisable(GL_STENCIL_TEST));
                        }
                    }

                    if(ctx->cache.depth_stencil.front.op_cmp != pipeline->depth_stencil.front.op_cmp ||
                       ctx->cache.depth_stencil.front.mask_cmp != pipeline->depth_stencil.front.mask_cmp ||
                       ctx->cache.depth_stencil.front.ref != pipeline->depth_stencil.front.ref) {
                        ctx->cache.depth_stencil.front.op_cmp = pipeline->depth_stencil.front.op_cmp;
                        ctx->cache.depth_stencil.front.mask_cmp = pipeline->depth_stencil.front.mask_cmp;
                        ctx->cache.depth_stencil.front.ref = pipeline->depth_stencil.front.ref;
                        FX_GL(ctx, glStencilFuncSeparate(
                            GL_FRONT, _FX_GL33_COMPARE_FUNC[pipeline->depth_stencil.front.op_cmp],
                            pipeline->depth_stencil.front.ref, pipeline->depth_stencil.front.mask_cmp));
                    }

                    if(ctx->cache.depth_stencil.front.op_cmp != pipeline->depth_stencil.back.op_cmp ||
                       ctx->cache.depth_stencil.back.mask_cmp != pipeline->depth_stencil.back.mask_cmp ||
                       ctx->cache.depth_stencil.back.ref != pipeline->depth_stencil.back.ref) {
                        ctx->cache.depth_stencil.back.op_cmp = pipeline->depth_stencil.back.op_cmp;
                        ctx->cache.depth_stencil.back.mask_cmp = pipeline->depth_stencil.back.mask_cmp;
                        ctx->cache.depth_stencil.back.ref = pipeline->depth_stencil.back.ref;
                        FX_GL(ctx, glStencilFuncSeparate(
                            GL_BACK, _FX_GL33_COMPARE_FUNC[pipeline->depth_stencil.back.op_cmp],
                            pipeline->depth_stencil.back.ref, pipeline->depth_stencil.back.mask_cmp));
                    }

                    if(ctx->cache.depth_stencil.front.op_fail != pipeline->depth_stencil.front.op_fail ||
                       ctx->cache.depth_stencil.front.op_pass != pipeline->depth_stencil.front.op_pass ||
                       ctx->cache.depth_stencil.front.op_depth_fail != pipeline->depth_stencil.front.op_depth_fail) {
                        ctx->cache.depth_stencil.front.op_fail = pipeline->depth_stencil.front.op_fail;
                        ctx->cache.depth_stencil.front.op_pass = pipeline->depth_stencil.front.op_pass;
                        ctx->cache.depth_stencil.front.op_depth_fail = pipeline->depth_stencil.front.op_depth_fail;
                        FX_GL(ctx, glStencilOpSeparate(
                            GL_FRONT, _FX_GL33_STENCIL_OP[pipeline->depth_stencil.front.op_fail],
                            _FX_GL33_STENCIL_OP[pipeline->depth_stencil.front.op_depth_fail],
                            _FX_GL33_STENCIL_OP[pipeline->depth_stencil.front.op_pass]));
                    }

                    if(ctx->cache.depth_stencil.back.op_fail != pipeline->depth_stencil.back.op_fail ||
                       ctx->cache.depth_stencil.back.op_pass != pipeline->depth_stencil.back.op_pass ||
                       ctx->cache.depth_stencil.back.op_depth_fail != pipeline->depth_stencil.back.op_depth_fail) {
                        ctx->cache.depth_stencil.back.op_fail = pipeline->depth_stencil.back.op_fail;
                        ctx->cache.depth_stencil.back.op_pass = pipeline->depth_stencil.back.op_pass;
                        ctx->cache.depth_stencil.back.op_depth_fail = pipeline->depth_stencil.back.op_depth_fail;
                        FX_GL(ctx, glStencilOpSeparate(
                            GL_BACK, _FX_GL33_STENCIL_OP[pipeline->depth_stencil.back.op_fail],
                            _FX_GL33_STENCIL_OP[pipeline->depth_stencil.back.op_depth_fail],
                            _FX_GL33_STENCIL_OP[pipeline->depth_stencil.back.op_pass]));
                    }

                    bool blend = pipeline->blend.flags & FX_PIPELINE_BLEND;
                    if(ctx->cache.blend.enabled != blend) {
                        ctx->cache.blend.enabled = blend;
                        if(blend) {
                            FX_GL(ctx, glEnable(GL_BLEND));
                        } else {
                            FX_GL(ctx, glDisable(GL_BLEND));
                        }
                    }

                    if(ctx->cache.blend.factor_src_colour != pipeline->blend.factor_src_colour ||
                       ctx->cache.blend.factor_dst_colour != pipeline->blend.factor_dst_colour ||
                       ctx->cache.blend.factor_src_alpha != pipeline->blend.factor_src_alpha ||
                       ctx->cache.blend.factor_dst_alpha != pipeline->blend.factor_dst_alpha) {
                        FX_GL(ctx, glBlendFuncSeparate(
                            _FX_GL33_BLEND_FACTOR[pipeline->blend.factor_src_colour],
                            _FX_GL33_BLEND_FACTOR[pipeline->blend.factor_dst_colour],
                            _FX_GL33_BLEND_FACTOR[pipeline->blend.factor_src_alpha],
                            _FX_GL33_BLEND_FACTOR[pipeline->blend.factor_dst_alpha]));
                    }

                    if(ctx->cache.blend.op_colour != pipeline->blend.op_colour ||
                       ctx->cache.blend.op_colour != pipeline->blend.op_colour) {
                        FX_GL(ctx, glBlendEquationSeparate(
                                    _FX_GL33_BLEND_OP[pipeline->blend.op_colour],
                                    _FX_GL33_BLEND_OP[pipeline->blend.op_alpha]));
                    }

                    if(ctx->cache.blend.colour_mask != pipeline->blend.colour_mask) {
                        ctx->cache.blend.colour_mask = pipeline->blend.colour_mask;
                        FX_GL(ctx, glColorMask(
                            !(pipeline->blend.colour_mask & FX_COLOUR_MASK_R),
                            !(pipeline->blend.colour_mask & FX_COLOUR_MASK_G),
                            !(pipeline->blend.colour_mask & FX_COLOUR_MASK_B),
                            !(pipeline->blend.colour_mask & FX_COLOUR_MASK_A)));
                    }

                    if(ctx->cache.blend.colour[0] != pipeline->blend.colour[0] ||
                       ctx->cache.blend.colour[1] != pipeline->blend.colour[1] ||
                       ctx->cache.blend.colour[2] != pipeline->blend.colour[2] ||
                       ctx->cache.blend.colour[3] != pipeline->blend.colour[3]) {
                        ctx->cache.blend.colour[0] = pipeline->blend.colour[0];
                        ctx->cache.blend.colour[1] = pipeline->blend.colour[1];
                        ctx->cache.blend.colour[2] = pipeline->blend.colour[2];
                        ctx->cache.blend.colour[3] = pipeline->blend.colour[3];
                        FX_GL(ctx, glBlendColor(
                            pipeline->blend.colour[0],
                            pipeline->blend.colour[1],
                            pipeline->blend.colour[2],
                            pipeline->blend.colour[3]));
                    }

                    bool logic = pipeline->blend.flags & FX_PIPELINE_BLEND_LOGIC;
                    GLenum op_logic = _FX_GL33_LOGIC_OP[pipeline->blend.op_logic];
                    if(ctx->cache.blend.logic_enabled != logic) {
                        ctx->cache.blend.logic_enabled = logic;
                        ctx->cache.blend.op_logic = op_logic;
                        if(logic) {
                            FX_GL(ctx, glEnable(GL_COLOR_LOGIC_OP));
                            FX_GL(ctx, glLogicOp(op_logic));
                        } else {
                            FX_GL(ctx, glDisable(GL_COLOR_LOGIC_OP));
                        }
                    }

                    GLenum cull = _FX_GL33_CULL[pipeline->raster.cull];
                    if(ctx->cache.raster.cull != cull) {
                        ctx->cache.raster.cull = cull;
                        if(cull) {
                            FX_GL(ctx, glEnable(GL_CULL_FACE));
                            FX_GL(ctx, glCullFace(cull));
                        } else {
                            FX_GL(ctx, glDisable(GL_CULL_FACE));
                        }
                    }

                    GLenum winding = _FX_GL33_FRONT_FACE[pipeline->raster.winding];
                    if(ctx->cache.raster.winding != winding) {
                        ctx->cache.raster.winding = winding;
                        FX_GL(ctx, glFrontFace(winding));
                    }

                    bool scissor = pipeline->raster.flags & FX_PIPELINE_RASTER_SCISSOR_TEST;
                    if(ctx->cache.raster.scissor != scissor) {
                        ctx->cache.raster.scissor = scissor;
                        if(scissor) {
                            FX_GL(ctx, glEnable(GL_SCISSOR_TEST));
                        } else {
                            FX_GL(ctx, glDisable(GL_SCISSOR_TEST));
                        }
                    }

                    bool alpha_to_coverage = pipeline->raster.flags & FX_PIPELINE_RASTER_ALPHA_TO_COVERAGE;
                    if(ctx->cache.raster.alpha_to_coverage != alpha_to_coverage) {
                        ctx->cache.raster.alpha_to_coverage = alpha_to_coverage;
                        if(alpha_to_coverage) {
                            FX_GL(ctx, glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE));
                        } else {
                            FX_GL(ctx, glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE));
                        }
                    }

                    if(ctx->cache.raster.point_size != pipeline->raster.point_size) {
                        ctx->cache.raster.point_size = pipeline->raster.point_size;
                        if(pipeline->raster.point_size > 0.0f) {
                            FX_GL(ctx, glPointSize(pipeline->raster.point_size));
                        }
                    }

                    if(ctx->cache.raster.fill != _FX_GL33_POLYGON[pipeline->raster.fill]) {
                        ctx->cache.raster.fill = _FX_GL33_POLYGON[pipeline->raster.fill];
                        FX_GL(ctx, glPolygonMode(GL_FRONT_AND_BACK, _FX_GL33_POLYGON[pipeline->raster.fill]));
                    }

                    if(ctx->cache.raster.line_width != pipeline->raster.line_width) {
                        ctx->cache.raster.line_width = pipeline->raster.line_width;
                        if(pipeline->raster.line_width > 0.0f) {
                            FX_GL(ctx, glLineWidth(pipeline->raster.line_width));
                        }
                    }

                    if(ctx->cache.raster.samples != pipeline->raster.samples) {
                        ctx->cache.raster.samples = pipeline->raster.samples;
                        if(pipeline->raster.samples > 0) {
                            FX_GL(ctx, glEnable(GL_MULTISAMPLE));
                        } else {
                            FX_GL(ctx, glDisable(GL_MULTISAMPLE));
                        }
                    }

                    FX_GL(ctx, glUseProgram(pipeline->program.name));
                }
            } break;
            case FX_CMD_KIND_BIND_VERTEX_BUFFERS: {
                fxCmdBindVertexBuffers* cmd = (fxCmdBindVertexBuffers*) raw_cmd;
                for(uint32_t i = 0; i < cmd->count; i++) {
                    fxGl33Buffer* buffer = FX_PTR_FROM_ID(ctx->buffers, cmd->vertex_buffers[i]);
                    uint32_t name = buffer->name;
                    if(ctx->cache.binding.vertex[i] != name) {
                        ctx->cache.binding.vertex[i] = name;
                        fxGl33Pipeline* pipeline = ctx->cache.pipeline;
                        fxGl33Layout* layout = &pipeline->layouts[i];
                        FX_ASSERT(buffer->target == GL_ARRAY_BUFFER);
                        FX_GL(ctx, glBindBuffer(GL_ARRAY_BUFFER, name));
                        FX_GL(ctx, glVertexAttribDivisor(i, layout->rate));
                        for(uint32_t j = 0; j < layout->count; j++) {
                            fxGl33VertexAttrib attrib = layout->attribs[j];
                            if(attrib.kind == 0) {
                                break;
                            }
                            FX_GL(ctx, glEnableVertexAttribArray(attrib.location));
                            FX_GL(ctx, glVertexAttribPointer(attrib.location, attrib.count, attrib.kind, attrib.normalised, layout->stride, (void*) (uintptr_t) attrib.offset));
                        }
                    }
                }
            } break;
            case FX_CMD_KIND_BIND_INDEX_BUFFER: {
                fxCmdBindIndexBuffer* cmd = (fxCmdBindIndexBuffer*) raw_cmd;
                fxGl33Buffer* buffer = FX_PTR_FROM_ID(ctx->buffers, cmd->index_buffer);
                uint32_t name = buffer->name;
                if(ctx->cache.binding.index != name) {
                    ctx->cache.binding.index = name;
                    ctx->cache.binding.index_type = _FX_GL33_INDEX_TYPE[cmd->index_kind];
                    FX_GL(ctx, glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, name));
                }
            } break;
            case FX_CMD_KIND_BIND_UNIFORM_BUFFER: {
                fxCmdBindUniformBuffer* cmd = (fxCmdBindUniformBuffer*) raw_cmd;
                fxGl33Buffer* buffer = FX_PTR_FROM_ID(ctx->buffers, cmd->uniform_buffer);
                uint32_t name = buffer->name;
                if(ctx->cache.binding.uniform[cmd->index] != name) {
                    ctx->cache.binding.uniform[cmd->index] = name;
                    FX_GL(ctx, glBindBufferRange(GL_UNIFORM_BUFFER, cmd->index, name, cmd->offset, cmd->size));
                }
            } break;
            case FX_CMD_KIND_BUFFER_UPDATE: {
                fxCmdBufferUpdate* cmd = (fxCmdBufferUpdate*) raw_cmd;
                void* data = cmd + 1;
                _fx_backend_buffer_update(ctx, cmd->buffer, data, cmd->size, cmd->offset);
            } break;
            case FX_CMD_KIND_BUFFER_COPY: {
                fxCmdBufferCopy* cmd = (fxCmdBufferCopy*) raw_cmd;
                fxGl33Buffer* src = FX_PTR_FROM_ID(ctx->buffers, cmd->src);
                fxGl33Buffer* dst = FX_PTR_FROM_ID(ctx->buffers, cmd->dst);
                FX_GL(ctx, glBindBuffer(GL_COPY_READ_BUFFER, src->name));
                FX_GL(ctx, glBindBuffer(GL_COPY_WRITE_BUFFER, dst->name));
                FX_GL(ctx, glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, cmd->src_offset, cmd->dst_offset, cmd->size == FX_ALL ? src->size: cmd->size));
            } break;
            case FX_CMD_KIND_BIND_TEXTURES: {
                fxCmdBindTextures* cmd = (fxCmdBindTextures*) raw_cmd;
                for(uint32_t i = 0; i < cmd->count; i++) {
                    fxGl33Texture* texture = FX_PTR_FROM_ID(ctx->textures, cmd->textures[i]);
                    uint32_t name = texture->name;
                    if(ctx->cache.binding.texture[i] != name) {
                        ctx->cache.binding.texture[i] = name;
                        uint8_t unit = (cmd->units[i] == ((uint8_t) -1)) ? i: cmd->units[i];
                        FX_GL(ctx, glActiveTexture(GL_TEXTURE0 + unit));
                        FX_GL(ctx, glBindTexture(texture->target, name));
                    }
                }
            } break;
            case FX_CMD_KIND_BIND_SAMPLERS: {
                fxCmdBindSamplers* cmd = (fxCmdBindSamplers*) raw_cmd;
                for(uint32_t i = 0; i < cmd->count; i++) {
                    fxGl33Sampler* sampler = FX_PTR_FROM_ID(ctx->samplers, cmd->samplers[i]);
                    uint32_t name = sampler->name;
                    if(ctx->cache.binding.sampler[i] != name) {
                        ctx->cache.binding.sampler[i] = name;
                        FX_GL(ctx, glBindSampler(cmd->units[i] == ((uint8_t) -1) ? i: cmd->units[i], name));
                    }
                }
            } break;
            case FX_CMD_KIND_TEXTURE_COPY: {
                FX_ASSERT(!"Texture Copy is Unsupported in GL33");
            } break;
            case FX_CMD_KIND_TEXTURE_BLIT: {
                fxCmdTextureBlit* cmd = (fxCmdTextureBlit*) raw_cmd;
                fxGl33Texture* src = FX_PTR_FROM_ID(ctx->textures, cmd->src);
                fxGl33Texture* dst = FX_PTR_FROM_ID(ctx->textures, cmd->dst);
                fxTextureRegion region = cmd->region;
                FX_GL(ctx, glBindFramebuffer(GL_READ_FRAMEBUFFER, src->name));
                FX_GL(ctx, glBindFramebuffer(GL_DRAW_FRAMEBUFFER, dst->name));
                FX_GL(ctx, glBlitFramebuffer(
                    region.src_offset.x, region.src_offset.y, region.src_offset.x + region.width, region.src_offset.y + region.height,
                    region.dst_offset.x, region.dst_offset.y, region.dst_offset.x + region.width, region.dst_offset.y + region.height,
                    GL_COLOR_BUFFER_BIT, GL_NEAREST));
            } break;
            case FX_CMD_KIND_DRAW: {
                fxCmdDraw* cmd = (fxCmdDraw*) raw_cmd;
                FX_GL(ctx, glDrawArrays(_FX_GL33_PRIMITIVE[cmd->primitive], cmd->first_vertex, cmd->count));
            } break;
            case FX_CMD_KIND_DRAW_INDEXED: {
                fxCmdDraw* cmd = (fxCmdDraw*) raw_cmd;
                GLenum index_type = ctx->cache.binding.index_type;
                void* offset = (void*) ((uint64_t) cmd->first_index * (index_type == GL_UNSIGNED_SHORT ? sizeof(uint16_t): sizeof(uint32_t)));
                FX_GL(ctx, glDrawElementsBaseVertex(_FX_GL33_PRIMITIVE[cmd->primitive], cmd->count, index_type, offset, cmd->first_vertex));
            } break;
            case FX_CMD_KIND_DRAW_INSTANCED: {
                fxCmdDrawInstanced* cmd = (fxCmdDrawInstanced*) raw_cmd;
                FX_GL(ctx, glDrawArraysInstanced(_FX_GL33_PRIMITIVE[cmd->primitive], cmd->first_vertex, cmd->count, cmd->instance_count));
            } break;
            case FX_CMD_KIND_DRAW_INSTANCED_INDEXED: {
                fxCmdDrawInstanced* cmd = (fxCmdDrawInstanced*) raw_cmd;
                GLenum index_type = ctx->cache.binding.index_type;
                void* offset = (void*) ((uint64_t) cmd->first_index * (index_type == GL_UNSIGNED_SHORT ? sizeof(uint16_t): sizeof(uint32_t)));
                FX_GL(ctx, glDrawElementsInstancedBaseVertex(_FX_GL33_PRIMITIVE[cmd->primitive], cmd->count, index_type, offset, cmd->instance_count, cmd->first_vertex));
            } break;
            default: { FX_ASSERT(!"Unimplemented"); } break;
        }
        cmds += sizeof(fxCmdHeader) + header->size;
    } while(cmds < (cmd_buffer->cmds + cmd_buffer->used));
    // FX_GL(ctx, glFinish());
}

static void _fx_backend_debug_callback(GLenum src, GLenum type, uint32_t id, GLenum severity, int32_t size, const GLchar* msg, const void* usr) {
    (void) (id);
    (void) (size);

    static const char* GL_ERROR_SOURCE[] = {"API", "Window System", "Shader Compiler", "Third Party", "Application",   "Other"};
    static const char* GL_ERROR_SEVERITY[] = {"High", "Medium", "Low", "Notification"};
    static const char* GL_ERROR_TYPE[] = {"Error", "Deprecated", "Undefined", "Portability", "Performance", "Other"};

    fxBackendCtx* ctx = (fxBackendCtx*) usr;
    FX_ASSERT(ctx != NULL);
    ctx->log(ctx->usr,
        "%d:%s:%s:%s: %s\n", _FX_GL33_LINE, GL_ERROR_SOURCE[src - GL_DEBUG_SOURCE_API],
        GL_ERROR_SEVERITY[severity != GL_DEBUG_SEVERITY_NOTIFICATION ? severity - GL_DEBUG_SEVERITY_HIGH: 3],
        GL_ERROR_TYPE[type - GL_DEBUG_TYPE_ERROR], msg);
}

static void* _fx_backend(fxCfg* cfg, fxSystemInfo* info) {
    fxBackendCtx* res = (fxBackendCtx*) FX_MALLOC(sizeof(fxBackendCtx));
    FX_ASSERT(res != NULL);
    FX_MEMSET(res, 0, sizeof(fxBackendCtx));

    res->usr = cfg->usr;
    res->log = cfg->log;

#define _FX_GL33_FN_LOAD(type, ret, name, ...) res->name = (ret(*)(__VA_ARGS__)) cfg->fn_address(cfg->usr_fn_address, #name);
    _FX_GL33_FN_MAP(_FX_GL33_FN_LOAD)
#undef _FX_GL33_FN_LOAD

    FX_GL(res, glGenVertexArrays(1, &res->cache.vertex_array));
    FX_GL(res, glBindVertexArray(res->cache.vertex_array));

    if(res->glDebugMessageCallback) {
        FX_GL(res, glDebugMessageCallback(_fx_backend_debug_callback, res));
        FX_GL(res, glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE));
        FX_GL(res, glEnable(GL_DEBUG_OUTPUT));
        FX_GL(res, glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS));
    }

    res->buffer_allocator = _fx_pool_allocator(res->buffers, FX_CONFIG_BUFFER_MAX, sizeof(fxGl33Buffer));
    res->pass_allocator = _fx_pool_allocator(res->passes, FX_CONFIG_PASS_MAX, sizeof(fxGl33Pass));
    res->pipeline_allocator = _fx_pool_allocator(res->pipelines, FX_CONFIG_PIPELINE_MAX, sizeof(fxGl33Pipeline));
    res->sampler_allocator = _fx_pool_allocator(res->samplers, FX_CONFIG_TEXTURE_MAX, sizeof(fxGl33Sampler));
    res->shader_allocator = _fx_pool_allocator(res->shaders, FX_CONFIG_SHADER_MAX, sizeof(fxGl33Shader));
    res->texture_allocator = _fx_pool_allocator(res->textures, FX_CONFIG_TEXTURE_MAX, sizeof(fxGl33Texture));

    res->default_pass.name = 0;
    res->default_pass.count = 1;

    FX_GL(res, glDisable(GL_DEPTH_TEST));
    FX_GL(res, glDepthFunc(GL_ALWAYS));
    FX_GL(res, glDepthMask(GL_FALSE));
    FX_GL(res, glDisable(GL_STENCIL_TEST));

    FX_GL(res, glDisable(GL_BLEND));
    FX_GL(res, glBlendFuncSeparate(GL_ONE, GL_ZERO, GL_ONE, GL_ZERO));
    FX_GL(res, glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD));
    FX_GL(res, glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE));
    FX_GL(res, glBlendColor(0.0f, 0.0f, 0.0f, 0.0f));

    FX_GL(res, glDisable(GL_CULL_FACE));
    FX_GL(res, glFrontFace(GL_CCW));
    FX_GL(res, glCullFace(GL_BACK));
    FX_GL(res, glDisable(GL_POLYGON_OFFSET_FILL));
    FX_GL(res, glDisable(GL_SCISSOR_TEST));
    FX_GL(res, glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE));
    FX_GL(res, glEnable(GL_DITHER));

    res->cache.depth_stencil.depth_op = GL_ALWAYS;
    res->cache.raster.winding = GL_CCW;
    res->cache.raster.cull = GL_NONE;
    res->cache.raster.line_width = 1.0f;
    res->cache.raster.point_size = 1.0f;

    if(info) {
        info->api = "fx OpenGL 3.3";
        info->version = (const char*) FX_GL(res, glGetString(GL_VERSION));
        info->device = (const char*) FX_GL(res, glGetString(GL_RENDERER));
        info->vendor = (const char*) FX_GL(res, glGetString(GL_VENDOR));
        info->shading_language = (const char*) FX_GL(res, glGetString(GL_SHADING_LANGUAGE_VERSION));
        info->texture_copy_support = false;
        info->geometry_shader_support = true;
        info->tessellation_shader_support = false;
        info->compute_shader_support = false;
        FX_GL(res, glGetIntegerv(GL_MAX_TEXTURE_SIZE, (GLint*) &info->max_texture_size));
        FX_GL(res, glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, (GLint*) &info->max_texture_array_count));
    }

    return res;
}

/*
 * ---------------------------------- LICENSE ----------------------------------
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org>
 * =============================================================================
 */
