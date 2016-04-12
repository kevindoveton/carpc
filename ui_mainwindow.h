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

		QPushButton *buttonMessages;
		QLabel *labelMessages;
		QFrame *lineMessages;

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


		QPushButton *buttonBack;

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

		// Not used
		QFrame *frameBottomBar;

		QPushButton *buttonMusicPlayPause;
		QPushButton *buttonMusicNext;
		QPushButton *buttonVolumeUp;
		QPushButton *buttonVolumeDown;
		QPushButton *buttonMusicPrevious;

		void setupTopBarFrame();

		void setupUi(QMainWindow *MainWindow)
		{
			// Screen Dimensions
			int screenWidth = QApplication::desktop()->geometry().width(); int screenHeight = QApplication::desktop()->geometry().height();
//			int screenWidth = 800, screenHeight = 480; // test values


			// Fonts
			int id = QFontDatabase::addApplicationFont(":/resources/fonts/avenir/avenirLight.ttf");
			QString family = QFontDatabase::applicationFontFamilies(id).at(0);
			QFont avenirLight(family);





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
				 << "text-transform: uppercase;\n";
			sstr << "font-family: Avenir;";
			std::string homePageLabelsStyle = sstr.str();
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




			// buttonMessages
			QPixmap messagesImage(":/resources/icons/messages.png");
			QIcon messagesIcon(messagesImage);
			buttonMessages = new QPushButton(frameHome);
			buttonMessages->setObjectName(QStringLiteral("buttonMessages"));
			buttonMessages->setGeometry(QRect(0.715*screenWidth, 0.541*screenHeight, 0.121*screenWidth, 0.216*screenHeight));
			buttonMessages->setFlat(true);
			buttonMessages->raise();
			buttonMessages->setIcon(messagesIcon);
			buttonMessages->setIconSize(buttonMessages->size());

			lineMessages = new QFrame(frameHome);
			lineMessages->setObjectName(QStringLiteral("lineMessages"));
			lineMessages->setGeometry(QRect(0.715*screenWidth, 0.774*screenHeight, 0.121*screenWidth, lineHeight));
			lineMessages->setStyleSheet(lineStyles);

			labelMessages = new QLabel(frameHome);
			labelMessages->setObjectName(QStringLiteral("labelMessages"));
			labelMessages->setGeometry(QRect(0.715*screenWidth, 0.794*screenHeight, 0.121*screenWidth, 0.028*screenHeight));
			labelMessages->setText("Messages");
			labelMessages->setAlignment(Qt::AlignCenter);
			labelMessages->setStyleSheet(QString::fromStdString(homePageLabelsStyle));




			// labelHome - temp
			labelHome = new QLabel(frameHome);
			labelHome->setObjectName(QStringLiteral("labelHome"));
			labelHome->setGeometry(QRect(10, 40, 67, 21));











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





//			// label_3
//			label_3 = new QLabel(frameMusic);
//			label_3->setObjectName(QStringLiteral("label_3"));
//			label_3->setGeometry(QRect(30, 40, 67, 21));
//			label_3->setStyleSheet("Background: red;");
//			label_3->setVisible(true);





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
			buttonMusicPlaylists->setObjectName(QStringLiteral("buttonArtist"));
			buttonMusicPlaylists->setGeometry(QRect(0.189*screenWidth, 0.0868*screenHeight, 0.0817*screenWidth,0.039*screenHeight));
			buttonMusicPlaylists->setFlat(true);
			buttonMusicPlaylists->raise();
			buttonMusicPlaylists->setText("Playlists");
			buttonMusicPlaylists->setStyleSheet(QString::fromStdString(musicPageButtonStyles));

			// buttonArtist
			buttonMusicArtist = new QPushButton(frameMusic);
			buttonMusicArtist->setObjectName(QStringLiteral("buttonArtist"));
			buttonMusicArtist->setGeometry(QRect(368, 0, 230, 111));
			buttonMusicArtist->setFlat(true);
			buttonMusicArtist->raise();
			buttonMusicArtist->setText("Artists");
			buttonMusicArtist->setStyleSheet(QString::fromStdString(musicPageButtonStyles));

			// buttonAlbum
			buttonMusicAlbum = new QPushButton(frameMusic);
			buttonMusicAlbum->setObjectName(QStringLiteral("buttonAlbum"));
			buttonMusicAlbum->setGeometry(QRect(678, 0, 230, 111));
			buttonMusicAlbum->setFlat(true);
			buttonMusicAlbum->raise();
			buttonMusicAlbum->setText("Albums");
			buttonMusicAlbum->setStyleSheet(QString::fromStdString(musicPageButtonStyles));

			// buttonSong
			buttonMusicSong = new QPushButton(frameMusic);
			buttonMusicSong->setObjectName(QStringLiteral("buttonSong"));
			buttonMusicSong->setGeometry(QRect(989, 0, 230, 111));
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
			labelCurrentArtist->setGeometry(QRect(0.328*screenWidth, 0.326*screenHeight, 0.572*screenWidth, 0.05556*screenHeight));
			labelCurrentArtist->setAlignment(Qt::AlignLeft|Qt::AlignBottom);
			labelCurrentArtist->setStyleSheet(QString::fromStdString(labelNowPlayingArtistStyle));
//			labelCurrentArtist->setVisible(false);

			// labelCurrentTrack
			labelCurrentTrack = new QLabel(frameNowPlaying);
			labelCurrentTrack->setObjectName(QStringLiteral("labelCurrentTrack"));
			labelCurrentTrack->setGeometry(QRect(0.328*screenWidth, 0.397*screenHeight, 0.572*screenWidth, .101*screenHeight));
			labelCurrentTrack->setAlignment(Qt::AlignLeft);
			labelCurrentTrack->setStyleSheet(QString::fromStdString(labelNowPlayingSongStyle));
//			labelCurrentTrack->setVisible(false);

			// labelCurrentAlbum
			labelCurrentAlbum = new QLabel(frameNowPlaying);
			labelCurrentAlbum->setObjectName(QStringLiteral("labelCurrentAlbum"));
			labelCurrentAlbum->setGeometry(QRect(0.328*screenWidth, 0.507*screenHeight, 0.572*screenWidth, 0.05556*screenHeight));
			labelCurrentAlbum->setAlignment(Qt::AlignLeft);
			labelCurrentAlbum->setStyleSheet(QString::fromStdString(labelNowPlayingAlbumStyle));
//			labelCurrentAlbum->setVisible(false);

			// imageCurrentAlbum
//			labelCurrentAlbum->
			imageCurrentAlbum = new QLabel(frameNowPlaying);
			imageCurrentAlbum->setObjectName(QStringLiteral("imageCurrentAlbum"));
			imageCurrentAlbum->setGeometry(QRect(0.06543*screenWidth, 0.230*screenHeight, 0.233*screenWidth, 0.4148*screenHeight));
			imageCurrentAlbum->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);
//			labelCurrentAlbum->setStyleSheet(QString::fromStdString(labelNowPlayingAlbumStyle));

			// buttonMusicPlayPause
			buttonMusicPlayPause = new QPushButton(frameNowPlaying);
			buttonMusicPlayPause->setObjectName(QStringLiteral("buttonMusicPlayPause"));
			buttonMusicPlayPause->setGeometry(QRect(950, 30, 65, 65));
			buttonMusicPlayPause->setFlat(true);
			buttonMusicPlayPause->setStyleSheet(QLatin1String("background-image: url(./resources/icons/play.png);\n"
															  "background-repeat: no-repeat;"));
//			buttonMusicPlayPause->setVisible(false);





			// buttonMusicNext
			buttonMusicNext = new QPushButton(frameNowPlaying);
			buttonMusicNext->setObjectName(QStringLiteral("buttonMusicNext"));
			buttonMusicNext->setGeometry(QRect(1070, 30, 65, 65));
			buttonMusicNext->setFlat(true);
			buttonMusicNext->setStyleSheet(QLatin1String("background-image: url(./resources/icons/next.png);\n"
														 "background-repeat: no-repeat;"));
//			buttonMusicNext->setVisible(false);





			// buttonVolumeUp
			buttonVolumeUp = new QPushButton(frameNowPlaying);
			buttonVolumeUp->setObjectName(QStringLiteral("buttonVolumeUp"));
			buttonVolumeUp->setGeometry(QRect(1190, 30, 65, 65));
			buttonVolumeUp->setFlat(true);
			buttonVolumeUp->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volUp.png);\n"
														"background-repeat: no-repeat;"));
//			buttonVolumeUp->setVisible(false);





			// buttonVolumeDown
			buttonVolumeDown = new QPushButton(frameNowPlaying);
			buttonVolumeDown->setObjectName(QStringLiteral("buttonVolumeDown"));
			buttonVolumeDown->setGeometry(QRect(710, 30, 65, 65));
			buttonVolumeDown->setFlat(true);
			buttonVolumeDown->setStyleSheet(QLatin1String("background-image: url(./resources/icons/volDown.png);\n"
														  "background-repeat: no-repeat;"));
//			buttonVolumeDown->setVisible(false);





			// buttonMusicPrevious
			buttonMusicPrevious = new QPushButton(frameNowPlaying);
			buttonMusicPrevious->setObjectName(QStringLiteral("buttonMusicPrevious"));
			buttonMusicPrevious->setGeometry(QRect(830, 30, 65, 65));
			buttonMusicPrevious->setFlat(true);
			buttonMusicPrevious->setStyleSheet(QLatin1String("background-image: url(./resources/icons/previous.png);\n"
															 "background-repeat: no-repeat;"));
//			buttonMusicPrevious->setVisible(false);





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



			// buttonBack
			buttonBack = new QPushButton(frameBottomBar);
			buttonBack->setObjectName(QStringLiteral("buttonBack"));
			buttonBack->setGeometry(QRect(58, 0, 230, 111));
			buttonBack->setFlat(true);
			buttonBack->raise();
			buttonBack->setStyleSheet(QLatin1String("background-image: url(./resources/icons/back.png);\n"
													"background-repeat: no-repeat;\n"
													"background-position: center;"));











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



			// buttonQuit
			// This is technically part of the top bar
			// but is only shown on the home page to
			// avoid accidentally quitting the program
			buttonQuit = new QPushButton(frameTopBar);
			buttonQuit->setObjectName(QStringLiteral("buttonQuit"));
			buttonQuit->setGeometry(QRect(0.0185*screenWidth, 0.0185*screenHeight, 0.1*screenWidth, 0.05*screenHeight));
			buttonQuit->setStyleSheet(QString::fromStdString(topBarLabelStyles));






			// -------------------------------------------------------------------------------------------------------------
			// Right Bar
			// -------------------------------------------------------------------------------------------------------------

			int frameRightBarWidth = 0.05325*screenWidth;
			int frameRightBarHeight = screenHeight;
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
