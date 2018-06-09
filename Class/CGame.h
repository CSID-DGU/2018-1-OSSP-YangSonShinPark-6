#ifndef CLASS_CGAME_H_
#define CLASS_CGAME_H_

class CGame : public CSceneManager{

	CChar _Char;
	CUI   _UI;
	std::vector<CItem*> _Items;
	std::map< std::string, std::vector<stItemInfo> > _Patterns;
	std::map<int, std::string> _swap;
	SDL_Thread * _Thread;

	CImageRenderer _BackGrounds[12];
	stPos 			 _BackGroundsPos[12];

	Uint32 _nItemTime;
	Uint32 _nLevelTime;
	Uint32 _nCurrTime;

private:
	void CheatCodes();
	void ReadPatterns();
	void Timer(int dt);
	void Movement();
	void BackGround();
	void MakeItem(int t);
	bool IsCollision(const stPos& target, const stPos& col, const int& tSize, const int& cSize);

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(int dt);
	virtual void Render(int dt);
	virtual void Exit();
};

#endif /* CLASS_CGAME_H_ */
