#include <vector>
#include <string>

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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::vector<int> leaf1, leaf2;

        helper(root1, leaf1);
        helper(root2, leaf2);

        return leaf1 == leaf2;
    }

    void helper(TreeNode *node, std::vector<int> &leaf)
    {
        if (!node) return;
        if (!node->left && !node->right)
        {
            leaf.push_back(node->val);
        }

        helper(node->left, leaf);
        helper(node->right, leaf);
    }
#endif

#if method2
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::string leaf1, leaf2;

        helper(root1, leaf1);
        helper(root2, leaf2);

        return leaf1 == leaf2;
    }

    void helper(TreeNode *node, std::string &leaf)
    {
        if (!node) return;
        if (!node->left && !node->right)
        {
            leaf += std::to_string(node->val) + "-";
        }

        helper(node->left, leaf);
        helper(node->right, leaf);
    }
#endif
};
