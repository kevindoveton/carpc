#include "ClassVoicecall.h"

Voicecall :: Voicecall(QDBusObjectPath *object, QObject *parent)
{
	OrgOfonoVoiceCallInterface *call = new OrgOfonoVoiceCallInterface("org.ofono", object->path(), QDBusConnection::systemBus());
	connect(call, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(PropertyChanged(QString,QDBusVariant)));
}

void  Voicecall :: PropertyChanged(const QString &name, const QDBusVariant &value)
{

}
