#ifndef __STYLE_HEXYL_H__
#define __STYLE_HEXYL_H__

#include "ABCStyle.h"

struct ByteTextStyle
{
    std::string m_color;
    std::string m_byte;
    std::string m_text;
};

class Hexyl : public ABCStyle
{
public:
    Hexyl(bool _colourful = true);
    std::string getPosition(size_t _position);
    std::string getHeader();
    std::string getRow(const std::string& _position, const std::vector<unsigned short>& _dbytes);
    std::string getFooter();
    size_t getBlockSize();
private:
    const std::string& getText(unsigned short _byte);
    const std::string& getByte(unsigned short _byte);
private:
    std::vector<ByteTextStyle> m_byteTextStyle;
    bool m_colourful;
};

#endif // __STYLE_HEXYL_H__