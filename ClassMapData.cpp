#include "ClassMapData.h"

MapData::MapData(QString accessToken)
{
	_apiAddress = "https://api.mapbox.com/";
	_accessToken = accessToken;
}

void MapData :: addressToCoordinates(QString address)
{
	address = address.replace(" ", "+");
	QUrl url = QUrl(_apiAddress + "geocoding/v5/mapbox.places/" + address + ".json?country=au&access_token="+_accessToken);
	_reply = manager->get(QNetworkRequest(url));
	connect(_reply, SIGNAL(finished()), this, SLOT(handleData()));
}

void MapData :: coordinatesToAddress(QString x, QString y)
{
	QUrl url = QUrl(_apiAddress + "geocoding/v5/mapbox.places/" + x + "," + y + ".json?country=au&access_token="+_accessToken);
	_reply = manager->get(QNetworkRequest(url));
	connect(_reply, SIGNAL(finished()), this, SLOT(handleData()));
}

void MapData :: coordinatesToAddress(QMapbox::Coordinate coordinates)
{
//	coordinatesToAddress(QString(coordinates.first), QString(coordinates.second));
}

void MapData :: handleData()
{
	qDebug() << _reply->readAll();
}
