#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#define method1 1
#define method2 0

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
        ListNode *head=NULL, *p=NULL;
        for(int i = 0; i < n; ++i)
        {
            if (head == NULL)
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        while(head != NULL)
        {
            ListNode *temp = dummy;
            ListNode *next = head->next;
            while(temp->next != NULL && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy->next;
    }
#endif

#if method2
    ListNode *insertionSortList(ListNode *head)
    {
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return head;
        }
        ListNode *p, *q;
        p = head;
        q = p;
        std::vector<int> v;
        while(head != NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int i, j;
        for(i = 0; i < v.size(); ++i)
        {
            for(j = i; j > 0; j--)
            {
                if(v[j - 1] > v[j])
                {
                    int temp = v[j - 1];
                    v[j - 1] = v[j];
                    v[j] = temp;
                }
            }
        }
        i = 0;
        while(p != NULL)
        {
            p->val = v[i];
            p = p->next;
            ++i;
        }
        return q;
    }
#endif
};

int main(int argc, char** argv)
{
    Solution s;
    int n = 10;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    srand(time(NULL));

    int *a = new int[n];
    for(int i = 0; i < n; ++i)
    {
        a[i] = random()%n + 1;
    }

    ListNode *p = s.createList(a, n);
    s.printList(p);
    s.printList(s.insertionSortList(p));

    delete[] a;
    a = NULL;

    return 0;
}
