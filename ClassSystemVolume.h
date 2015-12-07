#ifndef CLASSSYSTEMVOLUME_H
#define CLASSSYSTEMVOLUME_H
#include <alsa/asoundlib.h>
#include <alsa/asoundlib.h>
#include <iostream>
class SystemVolume
{
	public:
		void setMasterVolume(long volume);
		long getCurrentVolume();
};

#endif // CLASSSYSTEMVOLUME_H
