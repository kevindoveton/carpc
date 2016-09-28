#include "ClassAudioPlayerQT.h"

ClassAudioPlayerQT::ClassAudioPlayerQT()
{
	player = new QMediaPlayer(0, QMediaPlayer::StreamPlayback);
}
