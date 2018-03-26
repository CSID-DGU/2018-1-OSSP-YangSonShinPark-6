#pragma once

class CAniRenderer : public CImageRenderer
{
	std::vector<IplImage*> 		_vAni;

	int								_nMax;
	int								_nIdx;
	int								_nAniTime; //!< millisec

	float							_fFrameTime;

public:
	
	void InitAnimation(const int& xpos, const int& ypos, const int& imagemax, const int& time);
	void SetImage(const std::string& path, const int& width, const int& height);

	virtual void Draw();
	virtual void Exit();
};
