#pragma once
#include <exception>
#include <string>

namespace Engine
{
    class FailedToCreateWindowException : public std::exception
    {
        public:
        const char* what() const;
    };
}
