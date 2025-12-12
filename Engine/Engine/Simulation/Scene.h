#pragma once
#include "Geometry.h"
#include <memory>
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"
#include "Renderer.h"
#include "SceneSettings.h"

namespace Engine
{
    class Skybox;
    
    class Renderer;
    
    class Camera;
    
    class Scene
    {
        public:

        Scene(const Renderer& renderer);
        float GetTime() const;
        VAO GetVAO(int i) const;
        VBO GetVBO(int i) const;
        EBO GetEBO(int i) const;
        Geometry& GetGeometry(int i) const;
        std::shared_ptr<Camera> GetCamera() const;
        ~Scene();
        void Update(GLFWwindow* window);
        void const CreateGeometries(const DrawSettings& settings);
        void InitializeModels(const Renderer& renderer);
        void UpdateTime();
        
        private: 

        int keepCenteringFlag;
        int centeringFlag;
        static std::shared_ptr<Camera> camera;
        std::vector<Geometry*> objects;
        std::vector<VAO> vao;
        std::vector<VBO> vbo;
        std::vector<EBO> ebo;
        
        float time = 0;
        double prevFrame = 0;
        double currentFrame = 0;
        float deltaTime;
    };
}
