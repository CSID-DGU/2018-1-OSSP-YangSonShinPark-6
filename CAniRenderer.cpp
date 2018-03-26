#include "stdafx.h"

void CAniRenderer::InitAnimation(const int& xpos, const int& ypos, const int& imagemax, const int& time)
{
	_stPos._xPos = xpos;
	_stPos._yPos = ypos;

	_nMax = imagemax;
	_nAniTime = time;

	_nIdx = 0;
	_fFrameTime = 0.0f;

	_nDir = __E_RIGHT__;
}

void CAniRenderer::SetImage(const std::string& path, const int& width, const int& height)
{
	std::string _path = "resource/" + path;
	IplImage * _Image = new IplImage;

	_Image = cvLoadImage(_path.c_str(), CV_LOAD_IMAGE_UNCHANGED);

	if (_Image == NULL)
		std::cout << path << " : do not find image file" << std::endl;
	
	_nWidth = width;
	_nHeight = height;

	_vAni.push_back(_Image);
}

void CAniRenderer::Draw()
{
	if (_vAni[_nIdx] == NULL)
		return;
	
	_fFrameTime += 1000.0f / __D_FRAME_MAX__;

	if (_nAniTime < _fFrameTime)
	{
		_fFrameTime = 0.0f;
		_nIdx++;

		if (_nIdx >= _nMax - 1)
			_nIdx = 0;
	}

	glPushMatrix();

	glRasterPos2f(_nDir == __E_LEFT__ ? _stPos._xPos + _nWidth : _stPos._xPos, _stPos._yPos);
	glPixelZoom(_nDir, -1);
	glDrawPixels(_nWidth, _nHeight, GL_RGBA, GL_UNSIGNED_BYTE, _vAni[_nIdx]->imageData);

	glPopMatrix();
}

void CAniRenderer::Exit()
{
	for (int i = 0; i < _nMax; i++)
		delete _vAni[i];

	_vAni.clear();
}
