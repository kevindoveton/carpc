#include "mainwindow.h"


HSTREAM audioChannel; // bass handle

QStringList artists;
std::vector<SongData> musicDB;

std::vector<SongData> currentPlaylist;
int currentView = 1; // start up in artist mode
song nowPlaying;
SongData currentSong;
QStandardItemModel* model;
std::string DBPATH = "resources/music/musicLibrary.sqlite3";

int currentBassStatus; // used in run loop
int oldBassStatus; // used in run loop

MusicDB musicDB;

int artistIDCur;
int albumIDCur;
int songIDCur;


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	//  Set home frame for start up
	selectedFrame(0);

	hideMusicButtons();

	// hide all selected tab labels then select home
	selectedButton(0);

	nowPlaying.playing = false;

	// labels
	setSongTags("", "", "");
	ui->labelTime->setText(getCurrentTime().c_str());

	// Create Song Model
	model = new QStandardItemModel;
	musicDB.getAllArtists(model); // set artist
	ui->listviewMusic->setModel(model);
	ui->listviewMusic->setItemDelegate(new listViewMusicDelegate);
	//	ui->listviewMusic->setAlternatingRowColors(true);


	// Run Loop
	// this loop will run once every second
	QTimer* runLoopTimer = new QTimer(this);
	connect(runLoopTimer, SIGNAL(timeout()), this, SLOT(runLoop()));
	runLoopTimer->start(1000); // 1000ms = 1 seconds


	// Set window to full screens
	QMainWindow::showFullScreen();

	std :: cout << "started"
				<< std :: endl;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::runLoop()
{
	//	std::cout << "runLoop timed out " << std::endl;


	// TIME SECTION
	ui->labelTime->setText(getCurrentTime().c_str()); // set the time



	// MUSIC SECTION
	// check if song has finished played
	// probably not the best way.. this will play a song as soon as you push the stop button
	// could possibly add a stopped variable? not that we even have a stop button
	currentBassStatus = BASS_ChannelIsActive(audioChannel);
	if ((currentBassStatus == 0) && (oldBassStatus == 1)) // song was playing and is now stopped
	{
		// play the next song
		// put the new song into previously played list
	}
	oldBassStatus = currentBassStatus; // update oldBassSTatus, bad things happen if we dont do this
	
}







std::string getCurrentTime() {
	std::stringstream strstream;\
	strstream.str() = "";
	// set time
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	strstream << std::put_time(&tm, "%H:%M");
	return strstream.str();
}

void MainWindow :: on_buttonHome_released()
{
	// frames
	selectedFrame(0);

	// selected tab bar label
	selectedButton(0);
}


void MainWindow :: hideAllCentreFrames()
{
	ui->frameHome->hide();
	ui->frameMusic->hide();
	ui->framePhone->hide();
	ui->frameMaps->hide();
}

void MainWindow :: on_buttonMusic_released()
{
	// frames
	selectedFrame(1);

	selectedButton(1);
}

void MainWindow :: on_buttonPhone_released()
{
	// frames
	selectedFrame(2);

	// selected tab bar label
	selectedButton(2);
}

void MainWindow :: on_buttonMaps_released()
{
	// frames
	selectedFrame(3);

	// selected tab bar label
	selectedButton(3);
}

void MainWindow :: on_buttonVolumeDown_released()
{
	// lower the volume by a percentage..
	std :: cout << "Volume Down"
				<< std :: endl;
}

void MainWindow :: on_buttonVolumeUp_released()
{
	// increase the volume by a percentage
	std :: cout << "Volume Up"
				<< std :: endl;
}

void MainWindow :: on_buttonMusicPlayPause_released()
{
	int playStatus = playNewSong("file.mp3", audioChannel, FALSE);
	setButtonPlayPauseText(playStatus);
	setSongTags(nowPlaying.artist, nowPlaying.album, nowPlaying.artist);
}

void MainWindow :: on_buttonMusicNext_released()
{
	currentPlaylist.erase(currentPlaylist.begin());
	int playStatus = playNewSong(currentPlaylist[0].getPath(), audioChannel, TRUE);
	setButtonPlayPauseText(playStatus);
	setSongTags(nowPlaying.title, nowPlaying.album, nowPlaying.artist);
}

void MainWindow :: setButtonPlayPauseText(int playStatus)
{
	switch (playStatus)
	{
		case 0:
			//            ui->buttonMusicPlayPause->setText("Play");
			ui->buttonMusicPlayPause->setStyleSheet("background-image: url(./resources/icons/play.png);"
													"background-repeat: no-repeat;");
			break;

		case 1:
			//            ui->buttonMusicPlayPause->setText("Pause");
			ui->buttonMusicPlayPause->setStyleSheet("background-image: url(./resources/icons/pause.png);"
													"background-repeat: no-repeat;");
			break;

		case 2:
			//            ui->buttonMusicPlayPause->setText("2 = Err..");
			break;

		case 3:
			//            ui->buttonMusicPlayPause->setText("Play");
			ui->buttonMusicPlayPause->setStyleSheet("background-image: url(./resources/icons/play.png);"
													"background-repeat: no-repeat;");
			break;

		default:
			//            ui->buttonMusicPlayPause->setText("Err...");
			break;
	}
}

void MainWindow :: setSongTags(std::string title, std::string album, std::string artist)
{
	ui->labelCurrentTrack->setText(title.c_str());
	ui->labelCurrentArtistAlbum->setText((artist + " - " + album).c_str());
}

void MainWindow::on_buttonQuit_released()
{
	quick_exit(0);
}

void MainWindow :: on_listviewMusic_clicked(const QModelIndex &index)
{

	switch (currentView)
	{
		case 1:

			// going to album view now
			artistIDCur = index.sibling(index.row(), 1).data().toInt();
			model->clear();
			musicDB.getAlbums(model, artistIDCur);
			hideAllTabSelected();
			ui->labelSelected2->show();
			break;

		case 2:
			// going to the song view now
			albumIDCur = index.sibling(index.row(), 1).data().toInt();
			std::cout << albumIDCur << std::endl;
			model->clear();
			musicDB.getSongs(model, albumIDCur);
			hideAllTabSelected();
			ui->labelSelected3->show();
			break;

		case 3:
			// selected a song
			songIDCur = index.sibling(index.row(), 1).data().toInt();
			musicDB.getSongPath(songIDCur, currentSong);
			playNewSong(currentSong.getPath(), audioChannel, true);
			setButtonPlayPauseText(1);
			setSongTags(nowPlaying.title, nowPlaying.album, nowPlaying.artist);
			currentView--;

		default:
			break;

	}
	currentView++;
}







// Hide All Tab Selected
// Hide all Selected Labels
void MainWindow :: hideAllTabSelected()
{
	ui->labelSelected0->hide();
	ui->labelSelected1->hide();
	ui->labelSelected2->hide();
	ui->labelSelected3->hide();
}

void MainWindow :: hideMenuButtons()
{
	ui->buttonHome->hide();
	ui->buttonMusic->hide();
	ui->buttonMaps->hide();
	ui->buttonPhone->hide();
}

void MainWindow :: showMenuButtons()
{
	ui->buttonHome->show();
	ui->buttonMusic->show();
	ui->buttonMaps->show();
	ui->buttonPhone->show();
}


void MainWindow :: showMusicButtons()
{
	ui->buttonBack->show();
	ui->buttonArtist->show();
	ui->buttonAlbum->show();
	ui->buttonSong->show();
}

void MainWindow :: hideMusicButtons()
{
	ui->buttonBack->hide();
	ui->buttonArtist->hide();
	ui->buttonAlbum->hide();
	ui->buttonSong->hide();
}

int MainWindow :: selectedButton(int selected)
{
	switch (selected)
	{
		case 0:
			ui->labelSelected0->show();
			ui->labelSelected1->hide();
			ui->labelSelected2->hide();
			ui->labelSelected3->hide();
			break;

		case 1:
			ui->labelSelected0->hide();
			ui->labelSelected1->show();
			ui->labelSelected2->hide();
			ui->labelSelected3->hide();
			hideMenuButtons();
			showMusicButtons();
			break;

		case 2:
			ui->labelSelected0->hide();
			ui->labelSelected1->hide();
			ui->labelSelected2->show();
			ui->labelSelected3->hide();
			break;

		case 3:
			ui->labelSelected0->hide();
			ui->labelSelected1->hide();
			ui->labelSelected2->hide();
			ui->labelSelected3->show();
			break;

		default:
			if (ui->labelSelected0->isVisible())
				selected = 0;
			else if (ui->labelSelected1->isVisible())
				selected = 1;
			else if (ui->labelSelected2->isVisible())
				selected = 2;
			else if (ui->labelSelected3->isVisible())
				selected = 3;
			
			break;
	}

	return selected;
}

int MainWindow :: selectedFrame(int selected)
{
	switch (selected)
	{
		case 0:
			ui->frameHome->show();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			break;

		case 1:
			ui->frameHome->hide();
			ui->frameMusic->show();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			break;

		case 2:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->show();
			ui->frameMaps->hide();
			break;

		case 3:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->show();
			break;

		default:
			if (ui->frameHome->isVisible())
				selected = 0;
			else if (ui->frameMusic->isVisible())
				selected = 1;
			else if (ui->framePhone->isVisible())
				selected = 2;
			else if (ui->frameMaps->isVisible())
				selected = 3;

			break;

	}
	return selected;
}



void MainWindow::on_buttonBack_released()
{
	hideAllTabSelected();
	ui->labelSelected1->show();
	hideMusicButtons();
	showMenuButtons();
}

void MainWindow::on_buttonArtist_released()
{

}

void MainWindow::on_buttonAlbum_released()
{

}

void MainWindow::on_buttonSong_released()
{

}

int playNewSong(std::string songName, HSTREAM& handle, BOOL restart) {
	std::cout << BASS_ChannelIsActive(handle) << std::endl;

	if (restart == FALSE) {
		// nothing is playing
		if (BASS_ChannelIsActive(handle) == 0)
		{
			handle = BASS_StreamCreateFile(FALSE, songName.c_str(), 0, 0, 0);
			BASS_ChannelPlay(handle, FALSE);
		}

		// currently playing
		else if (BASS_ChannelIsActive(handle) == 1)
		{
			BASS_ChannelPause(handle);
		}

		// currently paused
		else if (BASS_ChannelIsActive(handle) == 3)
		{
			BASS_ChannelPlay(handle, FALSE);
		}
	}
	else
	{
		BASS_ChannelStop(handle);
		handle = BASS_StreamCreateFile(FALSE, songName.c_str(), 0, 0, 0);
		BASS_ChannelPlay(handle, TRUE);
	}

	nowPlaying.getSongTags(songName, nowPlaying.title, nowPlaying.album, nowPlaying.artist);

	return BASS_ChannelIsActive(handle);
}