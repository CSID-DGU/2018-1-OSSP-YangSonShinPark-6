/*
 * CImageRenderer.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#include "../stdafx.h"

void CImageRenderer::SetImage(const std::string& filePath)
{
	std::string path = "resource/" + filePath;
	_Rwop = SDL_RWFromFile(path.c_str(), "rb");
	_Image = IMG_LoadPNG_RW(_Rwop);
	if( _Image == NULL )
		std::cout << filePath << " : Cannot find" << std::endl;

	_Map = (GLubyte*)_Image->pixels;
	_nWidth = _Image->w;
	_nHeight = _Image->h;

	glGenTextures(1, &_TexID);
	glBindTexture(GL_TEXTURE_2D, _TexID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
					_nWidth, _nHeight, 0,
					GL_RGBA, GL_UNSIGNED_BYTE, _Map);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void CImageRenderer::Render(SDL_Surface * screen)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glBindTexture(GL_TEXTURE_2D, _TexID);

	glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.f); glVertex2f(0, 0);
		glTexCoord2f(1.f, 0.f); glVertex2f(_nWidth, 0);
		glTexCoord2f(1.f, 1.f); glVertex2f(_nWidth, _nHeight);
		glTexCoord2f(0.f, 1.f); glVertex2f(0, _nHeight);
	glEnd();
}
