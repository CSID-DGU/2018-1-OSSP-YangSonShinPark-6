/*
 * CUI.cpp
 *
 *  Created on: 2018. 5. 27.
 *      Author: root
 */

#include "../stdafx.h"

void CUI::Init(SDL_Surface * screen)
{
	for(int i = 0 ; i < 12 ; i++)
	{
		_BackGrounds[i].SetImage("Object/BG_Tile_7.png",screen);
		if( i % 2 == 0 ) _BackGroundsPos[i]._x = 0;
		else _BackGroundsPos[i]._x = 250;
		_BackGroundsPos[i]._y = -500 + (250 * (int)(i/2));
	}

	_nScrollSpeed = 2;
}

void CUI::Update()
{
	for(int i = 0 ; i < 12 ; i++)
	{
		_BackGroundsPos[i]._y += _nScrollSpeed;
		_BackGrounds[i].SetPos(_BackGroundsPos[i]._x, _BackGroundsPos[i]._y);
		if(_BackGroundsPos[i]._y >= 800)
			_BackGroundsPos[i]._y = -450;
	}
}

void CUI::Render()
{
	for(int i = 0 ; i < 12 ; i++)
		_BackGrounds[i].Render();
}

void CUI::Exit()
{
	for(int i = 0 ; i < 12 ; i++)
		_BackGrounds[i].Exit();
}
