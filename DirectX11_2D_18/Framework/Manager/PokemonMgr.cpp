#include "Framework.h"
#include "PokemonMgr.h"
#include "Object/Pokemon.h"

void PokemonMgr::Init()
{
	Pokemon* pokemon = new Pokemon(L"Infernape",100,100,100,10,30);

	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bibarel", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bronzong", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);

	pokemon = new Pokemon(L"Floatzel", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Garchomp", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Giratina", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Gliscor", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Honchkrow", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Lopunny", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);

	pokemon = new Pokemon(L"Pachrisu", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Roserade", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Starraptor", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
}

PokemonMgr::PokemonMgr()
{
}

PokemonMgr::~PokemonMgr()
{
}
