#include <stdio.h>

// the maximal length of array
#define al 10000

int main(void)
{
	// get initial input. M is the amount of money the rich owns, N is the number of kind of coins. 
	int M, N;
	scanf("%d%d",&M,&N);

	// get the value of each coin
	int i;
	int value[N];
	for (i=0; i<N; i++)
		scanf("%d",&value[i]);
	
	// calculate the number of ways to make the total amount M
	// initailzie
	int num[M/al+1][al];
	int j;
	for (i=0; i<=M/al; i++)
		for(j=0; j<al; j++)
			num[i][j]=-1;
	for (i=0; i<N; i++)
		num[value[i]/al][value[i]%al] = 1;
	
	// calculate
	for (i=1; i<=M; i++)
	{
		int	min = -2;
		for(j=0; j<N; j++)
		{
			if( value[j] >= i)
				continue;

			int refRow, refCol;
			if (i%al >= value[j]) {
				refRow = i/al;
				refCol = i%al - value[j];
			}	else {
				refRow = (i/al)-1;
				refCol = (i-value[j])%al;
			}
			
			int cur = num[refRow][refCol];
			if (cur>0)
			{
				if (min<0 || min>cur)
					min = cur;
			}
		}
		if (min>0 && num[i/al][i%al] < 0)
			num[i/al][i%al] = min+1;
	}


	printf("%d\n",num[M/al][M%al]);

	return 0;
}
