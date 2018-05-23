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

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};
#endif /* CLASS_COPTION_H_ */
