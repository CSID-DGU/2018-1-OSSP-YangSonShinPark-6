/*
 * CObject.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: root
 */

#ifndef LIBRARY_COBJECT_H_
#define LIBRARY_COBJECT_H_

class CObject {

public:
	stPos 	_Pos;

	virtual void Init(SDL_Surface * screen) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

	//!< SETTER & GETTER
	void SetPos(const int& x, const int& y) { _Pos._x = x; _Pos._y = y; }
	void SetPos(const stPos& pos) { _Pos = pos; }
	stPos GetPos() { return _Pos; }
};

#endif /* LIBRARY_COBJECT_H_ */
