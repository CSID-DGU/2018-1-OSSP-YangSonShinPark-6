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
	SDL_RWops   * _Rwop;
	GLubyte	 *	_Map;
	GLuint			_TexID;

	int 			_nWidth;
	int 			_nHeight;

public:
	void SetImage(const std::string& filePath);
	void Render(SDL_Surface * screen);
};

#endif /* LIBRARY_CIMAGERENDERER_H_ */
