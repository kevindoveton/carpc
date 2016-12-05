#include "ClassAudioPlayerQT.h"

AudioPlayerQT :: AudioPlayerQT()
{
	player = new QMediaPlayer;
}

int AudioPlayerQT :: playNewSong(std::string songPath)
{
	QString path = QString::fromStdString(songPath);
	player->setMedia(QUrl::fromLocalFile(path));
	player->setVolume(100);
	play();
	return player->state();
}

int AudioPlayerQT :: play()
{
	player->play();
	return player->state();
}

int AudioPlayerQT :: pause()
{
	player->pause();
	return player->state();
}
