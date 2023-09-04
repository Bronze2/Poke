#pragma once
#include "CObject.h"
class Pokemon;
class Player :
    public CObject
{
private:
	class AnimationRect* AnimRect;
	class AnimationRect* BattleRect;
	
	vector<Pokemon*> m_vecPokemon;
	

	BATTLE_STATE m_eBattleState=BATTLE_STATE::NONE;
	Vector3 m_Position;
	Vector3 m_BattlePosition;


public:  
	class AnimationRect* GetAnimRect() { return AnimRect; }
	  class AnimationRect* GetBattleRect() { return BattleRect; }
	
	void SetPosition(const Vector3& _Position);
	void SetBattlePosition(const Vector3& _Position);
	void SetSize(const Vector3& _Size);
	void SetBattleSize(const Vector3& _Size);
	
	void Move();


	virtual void Init() ;
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	Player();
	Player(const Player& _Other);
	virtual ~Player();
};

