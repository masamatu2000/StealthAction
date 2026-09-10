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
}

void Player::Initialize()
{
	hModel_ = MV1LoadModel("Assets/Idle.mv1");
    _ASSERT_EXPR(
        hModel_ != -1,
        L"Failed to load Idle.mv1"
    );
	position_ = { 300.0f, 0.0f, 0.0f };
	rotation_ = { 0.0f, 0.0f, 0.0f };
	scale_ = { 1.0f, 1.0f, 1.0f };
	velocity_ = { 0.0f, 0.0f, 0.0f };
    int animNum = MV1GetAnimNum(hModel_);

    printfDx("AnimNum = %d\n", animNum);
    int attach = MV1AttachAnim(hModel_, 1);

    printfDx("AnimNum = %d\n", MV1GetAnimNum(hModel_));
    printfDx("AttachIndex = %d\n", attach);
}

void Player::Update()
{
    Move();
   
    static float animTime_ = 0.0f;

    float totalTime =
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
    );
}

void Player::Draw()
{
    MV1SetPosition(
        hModel_,
        VGet(position_.x, position_.y, position_.z)
    );

    MV1SetRotationXYZ(
        hModel_,
        VGet(rotation_.x, rotation_.y, rotation_.z)
    );

    MV1SetScale(
        hModel_,
        VGet(scale_.x, scale_.y, scale_.z)
    );

    MV1DrawModel(hModel_);
}

void Player::Move()
{
    // ゲーム上の向き
    static float directionY_ = 0.0f;

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
    }
    if (Input::IsKeepKeyDown(KEY_INPUT_S))
    {
        position_.x -= sinf(directionY_) * MOVE_SPEED;
        position_.z -= cosf(directionY_) * MOVE_SPEED;
    }
    // モデルだけ180度回転させる
    rotation_.y = directionY_ + DX_PI_F;
}
