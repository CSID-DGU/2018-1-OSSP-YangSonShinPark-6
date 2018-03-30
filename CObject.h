#pragma once

class CObject
{
protected:
	int							_nType = 0; //!< ObjectType
	int							_nDir; //!< ObjectDirection
	int							_nState; //!<ObjectState_ENUM
	int							_nBoxSize; //!< BoundingBoxSize

	float						_fVelocity;

	stPos						_stPos; //!< ObjectPosition

	std::vector<CImageRenderer*>	 _vImage; //!< Object ImgVector

public:
	//!< public call
	virtual void Init() {}; //!< Initializer, Make Object
	virtual void Update(); //!< Update All Object
	virtual void Render(); //!< Draw Object Img
	virtual void Exit(); //!< OutCall, Delete Object

						 //!< setter
	void SetPosition(const float& xpos, const float& ypos)
	{
		_stPos._xPos = xpos; _stPos._yPos = ypos;
	}
	void SetDirection(const eDir& dir) { _nDir = dir; }
	void SetState(const int& state) { _nState = state; }

	//!< getter
	stPos GetPosition() { return _stPos; }
	int GetDirection() { return _nDir; }
	int GetType() { return _nType; }
	int GetState() { return _nState; }
	int GetSize() { return _nBoxSize; }
};
