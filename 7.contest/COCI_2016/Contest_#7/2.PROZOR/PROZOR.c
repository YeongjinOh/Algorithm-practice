#include <stdio.h>

int main(void) 
{
	// 3 <= K <= R, S <= 100 
	int R, S, K, i, j;
	scanf("%d%d%d",&R,&S,&K);
	
	// get fly information
	int fly[R][S];
	char read[R][S];
	for (i=0; i<R; i++) {
		scanf("%s",read[i]);
		for (j=0; j<S; j++)
		{
			if (read[i][j] == '*')
				fly[i][j]=1;
			else 
				fly[i][j]=0;
		}
	
	}
	
	// build the integral array
	for (i=0; i<R; i++) {
		for (j=0; j<S; j++)	{
			if (i > 0)
				fly[i][j] += fly[i-1][j];
			if (j > 0)
				fly[i][j] += fly[i][j-1];
			if (i > 0 && j > 0)
				fly[i][j] -= fly[i-1][j-1];
		}
	}
	
	// find the maximal number of flies which we can kill in a single shot.
	int max=-1, cur, max_i, max_j;

	// ignore the flies located at the side of the racket.
	K-=2;


	for (i=K; i<R-1 && max<K*K; i++) {
		for (j=K; j<S-1 && max<K*K; j++)	{
			cur = fly[i][j] - fly[i-K][j] - fly[i][j-K] + fly[i-K][j-K];
			if (max < cur) {
				max = cur;
				max_i = i;
				max_j = j;
			}
		}
	}
	
	// print the result
	printf("%d\n",max);
	
	for (i=0; i<R; i++) {
		for (j=0; j<S; j++) {

			if (i == max_i-K || i == max_i+1) {
				if (j == max_j-K || j == max_j+1)
					printf("+");
				else if (j > max_j-K && j < max_j+1)
					printf("-");
				else
					printf("%c",read[i][j]);
			} else if (j == max_j-K || j == max_j+1) {
				if (i > max_i-K && i < max_i+1)
					printf("|");
				else
					printf("%c",read[i][j]);
			} else {
					printf("%c",read[i][j]);
			}
		}
		printf("\n");
	}


	return 0;
}
