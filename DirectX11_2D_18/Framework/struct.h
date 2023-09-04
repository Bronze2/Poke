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

