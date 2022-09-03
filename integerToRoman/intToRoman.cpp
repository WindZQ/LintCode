#include <string>
#include <pair>

#define method1 1
#define method2 0

#if method1
const std::pair<int, std::string> valueSymbols[] =
{
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};
#endif

#if method2
const std::string thousands[] = {"", "M", "MM", "MMM"};
const std::string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const std::string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const std::string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
#endif

class Solution
{
public:
#if method1
    std::string intToRoman(int n)
    {
        std::string roman;

        for (const auto &[value, symbol] : valueSymbols)
        {
            while (n >= value)
            {
                n -= value;
                roman += symbol;
            }

            if (n == 0)
            {
                break;
            }
        }

        return roman;
    }
#endif

#if method2
    std::string intToRoman(int n)
    {
        return thousands[n / 1000] + hundreds[n % 1000 / 100] + tens[n % 100 / 10] + ones[n % 10];
    }
#endif
};
