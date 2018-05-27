#include "../stdafx.h"

void CMenu::Init(SDL_Surface * screen)
{
	_TitlePosition._x = 120;
	_TitlePosition._y = 100;
	_TitleGround.SetImage("UI/UI_Title.PNG", screen);

	_BackGround.SetImage("UI/Board_Main.PNG", screen);
	_StartButton.SetImage("UI/Btn_Start.png", screen);
	_StartButton.SetPos(25, 600);
	_OptionButton.SetImage("UI/Btn_Option.png", screen);
	_OptionButton.SetPos(380, 500);
}

void CMenu::Move_Title()
{
	if( _bUp ) _TitlePosition._y -= 1;
	else _TitlePosition._y += 1;

	if(_TitlePosition._y <= 80) _bUp = false;
	else if(_TitlePosition._y >= 120) _bUp = true;
}

void CMenu::Update(float dt)
{
	Move_Title();

	_TitleGround.SetPos(_TitlePosition._x ,_TitlePosition._y);

	SDL_Event e;
	SDL_PollEvent(&e);
	if( e.type == SDL_MOUSEBUTTONDOWN )
		MouseEvent();
	else if( e.type == SDL_KEYDOWN )
		if(e.key.keysym.sym == SDLK_ESCAPE)
			g_bLoop = false;
}

void CMenu::Render(float dt)
{
	_BackGround.Render();
	_TitleGround.Render();
	_StartButton.Render();
	_OptionButton.Render();
}

void CMenu::Exit()
{
	_TitleGround.Exit();
	_BackGround.Exit();
	_StartButton.Exit();
}

void CMenu::MouseEvent()
{
	SDL_GetMouseState(&_MousePosition._x, &_MousePosition._y);
	if(_MousePosition._x >= 25 && _MousePosition._x < 455 &&
			_MousePosition._y >= 600 && _MousePosition._y < 680 )
		g_eState = __E_GAME__;
	if(_MousePosition._x >= 380 && _MousePosition._x < 460 &&
			_MousePosition._y >= 500 && _MousePosition._y < 580 )
		g_eState = __E_OPTION__;
}
