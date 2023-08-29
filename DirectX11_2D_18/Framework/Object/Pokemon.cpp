#include "Framework.h"
#include "Pokemon.h"

#include "Geometries/AnimationRect.h"
Pokemon::Pokemon(wstring Name, UINT maxhp, int hp, int att, int def, UINT level)
	:Name(Name),maxhp(maxhp),hp(hp),att(att),def(def),level(level)
{
}
Pokemon::~Pokemon()
{
	SAFE_DELETE(AnimRect);
}
void Pokemon::Init(wstring Name, UINT maxhp, int hp, int att, int def, UINT level)
{
	AnimRect = new AnimationRect(Vector3(0.f,0.f,0.f),Vector3(0.f,0.f,0.f));
}

void Pokemon::Update()
{
	AnimRect->Update();
}

void Pokemon::Render()
{
	AnimRect->Render();
}

