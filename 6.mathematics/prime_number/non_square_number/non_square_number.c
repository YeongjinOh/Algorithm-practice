#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
   
#define MAX_LENGTH 100000
  
bool check[MAX_LENGTH];
  
int count (int prime[], int size, long long min, long long max);
  
int main(){
		 
	// get inputs
	// 1<=min<=10^13, 1<=max<=min+10^7
	long long min, max;
	scanf("%lld%lld",&min,&max);
	long long length = max-min+1, ans = length, size=0;

	// generate prime numbers smaller than or equal to sqrt(max)
	int i, j;
	for (size=0; size*size<=max; size++);

	// prime[i] measn if i is prime number.
	bool prime_check[size+1];
	long long prime_size=0;

	// initialize with true
	for (i=2; i<=size; i++)
			prime_check[i]=true;
	
	// Check if the number i is prime using Sieve of Eratosthenes
	for (i=2; i*i<=size; i++)
		if(prime_check[i])
			 for (j=i*i; j<=size; j+=i)
				 prime_check[j]=false;
			
	// Count the number of primes
	for (i=2; i<=size; i++)
		if(prime_check[i])
			prime_size++;
					 
	// initialize the prime array
	int prime[prime_size];
	prime_size=0;
	for (i=2; i<=size; i++)
		if(prime_check[i])
			prime[prime_size++]=i;
	 
	// count the non square numbers   
	if (length > MAX_LENGTH)
	{
			int rep = length/MAX_LENGTH, i;
			for (i=0; i<rep; i++)
			{
					ans -= count (prime, prime_size, (min+(long long)i*MAX_LENGTH), (min-1+(long long)(i+1)*MAX_LENGTH));
			}
			if (length%MAX_LENGTH != 0)
					ans -= count (prime, prime_size, min+(long long)rep*MAX_LENGTH, max);
	}   else {
			ans -= count(prime, prime_size, min, max);
	}

	printf("%lld\n", ans);

	return 0;
}
  
int count (int prime[], int size, long long min, long long max)
{
    long long i;
		int j, cnt=0;
    long long length = max-min+1;
    for (j=0; j<length; j++)
        check[j]=false;
      
    for (j=0; j<size; j++)
    {
        long long sqr = (long long)prime[j]*prime[j];
        long long start = min%sqr;
        if (start != 0)
            start = sqr-start;
          
        for (i=start; i<length; i+=sqr)
            if (!check[i])
            {
                check[i]=true;
                cnt++;
            }
    }
    return cnt;
}
