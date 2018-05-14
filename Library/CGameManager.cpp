/*
 * CGameManager.cpp
 *
 *  Created on: 2018. 4. 9.
 *      Author: root
 */

#include "../stdafx.h"

void CGameManager::Init(SDL_Surface * screen)
{
	_Screen = screen;
	_Image.SetImage("apple.png", _Screen);
}

void CGameManager::Loop()
{
	_Image.Render(_Screen);
}

void CGameManager::Exit()
{

}
