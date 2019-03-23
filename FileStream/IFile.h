#ifndef __FILE_SYSTEM_IFILE_H__
#define __FILE_SYSTEM_IFILE_H__

#include <cstddef> // size_t

class IFile
{
public:
    virtual ~IFile() = default;
    virtual void read() = 0;
    virtual void setOffset(long _offset) = 0;
    virtual void setLength(size_t _length) = 0;
    virtual size_t getSize() = 0;
};

#endif // __FILE_SYSTEM_IFILE_H__