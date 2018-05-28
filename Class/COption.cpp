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
}

void COption::Update(int dt)
{

}

void COption::Render(int dt)
{
	_Background.Render();
}

void COption::Exit()
{

}
