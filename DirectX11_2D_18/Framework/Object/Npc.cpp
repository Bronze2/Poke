#include "Framework.h"
#include "Npc.h"
#include "Geometries/AnimationRect.h"

Npc::Npc()
{
}

Npc::~Npc()
{
}

Npc::Npc(const wstring& _Name, bool bBattle)
{
	if (bBattle) {
		AnimRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
		BattleRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
		Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Char/" + _Name + L".png");
		Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Char/" + _Name + L"Battle.png");
		AnimRect->SetHeight(srcTex->GetHeight()/5);
		AnimRect->SetWidth(srcTex->GetWidth() / 12);
		BattleRect->SetHeight(IconTex->GetHeight());
		BattleRect->SetWidth(IconTex->GetWidth() );
		Animator* animator = new Animator;
		AnimationClip* clip = new AnimationClip(L"IDLE_D", srcTex, 1, Values::ZeroVec2,
			Vector2(srcTex->GetWidth() / 4.F, srcTex->GetHeight() /3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_U", srcTex, 1, Vector2(srcTex->GetWidth() / 4.F, 0.f),
			Vector2(srcTex->GetWidth() / 2.f, srcTex->GetHeight() /3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_L", srcTex, 1, Vector2(srcTex->GetWidth() / 2.f, 0.f),
			Vector2(srcTex->GetWidth() *0.75f, srcTex->GetHeight()/3.f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"IDLE_R", srcTex, 1, Vector2(srcTex->GetWidth() * 0.75f, 0.f),
			Vector2(srcTex->GetWidth() , srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(L"WALK_U", srcTex, 2, Vector2(0.f, srcTex->GetHeight() / 3.f),
			Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 1.5f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_D", srcTex, 2, Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 3.f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight() /1.5f), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_L", srcTex, 2, Vector2(0.f, srcTex->GetHeight() / 1.5f),
			Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() ), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(L"WALK_R", srcTex, 2, Vector2(srcTex->GetWidth() / 2.0F, srcTex->GetHeight() / 1.5f),
			Vector2(srcTex->GetWidth(), srcTex->GetHeight() ), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		AnimRect->SetAnimation(animator);
		animator = new Animator;
		clip = new AnimationClip(L"BATTLE", srcTex, 4, Values::ZeroVec2,
			Vector2(srcTex->GetWidth(), srcTex->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(clip);
		BattleRect->SetAnimation(animator);


		SAFE_DELETE(srcTex);
		SAFE_DELETE(IconTex);
	}
}

void Npc::Init()
{
}

void Npc::Update()
{
}

void Npc::Render()
{
}
