#include <string>

#define method1 1
#define method2 0

class StringUtils
{
public:
#if method1
    static std::string leftPad(std::string &originalStr, int size, char padChar = ' ')
    {
        if(size <= originalStr.size()) return originalStr;
        return std::string(size - originalStr.size(), padChar) + originalStr;
    }
#endif

#if method2
    static std::string leftPad(std::string &originalStr, int size, char padChar = ' ')
    {
        return size <= originalStr.size() ? originalStr : std::string(size - originalStr.size(), padChar) + originalStr;
    }
#endif
};
