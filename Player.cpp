#include "Player.h"
#include<assert.h>
#include<cmath>
namespace
{
	const float MOVE_SPEED = 10.0f; // 移動速度
	const float ROTATE_SPEED = 10.0f;// 回転速度
    
}
Player::Player()
{
}
Player::~Player()
{
	if (hModel_ != -1)
	{
		MV1DeleteModel(hModel_);
		hModel_ = -1;
	}
	if (hWalkModel_ != -1)
	{
		MV1DeleteModel(hWalkModel_);
		hWalkModel_ = -1;
	}
}

void Player::Initialize()
{
    AnimHandle[static_cast<int>(PlayerState::Idle)]= MV1LoadModel("Assets/Idle.mv1");
    AnimHandle[static_cast<int>(PlayerState::Walk)] = MV1LoadModel("Assets/Walking.mv1");
    _ASSERT_EXPR(
        AnimHandle[static_cast<int>(PlayerState::Idle)]!= -1,
        L"Failed to load Idle.mv1"
    );
    _ASSERT_EXPR(
        AnimHandle[static_cast<int>(PlayerState::Walk)] != -1,
        L"Failed to load Walking.mv1"
    );
	position_ = { 300.0f, 0.0f, 0.0f };
	rotation_ = { 0.0f, 0.0f, 0.0f };
	scale_ = { 1.0f, 1.0f, 1.0f };
	velocity_ = { 0.0f, 0.0f, 0.0f };
	state_ = PlayerState::Idle;
}

void Player::Update()
{
    static float animTime_ = 0.0f;
    Move();

    UpdateAnimation(animTime_);
    
    /*float totalTime =
        MV1GetAttachAnimTotalTime(
            hModel_,
            0
        );

    animTime_ += GetDeltaTime() * 30.0f;

    if (animTime_ >= totalTime)
    {
        animTime_ = 0.0f;
    }

    MV1SetAttachAnimTime(
        hModel_,
        0,
        animTime_
    );*/
   
}

void Player::Draw()
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

void Player::Move()
{
    // ゲーム上の向き
    static float directionY_ = 0.0f;
    bool IsWalk = false;
    static bool DidWalk = false;
    // 左回転
    if (Input::IsKeepKeyDown(KEY_INPUT_A))
    {
        directionY_ -= ROTATE_SPEED * GetDeltaTime();
    }

    // 右回転
    if (Input::IsKeepKeyDown(KEY_INPUT_D))
    {
        directionY_ += ROTATE_SPEED * GetDeltaTime();
    }

    // 前進
    if (Input::IsKeepKeyDown(KEY_INPUT_W))
    {
        position_.x += sinf(directionY_) * MOVE_SPEED;
        position_.z += cosf(directionY_) * MOVE_SPEED;
		//state_ = PlayerState::Walk;
    }
    if (Input::IsKeepKeyDown(KEY_INPUT_S))
    {
        position_.x -= sinf(directionY_) * MOVE_SPEED;
        position_.z -= cosf(directionY_) * MOVE_SPEED;
        //state_ = PlayerState::Walk;
    }
    if (IsWalk == DidWalk) {
        state_ = PlayerState::Walk;
    }
    else {
        state_ = PlayerState::Idle;
    }
    // モデルだけ180度回転させる
    rotation_.y = directionY_ + DX_PI_F;
}

void Player::UpdateAnimation(float &deltaTime)
{
    float totalTime =
        MV1GetAttachAnimTotalTime(
           AnimHandle[static_cast<int>(state_)],
           0
        );

    deltaTime += GetDeltaTime() * 30.0f;

    if (deltaTime >= totalTime)
    {
        deltaTime= 0.0f;
    }
   
    MV1SetAttachAnimTime(
        AnimHandle[static_cast<int>(state_)],
        0,
        deltaTime
    );
}
