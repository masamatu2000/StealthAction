#include "PlayScene.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
}

void PlayScene::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_R)) {
		RequestChangeScene(SceneState::Result);
	}
}

void PlayScene::Draw()
{
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2, "PLAY SCENE", GetColor(255, 255, 0));
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2 + 40, "PUSH R TO RESULT", GetColor(255, 255, 255));
}
