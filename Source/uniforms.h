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

    typedef void (APIENTRYP PFN_OF(GLUNIFORM1FV))(GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM2FV))(GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM3FV))(GLint location, GLsizei count, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORM4FV))(GLint location, GLsizei count, const GLfloat *value);

    typedef void (APIENTRYP PFN_OF(GLUNIFORMMATRIX2FV))(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORMMATRIX3FV))(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
    typedef void (APIENTRYP PFN_OF(GLUNIFORMMATRIX4FV))(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

    typedef GLuint  (APIENTRYP PFN_OF(GLGETUNIFORMBLOCKINDEX))  (GLuint program, const GLchar *uniformBlockName);
    typedef void    (APIENTRYP PFN_OF(GLGETACTIVEUNIFORMBLOCK)) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
    typedef GLint   (APIENTRYP PFN_OF(GLGETUNIFORMLOCATION))    (GLuint program, const GLchar *name);
    typedef void    (APIENTRYP PFN_OF(GLUNIFORMBLOCKBINDING))   (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
}
