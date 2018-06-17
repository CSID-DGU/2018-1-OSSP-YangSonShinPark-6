#include "stdafx.h"

//!< global variables
int g_eState;
int g_nLevel;
int g_nBoost = 1;
int g_nType = 0;
bool g_bMulti = false;
bool g_bMake = false;
bool g_bSound = true;
bool g_bLoop = true;
bool g_bKeyState[__E_KEY_MAX__];

int main(int argc, char * args[])
{
	CGraphicsManager _Graphics;
	_Graphics.Init();
	_Graphics.Loop();

	_Graphics.Exit();
	return 0;
}
