/*
 * CGameManager.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#include "../stdafx.h"

void CGameManager::Init(SDL_Surface * screen)
{
	g_eState = (int)__E_MENU__;

	_vScene.push_back(new CMenu());
	_vScene.push_back(new CGame());
	_vScene.push_back(new COption());

	for(int i = 0; i < _vScene.size(); i++)
		_vScene[i]->Init(screen);
}

void CGameManager::Loop(int dt)
{
	_vScene[g_eState]->Update(dt);
	_vScene[g_eState]->Render(dt);
}

void CGameManager::Exit()
{
	_vScene[g_eState]->Exit();
}
