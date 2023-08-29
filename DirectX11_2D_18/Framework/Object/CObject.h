#pragma once
class AnimationRect;
class Animator;
class CObject
{
private:
	bool m_bDead;
	Vector3 m_Position;
	Vector3 m_Size;

	AnimationRect* m_pAnimRect;
	Animator* m_pAnimator;

protected:

public:
	virtual void Init() {};
	virtual void Update() {};
	virtual void Render();
	virtual void PostRender() {};
	virtual void GUI() {};
	CObject();
	virtual ~CObject();


};

