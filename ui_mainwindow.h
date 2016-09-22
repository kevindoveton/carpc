// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QApplication>
#include <QtGui>
#include <QDesktopWidget>
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
#include <QPainter>
#include <sstream>
#include <QFontDatabase>
#include <QDebug>


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
		QFrame *frameRightBarLine;
		QPushButton *buttonRBBack;
		QPushButton *buttonRBHome;
		QPushButton *buttonRBNowPlaying;

		// Home
		QFrame *frameHome;
		QPushButton *buttonQuit;

		QPushButton *buttonMusic;
		QLabel *labelMusic;
		QFrame *lineMusic;

		QPushButton *buttonContacts;
		QLabel *labelContacts;
		QFrame *lineContacts;

		QPushButton *buttonMaps;
		QLabel *labelMaps;
		QFrame *lineMaps;

		QPushButton *buttonCamera;
		QLabel *labelCamera;
		QFrame *lineCamera;

		QPushButton *buttonPhone;
		QLabel *labelPhone;
		QFrame *linePhone;

		QPushButton *buttonAirplay;
		QLabel *labelAirplay;
		QFrame *lineAirplay;

		QPushButton *buttonHome;

		// Applications
		QFrame *frameMusic;
		QFrame *framePhone;
		QFrame *frameMaps;


		QLabel *labelHome;



		QLabel *label_3;

		QListView *listviewMusic;
		QAbstractItemDelegate *listviewDelegate;

		QLabel *label_4;

		QLabel *label_5;



		// Music - Application
		QPushButton *buttonMusicArtist;
		QPushButton *buttonMusicAlbum;
		QPushButton *buttonMusicSong;
		QPushButton *buttonMusicPlaylists;

		// Now Playing - Application
		QFrame *frameNowPlaying;
		QLabel *labelCurrentTrack;
		QLabel *labelCurrentArtist;
		QLabel *labelCurrentAlbum;
		QLabel *imageCurrentAlbum;
		QFrame *lineNowPlayingBB;
		QFrame *boxNowPlayingBB;
		QPushButton *buttonNowPlayingPlayPause;
		QPushButton *buttonNowPlayingNext;
		QPushButton *buttonNowPlayingPrevious;
		QPushButton *buttonNowPlayingFavourite;
		QPushButton *buttonNowPlayingShuffle;
		QPushButton *buttonNowPlayingRepeat;
		QPushButton *buttonNowPlayingVolumeUp;
		QPushButton *buttonNowPlayingVolumeDown;

		// Phone Call Received
		QFrame *frameCallReceived;
		QLabel *labelContactName;
		QLabel *labelPhoneNumber;
		QPushButton *buttonCallAccept;
		QPushButton *buttonCallDecline;
		QLabel *imageCaller;

		// Phone Call
		QFrame *frameCallPresent;
		QLabel *labelCallContactName;
		QLabel *labelCallPhoneNumber;
		QLabel *labelCallTimer;
		QLabel *labelCallStatus;
		QPushButton *buttonCallHangup;
		QLabel *imageCallPresentCaller;

		// Not used

//		QPushButton *buttonMusicPlayPause;
//		QPushButton *buttonMusicNext;
//		QPushButton *buttonVolumeUp;
//		QPushButton *buttonVolumeDown;
//		QPushButton *buttonMusicPrevious;

		void setupTopBarFrame();

		void setupUi(QMainWindow *MainWindow)
		{
			// Screen Dimensions
//			int screenWidth = QApplication::desktop()->geometry().width(); int screenHeight = QApplication::desktop()->geometry().height();
			int screenWidth = 800, screenHeight = 480; // test values


			// Fonts
			int id = QFontDatabase::addApplicationFont(":/resources/fonts/avenir/avenirLight.ttf");
			QString family = QFontDatabase::applicationFontFamilies(id).at(0);
			QFont avenirLight(family);


			// Right Bar Dimensions
			// These get used in now playing
			// as well as the right bar
			int frameRightBarWidth = 0.05325*screenWidth;
			int frameRightBarHeight = screenHeight;



			// -------------------------------------------------------------------------------------------------------------
			// main container window
			// -------------------------------------------------------------------------------------------------------------
			if (MainWindow->objectName().isEmpty())
				MainWindow->setObjectName(QStringLiteral("MainWindow"));
			MainWindow->resize(screenWidth, screenHeight);
			MainWindow->setMinimumSize(QSize(screenWidth, screenHeight));
			MainWindow->setMaximumSize(QSize(screenWidth, screenHeight));
			std::ostringstream sstr;

			// 1080p 32pt
			sstr << "font-size: " << 0.02692*screenHeight << "pt;\n"
				 << "text-transform: uppercase;\n"
				 << "color: rgb(255,255,255);"
				 << "font-family: Avenir;";
			std::string homePageLabelsStyle = sstr.str();
			sstr << "vertical-align: middle; \n"
				 << "text-align: center;";
			std::string musicPageButtonStyles = sstr.str();

			sstr.str(std::string(""));
			sstr << "font-size: " << 0.02692*screenHeight << "pt;\n"
				 << "text-transform: uppercase;\n"
				 << "font-family: Avenir;"
				 << "color: #FFFFFF";
			std::string topBarLabelStyles = sstr.str();


			// Now playing styles
			sstr.str(std::string(""));
			sstr << "font-size: " << 0.0592/2*screenHeight << "pt; \n"
				 << "font-family: Avenir;\n"
				 << "color: rgba(255,255,255,70);";
			std::string labelNowPlayingArtistStyle = sstr.str();

			sstr.str(std::string(""));
			sstr << "font-size: " << 0.133333/2*screenHeight << "pt; \n"
				 << "text-transform: uppercase; \n"
				 << "font-family: Avenir;\n"
				 << "color: rgb(255,255,255);";
			std::string labelNowPlayingSongStyle = sstr.str();

			sstr.str(std::string(""));
			sstr << "font-size: " << 0.0592/2*screenHeight << "pt; \n"
				 << "font-family: Avenir;\n"
				 << "color: rgb(255,255,255);";
			std::string labelNowPlayingAlbumStyle = sstr.str();

			MainWindow->setStyleSheet(QLatin1String("#MainWindow {\n"
													"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.4, stop:0 rgb(3,41,79), stop:1 rgb(66,123,164)); \n"
													"}\n"
													"\n"
													"QLabel {\n"
													"	font-family: sanFrancisco;\n"
													"	color: #fff;\n"
													"}\n"
													"\n"
													"#labelCurrentTrack {\n"
													"	;\n"
													"}\n"
													"\n"
													"#labelCurrentArtistAlbum {\n"
													"	font-size: 20pt;\n"
													"}\n"
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
			frameTopBar->setGeometry(QRect(0, 0, screenWidth, 0.1*screenHeight));
			frameTopBar->setFrameShape(QFrame::StyledPanel);
			frameTopBar->setFrameShadow(QFrame::Plain);


			// labelTime
			labelTime = new QLabel(frameTopBar);
			labelTime->setObjectName(QStringLiteral("labelTime"));
			labelTime->setGeometry(QRect(0.85*screenWidth, 0.0185*screenHeight, 0.1*screenWidth, 0.05*screenHeight));
			labelTime->setAlignment(Qt::AlignRight);
			labelTime->setStyleSheet(QString::fromStdString(topBarLabelStyles));









			// -------------------------------------------------------------------------------------------------------------
			// Home Page
			// -------------------------------------------------------------------------------------------------------------
			int lineHeight = 1;
			QString lineStyles = "background: rgba(255,255,255,70)";
			// frameHome
			frameHome = new QFrame(centralWidget);
			frameHome->setObjectName(QStringLiteral("frameHome"));
			frameHome->setEnabled(true);
			frameHome->setGeometry(QRect(0, 0, screenWidth, screenHeight));
			frameHome->setAutoFillBackground(false);
			frameHome->setFrameShape(QFrame::StyledPanel);
			frameHome->setFrameShadow(QFrame::Plain);

			// buttonMusic
			QPixmap musicImage(":/resources/icons/music.png");
			QIcon musicIcon(musicImage);
			buttonMusic = new QPushButton(frameHome);
			buttonMusic->setObjectName(QStringLiteral("buttonMusic"));
			buttonMusic->setGeometry(QRect(0.132*screenWidth, 0.151*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonMusic->setFlat(true);
			buttonMusic->raise();
			buttonMusic->setIcon(musicIcon);
			buttonMusic->setIconSize(buttonMusic->size());

			lineMusic = new QFrame(frameHome);
			lineMusic->setObjectName(QStringLiteral("lineMusic"));
			lineMusic->setGeometry(QRect(0.132*screenWidth, 0.382*screenHeight, 0.121*screenWidth, lineHeight));
			lineMusic->setStyleSheet(lineStyles);

			labelMusic = new QLabel(frameHome);
			labelMusic->setObjectName(QStringLiteral("labelMusic"));
			labelMusic->setGeometry(QRect(0.132*screenWidth, 0.398*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelMusic->setText("Music");
			labelMusic->setAlignment(Qt::AlignCenter);
			labelMusic->setStyleSheet(QString::fromStdString(homePageLabelsStyle));

			// buttonNavigation
			// buttonMaps
			QPixmap navigationImage(":/resources/icons/maps.png");
			QIcon navigationIcon(navigationImage);
			buttonMaps = new QPushButton(frameHome);
			buttonMaps->setObjectName(QStringLiteral("buttonMaps"));
			buttonMaps->setGeometry(QRect(0.425*screenWidth, 0.151*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonMaps->setFlat(true);
			buttonMaps->raise();
			buttonMaps->setIcon(navigationIcon);
			buttonMaps->setIconSize(buttonMaps->size());

			lineMaps = new QFrame(frameHome);
			lineMaps->setObjectName(QStringLiteral("lineMaps"));
			lineMaps->setGeometry(QRect(0.425*screenWidth, 0.382*screenHeight, 0.121*screenWidth, lineHeight));
			lineMaps->setStyleSheet(lineStyles);

			labelMaps = new QLabel(frameHome);
			labelMaps->setObjectName(QStringLiteral("labelMaps"));
			labelMaps->setGeometry(QRect(0.425*screenWidth, 0.398*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelMaps->setText("Maps");
			labelMaps->setAlignment(Qt::AlignCenter);
			labelMaps->setStyleSheet(QString::fromStdString(homePageLabelsStyle));





			// buttonContacts
			QPixmap contactsImage(":/resources/icons/contacts.png");
			QIcon contactsIcon(contactsImage);
			buttonContacts = new QPushButton(frameHome);
			buttonContacts->setObjectName(QStringLiteral("buttonContacts"));
			buttonContacts->setGeometry(QRect(0.715*screenWidth, 0.15*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonContacts->setFlat(true);
			buttonContacts->raise();
			buttonContacts->setIcon(contactsIcon);
			buttonContacts->setIconSize(buttonContacts->size());

			lineContacts = new QFrame(frameHome);
			lineContacts->setObjectName(QStringLiteral("lineContacts"));
			lineContacts->setGeometry(QRect(0.715*screenWidth, 0.382*screenHeight, 0.121*screenWidth, lineHeight));
			lineContacts->setStyleSheet(lineStyles);

			labelContacts = new QLabel(frameHome);
			labelContacts->setObjectName(QStringLiteral("labelContacts"));
			labelContacts->setGeometry(QRect(0.715*screenWidth, 0.398*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelContacts->setText("Contacts");
			labelContacts->setAlignment(Qt::AlignCenter);
			labelContacts->setStyleSheet(QString::fromStdString(homePageLabelsStyle));



			// buttonCamera
			QPixmap cameraImage(":/resources/icons/camera.png");
			QIcon cameraIcon(cameraImage);
			buttonCamera = new QPushButton(frameHome);
			buttonCamera->setObjectName(QStringLiteral("buttonCamera"));
			buttonCamera->setGeometry(QRect(0.132*screenWidth, 0.541*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonCamera->setFlat(true);
			buttonCamera->raise();
			buttonCamera->setIcon(cameraIcon);
			buttonCamera->setIconSize(buttonCamera->size());


			lineCamera = new QFrame(frameHome);
			lineCamera->setObjectName(QStringLiteral("lineMaps"));
			lineCamera->setGeometry(QRect(0.132*screenWidth, 0.774*screenHeight, 0.121*screenWidth, lineHeight));
			lineCamera->setStyleSheet(lineStyles);

			labelCamera = new QLabel(frameHome);
			labelCamera->setObjectName(QStringLiteral("labelCamera"));
			labelCamera->setGeometry(QRect(0.132*screenWidth, 0.794*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelCamera->setText("Camera");
			labelCamera->setAlignment(Qt::AlignCenter);
			labelCamera->setStyleSheet(QString::fromStdString(homePageLabelsStyle));



			// buttonPhone
			QPixmap phoneImage(":/resources/icons/phone.png");
			QIcon phoneIcon(phoneImage);
			buttonPhone = new QPushButton(frameHome);
			buttonPhone->setObjectName(QStringLiteral("buttonPhone"));
			buttonPhone->setGeometry(QRect(0.425*screenWidth, 0.541*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonPhone->setFlat(true);
			buttonPhone->raise();
			buttonPhone->setIcon(phoneIcon);
			buttonPhone->setIconSize(buttonPhone->size());

			linePhone = new QFrame(frameHome);
			linePhone->setObjectName(QStringLiteral("linePhone"));
			linePhone->setGeometry(QRect(0.425*screenWidth, 0.774*screenHeight, 0.121*screenWidth, lineHeight));
			linePhone->setStyleSheet(lineStyles);

			labelPhone = new QLabel(frameHome);
			labelPhone->setObjectName(QStringLiteral("labelPhone"));
			labelPhone->setGeometry(QRect(0.425*screenWidth, 0.794*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelPhone->setText("Phone");
			labelPhone->setAlignment(Qt::AlignCenter);
			labelPhone->setStyleSheet(QString::fromStdString(homePageLabelsStyle));




			// buttonAirplay
			QPixmap airplayImage(":/resources/icons/messages.png");
			QIcon airplayIcon(airplayImage);
			buttonAirplay = new QPushButton(frameHome);
			buttonAirplay->setObjectName(QStringLiteral("buttonAirplay"));
			buttonAirplay->setGeometry(QRect(0.715*screenWidth, 0.541*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonAirplay->setFlat(true);
			buttonAirplay->raise();
			buttonAirplay->setIcon(airplayIcon);
			buttonAirplay->setIconSize(buttonAirplay->size());

			lineAirplay = new QFrame(frameHome);
			lineAirplay->setObjectName(QStringLiteral("lineAirplay"));
			lineAirplay->setGeometry(QRect(0.715*screenWidth, 0.774*screenHeight, 0.121*screenWidth, lineHeight));
			lineAirplay->setStyleSheet(lineStyles);

			labelAirplay = new QLabel(frameHome);
			labelAirplay->setObjectName(QStringLiteral("labelAirplay"));
			labelAirplay->setGeometry(QRect(0.715*screenWidth, 0.794*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelAirplay->setText("Airplay");
			labelAirplay->setAlignment(Qt::AlignCenter);
			labelAirplay->setStyleSheet(QString::fromStdString(homePageLabelsStyle));




			// buttonQuit
			// This is technically part of the top bar
			// but is only shown on the home page to
			// avoid accidentally quitting the program
			buttonQuit = new QPushButton(frameHome);
			buttonQuit->setObjectName(QStringLiteral("buttonQuit"));
			buttonQuit->setGeometry(QRect(0.0185*screenWidth, 0.0185*screenHeight, 0.1*screenWidth, 0.05*screenHeight));
			buttonQuit->setStyleSheet(QString::fromStdString(topBarLabelStyles));










			// -------------------------------------------------------------------------------------------------------------
			// Music Page
			// -------------------------------------------------------------------------------------------------------------


			// frameMusic
			frameMusic = new QFrame(centralWidget);
			frameMusic->setObjectName(QStringLiteral("frameMusic"));
			frameMusic->setEnabled(true);
			frameMusic->setGeometry(QRect(0, 0, .9*screenWidth, screenHeight));
			frameMusic->setAutoFillBackground(false);
			frameMusic->setFrameShape(QFrame::StyledPanel);
			frameMusic->setFrameShadow(QFrame::Plain);



			// listViewMusic
			listviewMusic = new QListView(frameMusic);
			listviewMusic->setObjectName(QStringLiteral("listviewMusic"));
			listviewMusic->setGeometry(QRect(0.1*screenWidth, 0.144*screenHeight, 0.8*screenWidth, 0.756*screenHeight));
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


			// buttonPlaylists
			buttonMusicPlaylists = new QPushButton(frameMusic);
			buttonMusicPlaylists->setObjectName(QStringLiteral("buttonPlaylists"));
			buttonMusicPlaylists->setGeometry(QRect(0.189*screenWidth, 0.0868*screenHeight, 0.1111*screenWidth,0.0407*screenHeight));
			buttonMusicPlaylists->setFlat(true);
			buttonMusicPlaylists->raise();
			buttonMusicPlaylists->setText("Playlists");
			buttonMusicPlaylists->setStyleSheet(QString::fromStdString(musicPageButtonStyles));


			// buttonArtist
			buttonMusicArtist = new QPushButton(frameMusic);
			buttonMusicArtist->setObjectName(QStringLiteral("buttonArtist"));
			buttonMusicArtist->setGeometry(QRect(0.296*screenWidth, 0.0868*screenHeight, 0.11111*screenWidth,0.0407*screenHeight));
			buttonMusicArtist->setFlat(true);
			buttonMusicArtist->raise();
			buttonMusicArtist->setText("Artists");
			buttonMusicArtist->setStyleSheet(QString::fromStdString(musicPageButtonStyles));

			// buttonAlbum
			buttonMusicAlbum = new QPushButton(frameMusic);
			buttonMusicAlbum->setObjectName(QStringLiteral("buttonAlbum"));
			buttonMusicAlbum->setGeometry(QRect(0.424*screenWidth, 0.0868*screenHeight, 0.1111*screenWidth,0.0407*screenHeight));
			buttonMusicAlbum->setFlat(true);
			buttonMusicAlbum->raise();
			buttonMusicAlbum->setText("Albums");
			buttonMusicAlbum->setStyleSheet(QString::fromStdString(musicPageButtonStyles));

			// buttonSong
			buttonMusicSong = new QPushButton(frameMusic);
			buttonMusicSong->setObjectName(QStringLiteral("buttonSong"));
			buttonMusicSong->setGeometry(QRect(0.544*screenWidth, 0.0868*screenHeight, 0.1111*screenWidth,0.0407*screenHeight));
			buttonMusicSong->setFlat(true);
			buttonMusicSong->raise();
			buttonMusicSong->setText("Songs");
			buttonMusicSong->setStyleSheet(QString::fromStdString(musicPageButtonStyles));







			// -------------------------------------------------------------------------------------------------------------
			// Phone Page
			// -------------------------------------------------------------------------------------------------------------


			// framePhone
			framePhone = new QFrame(centralWidget);
			framePhone->setObjectName(QStringLiteral("framePhone"));
			framePhone->setEnabled(true);
			framePhone->setGeometry(QRect(0, 0, .9*screenWidth, screenHeight));
			framePhone->setAutoFillBackground(false);
			framePhone->setFrameShape(QFrame::StyledPanel);
			framePhone->setFrameShadow(QFrame::Plain);





			// label_4 - placeholder..
			label_4 = new QLabel(framePhone);
			label_4->setObjectName(QStringLiteral("label_4"));
			label_4->setGeometry(QRect(20, 30, 67, 21));
			label_4->setText("phone");










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


			// -------------------------------------------------------------------------------------------------------------
			// Now Playing Page
			// -------------------------------------------------------------------------------------------------------------

			// frameNowPlaying
			frameNowPlaying = new QFrame(centralWidget);
			frameNowPlaying->setObjectName(QStringLiteral("frameNowPlaying"));
			frameNowPlaying->setEnabled(true);
			frameNowPlaying->setGeometry(QRect(0, 0, screenWidth, screenHeight));
			frameNowPlaying->setAutoFillBackground(false);
			frameNowPlaying->setFrameShape(QFrame::StyledPanel);
			frameNowPlaying->setFrameShadow(QFrame::Plain);

			// 0.06453
			// width = 0.233

			// 0.230
			// height = 0.4148


			// labelCurrentArtist
			labelCurrentArtist = new QLabel(frameNowPlaying);
			labelCurrentArtist->setObjectName(QStringLiteral("labelCurrentArtist"));
			labelCurrentArtist->setGeometry(QRect(0.328*screenWidth, 0.346*screenHeight, 0.572*screenWidth, 0.054*screenHeight));
			labelCurrentArtist->setAlignment(Qt::AlignLeft|Qt::AlignBottom);
			labelCurrentArtist->setStyleSheet(QString::fromStdString(labelNowPlayingArtistStyle));

			// labelCurrentTrack
			labelCurrentTrack = new QLabel(frameNowPlaying);
			labelCurrentTrack->setObjectName(QStringLiteral("labelCurrentTrack"));
			labelCurrentTrack->setGeometry(QRect(0.328*screenWidth, 0.397*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelCurrentTrack->setAlignment(Qt::AlignLeft);
			labelCurrentTrack->setStyleSheet(QString::fromStdString(labelNowPlayingSongStyle));

			// labelCurrentAlbum
			labelCurrentAlbum = new QLabel(frameNowPlaying);
			labelCurrentAlbum->setObjectName(QStringLiteral("labelCurrentAlbum"));
			labelCurrentAlbum->setGeometry(QRect(0.328*screenWidth, 0.507*screenHeight, 0.572*screenWidth, 0.05556*screenHeight));
			labelCurrentAlbum->setAlignment(Qt::AlignLeft);
			labelCurrentAlbum->setStyleSheet(QString::fromStdString(labelNowPlayingAlbumStyle));

			// imageCurrentAlbum
			imageCurrentAlbum = new QLabel(frameNowPlaying);
			imageCurrentAlbum->setObjectName(QStringLiteral("imageCurrentAlbum"));
			imageCurrentAlbum->setGeometry(QRect(0.06543*screenWidth, 0.230*screenHeight, 0.233*screenWidth, 0.4148*screenHeight));
			imageCurrentAlbum->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
			QRect r = imageCurrentAlbum->rect();
			QPainterPath path = QPainterPath(r.topLeft());
			path.addRoundRect(r, 6);
			QPolygon p = path.toFillPolygon().toPolygon();
			imageCurrentAlbum->setMask(p);



			lineNowPlayingBB = new QFrame(frameNowPlaying);
			lineNowPlayingBB->setObjectName(QStringLiteral("lineNowPlayingBB"));
			lineNowPlayingBB->setGeometry(QRect(0, 0.83425*screenHeight, 0.946875*screenWidth, 2));
			lineNowPlayingBB->setStyleSheet(QLatin1String("background: rgba(255,255,255, 30);"));

			boxNowPlayingBB = new QFrame(frameNowPlaying);
			boxNowPlayingBB->setObjectName(QStringLiteral("boxNowPlayingBB"));
			// -2 from frameRightBarWidth because of frameRightBarLine
			boxNowPlayingBB->setGeometry(QRect(0, 0.83425*screenHeight, screenWidth-frameRightBarWidth-2, 16575*screenHeight));
			boxNowPlayingBB->setStyleSheet(QLatin1String("background: rgb(47, 76, 94);"));




			// buttonNowPlayingPrevious
			QPixmap bbNowPlayingPreviousImage(":/resources/icons/nowPlayingPrevious.png");
			QIcon bbNowPlayingPreviousIcon(bbNowPlayingPreviousImage);
			buttonNowPlayingPrevious = new QPushButton(frameNowPlaying);
			buttonNowPlayingPrevious->setObjectName(QStringLiteral("buttonNowPlayingPrevious"));
			buttonNowPlayingPrevious->setGeometry(QRect(0.4968*screenWidth, 0.875*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonNowPlayingPrevious->setFlat(true);
			buttonNowPlayingPrevious->setIcon(bbNowPlayingPreviousIcon);
			buttonNowPlayingPrevious->setIconSize(buttonNowPlayingPrevious->size());


			// buttonNowPlayingPlayPause
			QPixmap bbNowPlayingPlayPauseImage(":/resources/icons/nowPlayingPause.png");
			QIcon bbNowPlayingPlayPauseIcon(bbNowPlayingPlayPauseImage);
			buttonNowPlayingPlayPause = new QPushButton(frameNowPlaying);
			buttonNowPlayingPlayPause->setObjectName(QStringLiteral("buttonNowPlayingPlayPause"));
			buttonNowPlayingPlayPause->setGeometry(QRect(0.613*screenWidth, 0.8638*screenHeight, 0.05989*screenWidth, .105*screenHeight));
			buttonNowPlayingPlayPause->setFlat(true);
			buttonNowPlayingPlayPause->setIcon(bbNowPlayingPlayPauseIcon);
			buttonNowPlayingPlayPause->setIconSize(buttonNowPlayingPlayPause->size());







			// buttonNowPlayingNext
			QPixmap bbNowPlayingNextImage(":/resources/icons/nowPlayingNext.png");
			QIcon bbNowPlayingNextIcon(bbNowPlayingNextImage);
			buttonNowPlayingNext = new QPushButton(frameNowPlaying);
			buttonNowPlayingNext->setObjectName(QStringLiteral("buttonNowPlayingNext"));
			buttonNowPlayingNext->setGeometry(QRect(0.7796*screenWidth, 0.875*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonNowPlayingNext->setFlat(true);
			buttonNowPlayingNext->setIcon(bbNowPlayingNextIcon);
			buttonNowPlayingNext->setIconSize(buttonNowPlayingNext->size());



			// buttonNowPlayingFavourite
			QPixmap bbNowPlayingFavouriteImage(":/resources/icons/nowPlayingFavourite.png");
			QIcon bbNowPlayingFavouriteIcon(bbNowPlayingFavouriteImage);
			buttonNowPlayingFavourite = new QPushButton(frameNowPlaying);
			buttonNowPlayingFavourite->setObjectName(QStringLiteral("buttonNowPlayingFavourite"));
			buttonNowPlayingFavourite->setGeometry(QRect(0.3557*screenWidth, 0.875*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonNowPlayingFavourite->setFlat(true);
			buttonNowPlayingFavourite->setIcon(bbNowPlayingFavouriteIcon);
			buttonNowPlayingFavourite->setIconSize(buttonNowPlayingFavourite->size());

			// buttonNowPlayingShuffle
			QPixmap bbNowPlayingShuffleImage(":/resources/icons/nowPlaying.png");
			QIcon bbNowPlayingShuffleIcon(bbNowPlayingShuffleImage);
			buttonNowPlayingShuffle = new QPushButton(frameNowPlaying);
			buttonNowPlayingShuffle->setObjectName(QStringLiteral("buttonNowPlayingShuffle"));
			buttonNowPlayingShuffle->setGeometry(QRect(0.214*screenWidth, 0.875*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonNowPlayingShuffle->setFlat(true);
			buttonNowPlayingShuffle->setIcon(bbNowPlayingShuffleIcon);
			buttonNowPlayingShuffle->setIconSize(buttonNowPlayingShuffle->size());


			// buttonNowPlayingRepeat
			QPixmap bbNowPlayingRepeatImage(":/resources/icons/nowPlaying.png");
			QIcon bbNowPlayingRepeatIcon(bbNowPlayingRepeatImage);
			buttonNowPlayingRepeat = new QPushButton(frameNowPlaying);
			buttonNowPlayingRepeat->setObjectName(QStringLiteral("buttonNowPlayingRepeat"));
			buttonNowPlayingRepeat->setGeometry(QRect(0.073*screenWidth, 0.875*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonNowPlayingRepeat->setFlat(true);
			buttonNowPlayingRepeat->setIcon(bbNowPlayingRepeatIcon);
			buttonNowPlayingRepeat->setIconSize(buttonNowPlayingRepeat->size());




			// buttonVolumeUp
			buttonNowPlayingVolumeUp = new QPushButton(frameNowPlaying);
			buttonNowPlayingVolumeUp->setObjectName(QStringLiteral("buttonNowPlayingVolumeUp"));
			buttonNowPlayingVolumeUp->setGeometry(QRect(1190, 30, 65, 65));
			buttonNowPlayingVolumeUp->setFlat(true);
			buttonNowPlayingVolumeUp->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volUp.png);\n"
														"background-repeat: no-repeat;"));
//			buttonVolumeUp->setVisible(false);





			// buttonVolumeDown
			buttonNowPlayingVolumeDown = new QPushButton(frameNowPlaying);
			buttonNowPlayingVolumeDown->setObjectName(QStringLiteral("buttonNowPlayingVolumeDown"));
			buttonNowPlayingVolumeDown->setGeometry(QRect(710, 30, 65, 65));
			buttonNowPlayingVolumeDown->setFlat(true);
			buttonNowPlayingVolumeDown->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volDown.png);\n"
														  "background-repeat: no-repeat;"));
//			buttonVolumeDown->setVisible(false);




			frameCallReceived = new QFrame(centralWidget);
			frameCallReceived->setObjectName(QStringLiteral("frameCallReceived"));
			frameCallReceived->setEnabled(true);
			frameCallReceived->setGeometry(QRect(0, 0, screenWidth, screenHeight));
			frameCallReceived->setAutoFillBackground(false);
			frameCallReceived->setFrameShape(QFrame::StyledPanel);
			frameCallReceived->setFrameShadow(QFrame::Plain);


			labelContactName = new QLabel(frameCallReceived);
			labelContactName->setObjectName(QStringLiteral("labelContactName"));
			labelContactName->setGeometry(QRect(0.328*screenWidth, 0.397*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelContactName->setAlignment(Qt::AlignLeft);
			labelContactName->setStyleSheet(QString::fromStdString(labelNowPlayingSongStyle));


			labelPhoneNumber = new QLabel(frameCallReceived);
			labelPhoneNumber->setObjectName(QStringLiteral("labelPhoneNumber"));
			labelPhoneNumber->setGeometry(QRect(0.328*screenWidth, 0.346*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelPhoneNumber->setAlignment(Qt::AlignLeft);
			labelPhoneNumber->setStyleSheet(QString::fromStdString(labelNowPlayingArtistStyle));


			buttonCallAccept = new QPushButton(frameCallReceived);
			buttonCallAccept->setObjectName(QStringLiteral("buttonCallAccept"));
			buttonCallAccept->setGeometry(QRect(0.3*screenWidth, 0.6*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonCallAccept->setFlat(true);
			buttonCallAccept->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volUp.png);\n"
														"background-repeat: no-repeat;"));


			buttonCallDecline = new QPushButton(frameCallReceived);
			buttonCallDecline->setObjectName(QStringLiteral("buttonCallDecline"));
			buttonCallDecline->setGeometry(QRect(0.6*screenWidth, 0.6*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonCallDecline->setFlat(true);
			buttonCallDecline->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volDown.png);\n"
														"background-repeat: no-repeat;"));

			imageCaller = new QLabel(frameCallReceived);
			imageCaller->setObjectName(QStringLiteral("imageCaller"));
			imageCaller->setGeometry(QRect(0.06543*screenWidth, 0.15*screenHeight, 0.233*screenWidth, 0.7*screenHeight));
			imageCaller->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
			QRect rectImageCaller = imageCaller->rect();
			QPainterPath pathImageCaller = QPainterPath(rectImageCaller.topLeft());
			pathImageCaller.addRoundRect(rectImageCaller, 6);
			QPolygon polyImageCaller = pathImageCaller.toFillPolygon().toPolygon();
			imageCaller->setMask(polyImageCaller );




			// Phone Call

			QLabel *imageCallPresentCaller;

			frameCallPresent = new QFrame(centralWidget);
			frameCallPresent->setObjectName(QStringLiteral("frameCallPresent"));
			frameCallPresent->setEnabled(true);
			frameCallPresent->setGeometry(QRect(0, 0, screenWidth, screenHeight));
			frameCallPresent->setAutoFillBackground(false);
			frameCallPresent->setFrameShape(QFrame::StyledPanel);
			frameCallPresent->setFrameShadow(QFrame::Plain);


			labelCallContactName = new QLabel(frameCallPresent);
			labelCallContactName->setObjectName(QStringLiteral("labelCallContactName"));
			labelCallContactName->setGeometry(QRect(0.328*screenWidth, 0.397*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelCallContactName->setAlignment(Qt::AlignLeft);
			labelCallContactName->setStyleSheet(QString::fromStdString(labelNowPlayingSongStyle));


			labelCallPhoneNumber = new QLabel(frameCallPresent);
			labelCallPhoneNumber->setObjectName(QStringLiteral("labelCallPhoneNumber"));
			labelCallPhoneNumber->setGeometry(QRect(0.328*screenWidth, 0.346*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelCallPhoneNumber->setAlignment(Qt::AlignLeft);
			labelCallPhoneNumber->setStyleSheet(QString::fromStdString(labelNowPlayingArtistStyle));

			labelCallTimer = new QLabel(frameCallPresent);
			labelCallTimer->setObjectName(QStringLiteral("labelCallTimer"));
			labelCallTimer->setGeometry(QRect(0.328*screenWidth, 0.346*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelCallTimer->setAlignment(Qt::AlignLeft);
			labelCallTimer->setStyleSheet(QString::fromStdString(labelNowPlayingArtistStyle));

			labelCallStatus = new QLabel(frameCallPresent);
			labelCallStatus->setObjectName(QStringLiteral("labelCallStatus"));
			labelCallStatus->setGeometry(QRect(0.328*screenWidth, 0.346*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelCallStatus->setAlignment(Qt::AlignLeft);
			labelCallStatus->setStyleSheet(QString::fromStdString(labelNowPlayingArtistStyle));


			buttonCallHangup = new QPushButton(frameCallPresent);
			buttonCallHangup->setObjectName(QStringLiteral("buttonCallHangup"));
			buttonCallHangup->setGeometry(QRect(0.3*screenWidth, 0.6*screenHeight, 0.04747*screenWidth, 0.0833*screenHeight));
			buttonCallHangup->setFlat(true);
			buttonCallHangup->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volUp.png);\n"
														"background-repeat: no-repeat;"));

			imageCallPresentCaller = new QLabel(frameCallReceived);
			imageCallPresentCaller->setObjectName(QStringLiteral("imageCaller"));
			imageCallPresentCaller->setGeometry(QRect(0.06543*screenWidth, 0.15*screenHeight, 0.233*screenWidth, 0.7*screenHeight));
			imageCallPresentCaller->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
			QRect rectImageCallPresentCaller = imageCallPresentCaller->rect();
			QPainterPath pathImageCallPresentCaller = QPainterPath(rectImageCallPresentCaller.topLeft());
			pathImageCallPresentCaller.addRoundRect(rectImageCaller, 6);
			QPolygon polyImageCallPresentCaller = pathImageCallPresentCaller.toFillPolygon().toPolygon();
			imageCallPresentCaller->setMask(polyImageCallPresentCaller);

















			// -------------------------------------------------------------------------------------------------------------
			// Right Bar
			// -------------------------------------------------------------------------------------------------------------

			// frameRightBar
			frameRightBar = new QFrame(centralWidget);
			frameRightBar->setObjectName(QStringLiteral("frameRightBar"));
			frameRightBar->setGeometry(QRect(0.946875*screenWidth, 0, frameRightBarWidth, frameRightBarHeight));
			frameRightBar->setFrameShape(QFrame::StyledPanel);
			frameRightBar->setFrameShadow(QFrame::Plain);


			// Right Bar Line
			frameRightBarLine = new QFrame(centralWidget);
			frameRightBarLine->setObjectName(QStringLiteral("frameRightBarLine"));
			frameRightBarLine->setGeometry(QRect(0.946875*screenWidth, 0.15*screenHeight, 2, 0.75*screenHeight));
			frameRightBarLine->setStyleSheet(QLatin1String("background: rgba(255,255,255, 30);"));

			// buttonMusic
			QPixmap rbMusicImage(":/resources/icons/nowPlaying.png");
			QIcon rbMusicIcon(rbMusicImage);
			buttonRBNowPlaying = new QPushButton(frameRightBar);
			buttonRBNowPlaying->setObjectName(QStringLiteral("buttonRBNowPlaying"));
			buttonRBNowPlaying->setGeometry(QRect(0.3*frameRightBarWidth, 0.27*screenHeight, 0.5*frameRightBarWidth, 0.05*screenHeight));
			buttonRBNowPlaying->setFlat(true);
			buttonRBNowPlaying->raise();
			buttonRBNowPlaying->setIcon(rbMusicIcon);
			buttonRBNowPlaying->setIconSize(buttonRBNowPlaying->size());

			// buttonHome
			QPixmap rbHomeImage(":/resources/icons/home.png");
			QIcon rbHomeIcon(rbHomeImage);
			buttonRBHome = new QPushButton(frameRightBar);
			buttonRBHome->setObjectName(QStringLiteral("buttonRBHome"));
			buttonRBHome->setGeometry(QRect(0.3*frameRightBarWidth, 0.47*screenHeight, 0.5*frameRightBarWidth, 0.05*screenHeight));
			buttonRBHome->setFlat(true);
			buttonRBHome->raise();
			buttonRBHome->setIcon(rbHomeIcon);
			buttonRBHome->setIconSize(buttonRBHome->size());


			// back button
			QPixmap rbBackImage(":/resources/icons/back.png");
			QIcon rbBackIcon(rbBackImage);
			buttonRBBack = new QPushButton(frameRightBar);
			buttonRBBack->setObjectName(QStringLiteral("buttonRBBack"));
			buttonRBBack->setGeometry(QRect(0.3*frameRightBarWidth, 0.67*screenHeight, 0.5*frameRightBarWidth, 0.05*screenHeight));
			buttonRBBack->setFlat(true);
			buttonRBBack->raise();
			buttonRBBack->setIcon(rbBackIcon);
			buttonRBBack->setIconSize(buttonRBBack->size());

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

		} // retranslateUi

};

namespace Ui {
	class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
