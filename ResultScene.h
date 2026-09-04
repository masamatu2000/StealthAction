#pragma once
#include "Scene.h"
class ResultScene :
    public Scene
{
public:
    ResultScene();
    ~ResultScene() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
};

