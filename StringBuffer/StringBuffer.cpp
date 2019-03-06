#include <iostream>
#include <algorithm>
#include <cstring>

#include "StringBuffer.h"

StringBuffer::StringBuffer(size_t _size)
: m_position(0)
, m_size(_size)
{
    m_buffer = new char[_size];
}

StringBuffer::~StringBuffer()
{
    delete[] m_buffer;
}

StringBuffer& StringBuffer::operator<<(const char* _string)
{
    return inputString(_string, strlen(_string));
}

StringBuffer& StringBuffer::operator<<(const std::string& _string)
{
    return inputString(_string.c_str(), _string.size());
}

StringBuffer& StringBuffer::inputString(const char* _string, size_t _size)
{
    if (_size >= m_size)
    {
        std::cout << _string;
        
        return *this;
    }
    
    if (_size+m_position > m_size)
    {
        std::cout << m_buffer;

        m_position = 0;
    }
    
    std::copy(_string, _string+_size, m_buffer+m_position);

    m_position          += _size;
    m_buffer[m_position] = 0;

    return *this;
}

void StringBuffer::flush()
{
    std::cout << m_buffer;

    clear();
}

void StringBuffer::clear()
{
    m_position           = 0;
    m_buffer[m_position] = 0;
}

char* StringBuffer::get()
{
    return m_buffer;
}