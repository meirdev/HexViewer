#ifndef __DATA_PROCESSING_H__
#define __DATA_PROCESSING_H__

#include "Printer/IPrinter.h"
#include "Style/IStyle.h"
#include "FileStream/IFile.h"

class DataProcessing
{
private:
    typedef std::vector<unsigned short> dbytes;
public:
    DataProcessing(IPrinter& _printer, IStyle& _style, IFile& _file);
    void setOffset(int _offset);
    void setLength(size_t _length);
    void process();
private:
    void printByte(unsigned char _byte);
    void printEnd();
    void printRow();
private:
    size_t    m_offset;
    size_t    m_length;
    IPrinter& m_printer;
    IStyle&   m_style;
    IFile&    m_file;
    dbytes    m_bytes;
    size_t    m_blockSize;
};

#endif // __DATA_PROCESSING_H__