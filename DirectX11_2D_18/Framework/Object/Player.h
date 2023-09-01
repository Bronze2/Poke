#pragma once
#include "CObject.h"
class Player :
    public CObject
{
private:
	class AnimationRect* AnimRect;
	class AnimationRect* BattleRect;
public:


	virtual void Init() ;
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	Player();
	virtual ~Player();
};

