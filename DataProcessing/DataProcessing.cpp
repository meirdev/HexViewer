#include <limits>

#include "DataProcessing/DataProcessing.h"

DataProcessing::DataProcessing(IPrinter& _printer, IStyle& _style, IFile& _file)
: m_offset(0)
, m_length(std::numeric_limits<size_t>::max())
, m_printer(_printer)
, m_style(_style)
, m_file(_file)
{
    m_blockSize = m_style.blockSize();
}

void DataProcessing::setOffset(int _offset)
{
    if (_offset < 0)
    {
        _offset = static_cast<int>(m_file.size())+_offset;

        if (_offset < 0)
        {
            _offset = 0;
        }
    }

    m_offset = _offset;
}

void DataProcessing::setLength(size_t _length)
{
    m_length = _length;
}

void DataProcessing::process()
{
    const size_t bufferSize = 4096;

    char* buffer = new char[bufferSize];

    m_file.seek(m_offset);

    m_printer << m_style.header();

    size_t totalLength = 0;

    while (!m_file.eof())
    {
        size_t readBytes = m_file.read(buffer, bufferSize);

        for (size_t i = 0; (totalLength < m_length) && (i < readBytes); ++i, ++totalLength)
        {
            printByte(buffer[i]);
        }

        if (totalLength == m_length)
        {
            break;
        }
    }

    printEnd();

    m_printer << m_style.footer();

    m_printer.flush();

    delete[] buffer;
}

inline void DataProcessing::printByte(unsigned char _byte)
{
    m_bytes.push_back(_byte);

    size_t size = m_bytes.size();

    if (size && (size % m_blockSize == 0))
    {
        printRow();
    }
}

inline void DataProcessing::printEnd()
{
    size_t size = m_bytes.size();

    if (size && (size != m_blockSize))
    {
        m_bytes.insert(m_bytes.begin()+size, m_blockSize-size, 256);
    }

    printRow();
}

inline void DataProcessing::printRow()
{
    m_printer << m_style.row(m_style.position(m_offset), m_bytes);

    m_offset += m_blockSize;

    m_bytes.clear();
}