#include "../stdafx.h"

void CGame::Init(SDL_Surface * screen)
{
	_Screen = screen;
	_Char.Init(screen);
}

void CGame::Update()
{
	KeyEvent();

	_Char.Update();
	stPos ps;
	if(IsCollision(_Char.GetPos(), ps, 100))
		std::cout << "COL" << std::endl;
}

void CGame::Render()
{
	_Char.Render();
}

void CGame::Exit()
{
	_Char.Exit();
}

void CGame::Movement()
{
	if( _bKeyState[__E_UP__]) _Char.SetPos(_Char.GetPos()._x, _Char.GetPos()._y - 1);
	if( _bKeyState[__E_DOWN__]) _Char.SetPos(_Char.GetPos()._x, _Char.GetPos()._y + 1);
	if( _bKeyState[__E_LEFT__]) _Char.SetPos(_Char.GetPos()._x - 1, _Char.GetPos()._y);
	if( _bKeyState[__E_RIGHT__]) _Char.SetPos(_Char.GetPos()._x + 1, _Char.GetPos()._y);
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
