#include "stdafx.h"
#include "TitleScene.h"
#include "Geometries/TextureRect.h"
#include "Object/CObject.h"
#include "Object/Title.h"
void TitleScene::Init()
{
    m_Obj = new Title;

    m_Obj->Init();
    AddObj(m_Obj, OBJ_TYPE::DEFAULT);
}

void TitleScene::Destroy()
{
    DeleteAllObj();
}

void TitleScene::Update()
{
    Scene::Update();
}

void TitleScene::Render()
{
    Scene::Render();
}

void TitleScene::PostRender()
{
  
}

void TitleScene::GUI()
{
   
}
