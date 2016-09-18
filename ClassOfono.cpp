#include "ClassOfono.h"

Ofono :: Ofono(QObject *parent)
{

}

void Ofono :: setPowerOn()
{
	OrgOfonoModemInterface *ofono = new OrgOfonoModemInterface("org.ofono", MODEM_PATH, QDBusConnection::systemBus());
	ofono->SetProperty("Powered", QDBusVariant(bool(true)));
}

void Ofono :: setPowerOff()
{
	OrgOfonoModemInterface *ofono = new OrgOfonoModemInterface("org.ofono", MODEM_PATH, QDBusConnection::systemBus());
	ofono->SetProperty("Powered", QDBusVariant(bool(false)));
}

QString Ofono :: getPhoneNumber(QString id)
{

}

void Ofono :: dialNumber(QString number)
{
	OrgOfonoVoiceCallManagerInterface *ofono = new OrgOfonoVoiceCallManagerInterface("org.ofono", MODEM_PATH, QDBusConnection::systemBus());
	ofono->Dial(number, "default");
	qDebug() << "Dialing: " << number;
}

//void Ofono :: answerCall(QString id)
//{
//	OrgOfonoVoiceCallManagerInterface voicecall("org.ofono", id, QDBusConnction::systemBus());
//	voicecall.Answer();
//}

//void Ofono :: hangupCall(QString id)
//{
//	OrgOfonoVoiceCallManagerInterface voicecall("org.ofono", id, QDBusConnction::systemBus());
//	voicecall.Hangup();
//}
