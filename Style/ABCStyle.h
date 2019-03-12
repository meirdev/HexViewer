#ifndef __STYLE_ABCSTYLE_H__
#define __STYLE_ABCSTYLE_H__

#include "Style/IStyle.h"

class ABCStyle : public IStyle
{
public:
    std::string getHeader();
    std::string getFooter();
};

#endif // __STYLE_ABCSTYLE_H__