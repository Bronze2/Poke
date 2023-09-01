#include "Framework.h"
#include "Player.h"
#include "Geometries/AnimationRect.h"
void Player::Init()
{
	AnimRect = new AnimationRect(Vector3(0,0,0),Vector3(0,0,0));
	BattleRect = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));

	
	Animator* animator = new Animator;


}
Player::Player() {

}

Player::~Player() {

	SAFE_DELETE(AnimRect);
	SAFE_DELETE(BattleRect);


}



void Player::Update()
{
}

void Player::Render()
{
}
