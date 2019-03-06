#ifndef __ABCPRINTER_H__
#define __ABCPRINTER_H__

#include <vector>

#include "IPrinter.h"
#include "IStyle.h"

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

#endif // __ABCPRINTER_H__