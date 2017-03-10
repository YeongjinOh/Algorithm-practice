#include <stdio.h>

int main() {
	
	// get N, M, K
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	
	// initailize max array
	double cur, max[N];
	int i, j, idx;
	for (i=0; i<N; i++) max[i]=0;

	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			scanf("%d%lf", &idx, &cur);
			if (max[idx-1] < cur)
				max[idx-1] = cur;
		}
	}
	
	// bubble sort
	double tmp, sum=0;
	for (i=1; i<N; i++)
		for (j=i; j>0 && max[j] > max[j-1]; j--) {
			tmp = max[j];
			max[j] = max[j-1];
			max[j-1] = tmp;
		}

	// print sum
	for (i=0; i<K; i++)
		sum += max[i];
	printf("%.1f",sum);
}
