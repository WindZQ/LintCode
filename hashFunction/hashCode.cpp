#include <iostream>
#include <string>

class Solution
{
public:
    int hashCode(std::string &key, int HASH_SIZE)
    {
        long ans = 0;
        for(int i = 0; i < key.size(); ++i)
        {
            ans = (1LL * ans * 33 + key[i]) % HASH_SIZE;
        }
        return (int)ans;
    }
};

int main(void)
{
    std::string key = "abcd";
    int size = 1000;
    Solution s;
    std::cout << s.hashCode(key, size) << std::endl;
    return 0;
}
