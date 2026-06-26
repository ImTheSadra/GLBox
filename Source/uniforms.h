#pragma once
#include "glbox_head.h"

namespace Pengine::GL {
    typedef void (APIENTRYP PFN_OF(GLUNIFORM1F))(GLint location, GLfloat v0);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM2F))(GLint location, GLfloat v0, GLfloat v1);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM3F))(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM4F))(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);

    typedef void (APIENTRYP PFN_OF(GLUNIFORM1I))(GLint location, GLint v0);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM2I))(GLint location, GLint v0, GLint v1);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM3I))(GLint location, GLint v0, GLint v1, GLint v2);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM4I))(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);

    typedef void (APIENTRYP PFN_OF(GLUNIFORMMATRIX2FV))(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORMMATRIX3FV))(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORMMATRIX4FV))(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

    typedef GLuint  (APIENTRYP PFN_OF(GLGETUNIFORMBLOCKINDEX))  (GLuint program, const GLchar *uniformBlockName);
    typedef GLuint  (APIENTRYP PFN_OF(GLGETACTIVEUNIFORMBLOCK)) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    typedef GLint   (APIENTRYP PFN_OF(GLGETUNIFORMLOCATION))    (GLuint program, const GLchar *name);
    typedef void    (APIENTRYP PFN_OF(GLUNIFORMBLOCKBINDING))   (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

    extern PFN_OF(GLUNIFORM1F) Uniform1f;
    extern PFN_OF(GLUNIFORM2F) Uniform2f;
    extern PFN_OF(GLUNIFORM3F) Uniform3f;
    extern PFN_OF(GLUNIFORM4F) Uniform4f;

    extern PFN_OF(GLUNIFORM1I) Uniform1i;
    extern PFN_OF(GLUNIFORM2I) Uniform2i;
    extern PFN_OF(GLUNIFORM3I) Uniform3i;
    extern PFN_OF(GLUNIFORM4I) Uniform4i;

    extern PFN_OF(GLUNIFORMMATRIX2FV) UniformMatrix2fv;
    extern PFN_OF(GLUNIFORMMATRIX3FV) UniformMatrix3fv;
    extern PFN_OF(GLUNIFORMMATRIX4FV) UniformMatrix4fv;

    extern PFN_OF(GLGETUNIFORMBLOCKINDEX)   GetUniformBlockIndex;
    extern PFN_OF(GLGETACTIVEUNIFORMBLOCK)  GetActiveUniformBlock;
    extern PFN_OF(GLGETUNIFORMLOCATION)     GetUnifromLocation;
    extern PFN_OF(GLUNIFORMBLOCKBINDING)    UniformBlockBinding;
}