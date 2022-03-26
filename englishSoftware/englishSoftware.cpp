#include <vector>
#include <map>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    struct stu
    {
        int ind;
        double sco;
        stu(int _ind, double _sco)
        {
            ind = _ind;
            sco = _sco;
        }

        bool operator<(const stu &A) const
        {
            return sco < A.sco;
        }
    };

    std::vector<int> englishSoftware(std::vector<int> &score, std::vector<int> &ask)
    {
        std::map<int, double> vec;
        std::vector<stu> sort_vec;

        for(int i = 0; i < score.size(); ++i)
        {
            vec[i + 1] = score[i];
            sort_vec.push_back(stu(i, score[i]));
        }

        std::sort(sort_vec.begin(), sort_vec.end());
        std::map<double, double> m;
        for(int i = 0; i < sort_vec.size(); ++i)
        {
            m[sort_vec[i].sco] = (double) i * 100 / sort_vec.size();
        }

        std::vector<int> res;
        for(int k : ask)
        {
            res.push_back(floor(m[vec[k]]));
        }

        return res;
    }
#endif

#if method2
    std::vector<int> englishSoftware(std::vector<int> &score, std::vector<int> &ask)
    {
        std::vector<int> res;
        std::vector<int> sscore(score.begin(), score.end());
        std::sort(sscore.begin(), sscore.end());

        for(int &i : ask)
        {
            auto it = std::upper_bound(sscore.begin(), sscore.end(), score[i - 1]);
            if(it == sscore.begin())
            {
                res.push_back(0);
            }
            else
            {
                double val = double(it - sscore.begin()) - 1;
                res.push_back(val * 100 / score.size());
            }
        }

        return res;
    }
#endif
};
