#include "glbox.h"

namespace Pengine::GL {
#ifdef _WIN32
    PFNWGLCREATECONTEXTATTRIBSARBPROC CreateContextAttribsARB = nullptr;
#endif

#define X(type, name, str) PFN_OF(type) name = nullptr;
    GL_FUNCTIONS_LIST
    GL_CORE_FUNCTIONS_LIST
#undef X

    bool loaded = false;

    void LoadExtensions() {
        if (loaded) return;

#define X(type, name, str) name = (PFN_OF(type))GLoad(str);
        GL_FUNCTIONS_LIST
        GL_CORE_FUNCTIONS_LIST
#undef X

#ifdef _WIN32
        CreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)GLoad("wglCreateContextAttribsARB");
#endif
        loaded = true;
    }
}
