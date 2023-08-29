#pragma once

#include "TextureRect.h"
#include "Utilities/Animator.h"

class AnimationRect : public TextureRect
{
public:
    AnimationRect(Vector3 position, Vector3 size);
    ~AnimationRect();

    void Update();
    void Render();
    void Init(wstring _Name);

    void SetAnimation(Animator* animator) { this->animator = animator; }
    class Animator* GetAnimator() { return animator; }

    void AddAnimation(AnimationClip* _pClip);
    virtual void Move() override;
protected:
    class Animator* animator = nullptr;

private:

    ID3D11SamplerState* point[2];
    ID3D11BlendState* bPoint[2];
};