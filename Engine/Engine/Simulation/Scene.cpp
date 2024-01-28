#include "pch.h"
#include "framework.h"
#include "scene.h"

std::shared_ptr<Engine::Camera>	Engine::Scene::camera(new Engine::Camera(glm::vec3(-0.4f, 0.0f, 15.0f), 45.0f, 0.1f, 1000.0f));

namespace Engine
{
    
    void Scene::UpdateTime()
    {
        currentFrame = glfwGetTime();
        deltaTime = (currentFrame - prevFrame) / 4;
        prevFrame = currentFrame;
        time += deltaTime * PI;
    }
    
    Scene::Scene(const Renderer& renderer)
    {
        InitializeModels(renderer);
    }
    
    void Scene::CreateGeometries(int definition)
    {
        Geometry* g = new Geometry(1, definition);
        objects.push_back(g);
    }
    float Scene::GetTime() const
    {
        return 0;
    }
    void Scene::InitializeModels(const Renderer& renderer)
    {
        CreateGeometries(renderer.GetDefinition());
        VAO tempvao = VAO();
        tempvao.Bind();
        VBO tempvbo = VBO((*objects[0]).vertices, sizeof((*objects[0]).vertices));
        EBO tempebo = EBO((*objects[0]).indices, sizeof((*objects[0]).indices));
        GLsizeiptr stride = VERTEX_SIZE * sizeof(float);
        tempvao.LinkAttrib(tempvbo, 0, 3, GL_FLOAT, stride, (void*)0);
        tempvao.LinkAttrib(tempvbo, 1, 3, GL_FLOAT, stride, (void*)(3 * sizeof(float)));
        tempvao.Unbind();
        tempvbo.Unbind();
        tempebo.Unbind();
        vao.push_back(tempvao);
        vbo.push_back(tempvbo);
        ebo.push_back(tempebo);
        
    }
    
    void Scene::Destroy()
    {
        vao[0].Delete();
        vbo[0].Delete();
        ebo[0].Delete();
    }
    
    void Scene::Update(GLFWwindow* window)
    {
        if (camera->IsCursorHidden())
        ImGui::SetMouseCursor(ImGuiMouseCursor_None);
        UpdateTime();
        camera->Inputs(window);
        camera->updateMatrix();
    }
    std::shared_ptr<Camera> Scene::GetCamera() const
    {
        return camera;
    }
    Scene::~Scene()
    {
        
        delete objects[0];
    }
    VAO Scene::GetVAO(int i) const
    {
        return vao[i];
    }
    VBO Scene::GetVBO(int i) const
    {
        return vbo[i];
    }
    EBO Scene::GetEBO(int i) const
    {
        return ebo[i];
    }
    
    Geometry Scene::GetGeometry(int i) const
    {
        return *objects[i];
    }
}
