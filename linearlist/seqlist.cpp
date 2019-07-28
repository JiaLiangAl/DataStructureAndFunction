#include <stdio.h>

#include "seqlist.h"
void InitList(SeqList *L)
{
    L->length = 0;
}
int ListEmpty(SeqList L)
{
    if (L.length ==0)
    {
        return 1;
    }
    return 0;
}

int GetElem(SeqList L,int i,DataType *e)
{
    if (i < 0 || i >=L.length)
    {
        return -1;
    }
    *e = L.list[i];
    return 1;
    
}

int LocateElem(SeqList L,DataType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.list[i] == e)
        {
            return i;
        }
        
    }
    return 0;
}

int InsertList(SeqList *L,int i,DataType e)
{
    if (i < 0 || i > L->length)
    {
        printf("Insert index %d is invalid\n",i);
        return -1;
    }
    else if (L->length >= ListSize)
    {
        printf("Seqlist is full,insert failed\n");
        return 0;
    }
    
    for (int j = L->length -1 ; j  > i; j--)
    {
        L->list[j] = L->list[j-1];
    }
    L->list[i] = e;
    L->length+=1;
    return 1;
}

int DeleteList(SeqList *L,int i,DataType *e)
{
    if (ListEmpty(*L) != 0)
    {
        printf("seqlist is empty,delete failed\n");
        return 0;
    }
    else if (i < 0 || i >= L->length)
    {
        printf("delete index %d is invalid,delete failed\n",i);
        return -1;
    }
    *e = L->list[i];
    for (int j = 0; j < L->length-1; j++)
    {
        L->list[j-1] = L->list[j];
    }
    L->length -= 1;
    return 1;  
}

int ListLength(SeqList L)
{
    return L.length;
}

void ClearList(SeqList *L)
{
    L->length = 0;
}
