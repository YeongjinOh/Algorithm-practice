#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, i, j, cnt=0;
	scanf("%d", &N);		

	// Initialize array //
	int row[N];
	for (i=0; i<N; i++)
		row[i]=-1;
 	
	for(i=0; i<N; i++)
		cnt += queen(0,N,row,i);

	printf("%d\n",cnt);
	return 0;
}

int queen(int current, int total, int ar[], int new)
{
	int i=0;

	// Copy the array//
	int row[total];
	for (i=0; i<current; i++)
		row[i]=ar[i];


	if (check(current,total,ar,new) == 0)
		return 0;
	else
	{
		row[current] = new;
		current++;
		
		if (current ==  total)
			return 1;
		else
		{
			// Initialize row // 
			int candidate[total];
			int sum = 0;
			for (i=0; i<total; i++)
				candidate[i]=i;

			// Subtract already occupied column //
			for (i=0; i<current; i++)
				candidate[row[i]] = -1;

			for (i=0; i<total; i++)
				if (candidate[i] != -1)
					sum += queen(current, total, row, i);
			
			return sum;
		}
	}
}

int check (int current, int total, int ar[], int new)
{
	int i=0;
	for(i=1; i<=current; i++)
		if (ar[current-i]-i == new || ar[current-i]+i == new)
			return 0;
	return 1;

}
