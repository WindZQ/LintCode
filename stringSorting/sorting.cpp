#include <string>

class Solution
{
public:
    void qsort(std::vector<std::string> &s, int m, int n)
    {
        int i = m, j = n;
        std::string k = s[(i + j) / 2];

        while(i <= j)
        {
            while(s[i] < k)
            {
                i++;
            }
            while(s[j] > k)
            {
                j--;
            }

            if(i <= j)
            {
                std::swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        if(i < n) qsort(s, i, n);
        if(m < j) qsort(s, m, j);
    }

    std::string sorting(std::string &s)
    {
        std::vector<std::string> str;
        std::string now = "";

        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == ',')
            {
                str.push_back(now);
                now = "";
            }
            else
            {
                now += s[i];
            }
        }
        str.push_back(now);
        qsort(str, 0, str.size() - 1 );

        std::string res = "";
        for(int i = 0;i < str.size(); ++i)
        {
            res += (i == 0 ? "" : ",") + str[i];
        }

        return res;
    }
};
