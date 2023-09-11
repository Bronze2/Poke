#include "Framework.h"
#include "GI.h"

GI::~GI()
{
	//SAFE_RELEASE(srv);
	SAFE_DELETE(wb);
	SAFE_DELETE(il);
	SAFE_DELETE(ps);
	SAFE_DELETE(vs);
	SAFE_DELETE(ib);
	SAFE_DELETE(vb);
}

// Color
void GI::Init(Vector3 position, Vector3 size, float rotation, Color color, FillType type)
{
	// 변수 초기화
	{
		this->originPosition = this->position = position;
		this->originSize = this->size = size;
		this->originRotation = this->rotation = rotation;
		this->color = color;
	}

	colorVertices.assign(4, VertexColor());
	SetVertices(colorVertices, type);

	for (VertexColor& v : colorVertices)
		v.color = color;

	vb = new VertexBuffer();
	vb->Create(colorVertices, D3D11_USAGE_DYNAMIC);

	indices = { 0,1,2,0,3,1 };
	ib = new IndexBuffer();
	ib->Create(indices, D3D11_USAGE_IMMUTABLE);

	vs = new VertexShader();
	vs->Create(ShaderPath + L"UI/ColorUI.hlsl", "VS");

	ps = new PixelShader();
	ps->Create(ShaderPath + L"UI/ColorUI.hlsl", "PS");

	il = new InputLayout();
	il->Create(VertexColor::descs, VertexColor::count, vs->GetBlob());

	wb = new WorldBuffer();
}

// Texture
void GI::Init(Vector3 position, Vector3 size, float rotation, wstring path, FillType type)
{
	// 변수 초기화
	{
		this->originPosition = this->position = position;
		this->originSize = this->size = size;
		this->originRotation = this->rotation = rotation;
	}

	textureVertices.assign(4, VertexTexture());
	SetVertices(textureVertices, type);

	textureVertices[0].uv = Vector2(0, 1);
	textureVertices[1].uv = Vector2(1, 0);
	textureVertices[2].uv = Vector2(1, 1);
	textureVertices[3].uv = Vector2(0, 0);

	vb = new VertexBuffer();
	vb->Create(textureVertices, D3D11_USAGE_DYNAMIC);

	indices = { 0,1,2,0,3,1 };
	ib = new IndexBuffer();
	ib->Create(indices, D3D11_USAGE_IMMUTABLE);

	vs = new VertexShader();
	vs->Create(ShaderPath + L"UI/TextureUI.hlsl", "VS");

	ps = new PixelShader();
	ps->Create(ShaderPath + L"UI/TextureUI.hlsl", "PS");

	il = new InputLayout();
	il->Create(VertexTexture::descs, VertexTexture::count, vs->GetBlob());

	wb = new WorldBuffer();

	HRESULT hr = D3DX11CreateShaderResourceViewFromFile
	(
		DEVICE,
		path.c_str(),
		nullptr,
		nullptr,
		&srv,
		nullptr
	);
	CHECK(hr);
	SRV::Get()->AddSRV(String::ToString(path), srv);
}

// Texture
void GI::Init(Vector3 position, Vector3 size, float rotation, FillType type)
{
	// 변수 초기화
	{
		this->originPosition = this->position = position;
		this->originSize = this->size = size;
		this->originRotation = this->rotation = rotation;
	}

	textureVertices.assign(4, VertexTexture());
	SetVertices(textureVertices, type);

	textureVertices[0].uv = Vector2(0, 1);
	textureVertices[1].uv = Vector2(1, 0);
	textureVertices[2].uv = Vector2(1, 1);
	textureVertices[3].uv = Vector2(0, 0);

	vb = new VertexBuffer();
	vb->Create(textureVertices, D3D11_USAGE_DYNAMIC);

	indices = { 0,1,2,0,3,1 };
	ib = new IndexBuffer();
	ib->Create(indices, D3D11_USAGE_IMMUTABLE);

	vs = new VertexShader();
	vs->Create(ShaderPath + L"UI/TextureUI.hlsl", "VS");

	ps = new PixelShader();
	ps->Create(ShaderPath + L"UI/TextureUI.hlsl", "PS");

	il = new InputLayout();
	il->Create(VertexTexture::descs, VertexTexture::count, vs->GetBlob());

	wb = new WorldBuffer();
}

void GI::MapVertexBuffer()
{
	DC->Map(vb->GetResource(), 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);
}

void GI::UnmapVertexBuffer()
{
	memcpy(subResource.pData, textureVertices.data(), sizeof(textureVertices[0]) * textureVertices.size());
	DC->Unmap(vb->GetResource(), 0);
}

void GI::SetShader(wstring shaderpath)
{
	vs->Clear();
	ps->Clear();

	vs->Create(shaderpath, "VS");
	ps->Create(shaderpath, "PS");
}

void GI::UpdateColor()
{

	D3D11_MAPPED_SUBRESOURCE subResource;
	DC->Map(vb->GetResource(), 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);
	{
		for (VertexColor& v : colorVertices)
			v.color = color;

		memcpy(subResource.pData, colorVertices.data(), vb->GetCount() * vb->GetStride());
	}
	DC->Unmap(vb->GetResource(), 0);
}

void GI::Update()
{
	UpdatePosition();
	UpdateWorld();
	UpdateColor();
}

void GI::UpdateWorld()
{
	world =
		DXMath::Scaling(size) *
		DXMath::RotationInDegree(rotation) *
		DXMath::Translation(position);

	wb->SetWorld(world);
}

void GI::UpdatePosition()
{
//	Vector3 centerPos = CAMERA->GetPosition() + Vector3(WinMaxWidth / 2, WinMaxHeight / 2, 0.f);
//	position = centerPos + originPosition;
}

void GI::Render()
{
	vb->SetIA();
	ib->SetIA();
	il->SetIA();
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	vs->SetShader();
	ps->SetShader();

	wb->SetVSBuffer(0);

	if(srv)
		DC->PSSetShaderResources(0, 1, &srv);

	DC->DrawIndexed(ib->GetCount(), 0, 0);
}

#pragma region FillType
template<typename T>
inline void GI::SetVertices(vector<T>& vertices, FillType type)
{
	switch (type)
	{
		case GI::NONE:
		{
			vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
			vertices[1].position = Vector3(+0.5f, +0.5f, 0.0f);
			vertices[2].position = Vector3(+0.5f, -0.5f, 0.0f);
			vertices[3].position = Vector3(-0.5f, +0.5f, 0.0f);
			break;
		}

		case GI::LEFT_TO_RIGHT:
		{
			vertices[0].position = Vector3(+0.0f, -0.5f, 0.0f);
			vertices[1].position = Vector3(+1.0f, +0.5f, 0.0f);
			vertices[2].position = Vector3(+1.0f, -0.5f, 0.0f);
			vertices[3].position = Vector3(+0.0f, +0.5f, 0.0f);
			break;
		}

		case GI::RIGHT_TO_LEFT:
		{
			vertices[0].position = Vector3(-1.0f, -0.5f, 0.0f);
			vertices[1].position = Vector3(+0.0f, +0.5f, 0.0f);
			vertices[2].position = Vector3(+0.0f, -0.5f, 0.0f);
			vertices[3].position = Vector3(-1.0f, +0.5f, 0.0f);
			break;
		}

		case GI::UP_TO_DOWN:
		{
			vertices[0].position = Vector3(-0.5f, -1.0f, 0.0f);
			vertices[1].position = Vector3(+0.5f, -0.0f, 0.0f);
			vertices[2].position = Vector3(+0.5f, -1.0f, 0.0f);
			vertices[3].position = Vector3(-0.5f, -0.0f, 0.0f);
			break;
		}

		case GI::DOWN_TO_UP:
		{
			vertices[0].position = Vector3(-0.5f, +0.0f, 0.0f);
			vertices[1].position = Vector3(+0.5f, +1.0f, 0.0f);
			vertices[2].position = Vector3(+0.5f, +0.0f, 0.0f);
			vertices[3].position = Vector3(-0.5f, +1.0f, 0.0f);
			break;
		}
	}
}
#pragma endregion