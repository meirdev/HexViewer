#ifndef __STYLE_ISTYLE_H__
#define __STYLE_ISTYLE_H__

#include <string>
#include <vector>
#include <cstddef> // size_t

class IStyle
{
public:
    virtual ~IStyle() = default;
    virtual std::string position(size_t _position) = 0;
    virtual std::string header();
    virtual std::string footer();
    virtual std::string row(const std::string& _position, const std::vector<unsigned short>& _dbytes) = 0;
    virtual size_t blockSize() = 0;
};

#endif // __STYLE_ISTYLE_H__