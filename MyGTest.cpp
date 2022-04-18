#include "MyGTest.h"

MyTest* MyGTest::myTest = nullptr;

//void MyGTest::SetUp(){
//    cout << "MyGTest::SetUp called...\n";
//    myTest = new MyTest();

//}

//void MyGTest::TearDown(){
//    cout << "MyGTest::TearDown called...\n";
//    if (myTest != nullptr){
//        delete myTest;
//        myTest = nullptr;
//    }
//}

void MyGTest::SetUpTestCase(){
    cout << "MyGTest::SetUpTestCase called...\n";
    myTest = new MyTest();
}

void MyGTest::TearDownTestCase(){
    cout << "MyGTest::TearDownTestCase called...\n";
    if (myTest != nullptr){
        delete myTest;
        myTest = nullptr;
    }
}

TEST_F(MyGTest, setParameterTest){
    myTest->setParameter(10, 20);
    EXPECT_EQ(10, myTest->getA());
    EXPECT_EQ(20, myTest->getB());
}

TEST_F(MyGTest, getSumTest){
    myTest->setParameter(1,5);
    auto Ret = myTest->getSum();
    EXPECT_EQ(6, Ret);
}

TEST_F(MyGTest, strCaseTest){
    //ASSERT_STREQ("abc","ABc") << "Expect abc==ABc, but not."; // false
    EXPECT_STRNE("abc","ABc");

    EXPECT_STRCASEEQ("abc","ABc");
    //EXPECT_STRCASENE("abc","ABc") << "Expect abc != ABc, but it ignore case."; // false
}

TEST_F(MyGTest, Case1){
    ASSERT_TRUE(1 == 1);
    ASSERT_FALSE(1 == 2);
}

TEST_F(MyGTest, Case2){
    ASSERT_DOUBLE_EQ(1.0,1.0);
    ASSERT_FLOAT_EQ(2.3F,2.3F);
}
