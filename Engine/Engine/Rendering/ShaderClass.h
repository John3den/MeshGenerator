#pragma once

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include "FileReadingFailedException.h"
#include "OpenglObject.h"
namespace Engine
{
    std::string get_file_contents(const char* filename);
    
    class Shader : public OpenglObject
    {
        public:
        Shader(const char* vertexFile, const char* fragmentFile);
        
        void Activate();
        void Delete();
        
        private:
        void compileErrors(unsigned int shader, const char* type);
    };
    
}
