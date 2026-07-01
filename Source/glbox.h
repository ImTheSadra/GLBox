#pragma once
#include "glbox_head.h"
#include "uniforms.h"
#include "textures.h"

#define GL_FUNCTIONS_LIST \
    X(GLCREATESHADER, CreateShader, "glCreateShader") \
    X(GLSHADERSOURCE, ShaderSource, "glShaderSource") \
    X(GLCOMPILESHADER, CompileShader, "glCompileShader") \
    X(GLGETSHADERIV, GetShaderiv, "glGetShaderiv") \
    X(GLGETSHADERINFOLOG, GetShaderInfoLog, "glGetShaderInfoLog") \
    X(GLDELETESHADER, DeleteShader, "glDeleteShader") \
    X(GLCREATEPROGRAM, CreateProgram, "glCreateProgram") \
    X(GLATTACHSHADER, AttachShader, "glAttachShader") \
    X(GLLINKPROGRAM, LinkProgram, "glLinkProgram") \
    X(GLGETPROGRAMIV, GetProgramiv, "glGetProgramiv") \
    X(GLGETPROGRAMINFOLOG, GetProgramInfoLog, "glGetProgramInfoLog") \
    X(GLDELETEPROGRAM, DeleteProgram, "glDeleteProgram") \
    X(GLUSEPROGRAM, UseProgram, "glUseProgram") \
    X(GLGENBUFFERS, GenBuffers, "glGenBuffers") \
    X(GLDELETEBUFFERS, DeleteBuffers, "glDeleteBuffers") \
    X(GLBINDBUFFER, BindBuffer, "glBindBuffer") \
    X(GLBINDBUFFERBASE, BindBufferBase, "glBindBufferBase") \
    X(GLBINDVERTEXARRAY, BindVertexArray, "glBindVertexArray") \
    X(GLVERTEXATTRIBIPOINTER, VertexAttribIPointer, "glVertexAttribIPointer") \
    X(GLVERTEXATTRIBLPOINTER, VertexAttribLPointer, "glVertexAttribLPointer") \
    X(GLVERTEXATTRIBPOINTER, VertexAttribPointer, "glVertexAttribPointer") \
    X(GLENABLEVERTEXATTRIBARRAY, EnableVertexAttribArray, "glEnableVertexAttribArray") \
    X(GLDELETEVERTEXARRAYS, DeleteVertexArrays, "glDeleteVertexArrays") \
    X(GLBUFFERDATA, BufferData, "glBufferData") \
    X(GLNAMEDBUFFERDATA, NamedBufferData, "glNamedBufferData") \
    X(GLGENVERTEXARRAYS, GenVertexArrays, "glGenVertexArrays") \
    X(GLBUFFERSUBDATA, BufferSubData, "glBufferSubData") \
    X(GLGENFRAMEBUFFERS, GenFrameBuffers, "glGenFramebuffers") \
    X(GLBINDFRAMEBUFFER, BindFrameBuffer, "glBindFramebuffer") \
    X(GLFRAMEBUFFERTEXTURE2D, FrameBufferTexture2D, "glFramebufferTexture2D") \
    X(GLFRAMEBUFFERRENDERBUFFER, FrameBufferRenderBuffer, "glFramebufferRenderbuffer") \
    X(GLCHECKFRAMEBUFFERSTATUS, CheckFrameBufferStatus, "glCheckFramebufferStatus") \
    X(GLDELETEFRAMEBUFFERS, DeleteFrameBuffers, "glDeleteFramebuffers") \
    X(GLGENRENDERBUFFERS, GenRenderBuffers, "glGenRenderBuffers") \
    X(GLBINDRENDERBUFFER, BindRenderBuffer, "glBindRenderbuffer") \
    X(GLRENDERBUFFERSTORAGE, RenderBufferStorage, "glRenderBufferStorage") \
    X(GLDELETERENDERBUFFERS, DeleteRenderBuffers, "glDeleteRenderbuffers") \
    X(GLGENERATEMIPMAP, GenerateMipmap, "glGenerateMipmap") \
    X(GLACTIVETEXTURE, ActiveTexture, "glActiveTexture") \
    X(GLGETUNIFORMBLOCKINDEX, GetUniformBlockIndex, "glGetUniformBlockIndex") \
    X(GLGETACTIVEUNIFORMBLOCK, GetActiveUniformBlock, "glGetActiveUniformBlockiv") \
    X(GLUNIFORMBLOCKBINDING, UniformBlockBinding, "glUniformBlockBinding") \
    X(GLUNIFORM1FV, Uniform1fv, "glUniform1fv") \
    X(GLUNIFORM2FV, Uniform2fv, "glUniform2fv") \
    X(GLUNIFORM3FV, Uniform3fv, "glUniform3fv") \
    X(GLUNIFORM4FV, Uniform4fv, "glUniform4fv") \
    X(GLUNIFORMMATRIX2FV, UniformMatrix2fv, "glUniformMatrix2fv") \
    X(GLUNIFORMMATRIX3FV, UniformMatrix3fv, "glUniformMatrix3fv") \
    X(GLUNIFORMMATRIX4FV, UniformMatrix4fv, "glUniformMatrix4fv")

namespace Pengine::GL {
#ifdef _WIN32
    typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, const int*);
    extern PFNWGLCREATECONTEXTATTRIBSARBPROC CreateContextAttribsARB;
#endif

    using PFNGLDRAWARRAYSPROC = void (APIENTRY *)(GLenum mode, GLint first, GLsizei count);
    using PFNGLDRAWELEMENTSPROC = void (APIENTRY *)(GLenum mode, GLsizei count, GLenum type, const void *indices);
    using PFNGLGENTEXTURESPROC = void (APIENTRY *)(GLsizei n, GLuint *textures);
    using PFNGLBINDTEXTUREPROC = void (APIENTRY *)(GLenum target, GLuint texture);
    using PFNGLTEXIMAGE2DPROC = void (APIENTRY *)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    using PFNGLTEXPARAMETERIPROC = void (APIENTRY *)(GLenum target, GLenum pname, GLint param);
    using PFNGLDELETETEXTURESPROC = void (APIENTRY *)(GLsizei n, const GLuint *textures);
    using PFNGLGETUNIFORMLOCATIONPROC = GLint (APIENTRY *)(GLuint program, const GLchar *name);
    using PFNGLUNIFORM1FPROC = void (APIENTRY *)(GLint location, GLfloat v0);
    using PFNGLUNIFORM2FPROC = void (APIENTRY *)(GLint location, GLfloat v0, GLfloat v1);
    using PFNGLUNIFORM3FPROC = void (APIENTRY *)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    using PFNGLUNIFORM4FPROC = void (APIENTRY *)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
    using PFNGLUNIFORM1IPROC = void (APIENTRY *)(GLint location, GLint v0);
    using PFNGLUNIFORM2IPROC = void (APIENTRY *)(GLint location, GLint v0, GLint v1);
    using PFNGLUNIFORM3IPROC = void (APIENTRY *)(GLint location, GLint v0, GLint v1, GLint v2);
    using PFNGLUNIFORM4IPROC = void (APIENTRY *)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
    using PFNGLGETINTEGERVPROC = void (APIENTRY *)(GLenum pname, GLint *data);

#define GL_CORE_FUNCTIONS_LIST \
    X(GLDRAWARRAYS, DrawArrays, "glDrawArrays") \
    X(GLDRAWELEMENTS, DrawElements, "glDrawElements") \
    X(GLGENTEXTURES, GenTextures, "glGenTextures") \
    X(GLBINDTEXTURE, BindTexture, "glBindTexture") \
    X(GLTEXIMAGE2D, TexImage2D, "glTexImage2D") \
    X(GLTEXPARAMETERI, TexParameteri, "glTexParametri") \
    X(GLDELETETEXTURES, DeleteTextures, "glDeleteTextures") \
    X(GLGETUNIFORMLOCATION, GetUniformLocation, "glGetUniformLocation") \
    X(GLUNIFORM1F, Uniform1f, "glUniform1f") \
    X(GLUNIFORM2F, Uniform2f, "glUniform2f") \
    X(GLUNIFORM3F, Uniform3f, "glUniform3f") \
    X(GLUNIFORM4F, Uniform4f, "glUniform4f") \
    X(GLUNIFORM1I, Uniform1i, "glUniform1i") \
    X(GLUNIFORM2I, Uniform2i, "glUniform2i") \
    X(GLUNIFORM3I, Uniform3i, "glUniform3i") \
    X(GLUNIFORM4I, Uniform4i, "glUniform4i") \
    X(GLGETINTEGERV, GetIntegerv, "glGetIntegerv")

#define X(type, name, str) extern PFN_OF(type) name;
    GL_FUNCTIONS_LIST
    GL_CORE_FUNCTIONS_LIST
#undef X

    extern bool loaded;
    void LoadExtensions();
}
