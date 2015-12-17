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

//______________ Median of sorted list___________________//
int median(LLnode* head)
{
    LLnode* p1=head->next;
    LLnode* p2=head;
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


//_______________find r when n1,n2 are given_______________//
int find_R_givenN1_N2(int n1,int n2,int r)
{
    int rthN = 0,x=n1,y=n2,i;
	for (i = 0; i < r; i++){
		if (x < y)
			rthN = x;
		else
			rthN = y;
		if (rthN >= x)
			x = x + n1;
		if (rthN >= y)
			y = y + n2;
	}
	return rthN;
}


//_________________add two linked lists____________________//
LLnode* addLLinReverse(LLnode* head,LLnode* head1,LLnode* head2)
{
    int l=length(head);
    int l1=length(head1);
    if(l>l1)
    {
        int d= l-l1;
        while(d!=0)
        {
            head1=insertAtEnd(head1,0);
            d--;
        }
    }
    else if(l1>l)
    {
        int d=l1-l;
        while(d!=0)
        {
            head=insertAtEnd(head,0);
            d--;
        }
    }
    head=reverse2(head);
    head1=reverse2(head1);
    LLnode* p=head;
    LLnode* p1=head1;
    int res=0;
    while(p!=NULL)
    {
        int add=p->data+p1->data+res;
        head2=insertAtEnd(head2,add%10);
        res=add/10;
        p=p->next;
        p1=p1->next;
    }
    head2=insertAtEnd(head2,res);
    return reverse2(head2);
}

//______________print last 10 lines in a file___________//

void lastNLinesInFile(FILE* fp)
{
    int offset = 0;
    int line = 1;
    char ch;
    FILE* f = fp;
    while(line < 20 && fp != f)
    {
        if(fseek(fp,-1*offset,SEEK_END)!=-1)
        {
            ch=fgetc(fp);
            if(ch == '\n')
                line++;
        }
        offset++;
    }
    char c;
    while( ( c = fgetc(fp) ) != EOF )
        printf("%c",c);
}


//________sort LL which is sorted in inc Order but two numbers are exchanged_______//
LLnode* sortLL2NumChanged(LLnode* head)
{
    LLnode *p=head->next;
	LLnode *ptr1=head;
	LLnode *ptr2=head;
	while(p!=NULL)
	{
		if(ptr1->data > p->data)
		{
			ptr2=ptr2->next;
			while(p->data <= ptr2->data)
                ptr2 = ptr2->next;
            int temp=ptr2->data;
            ptr2->data=ptr1->data;
            ptr1->data=temp;
            break;
		}
		else
		{
			ptr1=ptr1->next;
			p=p->next;
			ptr2=ptr2->next;

		}
	}
	return head;
}

