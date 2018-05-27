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
	_nFrameTime = SDL_GetTicks() + __D_FRAME_TIMER__;
	while(g_bLoop)
	{
		_deltaTime = CountTime();
		SDL_FillRect(_ScreenSurface, NULL, 0x000000);
		_Game.Loop();
		SDL_UpdateWindowSurface(_Window);
		SDL_Delay(_deltaTime);
		_nFrameTime += __D_FRAME_TIMER__;
	}
}

void CGraphicsManager::Exit()
{
	_Game.Exit();

	IMG_Quit();
	SDL_DestroyWindow(_Window);
	SDL_Quit();
}

Uint32 CGraphicsManager::CountTime()
{
	Uint32 now;

	now = SDL_GetTicks();
	if( _nFrameTime <= now )
		return 0;
	else
		return _nFrameTime - now;
}




