#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	long long pinary[2][N];

	pinary[0][0] = 0;
	pinary[1][0] = 1;
	
	int i;
	for(i=1; i<N; i++) {
		pinary[0][i] = pinary[0][i-1] + pinary[1][i-1];
		pinary[1][i] = pinary[0][i-1];
	}

	printf("%lld",pinary[0][N-1]+pinary[1][N-1]);
	
	return 0;
}
