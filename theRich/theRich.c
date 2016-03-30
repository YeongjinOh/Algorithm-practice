#include <stdio.h>

// the maximal length of array
#define al 10001

int main(void)
{
	// get initial input. M is the amount of money the rich owns, N is the number of kind of coins. 
	int M, N;
	scanf("%d%d",&M,&N);

	// get the value of each coin
	int i, j;
	int value[N];
	for (i=0; i<N; i++)
		scanf("%d",&value[i]);


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

	printf("%d\n",num[M%al]);

	return 0;
}
