#include <iostream>
#include <string>
#include <unordered_map>
#define method1 0
#define method2 0
#define method3 1



class Soluction
{
public:
#if method1
    //时间复杂度为O(n),空间复杂度为O(1)
    bool compareString(std::string &A, std::string &B)
    {
        int count[26] = {0};
        for(int i = 0; i < A.size(); ++i)
            count[A[i] - 'A']++;
        for(int i = 0; i < A.size(); ++i)
            count[B[i] - 'A']--;
        for(int i = 0; i < 26; ++i)
        {
            if(count[i] < 0)
                return false;
        }
        return true;
    }
#endif

#if method2
    //时间复杂度为O(n),空间复杂度为O(1)
    bool compareString(std::string &A, std::string &B)
    {
        if(A.size() < B.size())
            return false;
        int letter[26] = {0};
        for(int i = 0; i < A.size(); ++i)
            letter[A[i] - 'A']++;
        for(int i = 0; i < B.size(); ++i)
        {
            if(letter[B[i] - 'A'] <= 0)
                return false;
            else
                letter[B[i] - 'A']--;
        }
        return true;
    }
#endif

#if method3
    //时间复杂度为O(1), 空间复杂度为O(n)
    bool compareString(std::string &A, std::string &B)
    {
        std::unordered_map<char, int> table;
        for(int i = 0; i < A.size(); ++i)
            table[A[i]]++;
        for(int i = 0; i < B.size(); ++i)
        {
            if(table.find(B[i]) != table.end() && table[B[i]] > 0)
                table[B[i]]--;
            else
                return false;
        }
        return true;
    }
#endif
};

int main()
{
    Soluction s;
    std::string str = "ABC";
    std::string str2 = "AC";
    if(s.compareString(str, str2))
        std::cout << "True\n" << std::endl;
    else
        std::cout << "False\n" << std::endl;
    return 0;
}
