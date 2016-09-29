#ifndef CLASSAUDIOPLAYERQT_H
#define CLASSAUDIOPLAYERQT_H

#include <QtMultimedia>
#include <QMediaContent>
#include <QAudioOutput>
#include <QFile>
#include <QIODevice>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
class AudioPlayerQT
{
	public:
		AudioPlayerQT();
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
		QAudioOutput *audio;
};

#endif // CLASSAUDIOPLAYERQT_H
