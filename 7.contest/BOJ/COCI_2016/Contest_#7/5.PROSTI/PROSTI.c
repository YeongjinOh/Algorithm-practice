#include <stdio.h>
#include <stdbool.h>

#define UNHAPPY_SIZE 8000000

int main(void)
{
	int Q, i, j, K, L, M, size=UNHAPPY_SIZE;

	// true if not prime
	bool unhappy[UNHAPPY_SIZE]={1,1,};


	scanf("%d",&Q);
	while (Q--) {
		// 1 <= K, M <= 150 , 0 <= L <= K <= 150
		scanf("%d%d%d", &K, &L, &M);
		
		// build not primes
		for (i=2; i*i<size; i++) {
			if (!unhappy[i])
			for (j=i*i; j<size; j+=i)
				unhappy[j]=true;
		}	


		// cnt counts the total number of unhappy within k-consecutive numbers
		int start=1, cnt=0;
		if (M > L)
			start = M-L+1; 

		// build unhappy with the first condition that happy numbers are smaller than or equal to M
		for (i=start; i<=M; i++)
			unhappy[i]=false;

		// only the first M elements are modified.
		size = M;

		// check the first unhappy
		for (i=start; i<start+K; i++)
			cnt += unhappy[i];

		while (cnt != K-L && i < UNHAPPY_SIZE) {
			cnt += unhappy[i];
			cnt -= unhappy[i-K];
			i++;
		}
		if (i >= UNHAPPY_SIZE) 
			printf("-1\n");
		else
			printf("%d\n",i-K);
		
		int j;
		for (j=M+1; j<i; j++)
			if (!unhappy[j])
				printf("%d ",j);


	}


}
