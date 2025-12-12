#include "pch.h"
#include "UI.h"

namespace Engine
{

    void UI::Init(GLFWwindow* window)
    {
        const char* glsl_version = "#version 420";
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        
        ImGui::StyleColorsDark();
        
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
        io.FontGlobalScale = 1;
        
        bool show_demo_window = true;
        bool show_another_window = false;
    }
    
    void UI::CreateUIFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
    
    void UI::RenderAndPollUI(DrawSettings& settings)
    {
        {
            settings.focusOnCenterFlag = false;
            static float f = 0.0f;
            static int counter = 0;
            static ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove;
            bool t = true;
            ImGui::Begin("Panel", &t, flags);
            if (ImGui::Button("Mesh generation mode", ImVec2(UI_WIDTH, UI_BUTTONWIDTH))) {
                settings.geometryType = 1 - settings.geometryType;
            }
            if (ImGui::Button("Focus on center", ImVec2(UI_WIDTH, UI_BUTTONWIDTH))) {
              settings.focusOnCenterFlag = true;
            }
            ImGui::Text(settings.geometryType == 0 ? "UV sphere" : "Icosphere");
            ImGui::SetWindowPos(ImVec2(0, 0));
            ImGui::SetWindowSize(ImVec2(UI_WIDTH, UI_HEIGHT));
            ImGui::SliderInt(" ",&settings.geometryDefinition, Engine::GEOMETRY_MINDEFINITION, Engine::GEOMETRY_MAXDEFINITION);
            ImGui::Checkbox("Show wireframe", &settings.showWireframe);
            ImGui::Checkbox("Directional lighting", &settings.directionalLighting);
            ImGui::Checkbox("Keep focus on center", &settings.keepCenteringFlag);

            ImGui::End();
        }
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    void UI::ClearUI()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
