#include "Framework.h"
#include "UI.h"
#include "Geometries/AnimationRect.h"
AnimationRect* UI::GetTex()
{
	return m_pTex;
}
void UI::Init()
{
}
void UI::DeleteTexture() {
	SAFE_DELETE(srcTex);
}
Texture2D* UI::GetTexture() {
	return srcTex;
}
void UI::Init(const wstring& _Path, const int& _Number, const int& _Width, const int& _Height)
{
	 srcTex = new Texture2D(TexturePath + L"Pokemon/"+_Path+ L".png");
	m_pTex->SetHeight(srcTex->GetHeight() / _Height); m_pTex->SetWidth(srcTex->GetWidth() / _Width);
}

void UI::Update()
{
	if (nullptr != m_pTex)
		m_pTex->Update();
}

void UI::Render()
{
	if (nullptr != m_pTex)
		m_pTex->Render();
}

UI::UI()
{
	m_pTex = new AnimationRect
	(
		Vector3(0.f, 0.f, 0),
		Vector3(0.f, 0.f, 0)
	);
}

UI::~UI()
{
	SAFE_DELETE(m_pTex);
}
