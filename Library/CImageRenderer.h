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

	int 			_nWidth;
	int 			_nHeight;

public:
	void SetImage(const std::string& filePath, SDL_Surface * screen);
	void Render(SDL_Surface * screen);
	void Exit();
};

#endif /* LIBRARY_CIMAGERENDERER_H_ */
