//
//  xmldata.hpp
//  xmlTest
//
//  Created by Kevin Doveton on 16/07/2015.
//  Copyright © 2015 Kevin Doveton. All rights reserved.
//

#ifndef ClassMusic_cpp
#define ClassMusic_cpp

#include <stdio.h>
#include <chrono>
#include <sstream>

class SongData
{

	public:
		void setID(int ID);

		int getID();

		void setArtist(std::string ARTIST);

		std::string getArtist();

		void setAlbum(std::string ALBUM);

		std::string getAlbum();

		void setSong(std::string SONG);

		std::string getSong();

		void setPath(std::string PATH);

		std::string getPath();

		void setRating(int RATING);

		int getRating();

		void setPlayCount(int PLAYCOUNT);

		int getPlayCount();

		void setSkipCount(int SKIPCOUNT);

		int getSkipCount();

		void setKind(std::string KIND);

		std::string getKind();

		void setBitRate(int BITRATE);

		int getBitRate();

		void setLastPlayed(std::string LASTPLAYED);

		std::string getLastPlayed();

		void setSampleRate(int SAMPLERATE);

		int getSampleRate();

		void setLength(int LENGTH);

		int getLength();

		void get(int& ID, std::string& ARTIST, std::string& ALBUM, std::string& SONG, std::string& PATH, int& RATING, int& PLAYCOUNT, int& SKIPCOUNT, std::string& KIND, int& BITRATE, std::string& LASTPLAYED, int& SAMPLERATE, int& LENGTH);

		void set(int ID, std::string ARTIST, std::string ALBUM, std::string SONG, std::string PATH, int RATING, int PLAYCOUNT, int SKIPCOUNT, std::string KIND, int BITRATE, std::string LASTPLAYED, int SAMPLERATE, int LENGTH);

		std::string dump(std::string info = "all");

	private:
		int id;
		std::string artist;
		std::string album;
		std::string song;
		std::string path;
		int rating;
		int playCount;
		int skipCount;
		std::string kind;
		int bitRate;
		std::string lastPlayed; // this needs to be date time..
		int sampleRate;
		int length;
};

#endif /* xmldata_cpp */
