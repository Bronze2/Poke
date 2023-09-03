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
private:
    class AnimationRect* AnimRect;
    class AnimationRect* BattleRect;

    Pokemon* Pokemon[6];
    Player* player = nullptr;
public:

    Npc();
    virtual ~Npc();
    Npc(const wstring& _Name,bool bBattle=true);

    void SetPlayer(Player* _pPlayer) { player = _pPlayer; }

    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void PostRender() {};
    virtual void GUI() {};
    
};

