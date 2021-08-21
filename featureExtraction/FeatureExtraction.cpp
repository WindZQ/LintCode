#include <vector>
#include <pair>
#include <map>

class Solution
{
public:
    int FeatureExtraction(std::vector<std::vector<int>> &frames)
    {
        std::map<std::pair<int, int>, int> pre_featimes;
        std::map<std::pair<int, int>, int> feal_times;
        int count = 0;
        std::pair<int, int> xy;
        for(int i = 0; i < frames.size(); ++i)
        {
            for(int j = 0; j < frames[i][0]; ++j)
            {
                xy.first = frames[i][j * 2  + 1];
                xy.second = frames[i][j * 2 + 2];

                if(pre_featimes.count(xy))
                {
                    feal_times[xy] = pre_featimes[xy] + 1;
                }
                else
                {
                    feal_times[xy] = 1;
                }

                count = std::max(count, feal_times[xy]);
            }

            pre_featimes.clear();
            pre_featimes.swap(feal_times);
        }

        return count;
    }
};
