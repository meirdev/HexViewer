#ifndef __FILE_SYSTEM_IFILE_H__
#define __FILE_SYSTEM_IFILE_H__

#include <cstddef> // size_t

class IFile
{
public:
    virtual ~IFile() = default;
    virtual size_t read(char* _buffer, size_t _count) = 0;
    virtual void seek(size_t _position) = 0;
    virtual size_t tell() = 0;
    virtual bool eof() = 0;
    virtual size_t size() = 0;
};

#endif // __FILE_SYSTEM_IFILE_H__