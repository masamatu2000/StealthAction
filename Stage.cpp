#include "Stage.h"

void Stage::Initialize()
{
	walls_.push_back(Wall(wallMin_, wallMax_));
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
	const float WALL_HEIGHT = 200.0f; // 壁の高さ
	const float WALL_THICKNESS = 10.0f; // 壁の厚さ
	const float WALL_WIDTH = 400.0f; // 壁の幅
    DrawCube3D(VGet(0.0f, WALL_HEIGHT, 0.0f), VGet(WALL_THICKNESS, WALL_HEIGHT, WALL_WIDTH), GetColor(100, 110, 120),GetColor(0,0,0), TRUE);
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
