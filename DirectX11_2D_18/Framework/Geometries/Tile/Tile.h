#pragma once

class Tile
{
public:
	Vector3 GetPosition() { return position; }
	void SetPosition(Vector3 position) { this->position = position; }

	Vector2 GetStartUV() { return startUV; }
	void SetStartUV(Vector2 startUV) { this->startUV = startUV; }

	Vector2 GetEndUV() { return endUV; }
	void SetEndUV(Vector2 endUV) { this->endUV = endUV; }

	Color GetColor() { return color; }
	void SetColor(Color color) { this->color = color; }

	uint GetIndex() { return index; }
	void SetIndex(uint index) { this->index = index; }

	ID3D11ShaderResourceView* GetSRV() { return srv; }
	void SetSRV(ID3D11ShaderResourceView* srv) { this->srv = srv; }

	void SetCol() { if (!bCol)bCol = true; else bCol = false; }
	void SetAppear() { if (!bAppear)bAppear = true; else bAppear = false; }
	void SetAnimation() { if (!bAnimation)bAnimation = true; else bAnimation = false; }
	void SetTeleport(){ if (!bTeleport)bTeleport = true; else bTeleport = false; }
	bool& GetCol() { return bCol; }
private:
	Vector3 position = Values::ZeroVec3;
	Color color = Values::Black;

	Vector2 startUV = Vector2(0, 0);
	Vector2 endUV = Vector2(0, 0);

	ID3D11ShaderResourceView* srv = nullptr;

	uint index = -1;
	
	bool bCol = false;
	bool bAppear = false;
	bool bAnimation = false;
	bool bTeleport = false;
};