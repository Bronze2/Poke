#pragma once

#include "CObject.h"
class TextureObject : public CObject
{
private:
	class TextureRect* m_pTex;

public:
	class TextureRect* GetTex();
	virtual void Init();
	void Init(const wstring& _Name);
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	TextureObject();
	virtual ~TextureObject();
};

