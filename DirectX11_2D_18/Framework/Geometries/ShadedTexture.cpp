#include "Framework.h"
#include "ShadedTexture.h"

ShadedTexture::ShadedTexture(Vector3 position, Vector3 size, float rotation, wstring path)
    : TextureRect(position, size, rotation, path)
{
    sb = new ShadedBuffer();

   ps->Clear();
   ps->Create(ShaderPath + L"TextureFilter.hlsl", "PS");
}

ShadedTexture::~ShadedTexture()
{
    SAFE_DELETE(sb);
}

void ShadedTexture::Render()
{
    sb->SetPSBuffer(0);
    TextureRect::Render();
}

void ShadedTexture::GUI()
{

}

FadedTexture::FadedTexture(Vector3 position, Vector3 size, float rotation, wstring path)
    :TextureRect(position,size,rotation,path)
{
    sb = new FadeBuffer();

    ps->Clear();
    ps->Create(ShaderPath + L"Fade.hlsl", "PS");
}

FadedTexture::~FadedTexture()
{
    SAFE_DELETE(sb);
}

void FadedTexture::Render()
{
    sb->SetPSBuffer(0);
    TextureRect::Render();
}

void FadedTexture::GUI()
{
}
