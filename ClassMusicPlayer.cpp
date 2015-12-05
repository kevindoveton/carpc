// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassMusicPlayer.h"

int playNewSong(std::string songName, HSTREAM& handle, BOOL restart) {
	std::cout << BASS_ChannelIsActive(handle) << std::endl;

	if (restart == FALSE) {
		// nothing is playing
		if (BASS_ChannelIsActive(handle) == 0)
		{
			handle = BASS_StreamCreateFile(FALSE, songName.c_str(), 0, 0, 0);
			BASS_ChannelPlay(handle, FALSE);
		}

		// currently playing
		else if (BASS_ChannelIsActive(handle) == 1)
		{
			BASS_ChannelPause(handle);
		}

		// currently paused
		else if (BASS_ChannelIsActive(handle) == 3)
		{
			BASS_ChannelPlay(handle, FALSE);
		}
	}
	else
	{
		BASS_ChannelStop(handle);
		handle = BASS_StreamCreateFile(FALSE, songName.c_str(), 0, 0, 0);
		BASS_ChannelPlay(handle, TRUE);
	}

	nowPlaying.getSongTags(songName, nowPlaying.title, nowPlaying.album, nowPlaying.artist);

	return BASS_ChannelIsActive(handle);
}

int pause(HSTREAM& audioChannel = defaultAudioChannel)
{
	BASS_ChannelPause(audioChannel);
}

int resume(HSTREAM& audioChannel = defaultAudioChannel)
{

}

int getCurrentBassStatus()
{
	return currentBassStatus;
}

int setCurrentBassStatus(int status)
{
	currentBassStatus = status;
	return currentBassStatus;
}

int getOldBassStatus()
{
	return oldBassStatus;
}

int setOldBassStatus(int status)
{
	oldBassStatus = status;
	return oldBassStatus;
}





