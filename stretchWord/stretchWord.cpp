#include <string>

class Solution
{
public:
    long long strectWord(std::string &s)
    {
        long res = 1;
        int index = 0;

        while (index + 1 < s.size())
        {
            int count = 1;
            while (index + 1 < s.size() && s[index] == s[index + 1])
            {
                index += 1;
                count += 1;
            }

            if (count >= 2)
            {
                res *= 2;
            }

            index += 1;
        }

        return res;
    }
};
