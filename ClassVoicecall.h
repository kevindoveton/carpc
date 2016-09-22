#ifndef VOICECALL_H
#define VOICECALL_H

#include <QObject>
#include <QtDBus>

class Voicecall : public QObject
{
	Q_OBJECT
public:
	Voicecall(QDBusObjectPath *object, QObject *parent = 0);

signals:

public slots:
};

#endif // VOICECALL_H
