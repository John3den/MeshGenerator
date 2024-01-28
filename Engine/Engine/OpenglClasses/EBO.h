#pragma once
#include <glad/glad.h>
#include "OpenglBuffer.h"

namespace Engine
{
    
    class EBO : public OpenglBuffer
    {
        public:
        EBO(GLuint* indices, GLsizeiptr size);
        void Bind();
        void Unbind();
        void Delete();
    };
    
}
