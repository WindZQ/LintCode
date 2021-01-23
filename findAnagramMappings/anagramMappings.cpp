#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<int> anagramMappings(std::vector<int> &A, std::vector<int> &B)
    {
        std::vector<int> res;
        std::unordered_map<int, int> m;
        for(int i = 0; i < A.size(); ++i)
        {
            m[B[i]] = i;
        }

        for(int i = 0; i < B.size(); ++i)
        {
            res.push_back(m[A[i]]);
        }

        return res;
    }
#endif

#if method2
    std::vector<int> anagramMappings(std::vector<int> &A, std::vector<int> &B)
    {
        std::vector<int> res;
        std::unordered_map<int, std::vector<int>> index;
        for(int i = 0; i < B.size(); ++i)
        {
            index[B[i]].push_back(i);
        }

        for(int i = 0; i < A.size(); ++i)
        {
            res.push_back(index[A[i]].back());
            index[A[i]].pop_back();
        }

        return res;
    }
#endif
};
