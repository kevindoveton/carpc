#include "ClassAudioPlayerQT.h"

AudioPlayerQT :: AudioPlayerQT()
{
	deviceInfo = QAudioDeviceInfo::defaultOutputDevice();
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

void AudioPlayerQT :: startAirplay()
{
	// read the pipe
	file.setFileName("/tmp/shairport-sync-pipe");
	file.open(QIODevice::ReadOnly);



	// set the audio format
	// https://github.com/mikebrady/shairport-sync/issues/126
	// Playing raw data 'stdin' : Signed 16 bit Little Endian, Rate 44100 Hz, Stereo
	QAudioFormat format;
	format.setSampleRate(44100); // rate
	format.setChannelCount(2); // stereo
	format.setCodec("audio/pcm"); // raw
	format.setSampleSize(16); // 16 bit
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::SignedInt);

	// check format is supported
	if (!deviceInfo.isFormatSupported(format))
		qWarning() << "Output format not supported";

	audio = new QAudioOutput(deviceInfo, format, this);
	connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChange(QAudio::State)));
	audio->start(&file);
}
