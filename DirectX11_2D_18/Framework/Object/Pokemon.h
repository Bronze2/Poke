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
    class AnimationRect* IconRect;

public:

   
    class AnimationRect* GetAnimRect() { return AnimRect; }
    class AnimationRect* GetIconRect() { return IconRect; }
    Pokemon(wstring Name
        , UINT maxhp, int hp, int att, int def, UINT level);

    void SetPos(const Vector3& pos);
    void SetSize(const Vector3& size); 


    void StartAnimation(const wstring& _Name) { AnimRect->GetAnimator()->SetCurrentAnimClip(_Name); }


    void SetIconPos(const Vector3& pos);
    void SetIconSize(const Vector3& size);
    ~Pokemon();
    void Init(wstring Name
    ,UINT maxhp,int hp,int att,int def,UINT level,wstring Path);
    void Update();

    void Render();


};

