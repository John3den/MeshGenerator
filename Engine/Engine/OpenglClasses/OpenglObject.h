#pragma once

#include<glad/glad.h>
namespace Engine
{
    class OpenglObject
    {
        public:
        virtual GLuint GetID() const;
        
        virtual void Delete() = 0;
        protected:
        GLuint ID;
    };
}
