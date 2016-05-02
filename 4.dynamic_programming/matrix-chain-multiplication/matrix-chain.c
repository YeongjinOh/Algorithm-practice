#include <stdio.h>

void count_parentheses(int left[], int right[], int n, int split[n][n], int i, int j) {
	if (i == j)
		return;
	else {
		int k = split[i][j];
		left[i]++;
		right[j+1]++;

		if (j == i+1) 
			return;
		count_parentheses(left, right, n, split, i, k);
		count_parentheses(left, right, n, split, k+1, j);
		return;
	}
}

long long matrix_chain_order(int p[], int n)
{
	long long m[n][n];
	int i, j, k, min, cur;

	// split[i][j] means where to split between i and j
	int split[n][n];

	// the number of parentheses
	int left[n+1], right[n+1];
	for (i=0; i<=n; i++) {
		left[i] = 0;
		right[i] = 0;
	}

	for (i=0; i<n; i++) {
		m[i][i] = 0;
		for (j=0; j<n; j++)
			split[i][j] = 0;
	}

	for (i=1; i<n; i++)
		for (j=0; j<(n-i); j++) {
			
			// initialize minimum
			min = -1;
			
			for (k=j; k<j+i; k++)  {
				cur = m[j][k] + m[k+1][j+i] + p[j]*p[k+1]*p[j+i+1];
				if (min == -1 || min > cur) {
					min = cur;
					split[j][i+j] = k;
				}
			}
			m[j][i+j] = min;
		}

	count_parentheses(left, right, n, split, 0, n-1);
	
	for (i=0; i<n; i++) {
		for (j=0; j<right[i]; j++)
			printf(")");
		for (j=0; j<left[i]; j++)
			printf("(");
		printf("A%d",i+1);
	}
	for (j=0; j<right[i]; j++)
		printf(")");
	printf("\n");	

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
