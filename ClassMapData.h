#ifndef MAPDATA_H
#define MAPDATA_H

#include <QNetworkAccessManager>
#include <QMapbox>
#include <QUrl>
#include <QNetworkReply>
#include <QIODevice>
#include <QObject>

class MapData : QObject
{
	Q_OBJECT
	public:
		MapData(QString accessToken);

		void addressToCoordinates(QString address);
		void coordinatesToAddress(QString x, QString y);
		void coordinatesToAddress(QMapbox::Coordinate coordinates);

	private slots:
		void handleData();

	protected:
		QNetworkAccessManager *manager = new QNetworkAccessManager();
		QString _accessToken;
		QString _apiAddress;
		QNetworkReply *_reply;
};

#endif // MAPDATA_H
