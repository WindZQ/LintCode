#include <queue>
#include <algorithm>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


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
    int findSecondMinimumValue(TreeNode *root)
    {
        int first = root->val, second = INT_MAX;
        helper(root, first, second);
        return (second == first || second == INT_MAX) ? -1 : second;
    }

    void helper(TreeNode *node, int &first, int &second)
    {
        if(!node) return ;
        if(node->val != first && node->val < second)
        {
            second = node->val;
        }

        helper(node->left, first, second);
        helper(node->right, first, second);
    }
#endif

#if method2
    int findSecondMinimumValue(TreeNode *root)
    {
        return helper(root, root->val);
    }

    int helper(TreeNode *node, int first)
    {
        if(!node) return -1;
        if(node->val != first) return node->val;
        int left = helper(node->left, first), right = helper(node->right, first);

        return (left == -1 || right == -1) ? std::max(left, right) : std::min(left, right);
    }
#endif

#if method3
    int findSecondMinimumValue(TreeNode *root)
    {
        if(!root->left) return -1;
        int left = (root->left->val == root->val) ? findSecondMinimumValue(root->left) : root->left->val;
        int right = (root->right->val == root->val) ? findSecondMinimumValue(root->right) : root->right->val;
        return (left == -1 || right == -1) ? std::max(left, right) : std::min(left, right);
    }
#endif

#if method4
    int findSecondMinimumValue(TreeNode *root)
    {
        int first = root->val, second = INT_MAX;
        std::queue<TreeNode *> q{{root}};

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            if(t->val != first && t->val < second)
            {
                second = t->val;
            }

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }

        return (second == first || second == INT_MAX) ? -1 : second;
    }
#endif
};
