/*
 * CChar.h
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#ifndef CLASS_CCHAR_H_
#define CLASS_CCHAR_H_

class CChar : public CObject {
	CImageRenderer _Image;

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();

};

#endif /* CLASS_CCHAR_H_ */
