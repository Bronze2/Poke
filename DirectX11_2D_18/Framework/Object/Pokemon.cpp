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
void Pokemon::Init(wstring Name, UINT maxhp, int hp, int att, int def, UINT level, wstring Path)
{
	AnimRect = new AnimationRect(Vector3(0.f,0.f,0.f),Vector3(0.f,0.f,0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + Path+L".png");
	Texture2D* IconTex = new Texture2D(TexturePath + Path+L"Icon.png");
	AnimationClip* Opponent_Animation = new AnimationClip(L"Opponent", srcTex, 2, Values::ZeroVec2, 
		Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()), 1.0f / 15.0f);
	AnimationClip* Our_Animation = new AnimationClip(L"Our", srcTex, 2, Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()),
		Vector2(srcTex->GetWidth() , srcTex->GetHeight()), 1.0f / 15.0f);
	AnimationClip* Icon_Animation = new AnimationClip(L"Icon", IconTex, 2, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 1.0f / 15.0f);
	Animator* animator = new Animator;
	animator->AddAnimClip(Opponent_Animation);
	animator->AddAnimClip(Our_Animation);
	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Icon");
	AnimRect->SetAnimation(animator);
	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);

}

void Pokemon::Update()
{
	AnimRect->Update();
}

void Pokemon::Render()
{
	AnimRect->Render();
}

