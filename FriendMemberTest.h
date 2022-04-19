#ifndef FRIENDMEMBERTEST_H
#define FRIENDMEMBERTEST_H
#include "FriendTest.h"
#include <gtest/gtest.h>

class FriendMemberTest : public testing::Test
{
public:
    static void SetUpTestCase();
    static void TearDownTestCase();

};

class Friend_Test2 : public testing::Test{
protected:
    FriendTest friendTest;
};

#endif // FRIENDMEMBERTEST_H
