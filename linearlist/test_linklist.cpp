#include <stdio.h>
#include <mm_malloc.h>
#include "linklist.h"


void MergeList(LinkList A,LinkList B,LinkList *C);
int main(int argc,char** argv)
{
    DataType a[] = {8,17,17,25,29};
    DataType b[] = {3,9,21,21,26,57};
    LinkList A,B,C;
    InitList(&A);
    InitList(&B);
    InitList(&C);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        if (InsertList(A,i,a[i]) == 0)
        {
            return -1;
        }
        
    }
    for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
    {
        if (InsertList(B,i,b[i]) == 0)
        {
            return -1;
        }
        
    }
    
    printf("printf the elements in A\n");
    for (int i = 0; i < ListLength(A); i++)
    {
        ListNode *p = Get(A,i);
        if (p)
        {
            printf("%4d",p->data);
        }
        
    }
    printf("\n");

    printf("printf the elements in B\n");
    for (int i = 0; i < ListLength(B); i++)
    {
        ListNode *p = Get(B,i);
        if (p)
        {
            printf("%4d",p->data);
        }
        
    }
    printf("\n");

    printf("Merge A and B to C\n");
    MergeList(A,B,&C);

    printf("printf the elements in C\n");
    for (int i = 0; i < ListLength(C); i++)
    {
        ListNode *p = Get(C,i);
        if (p)
        {
            printf("%4d",p->data);
        }
        
    }
    printf("\n");
    
    
    return 0;
}


void MergeList(LinkList A,LinkList B,LinkList *C)
{
    ListNode *pa = A->next;
    ListNode *pb = B->next;
    ListNode *qa,*qb;
    free(B);
    *C = A;
    (*C)->next = NULL;
    while (pa && pb)
    {
        if(pa->data < pb->data)
        {
            qa = pa;
            pa = pa->next;
            if ((*C)->next == NULL)
            {
                qa->next = (*C)->next;
                (*C)->next = qa;
            }else if ((*C)->next->data < qa->data)
            {
                qa ->next = (*C)->next;
                (*C)->next = qa;
            }else
            {
                free(qa);
            }
        }
        else
        {
            qb = pb;
            pb = pb->next;
            if ((*C)->next == NULL)
            {
                qb->next = (*C)->next;
                (*C)->next = qb;
            }else if ((*C)->next->data  < qb->data)
            {
                qb->next = (*C)->next;
                (*C)->next = qb;
            }else
            {
                free(qb);
            }
        }
        
    }

    while (pa)
    {
        qa = pa;
        pa = pa->next;
        if((*C)->next && (*C)->next->data < qa->data)
        {
            qa->next = (*C)->next;
            (*C)->next = qa;
        }else
        {
            free(qa);
        }
        
    }
    while (pb)
    {
        qb = pb;
        pb = pb->next;
        if((*C)->next && (*C)->next->data < qb->data)
        {
            qb->next = (*C)->next;
            (*C)->next = qb;
        }else
        {
            free(qb);
        }
        
    }
    
}