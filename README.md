# Pengine::GL – OpenGL Function Loader

**Pengine::GL** is a lightweight, cross‑platform OpenGL function loader for C++.  
It defines function pointers for all core OpenGL functions (up to the version you target) and common extensions, then loads them at runtime using the platform’s native API.

- **Windows** – uses `wglGetProcAddress`
- **X11 (Linux, BSD, etc.)** – uses `glXGetProcAddress`

The loader separates declaration (`Pengine/GL.h`) from implementation – you provide the function pointer definitions and implement `LoadExtensions()`.

---

## Features

- Loads **shader & program** functions (`CreateShader`, `ShaderSource`, `LinkProgram`, …)
- Buffer & vertex array management (`GenBuffers`, `BindVertexArray`, `VertexAttribPointer`, …)
- Drawing commands (`DrawArrays`, `DrawElements`)
- Frame buffer objects (`GenFrameBuffers`, `BindFrameBuffer`, …)
- Texture & renderbuffer objects
- Uniform blocks (`GetUniformBlockIndex`, `UniformBlockBinding`)
- Context creation helper on Windows: `CreateContextAttribsARB`
- Clean, namespaced API (`Pengine::GL::`)

---

## Supported Platforms

| Platform | Macro | GL function loader      |
|----------|-------|--------------------------|
| Windows  | `_WIN32` | `wglGetProcAddress`     |
| X11      | `_X11`   | `glXGetProcAddress`     |

> ⚠️ The loader does **not** create an OpenGL context. You must create a valid context before calling `Pengine::GL::LoadExtensions()`!.

---

## Usage

```cpp
#include "Pengine/GL.h"

auto ctx = SomeWayToCreateContext();
Pengine::GL::LoadExtensions();
if(!Pengine::GL::loaded){
    //handle the error here
}
```