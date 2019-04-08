#ifndef __PRINTER_DEFAULT_PRINTER_H__
#define __PRINTER_DEFAULT_PRINTER_H__

#include "Printer/IPrinter.h"
#include "StringBuffer/StringBuffer.h"

class DefaultPrinter : public IPrinter
{
private:
    static const size_t m_bufferSize = 8192;
public:
    DefaultPrinter();
    void flush();
    void operator<<(const std::string& _buffer);
private:
    StringBuffer m_buffer;
};

#endif // __PRINTER_DEFAULT_PRINTER_H__