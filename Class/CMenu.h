/*
 * CMenu.h
 *
 *  Created on: 2018. 5. 14.
 *      Author: root
 */

#ifndef LIBRARY_CMENU_H_
#define LIBRARY_CMENU_H_

class CMenu : public CSceneManager {

	CImageRenderer _BackGround;
	CImageRenderer _StartButton;
	CImageRenderer _OptionButton;

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* LIBRARY_CMENU_H_ */
