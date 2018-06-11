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

	_Score.resize(4);
	for(int i = 0 ; i < 4 ; i++)
	{
		CImageRenderer * img = new CImageRenderer[9];
		for(int j = 0 ; j < 9 ; j++)
		{
			std::ostringstream stream;
			stream << j;
			std::string str = "Object/Object_" + stream.str() + ".png";
			img[j].SetImage(str, screen);
			img[j].SetPos(440 - (i * 40), 730);
		}
		_Score.push_back(img);
	}
}

void CUI::Update(int dt)
{
	//_Scores[0] = g_nScore % 10;
	//_Scores[1] = (g_nScore / 10) % 10;
	//_Scores[2] = (g_nScore / 100) % 10;
	//_Scores[3] = (g_nScore / 1000) % 10;
}

void CUI::Render(int dt)
{
	_HPBarBG.Render();
	_HPBar.Render();

//	for(int i = 0 ; i < 4 ; i++)
//		_Score[i][_Scores[i]].Render();
}

void CUI::Exit()
{
	_HPBarBG.Exit();
	_HPBar.Exit();
}
