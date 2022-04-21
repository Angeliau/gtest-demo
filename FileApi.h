#ifndef FILEAPI_H
#define FILEAPI_H

class FileApi{
public:
    virtual int open(const char* path, int mode) = 0;
    virtual int read(const char* path, char* buffer, int size, int& size_ret) = 0;
    virtual int close(int fd) = 0;
};

#endif // FILEAPI_H
