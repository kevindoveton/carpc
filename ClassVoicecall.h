#ifndef VOICECALL_H
#define VOICECALL_H

#include <QObject>
#include <QtDBus>
#include <QDebug>
#include "dbus/OfonoVoiceCall.h"

class Voicecall : public QObject
{
	Q_OBJECT
public:
	Voicecall(QDBusObjectPath object, QObject *parent = 0);

	QString getState();

//signals:

public slots:
	void PropertyChanged(const QString &name, const QDBusVariant &value);

protected:
	QString _state;
};

#endif // VOICECALL_H
