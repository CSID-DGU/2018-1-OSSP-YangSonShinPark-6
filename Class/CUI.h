/*
 * CUI.h
 *
 *  Created on: 2018. 5. 27.
 *      Author: root
 */

#ifndef CLASS_CUI_H_
#define CLASS_CUI_H_

class CUI : public CObject{

	CImageRenderer _HPBarBG;
	CImageRenderer _HPbars[9];
	int _Hp;
public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();

	void SetHp(int h) { _Hp = h; }
};

#endif /* CLASS_CUI_H_ */
