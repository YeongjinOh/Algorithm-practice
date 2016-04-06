#include <stdio.h>

int main(void)
{
	// T is the number of test cases, and N is the length of array.
	int T, N;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		int num[N];
		int i;

		// get integer input whose abs value <= 1000
		for (i=0; i<N; i++)
			scanf("%d",&num[i]);

		// calculate maximum subarray
		int max=-1000, sum=0;
		i=0;

		while (i<N) {
			if (sum<0)
				sum=0;
			sum += num[i++];
			if (sum > max)
				max = sum;
		}
		printf("%d\n",max);
	}
	return 0;
}
