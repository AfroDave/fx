#include <GL/glcorearb.h>

#define _FX_GL45_FN_MAP(X)                                                                                                                                                                                                                                                                         \
    X(PFNGLCREATESAMPLERSPROC, void, glCreateSamplers, GLsizei n, GLuint* samplers)                                                                                                                                                                                                                \
    X(PFNGLSAMPLERPARAMETERIPROC, void, glSamplerParameteri, GLuint sampler, GLenum pname, GLint param)                                                                                                                                                                                            \
    X(PFNGLDELETESAMPLERSPROC, void, glDeleteSamplers, GLsizei n, const GLuint* samplers)                                                                                                                                                                                                          \
    X(PFNGLBINDSAMPLERPROC, void, glBindSampler, GLuint unit, GLuint sampler)                                                                                                                                                                                                                      \
    X(PFNGLBLITNAMEDFRAMEBUFFERPROC, void, glBlitNamedFramebuffer, GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)                                         \
    X(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, void, glTextureStorage2DMultisample, GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)                                                                                            \
    X(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, void, glTextureStorage3DMultisample, GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)                                                                             \
    X(PFNGLCOPYIMAGESUBDATAPROC, void, glCopyImageSubData, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)      \
    X(PFNGLDELETESYNCPROC, void, glDeleteSync, GLsync sync)                                                                                                                                                                                                                                        \
    X(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, void, glFlushMappedNamedBufferRange, GLuint buffer, GLintptr offset, GLsizeiptr length)                                                                                                                                                                \
    X(PFNGLCLIENTWAITSYNCPROC, GLenum, glClientWaitSync, GLsync sync, GLbitfield flags, GLuint64 timeout)                                                                                                                                                                                          \
    X(PFNGLUNMAPNAMEDBUFFERPROC, GLboolean, glUnmapNamedBuffer, GLuint buffer)                                                                                                                                                                                                                     \
    X(PFNGLCREATESHADERPROC, GLuint, glCreateShader, GLenum type)                                                                                                                                                                                                                                  \
    X(PFNGLATTACHSHADERPROC, void, glAttachShader, GLuint program, GLuint shader)                                                                                                                                                                                                                  \
    X(PFNGLDETACHSHADERPROC, void, glDetachShader, GLuint program, GLuint shader)                                                                                                                                                                                                                  \
    X(PFNGLLINKPROGRAMPROC, void, glLinkProgram, GLuint program)                                                                                                                                                                                                                                   \
    X(PFNGLPROGRAMBINARYPROC, void, glProgramBinary, GLuint program, GLenum binaryFormat, const void* binary, GLsizei length)                                                                                                                                                                      \
    X(PFNGLSHADERBINARYPROC, void, glShaderBinary, GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length)                                                                                                                                                  \
    X(PFNGLGETATTRIBLOCATIONPROC, GLint, glGetAttribLocation, GLuint program, const GLchar* name)                                                                                                                                                                                                  \
    X(PFNGLGETUNIFORMLOCATIONPROC, GLint, glGetUniformLocation, GLuint program, const GLchar* name)                                                                                                                                                                                                \
    X(PFNGLGETPROGRAMRESOURCEINDEXPROC, GLuint, glGetProgramResourceIndex, GLuint program, GLenum programInterface, const GLchar* name)                                                                                                                                                            \
    X(PFNGLGETPROGRAMRESOURCENAMEPROC, void, glGetProgramResourceName, GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name)                                                                                                                      \
    X(PFNGLGETPROGRAMRESOURCEIVPROC, void, glGetProgramResourceiv, GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei* length, GLint* params)                                                                                 \
    X(PFNGLGETPROGRAMRESOURCELOCATIONPROC, GLint, glGetProgramResourceLocation, GLuint program, GLenum programInterface, const GLchar* name)                                                                                                                                                       \
    X(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, GLint, glGetProgramResourceLocationIndex, GLuint program, GLenum programInterface, const GLchar* name)                                                                                                                                             \
    X(PFNGLGETPROGRAMINTERFACEIVPROC, void, glGetProgramInterfaceiv, GLuint program, GLenum programInterface, GLenum pname, GLint* params)                                                                                                                                                         \
    X(PFNGLVERTEXBINDINGDIVISORPROC, void, glVertexBindingDivisor, GLuint bindingindex, GLuint divisor)                                                                                                                                                                                            \
    X(PFNGLFINISHPROC, void, glFinish, void)                                                                                                                                                                                                                                                       \
    X(PFNGLFENCESYNCPROC, GLsync, glFenceSync, GLenum condition, GLbitfield flags)                                                                                                                                                                                                                 \
    X(PFNGLMAPNAMEDBUFFERRANGE, void*, glMapNamedBufferRange, GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)                                                                                                                                                                \
    X(PFNGLLOGICOPPROC, void, glLogicOp, GLenum opcode)                                                                                                                                                                                                                                            \
    X(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, GLenum, glCheckNamedFramebufferStatus, GLuint framebuffer, GLenum target)                                                                                                                                                                              \
    X(PFNGLGETSHADERINFOLOGPROC, void, glGetShaderInfoLog, GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog)                                                                                                                                                                       \
    X(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, void, glGetProgramPipelineInfoLog, GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog)                                                                                                                                                   \
    X(PFNGLCLEARPROC, void, glClear, GLbitfield flags)                                                                                                                                                                                                                                             \
    X(PFNGLCLEARCOLOURPROC, void, glClearColor, GLfloat r, GLfloat g, GLfloat b, GLfloat a)                                                                                                                                                                                                        \
    X(PFNGLCLEARDEPTHPROC, void, glClearDepth, GLdouble d)                                                                                                                                                                                                                                         \
    X(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, void, glClearNamedFramebufferiv, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value)                                                                                                                                                  \
    X(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, void, glClearNamedFramebufferuiv, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value)                                                                                                                                               \
    X(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, void, glClearNamedFramebufferfv, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value)                                                                                                                                                \
    X(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, void, glClearNamedFramebufferfi, GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)                                                                                                                                        \
    X(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, void, glCompressedTextureSubImage2D, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data)                                                                     \
    X(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, void, glCompressedTextureSubImage3D, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data)                                       \
    X(PFNGLBINDBUFFERPROC, void, glBindBuffer, GLenum target, GLuint buffer)                                                                                                                                                                                                                       \
    X(PFNGLBINDBUFFERRANGEPROC, void, glBindBufferRange, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)                                                                                                                                                             \
    X(PFNGLBINDFRAMEBUFFERPROC, void, glBindFramebuffer, GLenum target, GLuint framebuffer)                                                                                                                                                                                                        \
    X(PFNGLUSEPROGRAMPROC, void, glUseProgram, GLuint program)                                                                                                                                                                                                                                     \
    X(PFNGLBINDPROGRAMPIPELINEPROC, void, glBindProgramPipeline, GLuint pipeline)                                                                                                                                                                                                                  \
    X(PFNGLBINDTEXTUREPROC, void, glBindTexture, GLenum target, GLuint texture)                                                                                                                                                                                                                    \
    X(PFNGLBINDTEXTUREUNITPROC, void, glBindTextureUnit, GLuint unit, GLuint texture)                                                                                                                                                                                                              \
    X(PFNGLBINDVERTEXARRAYPROC, void, glBindVertexArray, GLuint array)                                                                                                                                                                                                                             \
    X(PFNGLBINDVERTEXBUFFERPROC, void, glBindVertexBuffer, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)                                                                                                                                                                    \
    X(PFNGLBLENDCOLORPROC, void, glBlendColor, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)                                                                                                                                                                                            \
    X(PFNGLBLENDEQUATIONSEPARATEIPROC, void, glBlendEquationSeparatei, GLuint buf, GLenum modeRGB, GLenum modeAlpha)                                                                                                                                                                               \
    X(PFNGLBLENDEQUATIONSEPARATEPROC, void, glBlendEquationSeparate, GLenum modeRGB, GLenum modeAlpha)                                                                                                                                                                                             \
    X(PFNGLBLENDFUNCSEPARATEIPROC, void, glBlendFuncSeparatei, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)                                                                                                                                                         \
    X(PFNGLBLENDFUNCSEPARATEPROC, void, glBlendFuncSeparate, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)                                                                                                                                                                       \
    X(PFNGLCOPYNAMEDBUFFERSUBDATAPROC, void, glCopyNamedBufferSubData, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)                                                                                                                          \
    X(PFNGLCOLORMASKIPROC, void, glColorMaski, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)                                                                                                                                                                                   \
    X(PFNGLCOLORMASKPROC, void, glColorMask, GLboolean r, GLboolean g, GLboolean b, GLboolean a)                                                                                                                                                                                                   \
    X(PFNGLCREATEBUFFERSPROC, void, glCreateBuffers, GLsizei n, GLuint* buffers)                                                                                                                                                                                                                   \
    X(PFNGLCREATEFRAMEBUFFERSPROC, void, glCreateFramebuffers, GLsizei n, GLuint* framebuffers)                                                                                                                                                                                                    \
    X(PFNGLCREATEPROGRAMPIPELINESPROC, void, glCreateProgramPipelines, GLsizei n, GLuint* pipelines)                                                                                                                                                                                               \
    X(PFNGLCREATEPROGRAMPROC, GLuint, glCreateProgram, void)                                                                                                                                                                                                                                       \
    X(PFNGLCREATESHADERPROGRAMVPROC, GLuint, glCreateShaderProgramv, GLenum type, GLsizei count, const GLchar* const* strings)                                                                                                                                                                     \
    X(PFNGLCREATETEXTURESPROC, void, glCreateTextures, GLenum target, GLsizei n, GLuint* textures)                                                                                                                                                                                                 \
    X(PFNGLCULLFACEPROC, void, glCullFace, GLenum mode)                                                                                                                                                                                                                                            \
    X(PFNGLDEBUGMESSAGECALLBACKPROC, void, glDebugMessageCallback, GLDEBUGPROC callback, const void* userParam)                                                                                                                                                                                    \
    X(PFNGLDEBUGMESSAGECONTROLPROC, void, glDebugMessageControl, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled)                                                                                                                                 \
    X(PFNGLDEBUGMESSAGEINSERTPROC, void, glDebugMessageInsert, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf)                                                                                                                                          \
    X(PFNGLDELETEBUFFERSPROC, void, glDeleteBuffers, GLsizei n, const GLuint* buffers)                                                                                                                                                                                                             \
    X(PFNGLDELETEFRAMEBUFFERSPROC, void, glDeleteFramebuffers, GLsizei n, const GLuint* framebuffers)                                                                                                                                                                                              \
    X(PFNGLDELETEPROGRAMPIPELINESPROC, void, glDeleteProgramPipelines, GLsizei n, const GLuint* pipelines)                                                                                                                                                                                         \
    X(PFNGLDELETEPROGRAMPROC, void, glDeleteProgram, GLuint program)                                                                                                                                                                                                                               \
    X(PFNGLDELETESHADERPROC, void, glDeleteShader, GLuint shader)                                                                                                                                                                                                                                  \
    X(PFNGLDELETETEXTURESPROC, void, glDeleteTextures, GLsizei n, const GLuint* textures)                                                                                                                                                                                                          \
    X(PFNGLDELETEVERTEXARRAYSPROC, void, glDeleteVertexArrays, GLsizei n, const GLuint* arrays)                                                                                                                                                                                                    \
    X(PFNGLDEPTHFUNCPROC, void, glDepthFunc, GLenum func)                                                                                                                                                                                                                                          \
    X(PFNGLDEPTHMASKPROC, void, glDepthMask, GLboolean flag)                                                                                                                                                                                                                                       \
    X(PFNGLDEPTHRANGEPROC, void, glDepthRange, GLdouble near, GLdouble far)                                                                                                                                                                                                                        \
    X(PFNGLDISABLEIPROC, void, glDisablei, GLenum target, GLuint index)                                                                                                                                                                                                                            \
    X(PFNGLDISABLEPROC, void, glDisable, GLenum cap)                                                                                                                                                                                                                                               \
    X(PFNGLDRAWARRAYSINSTANCEDPROC, void, glDrawArraysInstanced, GLenum mode, GLint first, GLsizei count, GLsizei primcecount)                                                                                                                                                                     \
    X(PFNGLDRAWARRAYSPROC, void, glDrawArrays, GLenum mode, GLint first, GLsizei count)                                                                                                                                                                                                            \
    X(PFNGLDRAWELEMENTSBASEVERTEXPROC, void, glDrawElementsBaseVertex, GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex)                                                                                                                                             \
    X(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, void, glDrawElementsInstancedBaseVertex, GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount, GLint basevertex)                                                                                                        \
    X(PFNGLENABLEIPROC, void, glEnablei, GLenum target, GLuint index)                                                                                                                                                                                                                              \
    X(PFNGLENABLEPROC, void, glEnable, GLenum cap)                                                                                                                                                                                                                                                 \
    X(PFNGLENABLEVERTEXATTRIBARRAYPROC, void, glEnableVertexAttribArray, GLuint index)                                                                                                                                                                                                             \
    X(PFNGLFRONTFACEPROC, void, glFrontFace, GLenum mode)                                                                                                                                                                                                                                          \
    X(PFNGLGENERATETEXTUREMIPMAPPROC, void, glGenerateTextureMipmap, GLuint texture)                                                                                                                                                                                                               \
    X(PFNGLGENVERTEXARRAYSPROC, void, glGenVertexArrays, GLsizei n, GLuint* arrays)                                                                                                                                                                                                                \
    X(PFNGLGETERRORPROC, GLenum, glGetError, void)                                                                                                                                                                                                                                                 \
    X(PFNGLGETINTEGERVPROC, void, glGetIntegerv, GLenum pname, GLint* data)                                                                                                                                                                                                                        \
    X(PFNGLGETPROGRAMINFOLOGPROC, void, glGetProgramInfoLog, GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog)                                                                                                                                                                    \
    X(PFNGLGETPROGRAMIVPROC, void, glGetProgramiv, GLuint program, GLenum pname, GLint* params)                                                                                                                                                                                                    \
    X(PFNGLGETPROGRAMPIPELINEIVPROC, void, glGetProgramPipelineiv, GLuint pipeline, GLenum pname, GLint* params)                                                                                                                                                                                   \
    X(PFNGLGETSHADERIVPROC, void, glGetShaderiv, GLuint shader, GLenum pname, GLint* params)                                                                                                                                                                                                       \
    X(PFNGLGETSTRINGPROC, const GLubyte*, glGetString, GLenum name)                                                                                                                                                                                                                                \
    X(PFNGLGETSTRINGIPROC, const GLubyte*, glGetStringi, GLenum name, GLuint index)                                                                                                                                                                                                                \
    X(PFNGLLINEWIDTHPROC, void, glLineWidth, GLfloat width)                                                                                                                                                                                                                                        \
    X(PFNGLNAMEDBUFFERSTORAGEPROC, void, glNamedBufferStorage, GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags)                                                                                                                                                                 \
    X(PFNGLNAMEDBUFFERSUBDATAEXTPROC, void, glNamedBufferSubDataEXT, GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data)                                                                                                                                                            \
    X(PFNGLNAMEDBUFFERSUBDATAPROC, void, glNamedBufferSubData, GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data)                                                                                                                                                                  \
    X(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, void, glNamedFramebufferTexture, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)                                                                                                                                                       \
    X(PFNGLPIXELSTOREIPROC, void, glPixelStorei, GLenum pname, GLint param)                                                                                                                                                                                                                        \
    X(PFNGLPOINTSIZEPROC, void, glPointSize, GLfloat size)                                                                                                                                                                                                                                         \
    X(PFNGLPOLYGONMODEPROC, void, glPolygonMode, GLenum face, GLenum mode)                                                                                                                                                                                                                         \
    X(PFNGLPROGRAMPARAMETERIPROC, void, glProgramParameteri, GLuint program, GLenum pname, GLint value)                                                                                                                                                                                            \
    X(PFNGLSCISSORPROC, void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height)                                                                                                                                                                                                          \
    X(PFNGLSTENCILFUNCSEPARATEPROC, void, glStencilFuncSeparate, GLenum face, GLenum func, GLint ref, GLuint mask)                                                                                                                                                                                 \
    X(PFNGLSTENCILMASKSEPARATEPROC, void, glStencilMaskSeparate, GLenum face, GLuint mask)                                                                                                                                                                                                         \
    X(PFNGLSTENCILOPSEPARATEPROC, void, glStencilOpSeparate, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)                                                                                                                                                                              \
    X(PFNGLTEXTUREPARAMETERIPROC, void, glTextureParameteri, GLuint texture, GLenum pname, GLint param)                                                                                                                                                                                            \
    X(PFNGLTEXTURESTORAGE2DPROC, void, glTextureStorage2D, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)                                                                                                                                                   \
    X(PFNGLTEXTURESTORAGE3DPROC, void, glTextureStorage3D, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)                                                                                                                                    \
    X(PFNGLTEXTURESUBIMAGE2DPROC, void, glTextureSubImage2D, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels)                                                                                             \
    X(PFNGLTEXTURESUBIMAGE3DPROC, void, glTextureSubImage3D, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels)                                                               \
    X(PFNGLUSEPROGRAMSTAGESPROC, void, glUseProgramStages, GLuint pipeline, GLbitfield stages, GLuint program)                                                                                                                                                                                     \
    X(PFNGLVERTEXATTRIBBINDINGPROC, void, glVertexAttribBinding, GLuint attribindex, GLuint bindingindex)                                                                                                                                                                                          \
    X(PFNGLVERTEXATTRIBFORMATPROC, void, glVertexAttribFormat, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)                                                                                                                                           \
    X(PFNGLVIEWPORTPROC, void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height)

static uint32_t _FX_GL45_LINE = 0;

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

static const GLenum _FX_GL45_INDEX_TYPE[] = {
    GL_UNSIGNED_SHORT,
    GL_UNSIGNED_INT,
};

static const GLenum _FX_GL45_PRIMITIVE[] = {
    GL_TRIANGLES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,
    GL_POINTS,
    GL_LINES,
    GL_LINE_STRIP,
    GL_PATCHES,
};

static const GLenum _FX_GL45_POLYGON[] = {
    GL_FILL,
    GL_LINE,
    GL_POINT,
};

static const GLenum _FX_GL45_CULL[] = {
    GL_NONE,
    GL_FRONT,
    GL_BACK,
    GL_FRONT_AND_BACK,
};

static const GLenum _FX_GL45_FRONT_FACE[] = {
    GL_CCW,
    GL_CW,
};

static const GLenum _FX_GL45_COMPARE_FUNC[] = {
    GL_ALWAYS,
    GL_LESS,
    GL_LEQUAL,
    GL_EQUAL,
    GL_NOTEQUAL,
    GL_GREATER,
    GL_GEQUAL,
    GL_NEVER,
};

static const GLenum _FX_GL45_STENCIL_OP[] = {
    GL_KEEP,
    GL_ZERO,
    GL_REPLACE,
    GL_INCR,
    GL_INCR_WRAP,
    GL_DECR,
    GL_DECR_WRAP,
    GL_INVERT,
};

static const GLenum _FX_GL45_BLEND_FACTOR[] = {
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

static const GLenum _FX_GL45_LOGIC_OP[] = {
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

static const GLenum _FX_GL45_BLEND_OP[] = {
    GL_FUNC_ADD,
    GL_FUNC_SUBTRACT,
    GL_FUNC_REVERSE_SUBTRACT,
    GL_MIN,
    GL_MAX
};

static const GLenum _FX_GL45_COMPONENT_SWIZZLE[] = {
    GL_NONE,
    GL_ZERO,
    GL_ONE,
    GL_RED,
    GL_GREEN,
    GL_BLUE,
    GL_ALPHA
};

static const GLenum _FX_GL45_BUFFER_USAGE[] = {
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
} _FX_GL45_FORMAT[] = {
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

static const GLenum _FX_GL45_TEXTURE_TARGET[] = {
    GL_TEXTURE_2D,
    GL_TEXTURE_2D_ARRAY,
};

static const GLenum _FX_GL45_FILTER_TYPE[] = {
    GL_NEAREST,
    GL_LINEAR,
};

static const GLenum _FX_GL45_FILTER_MIPMAP_TYPE[] = {
    GL_NONE,
    GL_NEAREST_MIPMAP_NEAREST,
    GL_LINEAR_MIPMAP_NEAREST,
    GL_NEAREST_MIPMAP_LINEAR,
    GL_LINEAR_MIPMAP_LINEAR,
};

static const GLenum _FX_GL45_WRAP_TYPE[] = {
    GL_REPEAT,
    GL_MIRRORED_REPEAT,
    GL_CLAMP_TO_EDGE,
    GL_CLAMP_TO_BORDER,
    GL_MIRROR_CLAMP_TO_EDGE,
};

static const GLenum _FX_GL45_SHADER_STAGE[] = {
    GL_VERTEX_SHADER,
    GL_TESS_CONTROL_SHADER,
    GL_TESS_EVALUATION_SHADER,
    GL_GEOMETRY_SHADER,
    GL_FRAGMENT_SHADER,
};

//static const char* _fx_backend_glsl_type_name(GLenum kind) {
//    switch(kind) {
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

typedef struct fxGl45Buffer {
    uintptr_t _;

    fxBufferId id;
    uint32_t name;
    uint32_t target;
    uint32_t flags;
    uint32_t size;
    void* ptr;
} fxGl45Buffer;

typedef struct fxGl45Texture {
    uintptr_t _;

    fxTextureId id;
    uint32_t name;
    uint32_t target;
    uint32_t kind;
    uint32_t format;

    fxTextureCfg cfg;
} fxGl45Texture;

typedef struct fxGl45Sampler {
    uintptr_t _;

    fxSamplerId id;
    uint32_t name;
    uint32_t flags;
} fxGl45Sampler;

typedef struct fxGl45Shader {
    uintptr_t _;

    fxShaderId id;
    uint32_t name;
} fxGl45Shader;

typedef struct fxGl45Program {
    uintptr_t _;

    uint32_t name;
    struct {
        uint32_t name;
    } stages[FX_SHADER_STAGE_COUNT];
} fxGl45Program;

typedef struct fxGl45Attachment {
    fxGl45Texture* texture;
} fxGl45Attachment;

typedef struct fxGl45Pass {
    uintptr_t _;

    fxPassId id;
    uint32_t name;
    fxGl45Attachment colours[FX_CONFIG_ATTACHMENT_MAX];
    fxGl45Attachment depth_stencil;
    uint32_t count;
} fxGl45Pass;

typedef struct fxGl45RenderTarget {
    uintptr_t _;

    uint32_t name;
} fxGl45RenderTarget;

typedef struct fxGl45VertexAttrib {
    uint32_t binding: 3;
    uint32_t location: 3;
    uint32_t normalised: 1;
    uint32_t count: 3;
    uint32_t kind: 16;
    uint32_t offset: 6;
} fxGl45VertexAttrib;

typedef struct fxGl45Layout {
    fxGl45VertexAttrib attribs[FX_ATTRIB_SEMANTIC_COUNT];
    uint32_t rate;
    uint32_t stride;
    uint32_t count;
} fxGl45Layout;

typedef struct fxGl45Pipeline {
    uintptr_t _;

    fxPipelineId id;
    fxPipelineBlendCfg blend;
    fxPipelineRasterCfg raster;
    fxPipelineDepthStencilCfg depth_stencil;
    fxGl45Layout layouts[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
    fxGl45Program program;
} fxGl45Pipeline;

struct fxBackendCtx {
    void* usr;
    void (*log)(void* usr, const char* fmt, ...);

    fxPoolAllocator pipeline_allocator;
    fxPoolAllocator buffer_allocator;
    fxPoolAllocator shader_allocator;
    fxPoolAllocator texture_allocator;
    fxPoolAllocator sampler_allocator;
    fxPoolAllocator pass_allocator;

    fxGl45Pipeline pipelines[FX_CONFIG_PIPELINE_MAX];
    fxGl45Buffer buffers[FX_CONFIG_BUFFER_MAX];
    fxGl45Shader shaders[FX_CONFIG_SHADER_MAX];
    fxGl45Texture textures[FX_CONFIG_TEXTURE_MAX];
    fxGl45Sampler samplers[FX_CONFIG_TEXTURE_MAX];
    fxGl45Pass passes[FX_CONFIG_PASS_MAX];

    fxGl45Pass default_pass;

    struct {
        uint32_t vertex_array;
        fxGl45Pipeline* pipeline;
        struct {
            uint32_t vertex[FX_CONFIG_VERTEX_BUFFER_BINDING_MAX];
            uint32_t index;
            uint32_t index_kind;
            uint32_t pass;
            uint32_t uniform[FX_CONFIG_UNIFORM_BUFFER_BINDING_MAX];
            uint32_t texture[FX_CONFIG_ATTACHMENT_MAX];
            uint32_t sampler[FX_CONFIG_ATTACHMENT_MAX];
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

#define _FX_GL45_FN_DECL(type, ret, name, ...) ret (*name)(__VA_ARGS__);
    _FX_GL45_FN_MAP(_FX_GL45_FN_DECL)
#undef _FX_GL45_FN_DECL
};

#define FX_GL(ctx, fn) (ctx)->fn; _FX_GL45_LINE = __LINE__

static void _fx_backend_destroy(fxBackendCtx* ctx) {
    FX_ASSERT(ctx != NULL);
    FX_GL(ctx, glDeleteVertexArrays(1, &ctx->cache.vertex_array));
    FX_GL(ctx, glBindVertexArray(0));
    FX_FREE(ctx);
}

static fxGl45Program _fx_backend_program(fxBackendCtx* ctx, fxPipelineShaderCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    FX_ASSERT(cfg->vertex != FX_ID_INVALID);
    FX_ASSERT(cfg->fragment != FX_ID_INVALID);
    fxGl45Program res;

    FX_GL(ctx, glCreateProgramPipelines(1, &res.name));

    res.stages[FX_SHADER_STAGE_VERTEX].name = FX_PTR_FROM_ID(ctx->shaders, cfg->vertex)->name;
    FX_GL(ctx, glUseProgramStages(res.name, GL_VERTEX_SHADER_BIT, res.stages[FX_SHADER_STAGE_VERTEX].name));

    if(cfg->tessellation_control) {
        res.stages[FX_SHADER_STAGE_TESSELLATION_CONTROL].name = FX_PTR_FROM_ID(ctx->shaders, cfg->tessellation_control)->name;
        FX_GL(ctx, glUseProgramStages(res.name, GL_TESS_CONTROL_SHADER_BIT, res.stages[FX_SHADER_STAGE_TESSELLATION_CONTROL].name));
    }

    if(cfg->tessellation_evaluation) {
        res.stages[FX_SHADER_STAGE_TESSELLATION_EVALUATION].name = FX_PTR_FROM_ID(ctx->shaders, cfg->tessellation_evaluation)->name;
        FX_GL(ctx, glUseProgramStages(res.name, GL_TESS_EVALUATION_SHADER_BIT, res.stages[FX_SHADER_STAGE_TESSELLATION_EVALUATION].name));
    }

    if(cfg->geometry) {
        res.stages[FX_SHADER_STAGE_GEOMETRY].name = FX_PTR_FROM_ID(ctx->shaders, cfg->geometry)->name;
        FX_GL(ctx, glUseProgramStages(res.name, GL_GEOMETRY_SHADER_BIT, res.stages[FX_SHADER_STAGE_GEOMETRY].name));
    }

    res.stages[FX_SHADER_STAGE_FRAGMENT].name = FX_PTR_FROM_ID(ctx->shaders, cfg->fragment)->name;
    FX_GL(ctx, glUseProgramStages(res.name, GL_FRAGMENT_SHADER_BIT, res.stages[FX_SHADER_STAGE_FRAGMENT].name));

    GLint log_size = 0;
    FX_GL(ctx, glGetProgramPipelineiv(res.name, GL_INFO_LOG_LENGTH, &log_size));
    if(log_size) {
        char log[4096];
        FX_GL(ctx, glGetProgramPipelineInfoLog(res.name, sizeof(log), &log_size, log));
        FX_GL(ctx, glDeleteProgramPipelines(1, &res.name));
        log[log_size] = '\0';
        ctx->log(ctx->usr, "%s\n", log);
        FX_ASSERT(!"Failed to link program");
    }
    return res;
}

static fxPipelineId _fx_backend_pipeline(fxBackendCtx* ctx, fxPipelineCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl45Pipeline* pipeline = (fxGl45Pipeline*) _fx_pool_allocator_alloc(&ctx->pipeline_allocator);
    FX_ASSERT(pipeline != NULL);

    fxPipelineId id = FX_ID(FX_INDEX_FROM_PTR(pipeline, ctx->pipelines), FX_ID_GENERATION(pipeline->id) + 1, FX_ID_KIND_PIPELINE);
    pipeline->id = id;
    pipeline->program = _fx_backend_program(ctx, &cfg->shader);
    FX_MEMCOPY(&pipeline->blend, &cfg->blend, sizeof(fxPipelineBlendCfg));
    FX_MEMCOPY(&pipeline->raster, &cfg->raster, sizeof(fxPipelineRasterCfg));
    FX_MEMCOPY(&pipeline->depth_stencil, &cfg->depth_stencil, sizeof(fxPipelineDepthStencilCfg));
    for(uint32_t i = 0; i < FX_CONFIG_VERTEX_BUFFER_BINDING_MAX; i++) {
        fxPipelineLayoutCfg* layout = &cfg->layouts[i];
        fxGl45Layout* backend_layout = &pipeline->layouts[i];
        backend_layout->stride = (uint32_t) layout->stride;
        backend_layout->rate = (uint32_t) layout->rate;
        for(uint32_t j = 0; j < FX_ATTRIB_SEMANTIC_COUNT; j++) {
            fxVertexAttrib attrib = layout->attribs[j];
            if(attrib.format == FX_FORMAT_INVALID) {
                break;
            }
            if(layout->stride == 0) {
                backend_layout->stride += _FX_GL45_FORMAT[attrib.format].size * _FX_GL45_FORMAT[attrib.format].count;
            }
            backend_layout->attribs[j].binding = attrib.binding;
            backend_layout->attribs[j].location = attrib.location;
            backend_layout->attribs[j].normalised = _FX_GL45_FORMAT[attrib.format].normalised;
            backend_layout->attribs[j].count = _FX_GL45_FORMAT[attrib.format].count;
            backend_layout->attribs[j].kind = (uint16_t) _FX_GL45_FORMAT[attrib.format].kind;
            backend_layout->attribs[j].offset = attrib.offset;
            backend_layout->count++;
        }
    }
    return id;
}

static void _fx_backend_pipeline_destroy(fxBackendCtx* ctx, fxPipelineId pipeline) {
    FX_ASSERT(ctx != NULL);
    fxGl45Pipeline* pipeline_ptr = FX_PTR_FROM_ID(ctx->pipelines, pipeline);
    _fx_pool_allocator_dealloc(&ctx->pipeline_allocator, pipeline_ptr);
}

static void _fx_backend_buffer_create(fxBackendCtx* ctx, uint32_t* buffers, uint32_t count, void* data, uint32_t size, uint32_t flags) {
    FX_ASSERT(ctx != NULL);
    FX_GL(ctx, glCreateBuffers(count, buffers));
    for(uint32_t i = 0; i < count; i++) {
        FX_GL(ctx, glNamedBufferStorage(buffers[i], size, data, flags));
    }
}

static fxBufferId _fx_backend_buffer(fxBackendCtx* ctx, fxBufferCfg* cfg, void* data, uint32_t size) {
    FX_ASSERT(ctx != NULL);
    fxGl45Buffer* buffer = (fxGl45Buffer*) _fx_pool_allocator_alloc(&ctx->buffer_allocator);
    FX_ASSERT(buffer != NULL);
    FX_ASSERT(size <= cfg->size);

    fxBufferId id = FX_ID(FX_INDEX_FROM_PTR(buffer, ctx->buffers), FX_ID_GENERATION(buffer->id) + 1, FX_ID_KIND_BUFFER);
    buffer->id = id;
    buffer->size = cfg->size;
    buffer->flags = (cfg->flags & FX_BUFFER_DYNAMIC) ? GL_DYNAMIC_STORAGE_BIT: 0;
    buffer->target = _FX_GL45_BUFFER_USAGE[cfg->kind];
    _fx_backend_buffer_create(ctx, &buffer->name, 1, data, buffer->size, buffer->flags);
    return id;
}

static void _fx_backend_buffer_destroy(fxBackendCtx* ctx, fxBufferId buffer) {
    FX_ASSERT(ctx != NULL);
    fxGl45Buffer* buffer_ptr = FX_PTR_FROM_ID(ctx->buffers, buffer);
    FX_GL(ctx, glDeleteBuffers(1, &buffer_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->buffer_allocator, buffer_ptr);
}

static void _fx_backend_buffer_update(fxBackendCtx* ctx, fxBufferId buffer, void* data, uint32_t size, uint32_t offset) {
    FX_ASSERT(ctx != NULL);
    fxGl45Buffer* buffer_ptr = FX_PTR_FROM_ID(ctx->buffers, buffer);
    FX_ASSERT(buffer == buffer_ptr->id);
    FX_ASSERT((buffer_ptr->flags & FX_BUFFER_DYNAMIC) == 0);
    FX_ASSERT(offset + size <= buffer_ptr->size);
    FX_GL(ctx, glNamedBufferSubData(buffer_ptr->name, offset, size, data));
}

static fxTextureId _fx_backend_texture(fxBackendCtx* ctx, fxTextureCfg* cfg, void** datas, uint32_t* sizes) {
    FX_ASSERT(ctx != NULL);
    fxGl45Texture* texture = (fxGl45Texture*) _fx_pool_allocator_alloc(&ctx->texture_allocator);
    FX_ASSERT(texture != NULL);

    fxTextureId id = FX_ID(FX_INDEX_FROM_PTR(texture, ctx->textures), FX_ID_GENERATION(texture->id) + 1, FX_ID_KIND_TEXTURE);
    texture->id = id;
    bool compressed = cfg->format >= FX_FORMAT_BC1 && cfg->format <= FX_FORMAT_ETC2A1;
    uint32_t width = cfg->width;
    uint32_t height = cfg->height;
    uint32_t depth = cfg->depth;
    uint32_t mipmaps = FX_MAX(1, cfg->mipmaps);
    GLenum internal_format = _FX_GL45_FORMAT[cfg->format].internal_format;
    texture->format = _FX_GL45_FORMAT[cfg->format].format;
    texture->kind = _FX_GL45_FORMAT[cfg->format].kind;
    texture->target = _FX_GL45_TEXTURE_TARGET[cfg->kind];

    FX_MEMCOPY(&texture->cfg, cfg, sizeof(fxTextureCfg));

    FX_GL(ctx, glCreateTextures(texture->target, 1, &texture->name));
    if(texture->target == GL_TEXTURE_2D) {
        if(cfg->flags & FX_TEXTURE_MULTISAMPLE) {
            FX_GL(ctx, glTextureStorage2DMultisample(texture->name, cfg->samples, internal_format, width, height, GL_FALSE));
        } else {
            FX_GL(ctx, glTextureStorage2D(texture->name, mipmaps, internal_format, width, height));
        }
    } else if(texture->target == GL_TEXTURE_2D_ARRAY) {
        if(cfg->flags & FX_TEXTURE_MULTISAMPLE) {
            FX_GL(ctx, glTextureStorage3DMultisample(texture->name, cfg->samples, internal_format, width, height, depth, GL_FALSE));
        } else {
            FX_GL(ctx, glTextureStorage3D(texture->name, mipmaps, internal_format, width, height, depth));
        }
    }

    for(uint32_t mipmap = 0; mipmap < mipmaps; mipmap++) {
        if(texture->target == GL_TEXTURE_2D) {
            if(datas[mipmap]) {
                if(compressed) {
                    FX_GL(ctx, glCompressedTextureSubImage2D(texture->name, mipmap, 0, 0, width, height, texture->format, sizes[mipmap], datas[mipmap]));
                } else {
                    FX_GL(ctx, glTextureSubImage2D(texture->name, mipmap, 0, 0, width, height, texture->format, texture->kind, datas[mipmap]));
                }
            }
        } else if(texture->target == GL_TEXTURE_2D_ARRAY) {
            if(datas[mipmap]) {
                if(compressed) {
                    FX_GL(ctx, glCompressedTextureSubImage3D(texture->name, mipmap, 0, 0, 0, width, height, depth, texture->format, sizes[mipmap], datas[mipmap]));
                } else {
                    FX_GL(ctx, glTextureSubImage3D(texture->name, mipmap, 0, 0, 0, width, height, depth, texture->format, texture->kind, datas[mipmap]));
                }
            }
        }
        width >>= 1;
        height >>= 1;
        width = FX_MAX(1, width);
        height = FX_MAX(1, height);
    }

    if(cfg->swizzle_r != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTextureParameteri(texture->name, GL_TEXTURE_SWIZZLE_R, _FX_GL45_COMPONENT_SWIZZLE[cfg->swizzle_r]));
    }
    if(cfg->swizzle_g != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTextureParameteri(texture->name, GL_TEXTURE_SWIZZLE_G, _FX_GL45_COMPONENT_SWIZZLE[cfg->swizzle_g]));
    }
    if(cfg->swizzle_b != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTextureParameteri(texture->name, GL_TEXTURE_SWIZZLE_B, _FX_GL45_COMPONENT_SWIZZLE[cfg->swizzle_b]));
    }
    if(cfg->swizzle_a != FX_SWIZZLE_INDENTITY) {
        FX_GL(ctx, glTextureParameteri(texture->name, GL_TEXTURE_SWIZZLE_A, _FX_GL45_COMPONENT_SWIZZLE[cfg->swizzle_a]));
    }
    return id;
}

static void _fx_backend_texture_destroy(fxBackendCtx* ctx, fxTextureId texture) {
    FX_ASSERT(ctx != NULL);
    fxGl45Texture* texture_ptr = FX_PTR_FROM_ID(ctx->textures, texture);
    FX_GL(ctx, glDeleteTextures(1, &texture_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->texture_allocator, texture_ptr);
}

static void _fx_backend_texture_update(fxBackendCtx* ctx, fxTextureId texture, void* data, fxTextureRegion* region) {
    FX_ASSERT(ctx != NULL);
    fxGl45Texture* texture_ptr = FX_PTR_FROM_ID(ctx->textures, texture);
    FX_GL(ctx, glTextureSubImage2D(texture_ptr->name, 0, region->src_offset.x, region->src_offset.y, region->width, region->height, texture_ptr->format, texture_ptr->kind, data));
}

static fxSamplerId _fx_backend_sampler(fxBackendCtx* ctx, fxSamplerCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl45Sampler* sampler = (fxGl45Sampler*) _fx_pool_allocator_alloc(&ctx->sampler_allocator);
    FX_ASSERT(sampler != NULL);

    fxSamplerId id = FX_ID(FX_INDEX_FROM_PTR(sampler, ctx->samplers), FX_ID_GENERATION(sampler->id) + 1, FX_ID_KIND_SAMPLER);
    sampler->id = id;
    sampler->flags = cfg->flags;
    FX_GL(ctx, glCreateSamplers(1, &sampler->name));
    if(cfg->filter_mipmap != FX_FILTER_MIPMAP_MODE_NONE) {
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MIN_FILTER, _FX_GL45_FILTER_TYPE[cfg->filter_min]));
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MAG_FILTER, _FX_GL45_FILTER_MIPMAP_TYPE[cfg->filter_mipmap]));
    } else {
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MIN_FILTER, _FX_GL45_FILTER_TYPE[cfg->filter_min]));
        FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_MAG_FILTER, _FX_GL45_FILTER_TYPE[cfg->filter_mag]));
    }
    FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_WRAP_S, _FX_GL45_WRAP_TYPE[cfg->wrap_u]));
    FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_WRAP_T, _FX_GL45_WRAP_TYPE[cfg->wrap_v]));
    FX_GL(ctx, glSamplerParameteri(sampler->name, GL_TEXTURE_WRAP_R, _FX_GL45_WRAP_TYPE[cfg->wrap_w]));
    return id;
}

static void _fx_backend_sampler_destroy(fxBackendCtx* ctx, fxSamplerId sampler) {
    FX_ASSERT(ctx != NULL);
    fxGl45Sampler* sampler_ptr = FX_PTR_FROM_ID(ctx->samplers, sampler);
    FX_GL(ctx, glDeleteSamplers(1, &sampler_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->sampler_allocator, sampler_ptr);
}

static fxPassId _fx_backend_pass(fxBackendCtx* ctx, fxPassCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl45Pass* pass = (fxGl45Pass*) _fx_pool_allocator_alloc(&ctx->pass_allocator);
    FX_ASSERT(pass != NULL);

    fxPassId id = FX_ID(FX_INDEX_FROM_PTR(pass, ctx->passes), FX_ID_GENERATION(pass->id) + 1, FX_ID_KIND_PASS);
    pass->id = id;
    pass->count = 0;
    FX_GL(ctx, glCreateFramebuffers(1, &pass->name));
    for(uint64_t i = 0; i < FX_CONFIG_ATTACHMENT_MAX; i++) {
        if(!cfg->colours[i].texture) {
            break;
        }
        fxGl45Texture* colour = &ctx->textures[cfg->colours[i].texture];
        FX_GL(ctx, glNamedFramebufferTexture(pass->name, (GLenum) (GL_COLOR_ATTACHMENT0 + i), colour->name, 0));
        pass->colours[i].texture = colour;
        pass->count++;
    }
    if(cfg->depth_stencil.texture != FX_ID_INVALID) {
        fxGl45Texture* depth_stencil = &ctx->textures[cfg->depth_stencil.texture];
        GLenum depth_attachment = GL_DEPTH_STENCIL_ATTACHMENT;
        FX_GL(ctx, glNamedFramebufferTexture(pass->name, depth_attachment, depth_stencil->name, 0));
        pass->depth_stencil.texture = depth_stencil;
    }
    if(!ctx->glCheckNamedFramebufferStatus(pass->name, GL_FRAMEBUFFER)) {
        FX_GL(ctx, glDeleteFramebuffers(1, &pass->name));
        _fx_pool_allocator_dealloc(&ctx->pass_allocator, pass);
        return FX_ID_INVALID;
    }
    return id;
}

static void _fx_backend_pass_destroy(fxBackendCtx* ctx, fxPassId pass) {
    FX_ASSERT(ctx != NULL);
    fxGl45Pass* pass_ptr = FX_PTR_FROM_ID(ctx->passes, pass);
    FX_GL(ctx, glDeleteFramebuffers(1, &pass_ptr->name));
    _fx_pool_allocator_dealloc(&ctx->pass_allocator, pass_ptr);
}

static fxShaderId _fx_backend_shader(fxBackendCtx* ctx, fxShaderCfg* cfg) {
    FX_ASSERT(ctx != NULL);
    fxGl45Shader* shader = (fxGl45Shader*) _fx_pool_allocator_alloc(&ctx->shader_allocator);
    FX_ASSERT(shader != NULL);

    fxShaderId id = FX_ID(FX_INDEX_FROM_PTR(shader, ctx->shaders), FX_ID_GENERATION(shader->id) + 1, FX_ID_KIND_SHADER);
    shader->id = id;
#if 0
    uint32_t magic = *(uint32_t*) cfg->source;
    if(magic == 0x07230203) {
        shader = FX_GL(ctx, glCreateProgram());
        GLuint shader = FX_GL(ctx, glCreateShader(stage));
        FX_GL(ctx, glShaderBinary(1, &shader, GL_SHADER_BINARY_FORMAT_SPIR_V, cfg->source, cfg->size));
        FX_GL(ctx, glSpecializeShaderARB(shader, !cfg->entry ? "main": cfg->entry, 0, NULL, NULL));
        shader = FX_GL(ctx, glCreateProgram());
        FX_GL(ctx, glProgramParameteri(shader, GL_PROGRAM_SEPARABLE, GL_TRUE));
        FX_GL(ctx, glAttachShader(shader, shader));
        FX_GL(ctx, glLinkProgram(shader));
        FX_GL(ctx, glDetachShader(shader, shader));
        FX_GL(ctx, glDeleteShader(shader));
    } else {
#endif
    shader->name = FX_GL(ctx, glCreateShaderProgramv(_FX_GL45_SHADER_STAGE[cfg->stage], 1, &cfg->source));
#if 0
    }
#endif

    GLint log_size = 0;
    FX_GL(ctx, glGetProgramiv(shader->name, GL_INFO_LOG_LENGTH, &log_size));
    GLint status = 0;
    FX_GL(ctx, glGetProgramiv(shader->name, GL_LINK_STATUS, &status));
    if(!status) {
        char log[4096];
        FX_GL(ctx, glGetProgramInfoLog(shader->name, sizeof(log), &log_size, log));
        FX_GL(ctx, glDeleteProgram(shader->name));
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
    //    GLenum type = 0;
    //    FX_GL(ctx, glGetProgramResourceName(shader->name, GL_PROGRAM_INPUT, i, name_max + 1, &count, name));
    //    GLenum props[] = {
    //        GL_TYPE,
    //    };
    //    FX_GL(ctx, glGetProgramResourceiv(shader->name, GL_PROGRAM_INPUT, i, FX_COUNT_OF(props), props, 1, NULL, (GLint*) &type));
    //    ctx->log(ctx->usr, "\t\tlayout(location = %d) in %s %s\n", ctx->glGetAttribLocation(shader->name, name), _fx_backend_glsl_type_name(type), name);
    //}

    //typedef struct {
    //    GLenum type;
    //    GLint location;
    //    GLint count;
    //} fxGl45UniformInfo;

    //ctx->log(ctx->usr, "\tUniforms (%d):\n", uniform_count);
    //for(int32_t i = 0; i < uniform_count; i++) {
    //    GLint count = 0;
    //    GLenum type = 0;
    //    fxGl45UniformInfo info;
    //    GLenum props[] = {
    //        GL_TYPE,
    //        GL_LOCATION,
    //        GL_ARRAY_SIZE,
    //    };
    //    FX_GL(ctx, glGetProgramResourceName(shader->name, GL_UNIFORM, i, name_max + 1, NULL, name));
    //    FX_GL(ctx, glGetProgramResourceiv(shader->name, GL_UNIFORM, i, FX_COUNT_OF(props), props, 1, NULL, (GLint*) &info));
    //    count = info.count;
    //    type = info.type;
    //    ctx->log(ctx->usr,
    //        "\t\tlayout(location = %d) uniform %s %s\n", ctx->glGetUniformLocation(shader->name, name), _fx_backend_glsl_type_name(type), name);
    //}

    //ctx->log(ctx->usr, "\tOutputs (%d):\n", output_count);
    //for(int32_t i = 0; i < output_count; i++) {
    //    fxGl45UniformInfo info;
    //    GLenum props[] = {
    //        GL_TYPE,
    //        GL_LOCATION,
    //        GL_ARRAY_SIZE,
    //    };
    //    FX_GL(ctx, glGetProgramResourceName(shader->name, GL_PROGRAM_OUTPUT, i, name_max + 1, NULL, name));
    //    FX_GL(ctx, glGetProgramResourceiv( shader->name, GL_PROGRAM_OUTPUT, i, FX_COUNT_OF(props), props, 1, NULL, (GLint*) &info));
    //    ctx->log(ctx->usr, "\t\tlayout(location = %d) out %s %s\n", info.location, _fx_backend_glsl_type_name(info.type), name);
    //}

    return id;
}

static void _fx_backend_shader_destroy(fxBackendCtx* ctx, fxShaderId shader) {
    FX_ASSERT(ctx != NULL);
    fxGl45Shader* shader_ptr = FX_PTR_FROM_ID(ctx->shaders, shader);
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
                fxGl45Pass* pass = (fxGl45Pass*) (cmd->pass != FX_ID_INVALID ? FX_PTR_FROM_ID(ctx->passes, cmd->pass): &ctx->default_pass);
                fxGl45Texture* texture = pass->colours[0].texture;
                int32_t width = texture ? texture->cfg.width: cmd->width;
                int32_t height = texture ? texture->cfg.height: cmd->height;
                FX_GL(ctx, glBindFramebuffer(GL_FRAMEBUFFER, pass->name));
                FX_GL(ctx, glViewport(0.0f, 0.0f, width, height));
                FX_GL(ctx, glScissor(0.0f, 0.0f, width, height));
                fxPassOp ops = cmd->ops;
                for(uint32_t i = 0; i < pass->count; i++) {
                    if(ops.colours[i].kind == FX_PASS_OP_KIND_CLEAR) {
                        float colour[4];
                        colour[0] = ((ops.colours[i].clear >> 24) & 0xFF) * (1.0f / 255.0f);
                        colour[1] = ((ops.colours[i].clear >> 16) & 0xFF) * (1.0f / 255.0f);
                        colour[2] = ((ops.colours[i].clear >> 8) & 0xFF) * (1.0f / 255.0f);
                        colour[3] = ((ops.colours[i].clear >> 0) & 0xFF) * (1.0f / 255.0f);
                        FX_GL(ctx, glClearNamedFramebufferfv(pass->name, GL_COLOR, i, colour));
                    }
                }
                if(ops.depth.kind == FX_PASS_OP_KIND_CLEAR) {
                    FX_GL(ctx, glClearNamedFramebufferfv(pass->name, GL_DEPTH, 0, &ops.depth.clear));
                }
                if(ops.stencil.kind == FX_PASS_OP_KIND_CLEAR) {
                    FX_GL(ctx, glClearNamedFramebufferiv(pass->name, GL_STENCIL, 0, &ops.stencil.clear));
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
                fxGl45Pipeline* pipeline = FX_PTR_FROM_ID(ctx->pipelines, cmd->pipeline);
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

                    GLenum depth_op = _FX_GL45_COMPARE_FUNC[pipeline->depth_stencil.depth_op];
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
                            GL_FRONT, _FX_GL45_COMPARE_FUNC[pipeline->depth_stencil.front.op_cmp],
                            pipeline->depth_stencil.front.ref, pipeline->depth_stencil.front.mask_cmp));
                    }

                    if(ctx->cache.depth_stencil.front.op_cmp != pipeline->depth_stencil.back.op_cmp ||
                       ctx->cache.depth_stencil.back.mask_cmp != pipeline->depth_stencil.back.mask_cmp ||
                       ctx->cache.depth_stencil.back.ref != pipeline->depth_stencil.back.ref) {
                        ctx->cache.depth_stencil.back.op_cmp = pipeline->depth_stencil.back.op_cmp;
                        ctx->cache.depth_stencil.back.mask_cmp = pipeline->depth_stencil.back.mask_cmp;
                        ctx->cache.depth_stencil.back.ref = pipeline->depth_stencil.back.ref;
                        FX_GL(ctx, glStencilFuncSeparate(
                            GL_BACK, _FX_GL45_COMPARE_FUNC[pipeline->depth_stencil.back.op_cmp],
                            pipeline->depth_stencil.back.ref, pipeline->depth_stencil.back.mask_cmp));
                    }

                    if(ctx->cache.depth_stencil.front.op_fail != pipeline->depth_stencil.front.op_fail ||
                       ctx->cache.depth_stencil.front.op_pass != pipeline->depth_stencil.front.op_pass ||
                       ctx->cache.depth_stencil.front.op_depth_fail != pipeline->depth_stencil.front.op_depth_fail) {
                        ctx->cache.depth_stencil.front.op_fail = pipeline->depth_stencil.front.op_fail;
                        ctx->cache.depth_stencil.front.op_pass = pipeline->depth_stencil.front.op_pass;
                        ctx->cache.depth_stencil.front.op_depth_fail = pipeline->depth_stencil.front.op_depth_fail;
                        FX_GL(ctx, glStencilOpSeparate(
                            GL_FRONT, _FX_GL45_STENCIL_OP[pipeline->depth_stencil.front.op_fail],
                            _FX_GL45_STENCIL_OP[pipeline->depth_stencil.front.op_depth_fail],
                            _FX_GL45_STENCIL_OP[pipeline->depth_stencil.front.op_pass]));
                    }

                    if(ctx->cache.depth_stencil.back.op_fail != pipeline->depth_stencil.back.op_fail ||
                       ctx->cache.depth_stencil.back.op_pass != pipeline->depth_stencil.back.op_pass ||
                       ctx->cache.depth_stencil.back.op_depth_fail != pipeline->depth_stencil.back.op_depth_fail) {
                        ctx->cache.depth_stencil.back.op_fail = pipeline->depth_stencil.back.op_fail;
                        ctx->cache.depth_stencil.back.op_pass = pipeline->depth_stencil.back.op_pass;
                        ctx->cache.depth_stencil.back.op_depth_fail = pipeline->depth_stencil.back.op_depth_fail;
                        FX_GL(ctx, glStencilOpSeparate(
                            GL_BACK, _FX_GL45_STENCIL_OP[pipeline->depth_stencil.back.op_fail],
                            _FX_GL45_STENCIL_OP[pipeline->depth_stencil.back.op_depth_fail],
                            _FX_GL45_STENCIL_OP[pipeline->depth_stencil.back.op_pass]));
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

                    if(ctx->cache.blend.factor_src_colour != (GLenum) pipeline->blend.factor_src_colour ||
                       ctx->cache.blend.factor_dst_colour != (GLenum) pipeline->blend.factor_dst_colour ||
                       ctx->cache.blend.factor_src_alpha != (GLenum) pipeline->blend.factor_src_alpha ||
                       ctx->cache.blend.factor_dst_alpha != (GLenum) pipeline->blend.factor_dst_alpha) {
                        FX_GL(ctx, glBlendFuncSeparate(
                            _FX_GL45_BLEND_FACTOR[pipeline->blend.factor_src_colour],
                            _FX_GL45_BLEND_FACTOR[pipeline->blend.factor_dst_colour],
                            _FX_GL45_BLEND_FACTOR[pipeline->blend.factor_src_alpha],
                            _FX_GL45_BLEND_FACTOR[pipeline->blend.factor_dst_alpha]));
                    }

                    if(ctx->cache.blend.op_colour != (GLenum) pipeline->blend.op_colour ||
                       ctx->cache.blend.op_colour != (GLenum) pipeline->blend.op_colour) {
                        FX_GL(ctx, glBlendEquationSeparate(
                                    _FX_GL45_BLEND_OP[pipeline->blend.op_colour],
                                    _FX_GL45_BLEND_OP[pipeline->blend.op_alpha]));
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
                        FX_GL(ctx, glBlendColor(pipeline->blend.colour[0], pipeline->blend.colour[1], pipeline->blend.colour[2], pipeline->blend.colour[3]));
                    }

                    bool logic = pipeline->blend.flags & FX_PIPELINE_BLEND_LOGIC;
                    GLenum op_logic = _FX_GL45_LOGIC_OP[pipeline->blend.op_logic];
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

                    GLenum cull = _FX_GL45_CULL[pipeline->raster.cull];
                    if(ctx->cache.raster.cull != cull) {
                        ctx->cache.raster.cull = cull;
                        if(cull) {
                            FX_GL(ctx, glEnable(GL_CULL_FACE));
                            FX_GL(ctx, glCullFace(cull));
                        } else {
                            FX_GL(ctx, glDisable(GL_CULL_FACE));
                        }
                    }

                    GLenum winding = _FX_GL45_FRONT_FACE[pipeline->raster.winding];
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

                    if(ctx->cache.raster.fill != _FX_GL45_POLYGON[pipeline->raster.fill]) {
                        ctx->cache.raster.fill = _FX_GL45_POLYGON[pipeline->raster.fill];
                        FX_GL(ctx, glPolygonMode(GL_FRONT_AND_BACK, _FX_GL45_POLYGON[pipeline->raster.fill]));
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

                    FX_GL(ctx, glUseProgram(0));
                    FX_GL(ctx, glBindProgramPipeline(pipeline->program.name));
                }
            } break;
            case FX_CMD_KIND_BIND_VERTEX_BUFFERS: {
                fxCmdBindVertexBuffers* cmd = (fxCmdBindVertexBuffers*) raw_cmd;
                for(uint32_t i = 0; i < cmd->count; i++) {
                    fxGl45Buffer* buffer = FX_PTR_FROM_ID(ctx->buffers, cmd->vertex_buffers[i]);
                    FX_ASSERT(cmd->vertex_buffers[i] == buffer->id);
                    uint32_t name = buffer->name;
                    if(ctx->cache.binding.vertex[i] != name) {
                        ctx->cache.binding.vertex[i] = name;
                        fxGl45Pipeline* pipeline = ctx->cache.pipeline;
                        fxGl45Layout* layout = &pipeline->layouts[i];
                        FX_ASSERT(buffer->target == GL_ARRAY_BUFFER);
                        FX_GL(ctx, glBindVertexBuffer(i, name, 0, layout->stride));
                        FX_GL(ctx, glVertexBindingDivisor(i, layout->rate));
                        for(uint32_t j = 0; j < layout->count; j++) {
                            fxGl45VertexAttrib attrib = layout->attribs[j];
                            if(attrib.kind == 0) {
                                break;
                            }
                            FX_GL(ctx, glEnableVertexAttribArray((GLuint) attrib.location));
                            FX_GL(ctx, glVertexAttribFormat((GLuint) attrib.location, (GLint) attrib.count, (GLenum) attrib.kind, (GLboolean) attrib.normalised, (GLuint) attrib.offset));
                            FX_GL(ctx, glVertexAttribBinding((GLuint) attrib.location, (GLuint) attrib.binding));
                        }
                    }
                }
            } break;
            case FX_CMD_KIND_BIND_INDEX_BUFFER: {
                fxCmdBindIndexBuffer* cmd = (fxCmdBindIndexBuffer*) raw_cmd;
                fxGl45Buffer* buffer = FX_PTR_FROM_ID(ctx->buffers, cmd->index_buffer);
                FX_ASSERT(cmd->index_buffer == buffer->id);
                uint32_t name = buffer->name;
                if(ctx->cache.binding.index != name) {
                    ctx->cache.binding.index = name;
                    ctx->cache.binding.index_kind = _FX_GL45_INDEX_TYPE[cmd->index_kind];
                    FX_GL(ctx, glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, name));
                }
            } break;
            case FX_CMD_KIND_BIND_UNIFORM_BUFFER: {
                fxCmdBindUniformBuffer* cmd = (fxCmdBindUniformBuffer*) raw_cmd;
                fxGl45Buffer* buffer = FX_PTR_FROM_ID(ctx->buffers, cmd->uniform_buffer);
                FX_ASSERT(cmd->uniform_buffer == buffer->id);
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
                fxGl45Buffer* src = FX_PTR_FROM_ID(ctx->buffers, cmd->src);
                fxGl45Buffer* dst = FX_PTR_FROM_ID(ctx->buffers, cmd->dst);
                FX_ASSERT(cmd->src == src->id);
                FX_ASSERT(cmd->dst == dst->id);
                FX_GL(ctx, glCopyNamedBufferSubData(src->name, dst->name, cmd->src_offset, cmd->dst_offset, cmd->size == FX_ALL ? src->size: cmd->size));
            } break;
            case FX_CMD_KIND_BIND_TEXTURES: {
                fxCmdBindTextures* cmd = (fxCmdBindTextures*) raw_cmd;
                for(uint32_t i = 0; i < cmd->count; i++) {
                    fxGl45Texture* texture = FX_PTR_FROM_ID(ctx->textures, cmd->textures[i]);
                    FX_ASSERT(cmd->textures[i] == texture->id);
                    uint32_t name = texture->name;
                    if(ctx->cache.binding.texture[i] != name) {
                        ctx->cache.binding.texture[i] = name;
                        uint8_t unit = (cmd->units[i] == ((uint8_t) -1)) ? i: cmd->units[i];
                        FX_GL(ctx, glBindTextureUnit(unit, name));
                    }
                }
            } break;
            case FX_CMD_KIND_BIND_SAMPLERS: {
                fxCmdBindSamplers* cmd = (fxCmdBindSamplers*) raw_cmd;
                for(uint32_t i = 0; i < cmd->count; i++) {
                    fxGl45Sampler* sampler = FX_PTR_FROM_ID(ctx->samplers, cmd->samplers[i]);
                    FX_ASSERT(cmd->samplers[i] == sampler->id);
                    uint32_t name = sampler->name;
                    if(ctx->cache.binding.sampler[i] != name) {
                        ctx->cache.binding.sampler[i] = name;
                        FX_GL(ctx, glBindSampler(cmd->units[i] == ((uint8_t) -1) ? i: cmd->units[i], name));
                    }
                }
            } break;
            case FX_CMD_KIND_TEXTURE_COPY: {
                fxCmdTextureCopy* cmd = (fxCmdTextureCopy*) raw_cmd;
                fxGl45Buffer* src = FX_PTR_FROM_ID(ctx->buffers, cmd->src);
                fxGl45Buffer* dst = FX_PTR_FROM_ID(ctx->buffers, cmd->dst);
                FX_ASSERT(cmd->src == src->id);
                FX_ASSERT(cmd->dst == dst->id);
                fxTextureRegion region = cmd->region;
                FX_GL(ctx, glCopyImageSubData(
                    src->name, src->target, 0, region.src_offset.x, region.src_offset.y, region.src_offset.z, dst->name,
                    dst->target, 0, region.dst_offset.x, region.dst_offset.y, region.dst_offset.z,
                    FX_MAX(1, region.width), FX_MAX(1, region.height), FX_MAX(1, region.depth)));
            } break;
            case FX_CMD_KIND_TEXTURE_BLIT: {
                fxCmdTextureBlit* cmd = (fxCmdTextureBlit*) raw_cmd;
                fxGl45Buffer* src = FX_PTR_FROM_ID(ctx->buffers, cmd->src);
                fxGl45Buffer* dst = FX_PTR_FROM_ID(ctx->buffers, cmd->dst);
                FX_ASSERT(cmd->src == src->id);
                FX_ASSERT(cmd->dst == dst->id);
                fxTextureRegion region = cmd->region;
                FX_GL(ctx, glBlitNamedFramebuffer(
                    src->name, dst->name,
                    region.src_offset.x, region.src_offset.y, region.src_offset.x + region.width, region.src_offset.y + region.height,
                    region.dst_offset.x, region.dst_offset.y, region.dst_offset.x + region.width, region.dst_offset.y + region.height,
                    GL_COLOR_BUFFER_BIT, GL_NEAREST));
            } break;
            case FX_CMD_KIND_DRAW: {
                fxCmdDraw* cmd = (fxCmdDraw*) raw_cmd;
                FX_GL(ctx, glDrawArrays(_FX_GL45_PRIMITIVE[cmd->primitive], cmd->first_vertex, cmd->count));
            } break;
            case FX_CMD_KIND_DRAW_INDEXED: {
                fxCmdDraw* cmd = (fxCmdDraw*) raw_cmd;
                GLenum index_kind = ctx->cache.binding.index_kind;
                void* offset = (void*) ((uint64_t) cmd->first_index * (index_kind == GL_UNSIGNED_SHORT ? sizeof(uint16_t): sizeof(uint32_t)));
                FX_GL(ctx, glDrawElementsBaseVertex(_FX_GL45_PRIMITIVE[cmd->primitive], cmd->count, index_kind, offset, cmd->first_vertex));
            } break;
            case FX_CMD_KIND_DRAW_INSTANCED: {
                fxCmdDrawInstanced* cmd = (fxCmdDrawInstanced*) raw_cmd;
                FX_GL(ctx, glDrawArraysInstanced(_FX_GL45_PRIMITIVE[cmd->primitive], cmd->first_vertex, cmd->count, cmd->instance_count));
            } break;
            case FX_CMD_KIND_DRAW_INSTANCED_INDEXED: {
                fxCmdDrawInstanced* cmd = (fxCmdDrawInstanced*) raw_cmd;
                GLenum index_kind = ctx->cache.binding.index_kind;
                void* offset = (void*) ((uint64_t) cmd->first_index * (index_kind == GL_UNSIGNED_SHORT ? sizeof(uint16_t): sizeof(uint32_t)));
                FX_GL(ctx, glDrawElementsInstancedBaseVertex(_FX_GL45_PRIMITIVE[cmd->primitive], cmd->count, index_kind, offset, cmd->instance_count, cmd->first_vertex));
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
    ctx->log(ctx->usr,
        "%d:%s:%s:%s: %s\n", _FX_GL45_LINE, GL_ERROR_SOURCE[src - GL_DEBUG_SOURCE_API],
        GL_ERROR_SEVERITY[severity != GL_DEBUG_SEVERITY_NOTIFICATION ? severity - GL_DEBUG_SEVERITY_HIGH: 3],
        GL_ERROR_TYPE[type - GL_DEBUG_TYPE_ERROR], msg);
}

static void* _fx_backend(fxCfg* cfg, fxSystemInfo* info) {
    fxBackendCtx* res = (fxBackendCtx*) FX_MALLOC(sizeof(fxBackendCtx));
    FX_ASSERT(res != NULL);
    FX_MEMSET(res, 0, sizeof(fxBackendCtx));

    res->usr = cfg->usr;
    res->log = cfg->log;

#define _FX_GL45_FN_LOAD(type, ret, name, ...) res->name = (ret(*)(__VA_ARGS__)) cfg->fn_address(cfg->usr_fn_address, #name);
    _FX_GL45_FN_MAP(_FX_GL45_FN_LOAD)
#undef _FX_GL45_FN_LOAD

    FX_GL(res, glGenVertexArrays(1, &res->cache.vertex_array));
    FX_GL(res, glBindVertexArray(res->cache.vertex_array));

    if(res->glDebugMessageCallback) {
        FX_GL(res, glDebugMessageCallback(_fx_backend_debug_callback, res));
        FX_GL(res, glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE));
        FX_GL(res, glEnable(GL_DEBUG_OUTPUT));
        FX_GL(res, glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS));
    }

    res->buffer_allocator = _fx_pool_allocator(res->buffers, FX_CONFIG_BUFFER_MAX, sizeof(fxGl45Buffer));
    res->pass_allocator = _fx_pool_allocator(res->passes, FX_CONFIG_PASS_MAX, sizeof(fxGl45Pass));
    res->pipeline_allocator = _fx_pool_allocator(res->pipelines, FX_CONFIG_PIPELINE_MAX, sizeof(fxGl45Pipeline));
    res->sampler_allocator = _fx_pool_allocator(res->samplers, FX_CONFIG_TEXTURE_MAX, sizeof(fxGl45Sampler));
    res->shader_allocator = _fx_pool_allocator(res->shaders, FX_CONFIG_SHADER_MAX, sizeof(fxGl45Shader));
    res->texture_allocator = _fx_pool_allocator(res->textures, FX_CONFIG_TEXTURE_MAX, sizeof(fxGl45Texture));

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
        info->api = "fx OpenGL 4.5";
        info->version = (const char*) FX_GL(res, glGetString(GL_VERSION));
        info->device = (const char*) FX_GL(res, glGetString(GL_RENDERER));
        info->vendor = (const char*) FX_GL(res, glGetString(GL_VENDOR));
        info->shading_language = (const char*) FX_GL(res, glGetString(GL_SHADING_LANGUAGE_VERSION));
        info->texture_copy_support = true;
        info->geometry_shader_support = true;
        info->tessellation_shader_support = true;
        info->compute_shader_support = true;
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
