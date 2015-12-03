#include "ClassMusicDB.h"

void MusicDB :: getAllArtists(QStandardItemModel* model)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 0;
	model->setColumnCount(2);
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT artistName, artistID FROM artists");


		while (query.executeStep())
		{
			//			artistIDCur = query.getColumn(1);


			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);


			model->setData(model->index((indexCount-1), 1), (column1));

			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
			//			model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);

		}

	}



	catch (std::exception& e)
	{
		std::cout << "getAllArtists - Exception: " << e.what() << std::endl;

	}
}

void MusicDB :: getSongPath(int songID, SongData& currentSong)
{
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT * FROM library WHERE songID == ?");
		query.bind(1, songID);

		while (query.executeStep())
		{
			\
			std::string album = "";
			std::string artist = "";
			int bitRate = query.getColumn(5);
			int ID = query.getColumn(0);
			std::string kind = "";
			std::string lastPlayed = "";
			int length = query.getColumn(9);
			std::string path = query.getColumn(1);
			int playCount = query.getColumn(4);
			int rating = query.getColumn(2);
			int sampleRate = 0;
			int skipCount = query.getColumn(3);
			std::string song;


			currentSong.set(ID, artist, album, song, path, rating, playCount, skipCount, kind, bitRate, lastPlayed, sampleRate, length);
			std::cout << currentSong.dump();
		}

	}



	catch (std::exception& e)
	{
		std::cout << "getAllArtists - Exception: " << e.what() << std::endl;

	}


	return ;
}

void MusicDB :: getSongs(QStandardItemModel* model, int albumID)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 0;
	model->setColumnCount(2);
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT songName, songID FROM songs WHERE albumID == ?");
		query.bind(1, albumID);

		while (query.executeStep())
		{
			//			songIDCur = query.getColumn(1);
			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);

			model->setData(model->index((indexCount-1), 1), (column1));
			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
			//			model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);

		}
	}

	catch (std::exception& e)
	{
		std::cout << "getSongs - Exception: " << e.what() << std::endl;

	}

}

void MusicDB :: getAlbums(QStandardItemModel* model, int artistID)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 0;
	model->setColumnCount(2);
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT albumName, albumID FROM albums WHERE artistID == ?");
		query.bind(1, artistID);

		while (query.executeStep())
		{
			//			albumIDCur = query.getColumn(1);
			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);

			model->setData(model->index((indexCount-1), 1), (column1));

			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
			//			model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);

		}

	}



	catch (std::exception& e)
	{
		std::cout << "getAlbums - Exception: " << e.what() << std::endl;

	}
}

/*void MusicDB :: getAllArtist(std::string path, QStringList& stringlist)
{
	artists.clear();
	std::stringstream hello;
	try
	{
		SQLite::Database db(path);

		SQLite::Statement query(db, "SELECT artist FROM music");

		while (query.executeStep())
		{
			hello.str("");
			hello << query.getColumn(0);
			stringlist << hello.str().c_str();
		}
	}

	catch (std::exception& e)
	{
		std::cout << "Get Artist - Exception: " << e.what() << std::endl;

	}
}*/

bool MusicDB :: getPlaylist(std::string path)
{
	try
	{
		SQLite::Database db(path);

		SQLite::Statement query(db, "SELECT * FROM artists");

		while (query.executeStep())
		{
			SongData temp;
			temp.set(query.getColumn(0), query.getColumn(1), query.getColumn(2), query.getColumn(3), query.getColumn(4), query.getColumn(5), query.getColumn(6), query.getColumn(7), query.getColumn(8), query.getColumn(9), query.getColumn(10), query.getColumn(11), query.getColumn(12));
//			musicDB.push_back(temp);
		}
	}

	catch (std::exception& e)
	{
		std::cout << "getPlaylist - exception: " << e.what() << std::endl;
		return false;

	}
	return true;
}

