#include "ClassOfono.h"

ClassOfono :: ClassOfono(QObject *parent)
{

}

void ClassOfono :: dialNumber(QString number)
{
	OrgOfonoVoiceCallManagerInterface *ofono = new OrgOfonoVoiceCallManagerInterface("org.ofono", MODEM_PATH, QDBusConnection::systemBus());
	ofono->Dial(number, "default");
	qDebug() << "Dialing: " << number;
}
