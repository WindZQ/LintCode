#include <string>

#define method1 1
#define method2 0

class Solution
{
#if method1
    char findLetter(std::string &str)
    {
        int visited[26][2];

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                visited[str[i] - 'a'][0] = 1;
            }
            else
            {
                visited[str[i] - 'A'][1] = 1;
            }
        }

        for (int i = 25; i >= 0; --i)
        {
            if (visited[i][0] == 1 &&visited[i][1] == 1)
            {
                return (char)((int)'A' + i);
            }
        }

        return '~';
    }
#endif

#if method2
    char findLetter(std::string &str)
    {
        char status[26];
        memset(status, 0, sizeof(status));

        for (int i = 0; i < str.size(); ++i)
        {
            char temp = str[i];
            if (temp >= 'a' && temp <= 'z')
            {
                status[temp - 'a'] |= 0x1;
            }
            else if (temp >= 'A' && temp <= 'Z')
            {
                status[temp - 'A'] |= 0x2;
            }
        }

        for (int i = 25; i >= 0; --i)
        {
            if (0x03 == status[i])
            {
                return char((int)'A' + i);
            }
        }

        return '~';
    }
#endif
};
