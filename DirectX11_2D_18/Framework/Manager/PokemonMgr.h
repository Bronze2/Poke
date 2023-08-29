#pragma once
class Pokemon;
class PokemonMgr : public SingletonBase<PokemonMgr>
{
private:
	vector<Pokemon*>m_vecPokemon;

public:


private:
	PokemonMgr();
	~PokemonMgr();
public:
	friend class SingletonBase<PokemonMgr>;
};

