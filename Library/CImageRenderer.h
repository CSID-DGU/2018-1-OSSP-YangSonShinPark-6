/*
 * CImageRenderer.h
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#ifndef LIBRARY_CIMAGERENDERER_H_
#define LIBRARY_CIMAGERENDERER_H_

class CImageRenderer {
	SDL_Surface * _Image;
	SDL_Surface * _Origin;
	SDL_Surface * _Screen;

	std::string 	_sName;
	SDL_Rect		_Rect;

public:
	void SetImage(const std::string& filePath, SDL_Surface * screen);
	void Render();
	void Exit();

	//!< setter
	void SetName(const std::string& name) { _sName = name; }
	void SetPos(const int& x, const int& y) { _Rect.x = x; _Rect.y = y; }
};
#endif /* LIBRARY_CIMAGERENDERER_H_ */
