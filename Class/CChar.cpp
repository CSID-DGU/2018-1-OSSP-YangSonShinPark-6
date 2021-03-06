/*
 * CChar.cpp
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#include "../stdafx.h"

void CChar::Init(SDL_Surface * screen)
{
	_Ani.SetImage("Character/Mole_1.png", screen, 100);
	_Ani.SetImage("Character/Mole_2.png", screen, 100);
	_Ani.SetLoop(true);

	_Boost.SetImage("Effect/Booster1_1.png", screen, 250);
	_Boost.SetImage("Effect/Booster2_1.png", screen, 250);
	_Boost.SetImage("Effect/Booster3_1.png", screen, 250);
	_Boost.SetImage("Effect/Booster4_1.png", screen, 250);
	_Boost.SetLoop(false);
	_Boost.SetShow(false);

	_BoostEff.SetImage("Effect/Booster1_2.png", screen, 250);
	_BoostEff.SetImage("Effect/Booster2_2.png", screen, 250);
	_BoostEff.SetImage("Effect/Booster3_2.png", screen, 250);
	_BoostEff.SetImage("Effect/Booster4_2.png", screen, 250);
	_BoostEff.SetLoop(false);
	_BoostEff.SetShow(false);

	_HpEff.SetImage("Effect/Heal_1.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_2.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_3.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_4.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_5.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_6.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_7.png", screen, 125);
	_HpEff.SetImage("Effect/Heal_8.png", screen, 125);
	_HpEff.SetLoop(false);
	_HpEff.SetShow(false);

	_LossEff.SetImage("Effect/Hit_1.png", screen, 250);
	_LossEff.SetImage("Effect/Hit_2.png", screen, 250);
	_LossEff.SetImage("Effect/Hit_3.png", screen, 250);
	_LossEff.SetImage("Effect/Hit_4.png", screen, 250);
	_LossEff.SetLoop(false);
	_LossEff.SetShow(false);

	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0 ; j < 10 ; j++)
		{
			std::ostringstream stream;
			stream << j;
			std::string imgPath = "Number/" + stream.str() + ".png";
			_Scores[i][j].SetImage(imgPath, screen);
			_Scores[i][j].SetPos(440 - (i*30), 740);
		}

	_Pos._x = 200;
	_Pos._y = 650;
	_nSpeed = 5;
	_nHp = 8;
	_nScore = 0;
	_eState = __E_ITEM_MAX__;
}

void CChar::Update(int dt)
{
	_nScore += 1;
	if(_Pos._x < -20) _Pos._x = -20;
	else if(_Pos._x > 435) _Pos._x = 435;

	//!< divine mode
	if(_nHp <= 0) g_eState = __E_MENU__;

	_Ani.SetPos(_Pos);
	if(_Boost.GetShow())
	{
		stPos pos(_Pos._x - 56, _Pos._y - 15);
		_Boost.SetPos(pos);
		_BoostEff.SetPos(pos);
		g_nBoost = 3;
	}
	else
		g_nBoost = 1;

	if(_HpEff.GetShow())
	{
		stPos pos(_Pos._x - 32, _Pos._y - 15);
		_HpEff.SetPos(pos);
	}

	if(_LossEff.GetShow())
	{
		stPos pos(_Pos._x - 32, _Pos._y - 15);
		_LossEff.SetPos(pos);
	}
}

void CChar::Render(int dt)
{
	if(_BoostEff.GetShow())
		_BoostEff.Render(dt);

	_Ani.Render(dt);
	if(_Boost.GetShow())
		_Boost.Render(dt);

	if(_LossEff.GetShow())
		_LossEff.Render(dt);

	if(_HpEff.GetShow())
		_HpEff.Render(dt);

	int cur = _nScore%10;
	_Scores[0][cur].Render(); cur = (_nScore/10)%10;
	_Scores[1][cur].Render(); cur = (_nScore/100)%10;
	_Scores[2][cur].Render(); cur = (_nScore/1000)%10;
	_Scores[3][cur].Render();
}

void CChar::Exit()
{
	_Ani.Exit();
}

void CChar::CheckState()
{
	if( _eState != __E_ITEM_MAX__ && !_Boost.GetShow() )
	{
		if( _eState == __E_ITEM_BUG__ )
		{
			_nHp += 1;
			if( _nHp > 8 ) _nHp = 8;
			_nScore += 5;
			_HpEff.SetShow(true);
		}
		else if( _eState == __E_ITEM_MOUSE__ )
		{
			_nHp += 2;
			if( _nHp > 8 ) _nHp = 8;
			_nScore += 15;
			_HpEff.SetShow(true);
		}
		if(!_LossEff.GetShow())
		{
			if( _eState == __E_ITEM_BONE__ || _eState == __E_ITEM_THORN__ )
			{
				_nHp -= 1;
				_LossEff.SetShow(true);
			}
			else if( _eState == __E_ITEM_STICK__ )
			{
				_nHp -= 2;
				_LossEff.SetShow(true);
			}
			else if( _eState == __E_ITEM_ROCK__ || _eState == __E_ITEM_STONE__ )
			{
				_nHp -= 3;
				_LossEff.SetShow(true);
			}
		}
		_eState = __E_ITEM_MAX__;
	}
}

void CChar::SetState(eItem st)
{
	_eState = st;
	if(st == __E_ITEM_SUPER__)
	{
		_nScore += 20;
		_Boost.SetShow(true);
		_BoostEff.SetShow(true);
	}

	CheckState();
}
