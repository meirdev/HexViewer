#ifndef __STYLE_HEXYL_H__
#define __STYLE_HEXYL_H__

#include "Style/IStyle.h"

struct ByteTextStyle
{
    std::string m_color;
    std::string m_byte;
    std::string m_text;
};

class Hexyl : public IStyle
{
public:
    Hexyl(bool _colourful = true);
    std::string position(size_t _position);
    std::string header();
    std::string footer();
    std::string row(const std::string& _position, const std::vector<unsigned short>& _dbytes);
    size_t blockSize();
private:
    const std::string& getText(unsigned short _byte);
    const std::string& getByte(unsigned short _byte);
private:
    std::vector<ByteTextStyle> m_byteTextStyle;
    bool m_colourful;
};

#endif // __STYLE_HEXYL_H__