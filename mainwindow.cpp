// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//  Set home frame for start up
	selectedFrame(0);
//	emit incomingCall("0433185809");

	// labels for now playing
	// setSongTags(album, artist, song)
	setSongTags("", "", "", "");
	ui->labelTime->setText(getCurrentTime().c_str());


	// Create Song Model
	// this is used in the now playing view
	model = new QStandardItemModel;
	musicDB.getArtists(model); // set artist
	ui->listviewMusic->setModel(model); // attach model to list
	ui->listviewMusic->setItemDelegate(new listViewMusicDelegate); // attach delegate to list
	ui->listviewMusic->setVerticalScrollMode(QListView::ScrollPerPixel);
	ui->listviewMusic->setGridSize(QSize(210,210));
	qDebug() << ui->listviewMusic->gridSize();

	// Run Loop
	// this timer will call
	// MainWindow::runLoop()
	// once every second
	QTimer* runLoopTimer = new QTimer(this);
	connect(runLoopTimer, SIGNAL(timeout()), this, SLOT(runLoop()));
	runLoopTimer->start(1000); // 1000ms = 1 seconds

	connect(ofono, SIGNAL(incomingCall(QString)), this, SLOT(incomingCall(QString)));

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
	/*	std::cout 	<< "runLoop timed out " 
					<< std::endl;
	*/


	// TIME SECTION
	ui->labelTime->setText(getCurrentTime().c_str()); // set the time



	// MUSIC SECTION
	// check if song has finished played
	// probably not the best way.. this will play a song as soon as you push the stop button
	// could possibly add a stopped variable? not that we even have a stop button
	if ((musicPlayer.currentBassStatus() == 0) && (musicPlayer.getOldBassStatus() == 1)) // song was playing and is now stopped
	{
		if (musicPlayer.playing())
		{
			// update playcount
			upNext[0].setPlayCount(upNext[0].getPlayCount() + 1);
			musicDB.setPlayCount(upNext[0].getPlayCount(), upNext[0].getID());

			// Push to previously played and remove from upNext
			recentlyPlayed.push_back(upNext[0]);
			upNext.erase(upNext.begin());

			// play new song
			int playStatus = musicPlayer.playNewSong(upNext[0].getPath());
			setButtonPlayPauseText(playStatus);
			setSongTags(upNext[0].getTitle(), upNext[0].getAlbum(), upNext[0].getArtist(), upNext[0].getAlbumImagePath());
		}
	}
	musicPlayer.setOldBassStatus(musicPlayer.currentBassStatus()); // update oldBassStatus, bad things happen if we dont do this
	
}







std::string getCurrentTime() {
	std::stringstream strstream;
	strstream.str() = "";
	// set time
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	strstream << std::put_time(&tm, "%H:%M");
	return strstream.str();
}

void MainWindow :: on_buttonRBHome_released()
{
	selectedFrame(0); 	// 	frames
}


void MainWindow :: hideAllCentreFrames()
{
	ui->frameHome->hide();
	ui->frameMusic->hide();
	ui->framePhone->hide();
	ui->frameMaps->hide();
	ui->frameNowPlaying->hide();
}

void MainWindow :: on_buttonMusic_released()
{
	// frames
	selectedFrame(1);
}

void MainWindow :: on_buttonPhone_released()
{
	// frames
	selectedFrame(2);
}

void MainWindow :: on_buttonMaps_released()
{
	selectedFrame(3); // frames
}

void MainWindow :: on_buttonAirplay_released()
{
	selectedFrame(4);
	musicPlayer.pause();
}


void MainWindow :: on_buttonNowPlayingVolumeDown_released()
{
	// lower the volume by a percentage..
	std :: cout << "Volume Down"
				<< std :: endl;

	if (systemVolume.getCurrentVolume() >= 0 + systemVolume.VOLUMECHANGE) // check that we won't go below minimum volume
		systemVolume.setMasterVolume(systemVolume.getCurrentVolume() - systemVolume.VOLUMECHANGE);
	else
		systemVolume.setMasterVolume(0);

	std::cout	<< "Current Volume: "
				<< systemVolume.getCurrentVolume()
				<< std::endl;
}

void MainWindow :: on_buttonNowPlayingVolumeUp_released()
{
	// increase the volume by a percentage
	std :: cout << "Volume Up"
				<< std :: endl;

	if (systemVolume.getCurrentVolume() <= 100 - systemVolume.VOLUMECHANGE) // check that we don't go above the max volume
		systemVolume.setMasterVolume(systemVolume.getCurrentVolume() + systemVolume.VOLUMECHANGE);
	else
		systemVolume.setMasterVolume(100);

	std::cout	<< "Current Volume: "
				<< systemVolume.getCurrentVolume()
				<< std::endl;

}

void MainWindow :: on_buttonNowPlayingPlayPause_released()
{

	switch (musicPlayer.currentBassStatus())
	{
		case 0:
			musicDB.shuffleAll(-1, upNext);
			musicPlayer.playNewSong(upNext[0].getPath());
			break;

		case 1:
			musicPlayer.pause();
			break;

		case 3:
			musicPlayer.resume();
			break;

		default:
			break;

	}

	setButtonPlayPauseText(musicPlayer.currentBassStatus());
	setSongTags(upNext[0].getTitle(), upNext[0].getAlbum(), upNext[0].getArtist(), upNext[0].getAlbumImagePath());
}

void MainWindow :: on_buttonNowPlayingNext_released()
{
	// Update skipcount
	std::cout << "SkipCount: " << upNext[0].getSkipCount() << std::endl;
	upNext[0].setSkipCount(upNext[0].getSkipCount() + 1);
	musicDB.setSkipCount(upNext[0].getSkipCount(), upNext[0].getID());

	if (musicPlayer.currentBassStatus() == 0)
	{
		musicDB.shuffleAll(-1, upNext);
		musicPlayer.playNewSong(upNext[0].getPath());
	}
	else
	{
		if (!upNext.empty())
		{
			recentlyPlayed.push_back(upNext[0]);
			upNext.erase(upNext.begin());
				if (!upNext.empty())
				{
					musicPlayer.playNewSong(upNext[0].getPath());
					setSongTags(upNext[0].getTitle(), upNext[0].getAlbum(), upNext[0].getArtist(), upNext[0].getAlbumImagePath());
				}
				else
				{
					musicPlayer.stop();
					setSongTags("", "", "", "");
				}
		}
	}

	setButtonPlayPauseText(musicPlayer.currentBassStatus());
}

void MainWindow :: on_buttonNowPlayingPrevious_released()
{
	upNext.insert(upNext.begin(), recentlyPlayed.back());
	recentlyPlayed.pop_back();
	int playStatus = musicPlayer.playNewSong(upNext[0].getPath());
	setButtonPlayPauseText(playStatus);
	setSongTags(upNext[0].getTitle(), upNext[0].getAlbum(), upNext[0].getArtist(), upNext[0].getAlbumImagePath());
}

void MainWindow :: setButtonPlayPauseText(int playStatus)
{
	// Play
	QPixmap pauseImage(":/resources/icons/nowPlayingPause.png");
	QIcon pauseIcon(pauseImage);
	QPixmap playImage(":/resources/icons/nowPlayingPlay.png");
	QIcon playIcon(playImage);
	switch (playStatus)
	{
		case 0:
			// Play
			ui->buttonNowPlayingPlayPause->setIcon(playIcon);
			break;

		case 1:
			// Pause
			ui->buttonNowPlayingPlayPause->setIcon(pauseIcon);
			break;

		case 2:
			//            ui->buttonMusicPlayPause->setText("2 = Err..");
			break;

		case 3:
			// Play
			ui->buttonNowPlayingPlayPause->setIcon(playIcon);
			break;

		default:
			//            ui->buttonMusicPlayPause->setText("Err...");
			break;
	}
}

void MainWindow :: setSongTags(std::string title, std::string album, std::string artist, std::string albumImagePath)
{

	QImage albumImageCrop = QImage(QString::fromStdString(albumImagePath));
	albumImageCrop = albumImageCrop.scaled(ui->imageCurrentAlbum->width(), ui->imageCurrentAlbum->height(), Qt::KeepAspectRatioByExpanding ,Qt::SmoothTransformation);
	QPixmap albumImage = QPixmap::fromImage(albumImageCrop);
	ui->imageCurrentAlbum->setPixmap(albumImage);


	ui->labelCurrentTrack->setText(title.c_str());
	ui->labelCurrentArtist->setText(artist.c_str());
	ui->labelCurrentAlbum->setText(album.c_str());

}

void MainWindow::on_buttonQuit_released()
{
	quick_exit(0);
}

void MainWindow :: on_listviewMusic_clicked(const QModelIndex &index)
{
	// song view should be a list
	// everything else should be icons
	if (currentView == 3)
		ui->listviewMusic->setViewMode(QListView::ListMode);
	else 
		ui->listviewMusic->setViewMode(QListView::IconMode);
	
	switch (currentView)
	{
		case 1:
			// going to album view now
			artistIDCur = index.sibling(index.row(), 1).data().toInt();
			model->clear();
			if (artistIDCur != -1)
				musicDB.getAlbums(model, artistIDCur);
			else
				musicDB.getAllAlbums(model);


			currentView = 2;
			break;

		case 2:
			// going to the song view now
			albumIDCur = index.sibling(index.row(), 1).data().toInt();
//			std::cout 	<< albumIDCur
//						<< std::endl;
			model->clear();
			if (albumIDCur != -1)
				musicDB.getSongs(model, albumIDCur);
			else
				musicDB.getAllSongs(model, artistIDCur);

			ui->listviewMusic->setViewMode(QListView::ListMode);
			currentView = 3;
			break;

		case 3:
		{
			// selected a song
			songIDCur = index.sibling(index.row(), 1).data().toInt();
			std::cout << songIDCur;
			SongData temp;

			musicDB.getSongPath(songIDCur, temp);
			upNext.clear();
			upNext.push_back(temp);
			musicPlayer.playNewSong(upNext[0].getPath());

			// Picked artist
			// Chose all songs
			if ((artistIDCur == -1) && (albumIDCur == -1))
				musicDB.shuffleAll(songIDCur, upNext);

			// Picked all albums
			// chose all songs
			else if (albumIDCur == -1)
					musicDB.shuffleArtist(songIDCur, upNext);

			// chose album
			else
				musicDB.shuffleAlbum(songIDCur, upNext);

			setButtonPlayPauseText(1);
			setSongTags(upNext[0].getTitle(), upNext[0].getAlbum(), upNext[0].getArtist(), upNext[0].getAlbumImagePath());
			selectedFrame(7);
			break;
		}

		default:
			break;

	}
}

void MainWindow :: showMenuButtons()
{
	ui->buttonHome->show();
	ui->buttonMusic->show();
	ui->buttonMaps->show();
	ui->buttonPhone->show();
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
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->hide();
			break;

		case 1:
			ui->frameHome->hide();
			ui->frameMusic->show();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->hide();
			break;

		case 2:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->show();
			ui->frameMaps->hide();
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->hide();
			break;

		case 3:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->show();
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->hide();
			break;

		case 4:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->hide();
			break;

		case 5:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->show();
			ui->frameCallPresent->hide();
			break;

		case 6:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			ui->frameNowPlaying->hide();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->show();
			break;

		case 7:
			ui->frameHome->hide();
			ui->frameMusic->hide();
			ui->framePhone->hide();
			ui->frameMaps->hide();
			ui->frameNowPlaying->show();
			ui->frameCallReceived->hide();
			ui->frameCallPresent->hide();
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





void MainWindow::on_buttonArtist_released()
{
	ui->listviewMusic->setViewMode(QListView::IconMode);
	currentView = 1;
	model->clear();
	musicDB.getArtists(model); // set artist
}

void MainWindow::on_buttonAlbum_released()
{
	ui->listviewMusic->setViewMode(QListView::IconMode);
	currentView = 2;
	model->clear();
	if (artistIDCur != -1)
		musicDB.getAlbums(model, artistIDCur);
	else
		musicDB.getAllAlbums(model);
}

void MainWindow::on_buttonSong_released()
{
	ui->listviewMusic->setViewMode(QListView::ListMode);

	currentView = 3;
	std::cout	<< albumIDCur
				<< std::endl;
	model->clear();
	if (albumIDCur != -1)
		musicDB.getSongs(model, albumIDCur);
	else
		musicDB.getAllSongs(model, albumIDCur);
}

void MainWindow::on_buttonRBNowPlaying_released()
{
	hideAllCentreFrames();
	ui->frameNowPlaying->show();
}


void MainWindow :: incomingCall(QString number)
{
	selectedFrame(5);

	// image
	QImage callerImageCrop;
	callerImageCrop.loadFromData(QByteArray::fromBase64(contactDB.getPictureFromNumber(number)));
	callerImageCrop = callerImageCrop.scaled(ui->imageCaller->width(), ui->imageCaller->height(), Qt::KeepAspectRatioByExpanding ,Qt::SmoothTransformation);
	QPixmap pixmapCallerImage = QPixmap::fromImage(callerImageCrop);
	ui->imageCaller->setPixmap(pixmapCallerImage);

	// labels
	if (contactDB.getNameFromNumber(number) == "")
	{
		ui->labelContactName->setText(number);
		ui->labelPhoneNumber->setText("");
	}
	else
	{
		ui->labelPhoneNumber->setText(number);
		ui->labelContactName->setText(contactDB.getNameFromNumber(number));
	}
}
