#ifndef MOCKTEST_H
#define MOCKTEST_H
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockFoo.h"
#include "MockFooImpl.h"


using namespace testing;

class MockTest : public Test
{
public:
    virtual ~MockTest();
    virtual void SetUp();
    virtual void TearDown();

protected:
    MockFoo* mockFoo;
    MockFooImpl* mockFooImpl;

};

#endif // MOCKTEST_H
