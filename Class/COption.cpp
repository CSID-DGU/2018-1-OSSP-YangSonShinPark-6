/*
 * COption.cpp
 *
 *  Created on: 2018. 5. 22.
 *      Author: root
 */

#include "../stdafx.h"

void COption::Init(SDL_Surface * screen)
{
	_Background.SetImage("UI/Board_Option.png", screen);
	_Sound_IMG.SetImage("UI/Sound.png", screen);
	_Sound_IMG.SetPos(200, 290);
	_ON_Btn.SetImage("UI/Btn_On.png", screen);
	_ON_Btn.SetPos(135, 350);
	_OFF_Btn.SetImage("UI/Btn_Off.png", screen);
	_OFF_Btn.SetPos(285,350);
	_Back_Btn.SetImage("UI/Btn_Back.png", screen);
	_Back_Btn.SetPos(300, 600);

	_Choose_Btn.SetImage("UI/Choose.png",screen);
	_Choose_Btn.SetPos(150,340);

}

void COption::Update(Uint32 dt)
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if( e.type == SDL_MOUSEBUTTONDOWN )
		MouseEvent();

	if(g_bSound)
		_Choose_Btn.SetPos(150,330);
	else
		_Choose_Btn.SetPos(300,330);
}

void COption::Render(Uint32 dt)
{
	_Background.Render();
	_Sound_IMG.Render();
	_ON_Btn.Render();
	_OFF_Btn.Render();
	_Back_Btn.Render();
	_Choose_Btn.Render();
}

void COption::Exit()
{
	_Background.Exit();
	_Sound_IMG.Exit();
	_ON_Btn.Exit();
	_OFF_Btn.Exit();
	_Back_Btn.Exit();
	_Choose_Btn.Exit();

}

void COption::MouseEvent()
{
	SDL_GetMouseState(&_MousePosition._x, &_MousePosition._y);
	if(_MousePosition._x >= 300 && _MousePosition._x < 380 &&
				_MousePosition._y >= 600 && _MousePosition._y < 680 )
		g_eState = __E_MENU__;
	if(_MousePosition._x >= 135 && _MousePosition._x < 215 &&
					_MousePosition._y >= 350 && _MousePosition._y < 430 )
		g_bSound = true;
	if(_MousePosition._x >= 285 && _MousePosition._x < 365 &&
						_MousePosition._y >= 350 && _MousePosition._y < 430 )
		g_bSound = false; _Choose_Btn.SetPos(300,330);

}
