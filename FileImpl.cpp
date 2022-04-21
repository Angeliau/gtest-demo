#include "FileImpl.h"

FileImpl::FileImpl(FileApi* api) : m_fileApi(api), m_fileData(nullptr), m_dataSize(0)
{

}

FileImpl::~FileImpl(){
    if (m_fileData != nullptr){
        delete[] m_fileData;
        m_fileData = nullptr;
    }
}

int FileImpl::loadData(const char* path, int size){
    //open file
    int fd = m_fileApi->open(path, 0777);
    if (fd < 0){
        return -1;
    }

    m_fileData = new char[size + 1];
    m_fileData[size] = '\0';
    int size_ret = 0;
    int ret = m_fileApi->read(path, m_fileData, size, size_ret);
    if (ret != 0){
        delete[] m_fileData;
        m_fileData = nullptr;
        return ret;
    }

    if (size != size_ret){
        m_fileApi->close(fd);
        return -1;
    }

    m_dataSize = size_ret;
    ret = m_fileApi->close(fd);

    return ret;
}

char* FileImpl::getFileData(){
    return m_fileData;
}

int FileImpl::getDataSize(){
    return m_dataSize;
}
