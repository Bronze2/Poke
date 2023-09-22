#pragma once
#include "CObject.h"
class AnimationRect;
class Item :
    public CObject
{
private:
    sItem m_sItem;
    AnimationRect* AnimRect;

    UINT Width;
    UINT Height;

public:

    Item();
    ~Item();
    Item(const Item& _Other);

    int GetCount() { return m_sItem.m_iCount; }


    void AddItem() {  m_sItem.m_iCount+=1; }
    void AddItem(int _iCount) { m_sItem.m_iCount += _iCount; }
    void SubItem() { if (m_sItem.m_iCount == 0)return;   m_sItem.m_iCount -= 1; }
    virtual void Init(){}
    const wstring& GetName() { return m_sItem.Name; }
    void SetItem(const sItem& _Item) { m_sItem = _Item; }
    void AnimInit(UINT _Width,UINT _Height);
    virtual void Update();
    virtual void Render();

};

