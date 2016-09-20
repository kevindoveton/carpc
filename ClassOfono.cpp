#include "ClassOfono.h"

Ofono :: Ofono(QObject *parent)
{
	_modemPath = MODEM_PATH;
	OrgOfonoVoiceCallManagerInterface *voicecallManager = new OrgOfonoVoiceCallManagerInterface("org.ofono", MODEM_PATH, QDBusConnection::systemBus());
	connect(voicecallManager, SIGNAL(CallAdded(QDBusObjectPath, QVariantMap)), this, SLOT(CallAdded(const QDBusObjectPath, const QVariantMap)));
	connect(voicecallManager, SIGNAL(CallRemoved(QDBusObjectPath)), this, SLOT(CallRemoved(const QDBusObjectPath)));
}

void Ofono :: setPowerOn()
{
	OrgOfonoModemInterface *ofono = new OrgOfonoModemInterface("org.ofono", _modemPath, QDBusConnection::systemBus());
	ofono->SetProperty("Powered", QDBusVariant(bool(true)));
}

void Ofono :: setPowerOff()
{
	OrgOfonoModemInterface *ofono = new OrgOfonoModemInterface("org.ofono", _modemPath, QDBusConnection::systemBus());
	ofono->SetProperty("Powered", QDBusVariant(bool(false)));
}

void Ofono :: listModems()
{
//	OrgOfonoManagerInterface *ofono = new OrgOfonoManagerInterface("org.ofono", "/", QDBusConnection::systemBus());
//	qDebug() << ofono->GetModems();
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

void Ofono :: CallAdded(const QDBusObjectPath &object, const QVariantMap &values)
{
	qDebug() << "call added";
	qDebug() << values;
	QString name = values["Name"].toString();
	QString number = values["LineIdentification"].toString();
	emit incomingCall(name, number);
}

void Ofono :: CallRemoved(const QDBusObjectPath &object)
{
	qDebug() << "call removed";
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
