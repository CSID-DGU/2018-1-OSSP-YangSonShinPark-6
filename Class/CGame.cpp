#include "../stdafx.h"

void CGame::Init(SDL_Surface * screen)
{
	_Screen = screen;
	img.SetImage("Object/BG_Tile_1.png", _Screen);
}

void CGame::Update()
{

}

void CGame::Render()
{
	img.Render();
}

void CGame::Exit()
{

}
