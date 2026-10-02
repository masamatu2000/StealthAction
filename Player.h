#pragma once
#include "GameObject.h"
enum class PlayerState
{
	Idle,
	Walk,
	Jump,
	Attack,
	Max
};
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
    void Move();
	void ChangeAnimation(PlayerState nextstate);
	void UpdateAnimation(float &deltaTime);
private:
	//int hWalkModel_ = -1; // モデルハンドル
	PlayerState state_ = PlayerState::Idle; // プレイヤーの状態
	int AnimHandle[static_cast<int>(PlayerState::Max)];//アニメハンドルを入れておく配列
	int AnimIndex[static_cast<int>(PlayerState::Max)];//アニメのインデックスを入れておく配列
};

