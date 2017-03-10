#include <stdio.h>

// Get the number of path from (i+1,j+1) to (M,N)
int get_path(int M, int N, int height[M][N], int i, int j)
{
	if (i==M-1 && j==N-1)
		return 1;
	
	// Initialize U,P,L,R direction
	int up=0, down=0, left=0, right=0;

	// Check if upper position is downhill
	if (i!=0 && height[i][j] > height[i-1][j])
		up = get_path(M, N, height, i-1, j);


	// Check if lower position is downhill
	if (i!=M-1 && height[i][j] > height[i+1][j])
		down = get_path(M, N, height, i+1, j);

	// Check if left position is downhill
	if (j!=0 && height[i][j] > height[i][j-1])
		left = get_path(M, N, height, i, j-1);

	// Check if right position is downhill
	if (j!=N-1 && height[i][j] > height[i][j+1])
		right = get_path(M, N, height, i, j+1);

	return up + down + left + right;
}

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
	printf("%d\n",get_path(M, N, height, 0, 0));

	return 0;
}
