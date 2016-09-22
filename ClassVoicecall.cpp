#include "ClassVoicecall.h"

Voicecall :: Voicecall(QDBusObjectPath object, QObject *parent)
{
	OrgOfonoVoiceCallInterface *call = new OrgOfonoVoiceCallInterface("org.ofono", object.path(), QDBusConnection::systemBus());
	connect(call, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(PropertyChanged(QString,QDBusVariant)));
}

void  Voicecall :: PropertyChanged(const QString &name, const QDBusVariant &value)
{
	if (name == "State")
		qDebug() << value.variant();
//		_state = value;
}

QString Voicecall :: getState()
{
	return _state;
}
