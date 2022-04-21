#include "MockTest.h"

void MockTest::SetUp(){
    mockFoo = new MockFoo();
    mockFooImpl = new MockFooImpl(mockFoo);
    mockFile = new MockFileApi();
    fileImpl = new FileImpl(mockFile);
    mockTemplate = new MockTemplate<int>();
}

void MockTest::TearDown(){
    if (mockTemplate != nullptr){
        delete mockTemplate;
        mockTemplate = nullptr;
    }
    if (fileImpl != nullptr){
        delete fileImpl;
        fileImpl = nullptr;
    }
    if (mockFile != nullptr){
        delete mockFile;
        mockFile = nullptr;
    }
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
    EXPECT_CALL(*mockFoo, count())
            .Times(3) // expect will be called 3 times, and returned results are 3, 5, 6 in turn.
            .WillOnce(::testing::Return(3))
            .WillOnce(::testing::Return(5))
            .WillOnce(::testing::Return(6));

    EXPECT_EQ(mockFooImpl->count(), 3);
    EXPECT_EQ(mockFooImpl->count(), 5);
    EXPECT_EQ(mockFooImpl->count(), 6);
}

TEST_F(MockTest, mockFooCount2){
    EXPECT_CALL(*mockFoo, count())
            .Times(3)
            .WillOnce(::testing::Return(3))
            .WillOnce(::testing::Return(5))
            .WillOnce(::testing::Return(6));

    EXPECT_EQ(mockFooImpl->count(), 3);
    //Simulation error results
    EXPECT_NE(mockFooImpl->count(), 6); // return 5
    EXPECT_NE(mockFooImpl->count(), 5); // return 6
}

TEST_F(MockTest, loadData){
    int size_ret = 200;

    // expect when call mockFile->open, it alaways return 10 and this function will be called twice.
    EXPECT_CALL(*mockFile, open(::testing::_, ::testing::_))
            .Times(2)
            .WillRepeatedly(::testing::Return(10));

    // expect when call mockFile->read, set the 4th parameter to 200 and return 0. And this function will be called twice.
    EXPECT_CALL(*mockFile, read(::testing::_, ::testing::_, ::testing::_, ::testing::_))
            .Times(2)
            .WillRepeatedly(::testing::DoAll(::testing::SetArgReferee<3>(size_ret),::testing::Return(0)));

    // expect when call mockFile->close, it alaways return 0. And this function will be called twice.
    EXPECT_CALL(*mockFile, close(::testing::_))
            .Times(2)
            .WillRepeatedly(::testing::Return(0));

    auto Ret = fileImpl->loadData("/home/test.txt", size_ret);
    // expect the return value is 0.
    EXPECT_EQ(Ret, 0);
    EXPECT_EQ(fileImpl->getDataSize(), 200);

    Ret = fileImpl->loadData("/home/test.txt", 50);
    // return -1
    EXPECT_NE(Ret, 0);
    EXPECT_EQ(fileImpl->getDataSize(), 200);
}


TEST_F(MockTest, loadDataError){
    int size_ret = 100;

    //expect when call mockFile->open, it alaways return 9 and this function will only be called once.
    EXPECT_CALL(*mockFile, open(::testing::_, ::testing::_))
            .Times(1)
            .WillRepeatedly(::testing::Return(9));


    //expect when call mockFile->read, set the 4th parameter to 100 and it alaways return 1 and this function will only be called once.
    EXPECT_CALL(*mockFile, read(_,_,_,_))
            .Times(1)
            .WillRepeatedly(DoAll(SetArgReferee<3>(size_ret), Return(1)));

    // expect mockFile->close is never called.
    EXPECT_CALL(*mockFile, close(_))
            .Times(0);

    auto Ret = fileImpl->loadData("/home", 100);
    EXPECT_EQ(Ret, 1);
    EXPECT_EQ(fileImpl->getDataSize(), 0);
    EXPECT_TRUE(fileImpl->getFileData() == nullptr);
}

TEST_F(MockTest, mockTemplate){
    // expect when call mockTemplate->push, it will be called three times.
    EXPECT_CALL(*mockTemplate, push(_))
            .Times(3);
    // expect when call mockTemplate->getSize, it will only be called once and return 3.
    EXPECT_CALL(*mockTemplate, getSize())
            .Times(1)
            .WillOnce(Return(3));

    mockTemplate->push(5);
    mockTemplate->push(6);
    mockTemplate->push(7);
    EXPECT_EQ(mockTemplate->getSize(), 3);
}
