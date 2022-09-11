#include <stack>

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
    TreeNode *increasingBST(TreeNode *root)
    {
        return helper(root, nullptr);
    }

    TreeNode *helper(TreeNode *node, TreeNode *pre)
    {
        if (!node) return pre;
        TreeNode *res = helper(node->left, node);
        node->left = nullptr;
        node->right = helper(node->right, pre);
        return res;
    }
#endif

#if method2
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode(-1), *pre = dummy;
        std::stack<TreeNode*> st;

        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            pre->right = root;
            pre = pre->right;
            root->left = nullptr;
            root = root->right;
        }

        return dummy->right;
    }
#endif
};
