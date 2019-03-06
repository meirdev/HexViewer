#ifndef __ISTYLE_H__
#define __ISTYLE_H__

#include <string>
#include <vector>
#include <cstddef> // size_t

class IStyle
{
public:
    virtual ~IStyle() = default;
    virtual std::string getPosition(size_t _position) = 0;
    virtual std::string getHeader() = 0;
    virtual std::string getRow(const std::string& _position, const std::vector<unsigned short>& _dbytes) = 0;
    virtual std::string getFooter() = 0;
    virtual size_t getBlockSize() = 0;
};

#endif // __ISTYLE_H__