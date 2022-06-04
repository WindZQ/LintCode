#include <queue>


class DoublyListNode
{
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val)
    {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class TreeNode
{
public:
    int val;
    TressNode *left, *right;
    TressNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

clas Solution
{
public:
    DoublyListNode *bstToDoublyList(TreeNode *root)
    {
        if (root == NULL) return NULL;

        preorder(root);
        int num = data.size();

        DoublyListNode *head = new DoublyListNode(data.front());
        DoublyListNode *pre = head;
        DoublyListNode *now;
        data.pop();

        for (int i = 0; i < num - 1; ++i)
        {
            now = new DoublyListNode(data.front());
            now->next = NULL;
            now->prev = pre;
            pre->next = now;
            pre = now;
            data.pop();
        }

        return head;
    }

    void preorder(TreeNode *root)
    {
        if (root == NULL) return ;

        preorder(root->left);
        data.push(root->val);
        preorder(root->right);
    }

private:
    std::queue<int> data;
};
