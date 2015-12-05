// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

// QT
#include <QtCore>
#include <QtGui>

// General
#include <iostream>								// General IO (cout/cin)
#include <string>								// Strings - STD :: String
#include <sstream>								// String Streams - STD :: stringstream
#include <iomanip>								// IOMainIP - time
#include <ctime>								// C-Time - time
#include <chrono>								// Chrono - STD :: chrono
#include <vector>

// Music
#include <sqlite3.h>							// SQLite (Data Storage)
#include "libraries/SQLiteCpp/SQLiteCpp.h"		// SQLiteCPP (SQLite API)

#include "ClassMusic.h"

class MusicDB
{
	public:
		void getAllArtists(QStandardItemModel* model);

		bool getPlaylist(std::string path);

		void getArtist(QStandardItemModel& model);

		void getAlbums(QStandardItemModel* model, int artistID);
		
		void getSongPath(int songID, SongData& currentSong);

		void getSongs(QStandardItemModel* model, int albumID);

	private:
		std::string DBPATH = "resources/music/musicLibrary.sqlite3";

};
