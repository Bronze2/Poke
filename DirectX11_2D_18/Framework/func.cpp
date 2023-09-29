#include "Framework.h"
#include "func.h"
#include "Object/CObject.h"
#include "Manager/EventMgr.h"
#include "Geometries/AnimationRect.h"
void CreateObj(CObject* _pNewObj, Vector3 _Pos, OBJ_TYPE _Type)
{
	_pNewObj->SetPosition(_Pos);
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::CREATE_OBJ;
	evn.wParam = (DWORD_PTR)_pNewObj;
	evn.lParam = (DWORD_PTR)_Type;
	EventMgr::Get()->AddEvent(evn);
}

void DeleteObj(CObject* _DeleteObj)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::DELETE_OBJ;
	evn.wParam = (DWORD_PTR)_DeleteObj;

	EventMgr::Get()->AddEvent(evn);
}

void ChangeScene(SCENE_TYPE _NextScene)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::SCENE_CHANGE;
	evn.wParam = (DWORD_PTR)_NextScene;

	EventMgr::Get()->AddEvent(evn);
}

bool TimeCheck(float fduration, chrono::steady_clock::time_point b)
{
	std::chrono::duration<double> p = chrono::steady_clock::now() - b;
	if (fduration <= p.count()) {
		return true;
	}
	return false;
}

void FontCreate()
{
	FontRect = new AnimationRect(Vector3(0,0,0),Vector3(0,0,0));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Battle/BattleUI/BattleFont.png");
	FontRect->SetWidth(srcTex->GetWidth() / 10);
	FontRect->SetHeight(srcTex->GetHeight() / 7);
	Animator* animator = new Animator;
	AnimationClip* clip = nullptr;
	clip = new AnimationClip(
		L"A", srcTex, 1, Values::ZeroVec2,
		Vector2(FontRect->GetWidth(), FontRect->GetHeight()), 1.f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(
		L"a", srcTex, 1, Vector2(0.f, FontRect->GetHeight() * 3),
		Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 4), 1.f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(
		L"B", srcTex, 1, Vector2(FontRect->GetWidth(), 0.f),
		Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight()), 1.f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(
		L"b", srcTex, 1, Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 3),
		Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 4), 1.f);
	animator->AddAnimClip(clip);
	
		
		clip = new AnimationClip(
				L"C", srcTex, 1, Vector2(FontRect->GetWidth() * 2, 0.f),
				Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);

	
		clip = new AnimationClip(
			L"c", srcTex, 1, Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"D", srcTex, 1, Vector2(FontRect->GetWidth() * 3, 0.f),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"d", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"E", srcTex, 1, Vector2(FontRect->GetWidth() * 4, 0.f),
			Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);

		clip = new AnimationClip(
				L"e", srcTex, 1, Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 3),
				Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"F", srcTex, 1, Vector2(FontRect->GetWidth() * 5, 0.f),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"f", srcTex, 1, Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"G", srcTex, 1, Vector2(FontRect->GetWidth() * 6, 0.f),
			Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight()), 1.f);

		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"g", srcTex, 1, Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 4), 1.f);

		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"H", srcTex, 1, Vector2(FontRect->GetWidth() * 7, 0.f),
			Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"h", srcTex, 1, Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"I", srcTex, 1, Vector2(FontRect->GetWidth() * 8, 0.f),
			Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"i", srcTex, 1, Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"J", srcTex, 1, Vector2(FontRect->GetWidth() * 9, 0.f),
			Vector2(FontRect->GetWidth() * 10, FontRect->GetHeight()), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"j", srcTex, 1, Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 3),
			Vector2(FontRect->GetWidth() * 10, FontRect->GetHeight() * 4), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"K", srcTex, 1, Vector2(0.f, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"k", srcTex, 1, Vector2(0.f, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"L", srcTex, 1, Vector2(FontRect->GetWidth(), FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"l", srcTex, 1, Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"M", srcTex, 1, Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"m", srcTex, 1, Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"N", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"n", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"O", srcTex, 1, Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"o", srcTex, 1, Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"P", srcTex, 1, Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"p", srcTex, 1, Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Q", srcTex, 1, Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"q", srcTex, 1, Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"R", srcTex, 1, Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"r", srcTex, 1, Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"S", srcTex, 1, Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"s", srcTex, 1, Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"T", srcTex, 1, Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight()),
			Vector2(FontRect->GetWidth() * 10, FontRect->GetHeight() * 2), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"t", srcTex, 1, Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 4),
			Vector2(FontRect->GetWidth() * 10, FontRect->GetHeight() * 5), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"U", srcTex, 1, Vector2(0.f, FontRect->GetHeight() * 2),
			Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"u", srcTex, 1, Vector2(0.f, FontRect->GetHeight() * 5),
			Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"V", srcTex, 1, Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 2),
			Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"v", srcTex, 1, Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 5),
			Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"W", srcTex, 1, Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 2),
			Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"w", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 5),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"X", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 2),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"x", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 5),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Y", srcTex, 1, Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 2),
			Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"y", srcTex, 1, Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 5),
			Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"Z", srcTex, 1, Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 2),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 3), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"z", srcTex, 1, Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 5),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 6), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"0", srcTex, 1, Vector2(0.f, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"1", srcTex, 1, Vector2(FontRect->GetWidth(), FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"2", srcTex, 1, Vector2(FontRect->GetWidth() * 2, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"3", srcTex, 1, Vector2(FontRect->GetWidth() * 3, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"4", srcTex, 1, Vector2(FontRect->GetWidth() * 4, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"5", srcTex, 1, Vector2(FontRect->GetWidth() * 5, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"6", srcTex, 1, Vector2(FontRect->GetWidth() * 6, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"7", srcTex, 1, Vector2(FontRect->GetWidth() * 7, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"8", srcTex, 1,Vector2(FontRect->GetWidth() * 8, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
		clip = new AnimationClip(
			L"9", srcTex, 1, Vector2(FontRect->GetWidth() * 9, FontRect->GetHeight() * 6),
			Vector2(FontRect->GetWidth() * 10, FontRect->GetHeight() * 7), 1.f);
		animator->AddAnimClip(clip);
	

	
		animator->SetCurrentAnimClip(L"0");
		FontRect->SetAnimation(animator);
		




		SAFE_DELETE(srcTex);


	

}
