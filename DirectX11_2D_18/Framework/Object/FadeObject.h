#pragma once
#include "CObject.h"
class FadeObject :
    public CObject
{
private:
	class FadedTexture* m_pTex;
	bool bReverse = false;
	bool bRender = true;
public:
	bool GetReverse() { return bReverse; }
	void ReverseUpdate();
	class FadedTexture* GetTexture();
	void SetReverse(const bool& _bReverse) { bReverse = _bReverse; }
	void SetRender(const bool& _bRender) { bRender = _bRender; }
	void Reset();
	void DeleteTexture();
	virtual void Init();

	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	FadeObject();
	virtual ~FadeObject();
};

