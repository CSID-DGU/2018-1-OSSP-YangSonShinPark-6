#include "stdafx.h"

<<<<<<< HEAD
int main()
{
	CGraphicsManager _cGraphics;

	_cGraphics.InitWindow(__D_SCREEN_WIDTH__, __D_SCREEN_HEIGHT__);

	_cGraphics.LoopWindow();

	_cGraphics.EndWIndow();

=======
int main(int argc, char * args[])
{
	CGraphicsManager _Graphics;
	_Graphics.Init();
	_Graphics.Loop();

	_Graphics.Exit();
>>>>>>> 9bd18a74282252446100ab7333680c22d7351b43
	return 0;
}
