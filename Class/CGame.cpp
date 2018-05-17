#include "../stdafx.h"

void CGame::Init(SDL_Surface * screen)
{
	_Screen = screen;
	img.SetImage("Character/Mole_1.png", _Screen);
	_Pos._x = 0;
	_Pos._y = 0;
}

void CGame::Update()
{
	KeyEvent();
	img.SetPos(_Pos._x, _Pos._y);
}

void CGame::Render()
{
	img.Render();
}

void CGame::Exit()
{

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
			_Pos._y--;
			break;
		case SDLK_DOWN:
			_Pos._y++;
			break;
		case SDLK_LEFT:
			_Pos._x--;
			break;
		case SDLK_RIGHT:
			_Pos._x++;
			break;
		case SDLK_ESCAPE:
			g_bLoop = false;
		}
	}
}
