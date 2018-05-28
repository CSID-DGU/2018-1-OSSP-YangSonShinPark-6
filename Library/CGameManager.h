/*
 * CGameManager.h
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#ifndef LIBRARY_CGAMEMANAGER_H_
#define LIBRARY_CGAMEMANAGER_H_

class CGameManager {
	eGameState 					_eState;

	std::vector<CSceneManager*> _vScene;

	bool _bGame;

public:
	void Init(SDL_Surface * screen);
	void Loop(int dt);
	void Exit();
};

#endif /* LIBRARY_CGAMEMANAGER_H_ */
