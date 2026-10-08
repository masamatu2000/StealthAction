#pragma once
#include "GameObject.h"
#include<vector>
#include <memory>
/// <summary>
/// 床と壁、そのほかのオブジェクト管理するクラス
/// </summary>
class Player;/// 前方宣言
class Enemy;/// 前方宣言
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
		
	};
	void DrawWall(const Wall& wall) const;// 壁を描画する関数
	void DrawFloor() const;// 床を描画する関数
	
	void SetPlayer(Player* player) {// プレイヤーのポインタを設定する関数
		player_ = player;
	}
	bool IsHitWall(VECTOR pos, VECTOR& dir,float r);
	void AddEnemy(Enemy* enemy) {// 敵のポインタを追加する関数
		enemies_.push_back(enemy);
	}

private:
	
	std::vector<Wall> walls_;
	Player* player_ = nullptr; // プレイヤーのポインタ
	std::vector<Enemy*> enemies_;

};

