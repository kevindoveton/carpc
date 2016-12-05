#ifndef CLASSAUDIOPLAYERQT_H
#define CLASSAUDIOPLAYERQT_H

#include <QtMultimedia>
#include <QMediaPlayer>
#include <QDebug>
#include <QObject>
class AudioPlayerQT : QObject
{
	Q_OBJECT
	public:
		AudioPlayerQT();
		int playNewSong(std::string songPath);
		// play a new song
		// requires path to song including extension
		// returns current status

		int pause();
		// Pause currently playing song
		// Returns current status

		int resume();
		// Resume current song
		// Returns current status

		int stop();
		// Stop current song
		// Returns current status

		int play();


	protected slots:

	protected:
		QMediaPlayer *player;
};

#endif // CLASSAUDIOPLAYERQT_H
