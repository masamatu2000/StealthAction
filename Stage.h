#pragma once
#include "GameObject.h"
#include<vector>
/// <summary>
/// 床と壁、そのほかのオブジェクト管理するクラス
/// </summary>
class Stage :
    public GameObject
{
public:
	Stage() = default;
	virtual ~Stage() = default;
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() override;
	struct Wall
	{
		VECTOR wallMin;
		VECTOR wallMax;
		Wall(VECTOR min, VECTOR max) : wallMin(min), wallMax(max) {}
		bool IsHitWall(const VECTOR& position) {

		}
	};
	void DrawWall(const Wall& wall) const;// 壁を描画する関数
	void DrawFloor() const;// 床を描画する関数
private:
	VECTOR wallMin_ = VGet(-200.0f, 0.0f, 200.0f);
	VECTOR wallMax_ = VGet(200.0f, 200.0f, 50.0f);
	std::vector<Wall> walls_;
};

