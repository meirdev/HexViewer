#ifndef __ABCFILE_H__
#define __ABCFILE_H__

#include "IFile.h"
#include "IPrinter.h"

class ABCFile : public IFile
{
protected:
    ABCFile(IPrinter& _printer);
public:
    void setOffset(size_t _offset);
    void setLength(size_t _length);
protected:
    size_t    m_offset;
    size_t    m_length;
    IPrinter& m_printer;
};

#endif // __ABCFILE_H__