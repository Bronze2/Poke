#include "Framework.h"
#include "Player.h"
#include "Geometries/AnimationRect.h"
#include "Manager/PokemonMgr.h"
#include "Manager/BattleManager.h"
#include "Pokemon.h"
#include "PokeBall.h"
#include "CSkill.h"
void Player::BattlePhase()
{
	if (BATTLE_STATE::NONE == m_eBattleState)
		return;
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::ALL_READY) {
		if (KEYUP(VK_RIGHT))
		{
			m_iSelect += 1;
				switch (m_eSelect)
				{

				case SELECT_PHASE::COMPREHENSIVE:
					if(m_iSelect>4)
					m_iSelect = 1;
					break;
				case SELECT_PHASE::SKILL:
					if (m_iSelect > 5)
					m_iSelect = 1;
					break;
				case SELECT_PHASE::ITEM:
					m_iSelect = 6;
					break;
				case SELECT_PHASE::POKEMON:
					m_iSelect = 7;
					break;
				case SELECT_PHASE::RUN:
					break;

			}
		}
	
		if (KEYUP(VK_LEFT)) {
			m_iSelect -= 1;
			if (m_iSelect < 0) {
				switch (m_eSelect)
				{
			
				case SELECT_PHASE::COMPREHENSIVE:
					m_iSelect = 4;
					break;
				case SELECT_PHASE::SKILL:
					m_iSelect = 5;
					break;
				case SELECT_PHASE::ITEM:
					m_iSelect = 6;
					break;
				case SELECT_PHASE::POKEMON:
					m_iSelect = 7;
					break;
				case SELECT_PHASE::RUN:
					break;

				}
			}
		}
	}
	switch (m_eSelect)
	{

	case SELECT_PHASE::COMPREHENSIVE:
	{
		if (m_iSelect == 1) {
			if (KEYUP(VK_SPACE)) {
				BattleManager::Get()->PhaseIn();
				m_eSelect = SELECT_PHASE::SKILL;
				m_iSelect = 0;
			}
		}
	}
		break;
	case SELECT_PHASE::SKILL:
	{
		if (m_iSelect == 5) {
			if (KEYUP(VK_SPACE)) {
			BattleManager::Get()->PhaseOut();
			m_eSelect = SELECT_PHASE::COMPREHENSIVE;
			m_iSelect = 0;
			}
		}
		else {
			if (m_iSelect == 0)
				return;
			if (KEYUP(VK_SPACE)) {
				BATTLE_BEHAVIOR behavior;
				behavior.eBattle = BATTLE_TYPE::SKILL;
				behavior.wParam = (DWORD_PTR)m_vecPokemon[m_curPokemon]->GetSkills()[m_iSelect];
				BattleManager::Get()->DoBehavior();
				BattleManager::Get()->PlayerBehavior(behavior);
				bbehavior = true;
			}
		}
	}
		break;
	case SELECT_PHASE::ITEM:
		
		break;
	case SELECT_PHASE::POKEMON:
		
		break;
	case SELECT_PHASE::RUN:
		break;

	}
}
void Player::SetPosition(const Vector3& _Position)
{
	m_Position = _Position;
	AnimRect->SetPosition(_Position);
}
void Player::SetBattlePosition(const Vector3& _Position)
{
	m_BattlePosition = _Position;
	BattleRect->SetPosition(_Position);
}
void Player::SetSize(const Vector3& _Size)
{
	AnimRect->SetSize(_Size); this->SetSz(_Size);
}
void Player::SetBattleSize(const Vector3& _Size)
{
	BattleRect->SetSize(_Size); this->SetSz(_Size);
}
void Player::Move()
{
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::P_READY) {
		m_BattlePosition.x -= 200 * Time::Delta();
		BattleRect->SetPosition(m_BattlePosition);
		BattleManager::Get()->GetPlayer()->GetBattleRect()->GetAnimator()->SetPause(false);
		if (m_BattlePosition.x + (BattleRect->GetWidth() / 2) < 0.f)
		{
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetPause(false);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetTopHeight(WinMaxHeight / 2 + (115 + 64) + 75);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetPos(Vector3(0.f, WinMaxHeight / 2 + (115 + 64), 0.f));
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetSize(
				Vector3(m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetHeight(), 0.f)
			);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Throw");
			BattleManager::Get()->SetCircumStance(BATTLE_CIR::P_ROAR);
		}
	}
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::P_ROAR) {
		if (m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->GetEnd()&& !m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(false);
			m_vecPokemon[m_curPokemon]->SetPos(Vector3(WinMaxWidth / 2 - 150, WinMaxHeight / 2 + (115 + 74), 0.f));
			m_vecPokemon[m_curPokemon]->SetSize(Vector3(
				m_vecPokemon[m_curPokemon]->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetAnimRect()->GetHeight(), 0.f
			));
			m_vecPokemon[m_curPokemon]->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Our_Roar");
		}
		if (m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Our_IDLE");
			BattleManager::Get()->SetCircumStance(BATTLE_CIR::ALL_READY);
			BattleManager::Get()->AllReady();
			m_eSelect = SELECT_PHASE::COMPREHENSIVE;
		}
	}
}
void Player::Init()
{
	AnimRect = new AnimationRect(Vector3(0,0,0),Vector3(0,0,0));
	BattleRect = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Char/Player48.png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Char/PlayerBattle.png");
	AnimRect->SetHeight(srcTex->GetHeight()/5);
	AnimRect->SetWidth(srcTex->GetWidth() / 12);
	BattleRect->SetHeight(IconTex->GetHeight());
	BattleRect->SetWidth(IconTex->GetWidth() /4);
	Animator* animator = new Animator;
	AnimationClip* clip = new AnimationClip(L"IDLE_D", srcTex, 1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() /12.F, srcTex->GetHeight()*0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip= new AnimationClip(L"IDLE_U", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"IDLE_L", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight()*0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"IDLE_R", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight()*0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);

	clip = new AnimationClip(L"WALK_D", srcTex, 4, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_U", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_L", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_R", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);


	clip = new AnimationClip(L"RUN_D", srcTex, 4, Vector2(srcTex->GetWidth() / 3.0F, 0),
		Vector2(srcTex->GetWidth() /1.5f, srcTex->GetHeight() * 0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_U", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_L", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_R", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	AnimRect->SetAnimation(animator);
	animator->SetCurrentAnimClip(L"IDLE_D");
	animator = new Animator;
	clip = new AnimationClip(L"BATTLE", IconTex, 5, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 0.15f );
	clip->SetRepeat(false);
	animator->AddAnimClip(clip);
	animator->SetCurrentAnimClip(L"BATTLE");
	BattleRect->SetAnimation(animator);


	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);
}
Player::Player() {
	Pokemon* pokemon = new Pokemon(L"Infernape", 100, 100, 100, 10, 30,100);
	pokemon->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	pokemon->GetSkills()[0]->SetSkillMVRIGHType();

	pokemon->AddSkill(L"BURN", SKILL_TYPE::FIRE, 30, 30, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bibarel", 100, 100, 100, 10, 30,70);
	pokemon->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bronzong", 100, 100, 100, 10, 30,60);
	pokemon->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	m_vecPokemon.push_back(pokemon);
	AnimRect = nullptr;
	BattleRect = nullptr;

}

Player::Player(const Player& _Other)
{
	for (int i = 0; i < _Other.m_vecPokemon.size(); ++i) {
		Pokemon* pokemon = new Pokemon(*_Other.m_vecPokemon[i]);
		m_vecPokemon.push_back(pokemon);
	}
	m_Position = _Other.m_Position;
	m_BattlePosition = _Other.m_BattlePosition;
	this->Init();
}
Player::~Player() {

	SAFE_DELETE(AnimRect);
	SAFE_DELETE(BattleRect);

	for (int i = 0; i < m_vecPokemon.size(); ++i) {
		SAFE_DELETE(m_vecPokemon[i]);
	}

}



void Player::Update()
{
	Move();
	BattlePhase();
	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Update();
	}
	else {
		BattleRect->Update();
	}
	if (nullptr != m_vecPokemon[m_curPokemon])
	{
		m_vecPokemon[m_curPokemon]->Update();
	}
}

void Player::Render()
{

	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Render();
	}
	else {
		BattleRect->Render();
	}
	if (nullptr != m_vecPokemon[m_curPokemon])
	{
		m_vecPokemon[m_curPokemon]->Render();
	}
}
