#pragma once

class CGraphicsManager
{
	float				_fTime;

	GLFWwindow * _Window;
	CManager	 _cManager;


	void Error(const std::string& error);
	unsigned int timeGetTime();
public:

	void InitWindow();
	void LoopWindow();
	void EndWIndow();
};
