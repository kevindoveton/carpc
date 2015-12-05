// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------


class MusicPlayer
{
	public:
		int playNewSong(std::string songName, BOOL restart, HSTREAM& audioChannel = defaultAudioChannel);
		// play a new song
		// requires path to song including extension
		// returns current status

		int pause(HSTREAM& audioChannel = defaultAudioChannel);
		int play();

		int getCurrentBassStatus();
		int setCurrentBassStatus(int status);

		int getOldBassStatus();
		int setOldBassStatus(int status);

	private:
		HSTREAM defaultAudioChannel; // bass handle
		int currentBassStatus; // used in run loop
		int oldBassStatus; // used in run loop

};
