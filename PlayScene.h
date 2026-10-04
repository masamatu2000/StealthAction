#pragma once
#include "Scene.h"
#include <memory>
#include<vector>
class Player;/// 前方宣言
class Enemy;/// 前方宣言
class Stage;/// 前方宣言
class PlayScene :
    public Scene
{
public:
    PlayScene();
    ~PlayScene() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
   
    Player* FindPlayer()const;
	
    const std::vector<std::unique_ptr<Enemy>>& FindEnemies() const;
private:
    std::unique_ptr<Player> player_;
    std::vector<std::unique_ptr<Enemy>> enemies_;
    std::unique_ptr<Stage> stage_;
};

