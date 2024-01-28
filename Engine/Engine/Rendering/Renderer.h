#pragma once
#include <memory>
#include "ShaderClass.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "UI.h"
#include "Scene.h"
#include "FailedToCreateWindowException.h"

namespace Engine
{
    class Scene;
    
    class Renderer
    {
        public:
        Renderer();

        const std::shared_ptr<Shader> GetLightShader() const;
        
        static GLFWwindow* Init();
        void NewFrame();
        void RenderFrame(const Scene& scene);
        void Destroy();
        void InitUI(GLFWwindow* window);
        int GetDefinition() const;
        int geometryType = 0;
        static const unsigned int width = 800;
        static const unsigned int height = 800;
        
        private:
        std::shared_ptr<Shader> phong;
        
        int geometryDefinition = 5;

        
        void ActivateShader();
        void Clear();
        void Frame(const Scene& scene);
        void Draw(const Scene& scene);
    };
}
