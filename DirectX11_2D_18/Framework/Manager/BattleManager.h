#pragma once

class Player;
class Npc;

class BattleManager : public SingletonBase<BattleManager>
{

private:


private:

	BattleManager();
	~BattleManager();


public:
	void BattleStart(Player* _player, Npc* _npc);


public:
	friend class SingletonBase<BattleManager>;

};

