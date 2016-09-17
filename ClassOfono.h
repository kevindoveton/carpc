#ifndef CLASSOFONO_H
#define CLASSOFONO_H

#include <QtDBus>
#include <QObject>
#include <QDebug>

#include "dbus/OfonoCallVolume.h"
#include "dbus/OfonoHandsFree.h"
#include "dbus/OfonoModem.h"
#include "dbus/OfonoNetworkRegistration.h"
#include "dbus/OfonoSiri.h"
#include "dbus/OfonoVoiceCallManager.h"


#define MODEM_PATH "/hfp/org/bluez/hci0/dev_CC_20_E8_CA_93_FF"

class ClassOfono : public QObject
{
	Q_OBJECT
	public:
		ClassOfono(QObject *parent = 0);
//		~ClassOfono();

		void dialNumber(QString number);
};

#endif // CLASSOFONO_H
