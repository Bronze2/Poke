#pragma once
#include "CObject.h"
class UI :
    public CObject
{
private:
	class AnimationRect* m_pTex;
	class Texture2D* srcTex;

	bool bRender = true;
public:
	class Texture2D* GetTexture();
	void SetRender(const bool& _bRender) { bRender = _bRender; }

	class AnimationRect* GetTex();
	void DeleteTexture();
	virtual void Init();
	void Init(const wstring& _Path,const int& _Count,const int& _Width,const int&_Height);
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	UI();
	virtual ~UI();
};

