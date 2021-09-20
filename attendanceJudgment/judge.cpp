#include <string>

class Solution
{
public:
    bool judge(std::string &record)
    {
        int length = record.size();
        int max_l = 1, count_l = 1;
        int count_d = 0;

        for(int i = 0; i < length; ++i)
        {
            if(record[i] == 'D')
            {
                count_d++;
            }
            else if(record[i] == 'L')
            {
                if(i < length - 1 && record[i] == record[i + 1])
                {
                    count_l++;
                    max_l = std::max(max_l, count_l);
                }
                else
                {
                    count_l = 1;
                }
            }
        }

        if(max_l >= 3 || count_d >= 2)
        {
            return true;
        }

        return false;
    }
};
