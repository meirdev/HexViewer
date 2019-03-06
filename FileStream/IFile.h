#ifndef __IFILE_H__
#define __IFILE_H__

#include <cstddef> // size_t

class IFile
{
public:
    virtual ~IFile() = default;
    virtual void print() = 0;
    virtual void setOffset(size_t _offset) = 0;
    virtual void setLength(size_t _length) = 0;
};

#endif // __IFILE_H__