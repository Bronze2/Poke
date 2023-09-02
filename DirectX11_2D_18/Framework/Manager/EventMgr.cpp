#include "Framework.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "../UnitTest/Scene/Scene.h"
#include "Object/CObject.h"
EventMgr::EventMgr()
{
}

EventMgr::~EventMgr()
{
}

void EventMgr::ExcuteEvent(const tEvent& _event)
{
	switch (_event.eEvent)
	{
	case EVENT_TYPE::CREATE_OBJ:
	{
		Scene* pCurScene = SceneMgr::Get()->GetCurScene();
		pCurScene->AddObj((CObject*)_event.wParam, (OBJ_TYPE)_event.lParam);
	}
	break;
	case EVENT_TYPE::DELETE_OBJ:
	{
		((CObject*)_event.wParam)->SetDead();
		m_vecDeadObj.push_back((CObject*)_event.wParam);

	}
	break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		SceneMgr::Get()->ChangeScene((SCENE_TYPE)_event.wParam);
	}
	break;
	default:
		break;
	}
}

void EventMgr::Update()
{
	for (size_t i = 0; i < m_vecDeadObj.size(); ++i) {
		if (nullptr != m_vecDeadObj[i])delete m_vecDeadObj[i];
	}
	m_vecDeadObj.clear();
	for (size_t i = 0; i < m_vecEvent.size(); ++i)
		ExcuteEvent(m_vecEvent[i]);
	m_vecEvent.clear();

}
