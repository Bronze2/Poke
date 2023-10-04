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

    {
        D3D11_SAMPLER_DESC desc;
        States::GetSamplerDesc(&desc);
        States::CreateSampler(&desc, &point[0]);

        desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
        States::CreateSampler(&desc, &point[1]);
    }

    // Blend
    {
        D3D11_BLEND_DESC desc;
        States::GetBlendDesc(&desc);
        States::CreateBlend(&desc, &bPoint[0]);

        desc.RenderTarget[0].BlendEnable = true;
        States::CreateBlend(&desc, &bPoint[1]);
    }

    ps->Clear();
    ps->Create(ShaderPath + L"UI/Fade.hlsl", "PS");
}
void FadedTexture::Update() {
    
    if (bStart) {
        float* a = sb->GetSelectionPtr();

        if ((*a) < 1.f) {

            (*a) += 0.5 * DELTA;
        }

    }
    TextureRect::Update();
}
void FadedTexture::ReverseUpdate()
{
    float* a = sb->GetSelectionPtr();
    if ((*a) > 0.f) {

        (*a) -= 0.5 * DELTA;
    }


    TextureRect::Update();
}
FadedTexture::~FadedTexture()
{
    SAFE_DELETE(sb);
}

void FadedTexture::Render()
{
    sb->SetPSBuffer(0);
    DC->PSSetSamplers(0, 1, &point[1]);
    DC->OMSetBlendState(bPoint[1], nullptr, (UINT)0xFFFFFFFF);

    TextureRect::Render();
}

void FadedTexture::GUI()
{
}
