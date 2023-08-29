#include "stdafx.h"
#include "Scene.h"

#include "Object/CObject.h"
void Scene::AddObj(CObject* _pObj, OBJ_TYPE _Type)
{
	m_vecObj[(UINT)_Type].push_back(_pObj);
}

void Scene::Destroy()
{
	for (UINT i = 0; i < (UINT)OBJ_TYPE::END; ++i) {
		for (int j = 0; j < m_vecObj[i].size(); ++i) {
			if (nullptr != m_vecObj[i][j])
			{
				delete m_vecObj[i][j];
			}
		}
	}
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)OBJ_TYPE::END; ++i) {
		for (int j = 0; j < m_vecObj[i].size(); ++i) {
			if (nullptr != m_vecObj[i][j])
			{
				m_vecObj[i][j]->Update();
			}
		}
	}
}

void Scene::Render()
{
	for (UINT i = 0; i < (UINT)OBJ_TYPE::END; ++i) {
		for (int j = 0; j < m_vecObj[i].size(); ++i) {
			if (nullptr != m_vecObj[i][j])
			{
				m_vecObj[i][j]->Render();
			}
		}
	}
}

void Scene::PostRender()
{
	for (UINT i = 0; i < (UINT)OBJ_TYPE::END; ++i) {
		for (int j = 0; j < m_vecObj[i].size(); ++i) {
			if (nullptr != m_vecObj[i][j])
			{
				m_vecObj[i][j]->PostRender();
			}
		}
	}
}

void Scene::GUI()
{
	for (UINT i = 0; i < (UINT)OBJ_TYPE::END; ++i) {
		for (int j = 0; j < m_vecObj[i].size(); ++i) {
			if (nullptr != m_vecObj[i][j])
			{
				m_vecObj[i][j]->GUI();
			}
		}
	}
}

void Scene::DeleteAllObj()
{
	for (UINT i = (UINT)OBJ_TYPE::END - 1; i > 0; --i)
	{
		DeleteGroup((OBJ_TYPE)i);
	}
}

void Scene::DeleteGroup(OBJ_TYPE _Type)
{
	vector<CObject*>& vecObj = m_vecObj[(UINT)_Type];
	for (size_t i = 0; i < vecObj.size(); i++)
	{
		assert(vecObj[i]);
		delete vecObj[i];

	}
	vecObj.clear();
}

Scene::Scene()
{
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)OBJ_TYPE::END; ++i) {
		for (int j = 0; j < m_vecObj[i].size(); ++i) {
			if (nullptr != m_vecObj[i][j])
			{
				delete m_vecObj[i][j];
			}
		}
	}
}
