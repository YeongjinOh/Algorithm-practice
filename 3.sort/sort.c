#include "sort.h"


int main(void)
{
	srand(time(NULL));
	
	// generate random number
	int i;
	for (i=0; i<LENGTH; i++) {
		back_up[i]= rand()%MOD;
	}
	
	printf("The LENGTH of random elements : %d\n", LENGTH);

	sort(bubble_sort,"Bubble");
	sort(insertion_sort, "Insertion");
	sort(merge_sort, "Merge");

	return 0;
}
