// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include <sstream>								// String Streams - STD :: stringstream
#include "libraries/bass/bass.h"				// Bass
#include <iostream>								// General IO (cout/cin)

class MusicPlayer
{
	public:
				int playNewSong(std::string songName, BOOL restart);
		// play a new song
		// requires path to song including extension
		// returns current status

		int pause();
		int resume();

		int currentBassStatus();

		int getOldBassStatus();
		int setOldBassStatus(int status);

	private:
		HSTREAM defaultAudioChannel; // bass handle
		int varCurrentBassStatus; // used in run loop
		int varOldBassStatus; // used in run loop

};
