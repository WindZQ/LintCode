#include <string>


#define method1 1
#define method2 0
#define method3 0


class Solution
{
public:
#if method1
    std::string reverseVowels(std::string &s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(is_vowel(s[left]) && is_vowel(s[right]))
            {
                std::swap(s[left++], s[right--]);
            }
            else if(is_vowel(s[left]))
            {
                --right;
            }
            else
            {
                ++left;
            }
        }

        return s;
    }

    bool is_vowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
#endif

#if method2
    std::string reverseVowels(std::string &s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            left = s.find_first_of("aeiouAEIOU", left);
            right = s.find_last_of("aeiouAEIOU", right);
            if(left < right)
            {
                std::swap(s[left++], s[right--]);
            }
        }

        return s;
    }
#endif

#if method3
    std::string reverseVowels(std::string &s)
    {
        int left = 0, right = s.size() - 1;
        std::string t = "aeiouAEIOU";
        while(left < right)
        {
            if(t.find(s[left]) == std::string::npos) ++left;
            else if(t.find(s[right]) == std::string::npos) --right;
            else std::swap(s[left++], s[right--]);
        }

        return s;
    }
#endif
};
