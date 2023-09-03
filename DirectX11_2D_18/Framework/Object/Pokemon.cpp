#include "Framework.h"
#include "Pokemon.h"

#include "Geometries/AnimationRect.h"
Pokemon::Pokemon(wstring Name, UINT maxhp, int hp, int att, int def, UINT level)
	:Name(Name), maxhp(maxhp), hp(hp), att(att), def(def), level(level)
{

	AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	IconRect= new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L".png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Monster/" + Name + L"Icon.png");
	AnimRect->SetHeight(srcTex->GetHeight());
	AnimRect->SetWidth(srcTex->GetWidth() / 4);
	IconRect->SetHeight(IconTex->GetHeight());
	IconRect->SetWidth(IconTex->GetWidth() / 2);
	Animator* animator = new Animator;
	AnimationClip* Opponent_Animation = new AnimationClip(L"Opponent_Roar", srcTex, 2, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.5f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Opponent_Animation);
	Opponent_Animation = new AnimationClip(L"Opponent_IDLE", srcTex,1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() * 0.25f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Opponent_Animation);
	AnimationClip* Our_Animation = new AnimationClip(L"Our_Roar", srcTex, 2, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Our_Animation);
	Our_Animation = new AnimationClip(L"Our_IDLE", srcTex,1, Vector2(srcTex->GetWidth() * 0.5f, 0.f),
		Vector2(srcTex->GetWidth()*0.75f, srcTex->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(Our_Animation);
	AnimationClip* Icon_Animation = new AnimationClip(L"Icon", IconTex, 2, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 1.0f / 15.0f);
	
	animator->AddAnimClip(Opponent_Animation);
	animator->AddAnimClip(Our_Animation);
//	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Our_Roar");
	AnimRect->SetAnimation(animator);

	animator = new Animator;
	animator->AddAnimClip(Icon_Animation);
	animator->SetCurrentAnimClip(L"Icon");
	IconRect->SetAnimation(animator);


	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);

}
void Pokemon::SetPos(const Vector3& pos)
{
	
	SetPosition(pos);
	AnimRect->SetPosition(pos);
	
}
void Pokemon::SetSize(const Vector3& size)
{
	AnimRect->SetSize(size); this->SetSz(size);
}
void Pokemon::StartAnimation(const wstring& _Name)
{
	AnimRect->GetAnimator()->SetCurrentAnimClip(_Name);
}
void Pokemon::SetIconPos(const Vector3& pos)
{
	IconRect->SetPosition(pos);

}
void Pokemon::SetIconSize(const Vector3& size)
{
	IconRect->SetSize(size);
}
Pokemon::~Pokemon()
{
	SAFE_DELETE(AnimRect);
	SAFE_DELETE(IconRect);
}
void Pokemon::Init(wstring Name, UINT maxhp, int hp, int att, int def, UINT level, wstring Path)
{
	AnimRect = new AnimationRect(Vector3(0.f,0.f,0.f),Vector3(0.f,0.f,0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + Name +L".png");

	AnimRect->SetHeight(srcTex->GetHeight());
	AnimRect->SetWidth(srcTex->GetWidth() / 4);
	Texture2D* IconTex = new Texture2D(TexturePath + Name+L"Icon.png");
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
	IconRect->Update();
}

void Pokemon::Render()
{
	AnimRect->Render();
	IconRect->Render();
}

