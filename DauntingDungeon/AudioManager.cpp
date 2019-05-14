#include "AudioManager.h"
#include <stdio.h>

AudioManager::AudioManager()
{
	gMusic = NULL;

	//Load Music
	gMusic = Mix_LoadMUS("DauntingDungeon/Assets/Music/ShotsFired.mp3");
	if (gMusic == NULL) {
		printf("Failed to load music!%s\n", Mix_GetError());
	}
}

void AudioManager::PlayMusic()
{
	Mix_PlayMusic(gMusic, -1);
}

void AudioManager::StopMusic()
{
	Mix_HaltMusic();
}

void AudioManager::ToggleMusic()
{

	if (Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
	}
	else {
		Mix_PauseMusic();
	}
}
