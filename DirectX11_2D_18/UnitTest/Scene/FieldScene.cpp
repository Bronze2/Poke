#include "stdafx.h"
#include "FieldScene.h"
#include "Manager/PokemonMgr.h"
#include "Object/CObject.h"
#include "Object/Pokemon.h"
#include "Geometries/AnimationRect.h"
#include "Object/Player.h"
#include "Object/Npc.h"
#include "Manager/BattleManager.h"
void FieldScene::Init()
{
	player = new Player;
	player->Init();

	player->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2, 0.f));
	player->SetSize(Vector3(player->GetAnimRect()->GetWidth(), player->GetAnimRect()->GetHeight(), 0.f));
	AddObj(player, OBJ_TYPE::PLAYER);

	npc = new Npc(L"Npc00");
	npc->Init();
	npc->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2+50, 0.f));
	npc->SetSize(Vector3(npc->GetAnimRect()->GetWidth(), npc->GetAnimRect()->GetHeight(), 0.f));

	npc->AddPokemon(L"Floatzel", 100, 100, 100, 10, 30,50);
	npc->SetPlayer(player);
	AddObj(npc, OBJ_TYPE::NPC);
}

void FieldScene::Destroy()
{
	DeleteAllObj();
}

void FieldScene::Update()
{
	Scene::Update();

	if (PRESS('A')) {
		BattleManager::Get()->BattleStart(player, npc);
		ChangeScene(SCENE_TYPE::BATTLE);
	}
}

void FieldScene::Render()
{
	Scene::Render();
}

void FieldScene::PostRender()
{
}

void FieldScene::GUI()
{
}
