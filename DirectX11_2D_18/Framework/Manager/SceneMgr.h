#pragma once
class Scene;
class SceneMgr: public SingletonBase<SceneMgr>
{
private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];
	Scene* m_pCurScene;
	VPBuffer* vpb = nullptr;
	Matrix view, proj;

private:
	void ChangeScene(SCENE_TYPE _NextScene);

	SceneMgr();
	~SceneMgr();
public:

	void Init();
	void Update();
	void Render();


	Scene* GetCurScene() { return m_pCurScene; }
public:
	friend class SingletonBase<SceneMgr>;
	friend class EventMgr;
};

