/*
 * CAnimationRenderer.cpp
 *
 *  Created on: 2018. 5. 16.
 *      Author: root
 */

#include "../stdafx.h"

void CAnimationRenderer::SetImage(const std::string& path, SDL_Surface * screen, const int& frame)
{
	CImageRenderer * image = new CImageRenderer();
	image->SetImage(path, screen);

	_vAnimation.push_back(image);
	_nSceneTimer = frame;
	_idx = 0;
	_maxFrame = _vAnimation.size();
	_bShow = true;
}

void CAnimationRenderer::SetImage(const std::string& path, SDL_Surface * screen, const int& frame, const int& num)
{
	for(int i = 1 ; i <= num ; i++)
	{
		CImageRenderer * image = new CImageRenderer();
		std::ostringstream stream;
		stream << i;
		std::string imgPath = path + stream.str() + ".png";
		image->SetImage(imgPath, screen);
		_vAnimation.push_back(image);
	}

	_idx = 0;
	_maxFrame = _vAnimation.size();
	_nSceneTimer = frame;
	_bShow = true;
}

void CAnimationRenderer::Render(int dt)
{
	if(!_bShow)
		return;

	if( _nCurrTime > _nSceneTimer )
	{
		_idx++;
		_nCurrTime = 0;
		if( _idx >= _maxFrame )
		{
			_idx = 0;
			if(!_bLoop)
				_bShow = false;
		}
	}
	_vAnimation[_idx]->Render();
	_nCurrTime += dt;
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
