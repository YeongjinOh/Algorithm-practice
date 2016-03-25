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


	// Get the repetition number
	int rep[n];
	for (i=0; i<n; i++)
		rep[i]=k/value[i];	

	// Define minimum array
	// Due to memory issue, I need to use 2-dimensional array
	// For convenience, Set the maximum length of a array as 30000
	int size = 30000;
	int array_dimension = (k-1)/size + 1; // Then the array min is array_dimension by size matrix.
	int  min[array_dimension][size];
	int j;

	// Initialize min array with DEFAULT_VALUE
	for(i=0; i<array_dimension; i++)
		for (j=0; j<size; j++)
			min[i][j]=DEFAULT_VALUE;
	
	for (i=0; i<n; i++)
		min[value[i]/size][value[i]%size]=1;


	// Calculate minimum times when k=sum
	int sum, sum_of_min, left_value, right_value;
	for (sum=1; sum<=k; sum++)
	{
		for (i=1; i<=sum/2; i++)
		{
			left_value = min[i/size][i%size];
			right_value = min[(sum-i)/size][(sum-i)%size];

			// If the way to this value doesn't exist, skip and continue next step
			if(left_value == DEFAULT_VALUE || right_value == DEFAULT_VALUE)
				continue;

			sum_of_min = left_value + right_value;
			// If target minimum value doesn't exist or is greater than sum_of_min, set min=sum_of_min
			if(min[sum/size][sum%size] == DEFAULT_VALUE || min[sum/size][sum%size] > sum_of_min)
				min[sum/size][sum%size] = sum_of_min;
		}
	}

	// Print minimum value
	printf("%d\n",min[k/size][k%size]);

	return 0; 
} 
