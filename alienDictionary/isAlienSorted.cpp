#include <string>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int index[30];
    bool isAlienSorted(std::vector<std::string> &words, std::string &order)
    {
        int i = 0;
        while (order[i])
        {
            int temp = order[i] - 'a';
            index[temp] = ++i;
        }

        for (i = 0; i < words.size() - 1; ++i)
        {
            if (!compare(words[i], words[i + 1]))
            {
                return false;
            }
        }

        return true;
    }

    bool compare(std::string &first, std::string &second)
    {
        int i = 0;
        while (first[i] && second[i])
        {
            if (index[first[i] - 'a'] == index[second[i] - 'a'])
            {
                ++i;
            }
            else
            {
                break;
            }
        }

        if (first[i] && second[i] == 0) return false;
        if (first[i] && second[i] && index[first[i] - 'a'] > index[second[i] - 'a']) return false;

        return true;
    }
#endif

#if method2
    bool isAlienSorted(std::vector<std::string> &words, std::string &order)
    {
        int temp[26];

        for (int i = 0; i < 26; temp[order[i++] - 'a'] = i + 'a');

        for (auto &word : words)
        {
            for (auto &ch : word)
            {
                ch = temp[ch - 'a'];
            }
        }

        return is_sorted(words.cbegin(), words.cend());
    }
#endif
};
