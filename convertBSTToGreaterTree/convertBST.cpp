#inclue <stack>

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
    TreeNode * convertBST(TreeNode *root)
    {
        int sum = 0;
        helper(root, sum);
        return root;
    }

    void helper(TreeNode * &node, int &sum)
    {
        if(!node) return;
        helper(node->right, sum);
        node->val += sum;
        sum = node->val;
        helper(node->left, sum);
    }
#endif

#if method2
    int sum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if(!root) return NULL;
        sum = 0;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);

        return root;
    }
#endif

#if method3
    TreeNode *convertBST(TreeNode *root)
    {
        if(!root) return NULL;
        int sum = 0;
        std::stack<TreeNode *> s;
        TreeNode *p = root;

        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);
                p = p->right;
            }

            p = s.top();
            s.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }

        return root;
    }
#endif
};
