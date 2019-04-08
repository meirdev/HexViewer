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
    void setStyle(const std::string& _style, bool _colors = true);
    void setPrinter(const std::string& _printer);
    void setFile(const std::string& _file);
    void print(int _offset = 0, size_t _length = 0);
private:
    IStyle*   m_style;
    IPrinter* m_printer;
    IFile*    m_file;
};

#endif // __HEX_VIEWER_H__