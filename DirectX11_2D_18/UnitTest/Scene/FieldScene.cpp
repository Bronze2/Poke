#include "stdafx.h"
#include "FieldScene.h"
#include "Manager/PokemonMgr.h"
#include "Object/CObject.h"
#include "Object/Pokemon.h"
#include "Geometries/AnimationRect.h"
#include "Object/Player.h"
#include "Object/Npc.h"
void FieldScene::Init()
{
	Pokemon* pObj = PokemonMgr::Get()->GetPokemons()[0];
	pObj->SetPos(Vector3(WinMaxWidth/2,WinMaxHeight/2,0.f));
	pObj->SetSize(Vector3(pObj->GetAnimRect()->GetWidth(),pObj->GetAnimRect()->GetHeight(),0.f));
	pObj->SetIconPos(Vector3(WinMaxWidth / 2, WinMaxHeight / 2+50, 0.f));
	pObj->SetIconSize(Vector3(pObj->GetIconRect
	()->GetWidth(), pObj->GetIconRect()->GetHeight(), 0.f));

	AddObj(pObj, OBJ_TYPE::DEFAULT);
}

void FieldScene::Destroy()
{
	DeleteAllObj();
}

void FieldScene::Update()
{
	Scene::Update();
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
