#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::vector<std::string>> getList(std::vector<std::vector<std::string>>  &datalist1, std::vector<std::vector<std::string>> &datalist2)
    {
        int n = datalist1.size();
        std::vector<std::vector<std::string>> res;

        for(int i = 0; i < n; ++i)
        {
            res.push_back(std::vector<std::string> {datalist1[i][1]});
            int sum = 0;
            for(int j = 2; j < 7; j += 2)
            {
                res[i].push_back(datalist2[i][j]);
                sum += atoi(datalist2[i][j].c_str());
            }

            res[i].push_back(to_string(sum));
        }
        return res;
    }
};
