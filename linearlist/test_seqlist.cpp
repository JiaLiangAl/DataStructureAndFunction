#include <stdio.h>
#include "seqlist.h"

typedef int DataType;

void MergeList(SeqList A,SeqList B,SeqList *C);
int main(int argc,char** argv)
{
    DataType a[] = {8,17,17,25,29};
    DataType b[] = {3,9,21,21,26,57};

    DataType e;
    SeqList A,B,C;
    InitList(&A);
    InitList(&B);
    InitList(&C);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        if (InsertList(&A,i,a[i]) == 0)
        {
            return -1;
        }
        
    }
    for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
    {
        if (InsertList(&B,i,b[i]) == 0)
        {
            return -1;
        }
        
    }
    
    printf("printf the elements in A\n");
    for (int i = 0; i < A.length; i++)
    {
        int flag = GetElem(A,i,&e);
        if (flag == 1)
        {
            printf("%4d",e);
        }
        
    }
    printf("\n");

    printf("printf the elements in B\n");
    for (int i = 0; i < B.length; i++)
    {
        int flag = GetElem(B,i,&e);
        if (flag == 1)
        {
            printf("%4d",e);
        }
        
    }
    printf("\n");

    printf("Merge A and B to C\n");
    MergeList(A,B,&C);

    printf("printf the elements in C\n");
    for (int i = 0; i < C.length; i++)
    {
        int flag = GetElem(C,i,&e);
        if (flag == 1)
        {
            printf("%4d",e);
        }
        
    }
    printf("\n");
    
    
    return 0;
}


void MergeList(SeqList A,SeqList B,SeqList *C)
{
    DataType e1,e2;
    int i = 0,j = 0,k = 0; 
    while (i < A.length && j < B.length)
    {
        GetElem(A,i,&e1);
        GetElem(B,j,&e2);
        if (e1<e2)
        {
            InsertList(C,k,e1);
            i++;
            k++;
        }else
        {
            InsertList(C,k,e2);
            j++;
            k++;
        }
        
        
    }

    while (i < A.length)
    {
        GetElem(A,i,&e1);
        InsertList(C,k,e1);
        i++;
        k++;
    }
    while (j < B.length)
    {
        GetElem(B,j,&e2);
        InsertList(C,k,e2);
        j++;
        k++;
    }
    C->length = A.length + B.length;

    
    
}

