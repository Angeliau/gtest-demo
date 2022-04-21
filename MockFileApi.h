#ifndef MOCKFILEAPI_H
#define MOCKFILEAPI_H
#include "FileApi.h"
#include "gmock/gmock.h"

class MockFileApi : public FileApi{
public:
    MockFileApi(){}
    virtual ~MockFileApi(){}

    MOCK_METHOD2(open, int(const char*, int));
    MOCK_METHOD4(read, int(const char*, char*, int, int&));
    MOCK_METHOD1(close, int(int));
};

#endif // MOCKFILEAPI_H
