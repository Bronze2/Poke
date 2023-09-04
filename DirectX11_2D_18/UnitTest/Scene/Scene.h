#pragma once
class CObject;
class Scene:public IObject
{
private:

	vector<CObject*> m_vecObj[(UINT)OBJ_TYPE::END];
public:
	void AddObj(CObject* _pObj,OBJ_TYPE _Type);
	virtual void Init() {};
	virtual void Destroy() ;	// �Ҹ��� ��ü

	virtual void Update() ;

	virtual void Render() ;
	virtual void PostRender();	// ��ó���� �ʿ��� �ڵ带 ó��

	virtual void GUI() ;	// �ܺ� ���̺귯��


	void DeleteAllObj();
	void DeleteGroup(OBJ_TYPE _Type);
	Scene();
	virtual ~Scene();

};

