#include "../stdafx.h"

int KeyEvent(void * unused);

void CGame::Init(SDL_Surface * screen)
{
	_Screen = screen;
	_nItemTime = 300;
	_nCurrTime = 0;
	_nLevelTime = 0;
	g_nLevel = 1;

	for(int i = 0 ; i < 4 ; i++)
	{
		_BackGrounds[i].SetImage("Object/BG.png",screen);
		_BackGroundsPos[i]._x = 0;
		_BackGroundsPos[i]._y = -120 + (480 * i);
		_BackGrounds[i].SetPos(_BackGroundsPos[i]._x, _BackGroundsPos[i]._y);
	}

	ReadPatterns();

	_Char.Init(_Screen);
	_UI.Init(_Screen);

	_bKey = false;
	_Sound.LoadMedia("resource/Sounds/BGM.mp3", "BGM");
	_Sound.PlayMusic("BGM");
}

void CGame::Update(Uint32 dt)
{
	if(!_bKey)
		_Thread = SDL_CreateThread(KeyEvent, NULL, NULL);
	//Timer(dt);
	//BackGround();
	Movement();
	CheatCodes();

	_UI.Update(dt);
	_Char.Update(dt);

	for(int i = 0 ; i < _Items.size() ; i++)
	{
		_Items[i]->Update(dt);

		if(_Items[i]->GetDead())
		{
			_Items[i]->Exit();
			delete _Items[i];
			_Items.erase(_Items.begin() + i);
		}
		else
		{
			if(_Items[i]->GetPos()._y > 590)
			{
				if(IsCollision(_Char.GetPos(), _Items[i]->GetPos(), 64, 56))
				{
					_Items[i]->SetDead(true);
					_Char.SetState(_Items[i]->GetType());
				}
			}
		}

	}
}

void CGame::Render(Uint32 dt)
{
	for(int i = 0 ; i < 4 ; i++)
		_BackGrounds[i].Render();

	for(int i = 0 ; i < _Items.size() ; i++)
		_Items[i]->Render(dt);

	_Char.Render(dt);
	_UI.Render(dt);
}

void CGame::Exit()
{
	for(int i = 0 ; i < 4 ; i++)
		_BackGrounds[i].Exit();
	_UI.Exit();
	_Char.Exit();
	for(int i = 0 ; i < _Items.size() ; i++)
		delete _Items[i];
}

void CGame::CheatCodes()
{
	if(g_bMake)
	{
		g_bMake = false;
		MakeItem(g_nType);

		_nCurrTime = 0;
		_nItemTime = 350 + rand() % 200;
	}
}

void CGame::ReadPatterns()
{
	std::ifstream pattern("resource/pattern.txt");
	int nums, objs, x, y;
	char c;
	std::string str;
	pattern >> nums;
	for(int i = 0; i < nums; i++)
	{
		pattern >> str >> objs;
		for(int j = 0 ; j < objs ; j++)
		{
			pattern >> x >> y >> c;
			_Patterns[str].push_back(stItemInfo(stPos(x, y),c));
		}
		_swap[i] = str;
	}
}

void CGame::Timer(Uint32 dt)
{
	_nCurrTime += dt;
	_nLevelTime += dt;

	if(_nLevelTime > 20000)
	{
		g_nLevel++;
		_nLevelTime = 0;
	}

	if( _nCurrTime > _nItemTime )
	{
		int t = rand() % _Patterns.size();
		MakeItem(t);
		_nCurrTime = 0;
		_nItemTime = 350 + rand() % 200;
	}

}

void CGame::Movement()
{
	if( g_bKeyState[__E_LEFT__]) _Char.SetPos(_Char.GetPos()._x - (_Char.GetSpeed() + g_nLevel), _Char.GetPos()._y);
	if( g_bKeyState[__E_RIGHT__]) _Char.SetPos(_Char.GetPos()._x + _Char.GetSpeed() + g_nLevel, _Char.GetPos()._y);
}

void CGame::BackGround()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		_BackGroundsPos[i]._y += g_nLevel * 2;
		_BackGrounds[i].SetPos(_BackGroundsPos[i]._x, _BackGroundsPos[i]._y);
		if(_BackGroundsPos[i]._y >= 800)
			_BackGroundsPos[i]._y = -640;
	}
}

void CGame::MakeItem(int t)
{
	for(int i = 0 ; i < _Patterns[_swap[t]].size(); i++)
	{
		CItem* item = new CItem;
		item->Make(_Patterns[_swap[t]][i]);
		item->Init(_Screen);
		_Items.push_back(item);
	}
}

bool CGame::IsCollision(const stPos& target, const stPos& col, const int& tSize, const int& cSize)
{
	if(((target._x >= col._x  && target._x <= col._x + cSize) ||
		(target._x + tSize >= col._x && target._x + tSize <= col._x + cSize)	)&&
		((target._y >= col._y && target._y <= col._y + cSize) ||
		(target._y + tSize >= col._y && target._y + tSize <= col._y + cSize)))
		return true;
	return false;
}

int KeyEvent(void * unused)
{
	while(1)
	{
		SDL_Event e;
		SDL_PollEvent(&e);
		if( e.type == SDL_KEYDOWN )
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				g_bKeyState[__E_UP__] = true;
				break;
			case SDLK_DOWN:
				g_bKeyState[__E_DOWN__] = true;
				break;
			case SDLK_LEFT:
				g_bKeyState[__E_LEFT__] = true;
				break;
			case SDLK_RIGHT:
				g_bKeyState[__E_RIGHT__] = true;
				break;
			case SDLK_ESCAPE:
				g_bLoop = false;
				break;
			case SDLK_0:
				g_nLevel++;
				break;
			case SDLK_1:
				g_bMake = true;
				g_nType = 0;
				break;
			case SDLK_2:
				g_bMake = true;
				g_nType = 1;
				break;
			case SDLK_3:
				g_bMake = true;
				g_nType = 2;
				break;
			case SDLK_4:
				g_bMake = true;
				g_nType = 3;
				break;
			case SDLK_5:
				g_bMake = true;
				g_nType = 0;
				break;
			case SDLK_6:
				g_bMake = true;
				g_nType = 1;
				break;
			}
		}
		else if( e.type == SDL_KEYUP )
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				g_bKeyState[__E_UP__] = false;
				break;
			case SDLK_DOWN:
				g_bKeyState[__E_DOWN__] = false;
				break;
			case SDLK_LEFT:
				g_bKeyState[__E_LEFT__] = false;
			break;
			case SDLK_RIGHT:
				g_bKeyState[__E_RIGHT__] = false;
				break;
			}
		}
	}

	return 0;
}
