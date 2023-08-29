#pragma once
class Scene;
class SceneMgr: public SingletonBase<SceneMgr>
{
private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];
	Scene* m_pCurScene;

private:
	void ChangeScene(SCENE_TYPE _pNextScene);

public:

	void Init();
	void Update();
	void Render();

public:
	friend class SingletonBase<SceneMgr>;
	friend class EventMgr;
};

