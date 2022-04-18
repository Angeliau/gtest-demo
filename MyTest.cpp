#include "MyTest.h"

MyTest::MyTest()
{
    a = 0;
    b = 0;
}

void MyTest::setParameter(int p1, int p2){
    a = p1;
    b = p2;
}

unsigned int MyTest::getSum(){
    return static_cast<unsigned int>(a+b);
}

int MyTest::getA(){
    return a;
}

int MyTest::getB(){
    return b;
}


