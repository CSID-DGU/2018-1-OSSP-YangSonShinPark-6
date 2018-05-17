/*
 * CAnimationRenderer.cpp
 *
 *  Created on: 2018. 5. 16.
 *      Author: root
 */

#include "stdafx.h"

void CAnimationRenderer::SetImage(const std::string& path, SDL_Surface * screen, const float& frame)
{
	CImageRenderer * image = new CImageRenderer();
	std::string imgPath = "resource/" + path;
	image->SetImage(imgPath, screen);

	_vAnimation.push_back(image);

	_idx = 0;
	_maxFrame = _vAnimation.size();
}

void CAnimationRenderer::SetImage(const std::string& path, SDL_Surface * screen, const float& frame, const int& num)
{
	for(int i = 1 ; i <= frame ; i++)
	{
		CImageRenderer * image = new CImageRenderer();
		std::string imgPath = "resource/" + path + i + ".png";
		image->SetImage(imgPath, screen);
		_vAnimation.push_back(image);
	}

	_idx = 0;
	_maxFrame = _vAnimation.size();
}

void CAnimationRenderer::Render(float dt)
{
	if( _fCurrTime > _fSceneTimer )
	{
		_idx++;
		if( _idx >= _maxFrame )
			_idx = 0;
	}

	_vAnimation[_idx]->Render();

	_fCurrTime += dt;
}

void CAnimationRenderer::Exit()
{
	for(int i = 0 ; i < _vAnimation.size() ; i++)
			delete _vAnimation[i];

	_vAnimation.clear();
}

void CAnimationRenderer::SetPos(const stPos& pos)
{
	for(int i = 0 ; i < _vAnimation.size() ; i++)
		_vAnimation[i]->SetPos(pos._x, pos._y);
}
