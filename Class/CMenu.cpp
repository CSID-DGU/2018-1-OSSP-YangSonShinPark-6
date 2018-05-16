#include "../stdafx.h"

void CMenu::Init(SDL_Surface * screen)
{
	_BackGround.SetImage("UI/Board_Main.PNG", screen);
	_StartButton.SetImage("UI/Btn_Start.png", screen);
	_StartButton.SetPos(25, 600);
	_OptionButton.SetImage("UI/Btn_Option.png", screen);
	_OptionButton.SetPos(380, 500);
}

void CMenu::Update()
{

}

void CMenu::Render()
{
	_BackGround.Render();
	_StartButton.Render();
	_OptionButton.Render();
}

void CMenu::Exit()
{
	_BackGround.Exit();
	_StartButton.Exit();
}
