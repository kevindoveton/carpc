// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassMusicPlayer.h"

int MusicPlayer :: playNewSong(std::string songName, BOOL restart) {
	std::cout << BASS_ChannelIsActive(defaultAudioChannel) << std::endl;

	if (restart == FALSE) {
		// nothing is playing
		if (BASS_ChannelIsActive(defaultAudioChannel) == 0)
		{
			defaultAudioChannel = BASS_StreamCreateFile(FALSE, songName.c_str(), 0, 0, 0);
			BASS_ChannelPlay(defaultAudioChannel, FALSE);
		}

		// currently playing
		else if (BASS_ChannelIsActive(defaultAudioChannel) == 1)
		{
			BASS_ChannelPause(defaultAudioChannel);
		}

		// currently paused
		else if (BASS_ChannelIsActive(defaultAudioChannel) == 3)
		{
			BASS_ChannelPlay(defaultAudioChannel, FALSE);
		}
	}
	else
	{
		BASS_ChannelStop(defaultAudioChannel);
		defaultAudioChannel = BASS_StreamCreateFile(FALSE, songName.c_str(), 0, 0, 0);
		BASS_ChannelPlay(defaultAudioChannel, TRUE);
	}

	//nowPlaying.getSongTags(songName, nowPlaying.title, nowPlaying.album, nowPlaying.artist);

	return BASS_ChannelIsActive(defaultAudioChannel);
}

int MusicPlayer :: pause()
{
	BASS_ChannelPause(defaultAudioChannel);
}

int MusicPlayer :: resume()
{
	BASS_ChannelPlay(defaultAudioChannel, FALSE);
}

int MusicPlayer :: currentBassStatus()
{
	BASS_ChannelIsActive(defaultAudioChannel);
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





