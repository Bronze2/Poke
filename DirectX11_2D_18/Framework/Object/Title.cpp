#include "Framework.h"
#include"CObject.h"
#include "Title.h"


#include "Geometries/TextureRect.h"

void Title::Init()
{
   m_pTex = new TextureRect
    (
        Vector3(WinMaxWidth / 2, WinMaxHeight / 2, 0),
        Vector3(512, 768, 0), 0,
        TexturePath + L"Pokemon/Map/StartScene.png"
    );

}

void Title::Update()
{
    m_pTex->Update();
}

void Title::Render()
{
    m_pTex->Render();
}

Title::Title()
{
}

Title::~Title()
{
	SAFE_DELETE(m_pTex);
}
