/*
 * CChar.h
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#ifndef CLASS_CCHAR_H_
#define CLASS_CCHAR_H_

class CChar : public CObject {
	CImageRenderer _Image;	//mole

	CImageRenderer _Image1;	//backgroud
	CImageRenderer _Image2;
	CImageRenderer _Image3;
	CImageRenderer _Image4;
	CImageRenderer _Image5;
	CImageRenderer _Image6;

	int 			 _nSpeed;

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();

	//!< Getter
	int GetSpeed() { return _nSpeed; }

};

#endif /* CLASS_CCHAR_H_ */
