#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Constants
#include "Constants.h"

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
#include "ClassSong.h"							
#include "ClassMusicDB.h"
#include "listviewmusicdelegate.h"				// listviewMusic Delegate



namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		

		//QStringListModel* artistsModel;
		//QStringListModel* albumModel;
		//QStringListModel* songModel;

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

		void setSongTags(std::string title, std::string album, std::string artist);
		// set the song labels

		void setButtonPlayPauseText(int playStatus);
		// set the text according to current playing ness


		void hideAllCentreFrames();
		// hide all the frames in the centre

		void hideMenuButtons();
		// hide standard menu buttons

		void showMenuButtons();
		// show standard menu buttons

		void showMusicButtons();
		// show music specific buttons

		void hideMusicButtons();
		// hide music specific buttons

		int selectedFrame(int selected = -1);
		// set selected frame
		// 0 = home, 1 = music, 2 = phone, 3 = maps
		// if set blank or incorrectly will return the
		// currently selected frame

		int selectedButton(int selected = -1);
		// Set selected label on bottom tab bar
		// if set blank or incorrectly will return the
		// currently selected button


		void hideAllTabSelected();
		// hide all the selected labels for the tab bar
};

std::string getCurrentTime();
// return current time as string

int playNewSong(std::string songName, HSTREAM& audioChannel, BOOL restart);
// play a new song
// requires path to song including extension
// returns current status

#endif // MAINWINDOW_H
