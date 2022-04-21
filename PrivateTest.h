#ifndef PRIVATETEST_H
#define PRIVATETEST_H
#define my_private private


class PrivateTest
{
public:
    PrivateTest();

#undef my_private
#define my_private public
my_private:
    int add(int a, int b);
};

#endif // PRIVATETEST_H
