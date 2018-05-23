/*
 * CItem.h
 *
 *  Created on: 2018. 5. 23.
 *      Author: root
 */

#ifndef CLASS_CITEM_H_
#define CLASS_CITEM_H_

class CItem : public CObject {
	std::vector<CImageRenderer> _Items;
	eItem _ItemType;
	bool _bDead;

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* CLASS_CITEM_H_ */
