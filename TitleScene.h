#pragma once
#include "Scene.h"
class TitleScene :
    public Scene
{
public:
    TitleScene();
    ~TitleScene() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
   
};

