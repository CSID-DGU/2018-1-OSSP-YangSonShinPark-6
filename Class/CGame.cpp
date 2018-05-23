#include "../stdafx.h"

void CGame::Init(SDL_Surface * screen)
{
	_Screen = screen;
	_Char.Init(screen);
	for(int i = 0 ; i < 10 ; i++)
		MakeItem();
}

void CGame::Update()
{
	__D_TIME__ tick = SDL_GetTicks();
	KeyEvent();

	_Char.Update();
	for(int i = 0 ; i < _Items.size() ; i++)
	{
		_Items[i]->Update();
		if(IsCollision(_Char.GetPos(), _Items[i]->GetPos(), 128))
			std::cout << "COL" << std::endl;
	}
}

void CGame::Render()
{
	_Char.Render();
	for(int i = 0 ; i < _Items.size() ; i++)
		_Items[i]->Render();
}

void CGame::Exit()
{
	_Char.Exit();
	for(int i = 0 ; i < _Items.size() ; i++)
		delete _Items[i];
}

void CGame::Movement()
{
	if( _bKeyState[__E_UP__]) _Char.SetPos(_Char.GetPos()._x, _Char.GetPos()._y - 2);
	if( _bKeyState[__E_DOWN__]) _Char.SetPos(_Char.GetPos()._x, _Char.GetPos()._y + 2);
	if( _bKeyState[__E_LEFT__]) _Char.SetPos(_Char.GetPos()._x - 2, _Char.GetPos()._y);
	if( _bKeyState[__E_RIGHT__]) _Char.SetPos(_Char.GetPos()._x + 2, _Char.GetPos()._y);
}

void CGame::MakeItem()
{
	CItem* item = new CItem;
	item->Init(_Screen);
	_Items.push_back(item);
}

void CGame::KeyEvent()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if( e.type == SDL_KEYDOWN )
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			_bKeyState[__E_UP__] = true;
			break;
		case SDLK_DOWN:
			_bKeyState[__E_DOWN__] = true;
			break;
		case SDLK_LEFT:
			_bKeyState[__E_LEFT__] = true;
			break;
		case SDLK_RIGHT:
			_bKeyState[__E_RIGHT__] = true;
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
			_bKeyState[__E_UP__] = false;
			break;
		case SDLK_DOWN:
			_bKeyState[__E_DOWN__] = false;
			break;
		case SDLK_LEFT:
			_bKeyState[__E_LEFT__] = false;
			break;
		case SDLK_RIGHT:
			_bKeyState[__E_RIGHT__] = false;
			break;
		}
	}

	Movement();
}

bool CGame::IsCollision(const stPos& target, const stPos& col, const int& cSize)
{
	if((target._x >= col._x  && target._x <= col._x + cSize) &&
			(target._y >= col._y && target._y <= col._y + cSize) )
		return true;
	return false;
}
