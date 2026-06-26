#pragma once
#include "glbox_head.h"

namespace Pengine::GL{
    typedef void (APIENTRYP PFN_OF(GLGENERATEMIPMAP))(GLenum target);
    typedef void (APIENTRYP PFN_OF(GLGENTEXTURES))(GLsizei n, GLuint* textures);
    typedef void (APIENTRYP PFN_OF(GLBINDTEXTURE))(GLenum target, GLuint texture);
    typedef void (APIENTRYP PFN_OF(GLTEXIMAGE2D))(GLenum target, GLint leve, GLint inFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* data);
    typedef void (APIENTRYP PFN_OF(GLTEXPARAMETERI))(GLenum target, GLenum pname, GLfloat param);
    typedef void (APIENTRYP PFN_OF(GLDELETETEXTURES))(GLsizei n, const GLuint* textures);
    typedef void (APIENTRYP PFN_OF(GLACTIVETEXTURE))(GLenum texture);

    extern PFN_OF(GLGENERATEMIPMAP) GenerateMipmap;
    extern PFN_OF(GLGENTEXTURES) GenTextures;
    extern PFN_OF(GLBINDTEXTURE) BindTexture;
    extern PFN_OF(GLTEXIMAGE2D) TexImage2D;
    extern PFN_OF(GLTEXPARAMETERI) TexParameteri;
    extern PFN_OF(GLDELETETEXTURES) DeleteTextures;
    extern PFN_OF(GLACTIVETEXTURE) ActiveTexture;
};