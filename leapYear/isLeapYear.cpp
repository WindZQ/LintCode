class Solution
{
public:
    bool isLeapYear(int n)
    {
        return (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0));
    }
};
