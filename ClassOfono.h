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
#include "dbus/OfonoManager.h"
#include "dbus/OfonoVoiceCall.h"

#include "ClassVoicecall.h"


#define MODEM_PATH "/hfp/org/bluez/hci0/dev_8C_8E_F2_C8_ED_FA"

class Ofono : public QObject
{
	Q_OBJECT
	public:
		Ofono(QObject *parent = 0);

		void setPowerOn();
		void setPowerOff();
		void listModems();
		void dialNumber(QString number);

	protected:
		QString _modemPath;

	signals:
		void incomingCall(QString number);

	public slots:
		void CallAdded(const QDBusObjectPath &object, const QVariantMap &values);
		void CallRemoved(const QDBusObjectPath &object);
};

#endif // CLASSOFONO_H

