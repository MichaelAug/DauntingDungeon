#pragma once
#include "SDL.h"
#include "SDL_mixer.h"

class AudioManager {
public:
	AudioManager();
	void PlayMusic();
	void StopMusic();
	void ToggleMusic();
protected:
	Mix_Music* gMusic;
};