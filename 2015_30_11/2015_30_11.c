#include "2015_30_11.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
//_____________Helper functions____________//
//-----------------------------------------//
LLnode* createNode(int data)
{
    LLnode* node = malloc(sizeof(LLnode));
    node->data=data;
    node->next=NULL;
    return node;
}

LLnode* insertInBegin(LLnode* head,int data)
{
    LLnode* n = createNode(data);
    if(n!=NULL)
        n->next=head;
    return n;
}

LLnode* insertAtEnd(LLnode* head, int data)
{
    LLnode* n=createNode(data);
    LLnode* temp=head;
    if(temp==NULL)
    {
        return n;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        return head;
    }
}

int length(LLnode* head)
{
    int count=1;
    if(head->next==NULL)
    {
        return count;
    }
    else
    {
        while(head->next!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
}

LLnode* createRandomLL(int nodeCount,int max)
{
    LLnode* p=NULL;
    time_t t;
    srand((unsigned) time(&t));
    int i;
    for(i=0;i<nodeCount;i++)
    {
        int m=(rand()%max)+1;
        p=insertAtEnd(p,m);
    }
    return p;
}

void traverse(LLnode* head)
{
    LLnode* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\n");
}
//_______________end of helper functions__________________//
//--------------------------------------------------------//


//______ merging of two sorted lists using recursion_____//
LLnode* sortedMerge(LLnode* a,LLnode* b)
{
    LLnode* result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    else if(a->data >= b->data)
    {
        result=b;
        result->next=sortedMerge(a,b->next);
    }
    else
    {
        result=a;
        result->next=sortedMerge(a->next,b);
    }
    return result;
}

//___________ Median of sorted list___________________//
int median(LLnode* head)
{
    LLnode* p1=head->next;
    LLnode* p2=head;
    //LLnode* p=NULL;
    while(p1!=NULL && p1->next!=NULL)
    {
        p2=p2->next;
        p1=p1->next->next;
    }
    if(p1==NULL)
    {
        return p2->data;
    }
    return (p2->data + p2->next->data)/2;
}

//_________________adding node to CLL_________________//
LLnode* addNodeInCLL(LLnode* head,int n)
{
    if(head==NULL)
            return NULL;
        else if(head!=NULL)
        {
            LLnode* p1=head;
            LLnode* p2=head;
            do
            {
                p1=p1->next->next;
                p2=p2->next;
            }
            while(p1!=p2);
            LLnode* node = createNode(n);
            LLnode* p3=p1->next;
            p1->next=node;
            node->next = p3 ;
            return head;
        }
}

//________reversing a linked list using recursion________//
LLnode* reverse2(LLnode* head)
{
    if(!head->next)
        return head;
    LLnode *hd = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;
    return hd;
}

//_____________Maximum sum contiguous subarray_________//
void maxSumContiguousSubArray(int a[],int n)
{
    int l=0,r=0,tempMax=0,max=0,i,max1=INT_MIN;
    for(i=0;i<n;i++)
    {
        int temp = tempMax+a[i];
        if(temp > 0)
        {
            if(temp > max)
            {
                max = temp;
                r=i+1;
            }
            tempMax = temp;

        }
        else
        {
            if(max1 < a[i])
                max1 = a[i];
            tempMax = 0;
            l=i+1;
        }
    }
    for(i=l;i<r;i++)
        printf("%d ",a[i]);
    if(tempMax > 0)
        printf("\n%d",max);
    else
        printf("\n%d",max1);
}
