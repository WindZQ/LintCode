#include <vector>
#include <string>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    std::vector<int> findAnagrams(std::string &s, std::string &p)
    {
        if(s.empty()) return {};
        std::vector<int> res, cnt(128, 0);
        int ns = s.size(), np = p.size(), i = 0;

        for(char c : p) ++cnt[c];
        while(i < ns)
        {
            bool success = true;
            std::vector<int> tmp = cnt;
            for(int j = i; j < i + np; ++j)
            {
                if(--tmp[s[j]] < 0)
                {
                    success = false;
                    break;
                }
            }
            if(success)
            {
                res.push_back(i);
            }
            ++i;
        }
        return res;
    }
#endif

#if method2
    std::vector<int> findAnagrams(std::string &s, std::string &p)
    {
        if(s.empty()) return {};
        std::vector<int> res, m1(256, 0), m2(256, 0);
        for(int i = 0; i < p.size(); ++i)
        {
            ++m1[s[i]];
            ++m2[p[i]];
        }

        if(m1 == m2) res.push_back(0);
        for(int i = p.size(); i < s.size(); ++i)
        {
            ++m1[s[i]];
            --m1[s[i - p.size()]];
            if(m1 == m2)
            {
                res.push_back(i - p.size() + 1);
            }
        }

        return res;
    }
#endif

#if method3
    std::vector<int> findAnagrams(std::string &s, std::string &p)
    {
        if(s.empty()) return {};
        std::vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for(char c : p) ++m[c];

        while(right < n)
        {
            if(m[s[right++]]-- >= 1) --cnt;
            if(cnt == 0) res.push_back(left);
            if(right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
        }
        return res;
    }
#endif
}
