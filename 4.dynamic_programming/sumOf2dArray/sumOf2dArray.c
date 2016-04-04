#include <stdio.h>

void sumOf2dArray(int N, int M, int num[N][M]);

int main(void)
{
	// get inputs. (N, M) is the size of 2d_array, K = number of sum.
	int N, M, K, i, j;
	scanf("%d%d",&N, &M);
	int num[N][M];
	for (i=0; i<N; i++)
		for (j=0; j<M; j++)
			scanf("%d",&num[i][j]);
	scanf("%d",&K);
	
	// print the result K times
	for (i=0; i<K; i++)
		sumOf2dArray(N, M, num);
	return 0;
}

void sumOf2dArray(int N, int M, int num[N][M])
{
	int i, j, x, y;
	scanf("%d%d%d%d", &i, &j, &x, &y);

	int sum = 0;
	int row, col;
	for (row=i-1; row<x; row++)
		for(col=j-1; col<y; col++)
			sum += num[row][col];
	printf("%d\n",sum);
}
