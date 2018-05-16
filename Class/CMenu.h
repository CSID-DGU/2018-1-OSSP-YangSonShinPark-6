/*
 * CMenu.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: root
 */

#ifndef CLASS_CMENU_H_
#define CLASS_CMENU_H_

class CMenu : public CSceneManager
{
	CImageRenderer _BackGround;
	CImageRenderer _StartButton;
	CImageRenderer _OptionButton;


	stPos 			 _MousePosition;

private:
	void MouseEvent();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* CLASS_CMENU_H_ */
