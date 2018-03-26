#pragma once

//!< use Opencv & Opengl
//!< Opencv just using png
//!<Ref_Site     http://pencil1031.tistory.com/72
//!<			 https://stackoverflow.com/questions/16809833/opencv-image-loading-for-opengl-texture
//!<			 https://open.gl/textures

class CImageRenderer
{
	IplImage * 	_Image;

protected:
	int				_nWidth;
	int				_nHeight;
	int				_nDir;

	stPos			_stPos;

public:

	//!< public Call
	void SetImage(const std::string& path, const int& xpos, const int& ypos, const int& width, const int& height);
	virtual void Draw();
	virtual void Exit();

	//!< setter
	void SetPosition(const stPos& pos) { _stPos = pos; }
	void SetDirection(const eDir& dir) { _nDir = dir; }

	//!< getter
	stPos GetPosition() { return _stPos; }
	int		GetWidth() { return _nWidth; }
	int		GetHeight() { return _nHeight; }
};
