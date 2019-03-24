#include "FileStream/LocalFile/LocalFile.h"

LocalFile::LocalFile(IPrinter& _printer, const std::string& _fileName)
: ABCFile(_printer)
, m_file(_fileName, std::fstream::binary)
{
    if (!m_file.is_open())
    {
        throw std::runtime_error("File not open");
    }
}

void LocalFile::read()
{
    const size_t bufferSize = 4096;

    char* buffer = new char[bufferSize];

    m_file.seekg(m_offset);
    
    size_t totalLength = 0;

    while (!m_file.eof())
    {
        m_file.read(buffer, bufferSize);

        for (size_t i = 0, readBytes = m_file.gcount(); (totalLength < m_length) && (i < readBytes); ++i, ++totalLength)
        {
            m_printer << buffer[i];
        }

        if (totalLength == m_length)
        {
            break;
        }
    }

    delete[] buffer;
}

size_t LocalFile::getSize()
{
    size_t currentPosition = m_file.tellg();

    m_file.seekg(0, std::ios_base::end);

    size_t fileSize = m_file.tellg();

    m_file.seekg(currentPosition, std::ios_base::beg);

    return fileSize;
}