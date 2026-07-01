#pragma once
#ifndef GLX_GLXEXT_PROTOTYPES
#define GLX_GLXEXT_PROTOTYPES
#endif

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/wglext.h>
#elif defined(__APPLE__)
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <dlfcn.h>
#else
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glx.h>
#include <dlfcn.h>
#endif

namespace Pengine::GL {

    #define PFN_OF(x) PFN##x##PROC

    #ifndef APIENTRYP
    #define APIENTRYP APIENTRY *
    #endif

    #ifndef GLchar
    typedef char GLchar;
    #endif

    inline void* GLoad(const char* name) {
#ifdef _WIN32
        void* p = (void*)wglGetProcAddress(name);
        if (p == nullptr || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1)) {
            static HMODULE module = GetModuleHandleA("opengl32.dll");
            p = (void*)GetProcAddress(module, name);
        }
        return p;
#elif defined(__APPLE__)
        static void* image = nullptr;
        if (image == nullptr) {
            image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY | RTLD_GLOBAL);
        }
        return image ? dlsym(image, name) : nullptr;
#else
        void* p = (void*)glXGetProcAddress((const GLubyte*)name);
        if (p == nullptr) {
            static void* libGL = nullptr;
            if (libGL == nullptr) {
                libGL = dlopen("libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
                if (libGL == nullptr) libGL = dlopen("libGL.so", RTLD_LAZY | RTLD_GLOBAL);
            }
            if (libGL) p = dlsym(libGL, name);
        }
        return p;
#endif
    }
}
