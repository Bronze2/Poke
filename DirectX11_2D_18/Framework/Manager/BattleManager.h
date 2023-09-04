#pragma once

class Player;
class Npc;

class BattleManager : public SingletonBase<BattleManager>
{

private:
	Player* m_Player;
	Npc* m_Npc;


private:

	BattleManager();
	~BattleManager();


public:
	void BattleStart(Player* _player, Npc* _npc);


public:
	friend class SingletonBase<BattleManager>;

};

