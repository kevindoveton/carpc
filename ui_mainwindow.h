// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
	public:
		// Main Window
		QWidget *centralWidget;

		// Always on Frames
		QFrame *frameTopBar;
		QLabel *labelTime;

		QFrame *frameRightBar;
		QPushButton *buttonRBBack;
		QPushButton *buttonRBHome;
		QPushButton *buttonRBNowPlaying;

		// Home
		QFrame *frameHome;
		QPushButton *buttonQuit;
		QPushButton *buttonMusic;
		QPushButton *buttonContacts;
		QPushButton *buttonMaps;
		QPushButton *buttonCamera;
		QPushButton *buttonPhone;
		QPushButton *buttonMessages;
		QPushButton *buttonHome;

		// Applications
		QFrame *frameMusic;
		QFrame *framePhone;
		QFrame *frameMaps;





		QLabel *labelSelected0;
		QLabel *labelSelected1;
		QLabel *labelSelected2;
		QLabel *labelSelected3;

		QLabel *labelHome;



		QLabel *label_3;
		QListView *listviewMusic;
		QAbstractItemDelegate *listviewDelegate;

		QLabel *label_4;

		QLabel *label_5;


		QPushButton *buttonBack;
		QPushButton *buttonArtist;
		QPushButton *buttonAlbum;
		QPushButton *buttonSong;

		// Not used
		QFrame *frameBottomBar;
		QLabel *labelCurrentTrack;
		QLabel *labelCurrentArtistAlbum;
		QPushButton *buttonMusicPlayPause;
		QPushButton *buttonMusicNext;
		QPushButton *buttonVolumeUp;
		QPushButton *buttonVolumeDown;
		QPushButton *buttonMusicPrevious;

		void setupUi(QMainWindow *MainWindow)
		{
			// -------------------------------------------------------------------------------------------------------------
			// main container window
			// -------------------------------------------------------------------------------------------------------------
			if (MainWindow->objectName().isEmpty())
				MainWindow->setObjectName(QStringLiteral("MainWindow"));
			MainWindow->resize(800, 480);
			MainWindow->setMinimumSize(QSize(800, 480));
			MainWindow->setMaximumSize(QSize(800, 480));

			MainWindow->setStyleSheet(QLatin1String("#MainWindow {\n"
													"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.4, stop:1 rgb(3,41,79), stop:2 rgb(66,123,164)); \n"
													"}\n"
													"\n"
													"@font-face {\n"
													"	font-family: sanFrancisco;\n"
													"	src: url(./resources/fonts/sanFrancisco/sanFranciscoUltralight.ttf);\n"
													"}\n"
													"\n"
													"QLabel {\n"
													"	font-family: sanFrancisco;\n"
													"	color: #fff;\n"
													"}\n"
													"\n"
													"#labelCurrentTrack {\n"
													"	font-size: 37pt;\n"
													"}\n"
													"\n"
													"#labelCurrentArtistAlbum {\n"
													"	font-size: 20pt;\n"
													"}\n"
													"\n"
													"#labelTime {\n"
													"	font-size: 17pt;\n"
													"}\n"
													"\n"
													"#labelSelected0, #labelSelected1, #labelSelected2, #labelSelected3 {\n"
													"	background: url(./resources/icons/selected.png);\n"
													"}\n"
													"\n"
													"\n"
													"QPushButton {\n"
													"	border: none;\n"
													"	outline: none;\n"
													"}"));
			MainWindow->setAnimated(false);


			centralWidget = new QWidget(MainWindow);
			centralWidget->setObjectName(QStringLiteral("centralWidget"));










			// -------------------------------------------------------------------------------------------------------------
			// Top Bar
			// -------------------------------------------------------------------------------------------------------------

			// frameTopBar
			frameTopBar = new QFrame(centralWidget);
			frameTopBar->setObjectName(QStringLiteral("frameTopBar"));
			frameTopBar->setGeometry(QRect(0, 0, 1280, 100));
			frameTopBar->setFrameShape(QFrame::StyledPanel);
			frameTopBar->setFrameShadow(QFrame::Plain);


			// labelTime
			labelTime = new QLabel(frameTopBar);
			labelTime->setObjectName(QStringLiteral("labelTime"));
			labelTime->setGeometry(QRect(680, 20, 84, 25));
			labelTime->setAlignment(Qt::AlignRight);




			// -------------------------------------------------------------------------------------------------------------
			// Right Bar
			// -------------------------------------------------------------------------------------------------------------

			// frameRightBar
			frameRightBar = new QFrame(centralWidget);
			frameRightBar->setObjectName(QStringLiteral("frameRightBar"));
			frameRightBar->setGeometry(QRect(756, 0, 46, 480));
			frameRightBar->setFrameShape(QFrame::StyledPanel);
			frameRightBar->setFrameShadow(QFrame::Plain);

			// buttonMusic
//			buttonMusic = new QPushButton(frameHome);
//			buttonMusic->setObjectName(QStringLiteral("buttonMusic"));
//			buttonMusic->setGeometry(QRect(50, 0, 200, 91));
//			buttonMusic->setFlat(true);
//			buttonMusic->raise();
//			buttonMusic->setStyleSheet(QLatin1String("background:red;"));









			// -------------------------------------------------------------------------------------------------------------
			// Home Page
			// -------------------------------------------------------------------------------------------------------------

			// frameHome
			frameHome = new QFrame(centralWidget);
			frameHome->setObjectName(QStringLiteral("frameHome"));
			frameHome->setEnabled(true);
			frameHome->setGeometry(QRect(0, 110, 1280, 700));
			frameHome->setAutoFillBackground(false);
			frameHome->setFrameShape(QFrame::StyledPanel);
			frameHome->setFrameShadow(QFrame::Plain);


			// buttonMusic
			buttonMusic = new QPushButton(frameHome);
			buttonMusic->setObjectName(QStringLiteral("buttonMusic"));
			buttonMusic->setGeometry(QRect(50, 0, 100, 100));
			buttonMusic->setFlat(true);
			buttonMusic->raise();
//			buttonMusic->setStyleSheet(QLatin1String("background-image: url(./resources/icons/music.png);\n"
//													 "background-repeat: no-repeat;\n"
//													 "background-position: center;"));
			buttonMusic->setStyleSheet(QLatin1String("background:red;"));

			// buttonNavigation
			// buttonMaps
			buttonMaps = new QPushButton(frameHome);
			buttonMaps->setObjectName(QStringLiteral("buttonMaps"));
			buttonMaps->setGeometry(QRect(280, 0, 100, 100));
			buttonMaps->setFlat(true);
			buttonMaps->raise();
			buttonMaps->setStyleSheet(QLatin1String("background-image: url(./resources/icons/maps.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));

			// buttonContacts
			buttonContacts = new QPushButton(frameHome);
			buttonContacts->setObjectName(QStringLiteral("buttonContacts"));
			buttonContacts->setGeometry(QRect(550, 0, 100, 100));
			buttonContacts->setFlat(true);
			buttonContacts->raise();
			buttonContacts->setStyleSheet(QLatin1String("background-image: url(./resources/icons/contacts.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));
			// buttonCamera
			buttonCamera = new QPushButton(frameHome);
			buttonCamera->setObjectName(QStringLiteral("buttonMaps"));
			buttonCamera->setGeometry(QRect(989, 0, 230, 111));
			buttonCamera->setFlat(true);
			buttonCamera->raise();
			buttonCamera->setStyleSheet(QLatin1String("background-image: url(./resources/icons/camera.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));

			// buttonPhone
			buttonPhone = new QPushButton(frameHome);
			buttonPhone->setObjectName(QStringLiteral("buttonPhone"));
			buttonPhone->setGeometry(QRect(678, 0, 230, 111));
			buttonPhone->setFlat(true);
			buttonPhone->raise();
			buttonPhone->setStyleSheet(QLatin1String("background-image: url(./resources/icons/phone.png);\n"
													 "background-repeat: no-repeat;\n"
													 "background-position: center;"));
			// buttonMessages
			buttonMessages = new QPushButton(frameHome);
			buttonMessages->setObjectName(QStringLiteral("buttonPhone"));
			buttonMessages->setGeometry(QRect(678, 0, 230, 111));
			buttonMessages->setFlat(true);
			buttonMessages->raise();
			buttonMessages->setStyleSheet(QLatin1String("background-image: url(./resources/icons/messages.png);\n"
													 "background-repeat: no-repeat;\n"
													 "background-position: center;"));


			// labelHome - temp
			labelHome = new QLabel(frameHome);
			labelHome->setObjectName(QStringLiteral("labelHome"));
			labelHome->setGeometry(QRect(10, 40, 67, 21));





			// buttonQuit
			buttonQuit = new QPushButton(frameHome);
			buttonQuit->setObjectName(QStringLiteral("buttonQuit"));
			buttonQuit->setGeometry(QRect(110, 170, 95, 31));















			// -------------------------------------------------------------------------------------------------------------
			// Music Page
			// -------------------------------------------------------------------------------------------------------------


			// frameMusic
			frameMusic = new QFrame(centralWidget);
			frameMusic->setObjectName(QStringLiteral("frameMusic"));
			frameMusic->setEnabled(true);
			frameMusic->setGeometry(QRect(-1, 110, 1281, 481));
			frameMusic->setAutoFillBackground(false);
			frameMusic->setFrameShape(QFrame::StyledPanel);
			frameMusic->setFrameShadow(QFrame::Plain);





			// label_3
			label_3 = new QLabel(frameMusic);
			label_3->setObjectName(QStringLiteral("label_3"));
			label_3->setGeometry(QRect(30, 40, 67, 21));





			// listViewMusic
			listviewMusic = new QListView(frameMusic);
			listviewMusic->setObjectName(QStringLiteral("listviewMusic"));
			listviewMusic->setGeometry(QRect(0, 1, 1281, 481));
			listviewMusic->setEditTriggers(QAbstractItemView::NoEditTriggers);
			listviewMusic->setIconSize(QSize(0, 0));
			listviewMusic->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
			listviewMusic->setMovement(QListView::Free);
			//		listviewMusic->setSpacing(10);
			listviewMusic->setMovement(QListView::Static);
			listviewMusic->setBatchSize(20);
			listviewMusic->setLayoutMode(QListView::Batched);
			listviewMusic->setGridSize(QSize(420, 180));
			listviewMusic->setViewMode(QListView::IconMode);
			listviewMusic->setSelectionRectVisible(false);
			listviewMusic->setStyleSheet("background-color: transparent; border: none;");










			// -------------------------------------------------------------------------------------------------------------
			// Phone Page
			// -------------------------------------------------------------------------------------------------------------


			// framePhone
			framePhone = new QFrame(centralWidget);
			framePhone->setObjectName(QStringLiteral("framePhone"));
			framePhone->setEnabled(true);
			framePhone->setGeometry(QRect(-1, 110, 1281, 481));
			framePhone->setAutoFillBackground(false);
			framePhone->setFrameShape(QFrame::StyledPanel);
			framePhone->setFrameShadow(QFrame::Plain);





			// label_4 - placeholder..
			label_4 = new QLabel(framePhone);
			label_4->setObjectName(QStringLiteral("label_4"));
			label_4->setGeometry(QRect(20, 30, 67, 21));










			// -------------------------------------------------------------------------------------------------------------
			// Maps Page
			// -------------------------------------------------------------------------------------------------------------

			// frameMaps
			frameMaps = new QFrame(centralWidget);
			frameMaps->setObjectName(QStringLiteral("frameMaps"));
			frameMaps->setEnabled(true);
			frameMaps->setGeometry(QRect(-1, 110, 1281, 481));
			frameMaps->setAutoFillBackground(false);
			frameMaps->setFrameShape(QFrame::StyledPanel);
			frameMaps->setFrameShadow(QFrame::Plain);





			// label_5 - this is a placeholder
			label_5 = new QLabel(frameMaps);
			label_5->setObjectName(QStringLiteral("label_5"));
			label_5->setGeometry(QRect(30, 30, 67, 21));




			// labelCurrentTrack
			labelCurrentTrack = new QLabel(frameTopBar);
			labelCurrentTrack->setObjectName(QStringLiteral("labelCurrentTrack"));
			labelCurrentTrack->setGeometry(QRect(0, 10, 681, 51));
			labelCurrentTrack->setAlignment(Qt::AlignCenter);
			labelCurrentTrack->setVisible(false);





			// labelCurrentArtistAlbum
			labelCurrentArtistAlbum = new QLabel(frameTopBar);
			labelCurrentArtistAlbum->setObjectName(QStringLiteral("labelCurrentArtistAlbum"));
			labelCurrentArtistAlbum->setGeometry(QRect(0, 60, 681, 41));
			labelCurrentArtistAlbum->setAlignment(Qt::AlignCenter);
			labelCurrentArtistAlbum->setVisible(false);





			// buttonMusicPlayPause
			buttonMusicPlayPause = new QPushButton(frameTopBar);
			buttonMusicPlayPause->setObjectName(QStringLiteral("buttonMusicPlayPause"));
			buttonMusicPlayPause->setGeometry(QRect(950, 30, 65, 65));
			buttonMusicPlayPause->setFlat(true);
			buttonMusicPlayPause->setStyleSheet(QLatin1String("background-image: url(./resources/icons/play.png);\n"
															  "background-repeat: no-repeat;"));
			buttonMusicPlayPause->setVisible(false);





			// buttonMusicNext
			buttonMusicNext = new QPushButton(frameTopBar);
			buttonMusicNext->setObjectName(QStringLiteral("buttonMusicNext"));
			buttonMusicNext->setGeometry(QRect(1070, 30, 65, 65));
			buttonMusicNext->setFlat(true);
			buttonMusicNext->setStyleSheet(QLatin1String("background-image: url(./resources/icons/next.png);\n"
														 "background-repeat: no-repeat;"));
			buttonMusicNext->setVisible(false);





			// buttonVolumeUp
			buttonVolumeUp = new QPushButton(frameTopBar);
			buttonVolumeUp->setObjectName(QStringLiteral("buttonVolumeUp"));
			buttonVolumeUp->setGeometry(QRect(1190, 30, 65, 65));
			buttonVolumeUp->setFlat(true);
			buttonVolumeUp->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volUp.png);\n"
														"background-repeat: no-repeat;"));
			buttonVolumeUp->setVisible(false);





			// buttonVolumeDown
			buttonVolumeDown = new QPushButton(frameTopBar);
			buttonVolumeDown->setObjectName(QStringLiteral("buttonVolumeDown"));
			buttonVolumeDown->setGeometry(QRect(710, 30, 65, 65));
			buttonVolumeDown->setFlat(true);
			buttonVolumeDown->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volDown.png);\n"
														  "background-repeat: no-repeat;"));
			buttonVolumeDown->setVisible(false);





			// buttonMusicPrevious
			buttonMusicPrevious = new QPushButton(frameTopBar);
			buttonMusicPrevious->setObjectName(QStringLiteral("buttonMusicPrevious"));
			buttonMusicPrevious->setGeometry(QRect(830, 30, 65, 65));
			buttonMusicPrevious->setFlat(true);
			buttonMusicPrevious->setStyleSheet(QLatin1String("background-image: url(./resources/icons/previous.png);\n"
															 "background-repeat: no-repeat;"));
			buttonMusicPrevious->setVisible(false);





			// -------------------------------------------------------------------------------------------------------------
			// Bottom tab bar
			// -------------------------------------------------------------------------------------------------------------


			// frameBottomBar
			frameBottomBar = new QFrame(centralWidget);
			frameBottomBar->setObjectName(QStringLiteral("frameBottomBar"));
			frameBottomBar->setGeometry(QRect(0, 610, 1281, 111));
			frameBottomBar->setStyleSheet(QStringLiteral(""));
			frameBottomBar->setFrameShape(QFrame::StyledPanel);
			frameBottomBar->setFrameShadow(QFrame::Plain);





			// labelSelected0 - home
			labelSelected0 = new QLabel(frameBottomBar);
			labelSelected0->setObjectName(QStringLiteral("labelSelected0"));
			labelSelected0->setGeometry(QRect(58, 0, 230, 111));
			labelSelected0->raise();


			// buttonHome
			buttonHome = new QPushButton(frameBottomBar);
			buttonHome->setObjectName(QStringLiteral("buttonHome"));
			buttonHome->setGeometry(QRect(58, 0, 230, 111));
			buttonHome->setFlat(true);
			buttonHome->raise();
			buttonHome->setStyleSheet(QLatin1String("background-image: url(./resources/icons/home.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));





			// labelSelected1 - music
			labelSelected1 = new QLabel(frameBottomBar);
			labelSelected1->setObjectName(QStringLiteral("labelSelected1"));
			labelSelected1->setGeometry(QRect(368, 0, 230, 111));
			labelSelected1->raise();











			// labelSelected2 - phone
			labelSelected2 = new QLabel(frameBottomBar);
			labelSelected2->setObjectName(QStringLiteral("labelSelected2"));
			labelSelected2->setGeometry(QRect(678, 0, 230, 111));
			labelSelected2->raise();








			// labelSelected3 - maps
			labelSelected3 = new QLabel(frameBottomBar);
			labelSelected3->setObjectName(QStringLiteral("labelSelected3"));
			labelSelected3->setGeometry(QRect(989, 0, 230, 111));
			labelSelected3->raise();





			// buttonBack
			buttonBack = new QPushButton(frameBottomBar);
			buttonBack->setObjectName(QStringLiteral("buttonBack"));
			buttonBack->setGeometry(QRect(58, 0, 230, 111));
			buttonBack->setFlat(true);
			buttonBack->raise();
			buttonBack->setStyleSheet(QLatin1String("background-image: url(./resources/icons/back.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));

			// buttonArtist
			buttonArtist = new QPushButton(frameBottomBar);
			buttonArtist->setObjectName(QStringLiteral("buttonArtist"));
			buttonArtist->setGeometry(QRect(368, 0, 230, 111));
			buttonArtist->setFlat(true);
			buttonArtist->raise();
			buttonArtist->setStyleSheet(QLatin1String("background-image: url(./resources/icons/artist.png);\n"
													  "background-repeat: no-repeat;\n"
													  "background-position: center;"));

			// buttonAlbum
			buttonAlbum = new QPushButton(frameBottomBar);
			buttonAlbum->setObjectName(QStringLiteral("buttonAlbum"));
			buttonAlbum->setGeometry(QRect(678, 0, 230, 111));
			buttonAlbum->setFlat(true);
			buttonAlbum->raise();
			buttonAlbum->setStyleSheet(QLatin1String("background-image: url(./resources/icons/album.png);\n"
													 "background-repeat: no-repeat;\n"
													 "background-position: center;"));

			// buttonSong
			buttonSong = new QPushButton(frameBottomBar);
			buttonSong->setObjectName(QStringLiteral("buttonSong"));
			buttonSong->setGeometry(QRect(989, 0, 230, 111));
			buttonSong->setFlat(true);
			buttonSong->raise();
			buttonSong->setStyleSheet(QLatin1String("background-image: url(./resources/icons/song.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));









			// -------------------------------------------------------------------------------------------------------------
			// Bottom tab bar
			// -------------------------------------------------------------------------------------------------------------


			MainWindow->setCentralWidget(centralWidget);
			retranslateUi(MainWindow);

			// this isnt the best but yolo
			QMetaObject::connectSlotsByName(MainWindow);
		} // setupUi


		void retranslateUi(QMainWindow *MainWindow)
		{
			MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
			MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
			MainWindow->setStatusTip(QString());
#endif // QT_NO_STATUSTIP

			buttonQuit->setText(QApplication::translate("MainWindow", "quit", 0));
			/*
		buttonMusic->setText(QApplication::translate("MainWindow", "Music", 0));
		buttonPhone->setText(QApplication::translate("MainWindow", "Phone", 0));
		buttonMaps->setText(QApplication::translate("MainWindow", "Maps", 0));
		buttonHome->setText(QApplication::translate("MainWindow", "Home", 0));
		labelSelected0->setText(QApplication::translate("MainWindow", "labelSelected0", 0));
		labelSelected1->setText(QApplication::translate("MainWindow", "labelSelected1", 0));
		labelSelected2->setText(QApplication::translate("MainWindow", "labelSelected2", 0));
		labelSelected3->setText(QApplication::translate("MainWindow", "labelSelected3", 0));
		labelHome->setText(QApplication::translate("MainWindow", "home", 0));

		labelTime->setText(QApplication::translate("MainWindow", "labelTime", 0));
		label_3->setText(QApplication::translate("MainWindow", "music", 0));
		label_4->setText(QApplication::translate("MainWindow", "phone", 0));
		label_5->setText(QApplication::translate("MainWindow", "maps", 0));
		labelCurrentTrack->setText(QApplication::translate("MainWindow", "labelCurrentTrack", 0));
		labelCurrentArtistAlbum->setText(QApplication::translate("MainWindow", "labelCurrentArtistAlbum", 0));
		buttonMusicPlayPause->setText(QApplication::translate("MainWindow", "Play/Pause", 0));
		buttonMusicNext->setText(QApplication::translate("MainWindow", "Next", 0));
		buttonVolumeUp->setText(QApplication::translate("MainWindow", "Volume Up", 0));
		buttonVolumeDown->setText(QApplication::translate("MainWindow", "Volume Down", 0));
		buttonMusicPrevious->setText(QApplication::translate("MainWindow", "Previous", 0));
		*/
		} // retranslateUi

};

namespace Ui {
	class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
