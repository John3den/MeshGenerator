#include "pch.h"
#include "framework.h"
#include "Renderer.h"
namespace Engine
{
    
    void Renderer::Draw(const Scene& scene)
    {
        glm::vec3 position;
        glm::mat4 model;
        position = glm::vec3();
        model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        //bind textures, buffers, normal maps and make a drawcall
        glUniform1i(glGetUniformLocation((*GetLightShader()).GetID(), "useLighting"), settings.directionalLighting ? 1 : 0);
        glUniformMatrix4fv(glGetUniformLocation((*GetLightShader()).GetID(), "model"), 1, 
                                                GL_FALSE, glm::value_ptr(model));
        scene.GetCamera()->SendCameraMatrixToUniform((*GetLightShader()));
        scene.GetVAO(0).Bind();
        glDrawElements(GL_TRIANGLES, sizeof(scene.GetGeometry(0).indices) / sizeof(int), 
                       GL_UNSIGNED_INT, 0);
    }
    
    void Renderer::Destroy()
    {
        UI::ClearUI();
        GetLightShader()->Delete();
    }
    void Renderer::Clear()
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void Renderer::ActivateShader()
    {
        (*GetLightShader()).Activate();
    }
    
    GLFWwindow* Renderer::Init()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        GLFWwindow* window = glfwCreateWindow(width, height, "Mesh Generator", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            throw FailedToCreateWindowException();
        }
        glfwMakeContextCurrent(window);
        gladLoadGL();
        glViewport(0, 0, width, height);
        return window;
    }
    
    Renderer::Renderer() :
    phongLightingShader(new Shader("shaders/default.vert", "shaders/default.frag"))
    {
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 10.0f);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        
        phongLightingShader->Activate();

        glUniformMatrix4fv(glGetUniformLocation(phongLightingShader->GetID(), "model"), 1, 
                                                GL_FALSE, glm::value_ptr(model));
        glEnable(GL_DEPTH_TEST);
    }
    
    const std::shared_ptr<Shader> Renderer::GetLightShader() const
    {
        return phongLightingShader;
    }
    void Renderer::Frame(Scene& scene)
    {
      if (settings.showWireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        Draw(scene);
        UI::RenderAndPollUI(settings);
    }
    void Renderer::RenderFrame(Scene& scene)
    {
        ActivateShader();
        Frame(scene);
    }
    void Renderer::NewFrame()
    {
        Clear();
        UI::CreateUIFrame();
    }
    
    void Renderer::InitUI(GLFWwindow* window)
    {
        UI::Init(window);
    }

    const DrawSettings& const Renderer::GetSettings() const
    {
      return settings;
    }


    
    
}

