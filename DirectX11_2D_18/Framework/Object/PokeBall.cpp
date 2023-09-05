#include "Framework.h"
#include "PokeBall.h"
#include "Geometries/AnimationRect.h"
#include "Pokemon.h"
bool PokeBall::GetAnimationEnd()
{
	return animationRect->GetAnimator()->GetEnd();
}
void PokeBall::Init()
{
}

void PokeBall::Update()
{
	

	if (m_bRender) {
		animationRect->Update();
		if (!bOpponent) {
			Vector3 pos = GetPos();
			pos.x += 100 * Time::Delta();
			if (!bReach)
			{
				pos.y += 200 * Time::Delta();
				if (pos.y > m_TopHeight)
					bReach = true;
			}
			else
				pos.y -= 200 * Time::Delta();
			SetPosition(pos);
			animationRect->SetPosition(pos);
		}
	}
}

void PokeBall::Render()
{
	if (m_bRender)
		animationRect->Render();
}



PokeBall::PokeBall()
{
	animationRect=new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Item/PokeBalls.png");
	animationRect->SetHeight(srcTex->GetHeight() / 4);
	animationRect->SetWidth(srcTex->GetWidth() / 23);
	Animator* animator = new Animator;
	AnimationClip* animation = new AnimationClip(L"Caught", srcTex, 23, Values::ZeroVec2,
		Vector2(srcTex->GetWidth(), animationRect->GetHeight()), 1.0f / 15.0f);
	animation->SetRepeat(false);
	animation->SetPause(true);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Throw", srcTex, 10, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() / 23 * 6, this->animationRect->GetHeight()), 0.5f);
	animation->SetRepeat(false);
	animation->SetPause(true);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Appear", srcTex, 3, Vector2(srcTex->GetWidth() / 23 * 7, 0.f),
		Vector2(srcTex->GetWidth() / 23 * 10, this->animationRect->GetHeight()), 0.5f);
	animation->SetRepeat(false);
	animation->SetPause(true);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"Throw");
	animationRect->SetAnimation(animator);
	SAFE_DELETE(srcTex);

}

PokeBall::PokeBall(const UINT& _Count)
{
}

PokeBall::~PokeBall()
{
	SAFE_DELETE(animationRect);
}

PokeBall::PokeBall(const PokeBall& _Ball)
{
	this->animationRect = new AnimationRect(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Item/PokeBalls.png");
	this->animationRect->SetHeight(srcTex->GetHeight() / 4);
	this->animationRect->SetWidth(srcTex->GetWidth() / 23);
	Animator* animator = new Animator;
	AnimationClip* animation = new AnimationClip(L"Caught", srcTex, 23, Values::ZeroVec2,
		Vector2(srcTex->GetWidth(), this->animationRect->GetHeight()),0.5f);
	animation->SetRepeat(false);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Throw", srcTex, 7, Values::ZeroVec2,
		Vector2(this->animationRect->GetWidth()*7, this->animationRect->GetHeight()),0.125);
	animation->SetRepeat(false);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Appear", srcTex, 3, Vector2(srcTex->GetWidth() / 23 * 7, 0.f),
		Vector2(srcTex->GetWidth() /23*10, this->animationRect->GetHeight()), 0.5f);
	animation->SetRepeat(false);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"Throw");
	this->animationRect->SetAnimation(animator);
	SAFE_DELETE(srcTex);
	this->m_bRender = _Ball.m_bRender;
	
	
}

void PokeBall::SetPos(const Vector3& _Position)
{
	SetPosition(_Position);
	animationRect->SetPosition(_Position);

}

void PokeBall::SetSize(const Vector3& _Size)
{
	animationRect->SetSize(_Size); this->SetSz(_Size);
}
