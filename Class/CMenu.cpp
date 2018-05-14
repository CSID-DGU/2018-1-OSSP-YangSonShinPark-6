/*
 * CMenu.cpp
 *
 *  Created on: 2018. 5. 14.
 *      Author: root
 */

#include "../stdafx.h"

void CMenu::Init(SDL_Surface * screen)
{
	_BackGround.SetImage("UI/Board_Main.PNG", screen);
	_StartButton.SetImage("UI/Btn_Start.png", screen);
	_StartButton.SetPos(25, 600);
}

void CMenu::Update()
{

}

void CMenu::Render()
{
	_BackGround.Render();
	_StartButton.Render();
}

void CMenu::Exit()
{
	_BackGround.Exit();
	_StartButton.Exit();
}
