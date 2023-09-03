#include "Framework.h"
#include "CSkill.h"

#include "Geometries/AnimationRect.h"

CSkill::CSkill(const wstring& _Name, const SKILL_TYPE& _type, const UINT& _maxPP, const UINT& _curPP, const UINT& _dmg)
{
	m_Skill.Name = _Name;
	m_Skill.m_eType = _type;
	m_Skill.maxPP = _maxPP;
	m_Skill.curPP = _curPP;
	m_Skill.Dmg = _dmg;
}

CSkill::~CSkill()
{
	SAFE_DELETE(AnimRect);
}

void CSkill::Update()
{
	if(m_bCast)
		if(nullptr!=AnimRect)
		AnimRect->Update();
}

void CSkill::Render()
{
	if (m_bCast)
		if (nullptr != AnimRect)
		AnimRect->Render();
}
