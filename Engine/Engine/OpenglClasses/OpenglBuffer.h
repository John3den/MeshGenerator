#pragma once

#include <glad/glad.h>
#include "OpenglObject.h"
namespace Engine
{
    class OpenglBuffer : public OpenglObject
    {
        public:
        virtual void Bind() = 0;
        virtual void Unbind() = 0;
    };
}
