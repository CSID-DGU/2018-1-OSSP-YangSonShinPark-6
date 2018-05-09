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
			std::cout << "SDL could not initialize! SDL_ERROR " << SDL_GetError() << std::endl;
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
		else
		{
			_Context = SDL_GL_CreateContext(_Window);

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glEnable(GL_TEXTURE_2D);
			glOrtho(0, __D_SCREEN_WIDTH__, __D_SCREEN_HEIGHT__, 0, -1, 1);

			_Game.Init();
		}
	}
}

void CGraphicsManager::Loop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_Game.Loop(_ScreenSurface);

	SDL_GL_SwapWindow(_Window);
}

void CGraphicsManager::Exit()
{
	_Game.Exit();

	IMG_Quit();
	SDL_DestroyWindow(_Window);
	SDL_Quit();
}




