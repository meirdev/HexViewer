#include <limits>

#include "FileStream/ABCFile.h"

ABCFile::ABCFile(IPrinter& _printer)
: m_offset(0)
, m_length(std::numeric_limits<size_t>::max())
, m_printer(_printer)
{
}

void ABCFile::setOffset(long _offset)
{
    if (_offset < 0)
    {
        m_offset = getSize()+_offset;

        if (m_offset < 0)
        {
            m_offset = 0;
        }
    }
    else
    {
        m_offset = _offset;
    }

    m_printer.setPosition(m_offset);
}

void ABCFile::setLength(size_t _length)
{
    m_length = _length;
}