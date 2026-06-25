#include "glbox.h"

namespace Pengine::GL {
    PFN_OF(GLCREATESHADER) CreateShader = nullptr;
    PFN_OF(GLSHADERSOURCE) ShaderSource = nullptr;
    PFN_OF(GLCOMPILESHADER) CompileShader = nullptr;
    PFN_OF(GLGETSHADERIV) GetShaderiv = nullptr;
    PFN_OF(GLGETSHADERINFOLOG) GetShaderInfoLog = nullptr;
    PFN_OF(GLDELETESHADER) DeleteShader = nullptr;
    
    PFN_OF(GLCREATEPROGRAM) CreateProgram = nullptr;
    PFN_OF(GLATTACHSHADER) AttachShader = nullptr;
    PFN_OF(GLLINKPROGRAM) LinkProgram = nullptr;
    PFN_OF(GLGETPROGRAMIV) GetProgramiv = nullptr;
    PFN_OF(GLGETPROGRAMINFOLOG) GetProgramInfoLog = nullptr;
    PFN_OF(GLDELETEPROGRAM) DeleteProgram = nullptr;
    PFN_OF(GLUSEPROGRAM) UseProgram = nullptr;

    PFN_OF(GLGENBUFFERS) GenBuffers = nullptr;
    PFN_OF(GLDELETEBUFFERS) DeleteBuffers = nullptr;
    PFN_OF(GLBINDBUFFER) BindBuffer = nullptr;
    PFN_OF(GLBINDBUFFERBASE) BindBufferBase = nullptr;
    PFN_OF(GLVERTEXATTRIBPOINTER) VertexAttribPointer = nullptr;
    PFN_OF(GLVERTEXATTRIBIPOINTER) VertexAttribIPointer = nullptr;
    PFN_OF(GLVERTEXATTRIBLPOINTER) VertexAttribLPointer = nullptr;
    PFN_OF(GLENABLEVERTEXATTRIBARRAY) EnableVertexAttribArray = nullptr;
    PFN_OF(GLDELETEVERTEXARRAYS) DeleteVertexArrays = nullptr;
    PFN_OF(GLBUFFERDATA) BufferData = nullptr;
    PFN_OF(GLNAMEDBUFFERDATA) NamedBufferData = nullptr;
    PFN_OF(GLGENVERTEXARRAYS) GenVertexArrays = nullptr;
    PFN_OF(GLBINDVERTEXARRAY) BindVertexArray = nullptr;
    PFN_OF(GLBUFFERSUBDATA) BufferSubData = nullptr;

    PFN_OF(GLDRAWARRAYS) DrawArrays = nullptr;
    PFN_OF(GLDRAWELEMENTS) DrawElements = nullptr;

    PFN_OF(GLGENFRAMEBUFFERS) GenFrameBuffers = nullptr;
    PFN_OF(GLBINDFRAMEBUFFER) BindFrameBuffer = nullptr;
    PFN_OF(GLFRAMEBUFFERTEXTURE2D) FrameBufferTexture2D = nullptr;
    PFN_OF(GLFRAMEBUFFERRENDERBUFFER) FrameBufferRenderBuffer = nullptr;
    PFN_OF(GLCHECKFRAMEBUFFERSTATUS) CheckFrameBufferStatus = nullptr;
    PFN_OF(GLDELETEFRAMEBUFFERS) DeleteFrameBuffers = nullptr;

    PFN_OF(GLGENTEXTURES) GenTextures = nullptr;
    PFN_OF(GLBINDTEXTURE) BindTexture = nullptr;
    PFN_OF(GLTEXIMAGE2D) TexImage2D = nullptr;
    PFN_OF(GLTEXPARAMETERI) TexParameteri = nullptr;
    PFN_OF(GLDELETETEXTURES) DeleteTextures = nullptr;

    PFN_OF(GLGENRENDERBUFFERS) GenRenderBuffers = nullptr;
    PFN_OF(GLBINDRENDERBUFFER) BindRenderBuffer = nullptr;
    PFN_OF(GLRENDERBUFFERSTORAGE) RenderBufferStorage = nullptr;
    PFN_OF(GLDELETERENDERBUFFERS) DeleteRenderBuffers = nullptr;

    PFN_OF(GLGETUNIFORMBLOCKINDEX) GetUniformBlockIndex = nullptr;
    PFN_OF(GLGETACTIVEUNIFORMBLOCK) GetActiveUniformBlock = nullptr;
    PFN_OF(GLGETUNIFORMLOCATION) GetUnifromLocation = nullptr;
    PFN_OF(GLUNIFORMBLOCKBINDING) UniformBlockBinding = nullptr;

    PFN_OF(GLGETINTEGERV) GetIntegerv = nullptr;

    bool loaded = false;

    #ifdef _WIN32
    PFNWGLCREATECONTEXTATTRIBSARBPROC CreateContextAttribsARB = nullptr;
    #endif

    void LoadExtensions() {
        CreateShader                = (PFN_OF(GLCREATESHADER))              GLoad("glCreateShader");
        ShaderSource                = (PFN_OF(GLSHADERSOURCE))              GLoad("glShaderSource");
        CompileShader               = (PFN_OF(GLCOMPILESHADER))             GLoad("glCompileShader");
        GetShaderiv                 = (PFN_OF(GLGETSHADERIV))               GLoad("glGetShaderiv");
        GetShaderInfoLog            = (PFN_OF(GLGETSHADERINFOLOG))          GLoad("glGetShaderInfoLog");
        DeleteShader                = (PFN_OF(GLDELETESHADER))              GLoad("glDeleteShader");
        
        CreateProgram               = (PFN_OF(GLCREATEPROGRAM))             GLoad("glCreateProgram");
        AttachShader                = (PFN_OF(GLATTACHSHADER))              GLoad("glAttachShader");
        LinkProgram                 = (PFN_OF(GLLINKPROGRAM))               GLoad("glLinkProgram");
        GetProgramiv                = (PFN_OF(GLGETPROGRAMIV))              GLoad("glGetProgramiv");
        GetProgramInfoLog           = (PFN_OF(GLGETPROGRAMINFOLOG))         GLoad("glGetProgramInfoLog");
        DeleteProgram               = (PFN_OF(GLDELETEPROGRAM))             GLoad("glDeleteProgram");
        UseProgram                  = (PFN_OF(GLUSEPROGRAM))                GLoad("glUseProgram");

        GenBuffers                  = (PFN_OF(GLGENBUFFERS))                GLoad("glGenBuffers");
        DeleteBuffers               = (PFN_OF(GLDELETEBUFFERS))             GLoad("glDeleteBuffers");
        BindBuffer                  = (PFN_OF(GLBINDBUFFER))                GLoad("glBindBuffer");
        BindBufferBase              = (PFN_OF(GLBINDBUFFERBASE))            GLoad("glBindBufferBase");
        VertexAttribPointer         = (PFN_OF(GLVERTEXATTRIBPOINTER))       GLoad("glVertexAttribPointer");
        VertexAttribIPointer        = (PFN_OF(GLVERTEXATTRIBIPOINTER))      GLoad("glVertexAttribIPointer");
        VertexAttribLPointer        = (PFN_OF(GLVERTEXATTRIBLPOINTER))      GLoad("glVertexAttribLPointer");
        EnableVertexAttribArray     = (PFN_OF(GLENABLEVERTEXATTRIBARRAY))   GLoad("glEnableVertexAttribArray");
        DeleteVertexArrays          = (PFN_OF(GLDELETEVERTEXARRAYS))        GLoad("glDeleteVertexArrays");
        BufferData                  = (PFN_OF(GLBUFFERDATA))                GLoad("glBufferData");
        NamedBufferData             = (PFN_OF(GLNAMEDBUFFERDATA))           GLoad("glNamedBufferData");
        GenVertexArrays             = (PFN_OF(GLGENVERTEXARRAYS))           GLoad("glGenVertexArrays");
        BindVertexArray             = (PFN_OF(GLBINDVERTEXARRAY))           GLoad("glBindVertexArray");
        BufferSubData               = (PFN_OF(GLBUFFERSUBDATA))             GLoad("glBufferSubData");
        
        DrawArrays                  = (PFN_OF(GLDRAWARRAYS))                GLoad("glDrawArrays");
        DrawElements                = (PFN_OF(GLDRAWELEMENTS))              GLoad("glDrawElements");

        GenFrameBuffers             = (PFN_OF(GLGENFRAMEBUFFERS))           GLoad("glGenFramebuffers");
        BindFrameBuffer             = (PFN_OF(GLBINDFRAMEBUFFER))           GLoad("glBindFramebuffer");
        FrameBufferTexture2D        = (PFN_OF(GLFRAMEBUFFERTEXTURE2D))      GLoad("glFramebufferTexture2D");
        FrameBufferRenderBuffer     = (PFN_OF(GLFRAMEBUFFERRENDERBUFFER))   GLoad("glFramebufferRenderbuffer");
        CheckFrameBufferStatus      = (PFN_OF(GLCHECKFRAMEBUFFERSTATUS))    GLoad("glCheckFramebufferStatus");
        DeleteFrameBuffers          = (PFN_OF(GLDELETEFRAMEBUFFERS))        GLoad("glDeleteFramebuffers");

        GenTextures                 = (PFN_OF(GLGENTEXTURES))               GLoad("glGenTextures");
        BindTexture                 = (PFN_OF(GLBINDTEXTURE))               GLoad("glBindTexture");
        TexImage2D                  = (PFN_OF(GLTEXIMAGE2D))                GLoad("glTexImage2D");
        TexParameteri               = (PFN_OF(GLTEXPARAMETERI))             GLoad("glTexParametri");
        DeleteTextures              = (PFN_OF(GLDELETETEXTURES))            GLoad("glDeleteTextures");

        GenRenderBuffers            = (PFN_OF(GLGENRENDERBUFFERS))          GLoad("glGenRenderBuffers");
        BindRenderBuffer            = (PFN_OF(GLBINDRENDERBUFFER))          GLoad("glBindRenderBuffers");
        RenderBufferStorage         = (PFN_OF(GLRENDERBUFFERSTORAGE))       GLoad("glRenderBufferStorage");
        DeleteRenderBuffers         = (PFN_OF(GLDELETERENDERBUFFERS))       GLoad("glDeleteRenderbuffers");
        
        GetUniformBlockIndex        = (PFN_OF(GLGETUNIFORMBLOCKINDEX))      GLoad("glGetUniformBlockIndex");
        GetActiveUniformBlock       = (PFN_OF(GLGETACTIVEUNIFORMBLOCK))     GLoad("glGetActiveUniformBlockiv");
        GetUnifromLocation          = (PFN_OF(GLGETUNIFORMLOCATION))        GLoad("glGetUniformLocation");
        UniformBlockBinding         = (PFN_OF(GLUNIFORMBLOCKBINDING))       GLoad("glUniformBlockBinding");

        GetIntegerv                 = (PFN_OF(GLGETINTEGERV))               GLoad("glGetIntegerv");

        loaded = true;

        #ifdef _WIN32
        CreateContextAttribsARB     = (PFNWGLCREATECONTEXTATTRIBSARBPROC)   GLoad("wglCreateContextAttribsARB");
        #endif
    }
}