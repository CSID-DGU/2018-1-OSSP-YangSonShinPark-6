#include "stdafx.h"

void CImageRenderer::SetImage(const std::string& path, const int& xpos, const int& ypos, const int& width, const int& height)
{
	std::string _path = "resource/" + path;
	_Image = cvLoadImage(_path.c_str(), CV_LOAD_IMAGE_UNCHANGED);
	_stPos._xPos = xpos;
	_stPos._yPos = ypos;

	if (_Image == NULL)
		std::cout << path << " : do not find image file" << std::endl;
	_nWidth = width;
	_nHeight = height;

	_nDir = __E_RIGHT__;
}

void CImageRenderer::Draw()
{
	if (_Image == NULL)
		return;
	glPushMatrix();
	
	glRasterPos2f(_nDir == __E_LEFT__ ? _stPos._xPos + _nWidth : _stPos._xPos, _stPos._yPos);
	glPixelZoom(_nDir, -1);
	glDrawPixels(_nWidth, _nHeight, GL_RGBA, GL_UNSIGNED_BYTE, _Image->imageData);
	
	glPopMatrix();
}

void CImageRenderer::Exit()
{
	cvReleaseImage(&_Image);
}
