#include "Framework.h"
#include "CFont.h"
#include "Geometries/AnimationRect.h"



void CFont::Setsize(const Vector3& _size)
{
	
}

void CFont::Setsize()
{
	Width = Font[0]->GetWidth();
	Height = Font[0]->GetHeight();
	for (int i = 0; i < 10; ++i) {
		Font[i]->SetSize(Vector3(Font[i]->GetWidth() , Font[i]->GetHeight() , 0.f));
	}
}

Vector3 CFont::GetPosition()
{
	return Font[0]->GetPosition();
}

void CFont::SetPosition(const Vector3& _Positon)
{
	for (size_t i = 0; i < Name.size(); ++i) {
		Font[i]->SetPosition(Vector3(_Positon.x + (i * (Font[i]->GetWidth())), _Positon.y,0.f));
	}
}

void CFont::SetPosition(const Vector3& _Positon, bool bTrue)
{
	for (size_t i = 0; i < Name.size(); ++i) {
		Font[i]->SetPosition(Vector3(_Positon.x + (i * (Font[i]->GetWidth()/2)), _Positon.y, 0.f));
	}
}

CFont::CFont()
{
}

CFont::CFont(wstring _Name)
{
}

CFont::~CFont()
{
	for (int i = 0; i <10; ++i)
		SAFE_DELETE(Font[i]);
}

CFont::CFont(const CFont& _Other)
{
	Name = _Other.Name;
	bRender = _Other.bRender;
	Width = _Other.Width;
	Height = _Other.Height;
	for (size_t i = 0; i < 10; ++i) {
		Font[i] = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));
		Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Battle/BattleUI/BattleFont.png");
		Font[i]->SetWidth(srcTex->GetWidth() / 10);
		Font[i]->SetHeight(srcTex->GetHeight() / 7);
		Font[i]->SetSize(Vector3(Width, Height, 0.f));
		Animator* animator = new Animator;
		AnimationClip* clip = nullptr;
		clip = new AnimationClip(
			L"A", srcTex, 1, Values::ZeroVec2,
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"a", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"B", srcTex, 1, Vector2(Font[i]->GetWidth(), 0.f),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"b", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);


		clip = new AnimationClip(
			L"C", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, 0.f),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);


		clip = new AnimationClip(
			L"c", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"D", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, 0.f),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"d", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"E", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, 0.f),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(
			L"e", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"F", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, 0.f),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"f", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"G", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, 0.f),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight()), 1.f);

		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"g", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 4), 1.f);

		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"H", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, 0.f),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"h", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"I", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, 0.f),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"i", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"J", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, 0.f),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"j", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"K", srcTex, 1, Vector2(0.f, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"k", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"L", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"l", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"M", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"m", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"N", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"n", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"O", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"o", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"P", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"p", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Q", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"q", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"R", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"r", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"S", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"s", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"T", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"t", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"U", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"u", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"V", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"v", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"W", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"w", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"X", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"x", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Y", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"y", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Z", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"z", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"0", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"1", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"2", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"3", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"4", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"5", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"6", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"7", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"8", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"9", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"NULL", srcTex, 1, Values::ZeroVec2,
			Values::ZeroVec2, 1.f);
		animator->AddAnimClip(clip);
		if (i < Name.size()) {
			wstring str{ Name[i] };
			animator->SetCurrentAnimClip(str);
			Font[i]->SetAnimation(animator);

		}
		else {
			animator->SetCurrentAnimClip(L"NULL");
			Font[i]->SetAnimation(animator);
		}



		SAFE_DELETE(srcTex);


	}

}

void CFont::SetName(const wstring& _Name)
{
	if (Name.size() != _Name.size()) {
		if (Name.size() > _Name.size()) {
			for (size_t i = 0; i < _Name.size(); ++i) {

				if (Name[i] != _Name[i])
				{
					wstring str{ _Name[i] };
					Font[i]->GetAnimator()->SetCurrentAnimClip(str);
				}
			}

			for (size_t i = _Name.size() - 1; i < Name.size(); ++i) {
				Font[i]->GetAnimator()->SetCurrentAnimClip(L"NULL");
			}
		}
		else {
			Name = _Name;
			for (size_t i = 0; i < _Name.size(); ++i) {
				wstring str{ _Name[i] };
				Font[i]->GetAnimator()->SetCurrentAnimClip(str);
				
			}
		}
	}
	else {

		for (size_t i = 0; i < _Name.size(); ++i) {

			if (Name[i] != _Name[i])
			{
				wstring str{ _Name[i] };
				Font[i]->GetAnimator()->SetCurrentAnimClip(str);
			}
		}
	}
	Name = _Name;
	
}

void CFont::Init(wstring _Name)
{
	Name = _Name;
	for (size_t i = 0; i <10; ++i) {
		Font[i] = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));
		Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Battle/BattleUI/BattleFont.png");
		Font[i]->SetWidth(srcTex->GetWidth() / 10);
		Font[i]->SetHeight(srcTex->GetHeight() / 7);
		Font[i]->SetSize(Vector3(Font[i]->GetWidth(), Font[i]->GetHeight(), 0.f));
		Width = Font[i]->GetWidth()*2;
		Height = Font[i]->GetHeight()*2;
		Animator* animator = new Animator;
		AnimationClip* clip = nullptr;
		clip = new AnimationClip(
			L"A", srcTex, 1, Values::ZeroVec2,
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"a", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"B", srcTex, 1, Vector2(Font[i]->GetWidth(), 0.f),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"b", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);


		clip = new AnimationClip(
			L"C", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, 0.f),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);


		clip = new AnimationClip(
			L"c", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"D", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, 0.f),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"d", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"E", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, 0.f),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(
			L"e", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"F", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, 0.f),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"f", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"G", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, 0.f),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight()), 1.f);

		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"g", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 4), 1.f);

		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"H", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, 0.f),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"h", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"I", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, 0.f),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"i", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"J", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, 0.f),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"j", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 3),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"K", srcTex, 1, Vector2(0.f, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"k", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"L", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"l", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"M", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"m", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"N", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"n", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"O", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"o", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"P", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"p", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Q", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"q", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"R", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"r", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"S", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"s", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"T", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight()),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"t", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 4),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"U", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"u", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"V", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"v", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"W", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"w", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"X", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"x", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Y", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"y", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Z", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 2),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"z", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 5),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"0", srcTex, 1, Vector2(0.f, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"1", srcTex, 1, Vector2(Font[i]->GetWidth(), Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"2", srcTex, 1, Vector2(Font[i]->GetWidth() * 2, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"3", srcTex, 1, Vector2(Font[i]->GetWidth() * 3, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"4", srcTex, 1, Vector2(Font[i]->GetWidth() * 4, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"5", srcTex, 1, Vector2(Font[i]->GetWidth() * 5, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"6", srcTex, 1, Vector2(Font[i]->GetWidth() * 6, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"7", srcTex, 1, Vector2(Font[i]->GetWidth() * 7, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"8", srcTex, 1, Vector2(Font[i]->GetWidth() * 8, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"9", srcTex, 1, Vector2(Font[i]->GetWidth() * 9, Font[i]->GetHeight() * 6),
			Vector2(Font[i]->GetWidth() * 10, Font[i]->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(
			L"NULL", srcTex, 1, Values::ZeroVec2,
			Values::ZeroVec2, 1.f);
		animator->AddAnimClip(clip);
		if (i < Name.size()) {
			wstring str{ Name[i] };
			animator->SetCurrentAnimClip(str);
			Font[i]->SetAnimation(animator);

		}
		else {
			animator->SetCurrentAnimClip(L"NULL");
			Font[i]->SetAnimation(animator);
		}




		SAFE_DELETE(srcTex);


	}
}

void CFont::Update()
{

	for (size_t i = 0; i < 10; ++i) {
		Font[i]->Update();
	}
}

void CFont::Render()
{
	if (bRender) {
		for (size_t i = 0; i < 10; ++i) {

			Font[i]->Render();
		}
	}
}
