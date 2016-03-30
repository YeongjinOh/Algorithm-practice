#include <stdio.h>

int main(void)
{
	// get initial input. M is the amount of money the rich owns, N is the number of kind of coins. 
	int M, N;
	scanf("%d%d",&M,&N);

	// get the value of each coin
	int i;
	int value[N];
	for (i=0; i<N; i++)
		scanf("%d",&value[N]);


	printf("M:%d, N:%d\n",M,N);

	return 0;
}
