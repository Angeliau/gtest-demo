#ifndef MOCKFOOIMPL_H
#define MOCKFOOIMPL_H
#include "Foo.h"

class MockFooImpl
{
public:
    MockFooImpl(Foo* f);
    int count();

private:
    Foo* foo;
};

#endif // MOCKFOOIMPL_H
