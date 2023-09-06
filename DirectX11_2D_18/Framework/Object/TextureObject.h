#pragma once

#include "CObject.h"
class TextureObject : public CObject
{
private:
	class TextureRect* m_pTex;
	bool m_bRender = true;
public:
	class TextureRect* GetTex();
	virtual void Init();
	void SetRender(const bool& _bRender) { m_bRender = _bRender; }
	void Init(const wstring& _Name);
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	TextureObject();
	virtual ~TextureObject();
};

