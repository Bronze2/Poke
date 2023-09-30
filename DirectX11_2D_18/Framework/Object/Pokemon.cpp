#include "Framework.h"
#include "Pokemon.h"
#include "PokeBall.h"
#include "Geometries/AnimationRect.h"
#include "CSkill.h"
#include "UI/ProgressBar.h"
#include "UI/CFont.h"
Vector3 Pokemon::GetAnimationSize()
{
	return AnimRect->GetSize();
}
Pokemon::Pokemon(wstring Name, UINT maxhp, int hp, int att, int def, UINT level)
	:Name(Name), maxhp(maxhp), hp(hp), att(att), def(def), level(level)
{

	AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	IconRect= new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L".png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L"Icon.png");
	AnimRect->SetHeight(srcTex->GetHeight());
	AnimRect->SetWidth(srcTex->GetWidth() / 4);
	IconRect->SetHeight(IconTex->GetHeight());
	IconRect->SetWidth(IconTex->GetWidth() / 2);
	Animator* animator = new Animator;
	AnimationClip* Opponent_Animation = new AnimationClip(L"Opponent_Roar", srcTex, 2, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Opponent_Animation);
	Opponent_Animation = new AnimationClip(L"Opponent_IDLE", srcTex,1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.25f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Opponent_Animation);
	AnimationClip* Our_Animation = new AnimationClip(L"Our_Roar", srcTex, 2, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Our_Animation);
	Our_Animation = new AnimationClip(L"Our_IDLE", srcTex,1, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth()*0.75f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Our_Animation);
	AnimationClip* Icon_Animation = new AnimationClip(L"Icon", IconTex, 2, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 1.0f / 15.0f);
	
	animator->AddAnimClip(Opponent_Animation);
	animator->AddAnimClip(Our_Animation);
//	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Our_Roar");
	AnimRect->SetAnimation(animator);

	animator = new Animator;
	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Icon");
	IconRect->SetAnimation(animator);

	m_Pokeball = new PokeBall;

	

	
	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);

}
Pokemon::Pokemon(wstring Name, UINT maxhp, int hp, int att, int def, UINT level, UINT Speed)
	:Name(Name), maxhp(maxhp), hp(hp), att(att), def(def), level(level), Speed(Speed)

{
	AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	IconRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L".png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L"Icon.png");
	AnimRect->SetHeight(srcTex->GetHeight());
	AnimRect->SetWidth(srcTex->GetWidth() / 4);
	IconRect->SetHeight(IconTex->GetHeight());
	IconRect->SetWidth(IconTex->GetWidth() / 2);
	Animator* animator = new Animator;
	AnimationClip* Opponent_Animation = new AnimationClip(L"Opponent_Roar", srcTex, 2, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Opponent_Animation);
	Opponent_Animation = new AnimationClip(L"Opponent_IDLE", srcTex, 1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.25f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Opponent_Animation);
	AnimationClip* Our_Animation = new AnimationClip(L"Our_Roar", srcTex, 2, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Our_Animation);
	Our_Animation = new AnimationClip(L"Our_IDLE", srcTex, 1, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth() * 0.75f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Our_Animation);
	AnimationClip* Icon_Animation = new AnimationClip(L"Icon", IconTex, 2, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 1.0f / 15.0f);

	animator->AddAnimClip(Opponent_Animation);
	animator->AddAnimClip(Our_Animation);
	//	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Our_Roar");
	AnimRect->SetAnimation(animator);

	animator = new Animator;
	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Icon");
	IconRect->SetAnimation(animator);

	m_Pokeball = new PokeBall();
	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);

	NameFont = new CFont();
	NameFont->Init(Name);
	NameFont->Setsize();
	NameFont->SetRender(false);


	BattleNameFont = new CFont();
	BattleNameFont->Init(Name);
	BattleNameFont->Setsize();
	BattleNameFont->SetRender(false);

	IconNameFont = new CFont();
	IconNameFont->Init(Name);
	IconNameFont->Setsize();
	IconNameFont->SetRender(false);
	LevelFont = new CFont;
	wstring str = to_wstring(level);
	LevelFont->Init(str);	LevelFont->Setsize();
	LevelFont->SetRender(false);
	HpFont = new CFont;
	 str = to_wstring(hp);
	 HpFont->Init(str);	HpFont->Setsize();
	 HpFont->SetRender(false);
	 MaxHpFont = new CFont;
	 str = to_wstring(maxhp);
	 MaxHpFont->Init(str); MaxHpFont->Setsize();
	 MaxHpFont->SetRender(false);
}
void Pokemon::SetPos(const Vector3& pos)
{
	SetPosition(pos);
	AnimRect->SetPosition(pos);
	
	
}
void Pokemon::SetSize(const Vector3& size)
{
	AnimRect->SetSize(size); this->SetSz(size);
}
void Pokemon::StartAnimation(const wstring& _Name)
{
	AnimRect->GetAnimator()->SetCurrentAnimClip(_Name);
}
void Pokemon::SetIconPos(const Vector3& pos)
{
	IconRect->SetPosition(pos);

}
void Pokemon::SetIconSize(const Vector3& size)
{
	IconRect->SetSize(size);
}
Pokemon::~Pokemon()
{
	SAFE_DELETE(AnimRect);
	SAFE_DELETE(IconRect);
	SAFE_DELETE(m_Pokeball);
	for (size_t i = 0; i < m_vecSkill.size(); ++i)
		SAFE_DELETE(m_vecSkill[i]);
	SAFE_DELETE(HpBar);

	SAFE_DELETE(NameFont);
	SAFE_DELETE(IconNameFont);
	SAFE_DELETE(BattleNameFont);
	SAFE_DELETE(MaxHpFont);
	SAFE_DELETE(HpFont);
	SAFE_DELETE(LevelFont);
}
void Pokemon::Init(wstring Name, UINT maxhp, int hp, int att, int def, UINT level, wstring Path)
{
	AnimRect = new AnimationRect(Vector3(0.f,0.f,0.f),Vector3(0.f,0.f,0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + Name +L".png");

	AnimRect->SetHeight(srcTex->GetHeight());
	AnimRect->SetWidth(srcTex->GetWidth() / 4);
	Texture2D* IconTex = new Texture2D(TexturePath + Name+L"Icon.png");
	AnimationClip* Opponent_Animation = new AnimationClip(L"Opponent", srcTex, 2, Values::ZeroVec2, 
		Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()),0.5f);
	Opponent_Animation->SetRepeat(false);
	Opponent_Animation = new AnimationClip(L"Opponent_IDLE", srcTex, 1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.25f, srcTex->GetHeight()), 0.5f);
	AnimationClip* Our_Animation = new AnimationClip(L"Our", srcTex, 2, Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()),
		Vector2(srcTex->GetWidth() , srcTex->GetHeight()), 0.5f);
	Our_Animation->SetRepeat(false);
	Our_Animation = new AnimationClip(L"Our_IDLE", srcTex, 1, Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()),
		Vector2(srcTex->GetWidth()*0.75f, srcTex->GetHeight()), 0.5f);
	AnimationClip* Icon_Animation = new AnimationClip(L"Icon", IconTex, 2, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 0.2f);
	Animator* animator = new Animator;
	animator->AddAnimClip(Opponent_Animation);
	animator->AddAnimClip(Our_Animation);
	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Icon");
	AnimRect->SetAnimation(animator);
	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);


}

void Pokemon::Update()
{
	if (nullptr != m_Pokeball)
		m_Pokeball->Update();
	if (!bRender)
		return;
	AnimRect->Update();
	
	
}

void Pokemon::Render()
{
	if (nullptr != m_Pokeball)
		m_Pokeball->Render();
	if (!bRender)
		return;
	AnimRect->Render();

	

}

Pokemon::Pokemon(const Pokemon& _Other)
{
	this->Name = _Other.Name;
	this->maxhp = _Other.maxhp;
	this->hp = _Other.hp;
	this->att = _Other.att;
	this->def = _Other.def;
	this->level = _Other.level;
	this->Speed = _Other.Speed;
	this->AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	this->IconRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L".png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L"Icon.png");
	this->AnimRect->SetHeight(srcTex->GetHeight());
	this->AnimRect->SetWidth(srcTex->GetWidth() / 4);
	this->IconRect->SetHeight(IconTex->GetHeight());
	this->IconRect->SetWidth(IconTex->GetWidth() / 2);
	Animator* animator = new Animator;
	AnimationClip* Opponent_Animation = new AnimationClip(L"Opponent_Roar", srcTex, 2, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()), 0.6f);
	Opponent_Animation->SetRepeat(false);
	animator->AddAnimClip(Opponent_Animation);
	Opponent_Animation = new AnimationClip(L"Opponent_IDLE", srcTex, 1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.25f, srcTex->GetHeight()), 0.6f);
	animator->AddAnimClip(Opponent_Animation);
	AnimationClip* Our_Animation = new AnimationClip(L"Our_Roar", srcTex, 2, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 0.6f);
	Our_Animation->SetRepeat(false);
	animator->AddAnimClip(Our_Animation);
	Our_Animation = new AnimationClip(L"Our_IDLE", srcTex, 1, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth() * 0.75f, srcTex->GetHeight()), 0.6f);
	animator->AddAnimClip(Our_Animation);
	AnimationClip* Icon_Animation = new AnimationClip(L"Icon", IconTex, 2, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 1.2f);

	animator->AddAnimClip(Opponent_Animation);
	animator->AddAnimClip(Our_Animation);
	//	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Our_Roar");
	this->AnimRect->SetAnimation(animator);

	animator = new Animator;
	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Icon");
	this->IconRect->SetAnimation(animator);
	this->m_Pokeball = new PokeBall(*_Other.m_Pokeball);
	this->m_Pokeball->SetPokemon(this);
	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);
	for (int i = 0; i < _Other.m_vecSkill.size(); ++i) {
	
		CSkill* pSkill = new CSkill(*_Other.m_vecSkill[i]);
		pSkill->SetPokemon(this);
		this->m_vecSkill.push_back(pSkill);
		
	}
	this->IsNpc = _Other.IsNpc;
	HpBar = new ProgressBar(Vector3(405, 535, 1.0f), Vector3(98, 6, 0), 0.f, Color(0, 1, 0, 1), GI::LEFT_TO_RIGHT);
	HpBar->SetRender(false);
	

	this->NameFont = new CFont(*_Other.NameFont);
	this->BattleNameFont = new CFont(*_Other.BattleNameFont);
	this->BattleNameFont->SetPosition(Vector3(50, 462, 0), true);
	this->HpFont = new CFont(*_Other.HpFont);
	this->MaxHpFont = new CFont(*_Other.MaxHpFont);
	this->IconNameFont = new CFont(*_Other.IconNameFont);
	this->LevelFont = new  CFont(*_Other.LevelFont);

}

void Pokemon::PostRender()
{
	IconRect->Update();
	UpdateHpBar();
	HpBar->Update();
	IconNameFont->Update();
	HpBar->Render();
	IconRect->Render();
	IconNameFont->Render();
}

void Pokemon::AddSkill(const wstring& _Name, const SKILL_TYPE& _type, const UINT& _maxPP, const UINT& _curPP, const UINT& _dmg, bool _bAnim)
{
	if (m_vecSkill.size() >= MAXSKILLCOUNT)return;
	CSkill* pSkill = new CSkill(
		_Name, _type, _maxPP, _curPP, _dmg);
	pSkill->SetPokemon(this);
	pSkill->DoAnimation(_bAnim);

	m_vecSkill.push_back(pSkill);

}

void Pokemon::UpdateHpBar()
{
	float percent = (float)hp / (float) maxhp;
	HpBar->UpdateProgressBar(percent);
}

void Pokemon::SetOpponent()
{
	IsOpponent = true;
	m_Pokeball->SetOpponent();
}

void Pokemon::SetHpBarRender(const bool& _bRender)
{
	HpBar->SetRender(_bRender);
}
