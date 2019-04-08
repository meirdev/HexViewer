#include "Printer/DefaultPrinter/DefaultPrinter.h"

DefaultPrinter::DefaultPrinter()
: m_buffer(m_bufferSize)
{
}

void DefaultPrinter::flush()
{
    m_buffer.flush();
}

void DefaultPrinter::operator<<(const std::string& _buffer)
{
    m_buffer << _buffer;
}