// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "libraries/bass/bass.h"
#include "ui_mainwindow.h"
#include <stdlib.h> // setenv


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// set qmap access token
	setenv("MAPBOX_ACCESS_TOKEN", "pk.eyJ1Ijoia2V2aW5kb3ZldG9uIiwiYSI6ImNpdGdsYm9zYTAxMmcydG1rMnhuMGkxbHkifQ.pfUpUrZVbxkcj_pDx4Pbeg", true);

	// initialise bass
	BASS_Init(-1,44100,0,0,0);

	// Main Window
	MainWindow w;
	w.show();
//	QMapboxGLSettings settings;
//	settings.setCacheDatabasePath("mbgl-cache.db");
//	settings.setCacheDatabaseMaximumSize(20 * 1024 * 1024);

//	MapWindow window(settings);

//	window.resize(800, 600);
//	window.show();

	return a.exec();
}
