#include "Framework.h"
#include "Npc.h"
#include "Geometries/AnimationRect.h"
#include "Pokemon.h"
#include "PokeBall.h"
#include "Manager/BattleManager.h"
#include "Player.h"
void Npc::SetPosition(const Vector3& _Position)
{
	m_Position = _Position;
	AnimRect->SetPosition(_Position);
}

void Npc::SetBattlePosition(const Vector3& _Position)
{
	m_BattlePosition = _Position;
	BattleRect->SetPosition(_Position);
}

void Npc::SetSize(const Vector3& _Size)
{
	AnimRect->SetSize(_Size); this->SetSz(_Size);
}

void Npc::SetBattleSize(const Vector3& _Size)
{
	BattleRect->SetSize(_Size); this->SetSz(_Size);
}

void Npc::DoBehavior()
{
}

void Npc::Move()
{
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::N_READY) {
		m_BattlePosition.x += 200 * Time::Delta();
		BattleRect->SetPosition(m_BattlePosition);
		if (m_BattlePosition.x - (BattleRect->GetWidth() / 2) > WinMaxWidth)
		{
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetPause(false);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetPos(Vector3(WinMaxWidth / 2 + 125, WinMaxHeight / 2 + (215 + 20), 0.f));
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetSize(
				Vector3(m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetHeight(), 0.f)
			);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Appear");
			BattleManager::Get()->SetCircumStance(BATTLE_CIR::N_ROAR);
		}
	}
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::N_ROAR) {
		if (m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->GetEnd()&&!m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(false);
			m_vecPokemon[m_curPokemon]->SetPos(Vector3(WinMaxWidth / 2 + 130, WinMaxHeight / 2 + (215 + 60), 0.f));
			m_vecPokemon[m_curPokemon]->SetSize(Vector3(
				m_vecPokemon[m_curPokemon]->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetAnimRect()->GetHeight(),0.f
			));
			m_vecPokemon[m_curPokemon]->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Opponent_Roar");
		}
		if (m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Opponent_IDLE");
			BattleManager::Get()->SetCircumStance(BATTLE_CIR::P_READY);
		}
		
	}
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::ALL_READY) {
		if (player->GetDobehavior()) {
			int i = rand() % m_vecPokemon[m_curPokemon]->GetSkills().size();
			BATTLE_BEHAVIOR behavior;
			behavior.eBattle=BATTLE_TYPE::SKILL;
			behavior.wParam = (DWORD_PTR)m_vecPokemon[m_curPokemon]->GetSkills()[i];
			BattleManager::Get()->NpcBehavior(behavior);
		}
	}
}


Npc::Npc()
{
}

Npc::~Npc()
{
	SAFE_DELETE(AnimRect);
	SAFE_DELETE(BattleRect);
	for (int i = 0; i < m_vecPokemon.size(); ++i) {
		SAFE_DELETE(m_vecPokemon[i]);
	}
}

Npc::Npc(const wstring& _Name, bool bBattle)
	:m_bBattle(bBattle),Name(_Name)
{
	IsNpc = true;
}

Npc::Npc(const Npc& _Other)
{
	this->Name = _Other.Name;
	for (int i = 0; i < _Other.m_vecPokemon.size(); ++i) {
		Pokemon* pokemon = new Pokemon(*_Other.m_vecPokemon[i]);
		pokemon->SetOpponent();
		m_vecPokemon.push_back(pokemon);
	}
	this->m_Position = _Other.m_Position;
	this->m_BattlePosition = _Other.m_BattlePosition;
	this->IsDefeat = _Other.IsDefeat;
	this->Init();
	this->IsNpc = true;
}

void Npc::AddPokemon(const wstring& Name, UINT maxhp, int hp, int att, int def, UINT level, UINT Speed)
{
	if (m_vecPokemon.size() >= 6)
		return;
	Pokemon* pokemon = new Pokemon(Name, maxhp, hp, att, def, level, Speed);
	pokemon->SetOpponent();
	m_vecPokemon.push_back(pokemon);
}

void Npc::Init()
{
	if (m_bBattle) {
		AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
		BattleRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
		Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Char/" + Name + L".png");
		Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Char/" + Name + L"Battle.png");
		AnimRect->SetHeight(srcTex->GetHeight() / 3);
		AnimRect->SetWidth(srcTex->GetWidth() / 4);
		BattleRect->SetHeight(IconTex->GetHeight());
		BattleRect->SetWidth(IconTex->GetWidth());
		Animator* animator = new Animator;
		AnimationClip* clip = new AnimationClip(L"IDLE_D", srcTex, 1, Values::ZeroVec2,
			Vector2(srcTex->GetWidth() / 4.F, srcTex->GetHeight() / 3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_U", srcTex, 1, Vector2(srcTex->GetWidth() / 4.F, 0.f),
			Vector2(srcTex->GetWidth() / 2.f, srcTex->GetHeight() / 3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_L", srcTex, 1, Vector2(srcTex->GetWidth() / 2.f, 0.f),
			Vector2(srcTex->GetWidth() * 0.75f, srcTex->GetHeight() / 3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_R", srcTex, 1, Vector2(srcTex->GetWidth() * 0.75f, 0.f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(L"WALK_U", srcTex, 2, Vector2(0.f, srcTex->GetHeight() / 3.f),
			Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 1.5f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_D", srcTex, 2, Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 3.f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight() / 1.5f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_L", srcTex, 2, Vector2(0.f, srcTex->GetHeight() / 1.5f),
			Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_R", srcTex, 2, Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 1.5f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		animator->SetCurrentAnimClip(L"IDLE_D");
		AnimRect->SetAnimation(animator);
		animator = new Animator;
		clip = new AnimationClip(L"BATTLE", IconTex, 1, Values::ZeroVec2,
			Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 0.1f );
		animator->AddAnimClip(clip);
		animator->SetCurrentAnimClip(L"BATTLE");
		BattleRect->SetAnimation(animator);


		SAFE_DELETE(srcTex);
		SAFE_DELETE(IconTex);
	}
}

void Npc::Update()
{
	Move();
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

void Npc::Render()
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
