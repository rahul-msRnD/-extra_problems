#include <stdio.h>
#include <stdlib.h>
#include "2015_30_11.h"
#include <stdbool.h>
#include <limits.h>
int main()
{
    LLnode* head=NULL;
    head=createRandomLL( 5,10);
    //traverse(head);
    // tests for reversing LL
    /*
    head = reverse2(head);
    traverse(head);
    */

    //tests for finding median
    /*
    printf("%d",median(head));
    */

    //tests for adding node in a CLL
    /*
    LLnode* head1=createRandomLL( 2,100);
    head1->next->next->next = head1;
    addNodeInCLL(head1,4);
    */

    //tests for finding maximum contiguous sub array
    /*
    int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    maxSumContiguousSubArray(a, n);
    */

    //tests for finding rth number if n1,n2 are given
    /*
    printf("%d",find_R_givenN1_N2(3,5,8));
    */

    //tests for adding two linked lists, all cases covered
    /*
    LLnode* head1 = createRandomLL(4,10);
    LLnode* head2=NULL;

    head2 = addLLinReverse(head,head1,head2);
    traverse(head2);
    */




    return 0;
}
