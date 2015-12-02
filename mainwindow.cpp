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


int artistIDCur;
int albumIDCur;
int songIDCur;

std::vector<int> artistIDs;
std::vector<int> albumIDs;
std::vector<int> songIDs;



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	//  hide all centre frames then show the home one for startup
	hideAllCentreFrames();
	ui->frameHome->show();

	// hide all selected tab labels then select home
	hideAllTabSelected();
	ui->labelSelected0->show();

	nowPlaying.playing = false;

	// labels
	setSongTags("", "", "");
	ui->labelTime->setText(getCurrentTime().c_str());

//	getPlaylist("musicLibrary.sqlite3");

	// get artists



	artistsModel = new QStringListModel(this);
	artistsModel->setStringList(artists);

	albumModel = new QStringListModel(this);
	songModel = new QStringListModel(this);


	model = new QStandardItemModel;
	getAllArtists(model); // set artist
	ui->listviewMusic->setModel(model);
	ui->listviewMusic->setItemDelegate(new listViewMusicDelegate);
//	ui->listviewMusic->setAlternatingRowColors(true);


	// run loop
	// this loop will run once every second
	QTimer* runLoopTimer = new QTimer(this);
	connect(runLoopTimer, SIGNAL(timeout()), this, SLOT(runLoop()));
	runLoopTimer->start(1000);



	QMainWindow::showFullScreen();

	std::cout << "started" << std::endl;

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



std::string getCurrentTime() {
	std::stringstream strstream;\
	strstream.str() = "";
	// set time
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	strstream << std::put_time(&tm, "%H:%M");
	return strstream.str();
}

void MainWindow::on_buttonHome_released()
{
	// frames
	MainWindow::hideAllCentreFrames();
	ui->frameHome->show();

	// selected tab bar label
	hideAllTabSelected();
	ui->labelSelected0->show();
}


void MainWindow::hideAllCentreFrames()
{
	ui->frameHome->hide();
	ui->frameMusic->hide();
	ui->framePhone->hide();
	ui->frameMaps->hide();
}

void MainWindow::on_buttonMusic_released()
{
	// frames
	MainWindow::hideAllCentreFrames();
	ui->frameMusic->show();

	// selected tab bar label
	hideAllTabSelected();
	ui->labelSelected1->show();
}

void MainWindow::on_buttonPhone_released()
{
	// frames
	MainWindow::hideAllCentreFrames();
	ui->framePhone->show();

	// selected tab bar label
	hideAllTabSelected();
	ui->labelSelected2->show();
}

void MainWindow::on_buttonMaps_released()
{
	// frames
	MainWindow::hideAllCentreFrames();
	ui->frameMaps->show();

	// selected tab bar label
	hideAllTabSelected();
	ui->labelSelected3->show();
}

void MainWindow::on_buttonVolumeDown_released()
{
	// lower the volume by a percentage..
}

void MainWindow::on_buttonVolumeUp_released()
{
	// increase the volume by a percentage
}

void song :: getSongTags(std::string path, std::string& title, std::string& album, std::string& artist)
{
	// initialise variables
	std::stringstream sstr;
	sstr.str("");

	// set path to file
	TagLib::FileRef f(path.c_str());

	// artist
	sstr << f.tag()->artist();
	artist = sstr.str();

	// album
	sstr.str("");
	sstr << f.tag()->album();
	album = sstr.str();

	// title
	sstr.str("");
	sstr << f.tag()->title();
	title = sstr.str();
}

void MainWindow::on_buttonMusicPlayPause_released()
{
	int playStatus = playNewSong("file.mp3", audioChannel, FALSE);
	setButtonPlayPauseText(playStatus);
	setSongTags(nowPlaying.artist, nowPlaying.album, nowPlaying.artist);
}

void MainWindow::on_buttonMusicNext_released()
{
	currentPlaylist.erase(currentPlaylist.begin());
	int playStatus = playNewSong(currentPlaylist[0].getPath(), audioChannel, TRUE);
	setButtonPlayPauseText(playStatus);
	setSongTags(nowPlaying.title, nowPlaying.album, nowPlaying.artist);
}

void MainWindow::setButtonPlayPauseText(int playStatus)
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

bool getPlaylist(std::string path)
{
	try
	{
		SQLite::Database db(path);

		SQLite::Statement query(db, "SELECT * FROM artists");

		while (query.executeStep())
		{
			SongData temp;
			temp.set(query.getColumn(0), query.getColumn(1), query.getColumn(2), query.getColumn(3), query.getColumn(4), query.getColumn(5), query.getColumn(6), query.getColumn(7), query.getColumn(8), query.getColumn(9), query.getColumn(10), query.getColumn(11), query.getColumn(12));
			musicDB.push_back(temp);
		}\
	}

	catch (std::exception& e)
	{
		std::cout << "getPlaylist - exception: " << e.what() << std::endl;
		return false;

	}
	return true;
}

void getArtist(std::string path, QStringList& stringlist)
{
	artists.clear();
	std::stringstream hello;
	try
	{
		SQLite::Database db(path);

		SQLite::Statement query(db, "SELECT artist FROM music");

		while (query.executeStep())
		{
			hello.str("");
			hello << query.getColumn(0);
			stringlist << hello.str().c_str();
		}
	}

	catch (std::exception& e)
	{
		std::cout << "Get Artist - Exception: " << e.what() << std::endl;

	}
}

void MainWindow::on_listviewMusic_clicked(const QModelIndex &index)
{

	switch (currentView)
	{
		case 1:

			// going to album view now

			artistIDCur = index.sibling(index.row(), 1).data().toInt();
			model->clear();
			getAlbums(model, artistIDCur);

			break;

		case 2:
			// going to the song view now
			albumIDCur = index.sibling(index.row(), 1).data().toInt();
			std::cout << albumIDCur << std::endl;
			model->clear();

			getSongs(model, albumIDCur);
			break;

		case 3:
			// selected a song
			songIDCur = index.sibling(index.row(), 1).data().toInt();
			getSongPath(songIDCur, currentSong);
			playNewSong(currentSong.getPath(), audioChannel, true);
			setButtonPlayPauseText(1);
			setSongTags(nowPlaying.title, nowPlaying.album, nowPlaying.artist);
			currentView--;

		default:
			break;

	}
	currentView++;
}

void getAlbums(QStandardItemModel* model, int artistID)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 0;
	model->setColumnCount(2);
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT albumName, albumID FROM albums WHERE artistID == ?");
		query.bind(1, artistID);

		while (query.executeStep())
		{
//			albumIDCur = query.getColumn(1);
			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);

			model->setData(model->index((indexCount-1), 1), (column1));

			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
//			model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);

		}

	}



	catch (std::exception& e)

			//			test = (model->data(model->index(0,0), Qt::DisplayRole).toString().toStdString());
	{
		std::cout << "getAlbums - Exception: " << e.what() << std::endl;

	}
}



void getSongs(QStandardItemModel* model, int albumID)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 0;
	model->setColumnCount(2);
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT songName, songID FROM songs WHERE albumID == ?");
		query.bind(1, albumID);

		while (query.executeStep())
		{
//			songIDCur = query.getColumn(1);
			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);

			model->setData(model->index((indexCount-1), 1), (column1));
			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
//			model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);

		}
	}

		catch (std::exception& e)
		{
			std::cout << "getSongs - Exception: " << e.what() << std::endl;

		}

}

void MainWindow :: hideAllTabSelected()
{
	ui->labelSelected0->hide();
	ui->labelSelected1->hide();
	ui->labelSelected2->hide();
	ui->labelSelected3->hide();

}

void getAllArtists(QStandardItemModel* model)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 0;
	model->setColumnCount(2);
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT artistName, artistID FROM artists");


		while (query.executeStep())
		{
//			artistIDCur = query.getColumn(1);


			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);


			model->setData(model->index((indexCount-1), 1), (column1));

			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
//			model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);

		}

	}



	catch (std::exception& e)
	{
		std::cout << "getAllArtists - Exception: " << e.what() << std::endl;

	}
}

void getSongPath(int songID, SongData& currentSong)
{
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT * FROM library WHERE songID == ?");
		query.bind(1, songID);

		while (query.executeStep())
		{
\
			std::string album = "";
			std::string artist = "";
			int bitRate = query.getColumn(5);
			int ID = query.getColumn(0);
			std::string kind = "";
			std::string lastPlayed = "";
			int length = query.getColumn(9);
			std::string path = query.getColumn(1);
			int playCount = query.getColumn(4);
			int rating = query.getColumn(2);
			int sampleRate = 0;
			int skipCount = query.getColumn(3);
			std::string song;


			currentSong.set(ID, artist, album, song, path, rating, playCount, skipCount, kind, bitRate, lastPlayed, sampleRate, length);
			std::cout << currentSong.dump();
		}

	}



	catch (std::exception& e)
	{
		std::cout << "getAllArtists - Exception: " << e.what() << std::endl;

	}


	return ;
}
