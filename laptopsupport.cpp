#include <QCoreApplication>
#include <QSet>

#include <utils/jid.h>
#include "laptopsupport.h"

LaptopSupport::LaptopSupport()
{
	FSystemWatch = SystemWatch::instance();
	connect(FSystemWatch, SIGNAL(sleep), this, SLOT(onSleep));
	connect(FSystemWatch, SIGNAL(wakeup), this, SLOT(onWeakUp));
}

LaptopSupport::~LaptopSupport()
{
	delete FSystemWatch;
}

void LaptopSupport::pluginInfo(IPluginInfo *APluginInfo)
{
	APluginInfo->name = tr("Laptop support");
	APluginInfo->description = tr("TODO");
	APluginInfo->version = QLatin1String("0.1");
	APluginInfo->author = QLatin1String("Andrey Karepin");
	APluginInfo->homePage = QLatin1String("http://www.vacuum-im.org");
	APluginInfo->dependences.append(STATUSCHANGER_UUID);
}

bool LaptopSupport::initConnections(IPluginManager *APluginManager, int &AInitOrder)
{
	Q_UNUSED(AInitOrder);

	IPlugin *plugin = APluginManager->pluginInterface("IStatusChanger").value(0, nullptr);
	if (plugin)
	{
		FStatusChanger = qobject_cast<IStatusChanger *>(plugin->instance());
	}

	return FStatusChanger != nullptr;
}

bool LaptopSupport::initObjects()
{
	return true;
}

void LaptopSupport::onSleep()
{
	QSet<Jid> activeStreamJids;
	foreach (int activeStatusId, FStatusChanger->activeStatusItems()) {
		foreach (Jid streamJid, FStatusChanger->statusStreams(activeStatusId))
		activeStreamJids << streamJid;
	}

	foreach (Jid streamJid, activeStreamJids) {
		FTempStreamStatuses[streamJid] = FStatusChanger->streamStatus(streamJid);
		//TODO: set message tr("Computer went to sleep")
		FStatusChanger->setStreamStatus(streamJid, IPresence::Offline);
	}
}

void LaptopSupport::onWeakUp()
{
	for (QMap<Jid, int>::const_iterator it = FTempStreamStatuses.constBegin(); it != FTempStreamStatuses.constEnd(); ++it)
	{
		FStatusChanger->setStreamStatus(it.key(), it.value());
	}
	FTempStreamStatuses.clear();
}
