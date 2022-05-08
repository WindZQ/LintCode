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
    TreeNode *convertSortedArraytoBinarySearchTree(std::vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(std::vector<int> &nums, int left, int right)
    {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;

        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = helper(nums, left, mid - 1);
        cur->right = helper(nums, mid + 1, right);

        return cur;
    }
#endif

#if method2
    TreeNode *convertSortedArraytoBinarySearchTree(std::vector<int> &nums)
    {
        if (nums.empty()) return NULL;

        int mid = nums.size() / 2;

        TreeNode *cur = new TreeNode(nums[mid]);
        std::vector<int> left(nums.begin(), nums.begin() + mid), right(nums.begin() + mid + 1, nums.end());
        cur->left = convertSortedArraytoBinarySearchTree(left);
        cur->right = convertSortedArraytoBinarySearchTree(right);

        return cur;
    }
#endif
};
