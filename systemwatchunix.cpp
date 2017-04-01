#include <QDBusConnection>

#include "systemwatchunix.h"

UnixSystemWatch::UnixSystemWatch() : SystemWatch ()
{
	QDBusConnection conn = QDBusConnection::systemBus();

	conn.connect("org.freedesktop.UPower", "/org/freedesktop/UPower", "org.freedesktop.UPower", "Sleeping", this, SLOT(sleeping()));
	conn.connect("org.freedesktop.UPower", "/org/freedesktop/UPower", "org.freedesktop.UPower", "Resuming", this, SLOT(resuming()));
}

void UnixSystemWatch::sleeping()
{
	emit sleep();
}

void UnixSystemWatch::resuming()
{
	emit wakeup();
}
