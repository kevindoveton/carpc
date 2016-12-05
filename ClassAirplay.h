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
class Airplay : QObject
{
	Q_OBJECT
	public:
		Airplay();
		void start();
		void stop();

	protected slots:
		void handleStateChange(QAudio::State state);

	protected:
		QAudioDeviceInfo deviceInfo;
		QFile file;
		QAudioOutput *audio;
};

#endif // CLASSAUDIOPLAYERQT_H
