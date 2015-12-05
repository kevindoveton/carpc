// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassMusicPlayer.h"

int MusicPlayer :: playNewSong(std::string songPath) 
{	
	BASS_ChannelStop(defaultAudioChannel);
	defaultAudioChannel = BASS_StreamCreateFile(FALSE, songPath.c_str(), 0, 0, 0);
	BASS_ChannelPlay(defaultAudioChannel, TRUE);

	return BASS_ChannelIsActive(defaultAudioChannel);
}

int MusicPlayer :: pause()
{
	BASS_ChannelPause(defaultAudioChannel);
	std::cout << "Pause";
	return currentBassStatus;
}

int MusicPlayer :: resume()
{
	BASS_ChannelPlay(defaultAudioChannel, FALSE);
	std::cout << "Play";
	return currentBassStatus;
}

int MusicPlayer :: stop()
{
	BASS_ChannelStop(defaultAudioChannel);
	return currentBassStatus;
}

int MusicPlayer :: currentBassStatus()
{
	return BASS_ChannelIsActive(defaultAudioChannel);
}

int MusicPlayer :: getOldBassStatus()
{
	return varOldBassStatus;
}

int MusicPlayer :: setOldBassStatus(int status)
{
	varOldBassStatus = status;
	return varOldBassStatus;
}





