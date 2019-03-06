#ifndef __LOCAL_FILE_H__
#define __LOCAL_FILE_H__

#include <fstream>
#include <string>

#include "ABCFile.h"

class LocalFile : public ABCFile
{
public:
    LocalFile(IPrinter& _printer, const std::string& _fileName);
    void print();
private:
    std::ifstream m_file;
};

#endif // __LOCAL_FILE_H__