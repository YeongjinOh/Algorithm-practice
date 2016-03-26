#include <stdio.h>

int main(void)
{
	// Get inputs M, N
	int M, N;
	scanf("%d %d", &M, &N);

	// Get height of each position
	int	height[M][N];
	int i,j;
	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			scanf("%d",&height[i][j]);

	// Print the output
	int path=0;
	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			path += height[i][j];

	printf("%d\n",path);


	return 0;
}
