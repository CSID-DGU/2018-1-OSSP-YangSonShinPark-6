#include "stdafx.h"

//!< global variables
int g_eState;

int main(int argc, char * args[])
{
	CGraphicsManager _Graphics;
	_Graphics.Init();
	_Graphics.Loop();

	_Graphics.Exit();
	return 0;
}
