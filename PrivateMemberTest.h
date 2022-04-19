#ifndef PRIVATEMEMBERTEST_H
#define PRIVATEMEMBERTEST_H
#include "PrivateTest.h"
#include <gtest/gtest.h>

class PrivateMemberTest : public testing::Test
{
public:
    static void SetUpTestCase();
    static void TearDownTestCase();

protected:
    static PrivateTest* privateTest;
};

#endif // PRIVATEMEMBERTEST_H
