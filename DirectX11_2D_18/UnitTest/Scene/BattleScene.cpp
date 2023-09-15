#include "stdafx.h"
#include "BattleScene.h"
#include "Manager/BattleManager.h"
#include "Object/Npc.h"
#include "Object/Player.h"
#include "Geometries/AnimationRect.h"
#include "Object/UI.h"
#include "Object/TextureObject.h"
void BattleScene::Init()
{
	
	AddObj(BattleManager::Get()->GetNpc(), OBJ_TYPE::NPC);
	BattleManager::Get()->GetPlayer()->SetBattlePosition(Vector3(WinMaxWidth / 2-150, WinMaxHeight / 2+(115+64), 0.f));
	BattleManager::Get()->GetPlayer()->SetBattleSize(
		Vector3(BattleManager::Get()->GetPlayer()->GetBattleRect()->GetWidth(), BattleManager::Get()->GetPlayer()->GetBattleRect()->GetHeight(), 0.f));
	BattleManager::Get()->GetPlayer()->GetBattleRect()->GetAnimator()->SetPause(true);
	BattleManager::Get()->GetNpc()->SetBattlePosition(Vector3(WinMaxWidth / 2+150, WinMaxHeight / 2+(215+64), 0.f));
	
	BattleManager::Get()->GetNpc()->SetBattleSize(
		Vector3(BattleManager::Get()->GetNpc()->GetBattleRect()->GetWidth(), BattleManager::Get()->GetNpc()->GetBattleRect()->GetHeight(), 0.f));



	BattleManager::Get()->GetNpc()->SetPlayer(BattleManager::Get()->GetPlayer());
	AddObj(BattleManager::Get()->GetPlayer(), OBJ_TYPE::PLAYER);



	UI* pObj = new UI();
	pObj->Init(L"Battle/BattleField", 4,5,3);
	Animator* animator = new Animator;
	AnimationClip* animation = new AnimationClip(L"Field", pObj->GetTexture(), 1, Vector2(pObj->GetTexture()->GetWidth() * 0.6f, 0.f),
		Vector2(pObj->GetTexture()->GetWidth() * 0.8f, pObj->GetTexture()->GetHeight()/3.f), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"Field");//128 64
	pObj->GetTex()->SetAnimation(animator); pObj->GetTex()->SetPosition(Vector3(WinMaxWidth/2,WinMaxHeight/2+256,1.0f));
	pObj->GetTex()->SetSize(Vector3(pObj->GetTex()->GetWidth(), pObj->GetTex()->GetHeight(), 0.0f));
	pObj->DeleteTexture();
	AddObj(pObj, OBJ_TYPE::UI);
	TextureObject* pObject = new TextureObject;
	pObject->Init(L"Pokemon/UI/TextBox.png");
	pObject->GetTex()->SetWidth(504); pObject->GetTex()->SetHeight(90);
	pObject->GetTex()->SetPosition(Vector3(WinMaxWidth/2,WinMaxHeight/2+64,1.0f)); pObject->GetTex()->SetSize(Vector3(504,90,0));
	AddObj(pObject, OBJ_TYPE::UI);
	pObj = new UI();
	pObj->Init(L"UI/TouchScreenBack", 4, 4, 2);
	animator = new Animator;
	animation = new AnimationClip(L"BackGround", pObj->GetTexture(), 1, Vector2(pObj->GetTexture()->GetWidth() * 0.75f, pObj->GetTexture()->GetHeight()/2),
		Vector2(pObj->GetTexture()->GetWidth(), pObj->GetTexture()->GetHeight() ), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"BackGround");//128 64
	pObj->GetTex()->SetAnimation(animator); pObj->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2 - 192, 1.0f));
	pObj->GetTex()->SetSize(Vector3(pObj->GetTex()->GetWidth(), pObj->GetTex()->GetHeight(), 0.0f));
	pObj->DeleteTexture();
	AddObj(pObj, OBJ_TYPE::UI);

	BattleManager::Get()->SetCircumStance(BATTLE_CIR::N_READY);
	start = std::chrono::system_clock::now();
}

void BattleScene::Destroy()
{
	DeleteAllObj();
}

void BattleScene::Update()
{
	Scene::Update();

	BattleManager::Get()->Update();
}

void BattleScene::Render()
{
	Scene::Render();
	BattleManager::Get()->Render();
}

void BattleScene::PostRender()
{

	Scene::PostRender();
}

void BattleScene::GUI()
{
	BattleManager::Get()->GUI();
}
