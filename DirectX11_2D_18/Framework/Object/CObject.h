#pragma once
class AnimationRect;
class Animator;
class CObject
{
private:
	bool m_bDead = false;
	Vector3 m_Position;
	Vector3 m_Size;

	AnimationRect* m_pAnimRect;
	Animator* m_pAnimator;
	
protected:
	bool IsNpc = false;
public:
	bool GetDead() { return m_bDead; }
	void SetIsNpc() { IsNpc = true; }
	bool GetIsNpc() { return IsNpc; }
	void SetPosition(Vector3 _pos) { m_Position = _pos; }
	void SetSz(Vector3 _size) { m_Size = _size; }
	void SetDead() { m_bDead = true; }
	virtual void Init() {};
	virtual void Update() {};
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	CObject();
	virtual ~CObject();
	Vector3 GetPos() { return m_Position; }
	Vector3 GetSize() { return m_Size; }
};

