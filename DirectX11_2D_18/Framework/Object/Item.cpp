#include "Framework.h"
#include "Item.h"
#include "Geometries/AnimationRect.h"
#include "Utilities/Animator.h"
Item::Item()
{
}
Item::~Item()
{
	SAFE_DELETE(AnimRect);
}
Item::Item(const Item& _Other)
{
	this->Width = _Other.Width;
	this->Height = _Other.Height;
	this->m_sItem = _Other.m_sItem;
	this->AnimInit(this->Width, this->Height);


}

void Item::AnimInit(UINT _Width, UINT _Height)
{
	Width = _Width;
	Height = _Height;
	AnimRect = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Item/Item.png");
	AnimRect->SetWidth(srcTex->GetWidth() / 10);
	AnimRect->SetHeight(srcTex->GetHeight() /28);
	Animator* animator = new Animator;
	AnimationClip* clip = new AnimationClip(
		m_sItem.Name, srcTex, 1, Vector2(AnimRect->GetWidth() *(Width-1), AnimRect->GetHeight()*(Height-1)),
		Vector2(AnimRect->GetWidth(),
			AnimRect->GetHeight()), 1.f
	);
	animator->AddAnimClip(clip);
	animator->SetCurrentAnimClip(m_sItem.Name);
	AnimRect->SetAnimation(animator);


	SAFE_DELETE(srcTex);
}																																																																																																																																																																																																																																											

void Item::Update()
{
	AnimRect->Update();

}

void Item::Render()
{
	AnimRect->Render();
}
