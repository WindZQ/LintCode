#include <stack>
#include <queue>

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
        this->val = this->right = NULL;
    }
};

class Solution
{
public:
#if method1
    bool pathSum(TreeNode *root, int sum)
    {
        if (!root) return false;

        if (!root->left && !root->right && root->val == sum) return true;

        return pathSum(root->left, sum - root->val) || pathSum(root->right, sum - root->val);
    }
#endif

#if method2
    bool pathSum(TreeNode *root, int sum)
    {
        if (!root) return false;

        std::stack<TreeNode*> s{{root}};

        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();

            if (!t->left && !t->right)
            {
                if(t->val == sum) return true;
            }

            if (t->left)
            {
                t->left->val += t->val;
                s.push(t->left);
            }

            if (t->right)
            {
                t->right->val += t->val;
                s.push(t->right);
            }
        }

        return false;
    }
#endif

#if method3
    bool pathSum(TreeNode *root, int sum)
    {
        if (!root) return false;

        std::queue<TreeNode *> que_node;
        std::queue<int> que_val;

        que_node.push(root);
        que_val.push(root->val);

        while (!que_node.empty())
        {
            TreeNode *now = que_node.front();

            int temp = que_val.front();
            que_node.pop();
            que_val.pop();

            if (!now->left && !now->right)
            {
                if (temp == sum) return true;

                continue;
            }

            if (now->left)
            {
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }

            if (now->right)
            {
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }

        return false;
    }
#endif
};
