#include <stdio.h>

int main() {
	
	// length of sequence
	int n;
	scanf("%d", &n);
	
	// initailize
	int i, j, cur, max[1001];

	for (i=0; i<1001; i++)
		max[i] = 0;
	
	int prev = 0,  cur_max;
	for (i=0; i<n; i++) {
		// get input number
		scanf("%d", &cur);

		// preprocess to avoid duplicate comparison
		if (prev == cur)
			continue;
		else if (prev > cur) 
			prev = 0;

		cur_max = max[prev];
		// compare and set maximum value
		for (j=prev+1; j<cur; j++) {
			if (cur_max < max[j])
				cur_max = max[j];
		}
		max[cur] = cur_max+1;
		prev = cur;
	}

	// calculate result
	int res=0;
	for (i=1; i<=1000; i++)
		if(res<max[i])
			res = max[i];
	printf("%d\n", res);	

	return 0;
}
