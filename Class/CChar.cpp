/*
 * CChar.cpp
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#include "../stdafx.h"

void CChar::Init(SDL_Surface * screen)
{
	_Image.SetImage("Character/Mole_1.png", screen);
}

void CChar::Update()
{
	_Image.SetPos(_Pos._x, _Pos._y);
}

void CChar::Render()
{
	_Image.Render();
}

void CChar::Exit()
{
	_Image.Exit();
}
