#include <set>
#include <vector>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int distributeCandies(std::vector<int> &candies)
    {
        std::unordered_set<int> s;
        for(int candy : candies) s.insert(candy);
        return std::min(s.size(), candies.size() / 2);
    }
#endif

#if method2
    int distributeCandies(std::vector<int> &candies)
    {
        return std::min(std::unordered_set<int>(candies.begin(), candies.end()).size(), candies.size() / 2);
    }
#endif
};
