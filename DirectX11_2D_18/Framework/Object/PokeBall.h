#pragma once
#include "CObject.h"
class PokeBall :
    public CObject
{
private:
    class Pokemon* pokemon;
    class AnimationRect* animationRect;
    bool m_bRender = false;
    bool bOpponent = false;
    float m_TopHeight;
    bool bReach = false;

public:
    void SetOpponent() { bOpponent = true; }
    void SetPokemon(Pokemon* _pPokemon) { pokemon = _pPokemon; }
    class AnimationRect* GetAnimRect() { return animationRect; }
    void SetTopHeight(const float& TopHeight) { m_TopHeight = TopHeight; }


    bool GetAnimationEnd();
    void Init();
    virtual void Update();
    virtual void Render();
    PokeBall();
    PokeBall(const UINT& _Count);
    ~PokeBall();
    PokeBall(const PokeBall& _Ball);
    void SetPos(const Vector3& _Position);
    void SetSize(const Vector3& _Size);
    void SetRender(const bool& _bRender) { m_bRender = _bRender; }
};

