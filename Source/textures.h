#pragma once
#include "glbox_head.h"

namespace Pengine::GL {
    typedef void (APIENTRYP PFN_OF(GLGENERATEMIPMAP))(GLenum target);
    typedef void (APIENTRYP PFN_OF(GLGENTEXTURES))(GLsizei n, GLuint* textures);
    typedef void (APIENTRYP PFN_OF(GLBINDTEXTURE))(GLenum target, GLuint texture);
    typedef void (APIENTRYP PFN_OF(GLTEXIMAGE2D))(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
    typedef void (APIENTRYP PFN_OF(GLTEXPARAMETERI))(GLenum target, GLenum pname, GLint param);
    typedef void (APIENTRYP PFN_OF(GLDELETETEXTURES))(GLsizei n, const GLuint* textures);
    typedef void (APIENTRYP PFN_OF(GLACTIVETEXTURE))(GLenum texture);
}
