#include <vector>
#include <string>
#include <map>
#include <pair>
#include <queue>

#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    std::vector<std::string> findRelativeRanks(std::vector<int> &nums)
    {
        int n = nums.size(), cnt = 1;
        std::vector<std::string> res(n, "");
        std::priority_queue<std::pair<int, int>> q;
        for(int i = 0; i < n; ++i)
        {
            q.push({nums[i], i});
        }

        for(int i = 0; i < n; ++i)
        {
            int idx = q.top().second; q.pop();
            if(cnt == 1) res[idx] = "Gold Medal";
            else if(cnt == 2) res[idx] = "Silver Medal";
            else if(cnt == 3) res[idx] = "Bronze Medal";
            else res[idx] = std::to_string(cnt);
            ++cnt;
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> findRelativeRanks(std::vector<int> &nums)
    {
        int n = nums.size(), cnt = 1;
        std::vector<std::string> res(n, "");
        std::map<int, int> m;
        for(int i = 0; i < n; ++i)
        {
            m[nums[i]] = i;
        }

        for(auto it = m.rbegin(); it != m.rend(); ++it)
        {
            if(cnt == 1) res[it->second] = "Gold Medal";
            else if(cnt == 2) res[it->second] = "Silver Medal";
            else if(cnt == 3) res[it->second] = "Bronze Medal";
            else res[it->second] = std::to_string(cnt);
            ++cnt;
        }

        return res;
    }
#endif

#if method3
    std::vector<std::string> findRelativeRanks(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> idx(n);
        std::vector<std::string> res(n, "");
        for(int i = 0; i < n; ++i) idx[i] = i;
        std::sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] > nums[b];});

        for(int i = 0; i < n; ++i)
        {
            if(i == 0) res[idx[i]] = "Gold Medal";
            else if(i == 1) res[idx[i]] = "Silver Medal";
            else if(i == 2) res[idx[i]] = "Bronze Medal";
            else res[idx[i]] = std::to_string(i + 1);
        }

        return res;
    }
#endif
};
