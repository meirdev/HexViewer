#include "Printer/DefaultPrinter/DefaultPrinter.h"

DefaultPrinter::DefaultPrinter(IStyle& _style)
: ABCPrinter(_style)
, m_buffer(m_bufferSize)
{
}

void DefaultPrinter::header()
{
    m_buffer << m_style.getHeader();
}

void DefaultPrinter::footer()
{
    size_t size      = m_bytes.size();
    size_t blockSize = m_style.getBlockSize();

    if (size && (size != blockSize))
    {
        m_bytes.insert(m_bytes.begin()+size, blockSize-size, 256);

        m_buffer << m_style.getRow(m_style.getPosition(m_position), m_bytes);

        m_bytes.clear();
    }

    m_buffer << m_style.getFooter();
    
    m_buffer.flush();
}

void DefaultPrinter::operator<<(unsigned char _byte)
{
    m_bytes.push_back(_byte);

    size_t size      = m_bytes.size();
    size_t blockSize = m_style.getBlockSize();

    if (size && (size % blockSize == 0))
    {
        m_buffer << m_style.getRow(m_style.getPosition(m_position), m_bytes);

        m_position += blockSize;

        m_bytes.clear();
    }
}