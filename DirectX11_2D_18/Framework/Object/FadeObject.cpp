#include "Framework.h"
#include "FadeObject.h"
#include "Geometries/ShadedTexture.h"


FadedTexture* FadeObject::GetTexture()
{
	return m_pTex;
}

void FadeObject::Reset()
{
	if (!bReverse) {
		float* alpha =(m_pTex->GetBuffer()->GetSelectionPtr());
		*alpha = 0;
	}
	else {
		float* alpha = (m_pTex->GetBuffer()->GetSelectionPtr());
		*alpha = 1;
	}
}

void FadeObject::DeleteTexture()
{
}

void FadeObject::Init()
{
	Vector3 pos = { WinMaxWidth / 2, WinMaxHeight / 2, 0 };
	Vector3 size = { WinMaxWidth, WinMaxHeight, 0 };
	m_pTex = new FadedTexture
	(pos, size, 0.f, TexturePath + L"Pokemon/Fade.png");
}

void FadeObject::Update()
{
	if(!bReverse)
		m_pTex->Update();
	else {
		m_pTex->ReverseUpdate();
	}
}

void FadeObject::Render()
{
	m_pTex->Render();
}

FadeObject::FadeObject()
{
}

FadeObject::~FadeObject()
{
	SAFE_DELETE(m_pTex);
}
