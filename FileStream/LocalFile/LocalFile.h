#ifndef __FILE_SYSTEM_LOCAL_FILE_H__
#define __FILE_SYSTEM_LOCAL_FILE_H__

#include <fstream>
#include <string>

#include "FileStream/ABCFile.h"

class LocalFile : public ABCFile
{
public:
    LocalFile(IPrinter& _printer, const std::string& _fileName);
    void print();
private:
    std::ifstream m_file;
};

#endif // __FILE_SYSTEM_LOCAL_FILE_H__