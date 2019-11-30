#include <iostream>
#define method1 0
#define method2 0
#define method3 1

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    #if method1
    ListNode * deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    #endif

    #if method2
    ListNode * deleteDuplicates(ListNode *head)
    {
        if(!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return (head->val == head->next->val) ? head->next : head;
    }
    #endif

    #if method3
    ListNode * deleteDuplicates(ListNode *head)
    {
        for(ListNode *p = head; p && p->next;)
        {
            if(p->val == p->next->val)
            {
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }
        return head;
    }
    #endif

    void printList(ListNode *head)
    {
        while(head != NULL)
        {
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    }

    ListNode *createList(int a[], int n)
    {
        ListNode *head = NULL, *p = NULL;
        for(int i = 0; i < n; ++i)
        {
            if(head == NULL)
            {
                head = p = new ListNode(a[i]);
            }
            else
            {
                p->next = new ListNode(a[i]);
                p = p->next;
            }
        }
        return head;
    }
};

int main(void)
{
    Solution s;
    int a[] = {1, 1, 2, 3, 3};
    int b[] = {1, 1, 1};

    s.printList(s.deleteDuplicates(s.createList(a, sizeof(a) / sizeof(int))));
    s.printList(s.deleteDuplicates(s.createList(b, sizeof(b) / sizeof(int))));
    return 0;
}
