#include "stdafx.h"
#include "FieldScene.h"
#include "Manager/PokemonMgr.h"
#include "Object/CObject.h"
#include "Object/Pokemon.h"
#include "Geometries/AnimationRect.h"
#include "Object/Player.h"
#include "Object/Npc.h"
#include "Manager/BattleManager.h"
#include "Object/CSkill.h"
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
	npc->GetPokemons(0)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npc->GetPokemons(0)->GetSkills()[0]->SetSkillMVRIGHType();


	npc->SetPlayer(player);
	AddObj(npc, OBJ_TYPE::NPC);
	BattleManager::Get()->PushNPC(npc);
	npcs = new Npc(L"Npc01");
	npcs->Init();
	npcs->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2 + 100, 0.f));
	npcs->SetSize(Vector3(npcs->GetAnimRect()->GetWidth(), npcs->GetAnimRect()->GetHeight(), 0.f));

	npcs->AddPokemon(L"Floatzel", 100, 100, 100, 10, 30, 50);
	npcs->GetPokemons(0)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npcs->GetPokemons(0)->GetSkills()[0]->SetSkillMVRIGHType();

	npcs->AddPokemon(L"Garchomp", 100, 100, 100, 10, 30, 50);
	npcs->GetPokemons(1)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npcs->GetPokemons(1)->GetSkills()[0]->SetSkillMVRIGHType();
	npcs->SetPlayer(player);
	AddObj(npcs, OBJ_TYPE::NPC);
	BattleManager::Get()->PushNPC(npcs);
}

void FieldScene::BattleInit()
{
	Npc* npc = BattleManager::Get()->GetNpc();
	Player* player = BattleManager::Get()->GetPlayer();
	Vector3 vPos = BattleManager::Get()->GetNpc()->GetPos();
	BattleManager::Get()->GetNpc()->SetPosition(BattleManager::Get()->GetNpc()->GetPrevPos());
	BattleManager::Get()->GetNpc()->SetSize(Vector3(BattleManager::Get()->GetNpc()->GetAnimRect()->GetWidth(), BattleManager::Get()->GetNpc()->GetAnimRect()->GetHeight(), 0.f));

	
	AddObj(BattleManager::Get()->GetNpc(), OBJ_TYPE::NPC);

	BattleManager::Get()->GetPlayer()->SetPosition(BattleManager::Get()->GetPlayer()->GetPrevPos());
	BattleManager::Get()->GetPlayer()->SetSize(Vector3(BattleManager::Get()->GetPlayer()->GetAnimRect()->GetWidth(), BattleManager::Get()->GetPlayer()->GetAnimRect()->GetHeight(), 0.f));

	AddObj(BattleManager::Get()->GetPlayer(), OBJ_TYPE::PLAYER);

	
	for (size_t i = 0; i < BattleManager::Get()->GetNpcs().size(); ++i) {
		BattleManager::Get()->GetNpcs()[i]->SetPosition(BattleManager::Get()->GetNpcs()[i]->GetPrevPos());
		BattleManager::Get()->GetNpcs()[i]->SetSize(Vector3(BattleManager::Get()->GetNpcs()[i]->GetAnimRect()->GetWidth(), BattleManager::Get()->GetNpcs()[i]->GetAnimRect()->GetHeight(), 0.f));
		AddObj(BattleManager::Get()->GetNpcs()[i], OBJ_TYPE::NPC);
	}
	BattleManager::Get()->GetNpcs().clear();
	for (size_t i = 0; i < GetObj(OBJ_TYPE::NPC).size(); ++i) {
		BattleManager::Get()->GetNpcs().push_back((Npc*)GetObj(OBJ_TYPE::NPC)[i]);
	}

}

void FieldScene::Destroy()
{
	DeleteAllObj();
}

void FieldScene::Update()
{
	Scene::Update();

	if (PRESS('A')) {
		if (npc->GetDefeat())
			return;
		player->SetPrevPos(player->GetPos());
		npc->SetPrevPos(npc->GetPos());
		BattleManager::Get()->BattleStart(player, npc);
		ChangeScene(SCENE_TYPE::BATTLE);
	}
	if (PRESS('B')) {
	
		ChangeScene(SCENE_TYPE::TITLE);
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
