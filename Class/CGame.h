#ifndef CLASS_CGAME_H_
#define CLASS_CGAME_H_

class CGame : public CSceneManager{

	CChar _Char;
	std::vector<CItem*> _Items;

	bool _bKeyState[__E_KEY_MAX__];

private:
	void KeyEvent();
	void Movement();
	void MakeItem();
	bool IsCollision(const stPos& target, const stPos& col, const int& cSize);

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* CLASS_CGAME_H_ */
