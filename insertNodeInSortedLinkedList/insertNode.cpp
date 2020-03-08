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
    ListNode *insertNode(ListNode *head, int val)
    {
        if(!head)
        {
            return new ListNode(val);
        }

        ListNode *newNode = new ListNode(val);

        if(val < head->val)
        {
            newNode->next = head;
            return newNode;
        }
        ListNode *node = head;

        while(node && node->next)
        {
            if(val >= node->val && val < node->next->val)
            {
                newNode->next = node->next;
                node->next = newNode;
                break;
            }
            node = node->next;
        }
        node->next = newNode;
        return head;
    }
#endif

#if method2
    ListNode *insertNode(ListNode *head, int val)
    {
        ListNode *cur = new ListNode(val);
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        if(!head)
        {
            return cur;
        }

        ListNode *p = dummy;
        while(p->next)
        {
            if(p->next->val > val)
            {
                break;
            }
            else
            {
                p = p->next;
            }
        }
        cur->next = p->next;
        p->next = cur;
        return dummy->next;
    }
#endif
};
