#include "Framework.h"
#include "PokemonMgr.h"
#include "Object/Pokemon.h"

void PokemonMgr::Init()
{

}

PokemonMgr::PokemonMgr()
{
}

PokemonMgr::~PokemonMgr()
{
	for (int i = 0; i < m_vecPokemon.size(); ++i) {
		SAFE_DELETE(m_vecPokemon[i]);
	}
}
