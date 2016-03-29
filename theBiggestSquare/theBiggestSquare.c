#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	// Get the inputs n, m
	int n,m;
	scanf("%d %d", &n, &m);

	// Get the input matrix M
	int M[n][m];
	int i, j;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d",&M[i][j]);


	// Get minimum value between n and m
	int min = n;
	if (min > m)
		min = m;
	
	// when min=1, just check if 1 exists
	int k = 0;
	if (min == 1)
	{
		for (i=0; i<n; i++)
			for(j=0; j<m; j++)
				if(M[i][j] == 1)
					k=1;
	} else {
		

		// Implement compression
		for (k=1; k<min; k++)
		{
			// It means the compressed sqaure exists
			bool existance = false;
			
			// Compression
			for (i=0; i<n-k; i++) {
				for (j=0; j<m-k; j++) {
					if( M[i][j] == 1 && M[i+1][j] == 1 && M[i][j+1] == 1 && M[i+1][j+1] == 1)
						existance = true;
					else
						M[i][j]=0;
				}
			}
					
			if (!existance)
				break;
		}
	}
	
	int length = k;

	// Print the output
	int area = length*length;
	printf("%d\n",area);

	return 0;
}
