/*
 * CGraphicsManager.h
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#ifndef RESOURCE_CGRAPHICSMANAGER_H_
#define RESOURCE_CGRAPHICSMANAGER_H_

class CGraphicsManager {
	SDL_Window * 	_Window;
	SDL_Surface * _ScreenSurface;

	SDL_Event 		_Event;
	CGameManager  _Game;

	Uint32 _deltaTime;
	Uint32 _nFrameTime;

private:
	Uint32 CountTime();

public:
	void Init();
	void Loop();
	void Exit();
};

#endif /* RESOURCE_CGRAPHICSMANAGER_H_ */
