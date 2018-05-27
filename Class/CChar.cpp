/*
 * CChar.cpp
 *
 *  Created on: 2018. 5. 19.
 *      Author: root
 */

#include "../stdafx.h"

void CChar::Init(SDL_Surface * screen)
{
	_Image1.SetImage("Object/BG_Tile_7.png",screen);
	_Image2.SetImage("Object/BG_Tile_7.png",screen);
	_Image3.SetImage("Object/BG_Tile_7.png",screen);
	_Image4.SetImage("Object/BG_Tile_7.png",screen);
	_Image5.SetImage("Object/BG_Tile_7.png",screen);
	_Image6.SetImage("Object/BG_Tile_7.png",screen);

	_Image.SetImage("Character/Mole_1.png", screen);
	_Pos._x = 200;
	_Pos._y = 700;
	_nSpeed = 5;
}

void CChar::Update()
{
	_Image1.SetPos(0,0);
	_Image2.SetPos(0,250);
	_Image3.SetPos(250,0);
	_Image4.SetPos(250,250);
	_Image5.SetPos(0,500);
	_Image6.SetPos(250,500);

	_Image.SetPos(_Pos._x, _Pos._y);
}

void CChar::Render()
{
	_Image1.Render();
	_Image2.Render();
	_Image3.Render();
	_Image4.Render();
	_Image5.Render();
	_Image6.Render();

	_Image.Render();
}

void CChar::Exit()
{
	_Image1.Exit();
	_Image2.Exit();
	_Image3.Exit();
	_Image4.Exit();
	_Image5.Exit();
	_Image6.Exit();

	_Image.Exit();
}
