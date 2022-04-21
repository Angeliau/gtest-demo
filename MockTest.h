#ifndef MOCKTEST_H
#define MOCKTEST_H
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockFoo.h"
#include "MockFooImpl.h"
#include "MockFileApi.h"
#include "FileImpl.h"
#include "MyTemplateClass.h"


using namespace testing;

class MockTest : public Test
{
public:
    virtual void SetUp();
    virtual void TearDown();

protected:
    MockFoo* mockFoo;
    MockFooImpl* mockFooImpl;
    MockFileApi* mockFile;
    FileImpl* fileImpl;
    MockTemplate<int>* mockTemplate;

};

#endif // MOCKTEST_H
