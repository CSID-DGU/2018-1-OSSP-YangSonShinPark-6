/*
 * CGameManager.h
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#ifndef LIBRARY_CGAMEMANAGER_H_
#define LIBRARY_CGAMEMANAGER_H_

class CGameManager {
	bool _bGame;
	SDL_Event _Event;
public:
	void Init();
	void Loop();
	void Exit();
};

#endif /* LIBRARY_CGAMEMANAGER_H_ */
