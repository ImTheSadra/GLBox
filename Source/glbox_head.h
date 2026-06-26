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

    #ifdef _WIN32
    #define PFN_OF(x) PFN##x##PROC
    #else
    #define PFN_OF(x) PFN##x
    #endif

    #ifndef APIENTRYP
    #define APIENTRYP APIENTRY *
    #endif

    #ifndef GLchar
    typedef char GLchar;
    #endif
}

#ifdef _WIN32
#define GLoad(name) wglGetProcAddress(name) 
#else
#define GLoad(name) glXGetProcAddress((const GLubyte*)name)
#endif