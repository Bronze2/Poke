#include "stdafx.h"
#include "06_Animation.h"

#include "Geometries/AnimationRect.h"

void AnimationDemo::Init()
{
    ar = new AnimationRect({ 720, 360, 0 }, { 200,200,0 });
}

void AnimationDemo::Destroy()
{
    SAFE_DELETE(ar);
}

void AnimationDemo::Update()
{
    ar->Update();
}

void AnimationDemo::Render()
{
    ar->Render();
}

void AnimationDemo::PostRender()
{
}

void AnimationDemo::GUI()
{
}

// Animator 리스트 초기화 안했고,
// frameSize 제대로 안썼고,
// texelStartPos.y Hegith->Width으로 적음