

class Solution
{
public:
    int getTheMonthDays(int year, int month)
    {
        int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if(month == 2)
        {
            if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                return 29;
            }
        }

        return day[month];
    }
};
