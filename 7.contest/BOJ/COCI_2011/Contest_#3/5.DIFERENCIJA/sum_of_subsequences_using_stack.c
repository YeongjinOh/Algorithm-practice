#include <stdio.h>

int main() {

	// length of sequence. 2 <= N <= 300,000
	int N;
	scanf("%d", &N);

	// I push elemnents in descending order into stack_max.
	// pop all the elemenets smaller than current value.
	// cnt_max count number of duplicate elements
	// d_max calculate sum of all elements from bottom to the top.
	long long stack_max[N], cnt_max[N], d_max[N];
	long long stack_min[N], cnt_min[N], d_min[N];
	long long cur, max_sum=0, min_sum=0, ptr_max=0, ptr_min=0;
	int i, cnt_small, cnt_large;
	for (i=0; i<N; i++) {
		scanf("%lld",&cur);

		/* max operation */

		cnt_small = 1;
		
		// pop smaller elements
		while (ptr_max > 0 && stack_max[ptr_max-1] < cur) { 
			ptr_max--; 
			cnt_small += cnt_max[ptr_max];
		}

		// push current element
		stack_max[ptr_max] = cur;
		cnt_max[ptr_max] = cnt_small;
		if (ptr_max > 0)
			d_max[ptr_max] = d_max[ptr_max-1] + cur*cnt_small;
		else
			d_max[ptr_max] = cur * cnt_small;
		max_sum += d_max[ptr_max];
		ptr_max++;

		/* min operation */

		cnt_large = 1;
		
		// pop larger elements
		while (ptr_min > 0 && stack_min[ptr_min-1] > cur) { 
			ptr_min--; 
			cnt_large += cnt_min[ptr_min];
		}

		// push current element
		stack_min[ptr_min] = cur;
		cnt_min[ptr_min] = cnt_large;
		if (ptr_min > 0)
			d_min[ptr_min] = d_min[ptr_min-1] + cur*cnt_large;
		else
			d_min[ptr_min] = cur * cnt_large;
		min_sum += d_min[ptr_min];
		ptr_min++;
	}
	printf("%lld\n", max_sum-min_sum);
}


