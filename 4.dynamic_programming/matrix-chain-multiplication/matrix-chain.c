#include <stdio.h>

long long matrix_chain_order(int p[], int n)
{
	long long m[n][n];
	int i, j, k, min, cur;
	
	for (i=0; i<n; i++)
		m[i][i] = 0;

	for (i=1; i<n; i++)
		for (j=0; j<(n-i); j++) {
			
			// initialize minimum
			min = -1;
			
			for (k=j; k<j+i; k++)  {
				cur = m[j][k] + m[k+1][j+i] + p[j]*p[k+1]*p[j+i+1];
				if (min == -1 || min > cur)
					min = cur;
			}
			m[j][i+j] = min;
		}

	return m[0][n-1];
}

int main(void)
{
	int n, i, a, b;
	scanf("%d",&n);
	int p[n+1];
	for (i=0; i<n; i++) {
		scanf("%d%d",&a, &b);
		p[i] = a;
	}
	p[i] = b;

	printf("%lld\n", matrix_chain_order(p, n));
	return 0;
}
