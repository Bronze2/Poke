#pragma once
class Player;
class Npc;
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

	void SetCol(const bool& _bCol) { bCol = _bCol; }
	void SetAppear(const bool& _bAppear) { bAppear = _bAppear; }
	void SetAnimation(const bool& _btrue) {bAnimation = _btrue;}
	void SetTeleport(const bool& _btrue) { bTeleport = _btrue; }
	float GetCol() { return (float)bCol; }
	float GetAppear() { return (float)bAppear; }
	float GetAnimation() { return (float)bAnimation; }
	float GetTelePort() { return (float)bTeleport; }

	void Update();

	
	void SetPlayer(Player* _Player) { m_Player = _Player; }
	void SetNpc(Npc* _pNpc) { m_Npc = _pNpc; }
	Npc* GetNpc();
private:
	Npc* m_Npc=nullptr;
	Player* m_Player=nullptr;
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