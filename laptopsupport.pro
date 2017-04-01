include(qmake/debug.inc)
include(qmake/config.inc)

#Project configuration
TARGET              = laptopsupport
QT                  = core dbus xml gui
include(laptopsupport.pri)

#Default project configuration
include(qmake/plugin.inc)

#Translation
TRANS_SOURCE_ROOT = .
TRANS_BUILD_ROOT = $${OUT_PWD}
include(translations/languages.inc)
