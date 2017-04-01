#ifndef SYSTEMWATCH_H
#define SYSTEMWATCH_H

#include <QObject>

class SystemWatch: public QObject
{
	Q_OBJECT
public:
	static SystemWatch* instance();

signals:
	void sleep();
	void wakeup();

protected:
	SystemWatch();

private:
	static SystemWatch* FWatchInstance;
};

#endif // SYSTEMWATCH_H
