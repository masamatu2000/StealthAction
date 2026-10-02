#pragma once
#include "GameObject.h"
enum class EnemyState
{
	Idle,
	Patrol,
	Chase,
	Attack,
	Serch,
	Max
};
class Enemy :
    public GameObject
{
public:
	Enemy();
	~Enemy() override;
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Damege(int damage) {
		// ダメージ処理の実装
	}
	void Move();
	void UpdateAnimation(float& deltaTime);
private:
	EnemyState state_; // 敵の状態
	int AnimHandle[static_cast<int>(EnemyState::Max)];//アニメハンドルを入れておく配列
	int AnimIndex[static_cast<int>(EnemyState::Max)];//アニメのインデックスを入れておく配列
	float Speed_; // 敵の移動速度
	int Hp_; // 敵の体力

};

