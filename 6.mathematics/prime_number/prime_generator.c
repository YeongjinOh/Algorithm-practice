#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "prime_number.h"

#define SIZE 1000000

// It compares two ways to build prime numbers 
int main()
{

	// prime[i] measn if i is prime number.
	bool prime_check[SIZE+1];
	int prime[SIZE/2];
	int i, prime_size=0;
	clock_t begin, end;
	// mili second
	double time_spent;

	/* The First method using array */
	begin = clock();
	// initialize with true
	for (i=2; i<=SIZE; i++)
		prime_check[i]=true;

	for (i=2; i*i<=SIZE; i++)
		if(prime_check[i])
		{
			int j;
			for (j=i*i; j<=SIZE; j+=i)
				prime_check[j]=false;
		}
	end = clock();

	for (i=2; i<=SIZE; i++)
		if (prime_check[i])
			prime_size++;
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC*1000;
	printf("size:%d time spent:%.2f(ms)\n",prime_size, time_spent);

	/* The Second method using structure */
	begin = clock();

	prime_number prime_;
	generate_prime(SIZE,&prime_);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC*1000;

	prime_size = count_prime(&prime_);

	printf("size:%d time spent:%.2f(ms)\n",prime_size, time_spent);

	return 0;
}
