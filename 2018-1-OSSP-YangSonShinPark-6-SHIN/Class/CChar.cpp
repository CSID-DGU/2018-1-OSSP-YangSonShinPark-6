/*
 * CChar.cpp
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#include "../stdafx.h"

void CChar::Init(SDL_Surface * screen)
{
//	_Image.SetImage("Character/Mole_1.png", screen);
	_Ani.SetImage("Character/Mole_1.png", screen, 100);
	_Ani.SetImage("Character/Mole_2.png", screen, 100);
	_Pos._x = 200;
	_Pos._y = 650;
	_nSpeed = 5;
	_nHp = 10;
	_eState = __E_ITEM_MAX__;
}

void CChar::Update(int dt)
{
	CheckState();

	if(_Pos._x < -20) _Pos._x = -20;
	else if(_Pos._x > 435) _Pos._x = 435;

	_Ani.SetPos(_Pos);
}

void CChar::Render(int dt)
{
	_Ani.Render(dt);
}

void CChar::Exit()
{
	_Ani.Exit();
}

void CChar::CheckState()
{
	if( _eState != __E_ITEM_MAX__ )
	{
		if( _eState == __E_ITEM_BUG__ ) _nHp += 10;
		else if( _eState == __E_ITEM_MOUSE__ ) _nHp += 30;
		else if( _eState == __E_ITEM_BONE__ || _eState == __E_ITEM_THORN__ ) _nHp -= 10;
		else if( _eState == __E_ITEM_STICK__ ) _nHp -= 5;
		else if( _eState == __E_ITEM_ROCK__ || _eState == __E_ITEM_STONE__ ) _nHp -= 20;
		_eState = __E_ITEM_MAX__;
	}
}
