#pragma once
#include<Dxlib.h>
#include"Input.h"
#include"globals.h"
#include<vector>
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
	void SetPosition(const VECTOR& position) {
		position_ = position;
	}
	VECTOR GetPosition() const {
		return position_;
	}
	
protected:
	VECTOR position_;
	VECTOR rotation_;
	VECTOR scale_= {1.0f, 1.0f, 1.0f};
	VECTOR velocity_;
	VECTOR direction_ ={ 0.0f,0.0f,0.0f };
	int hModel_=-1;
	std::vector<GameObject*> children_;
	float CollisionRadius_;
};

