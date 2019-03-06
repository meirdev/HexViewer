#ifndef __ABCSTYLE_H__
#define __ABCSTYLE_H__

#include "IStyle.h"

class ABCStyle : public IStyle
{
public:
    std::string getHeader();
    std::string getFooter();
};

#endif // __ABCSTYLE_H__