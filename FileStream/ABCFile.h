#ifndef __FILE_SYSTEM_ABCFILE_H__
#define __FILE_SYSTEM_ABCFILE_H__

#include "FileStream/IFile.h"
#include "Printer/IPrinter.h"

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

#endif // __FILE_SYSTEM_ABCFILE_H__