#include <vector>
#include <algorithm>

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
    int res = 110, pre = -1;
    int minDiffInBST(TreeNode *root)
    {
        if(root->left != NULL)
        {
            minDiffInBST(root->left);
        }

        if(pre != -1)
        {
            res = std::min(res, root->val - pre);
        }
        pre = root->val;

        if(root->right != NULL)
        {
            minDiffInBST(root->right);
        }

        return res;
    }
#endif

#if method2
    int minDiffInBST(TreeNode *root)
    {
        std::vector<int> sorted;
        inorder(root, sorted);
        int min_diff = sorted.back();
        for(int i = 1; i < sorted.size(); ++i)
        {
            min_diff = std::min(min_diff, sorted[i] - sorted[i - 1]);
        }

        return min_diff;
    }

    void inorder(TreeNode *root, std::vector<int> &sorted)
    {
        if(!root) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }
#endif
};
