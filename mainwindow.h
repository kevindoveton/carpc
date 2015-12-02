#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// QT
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QTimer>


// General
#include <iostream>								// General IO (cout/cin)
#include <string>								// Strings - STD :: String
#include <sstream>								// String Streams - STD :: stringstream
#include <iomanip>								// IOMainIP - time
#include <ctime>								// C-Time - time
#include <chrono>								// Chrono - STD :: chrono
#include <vector>


// GUI
#include "ui_mainwindow.h"						// Main Form


// Music
#include "libraries/bass/bass.h"				// Bass
#include <alsa/asoundlib.h>						// Alsa (System Volume)
#include <taglib/tag.h>							// Taglib (ID3 Tags)
#include <taglib/taglib.h>						// Taglib
#include <taglib/tstring.h>						// Taglib
#include <taglib/fileref.h>						// Taglib
#include <sqlite3.h>							// SQLite (Data Storage)
#include "libraries/SQLiteCpp/SQLiteCpp.h"		// SQLiteCPP (SQLite API)


// Clases
#include "ClassMusic.h"							// Song Data
#include "listviewmusicdelegate.h"				// listviewMusic Delegate



namespace Ui {
class MainWindow;
}

class song
{
public:
	std::string title;
	std::string artist;
	std::string album;
	std::string path;
	bool playing;


	void getSongTags(std::string path, std::string& title, std::string& album, std::string& artist);
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void setSongTags(std::string title, std::string album, std::string artist);
	// set the song labels

	QStringListModel* artistsModel;
	QStringListModel* albumModel;
	QStringListModel* songModel;

private slots:

	// frameTopBar
	void on_buttonVolumeUp_released();
	void on_buttonMusicPlayPause_released();
	void on_buttonMusicNext_released();
	void on_buttonVolumeDown_released();

	// frameTabBar
	void on_buttonHome_released();
	void on_buttonMusic_released();
	void on_buttonPhone_released();
	void on_buttonMaps_released();
    //music
    void on_buttonBack_released();
    void on_buttonArtist_released();
    void on_buttonAlbum_released();
    void on_buttonSong_released();


	// frameHome
	void on_buttonQuit_released();

	// frameMusic
	void on_listviewMusic_clicked(const QModelIndex &index);


	void runLoop();

private:
	Ui::MainWindow *ui;

	void setButtonPlayPauseText(int playStatus);
	// set the text according to current playing ness


	void hideAllCentreFrames();
	// hide all the frames in the centre


	void hideAllTabSelected();
	// hide all the selected labels for the tab bar
};

void getAllArtists(QStandardItemModel* model);

int playNewSong(std::string songName, HSTREAM& audioChannel, BOOL restart);
// play a new song
// requires path to song including extension
// returns current status

std::string getCurrentTime();
// return current time as string

bool getPlaylist(std::string path);

void getArtist(QStandardItemModel& model);
void getAlbums(QStandardItemModel* model, int artistID);
void getSongPath(int songID, SongData& currentSong);

void getSongs(QStandardItemModel* model, int albumID);


#endif // MAINWINDOW_H
