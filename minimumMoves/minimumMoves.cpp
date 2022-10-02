#include <string>

class Solution
{
public:
    int minimumMoves(std::string &s)
    {
        int answer = 0, index = 0, e_index = -1, lette_count = 0;

        while (index < s.size())
        {
            e_index = index +1;

            while (e_index < s.size() && s[index] == s[e_index]) e_index++;

            lette_count = e_index - index;

            if (lette_count >= 3)
            {
                while (lette_count > 5)
                {
                    lette_count -= 3;
                    answer++;
                }

                if (lette_count <= 5) answer++;
            }
            index = e_index;
        }

        return answer;
    }
};
