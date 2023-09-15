#pragma once
class CObject;
class Scene:public IObject
{
private:

	vector<CObject*> m_vecObj[(UINT)OBJ_TYPE::END];
public:
	void AddObj(CObject* _pObj,OBJ_TYPE _Type);
	virtual void Init() {};
	virtual void Destroy() ;	// 소멸자 대체

	virtual void Update() ;
	virtual void BattleInit() {};

	virtual void Render() ;
	virtual void PostRender();	// 후처리가 필요한 코드를 처리

	virtual void GUI() ;	// 외부 라이브러리


	vector<CObject*> GetObj(OBJ_TYPE  _eType) { return m_vecObj[(int) _eType]; }
	void DeleteAllObj();
	void DeleteGroup(OBJ_TYPE _Type);
	Scene();
	virtual ~Scene();

};

