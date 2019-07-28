#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>
int InitList(LinkList *head)
{
    if ((*head = (LinkList)malloc(sizeof(ListNode)))== NULL)
    {
        return -1;
    }
    (*head) ->next = NULL;

    return 0;
}
int ListEmpty(LinkList head)
{  
    if (head->next == NULL)
    {
        return 1;
    }
    return 0;
}
ListNode *Get(LinkList head,int i)
{
    
    if (ListEmpty(head) || i < 0)
    {
        return NULL;
    }
    int j = 0;
    ListNode *p = head;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (j == i)
    {
        return p;
    }
    return NULL;
}
ListNode *LocateElem(LinkList head,DataType e)
{
    ListNode *p = head->next;
    while (p)
    {
        if(p->data != e)
            p = p->next;
        else
            break;
    }
    return p;
    
}
int LocatePos(LinkList head,DataType e)
{
    if (ListEmpty(head))
    {
        return 0;
    }
    ListNode *p = head->next;

    int i = 0;
    while (p)
    {
        if (p->data == e)
        {
            break;
        }else
        {
            p = p->next;
            i++;
        }
    }
    
    return i;
}
int InsertList(LinkList head,int i,DataType e)
{
    ListNode *pre = head;
    int j = 0;
    while (pre->next != NULL && j < i)
    {
        pre = pre->next;
        j++;
    }
    if (j != i)
    {
        printf("insert position wrong\n");
        return 0;
    }
    ListNode *p;
    if ((p = (ListNode*)malloc(sizeof(ListNode))) == NULL)
    {
        return -1;
    }
    p->data = e;

    p->next = pre->next;
    pre->next = p;
    return 1;
    
}
int DeleteList(LinkList head,int i,DataType *e)
{
    ListNode *pre = head;
    int j = 0;
    while (pre->next != NULL && j < i)
    {
        pre = pre->next;
        j++;
    }
    if (j != i)
    {
        printf("insert position wrong\n");
        return 0;
    }
    ListNode *p = pre->next;
    *e = p->data;
    pre->next = p->next;
    free(p);
    return 1;
}
int ListLength(LinkList head)
{
    ListNode *p = head;
    int count = 0;
    while (p->next != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
    
}
void DestoryList(LinkList head)
{
    ListNode *p = head;
    ListNode *q;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    
}