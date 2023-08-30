#pragma once

class TextureRect
{
public:
    TextureRect(Vector3 position, Vector3 size, float rotation, wstring path, Pivot pivot = CENTER);
    TextureRect(Vector3 position, Vector3 size, float rotation);
    virtual ~TextureRect();

    void Update();
    void Render();
    void GUI();

    void SetShader(wstring shaderPath);
    void SetSRV(ID3D11ShaderResourceView* srv) { this->srv = srv; }

    void MapVertexBuffer();
    void UnmapVertexBuffer();

    void SetHeight(const UINT& _Height) { m_Height = _Height; }
    void SetWidth(const UINT& _Width) { m_Width = _Width; }

    virtual void Move();
    void SetPosition(const Vector3& pos) { position = pos; }
    void SetSize(const Vector3& _size) { size = _size; }
    const UINT& GetHeight() { return m_Height; }
    const UINT& GetWidth() { return m_Width; }
private:
    void SetVertices();
    void UpdateWorld();
    
protected:
    UINT m_Height;
    UINT m_Width;
    vector<VertexTexture> vertices;
    VertexBuffer* vb = nullptr;

    vector<uint> indices;
    IndexBuffer* ib = nullptr;

    InputLayout* il = nullptr;

    VertexShader* vs = nullptr;
    PixelShader* ps = nullptr;

    Matrix world, S, R, T;

    WorldBuffer* wb = nullptr;

    Vector3 position;
    Vector3 size;
    float rotation;

    Pivot pivot = CENTER;

    ID3D11ShaderResourceView* srv = nullptr;

    D3D11_MAPPED_SUBRESOURCE subResource;
};