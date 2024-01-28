#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
namespace Engine
{
    class UI
    {
        public:
        static void Init(GLFWwindow* window);
        static void CreateUIFrame();
        static void RenderUI(int& lightingType);
        static void ClearUI();
        
    };
}
