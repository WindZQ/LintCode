#include <vector>
#include <pair>
#include <set>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int findElements(std::vector<std::vector<int>> &Matrix)
    {
        int w = Matrix[0].size();
        int l = Matrix.size();
        std::vector<int> list;

        for(int i = 0; i < w; ++i)
        {
            list.push_back(Matrix[0][i]);
        }

        for(int i = 1; i < l; ++i)
        {
            std::set<int> st;
            for(int j = 0; j < w; ++j)
            {
                st.insert(Matrix[i][j]);
            }

            for(int j = 0; j < list.size(); ++j)
            {
                if(st.find(list[j]) == st.end())
                {
                    list.erase(list.begin() + j);
                }
            }
        }
        return list[0];
    }
#endif

#if method2
    int findElements(std::vector<std::vector<int>> &Matrix)
    {
        std::unordered_map<int, std::pair<int, int>> hash;
        for(int i = 0; i < Matrix.size(); ++i)
        {
            for(int j = 0; j < Matrix[0].size(); ++j)
            {
                if(hash.count(Matrix[i][j]))
                {
                    if(hash[Matrix[i][j]].first == i)
                    {
                        continue;
                    }
                    else
                    {
                        hash[Matrix[i][j]].first = i;
                        ++hash[Matrix[i][j]].second;
                    }
                }
                else
                {
                    hash[Matrix[i][j]] = std::make_pair(i, 1);
                }
            }
        }

        for(auto &&elem : hash)
        {
            if(elem.second.second == Matrix.size())
            {
                return elem.first;
            }
        }

        return 0;
    }
#endif
};
