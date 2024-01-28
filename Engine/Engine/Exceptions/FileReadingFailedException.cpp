#include "pch.h"
#include "FileReadingFailedException.h"

namespace Engine
{
    const char* FileReadingFailedException::what() const
    {
        return "File reading failed";
    }
}
