#include <stdio.h>
#include <stdbool.h>
 
// the maximal length of array
#define al 10001

// For convenience, i just use bubble sort
void bubble_sort(int val[], int length) {
    int i, j, tmp;
    for (i=length-1; i>0; i--) {
        bool swapped = false;
        for (j=0; j<i; j++)
            if (val[j] < val[j+1]) {
                tmp = val[j];
                val[j] = val[j+1];
                val[j+1] = tmp;
                swapped = true;
            }
        if (!swapped)
            break;
    }
}
 
int main(void)
{
    // get initial input. M is the amount of money the rich owns, N is the number of kind of coins. 
    long long M, num[al];
    int N;
    scanf("%lld%d",&M,&N);
 
    // get the value of each coin
    int i, j;
    int value[N];
    for (i=0; i<N; i++)
        scanf("%d",&value[i]);

    // sort value array in descending order
    bubble_sort(value,N);
 
    // erase overlapping value
    for (i=0; i<N-1; i++)
    	if(value[i] == value[i+1]) {
    		for (j=i+1; j<N-1; j++) {
        	value[j] = value[j+1];
        }
      	N--;
        i--;
      }
 
    /** Before calculation, use some mathematical trick .
     * Calculate the minimum of coefficient of maximal value,
		 * and then use it to reduce M downto M'.
		 * To do this, I implement two reductions.
		 * The first reduction reduces M down to S, which is sigma(v_i*v_(i+1)) for i from 1 to (n-1)
		 * if S is not that large, which means M is reduced down to the not that big number M', so we can just solve this problem with M'.
		 * if S it so large, I use the second reduction.
		 * The idea of the second reduction is the following :
		 
		 * Let's denote the minimal solution set A = {(a1,a2,...,an)| a1v1+...+anvn=M, (a1+a2+...+an) is minimum}
		 * Since 1 is given as input, we always have solution, which means A is not empty
		 * All ai's is bounded by M/vi, A is finite, so we can find and fix maximal a1(denote it 'a') of some solution tuple (x1,x2,...,xn)
		 * Then (a*v1 + x2*v2 + ... + xn*vn)=M, (x2v2+...+xnvn)=M-a*v1=M'
		 * For this M', since a was maximal, any minimal solutions of (a1*v1 + a2*v2 + ... + an*vn)=M' can not have a1>0.
		 * Now, let's denote the set B={M'|any minimal solutions of (a1v1+...+anvn)=M' has a1=0} (1<=M'<=M)
		 * So I'll find the upper bound of this set B by using forbidden array
		 * ,whose i-th element indicate whether the minimal solution of the element have a1>0
		 * At some point, incrementing i by 1, we can get consecutive forbidden values longer than max value.
		 * This means M' should be smaller than i, so we can reduce M downto i. */
		 

		/** The first reduction **/

		long long S = 0;
    for (i=0; i<N-1; i++)
        S += value[i]*value[i+1];
    
		// minimum coefficient of max
    int max = value[0];
    long long minCoeff;
		
		/* If inputs are not that large,	
     *  use this inequation, (m-(v1v2+...+vn-1vn))/v1 < a1 */
		if (S < 100000000)  {
			long long k = M;
			k -= S;
			if (k<0)
				k=0;

    minCoeff = (k/(long long)max);
		M -= max*minCoeff;
	
		/** The second reduction **/
		
		/* If inputs are so large, find the maximum M' such that
		 * when a1v1 + a2v2 + ... + anvn = M', for all (a1,a2,...,an) satisfies min(a1+a2+...+an), a1=0 */
		} else {
		
			// initialize
			// forbidden array, whose element i means the total amount i is forbidden, the solution to the amount should have a1>0
			int forbdd[al];
			for (i=0; i<al; i++)
			{
				num[i]=0;
				forbdd[i]=0;
			}
			for (j=1; j<N; j++)
				num[value[j]]=1;
		
			// count the number of the forbidden
			int cnt = 0;
		
			for (i=1; i<=M; i++) {
        int min = 0, fbd = 0, prev, cur;

				// Use the values' except the max value
				for(j=1; j<N; j++) {

					// Ignore the coin with the value higher than total amout i
          if( value[j] >= i)
          	continue;
 
					// Check the previous step to the i-value[j]
          if (i%al >= value[j]) 
          	prev = i%al - value[j];
          else
          	prev = (i-value[j])%al;

					// Compare current value with minimum value
          cur = num[prev] + 1;

          if (cur>1 && (min == 0 || min >= cur))
					{
						if (!(min == cur && fbd == 1))
							fbd = forbdd[prev];
						min = cur;
					}
        } // end of for loop of j
        
				// Use max value to check if it's forbidden
				if(i>=max) {
         if (i%al >= max) 
          	prev = i%al - max;
          else
          	prev = (i-max)%al;

         cur = num[prev] + 1;
				if (cur>1 && min >= cur)
				{
					min = cur;
					fbd = 1;
				}
       }

        // If it's on the first iteration, check if the coin which has the same value with current i exists
        if (i < al) {
        	if (min > 0 && num[i%al] == 0)
          	num[i%al] = min;
						cnt -= forbdd[i%al];
						forbdd[i%al] = fbd;
						cnt += fbd;
        } else {
          	num[i%al] = min;
						cnt -= forbdd[i%al];
						forbdd[i%al] = fbd;
						cnt += fbd;
        }
				if (cnt == al)
				{
					break;
				}
    	
			} // end of outter for loop of i
	 
			// if the upper bound of M', which corresponds (i-al) for now, exists, reduce M
			if (i<M) {
	 	  	long long k = M;
			 	k -= (i-al);
 	  		if (k<0)
	      	k=0;
			
				// minimum coefficient of max
	  	 	minCoeff = (k/(long long)max);
     	  M -= minCoeff*max;
			}
		}
 
    /* Now we are ready to solve this problem with reduced input M */
    /* calculate the number of ways to make the total amount M */
 
    // initailzie
    for(i=0; i<al; i++)
            num[i]=0;
    for (i=0; i<N; i++)
        num[value[i]] = 1;
     
    // each step calculates the number of ways up to the total amout i
    for (i=1; i<=M; i++) {
        int min = 0;
        for(j=0; j<N; j++)  {
            
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
          int cur = num[prev]+1;
          if (cur>1 && (min == 0 || min > cur))
          	min = cur;
        }
         
        // If it's on the first iteration, check if the coin which has the same value with current i exists
        if (i < al) {
        	if (min > 0 && num[i%al] == 0)
          	num[i%al] = min;
        } else {
          	num[i%al] = min;
        }
    }
     
    printf("%lld\n",num[M%al]+minCoeff);
     
    return 0;
}
