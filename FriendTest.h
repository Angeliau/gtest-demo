#ifndef FRIENDTEST_H
#define FRIENDTEST_H
#include <stdio.h>
#include "gtest/gtest_prod.h"

class FriendTest
{
public:
    FriendTest();

private:
    int add(int a, int b);

    //FRIEND_TEST(TestCaseName, TestName)
    FRIEND_TEST(FriendTest, addTest);
    FRIEND_TEST(Friend_Test2, addTest);
};

#endif // FRIENDTEST_H
