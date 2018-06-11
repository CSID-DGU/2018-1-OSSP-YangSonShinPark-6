/*
 * CMusicRender.h
 *
 *  Created on: 2018. 6. 10.
 *      Author: root
 */

#ifndef CMUSICRENDER_H_
#define CMUSICRENDER_H

bool MusicRender::Init()
{
	if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
		{
				std::cout << "SDL could not initialize! SDL_ERROR " << SDL_GetError() << std::endl;
				return false;
		}

	//Initialize SDL_mixer
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
		{
				printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				return false;

		}
	else if(!loadMedia()) return false;

}


bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load music
	BGM = Mix_LoadMUS( "BGM.mp3" );
	if( BGM == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	//Load sound effects
	LeftHook = Mix_LoadWAV( "LeftHook.wav" );
	if( LeftHook == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	PowerUp = Mix_LoadWAV( "PowerUp.wav" );
	if( PowerUp == NULL )
	{
		printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	return success;
}

void CMusicRender::palyMusic(int input)
{
	switch(input)
	{
	//Play sound effect
	case 1:
	Mix_PlayChannel( -1, PowerUp, 0 );
	break;

	//Play scratch sound effect
	case 2:
	Mix_PlayChannel( -1, LeftHook, 0 );
	break;

	case 3:
	//If there is no music playing
	if( Mix_PlayingMusic() == 0 )
	{
	   //Play the music
	   Mix_PlayMusic( BGM, -1 );
	}

    //If music is being played
	else
	{
	    //If the music is paused
		if( Mix_PausedMusic() == 1 )
	    {
	       //Resume the music
	       Mix_ResumeMusic();
	     }
	     //If the music is playing
	     else
	     {
            //Pause the music
	        Mix_PauseMusic();
	     }
	}
	break;

	case 0:
	//Stop the music
	Mix_HaltMusic();
	break;
	}
}

void CMusicRender::Exit()
{
	//Free the sound effects
	Mix_FreeChunk( LeftHook );
	Mix_FreeChunk( PowerUp );

	LeftHook = NULL;
	PowerUp = NULL;

	//Free the music
	Mix_FreeMusic( BGM );
	BGM = NULL;

	Mix_Quit();

}



#endif /* CMUSICRENDER_H_ */
