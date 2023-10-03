#include "Framework.h"
#include "FadeManager.h"
#include "Geometries/ShadedTexture.h"
#include "Object/FadeObject.h"
void FadeManager::Start()
{
    if (!bStart) {
        bStart = true;
        Reset();
    }

}
void FadeManager::SetReverse(const bool& _bReverse) {
    m_pObject->SetReverse(_bReverse);
}
void FadeManager::Init()
{
    m_pObject = new FadeObject;
    m_pObject->Init();

}
void FadeManager::Reset()
{
    m_pObject->Reset();
}

void FadeManager::Update()
{
   
    m_pObject->Update();
  
}

void FadeManager::Render()
{
    m_pObject->Render();
}

FadeManager::FadeManager()
{
}

FadeManager::~FadeManager()
{
	SAFE_DELETE(m_pObject);
}
