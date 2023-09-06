#include "Framework.h"
#include "BattleManager.h"
#include "Object/Player.h"
#include "Object/Npc.h"
#include "Object/UI.h"
#include "Object/TextureObject.h"
#include "Geometries/TextureRect.h"
#include "Geometries/AnimationRect.h"
BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
	SAFE_DELETE(BattlePhase);
	SAFE_DELETE(FightSelector);
	SAFE_DELETE(CancelSelector);
	SAFE_DELETE(MediumSelector);
	SAFE_DELETE(SmallSelector);
	SAFE_DELETE(OurHpBar);
	SAFE_DELETE(OpponentHpBar)
}

void BattleManager::BattleStart(Player* _player, Npc* _npc)
{
	
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_Npc);
	m_Player = new Player(*_player);
	m_Player->SetBattleMode();
	m_Npc = new Npc(*_npc);
	m_Npc->SetBattleMode();
}

void BattleManager::BattleEnd(Player* _player, Npc* _npc)
{
	if (nullptr != m_Player)
		SAFE_DELETE(m_Player);
	if (nullptr != m_Npc)
		SAFE_DELETE(m_Npc);

	m_Player = new Player(*_player);
	m_Player->Init();
	m_Player->SetIdleMode();

	m_Npc = new Npc(*_npc);
	m_Npc->Init();
	m_Npc->SetIdleMode();
}
void BattleManager::Render()
{
	if (m_eCir == BATTLE_CIR::ALL_READY) {
		BattlePhase->Render();
		FightSelector->Render();
		CancelSelector->Render();
		SmallSelector->Render();
		MediumSelector->Render();
		OpponentHpBar->Render();
		OurHpBar->Render();
	}
}

void BattleManager::Init()
{
	BattlePhase = new UI();
	BattlePhase->Init(L"Battle/BattleUI/BattlePhase", 1, 1, 2);
	Animator* animator = new Animator;
	AnimationClip* animation = new AnimationClip(L"BattlePhase", BattlePhase->GetTexture(), 1, Vector2(0.f, 0.f),
		Vector2(BattlePhase->GetTexture()->GetWidth() , BattlePhase->GetTexture()->GetHeight() / 2.f), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"BattlePhaseIn", BattlePhase->GetTexture(), 1, Vector2(0.f, BattlePhase->GetTexture()->GetHeight() / 2.f),
		Vector2(BattlePhase->GetTexture()->GetWidth(), BattlePhase->GetTexture()->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"BattlePhase");//128 64
	BattlePhase->GetTex()->SetAnimation(animator); 
	BattlePhase->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2 - 192, 1.0f));
	BattlePhase->GetTex()->SetSize(Vector3(BattlePhase->GetTex()->GetWidth(), BattlePhase->GetTex()->GetHeight(), 0.0f));
	BattlePhase->DeleteTexture();

	FightSelector = new TextureObject;
	FightSelector->Init(L"Pokemon/Battle/BattleUI/FightSelector.png");
	FightSelector->GetTex()->SetWidth(434); FightSelector->GetTex()->SetHeight(180);
	FightSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 2,230, 1.0f)); FightSelector->GetTex()->SetSize(Vector3(434, 180, 0));
	CancelSelector = new TextureObject;
	CancelSelector->Init(L"Pokemon/Battle/BattleUI/CancelSelector.png");
	CancelSelector->GetTex()->SetWidth(472); CancelSelector->GetTex()->SetHeight(80);
	CancelSelector->GetTex()->SetPosition(Vector3(256, 40, 1.0f));
	CancelSelector->GetTex()->SetSize(Vector3(472, 80, 0));

	MediumSelector = new TextureObject;
	MediumSelector->Init(L"Pokemon/Battle/BattleUI/MediumSelector.png");
	MediumSelector->GetTex()->SetWidth(248); MediumSelector->GetTex()->SetHeight(110);
	MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
	MediumSelector->GetTex()->SetSize(Vector3(248,110, 0));

	SmallSelector = new TextureObject;
	SmallSelector->Init(L"Pokemon/Battle/BattleUI/SmallSelector.png");
	SmallSelector->GetTex()->SetWidth(78); SmallSelector->GetTex()->SetHeight(44);
	SmallSelector->GetTex()->SetPosition(Vector3(80, 55, 1.0f)); //80 55 -> 256 45-> 432 55
	SmallSelector->GetTex()->SetSize(Vector3(78*2, 44*2, 0));

	OurHpBar = new TextureObject;
	OurHpBar->Init(L"Pokemon/Battle/BattleUI/OurHpBAR.png");
	OurHpBar->GetTex()->SetWidth(266); OurHpBar->GetTex()->SetHeight(90);
	OurHpBar->GetTex()->SetPosition(Vector3(390, 543, 1.0f));
	OurHpBar->GetTex()->SetSize(Vector3(266,90, 0));

	OpponentHpBar = new TextureObject;
	OpponentHpBar->Init(L"Pokemon/Battle/BattleUI/EnemyHpBar.png");
	OpponentHpBar->GetTex()->SetWidth(252); OpponentHpBar->GetTex()->SetHeight(78);
	OpponentHpBar->GetTex()->SetPosition(Vector3(126, 700, 1.0f));
	OpponentHpBar->GetTex()->SetSize(Vector3(252, 78, 0));
}

void BattleManager::GUI()
{
	Vector3 vPos = OpponentHpBar->GetTex()->GetPosition();
	Vector3 vSize = OpponentHpBar->GetTex()->GetSize ();
	using namespace ImGui;
	Begin("OpponentHpBar");
	{
		InputFloat3("Pos", vPos, 2);
		InputFloat3("Size", vSize, 2);
	}
	OpponentHpBar->GetTex()->SetPosition(vPos);
	OpponentHpBar->GetTex()->SetSize(vSize);
	End();

	vPos = OurHpBar->GetTex()->GetPosition();
	vSize = OurHpBar->GetTex()->GetSize();
	using namespace ImGui;
	Begin("OurHpBar");
	{
		InputFloat3("Pos", vPos, 2);
		InputFloat3("Size", vSize, 2);

	}
	OurHpBar->GetTex()->SetPosition(vPos);
	OurHpBar->GetTex()->SetSize(vSize);
	End();


}


void BattleManager::Update()
{
	if (m_eCir == BATTLE_CIR::ALL_READY) {
		BattlePhase->Update();
		FightSelector->Update();
		CancelSelector->Update();
		SmallSelector->Update();
		MediumSelector->Update();
		OpponentHpBar->Update();
		OurHpBar->Update();
		if (KEYUP('A'))
		{
			BattlePhase->GetTex()->GetAnimator()->SetCurrentAnimClip(L"BattlePhaseIn");
		}
	}
}
void BattleManager::NPCDefeat()
{
	if (nullptr != m_Npc)m_Npc->SetDefeat();
}
