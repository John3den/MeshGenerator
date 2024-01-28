#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#define PI 3.1415f
#define G 1.6180f
namespace Engine
{
    const int MAX_MEMORY = 300000;
    const int VERTEX_SIZE = 6;
    
    class Geometry
    {
        public:
        void GenerateUVSphere(float radius, int definition);
        void GenerateIcosphere(float radius, int definition);
        Geometry(float radius, int def, int type);
        GLfloat vertices[MAX_MEMORY];
        GLuint indices[MAX_MEMORY];
        ~Geometry();
    };
    
}
