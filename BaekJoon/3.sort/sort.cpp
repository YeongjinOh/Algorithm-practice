#include "sort.h"
#include <iostream>
int main(void)
{
    srand(time(NULL));

    // generate random number
    int i;
    for (i=0; i<LENGTH; i++) {
        back_up[i]= rand()%MOD;
    }

    printf("The LENGTH of random elements : %d\n", LENGTH);

//    sort(bubble_sort,"Bubble");
//    sort(insertion_sort, "Insertion");
    sort(merge_sort, "MERGE");
    sort(heap_sort, "HEAP");
    sort(quick_sort, "QUICK");
//    sort(counting_sort, "COUNTING");
//    sort(radix_sort, "RADIX");

    i = 3;
    //	printf("%d-th largest value : %d\n",i, selection (back_up, 1, LENGTH, i));

    return 0;
}
