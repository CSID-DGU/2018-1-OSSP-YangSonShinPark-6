/*
 * CGraphicsManager.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#include "../stdafx.h"

void CGraphicsManager::Init()
{
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
			std::cout << "SDL could not initialize! SDL_ERROR " << SDL_GetError() << std::endl;
			_bLoop = false;
	}
	else
	{
		//!< Create Window
		_Window = SDL_CreateWindow("GAME",
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										__D_SCREEN_WIDTH__,
										__D_SCREEN_HEIGHT__,
										SDL_WINDOW_SHOWN);
		if( _Window == NULL )
		{
			std::cout << "Window could not be created!" << std::endl;
			_bLoop = false;
		}
		else
		{
			if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) )
				_bLoop = false;
			else
			{
				_bLoop = true;
				_ScreenSurface = SDL_GetWindowSurface(_Window);

				_Game.Init(_ScreenSurface);
			}
		}
	}
}

void CGraphicsManager::Loop()
{
	while(_bLoop)
	{
		SDL_PollEvent(&_Event);
				if( _Event.type == SDL_KEYDOWN )
					if( _Event.key.keysym.sym == SDLK_ESCAPE )
						_bLoop = false;

		_Game.Loop();
		SDL_UpdateWindowSurface(_Window);
	}
}

void CGraphicsManager::Exit()
{
	_Game.Exit();

	IMG_Quit();
	SDL_DestroyWindow(_Window);
	SDL_Quit();
}




