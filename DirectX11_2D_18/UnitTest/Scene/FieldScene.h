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
	virtual void Destroy();	// 소멸자 대체

	virtual void Update();

	virtual void Render();
	virtual void PostRender();	// 후처리가 필요한 코드를 처리

	virtual void GUI();	// 외부 라이브러리
};

