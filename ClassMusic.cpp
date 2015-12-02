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

void Song Data :: setID(int ID)
{
	id = ID;
}

int SongData :: getID()
{
	return id;
}


void Song Data :: setArtist(std::string ARTIST)
{
	artist = ARTIST;
}

std::string Song Data :: getArtist()
{
	return artist;
}


void Song Data :: setAlbum(std::string ALBUM)
{
	album = ALBUM;
}

std::string Song Data :: getAlbum()
{
	return album;
}


void Song Data :: setSong(std::string SONG)
{
	song = SONG;
}

std::string Song Data :: getSong()
{
	return song;
}


void Song Data :: setPath(std::string PATH)
{
	path = PATH;
}

std::string Song Data :: getPath()
{
	return path;
}


void Song Data :: setRating(int RATING)
{
	rating = RATING;
}

int Song Data :: getRating()
{
	return rating;
}


void Song Data :: setPlayCount(int PLAYCOUNT)
{
	playCount = PLAYCOUNT;
}

int Song Data :: getPlayCount()
{
	return playCount;
}


void Song Data :: setSkipCount(int SKIPCOUNT)
{
	skipCount = SKIPCOUNT;
}

int Song Data :: getSkipCount()
{
	return skipCount;
}


void Song Data :: setKind(std::string KIND)
{
	kind = KIND;
}

std::string Song Data :: getKind()
{
	return kind;
}

void Song Data :: setBitRate(int BITRATE)
{
	bitRate = BITRATE;
}

int Song Data :: getBitRate()
{
	return bitRate;
}


void Song Data :: setLastPlayed(std::string LASTPLAYED)
{
	lastPlayed = LASTPLAYED;
}

std::string Song Data :: getLastPlayed()
{
	return lastPlayed;
}

void Song Data :: setSampleRate(int SAMPLERATE)
{
	sampleRate = SAMPLERATE;
}

int Song Data :: getSampleRate()
{
	return sampleRate;
}

void Song Data :: setLength(int LENGTH)
{
	length = LENGTH;
}

int Song Data :: getLength()
{
	return length;
}

void Song Data :: get(int& ID, std::string& ARTIST, std::string& ALBUM, std::string& SONG, std::string& PATH, int& RATING, int& PLAYCOUNT, int& SKIPCOUNT, std::string& KIND, int& BITRATE, std::string& LASTPLAYED, int& SAMPLERATE, int& LENGTH)
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

void Song Data :: set(int ID, std::string ARTIST, std::string ALBUM, std::string SONG, std::string PATH, int RATING, int PLAYCOUNT, int SKIPCOUNT, std::string KIND, int BITRATE, std::string LASTPLAYED, int SAMPLERATE, int LENGTH)
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

std::string Song Data :: dump(std::string info = "all")
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
