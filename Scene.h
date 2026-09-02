#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene()=default;
	virtual void Initialize()=0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

