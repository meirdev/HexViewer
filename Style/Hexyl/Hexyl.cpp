#include <sstream>
#include <iomanip>

#include "Style/Hexyl/Hexyl.h"

Hexyl::Hexyl(bool _colourful)
: m_colourful(_colourful)
{
    std::stringstream byte;

    for (int i = 0; i < 256; ++i)
    {
        byte << std::setfill('0') << std::setw(2) << std::hex << i;

        if (!i)
        {
            m_byteTextStyle.push_back({ "38;5;242", byte.str(), "0" });
        }
        else if (isspace(i))
        {
            m_byteTextStyle.push_back({ "32", byte.str(), i != 0x20 ? "_" : " " });
        }
        else if (iscntrl(i))
        {
            m_byteTextStyle.push_back({ "35", byte.str(), "•" });
        }
        else if (isprint(i))
        {
            m_byteTextStyle.push_back({ "36", byte.str(), std::string(1, static_cast<char>(i)) });
        }
        else
        {
            m_byteTextStyle.push_back({ "33", byte.str(), "×" });
        }

        byte.str("");
    }

    if (_colourful)
    {
        for (int i = 0; i < 256; ++i)
        {
            m_byteTextStyle[i].m_byte = "\x1b[" + m_byteTextStyle[i].m_color + "m" + m_byteTextStyle[i].m_byte + "\x1b[0m";
            m_byteTextStyle[i].m_text = "\x1b[" + m_byteTextStyle[i].m_color + "m" + m_byteTextStyle[i].m_text + "\x1b[0m";
        }
    }

    m_byteTextStyle.push_back({ "", "  ", " " });
}

inline const std::string& Hexyl::getByte(unsigned short _byte)
{
    return m_byteTextStyle[_byte].m_byte;
}

inline const std::string& Hexyl::getText(unsigned short _byte)
{
    return m_byteTextStyle[_byte].m_text;
}

inline std::string Hexyl::position(size_t _position)
{
    std::stringstream position;

    if (m_colourful)
    {
        position << "\x1b[38;5;242m" << std::setfill('0') << std::setw(8) << std::hex << _position << "\x1b[0m";
    }
    else
    {
        position << std::setfill('0') << std::setw(8) << std::hex << _position;
    }

    return position.str();
}

static std::string Repeat(const std::string& _string, size_t _length)
{
    std::stringstream fs;

    for (size_t i = 0; i < _length; ++i)
    {
        fs << _string;
    }

    return fs.str();
}

inline std::string Hexyl::header()
{
    std::stringstream header;

    std::string repeat8  = Repeat("─", 8);
    std::string repeat25 = Repeat("─", 25);

    header << "┌" << repeat8 << "┬" << repeat25 << "┬" << repeat25 << "┬" << repeat8 << "┬" << repeat8 << "┐" << std::endl;

    return header.str();
}

inline std::string Hexyl::footer()
{
    std::stringstream footer;

    std::string repeat8  = Repeat("─", 8);
    std::string repeat25 = Repeat("─", 25);

    footer << "└" << repeat8 << "┴" << repeat25 << "┴" << repeat25 << "┴" << repeat8 << "┴" << repeat8 << "┘" << std::endl;

    return footer.str();
}

std::string Hexyl::row(const std::string& _position, const std::vector<unsigned short>& _bytes)
{
    std::stringstream row;

    row << "│" << _position << "│ ";

    for (size_t i = 0; i < 16; ++i)
    {
        if (i)
        {
            if (i % 8 == 0)
            {
                row << " ┊ ";
            }
            else
            {
                row << " ";
            }
        }

        row << getByte(_bytes[i]);
    }
    
    row << " │";
    
    for (size_t i = 0; i < 16; ++i)
    {
        if (i && (i % 8 == 0))
        {
            row << "┊";
        }

        row << getText(_bytes[i]);
    }

    row << "│" << std::endl;

    return row.str();
}

inline size_t Hexyl::blockSize()
{
    return 16;
}