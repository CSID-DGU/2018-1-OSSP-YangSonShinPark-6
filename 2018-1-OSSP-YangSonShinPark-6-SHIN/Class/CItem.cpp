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
	_bDead = false;
}

void CItem::Update(int dt)
{
	_Pos._y += g_nLevel * 2;
	_Items[_ItemType].SetPos(_Pos._x, _Pos._y);
	if(_Pos._y >= __D_SCREEN_HEIGHT__)
		_bDead = true;
}

void CItem::Render(int dt)
{
	_Items[_ItemType].Render();
}

void CItem::Exit()
{
	for(int i = 0 ; i < __E_ITEM_MAX__ ; i++)
		_Items[i].Exit();
}

void CItem::Make(const stItemInfo& info)
{
	_Pos._x = info._position._x;
	_Pos._y = 0 - info._position._y;

	int type = rand()%100 + 1;
	if( info._type == 'O' )
	{
		if(type <= 15) _ItemType = __E_ITEM_ROCK__;
		else if(type <= 45) _ItemType = __E_ITEM_STICK__;
		else if(type <= 60) _ItemType = __E_ITEM_STONE__;
		else if(type <= 80) _ItemType = __E_ITEM_THORN__;
		else _ItemType = __E_ITEM_BONE__;
	}
	else if( info._type == 'F' )
	{
		if(type <= 70) _ItemType =  __E_ITEM_MOUSE__;
		else _ItemType =  __E_ITEM_BUG__;
	}
	else if( info._type == 'I' )
	{
		if(type <= 20) _ItemType = __E_ITEM_BORN__;
		else _ItemType = __E_ITEM_SUPER__;
	}
}
