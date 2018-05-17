#ifndef CLASS_CGAME_H_
#define CLASS_CGAME_H_

class CGame : public CSceneManager{

	CImageRenderer img;
	stPos _Pos;
	bool _bKeyState[__E_KEY_MAX__];

private:
	void KeyEvent();

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* CLASS_CGAME_H_ */
