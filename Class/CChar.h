/*
 * CChar.h
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#ifndef CLASS_CCHAR_H_
#define CLASS_CCHAR_H_

class CChar : public CObject {

	CImageRenderer _Scores[4][10];
	CAnimationRenderer _Ani;
	CAnimationRenderer _Boost;
	CAnimationRenderer _BoostEff;
	CAnimationRenderer _HpEff;
	CAnimationRenderer _LossEff;

	int 			 _nSpeed;
	int 			 _nHp;
	int  			 _nScore;
	eItem		 	 _eState;

private:
	void CheckState();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();

	//!< Setter & Getter
	void SetState(eItem st);

	eItem GetState() { return _eState; }
	int GetSpeed() { return _nSpeed; }
	int GetHp() { return _nHp; }

};

#endif /* CLASS_CCHAR_H_ */
