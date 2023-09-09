#include "Framework.h"
#include "CSkill.h"
#include "Pokemon.h"
#include "Geometries/AnimationRect.h"

void CSkill::Cast()
{
	m_bCast = true;
	start = std::chrono::steady_clock::now();

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
}

CSkill::~CSkill()
{
	SAFE_DELETE(TypeRect);
	SAFE_DELETE(AnimRect);
}

void CSkill::Update()
{
	
	if(nullptr!= TypeRect)
		TypeRect->Update();
	if (nullptr != AnimRect)
		AnimRect->Update();

	if (m_bCast) {
		if (SKILL_MVTYPE::RIGHT == m_mvType)
		{
			if(!m_Pokemon->GetIsNpc()){
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
	}
	

}

void CSkill::Render()
{
	
	if (nullptr != TypeRect)
		TypeRect->Render();
	if (nullptr != AnimRect)
		AnimRect->Render();

}
