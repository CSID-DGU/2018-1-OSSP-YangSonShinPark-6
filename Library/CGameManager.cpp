/*
 * CGameManager.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#include "../stdafx.h"

void CGameManager::Init()
{
	_bGame = true;
}

void CGameManager::Loop()
{
	while(_bGame)
	{
		SDL_PollEvent(&_Event);
		if( _Event.type == SDLK_ESCAPE )
			_bGame = false;
	}
}

void CGameManager::Exit()
{

}
