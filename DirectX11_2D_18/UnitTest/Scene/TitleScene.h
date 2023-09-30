#pragma once
#include "Scene.h"
class TitleScene :
    public Scene
{
private:
	class CObject* m_Obj;
//	class ShadedTexture* st;
	class FadedTexture* ft;
public:
	virtual void Init() ;
	virtual void Destroy();	// 소멸자 대체

	virtual void Update() ;

	virtual void Render() ;
	virtual void PostRender() ;	// 후처리가 필요한 코드를 처리

	virtual void GUI();	// 외부 라이브러리
};

