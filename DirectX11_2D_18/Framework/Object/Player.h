#pragma once
#include "CObject.h"
class Pokemon;
class Player :
    public CObject
{
private:
	class AnimationRect* AnimRect;
	class AnimationRect* BattleRect;
	
	Pokemon* Pokemon[6];
	
public:

	
	
	void Move();


	virtual void Init() ;
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	Player();
	virtual ~Player();
};

