#pragma once

class Player;
class Npc;

class UI;
class TextureObject;
class BattleManager : public SingletonBase<BattleManager>
{

private:
	Player* m_Player;
	Npc* m_Npc;

	BATTLE_CIR m_eCir=BATTLE_CIR::NONE;
	UI* BattlePhase;
	TextureObject* FightSelector;
	TextureObject* MediumSelector;
	TextureObject* SmallSelector;
	TextureObject* CancelSelector;

	TextureObject* OpponentHpBar;
	TextureObject* OurHpBar;
	
	vector<UI*> ourvecPokemon;
	vector<UI*> opponentvecPokemon;
	TextureObject* OpponentDecorator;
	TextureObject* OurDecorator;


	TextureObject* BackGround;
	UI* ItemSelect;

	bool bPlayerBehavior = false;
	BATTLE_BEHAVIOR playerbehavior;
	BATTLE_BEHAVIOR npcbehavior;
	bool bSpeedCheck = false;
	UINT m_iPhase = 0;
	bool bCast = false;
	DWORD_PTR ptr;
private:

	BattleManager();
	~BattleManager();

	void SelectorUpdate();

public:

	void NpcBehavior(const BATTLE_BEHAVIOR& _behavior) { npcbehavior = _behavior; }

	void PlayerBehavior(const BATTLE_BEHAVIOR& _behavior){playerbehavior=_behavior;}
	void DoBehavior() { bPlayerBehavior = true; }
	bool Getbehavior() { return bPlayerBehavior; }
	void DoBattlePhase();
	void PhaseIn();
	void PhaseOut();
	void AllReady();
	void SetCircumStance(const BATTLE_CIR& _State) { m_eCir =_State; }
	const BATTLE_CIR& GetCircumStance() { return m_eCir; }


	Player* GetPlayer() { if (nullptr != m_Player)return m_Player; }
	Npc* GetNpc() { if (nullptr != m_Npc)return m_Npc; }
	void BattleStart(Player* _player, Npc* _npc);
	void BattleEnd(Player* _player, Npc* _npc);

	void NPCDefeat();

	void Update();
	void Render();
	void Init();
	float m_fDelta;


	void GUI();
public:
	friend class SingletonBase<BattleManager>;

};

