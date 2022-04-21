TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS+=/usr/local/lib64/libgtest.a
LIBS+=/usr/local/lib64/libgmock.a
LIBS+=-lpthread

SOURCES += main.cpp \
    MyGTest.cpp \
    MyTest.cpp \
    PrivateTest.cpp \
    FriendTest.cpp \
    PrivateMemberTest.cpp \
    FriendMemberTest.cpp \
    MyClass.cpp \
    MyClassTest.cpp \
    MockFooImpl.cpp \
    MockTest.cpp \
    FileImpl.cpp

HEADERS += \
    MyGTest.h \
    MyTest.h \
    PrivateTest.h \
    FriendTest.h \
    PrivateMemberTest.h \
    FriendMemberTest.h \
    MyClass.h \
    MyClassTest.h \
    Foo.h \
    MockFoo.h \
    MockFooImpl.h \
    MockTest.h \
    FileApi.h \
    FileImpl.h \
    MockFileApi.h \
    MyTemplateClass.h
