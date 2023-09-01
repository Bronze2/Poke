#include "Framework.h"
#include "SceneMgr.h"
#include "../UnitTest/Scene/Scene.h"
#include "../UnitTest/Scene/TitleScene.h"
#include "../UnitTest/Scene/FieldScene.h"
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
	SAFE_DELETE(vpb);
}

void SceneMgr::Init()
{
	{
		vpb = new VPBuffer();

		D3DXMatrixLookAtLH
		(
			&view,
			&Vector3(0, 0, 0),
			&Vector3(0, 0, 1),
			&Vector3(0, 1, 0)
		);

		D3DXMatrixOrthoOffCenterLH
		(
			&proj,
			0.0f,
			(float)WinMaxWidth,
			0.0f,
			(float)WinMaxHeight,
			0,
			1
		);

		vpb->SetView(view);
		vpb->SetProjection(proj);
	}
	PokemonMgr::Create();

	


	PokemonMgr::Get()->Init();
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new TitleScene;
	m_arrScene[(UINT)SCENE_TYPE::FIELD] = new FieldScene;
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
	vpb->SetVSBuffer(1);
	if (nullptr != m_pCurScene) {
		m_pCurScene->Render();
		Camera::Get()->Render();
		m_pCurScene->PostRender();
		m_pCurScene->GUI();
	}
}
