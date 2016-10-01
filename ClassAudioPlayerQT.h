#ifndef CLASSAUDIOPLAYERQT_H
#define CLASSAUDIOPLAYERQT_H

#include <QtMultimedia>
#include <QMediaContent>
#include <QAudioOutput>
#include <QFile>
#include <QIODevice>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QDebug>
#include <QObject>
class AudioPlayerQT : QObject
{
	Q_OBJECT
	public:
		AudioPlayerQT();
//		int playNewSong(std::string songPath);
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
	protected slots:
		void handleStateChange(QAudio::State state);

	protected:
		QAudioDeviceInfo deviceInfo;
		QFile file;
		QAudioOutput *audio;
};

#endif // CLASSAUDIOPLAYERQT_H
