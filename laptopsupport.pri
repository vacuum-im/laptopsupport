HEADERS = laptopsupport.h \
    $$PWD/systemwatch.h

SOURCES = laptopsupport.cpp \
    $$PWD/systemwatch.cpp


unix:!mac {
        HEADERS += $$PWD/systemwatchunix.h
        SOURCES += $$PWD/systemwatchunix.cpp
}
win32: {
        HEADERS += $$PWD/systemwatchwin.h
        SOURCES += $$PWD/systemwatchwin.cpp
}
mac: {
        HEADERS += $$PWD/systemwatchmac.h
        SOURCES += $$PWD/systemwatchmac.cpp
}
