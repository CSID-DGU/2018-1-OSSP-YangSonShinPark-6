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

private:
	eItem RandType();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();

	//!< Setter & Getter
	void SetDead(bool dead) { _bDead = dead; }
	eItem GetType() { return _ItemType; }
	bool GetDead() { return _bDead; }
};

#endif /* CLASS_CITEM_H_ */
