/*
 * CGameManager.h
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#ifndef LIBRARY_CGAMEMANAGER_H_
#define LIBRARY_CGAMEMANAGER_H_

class CGameManager {
	SDL_Event _Event;

	CImageRenderer _Image;

	bool _bGame;
public:
	void Init();
	void Loop(SDL_Surface * screen);
	void Exit();
};

#endif /* LIBRARY_CGAMEMANAGER_H_ */
