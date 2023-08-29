#include "Framework.h"
#include "SceneMgr.h"
#include "../UnitTest/Scene/Scene.h"
#include "../UnitTest/Scene/TitleScene.h"
void SceneMgr::ChangeScene(SCENE_TYPE _pNextScene)
{
}

void SceneMgr::Init()
{
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new TitleScene;
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TITLE];
	m_pCurScene->Init();
}

void SceneMgr::Update()
{
	if (nullptr != m_pCurScene) {
		m_pCurScene->Update();
	}
	
}

void SceneMgr::Render()
{

	if (nullptr != m_pCurScene) {
		m_pCurScene->Render();
		m_pCurScene->PostRender();
		m_pCurScene->GUI();
	}
}
