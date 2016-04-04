#include <stdio.h>

int main(void)
{
	// get inputs. (N, M) is the size of 2d_array, K = number of sum.
	int N, M, K, i, j;
	scanf("%d%d",&N, &M);
	int num[N][M];
	
	// When getting input, directly add previous elements in order to make this array sum of all elements from (0,0)
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
		{
			scanf("%d",&num[i][j]);
			if (i)
				num[i][j] += num[i-1][j];
			if (j)
				num[i][j] += num[i][j-1];
			if (i && j)
				num[i][j] -= num[i-1][j-1];
		}
	scanf("%d",&K);
	
	int i1, i2, j1, j2, sum;
	// print the result K times
	for (i=0; i<K; i++)
	{
		scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
		sum = num[i2-1][j2-1];
		if (i1-1)
			sum -= num[i1-2][j2-1];
		if (j1-1)
			sum -= num[i2-1][j1-2];
		if (i1-1 && j1-1)
			sum += num[i1-2][j1-2];
		printf("%d\n",sum);
	}
		return 0;
}
