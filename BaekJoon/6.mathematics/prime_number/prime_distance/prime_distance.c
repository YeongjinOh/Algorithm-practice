#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
// Maximum integer less than or equal to sqrt(U)
#define MAX_PRIME 46340

int main(){
     
	// get inputs
	// 1 <= L < U < =2,147,483,647
	long long L, U, D1, D2, C1, C2;
	int prev_U=0, cnt=0;;
	char * no_prime = "There are no adjacent primes.";
	
	// if i is prime, then not_prime[i] = false;
	bool not_prime[MAX_PRIME]={true, true,};
	int i, j;
	
	for (i=2; i*i<=MAX_PRIME; i++)
		if (!not_prime[i])
			for (j=i*i; j<=MAX_PRIME; j+=i)
				not_prime[j]=true;

	// count prime size
	int prime_size=0;
	for (i=2; i<=MAX_PRIME; i++)
		if(!not_prime[i])
			prime_size++;

	// insert primes into array
	int prime[prime_size];
	j=0;
	for (i=2; i<=MAX_PRIME; i++)
		if(!not_prime[i])
			prime[j++]=i;
	int k=0, min, max;
	for (k=0; k<2; k++) {
		scanf("%lld%lld",&L,&U);
		min=0;
		max=0;
				
		// ignore 1
		if (L == 1)
			L=2;

		int length = U-L+1;
		// check if L+i is not prime
		bool check[length];
		for (i=0; i<length; i++)
			check[i]=false;

		for (i=0; i<prime_size; i++)
		{
			int p = prime[i];
			int start = L%p;
			if (start != 0)
				start = p-start;
			// if start value is equal to p
			if (start+L == p)
				start += p;
			for(j=start; j<length; j+=p)
				check[j]=true;
		}
				
		int prev_p=-1, dist=0;

		// we can use i+=2
		for (i=0; i<length; i++)
		{
			if (!check[i])
			{
				// For the first prime
				if (prev_p == -1)
				{
					prev_p = i;
					continue;
				}
							 
				dist = i-prev_p;
				if (dist > max)
				{
					D1 = prev_p;
					D2 = i;
					max = dist;
				}
				if (dist < min || min == 0)
				{
					C1 = prev_p;
					C2 = i;
					min = dist;
				}
				prev_p = i;
			}
		}
		if (min == 0)
			printf("%s\n",no_prime);
		else
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", L+C1, L+C2, L+D1, L+D2);
	}
 
    return 0;
}
 
