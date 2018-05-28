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
	CImageRenderer _TitleGround;
	CImageRenderer _BackGround;
	CImageRenderer _StartButton;
	CImageRenderer _OptionButton;

	stPos 			 _MousePosition;
	stPos 			 _TitlePosition;

	bool 			 _bUp;

private:
	void MouseEvent();
	void Move_Title();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();
};

#endif /* CLASS_CMENU_H_ */
