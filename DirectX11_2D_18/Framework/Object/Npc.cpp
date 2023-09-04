#include "Framework.h"
#include "Npc.h"
#include "Geometries/AnimationRect.h"
#include "Pokemon.h"

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


Npc::Npc()
{
}

Npc::~Npc()
{
	SAFE_DELETE(AnimRect);
	SAFE_DELETE(BattleRect);
}

Npc::Npc(const wstring& _Name, bool bBattle)
{
	if (bBattle) {
		AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
		BattleRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
		Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Char/" + _Name + L".png");
		Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Char/" + _Name + L"Battle.png");
		AnimRect->SetHeight(srcTex->GetHeight()/3);
		AnimRect->SetWidth(srcTex->GetWidth() / 4);
		BattleRect->SetHeight(IconTex->GetHeight());
		BattleRect->SetWidth(IconTex->GetWidth() );
		Animator* animator = new Animator;
		AnimationClip* clip = new AnimationClip(L"IDLE_D", srcTex, 1, Values::ZeroVec2,
			Vector2(srcTex->GetWidth() / 4.F, srcTex->GetHeight() /3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_U", srcTex, 1, Vector2(srcTex->GetWidth() / 4.F, 0.f),
			Vector2(srcTex->GetWidth() / 2.f, srcTex->GetHeight() /3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_L", srcTex, 1, Vector2(srcTex->GetWidth() / 2.f, 0.f),
			Vector2(srcTex->GetWidth() *0.75f, srcTex->GetHeight()/3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_R", srcTex, 1, Vector2(srcTex->GetWidth() * 0.75f, 0.f),
			Vector2(srcTex->GetWidth() , srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(L"WALK_U", srcTex, 2, Vector2(0.f, srcTex->GetHeight() / 3.f),
			Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 1.5f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_D", srcTex, 2, Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 3.f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight() /1.5f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_L", srcTex, 2, Vector2(0.f, srcTex->GetHeight() / 1.5f),
			Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() ), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_R", srcTex, 2, Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 1.5f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight() ), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		animator->SetCurrentAnimClip(L"IDLE_D");
		AnimRect->SetAnimation(animator);
		animator = new Animator;
		clip = new AnimationClip(L"BATTLE", srcTex, 4, Values::ZeroVec2,
			Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		animator->SetCurrentAnimClip(L"BATTLE");
		BattleRect->SetAnimation(animator);


		SAFE_DELETE(srcTex);
		SAFE_DELETE(IconTex);
	}
}

Npc::Npc(const Npc& _Other)
{
	for (int i = 0; i < _Other.m_vecPokemon.size(); ++i) {
		Pokemon* pokemon = new Pokemon(_Other.m_vecPokemon[i]->GetName(),
			_Other.m_vecPokemon[i]->GetMaxHp(), _Other.m_vecPokemon[i]->GetHp(), _Other.m_vecPokemon[i]->GetAttack()
			, _Other.m_vecPokemon[i]->GetDef(), _Other.m_vecPokemon[i]->GetLevel(), m_vecPokemon[i]->GetSpeed());

	}
}

void Npc::AddPokemon(const wstring& Name, UINT maxhp, int hp, int att, int def, UINT level, UINT Speed)
{
	if (m_vecPokemon.size() >= 6)
		return;
	Pokemon* pokemon = new Pokemon(Name, maxhp, hp, att, def, level, Speed);
	m_vecPokemon.push_back(pokemon);
}

void Npc::Init()
{
}

void Npc::Update()
{

	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Update();
	}
	else {
		BattleRect->Update();
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
}
