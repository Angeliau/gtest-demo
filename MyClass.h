#ifndef MYCLASS_H
#define MYCLASS_H
#include <stdio.h>

class MyPimplClass;
class MyPrivateClass{
public:
    int func(int i){
        return i;
    }
};

class MyClass
{
public:
    MyClass();
    ~MyClass();

    //辅助类指针
    MyPimplClass* pimp;

private:
    MyPrivateClass myPrivate;
    int square(int n);
};

class MyPimplClass{ //辅助类，包装原MyClass的私有方法
public:
    MyPrivateClass myPriClass;
     //封装原私有函数square
    int pub_square(int n){return n * n;}
    //封装原私有变量MyPrivateClass的func
    int pub_func(int i){ return myPriClass.func(i); }
};

#endif // MYCLASS_H
