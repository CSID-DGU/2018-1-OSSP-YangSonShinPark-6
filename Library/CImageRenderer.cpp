/*
 * CImageRenderer.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#include "../stdafx.h"

void CImageRenderer::SetImage(const std::string& filePath, SDL_Surface * screen)
{
	std::string path = "resource/" + filePath;

	_Image = IMG_Load(path.c_str());
	if( _Image == NULL )
		std::cout << filePath << " : Cannot find" << std::endl;
	else
	{
		_Origin = SDL_ConvertSurface(_Image, screen->format, NULL);
		if(_Origin == NULL)
			std::cout << "Unable to optimize img" << path << std::endl;

		SDL_FreeSurface(_Image);
	}
}

void CImageRenderer::Render(SDL_Surface * screen)
{
	SDL_BlitSurface(_Origin, NULL, screen, NULL);
}

void CImageRenderer::Exit()
{

}
