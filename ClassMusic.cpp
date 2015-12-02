//
//  xmldata.hpp
//  xmlTest
//
//  Created by Kevin Doveton on 16/07/2015.
//  Copyright © 2015 Kevin Doveton. All rights reserved.
//

#ifndef ClassMusic_cpp
#define ClassMusic_cpp

#include "ClassMusic.h"
class SongData
{

	public:
		void setID(int ID)
		{
			id = ID;
		}

		int getID()
		{
			return id;
		}


		void setArtist(std::string ARTIST)
		{
			artist = ARTIST;
		}

		std::string getArtist()
		{
			return artist;
		}


		void setAlbum(std::string ALBUM)
		{
			album = ALBUM;
		}

		std::string getAlbum()
		{
			return album;
		}


		void setSong(std::string SONG)
		{
			song = SONG;
		}

		std::string getSong()
		{
			return song;
		}


		void setPath(std::string PATH)
		{
			path = PATH;
		}

		std::string getPath()
		{
			return path;
		}


		void setRating(int RATING)
		{
			rating = RATING;
		}

		int getRating()
		{
			return rating;
		}


		void setPlayCount(int PLAYCOUNT)
		{
			playCount = PLAYCOUNT;
		}

		int getPlayCount()
		{
			return playCount;
		}


		void setSkipCount(int SKIPCOUNT)
		{
			skipCount = SKIPCOUNT;
		}

		int getSkipCount()
		{
			return skipCount;
		}


		void setKind(std::string KIND)
		{
			kind = KIND;
		}

		std::string getKind()
		{
			return kind;
		}




		void setBitRate(int BITRATE)
		{
			bitRate = BITRATE;
		}

		int getBitRate()
		{
			return bitRate;
		}


		void setLastPlayed(std::string LASTPLAYED)
		{
			lastPlayed = LASTPLAYED;
		}

		std::string getLastPlayed()
		{
			return lastPlayed;
		}



		void setSampleRate(int SAMPLERATE)
		{
			sampleRate = SAMPLERATE;
		}

		int getSampleRate()
		{
			return sampleRate;
		}


		void setLength(int LENGTH)
		{
			length = LENGTH;
		}

		int getLength()
		{
			return length;
		}


		void get(int& ID, std::string& ARTIST, std::string& ALBUM, std::string& SONG, std::string& PATH, int& RATING, int& PLAYCOUNT, int& SKIPCOUNT, std::string& KIND, int& BITRATE, std::string& LASTPLAYED, int& SAMPLERATE, int& LENGTH)
		{
			// get the object
			ID = id;
			ARTIST = artist;
			ALBUM = album;
			SONG = song;
			PATH = path;
			RATING = rating;
			PLAYCOUNT = playCount;
			SKIPCOUNT = skipCount;
			KIND = kind;
			BITRATE = bitRate;
			LASTPLAYED = lastPlayed;
			SAMPLERATE = sampleRate;
			LENGTH = length;
		}


		void set(int ID, std::string ARTIST, std::string ALBUM, std::string SONG, std::string PATH, int RATING, int PLAYCOUNT, int SKIPCOUNT, std::string KIND, int BITRATE, std::string LASTPLAYED, int SAMPLERATE, int LENGTH)
		{
			// set the object
			id = ID;
			artist = ARTIST;
			album = ALBUM;
			song = SONG;
			path = PATH;
			rating = RATING;
			playCount = PLAYCOUNT;
			skipCount = SKIPCOUNT;
			kind = KIND;
			bitRate = BITRATE;
			lastPlayed = LASTPLAYED;
			sampleRate = SAMPLERATE;
			length = LENGTH;
		}

		std::string dump(std::string info = "all")
		{
			std::stringstream returnValue;
			returnValue.str("");

			if (info == "all")
				returnValue << "id: " << (id) << ", artist: " << artist << ", album: " << album << ", song: " << song << ", path: " << path << ", rating: " << rating << ", playCount: " << playCount << ", skipCount: " << skipCount << ", kind: " << kind << ", bitRate: " << bitRate << ", lastPlayed: " << lastPlayed << ", sampleRate: " << sampleRate << ", length: " << length;

			else if(info == "id")
				returnValue << id;

			else if (info == "artist")
				returnValue << artist;

			else if (info == "album")
				returnValue << album;

			else if (info == "song")
				returnValue << song;

			else if (info == "path")
				returnValue << path;

			else if (info == "rating")
				returnValue << rating;

			else if ((info == "playCount") || (info == "playcount"))
				returnValue << playCount;

			else if ((info == "skipCount") || (info == "skipcount"))
				returnValue << skipCount;

			else if (info == "kind")
				returnValue << kind;

			else if (info == "bitrate")
				returnValue << bitRate;

			else if (info == "lastplayed")
				returnValue << lastPlayed;

			else if (info == "samplerate")
				returnValue << sampleRate;

			else if (info == "length")
				returnValue << length;
			else
				returnValue.str("failed");


			return returnValue.str();
		}

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
