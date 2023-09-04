#include "Framework.h"
#include "Player.h"
#include "Geometries/AnimationRect.h"
#include "Manager/PokemonMgr.h"

#include "Pokemon.h"
void Player::SetPosition(const Vector3& _Position)
{
	m_Position = _Position;
	AnimRect->SetPosition(_Position);
}
void Player::SetBattlePosition(const Vector3& _Position)
{
	m_BattlePosition = _Position;
	BattleRect->SetPosition(_Position);
}
void Player::SetSize(const Vector3& _Size)
{
	AnimRect->SetSize(_Size); this->SetSz(_Size);
}
void Player::SetBattleSize(const Vector3& _Size)
{
	BattleRect->SetSize(_Size); this->SetSz(_Size);
}
void Player::Move()
{


}
void Player::Init()
{
	AnimRect = new AnimationRect(Vector3(0,0,0),Vector3(0,0,0));
	BattleRect = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Char/Player48.png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Char/PlayerBattle.png");
	AnimRect->SetHeight(srcTex->GetHeight()/5);
	AnimRect->SetWidth(srcTex->GetWidth() / 12);
	BattleRect->SetHeight(IconTex->GetHeight());
	BattleRect->SetWidth(IconTex->GetWidth() /4);
	Animator* animator = new Animator;
	AnimationClip* clip = new AnimationClip(L"IDLE_D", srcTex, 1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() /12.F, srcTex->GetHeight()*0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip= new AnimationClip(L"IDLE_U", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"IDLE_L", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight()*0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"IDLE_R", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight()*0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);

	clip = new AnimationClip(L"WALK_D", srcTex, 4, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_U", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_L", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_R", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);


	clip = new AnimationClip(L"RUN_D", srcTex, 4, Vector2(srcTex->GetWidth() / 3.0F, 0),
		Vector2(srcTex->GetWidth() /1.5f, srcTex->GetHeight() * 0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_U", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_L", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_R", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	AnimRect->SetAnimation(animator);
	animator->SetCurrentAnimClip(L"IDLE_D");
	animator = new Animator;
	clip = new AnimationClip(L"BATTLE", srcTex, 4, Values::ZeroVec2,
		Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
	
	animator->AddAnimClip(clip);
	animator->SetCurrentAnimClip(L"BATTLE");
	BattleRect->SetAnimation(animator);
	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);
}
Player::Player() {
	Pokemon* pokemon = new Pokemon(L"Infernape", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bibarel", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bronzong", 100, 100, 100, 10, 30);
	m_vecPokemon.push_back(pokemon);

}

Player::Player(const Player& _Other)
{
	for (int i = 0; i < _Other.m_vecPokemon.size(); ++i) {
		Pokemon* pokemon = new Pokemon(_Other.m_vecPokemon[i]->GetName(),
			_Other.m_vecPokemon[i]->GetMaxHp(), _Other.m_vecPokemon[i]->GetHp(), _Other.m_vecPokemon[i]->GetAttack()
			, _Other.m_vecPokemon[i]->GetDef(), _Other.m_vecPokemon[i]->GetLevel(), m_vecPokemon[i]->GetSpeed());

	}
}
Player::~Player() {

	SAFE_DELETE(AnimRect);
	SAFE_DELETE(BattleRect);


}



void Player::Update()
{

	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Update();
	}
	else {
		BattleRect->Update();
	}
}

void Player::Render()
{

	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Render();
	}
	else {
		BattleRect->Render();
	}
	
}
