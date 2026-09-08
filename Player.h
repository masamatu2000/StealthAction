#pragma once
#include "GameObject.h"
/// <summary>
/// プレイヤークラス
/// </summary>
class Player :
    public GameObject
{
public:
    Player();
	~Player() override;
    void Initialize() override;
    void Update() override;
    void Draw() override;
	void Damege(int damage) {
		// ダメージ処理の実装
	}
};

