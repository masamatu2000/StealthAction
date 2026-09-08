#include "Player.h"
#include<assert.h>
#include<cmath>
#include <Windows.h>
namespace
{
	const float MOVE_SPEED = 0.1f; // 移動速度
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
{/*
    DWORD attr = GetFileAttributesA("Assets/Body Block.fbx");

    if (attr == INVALID_FILE_ATTRIBUTES)
    {
        MessageBoxA(
            nullptr,
            "Player.fbx NOT FOUND",
            "File Check",
            MB_OK
        );
    }
    else
    {
        MessageBoxA(
            nullptr,
            "Player.fbx FOUND",
            "File Check",
            MB_OK
        );
    }*/
   
	hModel_ = MV1LoadModel("Assets/Player.mv1");

    _ASSERT_EXPR(
        hModel_ != -1,
        L"Failed to load Player.mv1"
    );
	position_ = { 300.0f, 0.0f, 0.0f };
	rotation_ = { 0.0f, 0.0f, 0.0f };
	scale_ = { 1.0f, 1.0f, 1.0f };
	velocity_ = { 0.0f, 0.0f, 0.0f };
}

void Player::Update()
{
    Vector3 moveDir = { 0.0f, 0.0f, 0.0f };

    if (Input::IsKeyDown(KEY_INPUT_W))
    {
        moveDir.z += 1.0f;
    }

    if (Input::IsKeyDown(KEY_INPUT_S))
    {
        moveDir.z -= 1.0f;
    }

    if (Input::IsKeyDown(KEY_INPUT_A))
    {
        moveDir.x -= 1.0f;
    }

    if (Input::IsKeyDown(KEY_INPUT_D))
    {
        moveDir.x += 1.0f;
    }


    // 入力されている場合
    float length = sqrtf(
        moveDir.x * moveDir.x +
        moveDir.z * moveDir.z
    );

    if (length > 0.0f)
    {
        // 正規化
        moveDir.x /= length;
        moveDir.z /= length;

        // 速度
        velocity_.x = moveDir.x * MOVE_SPEED;
        velocity_.z = moveDir.z * MOVE_SPEED;

        // 移動方向を向く
        rotation_.y = atan2f(moveDir.x, moveDir.z);
    }
    else
    {
        velocity_.x = 0.0f;
        velocity_.z = 0.0f;
    }

    position_.x += velocity_.x;
    position_.z += velocity_.z;
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
