#ifndef SYSTEMWATCHUNIX_H
#define SYSTEMWATCHUNIX_H

#include "systemwatch.h"

class UnixSystemWatch : public SystemWatch
{
	Q_OBJECT
public:
	UnixSystemWatch();

private slots:
	void sleeping();
	void resuming();
};

#endif // SYSTEMWATCHUNIX_H
