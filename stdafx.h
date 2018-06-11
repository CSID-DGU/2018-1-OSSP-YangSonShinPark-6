/*
 * stdafx.h
 *
 *  Created on: 2018. 4. 5.
 *      Author: Son
 *      main Header file,
 *      include all header in here
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL.h>

#include "MY_DEFINE.h"

#include "Library/CImageRenderer.h"
#include "Library/CAnimationRenderer.h"
#include "Library/CSound.h"

//!< Objects
#include "Library/CObject.h"
#include "Class/CChar.h"
#include "Class/CItem.h"
#include "Class/CUI.h"

//!< Scenes
#include "Library/CSceneManager.h"
#include "Class/CMenu.h"
#include "Class/CGame.h"
#include "Class/COption.h"

#include "Library/CGameManager.h"
#include "Library/CGraphicsManager.h"
