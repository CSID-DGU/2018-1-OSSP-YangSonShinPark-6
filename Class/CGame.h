#ifndef CLASS_CGAME_H_
#define CLASS_CGAME_H_

class CGame : public CSceneManager{

	CChar 					_Char;
	CUI   					_UI;
	//CSound 				_Sound;
	SDL_Thread * 			_Thread;
	SDL_Thread * 			_SocketThread;

	std::vector<CItem*> 	_Items;
	std::map< std::string, std::vector<stItemInfo> > _Patterns;
	std::map<int, std::string> _swap;

	CImageRenderer 		_BackGrounds[3];
	stPos 			 		_BackGroundsPos[3];

	Uint32 				_nItemTime;
	Uint32 				_nLevelTime;
	Uint32 				_nCurrTime;

	bool 					_bInit;

private:
	void CheatCodes();
	void ReadPatterns();
	void Timer(Uint32 dt);
	void Movement();
	void BackGround();
	void MakeItem(int t);
	bool IsCollision(const stPos& target, const stPos& col, const int& tSize, const int& cSize);

public:
	virtual void Init(SDL_Surface * screen);
	virtual void Update(Uint32 dt);
	virtual void Render(Uint32 dt);
	virtual void Exit();
};

//!< for socket
static const int bufsize = 16;
static const char ip[20] = "127.0.0.1";
static int client, server;
static int portNum = 1500;
static int buffer_int[bufsize / 4];
static int clientCount = 1;
static unsigned int time_now;

static struct sockaddr_in server_addr;
static socklen_t size;

#endif /* CLASS_CGAME_H_ */
