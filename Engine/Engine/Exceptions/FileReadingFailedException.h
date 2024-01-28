#pragma once
#include <exception>
#include <string>

namespace Engine
{
    
    class FileReadingFailedException : public std::exception
    {
        public:
        const char* what() const;
    };
    
}
