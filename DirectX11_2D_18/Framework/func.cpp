#include "Framework.h"
#include "func.h"
#include "Object/CObject.h"
#include "Manager/EventMgr.h"
void CreateObj(CObject* _pNewObj, Vector3 _Pos, OBJ_TYPE _Type)
{
	_pNewObj->SetPosition(_Pos);
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::CREATE_OBJ;
	evn.wParam = (DWORD_PTR)_pNewObj;
	evn.lParam = (DWORD_PTR)_Type;
	EventMgr::Get()->AddEvent(evn);
}

void DeleteObj(CObject* _DeleteObj)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::DELETE_OBJ;
	evn.wParam = (DWORD_PTR)_DeleteObj;

	EventMgr::Get()->AddEvent(evn);
}

void ChangeScene(SCENE_TYPE _NextScene)
{
	tEvent evn = {};
	evn.eEvent = EVENT_TYPE::SCENE_CHANGE;
	evn.wParam = (DWORD_PTR)_NextScene;

	EventMgr::Get()->AddEvent(evn);
}
