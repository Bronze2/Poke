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
#include "Geometries/Tile/TMap.h"
#include "Geometries/Tile/Tile.h"
#include "Manager/FadeManager.h"
void FieldScene::Init()
{
	Camera::Get()->SetProjection(WinMaxWidth / 4, WinMaxHeight / 4);
	FadeManager::Get()->SetReverse(true);
	FadeManager::Get()->Reset();
	uint spacing = 48;
	uint width = WinMaxWidth / spacing;
	uint height = WinMaxHeight / spacing;
	tm = new TMap(width, height, spacing);
	tm->Load(TilePath + "Map");
	FadeManager::Get()->Update();
	FadeManager::Get()->Render();
	player = new Player;
	Camera::Get()->SetPlayer(player);
	tm->SetPlayer(player);
	player->Init();
	FadeManager::Get()->Update();
	FadeManager::Get()->Render();
	player->SetPosition(Vector3(48*2, 48*2, 0.f));
	player->SetTMap(tm);
	tm->GetTile(Vector3(48 * 2, 48 * 2, 0))->SetPlayer(player);

	player->SetSize(Vector3(player->GetAnimRect()->GetWidth()/2, player->GetAnimRect()->GetHeight()/2, 0.f));
	AddObj(player, OBJ_TYPE::PLAYER);

	npc = new Npc(L"Npc00");
	npc->Init();
	FadeManager::Get()->Update();
	FadeManager::Get()->Render();
	npc->SetPosition(Vector3(48*4, 48*4, 0.f));
	npc->SetSize(Vector3(npc->GetAnimRect()->GetWidth()/2, npc->GetAnimRect()->GetHeight()/2, 0.f));
	tm->GetTile(Vector3(48 * 4, 48 * 4, 0))->SetNpc(npc);
	Tile* p= tm->GetTile(Vector3(48 * 4, 48 * 4, 0));
	npc->AddPokemon(L"Floatzel", 100, 100, 100, 10, 30,50);
	npc->GetPokemons(0)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npc->GetPokemons(0)->GetSkills()[0]->SetSkillMVRIGHType();
	npc->AddPokemon(L"Garchomp", 100, 100, 100, 10, 30, 50);
	npc->GetPokemons(1)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npc->GetPokemons(1)->GetSkills()[0]->SetSkillMVRIGHType();

	npc->SetPlayer(player);
	AddObj(npc, OBJ_TYPE::NPC);
	BattleManager::Get()->PushNPC(npc);
	npcs = new Npc(L"Npc01");
	npcs->Init();
	FadeManager::Get()->Update();
	FadeManager::Get()->Render();
	npcs->SetPosition(Vector3(48 * 6, 48 * 6, 0.f));
	tm->GetTile(Vector3(TILESIZE * 6, TILESIZE *6, 0))->SetNpc(npcs);
	npcs->SetSize(Vector3(npcs->GetAnimRect()->GetWidth()/2, npcs->GetAnimRect()->GetHeight()/2, 0.f));

	npcs->AddPokemon(L"Floatzel", 100, 100, 100, 10, 30, 50);
	npcs->GetPokemons(0)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npcs->GetPokemons(0)->GetSkills()[0]->SetSkillMVRIGHType();

	npcs->AddPokemon(L"Garchomp", 100, 100, 100, 10, 30, 50);
	npcs->GetPokemons(1)->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	npcs->GetPokemons(1)->GetSkills()[0]->SetSkillMVRIGHType();
	npcs->SetPlayer(player);
	AddObj(npcs, OBJ_TYPE::NPC);
	FadeManager::Get()->Update();
	FadeManager::Get()->Render();
	BattleManager::Get()->PushNPC(npcs);
	FadeManager::Get()->SetReverse(false);
	FadeManager::Get()->Reset();

	Sounds::Get()->Play("BGM", 0.3f);

}
void FieldScene::DeleteMap() {
	
	SAFE_DELETE(tm);
}

void FieldScene::BattleInit()
{
	Camera::Get()->SetProjection(WinMaxWidth / 4, WinMaxHeight / 4);
	FadeManager::Get()->SetReverse(false);
	FadeManager::Get()->Reset();
	uint spacing = 48;
	uint width = WinMaxWidth / spacing;
	uint height = WinMaxHeight / spacing;
	tm = new TMap(width, height, spacing);
	tm->Load(TilePath + "Map");
	Npc* npc = BattleManager::Get()->GetNpc();
	Player* player = BattleManager::Get()->GetPlayer();
	
	Camera::Get()->SetPlayer(player);
	tm->SetPlayer(player);
	player->SetTMap(tm);

	Vector3 vPos = BattleManager::Get()->GetNpc()->GetPos();
	BattleManager::Get()->GetNpc()->SetPosition(BattleManager::Get()->GetNpc()->GetPrevPos());
	BattleManager::Get()->GetNpc()->SetSize(Vector3(BattleManager::Get()->GetNpc()->GetAnimRect()->GetWidth()/2
		, BattleManager::Get()->GetNpc()->GetAnimRect()->GetHeight()/2, 0.f));
	tm->GetTile(Vector3(TILESIZE * 6, TILESIZE * 6, 0))->SetNpc(BattleManager::Get()->GetNpc());
	
	AddObj(BattleManager::Get()->GetNpc(), OBJ_TYPE::NPC);

	BattleManager::Get()->GetPlayer()->SetPosition(BattleManager::Get()->GetPlayer()->GetPrevPos());
	BattleManager::Get()->GetPlayer()->SetSize(Vector3(BattleManager::Get()->GetPlayer()->GetAnimRect()->GetWidth()/2, BattleManager::Get()->GetPlayer()->GetAnimRect()->GetHeight()/2, 0.f));

	AddObj(BattleManager::Get()->GetPlayer(), OBJ_TYPE::PLAYER);

	
	for (size_t i = 0; i < BattleManager::Get()->GetNpcs().size(); ++i) {
		BattleManager::Get()->GetNpcs()[i]->SetPosition(BattleManager::Get()->GetNpcs()[i]->GetPrevPos());
		BattleManager::Get()->GetNpcs()[i]->SetSize(Vector3(BattleManager::Get()->GetNpcs()[i]->GetAnimRect()->GetWidth()/2, BattleManager::Get()->GetNpcs()[i]->GetAnimRect()->GetHeight()/2, 0.f));
		tm->GetTile(BattleManager::Get()->GetNpcs()[i]->GetPrevPos())->SetNpc(BattleManager::Get()->GetNpcs()[i]);
		AddObj(BattleManager::Get()->GetNpcs()[i], OBJ_TYPE::NPC);
	}
	BattleManager::Get()->GetNpcs().clear();
	for (size_t i = 0; i < GetObj(OBJ_TYPE::NPC).size(); ++i) {
		BattleManager::Get()->GetNpcs().push_back((Npc*)GetObj(OBJ_TYPE::NPC)[i]);
	}
	Sounds::Get()->Play("BGM", 0.3f);
}

void FieldScene::Destroy()
{
	SAFE_DELETE(tm);
	DeleteAllObj();
}

void FieldScene::Update()
{
	tm->Update();
	Scene::Update();

	if (PRESS('O')) {
		if (npc->GetDefeat())
			return;
		FadeManager::Get()->SetReverse(true);
		FadeManager::Get()->Reset();
		Sounds::Get()->Pause("BGM");
		Sounds::Get()->Play("Battle", 0.3f);
		player->SetPrevPos(player->GetPos());
		npc->SetPrevPos(npc->GetPos());
		BattleManager::Get()->BattleStart(player, npc);
		ChangeScene(SCENE_TYPE::BATTLE);
	}

}

void FieldScene::Render()
{
	tm->Render();
	Scene::Render();
}

void FieldScene::PostRender()
{
}

void FieldScene::GUI()
{
}
