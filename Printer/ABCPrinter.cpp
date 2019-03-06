#include "ABCPrinter.h"

ABCPrinter::ABCPrinter(IStyle& _style)
: m_position(0)
, m_style(_style)
{
}

void ABCPrinter::setPosition(size_t _position)
{
    m_position = _position;
}

void ABCPrinter::header()
{
}

void ABCPrinter::footer()
{
}