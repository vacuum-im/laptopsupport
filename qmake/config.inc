#Path to Vacuum SDK
isEmpty(VACUUM_SDK_PATH) {
  win32:VACUUM_SDK_PATH  = c:/vacuum/sdk
  unix:VACUUM_SDK_PATH   = /usr/local/include/vacuum
  macx:VACUUM_SDK_PATH   = /Applications/vacuum.app/Contents/include
  haiku:VACUUM_SDK_PATH  = /boot/apps/vacuum/sdk
}

#Path to Vacuum Utils Library
isEmpty(VACUUM_LIB_PATH) {
  win32:VACUUM_LIB_PATH  = c:/vacuum
  unix:VACUUM_LIB_PATH   = /usr/local/lib
  macx:VACUUM_LIB_PATH   = /Applications/vacuum.app/Contents/Frameworks
  haiku:VACUUM_LIB_PATH  = /boot/apps/vacuum
}

include($$VACUUM_SDK_PATH/make/config.inc)
