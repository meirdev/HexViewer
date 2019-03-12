#ifndef __STYLE_HEXDUMP_H__
#define __STYLE_HEXDUMP_H__

#include "Style/ABCStyle.h"
#include "StringBuffer/StringBuffer.h"

class HexDump : public ABCStyle
{
public:
    HexDump();
    std::string getPosition(size_t _position);
    std::string getRow(const std::string& _position, const std::vector<unsigned short>& _bytes);
    size_t getBlockSize();
private:
    const std::string& getText(unsigned short _byte);
    const std::string& getByte(unsigned short _byte);
private:
    std::vector<std::pair<std::string, std::string> > m_byteTextStyle;
    StringBuffer m_rowBuffer;
};

#endif // __STYLE_HEXDUMP_H__