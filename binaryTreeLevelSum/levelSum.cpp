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
    int levelSum(TreeNode *root, int level)
    {
        dfs(root, 1, level);
        return sum;
    }

    void dfs(TreeNode *root, int depth, int level)
    {
        if(root == NULL) return;

        if(depth == level)
        {
            sum += root->val;
        }

        dfs(root->left, depth + 1, level);
        dfs(root->right, depth + 1, level);
    }
private:
    int sum = 0;
#endif

#if method2
    int levelSum(TreeNode *root, int level)
    {
        if(root == NULL) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int l = 0, sum = 0;
        while(q.size())
        {
            ++l;
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }

                if(l == level)
                {
                    sum += node->val;
                }
            }
        }
        return sum;
    }
#endif
};
