#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	// Get the inputs n, m
	int n,m;
	scanf("%d %d", &n, &m);

	// Get the input matrix M
	int M[n][m];
	int i, j, k;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d",&M[i][j]);


	// Get minimum value between n and m
	int min = n;
	if (min > m)
		min = m;

	// Implement compression
	for (int k=1; k<min; i++)
	{
		// It means the compressed sqaure exists
		bool existance = false;
		
		// Compression
		for (int i=0; i<n-k; i++) {
			for (int j=0; j<m-k; j++) {
				if( M[i][j] == 1 && M[i+1][j] == 1 && M[i][j+1] == 1 && M[i+1][j+1] == 1)
					existance = true;
				else
					M[i][j]=0;
			}
		}
		
		if (!existance)
			break;
	}
	
	int length = k-1;

	// Print the output
	int area = length*length;
	printf("%d\n",area);

	return 0;
}
