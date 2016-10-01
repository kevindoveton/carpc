#include "ClassAudioPlayerQT.h"

AudioPlayerQT :: AudioPlayerQT()
{
	deviceInfo = QAudioDeviceInfo::defaultOutputDevice();
	qDebug() << "file";
	file.setFileName("/tmp/shairport-sync-pipe");
	file.open(QIODevice::ReadOnly);

	qDebug () << "opened";
	QAudioFormat format;
	format.setSampleRate(44100);
	format.setChannelCount(2);
	format.setCodec("audio/pcm");
	format.setSampleSize(16);
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::SignedInt);
	qDebug() << "open audio";
	QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
	if (!info.isFormatSupported(format))
		qWarning() << "Output format not supported";
	qDebug() << "opened";
	qDebug() << "new device";
	audio = new QAudioOutput(deviceInfo, format, this);
//	audio->setBufferSize(44100);
	audio->setNotifyInterval(50);
	connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChange(QAudio::State)));
	qDebug() << "about to start";
	audio->start(&file);
	qDebug() << "started";
}

void AudioPlayerQT :: handleStateChange(QAudio::State state)
{
	qDebug() << state;
	switch (state)
	{
		case QAudio::ActiveState:
			break;

		case QAudio::SuspendedState:
			qDebug() << "suspended";
			break;

		case QAudio::IdleState:
			audio->stop();
			file.close();
//			qDebug() << "stopped audio";
			delete audio;
			break;

		case QAudio::StoppedState:
			if (audio->error() != QAudio::NoError)
				qWarning() << "Error" + audio->error();
			break;
	}
}
