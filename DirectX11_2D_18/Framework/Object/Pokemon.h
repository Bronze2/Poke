#pragma once
#include "CObject.h"
class PokeBall;
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
    SKILL m_sSkill[4];
    bool bRender = false;

    bool IsOpponent = false;
    PokeBall* m_Pokeball;
public:
    PokeBall* GetPokeBall() { return m_Pokeball; }
    UINT GetMaxHp() { return maxhp; }
    int GetHp() { return hp; }
    int GetAttack() { return att; }
    int GetDef() { return def; }
    UINT GetLevel() { return level; }
    UINT GetSpeed() { return Speed; }


    void SetRender(const bool& _bRender) { bRender = _bRender; }
    void SetOpponent();
    bool GetOpponent() { return IsOpponent; }
   
    class AnimationRect* GetAnimRect() { return AnimRect; }
    class AnimationRect* GetIconRect() { return IconRect; }
    Pokemon(wstring Name
        , UINT maxhp, int hp, int att, int def, UINT level);
    Pokemon(wstring Name
        , UINT maxhp, int hp, int att, int def, UINT level,UINT Speed);
    void SetPos(const Vector3& pos);
    void SetSize(const Vector3& size); 


    void StartAnimation(const wstring& _Name);


    void SetIconPos(const Vector3& pos);
    void SetIconSize(const Vector3& size);
    ~Pokemon();
    void Init(wstring Name
    ,UINT maxhp,int hp,int att,int def,UINT level,wstring Path);
    void Update();

    void Render();
    Pokemon(const Pokemon& _Other);


    const wstring& GetName() { return Name; }
    void Attack();
    void SkillAttack();
};

