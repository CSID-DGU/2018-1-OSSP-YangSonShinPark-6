/*
 * CSound.h
 *
 *  Created on: 2018. 6. 11.
 *      Author: root
 */

#ifndef LIBRARY_CSOUND_H_
#define LIBRARY_CSOUND_H_

class CSound {
	std::map<std::string, Mix_Music*> _Sounds;
public:
	void LoadMedia(const std::string& path, const std::string& name);
	void PlayMusic(const std::string& name);
};

#endif /* LIBRARY_CSOUND_H_ */
