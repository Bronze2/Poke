#pragma once

class Player;
class Npc;
class Item;
class UI;
class CFont;
class TextureObject;
class ProgressBar;
class BattleManager : public SingletonBase<BattleManager>
{

private:
	Player* m_Player;
	Npc* m_Npc;
	vector<Npc*> m_vecNpcs;

	BATTLE_CIR m_eCir=BATTLE_CIR::NONE;
	UI* BattlePhase;


	TextureObject* FightSelector;
	TextureObject* MediumSelector;
	TextureObject* SmallSelector;
	TextureObject* CancelSelector;

	TextureObject* OpponentHpBar;
	TextureObject* OurHpBar;
	
	vector<UI*> ourvecPokemon;

	TextureObject* OpponentDecorator;
	TextureObject* OurDecorator;
	ProgressBar* OurHpPoint;
	ProgressBar* OpponentHpPoint;


	TextureObject* BackGround;

	TextureObject* BattleItemBar;
	TextureObject* ItemSelector;
	UI* BackButton;

	UI* BattleChangeButton;




	bool bPlayerBehavior = false;
	BATTLE_BEHAVIOR playerbehavior;
	BATTLE_BEHAVIOR npcbehavior;
	bool bSpeedCheck = false;
	UINT m_iPhase = 0;
	bool bCast = false;
	bool bHitted = false;
	DWORD_PTR ptr;

	UINT m_iHitEffectCount = 0;
	std::chrono::steady_clock::time_point start;
	bool bHitEffectCheck = false;
	UINT bUpdateHpBar = 0;
	int m_iTempValue = 0;
	bool bHitSound = false;
	bool bEffectSound = false;
	bool bDeadCheck = false;
private:
	UINT m_iChangePokemon = 0;
public:
	void addChangePokemonPhase() { m_iChangePokemon += 1; }
	void SetChangePokemonPhase(const UINT& _phase) { m_iChangePokemon = _phase; }
	const UINT& ChangePokemonPhase() { return m_iChangePokemon; }

	vector<Npc*> GetNpcs();

	void NpcClear();

	void PushNPC(Npc* _pOther) { m_vecNpcs.push_back(_pOther); }

private:
	TextureObject* ChangeOrNotButton;
	Vector3 DeadSize;
	UINT DeadCount = 0;

	CFont* ChangeUse;
	CFont* ItemUse;
	bool bFightChange = false;
private:

	void UpdateHpBar();
	void UpdateHpBar(UINT _healValue);
	BattleManager();
	~BattleManager();

	void SelectorUpdate();
	void DeadEffect();


	bool OurChangePokemon = false;

	bool bBattleEnd = false;
public:


	void Reset();
	void SetBattleEnd() { bBattleEnd = true; }
	void PhaseReset() { m_iPhase = 0; bSpeedCheck = false; bDeadCheck = false; }
	bool GetOurChangePokemon() { return OurChangePokemon; }
	void SetOurChangePokemon(const bool& _bChange); 

	void  ChangeButtonRender(const bool& _bRender);
	void CancelSelectorRender(const bool& _bRender);
	void NPCCurDead();


	void OurHpBarRender(const bool& _bRender);

	void BackButtonAnimation();
	void OpponentHpBarRender(const bool& _bRender);
	void BattleAnimationButton(UINT _prev,UINT _now);
	void BattleAnimationChangeButton(UINT _prev, UINT _now);
	void ItemAnimationButton(UINT _prev, UINT _now);
	void RenderBattleItemBar(const bool& _bTrue);

	void RenderPokemonSelect();
	void NotRenderPokemonSelect();
	void RenderChangeButton(bool _bRender,bool _bRend=true);

	void NpcBehavior(const BATTLE_BEHAVIOR& _behavior) { npcbehavior = _behavior; }

	void StartHpBar();

	void PlayerBehavior(const BATTLE_BEHAVIOR& _behavior){playerbehavior=_behavior;}
	void DoBehavior(bool bTrue= true) { bPlayerBehavior = bTrue; }
	bool Getbehavior() { return bPlayerBehavior; }
	void DoBattlePhase();
	void PhaseIn();
	void PhaseOut();
	void AllReady();
	void SetCircumStance(const BATTLE_CIR& _State) { m_eCir =_State; }
	const BATTLE_CIR& GetCircumStance() { return m_eCir; }


	

	void HitEffect();
	Player* GetPlayer() { if (nullptr != m_Player)return m_Player; }
	Npc* GetNpc() { if (nullptr != m_Npc)return m_Npc; }
	void BattleStart(Player* _player, Npc* _npc);
	void BattleEnd(Player* _player, Npc* _npc);

	void NPCDefeat();

	void Update();
	void Render();
	void Init();
	float m_fDelta;
	void ItemSelectInit();
	
	void AddCurItemSelect() { m_iCuritemSelect++; }
	void SubCsurItemSelect() { m_iCuritemSelect--; }

	void GUI();
public:
	friend class SingletonBase<BattleManager>;

private:
	vector<Item*> DeleteItem ;
	vector<UI*> m_vecItemSelect;
	UINT bCodeCheck = false;// ������ Value��üũ
	vector<Item*> m_vecHealItem;
	vector<Item*> m_vecBallItem;
	UINT HealValue = 0;
	UINT HealHp = 0;
	UI* PrevButton;
	UI* NextButton;
	UINT m_iCuritemSelect = 0;

public:
	UINT GetCurItemSelect() { return m_iCuritemSelect; }
	vector<Item*> GetvecHealItem();
	void EraseItem(Item* item);
	vector<Item*> GetvecBallItem() { return m_vecBallItem; }
	void NotRenderBattleItemBar();// �������� ���
	void NotRenderBattleItemBar(const bool& _bTrue);// �������� ���
	void NextButtonUpdate(vector<Item*> _item); //������ ���� ��� ���� ��� Ȱ��ȭ 
	void PrevButtonUpdate(vector<Item*> _item);// ������ ���� ��� ���� ��� Ȱ��ȭ
	void NotRenderBattleItemBarBall(); //���ϸ� �����۸��
	void NotRenderBattleItemBarBall(const bool& _bTrue); 


private:




};

