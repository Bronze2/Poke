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


	BATTLE_STATE m_eBattleState = BATTLE_STATE::NONE;
	Vector3 m_Position;
	Vector3 m_BattlePosition;
	bool bPause = false;
	UINT m_curPokemon = 0;

	int m_iSelect = 0;

	SELECT_PHASE m_eSelect = SELECT_PHASE::NONE;
	bool bbehavior = false;
	UINT m_iChangePokemon;
	
public:

	void Setbehavior(const bool& _be) { bbehavior = _be; }
	const bool& GetDobehavior() { return bbehavior; }
	vector<Pokemon*> GetPokemons() { return m_vecPokemon; }
	Pokemon* GetCurPokemons() { return m_vecPokemon[m_curPokemon]; }


	void Roar();
	void Roar_BattleCir();
	void SetSelectPhase(const SELECT_PHASE& _ePhase) { m_eSelect = _ePhase; }

	const SELECT_PHASE& GetSelectPhase() { return m_eSelect; }
	class AnimationRect* GetAnimRect() { return AnimRect; }
	  class AnimationRect* GetBattleRect() { return BattleRect; }
	
	  const int& GetSelect() { return m_iSelect; }
	 void BattlePhase();

	void SetPosition(const Vector3& _Position);
	void SetSize(const Vector3& _Size);
	void SetBattlePosition(const Vector3& _Position);
	void SetBattleSize(const Vector3& _Size);
	
	void Move();

//	const UINT& GetSelect() { return m_iSelect; }
	void SetSelect(const UINT& _Select) { m_iSelect = _Select; }

	void SetBattleMode() { m_eBattleState = BATTLE_STATE::BATTLE; }
	void SetIdleMode(){ m_eBattleState = BATTLE_STATE::NONE; }


	bool bChangePokemon = false;
	virtual void Init() ;
	virtual void Update();
	virtual void Render();
	virtual void PostRender();
	virtual void GUI() {};
	Player();
	Player(const Player& _Other);
	virtual ~Player();
};

