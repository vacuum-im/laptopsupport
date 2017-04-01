!macx:!isEmpty(DEBUG_VACUUM_SRC_PATH) {
  isEmpty(DEBUG_VACUUM_BIN_PATH) {
    DEBUG_VACUUM_BIN_PATH    = $$DEBUG_VACUUM_SRC_PATH
  }

  VACUUM_SDK_PATH            = $$DEBUG_VACUUM_SRC_PATH/src
  VACUUM_LIB_PATH            = $$DEBUG_VACUUM_BIN_PATH/src/libs

  win32:DLLDESTDIR           = $$DEBUG_VACUUM_BIN_PATH/plugins
  unix:DESTDIR               = $$DEBUG_VACUUM_BIN_PATH/plugins

  DEFINES                   += DEBUG_RESOURCES_DIR='\\\"$${_PRO_FILE_PWD_}/resources\\\"'
}
