#include "pch.h"
#include "framework.h"
#include"Camera.h"
namespace Engine
{
    Camera::Camera(glm::vec3 position, float FOV, float nearPlane, float farPlane) :
    FOVdeg(FOV),
    nearPlane(nearPlane),
    farPlane(farPlane)
    {
        Position = position;
        cursorHidden = false;
    }
    
    void Camera::updateMatrix()
    {
        glm::mat4 view = glm::lookAt(Position, Position + Orientation, Up);
        glm::mat4 projection = glm::perspective(glm::radians(FOVdeg), (float)Renderer::width / Renderer::height, nearPlane, farPlane);
        cameraMatrix = projection * view;
    }
    
    glm::vec3 Camera::GetOrientation() const
    {
        return Orientation;
    }
    
    glm::vec3 Camera::GetDirectionUp() const
    {
        return Up;
    }
    
    bool Camera::IsCursorHidden() const
    {
        return cursorHidden;
    }
    
    glm::vec3 Camera::GetPosition() const
    {
        return Position;
    }
    
    void Camera::Matrix(const Shader& shader, const char* uniform)
    {
        glUniformMatrix4fv(glGetUniformLocation(shader.GetID(), uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
    }
    
    void Camera::Inputs(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            Position += speed * Orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            Position += speed * -glm::normalize(glm::cross(Orientation, Up));
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            Position += speed * -Orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            Position += speed * glm::normalize(glm::cross(Orientation, Up));
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            Position += speed * Up;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        {
            Position += speed * -Up;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        {
            speed = 0.4f;
        }
        else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
        {
            speed = 0.1f;
        }
        
        
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            double mouseX;
            double mouseY;
            glfwGetCursorPos(window, &mouseX, &mouseY);
            if (mouseX > 200)
            {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
                cursorHidden = true;
                if (firstClick)
                {
                    glfwSetCursorPos(window, (Renderer::width / 2), (Renderer::height / 2));
                    firstClick = false;
                }
                
                
                float rotX = sensitivity * (float)(mouseY - (Renderer::height / 2)) / Renderer::height;
                float rotY = sensitivity * (float)(mouseX - (Renderer::width / 2)) / Renderer::width;
                
                glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));
                
                
                if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
                {
                    Orientation = newOrientation;
                }
                
                Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);
                
                
                glfwSetCursorPos(window, (Renderer::width / 2), (Renderer::height / 2));
            }
        }
        else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            cursorHidden = false;
            firstClick = true;
        }
    }
}
