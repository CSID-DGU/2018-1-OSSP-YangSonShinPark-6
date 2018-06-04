/*
 * COption.h
 *
 *  Created on: 2018. 5. 22.
 *      Author: root
 */

#ifndef CLASS_COPTION_H_
#define CLASS_COPTION_H_

class COption : public CSceneManager{

	CImageRenderer _Background;
	CImageRenderer _Sound_IMG;
	CImageRenderer _ON_Btn;
	CImageRenderer _OFF_Btn;
	CImageRenderer _Back_Btn;
	CImageRenderer _Choose_Btn;

	stPos 			 _MousePosition;

private:
	void MouseEvent();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();
};
#endif /* CLASS_COPTION_H_ */
