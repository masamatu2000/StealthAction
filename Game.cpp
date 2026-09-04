#include "Game.h"

void Game::Initialize()
{
	//ゲームオブジェクトの初期化
	SceneManager_.Initialize();
}

void Game::Update()
{
	//ゲームオブジェクトの更新
	SceneManager_.Update();
}

void Game::Draw()
{
	//ゲームオブジェクトの描画
	SceneManager_.Draw();
}

void Game::Finalize()
{
	SceneManager_.Finalize();
}
