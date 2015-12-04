#include <stdio.h>
#include <stdlib.h>
#include "2015_30_11.h"
#include <stdbool.h>
#include <limits.h>
int main()
{
    LLnode* head=NULL;
    head=createRandomLL( 6,100);
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
    addNodeInCLL(head,4);
    */

    //tests for finding maximum contiguous sub array

    int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    maxSumContiguousSubArray(a, n);






    return 0;
}
