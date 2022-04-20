#include "MockTest.h"

MockTest::~MockTest(){

}

void MockTest::SetUp(){
    mockFoo = new MockFoo();
    mockFooImpl = new MockFooImpl(mockFoo);
}

void MockTest::TearDown(){
    if (mockFooImpl != nullptr){
        delete mockFooImpl;
        mockFooImpl = nullptr;
    }
    if (mockFoo != nullptr){
        delete mockFoo;
        mockFoo = nullptr;
    }
}

TEST_F(MockTest, mockFooCount){
    EXPECT_CALL(*mockFoo, count()).Times(3)
            .WillOnce(Return(3))
            .WillOnce(Return(5))
            .WillOnce(Return(6));

    EXPECT_EQ(mockFooImpl->count(), 3);
    EXPECT_EQ(mockFooImpl->count(), 5);
    EXPECT_EQ(mockFooImpl->count(), 6);
}

TEST_F(MockTest, mockFooCount2){
    EXPECT_CALL(*mockFoo, count()).Times(3)
            .WillOnce(Return(3))
            .WillOnce(Return(5))
            .WillOnce(Return(6));

    EXPECT_EQ(mockFooImpl->count(), 3);
    EXPECT_EQ(mockFooImpl->count(), 6);
    EXPECT_EQ(mockFooImpl->count(), 5);
}
