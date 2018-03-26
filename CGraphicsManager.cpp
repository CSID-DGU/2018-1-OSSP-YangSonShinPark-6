#include "stdafx.h"

void CGraphicsManager::InitWindow(const int& width, const int& height)
{
	if (!glfwInit()) Error("glfwInit");

	_Window = glfwCreateWindow(width, height, "Game", NULL, NULL);
	if (!_Window) Error("WindowInit");

	glfwMakeContextCurrent(_Window);

	//!< Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) Error("glewInit");

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, width, 0, height);

	//!< Use AlphaBlend (PNG)
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	srand(time(NULL));

	_cManager.Init();
}

void CGraphicsManager::LoopWindow()
{
	_fTime = (float)timeGetTime();

	while (!glfwWindowShouldClose(_Window))
	{
		float currTime = (float)timeGetTime();
		int	nFrame = 1000 / __D_FRAME_MAX__ - (currTime - _fTime);

		glfwMakeContextCurrent(_Window);

		glClearColor(1, 1, 1, 1);			 //!< while background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glMatrixMode(GL_MODELVIEW);

		//!< Fixed Frame 
		if (nFrame > 0)
			_cManager.Update();

		_cManager.Render();

		glfwSwapBuffers(_Window);
		glfwPollEvents();

		_fTime = currTime;
	}
}

void CGraphicsManager::EndWIndow()
{
	_cManager.Exit();
}

void CGraphicsManager::Error(const std::string& error)
{
	std::cout << error << std::endl;

	exit(1);
}

//!< Emulating Windows to Linux
unsigned int CGraphicsManager::timeGetTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
