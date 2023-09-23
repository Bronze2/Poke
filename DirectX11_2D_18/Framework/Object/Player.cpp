#include "Framework.h"
#include "Player.h"
#include "Geometries/AnimationRect.h"
#include "Manager/PokemonMgr.h"
#include "Manager/BattleManager.h"
#include "Pokemon.h"
#include "PokeBall.h"
#include "CSkill.h"
#include "Npc.h"
#include "Item.h"
void Player::AddItem( Item* _Item)
{
	bool bFind = false;
	for (int i = 0; i < m_vecItem.size(); ++i) {
		if (m_vecItem[i]->GetName() == _Item->GetName())
		{
			m_vecItem[i]->AddItem(_Item->GetCount());
			bFind = true;
		}
	}
	if (!bFind)
	{
		m_vecItem.push_back(_Item);
	}

}
void Player::Roar()
{
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::P_READY) {
		m_BattlePosition.x -= 200 * Time::Delta();
		BattleRect->SetPosition(m_BattlePosition);
		BattleManager::Get()->GetPlayer()->GetBattleRect()->GetAnimator()->SetPause(false);
		if (m_BattlePosition.x + (BattleRect->GetWidth() / 2) < 0.f)
		{
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetPause(false);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetTopHeight(WinMaxHeight / 2 + (115 + 64) + 75);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetPos(Vector3(0.f, WinMaxHeight / 2 + (115 + 64), 0.f));
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetSize(
				Vector3(m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetHeight(), 0.f)
			);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Throw");
			BattleManager::Get()->SetCircumStance(BATTLE_CIR::P_ROAR);
		}
	}
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::P_ROAR) {
		if (m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->GetEnd() && !m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(false);
			m_vecPokemon[m_curPokemon]->SetPos(Vector3(WinMaxWidth / 2 - 150, WinMaxHeight / 2 + (115 + 74), 0.f));
			m_vecPokemon[m_curPokemon]->SetSize(Vector3(
				m_vecPokemon[m_curPokemon]->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetAnimRect()->GetHeight(), 0.f
			));
			m_vecPokemon[m_curPokemon]->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Our_Roar");
		}
		if (m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Our_IDLE");
			BattleManager::Get()->SetCircumStance(BATTLE_CIR::ALL_READY);
			BattleManager::Get()->AllReady();
			BattleManager::Get()->DoBehavior(false);
			BattleManager::Get()->PhaseOut();
			BattleManager::Get()->StartHpBar();
			BattleManager::Get()->PhaseReset();
			m_eSelect = SELECT_PHASE::COMPREHENSIVE;
		}
	}
}
void Player::Roar_BattleCir()
{
	if (BattleManager::Get()->ChangePokemonPhase() == (UINT)BATTLE_CIR::P_READY) {
		BattleManager::Get()->GetPlayer()->GetBattleRect()->GetAnimator()->SetPause(false);
		if (m_BattlePosition.x + (BattleRect->GetWidth() / 2) < 0.f)
		{
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetPause(false);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetTopHeight(WinMaxHeight / 2 + (115 + 64) + 75);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetPos(Vector3(0.f, WinMaxHeight / 2 + (115 + 64), 0.f));
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetSize(
				Vector3(m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetHeight(), 0.f)
			);
			m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Throw");
			BattleManager::Get()->addChangePokemonPhase();
		}
	}
	if (BattleManager::Get()->ChangePokemonPhase() == (UINT)BATTLE_CIR::P_ROAR) {
		if (m_vecPokemon[m_curPokemon]->GetPokeBall()->GetAnimRect()->GetAnimator()->GetEnd() && !m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetPokeBall()->SetRender(false);
			m_vecPokemon[m_curPokemon]->SetPos(Vector3(WinMaxWidth / 2 - 150, WinMaxHeight / 2 + (115 + 74), 0.f));
			m_vecPokemon[m_curPokemon]->SetSize(Vector3(
				m_vecPokemon[m_curPokemon]->GetAnimRect()->GetWidth(), m_vecPokemon[m_curPokemon]->GetAnimRect()->GetHeight(), 0.f
			));
			m_vecPokemon[m_curPokemon]->SetRender(true);
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Our_Roar");
		}
		if (m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->GetEnd()) {
			m_vecPokemon[m_curPokemon]->GetAnimRect()->GetAnimator()->SetCurrentAnimClip(L"Our_IDLE");
			BattleManager::Get()->addChangePokemonPhase();
			BattleManager::Get()->OurHpBarRender(true);
		}
	}
}
void Player::BattlePhase()
{
	if (BATTLE_STATE::NONE == m_eBattleState)
		return;
	if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::ALL_READY
		|| BattleManager::Get()->GetCircumStance() == BATTLE_CIR::N_DEAD
		|| BattleManager::Get()->GetCircumStance() == BATTLE_CIR::P_DEAD) {
		if (KEYUP(VK_RIGHT))
		{
		int	m_prevselect = m_iSelect;
			m_iSelect += 1; 
				switch (m_eSelect)
				{

				case SELECT_PHASE::COMPREHENSIVE:
					if(m_iSelect>4)
					m_iSelect = 1;
					break;
				case SELECT_PHASE::SKILL:
					if (m_iSelect > 5)
					m_iSelect = 1;
				
					break;
				case SELECT_PHASE::ITEM:
				
						if (bDetailItemSelect == ITEM_SELECT::NONE)
						{
							if (m_iSelect > 6)
							{
								m_iSelect = 0;
							}
						}

						else if (bDetailItemSelect == ITEM_SELECT::LIST)
						{
						
							if (m_iSelect > 7)
							{
								m_iSelect = 0;
							}
							BattleManager::Get()->ItemAnimationButton(m_prevselect, m_iSelect);

						}
				
					break;
				case SELECT_PHASE::POKEMON:
					if (m_iSelect > 7)
					m_iSelect = 1;
					if(!bChangePokemon)
					BattleManager::Get()->BattleAnimationButton(m_prevselect, m_iSelect);
					else
						BattleManager::Get()->BattleAnimationChangeButton(m_prevselect, m_iSelect);
					break;
				case SELECT_PHASE::RUN:
					break;
				case SELECT_PHASE::CHANGEORNOT:
					if (m_iSelect >2)
						m_iSelect = 0;
					break;
			}
		}
	
		if (KEYUP(VK_LEFT)) {
			int	m_prevselect = m_iSelect;
			m_iSelect -= 1;
			switch (m_eSelect)
			{

			case SELECT_PHASE::COMPREHENSIVE:
				if (m_iSelect < 0) 
				m_iSelect = 4;
				break;
			case SELECT_PHASE::SKILL:
				if (m_iSelect < 0)
				m_iSelect = 5;
				break;
			case SELECT_PHASE::ITEM:
				if (m_iSelect < 0)
					if (bDetailItemSelect == ITEM_SELECT::NONE)
					{
						m_iSelect = 6;

					}
					else if (bDetailItemSelect == ITEM_SELECT::LIST)
					{
						m_iSelect = 7;
						BattleManager::Get()->ItemAnimationButton(m_prevselect, m_iSelect);

					}
				break;
			case SELECT_PHASE::POKEMON:
				if (m_iSelect < 0)
				
				if (!bChangePokemon) {
					m_iSelect = 7;
					BattleManager::Get()->BattleAnimationButton(m_prevselect, m_iSelect);
				}
				else {
					m_iSelect = 2;
					BattleManager::Get()->BattleAnimationChangeButton(m_prevselect, m_iSelect);
				}
				break;
			case SELECT_PHASE::RUN:
				break;
		

			}
			
		}
	}
	switch (m_eSelect)
	{

	case SELECT_PHASE::COMPREHENSIVE:
	{
		if (m_iSelect == 1) {
			if (KEYUP(VK_SPACE)) {
				BattleManager::Get()->PhaseIn();
				m_eSelect = SELECT_PHASE::SKILL;
				m_iSelect = 0;
			}
		}
		else if (m_iSelect == 2) {
			if (KEYUP(VK_SPACE)) {
			
				m_eSelect = SELECT_PHASE::ITEM;
				BattleManager::Get()->RenderBattleItemBar(true);
				m_iSelect = 0;
				
			}
		}
		else if (m_iSelect == 3) {
			if (KEYUP(VK_SPACE)) {

			}
		}
		else if (m_iSelect == 4) {
			if (KEYUP(VK_SPACE)) {
				m_eSelect = SELECT_PHASE::POKEMON;
				BattleManager::Get()->RenderPokemonSelect();
				m_iSelect = 0;
			}
		}
	}
		break;
	case SELECT_PHASE::SKILL:
	{
		if (m_iSelect == 5) {
			if (KEYUP(VK_SPACE)) {
			BattleManager::Get()->PhaseOut();
			m_eSelect = SELECT_PHASE::COMPREHENSIVE;
			m_iSelect = 0;
			}
		}
		else {
			if (m_iSelect == 0)
				return;
			if (KEYUP(VK_SPACE)) {
				if (m_vecPokemon[m_curPokemon]->GetSkills()[m_iSelect - 1]->GetCurPP() <= 0)return;
				if (m_iSelect >= GetCurPokemons()->GetSkills().size())return;

				m_vecPokemon[m_curPokemon]->GetSkills()[m_iSelect - 1]->SubCurPP();
				BATTLE_BEHAVIOR behavior;
				behavior.eBattle = BATTLE_TYPE::SKILL;
				behavior.wParam = (DWORD_PTR)m_vecPokemon[m_curPokemon]->GetSkills()[m_iSelect-1];
				BattleManager::Get()->DoBehavior();
				BattleManager::Get()->PlayerBehavior(behavior);
				m_iSelect = 0;
				bbehavior = true;
			}
		}
	}
		break;
	case SELECT_PHASE::ITEM:
	{
		if (KEYUP(VK_SPACE)) {
			if (!m_iSelect)
				return;
			
			if (bDetailItemSelect == ITEM_SELECT::NONE) {
				if (6 == m_iSelect) {
					m_eSelect = SELECT_PHASE::COMPREHENSIVE;
					BattleManager::Get()->RenderBattleItemBar(false);
					m_iSelect = 0;
				}

				else {
					if (5 == m_iSelect)return;// 최근 아이템 목록
					if (2 == m_iSelect) {
						BattleManager::Get()->NotRenderBattleItemBar();
					}
					bDetailItemSelect = ITEM_SELECT::LIST;
					m_iSelect = 0;
				}
			}
			else if (bDetailItemSelect == ITEM_SELECT::LIST) {

			}

		}
	}


		break;
	case SELECT_PHASE::POKEMON:
	{
		if (m_iSelect == 7) {
			if (KEYUP(VK_SPACE)) {
				if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::ALL_READY) {
					BattleManager::Get()->NotRenderPokemonSelect();
					m_iSelect = 0;
					m_eSelect = SELECT_PHASE::COMPREHENSIVE;
				}
				else
				{
					m_iSelect = 0;
					m_eSelect = SELECT_PHASE::CHANGEORNOT;
					BattleManager::Get()->NotRenderPokemonSelect();
					BattleManager::Get()->ChangeButtonRender(true);
				}
			}
			
		}
		else {
			
				if (m_iSelect != 0) {
					if (KEYUP(VK_SPACE)) {
						if (BattleManager::Get()->GetCircumStance() == BATTLE_CIR::ALL_READY) {
							if (!bChangePokemon) {
								m_iChangePokemon = m_iSelect;
								BattleManager::Get()->RenderChangeButton(true);
								m_iSelect = 0;
								bChangePokemon = true;
							}
							else {
								if (m_iSelect == 2) {
									BattleManager::Get()->RenderChangeButton(false);
									m_iSelect = 0;
									bChangePokemon = false;
								}
								if (1 == m_iSelect) {
									//포켓몬 변경
									if (m_vecPokemon[m_iChangePokemon - 1]->GetHp() <= 0)
										return;
									BattleManager::Get()->RenderChangeButton(false, false);
									BattleManager::Get()->NotRenderPokemonSelect();
									swap(m_vecPokemon[m_curPokemon], m_vecPokemon[m_iChangePokemon - 1]);

									if (BattleManager::Get()->GetCircumStance() != BATTLE_CIR::N_DEAD ||
										BattleManager::Get()->GetCircumStance() != BATTLE_CIR::P_DEAD) {
										BATTLE_BEHAVIOR behavior;
										behavior.eBattle = BATTLE_TYPE::CHANGE;
										behavior.wParam = m_iChangePokemon;
										BattleManager::Get()->DoBehavior();
										BattleManager::Get()->PlayerBehavior(behavior);
										BattleManager::Get()->OurHpBarRender(false);
										bbehavior = true;

									}
									else {
										BATTLE_BEHAVIOR behavior;
										behavior.eBattle = BATTLE_TYPE::CHANGE;
										behavior.wParam = m_iChangePokemon;
										BattleManager::Get()->PlayerBehavior(behavior);
									}
									bChangePokemon = false;
								}
							}
						}
						else {
							if (!bChangePokemon) {
								m_iChangePokemon = m_iSelect;
								BattleManager::Get()->RenderChangeButton(true);
								m_iSelect = 0;
								bChangePokemon = true;
							}
							else {
								if (m_iSelect == 2) {
									BattleManager::Get()->RenderChangeButton(false);
									m_iSelect = 0;
								
									bChangePokemon = false;
									BattleManager::Get()->SetCircumStance(BATTLE_CIR::N_DEAD);
								}
								if (1 == m_iSelect) {
									//포켓몬 변경
									if (m_vecPokemon[m_iChangePokemon - 1]->GetHp() <= 0)
										return;
									BattleManager::Get()->ChangeButtonRender(false);
									BattleManager::Get()->RenderChangeButton(false, false);
									BattleManager::Get()->NotRenderPokemonSelect();
									swap(m_vecPokemon[m_curPokemon], m_vecPokemon[m_iChangePokemon - 1]);
									BattleManager::Get()->NPCCurDead();
									
									BattleManager::Get()->SetOurChangePokemon(true);
									BattleManager::Get()->SetCircumStance(BATTLE_CIR::N_DEAD);
									bChangePokemon = false;
									m_iSelect = 0;

								}
							}
						}

					}
					if (bChangePokemon) {
						if (KEYUP(VK_LEFT)) {
							if (m_iSelect < 0)
								m_iSelect = 2;
						}
						if (KEYUP(VK_RIGHT)) {

							if (m_iSelect > 2)
								m_iSelect = 0;
						}
					}

					
				}
			
		}
	}
		break;
	case SELECT_PHASE::RUN:
		break;
	case SELECT_PHASE::CHANGEORNOT:
		if (KEYUP(VK_SPACE)) {
			if (m_iSelect == 1) {
				m_eSelect = SELECT_PHASE::POKEMON;
				BattleManager::Get()->RenderPokemonSelect();
				BattleManager::Get()->ChangeButtonRender(false);
				BattleManager::Get()->CancelSelectorRender(false);
				m_iSelect = 0;

			}
			else if (m_iSelect == 2) {

				BattleManager::Get()->SetOurChangePokemon(false);
				BattleManager::Get()->ChangeButtonRender(false);
				BattleManager::Get()->CancelSelectorRender(false);
				BattleManager::Get()->SetOurChangePokemon(false);
				BattleManager::Get()->NPCCurDead();

				BattleManager::Get()->GetNpc()->FindPokemon();
				m_iSelect = 0;
			}
		}
		if (KEYUP(VK_RIGHT)) {
			if (m_iSelect > 2)
				m_iSelect = 0;

		}
		if (KEYUP(VK_LEFT)) {
			if (m_iSelect < 0)
				m_iSelect = 2;

		}
		break;

	}
}
void Player::SetPosition(const Vector3& _Position)
{
	m_Position = _Position;
	AnimRect->SetPosition(_Position);
}
void Player::SetBattlePosition(const Vector3& _Position)
{
	m_BattlePosition = _Position;
	BattleRect->SetPosition(_Position);
}
void Player::SetSize(const Vector3& _Size)
{
	AnimRect->SetSize(_Size); this->SetSz(_Size);
}
void Player::SetBattleSize(const Vector3& _Size)
{
	BattleRect->SetSize(_Size); this->SetSz(_Size);
}
void Player::Move()
{




}
void Player::Init()
{
	AnimRect = new AnimationRect(Vector3(0,0,0),Vector3(0,0,0));
	BattleRect = new AnimationRect(Vector3(0, 0, 0), Vector3(0, 0, 0));
	Texture2D* srcTex = new Texture2D(TexturePath + L"Pokemon/Char/Player48.png");
	Texture2D* IconTex = new Texture2D(TexturePath + L"Pokemon/Char/PlayerBattle.png");
	AnimRect->SetHeight(srcTex->GetHeight()/5);
	AnimRect->SetWidth(srcTex->GetWidth() / 12);
	BattleRect->SetHeight(IconTex->GetHeight());
	BattleRect->SetWidth(IconTex->GetWidth() /4);
	Animator* animator = new Animator;
	AnimationClip* clip = new AnimationClip(L"IDLE_D", srcTex, 1, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() /12.F, srcTex->GetHeight()*0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip= new AnimationClip(L"IDLE_U", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"IDLE_L", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight()*0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"IDLE_R", srcTex, 1, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() /12.f, srcTex->GetHeight()*0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);

	clip = new AnimationClip(L"WALK_D", srcTex, 4, Values::ZeroVec2,
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_U", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_L", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"WALK_R", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() / 3.0F, srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);


	clip = new AnimationClip(L"RUN_D", srcTex, 4, Vector2(srcTex->GetWidth() / 3.0F, 0),
		Vector2(srcTex->GetWidth() /1.5f, srcTex->GetHeight() * 0.2f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_U", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.2f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.4f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_L", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.4f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.6f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	clip = new AnimationClip(L"RUN_R", srcTex, 4, Vector2(0.f, srcTex->GetHeight() * 0.6f),
		Vector2(srcTex->GetWidth() / 1.5f, srcTex->GetHeight() * 0.8f), 1.0f / 15.0f);
	animator->AddAnimClip(clip);
	AnimRect->SetAnimation(animator);
	animator->SetCurrentAnimClip(L"IDLE_D");
	animator = new Animator;
	clip = new AnimationClip(L"BATTLE", IconTex, 5, Values::ZeroVec2,
		Vector2(IconTex->GetWidth(), IconTex->GetHeight()), 0.15f );
	clip->SetRepeat(false);
	animator->AddAnimClip(clip);
	animator->SetCurrentAnimClip(L"BATTLE");
	BattleRect->SetAnimation(animator);


	SAFE_DELETE(srcTex);
	SAFE_DELETE(IconTex);
}
Player::Player() {
	Pokemon* pokemon = new Pokemon(L"Infernape", 100, 100, 100, 10, 30,100);
	pokemon->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 100);
	pokemon->GetSkills()[0]->SetSkillMVRIGHType();
	pokemon->AddSkill(L"BURN", SKILL_TYPE::FIRE, 30, 30, 30,true);



	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bibarel", 100, 100, 100, 10, 30,70);
	pokemon->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	pokemon->GetSkills()[0]->SetSkillMVRIGHType();
	m_vecPokemon.push_back(pokemon);
	pokemon = new Pokemon(L"Bronzong", 100, 100, 100, 10, 30,60);
	pokemon->AddSkill(L"Tackle", SKILL_TYPE::NORMAL, 30, 30, 30);
	pokemon->GetSkills()[0]->SetSkillMVRIGHType();
	m_vecPokemon.push_back(pokemon);
	AnimRect = nullptr;
	BattleRect = nullptr;

	Item* item = new Item();
	sItem sitem = {};
	sitem.Name=L"Max Potion";
	sitem.m_iCount = 1;
	sitem.m_iValue = 9950;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(1, 4);
	AddItem(item);

	item = new Item();
	sitem = {};
	sitem.Name = L"Pokeball";
	sitem.m_iCount = 1;
	sitem.m_iValue = 0;
	sitem.m_eType = ITEM_TYPE::BALL;
	item->SetItem(sitem);
	item->AnimInit(2, 9);
	AddItem(item);

	item = new Item();
	sitem = {};
	sitem.Name = L"Full Restore";
	sitem.m_iCount = 1;
	sitem.m_iValue =9949;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(2, 4);
	AddItem(item);
	item = new Item();
	sitem = {};
	sitem.Name = L"Hyper Potion";
	sitem.m_iCount = 1;
	sitem.m_iValue = 120;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(5, 4);
	AddItem(item);
	item = new Item();
	sitem = {};
	sitem.Name = L"Super Potion";
	sitem.m_iCount = 1;
	sitem.m_iValue = 60;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(4, 4);
	AddItem(item);
	item = new Item();
	sitem = {};
	sitem.Name = L"Potion";
	sitem.m_iCount = 1;
	sitem.m_iValue = 20;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(3, 4);
	AddItem(item);
	item = new Item();
	sitem = {};
	sitem.Name = L"Ether";
	sitem.m_iCount = 1;
	sitem.m_iValue = 10;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(2, 5	);
	AddItem(item);
	item = new Item();
	sitem = {};
	sitem.Name = L"Max Ether";
	sitem.m_iCount = 1;
	sitem.m_iValue = 5;
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(3, 5);
	AddItem(item);
	item = new Item();
	sitem = {};
	sitem.Name = L"Elixir";
	sitem.m_iCount = 1;
	sitem.m_iValue = 9910;// 전체 기술회복
	sitem.m_eType = ITEM_TYPE::HEAL;
	item->SetItem(sitem);
	item->AnimInit(3, 5);
	AddItem(item);

}

Player::Player(const Player& _Other)
{
	for (int i = 0; i < _Other.m_vecPokemon.size(); ++i) {
		Pokemon* pokemon = new Pokemon(*_Other.m_vecPokemon[i]);
		m_vecPokemon.push_back(pokemon);
	}
	for (size_t i = 0; i < _Other.m_vecItem.size(); ++i) {
		Item* citem = new Item(*_Other.m_vecItem[i]);
		m_vecItem.push_back(citem);

	}

	m_Position = _Other.m_Position;
	m_BattlePosition = _Other.m_BattlePosition;
	this->Init();
	this->m_PrevPos = _Other.m_PrevPos;
	this->m_eDir = _Other.m_eDir;
}
Player::~Player() {

	SAFE_DELETE(AnimRect);
	SAFE_DELETE(BattleRect);

	for (size_t i = 0; i < m_vecPokemon.size(); ++i) {
		SAFE_DELETE(m_vecPokemon[i]);
	}
	for (size_t i = 0; i < m_vecItem.size(); ++i) {
		SAFE_DELETE(m_vecItem[i]);
	}
}



void Player::Update()
{
	Move();
	Roar();
	BattlePhase();
	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Update();
	}
	else {
		BattleRect->Update();
	}
	if (nullptr != m_vecPokemon[m_curPokemon])
	{
		m_vecPokemon[m_curPokemon]->Update();
	}

	for (size_t i = 1; i < m_vecPokemon.size(); ++i) {
		m_vecPokemon[i]->Update();
	}
}

void Player::Render()
{

	if (BATTLE_STATE::NONE == m_eBattleState) {
		AnimRect->Render();
	}
	else {
		BattleRect->Render();
	}
	if (nullptr != m_vecPokemon[m_curPokemon])
	{
		m_vecPokemon[m_curPokemon]->Render();
	}
}

void Player::PostRender()
{
	for (size_t i = 0; i < m_vecPokemon.size(); ++i) {
		m_vecPokemon[i]->PostRender();
	}
}
