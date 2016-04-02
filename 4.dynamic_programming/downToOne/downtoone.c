#include <stdio.h>

int main(void)
{
	// get initail input N
	int N;
	scanf("%d",&N);
	
	// for dynamic programming, pre-define array for minimum value to the number
	int num[N], i;

	// each i-th element corresponds to the number of minimum way to (i+1)
	num[0] = 0;

	for (i=1; i<N; i++)
	{
		num[i] = num[i-1];
		if (((i+1)%3 == 0) && (num[(i+1)/3-1] < num[i]))
			num[i] = num[(i+1)/3-1];
		if (((i+1)%2 == 0) && (num[(i+1)/2-1] < num[i]))
			num[i] = num[(i+1)/2-1];
		num[i]++;
	}

	// print output which is the number of ways from N down to 1
	printf("%d",num[N-1]);

	return 0;
}
