#pragma once
#include "CObject.h"
class Pokemon;

class CSkill:public CObject
{
private:
	SKILL m_Skill;
	class AnimationRect* TypeRect;
	class AnimationRect* AnimRect;
	bool m_bCast = false;
	Pokemon* m_Pokemon;
	SKILL_MVTYPE m_mvType=SKILL_MVTYPE::NONE;
	bool bMove = false;

	std::chrono::steady_clock::time_point start;
public:

	void SubCurPP() { if (m_Skill.curPP > 0)m_Skill.curPP-=1; }
	UINT GetCurPP() { return m_Skill.curPP; }
	bool GetCasting() { return m_bCast; }
	void Cast();
	void SetSkillMVRIGHType() { m_mvType = SKILL_MVTYPE::RIGHT; }
	void SetPokemon(Pokemon* _pPokemon) { m_Pokemon = _pPokemon; }
	void SetPos(const Vector3& _Pos);
	class AnimationRect* GetTypeTex() { return TypeRect; }
	CSkill(const CSkill& _Other);
	CSkill(const wstring& _Name, const SKILL_TYPE& _type,const UINT& _maxPP,const UINT& _curPP,const UINT& _dmg);
	~CSkill();
	
	virtual void Init() {};
	virtual void Update() ;
	virtual void Render();

};

