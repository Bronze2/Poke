#pragma once
class CObject;
class EventMgr:public SingletonBase<EventMgr>
{
public:
	friend class SingletonBase<EventMgr>;

private:
	vector<tEvent> m_vecEvent;
	vector<CObject*> m_vecDeadObj;

private:

	EventMgr();
	~EventMgr();
	void ExcuteEvent(const tEvent& _event);
public:
	void Update();
	void AddEvent(const tEvent& _event) { m_vecEvent.push_back(_event); }



};

