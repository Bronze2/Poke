#pragma once
#include "CObject.h"
class PokeBall;
class CSkill;
class Pokemon :
    public CObject
{
private:
    wstring Name;
    UINT maxhp;
    int hp;
    int att;
    int def;
    UINT level;
    UINT Speed;
    bool CanBattle = true;

    class AnimationRect* AnimRect;
    class AnimationRect* IconRect;
    vector<CSkill*> m_vecSkill;
    bool bRender = false;

    bool IsOpponent = false;
    PokeBall* m_Pokeball;
public:
    PokeBall* GetPokeBall() { return m_Pokeball; }
    UINT GetMaxHp() { return maxhp; }
    int GetHp() { return hp; }

    void SetHp(const int& _hp) { hp = _hp; }
    int GetAttack() { return att; }
    int GetDef() { return def; }
    UINT GetLevel() { return level; }
    UINT GetSpeed() { return Speed; }


    void UpdateHpBar();

    class ProgressBar* HpBar;
    void SetRender(const bool& _bRender) { bRender = _bRender; }
    void SetOpponent();
    bool GetOpponent() { return IsOpponent; }
    class ProgressBar* GetBar() { return HpBar; }
    void SetHpBarRender(const bool& _bRender);
   
    class AnimationRect* GetAnimRect() { return AnimRect; }
    class AnimationRect* GetIconRect() { return IconRect; }
    Vector3 GetAnimationSize();
    Pokemon(wstring Name
        , UINT maxhp, int hp, int att, int def, UINT level);
    Pokemon(wstring Name
        , UINT maxhp, int hp, int att, int def, UINT level,UINT Speed);
    void SetPos(const Vector3& pos);
    void SetSize(const Vector3& size); 

    vector<CSkill*> GetSkills() { return m_vecSkill; }

    void StartAnimation(const wstring& _Name);


    void SetIconPos(const Vector3& pos);
    void SetIconSize(const Vector3& size);
    ~Pokemon();
    void Init(wstring Name
    ,UINT maxhp,int hp,int att,int def,UINT level,wstring Path);
    void Update();

    void Render();
    Pokemon(const Pokemon& _Other);

    void PostRender();
    void AddSkill(const wstring& _Name, const SKILL_TYPE& _type, const UINT& _maxPP, const UINT& _curPP, const UINT& _dmg);

    const wstring& GetName() { return Name; }
    void Attack();
    void SkillAttack();
};

