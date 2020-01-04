#include <iostream>
#define method1 0
#define method2 0
#define method3 0

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
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);

        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
#endif

#if method2
    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        int res = 0;
        std::queue<TreeNode* > q{{root}};
        while(!q.empty())
        {
            ++res;
            for(int i = q.size(); i > 0; --i)
            {
                auto t = q.front();
                q.pop();
                if(!t->left && !t->right) return res;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return -1;
    }
#endif

#if method3
    int solve_dp(TreeNode *root)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }

        int lf = 0x7fffffff, rt = 0x7fffffff;
        if(root->left) lf = solve_dp(root->left);
        if(root->right) rt = solve_dp(root->right);

        return std::min(lf, rt) + 1;
    }

    int minDepth(TreeNode *root)
    {
        if(!root) return 0;
        return solve_dp(root);
    }
#endif
};
