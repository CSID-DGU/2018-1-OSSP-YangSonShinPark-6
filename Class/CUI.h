/*
 * CUI.h
 *
 *  Created on: 2018. 5. 27.
 *      Author: root
 */

#ifndef CLASS_CUI_H_
#define CLASS_CUI_H_

class CUI : public CObject{

	CImageRenderer _HPBar;
	CImageRenderer _HPBarBG;

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();
};

#endif /* CLASS_CUI_H_ */
