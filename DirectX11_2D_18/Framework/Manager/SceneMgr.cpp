#include "Framework.h"
#include "SceneMgr.h"
#include "../UnitTest/Scene/Scene.h"
#include "../UnitTest/Scene/TitleScene.h"
#include "../UnitTest/Scene/FieldScene.h"
#include "../UnitTest/Scene/TileMap.h"
#include "PokemonMgr.h"
void SceneMgr::ChangeScene(SCENE_TYPE _NextScene)
{
	if (m_pCurScene == m_arrScene[(UINT)_NextScene])
	{
		return;
	}
	m_pCurScene = m_arrScene[(UINT)_NextScene];
	m_pCurScene->Init();
}

SceneMgr::SceneMgr() :m_arrScene{}
{
	
}

SceneMgr::~SceneMgr()
{
	for (int i = 0; i < (UINT)SCENE_TYPE::END; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::Init()
{
	
	PokemonMgr::Create();

	


	PokemonMgr::Get()->Init();
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new TitleScene;
	m_arrScene[(UINT)SCENE_TYPE::FIELD] = new FieldScene;


	m_arrScene[(UINT)SCENE_TYPE::TOOL] = new TileMap;
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TOOL];
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
		Camera::Get()->Render();
		m_pCurScene->PostRender();
		m_pCurScene->GUI();
	}
}
