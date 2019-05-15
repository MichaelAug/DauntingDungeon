#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

class AudioManager {
public:
	AudioManager();
	void PlayMusic();
	void StopMusic();
	void ToggleMusic();
protected:
	Mix_Music* gMusic;
};