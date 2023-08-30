#include "stdafx.h"
#include "FieldScene.h"
#include "Manager/PokemonMgr.h"
#include "Object/CObject.h"
#include "Object/Pokemon.h"
#include "Geometries/AnimationRect.h"
void FieldScene::Init()
{
	Pokemon* pObj = PokemonMgr::Get()->GetPokemons()[0];
	pObj->SetPos(Vector3(WinMaxWidth/2,WinMaxHeight/2,0.f));
	pObj->SetSize(Vector3(pObj->GetAnimRect()->GetWidth(),pObj->GetAnimRect()->GetHeight(),0.f));
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
