#ifndef FILEIMPL_H
#define FILEIMPL_H
#include "FileApi.h"

class FileImpl
{
public:
    FileImpl(FileApi* api);
    ~FileImpl();

    int loadData(const char* path, int size);
    char* getFileData();
    int getDataSize();

private:
    FileApi* m_fileApi;
    char* m_fileData;
    int m_dataSize;
};

#endif // FILEIMPL_H
