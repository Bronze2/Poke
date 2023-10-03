#pragma once
class FadeManager:public SingletonBase<FadeManager>
{
private:
	class FadeObject* m_pObject;
	bool bReverse = false;
	bool bRender = true;
	bool bStart = false;
public:

	void Start();
	void Init();
	void SetReverse(const bool& _bReverse);
	void SetRender(const bool& _bRender)  { bRender = _bRender; }
	void Reset();
	void Update();
	virtual void Render();
private:
	FadeManager();
	~FadeManager();

public:
	friend class SingletonBase<FadeManager>;

};

