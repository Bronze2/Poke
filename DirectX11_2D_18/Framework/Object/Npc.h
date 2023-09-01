#pragma once
#include "CObject.h"
class Npc :
    public CObject
{
private:
    bool m_bBattle = true;

public:

    Npc();
    ~Npc();
};

