#pragma once
#include "Scene.h"
class BattleScene :
    public Scene
{
private:
	std::chrono::system_clock::time_point start;
public:
	virtual void Init();
	virtual void Destroy();	// �Ҹ��� ��ü

	virtual void Update();

	virtual void Render();
	virtual void PostRender();	// ��ó���� �ʿ��� �ڵ带 ó��

	virtual void GUI();
};

