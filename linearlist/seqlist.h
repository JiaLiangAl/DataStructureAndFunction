#pragma once
#ifndef ListSize
#define ListSize 100
#endif
typedef int DataType;
typedef struct 
{
    DataType list[ListSize];
    int length;
}SeqList;

void InitList(SeqList *L);

int ListEmpty(SeqList L);

int GetElem(SeqList L,int i,DataType *e);

int LocateElem(SeqList L,DataType e);

int InsertList(SeqList *L,int i,DataType e);

int DeleteList(SeqList *L,int i,DataType *e);

int ListLength(SeqList L);

void ClearList(SeqList *L);