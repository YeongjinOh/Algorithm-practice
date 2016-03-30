#include <stdio.h>
#include <time.h>

// the maximal length of array
#define al 10001

int max_value(int val[], int length, int * max_idx)
{
	int i, max = 0;
	for (i=0; i<length; i++)
		if (max < val[i])
		{
			max = val[i];
			*max_idx = i;
		}
	return max;
}


int main(void)
{
	// get initial input. M is the amount of money the rich owns, N is the number of kind of coins. 
	long long M;
	int N;
	scanf("%lld%d",&M,&N);

	// get the value of each coin
	int i, j;
	int value[N];
	for (i=0; i<N; i++)
		scanf("%d",&value[i]);

	/* Start of time checking */
	clock_t start, end;
	double cpu_time_used;
	start=clock();

	
	/* Before calculation, use some mathematical trick */
	/* It clearly holds for given input range */
	
	int max_idx;
	int max = max_value(value, N, &max_idx);
	printf("max:%d, idx:%d\n",max,max_idx);

	// k is the minimum coefficient of max
	int k = (int)(M/max);
	for (i=0; i<N; i++)
		if(i != max_idx)
			k -= value[i];
	
	M -= max*k;

	/* calculate the number of ways to make the total amount M */

	// initailzie
	int num[al];
	for(i=0; i<al; i++)
			num[i]=0;
	for (i=0; i<N; i++)
		num[value[i]] = 1;
	
	// each step calculates the number of ways up to the total amout i
	for (i=1; i<=M; i++)
	{
		int	min = 0;

		for(j=0; j<N; j++)
		{
			// Ignore the coin with the value higher than total amout i
			if( value[j] >= i)
				continue;

			// Check the previous step to the i-value[j]
			int prev;
			if (i%al >= value[j]) 
				prev = i%al - value[j];
			else 
				prev = (i-value[j])%al;
			
			// Compare current value with minimum value
			int cur = num[prev];
			if (cur>0 && (min == 0 || min > cur))
					min = cur;
		}
		
		// If it's on the first iteration, check if the coin which has the same value with current i exists
		if (i <= al)
		{
			if (min > 0 && num[i%al] == 0)
				num[i%al] = min+1;
		} else {
			if (min > 0)
				num[i%al] = min+1;
		}
	}
	
	printf("%d\n",num[M%al]+k);

	/* End of time checking */
	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Running tiem : %.2f\nk:%d\n",cpu_time_used,k);
	
	return 0;
}
