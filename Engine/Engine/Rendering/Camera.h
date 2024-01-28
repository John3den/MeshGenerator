#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include "Renderer.h"
#include"shaderClass.h"
namespace Engine
{
    class Camera
    {
        public:
        Camera(glm::vec3 position, float FOV, float nearPlane, float farPlane);
        
        glm::vec3 GetOrientation() const;
        glm::vec3 GetDirectionUp() const;
        glm::vec3 GetPosition() const;
        bool IsCursorHidden() const;
        
        void updateMatrix();
        void Matrix(const Shader& shader, const char* uniform);
        void Inputs(GLFWwindow* window);
        
        
        private:
        const float FOVdeg;
        const float nearPlane;
        const float farPlane;
        const float defaultSpeed = 0.1f;
        const float SprintSpeed = 0.4f;
        float speed = defaultSpeed;
        float sensitivity = 100.0f;
        bool firstClick = true;
        bool cursorHidden;
        const glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 Position;
        glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::mat4 cameraMatrix = glm::mat4(1.0f);
    };
}
