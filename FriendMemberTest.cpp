#include "FriendMemberTest.h"

void FriendMemberTest::SetUpTestCase(){

}

void FriendMemberTest::TearDownTestCase(){

}

TEST(FriendTest, addTest){
    FriendTest f;
    EXPECT_EQ(10, f.add(5, 5));
}

TEST_F(Friend_Test2, addTest){
    EXPECT_EQ(20, friendTest.add(10, 10));
}
