#pragma once
#ifndef GLX_GLXEXT_PROTOTYPES
#define GLX_GLXEXT_PROTOTYPES
#endif
#include <GL/gl.h>

#ifdef _X11
#include <GL/glx.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <GL/wglext.h>
#include <GL/glext.h>
#endif

namespace Pengine::GL {

    #ifdef _X11
    #define PFN_OF(x) PFN##x
    #endif
    #ifdef _WIN32
    #define PFN_OF(x) PFN##x##PROC
    #endif

    #ifndef APIENTRYP
    #define APIENTRYP APIENTRY *
    #endif

    #ifndef GLchar
    typedef char GLchar;
    #endif

    typedef GLuint (APIENTRYP PFN_OF(GLCREATESHADER))(GLenum shaderType);
    typedef void (APIENTRYP PFN_OF(GLSHADERSOURCE))(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
    typedef void (APIENTRYP PFN_OF(GLCOMPILESHADER))(GLuint shader);
    typedef void (APIENTRYP PFN_OF(GLGETSHADERIV))(GLuint shader, GLenum pname, GLint* params);
    typedef void (APIENTRYP PFN_OF(GLGETSHADERINFOLOG))(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
    typedef void (APIENTRYP PFN_OF(GLDELETESHADER))(GLuint shader);

    typedef GLuint (APIENTRYP PFN_OF(GLCREATEPROGRAM))();
    typedef void (APIENTRYP PFN_OF(GLATTACHSHADER))(GLuint program, GLuint shader);
    typedef void (APIENTRYP PFN_OF(GLLINKPROGRAM))(GLuint program);
    typedef void (APIENTRYP PFN_OF(GLGETPROGRAMIV))(GLuint program, GLenum pname, GLint* params);
    typedef void (APIENTRYP PFN_OF(GLGETPROGRAMINFOLOG))(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
    typedef void (APIENTRYP PFN_OF(GLDELETEPROGRAM))(GLuint program);
    typedef void (APIENTRYP PFN_OF(GLUSEPROGRAM))(GLuint program);

    typedef GLuint (APIENTRYP PFN_OF(GLGENBUFFERS))(GLsizei n, GLuint* buffers);
    typedef void (APIENTRYP PFN_OF(GLDELETEBUFFERS))(GLsizei size, const GLuint* arrays);
    typedef void (APIENTRYP PFN_OF(GLBINDBUFFER))(GLenum target, GLuint buffer);
    typedef void (APIENTRYP PFN_OF(GLBINDVERTEXARRAY))(GLuint array);
    typedef void (APIENTRYP PFN_OF(GLBINDBUFFERBASE))(GLenum target, GLuint index, GLuint buffer);
    typedef void (APIENTRYP PFN_OF(GLVERTEXATTRIBIPOINTER))(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
    typedef void (APIENTRYP PFN_OF(GLVERTEXATTRIBLPOINTER))(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
    typedef void (APIENTRYP PFN_OF(GLVERTEXATTRIBPOINTER))(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);
    typedef void (APIENTRYP PFN_OF(GLENABLEVERTEXATTRIBARRAY))(GLuint index);
    typedef void (APIENTRYP PFN_OF(GLDELETEVERTEXARRAYS))(GLsizei size, const GLuint* arrays);
    typedef void (APIENTRYP PFN_OF(GLBUFFERDATA))(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
    typedef void (APIENTRYP PFN_OF(GLNAMEDBUFFERDATA))(GLuint buffer, GLsizei size, const void* data, GLenum usage);
    typedef GLuint (APIENTRYP PFN_OF(GLGENVERTEXARRAYS))(GLsizei n, GLuint* arrays);
    typedef void (APIENTRYP PFN_OF(GLBUFFERSUBDATA))(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
    typedef void (APIENTRYP PFN_OF(GLDRAWARRAYS))(GLenum mode, GLint first, GLsizei count);
    typedef void (APIENTRYP PFN_OF(GLDRAWELEMENTS))(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);

    typedef void (APIENTRYP PFN_OF(GLGENFRAMEBUFFERS))(GLsizei n, GLuint* buffers);
    typedef void (APIENTRYP PFN_OF(GLBINDFRAMEBUFFER))(GLenum target, GLuint buffer);
    typedef void (APIENTRYP PFN_OF(GLFRAMEBUFFERTEXTURE2D))(GLenum target, GLenum attachment, GLenum textargt, GLuint texture, GLint level);
    typedef void (APIENTRYP PFN_OF(GLFRAMEBUFFERRENDERBUFFER))(GLenum target, GLenum attachment, GLenum renderTarget, GLuint renderbuffer);
    typedef GLenum (APIENTRYP PFN_OF(GLCHECKFRAMEBUFFERSTATUS))(GLenum target);
    typedef void (APIENTRYP PFN_OF(GLDELETEFRAMEBUFFERS))(GLsizei n, const GLuint* textures);

    typedef void (APIENTRYP PFN_OF(GLGENTEXTURES))(GLsizei n, GLuint* textures);
    typedef void (APIENTRYP PFN_OF(GLBINDTEXTURE))(GLenum target, GLuint texture);
    typedef void (APIENTRYP PFN_OF(GLTEXIMAGE2D))(GLenum target, GLint leve, GLint inFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data);
    typedef void (APIENTRYP PFN_OF(GLTEXPARAMETERI))(GLenum target, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFN_OF(GLDELETETEXTURES))(GLsizei n, const GLuint* textures);

    typedef void (APIENTRYP PFN_OF(GLGENRENDERBUFFERS))(GLsizei n, GLuint* buffers);
    typedef void (APIENTRYP PFN_OF(GLBINDRENDERBUFFER))(GLenum target, GLuint buffer);
    typedef void (APIENTRYP PFN_OF(GLRENDERBUFFERSTORAGE))(GLenum target, GLenum inFormat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFN_OF(GLDELETERENDERBUFFERS))(GLsizei n, const GLuint* textures);

    typedef GLuint (APIENTRYP PFN_OF(GLGETUNIFORMBLOCKINDEX))(GLuint program, const GLchar *uniformBlockName);
    typedef GLuint (APIENTRYP PFN_OF(GLGETACTIVEUNIFORMBLOCK))(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    typedef void (APIENTRYP PFN_OF(GLGETUNIFORMLOCATION))(GLuint program, const GLchar *name);
    typedef void (APIENTRYP PFN_OF(GLUNIFORMBLOCKBINDING))(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

    typedef void (APIENTRYP PFN_OF(GLGETINTEGERV))(GLenum what, GLuint* data);

    #ifdef _WIN32
    typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, const int*);
    #endif

    extern PFN_OF(GLCREATESHADER) CreateShader;
    extern PFN_OF(GLSHADERSOURCE) ShaderSource;
    extern PFN_OF(GLCOMPILESHADER) CompileShader;
    extern PFN_OF(GLGETSHADERIV) GetShaderiv;
    extern PFN_OF(GLGETSHADERINFOLOG) GetShaderInfoLog;
    extern PFN_OF(GLDELETESHADER) DeleteShader;
    
    extern PFN_OF(GLCREATEPROGRAM) CreateProgram;
    extern PFN_OF(GLATTACHSHADER) AttachShader;
    extern PFN_OF(GLLINKPROGRAM) LinkProgram;
    extern PFN_OF(GLGETPROGRAMIV) GetProgramiv;
    extern PFN_OF(GLGETPROGRAMINFOLOG) GetProgramInfoLog;
    extern PFN_OF(GLDELETEPROGRAM) DeleteProgram;
    extern PFN_OF(GLUSEPROGRAM) UseProgram;

    extern PFN_OF(GLGENBUFFERS) GenBuffers;
    extern PFN_OF(GLDELETEBUFFERS) DeleteBuffers;
    extern PFN_OF(GLBINDBUFFER) BindBuffer;
    extern PFN_OF(GLBINDBUFFERBASE) BindBufferBase;
    extern PFN_OF(GLBINDVERTEXARRAY) BindVertexArray;
    extern PFN_OF(GLVERTEXATTRIBIPOINTER) VertexAttribIPointer;
    extern PFN_OF(GLVERTEXATTRIBLPOINTER) VertexAttribLPointer;
    extern PFN_OF(GLVERTEXATTRIBPOINTER) VertexAttribPointer;
    extern PFN_OF(GLENABLEVERTEXATTRIBARRAY) EnableVertexAttribArray;
    extern PFN_OF(GLDELETEVERTEXARRAYS) DeleteVertexArrays;
    extern PFN_OF(GLBUFFERDATA) BufferData;
    extern PFN_OF(GLNAMEDBUFFERDATA) NamedBufferData;
    extern PFN_OF(GLGENVERTEXARRAYS) GenVertexArrays;
    extern PFN_OF(GLBUFFERSUBDATA) BufferSubData;

    extern PFN_OF(GLDRAWARRAYS) DrawArrays;
    extern PFN_OF(GLDRAWELEMENTS) DrawElements;

    extern PFN_OF(GLGENFRAMEBUFFERS) GenFrameBuffers;
    extern PFN_OF(GLBINDFRAMEBUFFER) BindFrameBuffer;
    extern PFN_OF(GLFRAMEBUFFERTEXTURE2D) FrameBufferTexture2D;
    extern PFN_OF(GLFRAMEBUFFERRENDERBUFFER) FrameBufferRenderBuffer;
    extern PFN_OF(GLCHECKFRAMEBUFFERSTATUS) CheckFrameBufferStatus;
    extern PFN_OF(GLDELETEFRAMEBUFFERS) DeleteFrameBuffers;

    extern PFN_OF(GLGENTEXTURES) GenTextures;
    extern PFN_OF(GLBINDTEXTURE) BindTexture;
    extern PFN_OF(GLTEXIMAGE2D) TexImage2D;
    extern PFN_OF(GLTEXPARAMETERI) TexParameteri;
    extern PFN_OF(GLDELETETEXTURES) DeleteTextures;

    extern PFN_OF(GLGENRENDERBUFFERS) GenRenderBuffers;
    extern PFN_OF(GLBINDRENDERBUFFER) BindRenderBuffer;
    extern PFN_OF(GLRENDERBUFFERSTORAGE) RenderBufferStorage;
    extern PFN_OF(GLDELETERENDERBUFFERS) DeleteRenderBuffers;

    extern PFN_OF(GLGETUNIFORMBLOCKINDEX) GetUniformBlockIndex;
    extern PFN_OF(GLGETACTIVEUNIFORMBLOCK) GetActiveUniformBlock;
    extern PFN_OF(GLGETUNIFORMLOCATION) GetUnifromLocation;
    extern PFN_OF(GLUNIFORMBLOCKBINDING) UniformBlockBinding;

    extern PFN_OF(GLGETINTEGERV) GetIntegerv;
    extern bool loaded;

    #ifdef _WIN32
    extern PFNWGLCREATECONTEXTATTRIBSARBPROC CreateContextAttribsARB;
    #endif
    
    void LoadExtensions();
}

#ifdef _WIN32
#define GLoad(name) wglGetProcAddress(name) 
#endif

#ifdef _X11
#define GLoad(name) glXGetProcAddress((const GLubyte*)name)
#endif