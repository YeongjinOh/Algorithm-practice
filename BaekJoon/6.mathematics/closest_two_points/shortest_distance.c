#include <stdio.h>

// -10000 <= x, y <= 10000
#define MAX_SIZE 20001

int dist(int x[], int y[], int i, int j) {
	int x_diff = x[i]-x[j];
	int y_diff = y[i]-y[j];
	return x_diff*x_diff + y_diff*y_diff ;
}

// return the floor(sqrt(n))
int sqrtInt(int n) {
	int i=1;
	while (i*i<=n) {i++;}

	return i-1;
}

int main(void){
	int n, i, j;
	scanf ("%d",&n);

	// initailize counting array for Counting sort
	int cnt_x[MAX_SIZE], cnt_y[MAX_SIZE], end_x[MAX_SIZE];
	for (i=0; i<MAX_SIZE; i++)	{
		cnt_x[i] = 0;
		cnt_y[i] = 0;
		end_x[i] = -1;
	}

	// Get the position of each point.
	int x[n], y[n], tmp_x[n], tmp_y[n];
	
	for (i=0; i<n; i++) {
		scanf("%d%d",&x[i],&y[i]);
		cnt_x[x[i]+10000]++;
		cnt_y[y[i]+10000]++;
	}

	/*  Radix sort using Counting sort for each x, y. */
	// x is the largest digit. 
	
	for (i=1; i<MAX_SIZE; i++) {
		cnt_x[i] += cnt_x[i-1];
		cnt_y[i] += cnt_y[i-1];
	}

	int new_idx;
	
	// Counting sort for y.
	for (i=n-1; i>=0; i--) {
		new_idx = --cnt_y[y[i]+10000];
		tmp_x[new_idx] = x[i];
		tmp_y[new_idx] = y[i];
	}

	// Counting sort for x.
	for (i=n-1; i>=0; i--) {
		new_idx = --cnt_x[tmp_x[i]+10000];
		x[new_idx] = tmp_x[i];
		y[new_idx] = tmp_y[i];
		if (end_x[tmp_x[i]+10000] == -1)
			end_x[tmp_x[i]+10000] = new_idx;

	}


	/* Calculate minimum distance using sorted array */

	int cur, min = dist(x, y, 0, 1);
	for (i=0; i<n-1 && min>1; i++) {
		int limit_x = x[i]+sqrtInt(min), limit_y = y[i]+sqrtInt(min);
		
		for (j=i+1; j<n && x[j] < limit_x; j++) {
			
			cur = dist(x, y, i, j);
			if (min > cur) {
				min = cur;
				limit_x = x[i]+sqrtInt(min);
				limit_y = y[i]+sqrtInt(min);
			}
			
			if (y[j] >= limit_y)
				j = end_x[x[j]+10000];

		}
	}

	printf("%d\n", min);
	return 0;
}
