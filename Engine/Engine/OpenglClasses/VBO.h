#pragma once

#include <glad/glad.h>
#include "OpenglBuffer.h"
namespace Engine
{
    class VBO : public OpenglBuffer
    {
        public:
        VBO(GLfloat* vertices, GLsizeiptr size);
        void Bind();
        void Unbind();
        void Delete();
    };
}
