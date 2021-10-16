#include <unordered_map>

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
    std::unordered_map<TreeNode *, int> m;
    int findTilt(TreeNode *root)
    {
        if(!root) return 0;
        int tilt = std::abs(get_sum(root->left, m) - get_sum(root->right, m));

        return tilt + findTilt(root->left) + findTilt(root->right);
    }

    int get_sum(TreeNode *node, std::unordered_map<TreeNode *, int> &m)
    {
        if(!node) return 0;
        if(m.count(node)) return m[node];
        return m[node] = get_sum(node->left, m) + get_sum(node->right, m) + node->val;
    }
#endif

#if method2
    int findTilt(TreeNode *root)
    {
        int res = 0;
        postorder(root, res);

        return res;
    }

    int postorder(TreeNode *node, int &res)
    {
        if(!node) return 0;
        int left_sum = postorder(node->left, res);
        int right_sum = postorder(node->right, res);
        res += std::abs(left_sum - right_sum);

        return left_sum + right_sum + node->val;
    }
#endif
}
