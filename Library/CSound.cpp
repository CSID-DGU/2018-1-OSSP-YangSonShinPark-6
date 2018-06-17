/*
 * CSound.cpp
 *
 *  Created on: 2018. 6. 11.
 *      Author: root
 */

#include "../stdafx.h"

void CSound::LoadMedia(const std::string& path, const std::string& name)
{
	_Sounds[name] = Mix_LoadMUS(path.data());
}

void CSound::PlayMusic(const std::string& name)
{
	if(name == "BGM")
		Mix_PlayMusic(_Sounds[name], -1);
	else
		Mix_PlayMusic(_Sounds[name], 0);
}
