#pragma once
#include "Scene.h"
#include <memory>

class Player;/// 前方宣言
class PlayScene :
    public Scene
{
public:
    PlayScene();
    ~PlayScene() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
private:
    std::unique_ptr<Player> player_;
};

