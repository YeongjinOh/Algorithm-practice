#include <stdio.h>

int main(void)
{
	// n is the length of array. (1 <= n <= 100,000)
	int n, i, cur, sum, max;
		scanf("%d",&n);
	// For the first input	
		scanf("%d", &sum);
		max = sum;

	// From the second to the last inputs.
	for (i=1; i<n; i++) {
		scanf("%d",&cur);
		if (sum<0)
			sum=0;
		sum += cur;
		if (sum > max)
			max = sum;
	}

	printf("%d\n",max);
	return 0;
}
