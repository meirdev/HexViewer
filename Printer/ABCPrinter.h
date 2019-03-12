#ifndef __PRINTER_ABCPRINTER_H__
#define __PRINTER_ABCPRINTER_H__

#include <vector>

#include "Printer/IPrinter.h"
#include "Style/IStyle.h"

class ABCPrinter : public IPrinter
{
protected:
    typedef std::vector<unsigned short> dbytes;
protected:
    ABCPrinter(IStyle& _style);
    void setPosition(size_t _position);
    void header();
    void footer();
protected:
    size_t  m_position;
    dbytes  m_bytes;
    IStyle& m_style;
};

#endif // __PRINTER_ABCPRINTER_H__