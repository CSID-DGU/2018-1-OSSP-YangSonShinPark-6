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
			g_bLoop = false;
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
			g_bLoop = false;
		}
		else
		{
			if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) )
				g_bLoop = false;
			else
			{
				srand(time(NULL));
				g_bLoop = true;
				_ScreenSurface = SDL_GetWindowSurface(_Window);

				_Game.Init(_ScreenSurface);
			}
		}
	}
}

void CGraphicsManager::Loop()
{
	while(g_bLoop)
	{
		SDL_FillRect(_ScreenSurface, NULL, 0x000000);
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




