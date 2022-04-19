#include "MyClassTest.h"

void MyClassTest::SetUp(){
    mc = new MyClass();
}

void MyClassTest::TearDown(){
    if (mc != nullptr){
        delete mc;
        mc = nullptr;
    }
}

TEST_F(MyClassTest, pub_square){
    EXPECT_EQ(25, mc->pimp->pub_square(5));
}

TEST_F(MyClassTest, pub_func){
    EXPECT_EQ(10, mc->pimp->pub_func(10));
}
