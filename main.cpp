// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "libraries/bass/bass.h"
#include "ui_mainwindow.h"
//#include <stdlib.h> // setenv


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// set qmap access token
	qputenv("MAPBOX_ACCESS_TOKEN", "pk.eyJ1Ijoia2V2aW5kb3ZldG9uIiwiYSI6ImNpdGdsYm9zYTAxMmcydG1rMnhuMGkxbHkifQ.pfUpUrZVbxkcj_pDx4Pbeg");

	// initialise bass
//	BASS_Init(-1,44100,0,0,0);

	// Main Window
	MainWindow w;
	w.show();

	return a.exec();
}
