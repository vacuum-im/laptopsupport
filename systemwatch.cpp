#include <QDBusConnection>

#include "systemwatch.h"

SystemWatch::SystemWatch()
{
	QDBusConnection conn = QDBusConnection::systemBus();

	conn.connect("org.freedesktop.UPower", "/org/freedesktop/UPower", "org.freedesktop.UPower", "Sleeping", this, SLOT(sleeping()));
	conn.connect("org.freedesktop.UPower", "/org/freedesktop/UPower", "org.freedesktop.UPower", "Resuming", this, SLOT(resuming()));
}

void SystemWatch::sleeping()
{
	emit sleep();
}

void SystemWatch::resuming()
{
	emit wakeup();
}
