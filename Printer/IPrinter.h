#ifndef __PRINTER_IPRINTER_H__
#define __PRINTER_IPRINTER_H__

#include <string>

class IPrinter
{
public:
    virtual ~IPrinter() = default;
    virtual void flush();
    virtual void operator<<(const std::string& _buffer) = 0;
};

#endif // __PRINTER_IPRINTER_H__