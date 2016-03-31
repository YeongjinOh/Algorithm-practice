#include <stdio.h>
#include <stdbool.h>

// the maximal length of array
#define al 10001

// print option
#define pt false

void bubble_sort(int val[], int length)
{
	int i, j, tmp;
	for (i=length-1; i>0; i--)
	{
		for (j=0; j<i; j++)
			if (val[j] < val[i])
			{
				tmp = val[j];
				val[j] = val[i];
				val[i] = tmp;
			}
	}
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

	/* Before calculation, use some mathematical trick */
	/* First calculate the minimum of coefficient of maximum value */	
	/* And use it to make M small */

	// make value array in descending order
	bubble_sort(value,N);

	// erase overlapping value
	for (i=0; i<N-1; i++)
		if(value[i] == value[i+1])	{
			for (j=i+1; j<N-1; j++)
			{
				value[j] = value[j+1];
			}
			N--;
			i--;
		}
	if (pt)
		printf("compressed length:%d\n",N);

	// to use this inequation, (M-(v1v2+...+vn-1vn))/v1 < a1
	long long k = M;
	for (i=0; i<N-1; i++)
			k -= value[i]*value[i+1];
	if (k<0)
		k=0;

	// minimum coefficient of max
	int max = value[0];
	long long minCoeff = (k/(long long)max);
	
	M -= minCoeff*max;
	
	if(pt)
		printf("reduced M:%lld coeff:%lld\n",M,minCoeff);

	/* Now we are ready to solve this problem with reduce input M */
	/* calculate the number of ways to make the total amount M */

	// initailzie
	long long num[al];
	for(i=0; i<al; i++)
			num[i]=0;
	for (i=0; i<N; i++)
		num[value[i]] = 1;

	/*
	// For the special case
	if (M%max == 0)
	{
		printf("%lld\n",M/max + minCoeff);
		return 0;
	} else if (num[M%max] == 1) {
		printf("%lld\n",M/max+1+minCoeff);
		return 0;
	}
	*/

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
		if (i < al)
		{
			if (min > 0 && num[i%al] == 0)
				num[i%al] = min+1;
		} else {
			if (min > 0)
				num[i%al] = min+1;
			else
				num[i%al] = 0;
		}
	}
	
	printf("%lld\n",num[M%al]+minCoeff);
	
	return 0;
}
