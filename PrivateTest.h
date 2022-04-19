#ifndef PRIVATETEST_H
#define PRIVATETEST_H
#define private public
#define protected public


class PrivateTest
{
public:
    PrivateTest();

private:
    int add(int a, int b);
};

#endif // PRIVATETEST_H
