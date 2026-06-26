#pragma once
#include "glbox_head.h"
#include "uniforms.h"
#include "textures.h"

namespace Pengine::GL {
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

    typedef void (APIENTRYP PFN_OF(GLGENRENDERBUFFERS))(GLsizei n, GLuint* buffers);
    typedef void (APIENTRYP PFN_OF(GLBINDRENDERBUFFER))(GLenum target, GLuint buffer);
    typedef void (APIENTRYP PFN_OF(GLRENDERBUFFERSTORAGE))(GLenum target, GLenum inFormat, GLsizei width, GLsizei height);
    typedef void (APIENTRYP PFN_OF(GLDELETERENDERBUFFERS))(GLsizei n, const GLuint* textures);

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

    

    extern PFN_OF(GLGENRENDERBUFFERS) GenRenderBuffers;
    extern PFN_OF(GLBINDRENDERBUFFER) BindRenderBuffer;
    extern PFN_OF(GLRENDERBUFFERSTORAGE) RenderBufferStorage;
    extern PFN_OF(GLDELETERENDERBUFFERS) DeleteRenderBuffers;

    extern PFN_OF(GLGETINTEGERV) GetIntegerv;
    extern bool loaded;

    #ifdef _WIN32
    extern PFNWGLCREATECONTEXTATTRIBSARBPROC CreateContextAttribsARB;
    #endif
    
    void LoadExtensions();
}