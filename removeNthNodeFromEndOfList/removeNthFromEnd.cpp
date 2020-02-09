#include <iostream>

#define method1 1
#define method2 0
#define method3 0


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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *tmp = res;
        for(int i = 0; i < n; ++i)
        {
            head = head->next;
        }
        while(head != NULL)
        {
            head = head->next;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return res->next;
    }
#endif

#if method2
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if(!head->next)
        {
            return NULL;
        }
        ListNode *pre = head, *cur = head;
        for(int i = 0; i < n; ++i)
        {
            cur = cur->next;
        }
        if(!cur)
        {
            return head->next;
        }
        while(cur->next)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
#endif

#if method3
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if(NULL == head || n <= 0)
        {
            return NULL;
        }
        ListNode fakeHead(0);
        fakeHead.next = head;
        head = &fakeHead;

        ListNode *p1, *p2;
        p1 = p2 = head;
        for(int i = 0; i < n; ++i)
        {
            if(NULL == p2)
            {
                return NULL;
            }
            p2 = p2->next;
        }
        while(p2->next != NULL)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p1->next->next;
        return head->next;
    }
#endif
};
