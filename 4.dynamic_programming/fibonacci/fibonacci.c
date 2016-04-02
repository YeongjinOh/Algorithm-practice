#include <stdio.h>

int main(void)
{
	// T = the number of test cases
	int T;
	scanf("%d",&T);

	long fib[41];
	fib[0]=0;
	fib[1]=1;

	int i=2;
	while(i<41)
	{
		fib[i]=fib[i-1]+fib[i-2];
		i++;
	}

	int n[T];
	for (i=0; i<T; i++)
		scanf("%d",&n[i]);
	for (i=0; i<T; i++)
	{
		if(n[i] == 0)
			printf("1 0\n");
		else
			printf("%ld %ld\n",fib[n[i]-1],fib[n[i]]);
	}

	return 0;
}
