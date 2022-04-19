TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += /usr/lib64/libgtest.so
LIBS+=-lpthread

SOURCES += main.cpp \
    MyGTest.cpp \
    MyTest.cpp \
    PrivateTest.cpp \
    FriendTest.cpp \
    PrivateMemberTest.cpp \
    FriendMemberTest.cpp \
    MyClass.cpp \
    MyClassTest.cpp

HEADERS += \
    MyGTest.h \
    MyTest.h \
    PrivateTest.h \
    FriendTest.h \
    PrivateMemberTest.h \
    FriendMemberTest.h \
    MyClass.h \
    MyClassTest.h
