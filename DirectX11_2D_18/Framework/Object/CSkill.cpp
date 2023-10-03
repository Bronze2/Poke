#include "Framework.h"
#include "CSkill.h"
#include "Pokemon.h"
#include "Geometries/AnimationRect.h"
#include "UI/CFont.h"


void CSkill::AnimationInit()
{
	if (bAnim) {
		Texture2D* srcTex = nullptr;
		if (m_Skill.Name == L"Burn") {
			AnimRect= new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
			 srcTex = new Texture2D(TexturePath + L"Pokemon/Effect/Burn.png");
			float height = srcTex->GetHeight(); float Width = srcTex->GetWidth() /5;
			AnimRect->SetHeight(height);
			AnimRect->SetWidth(Width);
			Animator* animator = new Animator;
			AnimationClip*  clip = new AnimationClip(L"Burn", srcTex, 5,Values::ZeroVec2 ,
				Vector2(srcTex->GetWidth(), height), 0.125f);
			clip->SetRepeat(false);
			animator->AddAnimClip(clip);
			animator->SetCurrentAnimClip(L"Burn");
			animator->SetPause(true);

			AnimRect->SetAnimation(animator);
		}

		if (m_Skill.Name == L"DRAGONCLAW") {
			AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
			srcTex = new Texture2D(TexturePath + L"Pokemon/Effect/DragonClaw01.png");
			float height = srcTex->GetHeight(); float Width = srcTex->GetWidth() / 8;
			AnimRect->SetHeight(height);
			AnimRect->SetWidth(Width);
			Animator* animator = new Animator;
			AnimationClip* clip = new AnimationClip(L"DragonClaw", srcTex, 8, Values::ZeroVec2,
				Vector2(srcTex->GetWidth(), height), 0.125f);
			clip->SetRepeat(false);
			animator->AddAnimClip(clip);
			animator->SetCurrentAnimClip(L"DragonClaw");
			animator->SetPause(true);

			AnimRect->SetAnimation(animator);
		}
		SAFE_DELETE(srcTex);
	}
}

void CSkill::Cast()
{
	m_bCast = true;
	start = std::chrono::steady_clock::now();

	if (nullptr != AnimRect)
		AnimRect->GetAnimator()->ResetCurrentFrameCount();
}

void CSkill::SetPos(const Vector3& _Pos)
{

	TypeRect->SetPosition(_Pos);
}

CSkill::CSkill(const CSkill& _Other)
{
	m_Skill.Name = _Other.m_Skill.Name;
	m_Skill.m_eType = _Other.m_Skill.m_eType;
	this->TypeRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Battle/BattleUI/BattleSkillType.png");

	float height = srcTex->GetHeight() / 3; float Width = srcTex->GetWidth() / 6;
	this->TypeRect->SetHeight(height);
	this->TypeRect->SetWidth(Width);

	Animator* animator = new Animator;
	AnimationClip* clip = nullptr;
	switch (m_Skill.m_eType)
	{
	case SKILL_TYPE::NORMAL:
	{
		clip = new AnimationClip(L"NORMAL", srcTex, 1, Vector2(Width * 2, height),
			Vector2(Width * 3, height * 2), 1.0f / 15.0f);
	}
	break;
	case SKILL_TYPE::FIRE:
	{
		clip = new AnimationClip(L"FIRE", srcTex, 1, Vector2(Width * 4, height * 2),
			Vector2(Width * 5, height * 3), 1.0f / 15.0f);
	}
	break;
	default:
		break;
	}
	animator->AddAnimClip(clip);
	animator->SetCurrentAnimClip(clip->GetName());
	TypeRect->SetAnimation(animator);
	m_Skill.maxPP = _Other.m_Skill.maxPP;
	m_Skill.curPP = _Other.m_Skill.curPP;
	m_Skill.Dmg = _Other.m_Skill.Dmg;
	this->m_mvType = _Other.m_mvType;
	SAFE_DELETE(srcTex);
	this->m_mvType = _Other.m_mvType;
	this->bAnim = _Other.bAnim;
	this->AnimationInit();

	this->NameFont = new CFont(*_Other.NameFont);
	this->BattleNameFont = new CFont(*_Other.BattleNameFont);
	this->BattleNameFont->SetPosition(Vector3(50, 435, 0), true);
	this->CurPPFont = new CFont(*_Other.CurPPFont);
	this->MaxPPFont = new CFont(*_Other.MaxPPFont);
}

CSkill::CSkill(const wstring& _Name, const SKILL_TYPE& _type, const UINT& _maxPP, const UINT& _curPP, const UINT& _dmg)
{
	m_Skill.Name = _Name;
	m_Skill.m_eType = _type;
	TypeRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Battle/BattleUI/BattleSkillType.png");

	float height = srcTex->GetHeight() / 3; float Width = srcTex->GetWidth() / 6;
	TypeRect->SetHeight(height);
	TypeRect->SetWidth(Width);
	
	Animator* animator = new Animator;
	AnimationClip* clip = nullptr;
	switch (m_Skill.m_eType)
	{
	case SKILL_TYPE::NORMAL:
	{
		 clip = new AnimationClip(L"NORMAL", srcTex, 1,Vector2(Width*2,height),
			 Vector2(Width * 3, height*2), 1.0f / 15.0f);
	}
		break;
	case SKILL_TYPE::FIRE:
	{
		clip = new AnimationClip(L"FIRE", srcTex, 1, Vector2(Width *4, height*2),
			Vector2(Width * 5, height * 3), 1.0f / 15.0f);
	}
		break;
	default:
		break;
	}
	animator->AddAnimClip(clip);
	animator->SetCurrentAnimClip(clip->GetName());
	TypeRect->SetAnimation(animator);
	m_Skill.maxPP = _maxPP;
	m_Skill.curPP = _curPP;
	m_Skill.Dmg = _dmg;
	SAFE_DELETE(srcTex);
	NameFont = new CFont;
	NameFont->Init(m_Skill.Name, m_Skill.Name.size());

	BattleNameFont = new CFont; BattleNameFont->Init(m_Skill.Name, m_Skill.Name.size());
	BattleNameFont->Setsize(); BattleNameFont->SetRender(false);
	
	CurPPFont = new CFont;
	wstring wstr = to_wstring(m_Skill.curPP);
	CurPPFont->Init(wstr,wstr.size());

	MaxPPFont = new CFont;
	wstr = to_wstring(m_Skill.maxPP);
	MaxPPFont->Init(wstr,wstr.size());

}

CSkill::~CSkill()
{
	SAFE_DELETE(TypeRect);
	SAFE_DELETE(AnimRect);

	SAFE_DELETE(NameFont);
	SAFE_DELETE(BattleNameFont);
	SAFE_DELETE(CurPPFont);
	SAFE_DELETE(MaxPPFont);

}

void CSkill::Update()
{
	
	if(nullptr!= TypeRect)
		TypeRect->Update();
	if (nullptr != AnimRect)
		if(m_bCast)
		AnimRect->Update();

	if (m_bCast) {
		if (SKILL_MVTYPE::RIGHT == m_mvType)
		{
			if(!m_Pokemon->GetOpponent()){
			std::chrono::duration<double> p =chrono::steady_clock::now() - start;
			if (p.count() >= 0.5f) {
				if (!bMove)
				{
					bMove = true;
					Vector3 vPos = m_Pokemon->GetPos();
					vPos.x += 60;
					m_Pokemon->SetPos(vPos);
					start = chrono::steady_clock::now();
				}
				else {
					Vector3 vPos = m_Pokemon->GetPos();
					vPos.x -= 60;
					m_Pokemon->SetPos(vPos);
					bMove = false;
					m_bCast = false;

				}
			}
			}
			else {
				std::chrono::duration<double> p = chrono::steady_clock::now() - start;
				if (p.count() >= 0.5f) {
					if (!bMove)
					{
						bMove = true;
						Vector3 vPos = m_Pokemon->GetPos();
						vPos.x -= 60;
						m_Pokemon->SetPos(vPos);
						start = chrono::steady_clock::now();
					}
					else {
						Vector3 vPos = m_Pokemon->GetPos();
						vPos.x += 60;
						m_Pokemon->SetPos(vPos);
						bMove = false;
						m_bCast = false;

					}
				}
			}
		}
		else {
			if (bAnim) {
				if (AnimRect->GetAnimator()->GetEnd()) {
					m_bCast = false;
					AnimRect->GetAnimator()->SetPause(true);
				}


			}


		}
	}
	NameFont->Update();
	CurPPFont->Update();
	MaxPPFont->Update();
	


}

void CSkill::Render()
{
	
	if (nullptr != TypeRect)
		TypeRect->Render();
	NameFont-> Render();
	CurPPFont->Render();
	MaxPPFont->Render();
	

}

void CSkill::SkillRender()
{
	if (nullptr != AnimRect)
		if (m_bCast)
			AnimRect->Render();
}
