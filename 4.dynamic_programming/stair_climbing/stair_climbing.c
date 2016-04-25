#include <stdio.h>

int max (int a, int b) { return a>b?a:b; }

int main(void) {

	// the number of input n.
	int n, i;
	scanf("%d",&n);

	// score of each stair
	int stair[n];
	for (i=0; i<n; i++)
		scanf("%d",&stair[i]);

	// score[i-1] means the maximal score at i-th stair.
	int score[n];
	score[0] = stair[0];
	score[1] = stair[0]+stair[1];
	score[2] = max(stair[0], stair[1]) + stair[2];
	for (i=3; i<n; i++) {
		score[i] = max(score[i-3]+stair[i-1], score[i-2]) + stair[i];
	}
	
	printf("%d", score[n-1]);

	return 0;
}
