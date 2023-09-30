#include "stdafx.h"
#include "TitleScene.h"
#include "Geometries/TextureRect.h"
#include "Object/CObject.h"
#include "Object/Title.h"
#include "Manager/SceneMgr.h"
#include "Manager/EventMgr.h"
#include "Geometries/ShadedTexture.h"

void TitleScene::Init()
{

    m_Obj = new Title;
    Vector3 pos = { WinMaxWidth / 2, WinMaxHeight / 2, 0 };
    Vector3 size = { WinMaxWidth, WinMaxHeight, 0 };
 //   st = new ShadedTexture(pos, size, 0.0f, TexturePath + L"Pokemon/Fade.png");
    ft = new FadedTexture
    (pos, size,0.f,TexturePath+L"Pokemon/Fade.png");
    m_Obj->Init();
    AddObj(m_Obj, OBJ_TYPE::DEFAULT);
}

void TitleScene::Destroy()
{
    SAFE_DELETE(ft);
    DeleteAllObj();
}

void TitleScene::Update()
{
 //  st->Update();
    ft->Update();
    Scene::Update();
  
    auto* key = Keyboard::Get();
    if (key->Up('A')) {
      
        ChangeScene(SCENE_TYPE::FIELD);
    }
}

void TitleScene::Render()
{
    
//    st->Render();
    Scene::Render();
    ft->Render();
}

void TitleScene::PostRender()
{
  
}

void TitleScene::GUI()
{
   
}
