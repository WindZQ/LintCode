#include <string>

class Solution
{
public:
    std::string convert(long long index)
    {
        index--;
        long long row_index = index / 702 + 1;
        std::string result = std::to_string(row_index);
        index = index % 702;
        int div = index / 26, rem = index % 26;
        if (div > 0) result += 'A' - 1 + div;

        result += 'A' + rem;

        return result;
    }
};
