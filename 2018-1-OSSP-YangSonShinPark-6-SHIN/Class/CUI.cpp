/*
 * CUI.cpp
 *
 *  Created on: 2018. 5. 27.
 *      Author: root
 */

#include "../stdafx.h"

void CUI::Init(SDL_Surface * screen)
{
	_HPBar.SetImage("UI/UI_HealthBarInner.png", screen);
	_HPBar.SetPos(28, 732);
	_HPBarBG.SetImage("UI/UI_HealthBar.png", screen);
	_HPBarBG.SetPos(0, 730);

}

void CUI::Update(int dt)
{

}

void CUI::Render(int dt)
{
	_HPBarBG.Render();
	_HPBar.Render();
}

void CUI::Exit()
{
	_HPBarBG.Exit();
	_HPBar.Exit();
}
