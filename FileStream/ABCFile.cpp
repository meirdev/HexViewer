#include <limits>

#include "ABCFile.h"

ABCFile::ABCFile(IPrinter& _printer)
: m_offset(0)
, m_length(std::numeric_limits<size_t>::max())
, m_printer(_printer)
{
}

void ABCFile::setOffset(size_t _offset)
{
    m_offset = _offset;

    m_printer.setPosition(_offset);
}

void ABCFile::setLength(size_t _length)
{
    m_length = _length;
}