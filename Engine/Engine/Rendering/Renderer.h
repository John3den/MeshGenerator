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
#include "SceneSettings.h"
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
        void RenderFrame(Scene& scene);
        void Destroy();
        void InitUI(GLFWwindow* window);
        const DrawSettings& const GetSettings() const;
        
        static const unsigned int width = 800;
        static const unsigned int height = 800;
        
        private:
        std::shared_ptr<Shader> phongLightingShader;
        DrawSettings settings;
        void ActivateShader();
        void Clear();
        void Frame(Scene& scene);
        void Draw(const Scene& scene);
    };
}
