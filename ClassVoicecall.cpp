#include "ClassVoicecall.h"

Voicecall :: Voicecall(QDBusObjectPath object, QObject *parent)
{
	_object = object;
	call = new OrgOfonoVoiceCallInterface("org.ofono", _object.path(), QDBusConnection::systemBus());
	connect(call, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(PropertyChanged(QString,QDBusVariant)));
}

void  Voicecall :: PropertyChanged(const QString &name, const QDBusVariant &value)
{
	if (name == "State")
		value.variant().toString();
}

QString Voicecall :: getState()
{
	return _state;
}

void Voicecall :: Answer()
{
	call->Answer();
}

void Voicecall :: Hangup()
{
	call->Hangup();
}
