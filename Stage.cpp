#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include<algorithm>
void Stage::Initialize()
{
	walls_.push_back(Wall(VECTOR(0.0f, 0.0f, 0.0f), VECTOR(50.0f, 200.0f, 200.0f)));
}

void Stage::Update()
{
	
}

void Stage::Draw()
{
    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);
    DrawFloor();
	for (auto& wall : walls_)
	{
		DrawWall(wall);
	}
}

void Stage::DrawWall(const Wall& wall) const
{
	
    DrawCube3D(VGet(wall.wallMin.x, wall.wallMin.y, wall.wallMin.z), VGet(wall.wallMax.x,wall.wallMax.y, wall.wallMax.z), GetColor(255, 255, 255),GetColor(0,0,0), TRUE);
}

void Stage::DrawFloor() const
{
    const float HALF_SIZE = 1000.0f; // 床の中心から端まで
    const float FLOOR_Y = 0.0f;      // 床の高さ
    const float GRID_SIZE = 100.0f;  // 格子の間隔
    const int GRID_COUNT = 10;

    const unsigned int floorColor = GetColor(100, 110, 120);
    const unsigned int gridColor = GetColor(145, 155, 165);


    // 床の四隅
    const VECTOR a = VGet(-HALF_SIZE, FLOOR_Y, -HALF_SIZE);
    const VECTOR b = VGet(-HALF_SIZE, FLOOR_Y, HALF_SIZE);
    const VECTOR c = VGet(HALF_SIZE, FLOOR_Y, HALF_SIZE);
    const VECTOR d = VGet(HALF_SIZE, FLOOR_Y, -HALF_SIZE);

    // 三角形2枚で四角い床を描画
    DrawTriangle3D(a, b, c, floorColor, TRUE);
    DrawTriangle3D(a, c, d, floorColor, TRUE);

    // 床と線が重なってちらつくのを防ぐため、少し上に描く
    const float LINE_Y = FLOOR_Y + 0.1f;

    for (int i = -GRID_COUNT; i <= GRID_COUNT; ++i)
    {
        const float position = i * GRID_SIZE;

        DrawLine3D(
            VGet(position, LINE_Y, -HALF_SIZE),
            VGet(position, LINE_Y, HALF_SIZE),
            gridColor
        );

        DrawLine3D(
            VGet(-HALF_SIZE, LINE_Y, position),
            VGet(HALF_SIZE, LINE_Y, position),
            gridColor
        );
    }
}

bool Stage::IsHitWall(VECTOR pos, VECTOR& dir,float r)
{
    for (auto& wall : walls_)
    {
            VECTOR closestPoint = VGet(
                std::clamp(pos.x, wall.wallMin.x, wall.wallMax.x),
                pos.y,
                std::clamp(pos.z, wall.wallMin.z, wall.wallMax.z)
            );
			float distance = (closestPoint.x -pos.x) *(closestPoint.x-pos.x) + (closestPoint.y-pos.y) * (closestPoint.y-pos.y) + (closestPoint.z-pos.z) * (closestPoint.z-pos.z);
            if(distance < r * r)
            {
                //↓壁すり
                //壁の法線ベクトル
				VECTOR wallNormal = VNorm(VSub(pos, closestPoint));
				float dot = VDot(dir, wallNormal);
				dir = VSub(dir, VScale(wallNormal,dot));
                return true;
            }
    }
    return false;
}
