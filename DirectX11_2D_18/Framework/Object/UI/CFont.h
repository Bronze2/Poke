#pragma once
class CFont
{
private:

	wstring Name;
	bool bRender = true;
	class AnimationRect* Font[10];
	Vector3 position;
	Vector3 Size;
	float Width = 0;
	float Height = 0;
	UINT m_iCount = 0;
public:
	void Setsize(const Vector3& _size);
	void Setsize();
	Vector3 GetPosition();
	void SetPosition(const Vector3& _Positon);
	void SetPosition(const Vector3& _Positon,bool bTrue);
	void SetRender(const bool& _bRender) { bRender = _bRender; }
	CFont();
	CFont(wstring _Name);
	~CFont();
	CFont(const CFont& _Other);


	void SetName(const wstring& _Name);
	void Init(wstring _Name);
	void Init(wstring _Name, UINT _Count);
	void Update();
	void Render();
};

