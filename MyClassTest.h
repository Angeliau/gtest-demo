#ifndef MYCLASSTEST_H
#define MYCLASSTEST_H
#include "MyClass.h"
#include "gtest/gtest.h"


class MyClassTest : public testing::Test
{
public:
    virtual void SetUp();
    virtual void TearDown();

protected:
    MyClass* mc;
};

#endif // MYCLASSTEST_H
