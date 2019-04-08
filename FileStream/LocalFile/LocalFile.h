#ifndef __FILE_SYSTEM_LOCAL_FILE_H__
#define __FILE_SYSTEM_LOCAL_FILE_H__

#include <fstream>
#include <string>

#include "FileStream/IFile.h"

class LocalFile : public IFile
{
public:
    LocalFile(const std::string& _fileName);
    size_t read(char* _buffer, size_t _count);
    void seek(size_t _position);
    size_t tell();
    bool eof();
    size_t size();
private:
    std::ifstream m_file;
};

#endif // __FILE_SYSTEM_LOCAL_FILE_H__