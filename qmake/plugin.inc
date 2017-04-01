#Project Configuration
TEMPLATE            = lib
CONFIG             += plugin
LIBS               += -l$$VACUUM_UTILS_NAME
LIBS               += -L$$VACUUM_LIB_PATH
DEPENDPATH         += $$VACUUM_SDK_PATH
INCLUDEPATH        += $$VACUUM_SDK_PATH


#Install
target.path         = $$INSTALL_PLUGINS
resources.path      = $$INSTALL_RESOURCES
resources.files     = ./resources/*
INSTALLS           += target resources

macx {
  UTILS_LIB_NAME    = lib$${VACUUM_UTILS_NAME}.$${VACUUM_UTILS_ABI}.dylib
  name_tool.path    = $$INSTALL_PLUGINS
  name_tool.extra   = install_name_tool -change $$UTILS_LIB_NAME @executable_path/../Frameworks/$$UTILS_LIB_NAME $(INSTALL_ROOT)$$INSTALL_PLUGINS/lib$${TARGET}.dylib
  INSTALLS         += name_tool
}
