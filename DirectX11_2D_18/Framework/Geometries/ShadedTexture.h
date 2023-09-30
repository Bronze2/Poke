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

    void Render();
    void GUI();

private:

    FadeBuffer* sb = nullptr;

};