#ifndef __DEFAULT_PRINTER_H__
#define __DEFAULT_PRINTER_H__

#include "ABCPrinter.h"
#include "StringBuffer.h"

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

#endif // __DEFAULT_PRINTER_H__