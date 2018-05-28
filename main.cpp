#include "stdafx.h"

//!< global variables
int g_eState;
int g_nLevel;
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
