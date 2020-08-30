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
    int longestConsecutive(TreeNode *root)
    {
        return helper(root, NULL, 0);
    }

    int helper(TreeNode *root, TreeNode *parents, int len)
    {
        if(!root) return len;
        len = (parents && root->val == parents->val + 1) ? len + 1 : 1;
        return std::max(len, max(helper(root->left, root, len), helper(root->right, root, len)));
    }
#endif

#if method2
    int longestConsecutive(TreeNode *root)
    {
        if(root == nullptr) return 0;
        int ret = 1, len = 1;
        helper(nullptr, root, len, ret);
        return ret;
    }

    void helper(TreeNode *parents, TreeNode *root, int len, int &ret)
    {
        if(root == nullptr) return;
        if(parents != nullptr && parents->val + 1 == root->val)
        {
            len++;
            ret = std::max(ret, len);
        }
        else
        {
            len = 1;
        }

        helper(root, root->left, len, ret);
        helper(root, root->right, len, ret);
    }
#endif
};
