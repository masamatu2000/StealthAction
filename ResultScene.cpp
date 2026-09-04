#include "ResultScene.h"

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Initialize()
{
}

void ResultScene::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_T)) {
		RequestChangeScene(SceneState::Title);
	}
}

void ResultScene::Draw()
{
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2, "RESULT SCENE", GetColor(255, 255, 0));
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2 + 40, "PUSH T TO TITLE", GetColor(255, 255, 255));
}
