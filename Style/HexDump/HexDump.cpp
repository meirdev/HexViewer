#include <sstream>
#include <iomanip>

#include "HexDump.h"

HexDump::HexDump()
: m_rowBuffer(256)
{
    std::stringstream byte;

    for (int i = 0; i < 256; ++i)
    {
        byte << std::setfill('0') << std::setw(2) << std::hex << i;

        if (isprint(i))
        {
            m_byteTextStyle.push_back({ byte.str(), std::string(1, static_cast<char>(i)) });
        }
        else
        {
            m_byteTextStyle.push_back({ byte.str(), "." });
        }

        byte.str("");
    }

    m_byteTextStyle.push_back({ "  ", "" });
}

inline const std::string& HexDump::getByte(unsigned short _byte)
{
    return m_byteTextStyle[_byte].first;
}

inline const std::string& HexDump::getText(unsigned short _byte)
{
    return m_byteTextStyle[_byte].second;
}

inline std::string HexDump::getPosition(size_t _position)
{
    std::stringstream position;

    position << std::setfill('0') << std::setw(8) << std::hex << _position;

    return position.str();
}

std::string HexDump::getRow(const std::string& _position, const std::vector<unsigned short>& _bytes)
{
    m_rowBuffer.clear();

    m_rowBuffer << _position << "  ";
    
    for (size_t i = 0; i < 16; ++i)
    {
        if (i)
        {
            if (i % 8 == 0)
            {
                m_rowBuffer << "  ";
            }
            else
            {
                m_rowBuffer << " ";
            }
        }

        m_rowBuffer << getByte(_bytes[i]);
    }
    
    m_rowBuffer << "  |";
    
    for (size_t i = 0; i < 16; ++i)
    {
        m_rowBuffer << getText(_bytes[i]);
    }

    m_rowBuffer << "|" << "\n";

    return m_rowBuffer.get();
}

inline size_t HexDump::getBlockSize()
{
    return 16;
}