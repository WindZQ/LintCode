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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr) return nullptr;
        if (val == root->val) return root;

        return searchBST(val < root->val ? root->left : root->right, val);
    }
#endif

#if method2
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (val == root->val) return root;

            root = val < root->val ? root->left : root->right;
        }

        return nullptr;
    }
#endif
};
