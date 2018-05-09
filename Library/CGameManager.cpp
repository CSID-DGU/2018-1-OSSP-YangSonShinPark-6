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
	_Image.SetImage("apple.png");
}

void CGameManager::Loop(SDL_Surface * screen)
{
	while(_bGame)
	{
		SDL_PollEvent(&_Event);
		if( _Event.type == SDL_KEYDOWN )
			if( _Event.key.keysym.sym == SDLK_ESCAPE )
				_bGame = false;

		_Image.Render(screen);
	}
}

void CGameManager::Exit()
{

}
