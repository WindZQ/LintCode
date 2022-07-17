#include <unordered_map>
#include <vector>

class Solution
{
public:
    bool partitioningArray(std::vector<int> &a, int k)        {
        if (a.size() == 0) return false;
        if (a.size() % k != 0) return false;

        int sub_num = a.size() / k;
        std::unordered_map<int, int> elemet_count;
        int max_count = 0;

        for (auto &i : a)
        {
            if (elemet_count.find(i) != elemet_count.end())
            {
                elemet_count[i]++;
            }
            else
            {
                elemet_count[i] = 1;
            }

            max_count = std::max(max_count, elemet_count[i]);
        }

        return max_count <= sub_num;
    }
};
