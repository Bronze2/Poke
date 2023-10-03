#pragma once
#include "Scene.h"
class FieldScene
	:public Scene
{
private:
	class Player* player;
	class Npc* npc;
	class Npc* npcs; 
private:
	class TMap* tm = nullptr;
public:
	void DeleteMap();
	virtual void Init();
	virtual void BattleInit();
	virtual void Destroy();	// �Ҹ��� ��ü

	virtual void Update();

	virtual void Render();
	virtual void PostRender();	// ��ó���� �ʿ��� �ڵ带 ó��

	virtual void GUI();	// �ܺ� ���̺귯��
};

