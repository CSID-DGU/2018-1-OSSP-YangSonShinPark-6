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

	_ItemType = RandType();
	_Pos._x = rand() % (__D_SCREEN_WIDTH__ - 56);
	_Pos._y = 0;
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

eItem CItem::RandType()
{
	int type = rand()%100 + 1;
	if(type <= 10) return __E_ITEM_MOUSE__;
	else if(type <= 20) return __E_ITEM_BUG__;
	else if(type <= 25) return __E_ITEM_ROCK__;
	else if(type <= 45) return __E_ITEM_STICK__;
	else if(type <= 55) return __E_ITEM_STONE__;
	else if(type <= 80) return __E_ITEM_THORN__;
	else if(type <= 95) return __E_ITEM_BONE__;
	else if(type <= 98) return __E_ITEM_BORN__;
	else return __E_ITEM_SUPER__;
}
