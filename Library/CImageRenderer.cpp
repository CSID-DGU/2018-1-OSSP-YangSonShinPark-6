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

	_Screen = screen;
	_Image = IMG_Load(path.c_str());
	if( _Image == NULL )
		std::cout << filePath << " : Cannot find" << std::endl;
	else
	{
		_Origin = SDL_ConvertSurface(_Image, _Screen->format, 0);
		if(_Origin == NULL)
			std::cout << "Unable to optimize img" << path << std::endl;

		SDL_FreeSurface(_Image);
	}
}

void CImageRenderer::Render()
{
	SDL_BlitSurface(_Origin, NULL, _Screen, NULL);
}

void CImageRenderer::Exit()
{

}
