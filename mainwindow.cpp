#include "mainwindow.h"


HSTREAM audioChannel;

std::string musicLibrary = "musicLibrary.sqlite3";
QStringList artists;
std::vector<SongData> musicDB;
std::set<std::string> artistsDB;
std::vector<SongData> currentPlaylist;
int currentView = 1;
song nowPlaying;

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

	getPlaylist("musicLibrary.sqlite3");

	// get artists

	getArtist("musicLibrary.sqlite3", artists);

	artistsModel = new QStringListModel(this);
	artistsModel->setStringList(artists);

	albumModel = new QStringListModel(this);
	songModel = new QStringListModel(this);

	QStandardItemModel* model;
	model = new QStandardItemModel;
	model->setRowCount(4);
	model->setColumnCount(1);
	model->setData(model->index(0,0), QPixmap("resources/testpiccies/mcmahon.jpg"), Qt::DecorationRole);
	model->setData(model->index(0,0), " Mayer");
	model->setData(model->index(1,0), QPixmap("resources/testpiccies/hendrix.png"), Qt::DecorationRole);
	model->setData(model->index(1,0), "Jimmi Hendrix");
	model->setData(model->index(2,0), QPixmap("resources/testpiccies/coldplay.png"), Qt::DecorationRole);
	model->setData(model->index(2,0), "Coldplay");
	model->setData(model->index(3,0), QPixmap("resources/testpiccies/rudimental.png"), Qt::DecorationRole);
	model->setData(model->index(3,0), "Rudimental");


	ui->listviewMusic->setModel(model);
	ui->listviewMusic->setItemDelegate(new listViewMusicDelegate);
//	ui->listviewMusic->setAlternatingRowColors(true);

	getAllArtists();

	QMainWindow::showFullScreen();

	std::cout << "started" << std::endl;

}

MainWindow::~MainWindow()
{
	delete ui;
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

		SQLite::Statement query(db, "SELECT * FROM music");

		while (query.executeStep())
		{
			SongData temp;
			temp.set(query.getColumn(0), query.getColumn(1), query.getColumn(2), query.getColumn(3), query.getColumn(4), query.getColumn(5), query.getColumn(6), query.getColumn(7), query.getColumn(8), query.getColumn(9), query.getColumn(10), query.getColumn(11), query.getColumn(12));
			musicDB.push_back(temp);
		}\
	}

	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
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

		SQLite::Statement query(db, "SELECT DISTINCT artist FROM music");

		while (query.executeStep())
		{
			hello.str("");
			hello << query.getColumn(0);
			stringlist << hello.str().c_str();
		}
	}

	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;

	}
}

void MainWindow::on_listviewMusic_clicked(const QModelIndex &index)
{
	switch (currentView)
	{
		case 1:

			getAlbums(musicLibrary, artists, artists[index.row()].toStdString());
			albumModel->setStringList(artists);
			ui->listviewMusic->setModel(albumModel);
			break;

		case 2:


			getSongs(musicLibrary, artists, artists[index.row()].toStdString());
			songModel->setStringList(artists);

			ui->listviewMusic->setModel(songModel);
			break;

		case 3:
			std::cout << musicDB[0].getPath();
			playNewSong(currentPlaylist[index.row()].getPath(), audioChannel, TRUE);
			setButtonPlayPauseText(1);
			setSongTags(currentPlaylist[index.row()].getSong(), currentPlaylist[index.row()].getAlbum(), currentPlaylist[index.row()].getArtist());
			currentView--;

		default:
			break;

	}
	currentView++;
}

void getAlbums(std::string path, QStringList& stringlist, std::string artist)
{
	std::stringstream hello;
	artists.clear();
	try
	{
		SQLite::Database db(path);

		SQLite::Statement query(db, "SELECT DISTINCT album FROM music WHERE artist = ?");
		query.bind(1, artist);

		while (query.executeStep())
		{
			hello.str("");
			hello << query.getColumn(0);
			stringlist << hello.str().c_str();
		}
	}

	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;

	}

}



void getSongs(std::string path, QStringList& stringlist, std::string album)
{
	std::stringstream hello;
	artists.clear();
	try
	{
		SQLite::Database db(path);

		SQLite::Statement query(db, "SELECT * FROM music where album = ?");
		query.bind(1, album);

		while (query.executeStep())
		{
			hello.str("");
			hello << query.getColumn(3);
			stringlist << hello.str().c_str();
			SongData temp;
			temp.set(query.getColumn(0), query.getColumn(1), query.getColumn(2), query.getColumn(3), query.getColumn(4), query.getColumn(5), query.getColumn(6), query.getColumn(7), query.getColumn(8), query.getColumn(9), query.getColumn(10), query.getColumn(11), query.getColumn(12));
			currentPlaylist.push_back(temp);
		}
	}

	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;

	}
}

void MainWindow :: hideAllTabSelected()
{
	ui->labelSelected0->hide();
	ui->labelSelected1->hide();
	ui->labelSelected2->hide();
	ui->labelSelected3->hide();

}

void getAllArtists()
{
	std::cout << musicDB.size();
	std::sort(musicDB.begin(), musicDB.

}
