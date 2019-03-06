#ifndef __STRING_BUFFER_H__
#define __STRING_BUFFER_H__

#include <string>
#include <cstddef> // size_t

class StringBuffer
{
public:
    StringBuffer(size_t _size);
    ~StringBuffer();
    StringBuffer& operator<<(const char* _string);
    StringBuffer& operator<<(const std::string& _string);
    void  flush();
    void  clear();
    char* get();
private:
    StringBuffer& inputString(const char* _string, size_t _size);
private:
    char*  m_buffer;
    size_t m_position;
    size_t m_size;
};

#endif // __STRING_BUFFER_H__