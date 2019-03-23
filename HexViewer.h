#ifndef __HEX_VIEWER_H__
#define __HEX_VIEWER_H__

#include <string>

#include "Style/IStyle.h"
#include "Printer/IPrinter.h"
#include "FileStream/IFile.h"

class HexViewer
{
public:
    HexViewer();
    ~HexViewer();
    void setStyle(std::string _style, bool _colors = true);
    void setPrinter(std::string _printer);
    void setFile(std::string _file, std::string _fileName, size_t _offset = 0, size_t _length = 0);
    void print();
private:
    IStyle*   m_style;
    IPrinter* m_printer;
    IFile*    m_file;
};

#endif // __HEX_VIEWER_H__