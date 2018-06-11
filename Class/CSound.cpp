/*
 * CMusicRender.cpp
 *
 *  Created on: 2018. 6. 10.
 *      Author: root
 */


#ifndef LIBRARY_CGAMEMANAGER_H_
#define LIBRARY_CGAMEMANAGER_H_

class CMusicRender {

	//The music that will be played
	Mix_Music *BGM;

	//The sound effects that will be used
	Mix_Chunk *LeftHook;
	Mix_Chunk *PowerUp;

public:
	bool Init();
	bool loadMedia();
	void playMusic(int input);
	void Exit();
};

#endif /* LIBRARY_CGAMEMANAGER_H_ */
