#pragma once
namespace Engine
{
  struct DrawSettings {
    bool focusOnCenterFlag = false;
    bool keepCenteringFlag = false;
    int geometryDefinition = 5;
    bool showWireframe = false;
    bool directionalLighting = true;
    int geometryType = 0;
  };
}