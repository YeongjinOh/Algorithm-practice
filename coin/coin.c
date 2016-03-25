#include <stdio.h>


int main(void)
{
	// Get the input n, k
	int n,k;
	scanf("%d %d",&n,&k);

	// Get the values of coin
	int value[n];
	int i;
	for (i=0; i<n; i++)
	scanf("%d",&value[i]);

	int min;

	// Print minimum value
	printf("%d\n",min);

	return 0; 
} 
