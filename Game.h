#pragma once
#include"SceneManager.h"
/// <summary>
/// ゲーム全体を管理するクラス
/// </summary>
class Game
{
public:
	Game()=default;
	~Game()=default;
	void Initialize();
	void Update();
	void Draw();
	void Finalize();
private:
	SceneManager SceneManager_;
};

