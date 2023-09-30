#pragma once
#include "CObject.h"
class Pokemon;
class Item;
class TMap;
class Player :
	public CObject
{
private:
	TMap* m_TMap;
	class AnimationRect* AnimRect;
	class AnimationRect* BattleRect;

	vector<Pokemon*> m_vecPokemon;

	DIR m_eDir;
	Vector3 m_PrevPos;

	BATTLE_STATE m_eBattleState = BATTLE_STATE::NONE;
	Vector3 m_Position;
	Vector3 m_BattlePosition;
	bool bPause = false;
	UINT m_curPokemon = 0;

	int m_iSelect = 0;

	SELECT_PHASE m_eSelect = SELECT_PHASE::NONE;
	bool bbehavior = false;
	UINT m_iChangePokemon;
	ITEM_SELECT bDetailItemSelect = ITEM_SELECT::NONE;
	vector<Item*> m_vecItem;
	Vector3 m_PrevPosition;
	Vector3 m_ArrivePosition;

	bool bMove = false; 
	bool bMoving = false;
private:
	void MapCheck(Vector3 _Position);

	void Moving();
public:


	ITEM_SELECT GetDetailItemSelect() { return bDetailItemSelect; }

	vector<Item*> GetvecItem() { return m_vecItem; }


	void SetTMap(TMap* _pMap) { m_TMap = _pMap; }

	void AddItem( Item* _Item);

	DIR  GetDir() { return m_eDir; }
	Vector3 GetPrevPos() { return m_PrevPos; }
	void SetPrevPos(Vector3 _Pos) { m_PrevPos = _Pos; }
	void Setbehavior(const bool& _be) { bbehavior = _be; }
	const bool& GetDobehavior() { return bbehavior; }
	vector<Pokemon*> GetPokemons() { return m_vecPokemon; }
	Pokemon* GetCurPokemons() { return m_vecPokemon[m_curPokemon]; }
	Vector3 GetPos() { return m_Position; }

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
	BATTLE_STATE GetBattleState() { return m_eBattleState; }

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

