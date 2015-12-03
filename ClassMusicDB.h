// Constants
#include "Constants.h"

// QT
#include <QtCore>
#include <QtGui>
//#include <QMainWindow>
//#include <QTimer>


// General
#include <iostream>								// General IO (cout/cin)
#include <string>								// Strings - STD :: String
#include <sstream>								// String Streams - STD :: stringstream
#include <iomanip>								// IOMainIP - time
#include <ctime>								// C-Time - time
#include <chrono>								// Chrono - STD :: chrono
#include <vector>


// GUI
//#include "ui_mainwindow.h"						// Main Form


// Music
//#include "libraries/bass/bass.h"				// Bass
//#include <alsa/asoundlib.h>						// Alsa (System Volume)
//#include <taglib/tag.h>							// Taglib (ID3 Tags)
//#include <taglib/taglib.h>						// Taglib
//#include <taglib/tstring.h>						// Taglib
//#include <taglib/fileref.h>						// Taglib
#include <sqlite3.h>							// SQLite (Data Storage)
#include "libraries/SQLiteCpp/SQLiteCpp.h"		// SQLiteCPP (SQLite API)
class MusicDB
{
	public:
		void getAllArtists(QStandardItemModel* model);

		bool getPlaylist(std::string path);

		void getArtist(QStandardItemModel& model);

		void getAlbums(QStandardItemModel* model, int artistID);
		
		void getSongPath(int songID, SongData& currentSong);

		void getSongs(QStandardItemModel* model, int albumID);

};
