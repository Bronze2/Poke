#include "Framework.h"
#include "BattleManager.h"
#include "Object/Player.h"
#include "Object/Npc.h"
#include "Object/UI.h"
#include "Object/TextureObject.h"
#include "Geometries/TextureRect.h"
#include "Geometries/AnimationRect.h"
#include "Object/Pokemon.h"
#include "Utilities/Animator.h"
#include "Object/Item.h"
#include "Object/CSkill.h"
#include "Object/UI/ProgressBar.h"
#include "Object/UI/CFont.h"

void BattleManager::OurHpBarRender(const bool& _bRender)
{
	OurHpBar->SetRender(_bRender);
	OurHpPoint->SetRender(_bRender);
	m_Player->GetCurPokemons()->GetNameFont()->SetRender(_bRender);
	m_Player->GetCurPokemons()->GetHpFont()->SetRender(_bRender);
	m_Player->GetCurPokemons()->GetMaxHpFont()->SetRender(_bRender);
	m_Player->GetCurPokemons()->GetLevelFont()->SetRender(_bRender);
	m_Player->GetCurPokemons()->GetNameFont()->SetPosition(Vector3(350, 555, 0.f), true);
	m_Player->GetCurPokemons()->GetMaxHpFont()->SetPosition(Vector3(460, 523, 0.f), true);
	m_Player->GetCurPokemons()->GetHpFont()->SetPosition(Vector3(410, 523, 0.f), true);
	if (_bRender) {
		float percent = (float)m_Player->GetCurPokemons()->GetHp() / (float)m_Player->GetCurPokemons()->GetMaxHp();
		if (0.2f < percent && percent <= 0.5f) {

			OurHpPoint->SetColor(Color(1, 1, 0, 1));

		}
		else if (percent <= 0.2f)
			OurHpPoint->SetColor(Color(1, 0, 0, 1));
		else
			OurHpPoint->SetColor(Color(0, 1, 0, 1));
		OurHpPoint->UpdateProgressBar(percent);
	}
}
void BattleManager::BackButtonAnimation()
{
	BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
}
void BattleManager::OpponentHpBarRender(const bool& _bRender)
{
	OpponentHpBar->SetRender(_bRender);
	OpponentHpPoint->SetRender(_bRender);
	m_Npc->GetCurPokemons()->GetNameFont()->SetRender(_bRender);
	m_Npc->GetCurPokemons()->GetHpFont()->SetRender(_bRender);
	m_Npc->GetCurPokemons()->GetMaxHpFont()->SetRender(_bRender);
	m_Npc->GetCurPokemons()->GetLevelFont()->SetRender(_bRender);
	if (_bRender) {
		float percent = (float)m_Npc->GetCurPokemons()->GetHp() / (float)m_Npc->GetCurPokemons()->GetMaxHp();
		if (0.2f < percent && percent <= 0.5f) {

			OpponentHpPoint->SetColor(Color(1, 1, 0, 1));

		}
		else if (percent <= 0.2f)
			OpponentHpPoint->SetColor(Color(1, 0, 0, 1));
		else 
			OpponentHpPoint->SetColor(Color(0, 1, 0, 1));
		OpponentHpPoint->UpdateProgressBar(percent);
	}
}
void BattleManager::BattleAnimationButton(UINT _prev, UINT _now)
{
	switch (_prev)
	{
	case 1:
		ourvecPokemon[0]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
		break;
	case 2:
		if (ourvecPokemon[1]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[1]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
		}
		break;
	case 3:
		if (ourvecPokemon[2]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[2]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
		}
		
		break;
	case 4:
		if (ourvecPokemon[3]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[3]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
		}
		break;
	case 5:
		if (ourvecPokemon[4]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[4]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
		}
		break;
	case 6:
		if (ourvecPokemon[5]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[5]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
		}
		break;
	case 7:
		BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		break;
	default:
		break;
	}
	switch (_now)
	{
	case 1:
		ourvecPokemon[0]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectPokemon");
		break;
	case 2:
		if (ourvecPokemon[1]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[1]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectPokemon");
		}
		break;
	case 3:
		if (ourvecPokemon[2]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[2]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectPokemon");
		}
		break;
	case 4:
		if (ourvecPokemon[3]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[3]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectPokemon");
		}
		break;
	case 5:
		if (ourvecPokemon[4]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[4]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectPokemon");
		}
		break;
	case 6:
		if (ourvecPokemon[5]->GetTex()->GetAnimator()->GetCurrentClip()->GetName() != L"Nope")
		{
			ourvecPokemon[5]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectPokemon");
		}
		break;
	case 7:
		BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		break;
	default:
		break;
	}
}

void BattleManager::ItemAnimationButton(UINT _prev, UINT _now)
{
	switch (_prev)
	{
	case 1:
		m_vecItemSelect[0]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		break;
	case 2:
		m_vecItemSelect[1]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		
		break;
	case 3:
		m_vecItemSelect[2]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");


		break;
	case 4:
		m_vecItemSelect[3]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");

		break;
	case 5:
		PrevButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		break;
	case 6:
		NextButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		break;
	case 7:
		BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		break;
	
	}
	switch (_now)
	{
	case 1:
		m_vecItemSelect[0]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		break;
	case 2:
		m_vecItemSelect[1]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");

		break;
	case 3:
		m_vecItemSelect[2]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");


		break;
	case 4:
		m_vecItemSelect[3]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");

		break;
	case 5:
		PrevButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		break;
	case 6:
		NextButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		break;
	case 7:
		BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		break;

	}
}


void BattleManager::BattleAnimationChangeButton(UINT _prev, UINT _now)
{
	switch (_prev)
	{
	case 1:
		BattleChangeButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		break;
	case 2:
		
		BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurButton");
		
		break;

	}
	switch (_now)
	{
	case 1:
		BattleChangeButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		break;
	case 2:
		
		BackButton->GetTex()->GetAnimator()->SetCurrentAnimClip(L"SelectButton");
		
		break;
	}
}

void BattleManager::RenderBattleItemBar(const bool& _bTrue)
{

	BattleItemBar->SetRender(_bTrue);
	BattlePhase->SetRender(!_bTrue);
	ItemSelector->SetRender(false);
}
vector<Item*> BattleManager::GetvecHealItem()
{
	return m_vecHealItem;
}

void BattleManager::EraseItem(Item* item)
{
	vector<Item*>::iterator iter = m_vecHealItem.begin();
	bool bFind = false;
	Item* items = nullptr;
	for (size_t i = 0; i < BattleManager::Get()->GetvecHealItem().size(); ++i) {

		if (BattleManager::Get()->GetvecHealItem()[i] == item) {
			bFind = true;
			items = BattleManager::Get()->GetvecHealItem()[i];
		
			break;
		}
		iter++;
	}
	DeleteItem.push_back( items);
	m_vecHealItem.erase(iter);
}


void BattleManager::NotRenderBattleItemBar()
{
	BattleItemBar->SetRender(false);
	BackGround->SetRender(true);
	BackButton->SetRender(true);
	ItemSelector->SetRender(false);
	for (size_t i = 0; i <m_vecItemSelect.size(); ++i)
	{
		m_vecItemSelect[i]->SetRender(true);
	}
	for (size_t i = 0; i < 4; ++i) {
		if (i >= m_vecHealItem.size())continue;
		m_vecHealItem[i]->SetRender(true);
		if (i == 0) {
			m_vecHealItem[i]->SetPos(Vector3(128.f, 345.f, 0.f));
		}
		if (i == 1) {
			m_vecHealItem[i]->SetPos(Vector3(384.f, 345.f, 0.f));
		}
		if (i == 2) {
			m_vecHealItem[i]->SetPos(Vector3(128.f, 190.f, 0.f));
		}
		if (i == 3) {
			m_vecHealItem[i]->SetPos(Vector3(384.f, 190.f, 0.f));
		}
		m_vecHealItem[i]->SetSize(Vector3(64, 64, 0));
	}


	PrevButton->SetRender(true);
	NextButton->SetRender(true);
}
void BattleManager::NotRenderBattleItemBar(const bool& _bTrue)
{

	BattleItemBar->SetRender(!_bTrue);
	BackGround->SetRender(_bTrue);
	BackButton->SetRender(_bTrue);
	ItemSelector->SetRender(!_bTrue);
	for (size_t i = 0; i < m_vecItemSelect.size(); ++i)
	{
		m_vecItemSelect[i]->SetRender(_bTrue);
	}
	for (size_t i = 0; i < 4; ++i) {
		if (i >= m_vecHealItem.size())continue;
		m_vecHealItem[i]->SetRender(_bTrue);
		if (i == 0) {
			m_vecHealItem[i]->SetPos(Vector3(128.f, 345.f, 0.f));
		}
		if (i == 1) {
			m_vecHealItem[i]->SetPos(Vector3(384.f, 345.f, 0.f));
		}
		if (i == 2) {
			m_vecHealItem[i]->SetPos(Vector3(128.f, 190.f, 0.f));
		}
		if (i == 3) {
			m_vecHealItem[i]->SetPos(Vector3(384.f, 190.f, 0.f));
		}
		m_vecHealItem[i]->SetSize(Vector3(64, 64, 0));
	}


	PrevButton->SetRender(_bTrue);
	NextButton->SetRender(_bTrue);
}
void BattleManager::NextButtonUpdate(vector<Item*> _item)
{
	UINT Size = _item.size();
	int Value = Size / 4;
	int Value2 = Size % 4;

	if ((m_iCuritemSelect + 1 <= Value)) {
		if ((Value2 > 0)&&(m_iCuritemSelect+1==Value)) {
			for (int i = (4 * (m_iCuritemSelect)); i < (4 * (m_iCuritemSelect + 1)); ++i) {
				_item[i]->SetRender(false);
			}
			m_iCuritemSelect += 1;
			for (int i = (4 * (m_iCuritemSelect)); i < (4 * (m_iCuritemSelect + 1)); ++i) {
				if (_item.size() <= i)break;
				UINT j = i % 4;
				if (j == 0) {
					_item[i]->SetPos(Vector3(128.f, 345.f, 0.f));
				}
				if (j == 1) {
					_item[i]->SetPos(Vector3(384.f, 345.f, 0.f));
				}
				if (j == 2) {
					_item[i]->SetPos(Vector3(128.f, 190.f, 0.f));
				}
				if (j == 3) {
					_item[i]->SetPos(Vector3(384.f, 190.f, 0.f));
				}
				_item[i]->SetRender(true);
				_item[i]->SetSize(Vector3(64, 64, 0));
			}
		}
		else {
			if (m_iCuritemSelect + 1 < Value) {
				for (int i = (4 * (m_iCuritemSelect)); i < (4 * (m_iCuritemSelect + 1)); ++i) {
					_item[i]->SetRender(false);
				}
				m_iCuritemSelect += 1;
				for (int i = (4 * (m_iCuritemSelect)); i < (4 * (m_iCuritemSelect + 1)); ++i) {
					if (_item.size() <= i)break;
					UINT j = i % 4;
					if (j== 0) {
						_item[i]->SetPos(Vector3(128.f, 345.f, 0.f));
					}
					if (j == 1) {
						_item[i]->SetPos(Vector3(384.f, 345.f, 0.f));
					}
					if (j == 2) {
						_item[i]->SetPos(Vector3(128.f, 190.f, 0.f));
					}
					if (j == 3) {
						_item[i]->SetPos(Vector3(384.f, 190.f, 0.f));
					}
					_item[i]->SetRender(true);
					_item[i]->SetSize(Vector3(64, 64, 0));
				}
			}
		}
	}
}
void BattleManager::PrevButtonUpdate(vector<Item*> _item)
{
	if (m_iCuritemSelect == 0)return;
	for (int i = (4 * (m_iCuritemSelect)); i < (4 * (m_iCuritemSelect + 1)); ++i) {
		if (_item.size() < i)break;
		_item[i]->SetRender(false);
	}
	m_iCuritemSelect -= 1;
	for (int i = (4 * (m_iCuritemSelect)); i < (4 * (m_iCuritemSelect + 1)); ++i) {
		_item[i]->SetRender(true);
		_item[i]->SetSize(Vector3(64, 64, 0));
	}
}
void BattleManager::NotRenderBattleItemBarBall()
{
	BattleItemBar->SetRender(false);
	BackGround->SetRender(true);
	BackButton->SetRender(true);
	ItemSelector->SetRender(false);
	for (size_t i = 0; i < m_vecItemSelect.size(); ++i)
	{
		m_vecItemSelect[i]->SetRender(true);
	}
	for (size_t i = 0; i < 4; ++i) {
		if (i >= m_vecBallItem.size())continue;
		m_vecBallItem[i]->SetRender(true);
		if (i == 0) {
			m_vecBallItem[i]->SetPos(Vector3(128.f, 345.f, 0.f));
		}
		if (i == 1) {
			m_vecBallItem[i]->SetPos(Vector3(384.f, 345.f, 0.f));
		}
		if (i == 2) {
			m_vecBallItem[i]->SetPos(Vector3(128.f, 190.f, 0.f));
		}
		if (i == 3) {
			m_vecBallItem[i]->SetPos(Vector3(384.f, 190.f, 0.f));
		}
		m_vecBallItem[i]->SetSize(Vector3(64, 64, 0));
	}


	PrevButton->SetRender(true);
	NextButton->SetRender(true);
}
void BattleManager::NotRenderBattleItemBarBall(const bool& _bTrue)
{
}
void BattleManager::RenderPokemonSelect()
{

	BackGround->SetRender(true);
	for (size_t i = 0; i < ourvecPokemon.size(); ++i) {
		if (i < m_Player->GetPokemons().size()) {
			ourvecPokemon[i]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
			if (i == 0) {
				m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(55, 330, 0));
				m_Player->GetPokemons()[i]->GetBar()->SetPosition(Vector3(127, 324, 0));
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(Vector3(140,345,0), true);
			}
			else if (i == 1) {
				m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(310, 330, 0));

				m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(Vector3(385, 345, 0), true);
				m_Player->GetPokemons()[i]->GetBar()->SetPosition(Vector3(383, 324, 0));
			}
			else if (i == 2) {
				m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(55, 240, 0));
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(Vector3(140, 255, 0), true);
				m_Player->GetPokemons()[i]->GetBar()->SetPosition(Vector3(127, 234, 0));
			}
			else if (i == 3) {
				m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(310, 240, 0));
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(Vector3(385, 255, 0), true);
				m_Player->GetPokemons()[i]->GetIconRect()->SetSize(
					Vector3(m_Player->GetPokemons()[i]->GetIconRect()->GetWidth(), m_Player->GetPokemons()[i]->GetIconRect()->GetHeight(), 0)
				);
				m_Player->GetPokemons()[i]->GetBar()->SetPosition(Vector3(383, 234, 0));
			}
			else if (i ==4) {
				m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(55, 150, 0));
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(Vector3(140, 165, 0), true);
				m_Player->GetPokemons()[i]->GetBar()->SetPosition(Vector3(127, 144, 0));
			}
			else if (i == 5) {
				m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(310, 150, 0));
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(Vector3(385, 165, 0), true);
				m_Player->GetPokemons()[i]->GetBar()->SetPosition(Vector3(383, 144, 0));
			}
			m_Player->GetPokemons()[i]->GetIconRect()->SetSize(
				Vector3(m_Player->GetPokemons()[i]->GetIconRect()->GetWidth(), m_Player->GetPokemons()[i]->GetIconRect()->GetHeight(), 0)
			);
			m_Player->GetPokemons()[i]->GetBar()->SetRender(true);
			m_Player->GetPokemons()[i]->GetIconNameFont()->SetRender(true);
		}
		else {
			ourvecPokemon[i]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"Nope");
		}
		
		ourvecPokemon[i]->SetRender(true);
	}
	BackButton->SetRender(true);
	for (size_t i = 0; i < m_Player->GetPokemons().size(); ++i) {
		m_Player->GetPokemons()[i]->SetIconSize(Vector3(m_Player->GetPokemons()[i]->GetIconRect()->GetWidth(), m_Player->GetPokemons()[i]->GetIconRect()->GetHeight(), 0));
	}
}
void BattleManager::NotRenderPokemonSelect()
{
	BackButton->SetRender(false);
	for (size_t i = 0; i < m_Player->GetPokemons().size(); ++i) {
		m_Player->GetPokemons()[i]->SetIconSize(Vector3(0.f, 0.f, 0));
		m_Player->GetPokemons()[i]->GetBar()->SetRender(false);
		m_Player->GetPokemons()[i]->GetIconNameFont()->SetRender(false);
	}
	BackGround->SetRender(false);
	for (size_t i = 0; i < ourvecPokemon.size(); ++i) {

		ourvecPokemon[i]->SetRender(false);
	}
}
void BattleManager::RenderChangeButton(bool _bRender,bool _bRend)
{
	BattleChangeButton->SetRender(_bRender);

	if (_bRender == true) {
		for (size_t i = 0; i < ourvecPokemon.size(); ++i) {
			if (i < m_Player->GetPokemons().size()) {
				if (m_Player->GetSelect() - 1 != i) {
					
					m_Player->GetPokemons()[i]->SetIconSize(Vector3(0.f, 0.f, 0));
				}
				else {
					ourvecPokemon[i]->GetTex()->GetAnimator()->SetCurrentAnimClip(L"CurPokemon");
					m_Player->GetPokemons()[i]->SetIconPos(Vector3(WinMaxWidth / 2, 225, 0));
				}
				m_Player->GetPokemons()[i]->GetBar()->SetRender(false);
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetRender(false);
			}
			ourvecPokemon[i]->SetRender(false);
			
		}
	}
	else {
		for (size_t i = 0; i < ourvecPokemon.size(); ++i) {
			if (i < m_Player->GetPokemons().size()) {
				if (i == 0) {
					m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(55, 330, 0));
					
				}
				else if (i == 1) {
					m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(310, 330, 0));


					
				}
				else if (i == 2) {
					m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(55, 240, 0));

				}
				else if (i == 3) {
					m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(310, 240, 0));

					
				}
				else if (i == 4) {
					m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(55, 150, 0));

					
				}
				else if (i == 5) {
					m_Player->GetPokemons()[i]->GetIconRect()->SetPosition(Vector3(310, 150, 0));

					
				}

				m_Player->GetPokemons()[i]->GetBar()->SetRender(true);
				m_Player->GetPokemons()[i]->GetIconRect()->SetSize(
					Vector3(m_Player->GetPokemons()[i]->GetIconRect()->GetWidth(), m_Player->GetPokemons()[i]->GetIconRect()->GetHeight(), 0)
				);
				m_Player->GetPokemons()[i]->GetIconNameFont()->SetRender(true);
			}
			ourvecPokemon[i]->SetRender(true);

		}
	}
	BackButton->SetRender(_bRend);
}
void BattleManager::StartHpBar()
{
	int i = m_Npc->GetCurPokemons()->GetHp();
	
	float percent = (float)((float)i / (float)m_Npc->GetCurPokemons()->GetMaxHp());
	if (0.2f < percent && percent <= 0.5f) {

		OpponentHpPoint->SetColor(Color(1, 1, 0, 1));

	}
	else if (percent <= 0.2f)
		OpponentHpPoint->SetColor(Color(1, 0, 0, 1));
	else
		OpponentHpPoint->SetColor(Color(0, 1, 0, 1));
	OpponentHpPoint->UpdateProgressBar(percent);
	i = m_Player->GetCurPokemons()->GetHp();

	percent = (float)((float)i / (float)m_Player->GetCurPokemons()->GetMaxHp());
	if (0.2f < percent && percent <= 0.5f) {

		OurHpPoint->SetColor(Color(1, 1, 0, 1));

	}
	else if (percent <= 0.2f)
		OurHpPoint->SetColor(Color(1, 0, 0, 1));
	else
		OurHpPoint->SetColor(Color(0, 1, 0, 1));
	OurHpPoint->UpdateProgressBar(percent);
	m_Player->GetCurPokemons()->GetNameFont()->SetRender(true);
	m_Player->GetCurPokemons()->GetNameFont()->SetPosition(Vector3(350,555,0.f), true);
	m_Player->GetCurPokemons()->GetMaxHpFont()->SetRender(true);
	m_Player->GetCurPokemons()->GetMaxHpFont()->SetPosition(Vector3(460, 523, 0.f), true);
	m_Player->GetCurPokemons()->GetHpFont()->SetRender(true);
	m_Player->GetCurPokemons()->GetHpFont()->SetPosition(Vector3(410, 523, 0.f), true);

	m_Player->GetCurPokemons()->GetLevelFont()->SetRender(true);
	m_Player->GetCurPokemons()->GetLevelFont()->SetPosition(Vector3(480, 555, 0.f), true);

	m_Npc->GetCurPokemons()->GetNameFont()->SetRender(true);
	m_Npc->GetCurPokemons()->GetNameFont()->SetPosition(Vector3(40, 705, 0.f), true);

	m_Npc->GetCurPokemons()->GetLevelFont()->SetRender(true);
	m_Npc->GetCurPokemons()->GetLevelFont()->SetPosition(Vector3(180, 705, 0.f), true);

}
vector<Npc*> BattleManager::GetNpcs()
{
	return m_vecNpcs;
}
void BattleManager::NpcClear()
{
	m_vecNpcs.clear();
}
void BattleManager::UpdateHpBar()
{
	switch (m_eCir)
	{

	case BATTLE_CIR::P_PHASE:
	{
		if (1==bUpdateHpBar)
		{
			CSkill* pSkill = (CSkill*)playerbehavior.wParam;
			m_iTempValue = m_Npc->GetCurPokemons()->GetHp()-pSkill->GetDamage();
			if (m_iTempValue <= 0) { m_iTempValue = 0; bDeadCheck = true; DeadSize = m_Npc->GetCurPokemons()->GetAnimationSize(); }
			bUpdateHpBar = 2;
		}
		else if (2 == bUpdateHpBar) {
			int i=m_Npc->GetCurPokemons()->GetHp();
			i -= 1;
			float percent =(float) ((float)i / (float)m_Npc->GetCurPokemons()->GetMaxHp());
			if (0.2f < percent && percent <= 0.5f) {
			
				OpponentHpPoint->SetColor(Color(1, 1, 0, 1));

			}
			else if (percent <= 0.2f)
				OpponentHpPoint->SetColor(Color(1, 0, 0, 1));
			OpponentHpPoint->UpdateProgressBar(percent);
			m_Npc->GetCurPokemons()->SetHp(i);
			if (i == m_iTempValue)
				bUpdateHpBar = 3;
		}
	}
		break;
	case BATTLE_CIR::N_PHASE:
	{
		if (1 == bUpdateHpBar)
		{
			CSkill* pSkill = (CSkill*)npcbehavior.wParam;
			m_iTempValue = m_Player->GetCurPokemons()->GetHp() - pSkill->GetDamage();
			if (m_iTempValue <= 0) { m_iTempValue = 0; bDeadCheck = true; DeadSize = m_Player->GetCurPokemons()->GetAnimationSize();
			}
			bUpdateHpBar = 2;
		}
		else if (2 == bUpdateHpBar) {
			int i = m_Player->GetCurPokemons()->GetHp();
			i -= 1;
			float percent = (float)((float)i / (float)m_Player->GetCurPokemons()->GetMaxHp());
			if (0.2f < percent && percent <= 0.5f) {
			
				OurHpPoint->SetColor(Color(1, 1, 0, 1));

			}
			else if(percent<=0.2f)
				OurHpPoint->SetColor(Color(1, 0,0, 1));


			OurHpPoint->UpdateProgressBar(percent);
			m_Player->GetCurPokemons()->SetHp(i);
			m_Player->GetCurPokemons()->GetHpFont()->SetName(to_wstring(i));
			if (i == m_iTempValue)
				bUpdateHpBar = 3;
		}
	}
		break;

	default:
		break;

	}
}
void BattleManager::UpdateHpBar(UINT _healValue)
{
	switch (m_eCir)
	{

	case BATTLE_CIR::P_PHASE:
	{
		if (1 == bUpdateHpBar)
		{
			m_iTempValue = _healValue;
			if (m_iTempValue <= 0) { m_iTempValue = 0; bDeadCheck = true; DeadSize = m_Npc->GetCurPokemons()->GetAnimationSize(); }
			bUpdateHpBar = 2;
		}
		else if (2 == bUpdateHpBar) {
			
			HealHp += 1;
			float k= HealHp + m_Player->GetCurPokemons()->GetHp();
			float percent = (float)((float)(HealHp +HealValue) / (float)m_Player->GetCurPokemons()->GetMaxHp());
			if (0.2f < percent && percent <= 0.5f) {

				OurHpPoint->SetColor(Color(1, 1, 0, 1));

			}
			else if (percent <= 0.2f)
				OurHpPoint->SetColor(Color(1, 0, 0, 1));
			else
				OurHpPoint->SetColor(Color(0,1,0,1));
			OurHpPoint->UpdateProgressBar(percent);
			m_Player->GetCurPokemons()->SetHp(HealHp + HealValue);
			m_Player->GetCurPokemons()->GetHpFont()->SetName(to_wstring(HealHp + HealValue));
			UINT value2 =m_Player->GetCurPokemons()->GetHp();
			UINT value3= m_Player->GetCurPokemons()->GetMaxHp();
			if (value2 == value3)
			{
				bUpdateHpBar = 3;
				return;
			}

			if (HealHp == m_iTempValue)
				bUpdateHpBar = 3;
		}
	}
	break;


	default:
		break;

	}

}
BattleManager::BattleManager()
{
}

BattleManager::~BattleManager()
{
	SAFE_DELETE(BattlePhase);
	SAFE_DELETE(FightSelector);
	SAFE_DELETE(CancelSelector);
	SAFE_DELETE(MediumSelector);
	SAFE_DELETE(SmallSelector);
	SAFE_DELETE(OurHpBar);
	SAFE_DELETE(OpponentHpBar);
	SAFE_DELETE(OurHpPoint);
	SAFE_DELETE(OpponentHpPoint);
	SAFE_DELETE(BackGround);
	SAFE_DELETE(BattleItemBar);
	for (size_t i = 0; i < ourvecPokemon.size(); ++i)
		SAFE_DELETE(ourvecPokemon[i]);
	SAFE_DELETE(BackButton);
	SAFE_DELETE(BattleChangeButton);
	SAFE_DELETE(ChangeOrNotButton);
	for (size_t i = 0; i < m_vecNpcs.size(); ++i)
		SAFE_DELETE(m_vecNpcs[i]);
	SAFE_DELETE(ItemSelector);
	for (int i = 0; i < 4; ++i)
		SAFE_DELETE(m_vecItemSelect[i]);
	SAFE_DELETE(PrevButton);
	SAFE_DELETE(NextButton);
	for (size_t i = 0; i < DeleteItem.size(); ++i)
		SAFE_DELETE(DeleteItem[i]);
	m_vecBallItem.clear();
	m_vecHealItem.clear();
}

void BattleManager::SelectorUpdate()
{
	switch (m_Player->GetSelectPhase())
	{
	case SELECT_PHASE::COMPREHENSIVE:
		
	{
		CancelSelector->SetRender(false);
		if (m_Player->GetSelect() == 1) {
			FightSelector->SetRender(true);
		}
		else {
			FightSelector->SetRender(false);
		}
		if (m_Player->GetSelect() == 2|| m_Player->GetSelect() == 3|| m_Player->GetSelect() == 4) {
			SmallSelector->SetRender(true);
			if(m_Player->GetSelect() == 2)
				SmallSelector->GetTex()->SetPosition(Vector3(80, 55, 1.0f)); //80 55 -> 256 45-> 432 55
			else if(m_Player->GetSelect() == 3)
				SmallSelector->GetTex()->SetPosition(Vector3(256, 45, 1.0f));
			else 
				SmallSelector->GetTex()->SetPosition(Vector3(432, 55, 1.0f));
		}
		else {
			SmallSelector->SetRender(false);
		}
	}
		break;

	case SELECT_PHASE::SKILL:
		if (m_Player->GetSelect() == 5) {
			CancelSelector->SetRender(true);
			MediumSelector->SetRender(false);
		}
		else {
			CancelSelector->SetRender(false);
			if (m_Player->GetSelect() == 0) {
				MediumSelector->SetRender(false);
			}
			else MediumSelector->SetRender(true);
			switch (m_Player->GetSelect())
			{
			case 1:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
				break;
			case 2:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth *0.75f, 290, 1.0f));
				break;
			case 3:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 165, 1.0f));
				break;
			case 4:
				MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth * 0.75f, 165, 1.0f));
				break;
			default:
				break;
			}
		}

		break;
	case SELECT_PHASE::CHANGEORNOT:
		if (!m_Player->GetSelect())
			CancelSelector->SetRender(false);
		else
			CancelSelector->SetRender(true);
		break;
	case SELECT_PHASE::ITEM:
	{
		BattleItemBar->Update();
		if (!m_Player->GetSelect()) {
			ItemSelector->SetRender(false);
		}
		else
		{
			if (m_Player->GetDetailItemSelect() == ITEM_SELECT::NONE) {
				ItemSelector->SetRender(true);
				switch (m_Player->GetSelect())
				{
				case 1:
					ItemSelector->GetTex()->SetPosition(Vector3(128, 295, 0.f)); ItemSelector->GetTex()->SetSize(Vector3(248, 130, 0.f));
					break;
				case 2:
					ItemSelector->GetTex()->SetPosition(Vector3(383, 295, 0.f)); ItemSelector->GetTex()->SetSize(Vector3(248, 130, 0.f));

					break;
				case 3:
					ItemSelector->GetTex()->SetPosition(Vector3(128, 150, 0.f)); ItemSelector->GetTex()->SetSize(Vector3(248, 130, 0.f));

					break;
				case 4:
					ItemSelector->GetTex()->SetPosition(Vector3(383, 295, 0.f)); ItemSelector->GetTex()->SetSize(Vector3(248, 130, 0.f));

					break;
				case 5:
					ItemSelector->GetTex()->SetPosition(Vector3(205, 37, 0.f)); ItemSelector->GetTex()->SetSize(Vector3(415, 66, 0.f));

					break;
				case 6:
					ItemSelector->GetTex()->SetPosition(Vector3(471, 37, 0.f)); ItemSelector->GetTex()->SetSize(Vector3(70, 66, 0.f));

					break;
				default:
					break;
				}
			}

		}


	}


		break;
	default:
		break;
	}
	FightSelector->Update();
	SmallSelector->Update();
	MediumSelector->Update();
	for (int i = 0; i < 4; ++i)
		m_vecItemSelect[i]->Update();


}

void BattleManager::DeadEffect()
{
	if (5 == DeadCount) { 
		m_Npc->FindPokemon();
		return;}
	switch (m_eCir)
	{
	case BATTLE_CIR::P_PHASE:
	{
		Vector3 vSize = DeadSize / 5;
		vSize = m_Npc->GetCurPokemons()->GetAnimationSize() - vSize;
	
		m_Npc->GetCurPokemons()->GetAnimRect()->SetSize(vSize);
	}
	break;
	case BATTLE_CIR::N_PHASE: {
		Vector3 vSize = DeadSize / 5;
		vSize = m_Player->GetCurPokemons()->GetAnimationSize() - vSize;
		m_Player->GetCurPokemons()->GetAnimRect()->SetSize(vSize);
		
	}
	break;
	}
	DeadCount += 1;
	if (5 == DeadCount) {
		switch (m_eCir)
		{
		case BATTLE_CIR::P_PHASE:
		{
		m_Npc->GetCurPokemons()->SetRender(false);
		}
		break;
		case BATTLE_CIR::N_PHASE: {
			m_Player->GetCurPokemons()->SetRender(false);

		}
		break;
		}
		
	
	}
}

void BattleManager::SetOurChangePokemon(const bool& _bChange)
{
	OurChangePokemon = _bChange;
	if (_bChange) {
		OurHpBar->SetRender(false);
		OurHpPoint->SetRender(false);
	}
}
void BattleManager::ChangeButtonRender(const bool& _bRender)
{
	ChangeOrNotButton->SetRender(_bRender);
}

void BattleManager::CancelSelectorRender(const bool& _bRender)
{
	CancelSelector->SetRender(_bRender);
}

void BattleManager::NPCCurDead()
{
	m_Npc->CurPokemonDead();
	OpponentHpBar->SetRender(false);
	OpponentHpPoint->SetRender(false);
	m_Npc->GetCurPokemons()->GetHpFont()->SetRender(false);
	m_Npc->GetCurPokemons()->GetMaxHpFont()->SetRender(false);
	m_Npc->GetCurPokemons()->GetLevelFont()->SetRender(false);

}

void BattleManager::DoBattlePhase()
{
	CancelSelector->Update();
	ChangeOrNotButton->Update();

	OpponentHpBar->Update();
	OpponentHpPoint->Update();
	OurHpBar->Update();
	OurHpPoint->Update();
	m_Player->GetCurPokemons()->GetNameFont()->Update();
	m_Player->GetCurPokemons()->GetHpFont()->Update();
	m_Player->GetCurPokemons()->GetMaxHpFont()->Update();
	m_Player->GetCurPokemons()->GetLevelFont()->Update();
	m_Npc->GetCurPokemons()->GetNameFont()->Update();

	m_Npc->GetCurPokemons()->GetLevelFont()->Update();
	switch (m_Player->GetSelectPhase())
	{
	case SELECT_PHASE::SKILL:
	{
		for (size_t i = 0; i < m_Player->GetCurPokemons()->GetSkills().size(); ++i) {
		
			m_Player->GetCurPokemons()->GetSkills()[i]->Update();
			
		}
		

	}
	break;

	default:
		break;
	}
	for (size_t i = 0; i < m_Npc->GetCurPokemons()->GetSkills().size(); ++i) {
		m_Npc->GetCurPokemons()->GetSkills()[i]->Update();
	}
	if (bPlayerBehavior) {

		if (!bSpeedCheck) {
			if (BATTLE_TYPE::SKILL == playerbehavior.eBattle) {
				if (m_Player->GetCurPokemons()->GetSpeed() >= m_Npc->GetCurPokemons()->GetSpeed()) {
					CSkill* pSkill = ((CSkill*)playerbehavior.wParam);

					pSkill->Cast();

					if (pSkill->GetAnim()) {
						pSkill->GetAnimRect()->GetAnimator()->SetPause(false);
						pSkill->GetAnimRect()->SetSize(Vector3(pSkill->GetAnimRect()->GetWidth(), pSkill->GetAnimRect()->GetHeight(), 0.f));
						pSkill->GetAnimRect()->SetPosition(m_Npc->GetCurPokemons()->GetAnimRect()->GetPosition());
					}

					ptr = playerbehavior.wParam;
					m_eCir = BATTLE_CIR::P_PHASE;

				}
				else {
					CSkill* pSkill = ((CSkill*)npcbehavior.wParam);
					pSkill->Cast();
					if (pSkill->GetAnim()) {
						pSkill->GetAnimRect()->SetPosition(m_Player->GetCurPokemons()->GetAnimRect()->GetPosition());
						pSkill->GetAnimRect()->GetAnimator()->SetPause(false);
					}
					ptr = npcbehavior.wParam;
					m_eCir = BATTLE_CIR::N_PHASE;
				}
				m_iPhase = 1;

				bSpeedCheck = true;
			}
			else if (BATTLE_TYPE::CHANGE == playerbehavior.eBattle)
			{
				m_iPhase = 1;
				m_eCir = BATTLE_CIR::P_PHASE;
				bSpeedCheck = true;
				m_iChangePokemon = (UINT) BATTLE_CIR::P_READY;
			}
			else if (BATTLE_TYPE::ITEM == playerbehavior.eBattle) {
				//아이템처리
				m_iPhase = 1;
				m_eCir = BATTLE_CIR::P_PHASE;
				bSpeedCheck = true;
				

				
			}
		
		}
		else {
			if (bSpeedCheck) {
				if (1 == m_iPhase) {
					if (BATTLE_CIR::P_PHASE == m_eCir) {
						if (BATTLE_TYPE::SKILL == playerbehavior.eBattle) {
							CSkill* pSkill = (CSkill*)ptr;
							if (!(pSkill->GetCasting()))
							{
								if (!bHitted) {
									HitEffect();
								}
							}
							UpdateHpBar();
							if (!bHitted || 3 != bUpdateHpBar)
								return;
						
						}
						else if (BATTLE_TYPE::CHANGE == playerbehavior.eBattle)
						{
							if (5 != m_iChangePokemon)
								m_Player->Roar_BattleCir();

							if (5 != m_iChangePokemon)
								return;

						}
						else if (BATTLE_TYPE::ITEM == playerbehavior.eBattle) {
							Item* item = (Item*)playerbehavior.wParam;
							if (nullptr == m_Npc) {
								//몬스터볼 처리

							}
							else {
								//
								int Code = (float)(item->GetValue()) / 100.f;
								int Value=0;
								if (!bCodeCheck)
								{
									bUpdateHpBar = 1;
									bCodeCheck = 1;
									HealValue = m_Player->GetCurPokemons()->GetHp();
								}
								if (99 == Code) {
									//풀회복약 ,회복약
									Value = m_Player->GetCurPokemons()->GetMaxHp() - m_Player->GetCurPokemons()->GetHp();
									
								}
		
								else {
									Value = item->GetValue();
									
								}
							

								
								UpdateHpBar(Value);
								if (3 != bUpdateHpBar)
									return;

								
								
							}



						}
					}
					else if (BATTLE_CIR::N_PHASE == m_eCir) {
						if (BATTLE_TYPE::SKILL == npcbehavior.eBattle) {
							CSkill* pSkill = (CSkill*)ptr;
							if (!(pSkill->GetCasting()))
							{
								if (!bHitted) {
									HitEffect();
								}
							}
							UpdateHpBar();
							if (!bHitted || 3 != bUpdateHpBar)
								return;
						}
					}
					
					if (bDeadCheck)
					{
						DeadEffect();


						if (5 == DeadCount) {
							m_iPhase = 4;
							m_Npc->FindPokemon();
							if (!m_Npc->GetDefeat())
							{
							
							switch (m_eCir)
							{
							case BATTLE_CIR::P_PHASE:
							{
								m_eCir = BATTLE_CIR::N_DEAD;

								ChangeOrNotButton->SetRender(true);
								m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
								bUpdateHpBar = 0;
								bHitted = false;
								m_iChangePokemon = 0;
								DeadCount = 0;
								bCodeCheck = false;
								HealValue = 0;
								HealHp = 0;
							}
							break;
							case BATTLE_CIR::N_PHASE: {
								m_eCir = BATTLE_CIR::P_DEAD;
								ChangeOrNotButton->SetRender(true);
								m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
								bUpdateHpBar = 0;
								bHitted = false;
								m_iChangePokemon = 0;
								DeadCount = 0;		bCodeCheck = false;
								HealValue = 0;
								HealHp = 0;
							}
													break;
							}
							}
							else {
								switch (m_eCir)
								{
								case BATTLE_CIR::P_PHASE:
								{
									m_eCir = BATTLE_CIR::N_DEAD;

									ChangeOrNotButton->SetRender(false);
									m_Npc->SetDefeatEffect(1);
								//	m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
									bUpdateHpBar = 0;
									bHitted = false;
									m_iChangePokemon = 0;
									DeadCount = 0;		bCodeCheck = false;
									HealValue = 0;
									HealHp = 0;
								}
								break;
								case BATTLE_CIR::N_PHASE: {
									m_eCir = BATTLE_CIR::P_DEAD;
									ChangeOrNotButton->SetRender(true);
									m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
									bUpdateHpBar = 0;
									bHitted = false;
									m_iChangePokemon = 0;
									DeadCount = 0;		bCodeCheck = false;
									HealValue = 0;
									HealHp = 0;
								}
														break;
								}

							}
						}
						return;
						
					}
					
					switch (m_eCir)
					{
					case BATTLE_CIR::P_PHASE:
					{
						if (BATTLE_TYPE::SKILL == playerbehavior.eBattle) {
							CSkill* pSkill = ((CSkill*)playerbehavior.wParam);


							pSkill = ((CSkill*)npcbehavior.wParam);
							pSkill->Cast();
						
							if (pSkill->GetAnim()) {
								pSkill->GetAnimRect()->SetPosition(m_Npc->GetCurPokemons()->GetAnimRect()->GetPosition());
								pSkill->GetAnimRect()->GetAnimator()->SetPause(false);
							}
						}
						else if (BATTLE_TYPE::SKILL == npcbehavior.eBattle) {

						}
					
					ptr = npcbehavior.wParam;
					m_eCir = BATTLE_CIR::N_PHASE; 
					bHitted = false;
					m_iChangePokemon = 0;
					bUpdateHpBar = 0;		bCodeCheck = false;
					HealValue = 0;
					HealHp = 0;
					}
						break;
					case BATTLE_CIR::N_PHASE: {
						CSkill* pSkill = ((CSkill*)playerbehavior.wParam);
						pSkill->Cast();
					
						if (pSkill->GetAnim()) {
							pSkill->GetAnimRect()->SetPosition(m_Player->GetCurPokemons()->GetAnimRect()->GetPosition());
							pSkill->GetAnimRect()->GetAnimator()->SetPause(false);
						}
						ptr = playerbehavior.wParam;
						m_eCir = BATTLE_CIR::P_PHASE;
						bHitted = false;
						bUpdateHpBar = 0;
					}
						break;
				
					}
					m_iPhase += 1;
				}
				else if (2 == m_iPhase) {
					CSkill* pSkill = (CSkill*)ptr;
					if (!(pSkill->GetCasting()))
					{
						if (!bHitted)
						HitEffect();
					}
					UpdateHpBar();
					if (!bHitted || 3 != bUpdateHpBar)
						return;
					if (bDeadCheck)
					{
						DeadEffect();


						if (5 == DeadCount) {
							m_iPhase = 4;
							m_Npc->FindPokemon();
							if (!m_Npc->GetDefeat())
							{

								switch (m_eCir)
								{
								case BATTLE_CIR::P_PHASE:
								{
									m_eCir = BATTLE_CIR::N_DEAD;

									ChangeOrNotButton->SetRender(true);
									m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
									bUpdateHpBar = 0;
									bHitted = false;
									m_iChangePokemon = 0;
									DeadCount = 0;
								}
								break;
								case BATTLE_CIR::N_PHASE: {
									m_eCir = BATTLE_CIR::P_DEAD;
									ChangeOrNotButton->SetRender(true);
									m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
									bUpdateHpBar = 0;
									bHitted = false;
									m_iChangePokemon = 0;
									DeadCount = 0;
								}
														break;
								}
							}
							else {
								switch (m_eCir)
								{
								case BATTLE_CIR::P_PHASE:
								{
									m_eCir = BATTLE_CIR::N_DEAD;

									ChangeOrNotButton->SetRender(false);
									m_Npc->SetDefeatEffect(true);
									//	m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
									bUpdateHpBar = 0;
									bHitted = false;
									m_iChangePokemon = 0;
									DeadCount = 0;
								}
								break;
								case BATTLE_CIR::N_PHASE: {
									m_eCir = BATTLE_CIR::P_DEAD;
									ChangeOrNotButton->SetRender(true);
									m_Player->SetSelectPhase(SELECT_PHASE::CHANGEORNOT);
									bUpdateHpBar = 0;
									bHitted = false;
									m_iChangePokemon = 0;
									DeadCount = 0;
								}
														break;
								}

							}
						}
						return;

					}
					m_eCir = BATTLE_CIR::BATTLE_END;
					m_iPhase += 1;
					bUpdateHpBar = 0;
				}

				else if(3==m_iPhase){
					m_iPhase = 0;
					m_eCir = BATTLE_CIR::ALL_READY;
					playerbehavior = {};
					npcbehavior = {};
					bPlayerBehavior = false;
					m_Player->SetSelect(0);
					m_Player->SetSelectPhase(SELECT_PHASE::COMPREHENSIVE);
					BattlePhase->GetTex()->GetAnimator()->SetCurrentAnimClip(L"BattlePhase");
					MediumSelector->SetRender(false);
					bSpeedCheck = false;
					bHitted = false;
					m_Player->Setbehavior(false);
				}
				else {
					switch (m_eCir)
					{
					case BATTLE_CIR::P_DEAD:
					{
						m_Player->SetSelectPhase(SELECT_PHASE::POKEMON);
						RenderPokemonSelect();
						BackButton->SetRender(false);
						bDeadCheck = false;
					}
						break;
					case BATTLE_CIR::N_DEAD:
					{
						m_Npc->SwapPokemon();
						if (!m_Npc->GetDefeat()) {
							m_Npc->Roar();
						}
						else {

						}
					}
						break;
		
					}
				}
			}
		}
		
	}
	BackButton->Update();
	for (size_t i = 0; i < ourvecPokemon.size(); ++i)
		ourvecPokemon[i]->Update();
	BackGround->Update();
	BattleChangeButton->Update();
	
}

void BattleManager::PhaseIn()
{
	BattlePhase->GetTex()->GetAnimator()->SetCurrentAnimClip(L"BattlePhaseIn");
	FightSelector->SetRender(false);
	SmallSelector->SetRender(false);
}

void BattleManager::PhaseOut()
{
	BattlePhase->GetTex()->GetAnimator()->SetCurrentAnimClip(L"BattlePhase");
}

void BattleManager::AllReady()
{
	OurHpBar->SetRender(true);
	OpponentHpBar->SetRender(true);

	OurHpPoint->SetRender(true);
	OpponentHpPoint->SetRender(true);
}

void BattleManager::HitEffect()
{
	
	switch (m_eCir)
	{
	case BATTLE_CIR::P_PHASE:
	{
		if (!bHitEffectCheck)
		{
			start = chrono::steady_clock::now();
			bHitEffectCheck = true;
		}
		else {
			if (TimeCheck(0.125f, start)) {
				bHitEffectCheck = false;
				m_iHitEffectCount += 1;
				if (m_iHitEffectCount % 2 == 0) {
					m_Npc->GetCurPokemons()->SetSize(
						Vector3(m_Npc->GetCurPokemons()->GetAnimRect()->GetWidth(), m_Npc->GetCurPokemons()->GetAnimRect()->GetHeight(), 0.f)

					);
					
				}
				else {
					m_Npc->GetCurPokemons()->SetSize(
						Vector3(0.f, 0.f, 0.f)

					);
				}
				if (m_iHitEffectCount == 6) {
					bHitted = true;
					m_iHitEffectCount = 0;
					bUpdateHpBar = 1;

			}
			}

		}
	}
		break;
	case BATTLE_CIR::N_PHASE:
	{
		if (!bHitEffectCheck)
		{
			start = chrono::steady_clock::now();
			bHitEffectCheck = true;
		}
		else {
			if (TimeCheck(0.125f, start)) {
				bHitEffectCheck = false;
				m_iHitEffectCount += 1;
				if (m_iHitEffectCount % 2 == 0) {
					m_Player->GetCurPokemons()->SetSize(
						Vector3(m_Player->GetCurPokemons()->GetAnimRect()->GetWidth(), m_Player->GetCurPokemons()->GetAnimRect()->GetHeight(), 0.f)

					);

				}
				else {
					m_Player->GetCurPokemons()->SetSize(
						Vector3(0.f, 0.f, 0.f)

					);
				}
				if (m_iHitEffectCount == 6) {
					bHitted = true;
					m_iHitEffectCount = 0;
					bUpdateHpBar = 1;
				}
			}

		}
	}
		break;

	}


}

void BattleManager::BattleStart(Player* _player, Npc* _npc)
{
	Vector3 vPos = _player->GetPos();
	vPos = _npc->GetPos();
	_player->SetPrevPos(_player->GetPos());
	_npc->SetPrevPos(_npc->GetPos());
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_Npc);
	m_Player = new Player(*_player);

	m_Player->SetBattleMode();
	ItemSelectInit();
	for (size_t j = 0; j < m_Player->GetPokemons().size(); ++j)
		for (size_t i = 0; i < m_Player->GetPokemons()[j]->GetSkills().size(); ++i) {
			if (i == 0) {
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetNameFont()->SetPosition(Vector3(90,310,0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetCurPPFont()->SetPosition(Vector3(150, 276, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetMaxPPFont()->SetPosition(Vector3(195, 276, 0));

			}
			if (i == 1) {
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth * 0.75f, 290, 1.0f));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetNameFont()->SetPosition(Vector3(368, 310, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetCurPPFont()->SetPosition(Vector3(405, 276, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetMaxPPFont()->SetPosition(Vector3(455, 276, 0));
			}
			if (i == 2) {
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth / 4, 165, 1.0f));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetNameFont()->SetPosition(Vector3(90, 190, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetCurPPFont()->SetPosition(Vector3(150, 156, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetMaxPPFont()->SetPosition(Vector3(195, 156, 0));

			}
			if (i == 3) {
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetPosition(Vector3(WinMaxWidth * 0.75f, 165, 1.0f));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetNameFont()->SetPosition(Vector3(368, 190, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetCurPPFont()->SetPosition(Vector3(405, 156, 0));
				m_Player->GetPokemons()[j]->GetSkills()[i]->GetMaxPPFont()->SetPosition(Vector3(455, 156, 0));
			}
			m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->SetSize(Vector3((float)m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->GetWidth(), (float)m_Player->GetPokemons()[j]->GetSkills()[i]->GetTypeTex()->GetHeight(), (float)0.0f));

		}
	m_Npc = new Npc(*_npc);
	m_Npc->SetBattleMode();
	vector<Npc*>::iterator iter = m_vecNpcs.begin();
	bool bFind = false;
	for (size_t i = 0; i < m_vecNpcs.size(); ++i) {
		if (_npc != m_vecNpcs[i]) {
			vPos = m_vecNpcs[i]->GetPos();
			m_vecNpcs[i]->SetPrevPos(m_vecNpcs[i]->GetPos());
			Npc* npc = new Npc(*m_vecNpcs[i]);
			m_vecNpcs[i] = npc;
		}
		else {
			bFind = true;
		}
		if (!bFind)iter++;

	}
	m_vecNpcs.erase(iter);
}


void BattleManager::BattleEnd(Player* _player, Npc* _npc)
{

	int a = 0;
	m_Player = new Player(*_player);
	m_Player->Init();
	m_Player->SetIdleMode();

	m_Npc = new Npc(*_npc);
	m_Npc->Init();
	m_Npc->SetIdleMode();


	m_vecBallItem.clear();
	m_vecHealItem.clear();


}
void BattleManager::Render()
{

	BackGround->Render();
	BackButton->Render();
	if (m_eCir == BATTLE_CIR::ALL_READY) {
		if (!bPlayerBehavior)
		{


			switch (m_Player->GetSelectPhase())
			{
			case SELECT_PHASE::COMPREHENSIVE:
			case SELECT_PHASE::SKILL:
		
				BattlePhase->Render();
				FightSelector->Render();

				SmallSelector->Render();
				MediumSelector->Render();
				

			if(m_Player->GetSelectPhase()==SELECT_PHASE::SKILL)
			{
				for (size_t i = 0; i < m_Player->GetCurPokemons()->GetSkills().size(); ++i) {
					m_Player->GetCurPokemons()->GetSkills()[i]->Render();
				}
			}
			break;
			case SELECT_PHASE::ITEM:
			{
				BattleItemBar->Render();
			}
			break;
		
			default:
				break;
			}
		}
		
		
	}
	switch (m_Player->GetSelectPhase())
	{
	case SELECT_PHASE::POKEMON:
	{
		for (size_t i = 0; i < ourvecPokemon.size(); ++i) {
			ourvecPokemon[i]->Render();
		}
		

	}
	break;
	default:
		break;
	}


	OpponentHpBar->Render();
	OurHpBar->Render();
	OpponentHpPoint->Render();
	OurHpPoint->Render();
	BattleChangeButton->Render();
	ChangeOrNotButton->Render();
	CancelSelector->Render();
	ItemSelector->Render();
	m_Player->GetCurPokemons()->GetNameFont()->Render();
	m_Player->GetCurPokemons()->GetHpFont()->Render();
	m_Player->GetCurPokemons()->GetMaxHpFont()->Render();
	m_Player->GetCurPokemons()->GetLevelFont()->Render();
	m_Npc->GetCurPokemons()->GetNameFont()->Render();
	m_Npc->GetCurPokemons()->GetLevelFont()->Render();

	for (int i = 0; i < 4; ++i)
		m_vecItemSelect[i]->Render();
	for (size_t i = 0; i < m_vecHealItem.size(); ++i)
		m_vecHealItem[i]->Render();

	NextButton->Render();
	PrevButton->Render();
	for (size_t i = 0; i < m_Player->GetCurPokemons()->GetSkills().size(); ++i) {
		m_Player->GetCurPokemons()->GetSkills()[i]->SkillRender();
	}
	for (size_t i = 0; i < m_Npc->GetCurPokemons()->GetSkills().size(); ++i) {
		m_Npc->GetCurPokemons()->GetSkills()[i]->SkillRender();
	}

}



void BattleManager::Init()
{
	{
		BattlePhase = new UI();
		BattlePhase->Init(L"Battle/BattleUI/BattlePhase", 1, 1, 2);
		Animator* animator = new Animator;
		AnimationClip* animation = new AnimationClip(L"BattlePhase", BattlePhase->GetTexture(), 1, Vector2(0.f, 0.f),
			Vector2(BattlePhase->GetTexture()->GetWidth(), BattlePhase->GetTexture()->GetHeight() / 2.f), 1.0f / 15.0f);
		animator->AddAnimClip(animation);
		animation = new AnimationClip(L"BattlePhaseIn", BattlePhase->GetTexture(), 1, Vector2(0.f, BattlePhase->GetTexture()->GetHeight() / 2.f),
			Vector2(BattlePhase->GetTexture()->GetWidth(), BattlePhase->GetTexture()->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(animation);
		animator->SetCurrentAnimClip(L"BattlePhase");//128 64
		BattlePhase->GetTex()->SetAnimation(animator);
		BattlePhase->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2 - 192, 1.0f));
		BattlePhase->GetTex()->SetSize(Vector3((float)BattlePhase->GetTex()->GetWidth(), (float)BattlePhase->GetTex()->GetHeight(), (float)0.0f));
		BattlePhase->DeleteTexture();
	
	FightSelector = new TextureObject;
	FightSelector->Init(L"Pokemon/Battle/BattleUI/FightSelector.png");
	FightSelector->GetTex()->SetWidth(434); FightSelector->GetTex()->SetHeight(180);
	FightSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, 230, 1.0f)); FightSelector->GetTex()->SetSize(Vector3(434, 180, 0));
	CancelSelector = new TextureObject;
	CancelSelector->Init(L"Pokemon/Battle/BattleUI/CancelSelector.png");
	CancelSelector->GetTex()->SetWidth(472); CancelSelector->GetTex()->SetHeight(80);
	CancelSelector->GetTex()->SetPosition(Vector3(256, 40, 1.0f));
	CancelSelector->GetTex()->SetSize(Vector3(472, 80, 0));
	CancelSelector->SetRender(false);
	MediumSelector = new TextureObject;
	MediumSelector->Init(L"Pokemon/Battle/BattleUI/MediumSelector.png");
	MediumSelector->GetTex()->SetWidth(248); MediumSelector->GetTex()->SetHeight(110);
	MediumSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
	MediumSelector->GetTex()->SetSize(Vector3(248, 110, 0));
	MediumSelector->SetRender(false);

	ItemSelector = new TextureObject;
	ItemSelector->Init(L"Pokemon/Battle/BattleUI/MediumSelector.png");
	ItemSelector->GetTex()->SetWidth(248); ItemSelector->GetTex()->SetHeight(110);
	ItemSelector->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 290, 1.0f));
	ItemSelector->GetTex()->SetSize(Vector3(248, 110, 0));
	ItemSelector->SetRender(false);


	SmallSelector = new TextureObject;
	SmallSelector->Init(L"Pokemon/Battle/BattleUI/SmallSelector.png");
	SmallSelector->GetTex()->SetWidth(78); SmallSelector->GetTex()->SetHeight(44);
	SmallSelector->GetTex()->SetPosition(Vector3(80, 55, 1.0f)); //80 55 -> 256 45-> 432 55
	SmallSelector->GetTex()->SetSize(Vector3(78 * 2, 44 * 2, 0));
	SmallSelector->SetRender(false);
	OurHpBar = new TextureObject;
	OurHpBar->Init(L"Pokemon/Battle/BattleUI/OurHpBAR.png");
	OurHpBar->GetTex()->SetWidth(266); OurHpBar->GetTex()->SetHeight(90);
	OurHpBar->GetTex()->SetPosition(Vector3(390, 543, 1.0f));
	OurHpBar->GetTex()->SetSize(Vector3(266, 90, 0));
	OurHpBar->SetRender(false);
	OpponentHpBar = new TextureObject;
	OpponentHpBar->Init(L"Pokemon/Battle/BattleUI/EnemyHpBar.png");
	OpponentHpBar->GetTex()->SetWidth(252); OpponentHpBar->GetTex()->SetHeight(78);
	OpponentHpBar->GetTex()->SetPosition(Vector3(126, 700, 1.0f));
	OpponentHpBar->GetTex()->SetSize(Vector3(252, 78, 0));
	OpponentHpBar->SetRender(false);




	OurHpPoint = new ProgressBar(Vector3(405, 535, 1.0f), Vector3(96, 5, 0), 0.f, Color(0, 1, 0, 1), GI::LEFT_TO_RIGHT);
	OurHpPoint->SetRender(false);
	OpponentHpPoint = new ProgressBar(Vector3(102, 683, 1.0f), Vector3(96, 5, 0), 0.f, Color(0, 1, 0, 1), GI::LEFT_TO_RIGHT);
	OpponentHpPoint->SetRender(false);



	BackGround = new TextureObject;
	BackGround->Init(L"Pokemon/Battle/Battle_Back.png");
	BackGround->GetTex()->SetWidth(512); BackGround->GetTex()->SetHeight(384);
	BackGround->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2 - 192, 1.0f));
	BackGround->GetTex()->SetSize(Vector3(512, 384, 0));
	BackGround->SetRender(false);

	BackButton = new UI;
	BackButton->Init(L"Battle/BattleUI/BattleBackButton02", 4, 4, 1);
	animator = new Animator;
	animation = new AnimationClip(L"CurButton", BackButton->GetTexture(), 1, Vector2(0.f, 0.f),
		Vector2(BackButton->GetTex()->GetWidth(), BackButton->GetTex()->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(animation);

	animation = new AnimationClip(L"SelectButton", BackButton->GetTexture(), 1, Vector2(BackButton->GetTex()->GetWidth(), 0.f),
		Vector2(BackButton->GetTex()->GetWidth() * 2, BackButton->GetTex()->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Nope", BackButton->GetTexture(), 1, Vector2(BackButton->GetTexture()->GetWidth() * 3, 0),
		Vector2(BackButton->GetTexture()->GetWidth() * 4, BackButton->GetTexture()->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"CurButton");
	BackButton->DeleteTexture();
	BackButton->GetTex()->SetAnimation(animator);
	BackButton->GetTex()->SetPosition(Vector3(450, 40, 1.0f));
	BackButton->GetTex()->SetSize(Vector3(BackButton->GetTex()->GetWidth(), BackButton->GetTex()->GetHeight(), 0));
	BackButton->SetRender(false);



	BattleItemBar = new TextureObject;
	BattleItemBar->Init(L"Pokemon/Battle/Battle_ItemBar.png");


	BattleItemBar->GetTex()->SetWidth(512); BattleItemBar->GetTex()->SetHeight(384);
	BattleItemBar->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight / 2 - 192, 1.0f));
	BattleItemBar->GetTex()->SetSize(Vector3(512, 384, 0));
	BattleItemBar->SetRender(false);
	}
	for (int i = 0; i < MAXPOKEMONCOUNT; ++i) {
		UI* pPokemon = new UI;

		pPokemon->Init(L"Battle/BattleUI/BattlePokemon", 4, 4, 1);
		Animator* animator = new Animator;
		AnimationClip* animation = new AnimationClip(L"CurPokemon", pPokemon->GetTexture(), 1, Vector2(0.f, 0.f),
			Vector2(pPokemon->GetTex()->GetWidth(), pPokemon->GetTex()->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(animation);
		animation = new AnimationClip(L"SelectPokemon", pPokemon->GetTexture(), 1, Vector2(pPokemon->GetTex()->GetWidth(), 0.f),
			Vector2(pPokemon->GetTex()->GetWidth()*2, pPokemon->GetTex()->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(animation);
		animation = new AnimationClip(L"Nope", pPokemon->GetTexture(), 1, Vector2(pPokemon->GetTex()->GetWidth() * 3, 0),
			Vector2(pPokemon->GetTex()->GetWidth() * 4, pPokemon->GetTex()->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(animation);
		animator->SetCurrentAnimClip(L"CurPokemon");//128 64
		pPokemon->GetTex()->SetAnimation(animator);
		if( i==0)
			pPokemon->GetTex()->SetPosition(Vector3(WinMaxWidth / 4,330, 1.0f));
		else if (i==1)
			pPokemon->GetTex()->SetPosition(Vector3(WinMaxWidth*0.75, 330, 1.0f));
		else if (i == 2)
			pPokemon->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 240, 1.0f));
		else if (i == 3)
			pPokemon->GetTex()->SetPosition(Vector3(WinMaxWidth * 0.75, 240, 1.0f));
		else if (i == 4)
			pPokemon->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 150, 1.0f));
		else if (i == 5)
			pPokemon->GetTex()->SetPosition(Vector3(WinMaxWidth * 0.75, 150, 1.0f));
		pPokemon->GetTex()->SetSize(Vector3((float)pPokemon->GetTex()->GetWidth(), (float)pPokemon->GetTex()->GetHeight(), (float)0.0f));
		pPokemon->DeleteTexture();
		pPokemon->SetRender(false);

		ourvecPokemon.push_back(pPokemon);
	}

	{
		BattleChangeButton = new UI;
		BattleChangeButton->Init(L"Battle/BattleUI/BattleChangeButton", 4, 4, 1);
		Animator* animator = new Animator;
		AnimationClip* animation = new AnimationClip(L"CurButton", BattleChangeButton->GetTexture(), 1, Vector2(0.f, 0.f),
			Vector2(BattleChangeButton->GetTex()->GetWidth(), BattleChangeButton->GetTex()->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(animation);

		animation = new AnimationClip(L"SelectButton", BattleChangeButton->GetTexture(), 1, Vector2(BattleChangeButton->GetTex()->GetWidth(), 0.f),
			Vector2(BattleChangeButton->GetTex()->GetWidth() * 2, BattleChangeButton->GetTex()->GetHeight()), 1.0f / 15.0f);
		animator->AddAnimClip(animation);
		animator->AddAnimClip(animation);
		animator->SetCurrentAnimClip(L"CurButton");
		BattleChangeButton->DeleteTexture();
		BattleChangeButton->GetTex()->SetAnimation(animator);
		BattleChangeButton->GetTex()->SetPosition(Vector3(WinMaxWidth/2, 225, 1.0f));
		BattleChangeButton->GetTex()->SetSize(Vector3(BattleChangeButton->GetTex()->GetWidth(), BattleChangeButton->GetTex()->GetHeight(), 0));
		BattleChangeButton->SetRender(false);

	}
	{

	ChangeOrNotButton = new TextureObject;
	ChangeOrNotButton->Init(L"Pokemon/Battle/BattleUI/ChangeOrNot.png");
	ChangeOrNotButton->GetTex()->SetWidth(512); ChangeOrNotButton->GetTex()->SetHeight(256);
	ChangeOrNotButton->GetTex()->SetPosition(Vector3(WinMaxWidth / 2, WinMaxHeight/4, 1.0f)); ChangeOrNotButton->GetTex()->SetSize(Vector3(512, 256, 0));
	ChangeOrNotButton->SetRender(false);
	}

	PrevButton = new UI;
	PrevButton->Init(L"Battle/BattleUI/BattleNextPrev", 4, 4, 2);
	Animator* animator = new Animator;
	AnimationClip* animation = new AnimationClip(L"CurButton", PrevButton->GetTexture(), 1, Vector2(0.f, 0.f),
		Vector2(PrevButton->GetTex()->GetWidth(), PrevButton->GetTex()->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(animation);

	animation = new AnimationClip(L"SelectButton", PrevButton->GetTexture(), 1, Vector2(PrevButton->GetTex()->GetWidth(), 0.f),
		Vector2(PrevButton->GetTex()->GetWidth() * 2, PrevButton->GetTex()->GetHeight()), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Nope", PrevButton->GetTexture(), 1, Vector2(PrevButton->GetTex()->GetWidth() * 3, 0.f),
		Vector2(PrevButton->GetTex()->GetWidth(), PrevButton->GetTex()->GetHeight() ), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"CurButton");
	PrevButton->DeleteTexture();
	PrevButton->GetTex()->SetAnimation(animator);
	PrevButton->GetTex()->SetPosition(Vector3(175, 40, 1.0f));

	PrevButton->GetTex()->SetSize(Vector3(PrevButton->GetTex()->GetWidth(), PrevButton->GetTex()->GetHeight(), 0));
	PrevButton->SetRender(false);

	NextButton = new UI;
	NextButton->Init(L"Battle/BattleUI/BattleNextPrev", 4, 4, 2);
	 animator = new Animator;
	 animation = new AnimationClip(L"CurButton", NextButton->GetTexture(), 1, Vector2(0.f, NextButton->GetTex()->GetHeight()),
		Vector2(NextButton->GetTex()->GetWidth(), NextButton->GetTex()->GetHeight()*2), 1.0f / 15.0f);
	animator->AddAnimClip(animation);

	animation = new AnimationClip(L"SelectButton", NextButton->GetTexture(), 1, Vector2(NextButton->GetTex()->GetWidth(), NextButton->GetTex()->GetHeight()),
		Vector2(NextButton->GetTex()->GetWidth() * 2, NextButton->GetTex()->GetHeight()*2), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animation = new AnimationClip(L"Nope", NextButton->GetTexture(), 1, Vector2(NextButton->GetTex()->GetWidth()*3, NextButton->GetTex()->GetHeight()),
		Vector2(NextButton->GetTex()->GetWidth() , NextButton->GetTex()->GetHeight() * 2), 1.0f / 15.0f);
	animator->AddAnimClip(animation);
	animator->SetCurrentAnimClip(L"CurButton");
	NextButton->DeleteTexture();
	NextButton->GetTex()->SetAnimation(animator);
	NextButton->GetTex()->SetPosition(Vector3(325, 40, 1.0f));

	NextButton->GetTex()->SetSize(Vector3(NextButton->GetTex()->GetWidth(), NextButton->GetTex()->GetHeight(), 0));
	NextButton->SetRender(false);
	{
		for (int i = 0; i < 4; ++i) {
			UI* ItemSelect = new UI;
			ItemSelect->Init(L"Battle/BattleUI/Battleselectitembutton", 4, 4, 1);
			Animator* animator = new Animator;
			AnimationClip* animation = new AnimationClip(L"CurButton", ItemSelect->GetTexture(), 1, Vector2(0.f, 0.f),
				Vector2(ItemSelect->GetTex()->GetWidth(), ItemSelect->GetTex()->GetHeight()), 1.0f / 15.0f);
			animator->AddAnimClip(animation);

			animation = new AnimationClip(L"SelectButton", ItemSelect->GetTexture(), 1, Vector2(ItemSelect->GetTex()->GetWidth(), 0.f),
				Vector2(ItemSelect->GetTex()->GetWidth() * 2, ItemSelect->GetTex()->GetHeight()), 1.0f / 15.0f);
			animator->AddAnimClip(animation);
			animator->SetCurrentAnimClip(L"CurButton");
			ItemSelect->DeleteTexture();
			ItemSelect->GetTex()->SetAnimation(animator);

			ItemSelect->GetTex()->SetPosition(Vector3(0.f, 0.f, 1.0f));
				if (i == 0)
					ItemSelect->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 300, 1.0f));
				if (i == 1)
					ItemSelect->GetTex()->SetPosition(Vector3(382, 300, 1.0f));
				if (i == 2)
					ItemSelect->GetTex()->SetPosition(Vector3(WinMaxWidth / 4, 150, 1.0f));
				if (i == 3)
					ItemSelect->GetTex()->SetPosition(Vector3(382, 150, 1.0f));

			ItemSelect->GetTex()->SetSize(Vector3(ItemSelect->GetTex()->GetWidth() * 2, ItemSelect->GetTex()->GetHeight() * 2, 0));
			ItemSelect->SetRender(false);
			m_vecItemSelect.push_back(ItemSelect);
		}
	}
}

void BattleManager::ItemSelectInit()
{
	for (size_t i = 0; i < m_Player->GetvecItem().size(); ++i) {
		if (ITEM_TYPE::HEAL != m_Player->GetvecItem()[i]->GetItemType())continue;
		Item* citem = m_Player->GetvecItem()[i];
		m_vecHealItem.push_back(citem);
	}



	for (size_t i = 0; i < m_Player->GetvecItem().size(); ++i) {
		if (ITEM_TYPE::BALL != m_Player->GetvecItem()[i]->GetItemType())continue;
		Item* citem = m_Player->GetvecItem()[i];
		m_vecBallItem.push_back(citem);
	}

}


void BattleManager::Reset() {
	BattleChangeButton->SetRender(false);
	ChangeOrNotButton->SetRender(false);
	BattlePhase->SetRender(false);
	BackButton->SetRender(false);
	BattleItemBar->SetRender(false);
	BackGround->SetRender(false);
	CancelSelector->SetRender(false);
	FightSelector->SetRender(false);
	OpponentHpBar->SetRender(false);
	bHitted = false;
	OpponentHpPoint->SetRender(false);
	MediumSelector->SetRender(false);
	SmallSelector->SetRender(false);
	for (int i = 0; i < MAXPOKEMONCOUNT; ++i) {
		ourvecPokemon[i]->SetRender(false);
	}
	ItemSelector->SetRender(false);
}
void BattleManager::GUI()
{
	return;
	using namespace ImGui;
	
	for (size_t i = 0; i < m_Player->GetPokemons().size(); ++i) {
		string str = "Pokemon Font";
		str += to_string(i);
		Begin(str.c_str());
		 Vector3 position = m_Player->GetPokemons()[i]->GetIconNameFont()->GetPosition();
		{
			InputFloat3("Pos", position, 2);
		}
		m_Player->GetPokemons()[i]->GetIconNameFont()->SetPosition(position,true);
		End();
	}

}

void BattleManager::Update()
{
	if (bBattleEnd) {
		BattleEnd(m_Player, m_Npc);
		ChangeScene(SCENE_TYPE::FIELD);
		Reset();
		bDeadCheck = false;
		bCast = false;
		bPlayerBehavior = false; bHitEffectCheck = false;
		m_iHitEffectCount = 0; m_iTempValue = 0;
		 bUpdateHpBar = 0;
		PhaseReset();
		OurChangePokemon = false;
		 bFightChange = false;
		bBattleEnd = false;
		m_eCir = BATTLE_CIR::NONE;
		return;
	}

	if (m_eCir == BATTLE_CIR::ALL_READY) {
		BattlePhase->Update();
		SelectorUpdate();
	}
	switch (m_Player->GetSelectPhase())
	{

	case SELECT_PHASE::CHANGEORNOT:
		CancelSelector->GetTex()->SetSize(Vector3(410,79,0));
		if (!m_Player->GetSelect())
			CancelSelector->SetRender(false);
		else {
			CancelSelector->SetRender(true);
			if (1 == m_Player->GetSelect())
			{
				CancelSelector->GetTex()->SetPosition(Vector3(256,250,1));
			}
			else {
				CancelSelector->GetTex()->SetPosition(Vector3(256,125,1));
			}
		}
		break;
	case SELECT_PHASE::ITEM:
	{
		BattleItemBar->Update();
		ItemSelector->Update();
		for (int i = 0; i < 4; ++i)
			m_vecItemSelect[i]->Update();
		for (size_t i = 0; i < m_vecHealItem.size(); ++i)
			m_vecHealItem[i]->Update();
		NextButton->Update();
		PrevButton->Update();
	}
	break;

	}
	
	DoBattlePhase();
}
void BattleManager::NPCDefeat()
{
	if (nullptr != m_Npc)m_Npc->SetDefeat();
}
