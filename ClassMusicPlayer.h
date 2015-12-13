// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

// Bass Statuses
// 0: Stopped (or invalid handle)
// 1: Playing
// 2: Stalled (not enough data//buffering)
// 3: Paused


// #include <sstream>								// String Streams - STD :: stringstream
#include "libraries/bass/bass.h"				// Bass
#include <iostream>								// General IO (cout/cin)

class MusicPlayer
{
	public:
		int playNewSong(std::string songPath);
		// play a new song
		// requires path to song including extension
		// returns current status

		int pause();
		// Pause currently playing song
		// Alias for BASS_ChannelPause(handle)
		// Returns current status

		int resume();
		// Resume current song
		// Alias for BASS_ChannelPlay(handle, FALSE)
		// Returns current status

		int stop();
		// Stop current song
		// Alias for BASS_ChannelPause(handle)
		// Returns current status

		int currentBassStatus();
		// return the current status
		// Alias for BASS_ChannelIsActive(handle);

		int getOldBassStatus();
		// Returns varOldBassStatus

		int setOldBassStatus(int status);
		// Sets varOldBassStatus

		bool playing();
		// check if song is active

	private:
		HSTREAM defaultAudioChannel; // bass handle
		int varCurrentBassStatus; // used in run loop
		int varOldBassStatus; // used in run loop
		bool _playing = false;

};
