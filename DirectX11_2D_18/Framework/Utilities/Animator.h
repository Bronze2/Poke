#pragma once

class AnimationClip
{
public:
    friend class Animator;
    AnimationClip(wstring clipName, Texture2D* srcTex, UINT frameCount,
                  Vector2 startPos, Vector2 endPos, float playRate,
                  bool bReversed = false);
    void SetRepeat(const bool& _bRepeat) { bRepeat = _bRepeat; }
    void SetPause(const bool& _bPause) { bPause = _bPause; }
    const wstring& GetName() { return clipName; }
protected:
    wstring clipName = L"";
    vector<Vector2> keyFrames;
    uint frameCount = 0;
    ID3D11ShaderResourceView* srv = nullptr;
    Vector2 texelFrameSize = Values::ZeroVec2;
    float playRate = 0.0f;
    bool bReversed = false;
    bool bRepeat = true;
    bool bPause = false;
};

class Animator
{
public:
    Animator();
    ~Animator();

    void Update();

    Vector2 GetCurrentFrame() { return currentFrame; }
    Vector2 GetTexelFrameSize() { return currentClip->texelFrameSize; }
    ID3D11ShaderResourceView* GetCurrentSRV() { return currentClip->srv; }

    UINT GetCurrentFraneIdx() { return currentFrameIndex; }
    bool GetEnd() { return bEnd; }

    void AddAnimClip(AnimationClip* animClip);
    void SetCurrentAnimClip(wstring clipName);
    void SetPause(const bool& _bPause) { currentClip->SetPause(_bPause); }
    AnimationClip* GetCurrentClip() { return currentClip; }
private:
    bool CheckExist(wstring clipName) { return animClips.find(clipName) != animClips.end(); }

private:
    unordered_map<wstring, AnimationClip*> animClips;

    AnimationClip* currentClip = nullptr;
    uint currentFrameIndex = 0;
    Vector2 currentFrame = Values::ZeroVec2;

    float deltaTime = 0.0f;

    bool bEnd = false;
};