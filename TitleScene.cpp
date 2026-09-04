#include "TitleScene.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{
	
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_P)) {
		//プレイシーンへ遷移
		 RequestChangeScene(SceneState::Play);
	}
}

void TitleScene::Draw()
{
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2, "TITLE SCENE", GetColor(255, 255, 0));
	DrawString(WIN_WIDTH / 2, WIN_HEIGHT / 2 + 40, "PUSH P TO PLAY", GetColor(255, 255, 255));
}

