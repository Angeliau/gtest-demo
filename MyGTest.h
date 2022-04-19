#ifndef MYGTEST_H
#define MYGTEST_H
#include <iostream>
#include <gtest/gtest.h>
#include "MyTest.h"


using namespace testing;
using namespace std;

class MyGTest : public Test
{
public:
    //重写SetUp和TearDown或者SetUpTestCase和TearDownTestCase都可以
//    virtual void SetUp();
//    virtual void TearDown();

    static void SetUpTestCase();
    static void TearDownTestCase();

protected:
//    MyTest* myTest;
    static MyTest* myTest;
};

#endif // MYGTEST_H
