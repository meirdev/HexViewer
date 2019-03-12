#ifndef __PRINTER_IPRINTER_H__
#define __PRINTER_IPRINTER_H__

#include <cstddef> // size_t

class IPrinter
{
public:
    virtual ~IPrinter() = default;
    virtual void setPosition(size_t _position) = 0;
    virtual void header() = 0;
    virtual void footer() = 0;
    virtual void operator<<(unsigned char _byte) = 0;
};

#endif // __PRINTER_IPRINTER_H__