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

	for(int i = 0; i < _vScene.size(); i++)
		_vScene[i]->Init(screen);
}

void CGameManager::Loop()
{
	_vScene[g_eState]->Update();
	_vScene[g_eState]->Render();
}

void CGameManager::Exit()
{
	_vScene[g_eState]->Exit();
}
