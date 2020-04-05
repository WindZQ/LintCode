#include <vector>

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
    std::vector<std::vector<int>> binaryTreePathSum(TreeNode *root, int target)
    {
        std::vector<std::vector<int>> result;

        if(root == NULL) return result;

        std::vector<int> path;
        helper(root, 0, target, path, result);

        return result;
    }

    void helper(TreeNode *root, int sum, int target, std::vector<int> path, std::vector<std::vector<int>> &result)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val + sum == target)
            {
                path.push_back(root->val);
                result.push_back(path);
            }
        }

        path.push_back(root->val);

        if(root->left)
        {
            helper(root->left, sum + root->val, target, path, result);
        }

        if(root->right)
        {
            helper(root->right, sum + root->val, target, path, result);
        }
    }
};
