#include <vector>
#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    char nextGreatestLetter(std::string &letters, char target)
    {
        if(target >= letters.back()) return letters[0];
        int n = letters.size(), left = 0, right = n;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(letters[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return letters[right];
    }
#endif

#if method2
    char nextGreatestLetter(std::string &letters, char target)
    {
        auto it = std::upper_bound(letters.begin(), letters.end(), target);

        return it == letters.end() ? *letters.begin() : *it;
    }
#endif
};
