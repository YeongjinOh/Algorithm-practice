#include <stdio.h>
int min(int a, int b) { return a>b?b:a; }
int max(int a, int b) { return a>b?a:b; }

int main() {

	// number of rows
	int n;
	scanf("%d", &n);

	int i, j, score[3];
	int tmp_min, tmp_max, min_score[3], max_score[3];
	
	// get scores
	for (j=0; j<3; j++) {
		min_score[j] = 0;
		max_score[j] = 0;
	}
	
	for (i=0; i<n; i++) {
		for (j=0; j<3; j++) 
			scanf("%d", &score[j]);
		tmp_min = min(min(min_score[0], min_score[1]), min_score[2]);
		tmp_max = max(max(max_score[0], max_score[1]), max_score[2]);
	
		min_score[0] = min(min_score[0], min_score[1]) + score[0];
		min_score[2] = min(min_score[1], min_score[2]) + score[2];
		min_score[1] = tmp_min + score[1];

		max_score[0] = max(max_score[0], max_score[1]) + score[0];
		max_score[2] = max(max_score[1], max_score[2]) + score[2];
		max_score[1] = tmp_max + score[1];
	}
	
	printf("%d %d\n", max(max(max_score[0], max_score[1]), max_score[2]), min(min(min_score[0], min_score[1]), min_score[2]) );

	return 0;
}
