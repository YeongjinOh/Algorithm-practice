#include <stdio.h>

int N;
int pt=0;

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

	int human_heavy = getSum(C,H,E,sum,prey_list,prey_num,N-1);
	if (H[N-1] > human_heavy)
		printf("yes\n%d\n",human_heavy);
	else
		printf("no\n");

	return 0;
}

// calculate minimal sum of heavy metal
int getSum (int C[], int H[], int E[], int sum[], int prey_list[N][N], int prey_num[], int idx)
{
	if (sum[idx])
		return sum[idx];
	int i, j, prey;
	for (i=0; i<prey_num[idx]; i++)
	{
		// index of current prey
		prey = prey_list[idx][i];

		if (sum[prey] == 0)
			sum[prey] = getSum (C, H, E, sum, prey_list, prey_num, prey);
		if (C[prey] != 0 && sum[prey] >= H[prey])
		{
			// if it dies, reduce prey list
			for(j=i; j<--prey_num[idx]; j++)
				prey_list[idx][j] = prey_list[idx][j+1];
			i--;
		}
	}
	
	// now, prey list contains only alive lives
	if (prey_num[idx] == 0)
		return H[idx];
	
	// calculate maximal energy for this inequation (a1E1 + ... + anEn) >= C
	int max_E=0, max_idx;
	for (i=0; i<prey_num[idx]; i++)
	{
		prey = prey_list[idx][i];
		if (max_E < E[prey])
		{
			max_E = E[prey];
			max_idx = prey;
		}
	

		if(pt && idx == N-1)
			printf("i:%d, max_E:%d\n",i,max_E);
	}

	int sumE, sumH[C[idx]+max_E], prev, min_sumH=0;
	for (i=0; i<C[idx]+max_E; i++)
		sumH[i]=0;

	for (sumE=1; sumE < C[idx]+max_E; sumE++)
	{
		for (i=0; i<prey_num[idx]; i++)
		{
			prey = prey_list[idx][i];
			
			if (sumE < E[prey])
				continue;
			else if (sumE == E[prey])
			{
				if(sumH[sumE] == 0)	{
					sumH[sumE] = sum[prey];
				} else if(sumH[sumE]>sum[prey]) {
					sumH[sumE] = sum[prey];
				}
				continue;
			}

			prev = sumH[sumE-E[prey]];
			if (prev == 0)
				continue;
			if (sumH[sumE] == 0 || sumH[sumE] > prev+sum[prey])
				sumH[sumE]=prev+sum[prey];
		}
		

	// find minimal sum of H which is min(a1S1 + ... + anSn)
		if (sumE == C[idx])
			min_sumH = sumH[sumE];
		else if (sumE > C[idx] && ((min_sumH == 0) || (min_sumH > sumH[sumE] && sumH[sumE])) != 0)
		min_sumH = sumH[sumE];
	}
		if(pt)
			printf("idx:%d, min_sumH:%d\n",idx,min_sumH);
		return min_sumH;
}
		

