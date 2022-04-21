#ifndef MYTEMPLATECLASS_H
#define MYTEMPLATECLASS_H

#include "gmock/gmock.h"
template <typename T>
class MyTemplateClass{
public:
    virtual ~MyTemplateClass(){}

    virtual int getSize() const = 0;
    virtual void push(const T& e) = 0;
};

template <typename T>
class MockTemplate : public MyTemplateClass<T>{
public:
    virtual ~MockTemplate(){}
    MOCK_CONST_METHOD0_T(getSize, int());
    MOCK_METHOD1_T(push, void(const T&));
};


#endif // MYTEMPLATECLASS_H
