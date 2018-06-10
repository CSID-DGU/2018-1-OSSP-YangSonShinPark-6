/*
 * CAnimationRenderer.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: root
 */

#ifndef LIBRARY_CANIMATIONRENDERER_H_
#define LIBRARY_CANIMATIONRENDERER_H_

class CAnimationRenderer{

	std::vector<CImageRenderer*> _vAnimation;

	int 	_idx;
	int 	_maxFrame;
	bool 	_bLoop;
	bool 	_bShow;
	Uint32 _nSceneTimer;
	Uint32 _nCurrTime;

public:
	void SetImage(const std::string& path, SDL_Surface * screen, const int& frame);
	void SetImage(const std::string& path, SDL_Surface * screen, const int& frame, const int& num);
	void Render(int dt);
	void Exit();
	void SetPos(const stPos& pos);

	//!< set & get
	void SetLoop(bool lp) { _bLoop = lp; }
	void SetShow(bool s) { _bShow = s; }

	bool GetShow() { return _bShow; }
};

#endif /* LIBRARY_CANIMATIONRENDERER_H_ */
