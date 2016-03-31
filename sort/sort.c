#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 30
#define MOD 100

void bubble_sort(int val[], int length)
{
	int i, j, tmp;
	for (i=length-1; i>0; i--)
	{
		bool swapped = false;
		for (j=0; j<i; j++)
			if (val[j] < val[j+1])
			{
				tmp = val[j];
				val[j] = val[j+1];
				val[j+1] = tmp;
				swapped = true;
			}
		if (!swapped)
			break;
	}
}


int main(void)
{
	srand(time(NULL));
	
	// generate random number
	int rand_num[LENGTH], i;
	for (i=0; i<LENGTH; i++) {
		rand_num[i]= rand()%MOD;
	}

	// sort the random number array
	bubble_sort(rand_num,LENGTH);
	
	// print sorted array
	for (i=0; i<LENGTH; i++) {
		printf("%d ",rand_num[i]);
	}
	printf("\n");

	return 0;
}
