#include "PrivateMemberTest.h"

PrivateTest* PrivateMemberTest::privateTest = nullptr;

void PrivateMemberTest::SetUpTestCase(){
    privateTest = new PrivateTest();
}

void PrivateMemberTest::TearDownTestCase(){
    if (privateTest != nullptr){
        delete privateTest;
        privateTest = nullptr;
    }
}

TEST_F(PrivateMemberTest, add){
    auto Ret = privateTest->add(5,5);
    EXPECT_EQ(10, Ret);
}
