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
    bool bRender = false;
public:

    Item();
    ~Item();
    Item(const Item& _Other);

    ITEM_TYPE GetItemType() { return m_sItem.m_eType; }


    void SetRender(const bool& _Render) { bRender = _Render; }
    int GetCount() { return m_sItem.m_iCount; }
    class AnimationRect* GetAnimRect() { return AnimRect; }
    void SetPos(const Vector3& pos);
    void SetSize(const Vector3& size);
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

