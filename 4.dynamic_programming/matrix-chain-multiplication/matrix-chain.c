#include <stdio.h>

/* bottom-up */

void print_optimal_parentheses(int n, int split[n][n], int i, int j) {
	if (i == j)
		printf("A%d",i+1);
	else {
		printf("(");
		int k = split[i][j];
		print_optimal_parentheses(n, split, i, k);
		printf("*");
		print_optimal_parentheses(n, split, k+1, j);
		printf(")");
	}
}


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

long long matrix_chain_bottom_up(int p[], int n)
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

	/*
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
	*/

	// Print parentheses withoug counting
	print_optimal_parentheses(n, split, 0, n-1);
	 
	printf("\n");	
	return m[0][n-1];
}

/* Top-down */

long long matrix_chain_top_down_aux (int p[], int n, int m[], int i, int j) {
	int idx;
	if (i==0)
		idx = j;
	else
		idx = i*(2*n+1-i)/2 + (j-i);

	if (m[idx] >= 0)
		return m[idx];
	else {
		int k, cur, min=-1;
		for (k=i; k<j; k++) {
			cur = matrix_chain_top_down_aux(p, n, m, i, k) + matrix_chain_top_down_aux(p, n, m, k+1, j) + p[i]*p[k+1]*p[j+1];
			if (min == -1 || min > cur)
				min = cur;
		}
		m[idx] = min;
		return min;
	}
}

long long matrix_chain_top_down(int p[], int n) {
	int m[n*(n+1)/2];
	int i, j;
	for (i=0; i<n*(n+1)/2; i++) {
		m[i] = -1;
	}
	j=0;
	for (i=n; i>0; i--) {
		m[j] = 0;
		j += i;
	}

	return matrix_chain_top_down_aux(p, n, m, 0, n-1);
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

	printf("%lld\n", matrix_chain_top_down(p, n));
//	printf("%lld\n", matrix_chain_bottom_up(p, n));
	return 0;
}
