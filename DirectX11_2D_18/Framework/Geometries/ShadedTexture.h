#pragma once

#include "TextureRect.h"

class ShadedBuffer : public ShaderBuffer
{
public:
    ShadedBuffer() : ShaderBuffer(&data, sizeof(Data))
    {
        data.Selection = 1;
  
    }

    int* GetSelectionPtr() { return &data.Selection; }
  //  void SubAlpha(const float& _alpha) { data.alpha -= _alpha; }
    // 16byte
    struct Data
    {
        int Selection;  //  4byte
       
        Vector3 dummy;  // 12byte
    };

private:
    Data data;
};

class ShadedTexture : public TextureRect
{
public:
    ShadedTexture(Vector3 position, Vector3 size, float rotation, wstring path);
    ~ShadedTexture();

    void Render();
    void GUI();

private:

    ShadedBuffer* sb = nullptr;

};

class FadeBuffer :public ShaderBuffer {
public:
    struct Data
    {
        float Selection;  //  4byte

        Vector3 dummy;  // 12byte
    };
private:
    Data data;

public:
    FadeBuffer() : ShaderBuffer(&data, sizeof(Data))
    {
        data.Selection = 0;

    }

    float* GetSelectionPtr() { return &data.Selection; }
   
 
};
class FadedTexture : public TextureRect
{
public:
    FadedTexture(Vector3 position, Vector3 size, float rotation, wstring path);
    ~FadedTexture();

    void Update();
    void ReverseUpdate();
    void Render();
    void GUI();
    FadeBuffer* GetBuffer() { return sb; }

private:

    FadeBuffer* sb = nullptr;

private:

    ID3D11SamplerState* point[2];
    ID3D11BlendState* bPoint[2];
};