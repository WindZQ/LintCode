#include <string>
#include <vector>

#define method1 1
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
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> res;
        if(root) helper(root, "", res);
        return res;
    }

    void helper(TreeNode *node, std::string out, std::vector<std::string> &res)
    {
        if(!node->left && !node->right) res.push_back(out + std::to_string(node->val));
        if(node->left) helper(node->left, out + std::to_string(node->val) + "->", res);
        if(node->right) helper(node->right, out + std::to_string(node->val) + "->", res);
    }
#endif

#if method2
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        if(!root) return {};
        if(!root->left && !root->right) return {std::to_string(root->val)};
        std::vector<std::string> left = binaryTreePaths(root->left);
        std::vector<std::string> right = binaryTreePaths(root->right);
        left.insert(left.end(), right.begin(), right.end());
        for(auto &a : left)
        {
            a = std::to_string(root->val) + "->" + a;
        }

        return left;
    }
#endif

#if method3
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        if(!root) return {};
        if(!root->left && !root->right) return {std::to_string(root->val)};

        std::vector<std::string> res;
        for(std::string str :binaryTreePaths(root->left))
        {
            res.push_back(std::to_string(root->val) + "->" + str);
        }
        for(std::string str : binaryTreePaths(root->right))
        {
            res.push_back(std::to_string(root->val) + "->" + str);
        }

        return res;
    }
#endif
};
