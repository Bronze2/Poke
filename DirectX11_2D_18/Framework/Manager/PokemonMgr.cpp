#include "Framework.h"
#include "PokemonMgr.h"
#include "Object/Pokemon.h"

void PokemonMgr::Init()
{
	Pokemon* pokemon = new Pokemon(L"Infernape",100,100,100,10,30);

	m_vecPokemon.push_back(pokemon);

}

PokemonMgr::PokemonMgr()
{
}

PokemonMgr::~PokemonMgr()
{
}
