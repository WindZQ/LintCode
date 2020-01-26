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
    ListNode *nthToLast(ListNode *head, int n)
    {
        if(head == NULL || n < 1)
        {
            return NULL;
        }

        ListNode *p1 = head;
        ListNode *p2 = head;

        for(int i = 0; i < n - 1; ++i)
        {
            if(p2 == NULL)
            {
                return NULL;
            }
            p2 = p2->next;
        }

        while(p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
#endif

#if method2
    ListNode *nthToLast(ListNode *head, int n)
    {
        int len = 0;
        ListNode *temp = head;
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        temp = head;

        while(len != n && temp)
        {
            temp = temp->next;
            len--;
        }
        return temp;
    }
#endif
};
