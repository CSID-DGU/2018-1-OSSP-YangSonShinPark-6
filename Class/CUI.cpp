/*
 * CUI.cpp
 *
 *  Created on: 2018. 5. 27.
 *      Author: root
 */

#include "../stdafx.h"

void CUI::Init(SDL_Surface * screen)
{
	_Hp = 8;
	_HPBarBG.SetImage("UI/UI_HealthBar.png", screen);
	_HPBarBG.SetPos(0, 730);

	_HPbars[0].SetImage("UI/inner_8.png", screen);
	_HPbars[1].SetImage("UI/inner_7.png", screen);
	_HPbars[2].SetImage("UI/inner_6.png", screen);
	_HPbars[3].SetImage("UI/inner_5.png", screen);
	_HPbars[4].SetImage("UI/inner_4.png", screen);
	_HPbars[5].SetImage("UI/inner_3.png", screen);
	_HPbars[6].SetImage("UI/inner_2.png", screen);
	_HPbars[7].SetImage("UI/inner_1.png", screen);
	_HPbars[8].SetImage("UI/inner_0.png", screen);
	for(int i = 8 ; i >= 0 ; i--)
		_HPbars[i].SetPos(28, 734);
}

void CUI::Update(int dt)
{

}

void CUI::Render(int dt)
{
	_HPBarBG.Render();
	_HPbars[_Hp].Render();
}

void CUI::Exit()
{
	_HPBarBG.Exit();
}
