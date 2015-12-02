#include <string>								// Strings - STD :: String
#include <sstream>								// String Streams - STD :: stringstream
#include <taglib/tag.h>							// Taglib (ID3 Tags)
#include <taglib/taglib.h>						// Taglib
#include <taglib/tstring.h>						// Taglib
#include <taglib/fileref.h>						// Taglib

class song
{
	public:
		std::string title;
		std::string artist;
		std::string album;
		std::string path;
		bool playing;


		void getSongTags(std::string path, std::string& title, std::string& album, std::string& artist);
};
