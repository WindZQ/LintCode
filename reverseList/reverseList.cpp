#include <cstdio>
#include <cstdlib>

typedef int ElemType;
#ifndef LIST_NODE
#define LIST_NODE
struct ListNode
{
    ElemType data;
    struct ListNode *next;
};
#endif
//ͷ�巨
ListNode * createList(ListNode *head)
{
    head = (ListNode *)malloc(sizeof(ListNode));
    if(head == NULL)
        printf("malloc failed!\n");
    head->next = NULL;
    printf("Please input the number:");
    int n;
    ElemType x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->data = x;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

//β�巨
ListNode * createListTail(ListNode *head)
{
    head = (ListNode *)malloc(sizeof(ListNode));
    if(head == NULL)
        printf("malloc failed!\n");
    printf("Please input the number:");
    int n;
    ElemType x;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        head->next = p;
        head = p;
    }
    head->next = NULL;
    return head;
}

ListNode * reverseList(ListNode * head)
{
    if(NULL == head || NULL == head->next)
        return head;
    else
    {
       ListNode* newhead =  reverseList(head->next);
       head->next->next = head;
       head->next = NULL;
       return newhead;
    }
}

ListNode * reverseList1(ListNode *head)
{
    if(NULL == head || NULL == head->next)
        return head;
    ListNode *prev = head;
    ListNode *cur = head->next;
    ListNode *temp = NULL;
    while(cur)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head->next = NULL;
    return prev;
}

void printList(ListNode *head)
{
    ListNode *p = head->next;
    while(p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void destroy(ListNode *head)
{
    ListNode *p = head->next;
    while(p != NULL)
    {
        free(p);
        p = p->next;
    }
}

int main()
{
    ListNode *head, *p, *q;
    p = createList(head);
    printList(p);
    q = reverseList(p);
    printf("\n");
    printList(q);
    return 0;
}
