#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string compress(std::string &originalString)
    {
        std::vector<int> counters(26, 0);
        std::string newString;
        int len = originalString.size();

        char currChar = originalString[0];
        counters[currChar - 'a'] = 1;

        for(int i = 1; i < len; ++i)
        {
            if(originalString[i] != currChar)
            {
                newString = newString + currChar + to_string(counters[currChar - 'a']);
                counters[currChar - 'a'] = 0;
                currChar = originalString[i];
            }
            counters[currChar - 'a']++;
        }

        newString = newString + currChar + to_string(counters[currChar - 'a']);

        if(newString.size() >= len)
        {
            return originalString;
        }
        else
        {
            return newString;
        }
    }
};
