#pragma once
class Skill;
class SkillMgr : public SingletonBase<SkillMgr>
{
private:
	SkillMgr();
	~SkillMgr();

	vector<Skill> m_vecSkill;
public:
	friend class SingletonBase<SkillMgr>;
};

