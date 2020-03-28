#include <iostream>

#define method1 1
#define method2 0

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val  = val;
        this->next = NULL;
    }
};

class Solution
{
public:
#if method1
    void deleteNode(ListNode *node)
    {
        if(node == NULL) return;

        if(node->next == NULL)
        {
            delete node;
            node = NULL;
            return;
        }

        ListNode *post = node->next;
        node->val = post->val;
        node->next = post->next;

    }
#endif

#if method2
    void deleteNode(ListNode *node)
    {
        if(!node) return;

        while(node)
        {
            if(node->next)
            {
                node->val = node->next->val;
                if(!node->next->next) node->next = NULL;
                node = node->next;
            }
        }
    }
#endif
};
