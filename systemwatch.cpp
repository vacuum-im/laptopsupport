#include "systemwatch.h"
#if defined(Q_OS_MAC)
	#include "systemwatchmac.h"
#elif defined(Q_OS_WIN32)
	#include "systemwatchwin.h"
#else
	#include "systemwatchunix.h"
#endif

SystemWatch::SystemWatch()
{

}

SystemWatch *SystemWatch::instance()
{
	if (!FWatchInstance)
	{
#if defined(Q_OS_MAC)
		FWatchInstance = new MacSystemWatch();
#elif defined(Q_OS_WIN)
		FWatchInstance = new WinSystemWatch();
#else
		FWatchInstance = new UnixSystemWatch();
#endif
	}

	return FWatchInstance;
}

SystemWatch* SystemWatch::FWatchInstance = 0;
