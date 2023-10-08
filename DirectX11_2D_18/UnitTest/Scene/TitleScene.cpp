#include "stdafx.h"
#include "TitleScene.h"
#include "Geometries/TextureRect.h"
#include "Object/CObject.h"
#include "Object/Title.h"
#include "Manager/SceneMgr.h"
#include "Manager/EventMgr.h"
#include "Geometries/ShadedTexture.h"
#include "Manager/FadeManager.h"
#include "Object/FadeObject.h"
void TitleScene::Init()
{

    m_Obj = new Title;
    

 //   st = new ShadedTexture(pos, size, 0.0f, TexturePath + L"Pokemon/Fade.png");

  
 
    m_Obj->Init();
    AddObj(m_Obj, OBJ_TYPE::DEFAULT);
}

void TitleScene::Destroy()
{
 
    DeleteAllObj();
}

void TitleScene::Update()
{
 //  st->Update();
    Scene::Update();
  
    auto* key = Keyboard::Get();
    if (key->Up('A')) {
        FadeManager::Get()->SetReverse(true);
        FadeManager::Get()->Reset();
        Sounds::Get()->Play("Press", 0.3f);
       
        Sounds::Get()->Pause("TitleBGM");
        ChangeScene(SCENE_TYPE::FIELD);
    }
    if (KEYUP('B')) {
        Sounds::Get()->Play("TitleBGM", 0.3f);
        FadeManager::Get()->Start();
    }
}

void TitleScene::Render()
{
    
//    st->Render();
    Scene::Render();
    
}

void TitleScene::PostRender()
{
  
}

void TitleScene::GUI()
{
   
}
