#include "ClassAudioPlayerQT.h"

AudioPlayerQT :: AudioPlayerQT()
{
	QFile file;
	file.setFileName("/tmp/shairport-sync-pipe");
	file.open(QIODevice::ReadOnly);

	QAudioFormat format;
	format.setSampleRate(44100);
	format.setChannelCount(2);
	format.setCodec("audio/pcm");
	format.setSampleSize(16);
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::SignedInt);

	QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
	if (!info.isFormatSupported(format))
		qWarning() << "Output format not supported";
	audio = new QAudioOutput(format);
	audio->start(&file);
//	player = new QMediaPlayer(0, QMediaPlayer::StreamPlayback);
}
