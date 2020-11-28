#include <math>

class Solution
{
public:
    float timeAngle(int h, int m)
    {
        float m_angle = m * 6;
        float h_angle = (h + m / 60.0) * 30;
        float res = std::abs(m_angle - h_angle);
        res -= std::floor(res / 360) * 360;
        if(res > 180)
        {
            res = 360 - res;
        }

        return res;
    }
};
