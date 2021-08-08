#include <queue>
#include <vector>

#define method1 1
#define method2 0

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution
{
public:
#if method1
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        if(!root) return {};
        std::vector<double> res;
        std::queue<TreeNode*> q{{root}};

        while(!q.empty())
        {
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; ++i)
            {
                TreeNode *t = q.front();
                q.pop();
                sum += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

            res.push_back(sum / n);
        }

        return res;
    }
#endif

#if method2
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::vector<double> res, cnt;
        helper(root, 0, cnt, res);

        for(int i = 0; i < res.size(); ++i)
        {
            res[i] /= cnt[i];
        }

        return res;
    }

    void helper(TreeNode *node, int level, std::vector<double> &cnt, std::vector<double> &res)
    {
        if(!node) return;

        if(res.size() <= level)
        {
            res.push_back(0);
            cnt.push_back(0);
        }

        res[level] += node->val;
        ++cnt[level];
        helper(node->left, level + 1, cnt, res);
        helper(node->right, level + 1, cnt, res);
    }
#endif
};
