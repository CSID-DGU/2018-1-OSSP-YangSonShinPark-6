/*
 * CUI.h
 *
 *  Created on: 2018. 5. 27.
 *      Author: root
 */

#ifndef CLASS_CUI_H_
#define CLASS_CUI_H_

class CUI : public CObject{
	CImageRenderer _BackGrounds[12];
	stPos 			 _BackGroundsPos[12];

	int 			 _nScrollSpeed;
public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* CLASS_CUI_H_ */
