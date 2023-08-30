#pragma once
class Pokemon;
class PokemonMgr : public SingletonBase<PokemonMgr>
{
private:
	vector<Pokemon*>m_vecPokemon;

public:
	void Init();

	vector<Pokemon*>GetPokemons() { return m_vecPokemon; }
private:
	PokemonMgr();
	~PokemonMgr();
public:
	friend class SingletonBase<PokemonMgr>;
};

