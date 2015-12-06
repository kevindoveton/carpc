// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassSong.h"

void song :: getSongTags(std::string path, std::string& title, std::string& album, std::string& artist)
{
	// initialise variables
	std::stringstream sstr;
	sstr.str("");

	// set path to file
	TagLib::FileRef f(path.c_str());

	// artist
	sstr << f.tag()->artist();
	artist = sstr.str();

	// album
	sstr.str("");
	sstr << f.tag()->album();
	album = sstr.str();

	// title
	sstr.str("");
	sstr << f.tag()->title();
	title = sstr.str();
}
