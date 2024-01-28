#pragma once

#include<glad/glad.h>
#include"VBO.h"
namespace Engine
{
    class VAO : public OpenglBuffer
    {
        public:
        VAO();
        void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
        void Bind();
        void Unbind();
        void Delete();
    };
}
