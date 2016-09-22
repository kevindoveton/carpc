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


class ContactDB
{
	public:
		ContactDB();
		QByteArray getPictureFromNumber(QString number);
		QString getNameFromNumber(QString number);

	protected:
		std::string DBPATH = "resources/contacts/contacts.sqlite3";

};
