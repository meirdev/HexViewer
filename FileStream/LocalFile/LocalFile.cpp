#include "FileStream/LocalFile/LocalFile.h"

LocalFile::LocalFile(const std::string& _fileName)
: m_file(_fileName, std::fstream::binary)
{
    if (!m_file.is_open())
    {
        throw std::runtime_error("File not open");
    }
}

inline size_t LocalFile::read(char* _buffer, size_t _count)
{
    m_file.read(_buffer, _count);

    return m_file.gcount();
}

inline void LocalFile::seek(size_t _position)
{
    m_file.seekg(_position);
}

inline size_t LocalFile::tell()
{
    return m_file.tellg();
}

inline bool LocalFile::eof()
{
    return m_file.eof();
}

inline size_t LocalFile::size()
{
    size_t currentPosition = tell();

    m_file.seekg(0, std::ios_base::end);

    size_t fileSize = tell();

    m_file.seekg(currentPosition, std::ios_base::beg);

    return fileSize;
}