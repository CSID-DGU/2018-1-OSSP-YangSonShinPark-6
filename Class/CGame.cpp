#include "../stdafx.h"

int KeyEvent(void * unused);

void CGame::Init(SDL_Surface * screen)
{
	_Screen = screen;
	_nItemTime = 700;
	_nCurrTime = 0;
	_Thread = SDL_CreateThread(KeyEvent, NULL, NULL);
	_Char.Init(screen);
	_UI.Init(screen);
}

void CGame::Update(float dt)
{
	_nCurrTime += (int)dt;
	if( _nCurrTime > _nItemTime )
	{
		MakeItem();
		_nCurrTime = 0;
		_nItemTime = 650 + rand() % 1000;
	}

	_UI.Update();
	Movement();
	_Char.Update();

	for(int i = 0 ; i < _Items.size() ; i++)
	{
		_Items[i]->Update();
		if(IsCollision(_Char.GetPos(), _Items[i]->GetPos(), 64, 32))
		{
			_Items[i]->SetDead(true);
			_Char.SetState(_Items[i]->GetType());
		}

		if(_Items[i]->GetDead())
		{
			_Items[i]->Exit();
			delete _Items[i];
			_Items.erase(_Items.begin() + i);
		}
	}
}

void CGame::Render(float dt)
{
	_UI.Render();
	_Char.Render();
	for(int i = 0 ; i < _Items.size() ; i++)
		_Items[i]->Render();
}

void CGame::Exit()
{
	_UI.Update();
	_Char.Exit();
	for(int i = 0 ; i < _Items.size() ; i++)
		delete _Items[i];
}

void CGame::Movement()
{
	if( g_bKeyState[__E_LEFT__]) _Char.SetPos(_Char.GetPos()._x - _Char.GetSpeed(), _Char.GetPos()._y);
	if( g_bKeyState[__E_RIGHT__]) _Char.SetPos(_Char.GetPos()._x + _Char.GetSpeed(), _Char.GetPos()._y);
}

void CGame::MakeItem()
{
	CItem* item = new CItem;
	item->Init(_Screen);
	_Items.push_back(item);
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
