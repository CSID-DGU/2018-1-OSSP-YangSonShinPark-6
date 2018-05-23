/*
 * CItem.cpp
 *
 *  Created on: 2018. 5. 23.
 *      Author: root
 */

#include "../stdafx.h"


void CItem::Init(SDL_Surface * screen)
{
	_Items.resize(__E_ITEM_MAX__);
	for(int i = 0 ; i < __E_ITEM_MAX__ ; i++)
	{
		std::ostringstream stream;
		stream << i;
		std::string str = "Object/Object_" + stream.str() + ".png";
		_Items[i].SetImage(str, screen);
	}

	_ItemType = (eItem)(rand() % (int)__E_ITEM_MAX__);
	_Pos._x = rand() % __D_SCREEN_WIDTH__;
	_bDead = false;
}

void CItem::Update()
{
	_Pos._y += 1;
	_Items[_ItemType].SetPos(_Pos._x, _Pos._y);
	if(_Pos._y >= __D_SCREEN_HEIGHT__)
		_bDead = true;
}

void CItem::Render()
{
	_Items[_ItemType].Render();
}

void CItem::Exit()
{
	for(int i = 0 ; i < __E_ITEM_MAX__ ; i++)
		_Items[i].Exit();
}
