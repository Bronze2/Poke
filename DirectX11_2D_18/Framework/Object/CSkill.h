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
public:
	void SetPos(const Vector3& _Pos);
	class AnimationRect* GetTypeTex() { return TypeRect; }
	CSkill(const CSkill& _Other);
	CSkill(const wstring& _Name, const SKILL_TYPE& _type,const UINT& _maxPP,const UINT& _curPP,const UINT& _dmg);
	~CSkill();
	void SetPokemon(Pokemon* _pPokemon) { m_Pokemon = _pPokemon; }
	virtual void Init() {};
	virtual void Update() ;
	virtual void Render();

};

