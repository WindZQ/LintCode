#include <iostream>
#include <vector>

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
    TreeNode *sortedArrayToBST(std::vector<int> &A)
    {
        if(A.size() == 0)
        {
            return NULL;
        }
        int len = A.size();
        return buildTree(A, 0, len - 1);
    }

    TreeNode *buildTree(std::vector<int> &A, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(A[mid]);
        root->left = buildTree(A, start, mid - 1);
        root->right = buildTree(A, mid + 1, end);
        return root;
    }
#endif

#if method2
    TreeNode *sortedArrayToBST(std::vector<int> &A)
    {
        if(A.empty())
        {
            return NULL;
        }

        int mid = A.size() / 2;
        TreeNode *cur = new TreeNode(A[mid]);
        std::vector<int> left(A.begin(), A.begin() + mid), right(A.begin() + mid + 1, A.end());
        cur->left = sortedArrayToBST(left);
        cur->right = sortedArrayToBST(right);
        return cur;
    }
#endif
};
