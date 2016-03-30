#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_VALUE  -1

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

	// Define minimum array
	int size = 10001;
	int  min[size];
	int j;

	// Initialize min array with DEFAULT_VALUE
	for (i=0; i<size; i++)
			min[i]=DEFAULT_VALUE;
	
	for (i=0; i<n; i++)
	{
		if(value[i]>=size)
			continue;
		min[value[i]]=1;
	}

	// Calculate minimum times when k=sum
	int sum;
	for (i=0; i<n; i++)
	{
		for (sum=value[i]; sum<=k; sum++)
		{
			if (min[sum-value[i]] == DEFAULT_VALUE)
				continue;
			else if (min[sum] == DEFAULT_VALUE || min[sum-value[i]]+1 < min[sum])
				min[sum] = min[sum-value[i]]+1;

		}
	}

	// Print minimum value
	printf("%d\n",min[k]);

	return 0; 
} 
