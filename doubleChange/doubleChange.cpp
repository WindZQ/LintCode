class Soution
{
public:
    int DoubleChange(int A, int B, int p, int q)
    {
        int times = 0;
        long long res = A, pchange = p;

        while(res < B)
        {
            if((res + pchange) >= B)
            {
                res += pchange;
            }
            else
            {
                pchange = pchange * q;
            }
            times++;
        }

        return times;
    }
};
