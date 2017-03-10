#include <stdio.h>

int main(void) {

	// n is the number of values of coin. k is the total sum of coins
	int n, k, i, j;
	scanf("%d%d", &n, &k);

	// the number of cases
	int cases[k];
	for (i=0; i<k; i++)
		cases[i]=0;

	// the value of each coin
	int	coin[n];
	for (i=0; i<n; i++) {
		scanf("%d", &coin[i]);
		if (coin[i] < 1 || coin[i] > k)
			continue;
		cases[coin[i]-1] += 1;
		for (j=coin[i]; j<k; j++)
			cases[j] += cases[j-coin[i]];
	}

	printf("%d\n",cases[k-1]);

	return 0;
}
