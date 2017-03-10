#include <stdio.h>

int main(){

	int N, i;
	scanf("%d",&N);
	int point[N+1], cnt[N+1];

	// count how many people points at i
	for (i=0; i<=N; i++)	
		cnt[i] = 0;
		
	for (i=1; i<=N; i++)	{
		scanf("%d",&point[i]);
		cnt[point[i]]++;
	}

	int stack[N], l=0, numberOfMafia=0;

	// if no one points at i, i is mafia.
	for (i=1; i<=N; i++)
		if (cnt[i] == 0)
			stack[l++] = i;

	// while stack is not empty
	while (l > 0) {

		int mafia, citizen, candidate;
		
		// take a mafia from the stack
		mafia = stack[--l];
		numberOfMafia++;
			
		// set the index of citizen, and the candidate of the next mafia
		citizen = point[mafia];
		candidate = point[citizen];

		// if the citizen is not processed by the other mafia.
		if (point[citizen]) {

			// set it as citizen and erase the pointer to next mafia candidate.
			if (--cnt[candidate] == 0)
				stack[l++] = candidate;
			point[citizen] = 0;
		}

		// erase the point of mafia
		// point[i]=0 means i is process as a mafia or as a citizen
		point[mafia] = 0;
	}
	
	// Now only cycles are left.
	for (i=1; i<=N; i++)	{
		if (point[i]) {
			int j=i, next_j;
			int size=0;
			do {
				size++;
				next_j = point[j];
				point[j] = 0;
				j = next_j;
			} while (j!=i);

			// only half of cycle members can be mafia
			numberOfMafia += size/2;
		}
	}

	printf("%d\n",numberOfMafia);

	return 0;
}
