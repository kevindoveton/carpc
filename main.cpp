// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "libraries/bass/bass.h"

#include "ui_mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// initialise bass
	BASS_Init(-1,44100,0,0,0);

	// Main Window
	MainWindow w;
	w.show();

	return a.exec();
}
