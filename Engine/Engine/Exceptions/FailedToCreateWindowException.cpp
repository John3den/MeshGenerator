#include "pch.h"
#include "FailedToCreateWindowException.h"

namespace Engine
{
    const char* FailedToCreateWindowException::what() const
    {
        return "Window creation failed";
    }
}
