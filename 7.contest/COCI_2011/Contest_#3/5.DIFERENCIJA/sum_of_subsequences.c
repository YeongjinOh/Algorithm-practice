#include <stdio.h>

long long sum_of_min (long long seq[], int l, int r) {
	
	if (l==r)
		return seq[l];

	long long min = 987654321, res;
	int i, min_idx;
	for (i=l; i<=r; i++) {
		if (min > seq[i]) {
			min = seq[i];
			min_idx = i;
		}
	}
	res = (min_idx-l+1)*(r-min_idx+1)*min;
	if (min_idx > l)
		res += sum_of_min(seq,l,min_idx-1);
	if (min_idx < r)
		res += sum_of_min(seq,min_idx+1,r);
	return res;
}

long long sum_of_max (long long seq[], int l, int r) {
	
	if (l==r)
		return seq[l];

	long long max = 0, res;
	int i, max_idx;
	for (i=l; i<=r; i++) {
		if (max < seq[i]) {
			max = seq[i];
			max_idx = i;
		}
	}
	res = (max_idx-l+1)*(r-max_idx+1)*max;
	if (max_idx > l)
		res += sum_of_max(seq,l,max_idx-1);
	if (max_idx < r)
		res += sum_of_max(seq,max_idx+1,r);
	return res;
}

int main() {

	// length of sequence. 2 <= N <= 300,000
	int N;
	scanf("%d", &N);

	long long seq[N];
	int i;
	for (i=0; i<N; i++)
		scanf("%lld",&seq[i]);

	printf("%lld\n", sum_of_max(seq,0,N-1) - sum_of_min(seq,0,N-1));
}


