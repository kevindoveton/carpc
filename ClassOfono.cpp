#include "ClassOfono.h"

Ofono :: Ofono(QObject *parent)
{
	_modemPath = MODEM_PATH;
	OrgOfonoVoiceCallManagerInterface *voicecallManager = new OrgOfonoVoiceCallManagerInterface("org.ofono", _modemPath, QDBusConnection::systemBus());
	connect(voicecallManager, SIGNAL(CallAdded(QDBusObjectPath, QVariantMap)), this, SLOT(CallAdded(const QDBusObjectPath, const QVariantMap)));
	connect(voicecallManager, SIGNAL(CallRemoved(QDBusObjectPath)), this, SLOT(CallRemoved(const QDBusObjectPath)));
	connect(voicecallManager, SIGNAL(PropertyChanged(QString, QDBusVariant)), this, SLOT(CallPropertyChanged(const QString, const QDBusVariant)));
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
	OrgOfonoVoiceCallManagerInterface *ofono = new OrgOfonoVoiceCallManagerInterface("org.ofono", _modemPath, QDBusConnection::systemBus());
	ofono->Dial(number, "default");
	qDebug() << "Dialing: " << number;
}

void Ofono :: CallAdded(const QDBusObjectPath &object, const QVariantMap &values)
{
	QString type = values["State"].toString();

	QString number = values["LineIdentification"].toString();
	if (number == "")
		number = "No Caller ID";

	if (type == "incoming")
	{
		emit incomingCall(number);
	}
	Voicecall *voicecall = new Voicecall(object);

//	if (type == "dialing")

}

void Ofono :: CallRemoved(const QDBusObjectPath &object)
{
	qDebug() << "call removed";
}

void Ofono :: CallPropertyChanged(const QString &name, const QDBusVariant &value)
{
	qDebug() << name;
//	qDebug() << value;
}
