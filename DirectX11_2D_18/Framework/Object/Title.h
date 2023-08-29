#pragma once


class Title : public CObject
{
private:
	class TextureRect* m_pTex;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	Title();
	virtual ~Title();
};

