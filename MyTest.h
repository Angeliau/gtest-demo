#ifndef MYTEST_H
#define MYTEST_H


class MyTest
{
public:
    MyTest();

    void setParameter(int p1,int p2);
    unsigned int getSum();
    int getA();
    int getB();

private:
    int a;
    int b;
};

#endif // MYTEST_H
