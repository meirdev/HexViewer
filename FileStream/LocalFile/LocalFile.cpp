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

void LocalFile::print()
{
    char* buffer = new char[4096];

    m_file.seekg(m_offset);

    m_printer.header();

    size_t totalLength = 0;

    while (!m_file.eof())
    {
        m_file.read(buffer, sizeof(buffer));

        for (size_t i = 0, readBytes = m_file.gcount(); (totalLength < m_length) && (i < readBytes); ++i, ++totalLength)
        {
            m_printer << buffer[i];
        }
    }

    m_printer.footer();

    delete[] buffer;
}