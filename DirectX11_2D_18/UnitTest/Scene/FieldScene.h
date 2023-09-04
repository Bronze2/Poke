#pragma once
#include "Scene.h"
class FieldScene
	:public Scene
{
private:
	class Player* player;
	class Npc* npc;
public:
	virtual void Init();
	virtual void Destroy();	// �Ҹ��� ��ü

	virtual void Update();

	virtual void Render();
	virtual void PostRender();	// ��ó���� �ʿ��� �ڵ带 ó��

	virtual void GUI();	// �ܺ� ���̺귯��
};

