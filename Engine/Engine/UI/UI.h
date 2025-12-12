#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "SceneSettings.h"

namespace Engine
{
    const float UI_WIDTH = 200.0f;
    const float UI_HEIGHT = 800.0f;
    const float UI_BUTTONWIDTH = 50.0f;
    class UI
    {
        public:
        static void Init(GLFWwindow* window);
        static void CreateUIFrame();
        static void RenderAndPollUI(DrawSettings& settings);
        static void ClearUI();
        
    };
}
