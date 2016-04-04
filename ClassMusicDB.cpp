// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassMusicDB.h"

void MusicDB :: getArtists(QStandardItemModel* model)
{
	// TO DO
	// Set background pictures from db


	int indexCount = 1;
	model->setColumnCount(2);

	// All Albums -> In Artist View
	model->setRowCount(indexCount);
	model->setData(model->index((indexCount-1), 0), QString::fromStdString("All Albums"));
	model->setData(model->index((indexCount-1), 1), (-1));
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT artistName, artistID, artistImagePath FROM artists");


		while (query.executeStep())
		{
			//			artistIDCur = query.getColumn(1);


			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);
			std::string imageColumn = query.getColumn(2);
//			std::cout << imageColumn << std::endl;
			QPixmap artistImage;
			artistImage.load(QString::fromStdString(imageColumn));
			model->setData(model->index((indexCount-1), 1), (column1));
			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
			model->setData(model->index((indexCount-1), 0), artistImage, Qt::DecorationRole);


		}

	}



	catch (std::exception& e)
	{
		std::cout << "getArtists - Exception: " << e.what() << std::endl;

	}
}

void MusicDB :: getSongPath(int songID, SongData& currentSong)
{
	std::cout << songID << std::endl;
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT * FROM library INNER JOIN songs\
									ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID WHERE songs.songID == ?");
		query.bind(1, songID);

		while (query.executeStep())
		{

			std::string album = query.getColumn(15);
			std::string artist = query.getColumn(19);
			int bitRate = query.getColumn(5);
			int ID = query.getColumn(0);
			std::string kind = query.getColumn(7);
			std::string lastPlayed = "";
			int length = query.getColumn(9);
			std::string path = query.getColumn(1);
			int playCount = query.getColumn(4);
			int rating = query.getColumn(2);
			int sampleRate = query.getColumn(6);
			int skipCount = query.getColumn(3);
			std::string song = query.getColumn(12);
			/*for (int i = 0; i < 20; i++)
				std::cout << "Column " << i << " " << query.getColumn(i) << std::endl*/;

			currentSong.set(ID, artist, album, song, path, rating, playCount, skipCount, kind, bitRate, lastPlayed, sampleRate, length);
			std::cout << currentSong.dump() << std::endl;
		}

	}



	catch (std::exception& e)
	{
		std::cout << "getSongPath - Exception: " << e.what() << std::endl;

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


	int indexCount = 1;
	model->setColumnCount(2);

	// Artists
	model->setRowCount(indexCount);
	model->setData(model->index((indexCount-1), 0), QString::fromStdString("All Songs"));
	model->setData(model->index((indexCount-1), 1), (-1));

	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT albumName, albumID, albumImagePath FROM albums WHERE artistID == ?");
		query.bind(1, artistID);

		while (query.executeStep())
		{
			//			albumIDCur = query.getColumn(1);
			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			int column1 = query.getColumn(1);
			std::string imageColumn = query.getColumn(2);
//			std::cout << imageColumn << std::endl;
			QPixmap albumImage;
			albumImage.load(QString::fromStdString(imageColumn));

			model->setData(model->index((indexCount-1), 1), (column1));
			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
			model->setData(model->index((indexCount-1), 0), albumImage, Qt::DecorationRole);


		}
	}



	catch (std::exception& e)
	{
		std::cout << "getAlbums - Exception: " << e.what() << std::endl;

	}
}

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

void MusicDB :: shuffleAlbum(int currentSongID, std::vector<SongData>& playlist)
{
	int albumIDCur;
	try
	{
		SQLite::Database db(DBPATH);
		SQLite::Statement query(db, "SELECT albums.albumID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID WHERE songs.songID == ?");
		query.bind(1, currentSongID);

		while (query.executeStep())
		{
			albumIDCur = query.getColumn(0);
		}

		SQLite::Statement songQuery(db, "SELECT songs.songID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID WHERE albums.albumID == ? ORDER BY RANDOM()");
		songQuery.bind(1, albumIDCur);

		while (songQuery.executeStep())
		{
			int curQuery = songQuery.getColumn(0);
			if (curQuery != currentSongID)
			{
				SongData temp;
				getSongPath(curQuery, temp);
				playlist.push_back(temp);
			}
		}
	}

	catch (std::exception& e)
	{
		std::cout << "shuffleAlbum - exception: " << e.what() << std::endl;
	}
}

void MusicDB :: shuffleAll(int currentSongID, std::vector<SongData>& playlist)
{
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement songQuery(db, "SELECT songs.songID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID ORDER BY RANDOM()");

		while (songQuery.executeStep())
		{
			int curQuery = songQuery.getColumn(0);
			if (curQuery != currentSongID)
			{
				SongData temp;
				getSongPath(curQuery, temp);
				playlist.push_back(temp);
			}
		}
	}

	catch (std::exception& e)
	{
		std::cout << "shuffleAlbum - exception: " << e.what() << std::endl;
	}
}

void MusicDB :: shuffleArtist(int currentSongID, std::vector<SongData>& playlist)
{
	int artistIDCur;
	try
	{
		SQLite::Database db(DBPATH);
		SQLite::Statement query(db, "SELECT artists.artistID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID WHERE songs.songID == ?");
		query.bind(1, currentSongID);

		while (query.executeStep())
		{
			artistIDCur = query.getColumn(0);
		}

		SQLite::Statement songQuery(db, "SELECT songs.songID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID WHERE artists.artistID == ? ORDER BY RANDOM()");
		songQuery.bind(1,artistIDCur);

		while (songQuery.executeStep())
		{
			int curQuery = songQuery.getColumn(0);
			if (curQuery != currentSongID)
			{
				SongData temp;
				getSongPath(curQuery, temp);
				playlist.push_back(temp);
			}
		}
	}

	catch (std::exception& e)
	{
		std::cout << "shuffleAlbum - exception: " << e.what() << std::endl;
	}
}


void MusicDB :: getAllAlbums(QStandardItemModel* model)
{
	int indexCount = 1;
	model->setColumnCount(2);

	model->setRowCount(indexCount);
	model->setData(model->index((indexCount-1), 0), QString::fromStdString("All Songs"));
	model->setData(model->index((indexCount-1), 1), (-1));

	try
	{
		SQLite::Database db(DBPATH);
		SQLite::Statement query(db, "SELECT DISTINCT albums.albumName, albums.albumID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID");

		while (query.executeStep())
		{
			indexCount++;
			model->setRowCount(indexCount);
			std::string column0 = query.getColumn(0);
			std::cout << column0 << std::endl;
			int column1 = query.getColumn(1);

			model->setData(model->index((indexCount-1), 1), (column1));
			model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
			// model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);
		}

	}

	catch (std::exception& e)
	{
		std::cout << "getAllAlbums - exception: " << e.what() << std::endl;
	}
}



void MusicDB :: getAllSongs(QStandardItemModel* model, int artistID)
{
	int indexCount = 0;
	model->setColumnCount(2);

	try
	{
		SQLite::Database db(DBPATH);
		if (artistID != -1)
		{
			SQLite::Statement query(db, "SELECT DISTINCT songs.songName, songs.songID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID WHERE artists.artistID == ?");
			query.bind(1, artistID);

			while (query.executeStep())
			{
				indexCount++;
				model->setRowCount(indexCount);
				std::string column0 = query.getColumn(0);
				int column1 = query.getColumn(1);

				model->setData(model->index((indexCount-1), 1), (column1));
				model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
				// model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);
			}
		}
		
		else
		{
			SQLite::Statement query(db, "SELECT DISTINCT songs.songName, songs.songID FROM library INNER JOIN songs ON library.songID = songs.songID INNER JOIN albums ON songs.albumID = albums.albumID INNER JOIN artists ON artists.artistID = albums.artistID");

			while (query.executeStep())
			{
				indexCount++;
				model->setRowCount(indexCount);
				std::string column0 = query.getColumn(0);
				int column1 = query.getColumn(1);

				model->setData(model->index((indexCount-1), 1), (column1));
				model->setData(model->index((indexCount-1), 0), QString::fromStdString(column0));
				// model.setData(model.index(indexCount, 0), QPixmap(query.getColumn(1)), Qt::DecorationRole);
			}
		}
		
		

	}

	catch (std::exception& e)
	{
		std::cout << "getAllSongs - exception: " << e.what() << std::endl;
	}
}


void MusicDB :: setPlayCount(int playCount, int songID)
{
	if (playCount == NULL)
	{
		playCount = 0;
	}

	try
	{
		SQLite::Database db(DBPATH, SQLITE_OPEN_READWRITE);
		SQLite::Transaction transaction(db);
		SQLite::Statement query(db, "UPDATE library SET playCount = ? WHERE songID = ?");
		query.bind(1, playCount);
		query.bind(2, songID);
		query.exec();

		transaction.commit();
	}

	catch (std::exception& e)
	{
		std::cout << "updatePlayCount - exception: " << e.what() << std::endl;
	}
}

void MusicDB :: setSkipCount(int skipCount, int songID)
{
	if (skipCount == NULL)
	{
		skipCount = 0; // 
	}

	try
	{
		SQLite::Database db(DBPATH, SQLITE_OPEN_READWRITE);
		SQLite::Transaction transaction(db);
		SQLite::Statement query(db, "UPDATE library SET skipCount = ? WHERE songID = ?");

		query.bind(1, skipCount);
		query.bind(2, songID);
		query.exec();

		transaction.commit();
	}

	catch (std::exception& e)
	{
		std::cout << "updateSkipCount - exception: " << e.what() << std::endl;
	}
}

void MusicDB :: setRating(float rating, int songID)
{
	if (rating == NULL)
	{
		rating = 0;
	}
	try
	{
		SQLite::Database db(DBPATH, SQLITE_OPEN_READWRITE);
		SQLite::Transaction transaction(db);
		SQLite::Statement query(db, "UPDATE library SET rating = ? WHERE songID = ?");

		query.bind(1, rating);
		query.bind(2, songID);
		query.exec();

		transaction.commit();
	}

	catch (std::exception& e)
	{
		std::cout << "updateRating - exception: " << e.what() << std::endl;
	}
}

