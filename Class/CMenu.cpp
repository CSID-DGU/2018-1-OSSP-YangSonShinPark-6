#include "../stdafx.h"

void CMenu::Init(SDL_Surface * screen)
{
	_BackGround.SetImage("UI/Board_Main.PNG", screen);
	_StartButton.SetImage("UI/Btn_Start.png", screen);
	_StartButton.SetPos(25, 600);
	_OptionButton.SetImage("UI/Btn_Option.png", screen);
	_OptionButton.SetPos(380, 500);
}

void CMenu::Update()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if( e.type == SDL_MOUSEBUTTONDOWN )
		MouseEvent();
}

void CMenu::Render()
{
	_BackGround.Render();
	_StartButton.Render();
	_OptionButton.Render();
}

void CMenu::Exit()
{
	_BackGround.Exit();
	_StartButton.Exit();
}

void CMenu::MouseEvent()
{
	SDL_GetMouseState(&_MousePosition._x, &_MousePosition._y);
	if(_MousePosition._x >= 25 && _MousePosition._x < 455 &&
			_MousePosition._y >= 600 && _MousePosition._y < 680 )
		g_eState = __E_GAME__;
}
