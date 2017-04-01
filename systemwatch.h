#ifndef SYSTEMWATCH_H
#define SYSTEMWATCH_H

#include <QObject>

class SystemWatch: public QObject
{
	Q_OBJECT
public:
	SystemWatch();

signals:
	void sleep();
	void wakeup();

private slots:
	void sleeping();
	void resuming();
};

#endif // SYSTEMWATCH_H
