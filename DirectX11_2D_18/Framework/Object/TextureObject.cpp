#include "Framework.h"
#include"CObject.h"
#include "TextureObject.h"


#include "Geometries/TextureRect.h"
#include "TextureObject.h"

TextureRect* TextureObject::GetTex()
{
    return m_pTex;
}

void TextureObject::Init()
{


}

void TextureObject::Init(const wstring& _Name)
{
    m_pTex = new TextureRect
    (
        Vector3(0.f,0.f, 0),
        Vector3(0.f, 0.f, 0), 0,
        TexturePath + _Name
    );

}

void TextureObject::Update()
{
    m_pTex->Update();
}

void TextureObject::Render()
{
    m_pTex->Render();
}

TextureObject::TextureObject()
{
}

TextureObject::~TextureObject()
{
    SAFE_DELETE(m_pTex);
}
