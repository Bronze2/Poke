#include "Framework.h"
#include "BattleManager.h"
#include "Object/Player.h"
#include "Object/Npc.h"
#include "Object/UI.h"
#include "Object/TextureObject.h"
#include "Geometries/TextureRect.h"
#include "Geometries/AnimationRect.h"
#include "Object/Pokemon.h"
#include "Object/CSkill.h"
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

void BattleManager::SelectorUpdate()
{
	switch (m_Player->GetSelectPhase())
	{
	case SELECT_PHASE::COMPREHENSIVE:
		
	{
		CancelSelector->SetRender(false);
		if (m_Player->GetSelect() == 1) {
			FightSelector->SetRender(true);
		}
		else {
			FightSelector->SetRender(false);
		}
		if (m_Player->GetSelect() == 2|| m_Player->GetSelect() == 3|| m_Player->GetSelect() == 4) {
			SmallSelector->SetRender(true);
			if(m_Player->GetSelect() == 2)
				SmallSelector->GetTex()->SetPosition(Vector3(80, 55, 1.0f)); //80 55 -> 256 45-> 432 55
			else if(m_Player->GetSelect() == 3)
				SmallSelector->GetTex()->SetPosition(Vector3(256, 45, 1.0f));
			else 
				SmallSelector->GetTex()->SetPosition(Vector3(432, 55, 1.0f));
		}
		else {
			SmallSelector->SetRender(false);
		}
	}
		break;

	case SELECT_PHASE::SKILL:
		if (m_Player->GetSelect() == 5) {
			CancelSelector->SetRender(true);
			MediumSelector->SetRender(false);
		}
		else {
			CancelSelector->SetRender(false);
			MediumSelector->SetRender(true);
			switch (m_Player->GetSelect())
			{
			case 1:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
				break;
			case 2:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth *0.75f, 290, 1.0f));
				break;
			case 3:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 165, 1.0f));
				break;
			case 4:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth * 0.75f, 165, 1.0f));
				break;
			default:
				break;
			}
		}

		break;

	default:
		break;
	}
	FightSelector->Update();
	CancelSelector->Update();
	SmallSelector->Update();
	MediumSelector->Update();
	OpponentHpBar->Update();
	OurHpBar->Update();

	switch (m_Player->GetSelectPhase())
	{
	case SELECT_PHASE::SKILL:
	{
		for (int i = 0; i < m_Player->GetCurPokemons()->GetSkills().size(); ++i) {
			m_Player->GetCurPokemons()->GetSkills()[i]->Update();
		}
	}
	break;

	default:
		break;
	}
}

void BattleManager::PhaseIn()
{
	BattlePhase->GetTex()->GetAnimator()->SetCurrentAnimClip(L"BattlePhaseIn");
	FightSelector->SetRender(false);
	SmallSelector->SetRender(false);
}

void BattleManager::PhaseOut()
{
	BattlePhase->GetTex()->GetAnimator()->SetCurrentAnimClip(L"BattlePhase");
}

void BattleManager::AllReady()
{
	OurHpBar->SetRender(true);
	OpponentHpBar->SetRender(true);
}

void BattleManager::BattleStart(Player* _player, Npc* _npc)
{
	
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_Npc);
	m_Player = new Player(*_player);
	m_Player->SetBattleMode();

	for (int j = 0; j < m_Player->GetPokemons().size(); ++j)
		for (int i = 0; i < m_Player->GetPokemons()[j]->GetSkills().size(); ++i) {
			if (i == 0)
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
			if (i == 1)
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth * 0.75f, 290, 1.0f));
			if (i == 2)
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth / 4, 165, 1.0f));
			if (i == 3)
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth * 0.75f, 165, 1.0f));
			m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetSize(Vector3((float)m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->GetWidth(), (float)m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->GetHeight(), (float)0.0f));

		}
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

		switch (m_Player->GetSelectPhase())
		{
		case SELECT_PHASE::SKILL:
		{
			for (int i = 0; i < m_Player->GetCurPokemons()->GetSkills().size(); ++i) {
				m_Player->GetCurPokemons()->GetSkills()[i]->Render();
			}
		}
			break;

		default:
			break;
		}
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
	BattlePhase->GetTex()->SetSize(Vector3((float)BattlePhase->GetTex()->GetWidth(), (float)BattlePhase->GetTex()->GetHeight(), (float)0.0f));
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
	CancelSelector->SetRender(false);
	MediumSelector = new TextureObject;
	MediumSelector->Init(L"Pokemon/Battle/BattleUI/MediumSelector.png");
	MediumSelector->GetTex()->SetWidth(248); MediumSelector->GetTex()->SetHeight(110);
	MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
	MediumSelector->GetTex()->SetSize(Vector3(248,110, 0));
	MediumSelector->SetRender(false);
	SmallSelector = new TextureObject;
	SmallSelector->Init(L"Pokemon/Battle/BattleUI/SmallSelector.png");
	SmallSelector->GetTex()->SetWidth(78); SmallSelector->GetTex()->SetHeight(44);
	SmallSelector->GetTex()->SetPosition(Vector3(80, 55, 1.0f)); //80 55 -> 256 45-> 432 55
	SmallSelector->GetTex()->SetSize(Vector3(78*2, 44*2, 0));
	SmallSelector->SetRender(false);
	OurHpBar = new TextureObject;
	OurHpBar->Init(L"Pokemon/Battle/BattleUI/OurHpBAR.png");
	OurHpBar->GetTex()->SetWidth(266); OurHpBar->GetTex()->SetHeight(90);
	OurHpBar->GetTex()->SetPosition(Vector3(390, 543, 1.0f));
	OurHpBar->GetTex()->SetSize(Vector3(266,90, 0));
	OurHpBar->SetRender(false);
	OpponentHpBar = new TextureObject;
	OpponentHpBar->Init(L"Pokemon/Battle/BattleUI/EnemyHpBar.png");
	OpponentHpBar->GetTex()->SetWidth(252); OpponentHpBar->GetTex()->SetHeight(78);
	OpponentHpBar->GetTex()->SetPosition(Vector3(126, 700, 1.0f));
	OpponentHpBar->GetTex()->SetSize(Vector3(252, 78, 0));
	OpponentHpBar->SetRender(false);

	
	
}

void BattleManager::GUI()
{
	

}


void BattleManager::Update()
{

	if (m_eCir == BATTLE_CIR::ALL_READY) {
		BattlePhase->Update();
		SelectorUpdate();
		
		
	}
}
void BattleManager::NPCDefeat()
{
	if (nullptr != m_Npc)m_Npc->SetDefeat();
}
