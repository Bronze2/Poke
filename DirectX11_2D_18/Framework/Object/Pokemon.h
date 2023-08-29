#pragma once
#include "CObject.h"
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


    class AnimationRect* AnimRect;


public:
    Pokemon(wstring Name
        , UINT maxhp, int hp, int att, int def, UINT level);


    ~Pokemon();
    void Init(wstring Name
    ,UINT maxhp,int hp,int att,int def,UINT level,wstring Path);
    void Update();

    void Render();


};

