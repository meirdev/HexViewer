#ifndef __HEX_DUMP_H__
#define __HEX_DUMP_H__

#include "ABCStyle.h"
#include "StringBuffer.h"

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

#endif // __HEX_DUMP_H__