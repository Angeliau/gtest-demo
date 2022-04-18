TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += /usr/lib64/libgtest.so
LIBS+=-lpthread

SOURCES += main.cpp \
    MyGTest.cpp \
    MyTest.cpp

HEADERS += \
    MyGTest.h \
    MyTest.h
