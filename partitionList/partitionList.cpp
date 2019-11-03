#include <cstdio>
#define method1 0
#define method2 1

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
    void printList(ListNode* h)
    {
        while(h != NULL)
        {
            printf("%d ", h->val);
            h = h->next;
        }
        printf("\n");
    }

    ListNode* createList(int a[], int n)
    {
         ListNode *head = NULL, *p = NULL;
         for(int i=0; i<n; i++)
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
#if method1
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *leftDummy = new ListNode(0);
        ListNode *rightDummy = new ListNode(0);
        ListNode *leftTail = leftDummy;
        ListNode *rightTail = rightDummy;
        while(head != NULL)
        {
            if(head->val < x)
            {
                leftTail->next = head;
                leftTail = head;
            }
            else
            {
                rightTail->next = head;
                rightTail = head;
            }
            head = head->next;
        }
        leftTail->next = rightDummy->next;
        rightTail->next = NULL;
        return leftDummy->next;
    }
#endif

#if method2
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while(pre->next && pre->next->val < x)
            pre = pre->next;
        cur = pre;
        while(cur->next)
        {
            if(cur->next->val < x)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
                pre = pre->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
#endif
};

int main()
{
    int a[] = {3, 1, 2};
    int x = 3;
    Solution s;
    ListNode *p = s.createList(a, sizeof(a) / sizeof(int));
    s.printList(p);
    p = s.partition(p, x);
    s.printList(p);
    return 0;
}
