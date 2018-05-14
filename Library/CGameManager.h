/*
 * CGameManager.h
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#ifndef LIBRARY_CGAMEMANAGER_H_
#define LIBRARY_CGAMEMANAGER_H_

class CGameManager {
	SDL_Surface* _Screen;

	CImageRenderer _Image;

	std::vector<CSceneManager*> _vScene;

	bool _bGame;
public:
	void Init(SDL_Surface * screen);
	void Loop();
	void Exit();
};

#endif /* LIBRARY_CGAMEMANAGER_H_ */
