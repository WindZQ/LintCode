#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    bool isOneBitCharacter(std::vector<int> &bits)
    {
        int n = bits.size(), i = 0;
        while(i < n - 1)
        {
            i += bits[i] + 1;
        }

        return i == n - 1;
    }
#endif

#if method2
    bool isOneBitCharacter(std::vector<int> &bits)
    {
        int n = bits.size(), i = 0;
        while(i < n - 1)
        {
            if(bits[i] == 0)
            {
                ++i;
            }
            else
            {
                i += 2;
            }
        }

        return i == n - 1;
    }
#endif

#if method3
    bool isOneBitCharacter(std::vector<int> &bits)
    {
        if(bits.empty()) return false;
        if(bits.size() == 1) return bits[0] == 0;
        std::vector<int> v;
        if(bits[0] == 0)
        {
            v = std::vector<int>(bits.begin() + 1, bits.end());
        }
        else if(bits[0] == 1)
        {
            v = std::vector<int>(bits.begin() + 2, bits.end());
        }

        return isOneBitCharacter(v);
    }
#endif

#if method4
    bool isOneBitCharacter(std::vector<int> &bits)
    {
        return helper(bits, 0);
    }

    bool helper(std::vector<int> &bits, int idx)
    {
        int n = bits.size();
        if(idx == n) return false;
        if(idx == n - 1) return bits[idx] == 0;
        if(bits[idx] == 0) return helper(bits, idx + 1);
        return helper(bits, idx + 2);
    }
#endif
};
