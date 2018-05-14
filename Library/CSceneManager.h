/*
 * CSceneManager.h
 *
 *  Created on: 2018. 5. 14.
 *      Author: root
 */

#ifndef LIBRARY_CSCENEMANAGER_H_
#define LIBRARY_CSCENEMANAGER_H_

class CSceneManager {
public:
	SDL_Surface * _Screen;

	virtual void Init(SDL_Surface * screen) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
};

#endif /* LIBRARY_CSCENEMANAGER_H_ */
