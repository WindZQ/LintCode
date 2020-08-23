#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
private:
    int sum = 0, depth = 1;
public:
#if method1
    int depthSum(const std::vector<NestedInteger> &nestedList)
    {
        int sum = 0, depth = 1;
        for(auto i : nestedList)
        {
            if(i.isInteger())
            {
                sum += i.getInteger() * depth;
            }
            else
            {
                depth++;
                depthSum(i.getList());
                depth--;
            }
        }

        return sum;
    }
#endif

#if method2
    int depthSum(const std::vector<NestedInteger> & nestedList)
    {
        int res = 0;
        for(auto a : nestedList)
        {
            res += getSum(a, 1);
        }

        return res;
    }

    int getSum(NestedInteger ni, int level)
    {
        int res = 0;
        if(ni.isInteger()) return level * ni.getInteger();
        for(auto a : ni.getList())
        {
            res += getSum(a, level + 1);
        }

        return res;
    }
#endif

#if method3
    int depthSum(std::vector<NestedInteger> &nestedList)
    {
        return helper(nestedList, 1);
    }

    int helper(std::vector<NestedInteger> ni, int depth)
    {
        int res = 0;
        for(auto a : ni)
        {
            res += a.isInteger() ? a.getInteger() * depth : helper(a.getList(), depth + 1);
        }

        return res;
    }
#endif
};
