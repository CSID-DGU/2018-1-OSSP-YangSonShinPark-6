#ifndef CLASS_CGAME_H_
#define CLASS_CGAME_H_

class CGame : public CSceneManager{

	CChar _Char;
	CUI   _UI;
	std::vector<CItem*> _Items;
	SDL_Thread * _Thread;

	bool _bKeyState[__E_KEY_MAX__];

	Uint32 _nItemTime;
	Uint32 _nCurrTime;

private:
	//void KeyEvent();
	void Movement();
	void MakeItem();
	bool IsCollision(const stPos& target, const stPos& col, const int& tSize, const int& cSize);

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(float dt);
	virtual void Render(float dt);
	virtual void Exit();
};

#endif /* CLASS_CGAME_H_ */
