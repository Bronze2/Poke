#pragma once
#include "CObject.h"

class Player;
class Pokemon;


enum class NPC_STATE {
    IDLE,
    MOVE,
    DETECTION,
    BATTLE,
    END
};
class Npc :
    public CObject
{
private:
    bool m_bBattle = true;

    NPC_STATE m_eState = NPC_STATE::IDLE;
    bool IsDefeat = false;
private:
    wstring Name;
    class AnimationRect* AnimRect;
    class AnimationRect* BattleRect;
 
    vector<Pokemon*> m_vecPokemon;
    Player* player = nullptr;

    BATTLE_STATE m_eBattleState = BATTLE_STATE::NONE;

    Vector3 m_PrevPosition;
    Vector3 m_Position;
    Vector3 m_BattlePosition;
    UINT m_curPokemon = 0;

    bool bCurPokemonDead = false;
    bool bDefeatEffect = false;
    DIR m_eDir;
    Vector3 m_PrevBattlePosition;

private:
    void FDeadEffect();
public:
    void CurPokemonDead() { bCurPokemonDead = true; }
    void SetPrevPos(Vector3 _Pos) { m_PrevPosition = _Pos; }
    void SetBattlePrevPos(Vector3 _Pos) { m_PrevBattlePosition = _Pos; }
    Vector3 GetPrevPos() { return m_PrevPosition; }
    void SetDefeatEffect(const bool& _bDefeatEffect) {
        bDefeatEffect = _bDefeatEffect;
    }
    int GetDeadEffect() { return bDefeatEffect; }

    void FindPokemon();
    void SwapPokemon();
    void Roar();

    Pokemon* GetPokemons(UINT i) { return m_vecPokemon[i]; }
    Pokemon* GetCurPokemons() { return m_vecPokemon[m_curPokemon]; }
    class AnimationRect* GetAnimRect() { return AnimRect; }
    class AnimationRect* GetBattleRect() { return BattleRect; }
    void SetPosition(const Vector3& _Position);
    void SetBattlePosition(const Vector3& _Position);
    void SetSize(const Vector3& _Size);
    void SetBattleSize(const Vector3& _Size);
    Vector3 GetPos() { return m_Position; }
    void DoBehavior();
    void Move();

    void SetBattleMode() { m_eBattleState = BATTLE_STATE::BATTLE; }
    void SetIdleMode() { m_eBattleState = BATTLE_STATE::NONE; }


    void SetDefeat() { IsDefeat = true; }
    const bool& GetDefeat() { return IsDefeat; }
    Npc();
    virtual ~Npc();
    Npc(const wstring& _Name,bool bBattle=true);
    Npc(const Npc& _Other);
    void SetPlayer(Player* _pPlayer) { player = _pPlayer; }
    void AddPokemon(const wstring& Name, UINT maxhp, int hp, int att,
        int def, UINT level, UINT Speed);
    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void PostRender() {};
    virtual void GUI() {};
    
};

