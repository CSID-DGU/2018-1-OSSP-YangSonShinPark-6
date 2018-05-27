/*
 * CAnimationRenderer.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: root
 */

#ifndef LIBRARY_CANIMATIONRENDERER_H_
#define LIBRARY_CANIMATIONRENDERER_H_

class CAnimationRenderer{
public:
	std::vector<CImageRenderer*> _vAnimation;

	int 	_idx;
	int 	_maxFrame;
	float 	_fSceneTimer;
	float 	_fCurrTime;
public:
	void SetImage(const std::string& path, SDL_Surface * screen, const float& frame);
	void SetImage(const std::string& path, SDL_Surface * screen, const float& frame, const int& num);
	void Render(float dt);
	void Exit();
	void SetPos(const stPos& pos);
};

#endif /* LIBRARY_CANIMATIONRENDERER_H_ */
