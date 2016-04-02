#include <stdio.h>

int N;

int getSum (int C[], int H[], int E[], int sum[], int prey_list[N][N], int prey_num[], int idx);

int main(void)
{
	// Get inputs
	int M;
	scanf("%d", &N);

	// C:calorise, H:heavy metal, E:energy, prey_num:# of preys, sum:sum of H which i have eaten.
	int C[N], H[N], E[N], prey_num[N], sum[N], i;
	for(i=0; i<N; i++)
	{
		scanf("%d%d%d", &C[i], &H[i], &E[i]);
		prey_num[i] = 0;
		if (C[i] == 0)
			sum[i] = H[i];
		else
			sum[i] = 0;
	}

	scanf("%d", &M);
	
	// i-th row contains the preys of (i+1)-th life
	int prey_list[N][N], prey, life;
	for(i=0; i<M; i++)
	{
		scanf("%d%d", &prey, &life);
		prey_list[life-1][prey_num[life-1]++] = prey-1;
	}

	/*
	int j, min;
	for (i=0; i<N; i++)
	{
		printf("The list of prey of %d : ",i+1);
		min = prey_num[i];
		for(j=0; j<min; j++)
			printf("%d ",prey_list[i][j]+1);
		printf("\n");
	}
	*/

	int human_heavy = getSum(C,H,E,sum,prey_list,prey_num,N-1);
	if (H[N-1] > human_heavy)
		printf("yes\n%d\n",human_heavy);
	else
		printf("no");

	
	return 0;
}

// calculate minimal sum of heavy metal
int getSum (int C[], int H[], int E[], int sum[], int prey_list[N][N], int prey_num[], int idx)
{
	if (sum[idx])
		return sum[idx];
	int i, j;
	for (i=0; i<prey_num[idx]; i++)
	{
		// index of current prey
		int prey = prey_list[idx][i];

		if (sum[prey] == 0)
			sum[prey] = getSum (C, H, E, sum, prey_list, prey_num, prey);
		if (sum[prey] >= H[prey])
		{
			// if it dies, reduce prey list
			for(j=i; j++; j<--prey_num[idx])
				prey_list[idx][j] = prey_list[idx][j+1];
			i--;
		}
	}
	
	// now, prey list contains only alive lives
	if (prey_num[idx] == 0)
		return H[idx];
	
	for (i=0; i<prey_num[idx]; i++)
	{
		


	}
}
		

