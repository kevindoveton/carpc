#ifndef CLASSAUDIOPLAYERQT_H
#define CLASSAUDIOPLAYERQT_H

#include <QtMultimedia>
#include <QMediaContent>

class ClassAudioPlayerQT
{
	public:
		ClassAudioPlayerQT();
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

	protected:
		QMediaPlayer *player;
		QMediaContent mediaContent;
};

#endif // CLASSAUDIOPLAYERQT_H
