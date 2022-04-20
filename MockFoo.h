#ifndef MOCKFOO_H
#define MOCKFOO_H
#include "Foo.h"
#include "gmock/gmock.h"

class MockFoo : public Foo{
public:
    MOCK_METHOD0(count, int());
};

#endif // MOCKFOO_H
