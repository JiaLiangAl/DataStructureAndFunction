#pragma once
typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
    
}ListNode,*LinkList;

int InitList(LinkList *head);
int ListEmpty(LinkList head);
ListNode *Get(LinkList head,int i);
ListNode *LocateElem(LinkList head,DataType e);
int LocatePos(LinkList head,DataType e);
int InsertList(LinkList head,int i,DataType e);
int DeleteList(LinkList head,int i,DataType *e);
int ListLength(LinkList head);
void DestoryList(LinkList head);
