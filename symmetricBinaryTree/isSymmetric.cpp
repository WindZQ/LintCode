#include <queue>

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
    bool isSymmetric(TreeNode *root)
    {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if(!left && !right) return true;
        if(left && !right || !left && right || left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
#endif

#if method2
    bool isSymmetric(TreeNode *root)
    {
        if(!root) return true;
        std::queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode *node1 = q1.front();
            q1.pop();
            TreeNode *node2 = q2.front();
            q2.pop();

            if(!node1 && !node2) continue;
            if((node1 && !node2) || (!node1 && node2))
            {
                return false;
            }
            if(node1->val != node2->val)
            {
                return false;
            }

            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }

        return true;
    }
#endif
};
