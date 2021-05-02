#include <string>
#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<std::string> subdomainVisits(std::vector<std::string> &cpdomains)
    {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> subdomaincnt;

        for(std::string cpdomain : cpdomains)
        {
            int space_idx = cpdomain.find(" ");
            int cnt = stoi(cpdomain.substr(0, space_idx));
            std::string rem = cpdomain.substr(space_idx + 1);

            for(int i = 0; i < rem.size(); ++i)
            {
                if(rem[i] == '.')
                {
                    subdomaincnt[rem.substr(i + 1)] += cnt;
                }
            }
            subdomaincnt[rem] += cnt;
        }

        for(auto a : subdomaincnt)
        {
            res.push_back(to_string(a.second)  + " " + a.first);
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> subdomainVisits(std::vector<std::string> &cpdomains)
    {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> subdomaincnt;
        for(std::string cpdomain : cpdomains)
        {
            int space_idx = cpdomain.find(" ");
            int cnt = stoi(cpdomain.substr(0, space_idx));
            while(space_idx != std::string::npos)
            {
                subdomaincnt[cpdomain.substr(space_idx + 1)] += cnt;
                space_idx = cpdomain.find('.', space_idx + 1);
            }
        }

        for(auto a : subdomaincnt)
        {
            res.push_back(to_string(a.second) + " " + a.first);
        }

        return res;
    }
#endif
};
