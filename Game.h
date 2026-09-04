#pragma once
#include"SceneManager.h"
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

