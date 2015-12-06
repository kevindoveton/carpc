// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassMusic.h"

void SongData :: setID(int ID)
{
	id = ID;
}

int SongData :: getID()
{
	return id;
}

void SongData :: setArtist(std::string ARTIST)
{
	artist = ARTIST;
}

std::string SongData :: getArtist()
{
	return artist;
}

void SongData :: setAlbum(std::string ALBUM)
{
	album = ALBUM;
}

std::string SongData :: getAlbum()
{
	return album;
}

void SongData :: setTitle(std::string SONG)
{
	song = SONG;
}

std::string SongData :: getTitle()
{
	return song;
}

void SongData :: setPath(std::string PATH)
{
	path = PATH;
}

std::string SongData :: getPath()
{
	return path;
}

void SongData :: setRating(int RATING)
{
	rating = RATING;
}

int SongData :: getRating()
{
	return rating;
}

void SongData :: setPlayCount(int PLAYCOUNT)
{
	playCount = PLAYCOUNT;
}

int SongData :: getPlayCount()
{
	return playCount;
}

void SongData :: setSkipCount(int SKIPCOUNT)
{
	skipCount = SKIPCOUNT;
}

int SongData :: getSkipCount()
{
	return skipCount;
}

void SongData :: setKind(std::string KIND)
{
	kind = KIND;
}

std::string SongData :: getKind()
{
	return kind;
}

void SongData :: setBitRate(int BITRATE)
{
	bitRate = BITRATE;
}

int SongData :: getBitRate()
{
	return bitRate;
}

void SongData :: setLastPlayed(std::string LASTPLAYED)
{
	lastPlayed = LASTPLAYED;
}

std::string SongData :: getLastPlayed()
{
	return lastPlayed;
}

void SongData :: setSampleRate(int SAMPLERATE)
{
	sampleRate = SAMPLERATE;
}

int SongData :: getSampleRate()
{
	return sampleRate;
}

void SongData :: setLength(int LENGTH)
{
	length = LENGTH;
}

int SongData :: getLength()
{
	return length;
}

void SongData :: get(int& ID, std::string& ARTIST, std::string& ALBUM, std::string& SONG, std::string& PATH, int& RATING, int& PLAYCOUNT, int& SKIPCOUNT, std::string& KIND, int& BITRATE, std::string& LASTPLAYED, int& SAMPLERATE, int& LENGTH)
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

void SongData :: set(int ID, std::string ARTIST, std::string ALBUM, std::string SONG, std::string PATH, int RATING, int PLAYCOUNT, int SKIPCOUNT, std::string KIND, int BITRATE, std::string LASTPLAYED, int SAMPLERATE, int LENGTH)
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

std::string SongData :: dump(std::string info)
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
