#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"



int main()
{
    
    GLFWwindow* window = NULL;
    try
    {
        window = Engine::Renderer::Init();
    }
    catch(const Engine::FailedToCreateWindowException& exception) 
    {
        std::cout << exception.what();
        return 0;
    }
    Engine::Renderer renderer;
    
    renderer.InitUI(window);
    while (!glfwWindowShouldClose(window))
    {
        Engine::Scene scene(renderer);
        renderer.NewFrame();
        scene.Update(window);
        renderer.RenderFrame(scene);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    renderer.Destroy();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
