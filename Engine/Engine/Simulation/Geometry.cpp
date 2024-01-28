#include "pch.h"
#include "framework.h"
#include "Geometry.h"
#include "iostream"
#include "Icosahedron.h"

int counter(int mode)
{
    static int count = -1;
    if (mode == 1) count = -2;
    count++;
    return count;
}
namespace Engine
{
    Geometry::Geometry(float radius, int definition)
    {
        counter(1);
        
        GenerateIcosphere(radius, definition/9);
    }
    
    Geometry::~Geometry()
    {
        
    }
    
    void Geometry::GenerateUVSphere(float radius, int definition)
    {
        int offset;
        for (int j = 0; j < definition; j++)
        for (int i = 0; i < definition; i++)
        {
            float x, y, z;
            float phi = 2 * PI * i / ((float)(definition - 1));
            float theta = j * PI / (definition - 1);
            
            x = radius * (sin(theta)) * cos(phi);
            y = radius * cos(theta);
            z = radius * (sin(theta)) * sin(phi);
            
            glm::vec3 pos(x, y, z);
            glm::vec3 normal = glm::normalize(pos);
            offset = (definition * j + i) * (VERTEX_SIZE);
            
            // VERTEX POSITION
            vertices[offset + 0] = x;
            vertices[offset + 1] = y;
            vertices[offset + 2] = z;
            //NORMAL
            vertices[offset + 3] = normal.x;
            vertices[offset + 4] = normal.y;
            vertices[offset + 5] = normal.z;
            
        }
        for (int j = 0; j < definition - 1; j++)
        {
            for (int k = 0; k < definition; k++)
            {
                offset = (j * definition + k);
                indices[offset * 6 + 0] = offset;
                indices[offset * 6 + 1] = offset + 1;
                indices[offset * 6 + 2] = offset + definition;
                
                indices[offset * 6 + 3] = offset + 1;
                indices[offset * 6 + 4] = offset + definition;
                indices[offset * 6 + 5] = offset + definition + 1;
            }
            offset = (j * definition + definition - 1) * 6;
            indices[offset + 3] = (j * definition);
            indices[offset + 4] = (j * definition) + definition;
            indices[offset + 5] = (j * definition) + definition - 1;
        }
        
    }
    
    
    
    void Geometry::GenerateIcosphere(float radius, int definition)
    {
        GLfloat* prev = new GLfloat[MAX_MEMORY];
        GLfloat* next = new GLfloat[MAX_MEMORY];
        GLfloat* buff;
        
        ICOSAHEDRON(prev,counter)
        int triangles = 20;
        for (int h = 0; h < definition; h++)
        {
            for (int j = 0; j < triangles; j++)
            {
                const int U = 72;
                const int Y = 18;
                int f = 0;
                next[U*j + f*6 +  0] = prev[Y*j + 0];
                next[U*j + f * 6 + 1] = prev[Y*j + 1];
                next[U*j + f * 6 + 2] = prev[Y*j + 2];
                
                next[U * j + f * 6 + 3] = prev[Y * j + 3];
                next[U * j + f * 6 + 4] = prev[Y * j + 4];
                next[U * j + f * 6 + 5] = prev[Y * j + 5];
                
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 0] + prev[Y * j + 6])/2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 1] + prev[Y * j + 7]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 2] + prev[Y * j + 8]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 3] + prev[Y * j + 9]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 4] + prev[Y * j + 10]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 5] + prev[Y * j + 11]) / 2;
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 0] + prev[Y * j + 12]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 1] + prev[Y * j + 13]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 2] + prev[Y * j + 14]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 3] + prev[Y * j + 15]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 4] + prev[Y * j + 16]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 5] + prev[Y * j + 17]) / 2;
                
                f++;
                next[U * j + f * 6 + 0] = prev[Y * j + 6];
                next[U * j + f * 6 + 1] = prev[Y * j + 7];
                next[U * j + f * 6 + 2] = prev[Y * j + 8];
                
                next[U * j + f * 6 + 3] = prev[Y * j + 9];
                next[U * j + f * 6 + 4] = prev[Y * j + 10];
                next[U * j + f * 6 + 5] = prev[Y * j + 11];
                
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 0] + prev[Y * j + 6]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 1] + prev[Y * j + 7]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 2] + prev[Y * j + 8]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 3] + prev[Y * j + 9]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 4] + prev[Y * j + 10]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 5] + prev[Y * j + 11]) / 2;
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 6] + prev[Y * j + 12]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 7] + prev[Y * j + 13]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 8] + prev[Y * j + 14]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 9] + prev[Y * j + 15]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 10] + prev[Y * j + 16]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 11] + prev[Y * j + 17]) / 2;
                
                f++;
                next[U * j + f * 6 + 0] = prev[Y * j + 12];
                next[U * j + f * 6 + 1] = prev[Y * j + 13];
                next[U * j + f * 6 + 2] = prev[Y * j + 14];
                
                next[U * j + f * 6 + 3] = prev[Y * j + 15];
                next[U * j + f * 6 + 4] = prev[Y * j + 16];
                next[U * j + f * 6 + 5] = prev[Y * j + 17];
                
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 0] + prev[Y * j + 12]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 1] + prev[Y * j + 13]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 2] + prev[Y * j + 14]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 3] + prev[Y * j + 15]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 4] + prev[Y * j + 16]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 5] + prev[Y * j + 17]) / 2;
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 6] + prev[Y * j + 12]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 7] + prev[Y * j + 13]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 8] + prev[Y * j + 14]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 9] + prev[Y * j + 15]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 10] + prev[Y * j + 16]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 11] + prev[Y * j + 17]) / 2;
                
                f++;
                next[U * j + f * 6 + 0] = (prev[Y * j + 0] + prev[Y * j + 6]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 1] + prev[Y * j + 7]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 2] + prev[Y * j + 8]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 3] + prev[Y * j + 9]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 4] + prev[Y * j + 10]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 5] + prev[Y * j + 11]) / 2;
                
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 0] + prev[Y * j + 12]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 1] + prev[Y * j + 13]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 2] + prev[Y * j + 14]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 3] + prev[Y * j + 15]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 4] + prev[Y * j + 16]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 5] + prev[Y * j + 17]) / 2;
                f++;
                
                next[U * j + f * 6 + 0] = (prev[Y * j + 6] + prev[Y * j + 12]) / 2;
                next[U * j + f * 6 + 1] = (prev[Y * j + 7] + prev[Y * j + 13]) / 2;
                next[U * j + f * 6 + 2] = (prev[Y * j + 8] + prev[Y * j + 14]) / 2;
                
                next[U * j + f * 6 + 3] = (prev[Y * j + 9] + prev[Y * j + 15]) / 2;
                next[U * j + f * 6 + 4] = (prev[Y * j + 10] + prev[Y * j + 16]) / 2;
                next[U * j + f * 6 + 5] = (prev[Y * j + 11] + prev[Y * j + 17]) / 2;
            }
            triangles *=12;
            buff = next;
            next = prev;
            prev = buff;
        }
        
        
        
        for (int m = 0; m*3 < MAX_MEMORY; m++)
        {			
            auto x = prev[m * 3 + 0];
            auto y = prev[m * 3 + 1];
            auto z = prev[m * 3 + 2];
            
            glm::vec3 n = glm::normalize(glm::vec3(x,y,z));
            
            vertices[m *3 +0] = n.x;
            vertices[m *3 +1] = n.y;
            vertices[m *3 +2] = n.z;
        }
        delete[] prev;
        delete[] next;
        
        
        for (int l = 0; l < 3 * triangles; l++)
        {
            indices[l] = l;
        }
        
    }
}
