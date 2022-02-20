#include <cstdio>

class Solution
{
public:
    int count_primeNum(int N)
    {
        int ans = 0;
        bool vis[100005];
        int prime[100005];
        memset(vis, 0, sizeof(vis));

        for(int i = 2; i <= N; ++i)
        {
            prime[i] = 1;
        }

        for(int i = 2; i <= N; ++i)
        {
            ans += prime[i];
            for(int j = 2; i * j <= N && j <= i; ++j)
            {
                if(vis[i * j]) continue;
                vis[i * j] = 1;
                prime[i * j] = prime[i] + prime[j];
            }
        }

        return ans;
    }
};
