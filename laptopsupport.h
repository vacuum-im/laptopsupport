#ifndef LAPTOPSUPPORT_H
#define LAPTOPSUPPORT_H

#include <QMap>

#include <interfaces/ipluginmanager.h>
#include <interfaces/ipresencemanager.h>
#include <interfaces/istatuschanger.h>

#include "systemwatch.h"

#define LAPTOPSUPPORT_UUID  "{f74f2ec7-13a9-43bb-99b7-73d88246a3e1}"

class LaptopSupport :
		public QObject,
		public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "org.vacuum-im.plugins.LaptopSupport");
public:
	LaptopSupport();
	~LaptopSupport();
	//IPlugin
	virtual QObject *instance() { return this; }
	virtual QUuid pluginUuid() const { return LAPTOPSUPPORT_UUID; }
	virtual void pluginInfo(IPluginInfo *APluginInfo);
	virtual bool initConnections(IPluginManager *APluginManager, int &AInitOrder);
	virtual bool initObjects();
	virtual bool initSettings() { return true; }
	virtual bool startPlugin() { return true; }
signals:

protected slots:
	void onSleep();
	void onWeakUp();

private:
	IStatusChanger *FStatusChanger;
	QMap<Jid, int> FTempStreamStatuses;
	SystemWatch *FSystemWatch;
};

#endif // LAPTOPSUPPORT_H
