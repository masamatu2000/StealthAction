#pragma once
#include<Dxlib.h>
#include"Input.h"
#include"globals.h"
struct Vector3 
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};
/// <summary>
/// ゲームオブジェクトの基底クラス
/// </summary>
class GameObject
{
public:
	GameObject()=default;
	virtual ~GameObject()=default;
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void SetPosition(const Vector3& position) {
		position_ = position;
	}
	Vector3 GetPosition() const {
		return position_;
	}
protected:
	Vector3 position_;
	Vector3 rotation_;
	Vector3 scale_= {1.0f, 1.0f, 1.0f};
	Vector3 velocity_;
	int hModel_=-1;
};

