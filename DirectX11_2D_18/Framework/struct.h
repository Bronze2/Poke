#pragma once

enum class SKILL_TYPE {
	NORMAL,
	GROUND,
	WATER,
	GHOST,
	BUG,
	FIGHT,
	PSYCHC,
	GRASS,
	DARK,
	POISON,
	ELCTR,
	WHAT,
	STEEL,
	ROCK,
	DRAGON,
	FLYING,
	FIRE,
	ICE,

};

enum class BATTLE_STATE {
	NONE,
	BATTLE,

};
enum class BATTLE_CIR {
	NONE,
	N_READY,
	N_ROAR,
	P_READY,
	P_ROAR,
	ALL_READY,
	P_PHASE,
	N_PHASE,
	BATTLE_END,
};

struct SKILL {
	SKILL_TYPE m_eType;
	wstring Name;
	UINT maxPP;
	UINT curPP;
	UINT Dmg;
};

struct tEvent {
	EVENT_TYPE eEvent;
	DWORD_PTR wParam;
	DWORD_PTR lParam;
};
struct Poke {

};


enum class SELECT_PHASE {
	NONE,
	COMPREHENSIVE,
	SKILL,
	ITEM,
	POKEMON,
	RUN,
};