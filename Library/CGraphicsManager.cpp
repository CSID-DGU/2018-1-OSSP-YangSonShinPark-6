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
			std::cout << "SDL could not initialize! SDL_ERROR" << SDL_GetError() << std::endl;
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
			std::cout << "Window could not be created!" << std::endl;
		elseP
		{
			_ScreenSurface = SDL_GetWindowSurface(_Window);
			SDL_FillRect( _ScreenSurface, NULL, SDL_MapRGB(_ScreenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(_Window);
			_Game.Init();
		}
	}
}

void CGraphicsManager::Loop()
{
	_Game.Loop();
}

void CGraphicsManager::Exit()
{
	_Game.Exit();

	SDL_DestroyWindow(_Window);
	SDL_Quit();
}




