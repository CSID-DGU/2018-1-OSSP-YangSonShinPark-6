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
	CAnimationRenderer _Ani;

	int 			 _nSpeed;
	int 			 _nHp;
	eItem		 	 _eState;

private:
	void CheckState();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();

	//!< Setter & Getter
	void SetState(eItem st) { _eState = st; }

	eItem GetState() { return _eState; }
	int GetSpeed() { return _nSpeed; }

};

#endif /* CLASS_CCHAR_H_ */
