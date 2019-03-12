#ifndef __PRINTER_DEFAULT_PRINTER_H__
#define __PRINTER_DEFAULT_PRINTER_H__

#include "Printer/ABCPrinter.h"
#include "StringBuffer/StringBuffer.h"

class DefaultPrinter : public ABCPrinter
{
private:
    static const size_t m_bufferSize = 8192;
public:
    DefaultPrinter(IStyle& _style);
    void header();
    void footer();
    void operator<<(unsigned char _byte);
private:
    StringBuffer m_buffer;
};

#endif // __PRINTER_DEFAULT_PRINTER_H__