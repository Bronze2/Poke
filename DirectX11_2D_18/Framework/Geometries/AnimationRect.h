#pragma once

#include "TextureRect.h"
#include "Utilities/Animator.h"

class AnimationRect : public TextureRect
{
public:
    AnimationRect(Vector3 position, Vector3 size);
    ~AnimationRect();

    AnimationRect(const AnimationRect& _rect);


    void Update();
    void Render();
    void Init(wstring _Name);

    void SetAnimation(Animator* animator) { this->animator = animator; }
    class Animator* GetAnimator() { return animator; }

    void AddClip(AnimationClip* _pClip);
    virtual void Move() override;
public:
    ID3D11SamplerState* GetPoint(UINT i) { return point[i]; }
    ID3D11BlendState* GetbPoint(UINT i) { return bPoint[i]; }
protected:
    class Animator* animator = nullptr;

private:

    ID3D11SamplerState* point[2];
    ID3D11BlendState*  bPoint[2];
};