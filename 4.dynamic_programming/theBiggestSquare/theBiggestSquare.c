#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	// Get the inputs n, m
	int n,m;
	scanf("%d %d", &n, &m);

	// Get the input matrix M
	char input[m];
	int M[n][m];
	int i, j;
	for (i=0; i<n; i++)
	{
		scanf("%s",input);
		for (j=0; j<m; j++)
			M[i][j] = input[j]-'0';
	}

	// Get minimum value between n and m
	int min = n;
	if (min > m)
		min = m;
	
	// when min=1, just check if 1 exists
	
	// Only check if 1 exists
	bool existanceofOne = false;
	for (i=0; i<n; i++)
	{
		if(existanceofOne)
			break;
		for(j=0; j<m; j++)
			if(M[i][j] == 1)
			{
				existanceofOne = true;
				break;
			}
	}
	

	// Implement compression
	int k;
	for (k=1; k<min; k++)
	{
		// It means the block square which will be compressed exists
		bool existanceofBlock = false;
		
		// Compression
		for (i=0; i<n-k; i++) {
			for (j=0; j<m-k; j++) {
				if( M[i][j] == 1 && M[i+1][j] == 1 && M[i][j+1] == 1 && M[i+1][j+1] == 1)
					existanceofBlock = true;
				else
					M[i][j]=0;
			}
		}
				
		if (!existanceofBlock)
			break;
	}	
	
	// Print the output
	int length = 0;
	if (existanceofOne)
		length = k;
	int area = length*length;
	printf("%d\n",area);

	return 0;
}
