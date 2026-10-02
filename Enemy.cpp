#include "Enemy.h"
#include<assert.h>
#include<string>
namespace
{
	const float MOVE_SPEED = 5.0f; // 移動速度
	const float ROTATE_SPEED = 5.0f;// 回転速度
	const std::string AnimPath = "Assets/Enemy/";// アニメーションのパス
}
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	state_ = EnemyState::Idle;
	AnimHandle[static_cast<int>(EnemyState::Idle)] = MV1LoadModel((AnimPath + "EnemyIdle.mv1").c_str());
    _ASSERT_EXPR(
        AnimHandle[static_cast<int>(EnemyState::Idle)] != -1,
        L"Failed to load EnemyIdle.mv1"
    );
	for(int i=0; i < static_cast<int>(EnemyState::Max); i++)
	{
		AnimIndex[i] = MV1AttachAnim(
			AnimHandle[i],
			1
		);
	}
	position_ = { 500.0f, 0.0f, 0.0f };
	rotation_ = { 0.0f, 0.0f, 0.0f };
	scale_ = { 1.0f, 1.0f, 1.0f };
	velocity_ = { 0.0f, 0.0f, 0.0f };
}

void Enemy::Update()
{
	static float animTime_ = 0.0f;
	UpdateAnimation(animTime_);
}

void Enemy::Draw()
{
	MV1SetPosition(
		AnimHandle[static_cast<int>(state_)],
		VGet(position_.x, position_.y, position_.z)
	);
	MV1SetRotationXYZ(
		AnimHandle[static_cast<int>(state_)],
		VGet(rotation_.x, rotation_.y, rotation_.z)
	);
	MV1SetScale(
		AnimHandle[static_cast<int>(state_)],
		VGet(scale_.x, scale_.y, scale_.z)
	);
	MV1DrawModel(AnimHandle[static_cast<int>(state_)]);
}

void Enemy::Move()
{
}

void Enemy::UpdateAnimation(float& deltaTime)
{
    float totalTime =
        MV1GetAttachAnimTotalTime(
            AnimHandle[static_cast<int>(state_)],
            AnimIndex[static_cast<int>(state_)]
        );

    deltaTime += GetDeltaTime() * 30.0f;

    if (deltaTime >= totalTime)
    {
        deltaTime = 0.0f;
    }

    MV1SetAttachAnimTime(
        AnimHandle[static_cast<int>(state_)],
        AnimIndex[static_cast<int>(state_)],
        deltaTime
    );
}
